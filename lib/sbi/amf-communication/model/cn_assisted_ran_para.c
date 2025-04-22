#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cn_assisted_ran_para.h"

cn_assisted_ran_para_t *cn_assisted_ran_para_create(
	stationary_indication_t *stationary_indication,
	bool is_communication_duration_time, int communication_duration_time,
	bool is_periodic_time, int periodic_time,
	scheduled_communication_time_t *scheduled_communication_time,
	scheduled_communication_type_t *scheduled_communication_type,
	traffic_profile_t *traffic_profile,
	battery_indication_t *battery_indication) {
	cn_assisted_ran_para_t *cn_assisted_ran_para_local_var =
		malloc(sizeof(cn_assisted_ran_para_t));

	cn_assisted_ran_para_local_var->stationary_indication =
		stationary_indication;
	cn_assisted_ran_para_local_var->is_communication_duration_time =
		is_communication_duration_time;
	cn_assisted_ran_para_local_var->communication_duration_time =
		communication_duration_time;
	cn_assisted_ran_para_local_var->is_periodic_time = is_periodic_time;
	cn_assisted_ran_para_local_var->periodic_time = periodic_time;
	cn_assisted_ran_para_local_var->scheduled_communication_time =
		scheduled_communication_time;
	cn_assisted_ran_para_local_var->scheduled_communication_type =
		scheduled_communication_type;
	cn_assisted_ran_para_local_var->traffic_profile = traffic_profile;
	cn_assisted_ran_para_local_var->battery_indication = battery_indication;

	return cn_assisted_ran_para_local_var;
}

void cn_assisted_ran_para_free(cn_assisted_ran_para_t *cn_assisted_ran_para) {
	lnode_t *node = NULL;

	if(NULL == cn_assisted_ran_para) {
		return;
	}
	if(cn_assisted_ran_para->stationary_indication) {
		stationary_indication_free(
			cn_assisted_ran_para->stationary_indication);
		cn_assisted_ran_para->stationary_indication = NULL;
	}
	if(cn_assisted_ran_para->scheduled_communication_time) {
		scheduled_communication_time_free(
			cn_assisted_ran_para->scheduled_communication_time);
		cn_assisted_ran_para->scheduled_communication_time = NULL;
	}
	if(cn_assisted_ran_para->scheduled_communication_type) {
		scheduled_communication_type_free(
			cn_assisted_ran_para->scheduled_communication_type);
		cn_assisted_ran_para->scheduled_communication_type = NULL;
	}
	if(cn_assisted_ran_para->traffic_profile) {
		traffic_profile_free(cn_assisted_ran_para->traffic_profile);
		cn_assisted_ran_para->traffic_profile = NULL;
	}
	if(cn_assisted_ran_para->battery_indication) {
		battery_indication_free(cn_assisted_ran_para->battery_indication);
		cn_assisted_ran_para->battery_indication = NULL;
	}
	free(cn_assisted_ran_para);
}

cJSON *cn_assisted_ran_para_convertToJSON(
	cn_assisted_ran_para_t *cn_assisted_ran_para) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cn_assisted_ran_para == NULL) {
		printf(
			"cn_assisted_ran_para_convertToJSON() failed [CnAssistedRanPara]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cn_assisted_ran_para->stationary_indication) {
		cJSON *stationary_indication_local_JSON =
			stationary_indication_convertToJSON(
				cn_assisted_ran_para->stationary_indication);
		if(stationary_indication_local_JSON == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [stationary_indication]");
			goto end;
		}
		cJSON_AddItemToObject(item, "stationaryIndication",
		                      stationary_indication_local_JSON);
		if(item->child == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [stationary_indication]");
			goto end;
		}
	}

	if(cn_assisted_ran_para->is_communication_duration_time) {
		if(cJSON_AddNumberToObject(item, "communicationDurationTime",
		                           cn_assisted_ran_para->
		                           communication_duration_time) == NULL)
		{
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [communication_duration_time]");
			goto end;
		}
	}

	if(cn_assisted_ran_para->is_periodic_time) {
		if(cJSON_AddNumberToObject(item, "periodicTime",
		                           cn_assisted_ran_para->periodic_time)
		   == NULL)
		{
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [periodic_time]");
			goto end;
		}
	}

	if(cn_assisted_ran_para->scheduled_communication_time) {
		cJSON *scheduled_communication_time_local_JSON =
			scheduled_communication_time_convertToJSON(
				cn_assisted_ran_para->scheduled_communication_time);
		if(scheduled_communication_time_local_JSON == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [scheduled_communication_time]");
			goto end;
		}
		cJSON_AddItemToObject(item, "scheduledCommunicationTime",
		                      scheduled_communication_time_local_JSON);
		if(item->child == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [scheduled_communication_time]");
			goto end;
		}
	}

	if(cn_assisted_ran_para->scheduled_communication_type) {
		cJSON *scheduled_communication_type_local_JSON =
			scheduled_communication_type_convertToJSON(
				cn_assisted_ran_para->scheduled_communication_type);
		if(scheduled_communication_type_local_JSON == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [scheduled_communication_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "scheduledCommunicationType",
		                      scheduled_communication_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [scheduled_communication_type]");
			goto end;
		}
	}

	if(cn_assisted_ran_para->traffic_profile) {
		cJSON *traffic_profile_local_JSON =
			traffic_profile_convertToJSON(
				cn_assisted_ran_para->traffic_profile);
		if(traffic_profile_local_JSON == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [traffic_profile]");
			goto end;
		}
		cJSON_AddItemToObject(item, "trafficProfile",
		                      traffic_profile_local_JSON);
		if(item->child == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [traffic_profile]");
			goto end;
		}
	}

	if(cn_assisted_ran_para->battery_indication) {
		cJSON *battery_indication_local_JSON =
			battery_indication_convertToJSON(
				cn_assisted_ran_para->battery_indication);
		if(battery_indication_local_JSON == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [battery_indication]");
			goto end;
		}
		cJSON_AddItemToObject(item, "batteryIndication",
		                      battery_indication_local_JSON);
		if(item->child == NULL) {
			printf(
				"cn_assisted_ran_para_convertToJSON() failed [battery_indication]");
			goto end;
		}
	}

end:
	return item;
}

cn_assisted_ran_para_t *cn_assisted_ran_para_parseFromJSON(
	cJSON *cn_assisted_ran_paraJSON) {
	cn_assisted_ran_para_t *cn_assisted_ran_para_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *stationary_indication = NULL;
	stationary_indication_t *stationary_indication_local_nonprim = NULL;
	cJSON *communication_duration_time = NULL;
	cJSON *periodic_time = NULL;
	cJSON *scheduled_communication_time = NULL;
	scheduled_communication_time_t *
	        scheduled_communication_time_local_nonprim = NULL;
	cJSON *scheduled_communication_type = NULL;
	scheduled_communication_type_t *
	        scheduled_communication_type_local_nonprim = NULL;
	cJSON *traffic_profile = NULL;
	traffic_profile_t *traffic_profile_local_nonprim = NULL;
	cJSON *battery_indication = NULL;
	battery_indication_t *battery_indication_local_nonprim = NULL;
	stationary_indication = cJSON_GetObjectItemCaseSensitive(
		cn_assisted_ran_paraJSON, "stationaryIndication");
	if(stationary_indication) {
		stationary_indication_local_nonprim =
			stationary_indication_parseFromJSON(
				stationary_indication);
		if(!stationary_indication_local_nonprim) {
			printf(
				"stationary_indication_parseFromJSON failed [stationary_indication]");
			goto end;
		}
	}

	communication_duration_time = cJSON_GetObjectItemCaseSensitive(
		cn_assisted_ran_paraJSON, "communicationDurationTime");
	if(communication_duration_time) {
		if(!cJSON_IsNumber(communication_duration_time)) {
			printf(
				"cn_assisted_ran_para_parseFromJSON() failed [communication_duration_time]");
			goto end;
		}
	}

	periodic_time = cJSON_GetObjectItemCaseSensitive(
		cn_assisted_ran_paraJSON, "periodicTime");
	if(periodic_time) {
		if(!cJSON_IsNumber(periodic_time)) {
			printf(
				"cn_assisted_ran_para_parseFromJSON() failed [periodic_time]");
			goto end;
		}
	}

	scheduled_communication_time = cJSON_GetObjectItemCaseSensitive(
		cn_assisted_ran_paraJSON, "scheduledCommunicationTime");
	if(scheduled_communication_time) {
		scheduled_communication_time_local_nonprim =
			scheduled_communication_time_parseFromJSON(
				scheduled_communication_time);
		if(!scheduled_communication_time_local_nonprim) {
			printf(
				"scheduled_communication_time_parseFromJSON failed [scheduled_communication_time]");
			goto end;
		}
	}

	scheduled_communication_type = cJSON_GetObjectItemCaseSensitive(
		cn_assisted_ran_paraJSON, "scheduledCommunicationType");
	if(scheduled_communication_type) {
		scheduled_communication_type_local_nonprim =
			scheduled_communication_type_parseFromJSON(
				scheduled_communication_type);
		if(!scheduled_communication_type_local_nonprim) {
			printf(
				"scheduled_communication_type_parseFromJSON failed [scheduled_communication_type]");
			goto end;
		}
	}

	traffic_profile = cJSON_GetObjectItemCaseSensitive(
		cn_assisted_ran_paraJSON, "trafficProfile");
	if(traffic_profile) {
		traffic_profile_local_nonprim = traffic_profile_parseFromJSON(
			traffic_profile);
		if(!traffic_profile_local_nonprim) {
			printf(
				"traffic_profile_parseFromJSON failed [traffic_profile]");
			goto end;
		}
	}

	battery_indication = cJSON_GetObjectItemCaseSensitive(
		cn_assisted_ran_paraJSON, "batteryIndication");
	if(battery_indication) {
		battery_indication_local_nonprim =
			battery_indication_parseFromJSON(battery_indication);
		if(!battery_indication_local_nonprim) {
			printf(
				"battery_indication_parseFromJSON failed [battery_indication]");
			goto end;
		}
	}

	cn_assisted_ran_para_local_var = cn_assisted_ran_para_create(
		stationary_indication ? stationary_indication_local_nonprim : NULL,
		communication_duration_time ? true : false,
		communication_duration_time ? communication_duration_time->valuedouble : 0,
		periodic_time ? true : false,
		periodic_time ? periodic_time->valuedouble : 0,
		scheduled_communication_time ? scheduled_communication_time_local_nonprim : NULL,
		scheduled_communication_type ? scheduled_communication_type_local_nonprim : NULL,
		traffic_profile ? traffic_profile_local_nonprim : NULL,
		battery_indication ? battery_indication_local_nonprim : NULL
		);

	return cn_assisted_ran_para_local_var;
end:
	if(stationary_indication_local_nonprim) {
		stationary_indication_free(stationary_indication_local_nonprim);
		stationary_indication_local_nonprim = NULL;
	}
	if(scheduled_communication_time_local_nonprim) {
		scheduled_communication_time_free(
			scheduled_communication_time_local_nonprim);
		scheduled_communication_time_local_nonprim = NULL;
	}
	if(scheduled_communication_type_local_nonprim) {
		scheduled_communication_type_free(
			scheduled_communication_type_local_nonprim);
		scheduled_communication_type_local_nonprim = NULL;
	}
	if(traffic_profile_local_nonprim) {
		traffic_profile_free(traffic_profile_local_nonprim);
		traffic_profile_local_nonprim = NULL;
	}
	if(battery_indication_local_nonprim) {
		battery_indication_free(battery_indication_local_nonprim);
		battery_indication_local_nonprim = NULL;
	}
	return NULL;
}

cn_assisted_ran_para_t *cn_assisted_ran_para_copy(
	cn_assisted_ran_para_t	*dst,
	cn_assisted_ran_para_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = cn_assisted_ran_para_convertToJSON(src);
	if(!item) {
		printf("cn_assisted_ran_para_convertToJSON() failed");
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

	cn_assisted_ran_para_free(dst);
	dst = cn_assisted_ran_para_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
