/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_EventTrigger_H_
#define	_NGAP_EventTrigger_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_EventTrigger_PR {
	NGAP_EventTrigger_PR_NOTHING,	/* No components present */
	NGAP_EventTrigger_PR_outOfCoverage,
	NGAP_EventTrigger_PR_eventL1LoggedMDTConfig,
	NGAP_EventTrigger_PR_choice_Extensions
} NGAP_EventTrigger_PR;
typedef enum NGAP_EventTrigger__outOfCoverage {
	NGAP_EventTrigger__outOfCoverage_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_EventTrigger__outOfCoverage;

/* Forward declarations */
struct NGAP_EventL1LoggedMDTConfig;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_EventTrigger */
typedef struct NGAP_EventTrigger {
	NGAP_EventTrigger_PR present;
	union NGAP_EventTrigger_u {
		long	 outOfCoverage;
		struct NGAP_EventL1LoggedMDTConfig	*eventL1LoggedMDTConfig;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_EventTrigger_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_NGAP_outOfCoverage_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_EventTrigger;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_EventTrigger_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_EventTrigger_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_EventTrigger_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_EventTrigger_H_ */
#include <asn_internal.h>
