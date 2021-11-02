

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from cctypes.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "cctypes.hpp"
#include "cctypesPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

namespace cctypes {

    std::ostream& operator << (std::ostream& o,const payloadTypesEnum& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case payloadTypesEnum::NO_PAYLOAD:
            o << "payloadTypesEnum::NO_PAYLOAD" << " ";
            break;
            case payloadTypesEnum::TOP_INFO_EXCHANGE:
            o << "payloadTypesEnum::TOP_INFO_EXCHANGE" << " ";
            break;
            case payloadTypesEnum::STREAM_FFMPEG_0:
            o << "payloadTypesEnum::STREAM_FFMPEG_0" << " ";
            break;
            case payloadTypesEnum::STREAM_FFMPEG_1:
            o << "payloadTypesEnum::STREAM_FFMPEG_1" << " ";
            break;
            case payloadTypesEnum::STREAM_GSTREAMER_0:
            o << "payloadTypesEnum::STREAM_GSTREAMER_0" << " ";
            break;
            case payloadTypesEnum::STREAM_GSTREAMER_1:
            o << "payloadTypesEnum::STREAM_GSTREAMER_1" << " ";
            break;
            case payloadTypesEnum::STREAM_OPENCV_0:
            o << "payloadTypesEnum::STREAM_OPENCV_0" << " ";
            break;
            case payloadTypesEnum::STREAM_OPENCV_1:
            o << "payloadTypesEnum::STREAM_OPENCV_1" << " ";
            break;
            case payloadTypesEnum::FILE_TRANSFER_REQUEST:
            o << "payloadTypesEnum::FILE_TRANSFER_REQUEST" << " ";
            break;
            case payloadTypesEnum::FILE_TRANSFER_ACCEPT:
            o << "payloadTypesEnum::FILE_TRANSFER_ACCEPT" << " ";
            break;
            case payloadTypesEnum::FILE_TRANSFER_PAYLOAD:
            o << "payloadTypesEnum::FILE_TRANSFER_PAYLOAD" << " ";
            break;
            case payloadTypesEnum::FILE_TRANSFER_VERIFY:
            o << "payloadTypesEnum::FILE_TRANSFER_VERIFY" << " ";
            break;
            case payloadTypesEnum::TEXT_CHAT_0:
            o << "payloadTypesEnum::TEXT_CHAT_0" << " ";
            break;
            case payloadTypesEnum::TEST_PATTERN_0:
            o << "payloadTypesEnum::TEST_PATTERN_0" << " ";
            break;
            case payloadTypesEnum::TRAFFIC_GEN_COMPRESSIBLE:
            o << "payloadTypesEnum::TRAFFIC_GEN_COMPRESSIBLE" << " ";
            break;
            case payloadTypesEnum::TRAFFIC_GEN_NONCOMPRESSIBLE:
            o << "payloadTypesEnum::TRAFFIC_GEN_NONCOMPRESSIBLE" << " ";
            break;
            case payloadTypesEnum::IMAGE_FILE:
            o << "payloadTypesEnum::IMAGE_FILE" << " ";
            break;
            case payloadTypesEnum::MAX_PAYLOAD_ENUM:
            o << "payloadTypesEnum::MAX_PAYLOAD_ENUM" << " ";
            break;
        }
        return o;
    }

    // ---- ccBulk: 

    ccBulk::ccBulk() :
        m_destination_id_ ("") ,
        m_content_type_(cctypes::payloadTypesEnum::NO_PAYLOAD) ,
        m_source_id_ ("") ,
        m_tstamp_first_frame_ (0ull) ,
        m_status_ (0)  {
    }   

    ccBulk::ccBulk (
        const std::string& destination_id,
        const cctypes::payloadTypesEnum& content_type,
        const std::string& source_id,
        uint64_t tstamp_first_frame,
        uint8_t status,
        const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data)
        :
            m_destination_id_( destination_id ),
            m_content_type_( content_type ),
            m_source_id_( source_id ),
            m_tstamp_first_frame_( tstamp_first_frame ),
            m_status_( status ),
            m_data_( data ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ccBulk::ccBulk(ccBulk&& other_) OMG_NOEXCEPT  :m_destination_id_ (std::move(other_.m_destination_id_))
    ,
    m_content_type_ (std::move(other_.m_content_type_))
    ,
    m_source_id_ (std::move(other_.m_source_id_))
    ,
    m_tstamp_first_frame_ (std::move(other_.m_tstamp_first_frame_))
    ,
    m_status_ (std::move(other_.m_status_))
    ,
    m_data_ (std::move(other_.m_data_))
    {
    } 

    ccBulk& ccBulk::operator=(ccBulk&&  other_) OMG_NOEXCEPT {
        ccBulk tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void ccBulk::swap(ccBulk& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_destination_id_, other_.m_destination_id_);
        swap(m_content_type_, other_.m_content_type_);
        swap(m_source_id_, other_.m_source_id_);
        swap(m_tstamp_first_frame_, other_.m_tstamp_first_frame_);
        swap(m_status_, other_.m_status_);
        swap(m_data_, other_.m_data_);
    }  

    bool ccBulk::operator == (const ccBulk& other_) const {
        if (m_destination_id_ != other_.m_destination_id_) {
            return false;
        }
        if (m_content_type_ != other_.m_content_type_) {
            return false;
        }
        if (m_source_id_ != other_.m_source_id_) {
            return false;
        }
        if (m_tstamp_first_frame_ != other_.m_tstamp_first_frame_) {
            return false;
        }
        if (m_status_ != other_.m_status_) {
            return false;
        }
        if (m_data_ != other_.m_data_) {
            return false;
        }
        return true;
    }
    bool ccBulk::operator != (const ccBulk& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ccBulk& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "destination_id: " << sample.destination_id()<<", ";
        o << "content_type: " << sample.content_type()<<", ";
        o << "source_id: " << sample.source_id()<<", ";
        o << "tstamp_first_frame: " << sample.tstamp_first_frame()<<", ";
        o << "status: " << (int)sample.status() <<", ";
        o << "data: " << sample.data() ;
        o <<"]";
        return o;
    }

    // ---- ccPerf: 

    ccPerf::ccPerf() :
        m_destination_id_ ("") ,
        m_source_id_ ("") ,
        m_tStart_ (0ull) ,
        m_tEnd_ (0ull) ,
        m_samples_count_ (0u) ,
        m_samples_dropped_ (0u)  {
            ::rti::core::fill_array< uint64_t >( m_latency_min_, 0);
            ::rti::core::fill_array< uint64_t >( m_latency_mean_, 0);
            ::rti::core::fill_array< uint64_t >( m_latency_max_, 0);
    }   

    ccPerf::ccPerf (
        const std::string& destination_id,
        const std::string& source_id,
        uint64_t tStart,
        uint64_t tEnd,
        uint32_t samples_count,
        uint32_t samples_dropped,
        const ::dds::core::array< uint64_t, 3L>& latency_min,
        const ::dds::core::array< uint64_t, 3L>& latency_mean,
        const ::dds::core::array< uint64_t, 3L>& latency_max)
        :
            m_destination_id_( destination_id ),
            m_source_id_( source_id ),
            m_tStart_( tStart ),
            m_tEnd_( tEnd ),
            m_samples_count_( samples_count ),
            m_samples_dropped_( samples_dropped ),
            m_latency_min_( latency_min ),
            m_latency_mean_( latency_mean ),
            m_latency_max_( latency_max ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ccPerf::ccPerf(ccPerf&& other_) OMG_NOEXCEPT  :m_destination_id_ (std::move(other_.m_destination_id_))
    ,
    m_source_id_ (std::move(other_.m_source_id_))
    ,
    m_tStart_ (std::move(other_.m_tStart_))
    ,
    m_tEnd_ (std::move(other_.m_tEnd_))
    ,
    m_samples_count_ (std::move(other_.m_samples_count_))
    ,
    m_samples_dropped_ (std::move(other_.m_samples_dropped_))
    ,
    m_latency_min_ (std::move(other_.m_latency_min_))
    ,
    m_latency_mean_ (std::move(other_.m_latency_mean_))
    ,
    m_latency_max_ (std::move(other_.m_latency_max_))
    {
    } 

    ccPerf& ccPerf::operator=(ccPerf&&  other_) OMG_NOEXCEPT {
        ccPerf tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void ccPerf::swap(ccPerf& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_destination_id_, other_.m_destination_id_);
        swap(m_source_id_, other_.m_source_id_);
        swap(m_tStart_, other_.m_tStart_);
        swap(m_tEnd_, other_.m_tEnd_);
        swap(m_samples_count_, other_.m_samples_count_);
        swap(m_samples_dropped_, other_.m_samples_dropped_);
        swap(m_latency_min_, other_.m_latency_min_);
        swap(m_latency_mean_, other_.m_latency_mean_);
        swap(m_latency_max_, other_.m_latency_max_);
    }  

    bool ccPerf::operator == (const ccPerf& other_) const {
        if (m_destination_id_ != other_.m_destination_id_) {
            return false;
        }
        if (m_source_id_ != other_.m_source_id_) {
            return false;
        }
        if (m_tStart_ != other_.m_tStart_) {
            return false;
        }
        if (m_tEnd_ != other_.m_tEnd_) {
            return false;
        }
        if (m_samples_count_ != other_.m_samples_count_) {
            return false;
        }
        if (m_samples_dropped_ != other_.m_samples_dropped_) {
            return false;
        }
        if (m_latency_min_ != other_.m_latency_min_) {
            return false;
        }
        if (m_latency_mean_ != other_.m_latency_mean_) {
            return false;
        }
        if (m_latency_max_ != other_.m_latency_max_) {
            return false;
        }
        return true;
    }
    bool ccPerf::operator != (const ccPerf& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ccPerf& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "destination_id: " << sample.destination_id()<<", ";
        o << "source_id: " << sample.source_id()<<", ";
        o << "tStart: " << sample.tStart()<<", ";
        o << "tEnd: " << sample.tEnd()<<", ";
        o << "samples_count: " << sample.samples_count()<<", ";
        o << "samples_dropped: " << sample.samples_dropped()<<", ";
        o << "latency_min: " << sample.latency_min()<<", ";
        o << "latency_mean: " << sample.latency_mean()<<", ";
        o << "latency_max: " << sample.latency_max() ;
        o <<"]";
        return o;
    }

    // ---- ccControl: 

    ccControl::ccControl() :
        m_destination_id_ ("") ,
        m_frames_per_sample_ (0u)  {
    }   

    ccControl::ccControl (
        const std::string& destination_id,
        uint32_t frames_per_sample)
        :
            m_destination_id_( destination_id ),
            m_frames_per_sample_( frames_per_sample ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ccControl::ccControl(ccControl&& other_) OMG_NOEXCEPT  :m_destination_id_ (std::move(other_.m_destination_id_))
    ,
    m_frames_per_sample_ (std::move(other_.m_frames_per_sample_))
    {
    } 

    ccControl& ccControl::operator=(ccControl&&  other_) OMG_NOEXCEPT {
        ccControl tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void ccControl::swap(ccControl& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_destination_id_, other_.m_destination_id_);
        swap(m_frames_per_sample_, other_.m_frames_per_sample_);
    }  

    bool ccControl::operator == (const ccControl& other_) const {
        if (m_destination_id_ != other_.m_destination_id_) {
            return false;
        }
        if (m_frames_per_sample_ != other_.m_frames_per_sample_) {
            return false;
        }
        return true;
    }
    bool ccControl::operator != (const ccControl& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ccControl& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "destination_id: " << sample.destination_id()<<", ";
        o << "frames_per_sample: " << sample.frames_per_sample() ;
        o <<"]";
        return o;
    }

} // namespace cctypes  

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        const cctypes::payloadTypesEnum default_enumerator<cctypes::payloadTypesEnum>::value = cctypes::payloadTypesEnum::NO_PAYLOAD;
        template<>
        struct native_type_code< cctypes::payloadTypesEnum > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member payloadTypesEnum_g_tc_members[18]=
                {

                    {
                        (char *)"NO_PAYLOAD",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::NO_PAYLOAD), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TOP_INFO_EXCHANGE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::TOP_INFO_EXCHANGE), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"STREAM_FFMPEG_0",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::STREAM_FFMPEG_0), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"STREAM_FFMPEG_1",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::STREAM_FFMPEG_1), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"STREAM_GSTREAMER_0",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::STREAM_GSTREAMER_0), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"STREAM_GSTREAMER_1",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::STREAM_GSTREAMER_1), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"STREAM_OPENCV_0",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::STREAM_OPENCV_0), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"STREAM_OPENCV_1",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::STREAM_OPENCV_1), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FILE_TRANSFER_REQUEST",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::FILE_TRANSFER_REQUEST), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FILE_TRANSFER_ACCEPT",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::FILE_TRANSFER_ACCEPT), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FILE_TRANSFER_PAYLOAD",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::FILE_TRANSFER_PAYLOAD), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"FILE_TRANSFER_VERIFY",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::FILE_TRANSFER_VERIFY), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TEXT_CHAT_0",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::TEXT_CHAT_0), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TEST_PATTERN_0",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::TEST_PATTERN_0), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TRAFFIC_GEN_COMPRESSIBLE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::TRAFFIC_GEN_COMPRESSIBLE), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"TRAFFIC_GEN_NONCOMPRESSIBLE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::TRAFFIC_GEN_NONCOMPRESSIBLE), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"IMAGE_FILE",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::IMAGE_FILE), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"MAX_PAYLOAD_ENUM",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::payloadTypesEnum::MAX_PAYLOAD_ENUM), 
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PRIVATE_MEMBER,/* Member visibility */ 

                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode payloadTypesEnum_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::payloadTypesEnum", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        18, /* Number of members */
                        payloadTypesEnum_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for payloadTypesEnum*/

                if (is_initialized) {
                    return &payloadTypesEnum_g_tc;
                }

                payloadTypesEnum_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                payloadTypesEnum_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                payloadTypesEnum_g_tc._data._annotations._defaultValue._u.long_value = 0;

                payloadTypesEnum_g_tc._data._sampleAccessInfo = sample_access_info();
                payloadTypesEnum_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &payloadTypesEnum_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo payloadTypesEnum_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo payloadTypesEnum_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &payloadTypesEnum_g_sampleAccessInfo;
                }

                payloadTypesEnum_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                payloadTypesEnum_g_sampleAccessInfo.memberAccessInfos = 
                payloadTypesEnum_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::payloadTypesEnum);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        payloadTypesEnum_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        payloadTypesEnum_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                payloadTypesEnum_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                payloadTypesEnum_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::payloadTypesEnum >;

                payloadTypesEnum_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &payloadTypesEnum_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin payloadTypesEnum_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &payloadTypesEnum_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< cctypes::payloadTypesEnum >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::payloadTypesEnum >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< cctypes::ccBulk > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ccBulk_g_tc_destination_id_string;
                static DDS_TypeCode ccBulk_g_tc_source_id_string;
                static DDS_TypeCode ccBulk_g_tc_data_sequence;

                static DDS_TypeCode_Member ccBulk_g_tc_members[6]=
                {

                    {
                        (char *)"destination_id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"content_type",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"source_id",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"tstamp_first_frame",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"status",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"data",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ccBulk_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::ccBulk", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        6, /* Number of members */
                        ccBulk_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ccBulk*/

                if (is_initialized) {
                    return &ccBulk_g_tc;
                }

                ccBulk_g_tc_destination_id_string = initialize_string_typecode(((cctypes::KEY_STRING_LEN)));
                ccBulk_g_tc_source_id_string = initialize_string_typecode(((cctypes::KEY_STRING_LEN)));
                ccBulk_g_tc_data_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) > >(((cctypes::MAX_SEQUENCE_LEN)));

                ccBulk_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ccBulk_g_tc_data_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ccBulk_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ccBulk_g_tc_destination_id_string;
                ccBulk_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< cctypes::payloadTypesEnum>::get().native();
                ccBulk_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&ccBulk_g_tc_source_id_string;
                ccBulk_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ccBulk_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ccBulk_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)& ccBulk_g_tc_data_sequence;

                /* Initialize the values for member annotations. */
                ccBulk_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ccBulk_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ccBulk_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ccBulk_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                ccBulk_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ccBulk_g_tc_members[2]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ccBulk_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ccBulk_g_tc_members[3]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ccBulk_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ccBulk_g_tc_members[3]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ccBulk_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ccBulk_g_tc_members[3]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ccBulk_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_OCTET;
                ccBulk_g_tc_members[4]._annotations._defaultValue._u.octet_value = 0;
                ccBulk_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_OCTET;
                ccBulk_g_tc_members[4]._annotations._minValue._u.octet_value = RTIXCdrOctet_MIN;
                ccBulk_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_OCTET;
                ccBulk_g_tc_members[4]._annotations._maxValue._u.octet_value = RTIXCdrOctet_MAX;

                ccBulk_g_tc._data._sampleAccessInfo = sample_access_info();
                ccBulk_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ccBulk_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                cctypes::ccBulk *sample;

                static RTIXCdrMemberAccessInfo ccBulk_g_memberAccessInfos[6] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ccBulk_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ccBulk_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    cctypes::ccBulk);
                if (sample == NULL) {
                    return NULL;
                }

                ccBulk_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->destination_id() - (char *)sample);

                ccBulk_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->content_type() - (char *)sample);

                ccBulk_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->source_id() - (char *)sample);

                ccBulk_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->tstamp_first_frame() - (char *)sample);

                ccBulk_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->status() - (char *)sample);

                ccBulk_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->data() - (char *)sample);

                ccBulk_g_sampleAccessInfo.memberAccessInfos = 
                ccBulk_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::ccBulk);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ccBulk_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ccBulk_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ccBulk_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ccBulk_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::ccBulk >;

                ccBulk_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ccBulk_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ccBulk_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ccBulk_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< cctypes::ccBulk >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::ccBulk >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< cctypes::ccPerf > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ccPerf_g_tc_destination_id_string;
                static DDS_TypeCode ccPerf_g_tc_source_id_string;
                static DDS_TypeCode ccPerf_g_tc_latency_min_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3L, NULL,NULL);
                static DDS_TypeCode ccPerf_g_tc_latency_mean_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3L, NULL,NULL);
                static DDS_TypeCode ccPerf_g_tc_latency_max_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,3L, NULL,NULL);

                static DDS_TypeCode_Member ccPerf_g_tc_members[9]=
                {

                    {
                        (char *)"destination_id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"source_id",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"tStart",/* Member name */
                        {
                            2,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"tEnd",/* Member name */
                        {
                            3,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"samples_count",/* Member name */
                        {
                            4,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"samples_dropped",/* Member name */
                        {
                            5,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"latency_min",/* Member name */
                        {
                            6,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"latency_mean",/* Member name */
                        {
                            7,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"latency_max",/* Member name */
                        {
                            8,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ccPerf_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::ccPerf", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        9, /* Number of members */
                        ccPerf_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ccPerf*/

                if (is_initialized) {
                    return &ccPerf_g_tc;
                }

                ccPerf_g_tc_destination_id_string = initialize_string_typecode(((cctypes::KEY_STRING_LEN)));
                ccPerf_g_tc_source_id_string = initialize_string_typecode(((cctypes::KEY_STRING_LEN)));

                ccPerf_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ccPerf_g_tc_latency_min_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ccPerf_g_tc_latency_mean_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ccPerf_g_tc_latency_max_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ccPerf_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ccPerf_g_tc_destination_id_string;
                ccPerf_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&ccPerf_g_tc_source_id_string;
                ccPerf_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ccPerf_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ccPerf_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccPerf_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccPerf_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)& ccPerf_g_tc_latency_min_array;
                ccPerf_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)& ccPerf_g_tc_latency_mean_array;
                ccPerf_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)& ccPerf_g_tc_latency_max_array;

                /* Initialize the values for member annotations. */
                ccPerf_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ccPerf_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ccPerf_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ccPerf_g_tc_members[1]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ccPerf_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ccPerf_g_tc_members[2]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ccPerf_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ccPerf_g_tc_members[2]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ccPerf_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ccPerf_g_tc_members[2]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ccPerf_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ccPerf_g_tc_members[3]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ccPerf_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ccPerf_g_tc_members[3]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ccPerf_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ccPerf_g_tc_members[3]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ccPerf_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[4]._annotations._defaultValue._u.ulong_value = 0u;
                ccPerf_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[4]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccPerf_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[4]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccPerf_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[5]._annotations._defaultValue._u.ulong_value = 0u;
                ccPerf_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[5]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccPerf_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[5]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccPerf_g_tc._data._sampleAccessInfo = sample_access_info();
                ccPerf_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ccPerf_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                cctypes::ccPerf *sample;

                static RTIXCdrMemberAccessInfo ccPerf_g_memberAccessInfos[9] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ccPerf_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ccPerf_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    cctypes::ccPerf);
                if (sample == NULL) {
                    return NULL;
                }

                ccPerf_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->destination_id() - (char *)sample);

                ccPerf_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->source_id() - (char *)sample);

                ccPerf_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->tStart() - (char *)sample);

                ccPerf_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->tEnd() - (char *)sample);

                ccPerf_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->samples_count() - (char *)sample);

                ccPerf_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->samples_dropped() - (char *)sample);

                ccPerf_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latency_min() - (char *)sample);

                ccPerf_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latency_mean() - (char *)sample);

                ccPerf_g_memberAccessInfos[8].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latency_max() - (char *)sample);

                ccPerf_g_sampleAccessInfo.memberAccessInfos = 
                ccPerf_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::ccPerf);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ccPerf_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ccPerf_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ccPerf_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ccPerf_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::ccPerf >;

                ccPerf_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ccPerf_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ccPerf_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ccPerf_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< cctypes::ccPerf >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::ccPerf >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< cctypes::ccControl > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ccControl_g_tc_destination_id_string;

                static DDS_TypeCode_Member ccControl_g_tc_members[2]=
                {

                    {
                        (char *)"destination_id",/* Member name */
                        {
                            0,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_KEY_MEMBER , /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"frames_per_sample",/* Member name */
                        {
                            1,/* Representation ID */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        0, /* Ignored */
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }
                };

                static DDS_TypeCode ccControl_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::ccControl", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        2, /* Number of members */
                        ccControl_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ccControl*/

                if (is_initialized) {
                    return &ccControl_g_tc;
                }

                ccControl_g_tc_destination_id_string = initialize_string_typecode(((cctypes::KEY_STRING_LEN)));

                ccControl_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ccControl_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ccControl_g_tc_destination_id_string;
                ccControl_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                /* Initialize the values for member annotations. */
                ccControl_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ccControl_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ccControl_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccControl_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
                ccControl_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccControl_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccControl_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccControl_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccControl_g_tc._data._sampleAccessInfo = sample_access_info();
                ccControl_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ccControl_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                cctypes::ccControl *sample;

                static RTIXCdrMemberAccessInfo ccControl_g_memberAccessInfos[2] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ccControl_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ccControl_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    cctypes::ccControl);
                if (sample == NULL) {
                    return NULL;
                }

                ccControl_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->destination_id() - (char *)sample);

                ccControl_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->frames_per_sample() - (char *)sample);

                ccControl_g_sampleAccessInfo.memberAccessInfos = 
                ccControl_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::ccControl);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ccControl_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ccControl_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ccControl_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ccControl_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::ccControl >;

                ccControl_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ccControl_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ccControl_g_typePlugin = 
                {
                    NULL, /* serialize */
                    NULL, /* serialize_key */
                    NULL, /* deserialize_sample */
                    NULL, /* deserialize_key_sample */
                    NULL, /* skip */
                    NULL, /* get_serialized_sample_size */
                    NULL, /* get_serialized_sample_max_size_ex */
                    NULL, /* get_serialized_key_max_size_ex */
                    NULL, /* get_serialized_sample_min_size */
                    NULL, /* serialized_sample_to_key */
                    NULL,
                    NULL,
                    NULL,
                    NULL
                };

                return &ccControl_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< cctypes::ccControl >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::ccControl >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
        void topic_type_support< cctypes::ccBulk >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                cctypes::ccBulkPlugin_new,
                cctypes::ccBulkPlugin_delete);
        }

        std::vector<char>& topic_type_support< cctypes::ccBulk >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const cctypes::ccBulk& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ccBulkPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ccBulkPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< cctypes::ccBulk >::from_cdr_buffer(cctypes::ccBulk& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ccBulkPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create cctypes::ccBulk from cdr buffer");
        }

        void topic_type_support< cctypes::ccBulk >::reset_sample(cctypes::ccBulk& sample) 
        {
            sample.destination_id("");
            sample.content_type(cctypes::payloadTypesEnum::NO_PAYLOAD);
            sample.source_id("");
            sample.tstamp_first_frame(0ull);
            sample.status(0);
            ::rti::topic::reset_sample(sample.data());
        }

        void topic_type_support< cctypes::ccBulk >::allocate_sample(cctypes::ccBulk& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.destination_id(),  -1, (cctypes::KEY_STRING_LEN));
            ::rti::topic::allocate_sample(sample.content_type(),  -1, -1);
            ::rti::topic::allocate_sample(sample.source_id(),  -1, (cctypes::KEY_STRING_LEN));
            ::rti::topic::allocate_sample(sample.data(),  (cctypes::MAX_SEQUENCE_LEN), -1);
        }

        void topic_type_support< cctypes::ccPerf >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                cctypes::ccPerfPlugin_new,
                cctypes::ccPerfPlugin_delete);
        }

        std::vector<char>& topic_type_support< cctypes::ccPerf >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const cctypes::ccPerf& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ccPerfPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ccPerfPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< cctypes::ccPerf >::from_cdr_buffer(cctypes::ccPerf& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ccPerfPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create cctypes::ccPerf from cdr buffer");
        }

        void topic_type_support< cctypes::ccPerf >::reset_sample(cctypes::ccPerf& sample) 
        {
            sample.destination_id("");
            sample.source_id("");
            sample.tStart(0ull);
            sample.tEnd(0ull);
            sample.samples_count(0u);
            sample.samples_dropped(0u);
            ::rti::topic::reset_sample(sample.latency_min());
            ::rti::topic::reset_sample(sample.latency_mean());
            ::rti::topic::reset_sample(sample.latency_max());
        }

        void topic_type_support< cctypes::ccPerf >::allocate_sample(cctypes::ccPerf& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.destination_id(),  -1, (cctypes::KEY_STRING_LEN));
            ::rti::topic::allocate_sample(sample.source_id(),  -1, (cctypes::KEY_STRING_LEN));
            ::rti::topic::allocate_sample(sample.latency_min(),  -1, -1);
            ::rti::topic::allocate_sample(sample.latency_mean(),  -1, -1);
            ::rti::topic::allocate_sample(sample.latency_max(),  -1, -1);
        }

        void topic_type_support< cctypes::ccControl >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                cctypes::ccControlPlugin_new,
                cctypes::ccControlPlugin_delete);
        }

        std::vector<char>& topic_type_support< cctypes::ccControl >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const cctypes::ccControl& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ccControlPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ccControlPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< cctypes::ccControl >::from_cdr_buffer(cctypes::ccControl& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ccControlPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create cctypes::ccControl from cdr buffer");
        }

        void topic_type_support< cctypes::ccControl >::reset_sample(cctypes::ccControl& sample) 
        {
            sample.destination_id("");
            sample.frames_per_sample(0u);
        }

        void topic_type_support< cctypes::ccControl >::allocate_sample(cctypes::ccControl& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.destination_id(),  -1, (cctypes::KEY_STRING_LEN));
        }

    }
}  

