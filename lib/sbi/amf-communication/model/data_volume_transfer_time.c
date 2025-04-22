#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_volume_transfer_time.h"

data_volume_transfer_time_t *data_volume_transfer_time_create(
	bool is_uplink_volume, long uplink_volume, bool is_avg_trans_time_ul,
	int avg_trans_time_ul, bool is_var_trans_time_ul,
	float var_trans_time_ul, bool is_downlink_volume, long downlink_volume,
	bool is_avg_trans_time_dl, int avg_trans_time_dl,
	bool is_var_trans_time_dl, float var_trans_time_dl) {
	data_volume_transfer_time_t *data_volume_transfer_time_local_var =
		malloc(sizeof(data_volume_transfer_time_t));

	data_volume_transfer_time_local_var->is_uplink_volume =
		is_uplink_volume;
	data_volume_transfer_time_local_var->uplink_volume = uplink_volume;
	data_volume_transfer_time_local_var->is_avg_trans_time_ul =
		is_avg_trans_time_ul;
	data_volume_transfer_time_local_var->avg_trans_time_ul =
		avg_trans_time_ul;
	data_volume_transfer_time_local_var->is_var_trans_time_ul =
		is_var_trans_time_ul;
	data_volume_transfer_time_local_var->var_trans_time_ul =
		var_trans_time_ul;
	data_volume_transfer_time_local_var->is_downlink_volume =
		is_downlink_volume;
	data_volume_transfer_time_local_var->downlink_volume = downlink_volume;
	data_volume_transfer_time_local_var->is_avg_trans_time_dl =
		is_avg_trans_time_dl;
	data_volume_transfer_time_local_var->avg_trans_time_dl =
		avg_trans_time_dl;
	data_volume_transfer_time_local_var->is_var_trans_time_dl =
		is_var_trans_time_dl;
	data_volume_transfer_time_local_var->var_trans_time_dl =
		var_trans_time_dl;

	return data_volume_transfer_time_local_var;
}

void data_volume_transfer_time_free(
	data_volume_transfer_time_t *data_volume_transfer_time) {
	lnode_t *node = NULL;

	if(NULL == data_volume_transfer_time) {
		return;
	}
	free(data_volume_transfer_time);
}

cJSON *data_volume_transfer_time_convertToJSON(
	data_volume_transfer_time_t *data_volume_transfer_time) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(data_volume_transfer_time == NULL) {
		printf(
			"data_volume_transfer_time_convertToJSON() failed [DataVolumeTransferTime]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(data_volume_transfer_time->is_uplink_volume) {
		if(cJSON_AddNumberToObject(item, "uplinkVolume",
		                           data_volume_transfer_time->
		                           uplink_volume) == NULL)
		{
			printf(
				"data_volume_transfer_time_convertToJSON() failed [uplink_volume]");
			goto end;
		}
	}

	if(data_volume_transfer_time->is_avg_trans_time_ul) {
		if(cJSON_AddNumberToObject(item, "avgTransTimeUl",
		                           data_volume_transfer_time->
		                           avg_trans_time_ul) == NULL)
		{
			printf(
				"data_volume_transfer_time_convertToJSON() failed [avg_trans_time_ul]");
			goto end;
		}
	}

	if(data_volume_transfer_time->is_var_trans_time_ul) {
		if(cJSON_AddNumberToObject(item, "varTransTimeUl",
		                           data_volume_transfer_time->
		                           var_trans_time_ul) == NULL)
		{
			printf(
				"data_volume_transfer_time_convertToJSON() failed [var_trans_time_ul]");
			goto end;
		}
	}

	if(data_volume_transfer_time->is_downlink_volume) {
		if(cJSON_AddNumberToObject(item, "downlinkVolume",
		                           data_volume_transfer_time->
		                           downlink_volume) == NULL)
		{
			printf(
				"data_volume_transfer_time_convertToJSON() failed [downlink_volume]");
			goto end;
		}
	}

	if(data_volume_transfer_time->is_avg_trans_time_dl) {
		if(cJSON_AddNumberToObject(item, "avgTransTimeDl",
		                           data_volume_transfer_time->
		                           avg_trans_time_dl) == NULL)
		{
			printf(
				"data_volume_transfer_time_convertToJSON() failed [avg_trans_time_dl]");
			goto end;
		}
	}

	if(data_volume_transfer_time->is_var_trans_time_dl) {
		if(cJSON_AddNumberToObject(item, "varTransTimeDl",
		                           data_volume_transfer_time->
		                           var_trans_time_dl) == NULL)
		{
			printf(
				"data_volume_transfer_time_convertToJSON() failed [var_trans_time_dl]");
			goto end;
		}
	}

end:
	return item;
}

data_volume_transfer_time_t *data_volume_transfer_time_parseFromJSON(
	cJSON *data_volume_transfer_timeJSON) {
	data_volume_transfer_time_t *data_volume_transfer_time_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *uplink_volume = NULL;
	cJSON *avg_trans_time_ul = NULL;
	cJSON *var_trans_time_ul = NULL;
	cJSON *downlink_volume = NULL;
	cJSON *avg_trans_time_dl = NULL;
	cJSON *var_trans_time_dl = NULL;
	uplink_volume = cJSON_GetObjectItemCaseSensitive(
		data_volume_transfer_timeJSON, "uplinkVolume");
	if(uplink_volume) {
		if(!cJSON_IsNumber(uplink_volume)) {
			printf(
				"data_volume_transfer_time_parseFromJSON() failed [uplink_volume]");
			goto end;
		}
	}

	avg_trans_time_ul = cJSON_GetObjectItemCaseSensitive(
		data_volume_transfer_timeJSON, "avgTransTimeUl");
	if(avg_trans_time_ul) {
		if(!cJSON_IsNumber(avg_trans_time_ul)) {
			printf(
				"data_volume_transfer_time_parseFromJSON() failed [avg_trans_time_ul]");
			goto end;
		}
	}

	var_trans_time_ul = cJSON_GetObjectItemCaseSensitive(
		data_volume_transfer_timeJSON, "varTransTimeUl");
	if(var_trans_time_ul) {
		if(!cJSON_IsNumber(var_trans_time_ul)) {
			printf(
				"data_volume_transfer_time_parseFromJSON() failed [var_trans_time_ul]");
			goto end;
		}
	}

	downlink_volume = cJSON_GetObjectItemCaseSensitive(
		data_volume_transfer_timeJSON, "downlinkVolume");
	if(downlink_volume) {
		if(!cJSON_IsNumber(downlink_volume)) {
			printf(
				"data_volume_transfer_time_parseFromJSON() failed [downlink_volume]");
			goto end;
		}
	}

	avg_trans_time_dl = cJSON_GetObjectItemCaseSensitive(
		data_volume_transfer_timeJSON, "avgTransTimeDl");
	if(avg_trans_time_dl) {
		if(!cJSON_IsNumber(avg_trans_time_dl)) {
			printf(
				"data_volume_transfer_time_parseFromJSON() failed [avg_trans_time_dl]");
			goto end;
		}
	}

	var_trans_time_dl = cJSON_GetObjectItemCaseSensitive(
		data_volume_transfer_timeJSON, "varTransTimeDl");
	if(var_trans_time_dl) {
		if(!cJSON_IsNumber(var_trans_time_dl)) {
			printf(
				"data_volume_transfer_time_parseFromJSON() failed [var_trans_time_dl]");
			goto end;
		}
	}

	data_volume_transfer_time_local_var = data_volume_transfer_time_create(
		uplink_volume ? true : false,
		uplink_volume ? uplink_volume->valuedouble : 0,
		avg_trans_time_ul ? true : false,
		avg_trans_time_ul ? avg_trans_time_ul->valuedouble : 0,
		var_trans_time_ul ? true : false,
		var_trans_time_ul ? var_trans_time_ul->valuedouble : 0,
		downlink_volume ? true : false,
		downlink_volume ? downlink_volume->valuedouble : 0,
		avg_trans_time_dl ? true : false,
		avg_trans_time_dl ? avg_trans_time_dl->valuedouble : 0,
		var_trans_time_dl ? true : false,
		var_trans_time_dl ? var_trans_time_dl->valuedouble : 0
		);

	return data_volume_transfer_time_local_var;
end:
	return NULL;
}

data_volume_transfer_time_t *data_volume_transfer_time_copy(
	data_volume_transfer_time_t *dst, data_volume_transfer_time_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = data_volume_transfer_time_convertToJSON(src);
	if(!item) {
		printf("data_volume_transfer_time_convertToJSON() failed");
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

	data_volume_transfer_time_free(dst);
	dst = data_volume_transfer_time_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
