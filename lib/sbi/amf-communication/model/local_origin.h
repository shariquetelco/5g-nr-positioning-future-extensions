/*
 * local_origin.h
 *
 * Indicates a Local origin in a reference system
 */

#ifndef _local_origin_H_
#define _local_origin_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographical_coordinates.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct local_origin_s local_origin_t;
typedef struct local_origin_s {
	char *coordinate_id;
	struct geographical_coordinates_s *point;
} local_origin_t;

local_origin_t *local_origin_create(char			*coordinate_id,
                                    geographical_coordinates_t	*point);
void local_origin_free(local_origin_t *local_origin);
local_origin_t *local_origin_parseFromJSON(cJSON *local_originJSON);
cJSON *local_origin_convertToJSON(local_origin_t *local_origin);
local_origin_t *local_origin_copy(local_origin_t *dst, local_origin_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _local_origin_H_ */
