/*
 * point_uncertainty_circle.h
 *
 * Ellipsoid point with uncertainty circle.
 */

#ifndef _point_uncertainty_circle_H_
#define _point_uncertainty_circle_H_

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

typedef struct point_uncertainty_circle_s point_uncertainty_circle_t;
typedef struct point_uncertainty_circle_s {
	supported_gad_shapes_e shape;
	struct geographical_coordinates_s *point;
	float uncertainty;
} point_uncertainty_circle_t;

point_uncertainty_circle_t *point_uncertainty_circle_create(
	supported_gad_shapes_e shape, geographical_coordinates_t *point,
	float uncertainty);
void point_uncertainty_circle_free(
	point_uncertainty_circle_t *point_uncertainty_circle);
point_uncertainty_circle_t *point_uncertainty_circle_parseFromJSON(
	cJSON *point_uncertainty_circleJSON);
cJSON *point_uncertainty_circle_convertToJSON(
	point_uncertainty_circle_t *point_uncertainty_circle);
point_uncertainty_circle_t *point_uncertainty_circle_copy(
	point_uncertainty_circle_t *dst, point_uncertainty_circle_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _point_uncertainty_circle_H_ */
