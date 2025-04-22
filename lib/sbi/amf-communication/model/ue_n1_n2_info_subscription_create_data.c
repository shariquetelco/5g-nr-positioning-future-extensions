#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_n1_n2_info_subscription_create_data.h"

ue_n1_n2_info_subscription_create_data_t *
ue_n1_n2_info_subscription_create_data_create(
	n2_information_class_e n2_information_class,
	char *n2_notify_callback_uri, n1_message_class_e n1_message_class,
	char *n1_notify_callback_uri, char *nf_id, char *supported_features,
	guami_t *old_guami) {
	ue_n1_n2_info_subscription_create_data_t *
	        ue_n1_n2_info_subscription_create_data_local_var =
		malloc(sizeof(ue_n1_n2_info_subscription_create_data_t));

	ue_n1_n2_info_subscription_create_data_local_var->n2_information_class =
		n2_information_class;
	ue_n1_n2_info_subscription_create_data_local_var->n2_notify_callback_uri
	        = n2_notify_callback_uri;
	ue_n1_n2_info_subscription_create_data_local_var->n1_message_class =
		n1_message_class;
	ue_n1_n2_info_subscription_create_data_local_var->n1_notify_callback_uri
	        = n1_notify_callback_uri;
	ue_n1_n2_info_subscription_create_data_local_var->nf_id = nf_id;
	ue_n1_n2_info_subscription_create_data_local_var->supported_features =
		supported_features;
	ue_n1_n2_info_subscription_create_data_local_var->old_guami = old_guami;

	return ue_n1_n2_info_subscription_create_data_local_var;
}

void ue_n1_n2_info_subscription_create_data_free(
	ue_n1_n2_info_subscription_create_data_t *ue_n1_n2_info_subscription_create_data)
{
	lnode_t *node = NULL;

	if(NULL == ue_n1_n2_info_subscription_create_data) {
		return;
	}
	if(ue_n1_n2_info_subscription_create_data->n2_notify_callback_uri) {
		free(
			ue_n1_n2_info_subscription_create_data->n2_notify_callback_uri);
		ue_n1_n2_info_subscription_create_data->n2_notify_callback_uri =
			NULL;
	}
	if(ue_n1_n2_info_subscription_create_data->n1_notify_callback_uri) {
		free(
			ue_n1_n2_info_subscription_create_data->n1_notify_callback_uri);
		ue_n1_n2_info_subscription_create_data->n1_notify_callback_uri =
			NULL;
	}
	if(ue_n1_n2_info_subscription_create_data->nf_id) {
		free(ue_n1_n2_info_subscription_create_data->nf_id);
		ue_n1_n2_info_subscription_create_data->nf_id = NULL;
	}
	if(ue_n1_n2_info_subscription_create_data->supported_features) {
		free(ue_n1_n2_info_subscription_create_data->supported_features);
		ue_n1_n2_info_subscription_create_data->supported_features =
			NULL;
	}
	if(ue_n1_n2_info_subscription_create_data->old_guami) {
		guami_free(ue_n1_n2_info_subscription_create_data->old_guami);
		ue_n1_n2_info_subscription_create_data->old_guami = NULL;
	}
	free(ue_n1_n2_info_subscription_create_data);
}

cJSON *ue_n1_n2_info_subscription_create_data_convertToJSON(
	ue_n1_n2_info_subscription_create_data_t *ue_n1_n2_info_subscription_create_data)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_n1_n2_info_subscription_create_data == NULL) {
		printf(
			"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [UeN1N2InfoSubscriptionCreateData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_n1_n2_info_subscription_create_data->n2_information_class !=
	   n2_information_class_NULL)
	{
		if(cJSON_AddStringToObject(item, "n2InformationClass",
		                           n2_information_class_ToString(
						   ue_n1_n2_info_subscription_create_data
						   ->n2_information_class))
		   == NULL)
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [n2_information_class]");
			goto end;
		}
	}

	if(ue_n1_n2_info_subscription_create_data->n2_notify_callback_uri) {
		if(cJSON_AddStringToObject(item, "n2NotifyCallbackUri",
		                           ue_n1_n2_info_subscription_create_data
		                           ->n2_notify_callback_uri)
		   == NULL)
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [n2_notify_callback_uri]");
			goto end;
		}
	}

	if(ue_n1_n2_info_subscription_create_data->n1_message_class !=
	   n1_message_class_NULL)
	{
		if(cJSON_AddStringToObject(item, "n1MessageClass",
		                           n1_message_class_ToString(
						   ue_n1_n2_info_subscription_create_data
						   ->
						   n1_message_class)) == NULL)
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [n1_message_class]");
			goto end;
		}
	}

	if(ue_n1_n2_info_subscription_create_data->n1_notify_callback_uri) {
		if(cJSON_AddStringToObject(item, "n1NotifyCallbackUri",
		                           ue_n1_n2_info_subscription_create_data
		                           ->n1_notify_callback_uri)
		   == NULL)
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [n1_notify_callback_uri]");
			goto end;
		}
	}

	if(ue_n1_n2_info_subscription_create_data->nf_id) {
		if(cJSON_AddStringToObject(item, "nfId",
		                           ue_n1_n2_info_subscription_create_data
		                           ->nf_id) == NULL)
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [nf_id]");
			goto end;
		}
	}

	if(ue_n1_n2_info_subscription_create_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           ue_n1_n2_info_subscription_create_data
		                           ->supported_features) ==
		   NULL)
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(ue_n1_n2_info_subscription_create_data->old_guami) {
		cJSON *old_guami_local_JSON = guami_convertToJSON(
			ue_n1_n2_info_subscription_create_data->old_guami);
		if(old_guami_local_JSON == NULL) {
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [old_guami]");
			goto end;
		}
		cJSON_AddItemToObject(item, "oldGuami", old_guami_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_n1_n2_info_subscription_create_data_convertToJSON() failed [old_guami]");
			goto end;
		}
	}

end:
	return item;
}

ue_n1_n2_info_subscription_create_data_t *
ue_n1_n2_info_subscription_create_data_parseFromJSON(
	cJSON *ue_n1_n2_info_subscription_create_dataJSON) {
	ue_n1_n2_info_subscription_create_data_t *
	        ue_n1_n2_info_subscription_create_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *n2_information_class = NULL;
	n2_information_class_e n2_information_classVariable = 0;
	cJSON *n2_notify_callback_uri = NULL;
	cJSON *n1_message_class = NULL;
	n1_message_class_e n1_message_classVariable = 0;
	cJSON *n1_notify_callback_uri = NULL;
	cJSON *nf_id = NULL;
	cJSON *supported_features = NULL;
	cJSON *old_guami = NULL;
	guami_t *old_guami_local_nonprim = NULL;
	n2_information_class = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_create_dataJSON,
		"n2InformationClass");
	if(n2_information_class) {
		if(!cJSON_IsString(n2_information_class)) {
			printf(
				"ue_n1_n2_info_subscription_create_data_parseFromJSON() failed [n2_information_class]");
			goto end;
		}
		n2_information_classVariable = n2_information_class_FromString(
			n2_information_class->valuestring);
	}

	n2_notify_callback_uri = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_create_dataJSON,
		"n2NotifyCallbackUri");
	if(n2_notify_callback_uri) {
		if(!cJSON_IsString(n2_notify_callback_uri) &&
		   !cJSON_IsNull(n2_notify_callback_uri))
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_parseFromJSON() failed [n2_notify_callback_uri]");
			goto end;
		}
	}

	n1_message_class = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_create_dataJSON, "n1MessageClass");
	if(n1_message_class) {
		if(!cJSON_IsString(n1_message_class)) {
			printf(
				"ue_n1_n2_info_subscription_create_data_parseFromJSON() failed [n1_message_class]");
			goto end;
		}
		n1_message_classVariable = n1_message_class_FromString(
			n1_message_class->valuestring);
	}

	n1_notify_callback_uri = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_create_dataJSON,
		"n1NotifyCallbackUri");
	if(n1_notify_callback_uri) {
		if(!cJSON_IsString(n1_notify_callback_uri) &&
		   !cJSON_IsNull(n1_notify_callback_uri))
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_parseFromJSON() failed [n1_notify_callback_uri]");
			goto end;
		}
	}

	nf_id = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_create_dataJSON, "nfId");
	if(nf_id) {
		if(!cJSON_IsString(nf_id) &&
		   !cJSON_IsNull(nf_id))
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_parseFromJSON() failed [nf_id]");
			goto end;
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_create_dataJSON,
		"supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"ue_n1_n2_info_subscription_create_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	old_guami = cJSON_GetObjectItemCaseSensitive(
		ue_n1_n2_info_subscription_create_dataJSON, "oldGuami");
	if(old_guami) {
		old_guami_local_nonprim = guami_parseFromJSON(old_guami);
		if(!old_guami_local_nonprim) {
			printf("guami_parseFromJSON failed [old_guami]");
			goto end;
		}
	}

	ue_n1_n2_info_subscription_create_data_local_var =
		ue_n1_n2_info_subscription_create_data_create(
			n2_information_class ? n2_information_classVariable : 0,
			n2_notify_callback_uri &&
			!cJSON_IsNull(n2_notify_callback_uri) ? strdup(
				n2_notify_callback_uri->valuestring) : NULL,
			n1_message_class ? n1_message_classVariable : 0,
			n1_notify_callback_uri &&
			!cJSON_IsNull(n1_notify_callback_uri) ? strdup(
				n1_notify_callback_uri->valuestring) : NULL,
			nf_id &&
			!cJSON_IsNull(nf_id) ? strdup(
				nf_id->valuestring) : NULL,
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL,
			old_guami ? old_guami_local_nonprim : NULL
			);

	return ue_n1_n2_info_subscription_create_data_local_var;
end:
	if(old_guami_local_nonprim) {
		guami_free(old_guami_local_nonprim);
		old_guami_local_nonprim = NULL;
	}
	return NULL;
}

ue_n1_n2_info_subscription_create_data_t *
ue_n1_n2_info_subscription_create_data_copy(
	ue_n1_n2_info_subscription_create_data_t	*dst,
	ue_n1_n2_info_subscription_create_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_n1_n2_info_subscription_create_data_convertToJSON(src);
	if(!item) {
		printf(
			"ue_n1_n2_info_subscription_create_data_convertToJSON() failed");
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

	ue_n1_n2_info_subscription_create_data_free(dst);
	dst = ue_n1_n2_info_subscription_create_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
