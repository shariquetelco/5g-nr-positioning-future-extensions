/*
 * event_notify_data_additional_info.h
 *
 * Additional information to Event Notify Data
 */

#ifndef _event_notify_data_additional_info_H_
#define _event_notify_data_additional_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "event_notify_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct event_notify_data_additional_info_s
        event_notify_data_additional_info_t;
typedef struct event_notify_data_additional_info_s {
	list_t *add_event_data_list;
} event_notify_data_additional_info_t;

event_notify_data_additional_info_t *event_notify_data_additional_info_create(
	list_t *add_event_data_list);
void event_notify_data_additional_info_free(
	event_notify_data_additional_info_t *event_notify_data_additional_info);
event_notify_data_additional_info_t *
event_notify_data_additional_info_parseFromJSON(
	cJSON *event_notify_data_additional_infoJSON);
cJSON *event_notify_data_additional_info_convertToJSON(
	event_notify_data_additional_info_t *event_notify_data_additional_info);
event_notify_data_additional_info_t *event_notify_data_additional_info_copy(
	event_notify_data_additional_info_t	*dst,
	event_notify_data_additional_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _event_notify_data_additional_info_H_ */
