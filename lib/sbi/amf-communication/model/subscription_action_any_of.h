/*
 * subscription_action_any_of.h
 *
 *
 */

#ifndef _subscription_action_any_of_H_
#define _subscription_action_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { subscription_action_any_of_NULL = 0,
	       subscription_action_any_of_CLOSE,
	       subscription_action_any_of_CONTINUE_WITH_MUTING,
	       subscription_action_any_of_CONTINUE_WITHOUT_MUTING }
subscription_action_any_of_e;

char *subscription_action_any_of_ToString(
	subscription_action_any_of_e subscription_action_any_of);

subscription_action_any_of_e subscription_action_any_of_FromString(
	char *subscription_action_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _subscription_action_any_of_H_ */
