/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_SRSPortIndex_H_
#define	_NRPPa_SRSPortIndex_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_SRSPortIndex {
	NRPPa_SRSPortIndex_id1000	= 0,
	NRPPa_SRSPortIndex_id1001	= 1,
	NRPPa_SRSPortIndex_id1002	= 2,
	NRPPa_SRSPortIndex_id1003	= 3
	/*
	 * Enumeration is extensible
	 */
} e_NRPPa_SRSPortIndex;

/* NRPPa_SRSPortIndex */
typedef long	 NRPPa_SRSPortIndex_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NRPPa_SRSPortIndex_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_SRSPortIndex;
extern const asn_INTEGER_specifics_t asn_SPC_NRPPa_SRSPortIndex_specs_1;
asn_struct_free_f NRPPa_SRSPortIndex_free;
asn_struct_print_f NRPPa_SRSPortIndex_print;
asn_constr_check_f NRPPa_SRSPortIndex_constraint;
per_type_decoder_f NRPPa_SRSPortIndex_decode_aper;
per_type_encoder_f NRPPa_SRSPortIndex_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_SRSPortIndex_H_ */
#include <asn_internal.h>
