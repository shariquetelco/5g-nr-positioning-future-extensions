/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_ProcedureStageChoice_H_
#define	_NGAP_ProcedureStageChoice_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_ProcedureStageChoice_PR {
	NGAP_ProcedureStageChoice_PR_NOTHING,	/* No components present */
	NGAP_ProcedureStageChoice_PR_first_dl_count,
	NGAP_ProcedureStageChoice_PR_choice_Extensions
} NGAP_ProcedureStageChoice_PR;

/* Forward declarations */
struct NGAP_FirstDLCount;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_ProcedureStageChoice */
typedef struct NGAP_ProcedureStageChoice {
	NGAP_ProcedureStageChoice_PR present;
	union NGAP_ProcedureStageChoice_u {
		struct NGAP_FirstDLCount	*first_dl_count;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_ProcedureStageChoice_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProcedureStageChoice;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_ProcedureStageChoice_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_ProcedureStageChoice_1[2];
extern asn_per_constraints_t asn_PER_type_NGAP_ProcedureStageChoice_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_ProcedureStageChoice_H_ */
#include <asn_internal.h>
