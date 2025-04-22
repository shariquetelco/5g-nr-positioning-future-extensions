/*
 * congestion_type_any_of.h
 *
 *
 */

#ifndef _congestion_type_any_of_H_
#define _congestion_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { congestion_type_any_of_NULL = 0,
	       congestion_type_any_of_USER_PLANE,
	       congestion_type_any_of_CONTROL_PLANE,
	       congestion_type_any_of_USER_AND_CONTROL_PLANE }
congestion_type_any_of_e;

char *congestion_type_any_of_ToString(
	congestion_type_any_of_e congestion_type_any_of);

congestion_type_any_of_e congestion_type_any_of_FromString(
	char *congestion_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _congestion_type_any_of_H_ */
