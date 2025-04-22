/*
 * velocity_estimate.h
 *
 * Velocity estimate.
 */

#ifndef _velocity_estimate_H_
#define _velocity_estimate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "horizontal_velocity.h"
#include "horizontal_velocity_with_uncertainty.h"
#include "horizontal_with_vertical_velocity.h"
#include "horizontal_with_vertical_velocity_and_uncertainty.h"
#include "vertical_direction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct velocity_estimate_s velocity_estimate_t;
typedef struct velocity_estimate_s {
	float h_speed;
	int bearing;
	float v_speed;
	vertical_direction_e v_direction;
	float h_uncertainty;
	float v_uncertainty;
} velocity_estimate_t;

velocity_estimate_t *velocity_estimate_create(float h_speed, int bearing,
                                              float v_speed,
                                              vertical_direction_e v_direction,
                                              float h_uncertainty,
                                              float v_uncertainty);
void velocity_estimate_free(velocity_estimate_t *velocity_estimate);
velocity_estimate_t *velocity_estimate_parseFromJSON(
	cJSON *velocity_estimateJSON);
cJSON *velocity_estimate_convertToJSON(velocity_estimate_t *velocity_estimate);
velocity_estimate_t *velocity_estimate_copy(velocity_estimate_t *dst,
                                            velocity_estimate_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _velocity_estimate_H_ */
