/*
 * flow_info.h
 *
 * Represents IP flow information.
 */

#ifndef _flow_info_H_
#define _flow_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct flow_info_s flow_info_t;
typedef struct flow_info_s {
	int flow_id;
	list_t *flow_descriptions;
	char *tos_tc;
} flow_info_t;

flow_info_t *flow_info_create(int flow_id, list_t *flow_descriptions,
                              char *tos_tc);
void flow_info_free(flow_info_t *flow_info);
flow_info_t *flow_info_parseFromJSON(cJSON *flow_infoJSON);
cJSON *flow_info_convertToJSON(flow_info_t *flow_info);
flow_info_t *flow_info_copy(flow_info_t *dst, flow_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _flow_info_H_ */
