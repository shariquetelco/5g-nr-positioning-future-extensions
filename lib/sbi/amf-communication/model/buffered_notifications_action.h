/*
 * buffered_notifications_action.h
 *
 * Indicates the required action by the event producer NF on the buffered Notifications.
 */

#ifndef _buffered_notifications_action_H_
#define _buffered_notifications_action_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "buffered_notifications_action_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct buffered_notifications_action_s buffered_notifications_action_t;
typedef struct buffered_notifications_action_s {}
buffered_notifications_action_t;

buffered_notifications_action_t *buffered_notifications_action_create();
void buffered_notifications_action_free(
	buffered_notifications_action_t *buffered_notifications_action);
buffered_notifications_action_t *buffered_notifications_action_parseFromJSON(
	cJSON *buffered_notifications_actionJSON);
cJSON *buffered_notifications_action_convertToJSON(
	buffered_notifications_action_t *buffered_notifications_action);
buffered_notifications_action_t *buffered_notifications_action_copy(
	buffered_notifications_action_t *dst,
	buffered_notifications_action_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _buffered_notifications_action_H_ */
