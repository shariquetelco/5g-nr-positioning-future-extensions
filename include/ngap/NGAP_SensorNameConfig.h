/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "../support/ngap-r18.0.0/38413-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NGAP_SensorNameConfig_H_
#define	_NGAP_SensorNameConfig_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_SensorNameConfig_PR {
	NGAP_SensorNameConfig_PR_NOTHING,	/* No components present */
	NGAP_SensorNameConfig_PR_uncompensatedBarometricConfig,
	NGAP_SensorNameConfig_PR_ueSpeedConfig,
	NGAP_SensorNameConfig_PR_ueOrientationConfig,
	NGAP_SensorNameConfig_PR_choice_Extensions
} NGAP_SensorNameConfig_PR;
typedef enum NGAP_SensorNameConfig__uncompensatedBarometricConfig {
	NGAP_SensorNameConfig__uncompensatedBarometricConfig_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_SensorNameConfig__uncompensatedBarometricConfig;
typedef enum NGAP_SensorNameConfig__ueSpeedConfig {
	NGAP_SensorNameConfig__ueSpeedConfig_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_SensorNameConfig__ueSpeedConfig;
typedef enum NGAP_SensorNameConfig__ueOrientationConfig {
	NGAP_SensorNameConfig__ueOrientationConfig_true	= 0
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_SensorNameConfig__ueOrientationConfig;

/* Forward declarations */
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_SensorNameConfig */
typedef struct NGAP_SensorNameConfig {
	NGAP_SensorNameConfig_PR present;
	union NGAP_SensorNameConfig_u {
		long	 uncompensatedBarometricConfig;
		long	 ueSpeedConfig;
		long	 ueOrientationConfig;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_SensorNameConfig_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_NGAP_uncompensatedBarometricConfig_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_NGAP_ueSpeedConfig_5;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_NGAP_ueOrientationConfig_8;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_SensorNameConfig;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_SensorNameConfig_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_SensorNameConfig_1[4];
extern asn_per_constraints_t asn_PER_type_NGAP_SensorNameConfig_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_SensorNameConfig_H_ */
#include <asn_internal.h>
