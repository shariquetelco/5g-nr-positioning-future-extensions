/*
 * reachability_filter_any_of.h
 *
 *
 */

#ifndef _reachability_filter_any_of_H_
#define _reachability_filter_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { reachability_filter_any_of_NULL = 0,
	       reachability_filter_any_of_UE_REACHABILITY_STATUS_CHANGE,
	       reachability_filter_any_of_UE_REACHABLE_DL_TRAFFIC }
reachability_filter_any_of_e;

char *reachability_filter_any_of_ToString(
	reachability_filter_any_of_e reachability_filter_any_of);

reachability_filter_any_of_e reachability_filter_any_of_FromString(
	char *reachability_filter_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _reachability_filter_any_of_H_ */
