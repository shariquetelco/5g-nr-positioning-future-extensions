/*
 * reachability_filter.h
 *
 * Event filter for REACHABILITY_REPORT event type
 */

#ifndef _reachability_filter_H_
#define _reachability_filter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "reachability_filter_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct reachability_filter_s reachability_filter_t;
typedef struct reachability_filter_s {} reachability_filter_t;

reachability_filter_t *reachability_filter_create();
void reachability_filter_free(reachability_filter_t *reachability_filter);
reachability_filter_t *reachability_filter_parseFromJSON(
	cJSON *reachability_filterJSON);
cJSON *reachability_filter_convertToJSON(
	reachability_filter_t *reachability_filter);
reachability_filter_t *reachability_filter_copy(reachability_filter_t	*dst,
                                                reachability_filter_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _reachability_filter_H_ */
