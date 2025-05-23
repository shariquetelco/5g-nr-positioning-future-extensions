/*
 * network_perf_type_any_of.h
 *
 *
 */

#ifndef _network_perf_type_any_of_H_
#define _network_perf_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { network_perf_type_any_of_NULL = 0,
	       network_perf_type_any_of_GNB_ACTIVE_RATIO,
	       network_perf_type_any_of_GNB_COMPUTING_USAGE,
	       network_perf_type_any_of_GNB_MEMORY_USAGE,
	       network_perf_type_any_of_GNB_DISK_USAGE,
	       network_perf_type_any_of_GNB_RSC_USAGE_OVERALL_TRAFFIC,
	       network_perf_type_any_of_GNB_RSC_USAGE_GBR_TRAFFIC,
	       network_perf_type_any_of_GNB_RSC_USAGE_DELAY_CRIT_GBR_TRAFFIC,
	       network_perf_type_any_of_NUM_OF_UE,
	       network_perf_type_any_of_SESS_SUCC_RATIO,
	       network_perf_type_any_of_HO_SUCC_RATIO }
network_perf_type_any_of_e;

char *network_perf_type_any_of_ToString(
	network_perf_type_any_of_e network_perf_type_any_of);

network_perf_type_any_of_e network_perf_type_any_of_FromString(
	char *network_perf_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _network_perf_type_any_of_H_ */
