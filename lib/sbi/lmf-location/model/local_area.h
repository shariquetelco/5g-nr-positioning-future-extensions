/*
 * local_area.h
 *
 * Local area specified by different shape
 */

#ifndef _local_area_H_
#define _local_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "local2d_point_uncertainty_ellipse.h"
#include "local3d_point_uncertainty_ellipsoid.h"
#include "local_origin.h"
#include "relative_cartesian_location.h"
#include "supported_gad_shapes.h"
#include "uncertainty_ellipse.h"
#include "uncertainty_ellipsoid.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct local_area_s local_area_t;
typedef struct local_area_s {
	supported_gad_shapes_e shape;
	struct local_origin_s *local_origin;
	struct relative_cartesian_location_s *point;
	struct uncertainty_ellipse_s *uncertainty_ellipse;
	int confidence;
	struct uncertainty_ellipsoid_s *uncertainty_ellipsoid;
} local_area_t;

local_area_t *local_area_create(supported_gad_shapes_e		shape,
                                local_origin_t			*local_origin,
                                relative_cartesian_location_t	*point,
                                uncertainty_ellipse_t		*uncertainty_ellipse,
                                int				confidence,
                                uncertainty_ellipsoid_t		*uncertainty_ellipsoid);
void local_area_free(local_area_t *local_area);
local_area_t *local_area_parseFromJSON(cJSON *local_areaJSON);
cJSON *local_area_convertToJSON(local_area_t *local_area);
local_area_t *local_area_copy(local_area_t *dst, local_area_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _local_area_H_ */
