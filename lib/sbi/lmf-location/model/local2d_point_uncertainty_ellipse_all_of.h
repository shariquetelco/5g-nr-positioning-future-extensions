/*
 * local2d_point_uncertainty_ellipse_all_of.h
 *
 *
 */

#ifndef _local2d_point_uncertainty_ellipse_all_of_H_
#define _local2d_point_uncertainty_ellipse_all_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "local_origin.h"
#include "relative_cartesian_location.h"
#include "uncertainty_ellipse.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct local2d_point_uncertainty_ellipse_all_of_s
        local2d_point_uncertainty_ellipse_all_of_t;
typedef struct local2d_point_uncertainty_ellipse_all_of_s {
	struct local_origin_s *local_origin;
	struct relative_cartesian_location_s *point;
	struct uncertainty_ellipse_s *uncertainty_ellipse;
	int confidence;
} local2d_point_uncertainty_ellipse_all_of_t;

local2d_point_uncertainty_ellipse_all_of_t *
local2d_point_uncertainty_ellipse_all_of_create(local_origin_t *local_origin,
                                                relative_cartesian_location_t *point, uncertainty_ellipse_t *uncertainty_ellipse, int confidence);
void local2d_point_uncertainty_ellipse_all_of_free(
	local2d_point_uncertainty_ellipse_all_of_t *local2d_point_uncertainty_ellipse_all_of);
local2d_point_uncertainty_ellipse_all_of_t *
local2d_point_uncertainty_ellipse_all_of_parseFromJSON(
	cJSON *local2d_point_uncertainty_ellipse_all_ofJSON);
cJSON *local2d_point_uncertainty_ellipse_all_of_convertToJSON(
	local2d_point_uncertainty_ellipse_all_of_t *local2d_point_uncertainty_ellipse_all_of);
local2d_point_uncertainty_ellipse_all_of_t *
local2d_point_uncertainty_ellipse_all_of_copy(
	local2d_point_uncertainty_ellipse_all_of_t	*dst,
	local2d_point_uncertainty_ellipse_all_of_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _local2d_point_uncertainty_ellipse_all_of_H_ */
