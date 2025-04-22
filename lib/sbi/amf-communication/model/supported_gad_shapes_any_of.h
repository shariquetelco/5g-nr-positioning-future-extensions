/*
 * supported_gad_shapes_any_of.h
 *
 *
 */

#ifndef _supported_gad_shapes_any_of_H_
#define _supported_gad_shapes_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { supported_gad_shapes_any_of_NULL = 0,
	       supported_gad_shapes_any_of_POINT,
	       supported_gad_shapes_any_of_POINT_UNCERTAINTY_CIRCLE,
	       supported_gad_shapes_any_of_POINT_UNCERTAINTY_ELLIPSE,
	       supported_gad_shapes_any_of_POLYGON,
	       supported_gad_shapes_any_of_POINT_ALTITUDE,
	       supported_gad_shapes_any_of_POINT_ALTITUDE_UNCERTAINTY,
	       supported_gad_shapes_any_of_ELLIPSOID_ARC,
	       supported_gad_shapes_any_of_LOCAL_2D_POINT_UNCERTAINTY_ELLIPSE,
	       supported_gad_shapes_any_of_LOCAL_3D_POINT_UNCERTAINTY_ELLIPSOID,
	       supported_gad_shapes_any_of_DISTANCE_DIRECTION,
	       supported_gad_shapes_any_of_RELATIVE_2D_LOCATION_UNCERTAINTY_ELLIPSE,
	       supported_gad_shapes_any_of_RELATIVE_3D_LOCATION_UNCERTAINTY_ELLIPSOID }
supported_gad_shapes_any_of_e;

char *supported_gad_shapes_any_of_ToString(
	supported_gad_shapes_any_of_e supported_gad_shapes_any_of);

supported_gad_shapes_any_of_e supported_gad_shapes_any_of_FromString(
	char *supported_gad_shapes_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _supported_gad_shapes_any_of_H_ */
