/*
 * horizontal_with_vertical_velocity_and_uncertainty.h
 *
 * Horizontal and vertical velocity with speed uncertainty.
 */

#ifndef _horizontal_with_vertical_velocity_and_uncertainty_H_
#define _horizontal_with_vertical_velocity_and_uncertainty_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "vertical_direction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct horizontal_with_vertical_velocity_and_uncertainty_s
        horizontal_with_vertical_velocity_and_uncertainty_t;
typedef struct horizontal_with_vertical_velocity_and_uncertainty_s {
	float h_speed;
	int bearing;
	float v_speed;
	vertical_direction_e v_direction;
	float h_uncertainty;
	float v_uncertainty;
} horizontal_with_vertical_velocity_and_uncertainty_t;

horizontal_with_vertical_velocity_and_uncertainty_t *
horizontal_with_vertical_velocity_and_uncertainty_create(float h_speed,
                                                         int bearing,
                                                         float v_speed,
                                                         vertical_direction_e v_direction, float h_uncertainty, float v_uncertainty);
void horizontal_with_vertical_velocity_and_uncertainty_free(
	horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty);
horizontal_with_vertical_velocity_and_uncertainty_t *
horizontal_with_vertical_velocity_and_uncertainty_parseFromJSON(
	cJSON *horizontal_with_vertical_velocity_and_uncertaintyJSON);
cJSON *horizontal_with_vertical_velocity_and_uncertainty_convertToJSON(
	horizontal_with_vertical_velocity_and_uncertainty_t *horizontal_with_vertical_velocity_and_uncertainty);
horizontal_with_vertical_velocity_and_uncertainty_t *
horizontal_with_vertical_velocity_and_uncertainty_copy(
	horizontal_with_vertical_velocity_and_uncertainty_t	*dst,
	horizontal_with_vertical_velocity_and_uncertainty_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _horizontal_with_vertical_velocity_and_uncertainty_H_ */
