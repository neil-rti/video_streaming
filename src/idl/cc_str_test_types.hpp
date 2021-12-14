

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from cc_str_test_types.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef cc_str_test_types_1867997756_hpp
#define cc_str_test_types_1867997756_hpp

#include <iosfwd>

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/core/BoundedSequence.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "dds/core/External.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace cctypes {

    static const uint32_t MAX_SEQUENCE_LEN = 18800UL;

    static const uint8_t KEY_STRING_LEN = 8;

    static const uint32_t MAX_LATENCY_SEGMENTS = 16UL;
    enum class commandMode {
        PING_2SEC = 0, 
        REPEAT_ONLY, 
        MAX_CMDMODE_ENUM
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const commandMode& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< uint8_t >;
    template class NDDSUSERDllExport std::vector< uint8_t >;
    #endif
    class NDDSUSERDllExport ccPerf {
      public:
        ccPerf();

        ccPerf(
            const std::string& pub_id,
            uint32_t sequence_id,
            const cctypes::commandMode& command_mode,
            uint16_t next_data_idx,
            const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data_payload);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ccPerf (ccPerf&&) = default;
        ccPerf& operator=(ccPerf&&) = default;
        ccPerf& operator=(const ccPerf&) = default;
        ccPerf(const ccPerf&) = default;
        #else
        ccPerf(ccPerf&& other_) OMG_NOEXCEPT;  
        ccPerf& operator=(ccPerf&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        std::string& pub_id() OMG_NOEXCEPT {
            return m_pub_id_;
        }

        const std::string& pub_id() const OMG_NOEXCEPT {
            return m_pub_id_;
        }

        void pub_id(const std::string& value) {
            m_pub_id_ = value;
        }

        void pub_id(std::string&& value) {
            m_pub_id_ = std::move(value);
        }
        uint32_t& sequence_id() OMG_NOEXCEPT {
            return m_sequence_id_;
        }

        const uint32_t& sequence_id() const OMG_NOEXCEPT {
            return m_sequence_id_;
        }

        void sequence_id(uint32_t value) {
            m_sequence_id_ = value;
        }

        cctypes::commandMode& command_mode() OMG_NOEXCEPT {
            return m_command_mode_;
        }

        const cctypes::commandMode& command_mode() const OMG_NOEXCEPT {
            return m_command_mode_;
        }

        void command_mode(const cctypes::commandMode& value) {
            m_command_mode_ = value;
        }

        void command_mode(cctypes::commandMode&& value) {
            m_command_mode_ = std::move(value);
        }
        uint16_t& next_data_idx() OMG_NOEXCEPT {
            return m_next_data_idx_;
        }

        const uint16_t& next_data_idx() const OMG_NOEXCEPT {
            return m_next_data_idx_;
        }

        void next_data_idx(uint16_t value) {
            m_next_data_idx_ = value;
        }

        ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data_payload() OMG_NOEXCEPT {
            return m_data_payload_;
        }

        const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data_payload() const OMG_NOEXCEPT {
            return m_data_payload_;
        }

        void data_payload(const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& value) {
            m_data_payload_ = value;
        }

        void data_payload(::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >&& value) {
            m_data_payload_ = std::move(value);
        }

        bool operator == (const ccPerf& other_) const;
        bool operator != (const ccPerf& other_) const;

        void swap(ccPerf& other_) OMG_NOEXCEPT ;

      private:

        std::string m_pub_id_;
        uint32_t m_sequence_id_;
        cctypes::commandMode m_command_mode_;
        uint16_t m_next_data_idx_;
        ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) > m_data_payload_;

    };

    inline void swap(ccPerf& a, ccPerf& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ccPerf& sample);

    enum class fillType {
        ALLZEROS = 0, 
        PRNGDATA, 
        MAX_FILLTYPE_ENUM
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const fillType& sample);

    class NDDSUSERDllExport ccTestControl {
      public:
        ccTestControl();

        ccTestControl(
            uint32_t test_number,
            const cctypes::commandMode& command_mode,
            const cctypes::fillType& data_init_type,
            uint32_t bytes_per_sample,
            uint32_t bytes_per_second,
            float reports_per_second,
            uint32_t test_duration_millisec);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ccTestControl (ccTestControl&&) = default;
        ccTestControl& operator=(ccTestControl&&) = default;
        ccTestControl& operator=(const ccTestControl&) = default;
        ccTestControl(const ccTestControl&) = default;
        #else
        ccTestControl(ccTestControl&& other_) OMG_NOEXCEPT;  
        ccTestControl& operator=(ccTestControl&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint32_t& test_number() OMG_NOEXCEPT {
            return m_test_number_;
        }

        const uint32_t& test_number() const OMG_NOEXCEPT {
            return m_test_number_;
        }

        void test_number(uint32_t value) {
            m_test_number_ = value;
        }

        cctypes::commandMode& command_mode() OMG_NOEXCEPT {
            return m_command_mode_;
        }

        const cctypes::commandMode& command_mode() const OMG_NOEXCEPT {
            return m_command_mode_;
        }

        void command_mode(const cctypes::commandMode& value) {
            m_command_mode_ = value;
        }

        void command_mode(cctypes::commandMode&& value) {
            m_command_mode_ = std::move(value);
        }
        cctypes::fillType& data_init_type() OMG_NOEXCEPT {
            return m_data_init_type_;
        }

        const cctypes::fillType& data_init_type() const OMG_NOEXCEPT {
            return m_data_init_type_;
        }

        void data_init_type(const cctypes::fillType& value) {
            m_data_init_type_ = value;
        }

        void data_init_type(cctypes::fillType&& value) {
            m_data_init_type_ = std::move(value);
        }
        uint32_t& bytes_per_sample() OMG_NOEXCEPT {
            return m_bytes_per_sample_;
        }

        const uint32_t& bytes_per_sample() const OMG_NOEXCEPT {
            return m_bytes_per_sample_;
        }

        void bytes_per_sample(uint32_t value) {
            m_bytes_per_sample_ = value;
        }

        uint32_t& bytes_per_second() OMG_NOEXCEPT {
            return m_bytes_per_second_;
        }

        const uint32_t& bytes_per_second() const OMG_NOEXCEPT {
            return m_bytes_per_second_;
        }

        void bytes_per_second(uint32_t value) {
            m_bytes_per_second_ = value;
        }

        float& reports_per_second() OMG_NOEXCEPT {
            return m_reports_per_second_;
        }

        const float& reports_per_second() const OMG_NOEXCEPT {
            return m_reports_per_second_;
        }

        void reports_per_second(float value) {
            m_reports_per_second_ = value;
        }

        uint32_t& test_duration_millisec() OMG_NOEXCEPT {
            return m_test_duration_millisec_;
        }

        const uint32_t& test_duration_millisec() const OMG_NOEXCEPT {
            return m_test_duration_millisec_;
        }

        void test_duration_millisec(uint32_t value) {
            m_test_duration_millisec_ = value;
        }

        bool operator == (const ccTestControl& other_) const;
        bool operator != (const ccTestControl& other_) const;

        void swap(ccTestControl& other_) OMG_NOEXCEPT ;

      private:

        uint32_t m_test_number_;
        cctypes::commandMode m_command_mode_;
        cctypes::fillType m_data_init_type_;
        uint32_t m_bytes_per_sample_;
        uint32_t m_bytes_per_second_;
        float m_reports_per_second_;
        uint32_t m_test_duration_millisec_;

    };

    inline void swap(ccTestControl& a, ccTestControl& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ccTestControl& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< float >;
    template class NDDSUSERDllExport std::vector< float >;
    #endif
    class NDDSUSERDllExport ccTestReport {
      public:
        ccTestReport();

        ccTestReport(
            uint32_t test_number,
            uint32_t samples_total,
            uint32_t lost_samples_total,
            uint64_t data_bytes_total,
            const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMin,
            const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMean,
            const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMax,
            const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyStdDev);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ccTestReport (ccTestReport&&) = default;
        ccTestReport& operator=(ccTestReport&&) = default;
        ccTestReport& operator=(const ccTestReport&) = default;
        ccTestReport(const ccTestReport&) = default;
        #else
        ccTestReport(ccTestReport&& other_) OMG_NOEXCEPT;  
        ccTestReport& operator=(ccTestReport&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        uint32_t& test_number() OMG_NOEXCEPT {
            return m_test_number_;
        }

        const uint32_t& test_number() const OMG_NOEXCEPT {
            return m_test_number_;
        }

        void test_number(uint32_t value) {
            m_test_number_ = value;
        }

        uint32_t& samples_total() OMG_NOEXCEPT {
            return m_samples_total_;
        }

        const uint32_t& samples_total() const OMG_NOEXCEPT {
            return m_samples_total_;
        }

        void samples_total(uint32_t value) {
            m_samples_total_ = value;
        }

        uint32_t& lost_samples_total() OMG_NOEXCEPT {
            return m_lost_samples_total_;
        }

        const uint32_t& lost_samples_total() const OMG_NOEXCEPT {
            return m_lost_samples_total_;
        }

        void lost_samples_total(uint32_t value) {
            m_lost_samples_total_ = value;
        }

        uint64_t& data_bytes_total() OMG_NOEXCEPT {
            return m_data_bytes_total_;
        }

        const uint64_t& data_bytes_total() const OMG_NOEXCEPT {
            return m_data_bytes_total_;
        }

        void data_bytes_total(uint64_t value) {
            m_data_bytes_total_ = value;
        }

        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMin() OMG_NOEXCEPT {
            return m_latencyMin_;
        }

        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMin() const OMG_NOEXCEPT {
            return m_latencyMin_;
        }

        void latencyMin(const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& value) {
            m_latencyMin_ = value;
        }

        void latencyMin(::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >&& value) {
            m_latencyMin_ = std::move(value);
        }
        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMean() OMG_NOEXCEPT {
            return m_latencyMean_;
        }

        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMean() const OMG_NOEXCEPT {
            return m_latencyMean_;
        }

        void latencyMean(const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& value) {
            m_latencyMean_ = value;
        }

        void latencyMean(::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >&& value) {
            m_latencyMean_ = std::move(value);
        }
        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMax() OMG_NOEXCEPT {
            return m_latencyMax_;
        }

        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyMax() const OMG_NOEXCEPT {
            return m_latencyMax_;
        }

        void latencyMax(const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& value) {
            m_latencyMax_ = value;
        }

        void latencyMax(::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >&& value) {
            m_latencyMax_ = std::move(value);
        }
        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyStdDev() OMG_NOEXCEPT {
            return m_latencyStdDev_;
        }

        const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& latencyStdDev() const OMG_NOEXCEPT {
            return m_latencyStdDev_;
        }

        void latencyStdDev(const ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >& value) {
            m_latencyStdDev_ = value;
        }

        void latencyStdDev(::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) >&& value) {
            m_latencyStdDev_ = std::move(value);
        }

        bool operator == (const ccTestReport& other_) const;
        bool operator != (const ccTestReport& other_) const;

        void swap(ccTestReport& other_) OMG_NOEXCEPT ;

      private:

        uint32_t m_test_number_;
        uint32_t m_samples_total_;
        uint32_t m_lost_samples_total_;
        uint64_t m_data_bytes_total_;
        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > m_latencyMin_;
        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > m_latencyMean_;
        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > m_latencyMax_;
        ::rti::core::bounded_sequence< float, (cctypes::MAX_LATENCY_SEGMENTS) > m_latencyStdDev_;

    };

    inline void swap(ccTestReport& a, ccTestReport& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ccTestReport& sample);

} // namespace cctypes  

namespace rti {
    namespace flat {
        namespace topic {
        }
    }
}
namespace dds {
    namespace topic {

        template<>
        struct topic_type_name< cctypes::ccPerf > {
            NDDSUSERDllExport static std::string value() {
                return "cctypes::ccPerf";
            }
        };

        template<>
        struct is_topic_type< cctypes::ccPerf > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< cctypes::ccPerf > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const cctypes::ccPerf& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(cctypes::ccPerf& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(cctypes::ccPerf& sample);

            NDDSUSERDllExport 
            static void allocate_sample(cctypes::ccPerf& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< cctypes::ccTestControl > {
            NDDSUSERDllExport static std::string value() {
                return "cctypes::ccTestControl";
            }
        };

        template<>
        struct is_topic_type< cctypes::ccTestControl > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< cctypes::ccTestControl > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const cctypes::ccTestControl& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(cctypes::ccTestControl& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(cctypes::ccTestControl& sample);

            NDDSUSERDllExport 
            static void allocate_sample(cctypes::ccTestControl& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

        template<>
        struct topic_type_name< cctypes::ccTestReport > {
            NDDSUSERDllExport static std::string value() {
                return "cctypes::ccTestReport";
            }
        };

        template<>
        struct is_topic_type< cctypes::ccTestReport > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< cctypes::ccTestReport > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const cctypes::ccTestReport& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(cctypes::ccTestReport& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(cctypes::ccTestReport& sample);

            NDDSUSERDllExport 
            static void allocate_sample(cctypes::ccTestReport& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<cctypes::commandMode>
        {
            static const cctypes::commandMode value;
        };
        template<>
        struct dynamic_type< cctypes::commandMode > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::commandMode > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< cctypes::ccPerf > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::ccPerf > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<cctypes::fillType>
        {
            static const cctypes::fillType value;
        };
        template<>
        struct dynamic_type< cctypes::fillType > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::fillType > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< cctypes::ccTestControl > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::ccTestControl > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< cctypes::ccTestReport > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::ccTestReport > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // cc_str_test_types_1867997756_hpp

