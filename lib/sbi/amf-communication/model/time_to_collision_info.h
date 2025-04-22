/*
 * time_to_collision_info.h
 *
 * Represents Time To Collision (TTC) information.
 */

#ifndef _time_to_collision_info_H_
#define _time_to_collision_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct time_to_collision_info_s time_to_collision_info_t;
typedef struct time_to_collision_info_s {
	char *ttc;
	bool is_accuracy;
	int accuracy;
	bool is_confidence;
	int confidence;
} time_to_collision_info_t;

time_to_collision_info_t *time_to_collision_info_create(char	*ttc,
                                                        bool	is_accuracy,
                                                        int	accuracy,
                                                        bool	is_confidence,
                                                        int	confidence);
void time_to_collision_info_free(
	time_to_collision_info_t *time_to_collision_info);
time_to_collision_info_t *time_to_collision_info_parseFromJSON(
	cJSON *time_to_collision_infoJSON);
cJSON *time_to_collision_info_convertToJSON(
	time_to_collision_info_t *time_to_collision_info);
time_to_collision_info_t *time_to_collision_info_copy(
	time_to_collision_info_t *dst, time_to_collision_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _time_to_collision_info_H_ */
