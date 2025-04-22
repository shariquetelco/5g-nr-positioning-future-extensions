/*
 * ue_mobility.h
 *
 * Represents UE mobility information.
 */

#ifndef _ue_mobility_H_
#define _ue_mobility_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "direction_info.h"
#include "location_info.h"
#include "scheduled_communication_time_1.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_mobility_s ue_mobility_t;
typedef struct ue_mobility_s {
	char *ts;
	struct scheduled_communication_time_1_s *recurring_time;
	bool is_duration;
	int duration;
	bool is_duration_variance;
	float duration_variance;
	list_t *loc_infos;
	list_t *direction_infos;
} ue_mobility_t;

ue_mobility_t *ue_mobility_create(char *ts,
                                  scheduled_communication_time_1_t *recurring_time, bool is_duration, int duration, bool is_duration_variance, float duration_variance, list_t *loc_infos, list_t *direction_infos);
void ue_mobility_free(ue_mobility_t *ue_mobility);
ue_mobility_t *ue_mobility_parseFromJSON(cJSON *ue_mobilityJSON);
cJSON *ue_mobility_convertToJSON(ue_mobility_t *ue_mobility);
ue_mobility_t *ue_mobility_copy(ue_mobility_t *dst, ue_mobility_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_mobility_H_ */
