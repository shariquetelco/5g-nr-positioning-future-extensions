/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_TRP_PRS_Information_List_Item_H_
#define	_NRPPa_TRP_PRS_Information_List_Item_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRPPa_TRP-ID.h"
#include "NRPPa_NR-PCI.h"
#include "NRPPa_PRSConfiguration.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NRPPa_CGI_NR;
struct NRPPa_ProtocolExtensionContainer;

/* NRPPa_TRP-PRS-Information-List-Item */
typedef struct NRPPa_TRP_PRS_Information_List_Item {
	NRPPa_TRP_ID_t	 tRP_ID;
	NRPPa_NR_PCI_t	 nR_PCI;
	struct NRPPa_CGI_NR	*cGI_NR;	/* OPTIONAL */
	NRPPa_PRSConfiguration_t	 pRSConfiguration;
	struct NRPPa_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_TRP_PRS_Information_List_Item_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_TRP_PRS_Information_List_Item;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_TRP_PRS_Information_List_Item_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_TRP_PRS_Information_List_Item_1[5];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_TRP_PRS_Information_List_Item_H_ */
#include <asn_internal.h>
