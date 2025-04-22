/*
 * amf_status_change_notification.h
 *
 * Data within an AMF Status Change Notification request
 */

#ifndef _amf_status_change_notification_H_
#define _amf_status_change_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "amf_status_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_status_change_notification_s amf_status_change_notification_t;
typedef struct amf_status_change_notification_s {
	list_t *amf_status_info_list;
} amf_status_change_notification_t;

amf_status_change_notification_t *amf_status_change_notification_create(
	list_t *amf_status_info_list);
void amf_status_change_notification_free(
	amf_status_change_notification_t *amf_status_change_notification);
amf_status_change_notification_t *amf_status_change_notification_parseFromJSON(
	cJSON *amf_status_change_notificationJSON);
cJSON *amf_status_change_notification_convertToJSON(
	amf_status_change_notification_t *amf_status_change_notification);
amf_status_change_notification_t *amf_status_change_notification_copy(
	amf_status_change_notification_t	*dst,
	amf_status_change_notification_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_status_change_notification_H_ */
