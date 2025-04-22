/*
 * network_perf_info.h
 *
 * Represents the network performance information.
 */

#ifndef _network_perf_info_H_
#define _network_perf_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"
#include "network_perf_type.h"
#include "resource_usage_requirement.h"
#include "time_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct network_perf_info_s network_perf_info_t;
typedef struct network_perf_info_s {
	struct network_area_info_s *network_area;
	struct network_perf_type_s *nw_perf_type;
	struct time_window_s *ana_period;
	bool is_relative_ratio;
	int relative_ratio;
	bool is_absolute_num;
	int absolute_num;
	struct resource_usage_requirement_s *rsc_usg_req;
	bool is_confidence;
	int confidence;
} network_perf_info_t;

network_perf_info_t *network_perf_info_create(network_area_info_t *network_area,
                                              network_perf_type_t *nw_perf_type,
                                              time_window_t *ana_period,
                                              bool is_relative_ratio,
                                              int relative_ratio,
                                              bool is_absolute_num,
                                              int absolute_num,
                                              resource_usage_requirement_t *rsc_usg_req, bool is_confidence, int confidence);
void network_perf_info_free(network_perf_info_t *network_perf_info);
network_perf_info_t *network_perf_info_parseFromJSON(
	cJSON *network_perf_infoJSON);
cJSON *network_perf_info_convertToJSON(network_perf_info_t *network_perf_info);
network_perf_info_t *network_perf_info_copy(network_perf_info_t *dst,
                                            network_perf_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _network_perf_info_H_ */
