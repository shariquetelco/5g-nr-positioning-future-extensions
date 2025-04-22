/*
 * positioning_method.h
 *
 * Indicates supported positioning methods.
 */

#ifndef _positioning_method_H_
#define _positioning_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "positioning_method_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct positioning_method_s positioning_method_t;
typedef struct positioning_method_s {} positioning_method_t;

positioning_method_t *positioning_method_create();
void positioning_method_free(positioning_method_t *positioning_method);
positioning_method_t *positioning_method_parseFromJSON(
	cJSON *positioning_methodJSON);
cJSON *positioning_method_convertToJSON(
	positioning_method_t *positioning_method);
positioning_method_t *positioning_method_copy(positioning_method_t	*dst,
                                              positioning_method_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _positioning_method_H_ */
