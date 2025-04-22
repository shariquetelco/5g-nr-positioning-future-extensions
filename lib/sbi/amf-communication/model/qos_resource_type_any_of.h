/*
 * qos_resource_type_any_of.h
 *
 *
 */

#ifndef _qos_resource_type_any_of_H_
#define _qos_resource_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { qos_resource_type_any_of_NULL = 0,
	       qos_resource_type_any_of_NON_GBR,
	       qos_resource_type_any_of_NON_CRITICAL_GBR,
	       qos_resource_type_any_of_CRITICAL_GBR }
qos_resource_type_any_of_e;

char *qos_resource_type_any_of_ToString(
	qos_resource_type_any_of_e qos_resource_type_any_of);

qos_resource_type_any_of_e qos_resource_type_any_of_FromString(
	char *qos_resource_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _qos_resource_type_any_of_H_ */
