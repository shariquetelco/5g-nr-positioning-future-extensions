#ifndef _LMFD_H_
#define _LMFD_H_

/*C standard library headers*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <errno.h>
#include <netdb.h>
#include <signal.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <poll.h>
#include <sched.h>

/*libhttp2 library header*/
#include <http2/nghttp2srv.h>

/*libuuid library header*/
#include <uuid/uuid.h>

/*CURL library header*/
#include <curl/curl.h>

/*SBI HTTP Client API*/
#include <api/N1N2MessageCollectionCollectionAPI.h>
#include <api/N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI.h>
#include <api/N1N2IndividualSubscriptionDocumentAPI.h>
#include <model/n2_information_notification.h>

#include <api/DetermineLocationAPI.h>

/*NRPPa and NGAP library headers*/
#include <nrppa/nrppa_create.h>
#include <ngap/ngap_create.h>

/*
 * Macros
 */
#define LISTENQ 5
#define SBI_PORT 54321
#define LMF_ADDR "127.0.3.1"
#define LMF_NFID "3a552bca-988e-21aa-f3f4-197cd5ea7633"
#define BMAX 4096
#define SA struct sockaddr
#define FD_OPEN_MAX 4096

#define GNB_MAX 256
#define NRPPA_TRANSID_MAX 32768
#define NRPPA_SAMPLE_MAX 2	/*Max. no. of sending request messages per thread*/
#define NRPPA_ECID_LMF_ID_MAX 256

#ifdef RESEARCH
#define RES_FILE_PATTERN "/etc/init5g/lmf/res_"
#endif

#define LMF_HNAME "lmfd.5gc"
#define AMF_HNAME "amfd.5gc"
#define LMF_TLS_KEY "/etc/init5g/tls/lmf.key"
#define LMF_TLS_CRT "/etc/init5g/tls/lmf.crt"

#define AMF_TLS_CRT "/etc/init5g/tls/amf.crt"
#define TLS_DIR "/etc/init5g/tls/"

/*SBI: LMF HTTP services*/
#define LMF_NLMF_LOC "/nlmf-loc/v1"
#define LMF_NLMF_BCAST "/nlmf-broadcast/v1"

/*
 * LMF Subscription URLs
 *
 * @LMF_CALLBACK_UE: Callback base URI that is used by the AMF invoking its N2InfoNotify service request
 * @LMF_CALLBACK_NONUE: Callback URI that is used by the AMF invoking its NonUeN2InfoNotify service request
 */
#define LMF_BASE_URI "https://lmfd.5gc:54321"

#define LMF_CALLBACK_UE "https://lmfd.5gc:54321/n2-ue-messages"
#define LMF_CALLBACK_NONUE "https://lmfd.5gc:54321/n2-nonue-messages"

/*
 * ue_ctx - representation of a UE context
 *
 * @supi: Unique identifier of UE (here: IMSI)
 * @n2sub: Subscription ID for N2 Notifications
 * @lcsid: assigned LCS Correlation Identifier
 * @amfid: NF ID (UUID) of the serving AMF
 * @lmf_ue: LMF UE Measurement ID (3GPP TS 38.455, 9.1.1.2)
 * @ran_ue: RAN UE Measurement ID (3GPP TS 38.455, 9.1.1.2)
 * @ufd: UNIX Domain socket to receive UE related data from other threads
 * @lock: POSIX thread mutex to realize mutual exclusion (used to change values of a certain UE context)
 * @next: reference to the next UE context
 */
typedef struct ue_ctx
{
	char *supi;
	char *n2subid;
	char *n2_clb_uri;
	char *lcsid;
	char *amfid;
	NRPPa_UE_Measurement_ID_t lmf_ue;
	NRPPa_UE_Measurement_ID_t ran_ue;
	int ufd;
	pthread_mutex_t lock;
	struct ue_ctx *next;
} ue_ctx_t;

/*
 * ue_ctx_list - representation of a global linked UE context list
 *
 * @first: pointer to the first entry
 * @last: pointer to the last entry
 * @lock: POSIX thread mutex to realize mutual exclusion
 * @cnt: number of contained entries
 * @barrier: POSIX barrier to synchronize all SBI determineLocation service requests at a certain point.
 * @bar_cnt: initial number of @barrier (corresponds to the total number of parallel UE's determineLocation requests)
 * @period: measurement period (only for E-CID Measurement Initiation Request messages that expect periodical responses!) 
 * @npool: size of SBI associated thread pool
 *
 * NOTE: An entry will be added, when the AMF invokes the Nlmf_loc_determineLocation service over SBI.
 */
typedef struct ue_ctx_list
{
	ue_ctx_t *first, *last;
	pthread_mutex_t lock;
	uint16_t cnt;
	pthread_barrier_t barrier;
	uint16_t bar_cnt;
	int period;
	size_t npool;
} ue_ctx_list_t;

/*
 * nrppa_transact_list - global list to manage the usage of NRPPa Transaction IDs that are initiated by the LMF itself (Class 1 NRPPa Initiating Messages).
 *
 * @list: NRPPa Transaction ID list -> field index corresponds to the ID
 * @lock: POSIX thread mutex to enable mutual exclusion
 * @cnt: number of used NRPPa Transaction IDs
 * @num: number of reserved elements in @list (important for generic usage)
 */
typedef struct nrppa_transact_list
{
	uint8_t *list;
	pthread_mutex_t lock;
	uint16_t cnt;
	int num;
} nrppa_transact_t;

typedef nrppa_transact_t lmf_id_t;

/*
 * global variables
 */
extern nrppa_transact_t *nrppa_list;
extern lmf_id_t *lmf_ue_meas_list;
extern ue_ctx_list_t *ue_list;
extern pthpool_t *tpool_in, *tpool_ue;

#endif
