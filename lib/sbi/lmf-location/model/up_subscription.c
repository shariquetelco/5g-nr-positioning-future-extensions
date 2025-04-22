#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_subscription.h"

up_subscription_t *up_subscription_create(char *up_notify_call_back_uri,
                                          char *notif_correlation_id,
                                          char *supi, char *gpsi) {
	up_subscription_t *up_subscription_local_var =
		malloc(sizeof(up_subscription_t));

	up_subscription_local_var->up_notify_call_back_uri =
		up_notify_call_back_uri;
	up_subscription_local_var->notif_correlation_id = notif_correlation_id;
	up_subscription_local_var->supi = supi;
	up_subscription_local_var->gpsi = gpsi;

	return up_subscription_local_var;
}

void up_subscription_free(up_subscription_t *up_subscription) {
	lnode_t *node = NULL;

	if(NULL == up_subscription) {
		return;
	}
	if(up_subscription->up_notify_call_back_uri) {
		free(up_subscription->up_notify_call_back_uri);
		up_subscription->up_notify_call_back_uri = NULL;
	}
	if(up_subscription->notif_correlation_id) {
		free(up_subscription->notif_correlation_id);
		up_subscription->notif_correlation_id = NULL;
	}
	if(up_subscription->supi) {
		free(up_subscription->supi);
		up_subscription->supi = NULL;
	}
	if(up_subscription->gpsi) {
		free(up_subscription->gpsi);
		up_subscription->gpsi = NULL;
	}
	free(up_subscription);
}

cJSON *up_subscription_convertToJSON(up_subscription_t *up_subscription) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(up_subscription == NULL) {
		printf("up_subscription_convertToJSON() failed [UpSubscription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!up_subscription->up_notify_call_back_uri) {
		printf(
			"up_subscription_convertToJSON() failed [up_notify_call_back_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "upNotifyCallBackUri",
	                           up_subscription->up_notify_call_back_uri) ==
	   NULL)
	{
		printf(
			"up_subscription_convertToJSON() failed [up_notify_call_back_uri]");
		goto end;
	}

	if(!up_subscription->notif_correlation_id) {
		printf(
			"up_subscription_convertToJSON() failed [notif_correlation_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "notifCorrelationId",
	                           up_subscription->notif_correlation_id) ==
	   NULL)
	{
		printf(
			"up_subscription_convertToJSON() failed [notif_correlation_id]");
		goto end;
	}

	if(!up_subscription->supi) {
		printf("up_subscription_convertToJSON() failed [supi]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "supi",
	                           up_subscription->supi) == NULL)
	{
		printf("up_subscription_convertToJSON() failed [supi]");
		goto end;
	}

	if(up_subscription->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           up_subscription->gpsi) == NULL)
		{
			printf("up_subscription_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

end:
	return item;
}

up_subscription_t *up_subscription_parseFromJSON(cJSON *up_subscriptionJSON) {
	up_subscription_t *up_subscription_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *up_notify_call_back_uri = NULL;
	cJSON *notif_correlation_id = NULL;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	up_notify_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		up_subscriptionJSON, "upNotifyCallBackUri");
	if(!up_notify_call_back_uri) {
		printf(
			"up_subscription_parseFromJSON() failed [up_notify_call_back_uri]");
		goto end;
	}
	if(!cJSON_IsString(up_notify_call_back_uri)) {
		printf(
			"up_subscription_parseFromJSON() failed [up_notify_call_back_uri]");
		goto end;
	}

	notif_correlation_id = cJSON_GetObjectItemCaseSensitive(
		up_subscriptionJSON, "notifCorrelationId");
	if(!notif_correlation_id) {
		printf(
			"up_subscription_parseFromJSON() failed [notif_correlation_id]");
		goto end;
	}
	if(!cJSON_IsString(notif_correlation_id)) {
		printf(
			"up_subscription_parseFromJSON() failed [notif_correlation_id]");
		goto end;
	}

	supi = cJSON_GetObjectItemCaseSensitive(up_subscriptionJSON, "supi");
	if(!supi) {
		printf("up_subscription_parseFromJSON() failed [supi]");
		goto end;
	}
	if(!cJSON_IsString(supi)) {
		printf("up_subscription_parseFromJSON() failed [supi]");
		goto end;
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(up_subscriptionJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("up_subscription_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	up_subscription_local_var = up_subscription_create(
		strdup(up_notify_call_back_uri->valuestring),
		strdup(notif_correlation_id->valuestring),
		strdup(supi->valuestring),
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL
		);

	return up_subscription_local_var;
end:
	return NULL;
}

up_subscription_t *up_subscription_copy(up_subscription_t	*dst,
                                        up_subscription_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = up_subscription_convertToJSON(src);
	if(!item) {
		printf("up_subscription_convertToJSON() failed");
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

	up_subscription_free(dst);
	dst = up_subscription_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
