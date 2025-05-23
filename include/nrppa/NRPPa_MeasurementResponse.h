/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-PDU-Contents"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_MeasurementResponse_H_
#define	_NRPPa_MeasurementResponse_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRPPa_ProtocolIE-Container.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NRPPa_MeasurementResponse */
typedef struct NRPPa_MeasurementResponse {
	NRPPa_ProtocolIE_Container_4420P17_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_MeasurementResponse_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_MeasurementResponse;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_MeasurementResponse_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_MeasurementResponse_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_MeasurementResponse_H_ */
#include <asn_internal.h>
