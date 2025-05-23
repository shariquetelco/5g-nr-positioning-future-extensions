/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_NG_RANAccessPointPosition_H_
#define	_NRPPa_NG_RANAccessPointPosition_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_NG_RANAccessPointPosition__latitudeSign {
	NRPPa_NG_RANAccessPointPosition__latitudeSign_north	= 0,
	NRPPa_NG_RANAccessPointPosition__latitudeSign_south	= 1
} e_NRPPa_NG_RANAccessPointPosition__latitudeSign;
typedef enum NRPPa_NG_RANAccessPointPosition__directionOfAltitude {
	NRPPa_NG_RANAccessPointPosition__directionOfAltitude_height	= 0,
	NRPPa_NG_RANAccessPointPosition__directionOfAltitude_depth	= 1
} e_NRPPa_NG_RANAccessPointPosition__directionOfAltitude;

/* Forward declarations */
struct NRPPa_ProtocolExtensionContainer;

/* NRPPa_NG-RANAccessPointPosition */
typedef struct NRPPa_NG_RANAccessPointPosition {
	long	 latitudeSign;
	long	 latitude;
	long	 longitude;
	long	 directionOfAltitude;
	long	 altitude;
	long	 uncertaintySemi_major;
	long	 uncertaintySemi_minor;
	long	 orientationOfMajorAxis;
	long	 uncertaintyAltitude;
	long	 confidence;
	struct NRPPa_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_NG_RANAccessPointPosition_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_NRPPa_latitudeSign_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_NRPPa_directionOfAltitude_7;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_NG_RANAccessPointPosition;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_NG_RANAccessPointPosition_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_NG_RANAccessPointPosition_1[11];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_NG_RANAccessPointPosition_H_ */
#include <asn_internal.h>
