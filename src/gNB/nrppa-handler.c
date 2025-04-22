#include "nrppa-handler.h"
#include "nrppa-ecid.h"

/*
 * Generic NRPPa handler function for different NRPPa message types
 *
 * @nrppa: NRPPa message structure that contains a decoded NRPPa PDU (has to be freed after usage!)
 * @ngap: decoded NGAP message where @pdu was extracted from.
 *
 * return: NRPPa message structure with (Class 1 NRPPa procedure) or without (Class 2 NRPPa procedure) encoded NRPPa PDU, 0 otherwise
 *
 * NOTE: If the passed NRPPa message triggers multiple messages (e.g. Measurement report),
 *		 this handler function creates a new POSIX thread to handle these messages.
 *
 */
nrppamsg_t*
handleNRPPaMessage(nrppamsg_t *nrppa, ngapmsg_t *ngap)
{
	/*Variables*/
	int ret = 0;
	nrppamsg_t *resp = 0;

	/*Check passed input parameter*/
	if(!nrppa || !nrppa->pdu || !ngap || !ngap->pdu)
	{
		goto err;
	}

	/*Determine received message type*/
	switch(nrppa->pdu->present)
	{
		/*NRPPa Initiating messages*/
		case NRPPa_NRPPA_PDU_PR_initiatingMessage:
		
			/*Handle NRPPa message depending on its message content type*/
			switch(nrppa->pdu->choice.initiatingMessage->value.present)
			{
				case NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementInitiationRequest:
					if((resp = E_CID_MeasurementInitiation(nrppa, ngap)) == NULL)
					{
						goto err;
					}
					break;

				case NRPPa_InitiatingMessage__value_PR_OTDOAInformationRequest:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_PositioningInformationRequest:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_MeasurementRequest:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_TRPInformationRequest:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_PositioningActivationRequest:

					break;
				case NRPPa_InitiatingMessage__value_PR_PRSConfigurationRequest:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_MeasurementPreconfigurationRequired:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementTerminationCommand:
					if(E_CID_MeasurementTermination(nrppa) != 0 || (resp = calloc(1, sizeof(nrppamsg_t))) == NULL)
					{
						goto err;
					}
					break;
				case NRPPa_InitiatingMessage__value_PR_ErrorIndication:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_AssistanceInformationControl:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_MeasurementUpdate:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_MeasurementAbort:
				
					break;
				case NRPPa_InitiatingMessage__value_PR_PositioningDeactivation:

					break;
				case NRPPa_InitiatingMessage__value_PR_MeasurementActivation:

					break;
				case NRPPa_InitiatingMessage__value_PR_SRSInformationReservationNotification:
				
					break;
	
				/*Error message codes that can only be initiated by a gNB*/
				case NRPPa_InitiatingMessage__value_PR_PositioningInformationUpdate:
				case NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementReport:
				case NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementFailureIndication:
				case NRPPa_InitiatingMessage__value_PR_PrivateMessage:
				case NRPPa_InitiatingMessage__value_PR_AssistanceInformationFeedback:
				case NRPPa_InitiatingMessage__value_PR_MeasurementReport:
				case NRPPa_InitiatingMessage__value_PR_MeasurementFailureIndication:
				default:
					goto err;
			
			}
			break;

		/*Ignored here because NRPPa transactions are already initiated by the target LMF*/
		case NRPPa_NRPPA_PDU_PR_successfulOutcome:
		case NRPPa_NRPPA_PDU_PR_unsuccessfulOutcome:
		
		default:
			goto err;
	
	}

	/*Free memory*/
	if(nrppa)
	{
		freeNRPPaMessage(nrppa);
		free(nrppa);
		nrppa = 0;
	}

	return resp;

err:
	/*Free memory*/
	if(nrppa)
	{
		freeNRPPaMessage(nrppa);
		free(nrppa);
	}

	if(resp)
	{
		freeNRPPaMessage(resp);
		free(resp);
	}

	return NULL;
}
