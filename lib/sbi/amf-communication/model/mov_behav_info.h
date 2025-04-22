/*
 * mov_behav_info.h
 *
 * Represents the Movement Behaviour information.
 */

#ifndef _mov_behav_info_H_
#define _mov_behav_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_coordinates.h"
#include "mov_behav.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mov_behav_info_s mov_behav_info_t;
typedef struct mov_behav_info_s {
	struct geographical_coordinates_s *geo_loc;
	list_t *mov_behavs;
	bool is_confidence;
	int confidence;
} mov_behav_info_t;

mov_behav_info_t *mov_behav_info_create(geographical_coordinates_t *geo_loc,
                                        list_t *mov_behavs, bool is_confidence,
                                        int confidence);
void mov_behav_info_free(mov_behav_info_t *mov_behav_info);
mov_behav_info_t *mov_behav_info_parseFromJSON(cJSON *mov_behav_infoJSON);
cJSON *mov_behav_info_convertToJSON(mov_behav_info_t *mov_behav_info);
mov_behav_info_t *mov_behav_info_copy(mov_behav_info_t	*dst,
                                      mov_behav_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _mov_behav_info_H_ */
