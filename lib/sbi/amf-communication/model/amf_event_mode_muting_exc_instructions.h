/*
 * amf_event_mode_muting_exc_instructions.h
 *
 *
 */

#ifndef _amf_event_mode_muting_exc_instructions_H_
#define _amf_event_mode_muting_exc_instructions_H_

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

typedef struct amf_event_mode_muting_exc_instructions_s
        amf_event_mode_muting_exc_instructions_t;
typedef struct amf_event_mode_muting_exc_instructions_s {
	struct buffered_notifications_action_s *buffered_notifs;
	struct subscription_action_s *subscription;
} amf_event_mode_muting_exc_instructions_t;

amf_event_mode_muting_exc_instructions_t *
amf_event_mode_muting_exc_instructions_create(
	buffered_notifications_action_t *buffered_notifs,
	subscription_action_t		*subscription);
void amf_event_mode_muting_exc_instructions_free(
	amf_event_mode_muting_exc_instructions_t *amf_event_mode_muting_exc_instructions);
amf_event_mode_muting_exc_instructions_t *
amf_event_mode_muting_exc_instructions_parseFromJSON(
	cJSON *amf_event_mode_muting_exc_instructionsJSON);
cJSON *amf_event_mode_muting_exc_instructions_convertToJSON(
	amf_event_mode_muting_exc_instructions_t *amf_event_mode_muting_exc_instructions);
amf_event_mode_muting_exc_instructions_t *
amf_event_mode_muting_exc_instructions_copy(
	amf_event_mode_muting_exc_instructions_t	*dst,
	amf_event_mode_muting_exc_instructions_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_mode_muting_exc_instructions_H_ */
