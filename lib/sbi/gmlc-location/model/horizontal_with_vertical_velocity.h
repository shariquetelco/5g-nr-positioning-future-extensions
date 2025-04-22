/*
 * horizontal_with_vertical_velocity.h
 *
 * Horizontal and vertical velocity.
 */

#ifndef _horizontal_with_vertical_velocity_H_
#define _horizontal_with_vertical_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "vertical_direction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct horizontal_with_vertical_velocity_s
        horizontal_with_vertical_velocity_t;
typedef struct horizontal_with_vertical_velocity_s {
	float h_speed;
	int bearing;
	float v_speed;
	vertical_direction_e v_direction;
} horizontal_with_vertical_velocity_t;

horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_create(
	float h_speed, int bearing, float v_speed,
	vertical_direction_e v_direction);
void horizontal_with_vertical_velocity_free(
	horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);
horizontal_with_vertical_velocity_t *
horizontal_with_vertical_velocity_parseFromJSON(
	cJSON *horizontal_with_vertical_velocityJSON);
cJSON *horizontal_with_vertical_velocity_convertToJSON(
	horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity);
horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_copy(
	horizontal_with_vertical_velocity_t	*dst,
	horizontal_with_vertical_velocity_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _horizontal_with_vertical_velocity_H_ */
