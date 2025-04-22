#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "battery_indication.h"

battery_indication_t *battery_indication_create(bool	is_battery_ind,
                                                int	battery_ind,
                                                bool	is_replaceable_ind,
                                                int	replaceable_ind,
                                                bool	is_rechargeable_ind,
                                                int	rechargeable_ind) {
	battery_indication_t *battery_indication_local_var =
		malloc(sizeof(battery_indication_t));

	battery_indication_local_var->is_battery_ind = is_battery_ind;
	battery_indication_local_var->battery_ind = battery_ind;
	battery_indication_local_var->is_replaceable_ind = is_replaceable_ind;
	battery_indication_local_var->replaceable_ind = replaceable_ind;
	battery_indication_local_var->is_rechargeable_ind = is_rechargeable_ind;
	battery_indication_local_var->rechargeable_ind = rechargeable_ind;

	return battery_indication_local_var;
}

void battery_indication_free(battery_indication_t *battery_indication) {
	lnode_t *node = NULL;

	if(NULL == battery_indication) {
		return;
	}
	free(battery_indication);
}

cJSON *battery_indication_convertToJSON(
	battery_indication_t *battery_indication) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(battery_indication == NULL) {
		printf(
			"battery_indication_convertToJSON() failed [BatteryIndication]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(battery_indication->is_battery_ind) {
		if(cJSON_AddBoolToObject(item, "batteryInd",
		                         battery_indication->battery_ind) ==
		   NULL)
		{
			printf(
				"battery_indication_convertToJSON() failed [battery_ind]");
			goto end;
		}
	}

	if(battery_indication->is_replaceable_ind) {
		if(cJSON_AddBoolToObject(item, "replaceableInd",
		                         battery_indication->replaceable_ind) ==
		   NULL)
		{
			printf(
				"battery_indication_convertToJSON() failed [replaceable_ind]");
			goto end;
		}
	}

	if(battery_indication->is_rechargeable_ind) {
		if(cJSON_AddBoolToObject(item, "rechargeableInd",
		                         battery_indication->rechargeable_ind)
		   == NULL)
		{
			printf(
				"battery_indication_convertToJSON() failed [rechargeable_ind]");
			goto end;
		}
	}

end:
	return item;
}

battery_indication_t *battery_indication_parseFromJSON(
	cJSON *battery_indicationJSON) {
	battery_indication_t *battery_indication_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *battery_ind = NULL;
	cJSON *replaceable_ind = NULL;
	cJSON *rechargeable_ind = NULL;
	battery_ind = cJSON_GetObjectItemCaseSensitive(battery_indicationJSON,
	                                               "batteryInd");
	if(battery_ind) {
		if(!cJSON_IsBool(battery_ind)) {
			printf(
				"battery_indication_parseFromJSON() failed [battery_ind]");
			goto end;
		}
	}

	replaceable_ind = cJSON_GetObjectItemCaseSensitive(
		battery_indicationJSON, "replaceableInd");
	if(replaceable_ind) {
		if(!cJSON_IsBool(replaceable_ind)) {
			printf(
				"battery_indication_parseFromJSON() failed [replaceable_ind]");
			goto end;
		}
	}

	rechargeable_ind = cJSON_GetObjectItemCaseSensitive(
		battery_indicationJSON, "rechargeableInd");
	if(rechargeable_ind) {
		if(!cJSON_IsBool(rechargeable_ind)) {
			printf(
				"battery_indication_parseFromJSON() failed [rechargeable_ind]");
			goto end;
		}
	}

	battery_indication_local_var = battery_indication_create(
		battery_ind ? true : false,
		battery_ind ? battery_ind->valueint : 0,
		replaceable_ind ? true : false,
		replaceable_ind ? replaceable_ind->valueint : 0,
		rechargeable_ind ? true : false,
		rechargeable_ind ? rechargeable_ind->valueint : 0
		);

	return battery_indication_local_var;
end:
	return NULL;
}

battery_indication_t *battery_indication_copy(battery_indication_t	*dst,
                                              battery_indication_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = battery_indication_convertToJSON(src);
	if(!item) {
		printf("battery_indication_convertToJSON() failed");
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

	battery_indication_free(dst);
	dst = battery_indication_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
