#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "traffic_information.h"

traffic_information_t *traffic_information_create(char	*uplink_rate,
                                                  char	*downlink_rate,
                                                  bool	is_uplink_volume,
                                                  long	uplink_volume,
                                                  bool	is_downlink_volume,
                                                  long	downlink_volume,
                                                  bool	is_total_volume,
                                                  long	total_volume) {
	traffic_information_t *traffic_information_local_var =
		malloc(sizeof(traffic_information_t));

	traffic_information_local_var->uplink_rate = uplink_rate;
	traffic_information_local_var->downlink_rate = downlink_rate;
	traffic_information_local_var->is_uplink_volume = is_uplink_volume;
	traffic_information_local_var->uplink_volume = uplink_volume;
	traffic_information_local_var->is_downlink_volume = is_downlink_volume;
	traffic_information_local_var->downlink_volume = downlink_volume;
	traffic_information_local_var->is_total_volume = is_total_volume;
	traffic_information_local_var->total_volume = total_volume;

	return traffic_information_local_var;
}

void traffic_information_free(traffic_information_t *traffic_information) {
	lnode_t *node = NULL;

	if(NULL == traffic_information) {
		return;
	}
	if(traffic_information->uplink_rate) {
		free(traffic_information->uplink_rate);
		traffic_information->uplink_rate = NULL;
	}
	if(traffic_information->downlink_rate) {
		free(traffic_information->downlink_rate);
		traffic_information->downlink_rate = NULL;
	}
	free(traffic_information);
}

cJSON *traffic_information_convertToJSON(
	traffic_information_t *traffic_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(traffic_information == NULL) {
		printf(
			"traffic_information_convertToJSON() failed [TrafficInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(traffic_information->uplink_rate) {
		if(cJSON_AddStringToObject(item, "uplinkRate",
		                           traffic_information->uplink_rate) ==
		   NULL)
		{
			printf(
				"traffic_information_convertToJSON() failed [uplink_rate]");
			goto end;
		}
	}

	if(traffic_information->downlink_rate) {
		if(cJSON_AddStringToObject(item, "downlinkRate",
		                           traffic_information->downlink_rate)
		   == NULL)
		{
			printf(
				"traffic_information_convertToJSON() failed [downlink_rate]");
			goto end;
		}
	}

	if(traffic_information->is_uplink_volume) {
		if(cJSON_AddNumberToObject(item, "uplinkVolume",
		                           traffic_information->uplink_volume)
		   == NULL)
		{
			printf(
				"traffic_information_convertToJSON() failed [uplink_volume]");
			goto end;
		}
	}

	if(traffic_information->is_downlink_volume) {
		if(cJSON_AddNumberToObject(item, "downlinkVolume",
		                           traffic_information->downlink_volume)
		   == NULL)
		{
			printf(
				"traffic_information_convertToJSON() failed [downlink_volume]");
			goto end;
		}
	}

	if(traffic_information->is_total_volume) {
		if(cJSON_AddNumberToObject(item, "totalVolume",
		                           traffic_information->total_volume) ==
		   NULL)
		{
			printf(
				"traffic_information_convertToJSON() failed [total_volume]");
			goto end;
		}
	}

end:
	return item;
}

traffic_information_t *traffic_information_parseFromJSON(
	cJSON *traffic_informationJSON) {
	traffic_information_t *traffic_information_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *uplink_rate = NULL;
	cJSON *downlink_rate = NULL;
	cJSON *uplink_volume = NULL;
	cJSON *downlink_volume = NULL;
	cJSON *total_volume = NULL;
	uplink_rate = cJSON_GetObjectItemCaseSensitive(traffic_informationJSON,
	                                               "uplinkRate");
	if(uplink_rate) {
		if(!cJSON_IsString(uplink_rate) &&
		   !cJSON_IsNull(uplink_rate))
		{
			printf(
				"traffic_information_parseFromJSON() failed [uplink_rate]");
			goto end;
		}
	}

	downlink_rate = cJSON_GetObjectItemCaseSensitive(
		traffic_informationJSON, "downlinkRate");
	if(downlink_rate) {
		if(!cJSON_IsString(downlink_rate) &&
		   !cJSON_IsNull(downlink_rate))
		{
			printf(
				"traffic_information_parseFromJSON() failed [downlink_rate]");
			goto end;
		}
	}

	uplink_volume = cJSON_GetObjectItemCaseSensitive(
		traffic_informationJSON, "uplinkVolume");
	if(uplink_volume) {
		if(!cJSON_IsNumber(uplink_volume)) {
			printf(
				"traffic_information_parseFromJSON() failed [uplink_volume]");
			goto end;
		}
	}

	downlink_volume = cJSON_GetObjectItemCaseSensitive(
		traffic_informationJSON, "downlinkVolume");
	if(downlink_volume) {
		if(!cJSON_IsNumber(downlink_volume)) {
			printf(
				"traffic_information_parseFromJSON() failed [downlink_volume]");
			goto end;
		}
	}

	total_volume = cJSON_GetObjectItemCaseSensitive(traffic_informationJSON,
	                                                "totalVolume");
	if(total_volume) {
		if(!cJSON_IsNumber(total_volume)) {
			printf(
				"traffic_information_parseFromJSON() failed [total_volume]");
			goto end;
		}
	}

	traffic_information_local_var = traffic_information_create(
		uplink_rate &&
		!cJSON_IsNull(uplink_rate) ? strdup(
			uplink_rate->valuestring) : NULL,
		downlink_rate &&
		!cJSON_IsNull(downlink_rate) ? strdup(
			downlink_rate->valuestring) : NULL,
		uplink_volume ? true : false,
		uplink_volume ? uplink_volume->valuedouble : 0,
		downlink_volume ? true : false,
		downlink_volume ? downlink_volume->valuedouble : 0,
		total_volume ? true : false,
		total_volume ? total_volume->valuedouble : 0
		);

	return traffic_information_local_var;
end:
	return NULL;
}

traffic_information_t *traffic_information_copy(traffic_information_t	*dst,
                                                traffic_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = traffic_information_convertToJSON(src);
	if(!item) {
		printf("traffic_information_convertToJSON() failed");
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

	traffic_information_free(dst);
	dst = traffic_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
