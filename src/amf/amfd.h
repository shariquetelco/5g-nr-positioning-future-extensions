#ifndef _AMFD_H_
#define _AMFD_H_

/*C standard library headers*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <pthread.h>
#include <errno.h>
#include <netdb.h>
#include <stdatomic.h>
#include <endian.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sched.h>

#include <NGAP_NRPPa-PDU.h>

/*libuuid library header*/
#include <uuid/uuid.h>

/*CURL library header*/
#include <curl/curl.h>

/*ASN.1 headers*/
#include <aper_encoder.h>
#include <aper_decoder.h>

/*libNGAP library header*/
#include <ngap/ngap_create.h>

/*libhttp2 library header*/
#include <http2/nghttp2srv.h>

/*SBI HTTP Client API*/
#include <api/N1N2MessageCollectionCollectionAPI.h>
#include <api/N1N2SubscriptionsCollectionForIndividualUEContextsCollectionAPI.h>

/*SCTP Client API*/
#include <sctpcli.h>

/*
 * Macros
 * @LISTENQ: size parameter of rx queue
 * @N2_PORT: IANA port of N2 interface (gNB <-> AMF)
 * @SBI_PORT: server port no. of all NFs
 * @AMF_ADDR: IPv4 address of this NF
 * @BUF_MAX: maximum buffer size for incomming messages
 * @SA: code simplicity
 * @AMF_TLS_KEY: path of TLS key file
 * @AMF_TLS_CRT: path of TLS certificate file
 *
 * @AMF_RTAB_SIZE: maximum size of entries in the global routing table
 *
 * @AMF_NAMF_*: URI of AMF services over SBI (see 3GPP TS 29.518, 5.1)
 */
#define LISTENQ 5
#define N2_PORT 38412
#define N2_ADDR "192.168.3.1"
#define SBI_PORT 54321
#define SBI_ADDR "127.0.2.1"
#define MSG_MAX 131072
#define GNB_MAX 256
#define SA struct sockaddr
#define FD_OPEN_MAX 4096

#define AMF_NFID "dd762bca-90f0-ee98-ab45-e34cd5eaff48"
#define AMF_MCC "001"
#define AMF_MNC "01"
/*
 * 3GPP TS 23.003, 2.10.1: GUAMI = <AMF REGION ID><AMF SET ID><AMF POINTER> = 8 Bit + 10 Bit + 6 Bit = 24 Bit = 3 Byte = 6 Hex character
 *
 * 0000 0010 0001 0000 0000 0000 = 0x021000 with AMF REGION ID = 0x02, AMF SET ID = 0x40, AMF POINTER = 0x00
 */
#define AMF_GUAMI_ID "021000"
#define AMF_HNAME "amfd.5gc"
#define LMF_HNAME "lmfd.5gc"
#define AMF_TLS_KEY "/etc/init5g/tls/amf.key"
#define AMF_TLS_CRT "/etc/init5g/tls/amf.crt"

#define AMF_RTAB_SIZE 10
#define AMF_NAME "imd-amf"
#define AMF_SCTP_OUT SCTP_MAX_OUT
#define AMF_SCTP_IN SCTP_MAX_IN

#define AMF_NAMF_COMM "/namf-comm/v1"	/*Currently, only this service is used*/
#define AMF_NAMF_EVNT "/namf-evts/v1"
#define AMF_NAMF_MT "/namf-mt/v1"
#define AMF_NAMF_LOC "/namf-loc/v1"
#define AMF_NAMF_BCST "/namf-mbs-bc/v1"
#define AMF_NAMF_MCOM "/namf-mbs-comm/v1"

#define AMF_SUB_N1_MAX 7	/*max. no. of parallel N1 subscriptions*/
#define AMF_SUB_N2_MAX 11	/*max. no. of parallel N2 subscriptions*/

/*
 * gnb_entry - entity to represent a successfully connected gNB
 *
 * @sockfd: corresponding SCTP socket
 * @ipaddr: gNB IPv4 address as a human-readable string
 * @name: gNB name that was received after a successfull NG Setup procedure.
 * @id: 3GPP compliant global gNB identifier
 * @con: stream management for an established SCTP connection
 * @num: number of associated UE contexts
 */
typedef struct gnb_entry
{
	int sockfd;
	char *ipaddr;
	char *name;
	NGAP_GlobalRANNodeID_t *id;
	sctpcli_t con;
	int num;
} gnb_t;

/*
 * gnb_list - global list that contains all connected gNBs
 *
 * @list: list that contains the gNB references.
 * @lock: POSIX thread mutex to enable mutual exclusion while modifying the list itself.
 * @cnt: number of included gNB in @list
 */
typedef struct gnb_list
{
	gnb_t *list[GNB_MAX];
	pthread_mutex_t lock;
	uint8_t cnt;
} gnb_list_t;

/*
 * rel_table_entry, rel_table - global lookup table for LCS sessions / UE contexts
 */
typedef struct rel_table_entry
{
	bool isComplete; /*Identifier to determine if an entry is completely initialized. This means, that a Callback URI exists (MsgSubscribe AMF service was invoked!). So, then it can be used to forward NRPPa messages.*/
	pthread_mutex_t lock;
	char *lcs_id;
	char *imsi; /*see: 3GPP TS 23.003, 2.2*/
	ue_n1_n2_info_subscription_create_data_t *sub_n2[AMF_SUB_N2_MAX];	/*Access via N2 information class enum member - 1: n2_information_class_e*/
	char *sub_n2_id[AMF_SUB_N2_MAX]; /*Access via N2 information class enum member: n2_information_class_e - 1*/
	ue_n1_n2_info_subscription_create_data_t *sub_n1[AMF_SUB_N1_MAX];
	char *sub_n1_id[AMF_SUB_N1_MAX];
	NGAP_RoutingID_t nfid;
	NGAP_AMF_UE_NGAP_ID_t ngap_amf_id;
	NGAP_RAN_UE_NGAP_ID_t ngap_ran_id;
	gnb_t *gnb;
	struct rel_table_entry *next;
} rentry_t;

typedef struct rel_table
{
	rentry_t *root, *last;
	pthread_mutex_t lock;
	uint16_t cnt;
} rlist_t;

typedef rlist_t lcs_session_t;

/*
 * Bit field to represent the requested Namf URI
 *
 * see: 3GPP TS 29.518, 6.1.3.1
 */
typedef struct namf_comm_url
{
	/*Layer 1*/
	uint8_t L1_ue_contexts:1;
	uint8_t L1_subscriptions:1;
	uint8_t L1_nonuen1n2msg:1;

	/*Layer 2*/
	uint8_t L2_uectxid:1;
	uint8_t L2_subscrid:1;
	uint8_t L2_nonuetrans:1;
	uint8_t L2_subscription:1;

	/*Layer 3*/
	uint8_t L3_assign:1;
	uint8_t L3_transfer:1;
	uint8_t L3_release:1;
	uint8_t L3_transupt:1;
	uint8_t L3_relocate:1;
	uint8_t L3_canreloc:1;
	uint8_t L3_n1n2msg:1;
	uint8_t L3_n2notifyid:1;
	char *n2notfiysubid;

	/*Layer 4*/
	uint8_t L4_n1n2msgid:1;
	uint8_t L4_subscriptions:1;

	/*Layer 5*/
	uint8_t L5_subscripid:1;
	char *subid;
} namfc_t;

/*
 * Global variables
 *
 * @ue_ctx: global UE context table
 * @glist: global gNB list
 * @amf: GUAMI of this AMF entity
 */
extern rlist_t *ue_ctx;			/*extern variable see https://stackoverflow.com/questions/1433204/how-do-i-use-extern-to-share-variables-between-source-files*/
extern gnb_list_t *glist;
extern guami_t *amf;

/*
 * helper functions for modifying elements to a list
 */
int addEntry(rlist_t *list, rentry_t *entry);
void deleteEntry(rlist_t *list, rentry_t *entry);
rentry_t* getEntry(rlist_t *list, void* key);
rentry_t* getEntryFull(rlist_t *list, NGAP_AMF_UE_NGAP_ID_t *ngap_amf_id, NGAP_RAN_UE_NGAP_ID_t *ngap_ran_ue, NGAP_RoutingID_t *nfid);
void addGNBToUEctx(rlist_t *list, gnb_t *gnb, int num);
void deleteGNBFromList(rlist_t *list, gnb_t *gnb);
void freeList(rlist_t *list);

#endif
