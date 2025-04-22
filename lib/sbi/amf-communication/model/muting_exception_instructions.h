/*
 * muting_exception_instructions.h
 *
 * Indicates to an Event producer NF instructions for the subscription and stored events when an exception (e.g. full buffer) occurs at the Event producer NF while the event is muted.
 */

#ifndef _muting_exception_instructions_H_
#define _muting_exception_instructions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "buffered_notifications_action.h"
#include "subscription_action.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct muting_exception_instructions_s muting_exception_instructions_t;
typedef struct muting_exception_instructions_s {
	struct buffered_notifications_action_s *buffered_notifs;
	struct subscription_action_s *subscription;
} muting_exception_instructions_t;

muting_exception_instructions_t *muting_exception_instructions_create(
	buffered_notifications_action_t *buffered_notifs,
	subscription_action_t		*subscription);
void muting_exception_instructions_free(
	muting_exception_instructions_t *muting_exception_instructions);
muting_exception_instructions_t *muting_exception_instructions_parseFromJSON(
	cJSON *muting_exception_instructionsJSON);
cJSON *muting_exception_instructions_convertToJSON(
	muting_exception_instructions_t *muting_exception_instructions);
muting_exception_instructions_t *muting_exception_instructions_copy(
	muting_exception_instructions_t *dst,
	muting_exception_instructions_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _muting_exception_instructions_H_ */
