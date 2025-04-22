/*
 * relative_cartesian_location.h
 *
 * Relative Cartesian Location
 */

#ifndef _relative_cartesian_location_H_
#define _relative_cartesian_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct relative_cartesian_location_s relative_cartesian_location_t;
typedef struct relative_cartesian_location_s {
	float x;
	float y;
	bool is_z;
	float z;
} relative_cartesian_location_t;

relative_cartesian_location_t *relative_cartesian_location_create(float x,
                                                                  float y,
                                                                  bool	is_z,
                                                                  float z);
void relative_cartesian_location_free(
	relative_cartesian_location_t *relative_cartesian_location);
relative_cartesian_location_t *relative_cartesian_location_parseFromJSON(
	cJSON *relative_cartesian_locationJSON);
cJSON *relative_cartesian_location_convertToJSON(
	relative_cartesian_location_t *relative_cartesian_location);
relative_cartesian_location_t *relative_cartesian_location_copy(
	relative_cartesian_location_t *dst, relative_cartesian_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _relative_cartesian_location_H_ */
