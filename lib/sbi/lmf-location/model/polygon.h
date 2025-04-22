/*
 * polygon.h
 *
 * Polygon.
 */

#ifndef _polygon_H_
#define _polygon_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "gad_shape.h"
#include "geographical_coordinates.h"
#include "supported_gad_shapes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct polygon_s polygon_t;
typedef struct polygon_s {
	supported_gad_shapes_e shape;
	list_t *point_list;
} polygon_t;

polygon_t *polygon_create(supported_gad_shapes_e shape, list_t *point_list);
void polygon_free(polygon_t *polygon);
polygon_t *polygon_parseFromJSON(cJSON *polygonJSON);
cJSON *polygon_convertToJSON(polygon_t *polygon);
polygon_t *polygon_copy(polygon_t *dst, polygon_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _polygon_H_ */
