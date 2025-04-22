#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wlan_per_ue_id_performance_info.h"

wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_create(
	char *supi, char *gpsi, list_t *wlan_per_ts_infos) {
	wlan_per_ue_id_performance_info_t *
	        wlan_per_ue_id_performance_info_local_var =
		malloc(sizeof(wlan_per_ue_id_performance_info_t));

	wlan_per_ue_id_performance_info_local_var->supi = supi;
	wlan_per_ue_id_performance_info_local_var->gpsi = gpsi;
	wlan_per_ue_id_performance_info_local_var->wlan_per_ts_infos =
		wlan_per_ts_infos;

	return wlan_per_ue_id_performance_info_local_var;
}

void wlan_per_ue_id_performance_info_free(
	wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info) {
	lnode_t *node = NULL;

	if(NULL == wlan_per_ue_id_performance_info) {
		return;
	}
	if(wlan_per_ue_id_performance_info->supi) {
		free(wlan_per_ue_id_performance_info->supi);
		wlan_per_ue_id_performance_info->supi = NULL;
	}
	if(wlan_per_ue_id_performance_info->gpsi) {
		free(wlan_per_ue_id_performance_info->gpsi);
		wlan_per_ue_id_performance_info->gpsi = NULL;
	}
	if(wlan_per_ue_id_performance_info->wlan_per_ts_infos) {
		list_for_each(
			wlan_per_ue_id_performance_info->wlan_per_ts_infos,
			node) {
			wlan_per_ts_performance_info_free(node->data);
		}
		list_free(wlan_per_ue_id_performance_info->wlan_per_ts_infos);
		wlan_per_ue_id_performance_info->wlan_per_ts_infos = NULL;
	}
	free(wlan_per_ue_id_performance_info);
}

cJSON *wlan_per_ue_id_performance_info_convertToJSON(
	wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(wlan_per_ue_id_performance_info == NULL) {
		printf(
			"wlan_per_ue_id_performance_info_convertToJSON() failed [WlanPerUeIdPerformanceInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(wlan_per_ue_id_performance_info->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           wlan_per_ue_id_performance_info->supi)
		   == NULL)
		{
			printf(
				"wlan_per_ue_id_performance_info_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(wlan_per_ue_id_performance_info->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           wlan_per_ue_id_performance_info->gpsi)
		   == NULL)
		{
			printf(
				"wlan_per_ue_id_performance_info_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(!wlan_per_ue_id_performance_info->wlan_per_ts_infos) {
		printf(
			"wlan_per_ue_id_performance_info_convertToJSON() failed [wlan_per_ts_infos]");
		return NULL;
	}
	cJSON *wlan_per_ts_infosList = cJSON_AddArrayToObject(item,
	                                                      "wlanPerTsInfos");
	if(wlan_per_ts_infosList == NULL) {
		printf(
			"wlan_per_ue_id_performance_info_convertToJSON() failed [wlan_per_ts_infos]");
		goto end;
	}
	list_for_each(wlan_per_ue_id_performance_info->wlan_per_ts_infos,
	              node) {
		cJSON *itemLocal = wlan_per_ts_performance_info_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf(
				"wlan_per_ue_id_performance_info_convertToJSON() failed [wlan_per_ts_infos]");
			goto end;
		}
		cJSON_AddItemToArray(wlan_per_ts_infosList, itemLocal);
	}

end:
	return item;
}

wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_parseFromJSON(
	cJSON *wlan_per_ue_id_performance_infoJSON) {
	wlan_per_ue_id_performance_info_t *
	        wlan_per_ue_id_performance_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	cJSON *wlan_per_ts_infos = NULL;
	list_t *wlan_per_ts_infosList = NULL;
	supi = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ue_id_performance_infoJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf(
				"wlan_per_ue_id_performance_info_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ue_id_performance_infoJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf(
				"wlan_per_ue_id_performance_info_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	wlan_per_ts_infos = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ue_id_performance_infoJSON, "wlanPerTsInfos");
	if(!wlan_per_ts_infos) {
		printf(
			"wlan_per_ue_id_performance_info_parseFromJSON() failed [wlan_per_ts_infos]");
		goto end;
	}
	cJSON *wlan_per_ts_infos_local = NULL;
	if(!cJSON_IsArray(wlan_per_ts_infos)) {
		printf(
			"wlan_per_ue_id_performance_info_parseFromJSON() failed [wlan_per_ts_infos]");
		goto end;
	}

	wlan_per_ts_infosList = list_create();

	cJSON_ArrayForEach(wlan_per_ts_infos_local, wlan_per_ts_infos) {
		if(!cJSON_IsObject(wlan_per_ts_infos_local)) {
			printf(
				"wlan_per_ue_id_performance_info_parseFromJSON() failed [wlan_per_ts_infos]");
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

	wlan_per_ue_id_performance_info_local_var =
		wlan_per_ue_id_performance_info_create(
			supi &&
			!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
			gpsi &&
			!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
			wlan_per_ts_infosList
			);

	return wlan_per_ue_id_performance_info_local_var;
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

wlan_per_ue_id_performance_info_t *wlan_per_ue_id_performance_info_copy(
	wlan_per_ue_id_performance_info_t	*dst,
	wlan_per_ue_id_performance_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = wlan_per_ue_id_performance_info_convertToJSON(src);
	if(!item) {
		printf("wlan_per_ue_id_performance_info_convertToJSON() failed");
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

	wlan_per_ue_id_performance_info_free(dst);
	dst = wlan_per_ue_id_performance_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
