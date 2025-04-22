#include "ngap_create.h"

/*
 * NGAP_NG_Setup_Request - create NG Setup Request message to initialize interface between gNB and AMF
 *
 * compliant with: 3GPP TS 38.413, 8.7.1
 *
 * @name: gNB RAN node name
 * @tac: Tracking Area Code (see 3GPP TS 38.413, 9.3.3.10)
 * @plmn: PLMN Identity (see 3GPP TS 38.413, 9.3.3.5)
 * @sst: S-NSSAI SST (see 3GPP TS 38.413, 9.3.1.24)
 *
 * NOTE: @tac and @plmn has to be an array of size 3!
 */
ngapmsg_t*
NGAP_NG_Setup_Request(const char *name, uint8_t *tac, uint8_t *plmn, uint8_t *sst)
{
	/*Variables*/
	int i;
	uint8_t buf[MAX_BUF];
	asn_enc_rval_t ec = {0}; /*result of PER encoding*/

	ngapmsg_t *ngap = 0;

	/*Checking passed input parameters*/
	if(!name || strlen(name) > 150 || !tac || !plmn || !sst)
	{
		printf("Input parameters are invalid!\n");
		return NULL;
	}

	/*Allocate memory for NGAP specific data structures*/
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

	/*Set NGAP PDU type to InitiatingMessage*/
	ngap->pdu->present = NGAP_NGAP_PDU_PR_initiatingMessage;

	/*Initialize NGAP InitiatingMessage*/
	ngap->pdu->choice.initiatingMessage->procedureCode = NGAP_ProcedureCode_id_NGSetup;
	ngap->pdu->choice.initiatingMessage->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.initiatingMessage->value.present = NGAP_InitiatingMessage__value_PR_NGSetupRequest;
	
	/*
	 * Allocation of memory and initialization of the NGAP IE container and its elements
	 *
	 * 3GPP TS 38.413, 9.2.6.1: The usage of 3 IEs is mandatory (M). But: we want to add a gNB human readable name, so 4 IEs are reserved.
	 */
	MALLOC_IE(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest, 4, NGAP_NGSetupRequestIEs_t)
	
	/*
	 * (1) Global RAN Node ID
	 */
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_GlobalRANNodeID;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.present = NGAP_NGSetupRequestIEs__value_PR_GlobalRANNodeID;

	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.present = NGAP_GlobalRANNodeID_PR_globalGNB_ID;
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID = calloc(1, sizeof(NGAP_GlobalGNB_ID_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
		
	/*PLMN Identity*/
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.buf = calloc(3, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.size = 3;
	memcpy((void*) ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.buf, (void*) plmn, 3);

	/*Global gNB ID*/
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.present = NGAP_GNB_ID_PR_gNB_ID;
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf = malloc(4 * sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	/*TODO: gNB ID Aufbau ggf. anpassen! -> s. 3GPP TS 29.571, 5.4.4.29, aktuell: initialisiert via malloc(3), d.h. Speicherinhalt ist zufaellig!*/
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.size = 4;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.bits_unused = 0;

	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count++;

	/*
	 * (2) RAN Node Name
	 */
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_RANNodeName;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->criticality = NGAP_Criticality_ignore;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.present = NGAP_NGSetupRequestIEs__value_PR_RANNodeName;
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.RANNodeName.buf = (uint8_t*) strdup(name)) == NULL)
	{
		perror("strdup()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.RANNodeName.size = strlen(name); /*sending without termination character*/

	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count++;
	
	/*
	 * (3) Supported TA List
	 */
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_SupportedTAList;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.present = NGAP_NGSetupRequestIEs__value_PR_SupportedTAList;
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array = calloc(1, sizeof(NGAP_SupportedTAItem_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.count = 1;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.size = 1;
	
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0] = calloc(1, sizeof(NGAP_SupportedTAItem_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	
	/*
	 * (3.1) TA List Item 1
	 */
	/*Tracking Area Code*/
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->tAC.buf = calloc(3, sizeof(uint8_t))) == NULL) /*TAC = 3 Byte*/
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->tAC.size = 3;
	memcpy((void*) ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->tAC.buf, (void*) tac, 3);

	/*Broadcast PLMN List*/
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array = calloc(1, sizeof(NGAP_BroadcastPLMNItem_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.count = 1;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.size = 1;

	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0] = calloc(1, sizeof(NGAP_BroadcastPLMNItem_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}

	/*
	 * PLMN List item
	 */
	/*PLMN Identity*/
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->pLMNIdentity.buf = calloc(3, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->pLMNIdentity.size = 3;
	memcpy((void*) ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->pLMNIdentity.buf, (void*) plmn, 3);

	/*Slice Support List*/
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array = calloc(1, sizeof(NGAP_SliceSupportItem_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.size = 1;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.count = 1;
	
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0] = calloc(1, sizeof(NGAP_SliceSupportItem_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	
	/*S-NSSAI (3GPP TS 38.413, 9.3.1.24)*/
	if((ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0]->s_NSSAI.sST.buf = calloc(1, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0]->s_NSSAI.sST.size = 1;
	memcpy((void*) ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0]->s_NSSAI.sST.buf, (void*) sst, 1);

	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count++;

	/*
	 * (4) Default paging DRX (here: 256 radio frames), see 3GPP TS 38.413, 9.3.1.90
	 */
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_DefaultPagingDRX;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->criticality = NGAP_Criticality_ignore;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.present = NGAP_NGSetupRequestIEs__value_PR_PagingDRX;
	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count]->value.choice.PagingDRX = NGAP_PagingDRX_v256;

	ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count++;

	/*Encoding NGAP PDU via ASN.1 PER*/
	explicit_bzero(buf, sizeof(buf));
	ec = aper_encode_to_buffer(&asn_DEF_NGAP_NGAP_PDU, NULL, (void*) ngap->pdu, (void*) buf, MAX_BUF);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*NGAP PDU: ASN.1 PER encoding*/
	ngap->size = ec.encoded/8;
	ngap->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(ngap->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)ngap->enc, (void*)buf, (ec.encoded+7)/8);

	return ngap;
	
err:
	/*Free IEs that are also allocated dynamically*/
	if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array)
	{
		/*Global RAN Node ID*/
		if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0])
		{
			if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID)
			{
				/*PLMN Identity*/
				if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.buf)
				{
					free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.buf);
				}
	
				/*Global gNB ID*/
				if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf)
				{
					free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf);
				}
				
				free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID);
			}
			free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]);
		}
	
		/*RAN Node name buffer*/
		if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1])
		{
			if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.choice.RANNodeName.buf)
			{
				free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.choice.RANNodeName.buf);
			}
			free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]);
		}

		/*Supported TA List*/
		if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2])
		{
			if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array)
			{
				/*Supported TA list item 1: Broadcast PLMN List*/
				if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0])
				{
					if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array)
					{
						/*PLMN identity*/
						if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0])
						{
							if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->pLMNIdentity.buf)
							{
								free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->pLMNIdentity.buf);
							}
							free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]);
						}
		
						/*SliceSupport List*/
						if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array)
						{
							/*S-NSSAI*/
							if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0])
							{
								/*S-NSSAI SST*/
								if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0]->s_NSSAI.sST.buf)
								{
									free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0]->s_NSSAI.sST.buf);
								}
							
								free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array[0]);
							}
						
							free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]->tAISliceSupportList.list.array);
						}
		
						/*Broadcast PLMN List Item 1*/
						if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0])
						{
							free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array[0]);
						}
						
						free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->broadcastPLMNList.list.array);
					}
	
					/*Supported TA list item 1: TAC*/
					if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->tAC.buf)
					{
						free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]->tAC.buf);
					}
			
					/*Supported TA list item*/
					if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0])
					{
						free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]);
					}

					free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[0]);
				}
				
				free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array);
			}
			free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]);
		}

		/*NG Setup Request: Last IE*/
		if(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[3])
		{
			free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[3]);
		}
		
		free(ngap->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array);
	}

	/*Free main data structures*/
	free(ngap->pdu->choice.initiatingMessage);
	free(ngap->pdu);
	free(ngap);
	
	return NULL;
}

/*
 * NGAP_NG_Setup_Response - create NG Setup Response message to response interface initialization to the target gNB
 *
 * compliant with: 3GPP TS 38.413, 8.7.1
 *
 * @name: AMF name
 * @plmn: PLMN Identity (see 3GPP TS 38.413, 9.3.3.5)
 * @amf_regio_id: AMF Region ID (see 3GPP TS 38.413, 9.3.3.3)
 * @amf_set_id: AMF Set ID (see 3GPP TS 38.413, 9.3.3.12)
 * @amf_pointer: AMF Set pointer (see 3GPP TS 38.413, 9.3.3.19)
 * @amf_capacity: Relative AMF Capacity (see 3GPP TS 38.413, 9.3.1.32)
 * @sst: S-NSSAI SST (see 3GPP TS 38.413, 9.3.1.24)
 */
ngapmsg_t*
NGAP_NG_Setup_Response(const char* name, uint8_t *plmn, uint8_t *amf_regio_id, uint8_t *amf_set_id, uint8_t *amf_pointer, NGAP_RelativeAMFCapacity_t *amf_capacity, uint8_t *sst)
{
	/*Variables*/
	int i;
	uint8_t buf[MAX_BUF];
	asn_enc_rval_t ec = {0}; /*result of PER encoding*/

	ngapmsg_t *ngap = 0;

	/*Checking passed input parameters*/
	if(!name || strlen(name) > 150 || !plmn || !amf_regio_id || !amf_set_id || !amf_pointer || !amf_capacity || !sst)
	{
		printf("Input parameters are invalid!\n");
		return NULL;
	}

	/*Allocate memory for NGAP specific data structures*/
	if((ngap = (ngapmsg_t*) calloc(1, sizeof(ngapmsg_t))) == NULL || (ngap->pdu = (NGAP_NGAP_PDU_t*) calloc(1, sizeof(NGAP_NGAP_PDU_t))) == NULL || (ngap->pdu->choice.successfulOutcome = (NGAP_SuccessfulOutcome_t*) calloc(1, sizeof(NGAP_SuccessfulOutcome_t))) == NULL)
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

	/*Set NGAP PDU type to SuccessfulOutcome*/
	ngap->pdu->present = NGAP_NGAP_PDU_PR_successfulOutcome;

	/*Initialize NGAP InitiatingMessage*/
	ngap->pdu->choice.successfulOutcome->procedureCode = NGAP_ProcedureCode_id_NGSetup;
	ngap->pdu->choice.successfulOutcome->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.successfulOutcome->value.present = NGAP_SuccessfulOutcome__value_PR_NGSetupResponse;
	
	/*
	 * Allocation of memory and initialization of the NGAP IE container and its elements
	 *
	 * 3GPP TS 38.413, 9.2.6.2: The usage of 4 IEs is mandatory (M).
	 */
	MALLOC_IE(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse, 4, NGAP_NGSetupResponseIEs_t)

	/*
	 * (1) AMF Name
	 */
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_AMFName;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.present = NGAP_NGSetupResponseIEs__value_PR_AMFName;
	
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.AMFName.buf = (uint8_t*) strdup(name)) == NULL)
	{
		perror("strdup()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.AMFName.size = strlen(name);
	
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count++;
	
	/*
	 * (2) Served GUAMI List
	 *
	 * NOTE: Only 1 list item added!
	 */
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_ServedGUAMIList;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.present = NGAP_NGSetupResponseIEs__value_PR_ServedGUAMIList;

	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array = calloc(1, sizeof(NGAP_ServedGUAMIItem_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.size = 1;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.count = 1;

	/*Served GUAMI List Item 1*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0] = calloc(1, sizeof(NGAP_ServedGUAMIItem_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	
	/*GUAMI -> PLMN Identity*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.pLMNIdentity.buf = calloc(3, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.pLMNIdentity.size = 3;
	memcpy((void*)ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.pLMNIdentity.buf, (void*) plmn, 3);

	/*GUAMI -> AMF Region ID [1 B]*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFRegionID.buf = calloc(1, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFRegionID.size = 1;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFRegionID.bits_unused = 0;
	memcpy((void*) ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFRegionID.buf, (void*) amf_regio_id, 1);
	
	/*GUAMI -> AMF Set ID [10 Bit]*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFSetID.buf = calloc(2, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFSetID.size = 2;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFSetID.bits_unused = 6;
	memcpy((void*) ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFSetID.buf, (void*) amf_set_id, 2);
	
	/*GUAMI -> AMF Pointer [6 Bit]*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFPointer.buf = calloc(1, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFPointer.size = 1;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFPointer.bits_unused = 2;
	memcpy((void*) ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFPointer.buf, (void*) amf_pointer, 1);

	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count++;

	/*
	 * (3) Relative AMF Capacity
	 */
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_RelativeAMFCapacity;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->criticality = NGAP_Criticality_ignore;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.present = NGAP_NGSetupResponseIEs__value_PR_RelativeAMFCapacity;
	
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.RelativeAMFCapacity = *amf_capacity;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count++;

	/*
	 * (4) PLMN Support List
	 */
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_PLMNSupportList;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.present = NGAP_NGSetupResponseIEs__value_PR_PLMNSupportList;

	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array = calloc(1, sizeof(NGAP_PLMNSupportItem_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.size = 1;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.count = 1;

	/*PLMN Support Item 1*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0] = calloc(1, sizeof(NGAP_PLMNSupportItem_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}

	/*Item 1 -> PLMN Identity*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->pLMNIdentity.buf = calloc(3, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->pLMNIdentity.size = 3;
	memcpy((void*) ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->pLMNIdentity.buf, (void*) plmn, 3);

	/*Item 1 -> Slice Support List*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array = calloc(1, sizeof(NGAP_SliceSupportItem_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.size = 1;
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.count = 1;

	/*Item 1 -> Slice Support List -> Item 1*/
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0] = calloc(1, sizeof(NGAP_SliceSupportItem_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	if((ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0]->s_NSSAI.sST.buf = calloc(1, sizeof(uint8_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0]->s_NSSAI.sST.size = 1;
	memcpy((void*) ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0]->s_NSSAI.sST.buf, (void*) sst, 1);

	ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count++;

	/*Encoding NGAP PDU via ASN.1 PER*/
	explicit_bzero(buf, sizeof(buf));
	ec = aper_encode_to_buffer(&asn_DEF_NGAP_NGAP_PDU, NULL, (void*) ngap->pdu, (void*) buf, MAX_BUF);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*NGAP PDU: ASN.1 PER encoding*/
	ngap->size = ec.encoded/8;
	ngap->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(ngap->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)ngap->enc, (void*)buf, (ec.encoded+7)/8);

	return ngap;
	
err:
	/*Free allocated container IEs*/
	if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array)
	{
		/*(1) AMF Name*/
		if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0])
		{
			if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.choice.AMFName.buf)
			{
				free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.choice.AMFName.buf);
			}
			free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]);
		}
		
		/*(2) Served GUAMI List*/
		if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1])
		{
			if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array)
			{
				/*Served GUAMI List Item 1*/
				if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0])
				{
					/*PLMN Identity*/
					if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.pLMNIdentity.buf)	
					{
						free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.pLMNIdentity.buf);
					}		

					/*AMF Region*/
					if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFRegionID.buf)
					{
						free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFRegionID.buf);
					}

					/*AMF Set ID*/
					if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFSetID.buf)
					{
						free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFSetID.buf);
					}
					
					/*AMF Pointer*/
					if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFPointer.buf)
					{
						free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]->gUAMI.aMFPointer.buf);
					}

					free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[0]);
				}
			
				free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array);
			}
		
			free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]);
		}

		/*(3) Relative AMF Capacity*/
		if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[2])
		{
			free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[2]);
		}

		/*(4) PLMN Support List*/
		if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3])
		{
			if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array)
			{
				/*PLMN Support List Item 1*/
				if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0])
				{
					/*PLMN PLMN Identity*/	
					if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->pLMNIdentity.buf)
					{
						free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->pLMNIdentity.buf);
					}
					
					/*Slice Support Liste*/
					if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array)
					{
						/*Slice List Support Item 1*/
						if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0])
						{
							if(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0]->s_NSSAI.sST.buf)
							{
								free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0]->s_NSSAI.sST.buf);
							}
							free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array[0]);
						}

						free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]->sliceSupportList.list.array);
					}
					
					free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[0]);
				}
			
				free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array);
			}

			free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]);
		}
				
		free(ngap->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array);
	}
	
	/*Free main data structures*/
	free(ngap->pdu->choice.successfulOutcome);
	free(ngap->pdu);
	free(ngap);
	
	return NULL;
}

/*
 * NGAP_NG_Setup_Failure - create NG Setup Failure message to response failure of interface initialization to the target gNB
 *
 * compliant with: 3GPP TS 38.413, 8.7.1
 *
 * @cause: Reason why an error occured (see 3GPP TS 38.413, 9.3.1.2).
 * @ttw: Time which the target gNB has to wait before sending its next NG Setup Request (see 3GPP TS 38.413, 9.3.1.56).
 * @diagnostics: Error indicator which IE/s was/were corrupt (see 3GPP TS 38.413, 9.3.1.3).
 */
ngapmsg_t*
NGAP_Setup_Failure(NGAP_Cause_t *cause, NGAP_TimeToWait_t *ttw, NGAP_CriticalityDiagnostics_t *diagnostics)
{
	/*Variables*/
	int i;
	uint8_t buf[MAX_BUF];
	asn_enc_rval_t ec = {0}; /*result of PER encoding*/

	ngapmsg_t *ngap = 0;

	/*Checking passed input parameters*/
	if(!cause)
	{
		printf("Input parameters are invalid!\n");
		return NULL;
	}

	/*Allocate memory for NGAP specific data structures*/
	if((ngap = (ngapmsg_t*) calloc(1, sizeof(ngapmsg_t))) == NULL || (ngap->pdu = (NGAP_NGAP_PDU_t*) calloc(1, sizeof(NGAP_NGAP_PDU_t))) == NULL || (ngap->pdu->choice.unsuccessfulOutcome = (NGAP_UnsuccessfulOutcome_t*) calloc(1, sizeof(NGAP_UnsuccessfulOutcome_t))) == NULL)
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

	/*Set NGAP PDU type to SuccessfulOutcome*/
	ngap->pdu->present = NGAP_NGAP_PDU_PR_unsuccessfulOutcome;

	/*Initialize NGAP InitiatingMessage*/
	ngap->pdu->choice.unsuccessfulOutcome->procedureCode = NGAP_ProcedureCode_id_NGSetup;
	ngap->pdu->choice.unsuccessfulOutcome->criticality = NGAP_Criticality_reject;
	ngap->pdu->choice.unsuccessfulOutcome->value.present = NGAP_UnsuccessfulOutcome__value_PR_NGSetupFailure;
	
	/*
	 * Allocation of memory and initialization of the NGAP IE container and its elements
	 *
	 * 3GPP TS 38.413, 9.2.6.3: The usage of 1 IE is mandatory (M). But: We use in best case all of them (3).
	 */
	MALLOC_IE(ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure, 3, NGAP_NGSetupFailureIEs_t)
	
	/*
	 * (1) Cause
	 */
	ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_Cause;
	ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->criticality = NGAP_Criticality_ignore;
	ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->value.present = NGAP_NGSetupFailureIEs__value_PR_Cause;

	memcpy((void*) &ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->value.choice.Cause, (void*) cause, sizeof(NGAP_Cause_t));

	ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count++;

	/*
	 * (2) Time to Wait
	 */
	if(ttw)
	{
		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_TimeToWait;
		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->criticality = NGAP_Criticality_ignore;
		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->value.present = NGAP_NGSetupFailureIEs__value_PR_TimeToWait;

		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->value.choice.TimeToWait = *ttw;
		
		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count++;
	}

	/*
	 * (3) Criticality Diagnostics
	 */
	if(diagnostics)
	{
		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->id = NGAP_ProtocolIE_ID_id_CriticalityDiagnostics;
		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->criticality = NGAP_Criticality_ignore;
		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->value.present = NGAP_NGSetupFailureIEs__value_PR_CriticalityDiagnostics;

		memcpy((void*) &ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count]->value.choice.CriticalityDiagnostics, (void*) diagnostics, sizeof(NGAP_CriticalityDiagnostics_t));

		ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.count++;
	}

	/*Encoding NGAP PDU via ASN.1 PER*/
	explicit_bzero(buf, sizeof(buf));
	ec = aper_encode_to_buffer(&asn_DEF_NGAP_NGAP_PDU, NULL, (void*) ngap->pdu, (void*) buf, MAX_BUF);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*NGAP PDU: ASN.1 PER encoding*/
	ngap->size = ec.encoded/8;
	ngap->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(ngap->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)ngap->enc, (void*)buf, (ec.encoded+7)/8);

	return ngap;

err:
	/*Free IE elements and its container*/
	if(ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array)
	{
		for(i = 0; i < ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.size; i++)
		{
			if(ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[i])
			{
				free(ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array[i]);
			}
		}
	
		free(ngap->pdu->choice.unsuccessfulOutcome->value.choice.NGSetupFailure.protocolIEs.list.array);
	}

	/*Free main data structures*/
	free(ngap->pdu->choice.unsuccessfulOutcome);
	free(ngap->pdu);
	free(ngap);

	return NULL;
}
