/** ----------------------------------------------------------------
 * com_perf.hpp
 * Class for measuring latency performance 
 * in the video streaming example.
 **/
#pragma once
#include <vector>
#include <algorithm>
#include <stdint.h>

class comPerf
{
    // vars for performance (latency) measurements
    // NPI: add monotonicity measurement too.  Do datarate per period.  Make period be adjustable (in S/mS/uS/nS)
    /*
        To accommodate the measurements:
        IN:     Timestamps<4>, considered to be sequential/in-order.  Could be more or less 
        OUT:    for each tstamp: min/mean/max/stddev of its abs time(or rate) <4>
                for each delta:  min/mean/max/stddev of its neighbor delta (<4> if between-sample time is included)
                datarate, samplerate for interval
                dropped sample count
                interval_finished
        In-process:
                previous timestamps
                previous sample sequence number
                sums/mins/maxes of latencies (period and total)
                sum of datasizes (period and total)
                counts of samples (period and total)
                count of dropped samples (period and total)
                interval duration
                interval start time
    */


public:
    // comPerf() // FIXME: build constructors
    comPerf() : tStampData(4), latencyMin(4), latencyMax(4), latencyMean(4), latencyStdDev(4) 
    {
        latencyMin = { -99999999999 };  // minimum latency in this interval
        latencyMax = { 0 };             // maximum latency in this interval
        latencyMean = { 0 };            // sums of latencies in this interval
        latencyStdDev = { 0 };          // standard deviation of latencies in this interval
        samplesInInterval = 0;          // number of samples in measurement period
        dataSumInInterval = 0;          // total bytes sent in period
        intervalActualStart = 0;        // actual start timestamp
        intervalActualDuration = 0;     // actual duration of test interval (nSec)
        dropCount = 0;                  // total samples dropped
        framesPerSample = 0;
        tStampPrevious.resize(4);
        tLatencyMin.resize(4);
        tLatencyMax.resize(4);
        tLatencySum.resize(4);
        latencyMin.resize(4);
        latencyMax.resize(4);
        latencyMean.resize(4);
        latencyStdDev.resize(4);
        perf_data_ready = false;
    }

    // Inputs
    std::vector<uint64_t> tStampData;       // nSec timestamps at different points in the pipe
    // Outputs
    std::vector<int64_t> latencyMin;        // minimum latency in this interval
    std::vector<int64_t> latencyMax;        // maximum latency in this interval
    std::vector<int64_t> latencyMean;       // sums of latencies in this interval
    std::vector<uint64_t> latencyStdDev;    // standard deviation of latencies in this interval
    uint32_t samplesInInterval;             // number of samples in measurement period
    uint64_t dataSumInInterval;             // total bytes sent in period
    uint64_t intervalActualStart;           // start timestamp of this interval
    uint64_t intervalActualDuration;        // actual duration of test interval (nSec)
    uint32_t dropCount;                     // total samples dropped
    uint32_t framesPerSample;               // 188-byte frames per sample
    bool perf_data_ready;                   // new performance data for interval is ready


    void interval_set_nsec(uint64_t nsec) { intervalDuration = nsec; }
    void interval_set_usec(uint64_t usec) { intervalDuration = usec * 1000; }
    void interval_set_msec(uint64_t msec) { intervalDuration = msec * 1000000; }

    // perf_data_new(): call this after updating the values in tStampData<>
    void perf_data_new(uint32_t seqnum, uint32_t datasize, uint32_t dataoverhead) {
        // is the interval over?
        if(tStampData.at(tQty-1) > intervalEndTime) {
            if(intervalSampleCount) {
                // move results, signal export, reset interval vars
                latencyMin = tLatencyMin;
                latencyMax = tLatencyMax;
                for(int i=0 ; i<tQty ; i++) {
                    latencyMean.at(i) = tLatencySum.at(i) / intervalSampleCount;
                    latencyStdDev.at(i) = 0;
                }
                samplesInInterval = intervalSampleCount;
                dataSumInInterval = intervalDataSum;
                intervalActualDuration = tStampData.at(tQty-1) - intervalStartTime;
                intervalActualStart = intervalStartTime;
                framesPerSample = datasize / 188;
                perf_data_ready = true;
            }
            // re-init
            for(int i=0 ; i<tQty ; i++) {
                tLatencyMin.at(i) = -999999999999;
                tLatencyMax.at(i) = 0;
                tLatencySum.at(i) = 0;
            }
            intervalSampleCount = 0;
            intervalDataSum = 0;
            intervalStartTime = tStampData.at(tQty-1);
            intervalEndTime = intervalStartTime + intervalDuration;
            dropCount = 0;
        }

        // any dropped sequence numbers?
        if((sampleSeqNumberPrevious != 0) && (seqnum != (sampleSeqNumberPrevious + 1))) {
            dropCount = seqnum - sampleSeqNumberPrevious - 1;
        }
        sampleSeqNumberPrevious = seqnum;

        // calculate latencies (diffs between tStamps)
        uint64_t tDelta = tStampData.at(1) - tStampData.at(0);          // pub add to send buffer -to- pub send delay
        if(tDelta < tLatencyMin.at(0)) tLatencyMin.at(0) = tDelta;
        if(tDelta > tLatencyMax.at(0)) tLatencyMax.at(0) = tDelta;
        tLatencySum.at(0) += tDelta;
        
        tDelta = tStampData.at(2) - tStampData.at(1);                   // pub send -to- sub receive delay
        if(tDelta < tLatencyMin.at(1)) tLatencyMin.at(1) = tDelta;
        if(tDelta > tLatencyMax.at(1)) tLatencyMax.at(1) = tDelta;
        tLatencySum.at(1) += tDelta;

        tDelta = tStampData.at(3) - tStampData.at(2);                   // sub receive -to- sub app delay
        if(tDelta < tLatencyMin.at(2)) tLatencyMin.at(2) = tDelta;
        if(tDelta > tLatencyMax.at(2)) tLatencyMax.at(2) = tDelta;
        tLatencySum.at(2) += tDelta;

        tDelta = tStampData.at(3) - tStampPrevious.at(3);               // previous sample sub app -to- this sample sub app
        if(tDelta < tLatencyMin.at(3)) tLatencyMin.at(3) = tDelta;
        if(tDelta > tLatencyMax.at(3)) tLatencyMax.at(3) = tDelta;
        tLatencySum.at(3) += tDelta;

        // add to totals
        totalSampleCount++;
        intervalSampleCount++;
        totalDataSum += (datasize + dataoverhead);
        intervalDataSum += (datasize + dataoverhead);
        tStampPrevious = tStampData;
    }


private:
    // internal
    int tQty = 4;       // FIXME
    // interval stats
    uint64_t intervalDuration;              // duration of the testing/reporting interval
    uint64_t intervalStartTime;             // start time (nSec) of test interval
    uint64_t intervalEndTime;               // start+duration, here for convenience
    uint32_t intervalSampleCount;           // number of samples in measurement period
    uint64_t intervalDataSum;               // total bytes sent in period
    uint32_t sampleSeqNumberPrevious;       // previous sample sequence number
    std::vector<uint64_t> tStampPrevious;   // previous timestamps from the application
    std::vector<int64_t> tLatencyMin;      // minimum latency in this interval
    std::vector<int64_t> tLatencyMax;      // maximum latency in this interval
    std::vector<int64_t> tLatencySum;      // sums of latencies in this interval

    // total stats
    uint32_t totalSampleCount;              // number of samples in measurement period
    uint64_t totalDataSum;                  // total bytes sent in period
};