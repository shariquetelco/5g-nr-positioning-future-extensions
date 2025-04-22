/*
 * local2d_point_uncertainty_ellipse.h
 *
 * Local 2D point with uncertainty ellipse
 */

#ifndef _local2d_point_uncertainty_ellipse_H_
#define _local2d_point_uncertainty_ellipse_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "gad_shape.h"
#include "local_origin.h"
#include "relative_cartesian_location.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct local2d_point_uncertainty_ellipse_s
        local2d_point_uncertainty_ellipse_t;
typedef struct local2d_point_uncertainty_ellipse_s {
	struct supported_gad_shapes_s *shape;
	struct local_origin_s *local_origin;
	struct relative_cartesian_location_s *point;
	struct uncertainty_ellipse_s *uncertainty_ellipse;
	int confidence;
} local2d_point_uncertainty_ellipse_t;

local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_create(
	supported_gad_shapes_t *shape, local_origin_t *local_origin,
	relative_cartesian_location_t *point,
	uncertainty_ellipse_t *uncertainty_ellipse, int confidence);
void local2d_point_uncertainty_ellipse_free(
	local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);
local2d_point_uncertainty_ellipse_t *
local2d_point_uncertainty_ellipse_parseFromJSON(
	cJSON *local2d_point_uncertainty_ellipseJSON);
cJSON *local2d_point_uncertainty_ellipse_convertToJSON(
	local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse);
local2d_point_uncertainty_ellipse_t *local2d_point_uncertainty_ellipse_copy(
	local2d_point_uncertainty_ellipse_t	*dst,
	local2d_point_uncertainty_ellipse_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _local2d_point_uncertainty_ellipse_H_ */
