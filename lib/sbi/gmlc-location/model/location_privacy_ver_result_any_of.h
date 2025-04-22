/*
 * location_privacy_ver_result_any_of.h
 *
 *
 */

#ifndef _location_privacy_ver_result_any_of_H_
#define _location_privacy_ver_result_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { location_privacy_ver_result_any_of_NULL = 0,
	       location_privacy_ver_result_any_of_LOCATION_ALLOWED,
	       location_privacy_ver_result_any_of_LOCATION_NOT_ALLOWED,
	       location_privacy_ver_result_any_of_RESPONSE_TIME_OUT }
location_privacy_ver_result_any_of_e;

char *location_privacy_ver_result_any_of_ToString(
	location_privacy_ver_result_any_of_e location_privacy_ver_result_any_of);

location_privacy_ver_result_any_of_e
location_privacy_ver_result_any_of_FromString(
	char *location_privacy_ver_result_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _location_privacy_ver_result_any_of_H_ */
