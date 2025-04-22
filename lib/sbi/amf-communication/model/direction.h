/*
 * direction.h
 *
 * Possible values are:     - NORTH: North direction.   - SOUTH: South direction.   - EAST: EAST direction.   - WEST: WEST direction.   - NORTHWEST: Northwest direction.   - NORTHEAST: Northeast direction.   - SOUTHWEST: Southwest direction.   - SOUTHEAST: Southeast direction.
 */

#ifndef _direction_H_
#define _direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "direction_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct direction_s direction_t;
typedef struct direction_s {} direction_t;

direction_t *direction_create();
void direction_free(direction_t *direction);
direction_t *direction_parseFromJSON(cJSON *directionJSON);
cJSON *direction_convertToJSON(direction_t *direction);
direction_t *direction_copy(direction_t *dst, direction_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _direction_H_ */
