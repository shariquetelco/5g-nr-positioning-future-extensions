/*
 * network_perf_order_criterion_any_of.h
 *
 *
 */

#ifndef _network_perf_order_criterion_any_of_H_
#define _network_perf_order_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { network_perf_order_criterion_any_of_NULL = 0,
	       network_perf_order_criterion_any_of_NUMBER_OF_UES,
	       network_perf_order_criterion_any_of_COMMUNICATION_PERF,
	       network_perf_order_criterion_any_of_MOBILITY_PERF }
network_perf_order_criterion_any_of_e;

char *network_perf_order_criterion_any_of_ToString(
	network_perf_order_criterion_any_of_e network_perf_order_criterion_any_of);

network_perf_order_criterion_any_of_e
network_perf_order_criterion_any_of_FromString(
	char *network_perf_order_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _network_perf_order_criterion_any_of_H_ */
