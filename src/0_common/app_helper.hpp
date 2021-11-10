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
 * app_helper.hpp -- derived from the 'application.hpp' file created by 
 * 'rtiddsgen' code generator application, customized for this example.
 **/

#ifndef __APP_HELPER_HPP__
#define __APP_HELPER_HPP__

#include <iostream>
#include <csignal>
#include <dds/core/ddscore.hpp>
#include "toml.hpp"                 // for config file I/O

namespace application {

    // Catch control-C and tell application to shut down
    bool shutdown_requested = false;

    const std::string config_filename_default = "config.toml";

    inline void stop_handler(int)
    {
        shutdown_requested = true;
        std::cout << "preparing to shut down..." << std::endl;
    }

    inline void setup_signal_handlers()
    {
        signal(SIGINT, stop_handler);
        signal(SIGTERM, stop_handler);
    }


    enum class ParseReturn {
        ok,
        failure,
        exit
    };

    struct ApplicationArguments {
        ParseReturn parse_result;
        unsigned int domain_id;
        std::string far_name;
        std::string near_name;
        bool use_reliable;
        bool pub_else_sub;
        uint32_t pub_data_size;
        rti::config::Verbosity verbosity;

        ApplicationArguments(
            ParseReturn parse_result_param,
            unsigned int domain_id_param,
            std::string far_name_param,
            std::string near_name_param,
            bool use_reliable_param,
            bool pub_else_sub_param,
            uint32_t pub_data_size_param,
            rti::config::Verbosity verbosity_param)
            : parse_result(parse_result_param),
            domain_id(domain_id_param),
            far_name(far_name_param),
            near_name(near_name_param),
            use_reliable(use_reliable_param),
            pub_else_sub(pub_else_sub_param),
            pub_data_size(pub_data_size_param),
            verbosity(verbosity_param) {}
    };

    inline void set_verbosity(
        rti::config::Verbosity& verbosity,
        int verbosity_value)
    {
        switch (verbosity_value) {
        case 0:
            verbosity = rti::config::Verbosity::SILENT;
            break;
        case 1:
            verbosity = rti::config::Verbosity::EXCEPTION;
            break;
        case 2:
            verbosity = rti::config::Verbosity::WARNING;
            break;
        case 3:
            verbosity = rti::config::Verbosity::STATUS_ALL;
            break;
        default:
            verbosity = rti::config::Verbosity::EXCEPTION;
            break;
        }
    }

    /** ------------------------------------------------------------
     * parse_arguments()
     * Parse the command line arguments, returning a struct.
     * This also works with a configuration file for convenience.
     * CmdLine args have priority over config file content.
     **/
    inline ApplicationArguments parse_arguments(int argc, char *argv[])
    {
        int arg_processing = 1;
        bool show_usage = false;
        ParseReturn parse_result = ParseReturn::ok;

        // arg priority is: 1:cmdLine args, 2:args from config file, 3: defaults
        // 3: init with defaults
        unsigned int domain_id = 0;
        std::string far_name = "Default Far Name";      // ID name to contact
        std::string near_name = "Default Near Name";    // My ID name
        std::string config_filename = config_filename_default;
        bool use_reliable = false;
        bool pub_else_sub = false;
        bool writeback_config_file = false;
        uint32_t pub_data_size = 1024;
        rti::config::Verbosity verbosity(rti::config::Verbosity::EXCEPTION);

        // 2: parms from config file.  Was one specified as cmdline arg?
        while (arg_processing < argc) {
            if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-c") == 0
            || strcmp(argv[arg_processing], "--configfile") == 0)) {
                config_filename = std::string(argv[arg_processing + 1]);
                arg_processing = argc;
            }
            else {
                arg_processing += 1;
            }
        }

        // try opening the config file
        bool config_file_exists = true;
        toml::value cfgfiledata;
        try {
            cfgfiledata = toml::parse(config_filename);
        } catch(const std::runtime_error& e) {
            config_file_exists = false;
        }
        if(config_file_exists) {
            if(cfgfiledata.contains("near_name")) {
                near_name = toml::find_or<std::string>(cfgfiledata, "near_name", "cfgfile_type_error");
            }
            if(cfgfiledata.contains("far_name")) {
                far_name = toml::find_or<std::string>(cfgfiledata, "far_name", "cfgfile_type_error");
            }
            if(cfgfiledata.contains("domain")) {
                domain_id = toml::find_or<unsigned int>(cfgfiledata, "domain", 0);
            }
            if(cfgfiledata.contains("pubsub")) {
                std::string pubsub = toml::find_or<std::string>(cfgfiledata, "pubsub", "cfgfile_type_error");
                std::size_t found = pubsub.find("pub");
                pub_else_sub = (found != std::string::npos);
            }
            if(cfgfiledata.contains("reliability")) {
                std::string reltype = toml::find_or<std::string>(cfgfiledata, "reliability", "cfgfile_type_error");
                std::size_t found = reltype.find("rel");
                use_reliable = (found != std::string::npos);
            }
            if(cfgfiledata.contains("data_chunk_size")) {
                pub_data_size = toml::find_or<uint32_t>(cfgfiledata, "data_chunk_size", 1111);
            }
        }

        // 1: parse the command line args
        arg_processing = 1;
        while (arg_processing < argc) {
            if ((argc > arg_processing + 1) 
            && (strcmp(argv[arg_processing], "-d") == 0
            || strcmp(argv[arg_processing], "--domain") == 0)) {
                domain_id = atoi(argv[arg_processing + 1]);
                arg_processing += 2;
            } else if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-f") == 0
            || strcmp(argv[arg_processing], "--farname") == 0)) {
                far_name = std::string(argv[arg_processing + 1]);
                arg_processing += 2;
            } else if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-n") == 0
            || strcmp(argv[arg_processing], "--nearname") == 0)) {
                near_name = std::string(argv[arg_processing + 1]);
                arg_processing += 2;
            } else if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-p") == 0
            || strcmp(argv[arg_processing], "--pubsub") == 0)) {
                std::string dirTmp = std::string(argv[arg_processing + 1]);
                std::size_t found = dirTmp.find("pub");
                pub_else_sub = (found != std::string::npos);
                arg_processing += 2;
            } else if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-r") == 0
            || strcmp(argv[arg_processing], "--reliability") == 0)) {
                std::string relTmp = std::string(argv[arg_processing + 1]);
                std::size_t found = relTmp.find("rel");
                use_reliable = (found != std::string::npos);
                arg_processing += 2;
            } else if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-s") == 0
            || strcmp(argv[arg_processing], "--size") == 0)) {
                pub_data_size = atoi(argv[arg_processing + 1]);
                arg_processing += 2;
            } else if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-c") == 0
            || strcmp(argv[arg_processing], "--configfile") == 0)) {
                config_filename = std::string(argv[arg_processing + 1]);
                arg_processing += 2;
            } else if ((strcmp(argv[arg_processing], "-w") == 0
            || strcmp(argv[arg_processing], "--writeback") == 0)) {
                writeback_config_file = true;
                arg_processing += 1;
            } else if ((argc > arg_processing + 1)
            && (strcmp(argv[arg_processing], "-v") == 0
            || strcmp(argv[arg_processing], "--verbosity") == 0)) {
                set_verbosity(verbosity, atoi(argv[arg_processing + 1]));
                arg_processing += 2;
            } else if (strcmp(argv[arg_processing], "-h") == 0
            || strcmp(argv[arg_processing], "--help") == 0) {
                std::cout << "Example application." << std::endl;
                show_usage = true;
                parse_result = ParseReturn::exit;
                break;
            } else {
                std::cout << "Bad parameter." << std::endl;
                show_usage = true;
                parse_result = ParseReturn::failure;
                break;
            }
        }
        if (show_usage) {
            std::cout << "Usage:\n"\
            "    -d, --domain      <int>     Domain ID this application will operate in\n" \
            "                                Default: " << domain_id << "\n"\
            "    -f, --farname     <string>  ID of the station to contact\n" \
            "                                Default: " << far_name << "\n"\
            "    -n, --nearname    <string>  ID of this station\n" \
            "                                Default: " << near_name << "\n"\
            "    -p, --pubsub      <pub|sub> Endpoint type: pub or sub\n" \
            "                                Default: sub\n"\
            "    -r, --reliability <rel|be>  Reliability type: best effort or reliable\n" \
            "                                Default: be\n"\
            "    -s, --size        <int>     Size of the data portion to be streamed\n"\
            "                                Default: " << pub_data_size << "\n"\
            "    -c, --configfile  <string>  Configuration filename to load\n"\
            "                                Default: " << config_filename_default << "\n"\
            "    -w, --writeback             Write-back to the config file, updated args\n"\
            "                                \n"\
            "    -v, --verbosity   <int>     How much debugging output to show.\n"\
            "                                Range: 0-3 \n"\
            "                                Default: 1 (EXCEPTION)\n"\
            "    -h, --help                  Print this list and exit\n"\
            << std::endl;
        }

        // write-back the config file if asked
        if(writeback_config_file) {
            cfgfiledata["near_name"] = near_name;
            cfgfiledata["far_name"] = far_name;
            cfgfiledata["domain"] = domain_id;
            if(pub_else_sub) {
                cfgfiledata["pubsub"] = "pub";
            }
            else {
                cfgfiledata["pubsub"] = "sub";
            }
            cfgfiledata["reliability"] = use_reliable ? "reliable" : "best effort";
            cfgfiledata["data_chunk_size"] = pub_data_size;

            std::ofstream fout(config_filename);
            if(fout) {
                fout << cfgfiledata << std::endl;
            }
            else {
                std::cerr << "Write-back failure to file " << config_filename << std::endl;
            }
        }

        return ApplicationArguments(
            parse_result, domain_id, far_name, near_name, 
            use_reliable, pub_else_sub, pub_data_size, verbosity);
 
    }

}  // namespace application

#endif  // __APP_HELPER_HPP__