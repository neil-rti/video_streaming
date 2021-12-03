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
#include <thread>                 // thread for UDP input from ffmpeg(blocking)
#include <signal.h>               // ctrl-c handler
#ifdef WIN32
#include <WinSock2.h>
#else
#include <arpa/inet.h>            // htons, inet_addr
#include <netinet/in.h>           // sockaddr_in
#include <sys/types.h>            // uint16_t
#include <sys/socket.h>           // socket, sendto
#include <unistd.h>               // close
#endif
#include <rti/util/util.hpp>      // for sleep()
#include "rti_comms.hpp"          // for Connext pub/sub
#include "murmurhash3.h"          // for hashing
#include "com_perf.hpp"           // for latency measurement
#include "app_helper.hpp"         // for command line args and signals

// class for measuring perf/latency
comPerf perfRep;

// UDP socket connection to FFMPEG
std::string hostname("127.0.0.1");
uint16_t port_base = 2277;
sockaddr_in destination;
char* tmpBuf;
const int tmpBufMax = 131072;
int inx, outx, rollx;
uint64_t intot, outtot;

#ifdef WIN32
SOCKET destSocket = INVALID_SOCKET;
#else  // Linux
int sock;
#endif



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
  MurmurHash3_x64_128( name.c_str(), (int)name.size(), hashSeed, &nameHash);

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
      perfRep.tStampData.at(0) = sample.data().tstamp_first_frame();
      perfRep.tStampData.at(1) = (sample.info().source_timestamp().to_microsecs() * 1000);
      perfRep.tStampData.at(2) = (sample.info().extensions().reception_timestamp().to_microsecs() * 1000);
      perfRep.tStampData.at(3) = tRcvApp;
      const size_t size = sample.data().data().size();
      perfRep.perf_data_new((uint32_t)sample.info().extensions().publication_sequence_number().value(), (uint32_t)size,
                            (uint32_t)(16 + sizeof(cctypes::payloadTypesEnum)));


      // write the data to external FFMPEG via UDP socket
      uint32_t chunk = 0;
      for (size_t i = 0; i < size;) {
          if ((size - i) > 188) { chunk = 188; }
          else { chunk = (uint32_t)(size - i); }
#ifdef WIN32
          i += sendto(destSocket, reinterpret_cast<const char*>(sample.data().data().data() + i),
              chunk, 0, (sockaddr*)&destination, sizeof(destination));
#else
          i += ::sendto(sock, sample.data().data().data() + i, chunk, 0,
              reinterpret_cast<sockaddr*>(&destination), sizeof(destination));
#endif
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
 * udpInputThread()
 * Use a separate thread for receiving UDP input from FFMPEG
 **/
void udpInputThread(void)
{
#ifdef WIN32
    WSADATA wsaData;
    int res = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (res != NO_ERROR) {
        printf("WSAStartup failed with error %d\n", res);
        return;
    }

    destSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (destSocket == INVALID_SOCKET) {
        printf("socket failed with error %d\n", WSAGetLastError());
        return;
    }

    // Bind the socket to the specified address and port.
    destination.sin_family = AF_INET;
    destination.sin_port = htons(port_base);
    destination.sin_addr.s_addr = inet_addr(hostname.c_str());

    if (bind(destSocket, (SOCKADDR*)&destination, sizeof(destination))) {
        printf("bind failed with error %d\n", WSAGetLastError());
        return;
    }
    int destAddrSize = sizeof(destination);
#else   // Linux
    sock = ::socket(AF_INET, SOCK_DGRAM, 0);
    destination.sin_family = AF_INET;
    destination.sin_port = htons(port_base);
    destination.sin_addr.s_addr = inet_addr(hostname.c_str());

    //checks connection
    if (bind(sock, (struct sockaddr*)&destination, sizeof(destination)) < 0) {
        std::cout << "UDP Connection error" << std::endl;
    }

#endif
    int udp_bytes_rcvd = 0;

    while (false == application::shutdown_requested)
    {
        // this call blocks until data is received
#ifdef WIN32
        udp_bytes_rcvd = recvfrom(destSocket, &tmpBuf[inx], 1504,
            0, (SOCKADDR*)&destination, &destAddrSize);
        if (udp_bytes_rcvd == SOCKET_ERROR) {
            printf("recvfrom failed with error %d\n", WSAGetLastError());
        }
#else   // Linux
        int udp_bytes_rcvd = recv(sock, &tmpBuf[inx], 2048, 0);
        if (udp_bytes_rcvd < 0) {
            std::cout << "recv failed" << std::endl;
        }
#endif
        intot += udp_bytes_rcvd;
        inx += udp_bytes_rcvd;

        if (inx > rollx) rollx = inx;

        // wrap the buffer when approaching the end,
        // or if in the upper half and had just gotten a short chunk
        // (this should help to align tmpBuf with the MPEG-TS packets)
        if (((inx > (tmpBufMax / 2)) && (udp_bytes_rcvd < 1472))
            || ((inx + 1472) >= tmpBufMax))
        {
            rollx = inx;
            inx = 0;
        }
    }
    return;
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
//  fprintf(stderr, "on topic %s\n", args.topic_name.c_str());

  // Create a DomainParticipant with default Qos
  dds::domain::DomainParticipant participant(args.domain_id);

  // Instantiate an rticomms class, with BestEffort pub or sub
  uint32_t cnxDir = 0;
  std::string topicId;
  if(args.pub_else_sub) {
    cnxDir = CTRL_PUB_BE;
    topicId = "v" + farId;
  }
  else {
    cnxDir = CTRL_SUB_BE;
    topicId = "v" + myId;
  }
  dds::core::cond::WaitSet waitset;
  rtiComms cnxStream(topicId, cnxDir, participant, &waitset, &vid_data_sub);

  // publisher -----------------------------------------
  if(args.pub_else_sub) {
    cnxStream.pub_sample_data_size_set(args.pub_data_size);
    cnxStream.pub_sample_content_type_set(cctypes::payloadTypesEnum::STREAM_FFMPEG_0);
    rtiComPubCtrl ctrlSub(std::string("c" + myId), CTRL_SUB_BE, participant, &waitset);

#if 0
#ifdef WIN32    // open a UDP socket to FFMPEG
    WSADATA wsaData;
    int res = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (res != NO_ERROR) {
        printf("WSAStartup failed with error %d\n", res);
        return;
    }

    destSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (destSocket == INVALID_SOCKET) {
        printf("socket failed with error %d\n", WSAGetLastError());
        return;
    }

    // Bind the socket to the specified address and port.
    destination.sin_family = AF_INET;
    destination.sin_port = htons(port_base);
    destination.sin_addr.s_addr = inet_addr(hostname.c_str());

    if (bind(destSocket, (SOCKADDR*)&destination, sizeof(destination))) {
        printf("bind failed with error %d\n", WSAGetLastError());
        return;
    }
    int destAddrSize = sizeof(destination);

#else
    sock = ::socket(AF_INET, SOCK_DGRAM, 0);
    destination.sin_family = AF_INET;
    destination.sin_port = htons(port_base);
    destination.sin_addr.s_addr = inet_addr(hostname.c_str());

    //checks connection
    if (bind(sock, (struct sockaddr *)&destination, sizeof(destination)) < 0) {
      std::cout << "UDP Connection error" << std::endl;
    }
    std::cout << "UDP Connected" << std::endl;
#endif
#endif
    tmpBuf = (char *)calloc(tmpBufMax, sizeof(char));
    if (NULL == tmpBuf) {
        fprintf(stderr, "Memory Allocation error\n");
        exit(-1);
    }

    inx = outx = 0;
    rollx = tmpBufMax;
    intot = outtot = 0;

    // launch thread for udp input from FFMPEG
    std::thread thrudp(udpInputThread);
    thrudp.detach();

    bool new_frame_group = true;
    int sendBufIdx = 0;
    volatile int checkForControl = 500000000;
    int loopcount = 0;

    while (false == application::shutdown_requested) {
        //rti::util::sleep(dds::core::Duration(0, 10000));
        // debug
        if((intot-outtot) > args.pub_data_size)
        {
            // skip the alignment for now -- just pack and ship
            if ((outx + (int)args.pub_data_size) <= rollx)
            {
                memcpy(cnxStream.pub_sample_data(), &tmpBuf[outx], args.pub_data_size);
                outx += args.pub_data_size;
            }
            else {
                memcpy(cnxStream.pub_sample_data(), &tmpBuf[outx], rollx-outx);
                memcpy(cnxStream.pub_sample_data() + (rollx-outx), &tmpBuf[0], args.pub_data_size - (rollx - outx));
                outx = args.pub_data_size - (rollx - outx);
            }
            outtot += args.pub_data_size;
            // new_frame_group = true;
            while (false == application::shutdown_requested) {
                try {
                    cnxStream.publish();
                    sendBufIdx = 0;
                    break;
                }
                catch (...) {
                    std::cerr << "Write operation timed out, retrying..." << std::endl;
                }
            }
            cnxStream.pub_sample_tstamp_first_frame();
        }

        // check for any control samples
        if (--checkForControl <= 0)
        {
            waitset.dispatch(dds::core::Duration(0, 20000));
            if (ctrlSub.sub_samples_in_queue()) {
                uint32_t newSize = ctrlSub.oldest_sub_sample().frames_per_sample();
                fprintf(stderr, "New size: %u\n", newSize);
                args.pub_data_size = newSize * 188;
                cnxStream.pub_sample_data_size_set(args.pub_data_size);
                ctrlSub.pop_oldest_sub_sample();
            }
            checkForControl = 500000000;
            fprintf(stdout, "Check %d\n", ++loopcount);
        }
    }
  }
  else {  // subscriber
    // create a publisher of the latency measurements
    rtiComPerf perfPub(std::string("m" + myId), CTRL_PUB_BE, participant);
    perfRep.interval_set_msec(200);


#ifdef WIN32    // open a UDP socket to FFPLAY
    WSADATA wsaData;
    int res = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (res != NO_ERROR) {
        printf("WSAStartup failed with error %d\n", res);
        return;
    }

    destSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (destSocket == INVALID_SOCKET) {
        printf("socket failed with error %d\n", WSAGetLastError());
        WSACleanup();
        return;
    }

    
    // set up to send to loopback address and the specified port.
    destination.sin_family = AF_INET;
    destination.sin_port = htons(port_base + 1);
    destination.sin_addr.s_addr = inet_addr(hostname.c_str());


#else
    sock = ::socket(AF_INET, SOCK_DGRAM, 0);
    destination.sin_family = AF_INET;
    destination.sin_port = htons(port_base + 1);
    destination.sin_addr.s_addr = inet_addr(hostname.c_str());

    if (connect(sock, (struct sockaddr *)&destination, sizeof(destination)) < 0) {
      std::cout << "UDP Connection error" << std::endl;
    }
    std::cout << "UDP Connected" << std::endl;
#endif
    while (false == application::shutdown_requested) {
      waitset.dispatch(dds::core::Duration(0, 50000));

      // time to publish performance results?
      if(perfRep.perf_data_ready) {
#if 1
        perfPub.pub_sample_latency_min_set(perfRep.latencyMin);
        perfPub.pub_sample_latency_mean_set(perfRep.latencyMean);
        perfPub.pub_sample_latency_max_set(perfRep.latencyMax);
        perfPub.pub_sample_latency_stddev_set(perfRep.latencyStdDev);
        perfPub.pub_sample_count_samples_set(perfRep.samplesInInterval);
        perfPub.pub_sample_count_data_set(perfRep.dataSumInInterval);
        perfPub.pub_sample_drop_samples_set(perfRep.dropCount);
        perfPub.pub_sample_frames_per_sample_set(perfRep.framesPerSample);
        perfPub.pub_sample_tstart_set(perfRep.intervalActualStart);
        perfPub.pub_sample_tduration_set(perfRep.intervalActualDuration);
        perfPub.publish();
#else
        for(int i=0 ; i<4 ; i++) {
          fprintf(stderr, "%d: %lu, %lu, %lu, %lu\n", i, perfRep.latencyMin.at(i),perfRep.latencyMean.at(i),perfRep.latencyMax.at(i),perfRep.latencyStdDev.at(i));
        }
        fprintf(stderr, "interval: %lu, samples: %u, dataSum: %lu, drops: %u\n", perfRep.intervalActual, perfRep.samplesInterval, perfRep.dataSumInterval, perfRep.dropCount);
#endif
        perfRep.perf_data_ready = false;
      }
    }
#ifdef WIN32        // FIXME: move these to outside of pub/sub
    closesocket(destSocket);
    WSACleanup();
#else
    ::close(sock);
#endif
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
