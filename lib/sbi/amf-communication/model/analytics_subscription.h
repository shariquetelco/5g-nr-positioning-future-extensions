/*
 * analytics_subscription.h
 *
 * Analytics subscriptions created in the NWDAF.
 */

#ifndef _analytics_subscription_H_
#define _analytics_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nwdaf_subscription.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct analytics_subscription_s analytics_subscription_t;
typedef struct analytics_subscription_s {
	char *nwdaf_id;
	char *nwdaf_set_id;
	list_t *nwdaf_subscription_list;
} analytics_subscription_t;

analytics_subscription_t *analytics_subscription_create(char	*nwdaf_id,
                                                        char	*nwdaf_set_id,
                                                        list_t	*nwdaf_subscription_list);
void analytics_subscription_free(
	analytics_subscription_t *analytics_subscription);
analytics_subscription_t *analytics_subscription_parseFromJSON(
	cJSON *analytics_subscriptionJSON);
cJSON *analytics_subscription_convertToJSON(
	analytics_subscription_t *analytics_subscription);
analytics_subscription_t *analytics_subscription_copy(
	analytics_subscription_t *dst, analytics_subscription_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_subscription_H_ */
