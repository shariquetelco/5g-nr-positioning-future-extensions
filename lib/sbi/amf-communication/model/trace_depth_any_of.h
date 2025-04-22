/*
 * trace_depth_any_of.h
 *
 *
 */

#ifndef _trace_depth_any_of_H_
#define _trace_depth_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { trace_depth_any_of_NULL = 0, trace_depth_any_of_MINIMUM,
	       trace_depth_any_of_MEDIUM, trace_depth_any_of_MAXIMUM,
	       trace_depth_any_of_MINIMUM_WO_VENDOR_EXTENSION,
	       trace_depth_any_of_MEDIUM_WO_VENDOR_EXTENSION,
	       trace_depth_any_of_MAXIMUM_WO_VENDOR_EXTENSION }
trace_depth_any_of_e;

char *trace_depth_any_of_ToString(trace_depth_any_of_e trace_depth_any_of);

trace_depth_any_of_e trace_depth_any_of_FromString(char *trace_depth_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _trace_depth_any_of_H_ */
