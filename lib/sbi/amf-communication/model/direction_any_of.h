/*
 * direction_any_of.h
 *
 *
 */

#ifndef _direction_any_of_H_
#define _direction_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { direction_any_of_NULL = 0, direction_any_of_NORTH,
	       direction_any_of_SOUTH, direction_any_of_EAST,
	       direction_any_of_WEST,
	       direction_any_of_NORTHWEST, direction_any_of_NORTHEAST,
	       direction_any_of_SOUTHWEST,
	       direction_any_of_SOUTHEAST } direction_any_of_e;

char *direction_any_of_ToString(direction_any_of_e direction_any_of);

direction_any_of_e direction_any_of_FromString(char *direction_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _direction_any_of_H_ */
