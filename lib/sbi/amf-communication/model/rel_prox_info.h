/*
 * rel_prox_info.h
 *
 * Represents the Relative Proximity information.
 */

#ifndef _rel_prox_info_H_
#define _rel_prox_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "time_to_collision_info.h"
#include "ue_proximity.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rel_prox_info_s rel_prox_info_t;
typedef struct rel_prox_info_s {
	char *ts_start;
	int ts_duration;
	list_t *supis;
	list_t *gpsis;
	list_t *ue_proximities;
	struct time_to_collision_info_s *ttc_info;
} rel_prox_info_t;

rel_prox_info_t *rel_prox_info_create(char *ts_start, int ts_duration,
                                      list_t *supis, list_t *gpsis,
                                      list_t *ue_proximities,
                                      time_to_collision_info_t *ttc_info);
void rel_prox_info_free(rel_prox_info_t *rel_prox_info);
rel_prox_info_t *rel_prox_info_parseFromJSON(cJSON *rel_prox_infoJSON);
cJSON *rel_prox_info_convertToJSON(rel_prox_info_t *rel_prox_info);
rel_prox_info_t *rel_prox_info_copy(rel_prox_info_t *dst, rel_prox_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _rel_prox_info_H_ */
