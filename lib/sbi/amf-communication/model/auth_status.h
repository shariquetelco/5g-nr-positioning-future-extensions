/*
 * auth_status.h
 *
 * Possible values are: - \&quot;EAP_SUCCESS\&quot;: The NSSAA status is EAP-Success. - \&quot;EAP_FAILURE\&quot;: The NSSAA status is EAP-Failure. - \&quot;PENDING\&quot;: The NSSAA status is Pending.
 */

#ifndef _auth_status_H_
#define _auth_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "auth_status_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct auth_status_s auth_status_t;
typedef struct auth_status_s {} auth_status_t;

auth_status_t *auth_status_create();
void auth_status_free(auth_status_t *auth_status);
auth_status_t *auth_status_parseFromJSON(cJSON *auth_statusJSON);
cJSON *auth_status_convertToJSON(auth_status_t *auth_status);
auth_status_t *auth_status_copy(auth_status_t *dst, auth_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _auth_status_H_ */
