

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from cc_str_test_types.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef cc_str_test_typesPlugin_1867997756_h
#define cc_str_test_typesPlugin_1867997756_h

#include "cc_str_test_types.hpp"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace cctypes {

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    commandModePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    commandModePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    commandModePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    commandModePluginSupport_print_data(
        const commandMode *sample, const char *desc, int indent_level);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ccPerf
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ccPerf)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ccPerf must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ccPerf.
    */
    typedef  class ccPerf ccPerfKeyHolder;

    #define ccPerfPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ccPerfPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ccPerfPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ccPerfPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ccPerfPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ccPerfPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ccPerfPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ccPerf*
    ccPerfPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ccPerf*
    ccPerfPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ccPerf*
    ccPerfPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ccPerfPluginSupport_copy_data(
        ccPerf *out,
        const ccPerf *in);

    NDDSUSERDllExport extern void 
    ccPerfPluginSupport_destroy_data_w_params(
        ccPerf *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ccPerfPluginSupport_destroy_data_ex(
        ccPerf *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ccPerfPluginSupport_destroy_data(
        ccPerf *sample);

    NDDSUSERDllExport extern void 
    ccPerfPluginSupport_print_data(
        const ccPerf *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ccPerf*
    ccPerfPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ccPerf*
    ccPerfPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ccPerfPluginSupport_destroy_key_ex(
        ccPerfKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ccPerfPluginSupport_destroy_key(
        ccPerfKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ccPerfPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ccPerfPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ccPerfPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ccPerfPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ccPerfPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ccPerfPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf *out,
        const ccPerf *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ccPerfPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccPerf *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ccPerfPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ccPerfPlugin_deserialize_from_cdr_buffer(
        ccPerf *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ccPerfPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ccPerfPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ccPerfPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ccPerfPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ccPerfPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ccPerfPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ccPerfKeyHolder *key, 
        const ccPerf *instance);

    NDDSUSERDllExport extern RTIBool 
    ccPerfPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf *instance, 
        const ccPerfKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ccPerfPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ccPerfPlugin_new(void);

    NDDSUSERDllExport extern void
    ccPerfPlugin_delete(struct PRESTypePlugin *);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    fillTypePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    fillTypePlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    fillTypePlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    fillTypePluginSupport_print_data(
        const fillType *sample, const char *desc, int indent_level);

    #define ccTestControlPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ccTestControlPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ccTestControlPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ccTestControlPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ccTestControlPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ccTestControl*
    ccTestControlPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ccTestControl*
    ccTestControlPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ccTestControl*
    ccTestControlPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ccTestControlPluginSupport_copy_data(
        ccTestControl *out,
        const ccTestControl *in);

    NDDSUSERDllExport extern void 
    ccTestControlPluginSupport_destroy_data_w_params(
        ccTestControl *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ccTestControlPluginSupport_destroy_data_ex(
        ccTestControl *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ccTestControlPluginSupport_destroy_data(
        ccTestControl *sample);

    NDDSUSERDllExport extern void 
    ccTestControlPluginSupport_print_data(
        const ccTestControl *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ccTestControlPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ccTestControlPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ccTestControlPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ccTestControlPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ccTestControlPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccTestControl *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ccTestControlPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccTestControl *out,
        const ccTestControl *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ccTestControlPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccTestControl *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ccTestControlPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ccTestControl **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ccTestControlPlugin_deserialize_from_cdr_buffer(
        ccTestControl *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ccTestControlPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ccTestControlPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ccTestControlPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ccTestControlPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ccTestControlPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccTestControl ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ccTestControlPlugin_new(void);

    NDDSUSERDllExport extern void
    ccTestControlPlugin_delete(struct PRESTypePlugin *);

    #define ccTestReportPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ccTestReportPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ccTestReportPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ccTestReportPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ccTestReportPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ccTestReport*
    ccTestReportPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ccTestReport*
    ccTestReportPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ccTestReport*
    ccTestReportPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ccTestReportPluginSupport_copy_data(
        ccTestReport *out,
        const ccTestReport *in);

    NDDSUSERDllExport extern void 
    ccTestReportPluginSupport_destroy_data_w_params(
        ccTestReport *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ccTestReportPluginSupport_destroy_data_ex(
        ccTestReport *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ccTestReportPluginSupport_destroy_data(
        ccTestReport *sample);

    NDDSUSERDllExport extern void 
    ccTestReportPluginSupport_print_data(
        const ccTestReport *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ccTestReportPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ccTestReportPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ccTestReportPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ccTestReportPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ccTestReportPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccTestReport *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ccTestReportPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccTestReport *out,
        const ccTestReport *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ccTestReportPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccTestReport *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ccTestReportPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ccTestReport **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ccTestReportPlugin_deserialize_from_cdr_buffer(
        ccTestReport *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ccTestReportPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ccTestReportPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ccTestReportPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ccTestReportPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ccTestReportPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccTestReport ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ccTestReportPlugin_new(void);

    NDDSUSERDllExport extern void
    ccTestReportPlugin_delete(struct PRESTypePlugin *);

} /* namespace cctypes  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* cc_str_test_typesPlugin_1867997756_h */

