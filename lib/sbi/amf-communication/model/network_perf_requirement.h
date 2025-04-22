/*
 * network_perf_requirement.h
 *
 * Represents a network performance requirement.
 */

#ifndef _network_perf_requirement_H_
#define _network_perf_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_perf_order_criterion.h"
#include "network_perf_type.h"
#include "resource_usage_requirement.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct network_perf_requirement_s network_perf_requirement_t;
typedef struct network_perf_requirement_s {
	struct network_perf_type_s *nw_perf_type;
	bool is_relative_ratio;
	int relative_ratio;
	bool is_absolute_num;
	int absolute_num;
	struct network_perf_order_criterion_s *order_criterion;
	struct resource_usage_requirement_s *rsc_usg_req;
} network_perf_requirement_t;

network_perf_requirement_t *network_perf_requirement_create(
	network_perf_type_t *nw_perf_type, bool is_relative_ratio,
	int relative_ratio, bool is_absolute_num, int absolute_num,
	network_perf_order_criterion_t *order_criterion,
	resource_usage_requirement_t *rsc_usg_req);
void network_perf_requirement_free(
	network_perf_requirement_t *network_perf_requirement);
network_perf_requirement_t *network_perf_requirement_parseFromJSON(
	cJSON *network_perf_requirementJSON);
cJSON *network_perf_requirement_convertToJSON(
	network_perf_requirement_t *network_perf_requirement);
network_perf_requirement_t *network_perf_requirement_copy(
	network_perf_requirement_t *dst, network_perf_requirement_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _network_perf_requirement_H_ */
