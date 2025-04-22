#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wlan_per_ss_id_performance_info.h"

wlan_per_ss_id_performance_info_t *wlan_per_ss_id_performance_info_create(
	char *ss_id, list_t *wlan_per_ts_infos) {
	wlan_per_ss_id_performance_info_t *
	        wlan_per_ss_id_performance_info_local_var =
		malloc(sizeof(wlan_per_ss_id_performance_info_t));

	wlan_per_ss_id_performance_info_local_var->ss_id = ss_id;
	wlan_per_ss_id_performance_info_local_var->wlan_per_ts_infos =
		wlan_per_ts_infos;

	return wlan_per_ss_id_performance_info_local_var;
}

void wlan_per_ss_id_performance_info_free(
	wlan_per_ss_id_performance_info_t *wlan_per_ss_id_performance_info) {
	lnode_t *node = NULL;

	if(NULL == wlan_per_ss_id_performance_info) {
		return;
	}
	if(wlan_per_ss_id_performance_info->ss_id) {
		free(wlan_per_ss_id_performance_info->ss_id);
		wlan_per_ss_id_performance_info->ss_id = NULL;
	}
	if(wlan_per_ss_id_performance_info->wlan_per_ts_infos) {
		list_for_each(
			wlan_per_ss_id_performance_info->wlan_per_ts_infos,
			node) {
			wlan_per_ts_performance_info_free(node->data);
		}
		list_free(wlan_per_ss_id_performance_info->wlan_per_ts_infos);
		wlan_per_ss_id_performance_info->wlan_per_ts_infos = NULL;
	}
	free(wlan_per_ss_id_performance_info);
}

cJSON *wlan_per_ss_id_performance_info_convertToJSON(
	wlan_per_ss_id_performance_info_t *wlan_per_ss_id_performance_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(wlan_per_ss_id_performance_info == NULL) {
		printf(
			"wlan_per_ss_id_performance_info_convertToJSON() failed [WlanPerSsIdPerformanceInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!wlan_per_ss_id_performance_info->ss_id) {
		printf(
			"wlan_per_ss_id_performance_info_convertToJSON() failed [ss_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ssId",
	                           wlan_per_ss_id_performance_info->ss_id) ==
	   NULL)
	{
		printf(
			"wlan_per_ss_id_performance_info_convertToJSON() failed [ss_id]");
		goto end;
	}

	if(!wlan_per_ss_id_performance_info->wlan_per_ts_infos) {
		printf(
			"wlan_per_ss_id_performance_info_convertToJSON() failed [wlan_per_ts_infos]");
		return NULL;
	}
	cJSON *wlan_per_ts_infosList = cJSON_AddArrayToObject(item,
	                                                      "wlanPerTsInfos");
	if(wlan_per_ts_infosList == NULL) {
		printf(
			"wlan_per_ss_id_performance_info_convertToJSON() failed [wlan_per_ts_infos]");
		goto end;
	}
	list_for_each(wlan_per_ss_id_performance_info->wlan_per_ts_infos,
	              node) {
		cJSON *itemLocal = wlan_per_ts_performance_info_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf(
				"wlan_per_ss_id_performance_info_convertToJSON() failed [wlan_per_ts_infos]");
			goto end;
		}
		cJSON_AddItemToArray(wlan_per_ts_infosList, itemLocal);
	}

end:
	return item;
}

wlan_per_ss_id_performance_info_t *wlan_per_ss_id_performance_info_parseFromJSON(
	cJSON *wlan_per_ss_id_performance_infoJSON) {
	wlan_per_ss_id_performance_info_t *
	        wlan_per_ss_id_performance_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ss_id = NULL;
	cJSON *wlan_per_ts_infos = NULL;
	list_t *wlan_per_ts_infosList = NULL;
	ss_id = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ss_id_performance_infoJSON, "ssId");
	if(!ss_id) {
		printf(
			"wlan_per_ss_id_performance_info_parseFromJSON() failed [ss_id]");
		goto end;
	}
	if(!cJSON_IsString(ss_id)) {
		printf(
			"wlan_per_ss_id_performance_info_parseFromJSON() failed [ss_id]");
		goto end;
	}

	wlan_per_ts_infos = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ss_id_performance_infoJSON, "wlanPerTsInfos");
	if(!wlan_per_ts_infos) {
		printf(
			"wlan_per_ss_id_performance_info_parseFromJSON() failed [wlan_per_ts_infos]");
		goto end;
	}
	cJSON *wlan_per_ts_infos_local = NULL;
	if(!cJSON_IsArray(wlan_per_ts_infos)) {
		printf(
			"wlan_per_ss_id_performance_info_parseFromJSON() failed [wlan_per_ts_infos]");
		goto end;
	}

	wlan_per_ts_infosList = list_create();

	cJSON_ArrayForEach(wlan_per_ts_infos_local, wlan_per_ts_infos) {
		if(!cJSON_IsObject(wlan_per_ts_infos_local)) {
			printf(
				"wlan_per_ss_id_performance_info_parseFromJSON() failed [wlan_per_ts_infos]");
			goto end;
		}
		wlan_per_ts_performance_info_t *wlan_per_ts_infosItem =
			wlan_per_ts_performance_info_parseFromJSON(
				wlan_per_ts_infos_local);
		if(!wlan_per_ts_infosItem) {
			printf("No wlan_per_ts_infosItem");
			goto end;
		}
		list_add(wlan_per_ts_infosList, wlan_per_ts_infosItem);
	}

	wlan_per_ss_id_performance_info_local_var =
		wlan_per_ss_id_performance_info_create(
			strdup(ss_id->valuestring),
			wlan_per_ts_infosList
			);

	return wlan_per_ss_id_performance_info_local_var;
end:
	if(wlan_per_ts_infosList) {
		list_for_each(wlan_per_ts_infosList, node) {
			wlan_per_ts_performance_info_free(node->data);
		}
		list_free(wlan_per_ts_infosList);
		wlan_per_ts_infosList = NULL;
	}
	return NULL;
}

wlan_per_ss_id_performance_info_t *wlan_per_ss_id_performance_info_copy(
	wlan_per_ss_id_performance_info_t	*dst,
	wlan_per_ss_id_performance_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = wlan_per_ss_id_performance_info_convertToJSON(src);
	if(!item) {
		printf("wlan_per_ss_id_performance_info_convertToJSON() failed");
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

	wlan_per_ss_id_performance_info_free(dst);
	dst = wlan_per_ss_id_performance_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
