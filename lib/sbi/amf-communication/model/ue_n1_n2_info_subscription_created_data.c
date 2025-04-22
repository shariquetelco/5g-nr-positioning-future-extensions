#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_n1_n2_info_subscription_created_data.h"

ue_n1_n2_info_subscription_created_data_t *
ue_n1_n2_info_subscription_created_data_create(
	char *n1n2_notify_subscription_id, char *supported_features) {
	ue_n1_n2_info_subscription_created_data_t *
	        ue_n1_n2_info_subscription_created_data_local_var =
		malloc(sizeof(ue_n1_n2_info_subscription_created_data_t));

	ue_n1_n2_info_subscription_created_data_local_var->
	n1n2_notify_subscription_id = n1n2_notify_subscription_id;
	ue_n1_n2_info_subscription_created_data_local_var->supported_features =
		supported_features;

	return ue_n1_n2_info_subscription_created_data_local_var;
}

void ue_n1_n2_info_subscription_created_data_free(
	ue_n1_n2_info_subscription_created_data_t *ue_n1_n2_info_subscription_created_data)
{
	lnode_t *node = NULL;

	if(NULL == ue_n1_n2_info_subscription_created_data) {
		return;
	}
	if(ue_n1_n2_info_subscription_created_data->n1n2_notify_subscription_id)
	{
		free(
			ue_n1_n2_info_subscription_created_data->n1n2_notify_subscription_id);
		ue_n1_n2_info_subscription_created_data->
		n1n2_notify_subscription_id = NULL;
	}
	if(ue_n1_n2_info_subscription_created_data->supported_features) {
		free(ue_n1_n2_info_subscription_created_data->supported_features);
		ue_n1_n2_info_subscription_created_data->supported_features =
			NULL;
	}
	free(ue_n1_n2_info_subscription_created_data);
}

cJSON *ue_n1_n2_info_subscription_created_data_convertToJSON(
	ue_n1_n2_info_subscription_created_data_t *ue_n1_n2_info_subscription_created_data)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_n1_n2_info_subscription_created_data == NULL) {
		printf(
			"ue_n1_n2_info_subscription_created_data_convertToJSON() failed [UeN1N2InfoSubscriptionCreatedData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ue_n1_n2_info_subscription_created_data->n1n2_notify_subscription_id)
	{
		printf(
			"ue_n1_n2_info_subscription_created_data_convertToJSON() failed [n1n2_notify_subscription_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "n1n2NotifySubscriptionId",
	                           ue_n1_n2_info_subscription_created_data->
	                           n1n2_notify_subscription_id) ==
	   NULL)
	{
		printf(
			"ue_n1_n2_info_subscription_created_data_convertToJSON() failed [n1n2_notify_subscription_id]");
		goto end;
	}

	if(ue_n1_n2_info_subscription_created_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           ue_n1_n2_info_subscription_created_data
		                           ->supported_features) ==
		   NULL)
		{
			printf(
				"ue_n1_n2_info_subscription_created_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

end:
	return item;
}

ue_n1_n2_info_subscription_created_data_t *
ue_n1_n2_info_subscription_created_data_parseFromJSON(
	cJSON *ue_n1_n2_info_subscription_created_dataJSON) {
	ue_n1_n2_info_subscription_created_data_t *
	        ue_n1_n2_info_subscription_created_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n1n2_notify_subscription_id = NULL;
	cJSON *supported_features = NULL;
	n1n2_notify_subscription_id = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_created_dataJSON,
		"n1n2NotifySubscriptionId");
	if(!n1n2_notify_subscription_id) {
		printf(
			"ue_n1_n2_info_subscription_created_data_parseFromJSON() failed [n1n2_notify_subscription_id]");
		goto end;
	}
	if(!cJSON_IsString(n1n2_notify_subscription_id)) {
		printf(
			"ue_n1_n2_info_subscription_created_data_parseFromJSON() failed [n1n2_notify_subscription_id]");
		goto end;
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_created_dataJSON,
		"supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"ue_n1_n2_info_subscription_created_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	ue_n1_n2_info_subscription_created_data_local_var =
		ue_n1_n2_info_subscription_created_data_create(
			strdup(n1n2_notify_subscription_id->valuestring),
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL
			);

	return ue_n1_n2_info_subscription_created_data_local_var;
end:
	return NULL;
}

ue_n1_n2_info_subscription_created_data_t *
ue_n1_n2_info_subscription_created_data_copy(
	ue_n1_n2_info_subscription_created_data_t	*dst,
	ue_n1_n2_info_subscription_created_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_n1_n2_info_subscription_created_data_convertToJSON(src);
	if(!item) {
		printf(
			"ue_n1_n2_info_subscription_created_data_convertToJSON() failed");
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

	ue_n1_n2_info_subscription_created_data_free(dst);
	dst = ue_n1_n2_info_subscription_created_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
