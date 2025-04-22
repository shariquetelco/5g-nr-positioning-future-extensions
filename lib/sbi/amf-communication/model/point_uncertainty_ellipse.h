/*
 * point_uncertainty_ellipse.h
 *
 * Ellipsoid point with uncertainty ellipse.
 */

#ifndef _point_uncertainty_ellipse_H_
#define _point_uncertainty_ellipse_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct point_uncertainty_ellipse_s point_uncertainty_ellipse_t;
typedef struct point_uncertainty_ellipse_s {
	struct supported_gad_shapes_s *shape;
	struct geographical_coordinates_s *point;
	struct uncertainty_ellipse_s *uncertainty_ellipse;
	int confidence;
} point_uncertainty_ellipse_t;

point_uncertainty_ellipse_t *point_uncertainty_ellipse_create(
	supported_gad_shapes_t *shape, geographical_coordinates_t *point,
	uncertainty_ellipse_t *uncertainty_ellipse, int confidence);
void point_uncertainty_ellipse_free(
	point_uncertainty_ellipse_t *point_uncertainty_ellipse);
point_uncertainty_ellipse_t *point_uncertainty_ellipse_parseFromJSON(
	cJSON *point_uncertainty_ellipseJSON);
cJSON *point_uncertainty_ellipse_convertToJSON(
	point_uncertainty_ellipse_t *point_uncertainty_ellipse);
point_uncertainty_ellipse_t *point_uncertainty_ellipse_copy(
	point_uncertainty_ellipse_t *dst, point_uncertainty_ellipse_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _point_uncertainty_ellipse_H_ */
