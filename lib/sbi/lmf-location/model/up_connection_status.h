/*
 * up_connection_status.h
 *
 *
 */

#ifndef _up_connection_status_H_
#define _up_connection_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { up_connection_status_NULL = 0, up_connection_status_ESTABLISHED,
	       up_connection_status_RELEASED,
	       up_connection_status_MOVE } up_connection_status_e;

char *up_connection_status_ToString(
	up_connection_status_e up_connection_status);

up_connection_status_e up_connection_status_FromString(
	char *up_connection_status);

#ifdef __cplusplus
}
#endif

#endif /* _up_connection_status_H_ */
