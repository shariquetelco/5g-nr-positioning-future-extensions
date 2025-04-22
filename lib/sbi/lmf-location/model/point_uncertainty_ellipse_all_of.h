/*
 * point_uncertainty_ellipse_all_of.h
 *
 *
 */

#ifndef _point_uncertainty_ellipse_all_of_H_
#define _point_uncertainty_ellipse_all_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_coordinates.h"
#include "uncertainty_ellipse.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct point_uncertainty_ellipse_all_of_s
        point_uncertainty_ellipse_all_of_t;
typedef struct point_uncertainty_ellipse_all_of_s {
	struct geographical_coordinates_s *point;
	struct uncertainty_ellipse_s *uncertainty_ellipse;
	int confidence;
} point_uncertainty_ellipse_all_of_t;

point_uncertainty_ellipse_all_of_t *point_uncertainty_ellipse_all_of_create(
	geographical_coordinates_t *point,
	uncertainty_ellipse_t *uncertainty_ellipse, int confidence);
void point_uncertainty_ellipse_all_of_free(
	point_uncertainty_ellipse_all_of_t *point_uncertainty_ellipse_all_of);
point_uncertainty_ellipse_all_of_t *
point_uncertainty_ellipse_all_of_parseFromJSON(
	cJSON *point_uncertainty_ellipse_all_ofJSON);
cJSON *point_uncertainty_ellipse_all_of_convertToJSON(
	point_uncertainty_ellipse_all_of_t *point_uncertainty_ellipse_all_of);
point_uncertainty_ellipse_all_of_t *point_uncertainty_ellipse_all_of_copy(
	point_uncertainty_ellipse_all_of_t	*dst,
	point_uncertainty_ellipse_all_of_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _point_uncertainty_ellipse_all_of_H_ */
