/*
 * service_experience_type_any_of.h
 *
 *
 */

#ifndef _service_experience_type_any_of_H_
#define _service_experience_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { service_experience_type_any_of_NULL = 0,
	       service_experience_type_any_of_VOICE,
	       service_experience_type_any_of_VIDEO,
	       service_experience_type_any_of_OTHER }
service_experience_type_any_of_e;

char *service_experience_type_any_of_ToString(
	service_experience_type_any_of_e service_experience_type_any_of);

service_experience_type_any_of_e service_experience_type_any_of_FromString(
	char *service_experience_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _service_experience_type_any_of_H_ */
