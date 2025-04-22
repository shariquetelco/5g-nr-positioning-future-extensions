/*
 * horizontal_velocity_with_uncertainty.h
 *
 * Horizontal velocity with speed uncertainty.
 */

#ifndef _horizontal_velocity_with_uncertainty_H_
#define _horizontal_velocity_with_uncertainty_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct horizontal_velocity_with_uncertainty_s
        horizontal_velocity_with_uncertainty_t;
typedef struct horizontal_velocity_with_uncertainty_s {
	float h_speed;
	int bearing;
	float h_uncertainty;
} horizontal_velocity_with_uncertainty_t;

horizontal_velocity_with_uncertainty_t *
horizontal_velocity_with_uncertainty_create(float h_speed, int bearing,
                                            float h_uncertainty);
void horizontal_velocity_with_uncertainty_free(
	horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);
horizontal_velocity_with_uncertainty_t *
horizontal_velocity_with_uncertainty_parseFromJSON(
	cJSON *horizontal_velocity_with_uncertaintyJSON);
cJSON *horizontal_velocity_with_uncertainty_convertToJSON(
	horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty);
horizontal_velocity_with_uncertainty_t *
horizontal_velocity_with_uncertainty_copy(
	horizontal_velocity_with_uncertainty_t	*dst,
	horizontal_velocity_with_uncertainty_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _horizontal_velocity_with_uncertainty_H_ */
