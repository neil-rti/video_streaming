/** ----------------------------------------------------------------
 * com_perf.hpp
 * Class for calculating latency performance, given a vector<u64> of
 * timestamp measurements
 **/
#pragma once
#include <vector>
#include <algorithm>
#include <stdint.h>

class comPerfCalc
{
    // vars for performance (latency) measurements
public:
    comPerfCalc()
    {
        perf_data_ready = false;
        mIntervalEnd = 0;
        mIntervalDuration = 500000000;
        mPrevSeqNum = 0;
        mTransStats.dataSizeMean = 0;
        mTransStats.dataSizeSum = 0;
        mTransStats.droppedSamples = 0;
        mTransStats.intervalNsec = 0;
        mTransStats.latMax = 0;
        mTransStats.latMean = 0;
        mTransStats.latMin = 999999999999999;
        mTransStats.latSampCount = 0;
        mTransStats.latSampSum = 0;
        mTransStats.pubIntervalSumNsec = 0;
    }

    // struct for the data packing into the video sample .data() payload
    struct testPacking {
        uint32_t    seqNum;
        uint32_t    testMode;
        uint32_t    pub_rate;
        uint32_t    pub_size;
        uint64_t    tStampPubPrev;
        uint64_t    tStampSubPrev;
        uint64_t    tStampPubNow;
    };

    struct transStats {
        int64_t     latMin;
        int64_t     latMean;
        int64_t     latMax;
        int64_t     latSampCount;
        int64_t     latSampSum;
        int64_t     dataSizeMean;
        int64_t     dataSizeSum;
        int32_t     droppedSamples;
        uint64_t    intervalNsec;
        uint64_t    pubIntervalSumNsec;
    };
    // Outputs
    std::vector<transStats> transportStats;
    bool perf_data_ready;                   // perfdata is ready for local monitoring program, for this interval


    // start test interval w/duration
    void interval_start_nsec(uint64_t nsec) {
        mIntervalDuration = nsec;
        mIntervalEnd = tstamp_u64_get() + mIntervalDuration;
    }
    void interval_start_usec(uint64_t usec) {
        mIntervalDuration = usec * 1000;
        mIntervalEnd = tstamp_u64_get() + mIntervalDuration;
    }
    void interval_start_msec(uint64_t msec) {
        mIntervalDuration = msec * 1000000;
        mIntervalEnd = tstamp_u64_get() + mIntervalDuration;
    }

    // update the stats with a new set of timestamps
    uint8_t update_stats(uint64_t tLast, const uint8_t* newStamps, uint32_t dataSize)
    {
        // Get the average transport latency, and check for any dropped samples
        testPacking* testParts = (testPacking*)newStamps;
        int64_t latPlusClockOfsPrev = testParts->tStampSubPrev - testParts->tStampPubPrev;
        int64_t latPlusClockOfsNow = tLast - testParts->tStampPubNow;
        int64_t transportLatencyAverage = (latPlusClockOfsPrev + latPlusClockOfsNow) / 2;
#if 0
        fprintf(stderr, "seq,%u,rate,%u,size,%u,B-A,%lld,D-C,%lld,Avg,%lld\n",
            testParts->seqNum,
            testParts->pub_rate,
            testParts->pub_size,
            latPlusClockOfsPrev,
            latPlusClockOfsNow,
            transportLatencyAverage);
#endif
        // put into sum/min/max values and update the count
        mTransStats.latSampSum += transportLatencyAverage;
        if (transportLatencyAverage < mTransStats.latMin) mTransStats.latMin = transportLatencyAverage;
        if (transportLatencyAverage > mTransStats.latMax) mTransStats.latMax = transportLatencyAverage;
        mTransStats.latSampCount++;
        mTransStats.dataSizeSum += dataSize;
        mTransStats.pubIntervalSumNsec += testParts->pub_rate;
        
        // check for dropped sample
        if (mPrevSeqNum != 0) {
            mTransStats.droppedSamples += (testParts->seqNum - (mPrevSeqNum + 1));
        }
        mPrevSeqNum = testParts->seqNum;
        

        // check if interval is finished
        if (tLast > mIntervalEnd)
        {
            // move [min/max/sum/count/size/lost] values to export and re-init
            mTransStats.latMean = mTransStats.latSampSum / mTransStats.latSampCount;
            mTransStats.dataSizeMean = mTransStats.dataSizeSum / mTransStats.latSampCount;
            mTransStats.intervalNsec = mIntervalDuration;
            mTransStats.pubIntervalSumNsec /= mTransStats.latSampCount;
            transportStats.push_back(mTransStats);
            perf_data_ready = true;
            // re-init
            mTransStats.dataSizeMean = 0;
            mTransStats.dataSizeSum = 0;
            mTransStats.droppedSamples = 0;
            mTransStats.intervalNsec = 0;
            mTransStats.latMax = 0;
            mTransStats.latMean = 0;
            mTransStats.latMin = 999999999999999;
            mTransStats.latSampCount = 0;
            mTransStats.latSampSum = 0;
            mTransStats.pubIntervalSumNsec = 0;
            mPrevSeqNum = 0;
        }
        return (uint8_t)testParts->testMode;
    }

    // print_perf_data() -- print stuff
    void print_perf_header(void) {
        fprintf(stdout, "dataSize,pubRate,latMin,latMean,latMax,count,dropped,pubRateS,dataRatekBS\n");
    }

    void print_perf_data(void)
    {
        while (transportStats.size()) {
            fprintf(stdout, "%lld,%0.1f,%lld,%lld,%lld,%lld,%d,%0.1f,%3.0f\n",
                transportStats.front().dataSizeMean,
                1000000000.0 / (double)transportStats.front().pubIntervalSumNsec,
                transportStats.front().latMin,
                transportStats.front().latMean,
                transportStats.front().latMax,
                transportStats.front().latSampCount,
                transportStats.front().droppedSamples,
                (double)transportStats.front().intervalNsec / 1000000000.0,
                (1000000000.0 / (double)transportStats.front().pubIntervalSumNsec) * transportStats.front().dataSizeMean
            );
            transportStats.erase(transportStats.begin());
        }
        perf_data_ready = false;
    }

private:
    struct transStats mTransStats;          // struct of transport latency stats data
    uint64_t mIntervalDuration;             // duration of the testing/reporting interval
    uint64_t mIntervalEnd;                  // finish time of testing interval
    uint32_t mPrevSeqNum;                   // sequence number of most-recently-received sample
};