/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_NGRANHighAccuracyAccessPointPosition_H_
#define	_NRPPa_NGRANHighAccuracyAccessPointPosition_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NRPPa_ProtocolExtensionContainer;

/* NRPPa_NGRANHighAccuracyAccessPointPosition */
typedef struct NRPPa_NGRANHighAccuracyAccessPointPosition {
	long	 latitude;
	long	 longitude;
	long	 altitude;
	long	 uncertaintySemi_major;
	long	 uncertaintySemi_minor;
	long	 orientationOfMajorAxis;
	long	 horizontalConfidence;
	long	 uncertaintyAltitude;
	long	 verticalConfidence;
	struct NRPPa_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_NGRANHighAccuracyAccessPointPosition_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_NGRANHighAccuracyAccessPointPosition;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_NGRANHighAccuracyAccessPointPosition_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_NGRANHighAccuracyAccessPointPosition_1[10];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_NGRANHighAccuracyAccessPointPosition_H_ */
#include <asn_internal.h>
