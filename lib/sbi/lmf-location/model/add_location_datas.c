#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_location_datas.h"

add_location_datas_t *add_location_datas_create(list_t *add_location_datas) {
	add_location_datas_t *add_location_datas_local_var =
		malloc(sizeof(add_location_datas_t));

	add_location_datas_local_var->add_location_datas = add_location_datas;

	return add_location_datas_local_var;
}

void add_location_datas_free(add_location_datas_t *add_location_datas) {
	lnode_t *node = NULL;

	if(NULL == add_location_datas) {
		return;
	}
	if(add_location_datas->add_location_datas) {
		list_for_each(add_location_datas->add_location_datas, node) {
			location_data_free(node->data);
		}
		list_free(add_location_datas->add_location_datas);
		add_location_datas->add_location_datas = NULL;
	}
	free(add_location_datas);
}

cJSON *add_location_datas_convertToJSON(
	add_location_datas_t *add_location_datas) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(add_location_datas == NULL) {
		printf(
			"add_location_datas_convertToJSON() failed [AddLocationDatas]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(add_location_datas->add_location_datas) {
		cJSON *add_location_datasList = cJSON_AddArrayToObject(item,
		                                                       "addLocationDatas");
		if(add_location_datasList == NULL) {
			printf(
				"add_location_datas_convertToJSON() failed [add_location_datas]");
			goto end;
		}
		list_for_each(add_location_datas->add_location_datas, node) {
			cJSON *itemLocal = location_data_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"add_location_datas_convertToJSON() failed [add_location_datas]");
				goto end;
			}
			cJSON_AddItemToArray(add_location_datasList, itemLocal);
		}
	}

end:
	return item;
}

add_location_datas_t *add_location_datas_parseFromJSON(
	cJSON *add_location_datasJSON) {
	add_location_datas_t *add_location_datas_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *add_location_datas = NULL;
	list_t *add_location_datasList = NULL;
	add_location_datas = cJSON_GetObjectItemCaseSensitive(
		add_location_datasJSON, "addLocationDatas");
	if(add_location_datas) {
		cJSON *add_location_datas_local = NULL;
		if(!cJSON_IsArray(add_location_datas)) {
			printf(
				"add_location_datas_parseFromJSON() failed [add_location_datas]");
			goto end;
		}

		add_location_datasList = list_create();

		cJSON_ArrayForEach(add_location_datas_local,
		                   add_location_datas) {
			if(!cJSON_IsObject(add_location_datas_local)) {
				printf(
					"add_location_datas_parseFromJSON() failed [add_location_datas]");
				goto end;
			}
			location_data_t *add_location_datasItem =
				location_data_parseFromJSON(
					add_location_datas_local);
			if(!add_location_datasItem) {
				printf("No add_location_datasItem");
				goto end;
			}
			list_add(add_location_datasList,
			         add_location_datasItem);
		}
	}

	add_location_datas_local_var = add_location_datas_create(
		add_location_datas ? add_location_datasList : NULL
		);

	return add_location_datas_local_var;
end:
	if(add_location_datasList) {
		list_for_each(add_location_datasList, node) {
			location_data_free(node->data);
		}
		list_free(add_location_datasList);
		add_location_datasList = NULL;
	}
	return NULL;
}

add_location_datas_t *add_location_datas_copy(add_location_datas_t	*dst,
                                              add_location_datas_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = add_location_datas_convertToJSON(src);
	if(!item) {
		printf("add_location_datas_convertToJSON() failed");
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

	add_location_datas_free(dst);
	dst = add_location_datas_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
