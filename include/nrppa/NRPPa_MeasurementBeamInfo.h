/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_MeasurementBeamInfo_H_
#define	_NRPPa_MeasurementBeamInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRPPa_PRS-Resource-ID.h"
#include "NRPPa_PRS-Resource-Set-ID.h"
#include "NRPPa_SSB-Index.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NRPPa_ProtocolExtensionContainer;

/* NRPPa_MeasurementBeamInfo */
typedef struct NRPPa_MeasurementBeamInfo {
	NRPPa_PRS_Resource_ID_t	*pRS_Resource_ID;	/* OPTIONAL */
	NRPPa_PRS_Resource_Set_ID_t	*pRS_Resource_Set_ID;	/* OPTIONAL */
	NRPPa_SSB_Index_t	*sSB_Index;	/* OPTIONAL */
	struct NRPPa_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_MeasurementBeamInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_MeasurementBeamInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_MeasurementBeamInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_MeasurementBeamInfo_1[4];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_MeasurementBeamInfo_H_ */
#include <asn_internal.h>
