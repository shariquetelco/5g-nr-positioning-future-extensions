#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_mobility.h"

ue_mobility_t *ue_mobility_create(char *ts,
                                  scheduled_communication_time_1_t *recurring_time, bool is_duration, int duration, bool is_duration_variance, float duration_variance, list_t *loc_infos,
                                  list_t *direction_infos) {
	ue_mobility_t *ue_mobility_local_var = malloc(sizeof(ue_mobility_t));

	ue_mobility_local_var->ts = ts;
	ue_mobility_local_var->recurring_time = recurring_time;
	ue_mobility_local_var->is_duration = is_duration;
	ue_mobility_local_var->duration = duration;
	ue_mobility_local_var->is_duration_variance = is_duration_variance;
	ue_mobility_local_var->duration_variance = duration_variance;
	ue_mobility_local_var->loc_infos = loc_infos;
	ue_mobility_local_var->direction_infos = direction_infos;

	return ue_mobility_local_var;
}

void ue_mobility_free(ue_mobility_t *ue_mobility) {
	lnode_t *node = NULL;

	if(NULL == ue_mobility) {
		return;
	}
	if(ue_mobility->ts) {
		free(ue_mobility->ts);
		ue_mobility->ts = NULL;
	}
	if(ue_mobility->recurring_time) {
		scheduled_communication_time_1_free(ue_mobility->recurring_time);
		ue_mobility->recurring_time = NULL;
	}
	if(ue_mobility->loc_infos) {
		list_for_each(ue_mobility->loc_infos, node) {
			location_info_free(node->data);
		}
		list_free(ue_mobility->loc_infos);
		ue_mobility->loc_infos = NULL;
	}
	if(ue_mobility->direction_infos) {
		list_for_each(ue_mobility->direction_infos, node) {
			direction_info_free(node->data);
		}
		list_free(ue_mobility->direction_infos);
		ue_mobility->direction_infos = NULL;
	}
	free(ue_mobility);
}

cJSON *ue_mobility_convertToJSON(ue_mobility_t *ue_mobility) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_mobility == NULL) {
		printf("ue_mobility_convertToJSON() failed [UeMobility]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_mobility->ts) {
		if(cJSON_AddStringToObject(item, "ts",
		                           ue_mobility->ts) == NULL)
		{
			printf("ue_mobility_convertToJSON() failed [ts]");
			goto end;
		}
	}

	if(ue_mobility->recurring_time) {
		cJSON *recurring_time_local_JSON =
			scheduled_communication_time_1_convertToJSON(
				ue_mobility->recurring_time);
		if(recurring_time_local_JSON == NULL) {
			printf(
				"ue_mobility_convertToJSON() failed [recurring_time]");
			goto end;
		}
		cJSON_AddItemToObject(item, "recurringTime",
		                      recurring_time_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_mobility_convertToJSON() failed [recurring_time]");
			goto end;
		}
	}

	if(ue_mobility->is_duration) {
		if(cJSON_AddNumberToObject(item, "duration",
		                           ue_mobility->duration) == NULL)
		{
			printf("ue_mobility_convertToJSON() failed [duration]");
			goto end;
		}
	}

	if(ue_mobility->is_duration_variance) {
		if(cJSON_AddNumberToObject(item, "durationVariance",
		                           ue_mobility->duration_variance) ==
		   NULL)
		{
			printf(
				"ue_mobility_convertToJSON() failed [duration_variance]");
			goto end;
		}
	}

	if(ue_mobility->loc_infos) {
		cJSON *loc_infosList = cJSON_AddArrayToObject(item, "locInfos");
		if(loc_infosList == NULL) {
			printf("ue_mobility_convertToJSON() failed [loc_infos]");
			goto end;
		}
		list_for_each(ue_mobility->loc_infos, node) {
			cJSON *itemLocal = location_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"ue_mobility_convertToJSON() failed [loc_infos]");
				goto end;
			}
			cJSON_AddItemToArray(loc_infosList, itemLocal);
		}
	}

	if(ue_mobility->direction_infos) {
		cJSON *direction_infosList = cJSON_AddArrayToObject(item,
		                                                    "directionInfos");
		if(direction_infosList == NULL) {
			printf(
				"ue_mobility_convertToJSON() failed [direction_infos]");
			goto end;
		}
		list_for_each(ue_mobility->direction_infos, node) {
			cJSON *itemLocal = direction_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"ue_mobility_convertToJSON() failed [direction_infos]");
				goto end;
			}
			cJSON_AddItemToArray(direction_infosList, itemLocal);
		}
	}

end:
	return item;
}

ue_mobility_t *ue_mobility_parseFromJSON(cJSON *ue_mobilityJSON) {
	ue_mobility_t *ue_mobility_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ts = NULL;
	cJSON *recurring_time = NULL;
	scheduled_communication_time_1_t *recurring_time_local_nonprim = NULL;
	cJSON *duration = NULL;
	cJSON *duration_variance = NULL;
	cJSON *loc_infos = NULL;
	list_t *loc_infosList = NULL;
	cJSON *direction_infos = NULL;
	list_t *direction_infosList = NULL;
	ts = cJSON_GetObjectItemCaseSensitive(ue_mobilityJSON, "ts");
	if(ts) {
		if(!cJSON_IsString(ts) &&
		   !cJSON_IsNull(ts))
		{
			printf("ue_mobility_parseFromJSON() failed [ts]");
			goto end;
		}
	}

	recurring_time = cJSON_GetObjectItemCaseSensitive(ue_mobilityJSON,
	                                                  "recurringTime");
	if(recurring_time) {
		recurring_time_local_nonprim =
			scheduled_communication_time_1_parseFromJSON(
				recurring_time);
		if(!recurring_time_local_nonprim) {
			printf(
				"scheduled_communication_time_1_parseFromJSON failed [recurring_time]");
			goto end;
		}
	}

	duration =
		cJSON_GetObjectItemCaseSensitive(ue_mobilityJSON, "duration");
	if(duration) {
		if(!cJSON_IsNumber(duration)) {
			printf("ue_mobility_parseFromJSON() failed [duration]");
			goto end;
		}
	}

	duration_variance = cJSON_GetObjectItemCaseSensitive(ue_mobilityJSON,
	                                                     "durationVariance");
	if(duration_variance) {
		if(!cJSON_IsNumber(duration_variance)) {
			printf(
				"ue_mobility_parseFromJSON() failed [duration_variance]");
			goto end;
		}
	}

	loc_infos =
		cJSON_GetObjectItemCaseSensitive(ue_mobilityJSON, "locInfos");
	if(loc_infos) {
		cJSON *loc_infos_local = NULL;
		if(!cJSON_IsArray(loc_infos)) {
			printf("ue_mobility_parseFromJSON() failed [loc_infos]");
			goto end;
		}

		loc_infosList = list_create();

		cJSON_ArrayForEach(loc_infos_local, loc_infos) {
			if(!cJSON_IsObject(loc_infos_local)) {
				printf(
					"ue_mobility_parseFromJSON() failed [loc_infos]");
				goto end;
			}
			location_info_t *loc_infosItem =
				location_info_parseFromJSON(loc_infos_local);
			if(!loc_infosItem) {
				printf("No loc_infosItem");
				goto end;
			}
			list_add(loc_infosList, loc_infosItem);
		}
	}

	direction_infos = cJSON_GetObjectItemCaseSensitive(ue_mobilityJSON,
	                                                   "directionInfos");
	if(direction_infos) {
		cJSON *direction_infos_local = NULL;
		if(!cJSON_IsArray(direction_infos)) {
			printf(
				"ue_mobility_parseFromJSON() failed [direction_infos]");
			goto end;
		}

		direction_infosList = list_create();

		cJSON_ArrayForEach(direction_infos_local, direction_infos) {
			if(!cJSON_IsObject(direction_infos_local)) {
				printf(
					"ue_mobility_parseFromJSON() failed [direction_infos]");
				goto end;
			}
			direction_info_t *direction_infosItem =
				direction_info_parseFromJSON(
					direction_infos_local);
			if(!direction_infosItem) {
				printf("No direction_infosItem");
				goto end;
			}
			list_add(direction_infosList, direction_infosItem);
		}
	}

	ue_mobility_local_var = ue_mobility_create(
		ts &&
		!cJSON_IsNull(ts) ? strdup(ts->valuestring) : NULL,
		recurring_time ? recurring_time_local_nonprim : NULL,
		duration ? true : false,
		duration ? duration->valuedouble : 0,
		duration_variance ? true : false,
		duration_variance ? duration_variance->valuedouble : 0,
		loc_infos ? loc_infosList : NULL,
		direction_infos ? direction_infosList : NULL
		);

	return ue_mobility_local_var;
end:
	if(recurring_time_local_nonprim) {
		scheduled_communication_time_1_free(recurring_time_local_nonprim);
		recurring_time_local_nonprim = NULL;
	}
	if(loc_infosList) {
		list_for_each(loc_infosList, node) {
			location_info_free(node->data);
		}
		list_free(loc_infosList);
		loc_infosList = NULL;
	}
	if(direction_infosList) {
		list_for_each(direction_infosList, node) {
			direction_info_free(node->data);
		}
		list_free(direction_infosList);
		direction_infosList = NULL;
	}
	return NULL;
}

ue_mobility_t *ue_mobility_copy(ue_mobility_t *dst, ue_mobility_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_mobility_convertToJSON(src);
	if(!item) {
		printf("ue_mobility_convertToJSON() failed");
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

	ue_mobility_free(dst);
	dst = ue_mobility_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
