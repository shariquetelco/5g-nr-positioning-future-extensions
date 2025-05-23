/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_DLCountChoice_H_
#define	_NGAP_DLCountChoice_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_DLCountChoice_PR {
	NGAP_DLCountChoice_PR_NOTHING,	/* No components present */
	NGAP_DLCountChoice_PR_count12bits,
	NGAP_DLCountChoice_PR_count18bits,
	NGAP_DLCountChoice_PR_choice_extension
} NGAP_DLCountChoice_PR;

/* Forward declarations */
struct NGAP_COUNTValueForPDCP_SN12;
struct NGAP_COUNTValueForPDCP_SN18;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_DLCountChoice */
typedef struct NGAP_DLCountChoice {
	NGAP_DLCountChoice_PR present;
	union NGAP_DLCountChoice_u {
		struct NGAP_COUNTValueForPDCP_SN12	*count12bits;
		struct NGAP_COUNTValueForPDCP_SN18	*count18bits;
		struct NGAP_ProtocolIE_SingleContainer	*choice_extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_DLCountChoice_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_DLCountChoice;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_DLCountChoice_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_DLCountChoice_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_DLCountChoice_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_DLCountChoice_H_ */
#include <asn_internal.h>
