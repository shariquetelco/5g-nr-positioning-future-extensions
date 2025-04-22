/*
 * network_perf_order_criterion.h
 *
 * Represents the ordering criterion for the list of network performance analytics.   Possible values are:     - NUMBER_OF_UES: The ordering criterion of the analytics is the number of UEs.   - COMMUNICATION_PERF: The ordering criterion of the analytics is the communication performance.   - MOBILITY_PERF: The ordering criterion of the analytics is themobility performance.
 */

#ifndef _network_perf_order_criterion_H_
#define _network_perf_order_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_perf_order_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct network_perf_order_criterion_s network_perf_order_criterion_t;
typedef struct network_perf_order_criterion_s {} network_perf_order_criterion_t;

network_perf_order_criterion_t *network_perf_order_criterion_create();
void network_perf_order_criterion_free(
	network_perf_order_criterion_t *network_perf_order_criterion);
network_perf_order_criterion_t *network_perf_order_criterion_parseFromJSON(
	cJSON *network_perf_order_criterionJSON);
cJSON *network_perf_order_criterion_convertToJSON(
	network_perf_order_criterion_t *network_perf_order_criterion);
network_perf_order_criterion_t *network_perf_order_criterion_copy(
	network_perf_order_criterion_t	*dst,
	network_perf_order_criterion_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _network_perf_order_criterion_H_ */
