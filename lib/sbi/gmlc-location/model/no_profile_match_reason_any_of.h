/*
 * no_profile_match_reason_any_of.h
 *
 *
 */

#ifndef _no_profile_match_reason_any_of_H_
#define _no_profile_match_reason_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { no_profile_match_reason_any_of_NULL = 0,
	       no_profile_match_reason_any_of_REQUESTER_PLMN_NOT_ALLOWED,
	       no_profile_match_reason_any_of_TARGET_NF_SUSPENDED,
	       no_profile_match_reason_any_of_TARGET_NF_UNDISCOVERABLE,
	       no_profile_match_reason_any_of_QUERY_PARAMS_COMBINATION_NO_MATCH,
	       no_profile_match_reason_any_of_TARGET_NF_TYPE_NOT_SUPPORTED,
	       no_profile_match_reason_any_of_UNSPECIFIED }
no_profile_match_reason_any_of_e;

char *no_profile_match_reason_any_of_ToString(
	no_profile_match_reason_any_of_e no_profile_match_reason_any_of);

no_profile_match_reason_any_of_e no_profile_match_reason_any_of_FromString(
	char *no_profile_match_reason_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _no_profile_match_reason_any_of_H_ */
