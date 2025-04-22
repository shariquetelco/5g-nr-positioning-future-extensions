/*
 * geographic_area.h
 *
 * Geographic area specified by different shape.
 */

#ifndef _geographic_area_H_
#define _geographic_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ellipsoid_arc.h"
#include "geographical_coordinates.h"
#include "point.h"
#include "point_altitude.h"
#include "point_altitude_uncertainty.h"
#include "point_uncertainty_circle.h"
#include "point_uncertainty_ellipse.h"
#include "polygon.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct geographic_area_s geographic_area_t;
typedef struct geographic_area_s {
	struct supported_gad_shapes_s *shape;
	struct geographical_coordinates_s *point;
	float uncertainty;
	struct uncertainty_ellipse_s *uncertainty_ellipse;
	int confidence;
	list_t *point_list;
	double altitude;
	float uncertainty_altitude;
	bool is_v_confidence;
	int v_confidence;
	int inner_radius;
	float uncertainty_radius;
	int offset_angle;
	int included_angle;
} geographic_area_t;

geographic_area_t *geographic_area_create(supported_gad_shapes_t *shape,
                                          geographical_coordinates_t *point,
                                          float uncertainty,
                                          uncertainty_ellipse_t *uncertainty_ellipse, int confidence, list_t *point_list, double altitude, float uncertainty_altitude, bool is_v_confidence, int v_confidence, int inner_radius, float uncertainty_radius, int offset_angle, int included_angle);
void geographic_area_free(geographic_area_t *geographic_area);
geographic_area_t *geographic_area_parseFromJSON(cJSON *geographic_areaJSON);
cJSON *geographic_area_convertToJSON(geographic_area_t *geographic_area);
geographic_area_t *geographic_area_copy(geographic_area_t	*dst,
                                        geographic_area_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _geographic_area_H_ */
