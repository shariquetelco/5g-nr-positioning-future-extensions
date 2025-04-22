#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "eps_interworking_info.h"

eps_interworking_info_t *eps_interworking_info_create(list_t	*eps_iwk_pgws,
                                                      char	*registration_time)
{
	eps_interworking_info_t *eps_interworking_info_local_var = malloc(
		sizeof(eps_interworking_info_t));

	eps_interworking_info_local_var->eps_iwk_pgws = eps_iwk_pgws;
	eps_interworking_info_local_var->registration_time = registration_time;

	return eps_interworking_info_local_var;
}

void eps_interworking_info_free(eps_interworking_info_t *eps_interworking_info)
{
	lnode_t *node = NULL;

	if(NULL == eps_interworking_info) {
		return;
	}
	if(eps_interworking_info->eps_iwk_pgws) {
		list_for_each(eps_interworking_info->eps_iwk_pgws, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			eps_iwk_pgw_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(eps_interworking_info->eps_iwk_pgws);
		eps_interworking_info->eps_iwk_pgws = NULL;
	}
	if(eps_interworking_info->registration_time) {
		free(eps_interworking_info->registration_time);
		eps_interworking_info->registration_time = NULL;
	}
	free(eps_interworking_info);
}

cJSON *eps_interworking_info_convertToJSON(
	eps_interworking_info_t *eps_interworking_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(eps_interworking_info == NULL) {
		printf(
			"eps_interworking_info_convertToJSON() failed [EpsInterworkingInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(eps_interworking_info->eps_iwk_pgws) {
		cJSON *eps_iwk_pgws =
			cJSON_AddObjectToObject(item, "epsIwkPgws");
		if(eps_iwk_pgws == NULL) {
			printf(
				"eps_interworking_info_convertToJSON() failed [eps_iwk_pgws]");
			goto end;
		}
		cJSON *localMapObject = eps_iwk_pgws;
		if(eps_interworking_info->eps_iwk_pgws) {
			list_for_each(eps_interworking_info->eps_iwk_pgws,
			              node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"eps_interworking_info_convertToJSON() failed [eps_iwk_pgws]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"eps_interworking_info_convertToJSON() failed [eps_iwk_pgws]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   eps_iwk_pgw_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"eps_interworking_info_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

	if(eps_interworking_info->registration_time) {
		if(cJSON_AddStringToObject(item, "registrationTime",
		                           eps_interworking_info->
		                           registration_time) == NULL)
		{
			printf(
				"eps_interworking_info_convertToJSON() failed [registration_time]");
			goto end;
		}
	}

end:
	return item;
}

eps_interworking_info_t *eps_interworking_info_parseFromJSON(
	cJSON *eps_interworking_infoJSON) {
	eps_interworking_info_t *eps_interworking_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *eps_iwk_pgws = NULL;
	list_t *eps_iwk_pgwsList = NULL;
	cJSON *registration_time = NULL;
	eps_iwk_pgws = cJSON_GetObjectItemCaseSensitive(
		eps_interworking_infoJSON, "epsIwkPgws");
	if(eps_iwk_pgws) {
		cJSON *eps_iwk_pgws_local_map = NULL;
		if(!cJSON_IsObject(eps_iwk_pgws) &&
		   !cJSON_IsNull(eps_iwk_pgws))
		{
			printf(
				"eps_interworking_info_parseFromJSON() failed [eps_iwk_pgws]");
			goto end;
		}
		if(cJSON_IsObject(eps_iwk_pgws)) {
			eps_iwk_pgwsList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(eps_iwk_pgws_local_map,
			                   eps_iwk_pgws) {
				cJSON *localMapObject = eps_iwk_pgws_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), eps_iwk_pgw_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"eps_interworking_info_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(eps_iwk_pgwsList, localMapKeyPair);
			}
		}
	}

	registration_time = cJSON_GetObjectItemCaseSensitive(
		eps_interworking_infoJSON, "registrationTime");
	if(registration_time) {
		if(!cJSON_IsString(registration_time) &&
		   !cJSON_IsNull(registration_time))
		{
			printf(
				"eps_interworking_info_parseFromJSON() failed [registration_time]");
			goto end;
		}
	}

	eps_interworking_info_local_var = eps_interworking_info_create(
		eps_iwk_pgws ? eps_iwk_pgwsList : NULL,
		registration_time &&
		!cJSON_IsNull(registration_time) ? strdup(registration_time->
		                                          valuestring) : NULL
		);

	return eps_interworking_info_local_var;
end:
	if(eps_iwk_pgwsList) {
		list_for_each(eps_iwk_pgwsList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			eps_iwk_pgw_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(eps_iwk_pgwsList);
		eps_iwk_pgwsList = NULL;
	}
	return NULL;
}

eps_interworking_info_t *eps_interworking_info_copy(
	eps_interworking_info_t *dst, eps_interworking_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = eps_interworking_info_convertToJSON(src);
	if(!item) {
		printf("eps_interworking_info_convertToJSON() failed");
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

	eps_interworking_info_free(dst);
	dst = eps_interworking_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
