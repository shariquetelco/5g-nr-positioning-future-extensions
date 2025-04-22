/*
 * network_perf_type.h
 *
 * Represents the network performance types.   Possible values are: - GNB_ACTIVE_RATIO: Indicates that the network performance requirement is gNodeB active   (i.e. up and running) rate. Indicates the ratio of gNB active (i.e. up and running) number   to the total number of gNB. - GNB_COMPUTING_USAGE: Indicates gNodeB computing resource usage. - GNB_MEMORY_USAGE: Indicates gNodeB memory usage. - GNB_DISK_USAGE: Indicates gNodeB disk usage. - GNB_RSC_USAGE_OVERALL_TRAFFIC: The gNB resource usage. - GNB_RSC_USAGE_GBR_TRAFFIC: The gNB resource usage for GBR traffic. - GNB_RSC_USAGE_DELAY_CRIT_GBR_TRAFFIC: The gNB resource usage for Delay-critical GBR   traffic. - NUM_OF_UE: Indicates number of UEs. - SESS_SUCC_RATIO: Indicates ratio of successful setup of PDU sessions to total PDU   session setup attempts. - HO_SUCC_RATIO: Indicates Ratio of successful handovers to the total handover attempts.
 */

#ifndef _network_perf_type_H_
#define _network_perf_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_perf_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct network_perf_type_s network_perf_type_t;
typedef struct network_perf_type_s {} network_perf_type_t;

network_perf_type_t *network_perf_type_create();
void network_perf_type_free(network_perf_type_t *network_perf_type);
network_perf_type_t *network_perf_type_parseFromJSON(
	cJSON *network_perf_typeJSON);
cJSON *network_perf_type_convertToJSON(network_perf_type_t *network_perf_type);
network_perf_type_t *network_perf_type_copy(network_perf_type_t *dst,
                                            network_perf_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _network_perf_type_H_ */
