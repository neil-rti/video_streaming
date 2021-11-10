

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from cctypes.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef cctypes_751230475_hpp
#define cctypes_751230475_hpp

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
    enum class payloadTypesEnum {
        NO_PAYLOAD = 0, 
        TOP_INFO_EXCHANGE, 
        STREAM_FFMPEG_0, 
        STREAM_FFMPEG_1, 
        STREAM_GSTREAMER_0, 
        STREAM_GSTREAMER_1, 
        STREAM_OPENCV_0, 
        STREAM_OPENCV_1, 
        FILE_TRANSFER_REQUEST, 
        FILE_TRANSFER_ACCEPT, 
        FILE_TRANSFER_PAYLOAD, 
        FILE_TRANSFER_VERIFY, 
        TEXT_CHAT_0, 
        TEST_PATTERN_0, 
        TRAFFIC_GEN_COMPRESSIBLE, 
        TRAFFIC_GEN_NONCOMPRESSIBLE, 
        IMAGE_FILE, 
        MAX_PAYLOAD_ENUM
    };

    NDDSUSERDllExport std::ostream& operator << (std::ostream& o,const payloadTypesEnum& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< uint8_t >;
    template class NDDSUSERDllExport std::vector< uint8_t >;
    #endif
    class NDDSUSERDllExport ccBulk {
      public:
        ccBulk();

        ccBulk(
            const cctypes::payloadTypesEnum& content_type,
            const std::string& pub_id,
            uint64_t tstamp_first_frame,
            const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ccBulk (ccBulk&&) = default;
        ccBulk& operator=(ccBulk&&) = default;
        ccBulk& operator=(const ccBulk&) = default;
        ccBulk(const ccBulk&) = default;
        #else
        ccBulk(ccBulk&& other_) OMG_NOEXCEPT;  
        ccBulk& operator=(ccBulk&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        cctypes::payloadTypesEnum& content_type() OMG_NOEXCEPT {
            return m_content_type_;
        }

        const cctypes::payloadTypesEnum& content_type() const OMG_NOEXCEPT {
            return m_content_type_;
        }

        void content_type(const cctypes::payloadTypesEnum& value) {
            m_content_type_ = value;
        }

        void content_type(cctypes::payloadTypesEnum&& value) {
            m_content_type_ = std::move(value);
        }
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
        uint64_t& tstamp_first_frame() OMG_NOEXCEPT {
            return m_tstamp_first_frame_;
        }

        const uint64_t& tstamp_first_frame() const OMG_NOEXCEPT {
            return m_tstamp_first_frame_;
        }

        void tstamp_first_frame(uint64_t value) {
            m_tstamp_first_frame_ = value;
        }

        ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data() OMG_NOEXCEPT {
            return m_data_;
        }

        const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& data() const OMG_NOEXCEPT {
            return m_data_;
        }

        void data(const ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >& value) {
            m_data_ = value;
        }

        void data(::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) >&& value) {
            m_data_ = std::move(value);
        }

        bool operator == (const ccBulk& other_) const;
        bool operator != (const ccBulk& other_) const;

        void swap(ccBulk& other_) OMG_NOEXCEPT ;

      private:

        cctypes::payloadTypesEnum m_content_type_;
        std::string m_pub_id_;
        uint64_t m_tstamp_first_frame_;
        ::rti::core::bounded_sequence< uint8_t, (cctypes::MAX_SEQUENCE_LEN) > m_data_;

    };

    inline void swap(ccBulk& a, ccBulk& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ccBulk& sample);

    #if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
    // On Windows, dll-export template instantiations of standard types used by
    // other dll-exported types
    template class NDDSUSERDllExport std::allocator< int64_t >;
    template class NDDSUSERDllExport std::vector< int64_t >;
    template class NDDSUSERDllExport std::allocator< uint64_t >;
    template class NDDSUSERDllExport std::vector< uint64_t >;
    #endif
    class NDDSUSERDllExport ccPerf {
      public:
        ccPerf();

        ccPerf(
            uint64_t tStart,
            uint64_t tDuration,
            uint64_t data_count,
            uint32_t frames_per_sample,
            uint32_t samples_count,
            uint32_t samples_dropped,
            const ::rti::core::bounded_sequence< int64_t, 4L >& latency_min,
            const ::rti::core::bounded_sequence< int64_t, 4L >& latency_mean,
            const ::rti::core::bounded_sequence< int64_t, 4L >& latency_max,
            const ::rti::core::bounded_sequence< uint64_t, 4L >& latency_stddev);

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

        uint64_t& tStart() OMG_NOEXCEPT {
            return m_tStart_;
        }

        const uint64_t& tStart() const OMG_NOEXCEPT {
            return m_tStart_;
        }

        void tStart(uint64_t value) {
            m_tStart_ = value;
        }

        uint64_t& tDuration() OMG_NOEXCEPT {
            return m_tDuration_;
        }

        const uint64_t& tDuration() const OMG_NOEXCEPT {
            return m_tDuration_;
        }

        void tDuration(uint64_t value) {
            m_tDuration_ = value;
        }

        uint64_t& data_count() OMG_NOEXCEPT {
            return m_data_count_;
        }

        const uint64_t& data_count() const OMG_NOEXCEPT {
            return m_data_count_;
        }

        void data_count(uint64_t value) {
            m_data_count_ = value;
        }

        uint32_t& frames_per_sample() OMG_NOEXCEPT {
            return m_frames_per_sample_;
        }

        const uint32_t& frames_per_sample() const OMG_NOEXCEPT {
            return m_frames_per_sample_;
        }

        void frames_per_sample(uint32_t value) {
            m_frames_per_sample_ = value;
        }

        uint32_t& samples_count() OMG_NOEXCEPT {
            return m_samples_count_;
        }

        const uint32_t& samples_count() const OMG_NOEXCEPT {
            return m_samples_count_;
        }

        void samples_count(uint32_t value) {
            m_samples_count_ = value;
        }

        uint32_t& samples_dropped() OMG_NOEXCEPT {
            return m_samples_dropped_;
        }

        const uint32_t& samples_dropped() const OMG_NOEXCEPT {
            return m_samples_dropped_;
        }

        void samples_dropped(uint32_t value) {
            m_samples_dropped_ = value;
        }

        ::rti::core::bounded_sequence< int64_t, 4L >& latency_min() OMG_NOEXCEPT {
            return m_latency_min_;
        }

        const ::rti::core::bounded_sequence< int64_t, 4L >& latency_min() const OMG_NOEXCEPT {
            return m_latency_min_;
        }

        void latency_min(const ::rti::core::bounded_sequence< int64_t, 4L >& value) {
            m_latency_min_ = value;
        }

        void latency_min(::rti::core::bounded_sequence< int64_t, 4L >&& value) {
            m_latency_min_ = std::move(value);
        }
        ::rti::core::bounded_sequence< int64_t, 4L >& latency_mean() OMG_NOEXCEPT {
            return m_latency_mean_;
        }

        const ::rti::core::bounded_sequence< int64_t, 4L >& latency_mean() const OMG_NOEXCEPT {
            return m_latency_mean_;
        }

        void latency_mean(const ::rti::core::bounded_sequence< int64_t, 4L >& value) {
            m_latency_mean_ = value;
        }

        void latency_mean(::rti::core::bounded_sequence< int64_t, 4L >&& value) {
            m_latency_mean_ = std::move(value);
        }
        ::rti::core::bounded_sequence< int64_t, 4L >& latency_max() OMG_NOEXCEPT {
            return m_latency_max_;
        }

        const ::rti::core::bounded_sequence< int64_t, 4L >& latency_max() const OMG_NOEXCEPT {
            return m_latency_max_;
        }

        void latency_max(const ::rti::core::bounded_sequence< int64_t, 4L >& value) {
            m_latency_max_ = value;
        }

        void latency_max(::rti::core::bounded_sequence< int64_t, 4L >&& value) {
            m_latency_max_ = std::move(value);
        }
        ::rti::core::bounded_sequence< uint64_t, 4L >& latency_stddev() OMG_NOEXCEPT {
            return m_latency_stddev_;
        }

        const ::rti::core::bounded_sequence< uint64_t, 4L >& latency_stddev() const OMG_NOEXCEPT {
            return m_latency_stddev_;
        }

        void latency_stddev(const ::rti::core::bounded_sequence< uint64_t, 4L >& value) {
            m_latency_stddev_ = value;
        }

        void latency_stddev(::rti::core::bounded_sequence< uint64_t, 4L >&& value) {
            m_latency_stddev_ = std::move(value);
        }

        bool operator == (const ccPerf& other_) const;
        bool operator != (const ccPerf& other_) const;

        void swap(ccPerf& other_) OMG_NOEXCEPT ;

      private:

        uint64_t m_tStart_;
        uint64_t m_tDuration_;
        uint64_t m_data_count_;
        uint32_t m_frames_per_sample_;
        uint32_t m_samples_count_;
        uint32_t m_samples_dropped_;
        ::rti::core::bounded_sequence< int64_t, 4L > m_latency_min_;
        ::rti::core::bounded_sequence< int64_t, 4L > m_latency_mean_;
        ::rti::core::bounded_sequence< int64_t, 4L > m_latency_max_;
        ::rti::core::bounded_sequence< uint64_t, 4L > m_latency_stddev_;

    };

    inline void swap(ccPerf& a, ccPerf& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ccPerf& sample);

    class NDDSUSERDllExport ccControl {
      public:
        ccControl();

        ccControl(
            const cctypes::payloadTypesEnum& content_type,
            uint32_t frames_per_sample);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        ccControl (ccControl&&) = default;
        ccControl& operator=(ccControl&&) = default;
        ccControl& operator=(const ccControl&) = default;
        ccControl(const ccControl&) = default;
        #else
        ccControl(ccControl&& other_) OMG_NOEXCEPT;  
        ccControl& operator=(ccControl&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        cctypes::payloadTypesEnum& content_type() OMG_NOEXCEPT {
            return m_content_type_;
        }

        const cctypes::payloadTypesEnum& content_type() const OMG_NOEXCEPT {
            return m_content_type_;
        }

        void content_type(const cctypes::payloadTypesEnum& value) {
            m_content_type_ = value;
        }

        void content_type(cctypes::payloadTypesEnum&& value) {
            m_content_type_ = std::move(value);
        }
        uint32_t& frames_per_sample() OMG_NOEXCEPT {
            return m_frames_per_sample_;
        }

        const uint32_t& frames_per_sample() const OMG_NOEXCEPT {
            return m_frames_per_sample_;
        }

        void frames_per_sample(uint32_t value) {
            m_frames_per_sample_ = value;
        }

        bool operator == (const ccControl& other_) const;
        bool operator != (const ccControl& other_) const;

        void swap(ccControl& other_) OMG_NOEXCEPT ;

      private:

        cctypes::payloadTypesEnum m_content_type_;
        uint32_t m_frames_per_sample_;

    };

    inline void swap(ccControl& a, ccControl& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o, const ccControl& sample);

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
        struct topic_type_name< cctypes::ccBulk > {
            NDDSUSERDllExport static std::string value() {
                return "cctypes::ccBulk";
            }
        };

        template<>
        struct is_topic_type< cctypes::ccBulk > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< cctypes::ccBulk > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const cctypes::ccBulk& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(cctypes::ccBulk& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(cctypes::ccBulk& sample);

            NDDSUSERDllExport 
            static void allocate_sample(cctypes::ccBulk& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

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
        struct topic_type_name< cctypes::ccControl > {
            NDDSUSERDllExport static std::string value() {
                return "cctypes::ccControl";
            }
        };

        template<>
        struct is_topic_type< cctypes::ccControl > : public ::dds::core::true_type {};

        template<>
        struct topic_type_support< cctypes::ccControl > {
            NDDSUSERDllExport 
            static void register_type(
                ::dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport 
            static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, 
                const cctypes::ccControl& sample,
                ::dds::core::policy::DataRepresentationId representation 
                = ::dds::core::policy::DataRepresentation::auto_id());

            NDDSUSERDllExport 
            static void from_cdr_buffer(cctypes::ccControl& sample, const std::vector<char>& buffer);
            NDDSUSERDllExport 
            static void reset_sample(cctypes::ccControl& sample);

            NDDSUSERDllExport 
            static void allocate_sample(cctypes::ccControl& sample, int, int);

            static const ::rti::topic::TypePluginKind::type type_plugin_kind = 
            ::rti::topic::TypePluginKind::STL;
        };

    }
}

namespace rti { 
    namespace topic {

        #ifndef NDDS_STANDALONE_TYPE
        template <>
        struct default_enumerator<cctypes::payloadTypesEnum>
        {
            static const cctypes::payloadTypesEnum value;
        };
        template<>
        struct dynamic_type< cctypes::payloadTypesEnum > {
            typedef ::dds::core::xtypes::EnumType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::EnumType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::payloadTypesEnum > {
            static const ::dds::core::xtypes::ExtensibilityKind::type kind =
            ::dds::core::xtypes::ExtensibilityKind::EXTENSIBLE;                
        };

        #ifndef NDDS_STANDALONE_TYPE
        template<>
        struct dynamic_type< cctypes::ccBulk > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::ccBulk > {
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
        template<>
        struct dynamic_type< cctypes::ccControl > {
            typedef ::dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const ::dds::core::xtypes::StructType& get();
        };
        #endif

        template <>
        struct extensibility< cctypes::ccControl > {
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

#endif // cctypes_751230475_hpp

