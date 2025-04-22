/*
 * location_privacy_ver_result.h
 *
 * The result of location privacy verification by UE
 */

#ifndef _location_privacy_ver_result_H_
#define _location_privacy_ver_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "location_privacy_ver_result_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_privacy_ver_result_s location_privacy_ver_result_t;
typedef struct location_privacy_ver_result_s {} location_privacy_ver_result_t;

location_privacy_ver_result_t *location_privacy_ver_result_create();
void location_privacy_ver_result_free(
	location_privacy_ver_result_t *location_privacy_ver_result);
location_privacy_ver_result_t *location_privacy_ver_result_parseFromJSON(
	cJSON *location_privacy_ver_resultJSON);
cJSON *location_privacy_ver_result_convertToJSON(
	location_privacy_ver_result_t *location_privacy_ver_result);
location_privacy_ver_result_t *location_privacy_ver_result_copy(
	location_privacy_ver_result_t *dst, location_privacy_ver_result_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _location_privacy_ver_result_H_ */
