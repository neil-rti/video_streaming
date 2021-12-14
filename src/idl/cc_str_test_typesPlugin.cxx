

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from cc_str_test_types.idl
using RTI Code Generator (rtiddsgen) version 3.1.0.
The rtiddsgen tool is part of the RTI Connext DDS distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the Code Generator User's Manual.
*/

#include <string.h>

#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef osapi_type_h
#include "osapi/osapi_type.h"
#endif
#ifndef osapi_heap_h
#include "osapi/osapi_heap.h"
#endif

#ifndef osapi_utility_h
#include "osapi/osapi_utility.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif

#ifndef cdr_type_object_h
#include "cdr/cdr_typeObject.h"
#endif

#ifndef cdr_encapsulation_h
#include "cdr/cdr_encapsulation.h"
#endif

#ifndef cdr_stream_h
#include "cdr/cdr_stream.h"
#endif

#ifndef cdr_log_h
#include "cdr/cdr_log.h"
#endif

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#include "dds_c/dds_c_typecode_impl.h"

#include "rti/topic/cdr/Serialization.hpp"

#define RTI_CDR_CURRENT_SUBMODULE RTI_CDR_SUBMODULE_MASK_STREAM

#include "cc_str_test_typesPlugin.hpp"

namespace cctypes {

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    unsigned int 
    commandModePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int initial_alignment = current_alignment;

            current_alignment += PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
                endpoint_data,
                NULL,
                include_encapsulation,
                encapsulation_id, current_alignment);

            return current_alignment - initial_alignment;
        } catch (...) {
            return 0;
        }    
    }

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    void commandModePluginSupport_print_data(
        const commandMode *sample,
        const char *description, int indent_level)
    {
        if (description != NULL) {
            RTICdrType_printIndent(indent_level);
            RTILogParamString_printPlain("%s:\n", description);
        }

        if (sample == NULL) {
            RTICdrType_printIndent(indent_level+1);
            RTILogParamString_printPlain("NULL\n");
            return;
        }

        RTICdrType_printEnum((RTICdrEnum *)sample, "commandMode", indent_level + 1);
    }

    /* ------------------------------------------------------------------------
    * Plug-in Installation Methods
    * ------------------------------------------------------------------------ */

    /* ----------------------------------------------------------------------------
    *  Type ccPerf
    * -------------------------------------------------------------------------- */

    /* -----------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------- */

    ccPerf *
    ccPerfPluginSupport_create_data(void)
    {
        try {
            ccPerf *sample = new ccPerf();
            ::rti::topic::allocate_sample(*sample);
            return sample;
        } catch (...) {
            return NULL;
        }
    }

    void 
    ccPerfPluginSupport_destroy_data(
        ccPerf *sample) 
    {
        delete sample;
    }

    RTIBool 
    ccPerfPluginSupport_copy_data(
        ccPerf *dst,
        const ccPerf *src)
    {
        try {
            *dst = *src;
        } catch (...) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }

    ccPerf *
    ccPerfPluginSupport_create_key(void)
    {
        return ccPerfPluginSupport_create_data();
    }

    void 
    ccPerfPluginSupport_destroy_key(
        ccPerfKeyHolder *key) 
    {
        ccPerfPluginSupport_destroy_data(key);
    }

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    PRESTypePluginParticipantData 
    ccPerfPlugin_on_participant_attached(
        void *registration_data,
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration,
        void *container_plugin_context,
        RTICdrTypeCode *type_code)
    {
        struct RTIXCdrInterpreterPrograms *programs = NULL;
        struct PRESTypePluginDefaultParticipantData *pd = NULL;
        struct RTIXCdrInterpreterProgramsGenProperty programProperty =
        RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
        if (registration_data) {} /* To avoid warnings */
        if (participant_info) {} /* To avoid warnings */
        if (top_level_registration) {} /* To avoid warnings */
        if (container_plugin_context) {} /* To avoid warnings */
        if (type_code) {} /* To avoid warnings */
        pd = (struct PRESTypePluginDefaultParticipantData *)
        PRESTypePluginDefaultParticipantData_new(participant_info);

        programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
        programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
        programProperty.resolveAlias = RTI_XCDR_TRUE;
        programProperty.inlineStruct = RTI_XCDR_TRUE;
        programProperty.optimizeEnum = RTI_XCDR_TRUE;

        programProperty.externalReferenceSize = 
        (RTIXCdrUnsignedShort) sizeof(::dds::core::external<char>);
        programProperty.getExternalRefPointerFcn = 
        ::rti::topic::interpreter::get_external_value_pointer;

        programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
            DDS_TypeCodeFactory_get_instance(),
            (DDS_TypeCode *) (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccPerf >::get().native()
            ,
            &programProperty,
            RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);

        if (programs == NULL) {
            PRESTypePluginDefaultParticipantData_delete(
                (PRESTypePluginParticipantData)pd);
            return NULL;
        }

        pd->programs = programs;
        return (PRESTypePluginParticipantData)pd;
    }

    void 
    ccPerfPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data)
    {
        if (participant_data != NULL) {
            struct PRESTypePluginDefaultParticipantData *pd = 
            (struct PRESTypePluginDefaultParticipantData *)participant_data;

            if (pd->programs != NULL) {
                DDS_TypeCodeFactory_remove_programs_from_global_list(
                    DDS_TypeCodeFactory_get_instance(),
                    pd->programs);
                pd->programs = NULL;
            }
            PRESTypePluginDefaultParticipantData_delete(participant_data);
        }
    }

    PRESTypePluginEndpointData
    ccPerfPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *containerPluginContext)
    {
        try {
            PRESTypePluginEndpointData epd = NULL;
            unsigned int serializedSampleMaxSize = 0;

            unsigned int serializedKeyMaxSize = 0;
            unsigned int serializedKeyMaxSizeV2 = 0;

            if (top_level_registration) {} /* To avoid warnings */
            if (containerPluginContext) {} /* To avoid warnings */

            if (participant_data == NULL) {
                return NULL;
            } 

            epd = PRESTypePluginDefaultEndpointData_new(
                participant_data,
                endpoint_info,
                (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                ccPerfPluginSupport_create_data,
                (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                ccPerfPluginSupport_destroy_data,
                (PRESTypePluginDefaultEndpointDataCreateKeyFunction)
                cctypes::ccPerfPluginSupport_create_key ,                (PRESTypePluginDefaultEndpointDataDestroyKeyFunction)
                cctypes::ccPerfPluginSupport_destroy_key);

            if (epd == NULL) {
                return NULL;
            } 

            serializedKeyMaxSize =  cctypes::ccPerfPlugin_get_serialized_key_max_size(
                epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
            serializedKeyMaxSizeV2 = ccPerfPlugin_get_serialized_key_max_size_for_keyhash(
                epd,
                RTI_CDR_ENCAPSULATION_ID_CDR2_BE,
                0);

            if(!PRESTypePluginDefaultEndpointData_createMD5StreamWithInfo(
                epd,
                endpoint_info,
                serializedKeyMaxSize,
                serializedKeyMaxSizeV2))  
            {
                PRESTypePluginDefaultEndpointData_delete(epd);
                return NULL;
            }

            if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
                serializedSampleMaxSize = cctypes::ccPerfPlugin_get_serialized_sample_max_size(
                    epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
                PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

                if (PRESTypePluginDefaultEndpointData_createWriterPool(
                    epd,
                    endpoint_info,
                    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                    cctypes::ccPerfPlugin_get_serialized_sample_max_size, epd,
                    (PRESTypePluginGetSerializedSampleSizeFunction)
                    PRESTypePlugin_interpretedGetSerializedSampleSize,
                    epd) == RTI_FALSE) {
                    PRESTypePluginDefaultEndpointData_delete(epd);
                    return NULL;
                }
            }

            return epd;
        } catch (...) {
            return NULL;
        }
    }

    void 
    ccPerfPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data)
    {  
        PRESTypePluginDefaultEndpointData_delete(endpoint_data);
    }

    void    
    ccPerfPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf *sample,
        void *handle)
    {
        try {
            ::rti::topic::reset_sample(*sample);
        } catch(const std::exception& ex) {
            RTICdrLog_logWithFunctionName(
                RTI_LOG_BIT_EXCEPTION,
                "ccPerfPlugin_return_sample",
                &RTI_LOG_ANY_FAILURE_ss,
                "exception: ",
                ex.what());
        }

        PRESTypePluginDefaultEndpointData_returnSample(
            endpoint_data, sample, handle);
    }

    RTIBool 
    ccPerfPlugin_copy_sample(
        PRESTypePluginEndpointData,
        ccPerf *dst,
        const ccPerf *src)
    {
        return cctypes::ccPerfPluginSupport_copy_data(dst,src);
    }

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */
    unsigned int 
    ccPerfPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    RTIBool
    ccPerfPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccPerf *sample,
        ::dds::core::policy::DataRepresentationId representation)
    {
        using namespace ::dds::core::policy;

        try{
            RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
            struct RTICdrStream stream;
            struct PRESTypePluginDefaultEndpointData epd;
            RTIBool result;
            struct PRESTypePluginDefaultParticipantData pd;
            struct RTIXCdrTypePluginProgramContext defaultProgramContext =
            RTIXCdrTypePluginProgramContext_INTIALIZER;
            struct PRESTypePlugin plugin = PRES_TYPEPLUGIN_DEFAULT;

            if (length == NULL) {
                return RTI_FALSE;
            }

            RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
            epd.programContext = defaultProgramContext;
            epd._participantData = &pd;
            epd.typePlugin = &plugin;
            epd.programContext.endpointPluginData = &epd;
            plugin.typeCode = (struct RTICdrTypeCode *)
            (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccPerf >::get().native()
            ;
            pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
            ccPerf, 
            true, true, true>();

            encapsulationId = DDS_TypeCode_get_native_encapsulation(
                (DDS_TypeCode *) plugin.typeCode,
                representation);

            if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
                return RTI_FALSE;
            }

            epd._maxSizeSerializedSample =
            ccPerfPlugin_get_serialized_sample_max_size(
                (PRESTypePluginEndpointData)&epd, 
                RTI_TRUE, 
                encapsulationId,
                0);

            if (buffer == NULL) {
                *length = 
                PRESTypePlugin_interpretedGetSerializedSampleSize(
                    (PRESTypePluginEndpointData)&epd,
                    RTI_TRUE,
                    encapsulationId,
                    0,
                    sample);

                if (*length == 0) {
                    return RTI_FALSE;
                }

                return RTI_TRUE;
            }    

            RTICdrStream_init(&stream);
            RTICdrStream_set(&stream, (char *)buffer, *length);

            result = PRESTypePlugin_interpretedSerialize(
                (PRESTypePluginEndpointData)&epd, 
                sample, 
                &stream, 
                RTI_TRUE, 
                encapsulationId,
                RTI_TRUE, 
                NULL);  

            *length = RTICdrStream_getCurrentPositionOffset(&stream);
            return result;     
        } catch (...) {
            return RTI_FALSE;
        }
    }

    RTIBool
    ccPerfPlugin_deserialize_from_cdr_buffer(
        ccPerf *sample,
        const char * buffer,
        unsigned int length)
    {
        struct RTICdrStream stream;
        struct PRESTypePluginDefaultParticipantData pd;
        struct RTIXCdrTypePluginProgramContext defaultProgramContext =
        RTIXCdrTypePluginProgramContext_INTIALIZER;
        struct PRESTypePlugin plugin;
        struct PRESTypePluginDefaultEndpointData epd;

        RTICdrStream_init(&stream);
        RTICdrStream_set(&stream, (char *)buffer, length);

        epd.programContext = defaultProgramContext;
        epd._participantData = &pd;
        epd.typePlugin = &plugin;
        epd.programContext.endpointPluginData = &epd;
        plugin.typeCode = (struct RTICdrTypeCode *)
        (struct RTICdrTypeCode *)(RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccPerf >::get().native()
        ;
        pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
        ccPerf, 
        true, true, true>();

        epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
        epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

        ::rti::topic::reset_sample(*sample);
        return PRESTypePlugin_interpretedDeserialize( 
            (PRESTypePluginEndpointData)&epd,
            sample,
            &stream, 
            RTI_TRUE, 
            RTI_TRUE, 
            NULL);
    }

    unsigned int 
    ccPerfPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int size;
            RTIBool overflow = RTI_FALSE;

            size = PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
                endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

            if (overflow) {
                size = RTI_CDR_MAX_SERIALIZED_SIZE;
            }

            return size;
        } catch (...) {
            return 0;
        }    
    }

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    PRESTypePluginKeyKind 
    ccPerfPlugin_get_key_kind(void)
    {
        return PRES_TYPEPLUGIN_USER_KEY;
    }

    RTIBool ccPerfPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos)
    {
        try {
            RTIBool result;
            if (drop_sample) {} /* To avoid warnings */
            stream->_xTypesState.unassignable = RTI_FALSE;
            result= PRESTypePlugin_interpretedDeserializeKey( 
                endpoint_data, (sample != NULL)?*sample:NULL, stream,
                deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
            if (result) {
                if (stream->_xTypesState.unassignable) {
                    result = RTI_FALSE;
                }
            }
            return result;    
        } catch (...) {
            return RTI_FALSE;
        }     
    }

    unsigned int
    ccPerfPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int size;
            RTIBool overflow = RTI_FALSE;

            size = PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
                endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
            if (overflow) {
                size = RTI_CDR_MAX_SERIALIZED_SIZE;
            }

            return size;
        } catch (...) {
            return RTI_FALSE;
        }    
    }

    unsigned int
    ccPerfPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
            endpoint_data,
            &overflow,
            encapsulation_id,
            current_alignment);
        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    }

    RTIBool 
    ccPerfPlugin_instance_to_key(
        PRESTypePluginEndpointData endpoint_data,
        ccPerfKeyHolder *dst, 
        const ccPerf *src)
    {
        try {
            if (endpoint_data) {} /* To avoid warnings */   

            dst->pub_id() = src->pub_id();
            return RTI_TRUE;
        } catch (...) {
            return RTI_FALSE;
        }    
    }

    RTIBool 
    ccPerfPlugin_key_to_instance(
        PRESTypePluginEndpointData endpoint_data,
        ccPerf *dst, const
        ccPerfKeyHolder *src)
    {
        try {
            if (endpoint_data) {} /* To avoid warnings */   
            dst->pub_id() = src->pub_id();
            return RTI_TRUE;
        } catch (...) {
            return RTI_FALSE;
        }    
    }

    RTIBool 
    ccPerfPlugin_serialized_sample_to_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        struct RTICdrStream *stream, 
        DDS_KeyHash_t *keyhash,
        RTIBool deserialize_encapsulation,
        void *endpoint_plugin_qos)
    {
        ccPerf * sample = NULL;
        sample = (ccPerf *)
        PRESTypePluginDefaultEndpointData_getTempSample(endpoint_data);
        if (sample == NULL) {
            return RTI_FALSE;
        }
        if (!PRESTypePlugin_interpretedSerializedSampleToKey(
            endpoint_data,
            sample,
            stream, 
            deserialize_encapsulation, 
            RTI_TRUE,
            endpoint_plugin_qos)) {
            return RTI_FALSE;
        }
        if (!PRESTypePlugin_interpretedInstanceToKeyHash(
            endpoint_data,
            keyhash,
            sample,
            RTICdrStream_getEncapsulationKind(stream))) {
            return RTI_FALSE;
        }
        return RTI_TRUE;   
    }

    /* ------------------------------------------------------------------------
    * Plug-in Installation Methods
    * ------------------------------------------------------------------------ */
    struct PRESTypePlugin *ccPerfPlugin_new(void) 
    { 
        struct PRESTypePlugin *plugin = NULL;
        const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

        RTIOsapiHeap_allocateStructure(
            &plugin, struct PRESTypePlugin);
        if (plugin == NULL) {
            return NULL;
        }

        plugin->version = PLUGIN_VERSION;

        /* set up parent's function pointers */
        plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        cctypes::ccPerfPlugin_on_participant_attached;
        plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        cctypes::ccPerfPlugin_on_participant_detached;
        plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        cctypes::ccPerfPlugin_on_endpoint_attached;
        plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        cctypes::ccPerfPlugin_on_endpoint_detached;

        plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        cctypes::ccPerfPlugin_copy_sample;
        plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        ccPerfPlugin_create_sample;
        plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        ccPerfPlugin_destroy_sample;

        plugin->serializeFnc = 
        (PRESTypePluginSerializeFunction) PRESTypePlugin_interpretedSerialize;
        plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction) PRESTypePlugin_interpretedDeserializeWithAlloc;
        plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        cctypes::ccPerfPlugin_get_serialized_sample_max_size;
        plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        PRESTypePlugin_interpretedGetSerializedSampleMinSize;
        plugin->getDeserializedSampleMaxSizeFnc = NULL; 
        plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        ccPerfPlugin_get_sample;
        plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        ccPerfPlugin_return_sample;
        plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        cctypes::ccPerfPlugin_get_key_kind;

        plugin->getSerializedKeyMaxSizeFnc =   
        (PRESTypePluginGetSerializedKeyMaxSizeFunction)
        cctypes::ccPerfPlugin_get_serialized_key_max_size;
        plugin->serializeKeyFnc =
        (PRESTypePluginSerializeKeyFunction)
        PRESTypePlugin_interpretedSerializeKey;
        plugin->deserializeKeyFnc =
        (PRESTypePluginDeserializeKeyFunction)
        cctypes::ccPerfPlugin_deserialize_key;
        plugin->deserializeKeySampleFnc =
        (PRESTypePluginDeserializeKeySampleFunction)
        PRESTypePlugin_interpretedDeserializeKey;

        plugin-> instanceToKeyHashFnc = 
        (PRESTypePluginInstanceToKeyHashFunction)
        PRESTypePlugin_interpretedInstanceToKeyHash;
        plugin->serializedSampleToKeyHashFnc = 
        (PRESTypePluginSerializedSampleToKeyHashFunction)
        cctypes::ccPerfPlugin_serialized_sample_to_keyhash;

        plugin->getKeyFnc =
        (PRESTypePluginGetKeyFunction)
        ccPerfPlugin_get_key;
        plugin->returnKeyFnc =
        (PRESTypePluginReturnKeyFunction)
        ccPerfPlugin_return_key;

        plugin->instanceToKeyFnc =
        (PRESTypePluginInstanceToKeyFunction)
        cctypes::ccPerfPlugin_instance_to_key;
        plugin->keyToInstanceFnc =
        (PRESTypePluginKeyToInstanceFunction)
        cctypes::ccPerfPlugin_key_to_instance;
        plugin->serializedKeyToKeyHashFnc = NULL; /* Not supported yet */
        #ifdef NDDS_STANDALONE_TYPE
        plugin->typeCode = NULL; 
        #else
        plugin->typeCode = (struct RTICdrTypeCode *) 
        &::rti::topic::dynamic_type< cctypes::ccPerf >::get().native();
        #endif
        plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

        /* Serialized buffer */
        plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        ccPerfPlugin_get_buffer;
        plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        ccPerfPlugin_return_buffer;
        plugin->getBufferWithParams = NULL;
        plugin->returnBufferWithParams = NULL;
        plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        PRESTypePlugin_interpretedGetSerializedSampleSize;

        plugin->getWriterLoanedSampleFnc = NULL; 
        plugin->returnWriterLoanedSampleFnc = NULL;
        plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
        plugin->validateWriterLoanedSampleFnc = NULL;
        plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

        static const char * TYPE_NAME = "cctypes::ccPerf";
        plugin->endpointTypeName = TYPE_NAME;
        plugin->isMetpType = RTI_FALSE;
        return plugin;
    }

    void
    ccPerfPlugin_delete(struct PRESTypePlugin *plugin)
    {
        RTIOsapiHeap_freeStructure(plugin);
    } 

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */

    unsigned int 
    fillTypePlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int initial_alignment = current_alignment;

            current_alignment += PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
                endpoint_data,
                NULL,
                include_encapsulation,
                encapsulation_id, current_alignment);

            return current_alignment - initial_alignment;
        } catch (...) {
            return 0;
        }    
    }

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    /* ----------------------------------------------------------------------------
    Support functions:
    * ---------------------------------------------------------------------------- */

    void fillTypePluginSupport_print_data(
        const fillType *sample,
        const char *description, int indent_level)
    {
        if (description != NULL) {
            RTICdrType_printIndent(indent_level);
            RTILogParamString_printPlain("%s:\n", description);
        }

        if (sample == NULL) {
            RTICdrType_printIndent(indent_level+1);
            RTILogParamString_printPlain("NULL\n");
            return;
        }

        RTICdrType_printEnum((RTICdrEnum *)sample, "fillType", indent_level + 1);
    }

    /* ------------------------------------------------------------------------
    * Plug-in Installation Methods
    * ------------------------------------------------------------------------ */

    /* ----------------------------------------------------------------------------
    *  Type ccTestControl
    * -------------------------------------------------------------------------- */

    /* -----------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------- */

    ccTestControl *
    ccTestControlPluginSupport_create_data(void)
    {
        try {
            ccTestControl *sample = new ccTestControl();
            ::rti::topic::allocate_sample(*sample);
            return sample;
        } catch (...) {
            return NULL;
        }
    }

    void 
    ccTestControlPluginSupport_destroy_data(
        ccTestControl *sample) 
    {
        delete sample;
    }

    RTIBool 
    ccTestControlPluginSupport_copy_data(
        ccTestControl *dst,
        const ccTestControl *src)
    {
        try {
            *dst = *src;
        } catch (...) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    PRESTypePluginParticipantData 
    ccTestControlPlugin_on_participant_attached(
        void *registration_data,
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration,
        void *container_plugin_context,
        RTICdrTypeCode *type_code)
    {
        struct RTIXCdrInterpreterPrograms *programs = NULL;
        struct PRESTypePluginDefaultParticipantData *pd = NULL;
        struct RTIXCdrInterpreterProgramsGenProperty programProperty =
        RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
        if (registration_data) {} /* To avoid warnings */
        if (participant_info) {} /* To avoid warnings */
        if (top_level_registration) {} /* To avoid warnings */
        if (container_plugin_context) {} /* To avoid warnings */
        if (type_code) {} /* To avoid warnings */
        pd = (struct PRESTypePluginDefaultParticipantData *)
        PRESTypePluginDefaultParticipantData_new(participant_info);

        programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
        programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
        programProperty.resolveAlias = RTI_XCDR_TRUE;
        programProperty.inlineStruct = RTI_XCDR_TRUE;
        programProperty.optimizeEnum = RTI_XCDR_TRUE;

        programProperty.externalReferenceSize = 
        (RTIXCdrUnsignedShort) sizeof(::dds::core::external<char>);
        programProperty.getExternalRefPointerFcn = 
        ::rti::topic::interpreter::get_external_value_pointer;

        programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
            DDS_TypeCodeFactory_get_instance(),
            (DDS_TypeCode *) (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccTestControl >::get().native()
            ,
            &programProperty,
            RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);

        if (programs == NULL) {
            PRESTypePluginDefaultParticipantData_delete(
                (PRESTypePluginParticipantData)pd);
            return NULL;
        }

        pd->programs = programs;
        return (PRESTypePluginParticipantData)pd;
    }

    void 
    ccTestControlPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data)
    {
        if (participant_data != NULL) {
            struct PRESTypePluginDefaultParticipantData *pd = 
            (struct PRESTypePluginDefaultParticipantData *)participant_data;

            if (pd->programs != NULL) {
                DDS_TypeCodeFactory_remove_programs_from_global_list(
                    DDS_TypeCodeFactory_get_instance(),
                    pd->programs);
                pd->programs = NULL;
            }
            PRESTypePluginDefaultParticipantData_delete(participant_data);
        }
    }

    PRESTypePluginEndpointData
    ccTestControlPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *containerPluginContext)
    {
        try {
            PRESTypePluginEndpointData epd = NULL;
            unsigned int serializedSampleMaxSize = 0;

            if (top_level_registration) {} /* To avoid warnings */
            if (containerPluginContext) {} /* To avoid warnings */

            if (participant_data == NULL) {
                return NULL;
            } 

            epd = PRESTypePluginDefaultEndpointData_new(
                participant_data,
                endpoint_info,
                (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                ccTestControlPluginSupport_create_data,
                (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                ccTestControlPluginSupport_destroy_data,
                NULL , NULL );

            if (epd == NULL) {
                return NULL;
            } 

            if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
                serializedSampleMaxSize = cctypes::ccTestControlPlugin_get_serialized_sample_max_size(
                    epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
                PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

                if (PRESTypePluginDefaultEndpointData_createWriterPool(
                    epd,
                    endpoint_info,
                    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                    cctypes::ccTestControlPlugin_get_serialized_sample_max_size, epd,
                    (PRESTypePluginGetSerializedSampleSizeFunction)
                    PRESTypePlugin_interpretedGetSerializedSampleSize,
                    epd) == RTI_FALSE) {
                    PRESTypePluginDefaultEndpointData_delete(epd);
                    return NULL;
                }
            }

            return epd;
        } catch (...) {
            return NULL;
        }
    }

    void 
    ccTestControlPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data)
    {  
        PRESTypePluginDefaultEndpointData_delete(endpoint_data);
    }

    void    
    ccTestControlPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccTestControl *sample,
        void *handle)
    {
        try {
            ::rti::topic::reset_sample(*sample);
        } catch(const std::exception& ex) {
            RTICdrLog_logWithFunctionName(
                RTI_LOG_BIT_EXCEPTION,
                "ccTestControlPlugin_return_sample",
                &RTI_LOG_ANY_FAILURE_ss,
                "exception: ",
                ex.what());
        }

        PRESTypePluginDefaultEndpointData_returnSample(
            endpoint_data, sample, handle);
    }

    RTIBool 
    ccTestControlPlugin_copy_sample(
        PRESTypePluginEndpointData,
        ccTestControl *dst,
        const ccTestControl *src)
    {
        return cctypes::ccTestControlPluginSupport_copy_data(dst,src);
    }

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */
    unsigned int 
    ccTestControlPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    RTIBool
    ccTestControlPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccTestControl *sample,
        ::dds::core::policy::DataRepresentationId representation)
    {
        using namespace ::dds::core::policy;

        try{
            RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
            struct RTICdrStream stream;
            struct PRESTypePluginDefaultEndpointData epd;
            RTIBool result;
            struct PRESTypePluginDefaultParticipantData pd;
            struct RTIXCdrTypePluginProgramContext defaultProgramContext =
            RTIXCdrTypePluginProgramContext_INTIALIZER;
            struct PRESTypePlugin plugin = PRES_TYPEPLUGIN_DEFAULT;

            if (length == NULL) {
                return RTI_FALSE;
            }

            RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
            epd.programContext = defaultProgramContext;
            epd._participantData = &pd;
            epd.typePlugin = &plugin;
            epd.programContext.endpointPluginData = &epd;
            plugin.typeCode = (struct RTICdrTypeCode *)
            (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccTestControl >::get().native()
            ;
            pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
            ccTestControl, 
            true, true, true>();

            encapsulationId = DDS_TypeCode_get_native_encapsulation(
                (DDS_TypeCode *) plugin.typeCode,
                representation);

            if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
                return RTI_FALSE;
            }

            epd._maxSizeSerializedSample =
            ccTestControlPlugin_get_serialized_sample_max_size(
                (PRESTypePluginEndpointData)&epd, 
                RTI_TRUE, 
                encapsulationId,
                0);

            if (buffer == NULL) {
                *length = 
                PRESTypePlugin_interpretedGetSerializedSampleSize(
                    (PRESTypePluginEndpointData)&epd,
                    RTI_TRUE,
                    encapsulationId,
                    0,
                    sample);

                if (*length == 0) {
                    return RTI_FALSE;
                }

                return RTI_TRUE;
            }    

            RTICdrStream_init(&stream);
            RTICdrStream_set(&stream, (char *)buffer, *length);

            result = PRESTypePlugin_interpretedSerialize(
                (PRESTypePluginEndpointData)&epd, 
                sample, 
                &stream, 
                RTI_TRUE, 
                encapsulationId,
                RTI_TRUE, 
                NULL);  

            *length = RTICdrStream_getCurrentPositionOffset(&stream);
            return result;     
        } catch (...) {
            return RTI_FALSE;
        }
    }

    RTIBool
    ccTestControlPlugin_deserialize_from_cdr_buffer(
        ccTestControl *sample,
        const char * buffer,
        unsigned int length)
    {
        struct RTICdrStream stream;
        struct PRESTypePluginDefaultParticipantData pd;
        struct RTIXCdrTypePluginProgramContext defaultProgramContext =
        RTIXCdrTypePluginProgramContext_INTIALIZER;
        struct PRESTypePlugin plugin;
        struct PRESTypePluginDefaultEndpointData epd;

        RTICdrStream_init(&stream);
        RTICdrStream_set(&stream, (char *)buffer, length);

        epd.programContext = defaultProgramContext;
        epd._participantData = &pd;
        epd.typePlugin = &plugin;
        epd.programContext.endpointPluginData = &epd;
        plugin.typeCode = (struct RTICdrTypeCode *)
        (struct RTICdrTypeCode *)(RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccTestControl >::get().native()
        ;
        pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
        ccTestControl, 
        true, true, true>();

        epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
        epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

        ::rti::topic::reset_sample(*sample);
        return PRESTypePlugin_interpretedDeserialize( 
            (PRESTypePluginEndpointData)&epd,
            sample,
            &stream, 
            RTI_TRUE, 
            RTI_TRUE, 
            NULL);
    }

    unsigned int 
    ccTestControlPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int size;
            RTIBool overflow = RTI_FALSE;

            size = PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
                endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

            if (overflow) {
                size = RTI_CDR_MAX_SERIALIZED_SIZE;
            }

            return size;
        } catch (...) {
            return 0;
        }    
    }

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    PRESTypePluginKeyKind 
    ccTestControlPlugin_get_key_kind(void)
    {
        return PRES_TYPEPLUGIN_NO_KEY;
    }

    RTIBool ccTestControlPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccTestControl **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos)
    {
        try {
            RTIBool result;
            if (drop_sample) {} /* To avoid warnings */
            stream->_xTypesState.unassignable = RTI_FALSE;
            result= PRESTypePlugin_interpretedDeserializeKey( 
                endpoint_data, (sample != NULL)?*sample:NULL, stream,
                deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
            if (result) {
                if (stream->_xTypesState.unassignable) {
                    result = RTI_FALSE;
                }
            }
            return result;    
        } catch (...) {
            return RTI_FALSE;
        }     
    }

    unsigned int
    ccTestControlPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int size;
            RTIBool overflow = RTI_FALSE;

            size = PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
                endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
            if (overflow) {
                size = RTI_CDR_MAX_SERIALIZED_SIZE;
            }

            return size;
        } catch (...) {
            return RTI_FALSE;
        }    
    }

    unsigned int
    ccTestControlPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
            endpoint_data,
            &overflow,
            encapsulation_id,
            current_alignment);
        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    }

    /* ------------------------------------------------------------------------
    * Plug-in Installation Methods
    * ------------------------------------------------------------------------ */
    struct PRESTypePlugin *ccTestControlPlugin_new(void) 
    { 
        struct PRESTypePlugin *plugin = NULL;
        const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

        RTIOsapiHeap_allocateStructure(
            &plugin, struct PRESTypePlugin);
        if (plugin == NULL) {
            return NULL;
        }

        plugin->version = PLUGIN_VERSION;

        /* set up parent's function pointers */
        plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        cctypes::ccTestControlPlugin_on_participant_attached;
        plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        cctypes::ccTestControlPlugin_on_participant_detached;
        plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        cctypes::ccTestControlPlugin_on_endpoint_attached;
        plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        cctypes::ccTestControlPlugin_on_endpoint_detached;

        plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        cctypes::ccTestControlPlugin_copy_sample;
        plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        ccTestControlPlugin_create_sample;
        plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        ccTestControlPlugin_destroy_sample;

        plugin->serializeFnc = 
        (PRESTypePluginSerializeFunction) PRESTypePlugin_interpretedSerialize;
        plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction) PRESTypePlugin_interpretedDeserializeWithAlloc;
        plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        cctypes::ccTestControlPlugin_get_serialized_sample_max_size;
        plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        PRESTypePlugin_interpretedGetSerializedSampleMinSize;
        plugin->getDeserializedSampleMaxSizeFnc = NULL; 
        plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        ccTestControlPlugin_get_sample;
        plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        ccTestControlPlugin_return_sample;
        plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        cctypes::ccTestControlPlugin_get_key_kind;

        /* These functions are only used for keyed types. As this is not a keyed
        type they are all set to NULL
        */
        plugin->serializeKeyFnc = NULL ;    
        plugin->deserializeKeyFnc = NULL;  
        plugin->getKeyFnc = NULL;
        plugin->returnKeyFnc = NULL;
        plugin->instanceToKeyFnc = NULL;
        plugin->keyToInstanceFnc = NULL;
        plugin->getSerializedKeyMaxSizeFnc = NULL;
        plugin->instanceToKeyHashFnc = NULL;
        plugin->serializedSampleToKeyHashFnc = NULL;
        plugin->serializedKeyToKeyHashFnc = NULL;    
        #ifdef NDDS_STANDALONE_TYPE
        plugin->typeCode = NULL; 
        #else
        plugin->typeCode = (struct RTICdrTypeCode *) 
        &::rti::topic::dynamic_type< cctypes::ccTestControl >::get().native();
        #endif
        plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

        /* Serialized buffer */
        plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        ccTestControlPlugin_get_buffer;
        plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        ccTestControlPlugin_return_buffer;
        plugin->getBufferWithParams = NULL;
        plugin->returnBufferWithParams = NULL;
        plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        PRESTypePlugin_interpretedGetSerializedSampleSize;

        plugin->getWriterLoanedSampleFnc = NULL; 
        plugin->returnWriterLoanedSampleFnc = NULL;
        plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
        plugin->validateWriterLoanedSampleFnc = NULL;
        plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

        static const char * TYPE_NAME = "cctypes::ccTestControl";
        plugin->endpointTypeName = TYPE_NAME;
        plugin->isMetpType = RTI_FALSE;
        return plugin;
    }

    void
    ccTestControlPlugin_delete(struct PRESTypePlugin *plugin)
    {
        RTIOsapiHeap_freeStructure(plugin);
    } 

    /* ----------------------------------------------------------------------------
    *  Type ccTestReport
    * -------------------------------------------------------------------------- */

    /* -----------------------------------------------------------------------------
    Support functions:
    * -------------------------------------------------------------------------- */

    ccTestReport *
    ccTestReportPluginSupport_create_data(void)
    {
        try {
            ccTestReport *sample = new ccTestReport();
            ::rti::topic::allocate_sample(*sample);
            return sample;
        } catch (...) {
            return NULL;
        }
    }

    void 
    ccTestReportPluginSupport_destroy_data(
        ccTestReport *sample) 
    {
        delete sample;
    }

    RTIBool 
    ccTestReportPluginSupport_copy_data(
        ccTestReport *dst,
        const ccTestReport *src)
    {
        try {
            *dst = *src;
        } catch (...) {
            return RTI_FALSE;
        }

        return RTI_TRUE;
    }

    /* ----------------------------------------------------------------------------
    Callback functions:
    * ---------------------------------------------------------------------------- */

    PRESTypePluginParticipantData 
    ccTestReportPlugin_on_participant_attached(
        void *registration_data,
        const struct PRESTypePluginParticipantInfo *participant_info,
        RTIBool top_level_registration,
        void *container_plugin_context,
        RTICdrTypeCode *type_code)
    {
        struct RTIXCdrInterpreterPrograms *programs = NULL;
        struct PRESTypePluginDefaultParticipantData *pd = NULL;
        struct RTIXCdrInterpreterProgramsGenProperty programProperty =
        RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;
        if (registration_data) {} /* To avoid warnings */
        if (participant_info) {} /* To avoid warnings */
        if (top_level_registration) {} /* To avoid warnings */
        if (container_plugin_context) {} /* To avoid warnings */
        if (type_code) {} /* To avoid warnings */
        pd = (struct PRESTypePluginDefaultParticipantData *)
        PRESTypePluginDefaultParticipantData_new(participant_info);

        programProperty.generateV1Encapsulation = RTI_XCDR_TRUE;
        programProperty.generateV2Encapsulation = RTI_XCDR_TRUE;
        programProperty.resolveAlias = RTI_XCDR_TRUE;
        programProperty.inlineStruct = RTI_XCDR_TRUE;
        programProperty.optimizeEnum = RTI_XCDR_TRUE;

        programProperty.externalReferenceSize = 
        (RTIXCdrUnsignedShort) sizeof(::dds::core::external<char>);
        programProperty.getExternalRefPointerFcn = 
        ::rti::topic::interpreter::get_external_value_pointer;

        programs = DDS_TypeCodeFactory_assert_programs_in_global_list(
            DDS_TypeCodeFactory_get_instance(),
            (DDS_TypeCode *) (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccTestReport >::get().native()
            ,
            &programProperty,
            RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN);

        if (programs == NULL) {
            PRESTypePluginDefaultParticipantData_delete(
                (PRESTypePluginParticipantData)pd);
            return NULL;
        }

        pd->programs = programs;
        return (PRESTypePluginParticipantData)pd;
    }

    void 
    ccTestReportPlugin_on_participant_detached(
        PRESTypePluginParticipantData participant_data)
    {
        if (participant_data != NULL) {
            struct PRESTypePluginDefaultParticipantData *pd = 
            (struct PRESTypePluginDefaultParticipantData *)participant_data;

            if (pd->programs != NULL) {
                DDS_TypeCodeFactory_remove_programs_from_global_list(
                    DDS_TypeCodeFactory_get_instance(),
                    pd->programs);
                pd->programs = NULL;
            }
            PRESTypePluginDefaultParticipantData_delete(participant_data);
        }
    }

    PRESTypePluginEndpointData
    ccTestReportPlugin_on_endpoint_attached(
        PRESTypePluginParticipantData participant_data,
        const struct PRESTypePluginEndpointInfo *endpoint_info,
        RTIBool top_level_registration, 
        void *containerPluginContext)
    {
        try {
            PRESTypePluginEndpointData epd = NULL;
            unsigned int serializedSampleMaxSize = 0;

            if (top_level_registration) {} /* To avoid warnings */
            if (containerPluginContext) {} /* To avoid warnings */

            if (participant_data == NULL) {
                return NULL;
            } 

            epd = PRESTypePluginDefaultEndpointData_new(
                participant_data,
                endpoint_info,
                (PRESTypePluginDefaultEndpointDataCreateSampleFunction)
                ccTestReportPluginSupport_create_data,
                (PRESTypePluginDefaultEndpointDataDestroySampleFunction)
                ccTestReportPluginSupport_destroy_data,
                NULL , NULL );

            if (epd == NULL) {
                return NULL;
            } 

            if (endpoint_info->endpointKind == PRES_TYPEPLUGIN_ENDPOINT_WRITER) {
                serializedSampleMaxSize = cctypes::ccTestReportPlugin_get_serialized_sample_max_size(
                    epd,RTI_FALSE,RTI_CDR_ENCAPSULATION_ID_CDR_BE,0);
                PRESTypePluginDefaultEndpointData_setMaxSizeSerializedSample(epd, serializedSampleMaxSize);

                if (PRESTypePluginDefaultEndpointData_createWriterPool(
                    epd,
                    endpoint_info,
                    (PRESTypePluginGetSerializedSampleMaxSizeFunction)
                    cctypes::ccTestReportPlugin_get_serialized_sample_max_size, epd,
                    (PRESTypePluginGetSerializedSampleSizeFunction)
                    PRESTypePlugin_interpretedGetSerializedSampleSize,
                    epd) == RTI_FALSE) {
                    PRESTypePluginDefaultEndpointData_delete(epd);
                    return NULL;
                }
            }

            return epd;
        } catch (...) {
            return NULL;
        }
    }

    void 
    ccTestReportPlugin_on_endpoint_detached(
        PRESTypePluginEndpointData endpoint_data)
    {  
        PRESTypePluginDefaultEndpointData_delete(endpoint_data);
    }

    void    
    ccTestReportPlugin_return_sample(
        PRESTypePluginEndpointData endpoint_data,
        ccTestReport *sample,
        void *handle)
    {
        try {
            ::rti::topic::reset_sample(*sample);
        } catch(const std::exception& ex) {
            RTICdrLog_logWithFunctionName(
                RTI_LOG_BIT_EXCEPTION,
                "ccTestReportPlugin_return_sample",
                &RTI_LOG_ANY_FAILURE_ss,
                "exception: ",
                ex.what());
        }

        PRESTypePluginDefaultEndpointData_returnSample(
            endpoint_data, sample, handle);
    }

    RTIBool 
    ccTestReportPlugin_copy_sample(
        PRESTypePluginEndpointData,
        ccTestReport *dst,
        const ccTestReport *src)
    {
        return cctypes::ccTestReportPluginSupport_copy_data(dst,src);
    }

    /* ----------------------------------------------------------------------------
    (De)Serialize functions:
    * ------------------------------------------------------------------------- */
    unsigned int 
    ccTestReportPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment);

    RTIBool
    ccTestReportPlugin_serialize_to_cdr_buffer(
        char * buffer,
        unsigned int * length,
        const ccTestReport *sample,
        ::dds::core::policy::DataRepresentationId representation)
    {
        using namespace ::dds::core::policy;

        try{
            RTIEncapsulationId encapsulationId = RTI_CDR_ENCAPSULATION_ID_INVALID;
            struct RTICdrStream stream;
            struct PRESTypePluginDefaultEndpointData epd;
            RTIBool result;
            struct PRESTypePluginDefaultParticipantData pd;
            struct RTIXCdrTypePluginProgramContext defaultProgramContext =
            RTIXCdrTypePluginProgramContext_INTIALIZER;
            struct PRESTypePlugin plugin = PRES_TYPEPLUGIN_DEFAULT;

            if (length == NULL) {
                return RTI_FALSE;
            }

            RTIOsapiMemory_zero(&epd, sizeof(struct PRESTypePluginDefaultEndpointData));
            epd.programContext = defaultProgramContext;
            epd._participantData = &pd;
            epd.typePlugin = &plugin;
            epd.programContext.endpointPluginData = &epd;
            plugin.typeCode = (struct RTICdrTypeCode *)
            (RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccTestReport >::get().native()
            ;
            pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
            ccTestReport, 
            true, true, true>();

            encapsulationId = DDS_TypeCode_get_native_encapsulation(
                (DDS_TypeCode *) plugin.typeCode,
                representation);

            if (encapsulationId == RTI_CDR_ENCAPSULATION_ID_INVALID) {
                return RTI_FALSE;
            }

            epd._maxSizeSerializedSample =
            ccTestReportPlugin_get_serialized_sample_max_size(
                (PRESTypePluginEndpointData)&epd, 
                RTI_TRUE, 
                encapsulationId,
                0);

            if (buffer == NULL) {
                *length = 
                PRESTypePlugin_interpretedGetSerializedSampleSize(
                    (PRESTypePluginEndpointData)&epd,
                    RTI_TRUE,
                    encapsulationId,
                    0,
                    sample);

                if (*length == 0) {
                    return RTI_FALSE;
                }

                return RTI_TRUE;
            }    

            RTICdrStream_init(&stream);
            RTICdrStream_set(&stream, (char *)buffer, *length);

            result = PRESTypePlugin_interpretedSerialize(
                (PRESTypePluginEndpointData)&epd, 
                sample, 
                &stream, 
                RTI_TRUE, 
                encapsulationId,
                RTI_TRUE, 
                NULL);  

            *length = RTICdrStream_getCurrentPositionOffset(&stream);
            return result;     
        } catch (...) {
            return RTI_FALSE;
        }
    }

    RTIBool
    ccTestReportPlugin_deserialize_from_cdr_buffer(
        ccTestReport *sample,
        const char * buffer,
        unsigned int length)
    {
        struct RTICdrStream stream;
        struct PRESTypePluginDefaultParticipantData pd;
        struct RTIXCdrTypePluginProgramContext defaultProgramContext =
        RTIXCdrTypePluginProgramContext_INTIALIZER;
        struct PRESTypePlugin plugin;
        struct PRESTypePluginDefaultEndpointData epd;

        RTICdrStream_init(&stream);
        RTICdrStream_set(&stream, (char *)buffer, length);

        epd.programContext = defaultProgramContext;
        epd._participantData = &pd;
        epd.typePlugin = &plugin;
        epd.programContext.endpointPluginData = &epd;
        plugin.typeCode = (struct RTICdrTypeCode *)
        (struct RTICdrTypeCode *)(RTIXCdrTypeCode *)&::rti::topic::dynamic_type< ccTestReport >::get().native()
        ;
        pd.programs = ::rti::topic::interpreter::get_cdr_serialization_programs<
        ccTestReport, 
        true, true, true>();

        epd._assignabilityProperty.acceptUnknownEnumValue = RTI_XCDR_TRUE;
        epd._assignabilityProperty.acceptUnknownUnionDiscriminator = RTI_XCDR_TRUE;

        ::rti::topic::reset_sample(*sample);
        return PRESTypePlugin_interpretedDeserialize( 
            (PRESTypePluginEndpointData)&epd,
            sample,
            &stream, 
            RTI_TRUE, 
            RTI_TRUE, 
            NULL);
    }

    unsigned int 
    ccTestReportPlugin_get_serialized_sample_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int size;
            RTIBool overflow = RTI_FALSE;

            size = PRESTypePlugin_interpretedGetSerializedSampleMaxSize(
                endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);

            if (overflow) {
                size = RTI_CDR_MAX_SERIALIZED_SIZE;
            }

            return size;
        } catch (...) {
            return 0;
        }    
    }

    /* --------------------------------------------------------------------------------------
    Key Management functions:
    * -------------------------------------------------------------------------------------- */

    PRESTypePluginKeyKind 
    ccTestReportPlugin_get_key_kind(void)
    {
        return PRES_TYPEPLUGIN_NO_KEY;
    }

    RTIBool ccTestReportPlugin_deserialize_key(
        PRESTypePluginEndpointData endpoint_data,
        ccTestReport **sample, 
        RTIBool * drop_sample,
        struct RTICdrStream *stream,
        RTIBool deserialize_encapsulation,
        RTIBool deserialize_key,
        void *endpoint_plugin_qos)
    {
        try {
            RTIBool result;
            if (drop_sample) {} /* To avoid warnings */
            stream->_xTypesState.unassignable = RTI_FALSE;
            result= PRESTypePlugin_interpretedDeserializeKey( 
                endpoint_data, (sample != NULL)?*sample:NULL, stream,
                deserialize_encapsulation, deserialize_key, endpoint_plugin_qos);
            if (result) {
                if (stream->_xTypesState.unassignable) {
                    result = RTI_FALSE;
                }
            }
            return result;    
        } catch (...) {
            return RTI_FALSE;
        }     
    }

    unsigned int
    ccTestReportPlugin_get_serialized_key_max_size(
        PRESTypePluginEndpointData endpoint_data,
        RTIBool include_encapsulation,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        try {
            unsigned int size;
            RTIBool overflow = RTI_FALSE;

            size = PRESTypePlugin_interpretedGetSerializedKeyMaxSize(
                endpoint_data,&overflow,include_encapsulation,encapsulation_id,current_alignment);
            if (overflow) {
                size = RTI_CDR_MAX_SERIALIZED_SIZE;
            }

            return size;
        } catch (...) {
            return RTI_FALSE;
        }    
    }

    unsigned int
    ccTestReportPlugin_get_serialized_key_max_size_for_keyhash(
        PRESTypePluginEndpointData endpoint_data,
        RTIEncapsulationId encapsulation_id,
        unsigned int current_alignment)
    {
        unsigned int size;
        RTIBool overflow = RTI_FALSE;

        size = PRESTypePlugin_interpretedGetSerializedKeyMaxSizeForKeyhash(
            endpoint_data,
            &overflow,
            encapsulation_id,
            current_alignment);
        if (overflow) {
            size = RTI_CDR_MAX_SERIALIZED_SIZE;
        }

        return size;
    }

    /* ------------------------------------------------------------------------
    * Plug-in Installation Methods
    * ------------------------------------------------------------------------ */
    struct PRESTypePlugin *ccTestReportPlugin_new(void) 
    { 
        struct PRESTypePlugin *plugin = NULL;
        const struct PRESTypePluginVersion PLUGIN_VERSION = 
        PRES_TYPE_PLUGIN_VERSION_2_0;

        RTIOsapiHeap_allocateStructure(
            &plugin, struct PRESTypePlugin);
        if (plugin == NULL) {
            return NULL;
        }

        plugin->version = PLUGIN_VERSION;

        /* set up parent's function pointers */
        plugin->onParticipantAttached =
        (PRESTypePluginOnParticipantAttachedCallback)
        cctypes::ccTestReportPlugin_on_participant_attached;
        plugin->onParticipantDetached =
        (PRESTypePluginOnParticipantDetachedCallback)
        cctypes::ccTestReportPlugin_on_participant_detached;
        plugin->onEndpointAttached =
        (PRESTypePluginOnEndpointAttachedCallback)
        cctypes::ccTestReportPlugin_on_endpoint_attached;
        plugin->onEndpointDetached =
        (PRESTypePluginOnEndpointDetachedCallback)
        cctypes::ccTestReportPlugin_on_endpoint_detached;

        plugin->copySampleFnc =
        (PRESTypePluginCopySampleFunction)
        cctypes::ccTestReportPlugin_copy_sample;
        plugin->createSampleFnc =
        (PRESTypePluginCreateSampleFunction)
        ccTestReportPlugin_create_sample;
        plugin->destroySampleFnc =
        (PRESTypePluginDestroySampleFunction)
        ccTestReportPlugin_destroy_sample;

        plugin->serializeFnc = 
        (PRESTypePluginSerializeFunction) PRESTypePlugin_interpretedSerialize;
        plugin->deserializeFnc =
        (PRESTypePluginDeserializeFunction) PRESTypePlugin_interpretedDeserializeWithAlloc;
        plugin->getSerializedSampleMaxSizeFnc =
        (PRESTypePluginGetSerializedSampleMaxSizeFunction)
        cctypes::ccTestReportPlugin_get_serialized_sample_max_size;
        plugin->getSerializedSampleMinSizeFnc =
        (PRESTypePluginGetSerializedSampleMinSizeFunction)
        PRESTypePlugin_interpretedGetSerializedSampleMinSize;
        plugin->getDeserializedSampleMaxSizeFnc = NULL; 
        plugin->getSampleFnc =
        (PRESTypePluginGetSampleFunction)
        ccTestReportPlugin_get_sample;
        plugin->returnSampleFnc =
        (PRESTypePluginReturnSampleFunction)
        ccTestReportPlugin_return_sample;
        plugin->getKeyKindFnc =
        (PRESTypePluginGetKeyKindFunction)
        cctypes::ccTestReportPlugin_get_key_kind;

        /* These functions are only used for keyed types. As this is not a keyed
        type they are all set to NULL
        */
        plugin->serializeKeyFnc = NULL ;    
        plugin->deserializeKeyFnc = NULL;  
        plugin->getKeyFnc = NULL;
        plugin->returnKeyFnc = NULL;
        plugin->instanceToKeyFnc = NULL;
        plugin->keyToInstanceFnc = NULL;
        plugin->getSerializedKeyMaxSizeFnc = NULL;
        plugin->instanceToKeyHashFnc = NULL;
        plugin->serializedSampleToKeyHashFnc = NULL;
        plugin->serializedKeyToKeyHashFnc = NULL;    
        #ifdef NDDS_STANDALONE_TYPE
        plugin->typeCode = NULL; 
        #else
        plugin->typeCode = (struct RTICdrTypeCode *) 
        &::rti::topic::dynamic_type< cctypes::ccTestReport >::get().native();
        #endif
        plugin->languageKind = PRES_TYPEPLUGIN_CPPSTL_LANG;

        /* Serialized buffer */
        plugin->getBuffer = 
        (PRESTypePluginGetBufferFunction)
        ccTestReportPlugin_get_buffer;
        plugin->returnBuffer = 
        (PRESTypePluginReturnBufferFunction)
        ccTestReportPlugin_return_buffer;
        plugin->getBufferWithParams = NULL;
        plugin->returnBufferWithParams = NULL;
        plugin->getSerializedSampleSizeFnc =
        (PRESTypePluginGetSerializedSampleSizeFunction)
        PRESTypePlugin_interpretedGetSerializedSampleSize;

        plugin->getWriterLoanedSampleFnc = NULL; 
        plugin->returnWriterLoanedSampleFnc = NULL;
        plugin->returnWriterLoanedSampleFromCookieFnc = NULL;
        plugin->validateWriterLoanedSampleFnc = NULL;
        plugin->setWriterLoanedSampleSerializedStateFnc = NULL;

        static const char * TYPE_NAME = "cctypes::ccTestReport";
        plugin->endpointTypeName = TYPE_NAME;
        plugin->isMetpType = RTI_FALSE;
        return plugin;
    }

    void
    ccTestReportPlugin_delete(struct PRESTypePlugin *plugin)
    {
        RTIOsapiHeap_freeStructure(plugin);
    } 
} /* namespace cctypes  */
#undef RTI_CDR_CURRENT_SUBMODULE 
