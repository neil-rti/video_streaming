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
/**
 * ffmpeg_stdio: Video streaming app to work with external FFMPEG via stdio
 **/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <poll.h>                 // stdio polling
#include <signal.h>               // ctrl-c handler
#include <rti/util/util.hpp>      // for sleep()
#include "rti_comms.hpp"          // for Connext pub/sub
#include "murmurhash3.h"          // for hashing
#include "app_helper.hpp"         // for command line args and signals

// a few globals for convenience (measuring performance)
// in-process vars
uint64_t tPeriodNanosecs = 200000000;   // measurement period: 200mS
uint64_t tPeriodStart = 0;        // start of measurement period
uint64_t tLatencySums[3];         // sums of latencies between dataflow points
uint64_t tLatencyMins[3];         // minimum latency between dataflow points
uint64_t tLatencyMaxs[3];         // maximum latency between dataflow points
uint32_t samplesInPeriod = 0;     // number of samples in measurement period
uint64_t dataSizeInPeriod = 0;    // total bytes sent in period
uint32_t dropCount = 0;           // total samples dropped
uint32_t lastSeqNum = 0;          // last seq. number (to detect drops)

// finished data from a period, ready to be sent
bool perf_data_ready = false;     // data is ready to copy and send            
uint64_t rStart = 0;              // start of this measuring period
uint64_t rEnd = 0;                // end of this measuring period
uint32_t rSamples_count = 0;      // count of samples this period
uint32_t rSamples_dropped = 0;    // count of dropped samples (total)
uint64_t rLatency_min[3];         //  min latency at firstFrameInSendBuf[0], transport[1], rcvToAppReady[2]
uint64_t rLatency_mean[3];        // mean latency at firstFrameInSendBuf[0], transport[1], rcvToAppReady[2]
uint64_t rLatency_max[3];         //  max latency at firstFrameInSendBuf[0], transport[1], rcvToAppReady[2]

// overall stats
uint32_t totalSampleCount = 0;
uint64_t totalDataSize = 0;

/** ----------------------------------------------------------------
 * contact_name_to_id()
 * create a hash of the name, convert to BASE64 and produce an ID
 * composed of: [first 1-3 chars of name][5-7 chars of BASE64 hash (30 bit equiv)]
 * This is done to make a consistent size, human-readable ID from the name string.
 **/
void contact_name_to_id(std::string name, std::string &id)
{
  // get a hash of the name string, convert to BASE64 string
  uint64_t nameHash[2];
  uint32_t hashSeed = 0x0ec3d821;   // no significance to this number, other that it is prime
  MurmurHash3_x64_128( name.c_str(), name.size(), hashSeed, &nameHash);

  char b64[9];
  for(int i=0 ; i<8 ; i++) {
    if((nameHash[0] & 0x3f) < 26)        { b64[i] = 'A' + (nameHash[0] & 0x3f);  }
    else if((nameHash[0] & 0x3f) < 52)   { b64[i] = 'a' + ((nameHash[0] & 0x3f) - 26); }
    else if((nameHash[0] & 0x3f) < 62)   { b64[i] = '0' + ((nameHash[0] & 0x3f) - 52); }
    else if ((nameHash[0] & 0x3f) == 62) { b64[i] = '+'; }
    else { b64[i] = '/'; }
    nameHash[0] = (nameHash[0] >> 6) | ((nameHash[1] & 0x3f) << 58);
    nameHash[1] = nameHash[1] >> 6;
  }
  b64[8] = 0;

  // now construct the ID from: [first 1-3 chars of name : 7-5 char BASE64 hash] = 8-char total
  size_t nameLen = name.size();
  if(nameLen > 3) nameLen = 3;
  size_t b64Len = 8-nameLen;
  int i=0;
  while(nameLen--) {
    id.push_back(name.at(i++));
  }
  while(b64Len--) {
    id.push_back(b64[i++]);
  }
}

/** ----------------------------------------------------------------
 * vid_data_sub()
 * handler for received samples from Connext datareader
 **/
int vid_data_sub(dds::sub::DataReader<cctypes::ccBulk> reader)
{
    // Take all samples
    int count = 0;
    dds::sub::LoanedSamples<cctypes::ccBulk> samples = reader.take();
    for (const auto& sample : samples) {
      if (sample.info().valid()) {
        // measure latencies and accumulate results
        uint64_t tRcvApp = tstamp_u64_get();
        uint64_t tLat[3];
        tLat[0] = (sample.info().source_timestamp().to_microsecs() * 1000) - sample.data().tstamp_first_frame();
        tLat[1] = (sample.info().extensions().reception_timestamp().to_microsecs() * 1000) - (sample.info().source_timestamp().to_microsecs() * 1000);
        tLat[2] = tRcvApp - (sample.info().extensions().reception_timestamp().to_microsecs() * 1000);
        for(int t=0 ; t<3 ; t++) {
          if(tLat[t] < tLatencyMins[t]) tLatencyMins[t] = tLat[t];
          if(tLat[t] > tLatencyMaxs[t]) tLatencyMaxs[t] = tLat[t];
          tLatencySums[t] += tLat[t];          
        }
        samplesInPeriod++;
        totalSampleCount++;
        dataSizeInPeriod += (25 + sizeof(cctypes::payloadTypesEnum) + sample.data().data().size());
        totalDataSize += (25 + sizeof(cctypes::payloadTypesEnum) + sample.data().data().size());

        if((lastSeqNum != 0) && (sample.info().extensions().publication_sequence_number().value() != (lastSeqNum + 1))) {
          dropCount++;
        }
        lastSeqNum = sample.info().extensions().publication_sequence_number().value();


        // is it time to finish the measurement period?
        if((tPeriodStart + tPeriodNanosecs) < tRcvApp)
        {
          // update the ready-to-send global values
          rStart = tPeriodStart;
          rEnd = tRcvApp;
          rSamples_count = samplesInPeriod;
          rSamples_dropped = dropCount;
          for(int i=0 ; i<3 ; i++)
          {
            rLatency_min[i] = tLatencyMins[i];
            rLatency_max[i] = tLatencyMaxs[i];
            rLatency_mean[i] = tLatencySums[i] / samplesInPeriod;
          }
          perf_data_ready = true;

          // now reset the in-process vars for the next period.
          for(int i=0 ; i<3 ; i++) {
            tLatencyMins[i] = (uint64_t)-1;
            tLatencyMaxs[i] = 0;
            tLatencySums[i] = 0;
          }
          samplesInPeriod = 0;
          dataSizeInPeriod = 0;
          tPeriodStart = tRcvApp;
        }

        // write the data to external FFMPEG via stdio
        const size_t size = sample.data().data().size();
        uint32_t chunk = 0;
        for (size_t i = 0; i < size;) {
          if((size-i) > 188) { chunk = 188; } else { chunk = (size-i); }
          i += ::write(1, sample.data().data().data() + i, chunk);
        }
        count++;
      } else {
        std::cout << "Instance state changed to "
          << sample.info().state().instance_state() << std::endl;
      }
    }
    return count; 
}


/** ----------------------------------------------------------------
 * participant_main()
 **/
void participant_main(application::ApplicationArguments args)
{
  // Create a DomainParticipant with default Qos
  dds::domain::DomainParticipant participant(args.domain_id);

  // Instantiate an rticomms class, with BestEffort pub or sub
  uint32_t cnxDir = 0;
  if(args.pub_else_sub) {
    cnxDir = CTRL_PUB_BE;
  }
  else {
    cnxDir = CTRL_SUB_BE;
  }
  dds::core::cond::WaitSet waitset;
  rtiComms cnxStream(args.topic_name, cnxDir, participant, &waitset, &vid_data_sub);
  
  // setup ----------------------------------------------------
  // convert names to ID strings (used as Keys in DDS topic)
  std::string myId, farId;
  contact_name_to_id(args.near_name, myId);
  contact_name_to_id(args.far_name, farId);
  fprintf(stderr, "myId:  [%s], myName:  '%s'\n", myId.c_str(), args.near_name.c_str());
  fprintf(stderr, "%s\n", args.pub_else_sub ? "publishing to" : "subcribing to");
  fprintf(stderr, "FarID: [%s], FarName: '%s'\n", farId.c_str(), args.far_name.c_str());
  fprintf(stderr, "on topic %s\n", args.topic_name.c_str());

  // publisher -----------------------------------------
  if(args.pub_else_sub) {
    cnxStream.pub_sample_source_id_set(myId);
    cnxStream.pub_sample_destination_id_set(farId);
    cnxStream.pub_sample_data_size_set(args.pub_data_size);
    cnxStream.pub_sample_content_type_set(cctypes::payloadTypesEnum::STREAM_FFMPEG_0);

    uint32_t i = 0;
    bool new_frame_group = true;
    while(false == application::shutdown_requested) {
      // poll for stdin
      pollfd fd{0, POLLIN, 0};
      if (::poll(&fd, 1, 100) > 0) {
        i += ::read(fd.fd, cnxStream.pub_sample_data() + i, 188);
        if(new_frame_group) {
          cnxStream.pub_sample_tstamp_first_frame();
          new_frame_group = false;
        }
        if(i >= args.pub_data_size) {
          i=0;
          new_frame_group = true;
          while (false == application::shutdown_requested) {
            try {
              cnxStream.publish();
              break;
            } catch (...) {
              std::cerr << "Write operation timed out, retrying..." << std::endl;
            }
          }
        }
      }
    }
  }
  else {  // subscriber
    // create a publisher of the latency measurements
    rtiComPerf perfPub("testTopicName", CTRL_PUB_BE, participant);
    perfPub.pub_sample_source_id_set(myId);
    perfPub.pub_sample_destination_id_set(farId);
    while (false == application::shutdown_requested) {
      waitset.dispatch(dds::core::Duration(0, 50000));

      // time to publish performance results?
      if(perf_data_ready) {
        perfPub.pub_sample_latency_min_set(rLatency_min);
        perfPub.pub_sample_latency_mean_set(rLatency_mean);
        perfPub.pub_sample_latency_max_set(rLatency_max);
        perfPub.pub_sample_count_samples_set(rSamples_count);
        perfPub.pub_sample_drop_samples_set(rSamples_dropped);
        perfPub.pub_sample_tstart_set(rStart);
        perfPub.pub_sample_tend_set(rEnd);
        perfPub.publish();
        perf_data_ready = false;
      }
    }
  }
}

/** ----------------------------------------------------------------
 * main()
 * arguments are handled in 'app_helper.hpp'
 **/
int main(int argc, char *argv[])
{
    using namespace application;

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    } else if (arguments.parse_result == ParseReturn::failure) {
        return EXIT_FAILURE;
    }
    setup_signal_handlers();

    // Sets Connext verbosity to help debugging
    rti::config::Logger::instance().verbosity(arguments.verbosity);
  
    try {
        participant_main(arguments);
    }
    catch (const std::exception& ex) {
        // This will catch DDS exceptions
        std::cerr << "Exception in participant_main(): " << ex.what() << std::endl;
        return -1;
    }

    // RTI Connext provides a finalize_participant_factory() method
    // if you want to release memory used by the participant factory singleton.
    // Uncomment the following line to release the singleton:
    //
    // dds::domain::DomainParticipant::finalize_participant_factory();

    return 0;
}
