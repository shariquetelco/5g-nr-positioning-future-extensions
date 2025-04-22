#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "updp_subscription_data.h"

updp_subscription_data_t *updp_subscription_data_create(
	char *updp_notify_subscription_id, char *updp_notify_callback_uri,
	char *supported_features, char *updp_callback_binding) {
	updp_subscription_data_t *updp_subscription_data_local_var = malloc(
		sizeof(updp_subscription_data_t));

	updp_subscription_data_local_var->updp_notify_subscription_id =
		updp_notify_subscription_id;
	updp_subscription_data_local_var->updp_notify_callback_uri =
		updp_notify_callback_uri;
	updp_subscription_data_local_var->supported_features =
		supported_features;
	updp_subscription_data_local_var->updp_callback_binding =
		updp_callback_binding;

	return updp_subscription_data_local_var;
}

void updp_subscription_data_free(
	updp_subscription_data_t *updp_subscription_data) {
	lnode_t *node = NULL;

	if(NULL == updp_subscription_data) {
		return;
	}
	if(updp_subscription_data->updp_notify_subscription_id) {
		free(updp_subscription_data->updp_notify_subscription_id);
		updp_subscription_data->updp_notify_subscription_id = NULL;
	}
	if(updp_subscription_data->updp_notify_callback_uri) {
		free(updp_subscription_data->updp_notify_callback_uri);
		updp_subscription_data->updp_notify_callback_uri = NULL;
	}
	if(updp_subscription_data->supported_features) {
		free(updp_subscription_data->supported_features);
		updp_subscription_data->supported_features = NULL;
	}
	if(updp_subscription_data->updp_callback_binding) {
		free(updp_subscription_data->updp_callback_binding);
		updp_subscription_data->updp_callback_binding = NULL;
	}
	free(updp_subscription_data);
}

cJSON *updp_subscription_data_convertToJSON(
	updp_subscription_data_t *updp_subscription_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(updp_subscription_data == NULL) {
		printf(
			"updp_subscription_data_convertToJSON() failed [UpdpSubscriptionData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!updp_subscription_data->updp_notify_subscription_id) {
		printf(
			"updp_subscription_data_convertToJSON() failed [updp_notify_subscription_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "updpNotifySubscriptionId",
	                           updp_subscription_data->
	                           updp_notify_subscription_id) == NULL)
	{
		printf(
			"updp_subscription_data_convertToJSON() failed [updp_notify_subscription_id]");
		goto end;
	}

	if(!updp_subscription_data->updp_notify_callback_uri) {
		printf(
			"updp_subscription_data_convertToJSON() failed [updp_notify_callback_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "updpNotifyCallbackUri",
	                           updp_subscription_data->
	                           updp_notify_callback_uri) == NULL)
	{
		printf(
			"updp_subscription_data_convertToJSON() failed [updp_notify_callback_uri]");
		goto end;
	}

	if(updp_subscription_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           updp_subscription_data->
		                           supported_features) == NULL)
		{
			printf(
				"updp_subscription_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(updp_subscription_data->updp_callback_binding) {
		if(cJSON_AddStringToObject(item, "updpCallbackBinding",
		                           updp_subscription_data->
		                           updp_callback_binding) == NULL)
		{
			printf(
				"updp_subscription_data_convertToJSON() failed [updp_callback_binding]");
			goto end;
		}
	}

end:
	return item;
}

updp_subscription_data_t *updp_subscription_data_parseFromJSON(
	cJSON *updp_subscription_dataJSON) {
	updp_subscription_data_t *updp_subscription_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *updp_notify_subscription_id = NULL;
	cJSON *updp_notify_callback_uri = NULL;
	cJSON *supported_features = NULL;
	cJSON *updp_callback_binding = NULL;
	updp_notify_subscription_id = cJSON_GetObjectItemCaseSensitive(
		updp_subscription_dataJSON, "updpNotifySubscriptionId");
	if(!updp_notify_subscription_id) {
		printf(
			"updp_subscription_data_parseFromJSON() failed [updp_notify_subscription_id]");
		goto end;
	}
	if(!cJSON_IsString(updp_notify_subscription_id)) {
		printf(
			"updp_subscription_data_parseFromJSON() failed [updp_notify_subscription_id]");
		goto end;
	}

	updp_notify_callback_uri = cJSON_GetObjectItemCaseSensitive(
		updp_subscription_dataJSON, "updpNotifyCallbackUri");
	if(!updp_notify_callback_uri) {
		printf(
			"updp_subscription_data_parseFromJSON() failed [updp_notify_callback_uri]");
		goto end;
	}
	if(!cJSON_IsString(updp_notify_callback_uri)) {
		printf(
			"updp_subscription_data_parseFromJSON() failed [updp_notify_callback_uri]");
		goto end;
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		updp_subscription_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"updp_subscription_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	updp_callback_binding = cJSON_GetObjectItemCaseSensitive(
		updp_subscription_dataJSON, "updpCallbackBinding");
	if(updp_callback_binding) {
		if(!cJSON_IsString(updp_callback_binding) &&
		   !cJSON_IsNull(updp_callback_binding))
		{
			printf(
				"updp_subscription_data_parseFromJSON() failed [updp_callback_binding]");
			goto end;
		}
	}

	updp_subscription_data_local_var = updp_subscription_data_create(
		strdup(updp_notify_subscription_id->valuestring),
		strdup(updp_notify_callback_uri->valuestring),
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL,
		updp_callback_binding &&
		!cJSON_IsNull(updp_callback_binding) ? strdup(
			updp_callback_binding->valuestring) : NULL
		);

	return updp_subscription_data_local_var;
end:
	return NULL;
}

updp_subscription_data_t *updp_subscription_data_copy(
	updp_subscription_data_t *dst, updp_subscription_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = updp_subscription_data_convertToJSON(src);
	if(!item) {
		printf("updp_subscription_data_convertToJSON() failed");
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

	updp_subscription_data_free(dst);
	dst = updp_subscription_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
