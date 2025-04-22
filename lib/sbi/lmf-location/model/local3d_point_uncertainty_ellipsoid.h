/*
 * local3d_point_uncertainty_ellipsoid.h
 *
 * Local 3D point with uncertainty ellipsoid
 */

#ifndef _local3d_point_uncertainty_ellipsoid_H_
#define _local3d_point_uncertainty_ellipsoid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "gad_shape.h"
#include "local_origin.h"
#include "relative_cartesian_location.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipsoid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct local3d_point_uncertainty_ellipsoid_s
        local3d_point_uncertainty_ellipsoid_t;
typedef struct local3d_point_uncertainty_ellipsoid_s {
	supported_gad_shapes_e shape;
	struct local_origin_s *local_origin;
	struct relative_cartesian_location_s *point;
	struct uncertainty_ellipsoid_s *uncertainty_ellipsoid;
	int confidence;
} local3d_point_uncertainty_ellipsoid_t;

local3d_point_uncertainty_ellipsoid_t *
local3d_point_uncertainty_ellipsoid_create(supported_gad_shapes_e shape,
                                           local_origin_t *local_origin,
                                           relative_cartesian_location_t *point,
                                           uncertainty_ellipsoid_t *uncertainty_ellipsoid, int confidence);
void local3d_point_uncertainty_ellipsoid_free(
	local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);
local3d_point_uncertainty_ellipsoid_t *
local3d_point_uncertainty_ellipsoid_parseFromJSON(
	cJSON *local3d_point_uncertainty_ellipsoidJSON);
cJSON *local3d_point_uncertainty_ellipsoid_convertToJSON(
	local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid);
local3d_point_uncertainty_ellipsoid_t *local3d_point_uncertainty_ellipsoid_copy(
	local3d_point_uncertainty_ellipsoid_t	*dst,
	local3d_point_uncertainty_ellipsoid_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _local3d_point_uncertainty_ellipsoid_H_ */
