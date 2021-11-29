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
 * vstream_mon: Performance monitoring for video streaming app.
 **/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <thread>                 // thread for keyboard input(blocking)
#include <queue>                  // queue for passing keyboard entries
#ifndef WIN32
#include <poll.h>                 // stdio polling
#endif
#include <signal.h>               // ctrl-c handler
#include <rti/util/util.hpp>      // for sleep()
#include "rti_comms.hpp"          // for Connext pub/sub
#include "murmurhash3.h"          // for hashing
#include "com_perf.hpp"           // for latency measurement
#include "app_helper.hpp"         // for command line args and signals

std::queue<std::string> keyq;     // for passing keyboard entries

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
 * perf_data_sub()
 * handler for received performance data samples from Connext datareader
 **/
int perf_data_sub(dds::sub::DataReader<cctypes::ccPerf> reader)
{
  // Take all samples
  int count = 0;
  dds::sub::LoanedSamples<cctypes::ccPerf> samples = reader.take();
  for (const auto& sample : samples) {
    if (sample.info().valid()) {
      // std::cout << "perfdata: " << sample.data() << std::flush; // std::endl;
      // print to terminal just the important elements:
      std::cout << '\r'
                << "dds[f]: " << std::setw(3) << sample.data().frames_per_sample() 
                << " fps: " << std::setw(3) 
                << ((sample.data().frames_per_sample() * sample.data().samples_count()) 
                  / (static_cast<double>(sample.data().tDuration()) / 1000000000))
                << " lat(mS):[" << std::setw(6) << (static_cast<double>(sample.data().latency_mean().at(0)) / 10000000) 
                << " | " << std::setw(6) << (static_cast<double>(sample.data().latency_mean().at(1)) / 10000000) 
                << " | " << std::setw(6) << (static_cast<double>(sample.data().latency_mean().at(2)) / 10000000) 
                << "]: " << std::flush;
      count++;
    } else {
      std::cout << "Instance state changed to "
        << sample.info().state().instance_state() << std::endl;
    }
  }
  return count;
}

/** ----------------------------------------------------------------
 * kb_thread()
 * keyboard input thread function
 **/
void kb_thread(void) 
{
  bool loop_again = true;
  while(loop_again) {
    std::string keyin;
    std::cin >> keyin;
    keyq.push(keyin);
    loop_again = (keyin != "q");
  }
  std::cout << "kb_thread() exiting" << std::endl;
}

/** ----------------------------------------------------------------
 * participant_main()
 **/
void participant_main(application::ApplicationArguments args)
{  
  // setup ----------------------------------------------------
  // convert names to ID strings (used as DDS topic name)
  std::string myId, farId;
  contact_name_to_id(args.near_name, myId);
  contact_name_to_id(args.far_name, farId);
  fprintf(stderr, "myId:  [%s], myName:  '%s'\n", myId.c_str(), args.near_name.c_str());
  fprintf(stderr, "%s\n", args.pub_else_sub ? "publishing to" : "subcribing to");
  fprintf(stderr, "FarID: [%s], FarName: '%s'\n", farId.c_str(), args.far_name.c_str());

  // Create a DomainParticipant with default Qos, 
  // and class instances for receiving performance data & publishing control data
  dds::domain::DomainParticipant participant(args.domain_id);
  dds::core::cond::WaitSet waitset;
  // we receive performance data from the video subscriber
  rtiComPerf perfRep(std::string("m" + farId), CTRL_SUB_BE, participant, &waitset, &perf_data_sub);
  // and publish control data to the video publisher.
  rtiComPubCtrl vidCtrl(std::string("c" + myId), CTRL_PUB_BE, participant);

  // init control sample?
  vidCtrl.pub_sample_frames_per_sample_set(7);

  // launch thread for keyboard input
  std::thread thkey(kb_thread);
  thkey.detach();

  // loop 
  while (false == application::shutdown_requested) {
    // check for keyboard entry
    while(!keyq.empty()) {
      uint32_t fps = 0;
      std::string key_entry = keyq.front();
      keyq.pop();
      if (key_entry == "q") {
        application::stop_handler(1);
      }
      else if((fps = strtoul(key_entry.c_str(), NULL, 10)) != 0) {
        // there's a valid number entry (for the frames-per-sample value)
        std::cout << "New fps: " << fps << std::endl;
        vidCtrl.pub_sample_frames_per_sample_set(fps);
        vidCtrl.publish();
      }
    }


    // check for received perfdata
    waitset.dispatch(dds::core::Duration(0, 20000000));

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
