/*
 * point_all_of.h
 *
 *
 */

#ifndef _point_all_of_H_
#define _point_all_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_coordinates.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct point_all_of_s point_all_of_t;
typedef struct point_all_of_s {
	struct geographical_coordinates_s *point;
} point_all_of_t;

point_all_of_t *point_all_of_create(geographical_coordinates_t *point);
void point_all_of_free(point_all_of_t *point_all_of);
point_all_of_t *point_all_of_parseFromJSON(cJSON *point_all_ofJSON);
cJSON *point_all_of_convertToJSON(point_all_of_t *point_all_of);
point_all_of_t *point_all_of_copy(point_all_of_t *dst, point_all_of_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _point_all_of_H_ */
