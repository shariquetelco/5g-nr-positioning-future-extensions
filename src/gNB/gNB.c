/*
 * gNB - implementation of a gNB that supports selected positioning functionalities
 *
 * created: 05/27/2024, NK
 * last modified: 07/22/2024, NK
 */

#include "gNB.h"
#include "ngap-handler.h"
#include "nrppa-ecid.h"
#include "uectx_parser.h"

/*
 * Global variables
 */
amf_t *amf = 0;
gnb_t *gnb = 0;
gnb_ue_ctx_t ngap_ids[GNB_MAX] = {0};
ecid_ran_list_t *ran_list = 0;
ecid_report_t report_list[ECID_SESS_MAX][ECID_SESS_MAX];
int ecid_fd[ECID_NUM_PARAMS] = {-1};
pthpool_t *tpool_n2 = 0, *tpool_long = 0;

/*
 * gnb_shutdown - signal handler to free global list(s) before termination
 */
static void
gnb_shutdown(int signum)
{
	int i, j;

	if(signum != SIGTERM && signum != SIGINT)
	{
		return;
	}

	/*Destroy POSIX thread pools*/
	pthpool_destroy(tpool_n2);
	pthpool_destroy(tpool_long);

	/*Free memory*/
	if(amf)
	{
		if(amf->name)
		{
			free(amf->name);
		}
		free(amf);
	}

	if(ran_list)
	{
		sem_destroy(&ran_list->lock);
		free(ran_list);
	}

	for(i = 0; i < ECID_SESS_MAX; i++)
	{
		for(j = 0; j < ECID_SESS_MAX; j++)
		{
			sem_destroy(&report_list[i][j].lock);
		}
	}

	if(gnb)
	{
		free(gnb);
	}

	/*Close all opened file descriptors*/
	for(i = 0; i < ECID_NUM_PARAMS; i++)
	{
		if(ecid_fd[i] >= 0)
		{
			close(ecid_fd[i]);
		}
	}

	exit(EXIT_SUCCESS);
}

/*
 * ue_handler - handle data from a UE
 *
 * NOTE: This function is executed as a separate POSIX thread.
 */
void*
ue_handler(void *data)
{
	/*
	 * NOTE: This handler will be implemented in future.
	 */
	pthread_exit(NULL);
}


/*
 * amf_handler - handle NGAP requests from target AMF
 *
 * NOTE: This function is executed as a separate POSIX thread using a thread pool.
 * NOTE: This POSIX thread shall create a second POSIX thread that is listening to additional incoming data from the target AMF (e.g. E-CID measurement termination command)!
 */
void
amf_handler(void *data)
{
	pthpool_data_t *tpinfo = 0;
	ngapmsg_t *msg = 0;
	int ret = 0;

	/*Checking input parameter*/
	if((tpinfo = (pthpool_data_t*) data) == NULL || (msg = (ngapmsg_t*) tpinfo->arg) == NULL || !msg->pdu)
	{
		printf("[gNB-n2] No NGAP message data to process!\n");
		goto end;
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
				printf("[gNB-n2] NGAP InitiatingMessage is invalid!\n");
				break;
			}

			/*
			 * Further processing depends on message content type.
			 *
			 * NOTE: Here, it is distinguished between Initiating Messages that can only be initiated by
			 *	     the AMF (correct case) or by the gNB itself (error case).
			 *
			 * See: 3GPP TS 38.413, 8.1
			 */
			switch(msg->pdu->choice.initiatingMessage->value.present)
			{
				/*
				 * Correct cases
				 *
				 * Procedure can be initiated by the AMF.
				 */
				/*--- CLASS 1 ---*/
				case NGAP_InitiatingMessage__value_PR_AMFConfigurationUpdate:
					break;
					
				case NGAP_InitiatingMessage__value_PR_HandoverRequest:
					break;
				
				case NGAP_InitiatingMessage__value_PR_InitialContextSetupRequest:
					break;
				
				case NGAP_InitiatingMessage__value_PR_NGReset:
					break;
					
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceModifyRequest:
					break;	

				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceReleaseCommand:
					break;

				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceSetupRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_UEContextModificationRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_UEContextReleaseCommand:
					break;

				case NGAP_InitiatingMessage__value_PR_WriteReplaceWarningRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_PWSCancelRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_UERadioCapabilityCheckRequest:
					break;
					
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionSetupRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_BroadcastSessionReleaseRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_MulticastSessionActivationRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_MulticastSessionDeactivationRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_MulticastSessionUpdateRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_TimingSynchronisationStatusRequest:
					break;

				/*--- CLASS 2 ---*/
				case NGAP_InitiatingMessage__value_PR_DownlinkRANConfigurationTransfer:
					break;

				case NGAP_InitiatingMessage__value_PR_DownlinkRANStatusTransfer:
					break;

				case NGAP_InitiatingMessage__value_PR_DownlinkNASTransport:
					break;
					
				case NGAP_InitiatingMessage__value_PR_ErrorIndication:
					break;

				case NGAP_InitiatingMessage__value_PR_Paging:
					break;

				case NGAP_InitiatingMessage__value_PR_RerouteNASRequest:
					break;
				
				case NGAP_InitiatingMessage__value_PR_AMFStatusIndication:
					break;

				case NGAP_InitiatingMessage__value_PR_DownlinkUEAssociatedNRPPaTransport:
#ifndef RESEARCH
					printf("[gNB-n2] Starting NGAP handler: Downlink UE Associated NRPPa Transport message\n");
#endif
					if((ret = handleDownlinkUEAssociatedNRPPaTransport(msg)) < 0)
					{
						printf("[gNB-n2] NGAP Downlink UE Associated NRPPa Transport message couldn't be handled!\n");
					}
#ifndef RESEARCH
					else
					{
						printf("[gNB-n2] NGAP Downlink UE Associated NRPPa Transport message successfully handled!\n");
					}
#endif
					break;

				case NGAP_InitiatingMessage__value_PR_DownlinkNonUEAssociatedNRPPaTransport:
#ifndef RESEARCH
					printf("[gNB-n2] Starting NGAP handler: Downlink Non UE Associated NRPPa Transport message\n");
#endif
					if((ret = handleDownlinkNonUEAssociatedNRPPaTransport(msg)) < 0)
					{
						printf("[gNB-n2] NGAP Downlink Non UE Associated NRPPa Transport message couldn't be handled!\n");
					}
					break;

				case NGAP_InitiatingMessage__value_PR_TraceStart:
					break;

				case NGAP_InitiatingMessage__value_PR_DeactivateTrace:
					break;

				case NGAP_InitiatingMessage__value_PR_LocationReportingControl:
					break;

				case NGAP_InitiatingMessage__value_PR_UETNLABindingReleaseRequest:
					break;

				case NGAP_InitiatingMessage__value_PR_OverloadStart:
					break;

				case NGAP_InitiatingMessage__value_PR_OverloadStop:
					break;

				case NGAP_InitiatingMessage__value_PR_DownlinkRIMInformationTransfer:
					break;

				case NGAP_InitiatingMessage__value_PR_UEInformationTransfer:
					break;

				case NGAP_InitiatingMessage__value_PR_ConnectionEstablishmentIndication:
					break;

				case NGAP_InitiatingMessage__value_PR_AMFCPRelocationIndication:
					break;

				case NGAP_InitiatingMessage__value_PR_HandoverSuccess:
					break;

				case NGAP_InitiatingMessage__value_PR_DownlinkRANEarlyStatusTransfer:
					break;

				case NGAP_InitiatingMessage__value_PR_MulticastGroupPaging:
					break;
					
				case NGAP_InitiatingMessage__value_PR_RANPagingRequest:
					break;
				/*
				 * Error cases
				 *
				 * Procedure can not be initiated by the AMF.
				 */
				/*--- CLASS 1 ---*/
				case NGAP_InitiatingMessage__value_PR_NGSetupRequest:
				case NGAP_InitiatingMessage__value_PR_RANConfigurationUpdate:
				case NGAP_InitiatingMessage__value_PR_HandoverCancel:
				case NGAP_InitiatingMessage__value_PR_HandoverRequired:
				case NGAP_InitiatingMessage__value_PR_PathSwitchRequest:
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceModifyIndication:
				case NGAP_InitiatingMessage__value_PR_UEContextSuspendRequest:
				case NGAP_InitiatingMessage__value_PR_UEContextResumeRequest:
				case NGAP_InitiatingMessage__value_PR_UERadioCapabilityIDMappingRequest:
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionModificationRequest:
				case NGAP_InitiatingMessage__value_PR_DistributionSetupRequest:
				case NGAP_InitiatingMessage__value_PR_DistributionReleaseRequest:
				case NGAP_InitiatingMessage__value_PR_MTCommunicationHandlingRequest:
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionTransportRequest:

				/*--- CLASS 2 ---*/
				case NGAP_InitiatingMessage__value_PR_UplinkRANConfigurationTransfer:
				case NGAP_InitiatingMessage__value_PR_UplinkRANStatusTransfer:
				case NGAP_InitiatingMessage__value_PR_HandoverNotify:
				case NGAP_InitiatingMessage__value_PR_InitialUEMessage:
				case NGAP_InitiatingMessage__value_PR_NASNonDeliveryIndication:
				case NGAP_InitiatingMessage__value_PR_PDUSessionResourceNotify:
				case NGAP_InitiatingMessage__value_PR_UEContextReleaseRequest:
				case NGAP_InitiatingMessage__value_PR_UplinkNASTransport:
				case NGAP_InitiatingMessage__value_PR_PWSRestartIndication:
				case NGAP_InitiatingMessage__value_PR_PWSFailureIndication:
				case NGAP_InitiatingMessage__value_PR_UplinkUEAssociatedNRPPaTransport:
				case NGAP_InitiatingMessage__value_PR_UplinkNonUEAssociatedNRPPaTransport:
				case NGAP_InitiatingMessage__value_PR_TraceFailureIndication:
				case NGAP_InitiatingMessage__value_PR_CellTrafficTrace:
				case NGAP_InitiatingMessage__value_PR_LocationReport:
				case NGAP_InitiatingMessage__value_PR_LocationReportingFailureIndication:
				case NGAP_InitiatingMessage__value_PR_UERadioCapabilityInfoIndication:
				case NGAP_InitiatingMessage__value_PR_RRCInactiveTransitionReport:
				case NGAP_InitiatingMessage__value_PR_SecondaryRATDataUsageReport:
				case NGAP_InitiatingMessage__value_PR_UplinkRIMInformationTransfer:
				case NGAP_InitiatingMessage__value_PR_RetrieveUEInformation:
				case NGAP_InitiatingMessage__value_PR_RANCPRelocationIndication:
				case NGAP_InitiatingMessage__value_PR_UplinkRANEarlyStatusTransfer:
				case NGAP_InitiatingMessage__value_PR_BroadcastSessionReleaseRequired:
				case NGAP_InitiatingMessage__value_PR_TimingSynchronisationStatusReport:
				case NGAP_InitiatingMessage__value_PR_PrivateMessage: /*FIXME: unknown type -> checking standard later again - if needed*/
					printf("[gNB-n2] Initiating Message type (%d) can only be initiated by the gNB!\n", msg->pdu->choice.initiatingMessage->value.present);
					break;

				default:
					printf("[gNB-n2] Unknown NGAP Initiating Message type!\n");
					break;
			}
	
			break;
		
		case NGAP_NGAP_PDU_PR_successfulOutcome:
		case NGAP_NGAP_PDU_PR_unsuccessfulOutcome:
			/*Out of interest here -> ignoring*/
			break;
	
		default:
			printf("[gNB-n2] Invalid NGAP message type (%d)\n", msg->pdu->present);
			break;
	}

end:
	/*Free NGAP message*/
	if(msg)
	{
		freeNGAPMessage(msg);
	}

	return;
}

/*
 * main - entry point of the program
 */
int
main(int argc, char **argv)
{
	/*Variables*/
	int i, j, k, sfd, ufd[2] = {0};
	struct sockaddr_in srvaddr;
	socklen_t len = 0;
	ngapmsg_t *msg = 0;
	pthread_t tid[2] = {0};
	struct sigaction act;
	struct utsname un = {0};
	char *hn = 0;
	bool wasClosed = false;

	struct sctp_sndrcvinfo sinfo;
	struct sctp_event_subscribe event;
	struct sctp_status status;
	struct sctp_initmsg initmsg;

	fd_set fds;
	int max_fd = 0;

	uint8_t buf[MAX_SIZE] = {0};
	uint8_t amf_reg = 0x2;
	uint8_t amf_ptr = 0x0;
	uint8_t amf_set[2] = {0};
	amf_set[1] = 0x40;
	NGAP_RelativeAMFCapacity_t amf_cap = 255;
	uint8_t sst = 0x01;

	ue_entry_t *list = 0;
	size_t num = 0;
	uint64_t inv = 0;
	uint8_t *ptr = 0;
	size_t psize = 0;

#ifdef RT
	struct sched_param sp = {
                .sched_priority = 2
        };
#endif

	/*Check passed parameter*/
	if(argc > 1)
	{
		if((psize = atoi(argv[1])) < 2)
		{
			printf("Usage: %s (<npool>) with npool > 1\n", argv[0]);
			printf("[gNB] Set default thread pool size: %d\n", PTHPOOL_SIZE);
			psize = PTHPOOL_SIZE;
		}
	}
	else
	{
		psize = PTHPOOL_SIZE;
	}

	printf("[gNB] Started with: %ld (thread pool size)\n", psize);

	/*Get hostname of system (used as gNB node name)*/
	if(uname(&un) != 0)
	{
		perror("[gNB] Hostname of the system couldn't be obtained");
		hn = GNB_NAME_DEFAULT;
	}
	else
	{
		hn = un.nodename;
	}
#ifdef RT
	/*Set RT priority*/
	if(sched_setscheduler(getpid(), SCHED_RR, &sp) != 0)
	{
		printf("[gNB] RT priority could not be set: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	printf("[gNB] RT_PREEMPT enabled\n");
#endif
	/*
	 * Set required signal handler:
	 *
	 * SIGINT, SIGTERM: catched by the signal handler gnb_shutdown
	 */
	memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = gnb_shutdown;
	act.sa_flags = SA_RESTART;
	if(sigemptyset(&act.sa_mask) != 0 || sigaction(SIGTERM, &act, NULL) != 0 || sigaction(SIGINT, &act, NULL) != 0)
	{
		printf("[gNB] Signal handler for SIGINT and SIGTERM couldn't be set\n");
		exit(EXIT_FAILURE);
	}

	/*Open E-CID Measurement virtual device files*/
	for(i = 0; i < ECID_NUM_PARAMS; i++)
	{
		switch(i)
		{
			case 0:
				ecid_fd[i] = open(ECID_SS_RSRP, O_RDONLY);
				break;
			case 1:
				ecid_fd[i] = open(ECID_SS_RSRQ, O_RDONLY);
				break;
			case 2:
				ecid_fd[i] = open(ECID_CSI_RSRP, O_RDONLY);
				break;
			case 3:
				ecid_fd[i] = open(ECID_CSI_RSRQ, O_RDONLY);
				break;
			case 4:
				ecid_fd[i] = open(ECID_AOA_NR, O_RDONLY);
				break;
			case 5:
				ecid_fd[i] = open(ECID_TADV_NR, O_RDONLY);
				break;
			case 6:
				ecid_fd[i] = open(ECID_UE_TXRX, O_RDONLY);
				break;
		}

		if(ecid_fd[i] < 0)
		{
			ecid_fd[i] = -1;
		}
	}

	/*Initialize this gNB entity*/
	if((gnb = calloc(1, sizeof(gnb_t))) == NULL)
	{
		perror("calloc()");
		return EXIT_FAILURE;
	}
	gnb->plmn[1] = 0xf1;
	gnb->plmn[2] = 0x10;
	gnb->tac[2] = 0x07;
	gnb->nr_cell_id[3] = 0x33;	/*random ...*/
	gnb->nr_cell_id[4] = 0x66;
	gnb->pci = 1;
	gnb->arfcn = 646667; /*approx. 3.7 GHz*/

	/*Initialize global lists for NRPPa E-CID Measurement messages*/
	if((ran_list = calloc(1, sizeof(ecid_ran_list_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}

	for(i = 0; i < ECID_SESS_MAX; i++)
        {
                for(j = 0; j < ECID_SESS_MAX; j++)
                {
			report_list[i][j].isActive = false;
			sem_init(&report_list[i][j].lock, 0, 1);
		}
	}

	if(sem_init(&ran_list->lock, 0, 1) != 0)
	{
		perror("sem_init()");
		goto err;
	}

	/*Loading NGAP related UE context IDs from file*/
	getUECTXfromFile(GNB_UECTX_PATH, &list, &num);
	if(!num || !list)
	{
		printf("[gNB] No UE context entries are found in %s\n", GNB_UECTX_PATH);
		goto err;
	}

	/*Map UE context entries (from file) to global UE context related NGAP ID list*/
	for(i = 0; i < num && i < GNB_MAX; i++)
	{
		ngap_ids[i].ngap_amf_ue_id = (uint64_t) list[i].ngap_amf;
		ngap_ids[i].ngap_ran_ue_id = list[i].ngap_ran;
	}
	freeUECTXList(list, num);
	list = 0;
	printf("[gNB] %ld UE context entries were successfully mapped to NGAP ID list\n", num);
	num = 0;

	/*Creation of a SCTP socket*/
	if((sfd = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP)) < 0)
	{
		perror("socket()");
		goto err;
	}

	/*Initialize server address structure*/
	explicit_bzero(&srvaddr, sizeof(srvaddr));
	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(N2_PORT);
	srvaddr.sin_addr.s_addr = inet_addr(N2_ADDR);

	memset(&event,      0, sizeof(struct sctp_event_subscribe));
	memset(&status,    0, sizeof(struct sctp_status));
	memset(&initmsg,    0, sizeof(struct sctp_initmsg));

	/*Enable receiving of stream ID*/
	event.sctp_data_io_event = 1;

	/*Set maximum no. of input and output streams*/
	initmsg.sinit_max_instreams = GNB_SCTP_IN;
	initmsg.sinit_num_ostreams = GNB_SCTP_OUT;

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

	/*Addressing in advance*/
	if(connect(sfd, (struct sockaddr*) &srvaddr, sizeof(srvaddr)) < 0)
	{
		perror("connect()");
		goto err;
	}

	/*Get number of supported SCTP streams per association*/
	i = sizeof(status);
	if (getsockopt(sfd, IPPROTO_SCTP, SCTP_STATUS, &status, &i) < 0)
	{
		perror("getsockopt()");
		goto err;
	}

	printf("[gNB-n2] Number of SCTP streams: %d (in), %d (out)\n", status.sstat_instrms, status.sstat_outstrms);

	/*Generation of NG Setup Request message*/
	if((msg = NGAP_NG_Setup_Request(hn, gnb->tac, gnb->plmn, &sst)) == NULL)
	{
		printf("[gNB] NGAP_NG_Setup_Request failed\n");
		goto err;
	}

	/*Send request to target AMF*/
	if(send(sfd, msg->enc, msg->size, MSG_DONTWAIT | MSG_NOSIGNAL) != msg->size)
	{
		perror("[gNB] send()");
		goto err;
	}

#ifdef DEBUG
	printf("NGAP message sent [%d B]\n", msg->size);
#endif

	/*Free memory*/
	freeNGAPMessage(msg);
	msg = 0;

	/*Waiting for NG Setup Response/Failure message*/
	if((i=read(sfd, buf, MAX_SIZE)) < 0)
	{
		perror("read()");
		goto err;
	}
	else if(!i)
	{
		printf("[gNB-n2] -- Connection was closed by the target AMF --\n");
		wasClosed = true;
		goto err;
	}

#ifdef DEBUG
	printf("NGAP Message Response received! [%d B]\n", i);
#endif

	/*Decode NGAP message*/
	if((msg = decodeNGAP(buf, i)) == NULL)
	{
		printf("[gNB-n2] NGAP message couldn't be decoded!\n");
		goto err;
	}

	/*
	 * Parsing of NGAP NG Setup Response/Failure message
	 */
	if(msg->pdu)
	{
		switch(msg->pdu->present)
		{
			/*NG Setup Response message*/
			case NGAP_NGAP_PDU_PR_successfulOutcome:

				/*Procedure Code, Criticality of message, used IE container*/
				if(msg->pdu->choice.successfulOutcome->procedureCode != NGAP_ProcedureCode_id_NGSetup || msg->pdu->choice.successfulOutcome->criticality != NGAP_Criticality_reject || msg->pdu->choice.successfulOutcome->value.present != NGAP_SuccessfulOutcome__value_PR_NGSetupResponse)
				{
					printf("[gNB-n2] Wrong NG Response message values!\n");
					goto err;
				}

				/*At least 4 IEs, max. 9 IEs*/
				if(msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count < 4 || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.count > 9 || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array)
				{
					printf("[gNB-n2] Number of transmitted IEs is wrong in NG Setup Response Message!\n");
					goto err;
				}

				/*(1) AMF Name*/
				if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0] || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->id != NGAP_ProtocolIE_ID_id_AMFName || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->criticality != NGAP_Criticality_reject || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.present != NGAP_NGSetupResponseIEs__value_PR_AMFName)
				{
					printf("[gNB-n2] NG Response message: AMF NAME IE is invalid!\n");
					goto err;
				}
				
				if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.choice.AMFName.buf || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.choice.AMFName.size)
				{
					printf("[gNB-n2] NG Response message: AMF NAME IE is invalid!\n");
					goto err;
				}

				if((amf = calloc(1, sizeof(amf_t))) == NULL || (amf->name = calloc(msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.choice.AMFName.size + 1, sizeof(char))) == NULL)
				{
					perror("calloc()");
					goto err;
				}

				/*--COPYING--*/
				memcpy(amf->name, msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.choice.AMFName.buf, msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[0]->value.choice.AMFName.size);

				/*(2) Served GUAMI List*/
				if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1] || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->id != NGAP_ProtocolIE_ID_id_ServedGUAMIList || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->criticality != NGAP_Criticality_reject || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.present != NGAP_NGSetupResponseIEs__value_PR_ServedGUAMIList)
				{
					printf("[gNB-n2] NG Response message: SERVED GUAMI LIST IE is invalid!\n");
					goto err;
				}
	
				if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.size > NGAP_maxnoofServedGUAMIs || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.count || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.size < msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.count)
				{
					printf("[gNB-n2] NG Response message: SERVED GUAMI LIST IE is invalid!\n");
					goto err;
				}

				/*--COPYING--*/
				//TODO: Copying GUAMI List and store it in amf_t structure!

				/*Iterate through GUAMI List Items*/
				for(i = 0; i < msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.count; i++)
				{
					/*Is item available?*/
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i])
					{
						printf("[gNB-n2] NG Response message: SERVED GUAMI LIST ITEM IE is invalid!\n");
						goto err;
					}

					/*Served GUAMI Item i: GUAMI.PLMNIdentity*/
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.pLMNIdentity.buf || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.pLMNIdentity.size != 3)
					{
						printf("[gNB-n2] NG Response message: PLMN IDENTITY is invalid!\n");
						goto err;
					}
					
					/*Served GUAMI Item i: GUAMI.AMF Region ID*/
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFRegionID.buf || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFRegionID.size != 1 || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFRegionID.bits_unused != 0)
					{
						printf("[gNB-n2] NG Response message: AMF REGION ID is invalid!\n");
						goto err;
					}
					
					/*Served GUAMI Item i: GUAMI.AMF Set ID*/
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFSetID.buf || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFSetID.size != 2 || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFSetID.bits_unused != 6)
					{
						printf("[gNB-n2] NG Response message: AMF SET ID is invalid!\n");
						goto err;
					}
					
					/*Served GUAMI Item i: GUAMI.AMF Pointer*/
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFPointer.buf || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFPointer.size != 1 || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[1]->value.choice.ServedGUAMIList.list.array[i]->gUAMI.aMFPointer.bits_unused != 2)
					{
						printf("[gNB-n2] NG Response message: AMF POINTER is invalid!\n");
						goto err;
					}
					
					/*
				 	 * NOTE: Further optional IEs of the Served GUAMI List Item members (3GPP TS 38.413, 9.2.6.2) will not be checked here...
				 	 */
				}
				
				/*(3) Relative AMF Capacity*/
				if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[2] || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[2]->id != NGAP_ProtocolIE_ID_id_RelativeAMFCapacity || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[2]->criticality != NGAP_Criticality_ignore || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[2]->value.present != NGAP_NGSetupResponseIEs__value_PR_RelativeAMFCapacity || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[2]->value.choice.RelativeAMFCapacity > 255)
				{
					printf("[gNB-n2] NG Response message: RELATIVE AMF CAPACITY IE is invalid!\n");
					goto err;
				}

				/*(4) PLMN Support List*/
				if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3] || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->id != NGAP_ProtocolIE_ID_id_PLMNSupportList || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->criticality != NGAP_Criticality_reject || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.present != NGAP_NGSetupResponseIEs__value_PR_PLMNSupportList)
				{
					printf("[gNB-n2] NG Response message: PLMN SUPPORT LIST IE is invalid!\n");
					goto err;
				}

				if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.size < msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.count || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.size > NGAP_maxnoofPLMNs || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.size || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.count)
				{
					printf("[gNB-n2] NG Response message: PLMN SUPPORT LIST IE is invalid!\n");
					goto err;
				}

				/*Iterate through PLMN Support List*/
				for(i = 0; i < msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.count; i++)
				{
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i])
					{
						printf("[gNB-n2] NG Response message: PLMN SUPPORT LIST ITEM is missing!\n");
						goto err;
					}

					/*PLMNIdentity*/
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->pLMNIdentity.buf || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->pLMNIdentity.size != 3)
					{
						printf("[gNB-n2] NG Response message: PLMN IDENTITY is invalid!\n");
						goto err;
					}

					/*SliceSupportList*/
					if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.array || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.size > NGAP_maxnoofSliceItems || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.size || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.count || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.size < msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.count)
					{
						printf("[gNB-n2] NG Response message: SLICE SUPPORT LIST is invalid!\n");
						goto err;
					}
					
					for(j = 0; j < msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.count; j++)
					{
						if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.array[j])
						{
							printf("[gNB-n2] NG Response message: SLICE SUPPORT LIST ITEM is missing!\n");
							goto err;
						}

						/*S-NSSAI SST*/
						if(!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.array[j]->s_NSSAI.sST.buf || !msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.array[j]->s_NSSAI.sST.size)
						{
							printf("[gNB-n2] NG Response message: SLICE SUPPORT LIST ITEM - S-NSSAI SST is invalid!\n");
							goto err;
						}

						/*S-NSSAI SD - optional*/
						if(msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.array[j]->s_NSSAI.sD && (!msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.array[j]->s_NSSAI.sD->buf || msg->pdu->choice.successfulOutcome->value.choice.NGSetupResponse.protocolIEs.list.array[3]->value.choice.PLMNSupportList.list.array[i]->sliceSupportList.list.array[j]->s_NSSAI.sD->size != 3))
						{
							printf("[gNB-n2] NG Response message: SLICE SUPPORT LIST ITEM - S-NSSAI SD is invalid!\n");
							goto err;
						}				
					}
				}

				/*
				 * NOTE: Further optional IEs of the NGAP NG Response message (3GPP TS 38.413, 9.2.6.2) will not be checked here...
				 */
				break;

			/*NG Setup Failure message*/
			case NGAP_NGAP_PDU_PR_unsuccessfulOutcome:
				printf("[gNB-n2] NGAP: NG Setup procedure failed!\n");
				goto err;
			
			default:
				printf("[gNB-n2] Unknown present flag in NG Setup Response message!\n");
				goto err;
		}
	}
	else
	{
		printf("[gNB-n2] No NGAP PDU received!\n");
		goto err;		
	}

	freeNGAPMessage(msg);
	msg = 0;

	/*Store AMF related connection data*/	
	amf->sockfd = sfd;
	if(initsctpcli(&amf->con, status.sstat_instrms, status.sstat_outstrms) != 0)
	{
		goto err;
	}

	printf("[gNB-n2] -- NGAP: NG Setup procedure successfully completed --\n");

	/*Initialize POSIX thread pools for N2 interface*/
	if((tpool_n2 = pthpool_create(psize/2)) == NULL || (tpool_long = pthpool_create(psize/2)) == NULL)
	{
		printf("[gNB-n2] POSIX thread pools couldn't be initialized\n");
		goto err;
	}

	/*
	 * Waiting loop for incoming data:
	 *
	 * (1) gNB is waiting for data from a UE and has to forward it to the target AMF.
	 * (2) gNB is waiting for a NGAP REQUEST from the AMF to process it or to forward it to a UE.
	 *
	 * NOTE: The gNB only handles requests from the AMF. If itself wants to initiate a Class 1 procedure,
	 *		 it will wait for the response.
	 */
	while(1)
	{
		/*Clear file descriptor set*/
		FD_ZERO(&fds);

		/*Set target file descriptors to the file descriptor set*/
		FD_SET(amf->sockfd, &fds);
		/*FD_SET(ue->fd, &fds)*/

		/*Monitor both file descriptors*/
		//(amf->sockfd > ue->fd) ? (max_fd = amf->sockfd) : (max_fd = ue->fd);
		if(select(amf->sockfd + 1, &fds, 0, 0, 0) < 0)
		{
			if(errno == EINTR)
			{
				printf("[gNB] Monitoring of AMF connection was interrupted\n");
				continue;
			}
			goto err;
		}
		
		/*
		 * Check which target was sending data
		 *
		 * AMF: decode and parse NGAP data
		 * UE: decode and parse UE data
		 *
		 * NOTE: Processing of the received data is realized by a separate POSIX thread.
		 * NOTE: Receive data from a UE is not yet implemented!
		 */
		if(FD_ISSET(amf->sockfd, &fds))
		{
			j = 0;

			/*Clear SCTP message info structure*/
			memset(&sinfo, 0, sizeof(struct sctp_sndrcvinfo));
			len = sizeof(srvaddr);

again:
			/*Reading encoded NGAP data from socket*/
			k = 0;
			if((i=sctp_recvmsg(amf->sockfd, buf + j, MAX_SIZE, (struct sockaddr*)&srvaddr, &len, &sinfo, &k)) < 0)
			{
				perror("[gNB-n2] sctp_recvmsg()");

				if(errno == ECONNRESET)
				{
					wasClosed = true;
					goto err;
				}
				goto next;
			}
			j += i;

			/*Check if all data chunks have been received...*/ //TODO: Take stream ID into account!! It could be that the next chunk is gotten from another stream (?!)
			if(!(k & MSG_EOR) && i && j < MAX_SIZE)
			{
				printf("[gNB-n2] Received data chunk (%d B) from stream %d (%d flag)\n", i, sinfo.sinfo_stream, k);
				goto again;
			}
			else if(!(k & MSG_EOR) && i && j >= MAX_SIZE)
			{
				printf("[gNB-n2] NGAP data exceeds buffer size - dropping\n");
				goto next;
			}

			/*Check if connection was closed by the target AMF*/
			if(!i)
			{
				printf("[gNB-n2] -- Connection was closed by the target AMF (%s) --\n", amf->name);
				wasClosed = true;
				goto err;
			}

			/*Decode NGAP message*/
			if((msg = decodeNGAP(buf, j)) == NULL)
			{
				printf("[gNB-n2] NGAP message couldn't be decoded!\n");
				goto next;
			}

			/* TODO: Reserving SCTP output stream number if received NGAP massage is Class 1!
			 *
			 * Pass data (here: heap address) to the target POSIX thread to which the stream ID is assigned.
			 *
			 * NOTE: If UNIX Domain socket was closed in the target thread, SIGPIPE is normally triggered.
			 *		 Therefore, the flag MSG_NOSIGNAL is set, to return an error instead.
			 *		 Afterwards, everything is closed and a new POSIX thread will be created to process data.
			 */
			if(isReserved(&amf->con, sinfo.sinfo_stream))
			{
				if(send(amf->con.in_list[sinfo.sinfo_stream][1], &msg, sizeof(msg), MSG_DONTWAIT | MSG_NOSIGNAL) < 0)
				{
					perror("[gNB-n2] send() failed during pass NGAP to target UNIX Domain socket");
				}

				/*Skip creation of a new POSIX thread*/
				else
				{
					msg = 0;
					goto next;
				}
			}

			/*Adding request data to the POSIX thread pool*/
			if(!pthpool_add_job(tpool_n2, amf_handler, msg))
			{
				printf("[gNB-n2] Encoded NGAP message couldn't add to the target thread pool\n");
				freeNGAPMessage(msg);
				msg = 0;
				goto next;
			}
			msg = 0;
		}

next:
		/*if(FD_ISSET(ue->fd))
		{
		
		}*/
	}

	return EXIT_SUCCESS;

err:
	/*Free memory*/
	if(msg)
	{
		freeNGAPMessage(msg);
	}
	
	if(amf)
	{
		if(amf->name)
		{
			free(amf->name);
		}
		free(amf);
	}

	if(ran_list)
	{
		sem_destroy(&ran_list->lock);
		free(ran_list);
	}

	for(i = 0; i < ECID_SESS_MAX; i++)
        {
                for(j = 0; j < ECID_SESS_MAX; j++)
                {
			sem_destroy(&report_list[i][j].lock);
		}
	}

	if(gnb)
	{
		free(gnb);
	}

	/*Close all opened file descriptors*/
	for(i = 0; i < ECID_NUM_PARAMS; i++)
	{
		if(ecid_fd[i] >= 0)
		{
			close(ecid_fd[i]);
		}
	}

	/*Destroy POSIX thread pool*/
	pthpool_destroy(tpool_n2);
	pthpool_destroy(tpool_long);

	if(wasClosed)
	{
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
