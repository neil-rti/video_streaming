/*
* (c) Copyright, Real-Time Innovations, 2021. All rights reserved.
* RTI grants Licensee a license to use, modify, compile, and create derivative
* works of the software solely for use with RTI Connext DDS. Licensee may
* redistribute copies of the software provided that all such copies are subject
* to this license. The software is provided "as is", with no warranty of any
* type, including any warranty for fitness for any purpose. RTI is under no
* obligation to maintain or support the software. RTI shall not be liable for
* any incidental or consequential damages arising out of the use or inability
* to use the software.
*/
#ifndef __RTI_COMMS_HPP__
#define __RTI_COMMS_HPP__
#include <algorithm>
#include <iostream>
#include <queue>
#include <dds/pub/ddspub.hpp>
#include <dds/sub/ddssub.hpp>
#include <dds/core/ddscore.hpp>
#include <rti/util/util.hpp>      // for sleep()
#include <rti/config/Logger.hpp>  // for logging
#include "cc_str_test_types.hpp"
// alternatively, to include all the standard APIs:
//  <dds/dds.hpp>
// or to include both the standard APIs and extensions:
//  <rti/rti.hpp>
//
// For more information about the headers and namespaces, see:
//    https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/api/connext_dds/api_cpp2/group__DDSNamespaceModule.html
// For information on how to use extensions, see:
//    https://community.rti.com/static/documentation/connext-dds/6.1.0/doc/api/connext_dds/api_cpp2/group__DDSCpp2Conventions.html

// defines make more sense here (for a bitfield)
#define CTRL_PUB_BE         (1<<0)
#define CTRL_SUB_BE         (1<<1)
#define CTRL_PUB_REL        (1<<2)
#define CTRL_SUB_REL        (1<<3)

uint64_t tstamp_u64_get(void);

// rti_comm_test.hpp :  Classes for measuring streaming comms performance
// rtiComPerf data is passed between test nodes; timestamps are inserted as the samples are passed
class rtiComPerf
{
public:
    rtiComPerf(
        const std::string topicName, uint32_t opt_en, 
        dds::domain::DomainParticipant participant,
        dds::core::cond::WaitSet *waitset_ext = NULL,
        int(*rcv_fptr)(dds::sub::DataReader<cctypes::ccPerf>) = NULL);
    ~rtiComPerf();

    cctypes::ccPerf *get_pub_sample(void) { return &pub_sample; }
    void publish(void);
    void publish(cctypes::ccPerf sample);
    void datarcv_waitset(int32_t secs, uint32_t nsecs) { waitset->dispatch(dds::core::Duration(secs, nsecs)); }

    // pub sample element setters
    void pub_sample_data_payload_buffer_size(uint32_t newSize) { pub_sample.data_payload().resize(newSize); }
    void pub_sample_pub_id(std::string pubId) { pub_sample.pub_id(pubId); }         // ID string of the HeadNode publisher
    void pub_sample_sequence_id(uint32_t seqId) { pub_sample.sequence_id(seqId); }  // sample sequence number (set by HeadNode)
    void pub_sample_command_mode(cctypes::commandMode commandMode) {                // mode of operation
        pub_sample.command_mode(commandMode);
    }
    void pub_sample_next_data_idx(uint16_t nextIdx) { pub_sample.next_data_idx(nextIdx); }  // index/offset for next open space in timestamp_data
    uint8_t* pub_sample_data_payload_buffer(void) { return pub_sample.data_payload().data(); }

    // sub sample
    cctypes::ccPerf pop_sub_sample(void) { 
        cctypes::ccPerf oldestSample = sub_samples.front();
        sub_samples.pop();
        return oldestSample;
    }
    cctypes::ccPerf oldest_sub_sample(void) { return sub_samples.front(); }
    uint32_t sub_samples_in_queue(void) { return (uint32_t)sub_samples.size(); }
    void pop_oldest_sub_sample(void) { sub_samples.pop(); }

private:
    // DDS Topic, DataWriter, DataReader, read data handler, sample
    dds::topic::Topic<cctypes::ccPerf> data_topic;
    dds::pub::DataWriter<cctypes::ccPerf> data_wr;
    dds::sub::DataReader<cctypes::ccPerf> data_rd;
    int rcv_dataProc(dds::sub::DataReader<cctypes::ccPerf> & reader);
    cctypes::ccPerf pub_sample;
    cctypes::ccPerf sub_sample;
    std::queue<cctypes::ccPerf> sub_samples;

    // misc
    dds::core::cond::WaitSet waitset_int;       // internal waitset (if no external provided)
    dds::core::cond::WaitSet *waitset;
    int32_t data_rcv_count;
};


// Class for controlling streaming comms tester
class rtiComTestControl
{
public:
    rtiComTestControl(
        const std::string topicName, uint32_t opt_en, 
        dds::domain::DomainParticipant participant,
        dds::core::cond::WaitSet *waitset_ext = NULL,
        int(*rcv_fptr)(dds::sub::DataReader<cctypes::ccTestControl>) = NULL);
    ~rtiComTestControl();

    cctypes::ccTestControl *get_pub_sample(void) { return &pub_sample; }
    void publish(void);
    void publish(cctypes::ccTestControl sample);
    void datarcv_waitset(int32_t secs, uint32_t nsecs) { waitset->dispatch(dds::core::Duration(secs, nsecs)); }

    // pub sample element setters

    // sub sample
    cctypes::ccTestControl pop_sub_sample(void) { 
        cctypes::ccTestControl oldestSample = sub_samples.front();
        sub_samples.pop();
        return oldestSample;
    }
    cctypes::ccTestControl oldest_sub_sample(void) { return sub_samples.front(); }
    uint32_t sub_samples_in_queue(void) { return (uint32_t)sub_samples.size(); }
    void pop_oldest_sub_sample(void) { sub_samples.pop(); }

private:
    // DDS Topic, DataWriter, DataReader, read data handler, sample
    dds::topic::Topic<cctypes::ccTestControl> data_topic;
    dds::pub::DataWriter<cctypes::ccTestControl> data_wr;
    dds::sub::DataReader<cctypes::ccTestControl> data_rd;
    int rcv_dataProc(dds::sub::DataReader<cctypes::ccTestControl> & reader);
    cctypes::ccTestControl pub_sample;
    cctypes::ccTestControl sub_sample;
    std::queue<cctypes::ccTestControl> sub_samples;

    // misc
    dds::core::cond::WaitSet waitset_int;       // internal waitset (if no external provided)
    dds::core::cond::WaitSet *waitset;
    int32_t data_rcv_count;
};

// Class for reporting data from the test nodes
class rtiComTestReport
{
public:
    rtiComTestReport(
        const std::string topicName, uint32_t opt_en,
        dds::domain::DomainParticipant participant,
        dds::core::cond::WaitSet* waitset_ext = NULL,
        int(*rcv_fptr)(dds::sub::DataReader<cctypes::ccTestReport>) = NULL);
    ~rtiComTestReport();

    cctypes::ccTestReport * get_pub_sample(void) { return &pub_sample; }
    void publish(void);
    void publish(cctypes::ccTestReport sample);
    void datarcv_waitset(int32_t secs, uint32_t nsecs) { waitset->dispatch(dds::core::Duration(secs, nsecs)); }

    // pub sample element setters
        // number of test (assigned by ccTestControl)
    void pub_sample_test_number(uint32_t testNumber) { pub_sample.test_number(testNumber); }
    // total samples since start of test
    void pub_sample_samples_total(uint32_t samplesTotal) {
        pub_sample.samples_total(samplesTotal);
    }
    // lost samples since start of test
    void pub_sample_lost_samples_total(uint32_t lostSamples) {      
        pub_sample.lost_samples_total(lostSamples);
    }
    // data bytes sent since start of test
    void pub_sample_data_bytes_total(uint64_t dataBytes) {
        pub_sample.data_bytes_total(dataBytes);
    }
    // min/mean/max/stddev of (2-way transport-only latency)/2 - at each segment.
    float* pub_sample_latency_min(void) { return pub_sample.latencyMin().data(); }
    float* pub_sample_latency_mean(void) { return pub_sample.latencyMean().data(); }
    float* pub_sample_latency_max(void) { return pub_sample.latencyMax().data(); }
    float* pub_sample_latency_stddev(void) { return pub_sample.latencyStdDev().data(); }
    // set the size of the output data
    void pub_sample_latency_resize(int newSize) { 
        pub_sample.latencyMin().resize(newSize); 
        pub_sample.latencyMean().resize(newSize);
        pub_sample.latencyMax().resize(newSize);
        pub_sample.latencyStdDev().resize(newSize);
    }
    // return the size of the output
    int32_t pub_sample_latency_size(void) {
        return (int32_t)pub_sample.latencyMin().size();
    }
    
        // sub sample
    cctypes::ccTestReport pop_sub_sample(void) {
        cctypes::ccTestReport oldestSample = sub_samples.front();
        sub_samples.pop();
        return oldestSample;
    }
    cctypes::ccTestReport oldest_sub_sample(void) { return sub_samples.front(); }
    uint32_t sub_samples_in_queue(void) { return (uint32_t)sub_samples.size(); }
    void pop_oldest_sub_sample(void) { sub_samples.pop(); }

private:
    // DDS Topic, DataWriter, DataReader, read data handler, sample
    dds::topic::Topic<cctypes::ccTestReport> data_topic;
    dds::pub::DataWriter<cctypes::ccTestReport> data_wr;
    dds::sub::DataReader<cctypes::ccTestReport> data_rd;
    int rcv_dataProc(dds::sub::DataReader<cctypes::ccTestReport>& reader);
    cctypes::ccTestReport pub_sample;
    cctypes::ccTestReport sub_sample;
    std::queue<cctypes::ccTestReport> sub_samples;

    // misc
    dds::core::cond::WaitSet waitset_int;       // internal waitset (if no external provided)
    dds::core::cond::WaitSet* waitset;
    int32_t data_rcv_count;
};


#endif      // ndef __RTI_COMMS_HPP__
