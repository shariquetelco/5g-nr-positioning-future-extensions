/*
 * amf_event_trigger_any_of.h
 *
 *
 */

#ifndef _amf_event_trigger_any_of_H_
#define _amf_event_trigger_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { amf_event_trigger_any_of_NULL = 0,
	       amf_event_trigger_any_of_ONE_TIME,
	       amf_event_trigger_any_of_CONTINUOUS,
	       amf_event_trigger_any_of_PERIODIC } amf_event_trigger_any_of_e;

char *amf_event_trigger_any_of_ToString(
	amf_event_trigger_any_of_e amf_event_trigger_any_of);

amf_event_trigger_any_of_e amf_event_trigger_any_of_FromString(
	char *amf_event_trigger_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_trigger_any_of_H_ */
