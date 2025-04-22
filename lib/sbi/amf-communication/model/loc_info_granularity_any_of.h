/*
 * loc_info_granularity_any_of.h
 *
 *
 */

#ifndef _loc_info_granularity_any_of_H_
#define _loc_info_granularity_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { loc_info_granularity_any_of_NULL = 0,
	       loc_info_granularity_any_of_TA_LEVEL,
	       loc_info_granularity_any_of_CELL_LEVEL,
	       loc_info_granularity_any_of_LON_AND_LAT_LEVEL }
loc_info_granularity_any_of_e;

char *loc_info_granularity_any_of_ToString(
	loc_info_granularity_any_of_e loc_info_granularity_any_of);

loc_info_granularity_any_of_e loc_info_granularity_any_of_FromString(
	char *loc_info_granularity_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _loc_info_granularity_any_of_H_ */
