/*
 * flow_direction_any_of.h
 *
 *
 */

#ifndef _flow_direction_any_of_H_
#define _flow_direction_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { flow_direction_any_of_NULL = 0, flow_direction_any_of_DOWNLINK,
	       flow_direction_any_of_UPLINK,
	       flow_direction_any_of_BIDIRECTIONAL,
	       flow_direction_any_of_UNSPECIFIED } flow_direction_any_of_e;

char *flow_direction_any_of_ToString(
	flow_direction_any_of_e flow_direction_any_of);

flow_direction_any_of_e flow_direction_any_of_FromString(
	char *flow_direction_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _flow_direction_any_of_H_ */
