#include "amfd.h"
#include "ngap-handler.h"
#include "sbi-client.h"
#include <uectx_parser.h>

/*
 * Forward declaration of callback functions
 */
int on_header_callback(nghttp2_session *session, const nghttp2_frame *frame, const uint8_t *name, size_t namelen, const uint8_t *value, size_t valuelen, uint8_t flags, void *user_data);
int on_frame_recv_callback(nghttp2_session *session, const nghttp2_frame *frame, void *user_data);

/*
 * Initialization of global tables
 */
rlist_t *ue_ctx = 0;
gnb_list_t *glist = 0;
guami_t *amf = 0;

atomic_int isPos = 0;

/*
 * @tpool_XXX: POSIX thread pools for handling incomming messages (SBI, N2)
 */
pthpool_t *tpool_sbi = 0, *tpool_n2 = 0;

static void
amfd_shutdown(int signum)
{
	int i;

	if(signum != SIGTERM && signum != SIGINT)
	{
		return;
	}
	
	/*Free global variables*/
	if(ue_ctx)
	{
		freeList(ue_ctx);
	}

	if(glist)
	{
		if(pthread_mutex_lock(&glist->lock) == 0)
		{
			for(i = 0; i < glist->cnt; i++)
			{
				if(!glist->list[i])
				{
					continue;
				}

				if(glist->list[i]->name)
				{
					free(glist->list[i]->name);
				}

				if(glist->list[i]->ipaddr)
				{
					free(glist->list[i]->ipaddr);
				}

				if(glist->list[i]->id)
				{
					if(glist->list[i]->id->choice.globalGNB_ID)
					{
						if(glist->list[i]->id->choice.globalGNB_ID->pLMNIdentity.buf)
						{
							free(glist->list[i]->id->choice.globalGNB_ID->pLMNIdentity.buf);
						}
				
						if(glist->list[i]->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf)
						{
							free(glist->list[i]->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf);
						}
				
						free(glist->list[i]->id->choice.globalGNB_ID);
					}
					free(glist->list[i]->id);
				}
				shutdown(glist->list[i]->sockfd, SHUT_WR);
				close(glist->list[i]->sockfd);
				free(glist->list[i]);
			}
			pthread_mutex_destroy(&glist->lock);
		}
		free(glist);
	}

	if(amf)
	{
		if(amf->plmn_id)
		{
			if(amf->plmn_id->mcc)
			{
				free(amf->plmn_id->mcc);
			}
			
			if(amf->plmn_id->mnc)
			{
				free(amf->plmn_id->mnc);
			}

			if(amf->plmn_id->nid)
			{
				free(amf->plmn_id->nid);
			}

			free(amf->plmn_id);
		}

		if(amf->amf_id)
		{
			free(amf->amf_id);
		}

		free(amf);
	}

	/*Destroy POSIX thread pools*/
	pthpool_destroy(tpool_sbi);
	pthpool_destroy(tpool_n2);

	printf("[AMF] -- Terminated by amfd_shutdown --\n");

	exit(EXIT_SUCCESS);
}

/*
 * triggerLMF - request LMF SBI determineLocation service for a certain UE context
 *
 */
static void*
triggerLMF(void* data)
{
	rentry_t *entry = 0;

	if((entry = data) == NULL)
	{
		goto end;
	}

	if(nlmf_loc_determineLocation(entry->imsi, entry->lcs_id, AMF_NFID) != 0)
	{
		printf("[AMF-sbi] Invoking DetermineLocation failed\n");
	}

end:
	pthread_exit(NULL);
}

/*
 * triggerPositioning - start positioning of all UEs that are attached to a gNB
 *
 * NOTE: This POSIX thread is started by the signal handler startPositioning.
 */
static void*
triggerPositioning(void* data)
{
	rentry_t *tmp = 0;
	pthread_t tid[GNB_MAX] = {-1};
	int i, num, started;

	/*Enter critical section*/
	if(pthread_mutex_lock(&ue_ctx->lock) != 0)
	{
		isPos = 0;
		pthread_exit(NULL);
	}

	/*Count available UE contexts which are associated with a gNB*/
	for(i = 0, num = 0, tmp = ue_ctx->root; i < ue_ctx->cnt; i++, tmp = tmp->next)
	{
		if(tmp && tmp->gnb)
		{
			num++;
		}
	}

	if(!num)
	{
		printf("[AMF-sbi] No assigned UE contexts available to start positioning ...\n");
		pthread_mutex_unlock(&ue_ctx->lock);
		isPos = 0;
		pthread_exit(NULL);
	}

	/*Starting of invoking positioning service of LMF*/
	for(i = 0, started = 0, tmp = ue_ctx->root; i < ue_ctx->cnt; i++, tmp = tmp->next)
	{
		if(tmp && tmp->gnb)
		{
			if(pthread_create(tid + started, NULL, triggerLMF, tmp) != 0)
			{
				continue;
			}
			started++;
		}
	}

	/*Leave critical section*/
	pthread_mutex_unlock(&ue_ctx->lock);

	printf("[AMF-sbi] -- Starting positioning service for %d/%d UEs --\n", started, num);

	/*Wait for termination of started POSIX threads*/
	for(i = 0; i < started; i++)
	{
		if(pthread_join(tid[i], NULL) != 0)
		{
			perror("pthread_join()");
			continue; //TODO: find a better fix!
		}
	}

	printf("[AMF-sbi] -- Finished positioning service for %d UEs --\n", started);
	isPos = 0;

	/*Wake up init5g: Positioning completed*/
	if(kill(getppid(), SIGUSR2) < 0)
	{
		perror("[AMF] init5g couldn't be waked up");
	}
#ifndef RESEARCH
	else
	{
		printf("[AMF] SIGUSR2 was sent to init5g (%d)\n", getppid());
	}
#endif

	pthread_exit(NULL);
}

/*
 * startPositioning - start positioning of registered UEs
 *
 * NOTE: This signal handler will be triggered by the SIGUSR2 signal.
 */
void
startPositioning(int signum)
{
	pthread_t tid;

	/*Check, if received signal is correct*/
	if(signum != SIGUSR2)
	{
		return;
	}

	/*Check, if positioning is already running*/
	if(isPos)
	{
		printf("[AMF-sbi] Positioning is already running\n");
		return;
	}
	else
	{
		isPos = 1;
	}

	/*Start separate POSIX thread to return from signal handler*/
	if(pthread_create(&tid, NULL, triggerPositioning, NULL) != 0)
	{
		isPos = 0;
	}
	pthread_detach(tid);

	return;
}

void
assignGNBtoUEctx(int signum)
{
	int i, num;

	/*Check, if received signal is correct*/
	if(signum != SIGUSR1)
	{
		return;
	}

	/*
	 * Access global gNB list: Usage of pthread_mutex_trylock instead of pthread_mutex_lock to prevent a deadlock
	 * if another POSIX thread is currently holding the lock.
	 */
	if(pthread_mutex_trylock(&glist->lock) != 0)
	{
		goto err;
	}

	/*Enter critical section*/
	if(pthread_mutex_trylock(&ue_ctx->lock) != 0)
	{
		pthread_mutex_unlock(&glist->lock);
		goto err;
	}

	if(!glist->cnt)
	{
		printf("[AMF] No gNB for assignment to %d UE contexts available ...\n", ue_ctx->cnt);
		goto end;
	}
	else if(!ue_ctx->cnt)
	{
		printf("[AMF] No UE context available for assignment to %d gNB(s)\n", glist->cnt);
		goto end;
	}

	for(i = 0, num = glist->cnt; i < GNB_MAX && num > 0; num--, i++)
	{
		/*Assign accepted gNBs to the same number of available UE contexts*/
		if(glist->list[i])
		{
			addGNBToUEctx(ue_ctx, glist->list[i], ue_ctx->cnt/glist->cnt);
		}
	}
	printf("[AMF] -- Assignment of %d gNB to %d UE contexts successfully finished --\n", glist->cnt, ue_ctx->cnt);

end:
	/*Leave critical sections*/
	pthread_mutex_unlock(&ue_ctx->lock);
	pthread_mutex_unlock(&glist->lock);

	return;

err:
	printf("[AMF] -- Assignment of accepted gNB failed --\n");
	return;
}

/*
 * http2_amfd - separate POSIX thread to handle SBI HTTP/2 requests
 */
void*
http2_amfd(void *data)
{
	/*Variables*/
	struct sigaction act;
	http2_cb_data_t *cb;

	/*Set signal handler to ignore SIGPIPE*/
	memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = SIG_IGN;
	sigaction(SIGPIPE, &act, NULL);

	/*Set callback functions for receiving and sending HTTP/2 data*/
	if((cb = (http2_cb_data_t*) calloc(1, sizeof(http2_cb_data_t))) == NULL)
	{
		perror("calloc()");
		exit(EXIT_FAILURE);
	}
	cb->on_frame_recv_callback = on_frame_recv_callback;
	cb->on_header_callback = on_header_callback;

	printf("[AMF-sbi] HTTP/2 server is starting on %s:%d ...\n", SBI_ADDR, SBI_PORT);

	/*Start server*/
	start_http2server(SBI_ADDR, SBI_PORT, AMF_TLS_KEY, AMF_TLS_CRT, cb, tpool_sbi);
}

/*
 * gnb_worker - process NGAP data of a specific SCTP stream
 *
 * NOTE: The working principle of this function is equal to the AMF function amf_handler (see /src/gNB/gNB.c).
 */
void
gnb_worker(void *data)
{
	pthpool_data_t *tpinfo = 0;
	ngapmsg_t *msg = 0;
	int ret;

	/*Checking input parameter*/
	if((tpinfo = (pthpool_data_t*) data) == NULL|| (msg = (ngapmsg_t*) tpinfo->arg) == NULL || !msg->pdu)
	{
		printf("[AMF-n2] No NGAP message data to process!\n");
		goto err;
	}

	/*
	 * Select a NGAP handler function for Initiating Messages depending on their procedure ID:
	 *
	 */
	switch(msg->pdu->present)
	{
		/*InitiatingMessage*/
		case NGAP_NGAP_PDU_PR_initiatingMessage:
			if(!msg->pdu->choice.initiatingMessage)
			{
				printf("[AMF-n2] NGAP InitiatingMessage is invalid!\n");
				goto err;
			}

			/*
			 * Further processing depends on message content type.
			 *
			 * NOTE: Here, it is distinguished between Initiating Messages that can only be initiated by
			 *	     a gNB (correct case) or by the AMF itself (error case).
			 *
			 * See: 3GPP TS 38.413, 8.1
			 */
			switch(msg->pdu->choice.initiatingMessage->value.present)
			{
				/*
				 * Correct cases
				 *
				 * Procedure can be initiated by a gNB.
				 */
				/*--- CLASS 1 ---*/
				case NGAP_InitiatingMessage__value_PR_NGSetupRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_RANConfigurationUpdate:
					break;
				case NGAP_InitiatingMessage__value_PR_HandoverCancel:
					break;
				case NGAP_InitiatingMessage__value_PR_HandoverRequired:
					break;
				case NGAP_InitiatingMessage__value_PR_PathSwitchRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceModifyIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_UEContextSuspendRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_UEContextResumeRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_UERadioCapabilityIDMappingRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionModificationRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_DistributionSetupRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_DistributionReleaseRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_MTCommunicationHandlingRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionTransportRequest:
					break;

				/*--- CLASS 2 ---*/
				case NGAP_InitiatingMessage__value_PR_UplinkRANConfigurationTransfer:
					break;
				case NGAP_InitiatingMessage__value_PR_UplinkRANStatusTransfer:
					break;
				case NGAP_InitiatingMessage__value_PR_HandoverNotify:
					break;
				case NGAP_InitiatingMessage__value_PR_InitialUEMessage:
					break;
				case NGAP_InitiatingMessage__value_PR_NASNonDeliveryIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceNotify:
					break;
				case NGAP_InitiatingMessage__value_PR_UEContextReleaseRequest:
					break;
				case NGAP_InitiatingMessage__value_PR_UplinkNASTransport:
					break;
				case NGAP_InitiatingMessage__value_PR_PWSRestartIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_PWSFailureIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_UplinkUEAssociatedNRPPaTransport:
#ifndef RESEARCH
					printf("[AMF-n2] Starting NGAP handler: Uplink UE Associated NRPPa Transport message\n");
#endif
					if((ret = handleUplinkUEAssociatedNRPPaTransport(msg)) != 0)
					{
#ifndef RESEARCH
						printf("[AMF-n2] NGAP Uplink UE Associated NRPPa Transport message couldn't be handled!\n");
#endif
					}
#ifndef RESEARCH
					else
					{
						printf("[AMF-n2] NGAP Uplink UE Associated NRPPa Transport message successfully handled!\n");
					}
#endif
					break;
				case NGAP_InitiatingMessage__value_PR_UplinkNonUEAssociatedNRPPaTransport:
					printf("[AMF-n2] Starting NGAP handler: Uplink Non UE Associated NRPPa Transport message\n");
					if((ret = handleUplinkNonUEAssociatedNRPPaTransport(msg)) != 0)
					{
						printf("[AMF-n2] NGAP Uplink Non UE Associated NRPPa Transport message couldn't be handled!\n");
					}
					else
					{
						printf("[AMF-n2] NGAP Uplink Non UE Associated NRPPa Transport message successfully handled!\n");
					}
					break;
				case NGAP_InitiatingMessage__value_PR_TraceFailureIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_CellTrafficTrace:
					break;
				case NGAP_InitiatingMessage__value_PR_LocationReport:
					break;
				case NGAP_InitiatingMessage__value_PR_LocationReportingFailureIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_UERadioCapabilityInfoIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_RRCInactiveTransitionReport:
					break;
				case NGAP_InitiatingMessage__value_PR_SecondaryRATDataUsageReport:
					break;
				case NGAP_InitiatingMessage__value_PR_UplinkRIMInformationTransfer:
					break;
				case NGAP_InitiatingMessage__value_PR_RetrieveUEInformation:
					break;
				case NGAP_InitiatingMessage__value_PR_RANCPRelocationIndication:
					break;
				case NGAP_InitiatingMessage__value_PR_UplinkRANEarlyStatusTransfer:
					break;
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionReleaseRequired:
					break;
				case NGAP_InitiatingMessage__value_PR_TimingSynchronisationStatusReport:
					break;
				
				/*
				 * Error cases
				 *
				 * Procedure can not be initiated by a gNB.
				 */
				/*--- CLASS 1 ---*/
				case NGAP_InitiatingMessage__value_PR_AMFConfigurationUpdate:
				case NGAP_InitiatingMessage__value_PR_HandoverRequest:
				case NGAP_InitiatingMessage__value_PR_InitialContextSetupRequest:
				case NGAP_InitiatingMessage__value_PR_NGReset:
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceModifyRequest:
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceReleaseCommand:
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceSetupRequest:
				case NGAP_InitiatingMessage__value_PR_UEContextModificationRequest:
				case NGAP_InitiatingMessage__value_PR_UEContextReleaseCommand:
				case NGAP_InitiatingMessage__value_PR_WriteReplaceWarningRequest:
				case NGAP_InitiatingMessage__value_PR_PWSCancelRequest:
				case NGAP_InitiatingMessage__value_PR_UERadioCapabilityCheckRequest:
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionSetupRequest:
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionReleaseRequest:
				case NGAP_InitiatingMessage__value_PR_MulticastSessionActivationRequest:
				case NGAP_InitiatingMessage__value_PR_MulticastSessionDeactivationRequest:
				case NGAP_InitiatingMessage__value_PR_MulticastSessionUpdateRequest:
				case NGAP_InitiatingMessage__value_PR_TimingSynchronisationStatusRequest:
				/*--- CLASS 2 ---*/
				case NGAP_InitiatingMessage__value_PR_DownlinkRANConfigurationTransfer:
				case NGAP_InitiatingMessage__value_PR_DownlinkRANStatusTransfer:
				case NGAP_InitiatingMessage__value_PR_DownlinkNASTransport:
				case NGAP_InitiatingMessage__value_PR_ErrorIndication:
				case NGAP_InitiatingMessage__value_PR_Paging:
				case NGAP_InitiatingMessage__value_PR_RerouteNASRequest:
				case NGAP_InitiatingMessage__value_PR_AMFStatusIndication:
				case NGAP_InitiatingMessage__value_PR_DownlinkUEAssociatedNRPPaTransport:
				case NGAP_InitiatingMessage__value_PR_DownlinkNonUEAssociatedNRPPaTransport:
				case NGAP_InitiatingMessage__value_PR_TraceStart:
				case NGAP_InitiatingMessage__value_PR_DeactivateTrace:
				case NGAP_InitiatingMessage__value_PR_LocationReportingControl:
				case NGAP_InitiatingMessage__value_PR_UETNLABindingReleaseRequest:
				case NGAP_InitiatingMessage__value_PR_OverloadStart:
				case NGAP_InitiatingMessage__value_PR_OverloadStop:
				case NGAP_InitiatingMessage__value_PR_DownlinkRIMInformationTransfer:
				case NGAP_InitiatingMessage__value_PR_UEInformationTransfer:
				case NGAP_InitiatingMessage__value_PR_ConnectionEstablishmentIndication:
				case NGAP_InitiatingMessage__value_PR_AMFCPRelocationIndication:
				case NGAP_InitiatingMessage__value_PR_HandoverSuccess:
				case NGAP_InitiatingMessage__value_PR_DownlinkRANEarlyStatusTransfer:
				case NGAP_InitiatingMessage__value_PR_MulticastGroupPaging:
				case NGAP_InitiatingMessage__value_PR_RANPagingRequest:
				case NGAP_InitiatingMessage__value_PR_PrivateMessage: /*FIXME: unknown type -> checking standard later again - if needed*/
					printf("[AMF-n2] Initiating Message type (%d) can only be initiated by the gNB!\n", msg->pdu->choice.initiatingMessage->value.present);
					goto err;

				default:
					printf("[AMF-n2] Unknown NGAP Initiating Message type!\n");
					goto err;
			}
	
			break;
		
		case NGAP_NGAP_PDU_PR_successfulOutcome:
		case NGAP_NGAP_PDU_PR_unsuccessfulOutcome:
			/*Out of interest here -> ignoring*/
			break;
	
		default:
			printf("[AMF-n2] Invalid NGAP message type (%d)\n", msg->pdu->present);
			goto err;
	}

err:
	/*Free memory*/
	if(msg)
	{
		freeNGAPMessage(msg);
	}

	return;
}

/*
 * gnb_handler - process gNB NG Setup Requests and handle their further requests as a separate POSIX thread
 */
void*
gnb_handler(void *data)
{
	/*Variables*/
	int i, j, k, ufd[2] = {0};
	gnb_t *gnb = 0;
	uint8_t buf[MSG_MAX] = {0}, *ptr = 0;
	pthread_t tid = 0;
	char plmn[7] = {0}, plmngnb[7] = {0};

	struct pollfd pfd = {0};
	struct sctp_sndrcvinfo sinfo;
	struct sockaddr_in cliaddr;
	socklen_t len = 0;

	uint8_t amf_reg = 0x2;
	uint8_t amf_ptr = 0x0;
	uint8_t amf_set[2] = {0};
	amf_set[1] = 0x40;
	NGAP_RelativeAMFCapacity_t amf_cap = 255;
	uint8_t sst = 0x01;

	NGAP_Cause_t cause;
	NGAP_TimeToWait_t ttw = NGAP_TimeToWait_v5s; /*error case: gNB has to wait at least 5s to send a new NG Setup Request message*/

	size_t size = 0;
	ngapmsg_t *msg = 0;
	rentry_t *entry = 0;
	uint64_t inv = 0;

	explicit_bzero(&cause, sizeof(cause));

	if((gnb = (gnb_t*)data) == NULL)
	{
		printf("[AMF-n2] gNB request is invalid!");
		goto fin;
	}

	/*Check if gNB list is full*/
	if(glist->cnt == GNB_MAX)
	{
		printf("[AMF-n2] Max. number of connected gNBs reached!\n");
		goto fin;
	}

	/*Receive NG Setup Request data from gNB*/
	if((size = recv(gnb->sockfd, buf, MSG_MAX, MSG_WAITALL)) < 0)
	{
		perror("recv()");
		goto fin;
	}
	else if(!size)
	{
		printf("[AMF-n2] -- Connection was closed by the target gNB (%s) --\n", gnb->ipaddr);
		goto fin;
	}

	/*Decoding NGAP message*/
	if((msg = decodeNGAP(buf, size)) == NULL)
	{
		printf("[AMF-n2] ASN.1 decoding of received NGAP message failed\n");
		goto fin;
	}

	/*
	 * Parsing NG Setup Request message and copying of gNB Global RAN ID to local gnb_t data structure
	 *
	 * TODO: According to 3GPP TS 38.413, 10, the error handling is distingueshed between Transfer Syntax, Abstract Syntax and Logical Errors
	 */
	if(msg->pdu && msg->pdu->present == NGAP_NGAP_PDU_PR_initiatingMessage)
	{
		/*Procedure Code, Criticality of message, used IE container*/
		if(msg->pdu->choice.initiatingMessage->procedureCode != NGAP_ProcedureCode_id_NGSetup || msg->pdu->choice.initiatingMessage->criticality != NGAP_Criticality_reject || msg->pdu->choice.initiatingMessage->value.present != NGAP_InitiatingMessage__value_PR_NGSetupRequest)
		{
			goto err;
		}

		/*At least 3 IEs*/
		if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count < 3 || !msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array)
		{
			goto err;
		}

		/*
		 * (1) Global RAN Node ID
		 */
		if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->id != NGAP_ProtocolIE_ID_id_GlobalRANNodeID || msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.present != NGAP_NGSetupRequestIEs__value_PR_GlobalRANNodeID)
		{
			/*Here: Abtract Syntax error because this IE is missing or on the wrong position*/
			goto err;
		}

		/* -- COPYING -- */
		if((gnb->id = calloc(1, sizeof(NGAP_GlobalRANNodeID_t))) == NULL)
		{
			goto err;
		}
		memcpy(gnb->id, &msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID, sizeof(NGAP_GlobalRANNodeID_t));

		/*Type of base station*/
		switch (msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.present)
		{
			/*gNB*/
			case NGAP_GlobalRANNodeID_PR_globalGNB_ID:
				if(!msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID)
				{
					goto err;
				}

				/*-- COPYING --*/
				if((gnb->id->choice.globalGNB_ID = calloc(1, sizeof(NGAP_GlobalGNB_ID_t))) == NULL)
				{
					goto err;
				}
				memcpy(gnb->id->choice.globalGNB_ID, msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID, sizeof(NGAP_GlobalGNB_ID_t));

				/*PLMN Identity*/
				if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.size != 3)
				{
					/*Transfer Syntax error*/
					cause.present = NGAP_Cause_PR_protocol;
					cause.choice.protocol = NGAP_CauseProtocol_transfer_syntax_error;
					goto err;
				}

				if(!msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.buf)
				{
					goto err;
				}

				/*Check, if PLMN Identity matches the PLMN of this AMF*/
				/*Swap nibbles to convert to <MCC>MNC> string*/
				ptr = (uint8_t*) msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.buf;				
				ptr[0] = ((ptr[0] >> 4) & 0x0F) | ((ptr[0] & 0x0F) << 4);
				ptr[1] = ((ptr[1] >> 4) & 0x0F) | ((ptr[1] & 0x0F) << 4);
				ptr[2] = ((ptr[2] >> 4) & 0x0F) | ((ptr[2] & 0x0F) << 4);
				
				/*Swap back, if filler bits are set (MNC == 2 digits)*/
				if((ptr[1] & 0x0F) == 0xf)
				{
					ptr[1] = ((ptr[1] >> 4) & 0x0F) | ((ptr[1] & 0x0F) << 4);
					ptr[1] &= 0x0F;
					snprintf(plmngnb, 7, "%.2x%x%.2x", ptr[0], ptr[1], ptr[2]);
				}
				else
				{
					snprintf(plmngnb, 7, "%.2x%.2x%.2x", ptr[0], ptr[1], ptr[2]);
				}
				snprintf(plmn, 6, "%s%s", AMF_MCC, AMF_MNC);

				if(strcmp(plmn, plmngnb) != 0)
				{
					goto err;
				}

				/*-- COPYING --*/
				if((gnb->id->choice.globalGNB_ID->pLMNIdentity.buf = calloc(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.size, sizeof(uint8_t))) == NULL)
				{
					goto err;
				}				
				memcpy(gnb->id->choice.globalGNB_ID->pLMNIdentity.buf, msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.buf, msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->pLMNIdentity.size);

				/*gNB Global ID -> 22 - 32 Bit*/
				if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.size > 4 || msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.size < 2)
				{
					/*Transfer Syntax error*/
					cause.present = NGAP_Cause_PR_protocol;
					cause.choice.protocol = NGAP_CauseProtocol_transfer_syntax_error;
					goto err;
				}

				/*gNB ID type*/
				switch(gnb->id->choice.globalGNB_ID->gNB_ID.present)
				{
					case NGAP_GNB_ID_PR_gNB_ID:
						if((gnb->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf = calloc(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.size, sizeof(uint8_t))) == NULL)
						{
							goto err;
						}
						memcpy(gnb->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf, msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[0]->value.choice.GlobalRANNodeID.choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf, gnb->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.size);
						break;

					case NGAP_GNB_ID_PR_choice_Extensions:
						/*TODO: Implementation open*/goto err;
						break;

					default:
						goto err;
				}

				break;

			case NGAP_GlobalRANNodeID_PR_globalNgENB_ID:
				/*TODO: Implementation open*/goto err;
				break;

			case NGAP_GlobalRANNodeID_PR_globalN3IWF_ID:
				/*TODO: Implementation open*/goto err;
				break;
			case NGAP_GlobalRANNodeID_PR_choice_Extensions:
				/*TODO: Implementation open*/goto err;
				break;
			
			default:
				goto err;
		}

		/*(2) RAN Node name*/
		if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count > 3 && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->id == NGAP_ProtocolIE_ID_id_RANNodeName && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.present == NGAP_NGSetupRequestIEs__value_PR_RANNodeName)
		{
			if(!msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.choice.RANNodeName.buf || msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.choice.RANNodeName.size < 1)
			{
				goto err;
			}

			/*-- COPYING --*/
			if((gnb->name = calloc(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.choice.RANNodeName.size + 1, sizeof(char))) == NULL)
			{
				goto err;
			}
			memcpy(gnb->name, msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.choice.RANNodeName.buf, msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.choice.RANNodeName.size);
		}
		
		/*If (2) corresponds to Supported TA List IE*/
		else if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->id == NGAP_ProtocolIE_ID_id_SupportedTAList && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[1]->value.present == NGAP_NGSetupRequestIEs__value_PR_SupportedTAList)
		{
			/*TODO: Implementation open!*/
		}
		
		else
		{
			goto err;
		}

		/*(3) Supported TA List*/
		if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->id == NGAP_ProtocolIE_ID_id_SupportedTAList && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.present == NGAP_NGSetupRequestIEs__value_PR_SupportedTAList)
		{
			if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.size >= msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.count && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.count > 0)
			{
				/*TA List Item i*/
				for(i = 0; i < msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.count; i++)
				{
					/*Break if item is not available ...*/
					if(!msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i])
					{
						goto err;
					}

					/*(3.1) Tracking Area Code*/
					if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->tAC.size != 3 || !msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->tAC.buf)
					{
						goto err;
					}

					/*TODO: Add a checking mechanism here, if TAC is okay!*/

					/*(3.2) Broadcast PLMN List*/
					if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.size >= msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.count && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.count > 0 && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array)
					{
						/*PLMN List Item j*/
						for(j = 0; j < msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.count; j++)
						{
							/*Break if item is not available ...*/
							if(!msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j])
							{
								goto err;
							}

							/*PLMN Identity*/
							if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->pLMNIdentity.size != 3)
							{
								/*Transfer Syntax error*/
								cause.present = NGAP_Cause_PR_protocol;
								cause.choice.protocol = NGAP_CauseProtocol_transfer_syntax_error;
								goto err;
							}
							else if(!msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->pLMNIdentity.buf)
							{
								goto err;
							}

							/*Slice Support List*/
							if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.size >= msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.count && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.count > 0 && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.array)
							{
								/*Slice Support Item k*/
								for(k = 0; k < msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.count; k++)
								{
									/*Break, if item is not available ...*/
									if(!msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.array[k])
									{
										goto err;
									}

									/*S-NSSAI - SST*/
									if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.array[k]->s_NSSAI.sST.size != 1 || !msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.array[k]->s_NSSAI.sST.buf)
									{
										goto err;
									}

									/*S-NSSAI - SD (optional)*/
									else if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.array[k]->s_NSSAI.sD && (msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.array[k]->s_NSSAI.sD->size != 3 || !msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.choice.SupportedTAList.list.array[i]->broadcastPLMNList.list.array[j]->tAISliceSupportList.list.array[k]->s_NSSAI.sD->buf))
									{
										goto err;
									}
								}
							}
							else
							{
								goto err;
							}

						}
					}
					else
					{
						goto err;
					}

				}
			}
			else
			{
				goto err;
			}
		}

		/*If (3) corresponds to Default Paging DRX*/
		else if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->id == NGAP_ProtocolIE_ID_id_DefaultPagingDRX && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[2]->value.present == NGAP_NGSetupRequestIEs__value_PR_PagingDRX)
		{
			/*TODO: Implementation open*/
		}

		else
		{
			goto err;
		}

		/*(4) Default Paging DRX*/
		if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count > 3 && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[3]->id == NGAP_ProtocolIE_ID_id_DefaultPagingDRX && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[3]->value.present == NGAP_NGSetupRequestIEs__value_PR_PagingDRX)
		{
			switch(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[3]->value.choice.PagingDRX)
			{
				case NGAP_PagingDRX_v32:
				case NGAP_PagingDRX_v64:
				case NGAP_PagingDRX_v128:
				case NGAP_PagingDRX_v256:
					break;
				
				default:
					goto err;
			}
		}

		/*If (4) corresponds to UE Retention Information*/
		else if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count > 3 && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[3]->id == NGAP_ProtocolIE_ID_id_UERetentionInformation && msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.array[3]->value.present == NGAP_NGSetupRequestIEs__value_PR_UERetentionInformation)
		{
			/*TODO: Implementation open*/
		}
		else
		{
			goto err;
		}

		/*NOTE: Further IEs will not be checked here...*/
		if(msg->pdu->choice.initiatingMessage->value.choice.NGSetupRequest.protocolIEs.list.count > 4)
		{
			/*TODO: Implementation open!*/
			goto err;
		}
	}
	else
	{
		goto err;
	}

	/*Free memory of decoded NGAP message*/
	freeNGAPMessage(msg);
	msg = 0;

	/*Add gNB to the global gNB list*/
	if(pthread_mutex_lock(&glist->lock) != 0)
	{
		perror("pthread_mutex_lock()");
		goto err;
	}

	glist->list[glist->cnt++] = gnb;

	pthread_mutex_unlock(&glist->lock);

	/*Generation of a NGAP NG Setup Response Message*/
	if((msg = NGAP_NG_Setup_Response(AMF_NAME, gnb->id->choice.globalGNB_ID->pLMNIdentity.buf, &amf_reg, amf_set, &amf_ptr, &amf_cap, &sst)) == NULL)
	{
		goto err;
	}
	if(!msg->enc || !msg->size)
	{
		goto err;
	}

	/*Send NG Setup Response message to target gNB*/
	if(send(gnb->sockfd, msg->enc, msg->size, MSG_DONTWAIT | MSG_NOSIGNAL) != msg->size)
	{
		perror("send()");
		goto err;
	}
	freeNGAPMessage(msg);
	msg = 0;

	/*Output: gNB was successfully accepted!*/
	if(gnb->name)
	{
		printf("\n[AMF-n2] gNB (%s) accepted from %s!\n", gnb->name, gnb->ipaddr);
	}
	else
	{
		printf("\n[AMF-n2] gNB accepted from %s!\n", gnb->ipaddr);
	}

	/*Wake up init5g: UE(s) can be assigned*/
	if(kill(getppid(), SIGUSR1) < 0)
	{
		perror("[AMF] init5g couldn't be waked up");
	}
#ifndef RESEARCH
	else
	{
		printf("[AMF] SIGUSR1 was sent to init5g (%d)\n", getppid());
	}
#endif

	/*
	 * Waiting loop for incoming data from gNB
	 */
	while(1)
	{
		pfd.fd = gnb->sockfd;
		pfd.events = POLLIN;

		/*Monitor the gNB's file descriptor*/
		if(poll(&pfd, 1, -1) != 1)
		{
			if(errno == EINTR)
			{
				printf("[AMF-n2] Monitoring of gNB (%s) connection was interrupted!\n", gnb->name);
				continue;
			}
			break;
		}

		/*Process data if target file descriptor is readable*/
		j = 0;

		/*Clear SCTP message info structure*/
		memset(&sinfo, 0, sizeof(struct sctp_sndrcvinfo));
		len = sizeof(cliaddr);

again:
		/*Reading encoded NGAP data from socket*/
		k = 0;
		if((i=sctp_recvmsg(gnb->sockfd, buf + j, MSG_MAX, (struct sockaddr*) &cliaddr, &len, &sinfo, &k)) < 0)
		{
			perror("recv()");
			if(errno == ECONNRESET)
			{
				break;
			}
			continue;
		}
		j += i;

		/*Check if all data chunks have been received...*/ //TODO: Take stream ID into account!! It could be that the next chunk is gotten from another stream (?!)
		if(!(k & MSG_EOR) && i && j < MSG_MAX)
		{
#ifndef RESEARCH
			printf("Received data chunk (%d B) from stream %d (%d flag)\n", i, sinfo.sinfo_stream, k);
#endif
			goto again;
		}
		else if(!(k & MSG_EOR) && i && j >= MSG_MAX)
		{
			printf("[AMF-n2] NGAP data exceeds buffer size - dropping\n");
			continue;
		}

		/*Check if connection was closed*/
		if(!i)
		{
			printf("[AMF-n2] -- Connection was closed by the target gNB (%s) --\n", gnb->name);
			break;
		}

		/*Decode NGAP message*/
		if((msg = decodeNGAP(buf, j)) == NULL)
		{
			printf("[AMF-n2] NGAP message couldn't be decoded (%d B)\n", j);
			continue;
		}

		/* TODO: Reserving SCTP output stream number if received NGAP message is Class 1!
		 *
		 * Pass data (here: heap address) to the target POSIX thread to which the input stream ID is assigned.
		 *
		 * NOTE: If UNIX Domain socket was closed in the target thread, SIGPIPE is normally triggered.
		 *		 Therefore, the flag MSG_NOSIGNAL is set, to return an error instead.
		 *		 Afterwards, everything is closed and a new POSIX thread will be created to process data.
		 */
		if(isReserved(&gnb->con, sinfo.sinfo_stream))
		{
			if(send(gnb->con.in_list[sinfo.sinfo_stream][1], &msg, sizeof(msg), MSG_DONTWAIT | MSG_NOSIGNAL) < 0)
			{
				perror("[AMF-n2] send() failed during pass NGAP to target UNIX Domain socket");
			}

			/*Skip creation of a new POSIX thread*/
			else
			{
				msg = 0;
				continue;
			}
		}

		/*Adding the request to the POSIX thread pool*/
		if(!pthpool_add_job(tpool_n2, gnb_worker, msg))
		{
			printf("[AMF-n2] Encoded NGAP message couldn't add to the target thread pool\n");
			freeNGAPMessage(msg);
			msg = 0;
			continue;
		}
		msg = 0;
	}

	/*-- Only reached if connection was closed by target gNB --*/
	if(gnb)
	{
		/*Remove gNB reference from UE context list*/
		deleteGNBFromList(ue_ctx, gnb);

		if(gnb->ipaddr)
		{
			free(gnb->ipaddr);
		}

		if(gnb->name)
		{
			free(gnb->name);
		}
		close(gnb->sockfd);

		if(gnb->id)
		{
			if(gnb->id->choice.globalGNB_ID)
			{
				if(gnb->id->choice.globalGNB_ID->pLMNIdentity.buf)
				{
					free(gnb->id->choice.globalGNB_ID->pLMNIdentity.buf);
				}

				if(gnb->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf)
				{
					free(gnb->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf);
				}

				free(gnb->id->choice.globalGNB_ID);
			}
			free(gnb->id);
		}

		/*Remove gNB from global gNB list*/
		if(pthread_mutex_lock(&glist->lock) != 0)
		{
			perror("pthread_mutex_lock()");
			free(gnb);
			pthread_exit(NULL);
		}

		for(i = 0; i < glist->cnt; i++)
		{
			if(glist->list[i] == gnb)
			{
				/*If found: decrease the list index of all higher placed gNBs by 1*/
				for(j = i; j < glist->cnt-1; j++)
				{
					glist->list[j] = glist->list[j+1];
				}
				glist->cnt--;
				free(gnb);
				gnb = 0;
			}
		}

		pthread_mutex_unlock(&glist->lock);

		if(gnb)
		{
			free(gnb);
		}
	}

	pthread_exit(NULL);

err:
	printf("\n[AMF-n2] gNB rejected from %s\n", gnb->ipaddr);

	if(msg->pdu || msg->enc)
	{
		freeNGAPMessage(msg);
	}
	msg = 0;

	/*
	 * If error cause was not initialized:
	 *
	 * Set NGAP_Cause to: Miscellaneous Cause + Unspecified Failure reason (3GPP TS 38.413, 9.3.1.2)
	 */
	if(!cause.present)
	{
		cause.present = NGAP_Cause_PR_misc;
		cause.choice.misc = NGAP_CauseMisc_unspecified;
	}

	/*
	 * Send NG Setup Failure message to client
	 *
	 * NOTE: The elements of @diagnostics has to be allocated dynamically because NG_Setup_Failure only copies the references!
	 */
	if((msg = NGAP_Setup_Failure(&cause, &ttw, NULL)) == NULL || !msg->enc || !msg->size)
	{
		printf("NGAP_Setup_Failure()\n");
	}

	if(msg && send(gnb->sockfd, msg->enc, msg->size, MSG_DONTWAIT | MSG_NOSIGNAL) != msg->size)
	{
		perror("send()");
	}
#ifdef DEBUG
	printf("NGAP Message Response was sent [%d B]\n", msg->size);
#endif
fin:
	/*Free memory*/
	if(gnb)
	{
		/*Remove gNB reference from UE context list*/
		deleteGNBFromList(ue_ctx, gnb);

		if(gnb->name)
		{
			free(gnb->name);
		}

		if(gnb->ipaddr)
		{
			free(gnb->ipaddr);
		}

		if(gnb->id)
		{
			if(gnb->id->choice.globalGNB_ID)
			{
				if(gnb->id->choice.globalGNB_ID->pLMNIdentity.buf)
				{
					free(gnb->id->choice.globalGNB_ID->pLMNIdentity.buf);
				}

				if(gnb->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf)
				{
					free(gnb->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf);
				}

				free(gnb->id->choice.globalGNB_ID);
			}
			free(gnb->id);
		}
		close(gnb->sockfd);
		free(gnb);
	}

	pthread_exit(NULL);
}

/*
 * main - entry point of the program
 */
int
main(int argc, char **argv)
{
	/*Variables*/
	int sfd, cfd, ret, flags, i;
	size_t npool = 0;
	struct sockaddr_in srvaddr, cliaddr;

	struct sctp_event_subscribe event;
	struct sctp_paddrparams heartbeat;
	struct sctp_rtoinfo rtoinfo;
	struct sctp_status status;
	struct sctp_initmsg initmsg;

	struct sigaction act;

	pthread_t tid = 0;
	pthread_t gtid[GNB_MAX] = {0};
	const int enable = 1;
	socklen_t ssize;
	gnb_t *gnb = 0;

	uint8_t buf[MSG_MAX];

	struct hostent *hn = 0;
	in_addr_t ip4 = inet_addr(SBI_ADDR);
	struct rlimit lim = {0};

	ue_entry_t *list = 0;
	size_t num = 0;
	rentry_t *entry = 0;
	uint64_t inv = 0;
	uint8_t *ptr = 0;

	pthread_mutexattr_t attr;
#ifdef RT
	struct sched_param sp = {
		.sched_priority = 2
	};
#endif

	/*Check passed input parameter*/
	if(argc != 3)
	{
		printf("Usage: %s <UE-context path> <npool>", argv[0]);
		return EXIT_FAILURE;
	}
	else if(strstr(argv[1], "ue_ctx-") == NULL)
	{
		printf("[AMF] Invalid UE context file path: %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	if((npool = atoi(argv[2])) <= 1)
	{
		printf("[AMF] Invalid thread pool size: %ld (npool > 1)\n", npool);
		return EXIT_FAILURE;
	}
#ifdef RT
	/*Set RT priority*/
	if(sched_setscheduler(getpid(), SCHED_RR, &sp) != 0)
	{
		printf("[AMF] RT priority could not be set: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	printf("[AMF] Started with: %s (UE context list), %ld (thread pool size), RT_PREEMPT\n", argv[1], npool);
#else
	printf("[AMF] Started with: %s (UE context list), %ld (thread pool size)\n", argv[1], npool);
#endif

	/*Check if hostname of this server is set to @AMF_HNAME*/
	if((hn = gethostbyaddr((void*) &ip4, sizeof(in_addr_t), AF_INET)) == NULL)
	{
		printf("[AMF] Hostname of server address could not be resolved: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	if(strcmp(hn->h_name, AMF_HNAME) != 0)
	{
		printf("[AMF] Hostname of this server does not match %s\n", AMF_HNAME);
		return EXIT_FAILURE;
	}
#ifdef DEBUG
	/*Look up IPv4 address of LMF*/
        if((hn = gethostbyname(LMF_HNAME)) == NULL)
        {
                printf("[AMF] Hostname of LMF not available: %s\n", strerror(errno));
                return EXIT_FAILURE;
        }

        if(inet_ntop(AF_INET, hn->h_addr_list[0], lmf_ip, 50) == NULL)
        {
                printf("[AMF] Hostname of LMF could not be converted to IPv4 address: %s\n", strerror(errno));
                return EXIT_FAILURE;
        }
#endif
	/*Increase maximum limit of open file descriptors*/
	if(getrlimit(RLIMIT_NOFILE, &lim) != 0)
	{
		printf("[AMF] Limit for open file descriptors couldn't obtained: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	if(lim.rlim_max < FD_OPEN_MAX)
	{
		printf("[AMF] Maximum limit of opened file descriptors can not be set: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	if(lim.rlim_cur < FD_OPEN_MAX)
	{
		lim.rlim_cur = FD_OPEN_MAX;
		if(setrlimit(RLIMIT_NOFILE, (const struct rlimit*) &lim) != 0)
		{
			printf("[AMF] Limit of opened file descriptors can not be set: %s\n", strerror(errno));
			return EXIT_FAILURE;
		}
	}

	/*
	 * Set required signal handlers:
	 *
	 * SIGINT, SIGTERM: catched by the signal handler amfd_shutdown
	 * SIGUSR1: catched by the signal handler assignGNBtoUEctx
	 * SIGUSR2: catched by the signal handler startPositioning
	 */
	memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = amfd_shutdown;
	act.sa_flags = SA_RESTART;
	if(sigemptyset(&act.sa_mask) != 0 || sigaction(SIGTERM, &act, NULL) != 0 || sigaction(SIGINT, &act, NULL) != 0)
	{
		perror("sigaction()");
		return EXIT_FAILURE;
	}

	act.sa_handler = assignGNBtoUEctx;
	if(sigaction(SIGUSR1, &act, NULL) != 0)
	{
		perror("sigaction()");
		return EXIT_FAILURE;
	}

	act.sa_handler = startPositioning;
	if(sigaction(SIGUSR2, &act, NULL) != 0)
	{
		perror("sigaction()");
		return EXIT_FAILURE;
	}

	/*Initialize POSIX thread pools*/
	if((tpool_n2 = pthpool_create(npool/2)) == NULL || (tpool_sbi = pthpool_create(npool/2)) == NULL)
	{
		printf("[AMF] POSIX thread pool(s) couldn't be initialized\n");
		return EXIT_FAILURE;
	}

	/*Initialize AMF GUAMI*/
	if((amf = calloc(1, sizeof(guami_t))) == NULL || (amf->plmn_id = calloc(1, sizeof(plmn_id_nid_t))) == NULL)
	{
		if(amf)
		{
			free(amf);
			amf = 0;
		}
		goto err;
	}
	amf->plmn_id->mcc = strdup(AMF_MCC);
	amf->plmn_id->mnc = strdup(AMF_MNC);
	amf->amf_id = strdup(AMF_GUAMI_ID);

	/*Get UE context entries from file*/
	getUECTXfromFile(argv[1], &list, &num);
	if(!num || !list)
	{
		printf("[AMF] No UE context entries in %s found\n", argv[1]);
		goto err;
	}

	/*Initialize global UE context list*/
	if(!(ue_ctx = (rlist_t*) calloc(1, sizeof(rlist_t))))
	{
		perror("calloc()");
		return EXIT_FAILURE;
	}

	/*Initialize mutex of UE context list*/
#ifdef DEBUG
	if(pthread_mutexattr_init(&attr) != 0)
	{
		printf("[AMF] pthread_mutexattr_init(): %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	if(pthread_mutexattr_setprotocol(&attr, PTHREAD_PRIO_INHERIT) != 0)
	{
		printf("[AMF] pthread_mutexattr_setprotocol(): %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
#endif
	if(pthread_mutex_init(&ue_ctx->lock, NULL) != 0)
	{
		perror("[AMF] pthread_mutex_init()");
		goto err;
	}

	/*Map UE context entries (from file) to global UE context list*/
	for(i = 0; i < num; i++)
	{
		if((entry = calloc(1, sizeof(rentry_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
		if(pthread_mutex_init(&entry->lock, NULL) != 0)
		{
			perror("pthread_mutex_init()");
			goto err;
		}

		/*Copy pointers*/
		entry->lcs_id = list[i].lcsid;
		entry->imsi = list[i].supi;
	
		if((entry->ngap_amf_id.buf = calloc(5, sizeof(uint8_t))) == NULL)
		{
			perror("calloc()");
			goto err;
		}
	
		/*
	 	* Copy AMF UE NGAP ID to target buffer
	 	*
	 	* NOTE: For converting to Big Endian, htobe64 is used because it is usable for 64 Bit integers.
	 	*		 However, this function is not POSIX-compliant. Therefore, this program is not portable anymore ...
	 	*/
		entry->ngap_amf_id.size = 5;
		inv = htobe64((uint64_t)list[i].ngap_amf);
		ptr = (uint8_t*) &inv;
		memcpy(entry->ngap_amf_id.buf, ptr + 3, 5); /*Ignore the first three leading bytes because AMF UE NGAP ID has a mximum size of five byte*/
	
		entry->ngap_ran_id = list[i].ngap_ran;

		/*Set entry to complete after subscription for N2 data AND a gNB is available*/
		entry->isComplete = false;

		/*Add entry to global list*/
		if(addEntry(ue_ctx, entry) != 0)
		{
			goto err;
		}
	}

	/*Free UE context list that was obtained from file*/
	free(list);
	list = 0;
	num = 0;

	/*Initialize global gNB list*/
	if(!(glist = (gnb_list_t*) calloc(1, sizeof(gnb_list_t))))
	{
		perror("calloc()");
		goto err;
	}

	/*Initialize semaphore of global gNB list*/
	if(pthread_mutex_init(&glist->lock, NULL) != 0)
	{
		perror("pthread_mutex_init()");
		goto err;
	}

	/*N2: SCTP socket initialization*/
	if((sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP)) < 0)
	{
		perror("socket()");
		goto err;
	}

	memset(&event,      0, sizeof(struct sctp_event_subscribe));
	memset(&heartbeat,  0, sizeof(struct sctp_paddrparams));
	memset(&rtoinfo,    0, sizeof(struct sctp_rtoinfo));
	memset(&initmsg,    0, sizeof(struct sctp_initmsg));

	/*Set SCTP heartbeat rate*/
	heartbeat.spp_flags = SPP_HB_ENABLE;
	heartbeat.spp_hbinterval = 4500;
	heartbeat.spp_pathmaxrxt = 1;

	rtoinfo.srto_max = 2000;

	/*Enable receiving of stream ID*/
	event.sctp_data_io_event = 1;

	/*Set maximum no. of input and output streams*/
	initmsg.sinit_max_instreams = AMF_SCTP_IN;
	initmsg.sinit_num_ostreams = AMF_SCTP_OUT;

	/*Assign heartbeat rate to socket*/
	if(setsockopt(sfd, SOL_SCTP, SCTP_PEER_ADDR_PARAMS , &heartbeat, sizeof(heartbeat)) != 0)
	{
		perror("setsockopt()");
		goto err;
	}

	/*Assign rto_max*/
	if(setsockopt(sfd, SOL_SCTP, SCTP_RTOINFO , &rtoinfo, sizeof(rtoinfo)) != 0)
	{
		perror("setsockopt()");
		goto err;
	}

	/*Assign event for data I/O*/
	if(setsockopt(sfd, IPPROTO_SCTP, SCTP_EVENTS, &event, sizeof(struct sctp_event_subscribe)) < 0)
	{
		perror("setsockopt()");
		goto err;
	}

	/*Assign number of streams for input and output*/
	if (setsockopt(sfd, IPPROTO_SCTP, SCTP_INITMSG, &initmsg, sizeof(initmsg)))
	{
		perror("setsockopt()");
		goto err;
	}

	/*Enable reuse of target socket address structure*/
	if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
	{
		perror("setsockopt()");
		goto err;
	}

	if (setsockopt(sfd, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) < 0)
	{
		perror("setsockopt()");
		goto err;
	}

	/*N2: Initialization of socket address structure*/
	explicit_bzero(&srvaddr, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(N2_PORT);
	srvaddr.sin_addr.s_addr = inet_addr(N2_ADDR);

	/*N2: Binding socket address*/
	if(bind(sfd, (SA*) &srvaddr, sizeof(srvaddr)) < 0)
	{
		perror("bind()");
		goto err;
	}

	/*N2: Creation of waiting queue*/
	if(listen(sfd, LISTENQ) < 0)
	{
		perror("listen()");
		goto err;
	}

	/*SBI: Start HTTP/2 server as seperate POSIX thread*/
	if((ret = pthread_create(&tid, NULL, http2_amfd, NULL)) != 0)
	{
		errno = ret;
		perror("pthread_create()");
		goto err;
	}
	pthread_detach(tid);

	/*Server loop*/
	printf("[AMF-n2] SCTP server is starting on %s:%d\n", N2_ADDR, N2_PORT);
	while(1)
	{
		bzero(&cliaddr, sizeof(cliaddr));
		ssize = sizeof(cliaddr);
		memset(&status, 0, sizeof(struct sctp_status));

		if((cfd = accept(sfd, (struct sockaddr*) &cliaddr, &ssize)) < 0)
		{
			perror("accept()");
			goto err;
		}

		/*Get number of input and output streams*/
		i = sizeof(status);
		if (getsockopt(cfd, IPPROTO_SCTP, SCTP_STATUS, &status, &i) < 0)
		{
			perror("getsockopt()");
			close(cfd);
			continue;
		}

		/*Create new gNB entity*/
		if((gnb = calloc(1, sizeof(gnb_t))) == NULL)
		{
			perror("calloc()");
			close(cfd);
			continue;
		}

		/*Store connected gNB data*/
		if(initsctpcli(&gnb->con, status.sstat_instrms, status.sstat_outstrms) != 0)
		{
			close(cfd);
			free(gnb);
			continue;
		}
		gnb->sockfd = cfd;
		gnb->ipaddr = strdup(inet_ntoa(cliaddr.sin_addr));

		/*
		 * Start separate POSIX thread to handle the target gNB until it closes the conntection.
		 *
		 * NOTE:
		 */
		if((ret = pthread_create(gtid + glist->cnt, NULL, gnb_handler, (void*) gnb)) != 0)
		{
			errno = ret;
			perror("pthread_create()");
			goto err;
		}
		pthread_detach(gtid[glist->cnt]);
	}

	return EXIT_SUCCESS;

err:

	/*Free memory*/
	if(list)
	{
		freeUECTXList(list, num);
	}

	if(ue_ctx)
	{
		freeList(ue_ctx);
	}

	if(glist)
	{
		if(pthread_mutex_lock(&glist->lock) == 0)
		{
			for(i = 0; i < glist->cnt; i++)
			{
				if(!glist->list[i])
				{
					continue;
				}

				if(glist->list[i]->name)
				{
					free(glist->list[i]->name);
				}

				if(glist->list[i]->ipaddr)
				{
					free(glist->list[i]->ipaddr);
				}

				if(glist->list[i]->id)
				{
					if(glist->list[i]->id->choice.globalGNB_ID)
					{
						if(glist->list[i]->id->choice.globalGNB_ID->pLMNIdentity.buf)
						{
							free(glist->list[i]->id->choice.globalGNB_ID->pLMNIdentity.buf);
						}
				
						if(glist->list[i]->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf)
						{
							free(glist->list[i]->id->choice.globalGNB_ID->gNB_ID.choice.gNB_ID.buf);
						}
				
						free(glist->list[i]->id->choice.globalGNB_ID);
					}
					free(glist->list[i]->id);
				}
				close(glist->list[i]->sockfd);
				free(glist->list[i]);
			}
			pthread_mutex_destroy(&glist->lock);
		}
		free(glist);
	}
	
	if(amf)
	{
		if(amf->plmn_id)
		{
			if(amf->plmn_id->mcc)
			{
				free(amf->plmn_id->mcc);
			}
			
			if(amf->plmn_id->mnc)
			{
				free(amf->plmn_id->mnc);
			}

			if(amf->plmn_id->nid)
			{
				free(amf->plmn_id->nid);
			}

			free(amf->plmn_id);
		}

		if(amf->amf_id)
		{
			free(amf->amf_id);
		}

		free(amf);
	}

	/*Destroy POSIX thread pools*/
	pthpool_destroy(tpool_sbi);
	pthpool_destroy(tpool_n2);

	/*Terminate process*/
	exit(EXIT_FAILURE);
}
