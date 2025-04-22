#ifndef _NRPPA_ECID_H_
#define _NRPPA_ECID_H_

#include "gNB.h"
#include <NRPPa_ProtocolIE-Field.h>
#include <NRPPa_MeasuredResultsValue.h>
#include <NRPPa_ResultSS-RSRP-Item.h>
#include <NRPPa_ResultSS-RSRP-PerSSB.h>
#include <NRPPa_ResultSS-RSRP-PerSSB-Item.h>
#include <test/ecid-params.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <semaphore.h>

#define ECID_SESS_MAX 256 /*corresponds to the maximum value of LMF/RAN Measurement ID*/
#define ECID_NUM_PARAMS 7

/*
 * Character Device files to get selected 5G NR E-CID Measurement Result parameters (simulated)
 *
 * E-CID values are listed in: 3GPP TS 38.455, 9.2.5
 *
 * NOTE: To obtain the target parameters, the self-developed Linux kernel module has to be loaded (see /src/kernel/ecid_params)!
 */
#define ECID_SS_RSRP "/dev/5g/ss_rsrp"
#define ECID_SS_RSRQ "/dev/5g/ss_rsrq"
#define ECID_CSI_RSRP "/dev/5g/csi_rsrp"
#define ECID_CSI_RSRQ "/dev/5g/csi_rsrq"
#define ECID_AOA_NR "/dev/5g/ul_aoa_nr"
#define ECID_TADV_NR "/dev/5g/tadv_nr"
#define ECID_UE_TXRX "/dev/5g/ue_txrx_diff"

/*
 * ran_list - manage UE conenctions for NRPPa E-CID Measurement messages
 *
 * @list: RAN UE Measurement ID list and its corresponding LMF UE Measurement ID
 * @lock: POSIX semaphore to enable mutual exclusion beween multiple threads
 * @cnt: number of stored ID pairs
 */
typedef struct ran_list
{
	NRPPa_UE_Measurement_ID_t list[ECID_SESS_MAX];
	sem_t lock;
	uint16_t cnt;
} ecid_ran_list_t;

/*
 * ecid_report_param - parameter set for E-CID Measurement Report message generation
 *
 * @lmf_ue, @ran_ue: target UE connection (NRPPa layer)
 * @ngap_amf, @ngap_ran: target UE connection (NGAP layer)
 * @nfid: NF ID of target LMF (needed by AMF to forward NRPPa messages)
 * @mqlist: Requested measurement quantities for an E-CID measurement result
 * @num: no. of elements in @mqlist
 * @next_period: time until the next period expires
 * @period_ns: duration of a period [ns]
 */
typedef struct ecid_report_param
{
	NRPPa_UE_Measurement_ID_t lmf_ue;
	NRPPa_UE_Measurement_ID_t ran_ue;
	NGAP_AMF_UE_NGAP_ID_t ngap_amf;
	NGAP_RAN_UE_NGAP_ID_t ngap_ran;
	uint8_t nfid[16];
	NRPPa_MeasurementQuantitiesValue_t mqlist[NRPPa_maxNoMeas];
	int num;
	struct timespec next_period;
	unsigned long period_ns;
} ecid_report_param_t;


/*
 * ecid_report_list - global data structure to manage periodical E-CID Measurement Report messages
 *
 * @list: currently UE connections for which E-CID Measurement Report messages are sent.
 * @lock: POSIX semaphore to enable mutual exclusion
 * @cnt: number of current list items
 *
 * NOTE: To access @list, the received LMF UE Measurement ID - 1 and RAN UE Measurement ID have to be used.
 */
typedef struct ecid_report_list
{
	bool isActive;
	sem_t lock;
} ecid_report_t;

/*
 * Global lists
 */
extern ecid_ran_list_t *ran_list;
extern ecid_report_t report_list[ECID_SESS_MAX][ECID_SESS_MAX];
extern int ecid_fd[ECID_NUM_PARAMS];

/*
 * NRPPa E-CID Measurement functions
 */
nrppamsg_t* E_CID_MeasurementInitiation(nrppamsg_t *nrppa, ngapmsg_t *ngap);
int E_CID_MeasurementTermination(nrppamsg_t *nrppa);

#endif
