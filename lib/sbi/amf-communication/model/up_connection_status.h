/*
 * up_connection_status.h
 *
 * UP Connection Status.
 */

#ifndef _up_connection_status_H_
#define _up_connection_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "up_connection_status_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct up_connection_status_s up_connection_status_t;
typedef struct up_connection_status_s {} up_connection_status_t;

up_connection_status_t *up_connection_status_create();
void up_connection_status_free(up_connection_status_t *up_connection_status);
up_connection_status_t *up_connection_status_parseFromJSON(
	cJSON *up_connection_statusJSON);
cJSON *up_connection_status_convertToJSON(
	up_connection_status_t *up_connection_status);
up_connection_status_t *up_connection_status_copy(
	up_connection_status_t	*dst,
	up_connection_status_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _up_connection_status_H_ */
