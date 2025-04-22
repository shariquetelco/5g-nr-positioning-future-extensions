/*
 * matching_direction.h
 *
 * Represents the matching direction when crossing a threshold.   Possible values are: - ASCENDING: Threshold is crossed in ascending direction. - DESCENDING: Threshold is crossed in descending direction. - CROSSED: Threshold is crossed either in ascending or descending direction.
 */

#ifndef _matching_direction_H_
#define _matching_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "matching_direction_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct matching_direction_s matching_direction_t;
typedef struct matching_direction_s {} matching_direction_t;

matching_direction_t *matching_direction_create();
void matching_direction_free(matching_direction_t *matching_direction);
matching_direction_t *matching_direction_parseFromJSON(
	cJSON *matching_directionJSON);
cJSON *matching_direction_convertToJSON(
	matching_direction_t *matching_direction);
matching_direction_t *matching_direction_copy(matching_direction_t	*dst,
                                              matching_direction_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _matching_direction_H_ */
