#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "area_of_validity.h"

area_of_validity_t *area_of_validity_create(list_t	*tai_list,
                                            list_t	*tai_range_list) {
	area_of_validity_t *area_of_validity_local_var =
		malloc(sizeof(area_of_validity_t));

	area_of_validity_local_var->tai_list = tai_list;
	area_of_validity_local_var->tai_range_list = tai_range_list;

	return area_of_validity_local_var;
}

void area_of_validity_free(area_of_validity_t *area_of_validity) {
	lnode_t *node = NULL;

	if(NULL == area_of_validity) {
		return;
	}
	if(area_of_validity->tai_list) {
		list_for_each(area_of_validity->tai_list, node) {
			tai_free(node->data);
		}
		list_free(area_of_validity->tai_list);
		area_of_validity->tai_list = NULL;
	}
	if(area_of_validity->tai_range_list) {
		list_for_each(area_of_validity->tai_range_list, node) {
			tai_range_free(node->data);
		}
		list_free(area_of_validity->tai_range_list);
		area_of_validity->tai_range_list = NULL;
	}
	free(area_of_validity);
}

cJSON *area_of_validity_convertToJSON(area_of_validity_t *area_of_validity) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(area_of_validity == NULL) {
		printf(
			"area_of_validity_convertToJSON() failed [AreaOfValidity]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!area_of_validity->tai_list) {
		printf("area_of_validity_convertToJSON() failed [tai_list]");
		return NULL;
	}
	cJSON *tai_listList = cJSON_AddArrayToObject(item, "taiList");
	if(tai_listList == NULL) {
		printf("area_of_validity_convertToJSON() failed [tai_list]");
		goto end;
	}
	list_for_each(area_of_validity->tai_list, node) {
		cJSON *itemLocal = tai_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"area_of_validity_convertToJSON() failed [tai_list]");
			goto end;
		}
		cJSON_AddItemToArray(tai_listList, itemLocal);
	}

	if(area_of_validity->tai_range_list) {
		cJSON *tai_range_listList = cJSON_AddArrayToObject(item,
		                                                   "taiRangeList");
		if(tai_range_listList == NULL) {
			printf(
				"area_of_validity_convertToJSON() failed [tai_range_list]");
			goto end;
		}
		list_for_each(area_of_validity->tai_range_list, node) {
			cJSON *itemLocal = tai_range_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"area_of_validity_convertToJSON() failed [tai_range_list]");
				goto end;
			}
			cJSON_AddItemToArray(tai_range_listList, itemLocal);
		}
	}

end:
	return item;
}

area_of_validity_t *area_of_validity_parseFromJSON(cJSON *area_of_validityJSON)
{
	area_of_validity_t *area_of_validity_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *tai_list = NULL;
	list_t *tai_listList = NULL;
	cJSON *tai_range_list = NULL;
	list_t *tai_range_listList = NULL;
	tai_list = cJSON_GetObjectItemCaseSensitive(area_of_validityJSON,
	                                            "taiList");
	if(!tai_list) {
		printf("area_of_validity_parseFromJSON() failed [tai_list]");
		goto end;
	}
	cJSON *tai_list_local = NULL;
	if(!cJSON_IsArray(tai_list)) {
		printf("area_of_validity_parseFromJSON() failed [tai_list]");
		goto end;
	}

	tai_listList = list_create();

	cJSON_ArrayForEach(tai_list_local, tai_list) {
		if(!cJSON_IsObject(tai_list_local)) {
			printf(
				"area_of_validity_parseFromJSON() failed [tai_list]");
			goto end;
		}
		tai_t *tai_listItem = tai_parseFromJSON(tai_list_local);
		if(!tai_listItem) {
			printf("No tai_listItem");
			goto end;
		}
		list_add(tai_listList, tai_listItem);
	}

	tai_range_list = cJSON_GetObjectItemCaseSensitive(area_of_validityJSON,
	                                                  "taiRangeList");
	if(tai_range_list) {
		cJSON *tai_range_list_local = NULL;
		if(!cJSON_IsArray(tai_range_list)) {
			printf(
				"area_of_validity_parseFromJSON() failed [tai_range_list]");
			goto end;
		}

		tai_range_listList = list_create();

		cJSON_ArrayForEach(tai_range_list_local, tai_range_list) {
			if(!cJSON_IsObject(tai_range_list_local)) {
				printf(
					"area_of_validity_parseFromJSON() failed [tai_range_list]");
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

	area_of_validity_local_var = area_of_validity_create(
		tai_listList,
		tai_range_list ? tai_range_listList : NULL
		);

	return area_of_validity_local_var;
end:
	if(tai_listList) {
		list_for_each(tai_listList, node) {
			tai_free(node->data);
		}
		list_free(tai_listList);
		tai_listList = NULL;
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

area_of_validity_t *area_of_validity_copy(area_of_validity_t	*dst,
                                          area_of_validity_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = area_of_validity_convertToJSON(src);
	if(!item) {
		printf("area_of_validity_convertToJSON() failed");
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

	area_of_validity_free(dst);
	dst = area_of_validity_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
