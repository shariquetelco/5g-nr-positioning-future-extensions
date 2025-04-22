/*
 * positioning_method_any_of.h
 *
 *
 */

#ifndef _positioning_method_any_of_H_
#define _positioning_method_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { positioning_method_any_of_NULL = 0,
	       positioning_method_any_of_CELLID, positioning_method_any_of_ECID,
	       positioning_method_any_of_OTDOA,
	       positioning_method_any_of_BAROMETRIC_PRESSURE,
	       positioning_method_any_of_WLAN,
	       positioning_method_any_of_BLUETOOTH,
	       positioning_method_any_of_MBS,
	       positioning_method_any_of_MOTION_SENSOR,
	       positioning_method_any_of_DL_TDOA,
	       positioning_method_any_of_DL_AOD,
	       positioning_method_any_of_MULTI_RTT,
	       positioning_method_any_of_NR_ECID,
	       positioning_method_any_of_UL_TDOA,
	       positioning_method_any_of_UL_AOA,
	       positioning_method_any_of_NETWORK_SPECIFIC,
	       positioning_method_any_of_SL_TDOA,
	       positioning_method_any_of_SL_TOA,
	       positioning_method_any_of_SL_AoA,
	       positioning_method_any_of_SL_RT } positioning_method_any_of_e;

char *positioning_method_any_of_ToString(
	positioning_method_any_of_e positioning_method_any_of);

positioning_method_any_of_e positioning_method_any_of_FromString(
	char *positioning_method_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _positioning_method_any_of_H_ */
