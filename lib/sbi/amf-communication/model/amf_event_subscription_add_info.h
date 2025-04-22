/*
 * amf_event_subscription_add_info.h
 *
 * Additional information received for an AMF event subscription, e.g. binding indications
 */

#ifndef _amf_event_subscription_add_info_H_
#define _amf_event_subscription_add_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "area_of_interest_event_state.h"
#include "nf_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_event_subscription_add_info_s
        amf_event_subscription_add_info_t;
typedef struct amf_event_subscription_add_info_s {
	list_t *binding_info;
	struct nf_type_s *subscribing_nf_type;
	bool is_event_sync_ind;
	int event_sync_ind;
	list_t *nf_consumer_info;
	list_t *aoi_state_list;
	char *access_token;
} amf_event_subscription_add_info_t;

amf_event_subscription_add_info_t *amf_event_subscription_add_info_create(
	list_t *binding_info, nf_type_t *subscribing_nf_type,
	bool is_event_sync_ind, int event_sync_ind, list_t *nf_consumer_info,
	list_t *aoi_state_list, char *access_token);
void amf_event_subscription_add_info_free(
	amf_event_subscription_add_info_t *amf_event_subscription_add_info);
amf_event_subscription_add_info_t *amf_event_subscription_add_info_parseFromJSON(
	cJSON *amf_event_subscription_add_infoJSON);
cJSON *amf_event_subscription_add_info_convertToJSON(
	amf_event_subscription_add_info_t *amf_event_subscription_add_info);
amf_event_subscription_add_info_t *amf_event_subscription_add_info_copy(
	amf_event_subscription_add_info_t	*dst,
	amf_event_subscription_add_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_subscription_add_info_H_ */
