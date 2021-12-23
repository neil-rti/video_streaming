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
#include <thread>                   // thread for UDP input from ffmpeg(blocking)
#include <mutex>
#include <condition_variable>
#include <signal.h>                 // ctrl-c handler
#include <rti/util/util.hpp>        // for sleep()
#include "rti_comms.hpp"            // for Connext pub/sub
#include "murmurhash3.h"            // for hashing
#include "com_perf.hpp"             // for latency measurement
#include "streamtest/app_helper.hpp"    // for command line args and signals

// a few globals for expediency
comPerfCalc gMyPerfCalc;            // class for accumulating latency test results
rtiComms* gMyPerfPub = NULL;        // pointer to DDS publisher instance
std::string gMyNodeId;              // my node ID, in hashed form
uint64_t gTSubRcv = 0;              // timestamp of most-recent subscriber sample received
uint64_t gTSPrevLink[2] = { 0 };    // timestamps (pub, sub) of the previous transport in test loop
bool gForwardOnly = false;          // if true, don't initiate any pub action (other than forwarding rcv'd samples)


/** ----------------------------------------------------------------
 * perfDataRcv_callback()
 * Callback for received performance samples from the far end
 * If sample pub_id != myId, then add my timestamps, re-publish the data,
 *     and calc/show transport latency
 * else sample pub_id == myId: copy the last 2 timestamps to the first 2
 *     in a new sample to pub, reset idx, and calc/show transport latency.
 **/
int perfDataRcv_callback(dds::sub::DataReader<cctypes::ccBulk > reader)
{
    int count = 0;
    dds::sub::LoanedSamples<cctypes::ccBulk> samples = reader.take();
    for (const auto& sample : samples) {
        if (sample.info().valid()) {

            // get high-res timestamp
            uint64_t tNow = tstamp_u64_get();
            gTSubRcv = tNow;

            // update the stats for this interval
            uint8_t myMode = gMyPerfCalc.update_stats(tNow, sample.data().data().data(), sample.data().data().size());
            gForwardOnly = (myMode != 0);

            // now either forward or retire the sample
            uint32_t idxAndMode = *(uint32_t*)(sample.data().data().data() + 4);
            uint32_t nextIdx = idxAndMode & 0xfff;
            if (sample.data().pub_id() == gMyNodeId) {
                // this sample did not come from me; re-publish it with my timestamps added, update the idx
                cctypes::ccBulk tmpSample = sample;
                idxAndMode = (idxAndMode & 0xf000) | (nextIdx + (2 * sizeof(uint64_t)));
                memcpy(tmpSample.data().data() + 4, &idxAndMode, sizeof(uint32_t));
                memcpy(tmpSample.data().data() + nextIdx, &tNow, sizeof(uint64_t));

                // a new timestamp right before publishing
                tNow = tstamp_u64_get();
                memcpy(tmpSample.data().data() + nextIdx + sizeof(uint64_t), &tNow, sizeof(uint64_t));
                gMyPerfPub->publish(tmpSample);
            }
            else {
                // this sample came from me; retire it
                // copy only the last 2 timestamps to be available for the start of my own next pub sample
                nextIdx -= sizeof(uint64_t);
                if (nextIdx >= 8) {
                    gTSPrevLink[0] = *(uint64_t*)(sample.data().data().data() + nextIdx);
                    gTSPrevLink[1] = tNow;
                }
            }
            count++;
        }
    }
    return count;
}


/** ----------------------------------------------------------------
 * participant_main()
 **/
void participant_main(application::ApplicationArguments args)
{
    // setup ----------------------------------------------------
    // convert names to ID strings (used as DDS topic name)
    std::string fromId;
    application::contact_name_to_id(args.this_station_name, gMyNodeId);
    application::contact_name_to_id(args.from_station_name, fromId);
    fprintf(stderr, "This Station: [%s], '%s'\n", gMyNodeId.c_str(), args.this_station_name.c_str());
    fprintf(stderr, "From Station: [%s], '%s'\n", fromId.c_str(), args.from_station_name.c_str());

    // Create a DomainParticipant with default Qos
    dds::domain::DomainParticipant participant(args.domain_id);

    // create ccBulk publisher and subscriber; these will be on different-named topics
    dds::core::cond::WaitSet waitset;
    rtiComms perfPub(std::string("t" + gMyNodeId), CTRL_PUB_BE, participant);
    gMyPerfPub = &perfPub;
    rtiComms perfSub(std::string("t" + fromId), CTRL_SUB_BE, participant, &waitset, &perfDataRcv_callback);

    // were any sweep parms set in the config file?
    uint8_t testMode = 0;
    enum loopCfgEnum {
        LOOP_NONE = 0,
        LOOP_PUBSIZE,
        LOOP_PUBRATE,
        LOOP_DATARATE
    };
    loopCfgEnum innerCfg, outerCfg;
    if (args.loopInnerSteps) {
        testMode = 1;
        if (args.loopInnerWhat == "pubsize") innerCfg = LOOP_PUBSIZE;
        else if (args.loopInnerWhat == "pubrate") innerCfg = LOOP_PUBRATE;
        else if (args.loopInnerWhat == "datarate") innerCfg = LOOP_DATARATE;
        else innerCfg = LOOP_NONE;
        if (args.loopOuterWhat == "pubsize") outerCfg = LOOP_PUBSIZE;
        else if (args.loopOuterWhat == "pubrate") outerCfg = LOOP_PUBRATE;
        else if (args.loopOuterWhat == "datarate") outerCfg = LOOP_DATARATE;
        else outerCfg = LOOP_NONE;
    }

    //cctypes::commandMode testMode = cctypes::commandMode::PING_2SEC;
    uint64_t pingRateNs = 2000000000;        // 2-second ping rate
    uint64_t tNextPingPub = tstamp_u64_get() + pingRateNs;
    uint32_t seqNum = 0;

    // test loop
    while (false == application::shutdown_requested) {
        // get timestamp for this loop
        uint64_t tLoop = tstamp_u64_get();

        // check our mode
        if (testMode == 0)      // ping every 2 seconds
        {
            // publish a ping every pingInterval
            if (tLoop >= tNextPingPub) {
                // publish a ping packet
                cctypes::ccBulk pubSample;
                // my ID, sequence number, index, and timestamps of previous link in loop
                pubSample.pub_id(gMyNodeId);
                memcpy(pubSample.data().data(), &seqNum, sizeof(uint32_t));
                uint32_t tmpIdx = 8 + (2 * sizeof(uint64_t));
                memcpy(pubSample.data().data() + sizeof(uint32_t), &tmpIdx, sizeof(uint32_t));
                memcpy(pubSample.data().data() + 8, &gTSPrevLink[0], sizeof(uint64_t));
                memcpy(pubSample.data().data() + 8 + sizeof(uint64_t), &gTSPrevLink[1], sizeof(uint64_t));
                perfPub.publish(pubSample);

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
        else {
            // run a sweep test of some sort; stay here until complete or timeout
            bool inloop = true;
            bool updateOuter = true;
            int32_t outNow = args.loopOuterStart;
            int32_t outStep = 0;
            int32_t inNow = args.loopInnerStart;
            int32_t inStep = 0;
            uint64_t timeBetweenPubsNs;
            uint32_t loopDataRate;
            while (inloop || false == application::shutdown_requested) {
                tLoop = tstamp_u64_get();

                // outer loop
                if ((outStep <= args.loopOuterSteps) && (updateOuter)) {
                    // set what needs setting
                    if (outerCfg == LOOP_PUBSIZE) {
                        perfPub.pub_sample_data_size_set(outNow);
                    }
                    else if (outerCfg == LOOP_PUBRATE) {
                        // pub rate is in samples per second
                        timeBetweenPubsNs = 1000000000 / outNow;
                    }
                    else if (outerCfg == LOOP_DATARATE) {
                        // datarate is in bytes per second
                        loopDataRate = outNow;
                    }

                    outStep++;
                    if (args.loopOuterSteps) {
                        // FIXME: scale this up to get better integer math rounding
                        outNow = ((outStep * (args.loopOuterStop - args.loopOuterStart)) / args.loopOuterSteps) + args.loopOuterStart;
                    }
                    updateOuter = false;
                }

                // inner loop
                if (innerCfg == LOOP_PUBSIZE) {
                    perfPub.pub_sample_data_size_set(inNow);
                }
                else if (innerCfg == LOOP_PUBRATE) {
                    // pub rate is in samples per second
                    timeBetweenPubsNs = 1000000000 / inNow;
                }
                else if (innerCfg == LOOP_DATARATE) {
                    // datarate is in bytes per second
                    // adjust the value that's not in the outer loop
                    if (outerCfg == LOOP_PUBRATE) {
                        // adjust the pubsize at this pubrate to meet this datarate
                    }
                    else if (outerCfg == LOOP_PUBSIZE) {
                        // adjust the pubrate at this pubsize to meet this datarate
                    }
                    loopDataRate = inNow;   // not needed?
                }

                inStep++;
                if (inStep >= args.loopInnerSteps) {
                    if (outStep > args.loopOuterSteps) {
                        // finished with test
                        inloop = false;
                    }
                    else {
                        // loop again
                        inNow = args.loopInnerStart;
                        inStep = 0;
                        updateOuter = true;
                    }
                }
                else {
                    // update the controlled value
                    // FIXME: scale this up to get better integer math rounding
                    // inNow = ((inStep * (args.loopInnerStop - args.loopInnerStart)) / args.loopInnerSteps) + args.loopInnerStart;
                    inNow = ((((10 * inStep * (args.loopInnerStop - args.loopInnerStart)) / args.loopInnerSteps) + 5) / 10) + args.loopInnerStart;
                }
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
