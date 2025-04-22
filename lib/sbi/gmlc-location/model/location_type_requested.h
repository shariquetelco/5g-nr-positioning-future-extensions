/*
 * location_type_requested.h
 *
 *
 */

#ifndef _location_type_requested_H_
#define _location_type_requested_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { location_type_requested_NULL = 0,
	       location_type_requested_CURRENT_LOCATION,
	       location_type_requested_CURRENT_OR_LAST_KNOWN_LOCATION,
	       location_type_requested_INITIAL_LOCATION,
	       location_type_requested_NOTIFICATION_VERIFICATION_ONLY }
location_type_requested_e;

char *location_type_requested_ToString(
	location_type_requested_e location_type_requested);

location_type_requested_e location_type_requested_FromString(
	char *location_type_requested);

#ifdef __cplusplus
}
#endif

#endif /* _location_type_requested_H_ */
