/*
 * ue_trajectory.h
 *
 * Represents timestamped UE positions.
 */

#ifndef _ue_trajectory_H_
#define _ue_trajectory_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "timestamped_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_trajectory_s ue_trajectory_t;
typedef struct ue_trajectory_s {
	char *supi;
	char *gpsi;
	list_t *timestamped_locs;
} ue_trajectory_t;

ue_trajectory_t *ue_trajectory_create(char *supi, char *gpsi,
                                      list_t *timestamped_locs);
void ue_trajectory_free(ue_trajectory_t *ue_trajectory);
ue_trajectory_t *ue_trajectory_parseFromJSON(cJSON *ue_trajectoryJSON);
cJSON *ue_trajectory_convertToJSON(ue_trajectory_t *ue_trajectory);
ue_trajectory_t *ue_trajectory_copy(ue_trajectory_t *dst, ue_trajectory_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_trajectory_H_ */
