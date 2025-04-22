#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_status_change_notification.h"

amf_status_change_notification_t *amf_status_change_notification_create(
	list_t *amf_status_info_list) {
	amf_status_change_notification_t *
	        amf_status_change_notification_local_var =
		malloc(sizeof(amf_status_change_notification_t));

	amf_status_change_notification_local_var->amf_status_info_list =
		amf_status_info_list;

	return amf_status_change_notification_local_var;
}

void amf_status_change_notification_free(
	amf_status_change_notification_t *amf_status_change_notification) {
	lnode_t *node = NULL;

	if(NULL == amf_status_change_notification) {
		return;
	}
	if(amf_status_change_notification->amf_status_info_list) {
		list_for_each(
			amf_status_change_notification->amf_status_info_list,
			node) {
			amf_status_info_free(node->data);
		}
		list_free(amf_status_change_notification->amf_status_info_list);
		amf_status_change_notification->amf_status_info_list = NULL;
	}
	free(amf_status_change_notification);
}

cJSON *amf_status_change_notification_convertToJSON(
	amf_status_change_notification_t *amf_status_change_notification) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_status_change_notification == NULL) {
		printf(
			"amf_status_change_notification_convertToJSON() failed [AmfStatusChangeNotification]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!amf_status_change_notification->amf_status_info_list) {
		printf(
			"amf_status_change_notification_convertToJSON() failed [amf_status_info_list]");
		return NULL;
	}
	cJSON *amf_status_info_listList = cJSON_AddArrayToObject(item,
	                                                         "amfStatusInfoList");
	if(amf_status_info_listList == NULL) {
		printf(
			"amf_status_change_notification_convertToJSON() failed [amf_status_info_list]");
		goto end;
	}
	list_for_each(amf_status_change_notification->amf_status_info_list,
	              node) {
		cJSON *itemLocal = amf_status_info_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"amf_status_change_notification_convertToJSON() failed [amf_status_info_list]");
			goto end;
		}
		cJSON_AddItemToArray(amf_status_info_listList, itemLocal);
	}

end:
	return item;
}

amf_status_change_notification_t *amf_status_change_notification_parseFromJSON(
	cJSON *amf_status_change_notificationJSON) {
	amf_status_change_notification_t *
	        amf_status_change_notification_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *amf_status_info_list = NULL;
	list_t *amf_status_info_listList = NULL;
	amf_status_info_list = cJSON_GetObjectItemCaseSensitive(
		amf_status_change_notificationJSON, "amfStatusInfoList");
	if(!amf_status_info_list) {
		printf(
			"amf_status_change_notification_parseFromJSON() failed [amf_status_info_list]");
		goto end;
	}
	cJSON *amf_status_info_list_local = NULL;
	if(!cJSON_IsArray(amf_status_info_list)) {
		printf(
			"amf_status_change_notification_parseFromJSON() failed [amf_status_info_list]");
		goto end;
	}

	amf_status_info_listList = list_create();

	cJSON_ArrayForEach(amf_status_info_list_local, amf_status_info_list) {
		if(!cJSON_IsObject(amf_status_info_list_local)) {
			printf(
				"amf_status_change_notification_parseFromJSON() failed [amf_status_info_list]");
			goto end;
		}
		amf_status_info_t *amf_status_info_listItem =
			amf_status_info_parseFromJSON(amf_status_info_list_local);
		if(!amf_status_info_listItem) {
			printf("No amf_status_info_listItem");
			goto end;
		}
		list_add(amf_status_info_listList, amf_status_info_listItem);
	}

	amf_status_change_notification_local_var =
		amf_status_change_notification_create(
			amf_status_info_listList
			);

	return amf_status_change_notification_local_var;
end:
	if(amf_status_info_listList) {
		list_for_each(amf_status_info_listList, node) {
			amf_status_info_free(node->data);
		}
		list_free(amf_status_info_listList);
		amf_status_info_listList = NULL;
	}
	return NULL;
}

amf_status_change_notification_t *amf_status_change_notification_copy(
	amf_status_change_notification_t	*dst,
	amf_status_change_notification_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_status_change_notification_convertToJSON(src);
	if(!item) {
		printf("amf_status_change_notification_convertToJSON() failed");
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

	amf_status_change_notification_free(dst);
	dst = amf_status_change_notification_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
