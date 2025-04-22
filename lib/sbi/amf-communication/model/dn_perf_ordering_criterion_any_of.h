/*
 * dn_perf_ordering_criterion_any_of.h
 *
 *
 */

#ifndef _dn_perf_ordering_criterion_any_of_H_
#define _dn_perf_ordering_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { dn_perf_ordering_criterion_any_of_NULL = 0,
	       dn_perf_ordering_criterion_any_of_AVERAGE_TRAFFIC_RATE,
	       dn_perf_ordering_criterion_any_of_MAXIMUM_TRAFFIC_RATE,
	       dn_perf_ordering_criterion_any_of_AVERAGE_PACKET_DELAY,
	       dn_perf_ordering_criterion_any_of_MAXIMUM_PACKET_DELAY,
	       dn_perf_ordering_criterion_any_of_AVERAGE_PACKET_LOSS_RATE }
dn_perf_ordering_criterion_any_of_e;

char *dn_perf_ordering_criterion_any_of_ToString(
	dn_perf_ordering_criterion_any_of_e dn_perf_ordering_criterion_any_of);

dn_perf_ordering_criterion_any_of_e dn_perf_ordering_criterion_any_of_FromString(
	char *dn_perf_ordering_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _dn_perf_ordering_criterion_any_of_H_ */
