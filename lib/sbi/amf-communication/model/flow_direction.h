/*
 * flow_direction.h
 *
 * Indicates the direction of the service data flow.   Possible values are: - DOWNLINK: The corresponding filter applies for traffic to the UE. - UPLINK: The corresponding filter applies for traffic from the UE. - BIDIRECTIONAL: The corresponding filter applies for traffic both to and from the UE. - UNSPECIFIED: The corresponding filter applies for traffic to the UE (downlink), but has no specific direction declared. The service data flow detection shall apply the filter for uplink traffic as if the filter was bidirectional. The PCF shall not use the value UNSPECIFIED in filters created by the network in NW-initiated procedures. The PCF shall only include the value UNSPECIFIED in filters in UE-initiated procedures if the same value is received from the SMF.
 */

#ifndef _flow_direction_H_
#define _flow_direction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "flow_direction_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct flow_direction_s flow_direction_t;
typedef struct flow_direction_s {} flow_direction_t;

flow_direction_t *flow_direction_create();
void flow_direction_free(flow_direction_t *flow_direction);
flow_direction_t *flow_direction_parseFromJSON(cJSON *flow_directionJSON);
cJSON *flow_direction_convertToJSON(flow_direction_t *flow_direction);
flow_direction_t *flow_direction_copy(flow_direction_t	*dst,
                                      flow_direction_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _flow_direction_H_ */
