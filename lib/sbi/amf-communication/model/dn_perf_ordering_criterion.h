/*
 * dn_perf_ordering_criterion.h
 *
 * Represents the order criterion for the list of DN performance analytics.   Possible values are:   - AVERAGE_TRAFFIC_RATE: Indicates the average traffic rate.   - MAXIMUM_TRAFFIC_RATE: Indicates the maximum traffic rate.   - AVERAGE_PACKET_DELAY: Indicates the average packet delay.   - MAXIMUM_PACKET_DELAY: Indicates the maximum packet delay.   - AVERAGE_PACKET_LOSS_RATE: Indicates the average packet loss rate.
 */

#ifndef _dn_perf_ordering_criterion_H_
#define _dn_perf_ordering_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dn_perf_ordering_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dn_perf_ordering_criterion_s dn_perf_ordering_criterion_t;
typedef struct dn_perf_ordering_criterion_s {} dn_perf_ordering_criterion_t;

dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_create();
void dn_perf_ordering_criterion_free(
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion);
dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_parseFromJSON(
	cJSON *dn_perf_ordering_criterionJSON);
cJSON *dn_perf_ordering_criterion_convertToJSON(
	dn_perf_ordering_criterion_t *dn_perf_ordering_criterion);
dn_perf_ordering_criterion_t *dn_perf_ordering_criterion_copy(
	dn_perf_ordering_criterion_t *dst, dn_perf_ordering_criterion_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _dn_perf_ordering_criterion_H_ */
