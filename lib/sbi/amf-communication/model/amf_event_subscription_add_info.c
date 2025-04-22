#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event_subscription_add_info.h"

amf_event_subscription_add_info_t *amf_event_subscription_add_info_create(
	list_t *binding_info, nf_type_t *subscribing_nf_type,
	bool is_event_sync_ind, int event_sync_ind, list_t *nf_consumer_info,
	list_t *aoi_state_list, char *access_token) {
	amf_event_subscription_add_info_t *
	        amf_event_subscription_add_info_local_var =
		malloc(sizeof(amf_event_subscription_add_info_t));

	amf_event_subscription_add_info_local_var->binding_info = binding_info;
	amf_event_subscription_add_info_local_var->subscribing_nf_type =
		subscribing_nf_type;
	amf_event_subscription_add_info_local_var->is_event_sync_ind =
		is_event_sync_ind;
	amf_event_subscription_add_info_local_var->event_sync_ind =
		event_sync_ind;
	amf_event_subscription_add_info_local_var->nf_consumer_info =
		nf_consumer_info;
	amf_event_subscription_add_info_local_var->aoi_state_list =
		aoi_state_list;
	amf_event_subscription_add_info_local_var->access_token = access_token;

	return amf_event_subscription_add_info_local_var;
}

void amf_event_subscription_add_info_free(
	amf_event_subscription_add_info_t *amf_event_subscription_add_info) {
	lnode_t *node = NULL;

	if(NULL == amf_event_subscription_add_info) {
		return;
	}
	if(amf_event_subscription_add_info->binding_info) {
		list_for_each(amf_event_subscription_add_info->binding_info,
		              node) {
			free(node->data);
		}
		list_free(amf_event_subscription_add_info->binding_info);
		amf_event_subscription_add_info->binding_info = NULL;
	}
	if(amf_event_subscription_add_info->subscribing_nf_type) {
		nf_type_free(
			amf_event_subscription_add_info->subscribing_nf_type);
		amf_event_subscription_add_info->subscribing_nf_type = NULL;
	}
	if(amf_event_subscription_add_info->nf_consumer_info) {
		list_for_each(amf_event_subscription_add_info->nf_consumer_info,
		              node) {
			free(node->data);
		}
		list_free(amf_event_subscription_add_info->nf_consumer_info);
		amf_event_subscription_add_info->nf_consumer_info = NULL;
	}
	if(amf_event_subscription_add_info->aoi_state_list) {
		list_for_each(amf_event_subscription_add_info->aoi_state_list,
		              node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			area_of_interest_event_state_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(amf_event_subscription_add_info->aoi_state_list);
		amf_event_subscription_add_info->aoi_state_list = NULL;
	}
	if(amf_event_subscription_add_info->access_token) {
		free(amf_event_subscription_add_info->access_token);
		amf_event_subscription_add_info->access_token = NULL;
	}
	free(amf_event_subscription_add_info);
}

cJSON *amf_event_subscription_add_info_convertToJSON(
	amf_event_subscription_add_info_t *amf_event_subscription_add_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event_subscription_add_info == NULL) {
		printf(
			"amf_event_subscription_add_info_convertToJSON() failed [AmfEventSubscriptionAddInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(amf_event_subscription_add_info->binding_info) {
		cJSON *binding_infoList = cJSON_AddArrayToObject(item,
		                                                 "bindingInfo");
		if(binding_infoList == NULL) {
			printf(
				"amf_event_subscription_add_info_convertToJSON() failed [binding_info]");
			goto end;
		}
		list_for_each(amf_event_subscription_add_info->binding_info,
		              node) {
			if(cJSON_AddStringToObject(binding_infoList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_subscription_add_info_convertToJSON() failed [binding_info]");
				goto end;
			}
		}
	}

	if(amf_event_subscription_add_info->subscribing_nf_type) {
		cJSON *subscribing_nf_type_local_JSON = nf_type_convertToJSON(
			amf_event_subscription_add_info->subscribing_nf_type);
		if(subscribing_nf_type_local_JSON == NULL) {
			printf(
				"amf_event_subscription_add_info_convertToJSON() failed [subscribing_nf_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "subscribingNfType",
		                      subscribing_nf_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_subscription_add_info_convertToJSON() failed [subscribing_nf_type]");
			goto end;
		}
	}

	if(amf_event_subscription_add_info->is_event_sync_ind) {
		if(cJSON_AddBoolToObject(item, "eventSyncInd",
		                         amf_event_subscription_add_info->
		                         event_sync_ind) == NULL)
		{
			printf(
				"amf_event_subscription_add_info_convertToJSON() failed [event_sync_ind]");
			goto end;
		}
	}

	if(amf_event_subscription_add_info->nf_consumer_info) {
		cJSON *nf_consumer_infoList = cJSON_AddArrayToObject(item,
		                                                     "nfConsumerInfo");
		if(nf_consumer_infoList == NULL) {
			printf(
				"amf_event_subscription_add_info_convertToJSON() failed [nf_consumer_info]");
			goto end;
		}
		list_for_each(amf_event_subscription_add_info->nf_consumer_info,
		              node) {
			if(cJSON_AddStringToObject(nf_consumer_infoList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_subscription_add_info_convertToJSON() failed [nf_consumer_info]");
				goto end;
			}
		}
	}

	if(amf_event_subscription_add_info->aoi_state_list) {
		cJSON *aoi_state_list = cJSON_AddObjectToObject(item,
		                                                "aoiStateList");
		if(aoi_state_list == NULL) {
			printf(
				"amf_event_subscription_add_info_convertToJSON() failed [aoi_state_list]");
			goto end;
		}
		cJSON *localMapObject = aoi_state_list;
		if(amf_event_subscription_add_info->aoi_state_list) {
			list_for_each(
				amf_event_subscription_add_info->aoi_state_list,
				node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"amf_event_subscription_add_info_convertToJSON() failed [aoi_state_list]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"amf_event_subscription_add_info_convertToJSON() failed [aoi_state_list]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   area_of_interest_event_state_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"amf_event_subscription_add_info_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

	if(amf_event_subscription_add_info->access_token) {
		if(cJSON_AddStringToObject(item, "accessToken",
		                           amf_event_subscription_add_info->
		                           access_token) == NULL)
		{
			printf(
				"amf_event_subscription_add_info_convertToJSON() failed [access_token]");
			goto end;
		}
	}

end:
	return item;
}

amf_event_subscription_add_info_t *amf_event_subscription_add_info_parseFromJSON(
	cJSON *amf_event_subscription_add_infoJSON) {
	amf_event_subscription_add_info_t *
	        amf_event_subscription_add_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *binding_info = NULL;
	list_t *binding_infoList = NULL;
	cJSON *subscribing_nf_type = NULL;
	nf_type_t *subscribing_nf_type_local_nonprim = NULL;
	cJSON *event_sync_ind = NULL;
	cJSON *nf_consumer_info = NULL;
	list_t *nf_consumer_infoList = NULL;
	cJSON *aoi_state_list = NULL;
	list_t *aoi_state_listList = NULL;
	cJSON *access_token = NULL;
	binding_info = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscription_add_infoJSON, "bindingInfo");
	if(binding_info) {
		cJSON *binding_info_local = NULL;
		if(!cJSON_IsArray(binding_info)) {
			printf(
				"amf_event_subscription_add_info_parseFromJSON() failed [binding_info]");
			goto end;
		}

		binding_infoList = list_create();

		cJSON_ArrayForEach(binding_info_local, binding_info) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(binding_info_local)) {
				printf(
					"amf_event_subscription_add_info_parseFromJSON() failed [binding_info]");
				goto end;
			}
			list_add(binding_infoList,
			         strdup(binding_info_local->valuestring));
		}
	}

	subscribing_nf_type = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscription_add_infoJSON, "subscribingNfType");
	if(subscribing_nf_type) {
		subscribing_nf_type_local_nonprim = nf_type_parseFromJSON(
			subscribing_nf_type);
		if(!subscribing_nf_type_local_nonprim) {
			printf(
				"nf_type_parseFromJSON failed [subscribing_nf_type]");
			goto end;
		}
	}

	event_sync_ind = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscription_add_infoJSON, "eventSyncInd");
	if(event_sync_ind) {
		if(!cJSON_IsBool(event_sync_ind)) {
			printf(
				"amf_event_subscription_add_info_parseFromJSON() failed [event_sync_ind]");
			goto end;
		}
	}

	nf_consumer_info = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscription_add_infoJSON, "nfConsumerInfo");
	if(nf_consumer_info) {
		cJSON *nf_consumer_info_local = NULL;
		if(!cJSON_IsArray(nf_consumer_info)) {
			printf(
				"amf_event_subscription_add_info_parseFromJSON() failed [nf_consumer_info]");
			goto end;
		}

		nf_consumer_infoList = list_create();

		cJSON_ArrayForEach(nf_consumer_info_local, nf_consumer_info) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(nf_consumer_info_local)) {
				printf(
					"amf_event_subscription_add_info_parseFromJSON() failed [nf_consumer_info]");
				goto end;
			}
			list_add(nf_consumer_infoList,
			         strdup(nf_consumer_info_local->valuestring));
		}
	}

	aoi_state_list = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscription_add_infoJSON, "aoiStateList");
	if(aoi_state_list) {
		cJSON *aoi_state_list_local_map = NULL;
		if(!cJSON_IsObject(aoi_state_list) &&
		   !cJSON_IsNull(aoi_state_list))
		{
			printf(
				"amf_event_subscription_add_info_parseFromJSON() failed [aoi_state_list]");
			goto end;
		}
		if(cJSON_IsObject(aoi_state_list)) {
			aoi_state_listList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(aoi_state_list_local_map,
			                   aoi_state_list) {
				cJSON *localMapObject =
					aoi_state_list_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), area_of_interest_event_state_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"amf_event_subscription_add_info_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(aoi_state_listList, localMapKeyPair);
			}
		}
	}

	access_token = cJSON_GetObjectItemCaseSensitive(
		amf_event_subscription_add_infoJSON, "accessToken");
	if(access_token) {
		if(!cJSON_IsString(access_token) &&
		   !cJSON_IsNull(access_token))
		{
			printf(
				"amf_event_subscription_add_info_parseFromJSON() failed [access_token]");
			goto end;
		}
	}

	amf_event_subscription_add_info_local_var =
		amf_event_subscription_add_info_create(
			binding_info ? binding_infoList : NULL,
			subscribing_nf_type ? subscribing_nf_type_local_nonprim : NULL,
			event_sync_ind ? true : false,
			event_sync_ind ? event_sync_ind->valueint : 0,
			nf_consumer_info ? nf_consumer_infoList : NULL,
			aoi_state_list ? aoi_state_listList : NULL,
			access_token &&
			!cJSON_IsNull(access_token) ? strdup(
				access_token->valuestring) : NULL
			);

	return amf_event_subscription_add_info_local_var;
end:
	if(binding_infoList) {
		list_for_each(binding_infoList, node) {
			free(node->data);
		}
		list_free(binding_infoList);
		binding_infoList = NULL;
	}
	if(subscribing_nf_type_local_nonprim) {
		nf_type_free(subscribing_nf_type_local_nonprim);
		subscribing_nf_type_local_nonprim = NULL;
	}
	if(nf_consumer_infoList) {
		list_for_each(nf_consumer_infoList, node) {
			free(node->data);
		}
		list_free(nf_consumer_infoList);
		nf_consumer_infoList = NULL;
	}
	if(aoi_state_listList) {
		list_for_each(aoi_state_listList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			area_of_interest_event_state_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(aoi_state_listList);
		aoi_state_listList = NULL;
	}
	return NULL;
}

amf_event_subscription_add_info_t *amf_event_subscription_add_info_copy(
	amf_event_subscription_add_info_t	*dst,
	amf_event_subscription_add_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_subscription_add_info_convertToJSON(src);
	if(!item) {
		printf("amf_event_subscription_add_info_convertToJSON() failed");
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

	amf_event_subscription_add_info_free(dst);
	dst = amf_event_subscription_add_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
