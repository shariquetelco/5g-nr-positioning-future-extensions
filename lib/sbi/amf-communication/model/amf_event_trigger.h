/*
 * amf_event_trigger.h
 *
 * Describes how AMF should generate the report for the event
 */

#ifndef _amf_event_trigger_H_
#define _amf_event_trigger_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "amf_event_trigger_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_event_trigger_s amf_event_trigger_t;
typedef struct amf_event_trigger_s {} amf_event_trigger_t;

amf_event_trigger_t *amf_event_trigger_create();
void amf_event_trigger_free(amf_event_trigger_t *amf_event_trigger);
amf_event_trigger_t *amf_event_trigger_parseFromJSON(
	cJSON *amf_event_triggerJSON);
cJSON *amf_event_trigger_convertToJSON(amf_event_trigger_t *amf_event_trigger);
amf_event_trigger_t *amf_event_trigger_copy(amf_event_trigger_t *dst,
                                            amf_event_trigger_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_trigger_H_ */
