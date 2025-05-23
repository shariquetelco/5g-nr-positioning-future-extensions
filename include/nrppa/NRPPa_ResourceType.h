/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_ResourceType_H_
#define	_NRPPa_ResourceType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_ResourceType_PR {
	NRPPa_ResourceType_PR_NOTHING,	/* No components present */
	NRPPa_ResourceType_PR_periodic,
	NRPPa_ResourceType_PR_semi_persistent,
	NRPPa_ResourceType_PR_aperiodic,
	NRPPa_ResourceType_PR_choice_extension
} NRPPa_ResourceType_PR;

/* Forward declarations */
struct NRPPa_ResourceTypePeriodic;
struct NRPPa_ResourceTypeSemi_persistent;
struct NRPPa_ResourceTypeAperiodic;
struct NRPPa_ProtocolIE_Single_Container;

/* NRPPa_ResourceType */
typedef struct NRPPa_ResourceType {
	NRPPa_ResourceType_PR present;
	union NRPPa_ResourceType_u {
		struct NRPPa_ResourceTypePeriodic	*periodic;
		struct NRPPa_ResourceTypeSemi_persistent	*semi_persistent;
		struct NRPPa_ResourceTypeAperiodic	*aperiodic;
		struct NRPPa_ProtocolIE_Single_Container	*choice_extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_ResourceType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_ResourceType;
extern asn_CHOICE_specifics_t asn_SPC_NRPPa_ResourceType_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_ResourceType_1[4];
extern asn_per_constraints_t asn_PER_type_NRPPa_ResourceType_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_ResourceType_H_ */
#include <asn_internal.h>
