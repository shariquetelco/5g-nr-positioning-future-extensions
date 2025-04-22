/*
 * retainability_threshold.h
 *
 * Represents a QoS flow retainability threshold.
 */

#ifndef _retainability_threshold_H_
#define _retainability_threshold_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "time_unit.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct retainability_threshold_s retainability_threshold_t;
typedef struct retainability_threshold_s {
	bool is_rel_flow_num;
	int rel_flow_num;
	struct time_unit_s *rel_time_unit;
	bool is_rel_flow_ratio;
	int rel_flow_ratio;
} retainability_threshold_t;

retainability_threshold_t *retainability_threshold_create(bool is_rel_flow_num,
                                                          int rel_flow_num,
                                                          time_unit_t *rel_time_unit, bool is_rel_flow_ratio, int rel_flow_ratio);
void retainability_threshold_free(
	retainability_threshold_t *retainability_threshold);
retainability_threshold_t *retainability_threshold_parseFromJSON(
	cJSON *retainability_thresholdJSON);
cJSON *retainability_threshold_convertToJSON(
	retainability_threshold_t *retainability_threshold);
retainability_threshold_t *retainability_threshold_copy(
	retainability_threshold_t *dst, retainability_threshold_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _retainability_threshold_H_ */
