/*
 * positioning_method.h
 *
 *
 */

#ifndef _positioning_method_H_
#define _positioning_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { positioning_method_NULL = 0, positioning_method_CELLID,
	       positioning_method_ECID, positioning_method_OTDOA,
	       positioning_method_BAROMETRIC_PRESSURE, positioning_method_WLAN,
	       positioning_method_BLUETOOTH, positioning_method_MBS,
	       positioning_method_MOTION_SENSOR, positioning_method_DL_TDOA,
	       positioning_method_DL_AOD, positioning_method_MULTI_RTT,
	       positioning_method_NR_ECID, positioning_method_UL_TDOA,
	       positioning_method_UL_AOA, positioning_method_NETWORK_SPECIFIC,
	       positioning_method_SL_TDOA, positioning_method_SL_TOA,
	       positioning_method_SL_AoA,
	       positioning_method_SL_RT } positioning_method_e;

char *positioning_method_ToString(positioning_method_e positioning_method);

positioning_method_e positioning_method_FromString(char *positioning_method);

#ifdef __cplusplus
}
#endif

#endif /* _positioning_method_H_ */
