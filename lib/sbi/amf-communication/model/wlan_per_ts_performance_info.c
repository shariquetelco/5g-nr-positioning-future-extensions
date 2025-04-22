#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wlan_per_ts_performance_info.h"

wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_create(
	char *ts_start, int ts_duration, bool is_rssi, int rssi, bool is_rtt,
	int rtt, traffic_information_t *traffic_info, bool is_number_of_ues,
	int number_of_ues, bool is_confidence, int confidence) {
	wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_local_var =
		malloc(sizeof(wlan_per_ts_performance_info_t));

	wlan_per_ts_performance_info_local_var->ts_start = ts_start;
	wlan_per_ts_performance_info_local_var->ts_duration = ts_duration;
	wlan_per_ts_performance_info_local_var->is_rssi = is_rssi;
	wlan_per_ts_performance_info_local_var->rssi = rssi;
	wlan_per_ts_performance_info_local_var->is_rtt = is_rtt;
	wlan_per_ts_performance_info_local_var->rtt = rtt;
	wlan_per_ts_performance_info_local_var->traffic_info = traffic_info;
	wlan_per_ts_performance_info_local_var->is_number_of_ues =
		is_number_of_ues;
	wlan_per_ts_performance_info_local_var->number_of_ues = number_of_ues;
	wlan_per_ts_performance_info_local_var->is_confidence = is_confidence;
	wlan_per_ts_performance_info_local_var->confidence = confidence;

	return wlan_per_ts_performance_info_local_var;
}

void wlan_per_ts_performance_info_free(
	wlan_per_ts_performance_info_t *wlan_per_ts_performance_info) {
	lnode_t *node = NULL;

	if(NULL == wlan_per_ts_performance_info) {
		return;
	}
	if(wlan_per_ts_performance_info->ts_start) {
		free(wlan_per_ts_performance_info->ts_start);
		wlan_per_ts_performance_info->ts_start = NULL;
	}
	if(wlan_per_ts_performance_info->traffic_info) {
		traffic_information_free(
			wlan_per_ts_performance_info->traffic_info);
		wlan_per_ts_performance_info->traffic_info = NULL;
	}
	free(wlan_per_ts_performance_info);
}

cJSON *wlan_per_ts_performance_info_convertToJSON(
	wlan_per_ts_performance_info_t *wlan_per_ts_performance_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(wlan_per_ts_performance_info == NULL) {
		printf(
			"wlan_per_ts_performance_info_convertToJSON() failed [WlanPerTsPerformanceInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!wlan_per_ts_performance_info->ts_start) {
		printf(
			"wlan_per_ts_performance_info_convertToJSON() failed [ts_start]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "tsStart",
	                           wlan_per_ts_performance_info->ts_start) ==
	   NULL)
	{
		printf(
			"wlan_per_ts_performance_info_convertToJSON() failed [ts_start]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "tsDuration",
	                           wlan_per_ts_performance_info->ts_duration) ==
	   NULL)
	{
		printf(
			"wlan_per_ts_performance_info_convertToJSON() failed [ts_duration]");
		goto end;
	}

	if(wlan_per_ts_performance_info->is_rssi) {
		if(cJSON_AddNumberToObject(item, "rssi",
		                           wlan_per_ts_performance_info->rssi)
		   == NULL)
		{
			printf(
				"wlan_per_ts_performance_info_convertToJSON() failed [rssi]");
			goto end;
		}
	}

	if(wlan_per_ts_performance_info->is_rtt) {
		if(cJSON_AddNumberToObject(item, "rtt",
		                           wlan_per_ts_performance_info->rtt) ==
		   NULL)
		{
			printf(
				"wlan_per_ts_performance_info_convertToJSON() failed [rtt]");
			goto end;
		}
	}

	if(wlan_per_ts_performance_info->traffic_info) {
		cJSON *traffic_info_local_JSON =
			traffic_information_convertToJSON(
				wlan_per_ts_performance_info->traffic_info);
		if(traffic_info_local_JSON == NULL) {
			printf(
				"wlan_per_ts_performance_info_convertToJSON() failed [traffic_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "trafficInfo",
		                      traffic_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"wlan_per_ts_performance_info_convertToJSON() failed [traffic_info]");
			goto end;
		}
	}

	if(wlan_per_ts_performance_info->is_number_of_ues) {
		if(cJSON_AddNumberToObject(item, "numberOfUes",
		                           wlan_per_ts_performance_info->
		                           number_of_ues) == NULL)
		{
			printf(
				"wlan_per_ts_performance_info_convertToJSON() failed [number_of_ues]");
			goto end;
		}
	}

	if(wlan_per_ts_performance_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           wlan_per_ts_performance_info->
		                           confidence) == NULL)
		{
			printf(
				"wlan_per_ts_performance_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_parseFromJSON(
	cJSON *wlan_per_ts_performance_infoJSON) {
	wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *ts_start = NULL;
	cJSON *ts_duration = NULL;
	cJSON *rssi = NULL;
	cJSON *rtt = NULL;
	cJSON *traffic_info = NULL;
	traffic_information_t *traffic_info_local_nonprim = NULL;
	cJSON *number_of_ues = NULL;
	cJSON *confidence = NULL;
	ts_start = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ts_performance_infoJSON, "tsStart");
	if(!ts_start) {
		printf(
			"wlan_per_ts_performance_info_parseFromJSON() failed [ts_start]");
		goto end;
	}
	if(!cJSON_IsString(ts_start) &&
	   !cJSON_IsNull(ts_start))
	{
		printf(
			"wlan_per_ts_performance_info_parseFromJSON() failed [ts_start]");
		goto end;
	}

	ts_duration = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ts_performance_infoJSON, "tsDuration");
	if(!ts_duration) {
		printf(
			"wlan_per_ts_performance_info_parseFromJSON() failed [ts_duration]");
		goto end;
	}
	if(!cJSON_IsNumber(ts_duration)) {
		printf(
			"wlan_per_ts_performance_info_parseFromJSON() failed [ts_duration]");
		goto end;
	}

	rssi = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ts_performance_infoJSON, "rssi");
	if(rssi) {
		if(!cJSON_IsNumber(rssi)) {
			printf(
				"wlan_per_ts_performance_info_parseFromJSON() failed [rssi]");
			goto end;
		}
	}

	rtt = cJSON_GetObjectItemCaseSensitive(wlan_per_ts_performance_infoJSON,
	                                       "rtt");
	if(rtt) {
		if(!cJSON_IsNumber(rtt)) {
			printf(
				"wlan_per_ts_performance_info_parseFromJSON() failed [rtt]");
			goto end;
		}
	}

	traffic_info = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ts_performance_infoJSON, "trafficInfo");
	if(traffic_info) {
		traffic_info_local_nonprim = traffic_information_parseFromJSON(
			traffic_info);
		if(!traffic_info_local_nonprim) {
			printf(
				"traffic_information_parseFromJSON failed [traffic_info]");
			goto end;
		}
	}

	number_of_ues = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ts_performance_infoJSON, "numberOfUes");
	if(number_of_ues) {
		if(!cJSON_IsNumber(number_of_ues)) {
			printf(
				"wlan_per_ts_performance_info_parseFromJSON() failed [number_of_ues]");
			goto end;
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(
		wlan_per_ts_performance_infoJSON, "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"wlan_per_ts_performance_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	wlan_per_ts_performance_info_local_var =
		wlan_per_ts_performance_info_create(
			strdup(ts_start->valuestring),

			ts_duration->valuedouble,
			rssi ? true : false,
			rssi ? rssi->valuedouble : 0,
			rtt ? true : false,
			rtt ? rtt->valuedouble : 0,
			traffic_info ? traffic_info_local_nonprim : NULL,
			number_of_ues ? true : false,
			number_of_ues ? number_of_ues->valuedouble : 0,
			confidence ? true : false,
			confidence ? confidence->valuedouble : 0
			);

	return wlan_per_ts_performance_info_local_var;
end:
	if(traffic_info_local_nonprim) {
		traffic_information_free(traffic_info_local_nonprim);
		traffic_info_local_nonprim = NULL;
	}
	return NULL;
}

wlan_per_ts_performance_info_t *wlan_per_ts_performance_info_copy(
	wlan_per_ts_performance_info_t	*dst,
	wlan_per_ts_performance_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = wlan_per_ts_performance_info_convertToJSON(src);
	if(!item) {
		printf("wlan_per_ts_performance_info_convertToJSON() failed");
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

	wlan_per_ts_performance_info_free(dst);
	dst = wlan_per_ts_performance_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
