#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_info_notification_rsp_data.h"

n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_create(
	list_t *sec_rat_data_usage_list) {
	n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_local_var
	        = malloc(sizeof(n2_info_notification_rsp_data_t));

	n2_info_notification_rsp_data_local_var->sec_rat_data_usage_list =
		sec_rat_data_usage_list;

	return n2_info_notification_rsp_data_local_var;
}

void n2_info_notification_rsp_data_free(
	n2_info_notification_rsp_data_t *n2_info_notification_rsp_data) {
	lnode_t *node = NULL;

	if(NULL == n2_info_notification_rsp_data) {
		return;
	}
	if(n2_info_notification_rsp_data->sec_rat_data_usage_list) {
		list_for_each(
			n2_info_notification_rsp_data->sec_rat_data_usage_list,
			node) {
			n2_sm_information_free(node->data);
		}
		list_free(n2_info_notification_rsp_data->sec_rat_data_usage_list);
		n2_info_notification_rsp_data->sec_rat_data_usage_list = NULL;
	}
	free(n2_info_notification_rsp_data);
}

cJSON *n2_info_notification_rsp_data_convertToJSON(
	n2_info_notification_rsp_data_t *n2_info_notification_rsp_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n2_info_notification_rsp_data == NULL) {
		printf(
			"n2_info_notification_rsp_data_convertToJSON() failed [N2InfoNotificationRspData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n2_info_notification_rsp_data->sec_rat_data_usage_list) {
		cJSON *sec_rat_data_usage_listList = cJSON_AddArrayToObject(
			item, "secRatDataUsageList");
		if(sec_rat_data_usage_listList == NULL) {
			printf(
				"n2_info_notification_rsp_data_convertToJSON() failed [sec_rat_data_usage_list]");
			goto end;
		}
		list_for_each(
			n2_info_notification_rsp_data->sec_rat_data_usage_list,
			node) {
			cJSON *itemLocal = n2_sm_information_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"n2_info_notification_rsp_data_convertToJSON() failed [sec_rat_data_usage_list]");
				goto end;
			}
			cJSON_AddItemToArray(sec_rat_data_usage_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_parseFromJSON(
	cJSON *n2_info_notification_rsp_dataJSON) {
	n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_local_var
	        = NULL;
	lnode_t *node = NULL;
	cJSON *sec_rat_data_usage_list = NULL;
	list_t *sec_rat_data_usage_listList = NULL;
	sec_rat_data_usage_list = cJSON_GetObjectItemCaseSensitive(
		n2_info_notification_rsp_dataJSON, "secRatDataUsageList");
	if(sec_rat_data_usage_list) {
		cJSON *sec_rat_data_usage_list_local = NULL;
		if(!cJSON_IsArray(sec_rat_data_usage_list)) {
			printf(
				"n2_info_notification_rsp_data_parseFromJSON() failed [sec_rat_data_usage_list]");
			goto end;
		}

		sec_rat_data_usage_listList = list_create();

		cJSON_ArrayForEach(sec_rat_data_usage_list_local,
		                   sec_rat_data_usage_list) {
			if(!cJSON_IsObject(sec_rat_data_usage_list_local)) {
				printf(
					"n2_info_notification_rsp_data_parseFromJSON() failed [sec_rat_data_usage_list]");
				goto end;
			}
			n2_sm_information_t *sec_rat_data_usage_listItem =
				n2_sm_information_parseFromJSON(
					sec_rat_data_usage_list_local);
			if(!sec_rat_data_usage_listItem) {
				printf("No sec_rat_data_usage_listItem");
				goto end;
			}
			list_add(sec_rat_data_usage_listList,
			         sec_rat_data_usage_listItem);
		}
	}

	n2_info_notification_rsp_data_local_var =
		n2_info_notification_rsp_data_create(
			sec_rat_data_usage_list ? sec_rat_data_usage_listList : NULL
			);

	return n2_info_notification_rsp_data_local_var;
end:
	if(sec_rat_data_usage_listList) {
		list_for_each(sec_rat_data_usage_listList, node) {
			n2_sm_information_free(node->data);
		}
		list_free(sec_rat_data_usage_listList);
		sec_rat_data_usage_listList = NULL;
	}
	return NULL;
}

n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_copy(
	n2_info_notification_rsp_data_t *dst,
	n2_info_notification_rsp_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n2_info_notification_rsp_data_convertToJSON(src);
	if(!item) {
		printf("n2_info_notification_rsp_data_convertToJSON() failed");
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

	n2_info_notification_rsp_data_free(dst);
	dst = n2_info_notification_rsp_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
