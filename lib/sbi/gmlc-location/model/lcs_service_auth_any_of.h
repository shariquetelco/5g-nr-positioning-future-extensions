/*
 * lcs_service_auth_any_of.h
 *
 *
 */

#ifndef _lcs_service_auth_any_of_H_
#define _lcs_service_auth_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { lcs_service_auth_any_of_NULL = 0,
	       lcs_service_auth_any_of_LOCATION_ALLOWED_WITH_NOTIFICATION,
	       lcs_service_auth_any_of_LOCATION_ALLOWED_WITHOUT_NOTIFICATION,
	       lcs_service_auth_any_of_LOCATION_ALLOWED_WITHOUT_RESPONSE,
	       lcs_service_auth_any_of_LOCATION_RESTRICTED_WITHOUT_RESPONSE,
	       lcs_service_auth_any_of_NOTIFICATION_ONLY,
	       lcs_service_auth_any_of_NOTIFICATION_AND_VERIFICATION_ONLY }
lcs_service_auth_any_of_e;

char *lcs_service_auth_any_of_ToString(
	lcs_service_auth_any_of_e lcs_service_auth_any_of);

lcs_service_auth_any_of_e lcs_service_auth_any_of_FromString(
	char *lcs_service_auth_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _lcs_service_auth_any_of_H_ */
