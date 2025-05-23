/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_UL_NGU_UP_TNLModifyItem_H_
#define	_NGAP_UL_NGU_UP_TNLModifyItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_UPTransportLayerInformation.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_UL-NGU-UP-TNLModifyItem */
typedef struct NGAP_UL_NGU_UP_TNLModifyItem {
	NGAP_UPTransportLayerInformation_t	 uL_NGU_UP_TNLInformation;
	NGAP_UPTransportLayerInformation_t	 dL_NGU_UP_TNLInformation;
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_UL_NGU_UP_TNLModifyItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_UL_NGU_UP_TNLModifyItem;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_UL_NGU_UP_TNLModifyItem_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_UL_NGU_UP_TNLModifyItem_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_UL_NGU_UP_TNLModifyItem_H_ */
#include <asn_internal.h>
