#include "ngap-handler.h"
#include "nrppa-handler.h"

/*
 * handleDownlinkUEAssociatedNRPPaTransport - process NGAP Downlink UE Associated NRPPa Transport message and generate a response
 *
 * @msg: decoded NGAP message reference
 *
 * return: 0 on success, -1 otherwise
 *
 * NOTE: The NGAP is already decoded. Here, its contents has to be checked, the NRPPa PDU has to be decoded and processed.
 */
int
handleDownlinkUEAssociatedNRPPaTransport(ngapmsg_t *ngap)
{
	nrppamsg_t *nrppa = 0;
	ngapmsg_t *resp = 0;
	int i, j, k;
	long ran_ue_id = 0;
	uint64_t amf_ue_id = 0;
	uint8_t *ptr = 0;

	/*Check existence of NGAP PDU*/
	if(!ngap || !ngap->pdu)
	{
		return -1;
	}

	/*Check message header*/
	if(ngap->pdu->choice.initiatingMessage->procedureCode != NGAP_ProcedureCode_id_DownlinkUEAssociatedNRPPaTransport || ngap->pdu->choice.initiatingMessage->criticality != NGAP_Criticality_ignore)
	{
		return -1;
	}

	/*IE Container: 4 IEs are mandatory and the maximum*/
	if(!ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array || ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.size != 4 || ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.count != 4 )
	{
		return -1;
	}

	for(i = 0; i < 4; i++)
	{
		/*Chek if item is available*/
		if(!ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i])
		{
			return -1;
		}

		/*Examine each IE*/
		switch(i)
		{
			/*IE 1: AMF UE NGAP ID*/
			case 0:
				if(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_AMF_UE_NGAP_ID
					|| ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject
					|| ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_AMF_UE_NGAP_ID)
				{
					return -1;
				}

				if(!ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.buf ||
				    ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size > 5*sizeof(uint8_t) ||
				    !ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size) /*NOTE: tests show that depending on the transmitted ID less byte were sent...*/
				{
					return -1;
				}				

				/*
				 * Convert AMF UE NGAP ID from Big Endian to Little Endian
				 *
				 * NOTE: This conversion is not POSIX-compliant!
				 */
				ptr = (uint8_t*) &amf_ue_id;
				memcpy(ptr + 8 - ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size, ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.buf, ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size);
				amf_ue_id = be64toh(amf_ue_id);

				break;

			/*IE 2: RAN UE NGAP ID*/
			case 1:
				if(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_RAN_UE_NGAP_ID ||
				   ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject ||
				   ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_RAN_UE_NGAP_ID)
				{
					return -1;
				}

				ran_ue_id = ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.RAN_UE_NGAP_ID;

				/*
				 * Looking up in global tables, if pair of AMF and RAN NGAP IDs exist
				 *
				 * Here: NGAP ID pairs were created from file during initialization of the gNB.
				 */
				for(j = 0; j < GNB_MAX; j++)
				{
					if(ngap_ids[j].ngap_amf_ue_id == amf_ue_id && ngap_ids[j].ngap_ran_ue_id == ran_ue_id)
					{
#ifdef DEBUG
						printf("NGAP ID pair found at position: %d\n", j);
#endif
						break;
					}

					/*Error, if no entry is available!*/
					if(j == GNB_MAX - 1)
					{
						return -1;
					}
				}

				break;

			/*IE 3: Routing ID*/
			case 2:
				if(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_RoutingID ||
				   ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject ||
				   ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_RoutingID)
				{
					return -1;
				}

				if(!ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.RoutingID.buf ||
				    ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.RoutingID.size != 16*sizeof(uint8_t))
				{
					return -1;
				}

				break;

			/*IE 4: ASN.1 PER encoded NRPPa PDU*/
			case 3:
				if(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_NRPPa_PDU ||
				   ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject ||
				   ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_DownlinkUEAssociatedNRPPaTransportIEs__value_PR_NRPPa_PDU)
				{
					return -1;
				}

				if(!ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.NRPPa_PDU.buf || !ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.NRPPa_PDU.size)
				{
					return -1;
				}

				/*Decode NRPPa PDU*/
				if((nrppa = calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa = decodeNRPPa(ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.NRPPa_PDU.buf, ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.NRPPa_PDU.size)) == NULL)
				{
					return -1;
				}

				break;
				
			default:
				return -1;
		
		}

	}

	/*
	 * Pass the decoded NRPPa PDU to the NRPPa handler function:
	 *
	 * NOTE: The passed NRPPa PDU is freed in the NRPPa handler function!
	 */
	if((nrppa = handleNRPPaMessage(nrppa, ngap)) == NULL)
	{
		return -1;
	}

	/*If return value does not contain an encoded NRPPa PDU, no NGAP response message has to be generated!*/
	if(!nrppa->enc || !nrppa->size)
	{
		if(nrppa->enc)
		{
			free(nrppa->enc);
		}
		free(nrppa);
		return 0;
	}
	
	/*
	 * Create a NGAP Uplink UE Associated NRPPa Transport Message
	 *
	 * NOTE: Adopt AMF UE NGAP ID, RAN UE NGAP ID and Routing ID from the received NGAP message.
	 */
	if((resp = createNGAPforNRPPaTransport(NGAP_ProcedureCode_id_UplinkUEAssociatedNRPPaTransport, nrppa->enc, nrppa->size, ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[0]->value.choice.AMF_UE_NGAP_ID, ran_ue_id, ngap->pdu->choice.initiatingMessage->value.choice.DownlinkUEAssociatedNRPPaTransport.protocolIEs.list.array[2]->value.choice.RoutingID.buf)) == NULL)
	{
		free(nrppa->enc);
		free(nrppa);
		return -1;
	}
	
	/*Send NGAP response message to the target AMF*/
	if(sctpcli(amf->sockfd, &amf->con, false, resp->enc, resp->size, NULL) != 0)
	{
		freeNGAPMessage(resp);
		return -1;
	}
	
	/*Freeing NGAP message*/
	freeNGAPMessage(resp);

	return 0;
}

int
handleDownlinkNonUEAssociatedNRPPaTransport(ngapmsg_t *msg)
{
	return 0;
}
