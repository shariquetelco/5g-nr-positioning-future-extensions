/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_MeasurementPeriodicityNR_AoA_H_
#define	_NRPPa_MeasurementPeriodicityNR_AoA_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_MeasurementPeriodicityNR_AoA {
	NRPPa_MeasurementPeriodicityNR_AoA_ms160	= 0,
	NRPPa_MeasurementPeriodicityNR_AoA_ms320	= 1,
	NRPPa_MeasurementPeriodicityNR_AoA_ms640	= 2,
	NRPPa_MeasurementPeriodicityNR_AoA_ms1280	= 3,
	NRPPa_MeasurementPeriodicityNR_AoA_ms2560	= 4,
	NRPPa_MeasurementPeriodicityNR_AoA_ms5120	= 5,
	NRPPa_MeasurementPeriodicityNR_AoA_ms10240	= 6,
	NRPPa_MeasurementPeriodicityNR_AoA_ms20480	= 7,
	NRPPa_MeasurementPeriodicityNR_AoA_ms40960	= 8,
	NRPPa_MeasurementPeriodicityNR_AoA_ms61440	= 9,
	NRPPa_MeasurementPeriodicityNR_AoA_ms81920	= 10,
	NRPPa_MeasurementPeriodicityNR_AoA_ms368640	= 11,
	NRPPa_MeasurementPeriodicityNR_AoA_ms737280	= 12,
	NRPPa_MeasurementPeriodicityNR_AoA_ms1843200	= 13
	/*
	 * Enumeration is extensible
	 */
} e_NRPPa_MeasurementPeriodicityNR_AoA;

/* NRPPa_MeasurementPeriodicityNR-AoA */
typedef long	 NRPPa_MeasurementPeriodicityNR_AoA_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NRPPa_MeasurementPeriodicityNR_AoA_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_MeasurementPeriodicityNR_AoA;
extern const asn_INTEGER_specifics_t asn_SPC_NRPPa_MeasurementPeriodicityNR_AoA_specs_1;
asn_struct_free_f NRPPa_MeasurementPeriodicityNR_AoA_free;
asn_struct_print_f NRPPa_MeasurementPeriodicityNR_AoA_print;
asn_constr_check_f NRPPa_MeasurementPeriodicityNR_AoA_constraint;
per_type_decoder_f NRPPa_MeasurementPeriodicityNR_AoA_decode_aper;
per_type_encoder_f NRPPa_MeasurementPeriodicityNR_AoA_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_MeasurementPeriodicityNR_AoA_H_ */
#include <asn_internal.h>
