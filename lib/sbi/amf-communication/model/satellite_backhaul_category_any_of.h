/*
 * satellite_backhaul_category_any_of.h
 *
 *
 */

#ifndef _satellite_backhaul_category_any_of_H_
#define _satellite_backhaul_category_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { satellite_backhaul_category_any_of_NULL = 0,
	       satellite_backhaul_category_any_of_GEO,
	       satellite_backhaul_category_any_of_MEO,
	       satellite_backhaul_category_any_of_LEO,
	       satellite_backhaul_category_any_of_OTHER_SAT,
	       satellite_backhaul_category_any_of_DYNAMIC_GEO,
	       satellite_backhaul_category_any_of_DYNAMIC_MEO,
	       satellite_backhaul_category_any_of_DYNAMIC_LEO,
	       satellite_backhaul_category_any_of_DYNAMIC_OTHER_SAT,
	       satellite_backhaul_category_any_of_NON_SATELLITE }
satellite_backhaul_category_any_of_e;

char *satellite_backhaul_category_any_of_ToString(
	satellite_backhaul_category_any_of_e satellite_backhaul_category_any_of);

satellite_backhaul_category_any_of_e
satellite_backhaul_category_any_of_FromString(
	char *satellite_backhaul_category_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _satellite_backhaul_category_any_of_H_ */
