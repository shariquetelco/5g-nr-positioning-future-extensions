/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_MBSSessionSetupResponseList_H_
#define	_NGAP_MBSSessionSetupResponseList_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_MBSSessionSetupResponseItem;

/* NGAP_MBSSessionSetupResponseList */
typedef struct NGAP_MBSSessionSetupResponseList {
	A_SEQUENCE_OF(struct NGAP_MBSSessionSetupResponseItem) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_MBSSessionSetupResponseList_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_MBSSessionSetupResponseList;
extern asn_SET_OF_specifics_t asn_SPC_NGAP_MBSSessionSetupResponseList_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_MBSSessionSetupResponseList_1[1];
extern asn_per_constraints_t asn_PER_type_NGAP_MBSSessionSetupResponseList_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_MBSSessionSetupResponseList_H_ */
#include <asn_internal.h>
