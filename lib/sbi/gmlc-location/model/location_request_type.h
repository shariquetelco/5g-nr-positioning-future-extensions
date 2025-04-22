/*
 * location_request_type.h
 *
 *
 */

#ifndef _location_request_type_H_
#define _location_request_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { location_request_type_NULL = 0, location_request_type_NI_LR,
	       location_request_type_MT_LR,
	       location_request_type_MO_LR } location_request_type_e;

char *location_request_type_ToString(
	location_request_type_e location_request_type);

location_request_type_e location_request_type_FromString(
	char *location_request_type);

#ifdef __cplusplus
}
#endif

#endif /* _location_request_type_H_ */
