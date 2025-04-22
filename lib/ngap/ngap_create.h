/*C standard library headers*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>

/*ASN.1 headers*/
#include <aper_encoder.h>
#include <aper_decoder.h>

/*3GPP TS 38.413 compliant headers*/
#include <NGAP_NGAP-PDU.h>
#include <NGAP_InitiatingMessage.h>
#include <NGAP_SuccessfulOutcome.h>
#include <NGAP_UnsuccessfulOutcome.h>
#include <NGAP_DownlinkUEAssociatedNRPPaTransport.h>
#include <NGAP_DownlinkNonUEAssociatedNRPPaTransport.h>
#include <NGAP_UplinkUEAssociatedNRPPaTransport.h>
#include <NGAP_UplinkNonUEAssociatedNRPPaTransport.h>
#include <NGAP_ProtocolIE-Field.h>
#include <NGAP_GlobalGNB-ID.h>
#include <NGAP_SupportedTAItem.h>
#include <NGAP_BroadcastPLMNItem.h>
#include <NGAP_PLMNSupportItem.h>
#include <NGAP_SliceSupportItem.h>
#include <NGAP_ServedGUAMIItem.h>

#ifndef _NGAP_CREATE_H_
#define _NGAP_CREATE_H_

/*
 * Macros
 *
 * @MAX_BUF: size of buffer for PER encoding of a PDU
 * @MALLOC_IE: function to allocate memory for a IE container
 * @SET_AMF_IE: function to add AMF UE NGAP ID as an IE to a container
 * @SET_RAN_IE: function to add RAN UE NGAP ID as an IE to a container
 * @SET_ROUTING_ID_IE: function to add Routing ID as an IE to a container
 * @SET_NRPPA_PDU_IE: function to add the NRPPa SDU as an IE to a container
 */
#define MAX_BUF 131072

#define MALLOC_IE(container, num, type) \
{\
	if((container.protocolIEs.list.array = calloc(num, sizeof(type*))) == NULL)\
	{\
		perror("calloc()");\
		goto err;\
	}\
	container.protocolIEs.list.count = 0;\
	container.protocolIEs.list.size = num;\
	for(i = 0; i < num; i++)\
	{\
		if((container.protocolIEs.list.array[i] = calloc(1, sizeof(type))) == NULL)\
		{\
			perror("calloc()");\
			goto err;\
		}\
	}\
}

/*
 * @container: target IE container
 * @pres: IE present ID (see ngap/ProtocolIE-Field.h)
 * @amf: AMF UE NGAP ID (40 Bit)
 */
#define SET_AMF_ID_IE(container, pres, amf) \
{ \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_AMF_UE_NGAP_ID; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NGAP_Criticality_reject; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = pres; \
\
	/*3GPP TS 38.401, 6.2.1: Size of AMF UE NGAP ID not defined, ID shall be uniquely*/ \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.AMF_UE_NGAP_ID.buf = (uint8_t*) calloc(5, sizeof(uint8_t)); \
	memcpy((void*)container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.AMF_UE_NGAP_ID.buf, (void*)amf.buf, amf.size); \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.AMF_UE_NGAP_ID.size = amf.size; \
	container.protocolIEs.list.count++; \
}

/*
 * @container: target IE container
 * @pres: IE present ID (see ngap/ProtocolIE-Field.h)
 * @ran: RAN UE NGAP ID
 */
#define SET_RAN_ID_IE(container, pres, ran) \
{\
	container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_RAN_UE_NGAP_ID; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NGAP_Criticality_reject; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = pres; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.RAN_UE_NGAP_ID = ran; \
	container.protocolIEs.list.count++; \
}

/*
 * @container: target IE container
 * @num: number of allocated IEs (2 or 4) of @container
 * @pres: IE present ID (see ngap/ProtocolIE-Field.h)
 * @routing: Routing ID
 */
#define SET_ROUTING_ID_IE(container, pres, routing) \
{\
	container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_RoutingID; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NGAP_Criticality_reject; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = pres; \
\
	/*3GPP TS 38.413, 9.3.3.13: The maximum length of the Routing ID is 16 Bytes.*/ \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.RoutingID.buf = (uint8_t*) calloc(16, sizeof(uint8_t)); \
	memcpy((void*)container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.RoutingID.buf, (void*)routing, 16*sizeof(uint8_t)); \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.RoutingID.size = 16*sizeof(uint8_t); \
	container.protocolIEs.list.count++; \
}

#define SET_NRPPA_PDU_IE(container, pres, nrppa, ssize) \
{\
	container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_NRPPa_PDU; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NGAP_Criticality_reject; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = pres; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.NRPPa_PDU.buf = nrppa; \
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.NRPPa_PDU.size = ssize; \
	container.protocolIEs.list.count++; \
}

/*
 * ngapmsg - data structure to handle a NGAP PDU
 *
 * @pdu: pointer to the unencoded NGAP PDU
 * @enc: pointer to the ASN.1 PER encoded NGAP PDU
 * @size: size [B] of @enc 
 */
typedef struct ngapmsg
{
	NGAP_NGAP_PDU_t *pdu;
	uint8_t *enc;
	uint32_t size;
} ngapmsg_t;

/*
 * NGAP_NG_Setup_Request - create NG Setup Request message to initialize interface between gNB and AMF
 *
 * compliant with: 3GPP TS 38.413, 8.7.1
 */
ngapmsg_t* NGAP_NG_Setup_Request(const char *name, uint8_t *tac, uint8_t *plmn, uint8_t *sst);

/*
 * NGAP_NG_Setup_Response - create NG Setup Response message to response interface initialization to the target gNB
 *
 * compliant with: 3GPP TS 38.413, 8.7.1
 */
ngapmsg_t* NGAP_NG_Setup_Response(const char* name, uint8_t *plmn, uint8_t *amf_regio_id, uint8_t *amf_set_id, uint8_t *amf_pointer, NGAP_RelativeAMFCapacity_t *amf_capacity, uint8_t *sst);

/*
 * NGAP_NG_Setup_Failure - create NG Setup Failure message to response failure of interface initialization to the target gNB
 *
 * compliant with: 3GPP TS 38.413, 8.7.1
 */
ngapmsg_t* NGAP_Setup_Failure(NGAP_Cause_t *cause, NGAP_TimeToWait_t *ttw, NGAP_CriticalityDiagnostics_t *diagnostics);

/*
 * createNGAPforNRPPaTransport - Generation of a PER encoded NGAP PDU
 *
 * NOTE: According to 3GPP TS 38.413, 3.1 and 8.1, transporting a NRPPA PDU is a class 2 NGAP procedure.
 *		 Therefore, a response from the target is never expected.
 *
 * NOTE: According to 3GPP TS 38.305, 6.5.1: The AMF creates the whole NGAP, not the LMF! BUT: From LMF <-> AMF a reduced NGAP that only contains the NRPPA PDU is created.
 *
 * caller: AMF or gNB
 */
ngapmsg_t* createNGAPforNRPPaTransport(uint32_t id, uint8_t *sdu, size_t size, NGAP_AMF_UE_NGAP_ID_t amf_id, unsigned long ran_id, uint8_t *rid);


/*
 * getNRPPafromNGAPTransport - Decode NGAP PDU and extract its encapsulated NRPPa PDU
 *
 * caller: AMF or gNB
 */
void getNRPPafromNGAPTransport();

ngapmsg_t* decodeNGAP(uint8_t *enc, size_t size);

/*
 * createNGAPforNRPPaTransportSBI and getNGAPNRPPafromSBI - ASN.1 PER encoding of NGAP NRPPa PDU
 */
void createNGAPforNRPPaTransportSBI(uint8_t *sdu, size_t size, uint8_t** pdu, size_t* length);

NGAP_NRPPa_PDU_t* getNGAPNRPPafromSBI(uint8_t *data, size_t size);

void freeNGAPNRPPaSBI(NGAP_NRPPa_PDU_t* ngap);


/*
 * createNGAPforNASTransport - Generation of a PER encoded NGAP PDU
 *
 * compliant with: 3GPP TS 38.413, 8.6.2 and 8.6.3
 */
void createNGAPforNASTransport();

/*
 * getNASfromNGAPTransport - Decode NGAP PDU and extract its encapsulated NAS PDU
 */
void getNASfromNGAPTransport();

/*
 * freeNGAPMessage - free a NGAP message structure
 */
void freeNGAPMessage(ngapmsg_t *msg);

#endif
