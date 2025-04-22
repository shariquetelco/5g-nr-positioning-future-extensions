/*
 * external_client_type.h
 *
 *
 */

#ifndef _external_client_type_H_
#define _external_client_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { external_client_type_NULL = 0,
	       external_client_type_EMERGENCY_SERVICES,
	       external_client_type_VALUE_ADDED_SERVICES,
	       external_client_type_PLMN_OPERATOR_SERVICES,
	       external_client_type_LAWFUL_INTERCEPT_SERVICES,
	       external_client_type_PLMN_OPERATOR_BROADCAST_SERVICES,
	       external_client_type_PLMN_OPERATOR_OM,
	       external_client_type_PLMN_OPERATOR_ANONYMOUS_STATISTICS,
	       external_client_type_PLMN_OPERATOR_TARGET_MS_SERVICE_SUPPORT,
	       external_client_type_SL_POS } external_client_type_e;

char *external_client_type_ToString(
	external_client_type_e external_client_type);

external_client_type_e external_client_type_FromString(
	char *external_client_type);

#ifdef __cplusplus
}
#endif

#endif /* _external_client_type_H_ */
