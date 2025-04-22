/*
 * dn_performance_req.h
 *
 * Represents other DN performance analytics requirements.
 */

#ifndef _dn_performance_req_H_
#define _dn_performance_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "dn_perf_ordering_criterion.h"
#include "matching_direction.h"
#include "threshold_level.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct dn_performance_req_s dn_performance_req_t;
typedef struct dn_performance_req_s {
	struct dn_perf_ordering_criterion_s *dn_perf_order_criter;
	struct matching_direction_s *order;
	list_t *report_thresholds;
} dn_performance_req_t;

dn_performance_req_t *dn_performance_req_create(
	dn_perf_ordering_criterion_t *dn_perf_order_criter,
	matching_direction_t *order, list_t *report_thresholds);
void dn_performance_req_free(dn_performance_req_t *dn_performance_req);
dn_performance_req_t *dn_performance_req_parseFromJSON(
	cJSON *dn_performance_reqJSON);
cJSON *dn_performance_req_convertToJSON(
	dn_performance_req_t *dn_performance_req);
dn_performance_req_t *dn_performance_req_copy(dn_performance_req_t	*dst,
                                              dn_performance_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _dn_performance_req_H_ */
