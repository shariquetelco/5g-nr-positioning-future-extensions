/*
 * up_subscription.h
 *
 * UP Subscription
 */

#ifndef _up_subscription_H_
#define _up_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct up_subscription_s up_subscription_t;
typedef struct up_subscription_s {
	char *up_notify_call_back_uri;
	char *notif_correlation_id;
	char *supi;
	char *gpsi;
} up_subscription_t;

up_subscription_t *up_subscription_create(char *up_notify_call_back_uri,
                                          char *notif_correlation_id,
                                          char *supi, char *gpsi);
void up_subscription_free(up_subscription_t *up_subscription);
up_subscription_t *up_subscription_parseFromJSON(cJSON *up_subscriptionJSON);
cJSON *up_subscription_convertToJSON(up_subscription_t *up_subscription);
up_subscription_t *up_subscription_copy(up_subscription_t	*dst,
                                        up_subscription_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _up_subscription_H_ */
