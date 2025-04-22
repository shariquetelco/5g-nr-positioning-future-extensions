#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ranging_data.h"

ranging_data_t *ranging_data_create(char *gpsi, char *supi,
                                    char *timestamp_of_location_estimate,
                                    minor_location_qo_s_t *achieved_qos,
                                    list_t *ranging_data_list,
                                    char *related_applicationlayer_id,
                                    range_direction_t *range_direction,
                                    model_2_d_relative_location_t *_2d_relative_location, model_3_d_relative_location_t *_3d_relative_location,
                                    velocity_estimate_t *relative_velocity) {
	ranging_data_t *ranging_data_local_var = malloc(sizeof(ranging_data_t));

	ranging_data_local_var->gpsi = gpsi;
	ranging_data_local_var->supi = supi;
	ranging_data_local_var->timestamp_of_location_estimate =
		timestamp_of_location_estimate;
	ranging_data_local_var->achieved_qos = achieved_qos;
	ranging_data_local_var->ranging_data_list = ranging_data_list;
	ranging_data_local_var->related_applicationlayer_id =
		related_applicationlayer_id;
	ranging_data_local_var->range_direction = range_direction;
	ranging_data_local_var->_2d_relative_location = _2d_relative_location;
	ranging_data_local_var->_3d_relative_location = _3d_relative_location;
	ranging_data_local_var->relative_velocity = relative_velocity;

	return ranging_data_local_var;
}

void ranging_data_free(ranging_data_t *ranging_data) {
	lnode_t *node = NULL;

	if(NULL == ranging_data) {
		return;
	}
	if(ranging_data->gpsi) {
		free(ranging_data->gpsi);
		ranging_data->gpsi = NULL;
	}
	if(ranging_data->supi) {
		free(ranging_data->supi);
		ranging_data->supi = NULL;
	}
	if(ranging_data->timestamp_of_location_estimate) {
		free(ranging_data->timestamp_of_location_estimate);
		ranging_data->timestamp_of_location_estimate = NULL;
	}
	if(ranging_data->achieved_qos) {
		minor_location_qo_s_free(ranging_data->achieved_qos);
		ranging_data->achieved_qos = NULL;
	}
	if(ranging_data->ranging_data_list) {
		list_for_each(ranging_data->ranging_data_list, node) {
			positioning_method_and_usage_free(node->data);
		}
		list_free(ranging_data->ranging_data_list);
		ranging_data->ranging_data_list = NULL;
	}
	if(ranging_data->related_applicationlayer_id) {
		free(ranging_data->related_applicationlayer_id);
		ranging_data->related_applicationlayer_id = NULL;
	}
	if(ranging_data->range_direction) {
		range_direction_free(ranging_data->range_direction);
		ranging_data->range_direction = NULL;
	}
	if(ranging_data->_2d_relative_location) {
		model_2_d_relative_location_free(
			ranging_data->_2d_relative_location);
		ranging_data->_2d_relative_location = NULL;
	}
	if(ranging_data->_3d_relative_location) {
		model_3_d_relative_location_free(
			ranging_data->_3d_relative_location);
		ranging_data->_3d_relative_location = NULL;
	}
	if(ranging_data->relative_velocity) {
		velocity_estimate_free(ranging_data->relative_velocity);
		ranging_data->relative_velocity = NULL;
	}
	free(ranging_data);
}

cJSON *ranging_data_convertToJSON(ranging_data_t *ranging_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ranging_data == NULL) {
		printf("ranging_data_convertToJSON() failed [RangingData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ranging_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           ranging_data->gpsi) == NULL)
		{
			printf("ranging_data_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(ranging_data->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           ranging_data->supi) == NULL)
		{
			printf("ranging_data_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(ranging_data->timestamp_of_location_estimate) {
		if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate",
		                           ranging_data->
		                           timestamp_of_location_estimate) ==
		   NULL)
		{
			printf(
				"ranging_data_convertToJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	if(ranging_data->achieved_qos) {
		cJSON *achieved_qos_local_JSON =
			minor_location_qo_s_convertToJSON(
				ranging_data->achieved_qos);
		if(achieved_qos_local_JSON == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [achieved_qos]");
			goto end;
		}
		cJSON_AddItemToObject(item, "achievedQos",
		                      achieved_qos_local_JSON);
		if(item->child == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [achieved_qos]");
			goto end;
		}
	}

	if(ranging_data->ranging_data_list) {
		cJSON *ranging_data_listList = cJSON_AddArrayToObject(item,
		                                                      "rangingDataList");
		if(ranging_data_listList == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [ranging_data_list]");
			goto end;
		}
		list_for_each(ranging_data->ranging_data_list, node) {
			cJSON *itemLocal =
				positioning_method_and_usage_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"ranging_data_convertToJSON() failed [ranging_data_list]");
				goto end;
			}
			cJSON_AddItemToArray(ranging_data_listList, itemLocal);
		}
	}

	if(ranging_data->related_applicationlayer_id) {
		if(cJSON_AddStringToObject(item, "relatedApplicationlayerId",
		                           ranging_data->
		                           related_applicationlayer_id) == NULL)
		{
			printf(
				"ranging_data_convertToJSON() failed [related_applicationlayer_id]");
			goto end;
		}
	}

	if(ranging_data->range_direction) {
		cJSON *range_direction_local_JSON =
			range_direction_convertToJSON(
				ranging_data->range_direction);
		if(range_direction_local_JSON == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [range_direction]");
			goto end;
		}
		cJSON_AddItemToObject(item, "rangeDirection",
		                      range_direction_local_JSON);
		if(item->child == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [range_direction]");
			goto end;
		}
	}

	if(ranging_data->_2d_relative_location) {
		cJSON *_2d_relative_location_local_JSON =
			model_2_d_relative_location_convertToJSON(
				ranging_data->_2d_relative_location);
		if(_2d_relative_location_local_JSON == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [_2d_relative_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "2dRelativeLocation",
		                      _2d_relative_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [_2d_relative_location]");
			goto end;
		}
	}

	if(ranging_data->_3d_relative_location) {
		cJSON *_3d_relative_location_local_JSON =
			model_3_d_relative_location_convertToJSON(
				ranging_data->_3d_relative_location);
		if(_3d_relative_location_local_JSON == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [_3d_relative_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "3dRelativeLocation",
		                      _3d_relative_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [_3d_relative_location]");
			goto end;
		}
	}

	if(ranging_data->relative_velocity) {
		cJSON *relative_velocity_local_JSON =
			velocity_estimate_convertToJSON(
				ranging_data->relative_velocity);
		if(relative_velocity_local_JSON == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [relative_velocity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "relativeVelocity",
		                      relative_velocity_local_JSON);
		if(item->child == NULL) {
			printf(
				"ranging_data_convertToJSON() failed [relative_velocity]");
			goto end;
		}
	}

end:
	return item;
}

ranging_data_t *ranging_data_parseFromJSON(cJSON *ranging_dataJSON) {
	ranging_data_t *ranging_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	cJSON *timestamp_of_location_estimate = NULL;
	cJSON *achieved_qos = NULL;
	minor_location_qo_s_t *achieved_qos_local_nonprim = NULL;
	cJSON *ranging_data_list = NULL;
	list_t *ranging_data_listList = NULL;
	cJSON *related_applicationlayer_id = NULL;
	cJSON *range_direction = NULL;
	range_direction_t *range_direction_local_nonprim = NULL;
	cJSON *_2d_relative_location = NULL;
	model_2_d_relative_location_t *_2d_relative_location_local_nonprim =
		NULL;
	cJSON *_3d_relative_location = NULL;
	model_3_d_relative_location_t *_3d_relative_location_local_nonprim =
		NULL;
	cJSON *relative_velocity = NULL;
	velocity_estimate_t *relative_velocity_local_nonprim = NULL;
	gpsi = cJSON_GetObjectItemCaseSensitive(ranging_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("ranging_data_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(ranging_dataJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("ranging_data_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		ranging_dataJSON, "timestampOfLocationEstimate");
	if(timestamp_of_location_estimate) {
		if(!cJSON_IsString(timestamp_of_location_estimate) &&
		   !cJSON_IsNull(timestamp_of_location_estimate))
		{
			printf(
				"ranging_data_parseFromJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	achieved_qos = cJSON_GetObjectItemCaseSensitive(ranging_dataJSON,
	                                                "achievedQos");
	if(achieved_qos) {
		achieved_qos_local_nonprim = minor_location_qo_s_parseFromJSON(
			achieved_qos);
		if(!achieved_qos_local_nonprim) {
			printf(
				"minor_location_qo_s_parseFromJSON failed [achieved_qos]");
			goto end;
		}
	}

	ranging_data_list = cJSON_GetObjectItemCaseSensitive(ranging_dataJSON,
	                                                     "rangingDataList");
	if(ranging_data_list) {
		cJSON *ranging_data_list_local = NULL;
		if(!cJSON_IsArray(ranging_data_list)) {
			printf(
				"ranging_data_parseFromJSON() failed [ranging_data_list]");
			goto end;
		}

		ranging_data_listList = list_create();

		cJSON_ArrayForEach(ranging_data_list_local, ranging_data_list) {
			if(!cJSON_IsObject(ranging_data_list_local)) {
				printf(
					"ranging_data_parseFromJSON() failed [ranging_data_list]");
				goto end;
			}
			positioning_method_and_usage_t *ranging_data_listItem =
				positioning_method_and_usage_parseFromJSON(
					ranging_data_list_local);
			if(!ranging_data_listItem) {
				printf("No ranging_data_listItem");
				goto end;
			}
			list_add(ranging_data_listList, ranging_data_listItem);
		}
	}

	related_applicationlayer_id = cJSON_GetObjectItemCaseSensitive(
		ranging_dataJSON, "relatedApplicationlayerId");
	if(related_applicationlayer_id) {
		if(!cJSON_IsString(related_applicationlayer_id) &&
		   !cJSON_IsNull(related_applicationlayer_id))
		{
			printf(
				"ranging_data_parseFromJSON() failed [related_applicationlayer_id]");
			goto end;
		}
	}

	range_direction = cJSON_GetObjectItemCaseSensitive(ranging_dataJSON,
	                                                   "rangeDirection");
	if(range_direction) {
		range_direction_local_nonprim = range_direction_parseFromJSON(
			range_direction);
		if(!range_direction_local_nonprim) {
			printf(
				"range_direction_parseFromJSON failed [range_direction]");
			goto end;
		}
	}

	_2d_relative_location = cJSON_GetObjectItemCaseSensitive(
		ranging_dataJSON, "2dRelativeLocation");
	if(_2d_relative_location) {
		_2d_relative_location_local_nonprim =
			model_2_d_relative_location_parseFromJSON(
				_2d_relative_location);
		if(!_2d_relative_location_local_nonprim) {
			printf(
				"model_2_d_relative_location_parseFromJSON failed [_2d_relative_location]");
			goto end;
		}
	}

	_3d_relative_location = cJSON_GetObjectItemCaseSensitive(
		ranging_dataJSON, "3dRelativeLocation");
	if(_3d_relative_location) {
		_3d_relative_location_local_nonprim =
			model_3_d_relative_location_parseFromJSON(
				_3d_relative_location);
		if(!_3d_relative_location_local_nonprim) {
			printf(
				"model_3_d_relative_location_parseFromJSON failed [_3d_relative_location]");
			goto end;
		}
	}

	relative_velocity = cJSON_GetObjectItemCaseSensitive(ranging_dataJSON,
	                                                     "relativeVelocity");
	if(relative_velocity) {
		relative_velocity_local_nonprim =
			velocity_estimate_parseFromJSON(relative_velocity);
		if(!relative_velocity_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [relative_velocity]");
			goto end;
		}
	}

	ranging_data_local_var = ranging_data_create(
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		timestamp_of_location_estimate &&
		!cJSON_IsNull(timestamp_of_location_estimate) ? strdup(
			timestamp_of_location_estimate->valuestring) : NULL,
		achieved_qos ? achieved_qos_local_nonprim : NULL,
		ranging_data_list ? ranging_data_listList : NULL,
		related_applicationlayer_id &&
		!cJSON_IsNull(related_applicationlayer_id) ? strdup(
			related_applicationlayer_id->valuestring) : NULL,
		range_direction ? range_direction_local_nonprim : NULL,
		_2d_relative_location ? _2d_relative_location_local_nonprim : NULL,
		_3d_relative_location ? _3d_relative_location_local_nonprim : NULL,
		relative_velocity ? relative_velocity_local_nonprim : NULL
		);

	return ranging_data_local_var;
end:
	if(achieved_qos_local_nonprim) {
		minor_location_qo_s_free(achieved_qos_local_nonprim);
		achieved_qos_local_nonprim = NULL;
	}
	if(ranging_data_listList) {
		list_for_each(ranging_data_listList, node) {
			positioning_method_and_usage_free(node->data);
		}
		list_free(ranging_data_listList);
		ranging_data_listList = NULL;
	}
	if(range_direction_local_nonprim) {
		range_direction_free(range_direction_local_nonprim);
		range_direction_local_nonprim = NULL;
	}
	if(_2d_relative_location_local_nonprim) {
		model_2_d_relative_location_free(
			_2d_relative_location_local_nonprim);
		_2d_relative_location_local_nonprim = NULL;
	}
	if(_3d_relative_location_local_nonprim) {
		model_3_d_relative_location_free(
			_3d_relative_location_local_nonprim);
		_3d_relative_location_local_nonprim = NULL;
	}
	if(relative_velocity_local_nonprim) {
		velocity_estimate_free(relative_velocity_local_nonprim);
		relative_velocity_local_nonprim = NULL;
	}
	return NULL;
}

ranging_data_t *ranging_data_copy(ranging_data_t *dst, ranging_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ranging_data_convertToJSON(src);
	if(!item) {
		printf("ranging_data_convertToJSON() failed");
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

	ranging_data_free(dst);
	dst = ranging_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
