/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_ResourceSetTypeSemi_persistent_H_
#define	_NRPPa_ResourceSetTypeSemi_persistent_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_ResourceSetTypeSemi_persistent__semi_persistentSet {
	NRPPa_ResourceSetTypeSemi_persistent__semi_persistentSet_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NRPPa_ResourceSetTypeSemi_persistent__semi_persistentSet;

/* Forward declarations */
struct NRPPa_ProtocolExtensionContainer;

/* NRPPa_ResourceSetTypeSemi-persistent */
typedef struct NRPPa_ResourceSetTypeSemi_persistent {
	long	 semi_persistentSet;
	struct NRPPa_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_ResourceSetTypeSemi_persistent_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_NRPPa_semi_persistentSet_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_ResourceSetTypeSemi_persistent;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_ResourceSetTypeSemi_persistent_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_ResourceSetTypeSemi_persistent_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_ResourceSetTypeSemi_persistent_H_ */
#include <asn_internal.h>
