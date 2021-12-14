

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from cc_str_test_types.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <iosfwd>
#include <iomanip>

#include "rti/topic/cdr/Serialization.hpp"

#include "cc_str_test_types.hpp"
#include "cc_str_test_typesPlugin.hpp"

#include <rti/util/ostream_operators.hpp>

namespace cctypes {

    std::ostream& operator << (std::ostream& o,const commandMode& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case commandMode::PING_2SEC:
            o << "commandMode::PING_2SEC" << " ";
            break;
            case commandMode::REPEAT_ONLY:
            o << "commandMode::REPEAT_ONLY" << " ";
            break;
            case commandMode::MAX_CMDMODE_ENUM:
            o << "commandMode::MAX_CMDMODE_ENUM" << " ";
            break;
        }
        return o;
    }

    // ---- ccPerf: 

    ccPerf::ccPerf() :
        m_pub_id_ ("") ,
        m_sequence_id_ (0u) ,
        m_command_mode_(cctypes::commandMode::PING_2SEC) ,
        m_next_data_idx_ (0)  {
    }   

    ccPerf::ccPerf (
        const std::string& pub_id,
        uint32_t sequence_id,
        const cctypes::commandMode& command_mode,
        uint16_t next_data_idx,
        const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data_payload)
        :
            m_pub_id_( pub_id ),
            m_sequence_id_( sequence_id ),
            m_command_mode_( command_mode ),
            m_next_data_idx_( next_data_idx ),
            m_data_payload_( data_payload ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ccPerf::ccPerf(ccPerf&& other_) OMG_NOEXCEPT  :m_pub_id_ (std::move(other_.m_pub_id_))
    ,
    m_sequence_id_ (std::move(other_.m_sequence_id_))
    ,
    m_command_mode_ (std::move(other_.m_command_mode_))
    ,
    m_next_data_idx_ (std::move(other_.m_next_data_idx_))
    ,
    m_data_payload_ (std::move(other_.m_data_payload_))
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
        swap(m_pub_id_, other_.m_pub_id_);
        swap(m_sequence_id_, other_.m_sequence_id_);
        swap(m_command_mode_, other_.m_command_mode_);
        swap(m_next_data_idx_, other_.m_next_data_idx_);
        swap(m_data_payload_, other_.m_data_payload_);
    }  

    bool ccPerf::operator == (const ccPerf& other_) const {
        if (m_pub_id_ != other_.m_pub_id_) {
            return false;
        }
        if (m_sequence_id_ != other_.m_sequence_id_) {
            return false;
        }
        if (m_command_mode_ != other_.m_command_mode_) {
            return false;
        }
        if (m_next_data_idx_ != other_.m_next_data_idx_) {
            return false;
        }
        if (m_data_payload_ != other_.m_data_payload_) {
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
        o << "pub_id: " << sample.pub_id()<<", ";
        o << "sequence_id: " << sample.sequence_id()<<", ";
        o << "command_mode: " << sample.command_mode()<<", ";
        o << "next_data_idx: " << sample.next_data_idx()<<", ";
        o << "data_payload: " << sample.data_payload() ;
        o <<"]";
        return o;
    }

    std::ostream& operator << (std::ostream& o,const fillType& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        switch(sample){
            case fillType::ALLZEROS:
            o << "fillType::ALLZEROS" << " ";
            break;
            case fillType::PRNGDATA:
            o << "fillType::PRNGDATA" << " ";
            break;
            case fillType::MAX_FILLTYPE_ENUM:
            o << "fillType::MAX_FILLTYPE_ENUM" << " ";
            break;
        }
        return o;
    }

    // ---- ccTestControl: 

    ccTestControl::ccTestControl() :
        m_test_number_ (0u) ,
        m_command_mode_(cctypes::commandMode::PING_2SEC) ,
        m_data_init_type_(cctypes::fillType::ALLZEROS) ,
        m_bytes_per_sample_ (0u) ,
        m_bytes_per_second_ (0u) ,
        m_reports_per_second_ (0.0f) ,
        m_test_duration_millisec_ (0u)  {
    }   

    ccTestControl::ccTestControl (
        uint32_t test_number,
        const cctypes::commandMode& command_mode,
        const cctypes::fillType& data_init_type,
        uint32_t bytes_per_sample,
        uint32_t bytes_per_second,
        float reports_per_second,
        uint32_t test_duration_millisec)
        :
            m_test_number_( test_number ),
            m_command_mode_( command_mode ),
            m_data_init_type_( data_init_type ),
            m_bytes_per_sample_( bytes_per_sample ),
            m_bytes_per_second_( bytes_per_second ),
            m_reports_per_second_( reports_per_second ),
            m_test_duration_millisec_( test_duration_millisec ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ccTestControl::ccTestControl(ccTestControl&& other_) OMG_NOEXCEPT  :m_test_number_ (std::move(other_.m_test_number_))
    ,
    m_command_mode_ (std::move(other_.m_command_mode_))
    ,
    m_data_init_type_ (std::move(other_.m_data_init_type_))
    ,
    m_bytes_per_sample_ (std::move(other_.m_bytes_per_sample_))
    ,
    m_bytes_per_second_ (std::move(other_.m_bytes_per_second_))
    ,
    m_reports_per_second_ (std::move(other_.m_reports_per_second_))
    ,
    m_test_duration_millisec_ (std::move(other_.m_test_duration_millisec_))
    {
    } 

    ccTestControl& ccTestControl::operator=(ccTestControl&&  other_) OMG_NOEXCEPT {
        ccTestControl tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void ccTestControl::swap(ccTestControl& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_test_number_, other_.m_test_number_);
        swap(m_command_mode_, other_.m_command_mode_);
        swap(m_data_init_type_, other_.m_data_init_type_);
        swap(m_bytes_per_sample_, other_.m_bytes_per_sample_);
        swap(m_bytes_per_second_, other_.m_bytes_per_second_);
        swap(m_reports_per_second_, other_.m_reports_per_second_);
        swap(m_test_duration_millisec_, other_.m_test_duration_millisec_);
    }  

    bool ccTestControl::operator == (const ccTestControl& other_) const {
        if (m_test_number_ != other_.m_test_number_) {
            return false;
        }
        if (m_command_mode_ != other_.m_command_mode_) {
            return false;
        }
        if (m_data_init_type_ != other_.m_data_init_type_) {
            return false;
        }
        if (m_bytes_per_sample_ != other_.m_bytes_per_sample_) {
            return false;
        }
        if (m_bytes_per_second_ != other_.m_bytes_per_second_) {
            return false;
        }
        if (m_reports_per_second_ != other_.m_reports_per_second_) {
            return false;
        }
        if (m_test_duration_millisec_ != other_.m_test_duration_millisec_) {
            return false;
        }
        return true;
    }
    bool ccTestControl::operator != (const ccTestControl& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ccTestControl& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "test_number: " << sample.test_number()<<", ";
        o << "command_mode: " << sample.command_mode()<<", ";
        o << "data_init_type: " << sample.data_init_type()<<", ";
        o << "bytes_per_sample: " << sample.bytes_per_sample()<<", ";
        o << "bytes_per_second: " << sample.bytes_per_second()<<", ";
        o << "reports_per_second: " << std::setprecision(9) <<sample.reports_per_second()<<", ";
        o << "test_duration_millisec: " << sample.test_duration_millisec() ;
        o <<"]";
        return o;
    }

    // ---- ccTestReport: 

    ccTestReport::ccTestReport() :
        m_test_number_ (0u) ,
        m_samples_total_ (0u) ,
        m_lost_samples_total_ (0u) ,
        m_data_bytes_total_ (0ull)  {
    }   

    ccTestReport::ccTestReport (
        uint32_t test_number,
        uint32_t samples_total,
        uint32_t lost_samples_total,
        uint64_t data_bytes_total,
        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMin,
        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMean,
        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMax,
        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyStdDev)
        :
            m_test_number_( test_number ),
            m_samples_total_( samples_total ),
            m_lost_samples_total_( lost_samples_total ),
            m_data_bytes_total_( data_bytes_total ),
            m_latencyMin_( latencyMin ),
            m_latencyMean_( latencyMean ),
            m_latencyMax_( latencyMax ),
            m_latencyStdDev_( latencyStdDev ) {
    }

    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    ccTestReport::ccTestReport(ccTestReport&& other_) OMG_NOEXCEPT  :m_test_number_ (std::move(other_.m_test_number_))
    ,
    m_samples_total_ (std::move(other_.m_samples_total_))
    ,
    m_lost_samples_total_ (std::move(other_.m_lost_samples_total_))
    ,
    m_data_bytes_total_ (std::move(other_.m_data_bytes_total_))
    ,
    m_latencyMin_ (std::move(other_.m_latencyMin_))
    ,
    m_latencyMean_ (std::move(other_.m_latencyMean_))
    ,
    m_latencyMax_ (std::move(other_.m_latencyMax_))
    ,
    m_latencyStdDev_ (std::move(other_.m_latencyStdDev_))
    {
    } 

    ccTestReport& ccTestReport::operator=(ccTestReport&&  other_) OMG_NOEXCEPT {
        ccTestReport tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void ccTestReport::swap(ccTestReport& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_test_number_, other_.m_test_number_);
        swap(m_samples_total_, other_.m_samples_total_);
        swap(m_lost_samples_total_, other_.m_lost_samples_total_);
        swap(m_data_bytes_total_, other_.m_data_bytes_total_);
        swap(m_latencyMin_, other_.m_latencyMin_);
        swap(m_latencyMean_, other_.m_latencyMean_);
        swap(m_latencyMax_, other_.m_latencyMax_);
        swap(m_latencyStdDev_, other_.m_latencyStdDev_);
    }  

    bool ccTestReport::operator == (const ccTestReport& other_) const {
        if (m_test_number_ != other_.m_test_number_) {
            return false;
        }
        if (m_samples_total_ != other_.m_samples_total_) {
            return false;
        }
        if (m_lost_samples_total_ != other_.m_lost_samples_total_) {
            return false;
        }
        if (m_data_bytes_total_ != other_.m_data_bytes_total_) {
            return false;
        }
        if (m_latencyMin_ != other_.m_latencyMin_) {
            return false;
        }
        if (m_latencyMean_ != other_.m_latencyMean_) {
            return false;
        }
        if (m_latencyMax_ != other_.m_latencyMax_) {
            return false;
        }
        if (m_latencyStdDev_ != other_.m_latencyStdDev_) {
            return false;
        }
        return true;
    }
    bool ccTestReport::operator != (const ccTestReport& other_) const {
        return !this->operator ==(other_);
    }

    std::ostream& operator << (std::ostream& o,const ccTestReport& sample)
    {
        ::rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "test_number: " << sample.test_number()<<", ";
        o << "samples_total: " << sample.samples_total()<<", ";
        o << "lost_samples_total: " << sample.lost_samples_total()<<", ";
        o << "data_bytes_total: " << sample.data_bytes_total()<<", ";
        o << "latencyMin: " << sample.latencyMin()<<", ";
        o << "latencyMean: " << sample.latencyMean()<<", ";
        o << "latencyMax: " << sample.latencyMax()<<", ";
        o << "latencyStdDev: " << sample.latencyStdDev() ;
        o <<"]";
        return o;
    }

} // namespace cctypes  

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        const cctypes::commandMode default_enumerator<cctypes::commandMode>::value = cctypes::commandMode::PING_2SEC;
        template<>
        struct native_type_code< cctypes::commandMode > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member commandMode_g_tc_members[3]=
                {

                    {
                        (char *)"PING_2SEC",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::commandMode::PING_2SEC), 
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
                        (char *)"REPEAT_ONLY",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::commandMode::REPEAT_ONLY), 
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
                        (char *)"MAX_CMDMODE_ENUM",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::commandMode::MAX_CMDMODE_ENUM), 
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

                static DDS_TypeCode commandMode_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::commandMode", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        commandMode_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for commandMode*/

                if (is_initialized) {
                    return &commandMode_g_tc;
                }

                commandMode_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                commandMode_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                commandMode_g_tc._data._annotations._defaultValue._u.long_value = 0;

                commandMode_g_tc._data._sampleAccessInfo = sample_access_info();
                commandMode_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &commandMode_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo commandMode_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo commandMode_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &commandMode_g_sampleAccessInfo;
                }

                commandMode_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                commandMode_g_sampleAccessInfo.memberAccessInfos = 
                commandMode_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::commandMode);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        commandMode_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        commandMode_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                commandMode_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                commandMode_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::commandMode >;

                commandMode_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &commandMode_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin commandMode_g_typePlugin = 
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

                return &commandMode_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< cctypes::commandMode >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::commandMode >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< cctypes::ccPerf > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ccPerf_g_tc_pub_id_string;
                static DDS_TypeCode ccPerf_g_tc_data_payload_sequence;

                static DDS_TypeCode_Member ccPerf_g_tc_members[5]=
                {

                    {
                        (char *)"pub_id",/* Member name */
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
                        (char *)"sequence_id",/* Member name */
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
                        (char *)"command_mode",/* Member name */
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
                        (char *)"next_data_idx",/* Member name */
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
                        (char *)"data_payload",/* Member name */
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
                        5, /* Number of members */
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

                ccPerf_g_tc_pub_id_string = initialize_string_typecode(((cctypes::KEY_STRING_LEN)));
                ccPerf_g_tc_data_payload_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) > >(((cctypes::MAX_SEQUENCE_LEN)));

                ccPerf_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ccPerf_g_tc_data_payload_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_octet;
                ccPerf_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&ccPerf_g_tc_pub_id_string;
                ccPerf_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccPerf_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< cctypes::commandMode>::get().native();
                ccPerf_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
                ccPerf_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)& ccPerf_g_tc_data_payload_sequence;

                /* Initialize the values for member annotations. */
                ccPerf_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_STRING;
                ccPerf_g_tc_members[0]._annotations._defaultValue._u.string_value = (DDS_Char *) "";

                ccPerf_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
                ccPerf_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccPerf_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccPerf_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccPerf_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ccPerf_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;

                ccPerf_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
                ccPerf_g_tc_members[3]._annotations._defaultValue._u.ushort_value = 0;
                ccPerf_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
                ccPerf_g_tc_members[3]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
                ccPerf_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
                ccPerf_g_tc_members[3]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

                ccPerf_g_tc._data._sampleAccessInfo = sample_access_info();
                ccPerf_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ccPerf_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                cctypes::ccPerf *sample;

                static RTIXCdrMemberAccessInfo ccPerf_g_memberAccessInfos[5] =
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
                (RTIXCdrUnsignedLong) ((char *)&sample->pub_id() - (char *)sample);

                ccPerf_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->sequence_id() - (char *)sample);

                ccPerf_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->command_mode() - (char *)sample);

                ccPerf_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->next_data_idx() - (char *)sample);

                ccPerf_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->data_payload() - (char *)sample);

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
        const cctypes::fillType default_enumerator<cctypes::fillType>::value = cctypes::fillType::ALLZEROS;
        template<>
        struct native_type_code< cctypes::fillType > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member fillType_g_tc_members[3]=
                {

                    {
                        (char *)"ALLZEROS",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::fillType::ALLZEROS), 
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
                        (char *)"PRNGDATA",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::fillType::PRNGDATA), 
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
                        (char *)"MAX_FILLTYPE_ENUM",/* Member name */
                        {
                            0, /* Ignored */
                            DDS_BOOLEAN_FALSE,/* Is a pointer? */
                            -1, /* Bitfield bits */
                            NULL/* Member type code is assigned later */
                        },
                        static_cast<int>(cctypes::fillType::MAX_FILLTYPE_ENUM), 
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

                static DDS_TypeCode fillType_g_tc =
                {{
                        DDS_TK_ENUM, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::fillType", /* Name */
                        NULL,     /* Base class type code is assigned later */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        3, /* Number of members */
                        fillType_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Type Modifier */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for fillType*/

                if (is_initialized) {
                    return &fillType_g_tc;
                }

                fillType_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                /* Initialize the values for annotations. */
                fillType_g_tc._data._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                fillType_g_tc._data._annotations._defaultValue._u.long_value = 0;

                fillType_g_tc._data._sampleAccessInfo = sample_access_info();
                fillType_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &fillType_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                static RTIXCdrMemberAccessInfo fillType_g_memberAccessInfos[1] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo fillType_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &fillType_g_sampleAccessInfo;
                }

                fillType_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 0;

                fillType_g_sampleAccessInfo.memberAccessInfos = 
                fillType_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::fillType);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        fillType_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        fillType_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                fillType_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                fillType_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::fillType >;

                fillType_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &fillType_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin fillType_g_typePlugin = 
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

                return &fillType_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::EnumType& dynamic_type< cctypes::fillType >::get()
        {
            return static_cast<const ::dds::core::xtypes::EnumType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::fillType >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< cctypes::ccTestControl > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode_Member ccTestControl_g_tc_members[7]=
                {

                    {
                        (char *)"test_number",/* Member name */
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
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"command_mode",/* Member name */
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
                        (char *)"data_init_type",/* Member name */
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
                        (char *)"bytes_per_sample",/* Member name */
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
                        (char *)"bytes_per_second",/* Member name */
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
                        (char *)"reports_per_second",/* Member name */
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
                        (char *)"test_duration_millisec",/* Member name */
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
                    }
                };

                static DDS_TypeCode ccTestControl_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::ccTestControl", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        7, /* Number of members */
                        ccTestControl_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ccTestControl*/

                if (is_initialized) {
                    return &ccTestControl_g_tc;
                }

                ccTestControl_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ccTestControl_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccTestControl_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< cctypes::commandMode>::get().native();
                ccTestControl_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&::rti::topic::dynamic_type< cctypes::fillType>::get().native();
                ccTestControl_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccTestControl_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccTestControl_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                ccTestControl_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;

                /* Initialize the values for member annotations. */
                ccTestControl_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[0]._annotations._defaultValue._u.ulong_value = 0u;
                ccTestControl_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[0]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccTestControl_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[0]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccTestControl_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ccTestControl_g_tc_members[1]._annotations._defaultValue._u.enumerated_value = 0;

                ccTestControl_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ENUM;
                ccTestControl_g_tc_members[2]._annotations._defaultValue._u.enumerated_value = 0;

                ccTestControl_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[3]._annotations._defaultValue._u.ulong_value = 0u;
                ccTestControl_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[3]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccTestControl_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[3]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccTestControl_g_tc_members[4]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[4]._annotations._defaultValue._u.ulong_value = 0u;
                ccTestControl_g_tc_members[4]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[4]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccTestControl_g_tc_members[4]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[4]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccTestControl_g_tc_members[5]._annotations._defaultValue._d = RTI_XCDR_TK_FLOAT;
                ccTestControl_g_tc_members[5]._annotations._defaultValue._u.float_value = 0.0f;
                ccTestControl_g_tc_members[5]._annotations._minValue._d = RTI_XCDR_TK_FLOAT;
                ccTestControl_g_tc_members[5]._annotations._minValue._u.float_value = RTIXCdrFloat_MIN;
                ccTestControl_g_tc_members[5]._annotations._maxValue._d = RTI_XCDR_TK_FLOAT;
                ccTestControl_g_tc_members[5]._annotations._maxValue._u.float_value = RTIXCdrFloat_MAX;

                ccTestControl_g_tc_members[6]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[6]._annotations._defaultValue._u.ulong_value = 0u;
                ccTestControl_g_tc_members[6]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[6]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccTestControl_g_tc_members[6]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccTestControl_g_tc_members[6]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccTestControl_g_tc._data._sampleAccessInfo = sample_access_info();
                ccTestControl_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ccTestControl_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                cctypes::ccTestControl *sample;

                static RTIXCdrMemberAccessInfo ccTestControl_g_memberAccessInfos[7] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ccTestControl_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ccTestControl_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    cctypes::ccTestControl);
                if (sample == NULL) {
                    return NULL;
                }

                ccTestControl_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->test_number() - (char *)sample);

                ccTestControl_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->command_mode() - (char *)sample);

                ccTestControl_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->data_init_type() - (char *)sample);

                ccTestControl_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->bytes_per_sample() - (char *)sample);

                ccTestControl_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->bytes_per_second() - (char *)sample);

                ccTestControl_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->reports_per_second() - (char *)sample);

                ccTestControl_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->test_duration_millisec() - (char *)sample);

                ccTestControl_g_sampleAccessInfo.memberAccessInfos = 
                ccTestControl_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::ccTestControl);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ccTestControl_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ccTestControl_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ccTestControl_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ccTestControl_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::ccTestControl >;

                ccTestControl_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ccTestControl_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ccTestControl_g_typePlugin = 
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

                return &ccTestControl_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< cctypes::ccTestControl >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::ccTestControl >::get())));
        }

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct native_type_code< cctypes::ccTestReport > {
            static DDS_TypeCode * get()
            {
                using namespace ::rti::topic::interpreter;

                static RTIBool is_initialized = RTI_FALSE;

                static DDS_TypeCode ccTestReport_g_tc_latencyMin_sequence;
                static DDS_TypeCode ccTestReport_g_tc_latencyMean_sequence;
                static DDS_TypeCode ccTestReport_g_tc_latencyMax_sequence;
                static DDS_TypeCode ccTestReport_g_tc_latencyStdDev_sequence;

                static DDS_TypeCode_Member ccTestReport_g_tc_members[8]=
                {

                    {
                        (char *)"test_number",/* Member name */
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
                        RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
                        DDS_PUBLIC_MEMBER,/* Member visibility */
                        1,
                        NULL, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER
                    }, 
                    {
                        (char *)"samples_total",/* Member name */
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
                        (char *)"lost_samples_total",/* Member name */
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
                        (char *)"data_bytes_total",/* Member name */
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
                        (char *)"latencyMin",/* Member name */
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
                        (char *)"latencyMean",/* Member name */
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
                        (char *)"latencyMax",/* Member name */
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
                        (char *)"latencyStdDev",/* Member name */
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
                    }
                };

                static DDS_TypeCode ccTestReport_g_tc =
                {{
                        DDS_TK_STRUCT, /* Kind */
                        DDS_BOOLEAN_FALSE, /* Ignored */
                        -1, /*Ignored*/
                        (char *)"cctypes::ccTestReport", /* Name */
                        NULL, /* Ignored */      
                        0, /* Ignored */
                        0, /* Ignored */
                        NULL, /* Ignored */
                        8, /* Number of members */
                        ccTestReport_g_tc_members, /* Members */
                        DDS_VM_NONE, /* Ignored */
                        RTICdrTypeCodeAnnotations_INITIALIZER,
                        DDS_BOOLEAN_TRUE, /* _isCopyable */
                        NULL, /* _sampleAccessInfo: assigned later */
                        NULL /* _typePlugin: assigned later */
                    }}; /* Type code for ccTestReport*/

                if (is_initialized) {
                    return &ccTestReport_g_tc;
                }

                ccTestReport_g_tc_latencyMin_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > >(((cctypes::MAX_LATENCY_SEGMENTS)));
                ccTestReport_g_tc_latencyMean_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > >(((cctypes::MAX_LATENCY_SEGMENTS)));
                ccTestReport_g_tc_latencyMax_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > >(((cctypes::MAX_LATENCY_SEGMENTS)));
                ccTestReport_g_tc_latencyStdDev_sequence = initialize_sequence_typecode< ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > >(((cctypes::MAX_LATENCY_SEGMENTS)));

                ccTestReport_g_tc._data._annotations._allowedDataRepresentationMask = 5;

                ccTestReport_g_tc_latencyMin_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                ccTestReport_g_tc_latencyMean_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                ccTestReport_g_tc_latencyMax_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                ccTestReport_g_tc_latencyStdDev_sequence._data._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;
                ccTestReport_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccTestReport_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccTestReport_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulong;
                ccTestReport_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ulonglong;
                ccTestReport_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)& ccTestReport_g_tc_latencyMin_sequence;
                ccTestReport_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)& ccTestReport_g_tc_latencyMean_sequence;
                ccTestReport_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)& ccTestReport_g_tc_latencyMax_sequence;
                ccTestReport_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)& ccTestReport_g_tc_latencyStdDev_sequence;

                /* Initialize the values for member annotations. */
                ccTestReport_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[0]._annotations._defaultValue._u.ulong_value = 0u;
                ccTestReport_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[0]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccTestReport_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[0]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccTestReport_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[1]._annotations._defaultValue._u.ulong_value = 0u;
                ccTestReport_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[1]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccTestReport_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[1]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccTestReport_g_tc_members[2]._annotations._defaultValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[2]._annotations._defaultValue._u.ulong_value = 0u;
                ccTestReport_g_tc_members[2]._annotations._minValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[2]._annotations._minValue._u.ulong_value = RTIXCdrUnsignedLong_MIN;
                ccTestReport_g_tc_members[2]._annotations._maxValue._d = RTI_XCDR_TK_ULONG;
                ccTestReport_g_tc_members[2]._annotations._maxValue._u.ulong_value = RTIXCdrUnsignedLong_MAX;

                ccTestReport_g_tc_members[3]._annotations._defaultValue._d = RTI_XCDR_TK_ULONGLONG;
                ccTestReport_g_tc_members[3]._annotations._defaultValue._u.ulong_long_value = 0ull;
                ccTestReport_g_tc_members[3]._annotations._minValue._d = RTI_XCDR_TK_ULONGLONG;
                ccTestReport_g_tc_members[3]._annotations._minValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MIN;
                ccTestReport_g_tc_members[3]._annotations._maxValue._d = RTI_XCDR_TK_ULONGLONG;
                ccTestReport_g_tc_members[3]._annotations._maxValue._u.ulong_long_value = RTIXCdrUnsignedLongLong_MAX;

                ccTestReport_g_tc._data._sampleAccessInfo = sample_access_info();
                ccTestReport_g_tc._data._typePlugin = type_plugin_info();    

                is_initialized = RTI_TRUE;

                return &ccTestReport_g_tc;
            }

            static RTIXCdrSampleAccessInfo * sample_access_info()
            {
                static RTIBool is_initialized = RTI_FALSE;

                cctypes::ccTestReport *sample;

                static RTIXCdrMemberAccessInfo ccTestReport_g_memberAccessInfos[8] =
                {RTIXCdrMemberAccessInfo_INITIALIZER};

                static RTIXCdrSampleAccessInfo ccTestReport_g_sampleAccessInfo = 
                RTIXCdrSampleAccessInfo_INITIALIZER;

                if (is_initialized) {
                    return (RTIXCdrSampleAccessInfo*) &ccTestReport_g_sampleAccessInfo;
                }

                RTIXCdrHeap_allocateStruct(
                    &sample, 
                    cctypes::ccTestReport);
                if (sample == NULL) {
                    return NULL;
                }

                ccTestReport_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->test_number() - (char *)sample);

                ccTestReport_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->samples_total() - (char *)sample);

                ccTestReport_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->lost_samples_total() - (char *)sample);

                ccTestReport_g_memberAccessInfos[3].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->data_bytes_total() - (char *)sample);

                ccTestReport_g_memberAccessInfos[4].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latencyMin() - (char *)sample);

                ccTestReport_g_memberAccessInfos[5].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latencyMean() - (char *)sample);

                ccTestReport_g_memberAccessInfos[6].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latencyMax() - (char *)sample);

                ccTestReport_g_memberAccessInfos[7].bindingMemberValueOffset[0] = 
                (RTIXCdrUnsignedLong) ((char *)&sample->latencyStdDev() - (char *)sample);

                ccTestReport_g_sampleAccessInfo.memberAccessInfos = 
                ccTestReport_g_memberAccessInfos;

                {
                    size_t candidateTypeSize = sizeof(cctypes::ccTestReport);

                    if (candidateTypeSize > RTIXCdrLong_MAX) {
                        ccTestReport_g_sampleAccessInfo.typeSize[0] =
                        RTIXCdrLong_MAX;
                    } else {
                        ccTestReport_g_sampleAccessInfo.typeSize[0] =
                        (RTIXCdrUnsignedLong) candidateTypeSize;
                    }
                }

                ccTestReport_g_sampleAccessInfo.useGetMemberValueOnlyWithRef =
                RTI_XCDR_TRUE;

                ccTestReport_g_sampleAccessInfo.getMemberValuePointerFcn = 
                interpreter::get_aggregation_value_pointer< cctypes::ccTestReport >;

                ccTestReport_g_sampleAccessInfo.languageBinding = 
                RTI_XCDR_TYPE_BINDING_CPP_11_STL ;

                RTIXCdrHeap_freeStruct(sample);
                is_initialized = RTI_TRUE;
                return (RTIXCdrSampleAccessInfo*) &ccTestReport_g_sampleAccessInfo;
            }

            static RTIXCdrTypePlugin * type_plugin_info()
            {
                static RTIXCdrTypePlugin ccTestReport_g_typePlugin = 
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

                return &ccTestReport_g_typePlugin;
            }
        }; // native_type_code
        #endif

        const ::dds::core::xtypes::StructType& dynamic_type< cctypes::ccTestReport >::get()
        {
            return static_cast<const ::dds::core::xtypes::StructType&>(
                ::rti::core::native_conversions::cast_from_native< ::dds::core::xtypes::DynamicType >(
                    *(native_type_code< cctypes::ccTestReport >::get())));
        }

    }
}

namespace dds { 
    namespace topic {
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
            sample.pub_id("");
            sample.sequence_id(0u);
            sample.command_mode(cctypes::commandMode::PING_2SEC);
            sample.next_data_idx(0);
            ::rti::topic::reset_sample(sample.data_payload());
        }

        void topic_type_support< cctypes::ccPerf >::allocate_sample(cctypes::ccPerf& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.pub_id(),  -1, (cctypes::KEY_STRING_LEN));
            ::rti::topic::allocate_sample(sample.command_mode(),  -1, -1);
            ::rti::topic::allocate_sample(sample.data_payload(),  (cctypes::MAX_SEQUENCE_LEN), -1);
        }

        void topic_type_support< cctypes::ccTestControl >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                cctypes::ccTestControlPlugin_new,
                cctypes::ccTestControlPlugin_delete);
        }

        std::vector<char>& topic_type_support< cctypes::ccTestControl >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const cctypes::ccTestControl& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ccTestControlPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ccTestControlPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< cctypes::ccTestControl >::from_cdr_buffer(cctypes::ccTestControl& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ccTestControlPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create cctypes::ccTestControl from cdr buffer");
        }

        void topic_type_support< cctypes::ccTestControl >::reset_sample(cctypes::ccTestControl& sample) 
        {
            sample.test_number(0u);
            sample.command_mode(cctypes::commandMode::PING_2SEC);
            sample.data_init_type(cctypes::fillType::ALLZEROS);
            sample.bytes_per_sample(0u);
            sample.bytes_per_second(0u);
            sample.reports_per_second(0.0f);
            sample.test_duration_millisec(0u);
        }

        void topic_type_support< cctypes::ccTestControl >::allocate_sample(cctypes::ccTestControl& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.command_mode(),  -1, -1);
            ::rti::topic::allocate_sample(sample.data_init_type(),  -1, -1);
        }

        void topic_type_support< cctypes::ccTestReport >:: register_type(
            ::dds::domain::DomainParticipant& participant,
            const std::string& type_name) 
        {

            ::rti::domain::register_type_plugin(
                participant,
                type_name,
                cctypes::ccTestReportPlugin_new,
                cctypes::ccTestReportPlugin_delete);
        }

        std::vector<char>& topic_type_support< cctypes::ccTestReport >::to_cdr_buffer(
            std::vector<char>& buffer, 
            const cctypes::ccTestReport& sample,
            ::dds::core::policy::DataRepresentationId representation)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = ccTestReportPlugin_serialize_to_cdr_buffer(
                NULL, 
                &length,
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = ccTestReportPlugin_serialize_to_cdr_buffer(
                &buffer[0], 
                &length, 
                &sample,
                representation);
            ::rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;
        }

        void topic_type_support< cctypes::ccTestReport >::from_cdr_buffer(cctypes::ccTestReport& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = ccTestReportPlugin_deserialize_from_cdr_buffer(
                &sample, 
                &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            ::rti::core::check_return_code(ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
            "Failed to create cctypes::ccTestReport from cdr buffer");
        }

        void topic_type_support< cctypes::ccTestReport >::reset_sample(cctypes::ccTestReport& sample) 
        {
            sample.test_number(0u);
            sample.samples_total(0u);
            sample.lost_samples_total(0u);
            sample.data_bytes_total(0ull);
            ::rti::topic::reset_sample(sample.latencyMin());
            ::rti::topic::reset_sample(sample.latencyMean());
            ::rti::topic::reset_sample(sample.latencyMax());
            ::rti::topic::reset_sample(sample.latencyStdDev());
        }

        void topic_type_support< cctypes::ccTestReport >::allocate_sample(cctypes::ccTestReport& sample, int, int) 
        {
            ::rti::topic::allocate_sample(sample.latencyMin(),  (cctypes::MAX_LATENCY_SEGMENTS), -1);
            ::rti::topic::allocate_sample(sample.latencyMean(),  (cctypes::MAX_LATENCY_SEGMENTS), -1);
            ::rti::topic::allocate_sample(sample.latencyMax(),  (cctypes::MAX_LATENCY_SEGMENTS), -1);
            ::rti::topic::allocate_sample(sample.latencyStdDev(),  (cctypes::MAX_LATENCY_SEGMENTS), -1);
        }

    }
}  

