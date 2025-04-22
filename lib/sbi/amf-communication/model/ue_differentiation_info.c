#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_differentiation_info.h"

ue_differentiation_info_t *ue_differentiation_info_create(
	periodic_communication_indicator_e periodic_com_ind,
	bool is_periodic_time, int periodic_time,
	scheduled_communication_time_t *scheduled_com_time,
	stationary_indication_t *stationary_ind,
	traffic_profile_t *traffic_profile, battery_indication_t *battery_ind,
	char *validity_time) {
	ue_differentiation_info_t *ue_differentiation_info_local_var = malloc(
		sizeof(ue_differentiation_info_t));

	ue_differentiation_info_local_var->periodic_com_ind = periodic_com_ind;
	ue_differentiation_info_local_var->is_periodic_time = is_periodic_time;
	ue_differentiation_info_local_var->periodic_time = periodic_time;
	ue_differentiation_info_local_var->scheduled_com_time =
		scheduled_com_time;
	ue_differentiation_info_local_var->stationary_ind = stationary_ind;
	ue_differentiation_info_local_var->traffic_profile = traffic_profile;
	ue_differentiation_info_local_var->battery_ind = battery_ind;
	ue_differentiation_info_local_var->validity_time = validity_time;

	return ue_differentiation_info_local_var;
}

void ue_differentiation_info_free(
	ue_differentiation_info_t *ue_differentiation_info) {
	lnode_t *node = NULL;

	if(NULL == ue_differentiation_info) {
		return;
	}
	if(ue_differentiation_info->scheduled_com_time) {
		scheduled_communication_time_free(
			ue_differentiation_info->scheduled_com_time);
		ue_differentiation_info->scheduled_com_time = NULL;
	}
	if(ue_differentiation_info->stationary_ind) {
		stationary_indication_free(
			ue_differentiation_info->stationary_ind);
		ue_differentiation_info->stationary_ind = NULL;
	}
	if(ue_differentiation_info->traffic_profile) {
		traffic_profile_free(ue_differentiation_info->traffic_profile);
		ue_differentiation_info->traffic_profile = NULL;
	}
	if(ue_differentiation_info->battery_ind) {
		battery_indication_free(ue_differentiation_info->battery_ind);
		ue_differentiation_info->battery_ind = NULL;
	}
	if(ue_differentiation_info->validity_time) {
		free(ue_differentiation_info->validity_time);
		ue_differentiation_info->validity_time = NULL;
	}
	free(ue_differentiation_info);
}

cJSON *ue_differentiation_info_convertToJSON(
	ue_differentiation_info_t *ue_differentiation_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_differentiation_info == NULL) {
		printf(
			"ue_differentiation_info_convertToJSON() failed [UeDifferentiationInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_differentiation_info->periodic_com_ind !=
	   periodic_communication_indicator_NULL)
	{
		if(cJSON_AddStringToObject(item, "periodicComInd",
		                           periodic_communication_indicator_ToString(
						   ue_differentiation_info->
						   periodic_com_ind)) == NULL)
		{
			printf(
				"ue_differentiation_info_convertToJSON() failed [periodic_com_ind]");
			goto end;
		}
	}

	if(ue_differentiation_info->is_periodic_time) {
		if(cJSON_AddNumberToObject(item, "periodicTime",
		                           ue_differentiation_info->
		                           periodic_time) == NULL)
		{
			printf(
				"ue_differentiation_info_convertToJSON() failed [periodic_time]");
			goto end;
		}
	}

	if(ue_differentiation_info->scheduled_com_time) {
		cJSON *scheduled_com_time_local_JSON =
			scheduled_communication_time_convertToJSON(
				ue_differentiation_info->scheduled_com_time);
		if(scheduled_com_time_local_JSON == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [scheduled_com_time]");
			goto end;
		}
		cJSON_AddItemToObject(item, "scheduledComTime",
		                      scheduled_com_time_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [scheduled_com_time]");
			goto end;
		}
	}

	if(ue_differentiation_info->stationary_ind) {
		cJSON *stationary_ind_local_JSON =
			stationary_indication_convertToJSON(
				ue_differentiation_info->stationary_ind);
		if(stationary_ind_local_JSON == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [stationary_ind]");
			goto end;
		}
		cJSON_AddItemToObject(item, "stationaryInd",
		                      stationary_ind_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [stationary_ind]");
			goto end;
		}
	}

	if(ue_differentiation_info->traffic_profile) {
		cJSON *traffic_profile_local_JSON =
			traffic_profile_convertToJSON(
				ue_differentiation_info->traffic_profile);
		if(traffic_profile_local_JSON == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [traffic_profile]");
			goto end;
		}
		cJSON_AddItemToObject(item, "trafficProfile",
		                      traffic_profile_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [traffic_profile]");
			goto end;
		}
	}

	if(ue_differentiation_info->battery_ind) {
		cJSON *battery_ind_local_JSON =
			battery_indication_convertToJSON(
				ue_differentiation_info->battery_ind);
		if(battery_ind_local_JSON == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [battery_ind]");
			goto end;
		}
		cJSON_AddItemToObject(item, "batteryInd",
		                      battery_ind_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_differentiation_info_convertToJSON() failed [battery_ind]");
			goto end;
		}
	}

	if(ue_differentiation_info->validity_time) {
		if(cJSON_AddStringToObject(item, "validityTime",
		                           ue_differentiation_info->
		                           validity_time) == NULL)
		{
			printf(
				"ue_differentiation_info_convertToJSON() failed [validity_time]");
			goto end;
		}
	}

end:
	return item;
}

ue_differentiation_info_t *ue_differentiation_info_parseFromJSON(
	cJSON *ue_differentiation_infoJSON) {
	ue_differentiation_info_t *ue_differentiation_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *periodic_com_ind = NULL;
	periodic_communication_indicator_e periodic_com_indVariable = 0;
	cJSON *periodic_time = NULL;
	cJSON *scheduled_com_time = NULL;
	scheduled_communication_time_t *scheduled_com_time_local_nonprim = NULL;
	cJSON *stationary_ind = NULL;
	stationary_indication_t *stationary_ind_local_nonprim = NULL;
	cJSON *traffic_profile = NULL;
	traffic_profile_t *traffic_profile_local_nonprim = NULL;
	cJSON *battery_ind = NULL;
	battery_indication_t *battery_ind_local_nonprim = NULL;
	cJSON *validity_time = NULL;
	periodic_com_ind = cJSON_GetObjectItemCaseSensitive(
		ue_differentiation_infoJSON, "periodicComInd");
	if(periodic_com_ind) {
		if(!cJSON_IsString(periodic_com_ind)) {
			printf(
				"ue_differentiation_info_parseFromJSON() failed [periodic_com_ind]");
			goto end;
		}
		periodic_com_indVariable =
			periodic_communication_indicator_FromString(
				periodic_com_ind->valuestring);
	}

	periodic_time = cJSON_GetObjectItemCaseSensitive(
		ue_differentiation_infoJSON, "periodicTime");
	if(periodic_time) {
		if(!cJSON_IsNumber(periodic_time)) {
			printf(
				"ue_differentiation_info_parseFromJSON() failed [periodic_time]");
			goto end;
		}
	}

	scheduled_com_time = cJSON_GetObjectItemCaseSensitive(
		ue_differentiation_infoJSON, "scheduledComTime");
	if(scheduled_com_time) {
		scheduled_com_time_local_nonprim =
			scheduled_communication_time_parseFromJSON(
				scheduled_com_time);
		if(!scheduled_com_time_local_nonprim) {
			printf(
				"scheduled_communication_time_parseFromJSON failed [scheduled_com_time]");
			goto end;
		}
	}

	stationary_ind = cJSON_GetObjectItemCaseSensitive(
		ue_differentiation_infoJSON, "stationaryInd");
	if(stationary_ind) {
		stationary_ind_local_nonprim =
			stationary_indication_parseFromJSON(stationary_ind);
		if(!stationary_ind_local_nonprim) {
			printf(
				"stationary_indication_parseFromJSON failed [stationary_ind]");
			goto end;
		}
	}

	traffic_profile = cJSON_GetObjectItemCaseSensitive(
		ue_differentiation_infoJSON, "trafficProfile");
	if(traffic_profile) {
		traffic_profile_local_nonprim = traffic_profile_parseFromJSON(
			traffic_profile);
		if(!traffic_profile_local_nonprim) {
			printf(
				"traffic_profile_parseFromJSON failed [traffic_profile]");
			goto end;
		}
	}

	battery_ind = cJSON_GetObjectItemCaseSensitive(
		ue_differentiation_infoJSON, "batteryInd");
	if(battery_ind) {
		battery_ind_local_nonprim = battery_indication_parseFromJSON(
			battery_ind);
		if(!battery_ind_local_nonprim) {
			printf(
				"battery_indication_parseFromJSON failed [battery_ind]");
			goto end;
		}
	}

	validity_time = cJSON_GetObjectItemCaseSensitive(
		ue_differentiation_infoJSON, "validityTime");
	if(validity_time) {
		if(!cJSON_IsString(validity_time) &&
		   !cJSON_IsNull(validity_time))
		{
			printf(
				"ue_differentiation_info_parseFromJSON() failed [validity_time]");
			goto end;
		}
	}

	ue_differentiation_info_local_var = ue_differentiation_info_create(
		periodic_com_ind ? periodic_com_indVariable : 0,
		periodic_time ? true : false,
		periodic_time ? periodic_time->valuedouble : 0,
		scheduled_com_time ? scheduled_com_time_local_nonprim : NULL,
		stationary_ind ? stationary_ind_local_nonprim : NULL,
		traffic_profile ? traffic_profile_local_nonprim : NULL,
		battery_ind ? battery_ind_local_nonprim : NULL,
		validity_time &&
		!cJSON_IsNull(validity_time) ? strdup(
			validity_time->valuestring) : NULL
		);

	return ue_differentiation_info_local_var;
end:
	if(scheduled_com_time_local_nonprim) {
		scheduled_communication_time_free(
			scheduled_com_time_local_nonprim);
		scheduled_com_time_local_nonprim = NULL;
	}
	if(stationary_ind_local_nonprim) {
		stationary_indication_free(stationary_ind_local_nonprim);
		stationary_ind_local_nonprim = NULL;
	}
	if(traffic_profile_local_nonprim) {
		traffic_profile_free(traffic_profile_local_nonprim);
		traffic_profile_local_nonprim = NULL;
	}
	if(battery_ind_local_nonprim) {
		battery_indication_free(battery_ind_local_nonprim);
		battery_ind_local_nonprim = NULL;
	}
	return NULL;
}

ue_differentiation_info_t *ue_differentiation_info_copy(
	ue_differentiation_info_t *dst, ue_differentiation_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_differentiation_info_convertToJSON(src);
	if(!item) {
		printf("ue_differentiation_info_convertToJSON() failed");
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

	ue_differentiation_info_free(dst);
	dst = ue_differentiation_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
