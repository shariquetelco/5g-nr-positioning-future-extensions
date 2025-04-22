/*
 * local3d_point_uncertainty_ellipsoid_all_of.h
 *
 *
 */

#ifndef _local3d_point_uncertainty_ellipsoid_all_of_H_
#define _local3d_point_uncertainty_ellipsoid_all_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "local_origin.h"
#include "relative_cartesian_location.h"
#include "uncertainty_ellipsoid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct local3d_point_uncertainty_ellipsoid_all_of_s
        local3d_point_uncertainty_ellipsoid_all_of_t;
typedef struct local3d_point_uncertainty_ellipsoid_all_of_s {
	struct local_origin_s *local_origin;
	struct relative_cartesian_location_s *point;
	struct uncertainty_ellipsoid_s *uncertainty_ellipsoid;
	int confidence;
} local3d_point_uncertainty_ellipsoid_all_of_t;

local3d_point_uncertainty_ellipsoid_all_of_t *
local3d_point_uncertainty_ellipsoid_all_of_create(local_origin_t *local_origin,
                                                  relative_cartesian_location_t *point, uncertainty_ellipsoid_t *uncertainty_ellipsoid, int confidence);
void local3d_point_uncertainty_ellipsoid_all_of_free(
	local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);
local3d_point_uncertainty_ellipsoid_all_of_t *
local3d_point_uncertainty_ellipsoid_all_of_parseFromJSON(
	cJSON *local3d_point_uncertainty_ellipsoid_all_ofJSON);
cJSON *local3d_point_uncertainty_ellipsoid_all_of_convertToJSON(
	local3d_point_uncertainty_ellipsoid_all_of_t *local3d_point_uncertainty_ellipsoid_all_of);
local3d_point_uncertainty_ellipsoid_all_of_t *
local3d_point_uncertainty_ellipsoid_all_of_copy(
	local3d_point_uncertainty_ellipsoid_all_of_t	*dst,
	local3d_point_uncertainty_ellipsoid_all_of_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _local3d_point_uncertainty_ellipsoid_all_of_H_ */
