#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_ranging_data.h"

input_ranging_data_t *input_ranging_data_create(char *gpsi, char *supi,
                                                location_qo_s_t *location_qo_s,
                                                external_client_type_e external_client_type, char *external_client_identification, list_t *requested_ranging_sl_result,
                                                char *scheduled_loc_time) {
	input_ranging_data_t *input_ranging_data_local_var =
		malloc(sizeof(input_ranging_data_t));

	input_ranging_data_local_var->gpsi = gpsi;
	input_ranging_data_local_var->supi = supi;
	input_ranging_data_local_var->location_qo_s = location_qo_s;
	input_ranging_data_local_var->external_client_type =
		external_client_type;
	input_ranging_data_local_var->external_client_identification =
		external_client_identification;
	input_ranging_data_local_var->requested_ranging_sl_result =
		requested_ranging_sl_result;
	input_ranging_data_local_var->scheduled_loc_time = scheduled_loc_time;

	return input_ranging_data_local_var;
}

void input_ranging_data_free(input_ranging_data_t *input_ranging_data) {
	lnode_t *node = NULL;

	if(NULL == input_ranging_data) {
		return;
	}
	if(input_ranging_data->gpsi) {
		free(input_ranging_data->gpsi);
		input_ranging_data->gpsi = NULL;
	}
	if(input_ranging_data->supi) {
		free(input_ranging_data->supi);
		input_ranging_data->supi = NULL;
	}
	if(input_ranging_data->location_qo_s) {
		location_qo_s_free(input_ranging_data->location_qo_s);
		input_ranging_data->location_qo_s = NULL;
	}
	if(input_ranging_data->external_client_identification) {
		free(input_ranging_data->external_client_identification);
		input_ranging_data->external_client_identification = NULL;
	}
	if(input_ranging_data->requested_ranging_sl_result) {
		list_free(input_ranging_data->requested_ranging_sl_result);
		input_ranging_data->requested_ranging_sl_result = NULL;
	}
	if(input_ranging_data->scheduled_loc_time) {
		free(input_ranging_data->scheduled_loc_time);
		input_ranging_data->scheduled_loc_time = NULL;
	}
	free(input_ranging_data);
}

cJSON *input_ranging_data_convertToJSON(
	input_ranging_data_t *input_ranging_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(input_ranging_data == NULL) {
		printf(
			"input_ranging_data_convertToJSON() failed [InputRangingData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(input_ranging_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           input_ranging_data->gpsi) == NULL)
		{
			printf(
				"input_ranging_data_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(input_ranging_data->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           input_ranging_data->supi) == NULL)
		{
			printf(
				"input_ranging_data_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(input_ranging_data->location_qo_s) {
		cJSON *location_qo_s_local_JSON = location_qo_s_convertToJSON(
			input_ranging_data->location_qo_s);
		if(location_qo_s_local_JSON == NULL) {
			printf(
				"input_ranging_data_convertToJSON() failed [location_qo_s]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationQoS",
		                      location_qo_s_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_ranging_data_convertToJSON() failed [location_qo_s]");
			goto end;
		}
	}

	if(input_ranging_data->external_client_type ==
	   external_client_type_NULL)
	{
		printf(
			"input_ranging_data_convertToJSON() failed [external_client_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "externalClientType",
	                           external_client_type_ToString(
					   input_ranging_data->
					   external_client_type))
	   == NULL)
	{
		printf(
			"input_ranging_data_convertToJSON() failed [external_client_type]");
		goto end;
	}

	if(input_ranging_data->external_client_identification) {
		if(cJSON_AddStringToObject(item, "externalClientIdentification",
		                           input_ranging_data->
		                           external_client_identification) ==
		   NULL)
		{
			printf(
				"input_ranging_data_convertToJSON() failed [external_client_identification]");
			goto end;
		}
	}

	if(input_ranging_data->requested_ranging_sl_result !=
	   ranging_sl_result_NULL)
	{
		cJSON *requested_ranging_sl_resultList = cJSON_AddArrayToObject(
			item, "requestedRangingSlResult");
		if(requested_ranging_sl_resultList == NULL) {
			printf(
				"input_ranging_data_convertToJSON() failed [requested_ranging_sl_result]");
			goto end;
		}
		list_for_each(input_ranging_data->requested_ranging_sl_result,
		              node) {
			if(cJSON_AddStringToObject(
				   requested_ranging_sl_resultList, "",
				   ranging_sl_result_ToString((intptr_t) node->
				                              data)) ==
			   NULL)
			{
				printf(
					"input_ranging_data_convertToJSON() failed [requested_ranging_sl_result]");
				goto end;
			}
		}
	}

	if(input_ranging_data->scheduled_loc_time) {
		if(cJSON_AddStringToObject(item, "scheduledLocTime",
		                           input_ranging_data->
		                           scheduled_loc_time) == NULL)
		{
			printf(
				"input_ranging_data_convertToJSON() failed [scheduled_loc_time]");
			goto end;
		}
	}

end:
	return item;
}

input_ranging_data_t *input_ranging_data_parseFromJSON(
	cJSON *input_ranging_dataJSON) {
	input_ranging_data_t *input_ranging_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	cJSON *location_qo_s = NULL;
	location_qo_s_t *location_qo_s_local_nonprim = NULL;
	cJSON *external_client_type = NULL;
	external_client_type_e external_client_typeVariable = 0;
	cJSON *external_client_identification = NULL;
	cJSON *requested_ranging_sl_result = NULL;
	list_t *requested_ranging_sl_resultList = NULL;
	cJSON *scheduled_loc_time = NULL;
	gpsi = cJSON_GetObjectItemCaseSensitive(input_ranging_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf(
				"input_ranging_data_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(input_ranging_dataJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf(
				"input_ranging_data_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	location_qo_s = cJSON_GetObjectItemCaseSensitive(input_ranging_dataJSON,
	                                                 "locationQoS");
	if(location_qo_s) {
		location_qo_s_local_nonprim = location_qo_s_parseFromJSON(
			location_qo_s);
		if(!location_qo_s_local_nonprim) {
			printf(
				"location_qo_s_parseFromJSON failed [location_qo_s]");
			goto end;
		}
	}

	external_client_type = cJSON_GetObjectItemCaseSensitive(
		input_ranging_dataJSON, "externalClientType");
	if(!external_client_type) {
		printf(
			"input_ranging_data_parseFromJSON() failed [external_client_type]");
		goto end;
	}
	if(!cJSON_IsString(external_client_type)) {
		printf(
			"input_ranging_data_parseFromJSON() failed [external_client_type]");
		goto end;
	}
	external_client_typeVariable = external_client_type_FromString(
		external_client_type->valuestring);

	external_client_identification = cJSON_GetObjectItemCaseSensitive(
		input_ranging_dataJSON, "externalClientIdentification");
	if(external_client_identification) {
		if(!cJSON_IsString(external_client_identification) &&
		   !cJSON_IsNull(external_client_identification))
		{
			printf(
				"input_ranging_data_parseFromJSON() failed [external_client_identification]");
			goto end;
		}
	}

	requested_ranging_sl_result = cJSON_GetObjectItemCaseSensitive(
		input_ranging_dataJSON, "requestedRangingSlResult");
	if(requested_ranging_sl_result) {
		cJSON *requested_ranging_sl_result_local = NULL;
		if(!cJSON_IsArray(requested_ranging_sl_result)) {
			printf(
				"input_ranging_data_parseFromJSON() failed [requested_ranging_sl_result]");
			goto end;
		}

		requested_ranging_sl_resultList = list_create();

		cJSON_ArrayForEach(requested_ranging_sl_result_local,
		                   requested_ranging_sl_result) {
			ranging_sl_result_e localEnum = ranging_sl_result_NULL;
			if(!cJSON_IsString(requested_ranging_sl_result_local)) {
				printf(
					"input_ranging_data_parseFromJSON() failed [requested_ranging_sl_result]");
				goto end;
			}
			localEnum = ranging_sl_result_FromString(
				requested_ranging_sl_result_local->valuestring);
			if(!localEnum) {
				printf(
					"Enum value \"%s\" for field \"requested_ranging_sl_result\" is not supported. Ignoring it ...",
					requested_ranging_sl_result_local->valuestring);
			} else {
				list_add(requested_ranging_sl_resultList,
				         (void *) localEnum);
			}
		}
		if(requested_ranging_sl_resultList->count == 0) {
			printf(
				"input_ranging_data_parseFromJSON() failed: Expected requested_ranging_sl_resultList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(
		input_ranging_dataJSON, "scheduledLocTime");
	if(scheduled_loc_time) {
		if(!cJSON_IsString(scheduled_loc_time) &&
		   !cJSON_IsNull(scheduled_loc_time))
		{
			printf(
				"input_ranging_data_parseFromJSON() failed [scheduled_loc_time]");
			goto end;
		}
	}

	input_ranging_data_local_var = input_ranging_data_create(
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		location_qo_s ? location_qo_s_local_nonprim : NULL,
		external_client_typeVariable,
		external_client_identification &&
		!cJSON_IsNull(external_client_identification) ? strdup(
			external_client_identification->valuestring) : NULL,
		requested_ranging_sl_result ? requested_ranging_sl_resultList : NULL,
		scheduled_loc_time &&
		!cJSON_IsNull(scheduled_loc_time) ? strdup(scheduled_loc_time->
		                                           valuestring) : NULL
		);

	return input_ranging_data_local_var;
end:
	if(location_qo_s_local_nonprim) {
		location_qo_s_free(location_qo_s_local_nonprim);
		location_qo_s_local_nonprim = NULL;
	}
	if(requested_ranging_sl_resultList) {
		list_free(requested_ranging_sl_resultList);
		requested_ranging_sl_resultList = NULL;
	}
	return NULL;
}

input_ranging_data_t *input_ranging_data_copy(input_ranging_data_t	*dst,
                                              input_ranging_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = input_ranging_data_convertToJSON(src);
	if(!item) {
		printf("input_ranging_data_convertToJSON() failed");
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

	input_ranging_data_free(dst);
	dst = input_ranging_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
