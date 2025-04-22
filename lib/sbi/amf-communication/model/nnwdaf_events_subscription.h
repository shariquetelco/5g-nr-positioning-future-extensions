/*
 * nnwdaf_events_subscription.h
 *
 * Represents an Individual NWDAF Event Subscription resource.
 */

#ifndef _nnwdaf_events_subscription_H_
#define _nnwdaf_events_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "consumer_nf_information.h"
#include "event_notification.h"
#include "event_subscription.h"
#include "failure_event_info.h"
#include "prev_sub_info.h"
#include "reporting_information.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nnwdaf_events_subscription_s nnwdaf_events_subscription_t;
typedef struct nnwdaf_events_subscription_s {
	list_t *event_subscriptions;
	struct reporting_information_s *evt_req;
	char *notification_uri;
	char *notif_corr_id;
	char *supported_features;
	list_t *event_notifications;
	list_t *fail_event_reports;
	struct prev_sub_info_s *prev_sub;
	struct consumer_nf_information_s *cons_nf_info;
} nnwdaf_events_subscription_t;

nnwdaf_events_subscription_t *nnwdaf_events_subscription_create(
	list_t *event_subscriptions, reporting_information_t *evt_req,
	char *notification_uri, char *notif_corr_id, char *supported_features,
	list_t *event_notifications, list_t *fail_event_reports,
	prev_sub_info_t *prev_sub, consumer_nf_information_t *cons_nf_info);
void nnwdaf_events_subscription_free(
	nnwdaf_events_subscription_t *nnwdaf_events_subscription);
nnwdaf_events_subscription_t *nnwdaf_events_subscription_parseFromJSON(
	cJSON *nnwdaf_events_subscriptionJSON);
cJSON *nnwdaf_events_subscription_convertToJSON(
	nnwdaf_events_subscription_t *nnwdaf_events_subscription);
nnwdaf_events_subscription_t *nnwdaf_events_subscription_copy(
	nnwdaf_events_subscription_t *dst, nnwdaf_events_subscription_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nnwdaf_events_subscription_H_ */
