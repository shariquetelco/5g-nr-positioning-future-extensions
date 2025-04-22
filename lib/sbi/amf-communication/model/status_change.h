/*
 * status_change.h
 *
 *
 */

#ifndef _status_change_H_
#define _status_change_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { status_change_NULL = 0, status_change_AMF_UNAVAILABLE,
	       status_change_AMF_AVAILABLE } status_change_e;

char *status_change_ToString(status_change_e status_change);

status_change_e status_change_FromString(char *status_change);

#ifdef __cplusplus
}
#endif

#endif /* _status_change_H_ */
