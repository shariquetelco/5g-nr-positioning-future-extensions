/*
 * subscription_action.h
 *
 * Indicates the required action by the event producer NF on the event subscription if an exception occurs while the event is muted.
 */

#ifndef _subscription_action_H_
#define _subscription_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "subscription_action_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct subscription_action_s subscription_action_t;
typedef struct subscription_action_s {} subscription_action_t;

subscription_action_t *subscription_action_create();
void subscription_action_free(subscription_action_t *subscription_action);
subscription_action_t *subscription_action_parseFromJSON(
	cJSON *subscription_actionJSON);
cJSON *subscription_action_convertToJSON(
	subscription_action_t *subscription_action);
subscription_action_t *subscription_action_copy(subscription_action_t	*dst,
                                                subscription_action_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _subscription_action_H_ */
