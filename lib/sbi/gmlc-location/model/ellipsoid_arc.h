/*
 * ellipsoid_arc.h
 *
 * Ellipsoid Arc.
 */

#ifndef _ellipsoid_arc_H_
#define _ellipsoid_arc_H_

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

typedef struct ellipsoid_arc_s ellipsoid_arc_t;
typedef struct ellipsoid_arc_s {
	supported_gad_shapes_e shape;
	struct geographical_coordinates_s *point;
	int inner_radius;
	float uncertainty_radius;
	int offset_angle;
	int included_angle;
	int confidence;
} ellipsoid_arc_t;

ellipsoid_arc_t *ellipsoid_arc_create(supported_gad_shapes_e shape,
                                      geographical_coordinates_t *point,
                                      int inner_radius,
                                      float uncertainty_radius,
                                      int offset_angle, int included_angle,
                                      int confidence);
void ellipsoid_arc_free(ellipsoid_arc_t *ellipsoid_arc);
ellipsoid_arc_t *ellipsoid_arc_parseFromJSON(cJSON *ellipsoid_arcJSON);
cJSON *ellipsoid_arc_convertToJSON(ellipsoid_arc_t *ellipsoid_arc);
ellipsoid_arc_t *ellipsoid_arc_copy(ellipsoid_arc_t *dst, ellipsoid_arc_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ellipsoid_arc_H_ */
