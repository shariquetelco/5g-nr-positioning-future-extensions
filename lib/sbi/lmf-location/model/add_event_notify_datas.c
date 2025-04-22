#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_event_notify_datas.h"

add_event_notify_datas_t *add_event_notify_datas_create(
	list_t *add_event_notify_datas) {
	add_event_notify_datas_t *add_event_notify_datas_local_var = malloc(
		sizeof(add_event_notify_datas_t));

	add_event_notify_datas_local_var->add_event_notify_datas =
		add_event_notify_datas;

	return add_event_notify_datas_local_var;
}

void add_event_notify_datas_free(
	add_event_notify_datas_t *add_event_notify_datas) {
	lnode_t *node = NULL;

	if(NULL == add_event_notify_datas) {
		return;
	}
	if(add_event_notify_datas->add_event_notify_datas) {
		list_for_each(add_event_notify_datas->add_event_notify_datas,
		              node) {
			event_notify_data_free(node->data);
		}
		list_free(add_event_notify_datas->add_event_notify_datas);
		add_event_notify_datas->add_event_notify_datas = NULL;
	}
	free(add_event_notify_datas);
}

cJSON *add_event_notify_datas_convertToJSON(
	add_event_notify_datas_t *add_event_notify_datas) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(add_event_notify_datas == NULL) {
		printf(
			"add_event_notify_datas_convertToJSON() failed [AddEventNotifyDatas]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(add_event_notify_datas->add_event_notify_datas) {
		cJSON *add_event_notify_datasList = cJSON_AddArrayToObject(item,
		                                                           "addEventNotifyDatas");
		if(add_event_notify_datasList == NULL) {
			printf(
				"add_event_notify_datas_convertToJSON() failed [add_event_notify_datas]");
			goto end;
		}
		list_for_each(add_event_notify_datas->add_event_notify_datas,
		              node) {
			cJSON *itemLocal = event_notify_data_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"add_event_notify_datas_convertToJSON() failed [add_event_notify_datas]");
				goto end;
			}
			cJSON_AddItemToArray(add_event_notify_datasList,
			                     itemLocal);
		}
	}

end:
	return item;
}

add_event_notify_datas_t *add_event_notify_datas_parseFromJSON(
	cJSON *add_event_notify_datasJSON) {
	add_event_notify_datas_t *add_event_notify_datas_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *add_event_notify_datas = NULL;
	list_t *add_event_notify_datasList = NULL;
	add_event_notify_datas = cJSON_GetObjectItemCaseSensitive(
		add_event_notify_datasJSON, "addEventNotifyDatas");
	if(add_event_notify_datas) {
		cJSON *add_event_notify_datas_local = NULL;
		if(!cJSON_IsArray(add_event_notify_datas)) {
			printf(
				"add_event_notify_datas_parseFromJSON() failed [add_event_notify_datas]");
			goto end;
		}

		add_event_notify_datasList = list_create();

		cJSON_ArrayForEach(add_event_notify_datas_local,
		                   add_event_notify_datas) {
			if(!cJSON_IsObject(add_event_notify_datas_local)) {
				printf(
					"add_event_notify_datas_parseFromJSON() failed [add_event_notify_datas]");
				goto end;
			}
			event_notify_data_t *add_event_notify_datasItem =
				event_notify_data_parseFromJSON(
					add_event_notify_datas_local);
			if(!add_event_notify_datasItem) {
				printf("No add_event_notify_datasItem");
				goto end;
			}
			list_add(add_event_notify_datasList,
			         add_event_notify_datasItem);
		}
	}

	add_event_notify_datas_local_var = add_event_notify_datas_create(
		add_event_notify_datas ? add_event_notify_datasList : NULL
		);

	return add_event_notify_datas_local_var;
end:
	if(add_event_notify_datasList) {
		list_for_each(add_event_notify_datasList, node) {
			event_notify_data_free(node->data);
		}
		list_free(add_event_notify_datasList);
		add_event_notify_datasList = NULL;
	}
	return NULL;
}

add_event_notify_datas_t *add_event_notify_datas_copy(
	add_event_notify_datas_t *dst, add_event_notify_datas_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = add_event_notify_datas_convertToJSON(src);
	if(!item) {
		printf("add_event_notify_datas_convertToJSON() failed");
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

	add_event_notify_datas_free(dst);
	dst = add_event_notify_datas_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
