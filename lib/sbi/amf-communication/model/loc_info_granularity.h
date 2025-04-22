/*
 * loc_info_granularity.h
 *
 * Represents the preferred granularity of location information.   Possible values are:     - TA_LEVEL: Indicates location granularity of TA level.   - CELL_LEVEL: Indicates location granularity of Cell level.   - LON_AND_LAT_LEVEL: Indicates location granularity of longitude and latitude level.
 */

#ifndef _loc_info_granularity_H_
#define _loc_info_granularity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "loc_info_granularity_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_info_granularity_s loc_info_granularity_t;
typedef struct loc_info_granularity_s {} loc_info_granularity_t;

loc_info_granularity_t *loc_info_granularity_create();
void loc_info_granularity_free(loc_info_granularity_t *loc_info_granularity);
loc_info_granularity_t *loc_info_granularity_parseFromJSON(
	cJSON *loc_info_granularityJSON);
cJSON *loc_info_granularity_convertToJSON(
	loc_info_granularity_t *loc_info_granularity);
loc_info_granularity_t *loc_info_granularity_copy(
	loc_info_granularity_t	*dst,
	loc_info_granularity_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_info_granularity_H_ */
