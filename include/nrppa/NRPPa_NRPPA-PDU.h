/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-PDU-Descriptions"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_NRPPA_PDU_H_
#define	_NRPPa_NRPPA_PDU_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_NRPPA_PDU_PR {
	NRPPa_NRPPA_PDU_PR_NOTHING,	/* No components present */
	NRPPa_NRPPA_PDU_PR_initiatingMessage,
	NRPPa_NRPPA_PDU_PR_successfulOutcome,
	NRPPa_NRPPA_PDU_PR_unsuccessfulOutcome
	/* Extensions may appear below */
	
} NRPPa_NRPPA_PDU_PR;

/* Forward declarations */
struct NRPPa_InitiatingMessage;
struct NRPPa_SuccessfulOutcome;
struct NRPPa_UnsuccessfulOutcome;

/* NRPPa_NRPPA-PDU */
typedef struct NRPPa_NRPPA_PDU {
	NRPPa_NRPPA_PDU_PR present;
	union NRPPa_NRPPA_PDU_u {
		struct NRPPa_InitiatingMessage	*initiatingMessage;
		struct NRPPa_SuccessfulOutcome	*successfulOutcome;
		struct NRPPa_UnsuccessfulOutcome	*unsuccessfulOutcome;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_NRPPA_PDU_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_NRPPA_PDU;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_NRPPA_PDU_H_ */
#include <asn_internal.h>
