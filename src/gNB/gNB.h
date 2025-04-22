#ifndef _GNB_H_
#define _GNB_H_

#include <ngap/ngap_create.h>
#include <nrppa/nrppa_create.h>
#include <NGAP_asn_constant.h>
#include <NRPPa_NR-PCI.h>
#include <NRPPa_NR-ARFCN.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/sctp.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <pthread.h>
#include <endian.h> /*not standardized...*/

/*SCTP Client API*/
#include <sctpcli.h>

/*POSIX thread pool header*/
#include <pthpool.h>

/*
 * Macros
 */
#define N2_PORT 38412
#define N2_ADDR "192.168.3.1"
#define MAX_SIZE 131072
#define GNB_SCTP_OUT SCTP_MAX_OUT
#define GNB_SCTP_IN SCTP_MAX_IN
#define GNB_MAX 256
#define GNB_UECTX_PATH "/etc/init5g/amf/ue_ctx-256.csv"
#define GNB_NAME_DEFAULT "imd-gnb"

/*
 * amd_data - global entity to represent target AMF parameters
 *
 * @sockfd: corresponding SCTP socket
 * @name: AMF name that is received after a successful NG Setup procedure.
 * @con: stream management for an established SCTP connection
 */
typedef struct amf_data
{
	int sockfd;
	char *name;
	sctpcli_t con;
} amf_t;

/*
 * gnb_ue_ctx - global entity that represents a logical UE connection within the gNB
 *
 * NOTE: Such a entry is generally created while uptime.
 *		 Here, it is assumed that such a logical UE connection already exists.
 *		 Therefore, all threads are just reading it, not writing.
 */
typedef struct gnb_ue_ctx
{
	uint64_t ngap_amf_ue_id;
	long ngap_ran_ue_id;
} gnb_ue_ctx_t;

/*
 * gnb_ctx - global entity that represents this gNB
 *
 * @plmn: PLMN identity of this gNB (here: 00101)
 * @tac: Tracking Area Code of this gNB (here: 7)
 * @nr_cell_id: NR Cell Identifier (36 Bit acc. to 3GPP TS 38.455, 9.2.6)
 * @pci: Physical Cell ID
 * @arfcn: Absolute Radio Frequency Channel Number (ARFCN)
 *
 * further reading: 3GPP TS 38.300, 8.2
 */
typedef struct gnb_ctx
{
	uint8_t plmn[3];
	uint8_t tac[3];
	uint8_t nr_cell_id[5];
	NRPPa_NR_PCI_t pci;
	NRPPa_NR_ARFCN_t arfcn;
} gnb_t;

/*
 * Global tables
 */
extern amf_t *amf;
extern gnb_t *gnb;
extern gnb_ue_ctx_t ngap_ids[GNB_MAX];
extern pthpool_t *tpool_long;

#endif
