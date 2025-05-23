/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_MeasurementAmount_H_
#define	_NRPPa_MeasurementAmount_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_MeasurementAmount {
	NRPPa_MeasurementAmount_ma0	= 0,
	NRPPa_MeasurementAmount_ma1	= 1,
	NRPPa_MeasurementAmount_ma2	= 2,
	NRPPa_MeasurementAmount_ma4	= 3,
	NRPPa_MeasurementAmount_ma8	= 4,
	NRPPa_MeasurementAmount_ma16	= 5,
	NRPPa_MeasurementAmount_ma32	= 6,
	NRPPa_MeasurementAmount_ma64	= 7
} e_NRPPa_MeasurementAmount;

/* NRPPa_MeasurementAmount */
typedef long	 NRPPa_MeasurementAmount_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NRPPa_MeasurementAmount_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_MeasurementAmount;
extern const asn_INTEGER_specifics_t asn_SPC_NRPPa_MeasurementAmount_specs_1;
asn_struct_free_f NRPPa_MeasurementAmount_free;
asn_struct_print_f NRPPa_MeasurementAmount_print;
asn_constr_check_f NRPPa_MeasurementAmount_constraint;
per_type_decoder_f NRPPa_MeasurementAmount_decode_aper;
per_type_encoder_f NRPPa_MeasurementAmount_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_MeasurementAmount_H_ */
#include <asn_internal.h>
