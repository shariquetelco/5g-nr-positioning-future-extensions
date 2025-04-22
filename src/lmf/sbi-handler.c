#include "sbi-handler.h"
#include "list-handler.h"
#include "sbi-client.h"

#ifdef RESEARCH
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * timespec_diff(struct timespec *, struct timespec *, struct timespec *)
 * @brief Compute the diff of two timespecs, that is a - b = result.
 * @param a the minuend
 * @param b the subtrahend
 * @param result a - b
 *
 * adopted from: https://gist.github.com/diabloneo/9619917
 */
static inline void
timespec_diff(struct timespec *a, struct timespec *b, struct timespec *result)
{
    result->tv_sec  = a->tv_sec  - b->tv_sec;
    result->tv_nsec = a->tv_nsec - b->tv_nsec;
    if (result->tv_nsec < 0)
    {
        --result->tv_sec;
        result->tv_nsec += 1000000000L;
    }
}

#endif

/*
 * json_read_callback - transfer JSON formatted string to final buffer
 *
 * @source->ptr: contains reference to JSON formatted response data (see 3GPP TS 29.518, 6.1.3.5.3.1)
 */
nghttp2_ssize
json_read_callback(nghttp2_session *session, int32_t stream_id, uint8_t *buf, size_t length, uint32_t *data_flags, nghttp2_data_source *source, void *user_data)
{
	/*Variables*/
	char* src = (char*) source->ptr;
	ssize_t ret;
	(void)session;
	(void)stream_id;
	(void)user_data;

	/*Checking if buffer is large enough*/
	if((ret = strlen(src)) > length)
	{
		free(src);
		return NGHTTP2_ERR_TEMPORAL_CALLBACK_FAILURE;
	}

#ifdef DEBUG
	fprintf(stderr, "json_read_callback():\n%s\n", src);
#endif

	/*Copy data to output buffer*/
	memcpy((void*)buf, (void*)src, ret);

	/*Set END FLAG and free memory*/
	*data_flags |= NGHTTP2_DATA_FLAG_EOF;
	free(src);

	return (nghttp2_ssize)ret;
}

/*
 * research_ECID_RequestResponseTime - send NRPPa E-CID Measurement Initiation Request messages and wait for its response (no periodic response!)
 *
 * return: 0 on success, -1 otherwise
 */
static int
research_ECID_RequestResponseTime(ue_ctx_t *ctx, int *ufd)
{
	/*Variables*/
	int i, j, fd = -1;
	char path[100] = {0};
	NRPPa_NRPPATransactionID_t ntid = NRPPA_TRANSID_MAX + 1;

	struct pollfd pfd;

	nrppamsg_t *msg = 0;
	struct meas_quantity mlist = {0};
	struct timespec start[NRPPA_SAMPLE_MAX] = {0}, end[NRPPA_SAMPLE_MAX] = {0}, res[NRPPA_SAMPLE_MAX] = {0};

	/*Get unused NRPPa Transaction ID*/
	if((ntid = reserveListID(nrppa_list)) >= NRPPA_TRANSID_MAX)
	{
		return -1;
	}

	snprintf(path, 99, "%secid_%d_%d_%s.csv", RES_FILE_PATTERN, ue_list->bar_cnt, ue_list->npool, ctx->supi);
	if((fd = open(path, O_WRONLY | O_CREAT | O_EXCL, 0660)) < 0)
	{
		if((fd = open(path, O_WRONLY | O_APPEND)) < 0)
		{
			goto err;
		}
#ifdef DEBUG
		write(fd, "------ New Sample\n", strlen("------ New Sample\n"));
#endif
	}

	/*POSIX barrier: Waiting here until all parallel threads have reached this point*/
	pthread_barrier_wait(&ue_list->barrier);

	for(j = 0; j < NRPPA_SAMPLE_MAX; j++)
	{
		/*Start timer here*/
		if(clock_gettime(CLOCK_MONOTONIC, start + j) != 0)
		{
			continue;
		}

		/*Send NRPPa message: E-CID Measurement Request*/
		explicit_bzero(&mlist, sizeof(mlist));
#ifdef RESEARCH
		for(i = 0; i < NRPPa_maxNoMeas; i++)
		{
			mlist.items[i] = NRPPa_MeasurementQuantitiesValue_sS_RSRP;
		}
		mlist.count = NRPPa_maxNoMeas;
#else
		mlist.items[0] = NRPPa_MeasurementQuantitiesValue_sS_RSRP;
		mlist.items[1] = NRPPa_MeasurementQuantitiesValue_sS_RSRQ;
		mlist.items[2] = NRPPa_MeasurementQuantitiesValue_cSI_RSRP;
		mlist.items[3] = NRPPa_MeasurementQuantitiesValue_cSI_RSRQ;
		mlist.items[4] = NRPPa_MeasurementQuantitiesValue_angleOfArrivalNR;
		mlist.items[5] = NRPPa_MeasurementQuantitiesValue_timingAdvanceNR;
		mlist.count = 6;
#endif
	
		/*Create NRPPa PDU: E-CID Measurement Initiation Request*/
		if((msg = NRPPa_ECID_Measurement_Initiation_Request(ntid, ctx->lmf_ue, NRPPa_ReportCharacteristics_onDemand, 0, &mlist, NULL, NULL, 0)) == NULL || !msg->enc || !msg->size)
		{
			printf("[LMF-sbi] NRPPa_ECID_Measurement_Initiation_Request failed\n");
			goto err;
		}
	
		/*Invoke SBI Namf_Communication_N1N2MessageTransfer service*/
		if(namf_comm_n1n2msgtransfer(msg, LMF_NFID, ctx->lcsid, ctx->supi) != 0)
		{
			printf("[LMF-sbi] N1N2MessageTransfer request failed for %s\n", ctx->supi);
			goto err;
		}
	
		freeNRPPaMessage(msg);
		free(msg);
		msg = 0;

		/*Waiting for E-CID Measurement Initiation Response/Failure*/
		while(1)
		{
			pfd.fd = ufd[0];
			pfd.events = POLLIN;

			/*Monitor the UNIX Domain socket file descriptor for response data*/
			if(poll(&pfd, 1, -1) <= 0)
			{
				if(errno == EINTR)
				{
					continue;
				}
				goto err;
			}

			/*Process data if target file descriptor is readable*/
			if(recv(ufd[0], &msg, sizeof(msg), 0) != sizeof(msg))
			{
				msg = 0;
			}

			break;
		}

		if(!msg || !msg->pdu)
		{
			freeNRPPaMessage(msg);
			if(msg)
			{
				free(msg);
				msg = 0;
			}

			continue;
		}

		/*Stopping timer*/	
		if(clock_gettime(CLOCK_MONOTONIC, end + j) != 0)
		{
			continue;
		}

		/*Free memory*/
		if(j < NRPPA_SAMPLE_MAX-1)
		{
			freeNRPPaMessage(msg);
			free(msg);
			msg = 0;
		}
	}

	/*Write everything to target file: if end == 0 || start == 0 -> empty line*/
	for(j = 0; j < NRPPA_SAMPLE_MAX; j++)
	{
		/*Calculate time difference for each measurement*/
		timespec_diff(end + j, start + j, res + j);
		
		/*Format line that is written to file*/
		snprintf(path, 99, "%ld,%ld,%ld\n", (start + j)->tv_sec*1000000000L + (start + j)->tv_nsec, (end + j)->tv_sec*1000000000L + (end + j)->tv_nsec, (res + j)->tv_sec*1000000000L + (res + j)->tv_nsec);
		
		if(write(fd, path, strlen(path)) < 0)
		{
			continue;
		}
	}
	close(fd);
	fd = -1;

	/*Check NRPPa response message*/
	switch(msg->pdu->present)
	{
		/*Successful: E-CID Measurement Initiation Response*/
		case NRPPa_NRPPA_PDU_PR_successfulOutcome:
			if(msg->pdu->choice.successfulOutcome->procedureCode != NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation || msg->pdu->choice.successfulOutcome->criticality != NRPPa_Criticality_reject || msg->pdu->choice.successfulOutcome->nrppatransactionID != ntid ||
			   msg->pdu->choice.successfulOutcome->value.present != NRPPa_SuccessfulOutcome__value_PR_E_CIDMeasurementInitiationResponse)
			{
				goto err;
			}
#ifndef RESEARCH
			printf("NRPPa E-CID Measurement Initiation Response message received (%s)\n", ctx->supi);
#endif
			//TODO: Implementation open!
			break;

		/*Unsuccessful: E-CID Measurement Initiation Failure*/
		case NRPPa_NRPPA_PDU_PR_unsuccessfulOutcome:
			if(msg->pdu->choice.unsuccessfulOutcome->procedureCode != NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation || msg->pdu->choice.unsuccessfulOutcome->criticality != NRPPa_Criticality_reject || msg->pdu->choice.unsuccessfulOutcome->nrppatransactionID != ntid ||
			   msg->pdu->choice.unsuccessfulOutcome->value.present != NRPPa_UnsuccessfulOutcome__value_PR_E_CIDMeasurementInitiationFailure)
			{
				goto err;
			}
#ifdef RESEARCH
			printf("NRPPa E-CID Measurement Initiation Failure message received (%s)\n", ctx->supi);
#endif
			//TODO: Implementation open!
			break;

		/*Unknown: Wrong NRPPa PDU message response type*/
		default:
			printf("NRPPa response message type unknown: %d\n", msg->pdu->present);
			goto err;
	
	}

	freeListID(nrppa_list, ntid);
	ntid = NRPPA_TRANSID_MAX + 1;
	freeNRPPaMessage(msg);
	free(msg);
	msg = 0;

	return 0;

err:
	if(msg)
	{
		freeNRPPaMessage(msg);
		free(msg);
	}

	if(ntid >= 0 && ntid < NRPPA_TRANSID_MAX)
	{
		freeListID(nrppa_list, ntid);
	}

	if(fd >= 0)
	{
		close(fd);
	}

	return -1;
}


/*
 * research_ECID_PeriodicTime - send NRPPa E-CID Measurement Initiation Request messages and wait for its responses
 *
 * return: 0 on success, -1 otherwise
 */
static int
research_ECID_PeriodicTime(ue_ctx_t *ctx, int *ufd)
{
	/*Variables*/
	int i, j, fd = -1;
	char path[100] = {0};
	NRPPa_NRPPATransactionID_t ntid = NRPPA_TRANSID_MAX + 1;
	bool isSending = false, isStarted = true;

	struct pollfd pfd;

	nrppamsg_t *msg = 0;
	struct meas_quantity mlist = {0};
	struct timespec start[NRPPA_SAMPLE_MAX] = {0}, end[NRPPA_SAMPLE_MAX] = {0}, res[NRPPA_SAMPLE_MAX] = {0};

#ifndef RESEARCH
	printf("[LMF-sbi] -- Starting NRPPa E-CID Measurement Report procedure --\n");
#endif

	snprintf(path, 99, "%secid_report_%d_%d_p%d_%s.csv", RES_FILE_PATTERN, ue_list->bar_cnt, ue_list->npool, ue_list->period, ctx->supi);
	if((fd = open(path, O_WRONLY | O_CREAT | O_EXCL, 0660)) < 0)
	{
		if((fd = open(path, O_WRONLY | O_APPEND)) < 0)
		{
			goto err;
		}
#ifdef DEBUG
		write(fd, "------ New Sample\n", strlen("------ New Sample\n"));
#endif
	}

	/*POSIX barrier: Waiting here until all parallel threads have reached this point*/
	pthread_barrier_wait(&ue_list->barrier);

	/*
	 *	NRPPa E-CID Measurement Report message procedure handling
	 *
	 *	(1) Sending of NRPPa E-CID Measurement Initiation Request with periodic response (reuse @mlist)
	 *	(2) Check response message: If Initiation response message is received, wait for NRPPA_SAMPLE_MAX responses
	 *	(3) Send NRPPa E-CID Measurement Termination message to stop the measurement report
	 *	(4) Write results to target file
	 */
	explicit_bzero(start, sizeof(start));
	explicit_bzero(end, sizeof(end));
	explicit_bzero(res, sizeof(res));

	/*Get unused NRPPa Transaction ID*/
	if((ntid = reserveListID(nrppa_list)) >= NRPPA_TRANSID_MAX)
	{
		goto err;
	}

	/*Send NRPPa message: E-CID Measurement Request*/
	explicit_bzero(&mlist, sizeof(mlist));
	for(i = 0; i < NRPPa_maxNoMeas; i++)
	{
		mlist.items[i] = NRPPa_MeasurementQuantitiesValue_sS_RSRP;
	}
	mlist.count = NRPPa_maxNoMeas;

	/*
	 * Measurement Periodicity according to /include/nrppa/NRPPa_MeasurementPeriodicity.h
	 *
	 * NRPPa_MeasurementPeriodicity_ms120	= 0,
	 * NRPPa_MeasurementPeriodicity_ms240	= 1,
	 * NRPPa_MeasurementPeriodicity_ms480	= 2,
	 * NRPPa_MeasurementPeriodicity_ms640	= 3,
	 * NRPPa_MeasurementPeriodicity_ms1024	= 4,
	 * NRPPa_MeasurementPeriodicity_ms2048	= 5,
	 * NRPPa_MeasurementPeriodicity_ms5120	= 6,
	 * NRPPa_MeasurementPeriodicity_ms10240	= 7,
	 * NRPPa_MeasurementPeriodicity_min1	= 8,
	 * NRPPa_MeasurementPeriodicity_min6	= 9,
	 * NRPPa_MeasurementPeriodicity_min12	= 10,
	 * NRPPa_MeasurementPeriodicity_min30	= 11,
	 * NRPPa_MeasurementPeriodicity_min60	= 12,
	 * NRPPa_MeasurementPeriodicity_ms20480	= 13,
	 * NRPPa_MeasurementPeriodicity_ms40960	= 14
	 */
	/*Create NRPPa PDU: E-CID Measurement Initiation Request*/
	if((msg = NRPPa_ECID_Measurement_Initiation_Request(ntid, ctx->lmf_ue, NRPPa_ReportCharacteristics_periodic, ue_list->period, &mlist, NULL, NULL, 0)) == NULL || !msg->enc || !msg->size)
	{
		printf("[LMF-sbi] NRPPa_ECID_Measurement_Initiation_Request failed\n");
		goto err;
	}

	/*Invoke SBI Namf_Communication_N1N2MessageTransfer service*/
	if(namf_comm_n1n2msgtransfer(msg, LMF_NFID, ctx->lcsid, ctx->supi) != 0)
	{
		printf("[LMF-sbi] N1N2MessageTransfer request failed for %s\n", ctx->supi);
		goto err;
	}

	freeNRPPaMessage(msg);
	free(msg);
	msg = 0;

	/*
	 * Loop: Waiting for E-CID Measurement XXX messages
	 *
	 * NOTE: The counter is increased manually every time when an E-CID Measurement Report message was received.
	 * NOTE: A race condition can occur if all E-CID Measurement Report messages were received before the corresponding
	 *		 E-CID Measurement Initiation Response message is received. Therefore, the FOR loop is also aborted manually.
	 */
	for(j = 0;;)
	{
		if(j > 0 && j < NRPPA_SAMPLE_MAX)
		{
			/*The previous time end point is the time start point of the next iteration*/
			memcpy(start + j, end + j - 1, sizeof(struct timespec));
		}
		else if(j == 0 && isStarted)
		{
			clock_gettime(CLOCK_MONOTONIC, start);
			isStarted = false;
		}

		pfd.fd = ufd[0];
		pfd.events = POLLIN;

		/*Monitor the UNIX Domain socket file descriptor for response data*/
		if(poll(&pfd, 1, -1) <= 0)
		{
			if(errno == EINTR)
			{
				continue;
			}
			goto err;
		}

		/*Process data if target file descriptor is readable*/
		if(recv(ufd[0], &msg, sizeof(msg), 0) != sizeof(msg))
		{
			msg = 0;
		}

		/*Get current timestamp from kernel*/
		if(j < NRPPA_SAMPLE_MAX)
		{
			if(clock_gettime(CLOCK_MONOTONIC, end + j) != 0)
			{
				printf("[LMF-sbi] The current timestamp couldn't be obtained from kernel\n");
			}
		}

		if(!msg || !msg->pdu)
		{
			if(msg)
			{
				freeNRPPaMessage(msg);
				free(msg);
				msg = 0;
			}

			goto err;
		}

		/*
		 * Check received NRPPa message type:
		 *
		 * (1) Successful Outcome: E-CID Measurement Initiation Response -> Measurement is started
		 * (2) Unsuccessful Outcome: E-CID Measurement Initiation Failure -> Measurement didn't start
		 * (3) Initiating message: E-CID Measurement Report (Measurement) OR E-CID Measurement Indication Failure (Measurement was stopped by target gNB)
		 */
		switch(msg->pdu->present)
		{
			/*(1) Successful: E-CID Measurement Initiation Response*/
			case NRPPa_NRPPA_PDU_PR_successfulOutcome:

				if(msg->pdu->choice.successfulOutcome->procedureCode != NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation ||
				   msg->pdu->choice.successfulOutcome->criticality != NRPPa_Criticality_reject ||
				   msg->pdu->choice.successfulOutcome->nrppatransactionID != ntid ||
				   msg->pdu->choice.successfulOutcome->value.present != NRPPa_SuccessfulOutcome__value_PR_E_CIDMeasurementInitiationResponse ||
				   msg->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count < 2 ||
				   msg->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[0]->value.choice.UE_Measurement_ID != ctx->lmf_ue)
				{
					printf("[LMF-sbi] Received E-CID Measurement Initiation Response message (%s) is invalid\n", ctx->supi);
					goto err;
				}

				/*Reminder to stop sending if an error occurs later*/
				isSending = true;

				/*Store RAN UE Measurement ID*/
				ctx->ran_ue = msg->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.array[1]->value.choice.UE_Measurement_ID_1;
#ifndef RESEARCH
				printf("[LMF-sbi] %s: E-CID Measurement ID pair complete %ld, %ld\n", ctx->supi, ctx->lmf_ue, ctx->ran_ue);
#endif
				/*Potential race condition: If NRPPA_SAMPLE_MAX E-CID Measurement Report messages were already received: ending*/
				if(j >= NRPPA_SAMPLE_MAX)
				{
					freeNRPPaMessage(msg);
					free(msg);
					msg = 0;
					goto end;
				}
				break;

			/*(2) Unsuccessful: E-CID Measurement Initiation Failure*/
			case NRPPa_NRPPA_PDU_PR_unsuccessfulOutcome:
				if(msg->pdu->choice.unsuccessfulOutcome->procedureCode != NRPPa_ProcedureCode_id_e_CIDMeasurementInitiation || msg->pdu->choice.unsuccessfulOutcome->criticality != NRPPa_Criticality_reject || msg->pdu->choice.unsuccessfulOutcome->nrppatransactionID != ntid ||
			   	msg->pdu->choice.unsuccessfulOutcome->value.present != NRPPa_UnsuccessfulOutcome__value_PR_E_CIDMeasurementInitiationFailure)
				{
					goto err;
				}
#ifdef RESEARCH
				printf("[LMF-sbi] NRPPa E-CID Measurement Initiation Failure message received (%s): aborting\n", ctx->supi);
#endif
				goto end;

			/*(3) Initiating: E-CID Measurement Report OR E-CID Measurement Indication Failure message*/
			case NRPPa_NRPPA_PDU_PR_initiatingMessage:

				/*E-CID Measurement Report*/
				if(msg->pdu->choice.initiatingMessage->procedureCode == NRPPa_ProcedureCode_id_e_CIDMeasurementReport &&
				   msg->pdu->choice.initiatingMessage->criticality == NRPPa_Criticality_ignore && 
				   msg->pdu->choice.initiatingMessage->value.present == NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementReport &&
				   msg->pdu->choice.initiatingMessage->value.choice.E_CIDMeasurementReport.protocolIEs.list.count >= 3)
				{
					if(!isSending)
					{
						/*Reminder to stop sending if an error occurs later*/
						isSending = true;
					}

					/*If RAN UE Measurement ID was already received and enough timestamps were taken: ending*/
					if(ctx->ran_ue != 0 && j >= NRPPA_SAMPLE_MAX)
					{
						freeNRPPaMessage(msg);
	                                        free(msg);
        	                                msg = 0;
                	                        goto end;
					}

					/*Increase message counter*/
					j++;
				}

				/*E-CID Measurement Indication Failure*/
				else if(msg->pdu->choice.initiatingMessage->procedureCode == NRPPa_ProcedureCode_id_e_CIDMeasurementFailureIndication &&
						msg->pdu->choice.initiatingMessage->criticality == NRPPa_Criticality_ignore &&
						msg->pdu->choice.initiatingMessage->value.present == NRPPa_InitiatingMessage__value_PR_E_CIDMeasurementFailureIndication)
				{
					printf("[LMF-sbi] E-CID Measurement Report message generation was aborted by the target gNB (%d/%d)\n", j, NRPPA_SAMPLE_MAX);

					/*Free memory*/
					freeNRPPaMessage(msg);
					free(msg);
					msg = 0;

					goto end;
				}

				else
				{
					goto err;
				}

				break;

			/*Unknown: Wrong NRPPa PDU message response type*/
			default:
				printf("[LMF-sbi] Received NRPPa message type is unknown: %d\n", msg->pdu->present);
				goto err;
		}

next:
		/*Free memory*/
		freeNRPPaMessage(msg);
		free(msg);
		msg = 0;
	}

end:
	/*If E-CID Measurement Report messages were received: Writing saved timestamps to file*/
	if(j > 0)
	{
		/*Send NRPPa E-CID Measurement Termination message to target gNB to stop its sending of NRPPa E-CID Measurement Report messages*/
		if((msg = NRPPa_ECID_Measurement_Termination(ntid, ctx->lmf_ue, ctx->ran_ue)) == NULL)
		{
			goto err;
		}

		/*Invoke SBI Namf_Communication_N1N2MessageTransfer service*/
		if(namf_comm_n1n2msgtransfer(msg, LMF_NFID, ctx->lcsid, ctx->supi) != 0)
		{
			printf("[LMF-sbi] N1N2MessageTransfer request failed for %s\n", ctx->supi);
			goto err;
		}
		isSending = false;
		ctx->ran_ue = 0;
		freeNRPPaMessage(msg);
		free(msg);
		msg = 0;

		/*Write results to the target file*/
		for(i = 1; i < j; i++)
		{
			/*Calculate time difference for each measurement*/
			timespec_diff(end + i, start + i, res + i);

			/*Format line that is written to file*/
			snprintf(path, 99, "%ld,%ld,%ld\n", (start + i)->tv_sec*1000000000L + (start + i)->tv_nsec, (end + i)->tv_sec*1000000000L + (end + i)->tv_nsec, (res + i)->tv_sec*1000000000L + (res + i)->tv_nsec);

			if(write(fd, path, strlen(path)) < 0)
			{
				continue;
			}
		}
		close(fd);
		fd = -1;
	}

	/*Free reserved NRPPa Transaction ID*/
	freeListID(nrppa_list, ntid);
	return 0;

err:
	if(msg)
	{
		freeNRPPaMessage(msg);
		free(msg);
		msg = 0;
	}

	if(ntid >= 0 && ntid < NRPPA_TRANSID_MAX)
	{
		freeListID(nrppa_list, ntid);
	}

	if(fd >= 0)
	{
		close(fd);
	}

	if(isSending)
	{
		if((msg = NRPPa_ECID_Measurement_Termination(ntid, ctx->lmf_ue, ctx->ran_ue)) != NULL)
		{
			/*Invoke SBI Namf_Communication_N1N2MessageTransfer service*/
			namf_comm_n1n2msgtransfer(msg, LMF_NFID, ctx->lcsid, ctx->supi);
		}
		ctx->ran_ue = 0;
	}

	return -1;
}


/*
 * DetermineLocation - determine the location of a target UE
 *
 * @session: HTTP/2 connection information
 * @stream: HTTP/2 stream related data
 *
 * compliant with: 3GPP TS 29.572, 5.2.2.2 
 */
int
nlmf_loc_determineLocation(nghttp2_session *session, http2_stream_data *stream_data)
{

	/*Variables*/
	int ufd[2] = {-1};
	int i, j;
	input_data_t *req = 0;
	location_data_ext_t *resp = 0;
	cJSON *jbody = 0;
	char *jstr = 0;
	uint8_t buf[100] = {0};

	pthread_mutexattr_t attr;

	struct pollfd pfd;
	ue_ctx_t *ctx = 0;
	nrppamsg_t *msg = 0;

	nghttp2_nv *nva = 0;
	size_t nvlen = 0;
	nghttp2_data_provider2 data_prd;

	/*Check 1: Content-type has to be multipart/related (3GPP TS 29.518, 6.1.2.4)*/
	if(strstr(stream_data->ctype, "application/json") != stream_data->ctype)
	{
		/*HTTP Error 415 unsupported media (TS 29.500, 5.2.7.2)*/
		printf("[LMF-sbi] Invalid content-type (%s) for requested path %s!\n", stream_data->ctype, stream_data->request_path);

		if(error_response(session, stream_data, 415, NULL) != 0)
		{
			return -1;
		}
		return 0;
	}

	/*Check 2: SBI consumer (client) has to be accept: application/json,application/problem+json*/
	if(strcmp(stream_data->accept, "application/json,application/problem+json") != 0)
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		printf("[LMF-sbi] Invalid accept value (%s) in request header!\n", stream_data->accept);

		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}

	/*Parse JSON body and create expected input data structure*/
	if((jbody = cJSON_ParseWithLength(stream_data->data, stream_data->size)) == NULL || (req = input_data_parseFromJSON(jbody)) == NULL)
	{
		if(jbody)
		{
			cJSON_Delete(jbody);
		}

		if(error_response(session, stream_data, 400, HTTP_400_INVFORM) != 0)
		{
			return -1;
		}

		return 0;
	}
	cJSON_Delete(jbody);
	jbody = 0;

	/*Check required request fields*/
	if(!req->correlation_id || !req->amf_id || !req->supi)
	{
		goto err;
	}
#ifdef RT
printf("[LMF-sbi] Successfully subscribed for %s\n", req->supi);
#endif
	/*Check if positioning is already running for the target UE*/
	if((ctx = getUEctx(ue_list, req->supi)) != NULL)
	{
		printf("[LMF-sbi] Positioning for UE (%s) is already running\n", req->supi);

		input_data_free(req);
		req = 0;

		/*HTTP response 403 FORBIDDEN: 3GPP TS 29.572, 6.1.4.2.2 -> Positioning denied because of already*/
		if(error_response(session, stream_data, 403, HTTP_403_POSDENIED) != 0)
		{
			return -1;
		}

		return 0;
	}

	/*Create unnamed UNIX Domain socket and add one end to the created UE context for receiving data*/
	if(socketpair(AF_UNIX, SOCK_STREAM, 0, ufd) < 0)
	{
		perror("socketpair()");
		goto err;
	}

	/*Initialize POSIX thread mutex attribute*/
#ifdef DEBUG
	if(pthread_mutexattr_init(&attr) != 0)
	{
		perror("pthread_mutexattr_init()");
		goto err;
	}

	if(pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT) != 0)
	{
		perror("pthread_mutexattr_setprotocol");
		goto err;
	}
#endif
	/*Create UE context entry*/
	if((ctx = calloc(1, sizeof(ue_ctx_t))) == NULL)
	{
		goto err;
	}

	ctx->supi = strdup(req->supi);
	ctx->lcsid = strdup(req->correlation_id);
	ctx->amfid = strdup(req->amf_id);
	ctx->ufd = ufd[1];

	if(pthread_mutex_init(&ctx->lock, NULL) != 0)
	{
		if(ctx->supi)
		{
			free(ctx->supi);
		}

		if(ctx->lcsid)
		{
			free(ctx->lcsid);
		}

		if(ctx->amfid)
		{
			free(ctx->amfid);
		}
		ctx = 0;

		goto err;
	}

	/*Get unused LMF UE Measurement ID*/
	if((ctx->lmf_ue = (NRPPa_UE_Measurement_ID_t) reserveListID(lmf_ue_meas_list)) >= NRPPA_ECID_LMF_ID_MAX)
	{
		if(ctx->supi)
		{
			free(ctx->supi);
		}

		if(ctx->lcsid)
		{
			free(ctx->lcsid);
		}

		if(ctx->amfid)
		{
			free(ctx->amfid);
		}
		ctx = 0;

		goto err;
	}
	ctx->lmf_ue++; /*LMF UE Measurement ID has a range from 1 - 256. Therefore, the received ID must be incremented by 1.*/

	/*Free memory*/
	input_data_free(req);
	req = 0;

#ifndef RESEARCH
	printf("[LMF-sbi] UE context for %s with LCS Correlation Identifier %s successfully created\n", ctx->supi, ctx->lcsid);
#endif

	/*Add UE context to global UE context list*/
	if(addUEctx(ue_list, ctx) == false)
	{
		goto err;
	}

#ifndef RESEARCH
	printf("[LMF-sbi] Added UE context (%s) successfully to global UE context list: %d\n", ctx->supi, ue_list->cnt);
#endif

	/*Subscribe for UE specific N2 data to the target AMF*/
	snprintf(buf, 99, "%s/%s", LMF_CALLBACK_UE, ctx->supi);
	if(namf_comm_n1n2msgsubscribe(buf, LMF_NFID, ctx) != 0)
	{
		goto err;
	}
#ifndef RESEARCH
	printf("[LMF-sbi] Successfully subscribed for UE context %s: %s | %s\n", ctx->supi, ctx->n2_clb_uri, ctx->n2subid);
#endif

	/*
	 * Here, NRPPa E-CID Measurement XXX procedures are investigated! :-)
	 *
	 * Investigation 1: Request-Response time of a NRPPa E-CID Measurement Initiation message
	 *		    FUNCTION: research_ECID_RequestResponseTime()
	 *
	 * Investigation 2: How accurate can periodical response messages be received?
	 *		    NRPPa E-CID Measurement Report message
	 *		    FUNCTION: research_ECID_PeriodicTime()
	 *
	 * NOTE: If @ue_list->period is not set per command line, then 1 is executed, otherwise 2.
	 */
	if(ue_list->period < 0)
	{
		if(research_ECID_RequestResponseTime(ctx, ufd) != 0)
		{
			goto err;
		}
	}
	else
	{
		if(research_ECID_PeriodicTime(ctx, ufd) != 0)
		{
			goto err;
		}
	}

	/*
	 * Send HTTP/2 response
	 *
	 * NOTE: Currently, the response message always corresponds to 501 NOT IMPLEMENTED.
	 */
	if(error_response(session, stream_data, 501, NULL) != 0)
	{
		goto err;
	}

	/*Remove UE context from global list*/
	if(deleteUEctx(ue_list, ctx) == false)
	{
		goto err;
	}
	ctx = 0;
#ifndef RESEARCH
	printf("[LMF-sbi] UE context removed from list: %d\n", ue_list->cnt);
#endif

	/*Potential memory leak: checking the UNIX Domain socket if there are still depending messages*/
	shutdown(ufd[1], SHUT_WR);
	i = 0;
	while(recv(ufd[0], &msg, sizeof(msg), MSG_DONTWAIT) == sizeof(msg))
	{
		freeNRPPaMessage(msg);
		free(msg);
		msg = 0;
		i++;
	}
#ifndef RESEARCH
	printf("[LMF-sbi] Freeing of %d depending NRPPa messages\n", i);
#endif
	/*Close opened UNIX Domain sockets*/
	close(ufd[0]);
	close(ufd[1]);

	return 0;

err:

	pthread_mutexattr_destroy(&attr);

	/*Free memory*/
	if(ctx)
	{
		deleteUEctx(ue_list, ctx);
#ifndef RESEARCH
		printf("[LMF-sbi] UE context removed from list: %d\n", ue_list->cnt);
#endif
	}

	if(jbody)
	{
		cJSON_Delete(jbody);
	}

	if(req)
	{
		input_data_free(req);
	}

	/*Potential memory leak: checking the UNIX Domain socket if there are still depending messages*/
	shutdown(ufd[1], SHUT_WR);
	while(recv(ufd[0], &msg, sizeof(msg), MSG_DONTWAIT) == sizeof(msg))
	{
		freeNRPPaMessage(msg);
		free(msg);
		msg = 0;
	}

	/*Closing UNIX Domain Sockets*/
	close(ufd[0]);
	close(ufd[1]);

	return -1;
}

/*
 * N2InfoNotify - handling of notifications for subscribed NRPPa (N2) data
 *
 * @session: HTTP/2 connection information
 * @stream: HTTP/2 stream related data
 *
 * compliant with: 3GPP TS 29.518, 5.2.2.3.6
 */
int
namf_comm_N2InfoNotify(nghttp2_session *session, http2_stream_data *stream_data)
{

	/*Variables*/
	int i, j;
	n2_information_notification_t *req = 0;
	cJSON *n2data = 0, *in = 0, *err_json = 0;
	char *jstr = 0, *bound_ptr = 0, *cont_id = 0, *supi = 0;
	uint8_t *idx = 0, *idx2 = 0, *tmp = 0, *bin = 0;
	uint64_t bsize = 0;

	ue_ctx_t *ctx = 0;
	nrppamsg_t *msg = 0;
	NGAP_NRPPa_PDU_t *nrppa = 0;

	nghttp2_nv *nva = 0;
	size_t nvlen = 0;

	/*Looking for UE context in global list for which data was forwarded*/
	supi = stream_data->request_path + strlen("/n2-ue-messages");
	if(strlen(supi) < 2 || supi[0] != '/')
	{
		if(error_response(session, stream_data, 400, HTTP_400_INVURL) != 0)
		{
			return -1;
		}
		return 0;
	}
	supi++;

	/*Pick up UE context from global list based on sent SUPI in URI path*/
	if((ctx = getUEctx(ue_list, supi)) == NULL)
	{
#ifndef RESEARCH
		printf("[LMF-sbi] No UE context found for %s (%d)\n", supi, ue_list->cnt);
#endif
		if(error_response(session, stream_data, 400, HTTP_400_INVURL) != 0)
		{
			return -1;
		}
		return 0;
	}

	/*Check 1: Content-type has to be multipart/related (3GPP TS 29.518, 6.1.2.4)*/
	if(strstr(stream_data->ctype, "multipart/related") != stream_data->ctype)
	{
		/*Wenn content type falsch ist, HTTP Error 415 unsupported media (TS 29.500, 5.2.7.2)*/
		printf("[LMF-sbi] Invalid content-type (%s) for requested path %s!\n", stream_data->ctype, stream_data->request_path);

		if(error_response(session, stream_data, 415, NULL) != 0)
		{
			return -1;
		}
		return 0;
	}

	/*Check 2: SBI consumer (client) has to be accept: application/json,application/problem+json*/
	if(strcmp(stream_data->accept, "application/json,application/problem+json") != 0)
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		printf("[LMF-sbi] Invalid accept value (%s) in request header!\n", stream_data->accept);

		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}

	/*Reference boundary pattern from Content-Type*/
	if((bound_ptr = strstr(stream_data->ctype, "boundary=")) == NULL)
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}
	bound_ptr += strlen("boundary=");

	/*Check 3: Exceed limit of Content-Type length*/
	if(bound_ptr - stream_data->ctype >= strlen(stream_data->ctype))
	{
		/*HTTP error code: 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			return -1;
		}

		return 0;
	}

	/*
	 * Parsing of multipart data
	 *
	 * Structure of body:
	 *
	 * (1) ---------- 48753945309\r\n (first boundary, 42 B without \r\n)
	 * (2) Content-Type: application/json (30 B)
	 * (3) SKIPPED (double \r\n expected)
	 * (4) JSON data
	 * (5) ---------- 48753945309\r\n (boundary, 42 B without \r\n, first binary (N1 or N2 data))
	 * (6) Content-Type: application/vnd.3gpp.ngap (39 B)
	 * (7) Content-ID: XXX
	 * (8) SKIPPED (double \r\n expected)
	 * (9) N2 binary data
	 * (10) ---------- 48753945309--\r\n (last boundary, 44 B without \r\n)
	 */
	for(idx = memchr(stream_data->data, 0x0d, stream_data->size), idx2 = 0, j = 0; idx - stream_data->data < stream_data->size && idx != NULL;)
	{
		/*If next byte is not 0x0a -> skip and continue searching OR if parsing binary data -> skip 0x0d 0x0a sequences until boundary pattern is reached*/
		if(idx[1] != 0x0a || (j == 8 && strstr((char*)(idx+4), bound_ptr) != (char*)idx+4))
		{
#ifdef DEBUG
			if(j == 8)
			{
				printf("Token 10: boundary pattern doesn't match %s | %s\n", idx+2, bound_ptr);
			}
#endif
			idx = memchr(idx + 1, 0x0d, stream_data->size - (idx + 1 - stream_data->data));
			continue;
		}

		/*Examine found token*/
		if(!idx2 && idx-stream_data->data > 2)
		{
			tmp = calloc(idx-stream_data->data+1, sizeof(uint8_t));
			memcpy(tmp, stream_data->data, idx-stream_data->data);
			tmp[idx-stream_data->data] = 0;
#ifdef DEBUG
			fprintf(stderr, "Token %d [%d B]:\n", j+1, idx-stream_data->data);
			for(i = 0; i < idx-stream_data->data; i++)
			{
				if(i%15 == 0)
				{
					fprintf(stderr, "\n%.2x ", tmp[i]);
				}
				else{
					fprintf(stderr, "%.2x ", tmp[i]);
				}
			}
#endif
		}
#ifdef DEBUG
		else if(idx - idx2 < 3)
		{
			printf("-- Token %d [%d B] skipped --\n", j+1, idx-idx2);
		}
#endif
		else if(idx - idx2 > 2)
		{
			tmp = calloc(idx-idx2+1, sizeof(uint8_t));
			memcpy(tmp, idx2, idx-idx2);
			tmp[idx-idx2] = 0;
#ifdef DEBUG			
			fprintf(stderr, "Token %d [%d B]:\n", j+1, idx-idx2);
			for(i = 0; i < idx-idx2; i++)
			{
				if(i%20 == 0)
				{
					fprintf(stderr, "\n%.2x ", tmp[i]);
				}
				else{
					fprintf(stderr, "%.2x ", tmp[i]);
				}
			}
#endif
		}

		/*Processing of token according to expected body structure*/
		switch(j)
		{
			/*Token 1: First boundary identifier*/
			case 0:
				if(!tmp || strstr(tmp, bound_ptr) == NULL)
				{
					if(tmp)
					{
						free(tmp);
					}
					goto end;
				}
				//printf("Token 1: successful!\n");
				break;

			/*Token 2: Content-Type = application/json*/
			case 1:
				if(idx-idx2 != 30 || memcmp(tmp, (uint8_t*)"Content-Type: application/json", 30) != 0)
				{
					free(tmp);
					goto end;
				}
				//printf("Token 2: successful!\n");
				break;
			
			/*-- Token 3/8 skipped --*/
			case 2:
			case 7:	 //printf("Token 3, 8: skipped!\n");
					 break;

			/*Token 4: JSON data (N1N2MessageTransferRequestData)*/
			case 3:
				if(idx - idx2 < 3 || (in = cJSON_ParseWithLength(tmp, idx-idx2)) == NULL || (req = n2_information_notification_parseFromJSON(in)) == NULL)
				{
					if(in)
					{
						cJSON_Delete(in);
						in = 0;
					}
					if(tmp)
					{
						free(tmp);
					}
					goto end;
				}
				//printf("Token 4: successful!\n");
				cJSON_Delete(in);
				in = 0;
				break;

			/*Token 5: Second boundary identifier*/
			case 4:
				if(!tmp || strstr(tmp, bound_ptr) == NULL)
				{
					if(req)
					{
						n2_information_notification_free(req);
						req = 0;
					}
					if(tmp)
					{
						free(tmp);
					}
					goto end;
				}
				//printf("Token 5: successful!\n");
				break;

			/*Token 6: N2 data*/
			case 5:
				if(!(idx-idx2 == 39 && memcmp(tmp, (uint8_t*)"Content-Type: application/vnd.3gpp.ngap", 39) == 0))
				{
					free(tmp);
					goto end;
				}
				//printf("Token 6: successful!\n");
				break;

			/*Token 7: Content-Id == N2*/
			case 6:
				if(idx-idx2 < strlen("Content-Id: ") + 1)
				{
					if(req)
					{
						n2_information_notification_free(req);
						req = 0;
					}
					free(tmp);
					goto end;
				}

				/*Convert raw data to string and check its semantic*/
				if((jstr = calloc(idx-idx2+1, sizeof(char))) == NULL)
				{
					if(req)
					{
						n2_information_notification_free(req);
						req = 0;
					}
					free(tmp);
					goto end;
				}
				memcpy(jstr, tmp, idx-idx2);

				if(strstr(jstr, "Content-Id: ") != jstr)
				{
					free(jstr);
					jstr = 0;
					if(req)
					{
						n2_information_notification_free(req);
						req = 0;
					}
					free(tmp);
					goto end;
				}

				if((cont_id = calloc(idx-idx2+1-strlen("Content-Id: "), sizeof(char))) == NULL)
				{
					free(jstr);
					jstr = 0;
					if(req)
					{
						n2_information_notification_free(req);
						req = 0;
					}
					free(tmp);
					tmp = 0;
					goto end;
				}

				memcpy(cont_id, jstr+strlen("Content-Id: "), idx-idx2-strlen("Content-Id: "));
				free(jstr);
				jstr = 0;
				//printf("Token 7: successful!\n");

				break;

			/*Token 9: N2 binary data*/
			case 8:
				if(!tmp)
				{
					goto end;
				}
				bin = tmp;
				tmp = 0;
				bsize = idx-idx2;
				//printf("Token 9: successful!\n");
				break;

			/*Token 10: Boundary identifier (last!)*/
			case 9:
				if(!(tmp && strstr(tmp, bound_ptr) != NULL && strlen(tmp+strlen(bound_ptr)+2) >= 2 && tmp[strlen(bound_ptr)+2] == '-' && tmp[strlen(bound_ptr)+3] == '-'))
				{
					if(cont_id)
					{
						free(cont_id);
						cont_id = 0;
					}
					if(bin)
					{
						free(bin);
						bin = 0;
					}
					if(req)
					{
						n2_information_notification_free(req);
						req = 0;
					}
					free(tmp);
					tmp = 0;
					goto end;
				}
				//printf("Token 10: successful!\n");
				break;
		}

		/*Free memory*/
		if(tmp)
		{
			free(tmp);
			tmp = 0;
		}

		/*Update address pointer for next iteration*/
		idx2 = idx + 2;
		idx = memchr(idx2, 0x0d, stream_data->size - (idx2 - stream_data->data));
		j++;
	}

end:
	/*
	 * Check 4: Was structure of the HTTP/2 DATA frame complete?
	 *
	 * 10 tokens were expected!
	 */
	if(j != 10)
	{
		printf("[LMF-sbi] Error while parsing of request data!\n");
		if(error_response(session, stream_data, 400, HTTP_400_INVFORM) != 0)
		{
			goto err;
		}
		goto fin;
	}

	/*If HTTP/2 header field user-agent: is set: AMF-... is required!*/
	if(stream_data->user_agent && strstr(stream_data->user_agent, "AMF") != stream_data->user_agent)
	{
		/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = OPTIONAL_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		if(error_response(session, stream_data, 400, HTTP_400_OPTIEINC) != 0)
		{
			goto err;
		}

		goto fin;
	}

	/*N2 Information class == NRPPa and LCS Correlation identifier has to be set (3GPP TS 29.518, 5.2.2.3.6.3)*/
	if(!req->n2_info_container || req->n2_info_container->n2_information_class != n2_information_class_NRPPa || !req->lcs_correlation_id || !req->n2_info_container->nrppa_info || !req->n2_info_container->nrppa_info->nrppa_pdu || req->n2_info_container->nrppa_info->nrppa_pdu->ngap_ie_type != ngap_ie_type_NRPPA_PDU || !req->n2_info_container->nrppa_info->nrppa_pdu->ngap_data || !req->n2_info_container->nrppa_info->nrppa_pdu->ngap_data->content_id || strcmp(req->n2_info_container->nrppa_info->nrppa_pdu->ngap_data->content_id, cont_id) != 0 || !req->n2_info_container->nrppa_info->nf_id || strcmp(LMF_NFID, req->n2_info_container->nrppa_info->nf_id) != 0)
	{
		/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			goto err;
		}

		goto fin;
	}

	/*Check, if received subscription ID correlates with the stored ID*/
#ifndef RESEARCH
	printf("[LMF-sbi] N2InfoNotify: Found UE context %s\n", ctx->supi);
#endif

	if(!req->n2_notify_subscription_id || strcmp(ctx->n2subid, req->n2_notify_subscription_id) != 0)
	{
		printf("Subscription IDs do not match: %s | %s\n", ctx->n2subid, req->n2_notify_subscription_id);

		/*HTTP error 400 BAD REQUEST + ProblemDetails.cause = MANDATORY_IE_INCORRECT (TS 29.500, 5.2.7.2)*/
		if(error_response(session, stream_data, 400, HTTP_400_MANIEINC) != 0)
		{
			goto err;
		}

		goto fin;
	}

	/*Decode received NGAP encapsulated encoded NRPPa PDU*/
	if((nrppa = getNGAPNRPPafromSBI(bin, bsize)) == NULL || (msg = decodeNRPPa(nrppa->buf, nrppa->size)) == NULL)
	{
		goto err;
	}
	free(nrppa->buf);
	free(nrppa);
	nrppa = 0;

	/*Passing decoded NRPPa message to target UNIX Domain socket*/
	if(send(ctx->ufd, &msg, sizeof(msg), MSG_NOSIGNAL) != sizeof(msg))
	{
		freeNRPPaMessage(msg);
		free(msg);
		goto err;
	}
	msg = 0;

#ifndef RESEARCH
	printf("[LMF-sbi] N2InfoNotify: Decoded NRPPa data was successfully passed to target thread\n");
#endif

	/*
	 * Initialize HTTP header fields (successful response)
	 *
	 * According to 3GPP TS 29.518, 6.1.5.5.3.1: Only one header field is expected.
	 */
	if((nva = calloc(1, sizeof(nghttp2_nv))) == NULL)
	{
		goto err;
	}
	nvlen = 1;

	/*(1) Status code*/
	nva->name = (uint8_t*) strdup(":status");
	nva->namelen = strlen(":status");
	nva->value = (uint8_t*) strdup("204");
	nva->valuelen = strlen(nva->value);

	/*Sending response data*/
	if (send_response(session, stream_data->stream_id, nva, nvlen, NULL) != 0)
	{
		goto err;
	}

fin:
	/*Free memory*/
	if(req)
	{
		n2_information_notification_free(req);
	}

	if(cont_id)
	{
		free(cont_id);
	}

	if(bin)
	{
		free(bin);
	}

	return 0;

err:

	/*Free memory*/
	if(req)
	{
		n2_information_notification_free(req);
	}

	if(cont_id)
	{
		free(cont_id);
	}

	if(jstr)
	{
		free(jstr);
	}

	if(bin)
	{
		free(bin);
	}
	return -1;
}
