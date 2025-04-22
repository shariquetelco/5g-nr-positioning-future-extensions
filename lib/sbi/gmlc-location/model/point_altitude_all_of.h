/*
 * point_altitude_all_of.h
 *
 *
 */

#ifndef _point_altitude_all_of_H_
#define _point_altitude_all_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_coordinates.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct point_altitude_all_of_s point_altitude_all_of_t;
typedef struct point_altitude_all_of_s {
	struct geographical_coordinates_s *point;
	double altitude;
} point_altitude_all_of_t;

point_altitude_all_of_t *point_altitude_all_of_create(
	geographical_coordinates_t *point, double altitude);
void point_altitude_all_of_free(point_altitude_all_of_t *point_altitude_all_of);
point_altitude_all_of_t *point_altitude_all_of_parseFromJSON(
	cJSON *point_altitude_all_ofJSON);
cJSON *point_altitude_all_of_convertToJSON(
	point_altitude_all_of_t *point_altitude_all_of);
point_altitude_all_of_t *point_altitude_all_of_copy(
	point_altitude_all_of_t *dst, point_altitude_all_of_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _point_altitude_all_of_H_ */
