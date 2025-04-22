/*
 * mov_behav.h
 *
 * Represents the Movement Behaviour information per time slot.
 */

#ifndef _mov_behav_H_
#define _mov_behav_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "direction_info.h"
#include "speed_threshold_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mov_behav_s mov_behav_t;
typedef struct mov_behav_s {
	char *ts_start;
	int ts_duration;
	bool is_num_of_ue;
	int num_of_ue;
	bool is_ratio;
	int ratio;
	bool is_avr_speed;
	float avr_speed;
	list_t *speed_thresd_infos;
	list_t *direction_ue_infos;
} mov_behav_t;

mov_behav_t *mov_behav_create(char *ts_start, int ts_duration,
                              bool is_num_of_ue, int num_of_ue, bool is_ratio,
                              int ratio, bool is_avr_speed, float avr_speed,
                              list_t *speed_thresd_infos,
                              list_t *direction_ue_infos);
void mov_behav_free(mov_behav_t *mov_behav);
mov_behav_t *mov_behav_parseFromJSON(cJSON *mov_behavJSON);
cJSON *mov_behav_convertToJSON(mov_behav_t *mov_behav);
mov_behav_t *mov_behav_copy(mov_behav_t *dst, mov_behav_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _mov_behav_H_ */
