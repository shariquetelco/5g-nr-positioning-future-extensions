/*
 * matching_direction_any_of.h
 *
 *
 */

#ifndef _matching_direction_any_of_H_
#define _matching_direction_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { matching_direction_any_of_NULL = 0,
	       matching_direction_any_of_ASCENDING,
	       matching_direction_any_of_DESCENDING,
	       matching_direction_any_of_CROSSED } matching_direction_any_of_e;

char *matching_direction_any_of_ToString(
	matching_direction_any_of_e matching_direction_any_of);

matching_direction_any_of_e matching_direction_any_of_FromString(
	char *matching_direction_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _matching_direction_any_of_H_ */
