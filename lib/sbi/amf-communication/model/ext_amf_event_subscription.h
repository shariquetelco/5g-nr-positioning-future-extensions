/*
 * ext_amf_event_subscription.h
 *
 * AMF event subscription extended with additional information received for the subscription
 */

#ifndef _ext_amf_event_subscription_H_
#define _ext_amf_event_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "amf_event.h"
#include "amf_event_mode.h"
#include "area_of_interest_event_state.h"
#include "nf_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ext_amf_event_subscription_s ext_amf_event_subscription_t;
typedef struct ext_amf_event_subscription_s {
	list_t *event_list;
	char *event_notify_uri;
	char *notify_correlation_id;
	char *nf_id;
	char *subs_change_notify_uri;
	char *subs_change_notify_correlation_id;
	char *supi;
	char *group_id;
	list_t *exclude_supi_list;
	list_t *exclude_gpsi_list;
	list_t *include_supi_list;
	list_t *include_gpsi_list;
	char *gpsi;
	char *pei;
	bool is_any_ue;
	int any_ue;
	struct amf_event_mode_s *options;
	struct nf_type_s *source_nf_type;
	bool is_term_notify_ind;
	int term_notify_ind;
	list_t *binding_info;
	struct nf_type_s *subscribing_nf_type;
	bool is_event_sync_ind;
	int event_sync_ind;
	list_t *nf_consumer_info;
	list_t *aoi_state_list;
	char *access_token;
} ext_amf_event_subscription_t;

ext_amf_event_subscription_t *ext_amf_event_subscription_create(
	list_t *event_list, char *event_notify_uri, char *notify_correlation_id,
	char *nf_id, char *subs_change_notify_uri,
	char *subs_change_notify_correlation_id, char *supi, char *group_id,
	list_t *exclude_supi_list, list_t *exclude_gpsi_list,
	list_t *include_supi_list, list_t *include_gpsi_list, char *gpsi,
	char *pei, bool is_any_ue, int any_ue, amf_event_mode_t *options,
	nf_type_t *source_nf_type, bool is_term_notify_ind, int term_notify_ind,
	list_t *binding_info, nf_type_t *subscribing_nf_type,
	bool is_event_sync_ind, int event_sync_ind, list_t *nf_consumer_info,
	list_t *aoi_state_list, char *access_token);
void ext_amf_event_subscription_free(
	ext_amf_event_subscription_t *ext_amf_event_subscription);
ext_amf_event_subscription_t *ext_amf_event_subscription_parseFromJSON(
	cJSON *ext_amf_event_subscriptionJSON);
cJSON *ext_amf_event_subscription_convertToJSON(
	ext_amf_event_subscription_t *ext_amf_event_subscription);
ext_amf_event_subscription_t *ext_amf_event_subscription_copy(
	ext_amf_event_subscription_t *dst, ext_amf_event_subscription_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ext_amf_event_subscription_H_ */
