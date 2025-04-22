#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wlan_performance_info.h"

wlan_performance_info_t *wlan_performance_info_create(
	network_area_info_t *network_area, list_t *wlan_per_ssid_infos,
	list_t *wlan_per_ue_id_infos) {
	wlan_performance_info_t *wlan_performance_info_local_var = malloc(
		sizeof(wlan_performance_info_t));

	wlan_performance_info_local_var->network_area = network_area;
	wlan_performance_info_local_var->wlan_per_ssid_infos =
		wlan_per_ssid_infos;
	wlan_performance_info_local_var->wlan_per_ue_id_infos =
		wlan_per_ue_id_infos;

	return wlan_performance_info_local_var;
}

void wlan_performance_info_free(wlan_performance_info_t *wlan_performance_info)
{
	lnode_t *node = NULL;

	if(NULL == wlan_performance_info) {
		return;
	}
	if(wlan_performance_info->network_area) {
		network_area_info_free(wlan_performance_info->network_area);
		wlan_performance_info->network_area = NULL;
	}
	if(wlan_performance_info->wlan_per_ssid_infos) {
		list_for_each(wlan_performance_info->wlan_per_ssid_infos,
		              node) {
			wlan_per_ss_id_performance_info_free(node->data);
		}
		list_free(wlan_performance_info->wlan_per_ssid_infos);
		wlan_performance_info->wlan_per_ssid_infos = NULL;
	}
	if(wlan_performance_info->wlan_per_ue_id_infos) {
		list_for_each(wlan_performance_info->wlan_per_ue_id_infos,
		              node) {
			wlan_per_ue_id_performance_info_free(node->data);
		}
		list_free(wlan_performance_info->wlan_per_ue_id_infos);
		wlan_performance_info->wlan_per_ue_id_infos = NULL;
	}
	free(wlan_performance_info);
}

cJSON *wlan_performance_info_convertToJSON(
	wlan_performance_info_t *wlan_performance_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(wlan_performance_info == NULL) {
		printf(
			"wlan_performance_info_convertToJSON() failed [WlanPerformanceInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(wlan_performance_info->network_area) {
		cJSON *network_area_local_JSON =
			network_area_info_convertToJSON(
				wlan_performance_info->network_area);
		if(network_area_local_JSON == NULL) {
			printf(
				"wlan_performance_info_convertToJSON() failed [network_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "networkArea",
		                      network_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"wlan_performance_info_convertToJSON() failed [network_area]");
			goto end;
		}
	}

	if(!wlan_performance_info->wlan_per_ssid_infos) {
		printf(
			"wlan_performance_info_convertToJSON() failed [wlan_per_ssid_infos]");
		return NULL;
	}
	cJSON *wlan_per_ssid_infosList = cJSON_AddArrayToObject(item,
	                                                        "wlanPerSsidInfos");
	if(wlan_per_ssid_infosList == NULL) {
		printf(
			"wlan_performance_info_convertToJSON() failed [wlan_per_ssid_infos]");
		goto end;
	}
	list_for_each(wlan_performance_info->wlan_per_ssid_infos, node) {
		cJSON *itemLocal =
			wlan_per_ss_id_performance_info_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"wlan_performance_info_convertToJSON() failed [wlan_per_ssid_infos]");
			goto end;
		}
		cJSON_AddItemToArray(wlan_per_ssid_infosList, itemLocal);
	}

	if(wlan_performance_info->wlan_per_ue_id_infos) {
		cJSON *wlan_per_ue_id_infosList = cJSON_AddArrayToObject(item,
		                                                         "wlanPerUeIdInfos");
		if(wlan_per_ue_id_infosList == NULL) {
			printf(
				"wlan_performance_info_convertToJSON() failed [wlan_per_ue_id_infos]");
			goto end;
		}
		list_for_each(wlan_performance_info->wlan_per_ue_id_infos,
		              node) {
			cJSON *itemLocal =
				wlan_per_ue_id_performance_info_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"wlan_performance_info_convertToJSON() failed [wlan_per_ue_id_infos]");
				goto end;
			}
			cJSON_AddItemToArray(wlan_per_ue_id_infosList,
			                     itemLocal);
		}
	}

end:
	return item;
}

wlan_performance_info_t *wlan_performance_info_parseFromJSON(
	cJSON *wlan_performance_infoJSON) {
	wlan_performance_info_t *wlan_performance_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *network_area = NULL;
	network_area_info_t *network_area_local_nonprim = NULL;
	cJSON *wlan_per_ssid_infos = NULL;
	list_t *wlan_per_ssid_infosList = NULL;
	cJSON *wlan_per_ue_id_infos = NULL;
	list_t *wlan_per_ue_id_infosList = NULL;
	network_area = cJSON_GetObjectItemCaseSensitive(
		wlan_performance_infoJSON, "networkArea");
	if(network_area) {
		network_area_local_nonprim = network_area_info_parseFromJSON(
			network_area);
		if(!network_area_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [network_area]");
			goto end;
		}
	}

	wlan_per_ssid_infos = cJSON_GetObjectItemCaseSensitive(
		wlan_performance_infoJSON, "wlanPerSsidInfos");
	if(!wlan_per_ssid_infos) {
		printf(
			"wlan_performance_info_parseFromJSON() failed [wlan_per_ssid_infos]");
		goto end;
	}
	cJSON *wlan_per_ssid_infos_local = NULL;
	if(!cJSON_IsArray(wlan_per_ssid_infos)) {
		printf(
			"wlan_performance_info_parseFromJSON() failed [wlan_per_ssid_infos]");
		goto end;
	}

	wlan_per_ssid_infosList = list_create();

	cJSON_ArrayForEach(wlan_per_ssid_infos_local, wlan_per_ssid_infos) {
		if(!cJSON_IsObject(wlan_per_ssid_infos_local)) {
			printf(
				"wlan_performance_info_parseFromJSON() failed [wlan_per_ssid_infos]");
			goto end;
		}
		wlan_per_ss_id_performance_info_t *wlan_per_ssid_infosItem =
			wlan_per_ss_id_performance_info_parseFromJSON(
				wlan_per_ssid_infos_local);
		if(!wlan_per_ssid_infosItem) {
			printf("No wlan_per_ssid_infosItem");
			goto end;
		}
		list_add(wlan_per_ssid_infosList, wlan_per_ssid_infosItem);
	}

	wlan_per_ue_id_infos = cJSON_GetObjectItemCaseSensitive(
		wlan_performance_infoJSON, "wlanPerUeIdInfos");
	if(wlan_per_ue_id_infos) {
		cJSON *wlan_per_ue_id_infos_local = NULL;
		if(!cJSON_IsArray(wlan_per_ue_id_infos)) {
			printf(
				"wlan_performance_info_parseFromJSON() failed [wlan_per_ue_id_infos]");
			goto end;
		}

		wlan_per_ue_id_infosList = list_create();

		cJSON_ArrayForEach(wlan_per_ue_id_infos_local,
		                   wlan_per_ue_id_infos) {
			if(!cJSON_IsObject(wlan_per_ue_id_infos_local)) {
				printf(
					"wlan_performance_info_parseFromJSON() failed [wlan_per_ue_id_infos]");
				goto end;
			}
			wlan_per_ue_id_performance_info_t *
			        wlan_per_ue_id_infosItem =
				wlan_per_ue_id_performance_info_parseFromJSON(
					wlan_per_ue_id_infos_local);
			if(!wlan_per_ue_id_infosItem) {
				printf("No wlan_per_ue_id_infosItem");
				goto end;
			}
			list_add(wlan_per_ue_id_infosList,
			         wlan_per_ue_id_infosItem);
		}
	}

	wlan_performance_info_local_var = wlan_performance_info_create(
		network_area ? network_area_local_nonprim : NULL,
		wlan_per_ssid_infosList,
		wlan_per_ue_id_infos ? wlan_per_ue_id_infosList : NULL
		);

	return wlan_performance_info_local_var;
end:
	if(network_area_local_nonprim) {
		network_area_info_free(network_area_local_nonprim);
		network_area_local_nonprim = NULL;
	}
	if(wlan_per_ssid_infosList) {
		list_for_each(wlan_per_ssid_infosList, node) {
			wlan_per_ss_id_performance_info_free(node->data);
		}
		list_free(wlan_per_ssid_infosList);
		wlan_per_ssid_infosList = NULL;
	}
	if(wlan_per_ue_id_infosList) {
		list_for_each(wlan_per_ue_id_infosList, node) {
			wlan_per_ue_id_performance_info_free(node->data);
		}
		list_free(wlan_per_ue_id_infosList);
		wlan_per_ue_id_infosList = NULL;
	}
	return NULL;
}

wlan_performance_info_t *wlan_performance_info_copy(
	wlan_performance_info_t *dst, wlan_performance_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = wlan_performance_info_convertToJSON(src);
	if(!item) {
		printf("wlan_performance_info_convertToJSON() failed");
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

	wlan_performance_info_free(dst);
	dst = wlan_performance_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
