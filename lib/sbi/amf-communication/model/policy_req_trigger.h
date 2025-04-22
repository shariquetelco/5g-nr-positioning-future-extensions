/*
 * policy_req_trigger.h
 *
 *
 */

#ifndef _policy_req_trigger_H_
#define _policy_req_trigger_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { policy_req_trigger_NULL = 0, policy_req_trigger_LOCATION_CHANGE,
	       policy_req_trigger_PRA_CHANGE,
	       policy_req_trigger_ALLOWED_NSSAI_CHANGE,
	       policy_req_trigger_NWDAF_DATA_CHANGE,
	       policy_req_trigger_PLMN_CHANGE,
	       policy_req_trigger_CON_STATE_CHANGE,
	       policy_req_trigger_SMF_SELECT_CHANGE,
	       policy_req_trigger_ACCESS_TYPE_CHANGE,
	       policy_req_trigger_SAT_BACKHAUL_CHANGE } policy_req_trigger_e;

char *policy_req_trigger_ToString(policy_req_trigger_e policy_req_trigger);

policy_req_trigger_e policy_req_trigger_FromString(char *policy_req_trigger);

#ifdef __cplusplus
}
#endif

#endif /* _policy_req_trigger_H_ */
