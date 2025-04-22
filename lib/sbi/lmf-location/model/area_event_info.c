#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "area_event_info.h"

area_event_info_t *area_event_info_create(
	list_t			*area_definition,
	occurrence_info_e	occurrence_info,
	bool			is_minimum_interval,
	int			minimum_interval,
	bool			is_maximum_interval,
	int			maximum_interval,
	bool			is_sampling_interval,
	int			sampling_interval,
	bool			is_reporting_duration,
	int			reporting_duration,
	bool			is_reporting_location_req,
	int			reporting_location_req)
{
	area_event_info_t *area_event_info_local_var =
		malloc(sizeof(area_event_info_t));

	area_event_info_local_var->area_definition = area_definition;
	area_event_info_local_var->occurrence_info = occurrence_info;
	area_event_info_local_var->is_minimum_interval = is_minimum_interval;
	area_event_info_local_var->minimum_interval = minimum_interval;
	area_event_info_local_var->is_maximum_interval = is_maximum_interval;
	area_event_info_local_var->maximum_interval = maximum_interval;
	area_event_info_local_var->is_sampling_interval = is_sampling_interval;
	area_event_info_local_var->sampling_interval = sampling_interval;
	area_event_info_local_var->is_reporting_duration =
		is_reporting_duration;
	area_event_info_local_var->reporting_duration = reporting_duration;
	area_event_info_local_var->is_reporting_location_req =
		is_reporting_location_req;
	area_event_info_local_var->reporting_location_req =
		reporting_location_req;

	return area_event_info_local_var;
}

void area_event_info_free(area_event_info_t *area_event_info) {
	lnode_t *node = NULL;

	if(NULL == area_event_info) {
		return;
	}
	if(area_event_info->area_definition) {
		list_for_each(area_event_info->area_definition, node) {
			reporting_area_free(node->data);
		}
		list_free(area_event_info->area_definition);
		area_event_info->area_definition = NULL;
	}
	free(area_event_info);
}

cJSON *area_event_info_convertToJSON(area_event_info_t *area_event_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(area_event_info == NULL) {
		printf("area_event_info_convertToJSON() failed [AreaEventInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!area_event_info->area_definition) {
		printf(
			"area_event_info_convertToJSON() failed [area_definition]");
		return NULL;
	}
	cJSON *area_definitionList = cJSON_AddArrayToObject(item,
	                                                    "areaDefinition");
	if(area_definitionList == NULL) {
		printf(
			"area_event_info_convertToJSON() failed [area_definition]");
		goto end;
	}
	list_for_each(area_event_info->area_definition, node) {
		cJSON *itemLocal = reporting_area_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"area_event_info_convertToJSON() failed [area_definition]");
			goto end;
		}
		cJSON_AddItemToArray(area_definitionList, itemLocal);
	}

	if(area_event_info->occurrence_info != occurrence_info_NULL) {
		if(cJSON_AddStringToObject(item, "occurrenceInfo",
		                           occurrence_info_ToString(
						   area_event_info->
						   occurrence_info)) ==
		   NULL)
		{
			printf(
				"area_event_info_convertToJSON() failed [occurrence_info]");
			goto end;
		}
	}

	if(area_event_info->is_minimum_interval) {
		if(cJSON_AddNumberToObject(item, "minimumInterval",
		                           area_event_info->minimum_interval) ==
		   NULL)
		{
			printf(
				"area_event_info_convertToJSON() failed [minimum_interval]");
			goto end;
		}
	}

	if(area_event_info->is_maximum_interval) {
		if(cJSON_AddNumberToObject(item, "maximumInterval",
		                           area_event_info->maximum_interval) ==
		   NULL)
		{
			printf(
				"area_event_info_convertToJSON() failed [maximum_interval]");
			goto end;
		}
	}

	if(area_event_info->is_sampling_interval) {
		if(cJSON_AddNumberToObject(item, "samplingInterval",
		                           area_event_info->sampling_interval)
		   == NULL)
		{
			printf(
				"area_event_info_convertToJSON() failed [sampling_interval]");
			goto end;
		}
	}

	if(area_event_info->is_reporting_duration) {
		if(cJSON_AddNumberToObject(item, "reportingDuration",
		                           area_event_info->reporting_duration)
		   == NULL)
		{
			printf(
				"area_event_info_convertToJSON() failed [reporting_duration]");
			goto end;
		}
	}

	if(area_event_info->is_reporting_location_req) {
		if(cJSON_AddBoolToObject(item, "reportingLocationReq",
		                         area_event_info->reporting_location_req)
		   == NULL)
		{
			printf(
				"area_event_info_convertToJSON() failed [reporting_location_req]");
			goto end;
		}
	}

end:
	return item;
}

area_event_info_t *area_event_info_parseFromJSON(cJSON *area_event_infoJSON) {
	area_event_info_t *area_event_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *area_definition = NULL;
	list_t *area_definitionList = NULL;
	cJSON *occurrence_info = NULL;
	occurrence_info_e occurrence_infoVariable = 0;
	cJSON *minimum_interval = NULL;
	cJSON *maximum_interval = NULL;
	cJSON *sampling_interval = NULL;
	cJSON *reporting_duration = NULL;
	cJSON *reporting_location_req = NULL;
	area_definition = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON,
	                                                   "areaDefinition");
	if(!area_definition) {
		printf(
			"area_event_info_parseFromJSON() failed [area_definition]");
		goto end;
	}
	cJSON *area_definition_local = NULL;
	if(!cJSON_IsArray(area_definition)) {
		printf(
			"area_event_info_parseFromJSON() failed [area_definition]");
		goto end;
	}

	area_definitionList = list_create();

	cJSON_ArrayForEach(area_definition_local, area_definition) {
		if(!cJSON_IsObject(area_definition_local)) {
			printf(
				"area_event_info_parseFromJSON() failed [area_definition]");
			goto end;
		}
		reporting_area_t *area_definitionItem =
			reporting_area_parseFromJSON(area_definition_local);
		if(!area_definitionItem) {
			printf("No area_definitionItem");
			goto end;
		}
		list_add(area_definitionList, area_definitionItem);
	}

	occurrence_info = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON,
	                                                   "occurrenceInfo");
	if(occurrence_info) {
		if(!cJSON_IsString(occurrence_info)) {
			printf(
				"area_event_info_parseFromJSON() failed [occurrence_info]");
			goto end;
		}
		occurrence_infoVariable = occurrence_info_FromString(
			occurrence_info->valuestring);
	}

	minimum_interval = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON,
	                                                    "minimumInterval");
	if(minimum_interval) {
		if(!cJSON_IsNumber(minimum_interval)) {
			printf(
				"area_event_info_parseFromJSON() failed [minimum_interval]");
			goto end;
		}
	}

	maximum_interval = cJSON_GetObjectItemCaseSensitive(area_event_infoJSON,
	                                                    "maximumInterval");
	if(maximum_interval) {
		if(!cJSON_IsNumber(maximum_interval)) {
			printf(
				"area_event_info_parseFromJSON() failed [maximum_interval]");
			goto end;
		}
	}

	sampling_interval = cJSON_GetObjectItemCaseSensitive(
		area_event_infoJSON, "samplingInterval");
	if(sampling_interval) {
		if(!cJSON_IsNumber(sampling_interval)) {
			printf(
				"area_event_info_parseFromJSON() failed [sampling_interval]");
			goto end;
		}
	}

	reporting_duration = cJSON_GetObjectItemCaseSensitive(
		area_event_infoJSON, "reportingDuration");
	if(reporting_duration) {
		if(!cJSON_IsNumber(reporting_duration)) {
			printf(
				"area_event_info_parseFromJSON() failed [reporting_duration]");
			goto end;
		}
	}

	reporting_location_req = cJSON_GetObjectItemCaseSensitive(
		area_event_infoJSON, "reportingLocationReq");
	if(reporting_location_req) {
		if(!cJSON_IsBool(reporting_location_req)) {
			printf(
				"area_event_info_parseFromJSON() failed [reporting_location_req]");
			goto end;
		}
	}

	area_event_info_local_var = area_event_info_create(
		area_definitionList,
		occurrence_info ? occurrence_infoVariable : 0,
		minimum_interval ? true : false,
		minimum_interval ? minimum_interval->valuedouble : 0,
		maximum_interval ? true : false,
		maximum_interval ? maximum_interval->valuedouble : 0,
		sampling_interval ? true : false,
		sampling_interval ? sampling_interval->valuedouble : 0,
		reporting_duration ? true : false,
		reporting_duration ? reporting_duration->valuedouble : 0,
		reporting_location_req ? true : false,
		reporting_location_req ? reporting_location_req->valueint : 0
		);

	return area_event_info_local_var;
end:
	if(area_definitionList) {
		list_for_each(area_definitionList, node) {
			reporting_area_free(node->data);
		}
		list_free(area_definitionList);
		area_definitionList = NULL;
	}
	return NULL;
}

area_event_info_t *area_event_info_copy(area_event_info_t	*dst,
                                        area_event_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = area_event_info_convertToJSON(src);
	if(!item) {
		printf("area_event_info_convertToJSON() failed");
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

	area_event_info_free(dst);
	dst = area_event_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
