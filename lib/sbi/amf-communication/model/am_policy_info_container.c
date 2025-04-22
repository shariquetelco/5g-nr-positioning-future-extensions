#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "am_policy_info_container.h"

am_policy_info_container_t *am_policy_info_container_create(
	list_t *slice_usg_ctrl_info_sets) {
	am_policy_info_container_t *am_policy_info_container_local_var = malloc(
		sizeof(am_policy_info_container_t));

	am_policy_info_container_local_var->slice_usg_ctrl_info_sets =
		slice_usg_ctrl_info_sets;

	return am_policy_info_container_local_var;
}

void am_policy_info_container_free(
	am_policy_info_container_t *am_policy_info_container) {
	lnode_t *node = NULL;

	if(NULL == am_policy_info_container) {
		return;
	}
	if(am_policy_info_container->slice_usg_ctrl_info_sets) {
		list_for_each(
			am_policy_info_container->slice_usg_ctrl_info_sets,
			node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			slice_usage_control_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(am_policy_info_container->slice_usg_ctrl_info_sets);
		am_policy_info_container->slice_usg_ctrl_info_sets = NULL;
	}
	free(am_policy_info_container);
}

cJSON *am_policy_info_container_convertToJSON(
	am_policy_info_container_t *am_policy_info_container) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(am_policy_info_container == NULL) {
		printf(
			"am_policy_info_container_convertToJSON() failed [AmPolicyInfoContainer]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(am_policy_info_container->slice_usg_ctrl_info_sets) {
		cJSON *slice_usg_ctrl_info_sets = cJSON_AddObjectToObject(item,
		                                                          "sliceUsgCtrlInfoSets");
		if(slice_usg_ctrl_info_sets == NULL) {
			printf(
				"am_policy_info_container_convertToJSON() failed [slice_usg_ctrl_info_sets]");
			goto end;
		}
		cJSON *localMapObject = slice_usg_ctrl_info_sets;
		if(am_policy_info_container->slice_usg_ctrl_info_sets) {
			list_for_each(
				am_policy_info_container->slice_usg_ctrl_info_sets,
				node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"am_policy_info_container_convertToJSON() failed [slice_usg_ctrl_info_sets]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"am_policy_info_container_convertToJSON() failed [slice_usg_ctrl_info_sets]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   slice_usage_control_info_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"am_policy_info_container_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

end:
	return item;
}

am_policy_info_container_t *am_policy_info_container_parseFromJSON(
	cJSON *am_policy_info_containerJSON) {
	am_policy_info_container_t *am_policy_info_container_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *slice_usg_ctrl_info_sets = NULL;
	list_t *slice_usg_ctrl_info_setsList = NULL;
	slice_usg_ctrl_info_sets = cJSON_GetObjectItemCaseSensitive(
		am_policy_info_containerJSON, "sliceUsgCtrlInfoSets");
	if(slice_usg_ctrl_info_sets) {
		cJSON *slice_usg_ctrl_info_sets_local_map = NULL;
		if(!cJSON_IsObject(slice_usg_ctrl_info_sets) &&
		   !cJSON_IsNull(slice_usg_ctrl_info_sets))
		{
			printf(
				"am_policy_info_container_parseFromJSON() failed [slice_usg_ctrl_info_sets]");
			goto end;
		}
		if(cJSON_IsObject(slice_usg_ctrl_info_sets)) {
			slice_usg_ctrl_info_setsList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(slice_usg_ctrl_info_sets_local_map,
			                   slice_usg_ctrl_info_sets) {
				cJSON *localMapObject =
					slice_usg_ctrl_info_sets_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), slice_usage_control_info_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"am_policy_info_container_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(slice_usg_ctrl_info_setsList,
				         localMapKeyPair);
			}
		}
	}

	am_policy_info_container_local_var = am_policy_info_container_create(
		slice_usg_ctrl_info_sets ? slice_usg_ctrl_info_setsList : NULL
		);

	return am_policy_info_container_local_var;
end:
	if(slice_usg_ctrl_info_setsList) {
		list_for_each(slice_usg_ctrl_info_setsList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			slice_usage_control_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(slice_usg_ctrl_info_setsList);
		slice_usg_ctrl_info_setsList = NULL;
	}
	return NULL;
}

am_policy_info_container_t *am_policy_info_container_copy(
	am_policy_info_container_t *dst, am_policy_info_container_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = am_policy_info_container_convertToJSON(src);
	if(!item) {
		printf("am_policy_info_container_convertToJSON() failed");
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

	am_policy_info_container_free(dst);
	dst = am_policy_info_container_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
