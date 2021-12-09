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
#include "cctypes.hpp"
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

// rti_comms.hpp
// Class for streaming comms using RTI Connext 
class rtiComms
{
public:
    rtiComms(
        const std::string topicName, uint32_t opt_en, 
        dds::domain::DomainParticipant participant,
        dds::core::cond::WaitSet *waitset_ext = NULL,
        int(*rcv_fptr)(dds::sub::DataReader<cctypes::ccBulk>) = NULL);
    ~rtiComms();

    cctypes::ccBulk *get_pub_sample(void) { return &pub_sample; }
    void publish(void);
    void publish(cctypes::ccBulk sample);
    void datarcv_waitset(int32_t secs, uint32_t nsecs) { waitset->dispatch(dds::core::Duration(secs, nsecs)); }

    // pub sample element setters
    void pub_sample_pub_id_set(std::string id) {pub_sample.pub_id(id); }
    void pub_sample_content_type_set(cctypes::payloadTypesEnum pType) {pub_sample.content_type(pType); }
    uint8_t *pub_sample_data(void) { return pub_sample.data().data(); }
    void pub_sample_data_size_set(int32_t newSize) { pub_sample.data().resize(newSize); }

    void pub_sample_tstamp_first_frame(void) { pub_sample.tstamp_first_frame(tstamp_u64_get()); }


    // sub sample
    cctypes::ccBulk pop_sub_sample(void) { 
        cctypes::ccBulk oldestSample = sub_samples.front();
        sub_samples.pop();
        return oldestSample;
    }
    cctypes::ccBulk oldest_sub_sample(void) { return sub_samples.front(); }
    uint32_t sub_samples_in_queue(void) { return (uint32_t)sub_samples.size(); }
    void pop_oldest_sub_sample(void) { sub_samples.pop(); }

private:
    // DDS Topic, DataWriter, DataReader, read data handler, sample
    dds::topic::Topic<cctypes::ccBulk> data_topic;
    dds::pub::DataWriter<cctypes::ccBulk> data_wr;
    dds::sub::DataReader<cctypes::ccBulk> data_rd;
    int rcv_dataProc(dds::sub::DataReader<cctypes::ccBulk> & reader);
    cctypes::ccBulk pub_sample;
    cctypes::ccBulk sub_sample;
    std::queue<cctypes::ccBulk> sub_samples;

    // misc
    dds::core::cond::WaitSet waitset_int;       // internal waitset (if no external provided)
    dds::core::cond::WaitSet *waitset;
    int32_t data_rcv_count;
    //uint32_t pub_seq_count;
};


// Class for measuring streaming comms performance
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
    void pub_sample_latency_min_set(std::vector<int64_t> latMin) { pub_sample.latency_min() = latMin; }
    void pub_sample_latency_mean_set(std::vector<int64_t> latMean) { pub_sample.latency_mean() = latMean; }
    void pub_sample_latency_max_set(std::vector<int64_t> latMax) { pub_sample.latency_max() = latMax; }
    void pub_sample_latency_stddev_set(std::vector<uint64_t> stddev) { pub_sample.latency_stddev() = stddev; }
    void pub_sample_drop_samples_set(uint32_t drops) { pub_sample.samples_dropped(drops); }
    void pub_sample_packets_per_sample_set(uint32_t count) { pub_sample.packets_per_sample(count); }
    void pub_sample_count_samples_set(uint32_t count) { pub_sample.samples_count(count); }
    void pub_sample_count_data_set(uint64_t datacount) { pub_sample.data_count(datacount); }
    void pub_sample_tstart_set(uint64_t tStart) { pub_sample.tStart(tStart); }
    void pub_sample_tduration_set(uint64_t tDuration) { pub_sample.tDuration(tDuration); }
    void pub_sample_last_timestamps_set(std::vector<uint64_t> lasttimes) { pub_sample.timestamps_last() = lasttimes; }

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


// Class for controlling streaming comms publisher
class rtiComPubCtrl
{
public:
    rtiComPubCtrl(
        const std::string topicName, uint32_t opt_en, 
        dds::domain::DomainParticipant participant,
        dds::core::cond::WaitSet *waitset_ext = NULL,
        int(*rcv_fptr)(dds::sub::DataReader<cctypes::ccControl>) = NULL);
    ~rtiComPubCtrl();

    cctypes::ccControl *get_pub_sample(void) { return &pub_sample; }
    void publish(void);
    void publish(cctypes::ccControl sample);
    void datarcv_waitset(int32_t secs, uint32_t nsecs) { waitset->dispatch(dds::core::Duration(secs, nsecs)); }

    // pub sample element setters
    void pub_sample_packets_per_sample_set(uint32_t fps) { pub_sample.packets_per_sample(fps);  }

    // sub sample
    cctypes::ccControl pop_sub_sample(void) { 
        cctypes::ccControl oldestSample = sub_samples.front();
        sub_samples.pop();
        return oldestSample;
    }
    cctypes::ccControl oldest_sub_sample(void) { return sub_samples.front(); }
    uint32_t sub_samples_in_queue(void) { return (uint32_t)sub_samples.size(); }
    void pop_oldest_sub_sample(void) { sub_samples.pop(); }

private:
    // DDS Topic, DataWriter, DataReader, read data handler, sample
    dds::topic::Topic<cctypes::ccControl> data_topic;
    dds::pub::DataWriter<cctypes::ccControl> data_wr;
    dds::sub::DataReader<cctypes::ccControl> data_rd;
    int rcv_dataProc(dds::sub::DataReader<cctypes::ccControl> & reader);
    cctypes::ccControl pub_sample;
    cctypes::ccControl sub_sample;
    std::queue<cctypes::ccControl> sub_samples;

    // misc
    dds::core::cond::WaitSet waitset_int;       // internal waitset (if no external provided)
    dds::core::cond::WaitSet *waitset;
    int32_t data_rcv_count;
};

#endif      // ndef __RTI_COMMS_HPP__
