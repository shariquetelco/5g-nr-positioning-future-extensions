/*
 * event_report_message.h
 *
 * Indicates an event report message.
 */

#ifndef _event_report_message_H_
#define _event_report_message_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "event_class.h"
#include "ref_to_binary_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct event_report_message_s event_report_message_t;
typedef struct event_report_message_s {
	event_class_e event_class;
	struct ref_to_binary_data_s *event_content;
} event_report_message_t;

event_report_message_t *event_report_message_create(
	event_class_e		event_class,
	ref_to_binary_data_t	*event_content);
void event_report_message_free(event_report_message_t *event_report_message);
event_report_message_t *event_report_message_parseFromJSON(
	cJSON *event_report_messageJSON);
cJSON *event_report_message_convertToJSON(
	event_report_message_t *event_report_message);
event_report_message_t *event_report_message_copy(
	event_report_message_t	*dst,
	event_report_message_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _event_report_message_H_ */
