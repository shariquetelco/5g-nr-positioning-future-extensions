/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_SRVCCOperationPossible_H_
#define	_NGAP_SRVCCOperationPossible_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_SRVCCOperationPossible {
	NGAP_SRVCCOperationPossible_possible	= 0,
	NGAP_SRVCCOperationPossible_notPossible	= 1
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_SRVCCOperationPossible;

/* NGAP_SRVCCOperationPossible */
typedef long	 NGAP_SRVCCOperationPossible_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NGAP_SRVCCOperationPossible_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_SRVCCOperationPossible;
extern const asn_INTEGER_specifics_t asn_SPC_NGAP_SRVCCOperationPossible_specs_1;
asn_struct_free_f NGAP_SRVCCOperationPossible_free;
asn_struct_print_f NGAP_SRVCCOperationPossible_print;
asn_constr_check_f NGAP_SRVCCOperationPossible_constraint;
per_type_decoder_f NGAP_SRVCCOperationPossible_decode_aper;
per_type_encoder_f NGAP_SRVCCOperationPossible_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_SRVCCOperationPossible_H_ */
#include <asn_internal.h>
