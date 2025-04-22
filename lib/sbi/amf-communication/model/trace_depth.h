/*
 * trace_depth.h
 *
 * The enumeration TraceDepth defines how detailed information should be recorded in the trace. See 3GPP TS 32.422 for further description of the values. It shall comply with the provisions defined in table 5.6.3.1-1
 */

#ifndef _trace_depth_H_
#define _trace_depth_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "trace_depth_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct trace_depth_s trace_depth_t;
typedef struct trace_depth_s {} trace_depth_t;

trace_depth_t *trace_depth_create();
void trace_depth_free(trace_depth_t *trace_depth);
trace_depth_t *trace_depth_parseFromJSON(cJSON *trace_depthJSON);
cJSON *trace_depth_convertToJSON(trace_depth_t *trace_depth);
trace_depth_t *trace_depth_copy(trace_depth_t *dst, trace_depth_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _trace_depth_H_ */
