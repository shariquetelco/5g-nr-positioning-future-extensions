/*
 * point.h
 *
 * Ellipsoid Point.
 */

#ifndef _point_H_
#define _point_H_

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

typedef struct point_s point_t;
typedef struct point_s {
	struct supported_gad_shapes_s *shape;
	struct geographical_coordinates_s *point;
} point_t;

point_t *point_create(supported_gad_shapes_t		*shape,
                      geographical_coordinates_t	*point);
void point_free(point_t *point);
point_t *point_parseFromJSON(cJSON *pointJSON);
cJSON *point_convertToJSON(point_t *point);
point_t *point_copy(point_t *dst, point_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _point_H_ */
