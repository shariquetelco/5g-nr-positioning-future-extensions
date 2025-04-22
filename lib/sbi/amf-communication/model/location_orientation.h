/*
 * location_orientation.h
 *
 * Possible values are:     - HORIZONTAL: Indicates horizontal orientation.   - VERTICAL: Indicates vertical orientation.   - HOR_AND_VER: Indicates both horizontal and vertical orientation.
 */

#ifndef _location_orientation_H_
#define _location_orientation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "location_orientation_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_orientation_s location_orientation_t;
typedef struct location_orientation_s {} location_orientation_t;

location_orientation_t *location_orientation_create();
void location_orientation_free(location_orientation_t *location_orientation);
location_orientation_t *location_orientation_parseFromJSON(
	cJSON *location_orientationJSON);
cJSON *location_orientation_convertToJSON(
	location_orientation_t *location_orientation);
location_orientation_t *location_orientation_copy(
	location_orientation_t	*dst,
	location_orientation_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _location_orientation_H_ */
