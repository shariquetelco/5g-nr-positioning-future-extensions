/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_SRSPeriodicity_H_
#define	_NRPPa_SRSPeriodicity_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_SRSPeriodicity {
	NRPPa_SRSPeriodicity_slot1	= 0,
	NRPPa_SRSPeriodicity_slot2	= 1,
	NRPPa_SRSPeriodicity_slot4	= 2,
	NRPPa_SRSPeriodicity_slot5	= 3,
	NRPPa_SRSPeriodicity_slot8	= 4,
	NRPPa_SRSPeriodicity_slot10	= 5,
	NRPPa_SRSPeriodicity_slot16	= 6,
	NRPPa_SRSPeriodicity_slot20	= 7,
	NRPPa_SRSPeriodicity_slot32	= 8,
	NRPPa_SRSPeriodicity_slot40	= 9,
	NRPPa_SRSPeriodicity_slot64	= 10,
	NRPPa_SRSPeriodicity_slot80	= 11,
	NRPPa_SRSPeriodicity_slot160	= 12,
	NRPPa_SRSPeriodicity_slot320	= 13,
	NRPPa_SRSPeriodicity_slot640	= 14,
	NRPPa_SRSPeriodicity_slot1280	= 15,
	NRPPa_SRSPeriodicity_slot2560	= 16,
	NRPPa_SRSPeriodicity_slot5120	= 17,
	NRPPa_SRSPeriodicity_slot10240	= 18,
	NRPPa_SRSPeriodicity_slot40960	= 19,
	NRPPa_SRSPeriodicity_slot81920	= 20,
	/*
	 * Enumeration is extensible
	 */
	NRPPa_SRSPeriodicity_slot128	= 21,
	NRPPa_SRSPeriodicity_slot256	= 22,
	NRPPa_SRSPeriodicity_slot512	= 23,
	NRPPa_SRSPeriodicity_slot20480	= 24
} e_NRPPa_SRSPeriodicity;

/* NRPPa_SRSPeriodicity */
typedef long	 NRPPa_SRSPeriodicity_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NRPPa_SRSPeriodicity_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_SRSPeriodicity;
extern const asn_INTEGER_specifics_t asn_SPC_NRPPa_SRSPeriodicity_specs_1;
asn_struct_free_f NRPPa_SRSPeriodicity_free;
asn_struct_print_f NRPPa_SRSPeriodicity_print;
asn_constr_check_f NRPPa_SRSPeriodicity_constraint;
per_type_decoder_f NRPPa_SRSPeriodicity_decode_aper;
per_type_encoder_f NRPPa_SRSPeriodicity_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_SRSPeriodicity_H_ */
#include <asn_internal.h>
