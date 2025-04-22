/*
 * traffic_direction_any_of.h
 *
 *
 */

#ifndef _traffic_direction_any_of_H_
#define _traffic_direction_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { traffic_direction_any_of_NULL = 0,
	       traffic_direction_any_of_UL_AND_DL, traffic_direction_any_of_UL,
	       traffic_direction_any_of_DL } traffic_direction_any_of_e;

char *traffic_direction_any_of_ToString(
	traffic_direction_any_of_e traffic_direction_any_of);

traffic_direction_any_of_e traffic_direction_any_of_FromString(
	char *traffic_direction_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _traffic_direction_any_of_H_ */
