/*
 * service_experience_type.h
 *
 * Represents the type of the service experience analytics.   Possible values are:   - VOICE: Indicates that the service experience analytics is for voice service. - VIDEO: Indicates that the service experience analytics is for video service. - OTHER: Indicates that the service experience analytics is for other service.
 */

#ifndef _service_experience_type_H_
#define _service_experience_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "service_experience_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct service_experience_type_s service_experience_type_t;
typedef struct service_experience_type_s {} service_experience_type_t;

service_experience_type_t *service_experience_type_create();
void service_experience_type_free(
	service_experience_type_t *service_experience_type);
service_experience_type_t *service_experience_type_parseFromJSON(
	cJSON *service_experience_typeJSON);
cJSON *service_experience_type_convertToJSON(
	service_experience_type_t *service_experience_type);
service_experience_type_t *service_experience_type_copy(
	service_experience_type_t *dst, service_experience_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _service_experience_type_H_ */
