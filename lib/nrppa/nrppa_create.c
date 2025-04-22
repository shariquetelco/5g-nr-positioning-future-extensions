/*
 * Generation of a NRPPa PDU according to 3GPP TS 38.455 v18.1.0 (Release 18)
 *
 * created on: 05/28/2024, NK
 * last modified: 08/01/2024, NK
 */
#include "nrppa_create.h"

/*
 * NRPPa_ECID_Measurement_Initiation_Request - create a NRPPa PDU
 *
 * NGAP message type: NGAP Downlink UE Associated NRPPa Transport
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF UE Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @rtype: Report Type (0 = on demand, 1 = periodical, see 3GPP TS 38.455, 9.1.1.1)
 * @interval: Measurement periodicity, how often the gNB reports measurements (only, if @rtype = 1!, see include/nrppa/NRPPa_MeasurementPeriodicity.h)
 * @list: measurement quantities (mandatory)
 * @orat: measurement quatities for other RATs (optional)
 * @wlan: measurement quantities for WLAN (optional)
 * @intervalAoA: Measurement periodicity for NR AoA
 */
nrppamsg_t*
NRPPa_ECID_Measurement_Initiation_Request(long nrppaTID, long ue_id, long rtype, long interval, struct meas_quantity *list, struct meas_quantity *orat, struct meas_quantity *wlan, long intervalAoA)
{
	/*Variables*/
	int i;
	bool isAoA = false;
	
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	nrppamsg_t *nrppa = 0;

	/*Check input parameter*/
	if(rtype < 0 && rtype > 1)
	{
		printf("\nReport type must be 0 or 1!\n");
		goto err;
	}
	else if(!list)
	{
		printf("\nNo measurement quantity was passed!\n");
		goto err;
	}

	/*Allocate memory*/
	if((nrppa = (nrppamsg_t*) calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->pdu = (NRPPa_NRPPA_PDU_t*) calloc(1, sizeof(NRPPa_NRPPA_PDU_t))) == NULL || (nrppa->pdu->choice.initiatingMessage = (NRPPa_InitiatingMessage_t*) calloc(1, sizeof(NRPPa_InitiatingMessage_t))) == NULL)
	{
		if(nrppa && nrppa->pdu)
		{
			free(nrppa->pdu);
		}
		if(nrppa)
		{
			free(nrppa);
		}
		
		return NULL;
	}

	/*Set NRPPa PDU present flag*/
	nrppa->pdu->present = NRPPa_NRPPA_PDU_PR_initiatingMessage;

	/*Setting up the Initiating Message*/
	nrppa->pdu->choice.initiatingMessage->procedureCode = NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation;
	nrppa->pdu->choice.initiatingMessage->criticality = NRPPa_Criticality_reject; //reject, see 3GPP TS 38.455, 9.1.1.1
	nrppa->pdu->choice.initiatingMessage->nrppatransactionID = nrppaTID;
	nrppa->pdu->choice.initiatingMessage->value.present = NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementInitiationRequest;

	/*
	 * Set up IE of message container:
	 * According to 3GPP TS 38.455, 9.1.1.1: In the worst case, the container has to contain 7 IEs!
	 */
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array = calloc(7, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.size = 7;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count = 2; /*At least 2 IEs are mandatory*/

	/*(1) LMF UE Measurement ID*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[0]->value.present = NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID = ue_id;

	/*(2) Report Characteristics*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_ReportCharacteristics;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[1]->value.present = NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_ReportCharacteristics;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[1]->value.choice.ReportCharacteristics = rtype;

	/*(3) Measurement Periodicity => only if @rtype == 1*/
	if(rtype == NRPPa_ReportCharacteristics_periodic)
	{
		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[2] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count++;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[2]->id = NRPPa_ProtocolIE_ID_id_MeasurementPeriodicity;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[2]->criticality = NRPPa_Criticality_reject;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[2]->value.present = NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_MeasurementPeriodicity;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[2]->value.choice.MeasurementPeriodicity = interval;
	}

	/*
	 * (4) Measurement Quantities
	 *
	 * This is another IE container that includes at least one IE item. ;-)
	 *
	 * NOTE: According to 3GPP TS 38.455, clause 9.1.1.1, it is assumed that this IE is mandatory!
	 */
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementQuantities;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_MeasurementQuantities;

	/*
	 * Allocate memory for IEs of the container in the container :-)
	 *
	 * NOTE: Here, an object-oriented paradigm is used: struct NRPPa_ProtocolIE_Single_Container is a generic data structure. In this case, it is mapped to NRPPa_MeasurementQuantities_ItemIEs_t (see include/nrppa/NRPPa_ProtocolIE_Single_Container.h)
	 */
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.array = (NRPPa_MeasurementQuantities_ItemIEs_t**) calloc(list->count, sizeof(NRPPa_MeasurementQuantities_ItemIEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.size = list->count;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.count = list->count;
	for(i = 0; i < list->count; i++)
	{
		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.array[i] = (NRPPa_MeasurementQuantities_ItemIEs_t*) calloc(1, sizeof(NRPPa_MeasurementQuantities_ItemIEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.array[i]->id = NRPPa_ProtocolIE_ID_id_MeasurementQuantities_Item;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.array[i]->criticality = NRPPa_Criticality_reject;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.array[i]->value.present = NRPPa_MeasurementQuantities_ItemIEs__value_PR_MeasurementQuantities_Item;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementQuantities.list.array[i]->value.choice.MeasurementQuantities_Item.measurementQuantitiesValue = list->items[i];

		/*Checking if NR AoA has to be measured. In this case, measurement periodicity (7) has to be also transmitted.*/
		if(list->items[i] == NRPPa_MeasurementQuantitiesValue_angleOfArrivalNR)
		{
			isAoA = true;
		}
	}
	
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count++; /*here, increasing counter. Not earlier because then the array access would not work...*/

	/*(5) Other RAT Measurement Quantities*/
	if(orat)
	{
		/*Allocate memory for other RAT measurement quantities IE container*/
		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_OtherRATMeasurementQuantities;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_OtherRATMeasurementQuantities;

		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.array = (NRPPa_OtherRATMeasurementQuantities_ItemIEs_t**) calloc(orat->count, sizeof(NRPPa_OtherRATMeasurementQuantities_ItemIEs_t*))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.size = orat->count;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.count = orat->count;

		/*Other RAT IEs*/
		for(i = 0; i < orat->count; i++)
		{
			if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.array[i] = (NRPPa_OtherRATMeasurementQuantities_ItemIEs_t*) calloc(1, sizeof(NRPPa_OtherRATMeasurementQuantities_ItemIEs_t))) == NULL)
			{
				perror("calloc()");
				goto err;
			}
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.array[i]->id = NRPPa_ProtocolIE_ID_id_OtherRATMeasurementQuantities_Item;
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.array[i]->criticality = NRPPa_Criticality_reject;
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.array[i]->value.present = NRPPa_OtherRATMeasurementQuantities_ItemIEs__value_PR_OtherRATMeasurementQuantities_Item;
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.OtherRATMeasurementQuantities.list.array[i]->value.choice.OtherRATMeasurementQuantities_Item.otherRATMeasurementQuantitiesValue = orat->items[i];
		}

		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count++;
	}

	/*(6) WLAN Measurement Quantities*/
	if(wlan)
	{
		/*Allocate memory for WLAN measurement quantities IE container*/
		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_WLANMeasurementQuantities;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_WLANMeasurementQuantities;

		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.array = (NRPPa_WLANMeasurementQuantities_ItemIEs_t**) calloc(wlan->count, sizeof(NRPPa_WLANMeasurementQuantities_ItemIEs_t*))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.size = wlan->count;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.count = wlan->count;

		/*WLAN IEs*/
		for(i = 0; i < wlan->count; i++)
		{
			if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.array[i] = (NRPPa_WLANMeasurementQuantities_ItemIEs_t*) calloc(1, sizeof(NRPPa_WLANMeasurementQuantities_ItemIEs_t))) == NULL)
			{
				perror("calloc()");
				goto err;
			}
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.array[i]->id = NRPPa_ProtocolIE_ID_id_WLANMeasurementQuantities_Item;
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.array[i]->criticality = NRPPa_Criticality_reject;
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.array[i]->value.present = NRPPa_WLANMeasurementQuantities_ItemIEs__value_PR_WLANMeasurementQuantities_Item;
			nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.WLANMeasurementQuantities.list.array[i]->value.choice.WLANMeasurementQuantities_Item.wLANMeasurementQuantitiesValue = wlan->items[i];
		}

		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count++;
	}

	/*(7) NR AoA Measurement Periodicity*/
	if(rtype == 1 && isAoA)
	{
		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityNR_AoA;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationRequest_IEs__value_PR_MeasurementPeriodicityNR_AoA;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count]->value.choice.MeasurementPeriodicityNR_AoA = intervalAoA;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest.protocolIEs.list.count++;
	}

	/*Encoding NRPPa PDU via ASN.1 PER*/
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) nrppa->pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	nrppa->size = ec.encoded/8;
	nrppa->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(nrppa->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)nrppa->enc, (void*)tmp, (ec.encoded+7)/8);

	/*Free memory*/
	ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	nrppa->pdu = 0;

	return nrppa;

err:
	//TODO: Free memory if an error occur
	return NULL;
}

/*
 * NRPPa_ECID_Measurement_Initiation_Response - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF UE Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @ran_id: RAN UE Measurement ID 
 * @isOnDemand: identifier to decide if measurement results has to be included.
 * @ecid: E-CID measurement results (NOTE: Additional value has to allocated on the heap!)
 * @orat: Other RAT measurement results (NOTE: Additional values has to be allocated on the heap!)
 * @diagnostics: Criticality Diagnostics (see 3GPP TS 38.455, 9.2.2)
 * @wlan: WiFi measurement results (NOTE: Additional values has to be allocated on the heap!)
 * @cp_id: Cell Portion ID (see 3GPP TS 38.455, 9.2.12)
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 *
 * compliant with: 3GPP TS 38.455, 8.2.1
 */
nrppamsg_t*
NRPPa_ECID_Measurement_Initiation_Response(long nrppaTID, long ue_id, long ran_id, NRPPa_E_CID_MeasurementResult_t **ecid, NRPPa_CriticalityDiagnostics_t *diagnostics, NRPPa_OtherRATMeasurementResult_t **orat, NRPPa_WLANMeasurementResult_t **wlan, long *cp_id)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	nrppamsg_t *nrppa = 0;

	/*Allocate memory*/
	if((nrppa = (nrppamsg_t*) calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->pdu = (NRPPa_NRPPA_PDU_t*) calloc(1, sizeof(NRPPa_NRPPA_PDU_t))) == NULL || (nrppa->pdu->choice.successfulOutcome = (NRPPa_SuccessfulOutcome_t*) calloc(1, sizeof(NRPPa_SuccessfulOutcome_t))) == NULL)
	{
		if(nrppa && nrppa->pdu)
		{
			free(nrppa->pdu);
		}
		if(nrppa)
		{
			free(nrppa);
		}
		
		return NULL;
	}

	/*Set NRPPa PDU flag*/
	nrppa->pdu->present = NRPPa_NRPPA_PDU_PR_successfulOutcome;

	/*Setting up the Successful Outcome Message*/
	nrppa->pdu->choice.successfulOutcome->procedureCode = NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation;
	nrppa->pdu->choice.successfulOutcome->criticality = NRPPa_Criticality_reject; //reject, see 3GPP TS 38.455, 9.1.1.2
	nrppa->pdu->choice.successfulOutcome->nrppatransactionID = nrppaTID;
	nrppa->pdu->choice.successfulOutcome->value.present = NRPPa_SuccessfulOutcome__value_PR_E_CIDMeasurementInitiationResponse;

	/*
	 * Set up IE of message container:
	 * According to 3GPP TS 38.455, 9.1.1.2: The container contains at least 2 IEs. Depending on passed input parameter and occured errors a maximum of 7 IEs has to be included!
	 */
	if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array = calloc(7, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t*))) == NULL)
	{
		goto err;
	}
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.size = 7;
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count = 2;

	/*(1) LMF UE Measurement ID*/
	if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t))) == NULL)
	{
		goto err;
	}
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID;
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[0]->value.present = NRPPa_E_CIDMeasurementInitiationResponse_IEs__value_PR_UE_Measurement_ID;
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID = ue_id;

	/*(2) RAN UE Measurement ID*/
	if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t))) == NULL)
	{
		goto err;
	}
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_UE_Measurement_ID;
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[1]->value.present = NRPPa_E_CIDMeasurementInitiationResponse_IEs__value_PR_UE_Measurement_ID_1;
	nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[1]->value.choice.UE_Measurement_ID_1 = ran_id;

	/*
	 * (3) E-CID Measurement Result
	 * NOTE: Copying with memcpy(3) should be enough because references shall be allocated on the heap!
	 */
	if(ecid && *ecid)
	{
		if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t))) == NULL)
		{
			goto err;
		}

		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_E_CID_MeasurementResult;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationResponse_IEs__value_PR_E_CID_MeasurementResult;

		/*Copying memory*/
		memcpy(&nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.choice.E_CID_MeasurementResult, *ecid, sizeof(NRPPa_E_CID_MeasurementResult_t));

		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count++;
	}

	/*(4) Criticality Diagnostics*/
	if(diagnostics)
	{
		if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t))) == NULL)
		{
			goto err;
		}
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_CriticalityDiagnostics;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationResponse_IEs__value_PR_CriticalityDiagnostics;
		memcpy((void*)&nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.choice.CriticalityDiagnostics, (void*) diagnostics, sizeof(NRPPa_CriticalityDiagnostics_t));

		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count++;
	}

	/*(5) Cell Portion ID*/
	if(cp_id)
	{
		if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t))) == NULL)
		{
			goto err;
		}
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_Cell_Portion_ID;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationResponse_IEs__value_PR_Cell_Portion_ID;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.choice.Cell_Portion_ID = *cp_id;

		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count++;
	}

	/*(6) Other RAT measurement results*/
	if(orat && *orat)
	{
		if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t))) == NULL)
		{
			goto err;
		}
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_OtherRATMeasurementResult;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationResponse_IEs__value_PR_OtherRATMeasurementResult;
		memcpy((void*)&nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.choice.OtherRATMeasurementResult, (void*) *orat, sizeof(NRPPa_OtherRATMeasurementResult_t));

		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count++;
	}

	/*(7) WLAN measurement results*/
	if(wlan && *wlan)
	{
		if((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationResponse_IEs_t))) == NULL)
		{
			goto err;
		}
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_WLANMeasurementResult;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationResponse_IEs__value_PR_WLANMeasurementResult;
		memcpy((void*)&nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.array[nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count]->value.choice.WLANMeasurementResult, (void*) *wlan, sizeof(NRPPa_WLANMeasurementResult_t));

		nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count++;
	}

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) nrppa->pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	nrppa->size = ec.encoded/8;
	nrppa->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(nrppa->enc == NULL)
	{
		goto err;
	}
	memcpy((void*)nrppa->enc, (void*)tmp, (ec.encoded+7)/8);

	/*Free NRPPa PDU related memory recursively*/
	ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	nrppa->pdu = 0;

	/*Measurement Result IEs have been already freed by ASN_STRUCT_FREE*/
	if(ecid)
	{
		*ecid = 0;
	}

	if(orat)
	{
		*orat = 0;
	}

	if(wlan)
	{
		*wlan = 0;
	}

	return nrppa;

err:
	/*Decide, if passed measurement result IE will be freed within this function*/
	if(ecid && nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count > 2)
	{
		*ecid = 0;
	}
	else if(ecid && *ecid)
	{
		ASN_STRUCT_FREE(asn_DEF_NRPPa_E_CID_MeasurementResult, *ecid);
		*ecid = 0;
	}

	if(orat && ((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count > 3 && !diagnostics && !cp_id) || (nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count > 4 && diagnostics && !cp_id) || (nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count > 5 && diagnostics && cp_id)))
	{
		*orat = 0;
	}
	else if(orat && *orat)
	{
		ASN_STRUCT_FREE(asn_DEF_NRPPa_OtherRATMeasurementResult, *orat);
		*orat = 0;
	}

	if(wlan && ((nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count > 4 && !diagnostics && !cp_id) || (nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count > 5 && diagnostics && !cp_id) || (nrppa->pdu->choice.successfulOutcome->value.choice.E_CIDMeasurementInitiationResponse.protocolIEs.list.count > 6 && diagnostics && cp_id)))
	{
		*wlan = 0;
	}
	else if(wlan && *wlan)
	{
		ASN_STRUCT_FREE(asn_DEF_NRPPa_WLANMeasurementResult, *wlan);
		*wlan = 0;
	}

	if(nrppa && nrppa->pdu)
	{
		ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	}

	if(nrppa)
	{
		free(nrppa);
	}
		
	return NULL;
}

/*
 * NRPPa_ECID_Measurement_Initiation_Failure - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF UE Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @cause: Error Indicator (see 3GPP TS 38.455, 9.2.1)
 * @diagnostics: Criticality Diagnostics (see 3GPP TS 38.455, 9.2.2)
 *
 * return: NRPPa message structure reference
 */
nrppamsg_t *
NRPPa_ECID_Measurement_Initiation_Failure(long nrppaTID, long ue_id, NRPPa_Cause_t *cause, NRPPa_CriticalityDiagnostics_t *diagnostics)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX] = {0};
	int i;
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	nrppamsg_t *nrppa = 0;

	/*Allocate memory*/
	if((nrppa = (nrppamsg_t*) calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->pdu = (NRPPa_NRPPA_PDU_t*) calloc(1, sizeof(NRPPa_NRPPA_PDU_t))) == NULL || (nrppa->pdu->choice.unsuccessfulOutcome = (NRPPa_UnsuccessfulOutcome_t*) calloc(1, sizeof(NRPPa_UnsuccessfulOutcome_t))) == NULL)
	{
		if(nrppa && nrppa->pdu)
		{
			free(nrppa->pdu);
		}
		if(nrppa)
		{
			free(nrppa);
		}
		
		return NULL;
	}

	/*Set NRPPa PDU flag*/
	nrppa->pdu->present = NRPPa_NRPPA_PDU_PR_unsuccessfulOutcome;

	/*Setting up the Unsuccessful Outcome Message*/
	nrppa->pdu->choice.unsuccessfulOutcome->procedureCode = NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation;
	nrppa->pdu->choice.unsuccessfulOutcome->criticality = NRPPa_Criticality_reject; //reject, see 3GPP TS 38.455, 9.1.1.2
	nrppa->pdu->choice.unsuccessfulOutcome->nrppatransactionID = nrppaTID;
	nrppa->pdu->choice.unsuccessfulOutcome->value.present = NRPPa_UnsuccessfulOutcome__value_PR_E_CIDMeasurementInitiationFailure;

	/*
	 * Set up IE of message container:
	 * According to 3GPP TS 38.455, 9.1.1.3: The container contains at least 2 IEs. The maximum is 3 according to 3GPP TS 38.455, 9.1.1.3 .
	 */
	if((nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array = calloc(3, sizeof(NRPPa_E_CIDMeasurementInitiationFailure_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.size = 3;
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count = 2;

	/*(1) LMF UE Measurement ID*/
	if((nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationFailure_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID;
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[0]->value.present = NRPPa_E_CIDMeasurementInitiationFailure_IEs__value_PR_UE_Measurement_ID;
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID = ue_id;

	/*(2) Cause*/
	if(!cause)
	{
		printf("[NRPPa] Mandatory IE Cause is missing!\n");
		goto err;
	}
	if((nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationFailure_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_Cause;
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_ignore;
	nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[1]->value.present = NRPPa_E_CIDMeasurementInitiationFailure_IEs__value_PR_Cause;
	memcpy((void*)&nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[1]->value.choice.Cause, (void*) cause, sizeof(nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[1]->value.choice.Cause));

	/*(3) Criticality Diagnostics*/
	if(diagnostics)
	{
		if((nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementInitiationFailure_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_CriticalityDiagnostics;
		nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementInitiationFailure_IEs__value_PR_CriticalityDiagnostics;
		memcpy((void*)&nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count]->value.choice.CriticalityDiagnostics, (void*) diagnostics, sizeof(NRPPa_CriticalityDiagnostics_t));

		nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count++;
	}

	/*Encoding NRPPa PDU via ASN.1 PER*/
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) nrppa->pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	nrppa->size = ec.encoded/8;
	nrppa->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(nrppa->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)nrppa->enc, (void*)tmp, (ec.encoded+7)/8);

	/*Free memory*/
	ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	nrppa->pdu = 0;

	return nrppa;

err:
	/*Free memory*/
	if(nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array)
	{
		for(i = 0; i < nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.count; i++)
		{
			if(nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[i])
			{
				free(nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array[i]);
			}
		}
		free(nrppa->pdu->choice.unsuccessfulOutcome->value.choice.E_CIDMeasurementInitiationFailure.protocolIEs.list.array);
	}

	free(nrppa->pdu->choice.unsuccessfulOutcome);
	free(nrppa->pdu);
	free(nrppa);

	return NULL;
}

/*
 * NRPPa_ECID_Measurement_Failure_Indication - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF UE Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @ran_id: RAN UE Measurement ID (see 3GPP TS 38.401, )
 * @cause: Error Indicator (see 3GPP TS 38.455, 9.2.1)
 *
 * return: NRPPa message structure reference
 */
nrppamsg_t*
NRPPa_ECID_Measurement_Failure_Indication(long nrppaTID, long ue_id, long ran_id, NRPPa_Cause_t *cause)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX] = {0};
	int i;
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	nrppamsg_t *nrppa = 0;

	/*Check passed input parameter*/
	if(!cause)
	{
		return NULL;
	}

	/*Allocate memory*/
	if((nrppa = (nrppamsg_t*) calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->pdu = (NRPPa_NRPPA_PDU_t*) calloc(1, sizeof(NRPPa_NRPPA_PDU_t))) == NULL || (nrppa->pdu->choice.initiatingMessage = (NRPPa_InitiatingMessage_t*) calloc(1, sizeof(NRPPa_InitiatingMessage_t))) == NULL)
	{
		if(nrppa && nrppa->pdu)
		{
			free(nrppa->pdu);
		}
		if(nrppa)
		{
			free(nrppa);
		}
		
		return NULL;
	}

	/*Set NRPPa PDU present flag*/
	nrppa->pdu->present = NRPPa_NRPPA_PDU_PR_initiatingMessage;

	/*Setting up the Initiating Message*/
	nrppa->pdu->choice.initiatingMessage->procedureCode = NRPPa_ProcedureCode_id_e_CIDMeasurementFailureIndication;
	nrppa->pdu->choice.initiatingMessage->criticality = NRPPa_Criticality_ignore; //reject, see 3GPP TS 38.455, 9.1.1.4
	nrppa->pdu->choice.initiatingMessage->nrppatransactionID = nrppaTID;
	nrppa->pdu->choice.initiatingMessage->value.present = NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementFailureIndication;

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.1.4: The container always contains 3 IEs.
	 */
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array = calloc(3, sizeof(NRPPa_E_CIDMeasurementFailureIndication_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.size = 3;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.count = 3;

	/*(1) LMF UE Measurement ID*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_E_CIDMeasurementFailureIndication_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[0]->value.present = NRPPa_E_CIDMeasurementFailureIndication_IEs__value_PR_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID = ue_id;

	/*(2) RAN UE Measurement ID*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_E_CIDMeasurementFailureIndication_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[1]->value.present = NRPPa_E_CIDMeasurementFailureIndication_IEs__value_PR_UE_Measurement_ID_1;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[1]->value.choice.UE_Measurement_ID_1 = ran_id;

	/*(3) Cause*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[2] = calloc(1, sizeof(NRPPa_E_CIDMeasurementFailureIndication_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[2]->id = NRPPa_ProtocolIE_ID_id_Cause;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[2]->criticality = NRPPa_Criticality_ignore;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[2]->value.present = NRPPa_E_CIDMeasurementFailureIndication_IEs__value_PR_Cause;
	memcpy((void*)&nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[2]->value.choice.Cause, (void*) cause, sizeof(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[2]->value.choice.Cause));

	/*Encoding NRPPa PDU via ASN.1 PER*/
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) nrppa->pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	nrppa->size = ec.encoded/8;
	nrppa->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(nrppa->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)nrppa->enc, (void*)tmp, (ec.encoded+7)/8);

	/*Free memory*/
	ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	nrppa->pdu = 0;

	return nrppa;

err:
	/*Free memory*/
	if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array)
	{
		for(i = 0; i < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.count; i++)
		{
			if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[i])
			{
				free(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array[i]);
			}
		}
		free(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementFailureIndication.protocolIEs.list.array);
	}

	free(nrppa->pdu->choice.initiatingMessage);
	free(nrppa->pdu);
	free(nrppa);

	return NULL;
}

/*
 * NRPPa_ECID_Measurement_Report - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF UE Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @ran_id: RAN UE Measurement ID (see 3GPP TS 38.401, )
 * @ecid: E-CID measurement results (NOTE: Additional value has to allocated on the heap!)
 * @cp: Cell Portion ID (see 3GPP TS 38.455, 9.2.12)
 *
 * return: NRPPa message structure reference
 */
nrppamsg_t*
NRPPa_ECID_Measurement_Report(long nrppaTID, long ue_id, long ran_id,  NRPPa_E_CID_MeasurementResult_t **ecid, long *cp)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX] = {0};
	int i;
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	nrppamsg_t *nrppa = 0;

	/*Check passed input parameter*/
	if(!ecid || !ecid[0])
	{
		return NULL;
	}

	/*Allocate memory*/
	if((nrppa = (nrppamsg_t*) calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->pdu = (NRPPa_NRPPA_PDU_t*) calloc(1, sizeof(NRPPa_NRPPA_PDU_t))) == NULL || (nrppa->pdu->choice.initiatingMessage = (NRPPa_InitiatingMessage_t*) calloc(1, sizeof(NRPPa_InitiatingMessage_t))) == NULL)
	{
		if(nrppa && nrppa->pdu)
		{
			free(nrppa->pdu);
		}
		if(nrppa)
		{
			free(nrppa);
		}
		
		return NULL;
	}

	/*Set NRPPa PDU present flag*/
	nrppa->pdu->present = NRPPa_NRPPA_PDU_PR_initiatingMessage;

	/*Setting up the Initiating Message*/
	nrppa->pdu->choice.initiatingMessage->procedureCode = NRPPa_ProcedureCode_id_e_CIDMeasurementReport;
	nrppa->pdu->choice.initiatingMessage->criticality = NRPPa_Criticality_ignore; //reject, see 3GPP TS 38.455, 9.1.1.5
	nrppa->pdu->choice.initiatingMessage->nrppatransactionID = nrppaTID;
	nrppa->pdu->choice.initiatingMessage->value.present = NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementReport;

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.1.5: The container contains at least 3 IEs. The maximum is 4 IEs.
	 */
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array = calloc(4, sizeof(NRPPa_E_CIDMeasurementReport_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.size = 4;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count = 3;

	/*(1) LMF UE Measurement ID*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_E_CIDMeasurementReport_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[0]->value.present = NRPPa_E_CIDMeasurementReport_IEs__value_PR_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID = ue_id;

	/*(2) RAN UE Measurement ID*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_E_CIDMeasurementReport_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[1]->value.present = NRPPa_E_CIDMeasurementReport_IEs__value_PR_UE_Measurement_ID_1;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[1]->value.choice.UE_Measurement_ID_1 = ran_id;

	/*(3) E-CID Measurement Results*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[2] = calloc(1, sizeof(NRPPa_E_CIDMeasurementReport_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}

	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[2]->id = NRPPa_ProtocolIE_ID_id_E_CID_MeasurementResult;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[2]->criticality = NRPPa_Criticality_ignore;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[2]->value.present = NRPPa_E_CIDMeasurementReport_IEs__value_PR_E_CID_MeasurementResult;

	memcpy((void*)&nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[2]->value.choice.E_CID_MeasurementResult, (void*) *ecid, sizeof(NRPPa_E_CID_MeasurementResult_t));

	/*(4) Cell Portion ID*/
	if(cp)
	{
		if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_E_CIDMeasurementReport_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_Cell_Portion_ID;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count]->value.present = NRPPa_E_CIDMeasurementReport_IEs__value_PR_Cell_Portion_ID;
		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count]->value.choice.Cell_Portion_ID = *cp;

		nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count++;
	}

	/*Encoding NRPPa PDU via ASN.1 PER*/
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) nrppa->pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		printf("E-CID Measurement Report: aper_encode_to_buffer()\n");
		goto err;
	}

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	nrppa->size = ec.encoded/8;
	nrppa->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(nrppa->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)nrppa->enc, (void*)tmp, (ec.encoded+7)/8);

	/*Free memory*/
	ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	nrppa->pdu = 0;
	*ecid = 0;

	return nrppa;

err:
	/*Free memory*/
	if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array)
	{
		for(i = 0; i < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count; i++)
		{
			if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[i])
			{
				free(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[i]);
			}
		}
		free(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array);
	}

	free(nrppa->pdu->choice.initiatingMessage);
	free(nrppa->pdu);
	free(nrppa);

	return NULL;
}

/*
 * NRPPa_ECID_Measurement_Termination - create a NRPPa PDU
 *
 * NGAP message type: NGAP Downlink UE Associated NRPPa Transport
 *
 * Direction: LMF -> gNB via AMF
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF UE Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @ran_id: RAN UE Measurement ID (see 3GPP TS 38.401, )
 *
 * return: NRPPa message structure reference
 */
nrppamsg_t*
NRPPa_ECID_Measurement_Termination(long nrppaTID, long ue_id, long ran_id)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX] = {0};
	int i;
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	nrppamsg_t *nrppa = 0;

	/*Allocate memory*/
	if((nrppa = (nrppamsg_t*) calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->pdu = (NRPPa_NRPPA_PDU_t*) calloc(1, sizeof(NRPPa_NRPPA_PDU_t))) == NULL || (nrppa->pdu->choice.initiatingMessage = (NRPPa_InitiatingMessage_t*) calloc(1, sizeof(NRPPa_InitiatingMessage_t))) == NULL)
	{
		if(nrppa && nrppa->pdu)
		{
			free(nrppa->pdu);
		}
		if(nrppa)
		{
			free(nrppa);
		}
		
		return NULL;
	}

	/*Set NRPPa PDU present flag*/
	nrppa->pdu->present = NRPPa_NRPPA_PDU_PR_initiatingMessage;

	/*Setting up the Initiating Message*/
	nrppa->pdu->choice.initiatingMessage->procedureCode = NRPPa_ProcedureCode_id_e_CIDMeasurementTermination;
	nrppa->pdu->choice.initiatingMessage->criticality = NRPPa_Criticality_reject; //reject, see 3GPP TS 38.455, 9.1.1.6
	nrppa->pdu->choice.initiatingMessage->nrppatransactionID = nrppaTID;
	nrppa->pdu->choice.initiatingMessage->value.present = NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementTerminationCommand;

	/*
	 * Set up IE of message container:
	 * According to 3GPP TS 38.455, 9.1.1.6: The container always contains 2 IEs.
	 */
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array = calloc(2, sizeof(NRPPa_E_CIDMeasurementTerminationCommand_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.size = 2;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.count = 2;

	/*(1) LMF UE Measurement ID*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_E_CIDMeasurementTerminationCommand_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->value.present = NRPPa_E_CIDMeasurementTerminationCommand_IEs__value_PR_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID = ue_id;

	/*(2) RAN UE Measurement ID*/
	if((nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_E_CIDMeasurementTerminationCommand_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_UE_Measurement_ID;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->value.present = NRPPa_E_CIDMeasurementTerminationCommand_IEs__value_PR_UE_Measurement_ID_1;
	nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[1]->value.choice.UE_Measurement_ID_1 = ran_id;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) nrppa->pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	nrppa->size = ec.encoded/8;
	nrppa->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(nrppa->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)nrppa->enc, (void*)tmp, (ec.encoded+7)/8);

	/*Free memory*/
	ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	nrppa->pdu = 0;

	return nrppa;

err:
	/*Free memory*/
	if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array)
	{
		for(i = 0; i < nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.count; i++)
		{
			if(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[i])
			{
				free(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array[i]);
			}
		}
		free(nrppa->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementTerminationCommand.protocolIEs.list.array);
	}

	free(nrppa->pdu->choice.initiatingMessage);
	free(nrppa->pdu);
	free(nrppa);

	return NULL;
}

/*
 * NRPPa_Error_Indication - create a NRPPa PDU for error detection cases
 *
 * Direction: LMF -> gNB via AMF or vise versa
 * Caller: LMF or gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @cause: Error Indicator (see 3GPP TS 38.455, 9.2.1)
 * @diagnostics: Criticality Diagnostics (see 3GPP TS 38.455, 9.2.2)
 *
 * return: NRPPa message structure reference
 */
nrppamsg_t *
NRPPa_Error_Indication(long nrppaTID, NRPPa_Cause_t *cause, NRPPa_CriticalityDiagnostics_t *diagnostics)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX] = {0};
	int i;
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	nrppamsg_t *nrppa = 0;

	/*Check passed parameter*/
	if(!cause && !diagnostics)
	{
		return NULL;
	}

	/*Allocate memory*/
	if((nrppa = (nrppamsg_t*) calloc(1, sizeof(nrppamsg_t))) == NULL || (nrppa->pdu = (NRPPa_NRPPA_PDU_t*) calloc(1, sizeof(NRPPa_NRPPA_PDU_t))) == NULL || (nrppa->pdu->choice.initiatingMessage = (NRPPa_InitiatingMessage_t*) calloc(1, sizeof(NRPPa_InitiatingMessage_t))) == NULL)
	{
		if(nrppa && nrppa->pdu)
		{
			free(nrppa->pdu);
		}
		if(nrppa)
		{
			free(nrppa);
		}
		
		return NULL;
	}

	/*Set NRPPa PDU present flag*/
	nrppa->pdu->present = NRPPa_NRPPA_PDU_PR_initiatingMessage;

	/*Setting up the Initiating Message*/
	nrppa->pdu->choice.initiatingMessage->procedureCode = NRPPa_ProcedureCode_id_errorIndication;
	nrppa->pdu->choice.initiatingMessage->criticality = NRPPa_Criticality_ignore; //ignore, see 3GPP TS 38.455, 9.1.2.1
	nrppa->pdu->choice.initiatingMessage->nrppatransactionID = nrppaTID;
	nrppa->pdu->choice.initiatingMessage->value.present = NRPPa_InitiatingMessage__value_PR_ErrorIndication;

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 8.3.1: The container shall contain at least 1 IE. The maximum is 2.
	 */
	if((nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array = calloc(2, sizeof(NRPPa_ErrorIndication_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.size = 2;
	nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count = 0;

	/*(1) Cause*/
	if(cause)
	{
		if((nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_ErrorIndication_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_Cause;
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[0]->value.present = NRPPa_ErrorIndication_IEs__value_PR_Cause;
		memcpy((void*)&nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[0]->value.choice.Cause, (void*) cause, sizeof(nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[0]->value.choice.Cause));
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count++;
	}
	
	/*(2) Criticality Diagnostics*/
	if(diagnostics)
	{
		if((nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_ErrorIndication_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_CriticalityDiagnostics;
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count]->value.present = NRPPa_ErrorIndication_IEs__value_PR_CriticalityDiagnostics;
		memcpy((void*)&nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count]->value.choice.CriticalityDiagnostics, (void*) diagnostics, sizeof(NRPPa_CriticalityDiagnostics_t));
		nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count++;
	}

	/*Encoding NRPPa PDU via ASN.1 PER*/
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) nrppa->pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	nrppa->size = ec.encoded/8;
	nrppa->enc = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(nrppa->enc == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)nrppa->enc, (void*)tmp, (ec.encoded+7)/8);

	/*Free memory*/
	ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, nrppa->pdu);
	nrppa->pdu = 0;

	return nrppa;

err:
	/*Free allocated memory*/
	if(nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array)
	{
		for(i = 0; i < nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.count; i++)
		{
			if(nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[i])
			{
				free(nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array[i]);
			}
		}
		free(nrppa->pdu->choice.initiatingMessage->value.choice.ErrorIndication.protocolIEs.list.array);
	}

	free(nrppa->pdu->choice.initiatingMessage);
	free(nrppa->pdu);
	free(nrppa);

	return NULL;
}

/*
 * NRPPa_Assistance_Information_Control - create a NRPPa PDU
 *
 * NGAP message type: Downlink Non UE Associated
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @info: assistance information (see 3GPP TS 38.455, 9.2.19)
 * @bcast: option to start or stop broadcasting
 * @cells: target cells that are requested (see 3GPP TS 38.455, 9.2.59)
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Assistance_Information_Control(long nrppaTID, NRPPa_Assistance_Information_t *info, NRPPa_Broadcast_t *bcast, NRPPa_PositioningBroadcastCells_t *cells, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_InitiatingMessage_t msg;
	NRPPa_AssistanceInformationControl_t container;
	
	/*Checking Inputs for IE creation: 3GPP TS 38.455, 8.4.1.3*/
	if(!info && !bcast)
	{
		printf("[NRPPa] Assistance Information Control procedure: Missing IEs for PDU creation!\n");
		goto err;
	}

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 8.4.1.3: The container shall contain at least 1 IE. The maximum is 3.
	 */
	if((container.protocolIEs.list.array = calloc(3, sizeof(NRPPa_AssistanceInformationControl_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 3;
	container.protocolIEs.list.count = 0;
	
	/*(1) Assistance Information*/
	if(info)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_AssistanceInformationControl_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_Assistance_Information;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_AssistanceInformationControl_IEs__value_PR_Assistance_Information;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.Assistance_Information, (void*) info, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.Assistance_Information));

		container.protocolIEs.list.count++;
	}

	/*(2) Broadcast*/
	if(bcast)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_AssistanceInformationControl_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_Broadcast;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_AssistanceInformationControl_IEs__value_PR_Broadcast;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.Broadcast, (void*) bcast, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.Broadcast));

		container.protocolIEs.list.count++;
	}

	/*(3) Positioning Broadcast Cells*/
	if(cells)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_AssistanceInformationControl_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_PositioningBroadcastCells;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_AssistanceInformationControl_IEs__value_PR_PositioningBroadcastCells;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.PositioningBroadcastCells, (void*) cells, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.PositioningBroadcastCells));

		container.protocolIEs.list.count++;
	}

	/*Setting up the Initiating Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_assistanceInformationControl;
	msg.criticality = NRPPa_Criticality_reject; //ignore, see 3GPP TS 38.455, 9.1.3.1
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_InitiatingMessage__value_PR_AssistanceInformationControl;
	msg.value.choice.AssistanceInformationControl = container;
	
	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_initiatingMessage;
	pdu.choice.initiatingMessage = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * NRPPa_Assistance_Information_Feedback - create a NRPPa PDU
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @flist: assistance information list with cell errors (see 3GPP TS 38.455, 9.2.23)
 * @cells: target cells that are requested (see 3GPP TS 38.455, 9.2.59)
 * @diagnostics: Criticality Diagnostics (see 3GPP TS 38.455, 9.2.2)
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Assistance_Information_Feedback(long nrppaTID, NRPPa_AssistanceInformationFailureList_t *flist, NRPPa_PositioningBroadcastCells_t *cells, NRPPa_CriticalityDiagnostics_t *diagnostics, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_InitiatingMessage_t msg;
	NRPPa_AssistanceInformationFeedback_t container;

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 8.4.2.2: The container do not has to contain an IE. The maximum is 3.
	 */
	if((container.protocolIEs.list.array = calloc(3, sizeof(NRPPa_AssistanceInformationFeedback_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 3;
	container.protocolIEs.list.count = 0;
	
	/*(1) Assistance Information Failure List*/
	if(flist)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_AssistanceInformationFeedback_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_AssistanceInformationFailureList;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_AssistanceInformationFeedback_IEs__value_PR_AssistanceInformationFailureList;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.AssistanceInformationFailureList, (void*) flist, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.AssistanceInformationFailureList));

		container.protocolIEs.list.count++;
	}

	/*(2) Positioning Broadcast Cells*/
	if(cells)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_AssistanceInformationFeedback_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_PositioningBroadcastCells;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_AssistanceInformationFeedback_IEs__value_PR_PositioningBroadcastCells;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.PositioningBroadcastCells, (void*) cells, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.PositioningBroadcastCells));

		container.protocolIEs.list.count++;
	}

	/*(3) Criticality Diagnostics*/
	if(diagnostics)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_AssistanceInformationFeedback_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_CriticalityDiagnostics;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_AssistanceInformationFeedback_IEs__value_PR_CriticalityDiagnostics;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.CriticalityDiagnostics, (void*) diagnostics, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.CriticalityDiagnostics));

		container.protocolIEs.list.count++;
	}

	/*Setting up the Initiating Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_assistanceInformationFeedback;
	msg.criticality = NRPPa_Criticality_reject;
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_InitiatingMessage__value_PR_AssistanceInformationFeedback;
	msg.value.choice.AssistanceInformationFeedback = container;
		
	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_initiatingMessage;
	pdu.choice.initiatingMessage = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * NRPPa_Measurement_Request - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Downlink Non UE Associated
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF Measurement ID
 * @tlist: TRP Measurement Request List
 * @rtype: Report Characteristics type
 * @mp: Measurement periodicity
 * @tq: TRP Measurement Quantities
 * @sfn: SFN Initialisation Time
 * @sconf: SRS Configuration
 * @inforeq: Measurement Beam Information Request
 * @sfrnum: System Frame Number
 * @slot: Slot Number
 * @mpext: Measurement Periodicity extended
 * @tresp: Response time
 * @mcind: Measurement Characteristics Request Indicator
 * @mto: Measurement Time Occasion
 * @mtimes: Measurement Amount
 * @twlist: Time Window Information Measurement List
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Measurement_Request(long nrppaTID, long ue_id, NRPPa_TRP_MeasurementRequestList_t *tlist, 
						  long rtype, NRPPa_MeasurementPeriodicity_t mp, NRPPa_TRPMeasurementQuantities_t *tq, NRPPa_RelativeTime1900_t *sfn,
						  NRPPa_SRSConfiguration_t *sconf, NRPPa_MeasurementBeamInfoRequest_t *inforeq, NRPPa_SystemFrameNumber_t *sfrnum,
						  NRPPa_SlotNumber_t *slot, NRPPa_MeasurementPeriodicityExtended_t mpext, NRPPa_ResponseTime_t *tresp,
						  NRPPa_MeasurementCharacteristicsRequestIndicator_t *mcind, NRPPa_MeasurementTimeOccasion_t *mto,
						  NRPPa_MeasurementAmount_t *mtimes, NRPPa_TimeWindowInformation_Measurement_List_t *twlist, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_InitiatingMessage_t msg;
	NRPPa_MeasurementRequest_t container;

	/*Checking passed input parameter*/
	if(!tlist || !tq)
	{
		printf("[NRPPa] Error in passed IEs for creation of Measurement Request!\n");
		goto err;
	}

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.4.1: The container contains a maximum of 16 IEs.
	 */
	if((container.protocolIEs.list.array = calloc(16, sizeof(NRPPa_MeasurementRequest_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 16;
	container.protocolIEs.list.count = 1;

	/*(1) LMF Measurement ID*/
	if((container.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_Measurement_ID;
	container.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[0]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_Measurement_ID;
	container.protocolIEs.list.array[0]->value.choice.Measurement_ID = ue_id;

	/*(2) TRP Measurement Request List*/
	if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_TRP_MeasurementRequestList;
	container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_TRP_MeasurementRequestList;
	memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.TRP_MeasurementRequestList, (void*) tlist, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.TRP_MeasurementRequestList));

	container.protocolIEs.list.count++;

	/*(3) Report Characteristics*/
	if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_ReportCharacteristics;
	container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_ReportCharacteristics;
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.ReportCharacteristics = rtype; //TODO: Checking value boundaries is currently missing!

	container.protocolIEs.list.count++;

	/*(4) Measurement Periodicity*/
	if(rtype == NRPPa_ReportCharacteristics_periodic)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementPeriodicity;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_MeasurementPeriodicity;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementPeriodicity = mp; //TODO: Checking value boundaries is currently missing!

		container.protocolIEs.list.count++;
	}

	/*(5) TRP Measurement Quantities*/
	if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementQuantities;
	container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_TRPMeasurementQuantities;
	memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.TRPMeasurementQuantities, (void*) tq, sizeof(container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.TRPMeasurementQuantities));

	container.protocolIEs.list.count++;

	/*(6) SFN Initialisation Time*/
	if(sfn)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_SFNInitialisationTime;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_RelativeTime1900;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.RelativeTime1900, (void*) sfn, sizeof(NRPPa_RelativeTime1900_t));
	
		container.protocolIEs.list.count++;
	}

	/*(7) SRS Configuration*/
	if(sconf)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_SRSConfiguration;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_SRSConfiguration;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.SRSConfiguration, (void*) sconf, sizeof(NRPPa_SRSConfiguration_t));
	
		container.protocolIEs.list.count++;
	}

	/*(8) Measurement Beam Information Request*/
	if(inforeq)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementBeamInfoRequest;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_MeasurementBeamInfoRequest;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementBeamInfoRequest = *inforeq; //TODO: Checking value boundaries is currently missing!

		container.protocolIEs.list.count++;
	}

	/*(9) System Frame Number*/
	if(sfrnum)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_SystemFrameNumber;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_SystemFrameNumber;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementBeamInfoRequest = *sfrnum; //TODO: Checking value boundaries is currently missing!

		container.protocolIEs.list.count++;
	}

	/*(10) Slot Number*/
	if(slot)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_SlotNumber;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_SlotNumber;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementBeamInfoRequest = *slot; //TODO: Checking value boundaries is currently missing!

		container.protocolIEs.list.count++;
	}

	/*(11) Measurement Periodicity Extended*/
	if(mp == NRPPa_MeasurementPeriodicity_extended)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementPeriodicityExtended;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_MeasurementPeriodicityExtended;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementPeriodicityExtended = mpext; //TODO: Checking value boundaries is currently missing!

		container.protocolIEs.list.count++;
	}

	/*(12) Response Time*/
	if(tresp && rtype == NRPPa_ReportCharacteristics_onDemand)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_ResponseTime;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_ResponseTime;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.ResponseTime, (void*) tresp, sizeof(NRPPa_ResponseTime_t));
	
		container.protocolIEs.list.count++;
	}

	/*(13) Measurement Characteristics Request Indicator*/
	if(mcind)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementCharacteristicsRequestIndicator;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_MeasurementCharacteristicsRequestIndicator;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementCharacteristicsRequestIndicator, (void*) mcind, sizeof(NRPPa_MeasurementCharacteristicsRequestIndicator_t));
	
		container.protocolIEs.list.count++;
	}

	/*(14) Measurement Time Occasion*/
	if(mto)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementTimeOccasion;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_MeasurementTimeOccasion;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementTimeOccasion, (void*) mto, sizeof(NRPPa_MeasurementTimeOccasion_t));
	
		container.protocolIEs.list.count++;
	}

	/*(15) Measurement Amount*/
	if(rtype == NRPPa_ReportCharacteristics_periodic && mtimes)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_MeasurementAmount;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_MeasurementAmount;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.MeasurementAmount = *mtimes; //TODO: Checking value boundaries is currently missing!

		container.protocolIEs.list.count++;
	}

	/*(16) Time Window Information Measurement List*/
	if(twlist)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementRequest_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_TimeWindowInformation_Measurement_List;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementRequest_IEs__value_PR_TimeWindowInformation_Measurement_List;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.TimeWindowInformation_Measurement_List, (void*) twlist, sizeof(NRPPa_TimeWindowInformation_Measurement_List_t));
	
		container.protocolIEs.list.count++;
	}

	/*Setting up the Initiating Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_Measurement;
	msg.criticality = NRPPa_Criticality_reject;
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_InitiatingMessage__value_PR_MeasurementRequest;
	msg.value.choice.MeasurementRequest = container;
		
	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_initiatingMessage;
	pdu.choice.initiatingMessage = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * NRPPa_Measurement_Response - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @ran_id: RAN Measurement ID 
 * @isOnDemand: identifier to decide if measurement results has to be included.
 * @tlist: TRP Measurement Response List
 * @diagnostics: Criticality Diagnostics (see 3GPP TS 38.455, 9.2.2)
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Measurement_Response(long nrppaTID, long ue_id, long ran_id, bool isOnDemand, NRPPa_TRP_MeasurementResponseList_t *tlist, NRPPa_CriticalityDiagnostics_t *diagnostics, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_SuccessfulOutcome_t msg;
	NRPPa_MeasurementResponse_t container;

	/*Checking passed input parameter*/
	if(isOnDemand && !tlist)
	{
		printf("[NRPPa] TRP Measurement Response List is exepected but the IE is missing!\n");
		goto err;
	}

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.4.2: The container contains at least 2 IEs. The maximum is 4 IEs.
	 */
	if((container.protocolIEs.list.array = calloc(4, sizeof(NRPPa_MeasurementResponse_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 4;
	container.protocolIEs.list.count = 2;

	/*(1) LMF Measurement ID*/
	if((container.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_MeasurementResponse_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_Measurement_ID;
	container.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[0]->value.present = NRPPa_MeasurementResponse_IEs__value_PR_Measurement_ID;
	container.protocolIEs.list.array[0]->value.choice.Measurement_ID = ue_id;

	/*(2) RAN Measurement ID*/
	if((container.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_MeasurementResponse_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_Measurement_ID;
	container.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[1]->value.present = NRPPa_MeasurementResponse_IEs__value_PR_Measurement_ID_1;
	container.protocolIEs.list.array[1]->value.choice.Measurement_ID_1 = ran_id;

	/*(3) TRP Measurement Response List*/
	if(isOnDemand)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementResponse_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_TRP_MeasurementResponseList;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_reject;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementResponse_IEs__value_PR_TRP_MeasurementResponseList;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.TRP_MeasurementResponseList, (void*) tlist, sizeof(NRPPa_TRP_MeasurementResponseList_t));
	
		container.protocolIEs.list.count++;
	}

	/*(4) Criticality Diagnostics*/
	if(diagnostics)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementResponse_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_CriticalityDiagnostics;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementResponse_IEs__value_PR_CriticalityDiagnostics;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.CriticalityDiagnostics, (void*) diagnostics, sizeof(NRPPa_CriticalityDiagnostics_t));
	
		container.protocolIEs.list.count++;
	}

	/*Setting up the SuccessfulOutcome Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_Measurement;
	msg.criticality = NRPPa_Criticality_reject;
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_SuccessfulOutcome__value_PR_MeasurementResponse;
	msg.value.choice.MeasurementResponse = container;
		
	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_successfulOutcome;
	pdu.choice.successfulOutcome = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * NRPPa_Measurement_Failure - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @cause: Error Indicator (see 3GPP TS 38.455, 9.2.1)
 * @diagnostics: Criticality Diagnostics (see 3GPP TS 38.455, 9.2.2)
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Measurement_Failure(long nrppaTID, long ue_id, NRPPa_Cause_t *cause, NRPPa_CriticalityDiagnostics_t *diagnostics, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_UnsuccessfulOutcome_t msg;
	NRPPa_MeasurementFailure_t container;

	/*Checking passed input parameter*/
	if(!cause)
	{
		printf("[NRPPa] Missing mandatory Cause IE for creation of NRPPa Measurement Failure message!\n");
		goto err;
	}

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.4.3: The container contains at least 2 IEs. The maximum is 3 IEs.
	 */
	if((container.protocolIEs.list.array = calloc(3, sizeof(NRPPa_MeasurementFailure_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 3;
	container.protocolIEs.list.count = 2;

	/*(1) LMF Measurement ID*/
	if((container.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_MeasurementFailure_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_Measurement_ID;
	container.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[0]->value.present = NRPPa_MeasurementFailure_IEs__value_PR_Measurement_ID;
	container.protocolIEs.list.array[0]->value.choice.Measurement_ID = ue_id;

	/*(2) Cause*/
	if((container.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_MeasurementFailure_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_Cause;
	container.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_ignore;
	container.protocolIEs.list.array[1]->value.present = NRPPa_MeasurementFailure_IEs__value_PR_Cause;
	memcpy((void*)&container.protocolIEs.list.array[1]->value.choice.Cause, (void*) cause, sizeof(NRPPa_Cause_t));

	/*(3) Criticality Diagnostics*/
	if(diagnostics)
	{
		if((container.protocolIEs.list.array[container.protocolIEs.list.count] = calloc(1, sizeof(NRPPa_MeasurementFailure_IEs_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		container.protocolIEs.list.array[container.protocolIEs.list.count]->id = NRPPa_ProtocolIE_ID_id_CriticalityDiagnostics;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->criticality = NRPPa_Criticality_ignore;
		container.protocolIEs.list.array[container.protocolIEs.list.count]->value.present = NRPPa_MeasurementFailure_IEs__value_PR_CriticalityDiagnostics;
		memcpy((void*)&container.protocolIEs.list.array[container.protocolIEs.list.count]->value.choice.CriticalityDiagnostics, (void*) diagnostics, sizeof(NRPPa_CriticalityDiagnostics_t));
	
		container.protocolIEs.list.count++;
	}

	/*Setting up the UnsuccessfulOutcome Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_Measurement;
	msg.criticality = NRPPa_Criticality_reject;
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_UnsuccessfulOutcome__value_PR_MeasurementFailure;
	msg.value.choice.MeasurementFailure = container;
		
	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_unsuccessfulOutcome;
	pdu.choice.unsuccessfulOutcome = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * NRPPa_Measurement_Report - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @lmf_id: LMF Measurement ID (see 3GPP TS 38.455, 9.1.1.1)
 * @ran_id: RAN Measurement ID 
 * @tlist: TRP Measurement Response List
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Measurement_Report(long nrppaTID, long lmf_id, long ran_id, NRPPa_TRP_MeasurementResponseList_t *tlist, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_InitiatingMessage_t msg;
	NRPPa_MeasurementReport_t container;

	/*Checking passed input parameter*/
	if(!tlist)
	{
		printf("[NRPPa] Missing IE for NRPPa Measurement Report message!\n");
		goto err;
	}

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.4.4: The container always contains 3 IEs.
	 */
	if((container.protocolIEs.list.array = calloc(3, sizeof(NRPPa_MeasurementReport_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 3;
	container.protocolIEs.list.count = 3;

	/*(1) LMF Measurement ID*/
	if((container.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_MeasurementReport_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_Measurement_ID;
	container.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[0]->value.present = NRPPa_MeasurementReport_IEs__value_PR_Measurement_ID;
	container.protocolIEs.list.array[0]->value.choice.Measurement_ID = lmf_id;

	/*(2) RAN Measurement ID*/
	if((container.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_MeasurementReport_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_Measurement_ID;
	container.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[1]->value.present = NRPPa_MeasurementReport_IEs__value_PR_Measurement_ID_1;
	container.protocolIEs.list.array[1]->value.choice.Measurement_ID_1 = ran_id;

	/*(3) TRP Measurement Response List*/
	if((container.protocolIEs.list.array[2] = calloc(1, sizeof(NRPPa_MeasurementReport_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[2]->id = NRPPa_ProtocolIE_ID_id_TRP_MeasurementResponseList;
	container.protocolIEs.list.array[2]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[2]->value.present = NRPPa_MeasurementReport_IEs__value_PR_TRP_MeasurementResponseList;
	memcpy((void*)&container.protocolIEs.list.array[2]->value.choice.TRP_MeasurementResponseList, (void*) tlist, sizeof(NRPPa_TRP_MeasurementResponseList_t));

	/*Setting up the Initiating Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_MeasurementReport;
	msg.criticality = NRPPa_Criticality_ignore;
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_InitiatingMessage__value_PR_MeasurementReport;
	msg.value.choice.MeasurementReport = container;
		
	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_initiatingMessage;
	pdu.choice.initiatingMessage = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * NRPPa_Measurement_Abort - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Downlink Non UE Associated
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @ue_id: LMF Measurement ID
 * @ran_id: RAN Measurement ID
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Measurement_Abort(long nrppaTID, long ue_id, long ran_id, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_InitiatingMessage_t msg;
	NRPPa_MeasurementAbort_t container;

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.4.6: The container always contains 2 IEs.
	 */
	if((container.protocolIEs.list.array = calloc(2, sizeof(NRPPa_MeasurementAbort_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 2;
	container.protocolIEs.list.count = 2;

	/*(1) LMF Measurement ID*/
	if((container.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_MeasurementAbort_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_Measurement_ID;
	container.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[0]->value.present = NRPPa_MeasurementAbort_IEs__value_PR_Measurement_ID;
	container.protocolIEs.list.array[0]->value.choice.Measurement_ID = ue_id;

	/*(2) RAN Measurement ID*/
	if((container.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_MeasurementAbort_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_Measurement_ID;
	container.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[1]->value.present = NRPPa_MeasurementAbort_IEs__value_PR_Measurement_ID_1;
	container.protocolIEs.list.array[1]->value.choice.Measurement_ID_1 = ran_id;

	/*Setting up the Initiating Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_MeasurementAbort;
	msg.criticality = NRPPa_Criticality_ignore;
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_InitiatingMessage__value_PR_MeasurementAbort;
	msg.value.choice.MeasurementAbort = container;
		
	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_initiatingMessage;
	pdu.choice.initiatingMessage = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * NRPPa_Measurement_Failure_Indication - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * @nrppaTID: NRPPa Transaction ID (see 3GPP TS 38.455, 9.2.4)
 * @lmf_id: LMF Measurement ID
 * @ran_id: RAN Measurement ID
 * @cause: Error Indicator (see 3GPP TS 38.455, 9.2.1)
 * @buf: pointer to target PER encoded PDU
 * @length: size [B] of @buf
 */
void
NRPPa_Measurement_Failure_Indication(long nrppaTID, long lmf_id, long ran_id, NRPPa_Cause_t *cause, uint8_t **buf, size_t *length)
{
	/*Variables*/
	uint8_t tmp[BUF_MAX];
	asn_enc_rval_t ec = {0}; /*result of ASN.1 PER encoding*/

	NRPPa_NRPPA_PDU_t pdu;
	NRPPa_InitiatingMessage_t msg;
	NRPPa_MeasurementFailureIndication_t container;

	/*Initialize data structures*/
	explicit_bzero(&pdu, sizeof(pdu));
	explicit_bzero(&msg, sizeof(msg));
	explicit_bzero(&container, sizeof(container));

	/*Checking passed input parameters*/
	if(!cause)
	{
		printf("[NRPPa] Missing IE for NRPPa Measurement Failure Indication message!\n");
		goto err;
	}

	/*
	 * Set up IEs of message container:
	 * According to 3GPP TS 38.455, 9.1.4.7: The container always contains 3 IEs.
	 */
	if((container.protocolIEs.list.array = calloc(3, sizeof(NRPPa_MeasurementFailureIndication_IEs_t*))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.size = 3;
	container.protocolIEs.list.count = 3;

	/*(1) LMF Measurement ID*/
	if((container.protocolIEs.list.array[0] = calloc(1, sizeof(NRPPa_MeasurementFailureIndication_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[0]->id = NRPPa_ProtocolIE_ID_id_LMF_Measurement_ID;
	container.protocolIEs.list.array[0]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[0]->value.present = NRPPa_MeasurementFailureIndication_IEs__value_PR_Measurement_ID;
	container.protocolIEs.list.array[0]->value.choice.Measurement_ID = lmf_id;

	/*(2) RAN Measurement ID*/
	if((container.protocolIEs.list.array[1] = calloc(1, sizeof(NRPPa_MeasurementFailureIndication_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[1]->id = NRPPa_ProtocolIE_ID_id_RAN_Measurement_ID;
	container.protocolIEs.list.array[1]->criticality = NRPPa_Criticality_reject;
	container.protocolIEs.list.array[1]->value.present = NRPPa_MeasurementFailureIndication_IEs__value_PR_Measurement_ID_1;
	container.protocolIEs.list.array[1]->value.choice.Measurement_ID_1 = ran_id;

	/*(3) Cause*/
	if((container.protocolIEs.list.array[2] = calloc(1, sizeof(NRPPa_MeasurementFailureIndication_IEs_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	container.protocolIEs.list.array[2]->id = NRPPa_ProtocolIE_ID_id_Cause;
	container.protocolIEs.list.array[2]->criticality = NRPPa_Criticality_ignore;
	container.protocolIEs.list.array[2]->value.present = NRPPa_MeasurementFailureIndication_IEs__value_PR_Cause;
	memcpy((void*) &container.protocolIEs.list.array[2]->value.choice.Cause, (void*) cause, sizeof(NRPPa_Cause_t));

	/*Setting up the Initiating Message*/
	msg.procedureCode = NRPPa_ProcedureCode_id_MeasurementFailureIndication;
	msg.criticality = NRPPa_Criticality_ignore;
	msg.nrppatransactionID = nrppaTID;
	msg.value.present = NRPPa_InitiatingMessage__value_PR_MeasurementFailureIndication;
	msg.value.choice.MeasurementFailureIndication = container;

	/*Initialize NRPPa PDU*/
	pdu.present = NRPPa_NRPPA_PDU_PR_initiatingMessage;
	pdu.choice.initiatingMessage = &msg;

	/*Encoding NRPPa PDU via ASN.1 PER*/
	explicit_bzero(tmp, sizeof(tmp));
	ec = aper_encode_to_buffer(&asn_DEF_NRPPa_NRPPA_PDU, NULL, (void*) &pdu, (void*) tmp, BUF_MAX);
	if(ec.encoded < 0)
	{
		perror("aper_encode_to_buffer()");
		goto err;
	}

	/*Free memory*/
	//ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, &pdu);

	/*Set pointer to encoded NRPPa PDU and its size for the caller*/
	*length = ec.encoded/8;
	*buf = (uint8_t*) calloc((ec.encoded+7)/8, sizeof(uint8_t));
	if(*buf == NULL)
	{
		perror("calloc()");
		goto err;
	}
	memcpy((void*)(*buf), (void*)tmp, (ec.encoded+7)/8);

	return;

err:
	*buf = 0;
	*length = 0;
	return;
}

/*
 * decodeNRPPa - decode an ASN.1 PER encoded NRPPa PDU
 */
nrppamsg_t*
decodeNRPPa(uint8_t *data, size_t size)
{
	/*Variables*/
	asn_dec_rval_t dec_ret = {0};
	nrppamsg_t *msg = 0;

	/*Checking for errors*/
	if(!data || !size || (msg = calloc(1, sizeof(nrppamsg_t))) == NULL)
	{
		return NULL;
	}

	dec_ret = aper_decode(NULL, &asn_DEF_NRPPa_NRPPA_PDU, (void **)&msg->pdu, data, size, 0, 0);

	if(dec_ret.code != RC_OK)
	{
		free(msg);
		return NULL;
	}

	return msg;
}

/*
 * freeNRPPaMessage - free a NRPPa message structure
 */
void freeNRPPaMessage(nrppamsg_t *msg)
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
		ASN_STRUCT_FREE(asn_DEF_NRPPa_NRPPA_PDU, msg->pdu);
		msg->pdu = 0;
	}

	return;
}
