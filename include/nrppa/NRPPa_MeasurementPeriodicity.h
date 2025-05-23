/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_MeasurementPeriodicity_H_
#define	_NRPPa_MeasurementPeriodicity_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_MeasurementPeriodicity {
	NRPPa_MeasurementPeriodicity_ms120	= 0,
	NRPPa_MeasurementPeriodicity_ms240	= 1,
	NRPPa_MeasurementPeriodicity_ms480	= 2,
	NRPPa_MeasurementPeriodicity_ms640	= 3,
	NRPPa_MeasurementPeriodicity_ms1024	= 4,
	NRPPa_MeasurementPeriodicity_ms2048	= 5,
	NRPPa_MeasurementPeriodicity_ms5120	= 6,
	NRPPa_MeasurementPeriodicity_ms10240	= 7,
	NRPPa_MeasurementPeriodicity_min1	= 8,
	NRPPa_MeasurementPeriodicity_min6	= 9,
	NRPPa_MeasurementPeriodicity_min12	= 10,
	NRPPa_MeasurementPeriodicity_min30	= 11,
	NRPPa_MeasurementPeriodicity_min60	= 12,
	/*
	 * Enumeration is extensible
	 */
	NRPPa_MeasurementPeriodicity_ms20480	= 13,
	NRPPa_MeasurementPeriodicity_ms40960	= 14,
	NRPPa_MeasurementPeriodicity_extended	= 15
} e_NRPPa_MeasurementPeriodicity;

/* NRPPa_MeasurementPeriodicity */
typedef long	 NRPPa_MeasurementPeriodicity_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NRPPa_MeasurementPeriodicity_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_MeasurementPeriodicity;
extern const asn_INTEGER_specifics_t asn_SPC_NRPPa_MeasurementPeriodicity_specs_1;
asn_struct_free_f NRPPa_MeasurementPeriodicity_free;
asn_struct_print_f NRPPa_MeasurementPeriodicity_print;
asn_constr_check_f NRPPa_MeasurementPeriodicity_constraint;
per_type_decoder_f NRPPa_MeasurementPeriodicity_decode_aper;
per_type_encoder_f NRPPa_MeasurementPeriodicity_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_MeasurementPeriodicity_H_ */
#include <asn_internal.h>
