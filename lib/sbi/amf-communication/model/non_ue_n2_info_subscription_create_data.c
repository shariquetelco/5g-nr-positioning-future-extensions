#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "non_ue_n2_info_subscription_create_data.h"

non_ue_n2_info_subscription_create_data_t *
non_ue_n2_info_subscription_create_data_create(list_t *global_ran_node_list,
                                               list_t *an_type_list,
                                               n2_information_class_e n2_information_class, char *n2_notify_callback_uri, char *nf_id, char *supported_features,
                                               char *notif_correlation_id) {
	non_ue_n2_info_subscription_create_data_t *
	        non_ue_n2_info_subscription_create_data_local_var =
		malloc(sizeof(non_ue_n2_info_subscription_create_data_t));

	non_ue_n2_info_subscription_create_data_local_var->global_ran_node_list
	        = global_ran_node_list;
	non_ue_n2_info_subscription_create_data_local_var->an_type_list =
		an_type_list;
	non_ue_n2_info_subscription_create_data_local_var->n2_information_class
	        = n2_information_class;
	non_ue_n2_info_subscription_create_data_local_var->
	n2_notify_callback_uri = n2_notify_callback_uri;
	non_ue_n2_info_subscription_create_data_local_var->nf_id = nf_id;
	non_ue_n2_info_subscription_create_data_local_var->supported_features =
		supported_features;
	non_ue_n2_info_subscription_create_data_local_var->notif_correlation_id
	        = notif_correlation_id;

	return non_ue_n2_info_subscription_create_data_local_var;
}

void non_ue_n2_info_subscription_create_data_free(
	non_ue_n2_info_subscription_create_data_t *non_ue_n2_info_subscription_create_data)
{
	lnode_t *node = NULL;

	if(NULL == non_ue_n2_info_subscription_create_data) {
		return;
	}
	if(non_ue_n2_info_subscription_create_data->global_ran_node_list) {
		list_for_each(
			non_ue_n2_info_subscription_create_data->global_ran_node_list,
			node) {
			global_ran_node_id_free(node->data);
		}
		list_free(
			non_ue_n2_info_subscription_create_data->global_ran_node_list);
		non_ue_n2_info_subscription_create_data->global_ran_node_list =
			NULL;
	}
	if(non_ue_n2_info_subscription_create_data->an_type_list) {
		list_free(non_ue_n2_info_subscription_create_data->an_type_list);
		non_ue_n2_info_subscription_create_data->an_type_list = NULL;
	}
	if(non_ue_n2_info_subscription_create_data->n2_notify_callback_uri) {
		free(
			non_ue_n2_info_subscription_create_data->n2_notify_callback_uri);
		non_ue_n2_info_subscription_create_data->n2_notify_callback_uri
		        = NULL;
	}
	if(non_ue_n2_info_subscription_create_data->nf_id) {
		free(non_ue_n2_info_subscription_create_data->nf_id);
		non_ue_n2_info_subscription_create_data->nf_id = NULL;
	}
	if(non_ue_n2_info_subscription_create_data->supported_features) {
		free(non_ue_n2_info_subscription_create_data->supported_features);
		non_ue_n2_info_subscription_create_data->supported_features =
			NULL;
	}
	if(non_ue_n2_info_subscription_create_data->notif_correlation_id) {
		free(
			non_ue_n2_info_subscription_create_data->notif_correlation_id);
		non_ue_n2_info_subscription_create_data->notif_correlation_id =
			NULL;
	}
	free(non_ue_n2_info_subscription_create_data);
}

cJSON *non_ue_n2_info_subscription_create_data_convertToJSON(
	non_ue_n2_info_subscription_create_data_t *non_ue_n2_info_subscription_create_data)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(non_ue_n2_info_subscription_create_data == NULL) {
		printf(
			"non_ue_n2_info_subscription_create_data_convertToJSON() failed [NonUeN2InfoSubscriptionCreateData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(non_ue_n2_info_subscription_create_data->global_ran_node_list) {
		cJSON *global_ran_node_listList = cJSON_AddArrayToObject(item,
		                                                         "globalRanNodeList");
		if(global_ran_node_listList == NULL) {
			printf(
				"non_ue_n2_info_subscription_create_data_convertToJSON() failed [global_ran_node_list]");
			goto end;
		}
		list_for_each(
			non_ue_n2_info_subscription_create_data->global_ran_node_list,
			node) {
			cJSON *itemLocal = global_ran_node_id_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"non_ue_n2_info_subscription_create_data_convertToJSON() failed [global_ran_node_list]");
				goto end;
			}
			cJSON_AddItemToArray(global_ran_node_listList,
			                     itemLocal);
		}
	}

	if(non_ue_n2_info_subscription_create_data->an_type_list !=
	   access_type_NULL)
	{
		cJSON *an_type_listList = cJSON_AddArrayToObject(item,
		                                                 "anTypeList");
		if(an_type_listList == NULL) {
			printf(
				"non_ue_n2_info_subscription_create_data_convertToJSON() failed [an_type_list]");
			goto end;
		}
		list_for_each(
			non_ue_n2_info_subscription_create_data->an_type_list,
			node) {
			if(cJSON_AddStringToObject(an_type_listList, "",
			                           access_type_ToString((
										intptr_t)
			                                                node->
			                                                data))
			   == NULL)
			{
				printf(
					"non_ue_n2_info_subscription_create_data_convertToJSON() failed [an_type_list]");
				goto end;
			}
		}
	}

	if(non_ue_n2_info_subscription_create_data->n2_information_class ==
	   n2_information_class_NULL)
	{
		printf(
			"non_ue_n2_info_subscription_create_data_convertToJSON() failed [n2_information_class]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "n2InformationClass",
	                           n2_information_class_ToString(
					   non_ue_n2_info_subscription_create_data
					   ->
					   n2_information_class))
	   == NULL)
	{
		printf(
			"non_ue_n2_info_subscription_create_data_convertToJSON() failed [n2_information_class]");
		goto end;
	}

	if(!non_ue_n2_info_subscription_create_data->n2_notify_callback_uri) {
		printf(
			"non_ue_n2_info_subscription_create_data_convertToJSON() failed [n2_notify_callback_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "n2NotifyCallbackUri",
	                           non_ue_n2_info_subscription_create_data->
	                           n2_notify_callback_uri) ==
	   NULL)
	{
		printf(
			"non_ue_n2_info_subscription_create_data_convertToJSON() failed [n2_notify_callback_uri]");
		goto end;
	}

	if(non_ue_n2_info_subscription_create_data->nf_id) {
		if(cJSON_AddStringToObject(item, "nfId",
		                           non_ue_n2_info_subscription_create_data
		                           ->nf_id) == NULL)
		{
			printf(
				"non_ue_n2_info_subscription_create_data_convertToJSON() failed [nf_id]");
			goto end;
		}
	}

	if(non_ue_n2_info_subscription_create_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           non_ue_n2_info_subscription_create_data
		                           ->supported_features) ==
		   NULL)
		{
			printf(
				"non_ue_n2_info_subscription_create_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(non_ue_n2_info_subscription_create_data->notif_correlation_id) {
		if(cJSON_AddStringToObject(item, "notifCorrelationId",
		                           non_ue_n2_info_subscription_create_data
		                           ->notif_correlation_id)
		   == NULL)
		{
			printf(
				"non_ue_n2_info_subscription_create_data_convertToJSON() failed [notif_correlation_id]");
			goto end;
		}
	}

end:
	return item;
}

non_ue_n2_info_subscription_create_data_t *
non_ue_n2_info_subscription_create_data_parseFromJSON(
	cJSON *non_ue_n2_info_subscription_create_dataJSON) {
	non_ue_n2_info_subscription_create_data_t *
	        non_ue_n2_info_subscription_create_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *global_ran_node_list = NULL;
	list_t *global_ran_node_listList = NULL;
	cJSON *an_type_list = NULL;
	list_t *an_type_listList = NULL;
	cJSON *n2_information_class = NULL;
	n2_information_class_e n2_information_classVariable = 0;
	cJSON *n2_notify_callback_uri = NULL;
	cJSON *nf_id = NULL;
	cJSON *supported_features = NULL;
	cJSON *notif_correlation_id = NULL;
	global_ran_node_list = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_create_dataJSON,
		"globalRanNodeList");
	if(global_ran_node_list) {
		cJSON *global_ran_node_list_local = NULL;
		if(!cJSON_IsArray(global_ran_node_list)) {
			printf(
				"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [global_ran_node_list]");
			goto end;
		}

		global_ran_node_listList = list_create();

		cJSON_ArrayForEach(global_ran_node_list_local,
		                   global_ran_node_list) {
			if(!cJSON_IsObject(global_ran_node_list_local)) {
				printf(
					"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [global_ran_node_list]");
				goto end;
			}
			global_ran_node_id_t *global_ran_node_listItem =
				global_ran_node_id_parseFromJSON(
					global_ran_node_list_local);
			if(!global_ran_node_listItem) {
				printf("No global_ran_node_listItem");
				goto end;
			}
			list_add(global_ran_node_listList,
			         global_ran_node_listItem);
		}
	}

	an_type_list = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_create_dataJSON, "anTypeList");
	if(an_type_list) {
		cJSON *an_type_list_local = NULL;
		if(!cJSON_IsArray(an_type_list)) {
			printf(
				"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [an_type_list]");
			goto end;
		}

		an_type_listList = list_create();

		cJSON_ArrayForEach(an_type_list_local, an_type_list) {
			access_type_e localEnum = access_type_NULL;
			if(!cJSON_IsString(an_type_list_local)) {
				printf(
					"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [an_type_list]");
				goto end;
			}
			localEnum = access_type_FromString(
				an_type_list_local->valuestring);
			if(!localEnum) {
				printf(
					"Enum value \"%s\" for field \"an_type_list\" is not supported. Ignoring it ...",
					an_type_list_local->valuestring);
			} else {
				list_add(an_type_listList, (void *) localEnum);
			}
		}
		if(an_type_listList->count == 0) {
			printf(
				"non_ue_n2_info_subscription_create_data_parseFromJSON() failed: Expected an_type_listList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	n2_information_class = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_create_dataJSON,
		"n2InformationClass");
	if(!n2_information_class) {
		printf(
			"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [n2_information_class]");
		goto end;
	}
	if(!cJSON_IsString(n2_information_class)) {
		printf(
			"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [n2_information_class]");
		goto end;
	}
	n2_information_classVariable = n2_information_class_FromString(
		n2_information_class->valuestring);

	n2_notify_callback_uri = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_create_dataJSON,
		"n2NotifyCallbackUri");
	if(!n2_notify_callback_uri) {
		printf(
			"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [n2_notify_callback_uri]");
		goto end;
	}
	if(!cJSON_IsString(n2_notify_callback_uri)) {
		printf(
			"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [n2_notify_callback_uri]");
		goto end;
	}

	nf_id = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_create_dataJSON, "nfId");
	if(nf_id) {
		if(!cJSON_IsString(nf_id) &&
		   !cJSON_IsNull(nf_id))
		{
			printf(
				"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [nf_id]");
			goto end;
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_create_dataJSON,
		"supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	notif_correlation_id = cJSON_GetObjectItemCaseSensitive(
		non_ue_n2_info_subscription_create_dataJSON,
		"notifCorrelationId");
	if(notif_correlation_id) {
		if(!cJSON_IsString(notif_correlation_id) &&
		   !cJSON_IsNull(notif_correlation_id))
		{
			printf(
				"non_ue_n2_info_subscription_create_data_parseFromJSON() failed [notif_correlation_id]");
			goto end;
		}
	}

	non_ue_n2_info_subscription_create_data_local_var =
		non_ue_n2_info_subscription_create_data_create(
			global_ran_node_list ? global_ran_node_listList : NULL,
			an_type_list ? an_type_listList : NULL,
			n2_information_classVariable,
			strdup(n2_notify_callback_uri->valuestring),
			nf_id &&
			!cJSON_IsNull(nf_id) ? strdup(
				nf_id->valuestring) : NULL,
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL,
			notif_correlation_id &&
			!cJSON_IsNull(notif_correlation_id) ? strdup(
				notif_correlation_id->valuestring) : NULL
			);

	return non_ue_n2_info_subscription_create_data_local_var;
end:
	if(global_ran_node_listList) {
		list_for_each(global_ran_node_listList, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(global_ran_node_listList);
		global_ran_node_listList = NULL;
	}
	if(an_type_listList) {
		list_free(an_type_listList);
		an_type_listList = NULL;
	}
	return NULL;
}

non_ue_n2_info_subscription_create_data_t *
non_ue_n2_info_subscription_create_data_copy(
	non_ue_n2_info_subscription_create_data_t	*dst,
	non_ue_n2_info_subscription_create_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = non_ue_n2_info_subscription_create_data_convertToJSON(src);
	if(!item) {
		printf(
			"non_ue_n2_info_subscription_create_data_convertToJSON() failed");
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

	non_ue_n2_info_subscription_create_data_free(dst);
	dst = non_ue_n2_info_subscription_create_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
