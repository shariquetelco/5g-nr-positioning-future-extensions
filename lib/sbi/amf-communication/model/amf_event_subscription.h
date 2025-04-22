/*
 * amf_event_subscription.h
 *
 * Represents an individual event subscription resource on AMF
 */

#ifndef _amf_event_subscription_H_
#define _amf_event_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "amf_event.h"
#include "amf_event_mode.h"
#include "nf_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_event_subscription_s amf_event_subscription_t;
typedef struct amf_event_subscription_s {
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
} amf_event_subscription_t;

amf_event_subscription_t *amf_event_subscription_create(list_t *event_list,
                                                        char *event_notify_uri,
                                                        char *notify_correlation_id, char *nf_id, char *subs_change_notify_uri, char *subs_change_notify_correlation_id, char *supi, char *group_id, list_t *exclude_supi_list, list_t *exclude_gpsi_list, list_t *include_supi_list, list_t *include_gpsi_list, char *gpsi, char *pei, bool is_any_ue, int any_ue, amf_event_mode_t *options, nf_type_t *source_nf_type, bool is_term_notify_ind, int term_notify_ind);
void amf_event_subscription_free(
	amf_event_subscription_t *amf_event_subscription);
amf_event_subscription_t *amf_event_subscription_parseFromJSON(
	cJSON *amf_event_subscriptionJSON);
cJSON *amf_event_subscription_convertToJSON(
	amf_event_subscription_t *amf_event_subscription);
amf_event_subscription_t *amf_event_subscription_copy(
	amf_event_subscription_t *dst, amf_event_subscription_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_subscription_H_ */
