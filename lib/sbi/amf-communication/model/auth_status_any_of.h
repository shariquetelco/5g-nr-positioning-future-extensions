/*
 * auth_status_any_of.h
 *
 *
 */

#ifndef _auth_status_any_of_H_
#define _auth_status_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { auth_status_any_of_NULL = 0, auth_status_any_of_EAP_SUCCESS,
	       auth_status_any_of_EAP_FAILURE,
	       auth_status_any_of_PENDING } auth_status_any_of_e;

char *auth_status_any_of_ToString(auth_status_any_of_e auth_status_any_of);

auth_status_any_of_e auth_status_any_of_FromString(char *auth_status_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _auth_status_any_of_H_ */
