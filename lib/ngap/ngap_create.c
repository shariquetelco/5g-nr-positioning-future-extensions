/*
 * Generation of a NGAP message that transports a NRPPa PDU according to 3GPP TS 38.413 v18.1.0 (Release 18)
 *
 * created on: 05/25/2024, NK
 * last modified: 05/27/2024, NK
 */
#include "ngap_create.h"

/*
 * createNGAPforNRPPaTransport - Generation of a PER encoded NGAP PDU
 *
 * @id: NGAP message procedure code that determine the NGAP PDU content.
 * @sdu: Service Data Unit, here: NRPPa PDU
 * @size: size [B] of the passed SDU
 * @amf_id: AMF UE NGAP ID
 * @ran_id: RAN UE NGAP ID
 * @rid: Routing ID (16B length)
 */
ngapmsg_t*
createNGAPforNRPPaTransport(uint32_t id, uint8_t *sdu, size_t size, NGAP_AMF_UE_NGAP_ID_t amf_id, unsigned long ran_id, uint8_t *rid)
{
	/*Variables*/
	int i;
	uint8_t buf[MAX_BUF];
	asn_enc_rval_t ec = {0}; /*result of PER encoding*/
	ngapmsg_t *ngap = 0;

	/*Checking input parameters*/
	if(!sdu || !rid)
	{
		return NULL;
	}

	/*Allocate memory*/
	if((ngap = (ngapmsg_t*) calloc(1, sizeof(ngapmsg_t))) == NULL || (ngap->pdu = (NGAP_NGAP_PDU_t*) calloc(1, sizeof(NGAP_NGAP_PDU_t))) == NULL || (ngap->pdu->choice.initiatingMessage = (NGAP_InitiatingMessage_t*) calloc(1, sizeof(NGAP_InitiatingMessage_t))) == NULL)
	{
		if(ngap && ngap->pdu)
		{
			free(ngap->pdu);
		}
		if(ngap)
		{
			free(ngap);
		}
		
		perror("calloc()");
		return NULL;
	}

	/*Set NGAP PDU flag*/
	ngap->pdu->present = NGAP_NGAP_PDU_PR_initiatingMessage;

	/*Set up NGAP_InitiatingMessage.criticality*/
	ngap->pdu->choice.initiatingMessage->criticality = NGAP_Criticality_ignore; /*ignore, see 3GPP TS 38.413, 9.2.9.X*/
	
	/*
	 * Allocation of memory and initialization of the NGAP IE container and its elements
	 *
	 * 3GPP TS 38.413, 9.2.9.X: The usage of all corresponding IEs is mandatory (M).
	 */
	switch(id)
	{
		/*3GPP TS 38.413, 9.2.9.1: Downlink UE Associated NRPPa Transport*/
		case NGAP_ProcedureCode_id_DownlinkUEAssociatedNRPPaTransport:
					MALLOC_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport, 4, NGAP_DownlinkUEAssociatedNRPPaTransportIEs_t)
					SET_AMF_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport, NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_AMF_UE_NGAP_ID, amf_id)
					SET_RAN_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport, NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_RAN_UE_NGAP_ID, ran_id)
					SET_ROUTING_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport, NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_RoutingID, rid)
					SET_NRPPA_PDU_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport, NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_NRPPa_PDU, sdu, size)

					/*Finish initialization of NGAP_InitiatingMessage*/
					ngap->pdu->choice.initiatingMessage->procedureCode = id;
					ngap->pdu->choice.initiatingMessage->value.present = NGAP_InitiatingMessage__value_PR_DownlinkUEAssociatedNRPPaTransport;

					break;

		/*3GPP TS 38.413, 9.2.9.2: Uplink UE Associated NRPPa Transport*/
		case NGAP_ProcedureCode_id_UplinkUEAssociatedNRPPaTransport:
					MALLOC_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport, 4, NGAP_UplinkUEAssociatedNRPPaTransportIEs_t)
					SET_AMF_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport, NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_AMF_UE_NGAP_ID, amf_id)
					SET_RAN_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport, NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_RAN_UE_NGAP_ID, ran_id)
					SET_ROUTING_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport, NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_RoutingID, rid)
					SET_NRPPA_PDU_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport, NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_NRPPa_PDU, sdu, size)

					/*Finish initialization of NGAP_InitiatingMessage*/
					ngap->pdu->choice.initiatingMessage->procedureCode = id;
					ngap->pdu->choice.initiatingMessage->value.present = NGAP_InitiatingMessage__value_PR_UplinkUEAssociatedNRPPaTransport;

					break;

		/*3GPP TS 38.413, 9.2.9.3: Downlink Non UE Associated NRPPa Transport*/
		case NGAP_ProcedureCode_id_DownlinkNonUEAssociatedNRPPaTransport:
					MALLOC_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkNonUEAssociatedNRPPaTransport, 2, NGAP_DownlinkNonUEAssociatedNRPPaTransportIEs_t)
					SET_ROUTING_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkNonUEAssociatedNRPPaTransport, NGAP_DownlinkNonUEAssociatedNRPPaTransportIEs__value_PR_RoutingID, rid)
					SET_NRPPA_PDU_IE(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkNonUEAssociatedNRPPaTransport, NGAP_DownlinkNonUEAssociatedNRPPaTransportIEs__value_PR_NRPPa_PDU, sdu, size)

					/*Finish initialization of NGAP_InitiatingMessage*/
					ngap->pdu->choice.initiatingMessage->procedureCode = id;
					ngap->pdu->choice.initiatingMessage->value.present = NGAP_InitiatingMessage__value_PR_DownlinkNonUEAssociatedNRPPaTransport;

					break;

		/*3GPP TS 38.413, 9.2.9.4: Uplink Non UE Associated NRPPa Transport*/
		case NGAP_ProcedureCode_id_UplinkNonUEAssociatedNRPPaTransport:
					MALLOC_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkNonUEAssociatedNRPPaTransport, 2, NGAP_UplinkNonUEAssociatedNRPPaTransportIEs_t)
					SET_ROUTING_ID_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkNonUEAssociatedNRPPaTransport, NGAP_UplinkNonUEAssociatedNRPPaTransportIEs__value_PR_RoutingID, rid)
					SET_NRPPA_PDU_IE(ngap->pdu->choice.initiatingMessage->value.choice.UplinkNonUEAssociatedNRPPaTransport, NGAP_UplinkNonUEAssociatedNRPPaTransportIEs__value_PR_NRPPa_PDU, sdu, size)

					/*Finish initialization of NGAP_InitiatingMessage*/
					ngap->pdu->choice.initiatingMessage->procedureCode = id;
					ngap->pdu->choice.initiatingMessage->value.present = NGAP_InitiatingMessage__value_PR_UplinkNonUEAssociatedNRPPaTransport;

					break;

		default:	goto err;
	}

	/*Encoding NGAP PDU via ASN.1 PER*/
	explicit_bzero(buf, sizeof(buf));
	ec = aper_encode_to_buffer(&asn_DEF_NGAP_NGAP_PDU, NULL, (void*) ngap->pdu, (void*) buf, MAX_BUF);
	if(ec.encoded < 0)
	{
		printf("aper_encode_to_buffer() failed!\n");
		goto err;
	}

	/*NGAP PDU: ASN.1 PER Encoding*/
	ngap->size = ec.encoded/8;
	ngap->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(ngap->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)ngap->enc, (void*)buf, (ec.encoded+7)/8);

	/*Free memory*/
//	ASN_STRUCT_FREE(asn_DEF_NGAP_NGAP_PDU, &ngap);

	return ngap;

err:

	return NULL;
}

void
createNGAPforNRPPaTransportSBI(uint8_t *sdu, size_t size, uint8_t** pdu, size_t* length)
{
	/*Variables*/
	uint8_t buf[MAX_BUF];
	asn_enc_rval_t ec = {0}; /*result of PER encoding*/

	NGAP_NRPPa_PDU_t *tmp = 0; /*NGAP wrapper: NRPPa PDU as Octet string -> 3GPP TS 38.413, 9.3.3.14*/

	/*
	 * Allocation of memory and initialization of the NGAP IE for the NRPPa PDU
	 *
	 * 3GPP TS 29.518, 6.1.6.4.3.2: Only the "IE" to wrap the NRPPa PDU is required (M): 3GPP TS 38.413, 9.3.3.1 Encode the NRPPa PDU as OCTET string
	 */
	if((tmp = (NGAP_NRPPa_PDU_t*) calloc(1, sizeof(NGAP_NRPPa_PDU_t))) == NULL || (tmp->buf = (uint8_t*) calloc(size, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)tmp->buf, (void*)sdu, size);
	tmp->size = size;

	/*ASN.1 PER encoding*/
	explicit_bzero(buf, sizeof(buf));
	ec = aper_encode_to_buffer(&asn_DEF_NGAP_NRPPa_PDU, NULL, (void*)tmp, (void*)buf, MAX_BUF);
	
	/*Checking result of ASN.1 PER encoding*/	
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Set pointer to encoded NGAP PDU and its size for the caller*/
	*length = ec.encoded/8;
	*pdu = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*pdu == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*pdu), (void*)buf, (ec.encoded+7)/8);

	/*Free memory*/
	ASN_STRUCT_FREE(asn_DEF_NGAP_NRPPa_PDU, tmp);

	return;

err:
	*length = 0;
	*pdu = 0;
	return;
}


NGAP_NRPPa_PDU_t*
getNGAPNRPPafromSBI(uint8_t *data, size_t size)
{
	/*Variables*/
	asn_dec_rval_t dec_ret = {0};	
	NGAP_NRPPa_PDU_t *tmp = 0;

	dec_ret = aper_decode(NULL, &asn_DEF_NGAP_NRPPa_PDU, (void **)&tmp, data, size, 0, 0);

	if(dec_ret.code != RC_OK)
	{
		return NULL;
	}
	
	return tmp;
}

void
freeNGAPNRPPaSBI(NGAP_NRPPa_PDU_t* ngap)
{
	ASN_STRUCT_FREE(asn_DEF_NGAP_NRPPa_PDU, ngap);
}

/*
 * getNRPPafromNGAPTransport - Decode NGAP PDU and extract its encapsulated NRPPa PDU
 */
void
getNRPPafromNGAPTransport()
{
	/*TODO: Implementation is open!*/
}

ngapmsg_t*
decodeNGAP(uint8_t *data, size_t size)
{
	/*Variables*/
	asn_dec_rval_t dec_ret = {0};
	ngapmsg_t *msg = 0;

	/*Checking for errors*/
	if(!data || !size || (msg = calloc(1, sizeof(ngapmsg_t))) == NULL)
	{
		return NULL;
	}

	dec_ret = aper_decode(NULL, &asn_DEF_NGAP_NGAP_PDU, (void **)&msg->pdu, data, size, 0, 0);

	if(dec_ret.code != RC_OK)
	{
		if(msg->pdu)
		{
			free(msg->pdu);
		}
		free(msg);
		return NULL;
	}

	return msg;
}

void
freeNGAPMessage(ngapmsg_t *msg)
{
	if(!msg)
	{
		return;
	}

	if(msg->enc)
	{
		free(msg->enc);
		msg->enc = 0;
		msg->size = 0;
	}

	if(msg->pdu)
	{
		ASN_STRUCT_FREE(asn_DEF_NGAP_NGAP_PDU, msg->pdu);
		msg->pdu = 0;
	}

	free(msg);

	return;
}	
