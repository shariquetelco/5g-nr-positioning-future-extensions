#include "ngap-handler.h"
#include "sbi-client.h"

/*
 * handleUplinkUEAssociatedNRPPaTransport - process NGAP Uplink UE Associated NRPPa Transport message and forward it to the target LMF
 *
 * @msg: decoded NGAP message reference
 *
 * return: 0 on success, -1 otherwise
 *
 * NOTE: The NGAP is already decoded. Here, its contents has to be checked, the NRPPa PDU has to be decoded and processed.
 */
int
handleUplinkUEAssociatedNRPPaTransport(ngapmsg_t *ngap)
{
	int i, j, k;
	NGAP_RAN_UE_NGAP_ID_t ran_ue_id = 0;
	uint64_t amf_ue_id = 0;
	uint8_t *ptr = 0;
	rentry_t *entry = 0;
	char nfid[37] = {0};
	nrppamsg_t *nrppa = 0;

	/*Check existence of NGAP PDU*/
	if(!ngap || !ngap->pdu)
	{
		return -1;
	}

	/*Check message header*/
	if(ngap->pdu->choice.initiatingMessage->procedureCode != NGAP_ProcedureCode_id_UplinkUEAssociatedNRPPaTransport || ngap->pdu->choice.initiatingMessage->criticality != NGAP_Criticality_ignore)
	{
		return -1;
	}

	/*IE Container: 4 IEs are mandatory and the maximum*/
	if(!ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array || ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.size != 4 || ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.count != 4 )
	{
		return -1;
	}

	/*Loop: Checking of each included IE*/
	for(i = 0; i < 4; i++)
	{
		if(!ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i])
		{
			return -1;
		}

		/*Examine each IE*/
		switch(i)
		{
			/*IE 1: AMF UE NGAP ID*/
			case 0:
				if(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_AMF_UE_NGAP_ID
					|| ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject
					|| ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_AMF_UE_NGAP_ID)
				{
					return -1;
				}

				if(!ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.buf ||
				    ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size > 5*sizeof(uint8_t) ||
				    !ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size) /*NOTE: tests show that depending on the transmitted ID less byte were sent...*/
				{
					return -1;
				}				

				/*Convert AMF UE NGAP ID from Big Endian to Little Endian*/
				ptr = (uint8_t*) &amf_ue_id;
				memcpy(ptr + 8 - ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size, ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.buf, ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.AMF_UE_NGAP_ID.size);
				amf_ue_id = be64toh(amf_ue_id);

				break;

			/*IE 2: RAN UE NGAP ID*/
			case 1:
				if(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_RAN_UE_NGAP_ID ||
				   ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject ||
				   ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_RAN_UE_NGAP_ID)
				{
					return -1;
				}

				ran_ue_id = ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.RAN_UE_NGAP_ID;

				break;

			/*IE 3: Routing ID*/
			case 2:
				if(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_RoutingID ||
				   ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject ||
				   ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_RoutingID)
				{
					return -1;
				}

				if(!ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.RoutingID.buf ||
				    ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.RoutingID.size != 16*sizeof(uint8_t))
				{
					return -1;
				}

				break;

			/*IE 4: ASN.1 PER encoded NRPPa PDU*/
			case 3:
				if(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->id != NGAP_ProtocolIE_ID_id_NRPPa_PDU ||
				   ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->criticality != NGAP_Criticality_reject ||
				   ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.present != NGAP_UplinkUEAssociatedNRPPaTransportIEs__value_PR_NRPPa_PDU)
				{
					return -1;
				}

				if(!ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.NRPPa_PDU.buf || !ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[i]->value.choice.NRPPa_PDU.size)
				{
					return -1;
				}

				break;
				
			default:
				return -1;
		
		}

	}

	/*
	 * Looking up in global UE context table, if a pair of AMF UE NGAP ID, RAN UE NGAP ID and Routing ID exists.
	 */
	if((entry = getEntryFull(ue_ctx, &ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[0]->value.choice.AMF_UE_NGAP_ID, &ran_ue_id, &ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[2]->value.choice.RoutingID)) == NULL)
	{
		uuid_unparse(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[2]->value.choice.RoutingID.buf, nfid);
		printf("[AMF-n2] No entry found in global LCS list for: %ld (AMF UE NGAP ID), %ld (RAN UE NGAP ID) and %s (NF ID)\n", amf_ue_id, ran_ue_id, nfid);

		return -1;
	}
	else if(!entry->sub_n2[n2_information_class_NRPPa-1] || !entry->sub_n2[n2_information_class_NRPPa-1]->n2_notify_callback_uri)
	{
#ifndef RESEARCH
		printf("[AMF-n2] No N2 callback URI for UE context %s available...\n", entry->imsi);
#endif
		pthread_mutex_unlock(&entry->lock);
		return -1;
	}
#ifndef RESEARCH
	else
	{
		printf("[AMF-n2] LCS entry found: %s with callback URI: %s\n", entry->imsi, entry->sub_n2[n2_information_class_NRPPa-1]->n2_notify_callback_uri);
	}
#endif

	/*Convert received Routing ID to NF ID (UUID) and compare with subscribed one*/
	uuid_unparse(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[2]->value.choice.RoutingID.buf, nfid);
	if( !nfid || !entry->sub_n2[n2_information_class_NRPPa-1]->nf_id || strcmp(entry->sub_n2[n2_information_class_NRPPa-1]->nf_id, nfid) != 0)
	{
		printf("[AMF-n2] Received Routing ID (%s) and subscribed NF ID (%s) do not match\n", nfid, entry->sub_n2[n2_information_class_NRPPa-1]->nf_id);
		pthread_mutex_unlock(&entry->lock);
		return -1;
	}

	/*Allocate memory for NRPPa message structure and initialize it*/
	if((nrppa = calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->enc = calloc(ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[3]->value.choice.NRPPa_PDU.size, sizeof(uint8_t))) == NULL)
	{
		if(nrppa)
		{
			free(nrppa);
		}
		pthread_mutex_unlock(&entry->lock);
		return -1;
	}
	memcpy(nrppa->enc, ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[3]->value.choice.NRPPa_PDU.buf, ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[3]->value.choice.NRPPa_PDU.size);
	nrppa->size = ngap->pdu->choice.initiatingMessage->value.choice.UplinkUEAssociatedNRPPaTransport.protocolIEs.list.array[3]->value.choice.NRPPa_PDU.size;

	/*SBI: Forwarding N2 data to the target LMF :-)*/
	if(namf_comm_n2InfoNotify(nrppa, entry->sub_n2[n2_information_class_NRPPa-1]->n2_notify_callback_uri, entry->sub_n2[n2_information_class_NRPPa-1]->nf_id, entry->lcs_id, entry->sub_n2_id[n2_information_class_NRPPa-1]) != 0)
	{
		pthread_mutex_unlock(&entry->lock);
		freeNRPPaMessage(nrppa);
		return -1;
	}
	pthread_mutex_unlock(&entry->lock);
	freeNRPPaMessage(nrppa);
	free(nrppa);

	return 0;
}

/*
 * handleUplinkNonUEAssociatedNRPPaTransport - process NGAP Uplink Non UE Associated NRPPa Transport message
 *
 * @msg: decoded NGAP message reference
 *
 * return: 0 on success, -1 otherwise
 *
 * NOTE: The NGAP is already decoded. Here, its contents has to be checked, the NRPPa PDU has to be decoded and processed.
 */
int
handleUplinkNonUEAssociatedNRPPaTransport(ngapmsg_t *msg)
{

	return 0;
}
