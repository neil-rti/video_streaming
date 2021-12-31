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

enum class loopCfg {
    LOOP_NONE,
    LOOP_PUBSIZE,
    LOOP_PUBRATE,
    LOOP_DATARATE
};

// a few globals for expediency
comPerfCalc gMyPerfCalc;            // class for accumulating latency test results
rtiComms* gMyPerfPub = NULL;        // pointer to DDS publisher instance
std::string gMyNodeId;              // my node ID, in hashed form
uint64_t gTSubRcv = 0;              // timestamp of most-recent subscriber sample received
uint64_t gTSPrevLink[2] = { 0 };    // timestamps (pub, sub) of the previous transport in test loop
uint32_t gRcvTestMode = 1;          // 0=forward only, 1=ping

// listener class for received test data
class TestDataReaderListener
    : public dds::sub::NoOpDataReaderListener<cctypes::ccBulk> {
    virtual void on_requested_deadline_missed(
        dds::sub::DataReader<cctypes::ccBulk>& reader,
        const dds::core::status::RequestedDeadlineMissedStatus& status)
    {
        std::cout << "ReaderListener: on_requested_deadline_missed()"
            << std::endl;
    }

    virtual void on_requested_incompatible_qos(
        dds::sub::DataReader<cctypes::ccBulk>& reader,
        const dds::core::status::RequestedIncompatibleQosStatus& status)
    {
        std::cout << "ReaderListener: on_requested_incompatible_qos()"
            << std::endl;
    }

    virtual void on_sample_rejected(
        dds::sub::DataReader<cctypes::ccBulk>& reader,
        const dds::core::status::SampleRejectedStatus& status)
    {
        std::cout << "ReaderListener: on_sample_rejected()" << std::endl;
    }

    virtual void on_liveliness_changed(
        dds::sub::DataReader<cctypes::ccBulk>& reader,
        const dds::core::status::LivelinessChangedStatus& status)
    {
        std::cout << "ReaderListener: on_liveliness_changed()" << std::endl
            << "  Alive writers: " << status.alive_count() << std::endl;
    }

    virtual void on_sample_lost(
        dds::sub::DataReader<cctypes::ccBulk>& reader,
        const dds::core::status::SampleLostStatus& status)
    {
        std::cout << "ReaderListener: on_sample_lost()" << std::endl;
    }

    virtual void on_subscription_matched(
        dds::sub::DataReader<cctypes::ccBulk>& reader,
        const dds::core::status::SubscriptionMatchedStatus& status)
    {
        std::cout << "ReaderListener: on_subscription_matched()" << std::endl;
    }

    virtual void on_data_available(dds::sub::DataReader<cctypes::ccBulk>& reader)
    {
        dds::sub::LoanedSamples<cctypes::ccBulk> samples = reader.take();
        for (const auto& sample : samples) {
            if (sample.info().valid()) {
                // get high-res timestamp
                uint64_t tNow = tstamp_u64_get();
                gTSubRcv = tNow;

                // update the stats for this interval
                gRcvTestMode = gMyPerfCalc.update_stats(tNow, sample.data().data().data(), (uint32_t)sample.data().data().size());
                
                // now either forward or retire the sample
                if (sample.data().pub_id() != gMyNodeId) {
                    // this sample did not come from me; re-publish it with my timestamps moved to 'prev' positions
                    cctypes::ccBulk tmpSample = sample;
                    memcpy(tmpSample.data().data() + 16, tmpSample.data().data() + 32, sizeof(uint64_t));
                    memcpy(tmpSample.data().data() + 24, &tNow, sizeof(uint64_t));

                    // a new timestamp right before publishing
                    tNow = tstamp_u64_get();
                    memcpy(tmpSample.data().data() + 32, &tNow, sizeof(uint64_t));
                    gMyPerfPub->publish(tmpSample);

                }
                else {
                    // this sample came from me; retire it
                    // copy only the last 2 timestamps to be available for the start of my own next pub sample
                    gTSPrevLink[0] = *(uint64_t*)(sample.data().data().data() + 32);
                    gTSPrevLink[1] = tNow;
                }
            }
        }
    }
};

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

    // use a dataReader with a listener to receive test data
    dds::topic::Topic<cctypes::ccBulk> rcvTopic(participant, std::string("t" + fromId));
    dds::sub::Subscriber rcvSub(participant);
    dds::sub::DataReader<cctypes::ccBulk> rcvReader(rcvSub, rcvTopic);
    auto rr_listener = std::make_shared<TestDataReaderListener>();
    rcvReader.set_listener(rr_listener);

    // create ccBulk publisher and init a sample
    rtiComms perfPub(std::string("t" + gMyNodeId), CTRL_PUB_BE, participant);
    gMyPerfPub = &perfPub;
    cctypes::ccBulk pubSample;
    pubSample.data().resize(args.data_sample_size);
    pubSample.pub_id(gMyNodeId);

    // were any sweep parms set in the config file?
    uint8_t testMode = 1;
    loopCfg innerCfg, outerCfg;
    if (args.loopInnerSteps) {
        testMode = 2;
        if (args.loopInnerWhat == "pubsize") innerCfg = loopCfg::LOOP_PUBSIZE;
        else if (args.loopInnerWhat == "pubrate") innerCfg = loopCfg::LOOP_PUBRATE;
        else if (args.loopInnerWhat == "datarate") innerCfg = loopCfg::LOOP_DATARATE;
        else innerCfg = loopCfg::LOOP_NONE;
        if (args.loopOuterWhat == "pubsize") outerCfg = loopCfg::LOOP_PUBSIZE;
        else if (args.loopOuterWhat == "pubrate") outerCfg = loopCfg::LOOP_PUBRATE;
        else if (args.loopOuterWhat == "datarate") outerCfg = loopCfg::LOOP_DATARATE;
        else outerCfg = loopCfg::LOOP_NONE;
    }

    uint64_t timeBetweenPubsNs = 2000000000;        // 2-second ping rate
    uint64_t tNextPingPub = tstamp_u64_get() + timeBetweenPubsNs;
    uint64_t tNextInnerUpdate;
    uint32_t seqNum = 0;
    uint32_t pubCount = 0;

    // test loop
    while (false == application::shutdown_requested) {
        // get timestamp for this loop
        uint64_t tLoop = tstamp_u64_get();

        // check our mode
        if (testMode == 1)      // ping every 2 seconds
        {
            // publish a ping every pingInterval
            if (tLoop >= tNextPingPub) {
                // publish a ping packet
                comPerfCalc::testPacking* testParts = (comPerfCalc::testPacking*)pubSample.data().data();
                testParts->seqNum = seqNum;
                testParts->pub_rate = 2000000000;
                testParts->pub_size = (uint32_t)pubSample.data().size();
                testParts->testMode = 1;
                testParts->tStampPubPrev = gTSPrevLink[0];
                testParts->tStampSubPrev = gTSPrevLink[1];
                testParts->tStampPubNow = tstamp_u64_get();
                perfPub.publish(pubSample);

                // set the next interval for now + timeBetweenPubsNs
                tNextPingPub = tLoop + timeBetweenPubsNs;
                // If needed, nudge the next ping time to be closer to (timeBetweenPubsNs/2) from received ping
                uint64_t tDiff = tLoop - gTSubRcv;
                // if we are receiving ping from another test app
                if (tDiff < (timeBetweenPubsNs * 2)) {
                    if (tDiff > ((timeBetweenPubsNs * 110) / 200)) {
                        // if they're more than 10% over the halfway point, nudge our next time downward
                        tNextPingPub -= (timeBetweenPubsNs / 32);
                    }
                    else if (tDiff < ((timeBetweenPubsNs * 90) / 200)) {
                        // if more than 10% under the halfway point, nudge upward
                        tNextPingPub += (timeBetweenPubsNs / 32);
                    }
                }
                seqNum++;
            }
            if (gRcvTestMode == 2) {
                testMode = 0;
            }
        }
        else if(testMode == 2) 
        {
            // run a sweep test of some sort; stay here until complete or timeout
            bool inloop = true;
            bool updateOuter = true;
            bool updateInner = true;
            int32_t outNow = args.loopOuterStart;
            int32_t outStep = 0;
            int32_t inNow = args.loopInnerStart;
            int32_t inStep = 0;
            gMyPerfCalc.print_perf_header();
            uint64_t timeToPublish = tstamp_u64_get();
            while (inloop || false == application::shutdown_requested) {
                tLoop = tstamp_u64_get();

                // outer loop
                if ((outStep <= args.loopOuterSteps) && (updateOuter)) {
                    // set what needs setting
                    if (outerCfg == loopCfg::LOOP_PUBSIZE) {
                        pubSample.data().resize(outNow);
                    }
                    else if (outerCfg == loopCfg::LOOP_PUBRATE) {
                        // pub rate is in samples per second
                        timeBetweenPubsNs = (uint64_t)1000000000 / outNow;
                    }
                    else if (outerCfg == loopCfg::LOOP_DATARATE) {
                        // datarate is in bytes per second
                    }

                    if (args.loopOuterSteps > 1) {
                        // FIXME: scale this up to get better integer math rounding
                        outNow = ((outStep * (args.loopOuterStop - args.loopOuterStart)) / (args.loopOuterSteps - 1)) + args.loopOuterStart;
                    }
                    outStep++;
                    updateOuter = false;
                }

                // inner loop is the stepped var, outer loop is fixed
                if (updateInner) {
                    if (innerCfg == loopCfg::LOOP_PUBSIZE) {
                        if (outerCfg == loopCfg::LOOP_DATARATE) {
                            // to keep a constant dataRate, adjust the pubRate
                            timeBetweenPubsNs = ((uint64_t)1000000000 * inNow) / outNow;
                        }
                        //                        fprintf(stderr, "iPubSize: %d, pubRate: %lld, dataRate: %d (%d)\n", inNow, ((uint64_t)1000000000 / timeBetweenPubsNs), outNow, (inNow * (uint64_t)1000000000) / timeBetweenPubsNs);
                        pubSample.data().resize(inNow);
                    }
                    else if (innerCfg == loopCfg::LOOP_PUBRATE) {
                        // pub rate is in samples per second
                        timeBetweenPubsNs = (uint64_t)1000000000 / inNow;
                        if (outerCfg == loopCfg::LOOP_DATARATE) {
                            // to keep a constant datarate, adjust the pubSize
                            int32_t tmpSize = outNow / inNow;
                            if (tmpSize > pubSample.data().max_size()) tmpSize = pubSample.data().max_size();
                            pubSample.data().resize(tmpSize);
                            //                            fprintf(stderr, "iPubRate: %d, pubSize: %d, dataRate: %d (%d) count: %u\n", inNow, tmpSize, (inNow * tmpSize), outNow, pubCount);
                        }
                    }
                    else if (innerCfg == loopCfg::LOOP_DATARATE) {
                        if (outerCfg == loopCfg::LOOP_PUBRATE) {
                            // adjust the pubsize at this pubrate to meet this datarate
                            int32_t tmpSize = inNow / outNow;
                            if (tmpSize > pubSample.data().max_size()) tmpSize = pubSample.data().max_size();
                            pubSample.data().resize(tmpSize);
                            //                            fprintf(stderr, "iDataRate: %d (%d), pubSize: %d, pubRate: %d\n", inNow, (outNow * tmpSize), tmpSize, outNow);
                        }
                        else if (outerCfg == loopCfg::LOOP_PUBSIZE) {
                            // adjust the pubrate to fit this pubsize and datarate
                            timeBetweenPubsNs = ((uint64_t)1000000000 * outNow) / inNow;
                            //                            fprintf(stderr, "iDataRate: %d, pubSize: %d, pubRate: %lld\n", inNow, outNow, ((uint64_t)1000000000 / timeBetweenPubsNs));

                        }
                    }

                    inStep++;
                    if (inStep >= args.loopInnerSteps) {
                        if (outStep >= args.loopOuterSteps) {
                            // finished with test; return to a low-rate ping
                            inloop = false;
                            testMode = 1;
                            timeBetweenPubsNs = 2000000000;
                            pubSample.data().resize(1504);
                        }
                        else {
                            // loop again
                            inNow = args.loopInnerStart;
                            inStep = 0;
                            updateOuter = true;
                        }
                    }
                    else {
                        // update the controlled value to the next step
                        inNow = ((((10 * inStep * (args.loopInnerStop - args.loopInnerStart)) / args.loopInnerSteps) + 5) / 10) + args.loopInnerStart;
                    }

                    // gMyPerfCalc.interval_start_nsec(timeBetweenPubsNs);
                    gMyPerfCalc.interval_start_nsec((uint64_t)args.loopInnerTimeMs * 1000000);
                    tNextInnerUpdate = tLoop + ((uint64_t)args.loopInnerTimeMs * 1000000);
                    pubCount = 0;
                    updateInner = false;
                }
                // now: time to publish?
                if (tLoop >= timeToPublish) {
                    // prepare and publish another sample
                    comPerfCalc::testPacking* testParts = (comPerfCalc::testPacking*)pubSample.data().data();
                    testParts->seqNum = seqNum;
                    testParts->pub_rate = timeBetweenPubsNs;
                    testParts->pub_size = (uint32_t)pubSample.data().size();
                    testParts->testMode = 2;
                    testParts->tStampPubPrev = gTSPrevLink[0];
                    testParts->tStampSubPrev = gTSPrevLink[1];
                    testParts->tStampPubNow = tstamp_u64_get();
                    perfPub.publish(pubSample);
                    timeToPublish = tLoop + timeBetweenPubsNs;
                    pubCount++;
                    seqNum++;
                }

                // take the next step in inner loop only if we're getting data returned
                if (gMyPerfCalc.perf_data_ready) {
                    gMyPerfCalc.print_perf_data();
                    updateInner = true;
                }
            }
        }
        else 
        {
            if ((tLoop - gTSubRcv) > 2500000000)
            {
                testMode = 1;
            }
        }

        // waitset.dispatch(dds::core::Duration(0, 100000));
        // rti::util::sleep(dds::core::Duration(0, 10000000));     // sleep 10mS, probably too long
    }
}

/** ----------------------------------------------------------------
 * main()
 * arguments are handled in 'app_helper.hpp'
 **/
int main(int argc, char* argv[])
{
    using namespace application;

    // Parse arguments and handle control-C
    auto arguments = parse_arguments(argc, argv);
    if (arguments.parse_result == ParseReturn::exit) {
        return EXIT_SUCCESS;
    }
    else if (arguments.parse_result == ParseReturn::failure) {
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
