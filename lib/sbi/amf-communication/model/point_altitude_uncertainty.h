/*
 * point_altitude_uncertainty.h
 *
 * Ellipsoid point with altitude and uncertainty ellipsoid.
 */

#ifndef _point_altitude_uncertainty_H_
#define _point_altitude_uncertainty_H_

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

typedef struct point_altitude_uncertainty_s point_altitude_uncertainty_t;
typedef struct point_altitude_uncertainty_s {
	struct supported_gad_shapes_s *shape;
	struct geographical_coordinates_s *point;
	double altitude;
	struct uncertainty_ellipse_s *uncertainty_ellipse;
	float uncertainty_altitude;
	int confidence;
	bool is_v_confidence;
	int v_confidence;
} point_altitude_uncertainty_t;

point_altitude_uncertainty_t *point_altitude_uncertainty_create(
	supported_gad_shapes_t *shape, geographical_coordinates_t *point,
	double altitude, uncertainty_ellipse_t *uncertainty_ellipse,
	float uncertainty_altitude, int confidence, bool is_v_confidence,
	int v_confidence);
void point_altitude_uncertainty_free(
	point_altitude_uncertainty_t *point_altitude_uncertainty);
point_altitude_uncertainty_t *point_altitude_uncertainty_parseFromJSON(
	cJSON *point_altitude_uncertaintyJSON);
cJSON *point_altitude_uncertainty_convertToJSON(
	point_altitude_uncertainty_t *point_altitude_uncertainty);
point_altitude_uncertainty_t *point_altitude_uncertainty_copy(
	point_altitude_uncertainty_t *dst, point_altitude_uncertainty_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _point_altitude_uncertainty_H_ */
