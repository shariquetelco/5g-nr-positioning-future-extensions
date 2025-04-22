#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cag_data.h"

cag_data_t *cag_data_create(list_t *cag_infos, list_t *conditional_cag_infos,
                            char *provisioning_time) {
	cag_data_t *cag_data_local_var = malloc(sizeof(cag_data_t));

	cag_data_local_var->cag_infos = cag_infos;
	cag_data_local_var->conditional_cag_infos = conditional_cag_infos;
	cag_data_local_var->provisioning_time = provisioning_time;

	return cag_data_local_var;
}

void cag_data_free(cag_data_t *cag_data) {
	lnode_t *node = NULL;

	if(NULL == cag_data) {
		return;
	}
	if(cag_data->cag_infos) {
		list_for_each(cag_data->cag_infos, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			cag_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(cag_data->cag_infos);
		cag_data->cag_infos = NULL;
	}
	if(cag_data->conditional_cag_infos) {
		list_for_each(cag_data->conditional_cag_infos, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			conditional_cag_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(cag_data->conditional_cag_infos);
		cag_data->conditional_cag_infos = NULL;
	}
	if(cag_data->provisioning_time) {
		free(cag_data->provisioning_time);
		cag_data->provisioning_time = NULL;
	}
	free(cag_data);
}

cJSON *cag_data_convertToJSON(cag_data_t *cag_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cag_data == NULL) {
		printf("cag_data_convertToJSON() failed [CagData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!cag_data->cag_infos) {
		printf("cag_data_convertToJSON() failed [cag_infos]");
		return NULL;
	}
	cJSON *cag_infos = cJSON_AddObjectToObject(item, "cagInfos");
	if(cag_infos == NULL) {
		printf("cag_data_convertToJSON() failed [cag_infos]");
		goto end;
	}
	cJSON *localMapObject = cag_infos;
	if(cag_data->cag_infos) {
		list_for_each(cag_data->cag_infos, node) {
			map_t *localKeyValue = (map_t *) node->data;
			if(localKeyValue == NULL) {
				printf(
					"cag_data_convertToJSON() failed [cag_infos]");
				goto end;
			}
			if(localKeyValue->key == NULL) {
				printf(
					"cag_data_convertToJSON() failed [cag_infos]");
				goto end;
			}
			cJSON *itemLocal = localKeyValue->value ?
			                   cag_info_convertToJSON(
				localKeyValue->value) :
			                   cJSON_CreateNull();
			if(itemLocal == NULL) {
				printf("cag_data_convertToJSON() failed [inner]");
				goto end;
			}
			cJSON_AddItemToObject(localMapObject,
			                      localKeyValue->key, itemLocal);
		}
	}

	if(cag_data->conditional_cag_infos) {
		cJSON *conditional_cag_infos = cJSON_AddObjectToObject(item,
		                                                       "conditionalCagInfos");
		if(conditional_cag_infos == NULL) {
			printf(
				"cag_data_convertToJSON() failed [conditional_cag_infos]");
			goto end;
		}
		cJSON *localMapObject = conditional_cag_infos;
		if(cag_data->conditional_cag_infos) {
			list_for_each(cag_data->conditional_cag_infos, node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"cag_data_convertToJSON() failed [conditional_cag_infos]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"cag_data_convertToJSON() failed [conditional_cag_infos]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   conditional_cag_info_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"cag_data_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

	if(cag_data->provisioning_time) {
		if(cJSON_AddStringToObject(item, "provisioningTime",
		                           cag_data->provisioning_time) == NULL)
		{
			printf(
				"cag_data_convertToJSON() failed [provisioning_time]");
			goto end;
		}
	}

end:
	return item;
}

cag_data_t *cag_data_parseFromJSON(cJSON *cag_dataJSON) {
	cag_data_t *cag_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cag_infos = NULL;
	list_t *cag_infosList = NULL;
	cJSON *conditional_cag_infos = NULL;
	list_t *conditional_cag_infosList = NULL;
	cJSON *provisioning_time = NULL;
	cag_infos = cJSON_GetObjectItemCaseSensitive(cag_dataJSON, "cagInfos");
	if(!cag_infos) {
		printf("cag_data_parseFromJSON() failed [cag_infos]");
		goto end;
	}
	cJSON *cag_infos_local_map = NULL;
	if(!cJSON_IsObject(cag_infos) &&
	   !cJSON_IsNull(cag_infos))
	{
		printf("cag_data_parseFromJSON() failed [cag_infos]");
		goto end;
	}
	if(cJSON_IsObject(cag_infos)) {
		cag_infosList = list_create();
		map_t *localMapKeyPair = NULL;
		cJSON_ArrayForEach(cag_infos_local_map, cag_infos) {
			cJSON *localMapObject = cag_infos_local_map;
			if(cJSON_IsObject(localMapObject)) {
				localMapKeyPair = map_create(
					strdup(
						localMapObject->string), cag_info_parseFromJSON(
						localMapObject));
			} else if(cJSON_IsNull(localMapObject)) {
				localMapKeyPair =
					map_create(strdup(
							   localMapObject->
							   string),
					           NULL);
			} else {
				printf("cag_data_parseFromJSON() failed [inner]");
				goto end;
			}
			list_add(cag_infosList, localMapKeyPair);
		}
	}

	conditional_cag_infos = cJSON_GetObjectItemCaseSensitive(cag_dataJSON,
	                                                         "conditionalCagInfos");
	if(conditional_cag_infos) {
		cJSON *conditional_cag_infos_local_map = NULL;
		if(!cJSON_IsObject(conditional_cag_infos) &&
		   !cJSON_IsNull(conditional_cag_infos))
		{
			printf(
				"cag_data_parseFromJSON() failed [conditional_cag_infos]");
			goto end;
		}
		if(cJSON_IsObject(conditional_cag_infos)) {
			conditional_cag_infosList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(conditional_cag_infos_local_map,
			                   conditional_cag_infos) {
				cJSON *localMapObject =
					conditional_cag_infos_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), conditional_cag_info_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"cag_data_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(conditional_cag_infosList,
				         localMapKeyPair);
			}
		}
	}

	provisioning_time = cJSON_GetObjectItemCaseSensitive(cag_dataJSON,
	                                                     "provisioningTime");
	if(provisioning_time) {
		if(!cJSON_IsString(provisioning_time) &&
		   !cJSON_IsNull(provisioning_time))
		{
			printf(
				"cag_data_parseFromJSON() failed [provisioning_time]");
			goto end;
		}
	}

	cag_data_local_var = cag_data_create(
		cag_infosList,
		conditional_cag_infos ? conditional_cag_infosList : NULL,
		provisioning_time &&
		!cJSON_IsNull(provisioning_time) ? strdup(provisioning_time->
		                                          valuestring) : NULL
		);

	return cag_data_local_var;
end:
	if(cag_infosList) {
		list_for_each(cag_infosList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			cag_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(cag_infosList);
		cag_infosList = NULL;
	}
	if(conditional_cag_infosList) {
		list_for_each(conditional_cag_infosList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			conditional_cag_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(conditional_cag_infosList);
		conditional_cag_infosList = NULL;
	}
	return NULL;
}

cag_data_t *cag_data_copy(cag_data_t *dst, cag_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cag_data_convertToJSON(src);
	if(!item) {
		printf("cag_data_convertToJSON() failed");
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

	cag_data_free(dst);
	dst = cag_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
