/*
 * geo_location.h
 *
 * Represents a horizontal and optionally vertical location using either geographic or local coordinates.
 */

#ifndef _geo_location_H_
#define _geo_location_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "local_origin.h"
#include "point.h"
#include "point_altitude.h"
#include "relative_cartesian_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct geo_location_s geo_location_t;
typedef struct geo_location_s {
	struct point_s *point;
	struct point_altitude_s *point_alt;
	struct local_origin_s *ref_point;
	struct relative_cartesian_location_s *local_coords;
} geo_location_t;

geo_location_t *geo_location_create(point_t *point, point_altitude_t *point_alt,
                                    local_origin_t *ref_point,
                                    relative_cartesian_location_t *local_coords);
void geo_location_free(geo_location_t *geo_location);
geo_location_t *geo_location_parseFromJSON(cJSON *geo_locationJSON);
cJSON *geo_location_convertToJSON(geo_location_t *geo_location);
geo_location_t *geo_location_copy(geo_location_t *dst, geo_location_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _geo_location_H_ */
