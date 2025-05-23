/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_M4Configuration_H_
#define	_NGAP_M4Configuration_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_M4period.h"
#include "NGAP_Links-to-log.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_M4Configuration */
typedef struct NGAP_M4Configuration {
	NGAP_M4period_t	 m4period;
	NGAP_Links_to_log_t	 m4_links_to_log;
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_M4Configuration_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_M4Configuration;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_M4Configuration_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_M4Configuration_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_M4Configuration_H_ */
#include <asn_internal.h>
