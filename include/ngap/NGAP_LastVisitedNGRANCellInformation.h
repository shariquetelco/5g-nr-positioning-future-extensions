/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_LastVisitedNGRANCellInformation_H_
#define	_NGAP_LastVisitedNGRANCellInformation_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_NGRAN-CGI.h"
#include "NGAP_CellType.h"
#include "NGAP_TimeUEStayedInCell.h"
#include "NGAP_TimeUEStayedInCellEnhancedGranularity.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_Cause;
struct NGAP_ProtocolExtensionContainer;

/* NGAP_LastVisitedNGRANCellInformation */
typedef struct NGAP_LastVisitedNGRANCellInformation {
	NGAP_NGRAN_CGI_t	 globalCellID;
	NGAP_CellType_t	 cellType;
	NGAP_TimeUEStayedInCell_t	 timeUEStayedInCell;
	NGAP_TimeUEStayedInCellEnhancedGranularity_t	*timeUEStayedInCellEnhancedGranularity;	/* OPTIONAL */
	struct NGAP_Cause	*hOCauseValue;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_LastVisitedNGRANCellInformation_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_LastVisitedNGRANCellInformation;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_LastVisitedNGRANCellInformation_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_LastVisitedNGRANCellInformation_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_LastVisitedNGRANCellInformation_H_ */
#include <asn_internal.h>
