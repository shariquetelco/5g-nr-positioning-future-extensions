/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_PRSFrequencyHoppingConfiguration_EUTRA_H_
#define	_NRPPa_PRSFrequencyHoppingConfiguration_EUTRA_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRPPa_NumberOfFrequencyHoppingBands.h"
#include "NRPPa_NarrowBandIndex.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NRPPa_ProtocolExtensionContainer;

/* NRPPa_PRSFrequencyHoppingConfiguration-EUTRA */
typedef struct NRPPa_PRSFrequencyHoppingConfiguration_EUTRA {
	NRPPa_NumberOfFrequencyHoppingBands_t	 noOfFreqHoppingBands;
	struct NRPPa_PRSFrequencyHoppingConfiguration_EUTRA__bandPositions {
		A_SEQUENCE_OF(NRPPa_NarrowBandIndex_t) list;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} bandPositions;
	struct NRPPa_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_PRSFrequencyHoppingConfiguration_EUTRA_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_PRSFrequencyHoppingConfiguration_EUTRA;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_PRSFrequencyHoppingConfiguration_EUTRA_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_PRSFrequencyHoppingConfiguration_EUTRA_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_PRSFrequencyHoppingConfiguration_EUTRA_H_ */
#include <asn_internal.h>
