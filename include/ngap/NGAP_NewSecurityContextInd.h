/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_NewSecurityContextInd_H_
#define	_NGAP_NewSecurityContextInd_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_NewSecurityContextInd {
	NGAP_NewSecurityContextInd_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_NewSecurityContextInd;

/* NGAP_NewSecurityContextInd */
typedef long	 NGAP_NewSecurityContextInd_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NGAP_NewSecurityContextInd_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_NewSecurityContextInd;
extern const asn_INTEGER_specifics_t asn_SPC_NGAP_NewSecurityContextInd_specs_1;
asn_struct_free_f NGAP_NewSecurityContextInd_free;
asn_struct_print_f NGAP_NewSecurityContextInd_print;
asn_constr_check_f NGAP_NewSecurityContextInd_constraint;
per_type_decoder_f NGAP_NewSecurityContextInd_decode_aper;
per_type_encoder_f NGAP_NewSecurityContextInd_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_NewSecurityContextInd_H_ */
#include <asn_internal.h>
