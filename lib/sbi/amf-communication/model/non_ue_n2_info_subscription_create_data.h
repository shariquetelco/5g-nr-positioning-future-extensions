/*
 * non_ue_n2_info_subscription_create_data.h
 *
 * Data within a create subscription request for non-UE specific N2 information notification
 */

#ifndef _non_ue_n2_info_subscription_create_data_H_
#define _non_ue_n2_info_subscription_create_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "global_ran_node_id.h"
#include "n2_information_class.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct non_ue_n2_info_subscription_create_data_s
        non_ue_n2_info_subscription_create_data_t;
typedef struct non_ue_n2_info_subscription_create_data_s {
	list_t *global_ran_node_list;
	list_t *an_type_list;
	n2_information_class_e n2_information_class;
	char *n2_notify_callback_uri;
	char *nf_id;
	char *supported_features;
	char *notif_correlation_id;
} non_ue_n2_info_subscription_create_data_t;

non_ue_n2_info_subscription_create_data_t *
non_ue_n2_info_subscription_create_data_create(list_t *global_ran_node_list,
                                               list_t *an_type_list,
                                               n2_information_class_e n2_information_class, char *n2_notify_callback_uri, char *nf_id, char *supported_features, char *notif_correlation_id);
void non_ue_n2_info_subscription_create_data_free(
	non_ue_n2_info_subscription_create_data_t *non_ue_n2_info_subscription_create_data);
non_ue_n2_info_subscription_create_data_t *
non_ue_n2_info_subscription_create_data_parseFromJSON(
	cJSON *non_ue_n2_info_subscription_create_dataJSON);
cJSON *non_ue_n2_info_subscription_create_data_convertToJSON(
	non_ue_n2_info_subscription_create_data_t *non_ue_n2_info_subscription_create_data);
non_ue_n2_info_subscription_create_data_t *
non_ue_n2_info_subscription_create_data_copy(
	non_ue_n2_info_subscription_create_data_t	*dst,
	non_ue_n2_info_subscription_create_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _non_ue_n2_info_subscription_create_data_H_ */
