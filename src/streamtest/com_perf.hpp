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
        mTransStats.dataSizeMean = 0;
        mTransStats.dataSizeSum = 0;
        mTransStats.droppedSamples = 0;
        mTransStats.intervalNsec = 0;
        mTransStats.latMax = 0;
        mTransStats.latMean = 0;
        mTransStats.latMin = 999999999999999;
        mTransStats.latSampCount = 0;
        mTransStats.latSampSum = 0;
    }

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
    uint8_t update_stats(uint64_t tLast, const uint8_t *newStamps, uint32_t dataSize)
    {
        // bytes[7:0] have meta info
        uint32_t seqNum = *(uint32_t*)(newStamps + 0);  // sequence number [3:0]
        uint32_t tmpVal = *(uint32_t*)(newStamps + 4);
        uint32_t nextIdx = tmpVal & 0xfff;              // next open index [6:4]
        uint8_t  myMode = tmpVal >> 24;                 // operating mode  [7]

        // for each link timestamp pair, get (latency+clockOffset) from pub-sub
        // most-recent link is timed from tLast - (last timestamp in newStamps)
        int64_t latencyAndClockOffsetSum = tLast - (*(uint64_t*)(newStamps + nextIdx - sizeof(uint64_t)));
        int32_t linkCount = 1;
        // now get the remaining link times
        uint32_t tmpIdx = nextIdx - (3 * sizeof(uint64_t));
        while (tmpIdx >= (8 + (2 * sizeof(uint64_t)))) {
            // add the (latency + clock offset) of this link to the running sum
            latencyAndClockOffsetSum += (*(uint64_t*)(newStamps + tmpIdx)) - (*(uint64_t*)(newStamps + tmpIdx + sizeof(uint64_t)));
            linkCount++;
            tmpIdx -= (2 * sizeof(uint64_t));
        }

        // in a 2-tester loop, the clock offsets will cancel each other out,
        // leaving us with just the transport latency (x2)
        int64_t transportLatencyAverage = latencyAndClockOffsetSum / linkCount;

        // put into sum/min/max values and update the count
        mTransStats.latSampSum += transportLatencyAverage;
        if (transportLatencyAverage < mTransStats.latMin) mTransStats.latMin = transportLatencyAverage;
        if (transportLatencyAverage > mTransStats.latMax) mTransStats.latMax = transportLatencyAverage;
        mTransStats.latSampCount++;
        mTransStats.dataSizeSum += dataSize;

        // check if interval is finished
        if (tLast > mIntervalEnd)
        {
            // move [min/max/sum/count/size/lost] values to export and re-init
            mTransStats.latMean = mTransStats.latSampSum / mTransStats.latSampCount;
            mTransStats.dataSizeMean = mTransStats.dataSizeSum / mTransStats.latSampCount;
            mTransStats.intervalNsec = mIntervalDuration;
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
        }
        return myMode;
    }

    // printPerfData() -- print stuff
    void print_perf_data(void)
    {
        while (transportStats.size()) {
            fprintf(stdout, "%lld,%lld,%lld,%lld,%lld,%d,%lld\n",
                transportStats.front().dataSizeMean,
                transportStats.front().latMin,
                transportStats.front().latMean,
                transportStats.front().latMax,
                transportStats.front().latSampCount,
                transportStats.front().droppedSamples,
                transportStats.front().intervalNsec);
            transportStats.erase(transportStats.begin());
        }
        perf_data_ready = false;
    }

private:
    // new new
    struct transStats mTransStats;          // struct of transport latency stats data
    uint64_t mIntervalDuration;             // duration of the testing/reporting interval
    uint64_t mIntervalEnd;                  // finish time of testing interval
};