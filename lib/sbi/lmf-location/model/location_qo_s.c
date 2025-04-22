#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_qo_s.h"

location_qo_s_t *location_qo_s_create(bool is_h_accuracy, float h_accuracy,
                                      bool is_v_accuracy, float v_accuracy,
                                      bool is_vertical_requested,
                                      int vertical_requested,
                                      response_time_e response_time,
                                      list_t *minor_loc_qoses,
                                      lcs_qos_class_e lcs_qos_class) {
	location_qo_s_t *location_qo_s_local_var = malloc(
		sizeof(location_qo_s_t));

	location_qo_s_local_var->is_h_accuracy = is_h_accuracy;
	location_qo_s_local_var->h_accuracy = h_accuracy;
	location_qo_s_local_var->is_v_accuracy = is_v_accuracy;
	location_qo_s_local_var->v_accuracy = v_accuracy;
	location_qo_s_local_var->is_vertical_requested = is_vertical_requested;
	location_qo_s_local_var->vertical_requested = vertical_requested;
	location_qo_s_local_var->response_time = response_time;
	location_qo_s_local_var->minor_loc_qoses = minor_loc_qoses;
	location_qo_s_local_var->lcs_qos_class = lcs_qos_class;

	return location_qo_s_local_var;
}

void location_qo_s_free(location_qo_s_t *location_qo_s) {
	lnode_t *node = NULL;

	if(NULL == location_qo_s) {
		return;
	}
	if(location_qo_s->minor_loc_qoses) {
		list_for_each(location_qo_s->minor_loc_qoses, node) {
			minor_location_qo_s_free(node->data);
		}
		list_free(location_qo_s->minor_loc_qoses);
		location_qo_s->minor_loc_qoses = NULL;
	}
	free(location_qo_s);
}

cJSON *location_qo_s_convertToJSON(location_qo_s_t *location_qo_s) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(location_qo_s == NULL) {
		printf("location_qo_s_convertToJSON() failed [LocationQoS]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(location_qo_s->is_h_accuracy) {
		if(cJSON_AddNumberToObject(item, "hAccuracy",
		                           location_qo_s->h_accuracy) == NULL)
		{
			printf(
				"location_qo_s_convertToJSON() failed [h_accuracy]");
			goto end;
		}
	}

	if(location_qo_s->is_v_accuracy) {
		if(cJSON_AddNumberToObject(item, "vAccuracy",
		                           location_qo_s->v_accuracy) == NULL)
		{
			printf(
				"location_qo_s_convertToJSON() failed [v_accuracy]");
			goto end;
		}
	}

	if(location_qo_s->is_vertical_requested) {
		if(cJSON_AddBoolToObject(item, "verticalRequested",
		                         location_qo_s->vertical_requested) ==
		   NULL)
		{
			printf(
				"location_qo_s_convertToJSON() failed [vertical_requested]");
			goto end;
		}
	}

	if(location_qo_s->response_time != response_time_NULL) {
		if(cJSON_AddStringToObject(item, "responseTime",
		                           response_time_ToString(location_qo_s
		                                                  ->
		                                                  response_time))
		   == NULL)
		{
			printf(
				"location_qo_s_convertToJSON() failed [response_time]");
			goto end;
		}
	}

	if(location_qo_s->minor_loc_qoses) {
		cJSON *minor_loc_qosesList = cJSON_AddArrayToObject(item,
		                                                    "minorLocQoses");
		if(minor_loc_qosesList == NULL) {
			printf(
				"location_qo_s_convertToJSON() failed [minor_loc_qoses]");
			goto end;
		}
		list_for_each(location_qo_s->minor_loc_qoses, node) {
			cJSON *itemLocal = minor_location_qo_s_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"location_qo_s_convertToJSON() failed [minor_loc_qoses]");
				goto end;
			}
			cJSON_AddItemToArray(minor_loc_qosesList, itemLocal);
		}
	}

	if(location_qo_s->lcs_qos_class != lcs_qos_class_NULL) {
		if(cJSON_AddStringToObject(item, "lcsQosClass",
		                           lcs_qos_class_ToString(location_qo_s
		                                                  ->
		                                                  lcs_qos_class))
		   == NULL)
		{
			printf(
				"location_qo_s_convertToJSON() failed [lcs_qos_class]");
			goto end;
		}
	}

end:
	return item;
}

location_qo_s_t *location_qo_s_parseFromJSON(cJSON *location_qo_sJSON) {
	location_qo_s_t *location_qo_s_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *h_accuracy = NULL;
	cJSON *v_accuracy = NULL;
	cJSON *vertical_requested = NULL;
	cJSON *response_time = NULL;
	response_time_e response_timeVariable = 0;
	cJSON *minor_loc_qoses = NULL;
	list_t *minor_loc_qosesList = NULL;
	cJSON *lcs_qos_class = NULL;
	lcs_qos_class_e lcs_qos_classVariable = 0;
	h_accuracy = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON,
	                                              "hAccuracy");
	if(h_accuracy) {
		if(!cJSON_IsNumber(h_accuracy)) {
			printf(
				"location_qo_s_parseFromJSON() failed [h_accuracy]");
			goto end;
		}
	}

	v_accuracy = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON,
	                                              "vAccuracy");
	if(v_accuracy) {
		if(!cJSON_IsNumber(v_accuracy)) {
			printf(
				"location_qo_s_parseFromJSON() failed [v_accuracy]");
			goto end;
		}
	}

	vertical_requested = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON,
	                                                      "verticalRequested");
	if(vertical_requested) {
		if(!cJSON_IsBool(vertical_requested)) {
			printf(
				"location_qo_s_parseFromJSON() failed [vertical_requested]");
			goto end;
		}
	}

	response_time = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON,
	                                                 "responseTime");
	if(response_time) {
		if(!cJSON_IsString(response_time)) {
			printf(
				"location_qo_s_parseFromJSON() failed [response_time]");
			goto end;
		}
		response_timeVariable = response_time_FromString(
			response_time->valuestring);
	}

	minor_loc_qoses = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON,
	                                                   "minorLocQoses");
	if(minor_loc_qoses) {
		cJSON *minor_loc_qoses_local = NULL;
		if(!cJSON_IsArray(minor_loc_qoses)) {
			printf(
				"location_qo_s_parseFromJSON() failed [minor_loc_qoses]");
			goto end;
		}

		minor_loc_qosesList = list_create();

		cJSON_ArrayForEach(minor_loc_qoses_local, minor_loc_qoses) {
			if(!cJSON_IsObject(minor_loc_qoses_local)) {
				printf(
					"location_qo_s_parseFromJSON() failed [minor_loc_qoses]");
				goto end;
			}
			minor_location_qo_s_t *minor_loc_qosesItem =
				minor_location_qo_s_parseFromJSON(
					minor_loc_qoses_local);
			if(!minor_loc_qosesItem) {
				printf("No minor_loc_qosesItem");
				goto end;
			}
			list_add(minor_loc_qosesList, minor_loc_qosesItem);
		}
	}

	lcs_qos_class = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON,
	                                                 "lcsQosClass");
	if(lcs_qos_class) {
		if(!cJSON_IsString(lcs_qos_class)) {
			printf(
				"location_qo_s_parseFromJSON() failed [lcs_qos_class]");
			goto end;
		}
		lcs_qos_classVariable = lcs_qos_class_FromString(
			lcs_qos_class->valuestring);
	}

	location_qo_s_local_var = location_qo_s_create(
		h_accuracy ? true : false,
		h_accuracy ? h_accuracy->valuedouble : 0,
		v_accuracy ? true : false,
		v_accuracy ? v_accuracy->valuedouble : 0,
		vertical_requested ? true : false,
		vertical_requested ? vertical_requested->valueint : 0,
		response_time ? response_timeVariable : 0,
		minor_loc_qoses ? minor_loc_qosesList : NULL,
		lcs_qos_class ? lcs_qos_classVariable : 0
		);

	return location_qo_s_local_var;
end:
	if(minor_loc_qosesList) {
		list_for_each(minor_loc_qosesList, node) {
			minor_location_qo_s_free(node->data);
		}
		list_free(minor_loc_qosesList);
		minor_loc_qosesList = NULL;
	}
	return NULL;
}

location_qo_s_t *location_qo_s_copy(location_qo_s_t	*dst,
                                    location_qo_s_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = location_qo_s_convertToJSON(src);
	if(!item) {
		printf("location_qo_s_convertToJSON() failed");
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

	location_qo_s_free(dst);
	dst = location_qo_s_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
