/*
 * nwdaf_subscription.h
 *
 * Individual NWDAF subscription identified by the subscription Id.
 */

#ifndef _nwdaf_subscription_H_
#define _nwdaf_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nnwdaf_events_subscription.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nwdaf_subscription_s nwdaf_subscription_t;
typedef struct nwdaf_subscription_s {
	char *nwdaf_evt_subs_service_uri;
	struct nnwdaf_events_subscription_s *nwdaf_events_subscription;
} nwdaf_subscription_t;

nwdaf_subscription_t *nwdaf_subscription_create(
	char				*nwdaf_evt_subs_service_uri,
	nnwdaf_events_subscription_t	*nwdaf_events_subscription);
void nwdaf_subscription_free(nwdaf_subscription_t *nwdaf_subscription);
nwdaf_subscription_t *nwdaf_subscription_parseFromJSON(
	cJSON *nwdaf_subscriptionJSON);
cJSON *nwdaf_subscription_convertToJSON(
	nwdaf_subscription_t *nwdaf_subscription);
nwdaf_subscription_t *nwdaf_subscription_copy(nwdaf_subscription_t	*dst,
                                              nwdaf_subscription_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _nwdaf_subscription_H_ */
