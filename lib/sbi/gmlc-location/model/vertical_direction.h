/*
 * vertical_direction.h
 *
 * Indicates direction of vertical speed.
 */

#ifndef _vertical_direction_H_
#define _vertical_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { vertical_direction_NULL = 0, vertical_direction_UPWARD,
	       vertical_direction_DOWNWARD } vertical_direction_e;

char *vertical_direction_ToString(vertical_direction_e vertical_direction);

vertical_direction_e vertical_direction_FromString(char *vertical_direction);

#ifdef __cplusplus
}
#endif

#endif /* _vertical_direction_H_ */
