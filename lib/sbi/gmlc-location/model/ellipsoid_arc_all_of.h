/*
 * ellipsoid_arc_all_of.h
 *
 *
 */

#ifndef _ellipsoid_arc_all_of_H_
#define _ellipsoid_arc_all_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_coordinates.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ellipsoid_arc_all_of_s ellipsoid_arc_all_of_t;
typedef struct ellipsoid_arc_all_of_s {
	struct geographical_coordinates_s *point;
	int inner_radius;
	float uncertainty_radius;
	int offset_angle;
	int included_angle;
	int confidence;
} ellipsoid_arc_all_of_t;

ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_create(
	geographical_coordinates_t *point, int inner_radius,
	float uncertainty_radius, int offset_angle, int included_angle,
	int confidence);
void ellipsoid_arc_all_of_free(ellipsoid_arc_all_of_t *ellipsoid_arc_all_of);
ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_parseFromJSON(
	cJSON *ellipsoid_arc_all_ofJSON);
cJSON *ellipsoid_arc_all_of_convertToJSON(
	ellipsoid_arc_all_of_t *ellipsoid_arc_all_of);
ellipsoid_arc_all_of_t *ellipsoid_arc_all_of_copy(
	ellipsoid_arc_all_of_t	*dst,
	ellipsoid_arc_all_of_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ellipsoid_arc_all_of_H_ */
