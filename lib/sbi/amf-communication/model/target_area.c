#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "target_area.h"

target_area_t *target_area_create(list_t *ta_list, list_t *tai_range_list,
                                  bool is_any_ta, int any_ta) {
	target_area_t *target_area_local_var = malloc(sizeof(target_area_t));

	target_area_local_var->ta_list = ta_list;
	target_area_local_var->tai_range_list = tai_range_list;
	target_area_local_var->is_any_ta = is_any_ta;
	target_area_local_var->any_ta = any_ta;

	return target_area_local_var;
}

void target_area_free(target_area_t *target_area) {
	lnode_t *node = NULL;

	if(NULL == target_area) {
		return;
	}
	if(target_area->ta_list) {
		list_for_each(target_area->ta_list, node) {
			tai_free(node->data);
		}
		list_free(target_area->ta_list);
		target_area->ta_list = NULL;
	}
	if(target_area->tai_range_list) {
		list_for_each(target_area->tai_range_list, node) {
			tai_range_free(node->data);
		}
		list_free(target_area->tai_range_list);
		target_area->tai_range_list = NULL;
	}
	free(target_area);
}

cJSON *target_area_convertToJSON(target_area_t *target_area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(target_area == NULL) {
		printf("target_area_convertToJSON() failed [TargetArea]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(target_area->ta_list) {
		cJSON *ta_listList = cJSON_AddArrayToObject(item, "taList");
		if(ta_listList == NULL) {
			printf("target_area_convertToJSON() failed [ta_list]");
			goto end;
		}
		list_for_each(target_area->ta_list, node) {
			cJSON *itemLocal = tai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"target_area_convertToJSON() failed [ta_list]");
				goto end;
			}
			cJSON_AddItemToArray(ta_listList, itemLocal);
		}
	}

	if(target_area->tai_range_list) {
		cJSON *tai_range_listList = cJSON_AddArrayToObject(item,
		                                                   "taiRangeList");
		if(tai_range_listList == NULL) {
			printf(
				"target_area_convertToJSON() failed [tai_range_list]");
			goto end;
		}
		list_for_each(target_area->tai_range_list, node) {
			cJSON *itemLocal = tai_range_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"target_area_convertToJSON() failed [tai_range_list]");
				goto end;
			}
			cJSON_AddItemToArray(tai_range_listList, itemLocal);
		}
	}

	if(target_area->is_any_ta) {
		if(cJSON_AddBoolToObject(item, "anyTa",
		                         target_area->any_ta) == NULL)
		{
			printf("target_area_convertToJSON() failed [any_ta]");
			goto end;
		}
	}

end:
	return item;
}

target_area_t *target_area_parseFromJSON(cJSON *target_areaJSON) {
	target_area_t *target_area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ta_list = NULL;
	list_t *ta_listList = NULL;
	cJSON *tai_range_list = NULL;
	list_t *tai_range_listList = NULL;
	cJSON *any_ta = NULL;
	ta_list = cJSON_GetObjectItemCaseSensitive(target_areaJSON, "taList");
	if(ta_list) {
		cJSON *ta_list_local = NULL;
		if(!cJSON_IsArray(ta_list)) {
			printf("target_area_parseFromJSON() failed [ta_list]");
			goto end;
		}

		ta_listList = list_create();

		cJSON_ArrayForEach(ta_list_local, ta_list) {
			if(!cJSON_IsObject(ta_list_local)) {
				printf(
					"target_area_parseFromJSON() failed [ta_list]");
				goto end;
			}
			tai_t *ta_listItem = tai_parseFromJSON(ta_list_local);
			if(!ta_listItem) {
				printf("No ta_listItem");
				goto end;
			}
			list_add(ta_listList, ta_listItem);
		}
	}

	tai_range_list = cJSON_GetObjectItemCaseSensitive(target_areaJSON,
	                                                  "taiRangeList");
	if(tai_range_list) {
		cJSON *tai_range_list_local = NULL;
		if(!cJSON_IsArray(tai_range_list)) {
			printf(
				"target_area_parseFromJSON() failed [tai_range_list]");
			goto end;
		}

		tai_range_listList = list_create();

		cJSON_ArrayForEach(tai_range_list_local, tai_range_list) {
			if(!cJSON_IsObject(tai_range_list_local)) {
				printf(
					"target_area_parseFromJSON() failed [tai_range_list]");
				goto end;
			}
			tai_range_t *tai_range_listItem =
				tai_range_parseFromJSON(tai_range_list_local);
			if(!tai_range_listItem) {
				printf("No tai_range_listItem");
				goto end;
			}
			list_add(tai_range_listList, tai_range_listItem);
		}
	}

	any_ta = cJSON_GetObjectItemCaseSensitive(target_areaJSON, "anyTa");
	if(any_ta) {
		if(!cJSON_IsBool(any_ta)) {
			printf("target_area_parseFromJSON() failed [any_ta]");
			goto end;
		}
	}

	target_area_local_var = target_area_create(
		ta_list ? ta_listList : NULL,
		tai_range_list ? tai_range_listList : NULL,
		any_ta ? true : false,
		any_ta ? any_ta->valueint : 0
		);

	return target_area_local_var;
end:
	if(ta_listList) {
		list_for_each(ta_listList, node) {
			tai_free(node->data);
		}
		list_free(ta_listList);
		ta_listList = NULL;
	}
	if(tai_range_listList) {
		list_for_each(tai_range_listList, node) {
			tai_range_free(node->data);
		}
		list_free(tai_range_listList);
		tai_range_listList = NULL;
	}
	return NULL;
}

target_area_t *target_area_copy(target_area_t *dst, target_area_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = target_area_convertToJSON(src);
	if(!item) {
		printf("target_area_convertToJSON() failed");
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

	target_area_free(dst);
	dst = target_area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
