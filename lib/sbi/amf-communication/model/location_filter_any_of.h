/*
 * location_filter_any_of.h
 *
 *
 */

#ifndef _location_filter_any_of_H_
#define _location_filter_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { location_filter_any_of_NULL = 0, location_filter_any_of_TAI,
	       location_filter_any_of_CELL_ID, location_filter_any_of_RAN_NODE,
	       location_filter_any_of_N3IWF, location_filter_any_of_UE_IP,
	       location_filter_any_of_UDP_PORT, location_filter_any_of_TNAP_ID,
	       location_filter_any_of_GLI,
	       location_filter_any_of_TWAP_ID } location_filter_any_of_e;

char *location_filter_any_of_ToString(
	location_filter_any_of_e location_filter_any_of);

location_filter_any_of_e location_filter_any_of_FromString(
	char *location_filter_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _location_filter_any_of_H_ */
