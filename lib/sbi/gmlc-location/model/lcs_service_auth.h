/*
 * lcs_service_auth.h
 *
 * Possible values are: - \&quot;LOCATION_ALLOWED_WITH_NOTIFICATION\&quot;: Location allowed with notification - \&quot;LOCATION_ALLOWED_WITHOUT_NOTIFICATION\&quot;: Location allowed without notification - \&quot;LOCATION_ALLOWED_WITHOUT_RESPONSE\&quot;: Location with notification and privacy    verification; location allowed if no response - \&quot;LOCATION_RESTRICTED_WITHOUT_RESPONSE\&quot;: Location with notification and privacy   verification; location restricted if no response - \&quot;NOTIFICATION_ONLY\&quot;: Notification only - \&quot;NOTIFICATION_AND_VERIFICATION_ONLY\&quot;: Notification and privacy verification only
 */

#ifndef _lcs_service_auth_H_
#define _lcs_service_auth_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "lcs_service_auth_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct lcs_service_auth_s lcs_service_auth_t;
typedef struct lcs_service_auth_s {} lcs_service_auth_t;

lcs_service_auth_t *lcs_service_auth_create();
void lcs_service_auth_free(lcs_service_auth_t *lcs_service_auth);
lcs_service_auth_t *lcs_service_auth_parseFromJSON(cJSON *lcs_service_authJSON);
cJSON *lcs_service_auth_convertToJSON(lcs_service_auth_t *lcs_service_auth);
lcs_service_auth_t *lcs_service_auth_copy(lcs_service_auth_t	*dst,
                                          lcs_service_auth_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _lcs_service_auth_H_ */
