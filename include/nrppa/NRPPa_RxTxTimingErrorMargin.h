/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_RxTxTimingErrorMargin_H_
#define	_NRPPa_RxTxTimingErrorMargin_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_RxTxTimingErrorMargin {
	NRPPa_RxTxTimingErrorMargin_tc0dot5	= 0,
	NRPPa_RxTxTimingErrorMargin_tc1	= 1,
	NRPPa_RxTxTimingErrorMargin_tc2	= 2,
	NRPPa_RxTxTimingErrorMargin_tc4	= 3,
	NRPPa_RxTxTimingErrorMargin_tc8	= 4,
	NRPPa_RxTxTimingErrorMargin_tc12	= 5,
	NRPPa_RxTxTimingErrorMargin_tc16	= 6,
	NRPPa_RxTxTimingErrorMargin_tc20	= 7,
	NRPPa_RxTxTimingErrorMargin_tc24	= 8,
	NRPPa_RxTxTimingErrorMargin_tc32	= 9,
	NRPPa_RxTxTimingErrorMargin_tc40	= 10,
	NRPPa_RxTxTimingErrorMargin_tc48	= 11,
	NRPPa_RxTxTimingErrorMargin_tc64	= 12,
	NRPPa_RxTxTimingErrorMargin_tc80	= 13,
	NRPPa_RxTxTimingErrorMargin_tc96	= 14,
	NRPPa_RxTxTimingErrorMargin_tc128	= 15
	/*
	 * Enumeration is extensible
	 */
} e_NRPPa_RxTxTimingErrorMargin;

/* NRPPa_RxTxTimingErrorMargin */
typedef long	 NRPPa_RxTxTimingErrorMargin_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NRPPa_RxTxTimingErrorMargin_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_RxTxTimingErrorMargin;
extern const asn_INTEGER_specifics_t asn_SPC_NRPPa_RxTxTimingErrorMargin_specs_1;
asn_struct_free_f NRPPa_RxTxTimingErrorMargin_free;
asn_struct_print_f NRPPa_RxTxTimingErrorMargin_print;
asn_constr_check_f NRPPa_RxTxTimingErrorMargin_constraint;
per_type_decoder_f NRPPa_RxTxTimingErrorMargin_decode_aper;
per_type_encoder_f NRPPa_RxTxTimingErrorMargin_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_RxTxTimingErrorMargin_H_ */
#include <asn_internal.h>
