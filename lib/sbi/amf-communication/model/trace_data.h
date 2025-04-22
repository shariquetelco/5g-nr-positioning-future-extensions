/*
 * trace_data.h
 *
 * contains Trace control and configuration parameters.
 */

#ifndef _trace_data_H_
#define _trace_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ipv6_addr.h"
#include "trace_depth.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct trace_data_s trace_data_t;
typedef struct trace_data_s {
	char *trace_ref;
	struct trace_depth_s *trace_depth;
	char *ne_type_list;
	char *event_list;
	char *collection_entity_ipv4_addr;
	struct ipv6_addr_s *collection_entity_ipv6_addr;
	char *trace_reporting_consumer_uri;
	char *interface_list;
} trace_data_t;

trace_data_t *trace_data_create(char *trace_ref, trace_depth_t *trace_depth,
                                char *ne_type_list, char *event_list,
                                char *collection_entity_ipv4_addr,
                                ipv6_addr_t *collection_entity_ipv6_addr,
                                char *trace_reporting_consumer_uri,
                                char *interface_list);
void trace_data_free(trace_data_t *trace_data);
trace_data_t *trace_data_parseFromJSON(cJSON *trace_dataJSON);
cJSON *trace_data_convertToJSON(trace_data_t *trace_data);
trace_data_t *trace_data_copy(trace_data_t *dst, trace_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _trace_data_H_ */
