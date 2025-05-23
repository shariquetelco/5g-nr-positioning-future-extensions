/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_ImmediateMDTNr_H_
#define	_NGAP_ImmediateMDTNr_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_MeasurementsToActivate.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_M1Configuration;
struct NGAP_M4Configuration;
struct NGAP_M5Configuration;
struct NGAP_M6Configuration;
struct NGAP_M7Configuration;
struct NGAP_BluetoothMeasurementConfiguration;
struct NGAP_WLANMeasurementConfiguration;
struct NGAP_MDT_Location_Info;
struct NGAP_SensorMeasurementConfiguration;
struct NGAP_ProtocolExtensionContainer;

/* NGAP_ImmediateMDTNr */
typedef struct NGAP_ImmediateMDTNr {
	NGAP_MeasurementsToActivate_t	 measurementsToActivate;
	struct NGAP_M1Configuration	*m1Configuration;	/* OPTIONAL */
	struct NGAP_M4Configuration	*m4Configuration;	/* OPTIONAL */
	struct NGAP_M5Configuration	*m5Configuration;	/* OPTIONAL */
	struct NGAP_M6Configuration	*m6Configuration;	/* OPTIONAL */
	struct NGAP_M7Configuration	*m7Configuration;	/* OPTIONAL */
	struct NGAP_BluetoothMeasurementConfiguration	*bluetoothMeasurementConfiguration;	/* OPTIONAL */
	struct NGAP_WLANMeasurementConfiguration	*wLANMeasurementConfiguration;	/* OPTIONAL */
	struct NGAP_MDT_Location_Info	*mDT_Location_Info;	/* OPTIONAL */
	struct NGAP_SensorMeasurementConfiguration	*sensorMeasurementConfiguration;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_ImmediateMDTNr_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ImmediateMDTNr;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_ImmediateMDTNr_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_ImmediateMDTNr_1[11];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_ImmediateMDTNr_H_ */
#include <asn_internal.h>
