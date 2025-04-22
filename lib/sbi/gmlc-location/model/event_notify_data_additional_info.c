#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_notify_data_additional_info.h"

event_notify_data_additional_info_t *event_notify_data_additional_info_create(
	list_t *add_event_data_list) {
	event_notify_data_additional_info_t *
	        event_notify_data_additional_info_local_var =
		malloc(sizeof(event_notify_data_additional_info_t));

	event_notify_data_additional_info_local_var->add_event_data_list =
		add_event_data_list;

	return event_notify_data_additional_info_local_var;
}

void event_notify_data_additional_info_free(
	event_notify_data_additional_info_t *event_notify_data_additional_info)
{
	lnode_t *node = NULL;

	if(NULL == event_notify_data_additional_info) {
		return;
	}
	if(event_notify_data_additional_info->add_event_data_list) {
		list_for_each(
			event_notify_data_additional_info->add_event_data_list,
			node) {
			event_notify_data_free(node->data);
		}
		list_free(event_notify_data_additional_info->add_event_data_list);
		event_notify_data_additional_info->add_event_data_list = NULL;
	}
	free(event_notify_data_additional_info);
}

cJSON *event_notify_data_additional_info_convertToJSON(
	event_notify_data_additional_info_t *event_notify_data_additional_info)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(event_notify_data_additional_info == NULL) {
		printf(
			"event_notify_data_additional_info_convertToJSON() failed [EventNotifyDataAdditionalInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(event_notify_data_additional_info->add_event_data_list) {
		cJSON *add_event_data_listList = cJSON_AddArrayToObject(item,
		                                                        "addEventDataList");
		if(add_event_data_listList == NULL) {
			printf(
				"event_notify_data_additional_info_convertToJSON() failed [add_event_data_list]");
			goto end;
		}
		list_for_each(
			event_notify_data_additional_info->add_event_data_list,
			node) {
			cJSON *itemLocal = event_notify_data_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notify_data_additional_info_convertToJSON() failed [add_event_data_list]");
				goto end;
			}
			cJSON_AddItemToArray(add_event_data_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

event_notify_data_additional_info_t *
event_notify_data_additional_info_parseFromJSON(
	cJSON *event_notify_data_additional_infoJSON) {
	event_notify_data_additional_info_t *
	        event_notify_data_additional_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *add_event_data_list = NULL;
	list_t *add_event_data_listList = NULL;
	add_event_data_list = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_additional_infoJSON, "addEventDataList");
	if(add_event_data_list) {
		cJSON *add_event_data_list_local = NULL;
		if(!cJSON_IsArray(add_event_data_list)) {
			printf(
				"event_notify_data_additional_info_parseFromJSON() failed [add_event_data_list]");
			goto end;
		}

		add_event_data_listList = list_create();

		cJSON_ArrayForEach(add_event_data_list_local,
		                   add_event_data_list) {
			if(!cJSON_IsObject(add_event_data_list_local)) {
				printf(
					"event_notify_data_additional_info_parseFromJSON() failed [add_event_data_list]");
				goto end;
			}
			event_notify_data_t *add_event_data_listItem =
				event_notify_data_parseFromJSON(
					add_event_data_list_local);
			if(!add_event_data_listItem) {
				printf("No add_event_data_listItem");
				goto end;
			}
			list_add(add_event_data_listList,
			         add_event_data_listItem);
		}
	}

	event_notify_data_additional_info_local_var =
		event_notify_data_additional_info_create(
			add_event_data_list ? add_event_data_listList : NULL
			);

	return event_notify_data_additional_info_local_var;
end:
	if(add_event_data_listList) {
		list_for_each(add_event_data_listList, node) {
			event_notify_data_free(node->data);
		}
		list_free(add_event_data_listList);
		add_event_data_listList = NULL;
	}
	return NULL;
}

event_notify_data_additional_info_t *event_notify_data_additional_info_copy(
	event_notify_data_additional_info_t	*dst,
	event_notify_data_additional_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = event_notify_data_additional_info_convertToJSON(src);
	if(!item) {
		printf(
			"event_notify_data_additional_info_convertToJSON() failed");
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

	event_notify_data_additional_info_free(dst);
	dst = event_notify_data_additional_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
