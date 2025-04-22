#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "motion_event_info.h"

motion_event_info_t *motion_event_info_create(int		linear_distance,
                                              occurrence_info_e occurrence_info,
                                              bool		is_minimum_interval,
                                              int		minimum_interval,
                                              bool		is_maximum_interval,
                                              int		maximum_interval,
                                              bool		is_sampling_interval,
                                              int		sampling_interval,
                                              bool		is_reporting_duration,
                                              int		reporting_duration,
                                              bool		is_reporting_location_req,
                                              int		reporting_location_req)
{
	motion_event_info_t *motion_event_info_local_var =
		malloc(sizeof(motion_event_info_t));

	motion_event_info_local_var->linear_distance = linear_distance;
	motion_event_info_local_var->occurrence_info = occurrence_info;
	motion_event_info_local_var->is_minimum_interval = is_minimum_interval;
	motion_event_info_local_var->minimum_interval = minimum_interval;
	motion_event_info_local_var->is_maximum_interval = is_maximum_interval;
	motion_event_info_local_var->maximum_interval = maximum_interval;
	motion_event_info_local_var->is_sampling_interval =
		is_sampling_interval;
	motion_event_info_local_var->sampling_interval = sampling_interval;
	motion_event_info_local_var->is_reporting_duration =
		is_reporting_duration;
	motion_event_info_local_var->reporting_duration = reporting_duration;
	motion_event_info_local_var->is_reporting_location_req =
		is_reporting_location_req;
	motion_event_info_local_var->reporting_location_req =
		reporting_location_req;

	return motion_event_info_local_var;
}

void motion_event_info_free(motion_event_info_t *motion_event_info) {
	lnode_t *node = NULL;

	if(NULL == motion_event_info) {
		return;
	}
	free(motion_event_info);
}

cJSON *motion_event_info_convertToJSON(motion_event_info_t *motion_event_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(motion_event_info == NULL) {
		printf(
			"motion_event_info_convertToJSON() failed [MotionEventInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "linearDistance",
	                           motion_event_info->linear_distance) == NULL)
	{
		printf(
			"motion_event_info_convertToJSON() failed [linear_distance]");
		goto end;
	}

	if(motion_event_info->occurrence_info != occurrence_info_NULL) {
		if(cJSON_AddStringToObject(item, "occurrenceInfo",
		                           occurrence_info_ToString(
						   motion_event_info->
						   occurrence_info)) ==
		   NULL)
		{
			printf(
				"motion_event_info_convertToJSON() failed [occurrence_info]");
			goto end;
		}
	}

	if(motion_event_info->is_minimum_interval) {
		if(cJSON_AddNumberToObject(item, "minimumInterval",
		                           motion_event_info->minimum_interval)
		   == NULL)
		{
			printf(
				"motion_event_info_convertToJSON() failed [minimum_interval]");
			goto end;
		}
	}

	if(motion_event_info->is_maximum_interval) {
		if(cJSON_AddNumberToObject(item, "maximumInterval",
		                           motion_event_info->maximum_interval)
		   == NULL)
		{
			printf(
				"motion_event_info_convertToJSON() failed [maximum_interval]");
			goto end;
		}
	}

	if(motion_event_info->is_sampling_interval) {
		if(cJSON_AddNumberToObject(item, "samplingInterval",
		                           motion_event_info->sampling_interval)
		   == NULL)
		{
			printf(
				"motion_event_info_convertToJSON() failed [sampling_interval]");
			goto end;
		}
	}

	if(motion_event_info->is_reporting_duration) {
		if(cJSON_AddNumberToObject(item, "reportingDuration",
		                           motion_event_info->reporting_duration)
		   == NULL)
		{
			printf(
				"motion_event_info_convertToJSON() failed [reporting_duration]");
			goto end;
		}
	}

	if(motion_event_info->is_reporting_location_req) {
		if(cJSON_AddBoolToObject(item, "reportingLocationReq",
		                         motion_event_info->
		                         reporting_location_req) == NULL)
		{
			printf(
				"motion_event_info_convertToJSON() failed [reporting_location_req]");
			goto end;
		}
	}

end:
	return item;
}

motion_event_info_t *motion_event_info_parseFromJSON(
	cJSON *motion_event_infoJSON) {
	motion_event_info_t *motion_event_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *linear_distance = NULL;
	cJSON *occurrence_info = NULL;
	occurrence_info_e occurrence_infoVariable = 0;
	cJSON *minimum_interval = NULL;
	cJSON *maximum_interval = NULL;
	cJSON *sampling_interval = NULL;
	cJSON *reporting_duration = NULL;
	cJSON *reporting_location_req = NULL;
	linear_distance = cJSON_GetObjectItemCaseSensitive(
		motion_event_infoJSON, "linearDistance");
	if(!linear_distance) {
		printf(
			"motion_event_info_parseFromJSON() failed [linear_distance]");
		goto end;
	}
	if(!cJSON_IsNumber(linear_distance)) {
		printf(
			"motion_event_info_parseFromJSON() failed [linear_distance]");
		goto end;
	}

	occurrence_info = cJSON_GetObjectItemCaseSensitive(
		motion_event_infoJSON, "occurrenceInfo");
	if(occurrence_info) {
		if(!cJSON_IsString(occurrence_info)) {
			printf(
				"motion_event_info_parseFromJSON() failed [occurrence_info]");
			goto end;
		}
		occurrence_infoVariable = occurrence_info_FromString(
			occurrence_info->valuestring);
	}

	minimum_interval = cJSON_GetObjectItemCaseSensitive(
		motion_event_infoJSON, "minimumInterval");
	if(minimum_interval) {
		if(!cJSON_IsNumber(minimum_interval)) {
			printf(
				"motion_event_info_parseFromJSON() failed [minimum_interval]");
			goto end;
		}
	}

	maximum_interval = cJSON_GetObjectItemCaseSensitive(
		motion_event_infoJSON, "maximumInterval");
	if(maximum_interval) {
		if(!cJSON_IsNumber(maximum_interval)) {
			printf(
				"motion_event_info_parseFromJSON() failed [maximum_interval]");
			goto end;
		}
	}

	sampling_interval = cJSON_GetObjectItemCaseSensitive(
		motion_event_infoJSON, "samplingInterval");
	if(sampling_interval) {
		if(!cJSON_IsNumber(sampling_interval)) {
			printf(
				"motion_event_info_parseFromJSON() failed [sampling_interval]");
			goto end;
		}
	}

	reporting_duration = cJSON_GetObjectItemCaseSensitive(
		motion_event_infoJSON, "reportingDuration");
	if(reporting_duration) {
		if(!cJSON_IsNumber(reporting_duration)) {
			printf(
				"motion_event_info_parseFromJSON() failed [reporting_duration]");
			goto end;
		}
	}

	reporting_location_req = cJSON_GetObjectItemCaseSensitive(
		motion_event_infoJSON, "reportingLocationReq");
	if(reporting_location_req) {
		if(!cJSON_IsBool(reporting_location_req)) {
			printf(
				"motion_event_info_parseFromJSON() failed [reporting_location_req]");
			goto end;
		}
	}

	motion_event_info_local_var = motion_event_info_create(

		linear_distance->valuedouble,
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

	return motion_event_info_local_var;
end:
	return NULL;
}

motion_event_info_t *motion_event_info_copy(motion_event_info_t *dst,
                                            motion_event_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = motion_event_info_convertToJSON(src);
	if(!item) {
		printf("motion_event_info_convertToJSON() failed");
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

	motion_event_info_free(dst);
	dst = motion_event_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
