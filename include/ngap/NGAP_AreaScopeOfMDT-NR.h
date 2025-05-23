/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_AreaScopeOfMDT_NR_H_
#define	_NGAP_AreaScopeOfMDT_NR_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NULL.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_AreaScopeOfMDT_NR_PR {
	NGAP_AreaScopeOfMDT_NR_PR_NOTHING,	/* No components present */
	NGAP_AreaScopeOfMDT_NR_PR_cellBased,
	NGAP_AreaScopeOfMDT_NR_PR_tABased,
	NGAP_AreaScopeOfMDT_NR_PR_pLMNWide,
	NGAP_AreaScopeOfMDT_NR_PR_tAIBased,
	NGAP_AreaScopeOfMDT_NR_PR_choice_Extensions
} NGAP_AreaScopeOfMDT_NR_PR;

/* Forward declarations */
struct NGAP_CellBasedMDT_NR;
struct NGAP_TABasedMDT;
struct NGAP_TAIBasedMDT;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_AreaScopeOfMDT-NR */
typedef struct NGAP_AreaScopeOfMDT_NR {
	NGAP_AreaScopeOfMDT_NR_PR present;
	union NGAP_AreaScopeOfMDT_NR_u {
		struct NGAP_CellBasedMDT_NR	*cellBased;
		struct NGAP_TABasedMDT	*tABased;
		NULL_t	 pLMNWide;
		struct NGAP_TAIBasedMDT	*tAIBased;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_AreaScopeOfMDT_NR_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_AreaScopeOfMDT_NR;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_AreaScopeOfMDT_NR_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_AreaScopeOfMDT_NR_1[5];
extern asn_per_constraints_t asn_PER_type_NGAP_AreaScopeOfMDT_NR_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_AreaScopeOfMDT_NR_H_ */
#include <asn_internal.h>
