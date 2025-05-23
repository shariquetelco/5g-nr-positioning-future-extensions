/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NRPPA-IEs"
 * 	found in "../support/nrppa-r18.1.0/38455-i10.asn"
 * 	`asn1c -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-BER -no-gen-XER -no-gen-OER -no-gen-UPER -no-gen-JER`
 */

#ifndef	_NRPPa_SRSResource_H_
#define	_NRPPa_SRSResource_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NRPPa_SRSResourceID.h"
#include <NativeEnumerated.h>
#include "NRPPa_TransmissionComb.h"
#include <NativeInteger.h>
#include "NRPPa_ResourceType.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NRPPa_SRSResource__nrofSRS_Ports {
	NRPPa_SRSResource__nrofSRS_Ports_port1	= 0,
	NRPPa_SRSResource__nrofSRS_Ports_ports2	= 1,
	NRPPa_SRSResource__nrofSRS_Ports_ports4	= 2
} e_NRPPa_SRSResource__nrofSRS_Ports;
typedef enum NRPPa_SRSResource__nrofSymbols {
	NRPPa_SRSResource__nrofSymbols_n1	= 0,
	NRPPa_SRSResource__nrofSymbols_n2	= 1,
	NRPPa_SRSResource__nrofSymbols_n4	= 2
} e_NRPPa_SRSResource__nrofSymbols;
typedef enum NRPPa_SRSResource__repetitionFactor {
	NRPPa_SRSResource__repetitionFactor_n1	= 0,
	NRPPa_SRSResource__repetitionFactor_n2	= 1,
	NRPPa_SRSResource__repetitionFactor_n4	= 2
} e_NRPPa_SRSResource__repetitionFactor;
typedef enum NRPPa_SRSResource__groupOrSequenceHopping {
	NRPPa_SRSResource__groupOrSequenceHopping_neither	= 0,
	NRPPa_SRSResource__groupOrSequenceHopping_groupHopping	= 1,
	NRPPa_SRSResource__groupOrSequenceHopping_sequenceHopping	= 2
} e_NRPPa_SRSResource__groupOrSequenceHopping;

/* Forward declarations */
struct NRPPa_ProtocolExtensionContainer;

/* NRPPa_SRSResource */
typedef struct NRPPa_SRSResource {
	NRPPa_SRSResourceID_t	 sRSResourceID;
	long	 nrofSRS_Ports;
	NRPPa_TransmissionComb_t	 transmissionComb;
	long	 startPosition;
	long	 nrofSymbols;
	long	 repetitionFactor;
	long	 freqDomainPosition;
	long	 freqDomainShift;
	long	 c_SRS;
	long	 b_SRS;
	long	 b_hop;
	long	 groupOrSequenceHopping;
	NRPPa_ResourceType_t	 resourceType;
	long	 sequenceId;
	struct NRPPa_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NRPPa_SRSResource_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_NRPPa_nrofSRS_Ports_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_NRPPa_nrofSymbols_9;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_NRPPa_repetitionFactor_13;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_NRPPa_groupOrSequenceHopping_22;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_NRPPa_SRSResource;
extern asn_SEQUENCE_specifics_t asn_SPC_NRPPa_SRSResource_specs_1;
extern asn_TYPE_member_t asn_MBR_NRPPa_SRSResource_1[15];

#ifdef __cplusplus
}
#endif

#endif	/* _NRPPa_SRSResource_H_ */
#include <asn_internal.h>
