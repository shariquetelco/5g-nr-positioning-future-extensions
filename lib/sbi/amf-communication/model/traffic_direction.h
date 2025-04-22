/*
 * traffic_direction.h
 *
 * Represents the traffic direction for the resource usage information.   Possible values are:     - UL_AND_DL: Uplink and downlink traffic.   - UL: Uplink traffic.   - DL: Downlink traffic.
 */

#ifndef _traffic_direction_H_
#define _traffic_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "traffic_direction_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct traffic_direction_s traffic_direction_t;
typedef struct traffic_direction_s {} traffic_direction_t;

traffic_direction_t *traffic_direction_create();
void traffic_direction_free(traffic_direction_t *traffic_direction);
traffic_direction_t *traffic_direction_parseFromJSON(
	cJSON *traffic_directionJSON);
cJSON *traffic_direction_convertToJSON(traffic_direction_t *traffic_direction);
traffic_direction_t *traffic_direction_copy(traffic_direction_t *dst,
                                            traffic_direction_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _traffic_direction_H_ */
