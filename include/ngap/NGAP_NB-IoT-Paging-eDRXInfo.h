/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_NB_IoT_Paging_eDRXInfo_H_
#define	_NGAP_NB_IoT_Paging_eDRXInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_NB-IoT-Paging-eDRXCycle.h"
#include "NGAP_NB-IoT-Paging-TimeWindow.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_NB-IoT-Paging-eDRXInfo */
typedef struct NGAP_NB_IoT_Paging_eDRXInfo {
	NGAP_NB_IoT_Paging_eDRXCycle_t	 nB_IoT_Paging_eDRXCycle;
	NGAP_NB_IoT_Paging_TimeWindow_t	*nB_IoT_Paging_TimeWindow;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_NB_IoT_Paging_eDRXInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_NB_IoT_Paging_eDRXInfo;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_NB_IoT_Paging_eDRXInfo_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_NB_IoT_Paging_eDRXInfo_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_NB_IoT_Paging_eDRXInfo_H_ */
#include <asn_internal.h>
