/*
 * range_direction.h
 *
 * Represents a distance and direction from a point A to a point B.
 */

#ifndef _range_direction_H_
#define _range_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct range_direction_s range_direction_t;
typedef struct range_direction_s {
	bool is_distance;
	double distance;
	bool is_azimuth_direction;
	int azimuth_direction;
	bool is_elevation_direction;
	int elevation_direction;
} range_direction_t;

range_direction_t *range_direction_create(bool is_distance, double distance,
                                          bool is_azimuth_direction,
                                          int azimuth_direction,
                                          bool is_elevation_direction,
                                          int elevation_direction);
void range_direction_free(range_direction_t *range_direction);
range_direction_t *range_direction_parseFromJSON(cJSON *range_directionJSON);
cJSON *range_direction_convertToJSON(range_direction_t *range_direction);
range_direction_t *range_direction_copy(range_direction_t	*dst,
                                        range_direction_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _range_direction_H_ */
