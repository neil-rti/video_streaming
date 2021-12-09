

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from cctypes.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#ifndef cctypesPlugin_751230169_h
#define cctypesPlugin_751230169_h

#include "cctypes.hpp"

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
    payloadTypesEnumPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern unsigned int 
    payloadTypesEnumPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    payloadTypesEnumPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern void
    payloadTypesEnumPluginSupport_print_data(
        const payloadTypesEnum *sample, const char *desc, int indent_level);

    /* The type used to store keys for instances of type struct
    * AnotherSimple.
    *
    * By default, this type is struct ccBulk
    * itself. However, if for some reason this choice is not practical for your
    * system (e.g. if sizeof(struct ccBulk)
    * is very large), you may redefine this typedef in terms of another type of
    * your choosing. HOWEVER, if you define the KeyHolder type to be something
    * other than struct AnotherSimple, the
    * following restriction applies: the key of struct
    * ccBulk must consist of a
    * single field of your redefined KeyHolder type and that field must be the
    * first field in struct ccBulk.
    */
    typedef  class ccBulk ccBulkKeyHolder;

    #define ccBulkPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ccBulkPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ccBulkPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ccBulkPlugin_get_key PRESTypePluginDefaultEndpointData_getKey 
    #define ccBulkPlugin_return_key PRESTypePluginDefaultEndpointData_returnKey

    #define ccBulkPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ccBulkPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ccBulk*
    ccBulkPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ccBulk*
    ccBulkPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ccBulk*
    ccBulkPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ccBulkPluginSupport_copy_data(
        ccBulk *out,
        const ccBulk *in);

    NDDSUSERDllExport extern void 
    ccBulkPluginSupport_destroy_data_w_params(
        ccBulk *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ccBulkPluginSupport_destroy_data_ex(
        ccBulk *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ccBulkPluginSupport_destroy_data(
        ccBulk *sample);

    NDDSUSERDllExport extern void 
    ccBulkPluginSupport_print_data(
        const ccBulk *sample,
        const char *desc,
        unsigned int indent);

    NDDSUSERDllExport extern ccBulk*
    ccBulkPluginSupport_create_key_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ccBulk*
    ccBulkPluginSupport_create_key(void);

    NDDSUSERDllExport extern void 
    ccBulkPluginSupport_destroy_key_ex(
        ccBulkKeyHolder *key,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ccBulkPluginSupport_destroy_key(
        ccBulkKeyHolder *key);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ccBulkPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ccBulkPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ccBulkPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ccBulkPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ccBulkPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccBulk *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ccBulkPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccBulk *out,
        const ccBulk *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ccBulkPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccBulk *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ccBulkPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ccBulk **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ccBulkPlugin_deserialize_from_cdr_buffer(
        ccBulk *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ccBulkPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ccBulkPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ccBulkPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ccBulkPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ccBulkPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccBulk ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool 
    ccBulkPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ccBulkKeyHolder *key, 
        const ccBulk *instance);

    NDDSUSERDllExport extern RTIBool 
    ccBulkPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ccBulk *instance, 
        const ccBulkKeyHolder *key);

    NDDSUSERDllExport extern RTIBool 
    ccBulkPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos); 

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ccBulkPlugin_new(void);

    NDDSUSERDllExport extern void
    ccBulkPlugin_delete(struct PRESTypePlugin *);

    #define ccPerfPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ccPerfPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ccPerfPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

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

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ccPerfPlugin_new(void);

    NDDSUSERDllExport extern void
    ccPerfPlugin_delete(struct PRESTypePlugin *);

    #define ccControlPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample

    #define ccControlPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
    #define ccControlPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer

    #define ccControlPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
    #define ccControlPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

    /* --------------------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------------------- */

    NDDSUSERDllExport extern ccControl*
    ccControlPluginSupport_create_data_w_params(
        const struct DDS_TypeAllocationParams_t * alloc_params);

    NDDSUSERDllExport extern ccControl*
    ccControlPluginSupport_create_data_ex(RTIBool allocate_pointers);

    NDDSUSERDllExport extern ccControl*
    ccControlPluginSupport_create_data(void);

    NDDSUSERDllExport extern RTIBool 
    ccControlPluginSupport_copy_data(
        ccControl *out,
        const ccControl *in);

    NDDSUSERDllExport extern void 
    ccControlPluginSupport_destroy_data_w_params(
        ccControl *sample,
        const struct DDS_TypeDeallocationParams_t * dealloc_params);

    NDDSUSERDllExport extern void 
    ccControlPluginSupport_destroy_data_ex(
        ccControl *sample,RTIBool deallocate_pointers);

    NDDSUSERDllExport extern void 
    ccControlPluginSupport_destroy_data(
        ccControl *sample);

    NDDSUSERDllExport extern void 
    ccControlPluginSupport_print_data(
        const ccControl *sample,
        const char *desc,
        unsigned int indent);

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    NDDSUSERDllExport extern PRESTypePluginParticipantData 
    ccControlPlugin_on_participant_attached(
        void *registration_data, 
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration, 
        void *container_plugin_context,
        RTICdrTypeCode *typeCode);

    NDDSUSERDllExport extern void 
    ccControlPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data);

    NDDSUSERDllExport extern PRESTypePluginEndpointData 
    ccControlPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *container_plugin_context);

    NDDSUSERDllExport extern void 
    ccControlPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data);

    NDDSUSERDllExport extern void    
    ccControlPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccControl *sample,
        void *handle);    

    NDDSUSERDllExport extern RTIBool 
    ccControlPlugin_copy_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccControl *out,
        const ccControl *in);

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    NDDSUSERDllExport extern RTIBool
    ccControlPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccControl *sample,
        ::dds::core::policy::DataRepresentationId representation
        = ::dds::core::policy::DataRepresentation::xcdr()); 

    NDDSUSERDllExport extern RTIBool 
    ccControlPlugin_deserialize(
        PRESTypePluginEndpointData endpoint_data,
        ccControl **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_sample, 
        void *endpoint_plugin_qos);

    NDDSUSERDllExport extern RTIBool
    ccControlPlugin_deserialize_from_cdr_buffer(
        ccControl *sample,
        const char * buffer,
        unsigned int length);    

    NDDSUSERDllExport extern unsigned int 
    ccControlPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */
    NDDSUSERDllExport extern PRESTypePluginKeyKind 
    ccControlPlugin_get_key_kind(void);

    NDDSUSERDllExport extern unsigned int 
    ccControlPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern unsigned int 
    ccControlPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    NDDSUSERDllExport extern RTIBool 
    ccControlPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccControl ** sample,
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos);

    /* Plugin Functions */
    NDDSUSERDllExport extern struct PRESTypePlugin*
    ccControlPlugin_new(void);

    NDDSUSERDllExport extern void
    ccControlPlugin_delete(struct PRESTypePlugin *);

} /* namespace cctypes  */

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* cctypesPlugin_751230169_h */

