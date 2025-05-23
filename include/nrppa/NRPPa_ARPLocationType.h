/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_ARPLocationType_H_
#define	_NRPPa_ARPLocationType_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_ARPLocationType_PR {
	NRPPa_ARPLocationType_PR_NOTHING,	/* No components present */
	NRPPa_ARPLocationType_PR_aRPPositionRelativeGeodetic,
	NRPPa_ARPLocationType_PR_aRPPositionRelativeCartesian,
	NRPPa_ARPLocationType_PR_choice_extension
} NRPPa_ARPLocationType_PR;

/* Forward declarations */
struct NRPPa_RelativeGeodeticLocation;
struct NRPPa_RelativeCartesianLocation;
struct NRPPa_ProtocolIE_Single_Container;

/* NRPPa_ARPLocationType */
typedef struct NRPPa_ARPLocationType {
	NRPPa_ARPLocationType_PR present;
	union NRPPa_ARPLocationType_u {
		struct NRPPa_RelativeGeodeticLocation	*aRPPositionRelativeGeodetic;
		struct NRPPa_RelativeCartesianLocation	*aRPPositionRelativeCartesian;
		struct NRPPa_ProtocolIE_Single_Container	*choice_extension;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_ARPLocationType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_ARPLocationType;
extern asn_CHOICE_specifics_t asn_SPC_NRPPa_ARPLocationType_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_ARPLocationType_1[3];
extern asn_per_constraints_t asn_PER_type_NRPPa_ARPLocationType_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_ARPLocationType_H_ */
#include <asn_internal.h>
