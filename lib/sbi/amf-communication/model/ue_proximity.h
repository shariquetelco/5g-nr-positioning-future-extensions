/*
 * ue_proximity.h
 *
 * Represents the Observed or Predicted proximity information.
 */

#ifndef _ue_proximity_H_
#define _ue_proximity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "location_orientation.h"
#include "ue_trajectory.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_proximity_s ue_proximity_t;
typedef struct ue_proximity_s {
	bool is_ue_distance;
	int ue_distance;
	struct velocity_estimate_s *ue_velocity;
	bool is_avr_speed;
	float avr_speed;
	struct location_orientation_s *loc_orientation;
	list_t *ue_trajectories;
	bool is_ratio;
	int ratio;
} ue_proximity_t;

ue_proximity_t *ue_proximity_create(bool is_ue_distance, int ue_distance,
                                    velocity_estimate_t *ue_velocity,
                                    bool is_avr_speed, float avr_speed,
                                    location_orientation_t *loc_orientation,
                                    list_t *ue_trajectories, bool is_ratio,
                                    int ratio);
void ue_proximity_free(ue_proximity_t *ue_proximity);
ue_proximity_t *ue_proximity_parseFromJSON(cJSON *ue_proximityJSON);
cJSON *ue_proximity_convertToJSON(ue_proximity_t *ue_proximity);
ue_proximity_t *ue_proximity_copy(ue_proximity_t *dst, ue_proximity_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_proximity_H_ */
