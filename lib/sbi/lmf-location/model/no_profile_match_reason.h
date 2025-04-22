/*
 * no_profile_match_reason.h
 *
 * No Profile Match Reason
 */

#ifndef _no_profile_match_reason_H_
#define _no_profile_match_reason_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "no_profile_match_reason_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct no_profile_match_reason_s no_profile_match_reason_t;
typedef struct no_profile_match_reason_s {} no_profile_match_reason_t;

no_profile_match_reason_t *no_profile_match_reason_create();
void no_profile_match_reason_free(
	no_profile_match_reason_t *no_profile_match_reason);
no_profile_match_reason_t *no_profile_match_reason_parseFromJSON(
	cJSON *no_profile_match_reasonJSON);
cJSON *no_profile_match_reason_convertToJSON(
	no_profile_match_reason_t *no_profile_match_reason);
no_profile_match_reason_t *no_profile_match_reason_copy(
	no_profile_match_reason_t *dst, no_profile_match_reason_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _no_profile_match_reason_H_ */
