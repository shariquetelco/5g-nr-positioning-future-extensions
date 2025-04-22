#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "non_ue_n2_info_subscription_created_data.h"

non_ue_n2_info_subscription_created_data_t *
non_ue_n2_info_subscription_created_data_create(
	char			*n2_notify_subscription_id,
	char			*supported_features,
	n2_information_class_e	n2_information_class)
{
	non_ue_n2_info_subscription_created_data_t *
	        non_ue_n2_info_subscription_created_data_local_var =
		malloc(sizeof(non_ue_n2_info_subscription_created_data_t));

	non_ue_n2_info_subscription_created_data_local_var->
	n2_notify_subscription_id = n2_notify_subscription_id;
	non_ue_n2_info_subscription_created_data_local_var->supported_features =
		supported_features;
	non_ue_n2_info_subscription_created_data_local_var->n2_information_class
	        = n2_information_class;

	return non_ue_n2_info_subscription_created_data_local_var;
}

void non_ue_n2_info_subscription_created_data_free(
	non_ue_n2_info_subscription_created_data_t *non_ue_n2_info_subscription_created_data)
{
	lnode_t *node = NULL;

	if(NULL == non_ue_n2_info_subscription_created_data) {
		return;
	}
	if(non_ue_n2_info_subscription_created_data->n2_notify_subscription_id)
	{
		free(
			non_ue_n2_info_subscription_created_data->n2_notify_subscription_id);
		non_ue_n2_info_subscription_created_data->
		n2_notify_subscription_id = NULL;
	}
	if(non_ue_n2_info_subscription_created_data->supported_features) {
		free(
			non_ue_n2_info_subscription_created_data->supported_features);
		non_ue_n2_info_subscription_created_data->supported_features =
			NULL;
	}
	free(non_ue_n2_info_subscription_created_data);
}

cJSON *non_ue_n2_info_subscription_created_data_convertToJSON(
	non_ue_n2_info_subscription_created_data_t *non_ue_n2_info_subscription_created_data)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(non_ue_n2_info_subscription_created_data == NULL) {
		printf(
			"non_ue_n2_info_subscription_created_data_convertToJSON() failed [NonUeN2InfoSubscriptionCreatedData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!non_ue_n2_info_subscription_created_data->n2_notify_subscription_id)
	{
		printf(
			"non_ue_n2_info_subscription_created_data_convertToJSON() failed [n2_notify_subscription_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "n2NotifySubscriptionId",
	                           non_ue_n2_info_subscription_created_data->
	                           n2_notify_subscription_id) ==
	   NULL)
	{
		printf(
			"non_ue_n2_info_subscription_created_data_convertToJSON() failed [n2_notify_subscription_id]");
		goto end;
	}

	if(non_ue_n2_info_subscription_created_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           non_ue_n2_info_subscription_created_data
		                           ->supported_features) ==
		   NULL)
		{
			printf(
				"non_ue_n2_info_subscription_created_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(non_ue_n2_info_subscription_created_data->n2_information_class !=
	   n2_information_class_NULL)
	{
		if(cJSON_AddStringToObject(item, "n2InformationClass",
		                           n2_information_class_ToString(
						   non_ue_n2_info_subscription_created_data
						   ->n2_information_class))
		   == NULL)
		{
			printf(
				"non_ue_n2_info_subscription_created_data_convertToJSON() failed [n2_information_class]");
			goto end;
		}
	}

end:
	return item;
}

non_ue_n2_info_subscription_created_data_t *
non_ue_n2_info_subscription_created_data_parseFromJSON(
	cJSON *non_ue_n2_info_subscription_created_dataJSON) {
	non_ue_n2_info_subscription_created_data_t *
	        non_ue_n2_info_subscription_created_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n2_notify_subscription_id = NULL;
	cJSON *supported_features = NULL;
	cJSON *n2_information_class = NULL;
	n2_information_class_e n2_information_classVariable = 0;
	n2_notify_subscription_id = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_created_dataJSON,
		"n2NotifySubscriptionId");
	if(!n2_notify_subscription_id) {
		printf(
			"non_ue_n2_info_subscription_created_data_parseFromJSON() failed [n2_notify_subscription_id]");
		goto end;
	}
	if(!cJSON_IsString(n2_notify_subscription_id)) {
		printf(
			"non_ue_n2_info_subscription_created_data_parseFromJSON() failed [n2_notify_subscription_id]");
		goto end;
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_created_dataJSON,
		"supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"non_ue_n2_info_subscription_created_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	n2_information_class = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_created_dataJSON,
		"n2InformationClass");
	if(n2_information_class) {
		if(!cJSON_IsString(n2_information_class)) {
			printf(
				"non_ue_n2_info_subscription_created_data_parseFromJSON() failed [n2_information_class]");
			goto end;
		}
		n2_information_classVariable = n2_information_class_FromString(
			n2_information_class->valuestring);
	}

	non_ue_n2_info_subscription_created_data_local_var =
		non_ue_n2_info_subscription_created_data_create(
			strdup(n2_notify_subscription_id->valuestring),
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL,
			n2_information_class ? n2_information_classVariable : 0
			);

	return non_ue_n2_info_subscription_created_data_local_var;
end:
	return NULL;
}

non_ue_n2_info_subscription_created_data_t *
non_ue_n2_info_subscription_created_data_copy(
	non_ue_n2_info_subscription_created_data_t	*dst,
	non_ue_n2_info_subscription_created_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = non_ue_n2_info_subscription_created_data_convertToJSON(src);
	if(!item) {
		printf(
			"non_ue_n2_info_subscription_created_data_convertToJSON() failed");
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

	non_ue_n2_info_subscription_created_data_free(dst);
	dst = non_ue_n2_info_subscription_created_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
