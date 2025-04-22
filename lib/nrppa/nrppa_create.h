/*C standard library headers*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*ASN.1 headers*/
#include <aper_encoder.h>

/*3GPP TS 38.455 compliant headers*/
#include <NRPPa_NRPPA-PDU.h>
#include <NRPPa_InitiatingMessage.h>
#include <NRPPa_SuccessfulOutcome.h>
#include <NRPPa_UnsuccessfulOutcome.h>
#include <NRPPa_E-CIDMeasurementInitiationRequest.h>
#include <NRPPa_ProcedureCode.h>
#include <NRPPa_NRPPATransactionID.h>
#include <NRPPa_ProtocolIE-Container.h>
#include <NRPPa_ProtocolIE-Field.h>
#include <NRPPa_ProtocolIE-ID.h>
#include <NRPPa_ReportCharacteristics.h>
#include <NRPPa_MeasurementPeriodicity.h>
#include <NRPPa_asn_constant.h>
#include <NRPPa_ProtocolIE-Single-Container.h>
#include <NRPPa_MeasuredResults.h>
#include <NRPPa_NG-RANAccessPointPosition.h>

#ifndef _NRPPA_CREATE_H_
#define _NRPPA_CREATE_H_

/*
 * Macros
 *
 * @BUF_MAX: maximum buffer size for result of ASN.1 PER encoding
 */
#define BUF_MAX 131072

/*
 * nrppamsg - data structure to handle a NRPPa PDU
 *
 * @pdu: pointer to the unencoded NRPPa PDU
 * @enc: pointer to the ASN.1 PER encoded NRPPa PDU
 * @size: size [B] of @enc 
 */
typedef struct nrppamsg
{
	NRPPa_NRPPA_PDU_t *pdu;
	uint8_t *enc;
	uint32_t size;
} nrppamsg_t;

/*
 * meas_quantity - generic data stucture for setting measurement types
 *
 * @items: array that contains recorded metric number according to include/nrppa/...QuantitiesValue.h
 * @count: number of initialized elements in @items
 */
struct meas_quantity
{
	long items[NRPPa_maxNoMeas];
	uint32_t count;
};

/*
 * NRPPa_ECID_Measurement_Initiation_Request - create a NRPPa PDU
 *
 * HTTPS message type: 
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * compliant with: 3GPP TS 38.455, 8.2.1
 */
nrppamsg_t* NRPPa_ECID_Measurement_Initiation_Request(long nrppaTID, long ue_id, NRPPa_ReportCharacteristics_t rtype, NRPPa_MeasurementPeriodicity_t interval, struct meas_quantity *list, struct meas_quantity *orat, struct meas_quantity *wlan, NRPPa_MeasurementPeriodicityNR_AoA_t intervalAoA);

/*
 * NRPPa_ECID_Measurement_Initiation_Response - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.2.1
 */
nrppamsg_t* NRPPa_ECID_Measurement_Initiation_Response(long nrppaTID, long ue_id, long ran_id, NRPPa_E_CID_MeasurementResult_t **ecid, NRPPa_CriticalityDiagnostics_t *diagnostics, NRPPa_OtherRATMeasurementResult_t **orat, NRPPa_WLANMeasurementResult_t **wlan, long *cp_id);

/*
 * NRPPa_ECID_Measurement_Initiation_Failure - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.2.1
 */
nrppamsg_t* NRPPa_ECID_Measurement_Initiation_Failure(long nrppaTID, long ue_id, NRPPa_Cause_t *cause, NRPPa_CriticalityDiagnostics_t *diagnostics);

/*
 * NRPPa_ECID_Measurement_Failure_Indication - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.2.2
 */
nrppamsg_t* NRPPa_ECID_Measurement_Failure_Indication(long nrppaTID, long ue_id, long ran_id, NRPPa_Cause_t *cause);

/*
 * NRPPa_ECID_Measurement_Report - create a NRPPa PDU
 *
 * NGAP message type: NGAP Uplink UE Associated NRPPa Transport
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.2.3
 */
nrppamsg_t* NRPPa_ECID_Measurement_Report(long nrppaTID, long ue_id, long ran_id, NRPPa_E_CID_MeasurementResult_t **ecid, long *cp);

/*
 * NRPPa_ECID_Measurement_Termination - create a NRPPa PDU
 *
 * HTTPS message type: 
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * compliant with: 3GPP TS 38.455, 8.2.4
 */
nrppamsg_t* NRPPa_ECID_Measurement_Termination(long nrppaTID, long ue_id, long ran_id);

/*
 * NRPPa_Error_Indication - create a NRPPa PDU for error detection cases
 *
 * Direction: LMF -> gNB via AMF or vise versa
 * Caller: LMF or gNB
 *
 * compliant with: 3GPP TS 38.455, 8.3.1
 */
nrppamsg_t* NRPPa_Error_Indication(long nrppaTID, NRPPa_Cause_t *cause, NRPPa_CriticalityDiagnostics_t *diagnostics);

/*
 * NRPPa_Assistance_Information_Control - create a NRPPa PDU
 *
 * NGAP message type: Downlink Non UE Associated
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * compliant with: 3GPP TS 38.455, 8.4.1
 */
void NRPPa_Assistance_Information_Control(long nrppaTID, NRPPa_Assistance_Information_t *info, NRPPa_Broadcast_t *bcast, NRPPa_PositioningBroadcastCells_t *cells, uint8_t **buf, size_t *length);

/*
 * NRPPa_Assistance_Information_Feedback - create a NRPPa PDU
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.4.2
 */
void NRPPa_Assistance_Information_Feedback(long nrppaTID, NRPPa_AssistanceInformationFailureList_t *flist, NRPPa_PositioningBroadcastCells_t *cells, NRPPa_CriticalityDiagnostics_t *diagnostics, uint8_t **buf, size_t *length);

/*
 * NRPPa_Measurement_Request - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Downlink Non UE Associated
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * compliant with: 3GPP TS 38.455, 8.5.1
 */
void NRPPa_Measurement_Request(long nrppaTID, long ue_id, NRPPa_TRP_MeasurementRequestList_t *tlist, 
						  long rtype, NRPPa_MeasurementPeriodicity_t mp, NRPPa_TRPMeasurementQuantities_t *tq, NRPPa_RelativeTime1900_t *sfn,
						  NRPPa_SRSConfiguration_t *sconf, NRPPa_MeasurementBeamInfoRequest_t *inforeq, NRPPa_SystemFrameNumber_t *sfrnum,
						  NRPPa_SlotNumber_t *slot, NRPPa_MeasurementPeriodicityExtended_t mpext, NRPPa_ResponseTime_t *tresp,
						  NRPPa_MeasurementCharacteristicsRequestIndicator_t *mcind, NRPPa_MeasurementTimeOccasion_t *mto,
						  NRPPa_MeasurementAmount_t *mtimes, NRPPa_TimeWindowInformation_Measurement_List_t *twlist, uint8_t **buf, size_t *length);

/*
 * NRPPa_Measurement_Response - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.5.1
 */
void NRPPa_Measurement_Response(long nrppaTID, long ue_id, long ran_id, bool isOnDemand, NRPPa_TRP_MeasurementResponseList_t *tlist, NRPPa_CriticalityDiagnostics_t *diagnostics, uint8_t **buf, size_t *length);

/*
 * NRPPa_Measurement_Failure - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.5.1
 */
void NRPPa_Measurement_Failure(long nrppaTID, long ue_id, NRPPa_Cause_t *cause, NRPPa_CriticalityDiagnostics_t *diagnostics, uint8_t **buf, size_t *length);

/*
 * NRPPa_Measurement_Report - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.5.2
 */
void NRPPa_Measurement_Report(long nrppaTID, long lmf_id, long ran_id, NRPPa_TRP_MeasurementResponseList_t *tlist, uint8_t **buf, size_t *length);

/*
 * NRPPa_Measurement_Abort - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Downlink Non UE Associated
 *
 * Direction: LMF -> gNB via AMF
 * Caller: LMF
 *
 * compliant with: 3GPP TS 38.455, 8.5.4
 */
void NRPPa_Measurement_Abort(long nrppaTID, long ue_id, long ran_id, uint8_t **buf, size_t *length);

/*
 * NRPPa_Measurement_Failure_Indication - create NRPPa PDU for Measurement procedure
 *
 * NGAP message type: Uplink Non UE Associated
 *
 * Direction: gNB -> LMF via AMF
 * Caller: gNB
 *
 * compliant with: 3GPP TS 38.455, 8.5.5
 */
void NRPPa_Measurement_Failure_Indication(long nrppaTID, long lmf_id, long ran_id, NRPPa_Cause_t *cause, uint8_t **buf, size_t *length);


nrppamsg_t* decodeNRPPa(uint8_t *enc, size_t size);

/*
 * forwardNRPPafromNGAP - reencapsulate the ASN.1 PER encoded NRPPa SDU from a NGAP to a HTTPS message
 *
 * Caller: AMF
 *
 * NOTE: This function is only important for the AMF to forward the NRPPa SDU to the LMF.
 */
void forwardNRPPafromNGAP();

/*
 * forwardNRPPafromHTTPS - reencapsulate the ASN.1 PER encoded NRPPa SDU from a HTTPS to a NGAP message
 *
 * Caller: AMF
 *
 * NOTE: This function is only important for the AMF to forward the NRPPa SDU to the target gNB.
 *
 * TODO: Call createNGAPforNRPPaTransport() within this function to encapsulate NRPPa SDU in a NGAP message. Depending on NRPPa message type (not known because AMF only forwards the message!), setting NGAP message type (UE Ass. or Non UE Ass.)
 */
void forwardNRPPafromHTTPS();

/*
 * freeNRPPaMessage - free a NRPPa message structure
 */
void freeNRPPaMessage(nrppamsg_t *msg);

#endif
