/*
 * up_connection_status_any_of.h
 *
 *
 */

#ifndef _up_connection_status_any_of_H_
#define _up_connection_status_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { up_connection_status_any_of_NULL = 0,
	       up_connection_status_any_of_ESTABLISHED,
	       up_connection_status_any_of_RELEASED,
	       up_connection_status_any_of_MOVE } up_connection_status_any_of_e;

char *up_connection_status_any_of_ToString(
	up_connection_status_any_of_e up_connection_status_any_of);

up_connection_status_any_of_e up_connection_status_any_of_FromString(
	char *up_connection_status_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _up_connection_status_any_of_H_ */
