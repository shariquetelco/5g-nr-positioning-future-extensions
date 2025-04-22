/*
 * gad_shape.h
 *
 * Common base type for GAD shapes.
 */

#ifndef _gad_shape_H_
#define _gad_shape_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "supported_gad_shapes.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct gad_shape_s gad_shape_t;
typedef struct gad_shape_s {
	supported_gad_shapes_e shape;
} gad_shape_t;

gad_shape_t *gad_shape_create(supported_gad_shapes_e shape);
void gad_shape_free(gad_shape_t *gad_shape);
gad_shape_t *gad_shape_parseFromJSON(cJSON *gad_shapeJSON);
cJSON *gad_shape_convertToJSON(gad_shape_t *gad_shape);
gad_shape_t *gad_shape_copy(gad_shape_t *dst, gad_shape_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _gad_shape_H_ */
