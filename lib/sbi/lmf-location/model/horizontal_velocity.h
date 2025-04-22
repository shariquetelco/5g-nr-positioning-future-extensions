/*
 * horizontal_velocity.h
 *
 * Horizontal velocity.
 */

#ifndef _horizontal_velocity_H_
#define _horizontal_velocity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct horizontal_velocity_s horizontal_velocity_t;
typedef struct horizontal_velocity_s {
	float h_speed;
	int bearing;
} horizontal_velocity_t;

horizontal_velocity_t *horizontal_velocity_create(float h_speed, int bearing);
void horizontal_velocity_free(horizontal_velocity_t *horizontal_velocity);
horizontal_velocity_t *horizontal_velocity_parseFromJSON(
	cJSON *horizontal_velocityJSON);
cJSON *horizontal_velocity_convertToJSON(
	horizontal_velocity_t *horizontal_velocity);
horizontal_velocity_t *horizontal_velocity_copy(horizontal_velocity_t	*dst,
                                                horizontal_velocity_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _horizontal_velocity_H_ */
