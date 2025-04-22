/*
 * buffered_notifications_action_any_of.h
 *
 *
 */

#ifndef _buffered_notifications_action_any_of_H_
#define _buffered_notifications_action_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { buffered_notifications_action_any_of_NULL = 0,
	       buffered_notifications_action_any_of_SEND_ALL,
	       buffered_notifications_action_any_of_DISCARD_ALL,
	       buffered_notifications_action_any_of_DROP_OLD }
buffered_notifications_action_any_of_e;

char *buffered_notifications_action_any_of_ToString(
	buffered_notifications_action_any_of_e buffered_notifications_action_any_of);

buffered_notifications_action_any_of_e
buffered_notifications_action_any_of_FromString(
	char *buffered_notifications_action_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _buffered_notifications_action_any_of_H_ */
