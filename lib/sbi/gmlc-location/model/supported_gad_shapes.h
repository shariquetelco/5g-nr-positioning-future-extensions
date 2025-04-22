/*
 * supported_gad_shapes.h
 *
 *
 */

#ifndef _supported_gad_shapes_H_
#define _supported_gad_shapes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { supported_gad_shapes_NULL = 0, supported_gad_shapes_POINT,
	       supported_gad_shapes_POINT_UNCERTAINTY_CIRCLE,
	       supported_gad_shapes_POINT_UNCERTAINTY_ELLIPSE,
	       supported_gad_shapes_POLYGON,
	       supported_gad_shapes_POINT_ALTITUDE,
	       supported_gad_shapes_POINT_ALTITUDE_UNCERTAINTY,
	       supported_gad_shapes_ELLIPSOID_ARC,
	       supported_gad_shapes_LOCAL_2D_POINT_UNCERTAINTY_ELLIPSE,
	       supported_gad_shapes_LOCAL_3D_POINT_UNCERTAINTY_ELLIPSOID,
	       supported_gad_shapes_DISTANCE_DIRECTION,
	       supported_gad_shapes_RELATIVE_2D_LOCATION_UNCERTAINTY_ELLIPSE,
	       supported_gad_shapes_RELATIVE_3D_LOCATION_UNCERTAINTY_ELLIPSOID }
supported_gad_shapes_e;

char *supported_gad_shapes_ToString(
	supported_gad_shapes_e supported_gad_shapes);

supported_gad_shapes_e supported_gad_shapes_FromString(
	char *supported_gad_shapes);

#ifdef __cplusplus
}
#endif

#endif /* _supported_gad_shapes_H_ */
