/*
 * non_ue_n2_info_subscription_created_data.h
 *
 * Data for the created subscription for non-UE specific N2 information notification
 */

#ifndef _non_ue_n2_info_subscription_created_data_H_
#define _non_ue_n2_info_subscription_created_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_information_class.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct non_ue_n2_info_subscription_created_data_s
        non_ue_n2_info_subscription_created_data_t;
typedef struct non_ue_n2_info_subscription_created_data_s {
	char *n2_notify_subscription_id;
	char *supported_features;
	n2_information_class_e n2_information_class;
} non_ue_n2_info_subscription_created_data_t;

non_ue_n2_info_subscription_created_data_t *
non_ue_n2_info_subscription_created_data_create(
	char			*n2_notify_subscription_id,
	char			*supported_features,
	n2_information_class_e	n2_information_class);
void non_ue_n2_info_subscription_created_data_free(
	non_ue_n2_info_subscription_created_data_t *non_ue_n2_info_subscription_created_data);
non_ue_n2_info_subscription_created_data_t *
non_ue_n2_info_subscription_created_data_parseFromJSON(
	cJSON *non_ue_n2_info_subscription_created_dataJSON);
cJSON *non_ue_n2_info_subscription_created_data_convertToJSON(
	non_ue_n2_info_subscription_created_data_t *non_ue_n2_info_subscription_created_data);
non_ue_n2_info_subscription_created_data_t *
non_ue_n2_info_subscription_created_data_copy(
	non_ue_n2_info_subscription_created_data_t	*dst,
	non_ue_n2_info_subscription_created_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _non_ue_n2_info_subscription_created_data_H_ */
