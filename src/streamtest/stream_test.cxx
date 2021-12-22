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
 * stream_test: test program that generates 'streaming' traffic for testing
 * transport/network performance.
 **/
#include <algorithm>
#include <iostream>
#include <thread>                 // thread for UDP input from ffmpeg(blocking)
#include <mutex>
#include <condition_variable>
#include <signal.h>               // ctrl-c handler
#include <rti/util/util.hpp>      // for sleep()
#include "rti_comm_test.hpp"      // for Connext pub/sub
#include "murmurhash3.h"          // for hashing
#include "com_perf.hpp"           // for latency measurement
#include "app_helper.hpp"         // for command line args and signals

// pointer to perf publisher class
rtiComPerf* gMyPerfPub = NULL;
std::string gMyNodeId;
uint64_t gTSubRcv = 0;

// perf calculation class
comPerfCalc gMyPerfCalc;

char* tmpBuf;
const int tmpBufMax = 131072;
int inx, outx, rollx;
uint64_t intot, outtot;
std::condition_variable cv;
std::mutex mtx;
uint32_t testGenDataRate = 0;


/** ----------------------------------------------------------------
 * perfDataRcv_callback()
 * Callback for received performance samples from vidSub
 **/
int perfDataRcv_callback(dds::sub::DataReader<cctypes::ccPerf > reader)
{
    int count = 0;
    dds::sub::LoanedSamples<cctypes::ccPerf> samples = reader.take();
    for (const auto& sample : samples) {
        if (sample.info().valid()) {
            uint64_t tNow = tstamp_u64_get();
            // if this sample's pub_id == myID, then update stats
            if (sample.data().pub_id() == gMyNodeId) {
#if 0
                fprintf(stdout, "Sub: seqId %u, idx: %u, data:\n", sample.data().sequence_id(), sample.data().next_data_idx());
                uint64_t* tmpDp = (uint64_t*)sample.data().data_payload().data();
                fprintf(stdout, "%llu\n%llu\n%llu\n%llu\n",
                    tmpDp[0], tmpDp[1], tmpDp[2], tNow
                );
                fprintf(stdout, "average: %llu, size: %lld\n", ((tNow - tmpDp[2]) + (tmpDp[1] - tmpDp[0])) / 2,
                    sample.data().data_payload().size());
                // FIXME: call the stats class here
#endif
                // pass to class: sequence<u64> of timestamps.  Have method to reset period, access results.
                std::vector<uint64_t> newStamps;
                int j = 0;
                for (; j < sample.data().data_payload().size(); j++)
                {
                    newStamps.push_back(sample.data().data_payload().at(j));
                }
                newStamps.push_back(tNow);
                gMyPerfCalc.update_stats(sample.data().sequence_id(), (uint32_t)sample.data().data_payload().size(), newStamps);
            }
            else {  // otherwise, update and re-publish the sample
                gTSubRcv = tNow;
                cctypes::ccPerf tmpSample = sample;
                memcpy(tmpSample.data_payload().data() + tmpSample.next_data_idx(), &gTSubRcv, sizeof(uint64_t));
                tNow = tstamp_u64_get();
                memcpy(tmpSample.data_payload().data() + tmpSample.next_data_idx() + sizeof(uint64_t), &tNow, sizeof(uint64_t));
                tmpSample.next_data_idx() = tmpSample.next_data_idx() + (2 * sizeof(uint64_t));
                gMyPerfPub->publish(tmpSample);
            }
            count++;
        }
    }
    return count;
}



/** ----------------------------------------------------------------
 * test_datagen_thread()
 * Thread for generating noisy (hashed) data at a settable rate.
 * This data is NOT usable video content; 
 * This is to be used for capacity testing of the network link 
 * between video publisher and subscriber.
 **/
void test_datagen_thread(void)
{
    // to use:
    // char* tmpBuf;
    // const int tmpBufMax = 131072;
    // int inx, outx, rollx;
    // uint64_t intot, outtot;
    // std::condition_variable cv;
    // std::mutex mtx;
    // uint32_t testGenDataRate = 0;

    uint32_t seqNumber = 0;
    uint64_t seqHash[2];
    uint32_t hashSeed = 0x0ec3d821;   // no significance to this number, other that it is prime
    // this thread uses the RTI sleep() function to yield for 10mS (100Hz)
    while (false == application::shutdown_requested)
    {
        // testGenDataRate == data rate in bytes per second
        int32_t packetsThisPeriod = (testGenDataRate / 100) / 188;
        if (packetsThisPeriod > 0) {

            int32_t packetSendCount = packetsThisPeriod;

            while (packetSendCount > 0) {
                // put the seqNumber in first, for each 188-byte 'packet'
                memcpy(&tmpBuf[inx], &seqNumber, sizeof(uint32_t));

                // for fun, fake like it's an MPEG-TS header (first 4 bytes) FIXME: delete this.
                tmpBuf[inx] = 0x47;         // sync byte
                tmpBuf[inx + 1] = 0x01;     // 3 signal bits + start of the PID
                tmpBuf[inx + 2] = 0x00;     // rest of the PID + 4 signal bits
                tmpBuf[inx + 3] = (uint8_t)(seqNumber & 0xf);   // continuity counter

                inx += sizeof(uint32_t);

                // mmh3 returns a 16-byte result; copy repeatedly into remaining 184 bytes
                MurmurHash3_x64_128(&seqNumber, sizeof(uint32_t), hashSeed, &seqHash);
                for (auto j = 0; j < 176; j += 16) {
                    memcpy(&tmpBuf[inx + j], seqHash, 16);
                }
                inx += 176;
                memcpy(&tmpBuf[inx], seqHash, 8);

                seqNumber++;
                packetSendCount--;

                // are we getting close to the end of the tmpBuf array?
                if (inx + 188 >= tmpBufMax) {
                    rollx = inx;
                    inx = 0;
                }
            }

            intot += (packetsThisPeriod * 188);

            // notify pub loop: there is data to send
            std::lock_guard<std::mutex> lk(mtx);
            cv.notify_one();
        }

        // yield the CPU for 10mS
        rti::util::sleep(dds::core::Duration(0, 10000000));
    }
}



/** ----------------------------------------------------------------
 * participant_main()
 **/
void participant_main(application::ApplicationArguments args)
{
    // setup ----------------------------------------------------
    // convert names to ID strings (used as DDS topic name)
    std::string myId, fromId;
    application::contact_name_to_id(args.this_station_name, myId);
    application::contact_name_to_id(args.from_station_name, fromId);
    fprintf(stderr, "This Station: [%s], '%s'\n", myId.c_str(), args.this_station_name.c_str());
    fprintf(stderr, "From Station: [%s], '%s'\n", fromId.c_str(), args.from_station_name.c_str());
    gMyNodeId = myId;

    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(args.domain_id);

    // create ccPerf publisher and subscriber; these will be on different-named topics
    dds::core::cond::WaitSet waitset;
    rtiComPerf perfPub(std::string("l" + myId), CTRL_PUB_BE, participant);
    perfPub.pub_sample_data_payload_buffer_size(args.data_sample_size);
    gMyPerfPub = &perfPub;
    rtiComPerf perfSub(std::string("l" + fromId), CTRL_SUB_BE, participant, &waitset, &perfDataRcv_callback);

    // create ccTestCtrl sub and ccTestReport pub
    //rtiComTestControl testCtrlSub(std::string("testControl"), CTRL_SUB_BE, participant, &waitset);
    //rtiComTestReport testReportPub(std::string("testReport"), CTRL_PUB_BE, participant);

    // init a class for processing the latency data / get stats
    // FIXME: do this in a class

    gMyPerfCalc.init_sizes(4);
    

    cctypes::commandMode testMode = cctypes::commandMode::PING_2SEC;
    uint64_t pingRateNs = 2000000000;        // 2-second ping rate
    uint64_t tNextPingPub = tstamp_u64_get() + pingRateNs;
    uint32_t seqNum = 0;

    // test loop
    while (false == application::shutdown_requested) {
        // get timestamp for this loop
        uint64_t tLoop = tstamp_u64_get();

        // check our mode
        if (testMode == cctypes::commandMode::PING_2SEC)
        {
            // publish a ping every pingInterval
            if (tLoop >= tNextPingPub) {
                // publish a ping packet
                perfPub.pub_sample_pub_id(myId);
                perfPub.pub_sample_command_mode(cctypes::commandMode::PING_2SEC);
                perfPub.pub_sample_sequence_id(seqNum);
                memcpy(perfPub.pub_sample_data_payload_buffer() + (0 * sizeof(uint64_t)), &tLoop, sizeof(uint64_t));
                perfPub.pub_sample_next_data_idx(1 * sizeof(uint64_t));
                perfPub.publish();

                // set the next interval for now + pingRateNs                
                tNextPingPub = tLoop + pingRateNs;
                // If needed, nudge the next ping time to be closer to (pingRateNs/2) from received ping
                uint64_t tDiff = tLoop - gTSubRcv;
                // if we are receiving ping from another test app
                if (tDiff < (pingRateNs * 2)) {
                    if (tDiff > ((pingRateNs * 110) / 200)) {
                        // if they're more than 10% over the halfway point, nudge our next time downward
                        tNextPingPub -= (pingRateNs / 32);
                    }
                    else if (tDiff < ((pingRateNs * 90) / 200)) {
                        // if more than 10% under the halfway point, nudge upward
                        tNextPingPub += (pingRateNs / 32);
                    }
                }
                seqNum++;
            }
        }

        waitset.dispatch(dds::core::Duration(0, 100000));
        // rti::util::sleep(dds::core::Duration(0, 10000000));     // sleep 10mS, probably too long
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
