/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_EmergencyAreaIDCancelledEUTRA_Item_H_
#define	_NGAP_EmergencyAreaIDCancelledEUTRA_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_EmergencyAreaID.h"
#include "NGAP_CancelledCellsInEAI-EUTRA.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_EmergencyAreaIDCancelledEUTRA-Item */
typedef struct NGAP_EmergencyAreaIDCancelledEUTRA_Item {
	NGAP_EmergencyAreaID_t	 emergencyAreaID;
	NGAP_CancelledCellsInEAI_EUTRA_t	 cancelledCellsInEAI_EUTRA;
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_EmergencyAreaIDCancelledEUTRA_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_EmergencyAreaIDCancelledEUTRA_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_EmergencyAreaIDCancelledEUTRA_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_EmergencyAreaIDCancelledEUTRA_Item_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_EmergencyAreaIDCancelledEUTRA_Item_H_ */
#include <asn_internal.h>
