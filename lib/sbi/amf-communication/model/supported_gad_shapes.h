/*
 * supported_gad_shapes.h
 *
 * Indicates supported GAD shapes.
 */

#ifndef _supported_gad_shapes_H_
#define _supported_gad_shapes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "supported_gad_shapes_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct supported_gad_shapes_s supported_gad_shapes_t;
typedef struct supported_gad_shapes_s {} supported_gad_shapes_t;

supported_gad_shapes_t *supported_gad_shapes_create();
void supported_gad_shapes_free(supported_gad_shapes_t *supported_gad_shapes);
supported_gad_shapes_t *supported_gad_shapes_parseFromJSON(
	cJSON *supported_gad_shapesJSON);
cJSON *supported_gad_shapes_convertToJSON(
	supported_gad_shapes_t *supported_gad_shapes);
supported_gad_shapes_t *supported_gad_shapes_copy(
	supported_gad_shapes_t	*dst,
	supported_gad_shapes_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _supported_gad_shapes_H_ */
