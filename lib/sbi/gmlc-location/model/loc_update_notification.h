/*
 * loc_update_notification.h
 *
 * Location Update Notification
 */

#ifndef _loc_update_notification_H_
#define _loc_update_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy_fulfilment_indicator.h"
#include "civic_address.h"
#include "geographic_area.h"
#include "lcs_qos_class.h"
#include "location_request_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_update_notification_s loc_update_notification_t;
typedef struct loc_update_notification_s {
	char *gpsi;
	char *supi;
	location_request_type_e location_request_type;
	struct geographic_area_s *location_estimate;
	int age_of_location_estimate;
	char *timestamp_of_location_estimate;
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator;
	struct civic_address_s *civic_address;
	lcs_qos_class_e lcs_qos_class;
	char *af_id;
	char *service_identity;
} loc_update_notification_t;

loc_update_notification_t *loc_update_notification_create(char *gpsi,
                                                          char *supi,
                                                          location_request_type_e location_request_type, geographic_area_t *location_estimate, int age_of_location_estimate, char *timestamp_of_location_estimate, accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator, civic_address_t *civic_address, lcs_qos_class_e lcs_qos_class, char *af_id, char *service_identity);
void loc_update_notification_free(
	loc_update_notification_t *loc_update_notification);
loc_update_notification_t *loc_update_notification_parseFromJSON(
	cJSON *loc_update_notificationJSON);
cJSON *loc_update_notification_convertToJSON(
	loc_update_notification_t *loc_update_notification);
loc_update_notification_t *loc_update_notification_copy(
	loc_update_notification_t *dst, loc_update_notification_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_update_notification_H_ */
