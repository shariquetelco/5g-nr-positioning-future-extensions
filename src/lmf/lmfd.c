#include "lmfd.h"
#include "list-handler.h"

/*
 * Forward declaration of callback functions
 */
int on_header_callback(nghttp2_session *session, const nghttp2_frame *frame, const uint8_t *name, size_t namelen, const uint8_t *value, size_t valuelen, uint8_t flags, void *user_data);
int on_frame_recv_callback(nghttp2_session *session, const nghttp2_frame *frame, void *user_data);

/*
 * Global UE context list
 */
ue_ctx_list_t *ue_list = 0;
nrppa_transact_t *nrppa_list = 0;
lmf_id_t *lmf_ue_meas_list = 0;

pthpool_t *tpool_in = 0, *tpool_ue = 0;


/*
 * lmfd_shutdown - signal handler to free global list(s) before task termination
 */
static void
lmfd_shutdown(int signum)
{
	if(signum != SIGTERM && signum != SIGINT)
	{
		return;
	}

	/*Free memory*/
	freeUEctxList(ue_list);
	freeNRPPaList(&nrppa_list);
	freeNRPPaList(&lmf_ue_meas_list);
	pthpool_destroy(tpool_in);
	pthpool_destroy(tpool_ue);

	printf("[LMF] -- Terminated by lmfd_shutdown --\n");

	exit(EXIT_SUCCESS);
}

/*
 * main - entry point of a program
 */
int
main(int argc, char **argv)
{
	/*Variables*/
	struct sigaction act;
	http2_cb_data_t *cb;
	size_t ues = 0, npool = 0;
	uint8_t period = 0;

	struct hostent *hn = 0;
	in_addr_t ip4 = inet_addr(LMF_ADDR);
	struct rlimit lim = {0};
#ifdef RT
	struct sched_param sp = {
		.sched_priority = 2
	};
#endif
	/*Check passed input parameter*/
	if(argc < 3)
	{
		printf("Usage: %s <UEs> <npool> (<period>)\n", argv[0]);
		return EXIT_FAILURE;
	}

	else if((ues = atoi(argv[1])) < 1)
	{
		printf("[LMF] Invalid number of UEs: %ld (must be > 0)\n", ues);
		return EXIT_FAILURE;
	}

	if((npool = atoi(argv[2])) <= 1)
	{
		printf("[LMF] Invalid thread pool size: %ld (npool > 1)\n", npool);
		return EXIT_FAILURE;
	}
#ifdef RT
	/*Set RT priority*/
        if(sched_setscheduler(getpid(), SCHED_RR, &sp) != 0)
        {
		printf("[LMF] RT priority could not be set: %s\n", strerror(errno));
		return EXIT_FAILURE;
        }
	printf("[LMF] RT_PREEMPT enabled\n");
#endif
	if(argc == 3)
	{
		printf("[LMF] Started with: %ld (UEs), %ld (thread pool size)\n", ues, npool/2);
	}
	else
	{
		if((period = atoi(argv[3])) > NRPPa_MeasurementPeriodicity_extended)
		{
			printf("[LMF] Invalid period value: %d (must be 0 - %d)\n", period, NRPPa_MeasurementPeriodicity_extended);
			return EXIT_FAILURE;
		}
		printf("[LMF] Started with: %ld (UEs), %ld (thread pool size), %d (period)\n", ues, npool/2, period);
	}

	/*Check if hostname of this server is set to @LMF_HNAME*/
	if((hn = gethostbyaddr((void*) &ip4, sizeof(in_addr_t), AF_INET)) == NULL)
	{
		printf("[LMF] Hostname of server address could not be resolved: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	if(strcmp(hn->h_name, LMF_HNAME) != 0)
	{
		printf("[LMF] Hostname of this server does not match %s\n", LMF_HNAME);
		return EXIT_FAILURE;
	}

#ifdef DEBUG
	/*Look up IPv4 address of AMF*/
        if((hn = gethostbyname(AMF_HNAME)) == NULL)
        {
                printf("[LMF] Hostname of AMF not available: %s\n", strerror(errno));
                return EXIT_FAILURE;
        }

        if(inet_ntop(AF_INET, hn->h_addr_list[0], amf_ip, 50) == NULL)
        {
                printf("[LMF] Hostname of AMF could not be converted to IPv4 address: %s\n", strerror(errno));
                return EXIT_FAILURE;
        }
#endif

	/*Increase maximum limit of open file descriptors*/
	if(getrlimit(RLIMIT_NOFILE, &lim) != 0)
	{
		printf("[LMF] Limit for open file descriptors couldn't obtained: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	if(lim.rlim_max < FD_OPEN_MAX)
	{
		printf("[LMF] Maximum limit of opened file descriptors can not be set: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}

	if(lim.rlim_cur < FD_OPEN_MAX)
	{
		lim.rlim_cur = FD_OPEN_MAX;
		if(setrlimit(RLIMIT_NOFILE, (const struct rlimit*) &lim) != 0)
		{
			printf("[LMF] Limit of opened file descriptors can not be set: %s\n", strerror(errno));
			return EXIT_FAILURE;
		}
	}

	/*Initialize POSIX thread pools*/
	if((tpool_in = pthpool_create(npool/2)) == NULL || (tpool_ue = pthpool_create(0)) == NULL)
	{
		printf("[LMF] POSIX thread pool(s) couldn't be initialized\n");
		return EXIT_FAILURE;
	}

	/*
	 * Initialize global lists:
	 *
	 * (1) UE context list
	 * (2) NRPPa Transaction ID list
	 * (3) LMF UE Measurement ID list
	 */
	initUEctxList(&ue_list);
	if(!ue_list || pthread_barrier_init(&ue_list->barrier, NULL, ues) != 0)
	{
		printf("[LMF] UE context list couldn't be initialized\n");
		goto err;
	}
	ue_list->bar_cnt = ues;
	ue_list->npool = npool;
	if(argc > 3)
	{
		ue_list->period = period;
	}
	else
	{
		ue_list->period = -1; /*If @period is not set per command line: determineLocation -> research_RequestResponseTime is executed*/
	}

	initNRPPaList(&nrppa_list, NRPPA_TRANSID_MAX);
	if(!nrppa_list)
	{
		printf("[LMF] NRPPa Transaction ID list couldn't be initialized\n");
		goto err;
	}

	initNRPPaList(&lmf_ue_meas_list, NRPPA_ECID_LMF_ID_MAX);
	if(!lmf_ue_meas_list)
	{
		printf("[LMF] LMF UE Measurement ID list couldn't be initialized\n");
		goto err;
	}

	/*
	 * Set required signal handler:
	 *
	 * SIGPIPE: ignore
	 * SIGINT, SIGTERM: catched by the signal handler lmfd_shutdown
	 */
	memset(&act, 0, sizeof(struct sigaction));
	act.sa_handler = SIG_IGN;
	if(sigaction(SIGPIPE, &act, NULL) != 0)
	{
		goto err;
	}

	act.sa_handler = lmfd_shutdown;
	act.sa_flags = SA_RESTART;
	if(sigemptyset(&act.sa_mask) != 0 || sigaction(SIGTERM, &act, NULL) != 0 || sigaction(SIGINT, &act, NULL) != 0)
	{
		goto err;
	}

	/*Set callback functions for receiving and sending HTTP/2 data*/
	if((cb = (http2_cb_data_t*) calloc(1, sizeof(http2_cb_data_t))) == NULL)
	{
		perror("calloc()");
		goto err;
	}
	cb->on_frame_recv_callback = on_frame_recv_callback;
	cb->on_header_callback = on_header_callback;

	printf("[LMF-sbi] HTTP/2 server is starting on %s:%d ...\n", LMF_ADDR, SBI_PORT);

	/*Start HTTP/2 server*/
	start_http2server(LMF_ADDR, SBI_PORT, LMF_TLS_KEY, LMF_TLS_CRT, cb, tpool_in);

	return EXIT_SUCCESS;

err:
	/*Free memory*/
	freeUEctxList(ue_list);
	freeNRPPaList(&nrppa_list);
	freeNRPPaList(&lmf_ue_meas_list);
	pthpool_destroy(tpool_in);
	pthpool_destroy(tpool_ue);
	if(cb)
	{
		free(cb);
	}

	return EXIT_FAILURE;
}
