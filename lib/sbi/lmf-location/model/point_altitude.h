/*
 * point_altitude.h
 *
 * Ellipsoid point with altitude.
 */

#ifndef _point_altitude_H_
#define _point_altitude_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct point_altitude_s point_altitude_t;
typedef struct point_altitude_s {
	supported_gad_shapes_e shape;
	struct geographical_coordinates_s *point;
	double altitude;
} point_altitude_t;

point_altitude_t *point_altitude_create(supported_gad_shapes_e		shape,
                                        geographical_coordinates_t	*point,
                                        double				altitude);
void point_altitude_free(point_altitude_t *point_altitude);
point_altitude_t *point_altitude_parseFromJSON(cJSON *point_altitudeJSON);
cJSON *point_altitude_convertToJSON(point_altitude_t *point_altitude);
point_altitude_t *point_altitude_copy(point_altitude_t	*dst,
                                      point_altitude_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _point_altitude_H_ */
