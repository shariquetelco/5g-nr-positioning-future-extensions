#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_subscription.h"

nwdaf_subscription_t *nwdaf_subscription_create(
	char				*nwdaf_evt_subs_service_uri,
	nnwdaf_events_subscription_t	*nwdaf_events_subscription) {
	nwdaf_subscription_t *nwdaf_subscription_local_var =
		malloc(sizeof(nwdaf_subscription_t));

	nwdaf_subscription_local_var->nwdaf_evt_subs_service_uri =
		nwdaf_evt_subs_service_uri;
	nwdaf_subscription_local_var->nwdaf_events_subscription =
		nwdaf_events_subscription;

	return nwdaf_subscription_local_var;
}

void nwdaf_subscription_free(nwdaf_subscription_t *nwdaf_subscription) {
	lnode_t *node = NULL;

	if(NULL == nwdaf_subscription) {
		return;
	}
	if(nwdaf_subscription->nwdaf_evt_subs_service_uri) {
		free(nwdaf_subscription->nwdaf_evt_subs_service_uri);
		nwdaf_subscription->nwdaf_evt_subs_service_uri = NULL;
	}
	if(nwdaf_subscription->nwdaf_events_subscription) {
		nnwdaf_events_subscription_free(
			nwdaf_subscription->nwdaf_events_subscription);
		nwdaf_subscription->nwdaf_events_subscription = NULL;
	}
	free(nwdaf_subscription);
}

cJSON *nwdaf_subscription_convertToJSON(
	nwdaf_subscription_t *nwdaf_subscription) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nwdaf_subscription == NULL) {
		printf(
			"nwdaf_subscription_convertToJSON() failed [NwdafSubscription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nwdaf_subscription->nwdaf_evt_subs_service_uri) {
		printf(
			"nwdaf_subscription_convertToJSON() failed [nwdaf_evt_subs_service_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "nwdafEvtSubsServiceUri",
	                           nwdaf_subscription->
	                           nwdaf_evt_subs_service_uri) == NULL)
	{
		printf(
			"nwdaf_subscription_convertToJSON() failed [nwdaf_evt_subs_service_uri]");
		goto end;
	}

	if(!nwdaf_subscription->nwdaf_events_subscription) {
		printf(
			"nwdaf_subscription_convertToJSON() failed [nwdaf_events_subscription]");
		return NULL;
	}
	cJSON *nwdaf_events_subscription_local_JSON =
		nnwdaf_events_subscription_convertToJSON(
			nwdaf_subscription->nwdaf_events_subscription);
	if(nwdaf_events_subscription_local_JSON == NULL) {
		printf(
			"nwdaf_subscription_convertToJSON() failed [nwdaf_events_subscription]");
		goto end;
	}
	cJSON_AddItemToObject(item, "nwdafEventsSubscription",
	                      nwdaf_events_subscription_local_JSON);
	if(item->child == NULL) {
		printf(
			"nwdaf_subscription_convertToJSON() failed [nwdaf_events_subscription]");
		goto end;
	}

end:
	return item;
}

nwdaf_subscription_t *nwdaf_subscription_parseFromJSON(
	cJSON *nwdaf_subscriptionJSON) {
	nwdaf_subscription_t *nwdaf_subscription_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nwdaf_evt_subs_service_uri = NULL;
	cJSON *nwdaf_events_subscription = NULL;
	nnwdaf_events_subscription_t *nwdaf_events_subscription_local_nonprim =
		NULL;
	nwdaf_evt_subs_service_uri = cJSON_GetObjectItemCaseSensitive(
		nwdaf_subscriptionJSON, "nwdafEvtSubsServiceUri");
	if(!nwdaf_evt_subs_service_uri) {
		printf(
			"nwdaf_subscription_parseFromJSON() failed [nwdaf_evt_subs_service_uri]");
		goto end;
	}
	if(!cJSON_IsString(nwdaf_evt_subs_service_uri)) {
		printf(
			"nwdaf_subscription_parseFromJSON() failed [nwdaf_evt_subs_service_uri]");
		goto end;
	}

	nwdaf_events_subscription = cJSON_GetObjectItemCaseSensitive(
		nwdaf_subscriptionJSON, "nwdafEventsSubscription");
	if(!nwdaf_events_subscription) {
		printf(
			"nwdaf_subscription_parseFromJSON() failed [nwdaf_events_subscription]");
		goto end;
	}
	nwdaf_events_subscription_local_nonprim =
		nnwdaf_events_subscription_parseFromJSON(
			nwdaf_events_subscription);
	if(!nwdaf_events_subscription_local_nonprim) {
		printf(
			"nnwdaf_events_subscription_parseFromJSON failed [nwdaf_events_subscription]");
		goto end;
	}

	nwdaf_subscription_local_var = nwdaf_subscription_create(
		strdup(nwdaf_evt_subs_service_uri->valuestring),
		nwdaf_events_subscription_local_nonprim
		);

	return nwdaf_subscription_local_var;
end:
	if(nwdaf_events_subscription_local_nonprim) {
		nnwdaf_events_subscription_free(
			nwdaf_events_subscription_local_nonprim);
		nwdaf_events_subscription_local_nonprim = NULL;
	}
	return NULL;
}

nwdaf_subscription_t *nwdaf_subscription_copy(nwdaf_subscription_t	*dst,
                                              nwdaf_subscription_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nwdaf_subscription_convertToJSON(src);
	if(!item) {
		printf("nwdaf_subscription_convertToJSON() failed");
		return NULL;
	}

	content = cJSON_Print(item);
	cJSON_Delete(item);

	if(!content) {
		printf("cJSON_Print() failed");
		return NULL;
	}

	item = cJSON_Parse(content);
	free(content);
	if(!item) {
		printf("cJSON_Parse() failed");
		return NULL;
	}

	nwdaf_subscription_free(dst);
	dst = nwdaf_subscription_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
