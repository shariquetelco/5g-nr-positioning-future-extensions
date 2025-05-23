/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_FiveG_ProSeAuthorized_H_
#define	_NGAP_FiveG_ProSeAuthorized_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_FiveGProSeDirectDiscovery.h"
#include "NGAP_FiveGProSeDirectCommunication.h"
#include "NGAP_FiveGProSeLayer2UEtoNetworkRelay.h"
#include "NGAP_FiveGProSeLayer3UEtoNetworkRelay.h"
#include "NGAP_FiveGProSeLayer2RemoteUE.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_FiveG-ProSeAuthorized */
typedef struct NGAP_FiveG_ProSeAuthorized {
	NGAP_FiveGProSeDirectDiscovery_t	*fiveGProSeDirectDiscovery;	/* OPTIONAL */
	NGAP_FiveGProSeDirectCommunication_t	*fiveGProSeDirectCommunication;	/* OPTIONAL */
	NGAP_FiveGProSeLayer2UEtoNetworkRelay_t	*fiveGProSeLayer2UEtoNetworkRelay;	/* OPTIONAL */
	NGAP_FiveGProSeLayer3UEtoNetworkRelay_t	*fiveGProSeLayer3UEtoNetworkRelay;	/* OPTIONAL */
	NGAP_FiveGProSeLayer2RemoteUE_t	*fiveGProSeLayer2RemoteUE;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_FiveG_ProSeAuthorized_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_FiveG_ProSeAuthorized;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_FiveG_ProSeAuthorized_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_FiveG_ProSeAuthorized_1[6];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_FiveG_ProSeAuthorized_H_ */
#include <asn_internal.h>
