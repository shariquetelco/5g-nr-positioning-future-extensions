#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "expected_ue_behaviour_data.h"

expected_ue_behaviour_data_t *expected_ue_behaviour_data_create(
	stationary_indication_t *stationary_indication,
	bool is_communication_duration_time, int communication_duration_time,
	bool is_periodic_time, int periodic_time,
	scheduled_communication_time_t *scheduled_communication_time,
	scheduled_communication_type_t *scheduled_communication_type,
	list_t *expected_umts, traffic_profile_t *traffic_profile,
	battery_indication_t *battery_indication, char *validity_time,
	char *confidence_level, char *accuracy_level) {
	expected_ue_behaviour_data_t *expected_ue_behaviour_data_local_var =
		malloc(sizeof(expected_ue_behaviour_data_t));

	expected_ue_behaviour_data_local_var->stationary_indication =
		stationary_indication;
	expected_ue_behaviour_data_local_var->is_communication_duration_time =
		is_communication_duration_time;
	expected_ue_behaviour_data_local_var->communication_duration_time =
		communication_duration_time;
	expected_ue_behaviour_data_local_var->is_periodic_time =
		is_periodic_time;
	expected_ue_behaviour_data_local_var->periodic_time = periodic_time;
	expected_ue_behaviour_data_local_var->scheduled_communication_time =
		scheduled_communication_time;
	expected_ue_behaviour_data_local_var->scheduled_communication_type =
		scheduled_communication_type;
	expected_ue_behaviour_data_local_var->expected_umts = expected_umts;
	expected_ue_behaviour_data_local_var->traffic_profile = traffic_profile;
	expected_ue_behaviour_data_local_var->battery_indication =
		battery_indication;
	expected_ue_behaviour_data_local_var->validity_time = validity_time;
	expected_ue_behaviour_data_local_var->confidence_level =
		confidence_level;
	expected_ue_behaviour_data_local_var->accuracy_level = accuracy_level;

	return expected_ue_behaviour_data_local_var;
}

void expected_ue_behaviour_data_free(
	expected_ue_behaviour_data_t *expected_ue_behaviour_data) {
	lnode_t *node = NULL;

	if(NULL == expected_ue_behaviour_data) {
		return;
	}
	if(expected_ue_behaviour_data->stationary_indication) {
		stationary_indication_free(
			expected_ue_behaviour_data->stationary_indication);
		expected_ue_behaviour_data->stationary_indication = NULL;
	}
	if(expected_ue_behaviour_data->scheduled_communication_time) {
		scheduled_communication_time_free(
			expected_ue_behaviour_data->scheduled_communication_time);
		expected_ue_behaviour_data->scheduled_communication_time = NULL;
	}
	if(expected_ue_behaviour_data->scheduled_communication_type) {
		scheduled_communication_type_free(
			expected_ue_behaviour_data->scheduled_communication_type);
		expected_ue_behaviour_data->scheduled_communication_type = NULL;
	}
	if(expected_ue_behaviour_data->expected_umts) {
		list_for_each(expected_ue_behaviour_data->expected_umts, node) {
			location_area_free(node->data);
		}
		list_free(expected_ue_behaviour_data->expected_umts);
		expected_ue_behaviour_data->expected_umts = NULL;
	}
	if(expected_ue_behaviour_data->traffic_profile) {
		traffic_profile_free(expected_ue_behaviour_data->traffic_profile);
		expected_ue_behaviour_data->traffic_profile = NULL;
	}
	if(expected_ue_behaviour_data->battery_indication) {
		battery_indication_free(
			expected_ue_behaviour_data->battery_indication);
		expected_ue_behaviour_data->battery_indication = NULL;
	}
	if(expected_ue_behaviour_data->validity_time) {
		free(expected_ue_behaviour_data->validity_time);
		expected_ue_behaviour_data->validity_time = NULL;
	}
	if(expected_ue_behaviour_data->confidence_level) {
		free(expected_ue_behaviour_data->confidence_level);
		expected_ue_behaviour_data->confidence_level = NULL;
	}
	if(expected_ue_behaviour_data->accuracy_level) {
		free(expected_ue_behaviour_data->accuracy_level);
		expected_ue_behaviour_data->accuracy_level = NULL;
	}
	free(expected_ue_behaviour_data);
}

cJSON *expected_ue_behaviour_data_convertToJSON(
	expected_ue_behaviour_data_t *expected_ue_behaviour_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(expected_ue_behaviour_data == NULL) {
		printf(
			"expected_ue_behaviour_data_convertToJSON() failed [ExpectedUeBehaviourData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(expected_ue_behaviour_data->stationary_indication) {
		cJSON *stationary_indication_local_JSON =
			stationary_indication_convertToJSON(
				expected_ue_behaviour_data->stationary_indication);
		if(stationary_indication_local_JSON == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [stationary_indication]");
			goto end;
		}
		cJSON_AddItemToObject(item, "stationaryIndication",
		                      stationary_indication_local_JSON);
		if(item->child == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [stationary_indication]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->is_communication_duration_time) {
		if(cJSON_AddNumberToObject(item, "communicationDurationTime",
		                           expected_ue_behaviour_data->
		                           communication_duration_time) ==
		   NULL)
		{
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [communication_duration_time]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->is_periodic_time) {
		if(cJSON_AddNumberToObject(item, "periodicTime",
		                           expected_ue_behaviour_data->
		                           periodic_time) == NULL)
		{
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [periodic_time]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->scheduled_communication_time) {
		cJSON *scheduled_communication_time_local_JSON =
			scheduled_communication_time_convertToJSON(
				expected_ue_behaviour_data->scheduled_communication_time);
		if(scheduled_communication_time_local_JSON == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [scheduled_communication_time]");
			goto end;
		}
		cJSON_AddItemToObject(item, "scheduledCommunicationTime",
		                      scheduled_communication_time_local_JSON);
		if(item->child == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [scheduled_communication_time]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->scheduled_communication_type) {
		cJSON *scheduled_communication_type_local_JSON =
			scheduled_communication_type_convertToJSON(
				expected_ue_behaviour_data->scheduled_communication_type);
		if(scheduled_communication_type_local_JSON == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [scheduled_communication_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "scheduledCommunicationType",
		                      scheduled_communication_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [scheduled_communication_type]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->expected_umts) {
		cJSON *expected_umtsList = cJSON_AddArrayToObject(item,
		                                                  "expectedUmts");
		if(expected_umtsList == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [expected_umts]");
			goto end;
		}
		list_for_each(expected_ue_behaviour_data->expected_umts, node) {
			cJSON *itemLocal = location_area_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"expected_ue_behaviour_data_convertToJSON() failed [expected_umts]");
				goto end;
			}
			cJSON_AddItemToArray(expected_umtsList, itemLocal);
		}
	}

	if(expected_ue_behaviour_data->traffic_profile) {
		cJSON *traffic_profile_local_JSON =
			traffic_profile_convertToJSON(
				expected_ue_behaviour_data->traffic_profile);
		if(traffic_profile_local_JSON == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [traffic_profile]");
			goto end;
		}
		cJSON_AddItemToObject(item, "trafficProfile",
		                      traffic_profile_local_JSON);
		if(item->child == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [traffic_profile]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->battery_indication) {
		cJSON *battery_indication_local_JSON =
			battery_indication_convertToJSON(
				expected_ue_behaviour_data->battery_indication);
		if(battery_indication_local_JSON == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [battery_indication]");
			goto end;
		}
		cJSON_AddItemToObject(item, "batteryIndication",
		                      battery_indication_local_JSON);
		if(item->child == NULL) {
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [battery_indication]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->validity_time) {
		if(cJSON_AddStringToObject(item, "validityTime",
		                           expected_ue_behaviour_data->
		                           validity_time) == NULL)
		{
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [validity_time]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->confidence_level) {
		if(cJSON_AddStringToObject(item, "confidenceLevel",
		                           expected_ue_behaviour_data->
		                           confidence_level) == NULL)
		{
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [confidence_level]");
			goto end;
		}
	}

	if(expected_ue_behaviour_data->accuracy_level) {
		if(cJSON_AddStringToObject(item, "accuracyLevel",
		                           expected_ue_behaviour_data->
		                           accuracy_level) == NULL)
		{
			printf(
				"expected_ue_behaviour_data_convertToJSON() failed [accuracy_level]");
			goto end;
		}
	}

end:
	return item;
}

expected_ue_behaviour_data_t *expected_ue_behaviour_data_parseFromJSON(
	cJSON *expected_ue_behaviour_dataJSON) {
	expected_ue_behaviour_data_t *expected_ue_behaviour_data_local_var =
		NULL;
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
	cJSON *expected_umts = NULL;
	list_t *expected_umtsList = NULL;
	cJSON *traffic_profile = NULL;
	traffic_profile_t *traffic_profile_local_nonprim = NULL;
	cJSON *battery_indication = NULL;
	battery_indication_t *battery_indication_local_nonprim = NULL;
	cJSON *validity_time = NULL;
	cJSON *confidence_level = NULL;
	cJSON *accuracy_level = NULL;
	stationary_indication = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "stationaryIndication");
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
		expected_ue_behaviour_dataJSON, "communicationDurationTime");
	if(communication_duration_time) {
		if(!cJSON_IsNumber(communication_duration_time)) {
			printf(
				"expected_ue_behaviour_data_parseFromJSON() failed [communication_duration_time]");
			goto end;
		}
	}

	periodic_time = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "periodicTime");
	if(periodic_time) {
		if(!cJSON_IsNumber(periodic_time)) {
			printf(
				"expected_ue_behaviour_data_parseFromJSON() failed [periodic_time]");
			goto end;
		}
	}

	scheduled_communication_time = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "scheduledCommunicationTime");
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
		expected_ue_behaviour_dataJSON, "scheduledCommunicationType");
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

	expected_umts = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "expectedUmts");
	if(expected_umts) {
		cJSON *expected_umts_local = NULL;
		if(!cJSON_IsArray(expected_umts)) {
			printf(
				"expected_ue_behaviour_data_parseFromJSON() failed [expected_umts]");
			goto end;
		}

		expected_umtsList = list_create();

		cJSON_ArrayForEach(expected_umts_local, expected_umts) {
			if(!cJSON_IsObject(expected_umts_local)) {
				printf(
					"expected_ue_behaviour_data_parseFromJSON() failed [expected_umts]");
				goto end;
			}
			location_area_t *expected_umtsItem =
				location_area_parseFromJSON(expected_umts_local);
			if(!expected_umtsItem) {
				printf("No expected_umtsItem");
				goto end;
			}
			list_add(expected_umtsList, expected_umtsItem);
		}
	}

	traffic_profile = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "trafficProfile");
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
		expected_ue_behaviour_dataJSON, "batteryIndication");
	if(battery_indication) {
		battery_indication_local_nonprim =
			battery_indication_parseFromJSON(battery_indication);
		if(!battery_indication_local_nonprim) {
			printf(
				"battery_indication_parseFromJSON failed [battery_indication]");
			goto end;
		}
	}

	validity_time = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "validityTime");
	if(validity_time) {
		if(!cJSON_IsString(validity_time) &&
		   !cJSON_IsNull(validity_time))
		{
			printf(
				"expected_ue_behaviour_data_parseFromJSON() failed [validity_time]");
			goto end;
		}
	}

	confidence_level = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "confidenceLevel");
	if(confidence_level) {
		if(!cJSON_IsString(confidence_level) &&
		   !cJSON_IsNull(confidence_level))
		{
			printf(
				"expected_ue_behaviour_data_parseFromJSON() failed [confidence_level]");
			goto end;
		}
	}

	accuracy_level = cJSON_GetObjectItemCaseSensitive(
		expected_ue_behaviour_dataJSON, "accuracyLevel");
	if(accuracy_level) {
		if(!cJSON_IsString(accuracy_level) &&
		   !cJSON_IsNull(accuracy_level))
		{
			printf(
				"expected_ue_behaviour_data_parseFromJSON() failed [accuracy_level]");
			goto end;
		}
	}

	expected_ue_behaviour_data_local_var =
		expected_ue_behaviour_data_create(
			stationary_indication ? stationary_indication_local_nonprim : NULL,
			communication_duration_time ? true : false,
			communication_duration_time ? communication_duration_time->valuedouble : 0,
			periodic_time ? true : false,
			periodic_time ? periodic_time->valuedouble : 0,
			scheduled_communication_time ? scheduled_communication_time_local_nonprim : NULL,
			scheduled_communication_type ? scheduled_communication_type_local_nonprim : NULL,
			expected_umts ? expected_umtsList : NULL,
			traffic_profile ? traffic_profile_local_nonprim : NULL,
			battery_indication ? battery_indication_local_nonprim : NULL,
			validity_time &&
			!cJSON_IsNull(validity_time) ? strdup(
				validity_time->valuestring) : NULL,
			confidence_level &&
			!cJSON_IsNull(confidence_level) ? strdup(
				confidence_level->
				valuestring) : NULL,
			accuracy_level &&
			!cJSON_IsNull(accuracy_level) ? strdup(accuracy_level->
			                                       valuestring) : NULL
			);

	return expected_ue_behaviour_data_local_var;
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
	if(expected_umtsList) {
		list_for_each(expected_umtsList, node) {
			location_area_free(node->data);
		}
		list_free(expected_umtsList);
		expected_umtsList = NULL;
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

expected_ue_behaviour_data_t *expected_ue_behaviour_data_copy(
	expected_ue_behaviour_data_t *dst, expected_ue_behaviour_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = expected_ue_behaviour_data_convertToJSON(src);
	if(!item) {
		printf("expected_ue_behaviour_data_convertToJSON() failed");
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

	expected_ue_behaviour_data_free(dst);
	dst = expected_ue_behaviour_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
