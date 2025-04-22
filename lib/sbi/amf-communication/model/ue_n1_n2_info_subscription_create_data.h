/*
 * ue_n1_n2_info_subscription_create_data.h
 *
 * Data within a create subscription request for UE specific N1 and/or N2 information notification
 */

#ifndef _ue_n1_n2_info_subscription_create_data_H_
#define _ue_n1_n2_info_subscription_create_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "guami.h"
#include "n1_message_class.h"
#include "n2_information_class.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_n1_n2_info_subscription_create_data_s
        ue_n1_n2_info_subscription_create_data_t;
typedef struct ue_n1_n2_info_subscription_create_data_s {
	n2_information_class_e n2_information_class;
	char *n2_notify_callback_uri;
	n1_message_class_e n1_message_class;
	char *n1_notify_callback_uri;
	char *nf_id;
	char *supported_features;
	struct guami_s *old_guami;
} ue_n1_n2_info_subscription_create_data_t;

ue_n1_n2_info_subscription_create_data_t *
ue_n1_n2_info_subscription_create_data_create(
	n2_information_class_e n2_information_class,
	char *n2_notify_callback_uri, n1_message_class_e n1_message_class,
	char *n1_notify_callback_uri, char *nf_id, char *supported_features,
	guami_t *old_guami);
void ue_n1_n2_info_subscription_create_data_free(
	ue_n1_n2_info_subscription_create_data_t *ue_n1_n2_info_subscription_create_data);
ue_n1_n2_info_subscription_create_data_t *
ue_n1_n2_info_subscription_create_data_parseFromJSON(
	cJSON *ue_n1_n2_info_subscription_create_dataJSON);
cJSON *ue_n1_n2_info_subscription_create_data_convertToJSON(
	ue_n1_n2_info_subscription_create_data_t *ue_n1_n2_info_subscription_create_data);
ue_n1_n2_info_subscription_create_data_t *
ue_n1_n2_info_subscription_create_data_copy(
	ue_n1_n2_info_subscription_create_data_t	*dst,
	ue_n1_n2_info_subscription_create_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_n1_n2_info_subscription_create_data_H_ */
