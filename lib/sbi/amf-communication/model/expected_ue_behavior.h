/*
 * expected_ue_behavior.h
 *
 * Represents the expected UE behavior (e.g. UE moving trajectory) and its validity period
 */

#ifndef _expected_ue_behavior_H_
#define _expected_ue_behavior_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "user_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct expected_ue_behavior_s expected_ue_behavior_t;
typedef struct expected_ue_behavior_s {
	list_t *exp_move_trajectory;
	char *validity_time;
} expected_ue_behavior_t;

expected_ue_behavior_t *expected_ue_behavior_create(
	list_t	*exp_move_trajectory,
	char	*validity_time);
void expected_ue_behavior_free(expected_ue_behavior_t *expected_ue_behavior);
expected_ue_behavior_t *expected_ue_behavior_parseFromJSON(
	cJSON *expected_ue_behaviorJSON);
cJSON *expected_ue_behavior_convertToJSON(
	expected_ue_behavior_t *expected_ue_behavior);
expected_ue_behavior_t *expected_ue_behavior_copy(
	expected_ue_behavior_t	*dst,
	expected_ue_behavior_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _expected_ue_behavior_H_ */
