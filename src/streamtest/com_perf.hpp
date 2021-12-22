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
        intervalSampleCount = 0;        // number of samples in measurement period
        intervalDataCount = 0;          // total bytes sent in period
        intervalActualStart = 0;        // actual start timestamp
        intervalActualDuration = 0;     // actual duration of test interval (nSec)
        intervalSamplesLost = 0;        // total samples dropped
        perf_data_ready = false;
        set_once = false;
        mSampleSeqNumberPrevious = 0;   // previous sample sequence number
        mDataSumInInterval = 0;         // total bytes sent in period
        mSampleSumInInterval = 0;       // number of samples in measurement period
        mSamplesDroppedInInterval = 0;  // number of samples dropped in measurement period
        mIntervalStart = 0;             // start time
        mIntervalDuration = 500000000;  // duration of the testing/reporting interval

    }

//FIXME: remove the 'duration' stuff from here.  Just use init()/reset() and finishCalc().
//        This should be timed/controlled externally.
//    This could also use another implementation that does histograms.   All as an include-file-only solution.

    // Outputs
    std::vector<uint64_t> latencyMin;       // 
    std::vector<uint64_t> latencyMean;      // 
    std::vector<uint64_t> latencyMax;       // 
    std::vector<uint64_t> latencyStdDev;    // 

    uint64_t intervalActualStart;           // start timestamp of this interval
    uint64_t intervalActualDuration;        // actual duration of test interval (nSec)
    uint64_t intervalDataCount;
    uint32_t intervalSampleCount;
    uint32_t intervalSamplesLost;
    bool perf_data_ready;                   // perfdata is ready for local monitoring program, for this interval

    // set test interval
    void interval_set_nsec(uint64_t nsec) { mIntervalDuration = nsec; }
    void interval_set_usec(uint64_t usec) { mIntervalDuration = usec * 1000; }
    void interval_set_msec(uint64_t msec) { mIntervalDuration = msec * 1000000; }

    // returns the size of the output stats vectors
    int32_t stats_size_get(void) { return (int32_t)latencyMin.size(); }

    // reset the totals and vars
    void reset_interval(void) {
    
    }

    // init_sizes() -- call this once to set up sizes
    void init_sizes(int32_t tStampPoints) {
        uint64_t pointCount = tStampPoints - 1;
        latencyMin.resize(pointCount);
        latencyMean.resize(pointCount);
        latencyMax.resize(pointCount);
        latencyStdDev.resize(pointCount);
        mLatencyMin.resize(pointCount);
        mLatencyMax.resize(pointCount);
        mLatencySum.resize(pointCount);
        std::fill(mLatencyMin.begin(), mLatencyMin.end(), (uint64_t)-1);
        std::fill(mLatencySum.begin(), mLatencySum.end(), 0);
        std::fill(mLatencyMax.begin(), mLatencyMax.end(), 0);
        mDataSumInInterval = 0;
        mSampleSumInInterval = 0;
        mSamplesDroppedInInterval = 0;
        set_once = false;
    }

    // update the stats with a new set of timestamps; assumed that the last value will be most-recent
    void update_stats(uint32_t seqNum, uint32_t dataSize, std::vector<uint64_t> newStamps)
    {
        // init on first time
        if (false == set_once) {
            mIntervalStart = newStamps.at(newStamps.size()-1);
            mSampleSeqNumberPrevious = seqNum - 1;
            set_once = true;
        }
        // update with new values
        for (int x = 0; x < newStamps.size()-1; x++) {
            uint64_t tmpVal = newStamps.at(x+1) - newStamps.at(x);
            if (tmpVal < mLatencyMin.at(x)) mLatencyMin.at(x) = tmpVal;
            if (tmpVal > mLatencyMax.at(x)) mLatencyMax.at(x) = tmpVal;
            mLatencySum.at(x) += tmpVal;
        }
        mSampleSumInInterval++;
        mDataSumInInterval += dataSize;
        mSamplesDroppedInInterval += (seqNum - mSampleSeqNumberPrevious - 1);
        mSampleSeqNumberPrevious = seqNum;

        // is it time to calc the stats?
        if (newStamps.at(newStamps.size() - 1) >= mIntervalStart + mIntervalDuration)
        {
            // transfer min/max to outputs
            latencyMin = mLatencyMin;
            latencyMax = mLatencyMax;

            // calculate mean
            for (auto x = 0; x < mLatencySum.size(); x++)
            {
                latencyMean.at(x) = mLatencySum.at(x) / mSampleSumInInterval;
            }

            // calculate stdDev
            // FIXME -- later

            // other values
            intervalDataCount = mDataSumInInterval;            // total bytes sent in period
            intervalSampleCount = mSampleSumInInterval;          // number of samples in measurement period
            intervalSamplesLost = mSamplesDroppedInInterval;     // number of samples dropped in measurement period

            // signal 
            perf_data_ready = true;
        }
    }


private:
    // new
    bool set_once;                          // used to set the size of vectors at the first call
    std::vector<uint64_t> mLatencyMin;      // newly-added timestamps
    std::vector<uint64_t> mLatencySum;      // newly-added timestamps
    std::vector<uint64_t> mLatencyMax;      // newly-added timestamps
    uint32_t mSampleSeqNumberPrevious;      // previous sample sequence number
    uint64_t mDataSumInInterval;            // total bytes sent in period
    uint32_t mSampleSumInInterval;          // number of samples in measurement period
    uint32_t mSamplesDroppedInInterval;     // number of samples dropped in measurement period
    uint64_t mIntervalStart;                // start time
    uint64_t mIntervalDuration;             // duration of the testing/reporting interval

};