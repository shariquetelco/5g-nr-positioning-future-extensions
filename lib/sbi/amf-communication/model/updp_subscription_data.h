/*
 * updp_subscription_data.h
 *
 * UE policy delivery related N1 message notification subscription data.
 */

#ifndef _updp_subscription_data_H_
#define _updp_subscription_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct updp_subscription_data_s updp_subscription_data_t;
typedef struct updp_subscription_data_s {
	char *updp_notify_subscription_id;
	char *updp_notify_callback_uri;
	char *supported_features;
	char *updp_callback_binding;
} updp_subscription_data_t;

updp_subscription_data_t *updp_subscription_data_create(
	char *updp_notify_subscription_id, char *updp_notify_callback_uri,
	char *supported_features, char *updp_callback_binding);
void updp_subscription_data_free(
	updp_subscription_data_t *updp_subscription_data);
updp_subscription_data_t *updp_subscription_data_parseFromJSON(
	cJSON *updp_subscription_dataJSON);
cJSON *updp_subscription_data_convertToJSON(
	updp_subscription_data_t *updp_subscription_data);
updp_subscription_data_t *updp_subscription_data_copy(
	updp_subscription_data_t *dst, updp_subscription_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _updp_subscription_data_H_ */
