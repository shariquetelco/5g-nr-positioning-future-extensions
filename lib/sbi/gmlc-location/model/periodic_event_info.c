#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "periodic_event_info.h"

char *reporting_infinite_indperiodic_event_info_ToString(
	periodic_event_info_reporting_infinite_ind_e reporting_infinite_ind) {
	const char *reporting_infinite_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(reporting_infinite_indArray) /
	                     sizeof(reporting_infinite_indArray[0]);
	if(reporting_infinite_ind < sizeofArray) {
		return (char *) reporting_infinite_indArray[
			reporting_infinite_ind];
	} else {
		return (char *) "Unknown";
	}
}

periodic_event_info_reporting_infinite_ind_e
reporting_infinite_indperiodic_event_info_FromString(
	char *reporting_infinite_ind) {
	int stringToReturn = 0;
	const char *reporting_infinite_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(reporting_infinite_indArray) /
	                     sizeof(reporting_infinite_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(reporting_infinite_ind,
		          reporting_infinite_indArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
periodic_event_info_t *periodic_event_info_create(int reporting_amount,
                                                  int reporting_interval,
                                                  periodic_event_info_reporting_infinite_ind_e reporting_infinite_ind, bool is_reporting_interval_ms,
                                                  int reporting_interval_ms) {
	periodic_event_info_t *periodic_event_info_local_var =
		malloc(sizeof(periodic_event_info_t));

	periodic_event_info_local_var->reporting_amount = reporting_amount;
	periodic_event_info_local_var->reporting_interval = reporting_interval;
	periodic_event_info_local_var->reporting_infinite_ind =
		reporting_infinite_ind;
	periodic_event_info_local_var->is_reporting_interval_ms =
		is_reporting_interval_ms;
	periodic_event_info_local_var->reporting_interval_ms =
		reporting_interval_ms;

	return periodic_event_info_local_var;
}

void periodic_event_info_free(periodic_event_info_t *periodic_event_info) {
	lnode_t *node = NULL;

	if(NULL == periodic_event_info) {
		return;
	}
	free(periodic_event_info);
}

cJSON *periodic_event_info_convertToJSON(
	periodic_event_info_t *periodic_event_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(periodic_event_info == NULL) {
		printf(
			"periodic_event_info_convertToJSON() failed [PeriodicEventInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "reportingAmount",
	                           periodic_event_info->reporting_amount) ==
	   NULL)
	{
		printf(
			"periodic_event_info_convertToJSON() failed [reporting_amount]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "reportingInterval",
	                           periodic_event_info->reporting_interval) ==
	   NULL)
	{
		printf(
			"periodic_event_info_convertToJSON() failed [reporting_interval]");
		goto end;
	}

	if(periodic_event_info->reporting_infinite_ind !=
	   periodic_event_info_REPORTINGINFINITEIND_NULL)
	{
		if(cJSON_AddStringToObject(item, "reportingInfiniteInd",
		                           reporting_infinite_indperiodic_event_info_ToString(
						   periodic_event_info->
						   reporting_infinite_ind)) ==
		   NULL)
		{
			printf(
				"periodic_event_info_convertToJSON() failed [reporting_infinite_ind]");
			goto end;
		}
	}

	if(periodic_event_info->is_reporting_interval_ms) {
		if(cJSON_AddNumberToObject(item, "reportingIntervalMs",
		                           periodic_event_info->
		                           reporting_interval_ms) == NULL)
		{
			printf(
				"periodic_event_info_convertToJSON() failed [reporting_interval_ms]");
			goto end;
		}
	}

end:
	return item;
}

periodic_event_info_t *periodic_event_info_parseFromJSON(
	cJSON *periodic_event_infoJSON) {
	periodic_event_info_t *periodic_event_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *reporting_amount = NULL;
	cJSON *reporting_interval = NULL;
	cJSON *reporting_infinite_ind = NULL;
	periodic_event_info_reporting_infinite_ind_e
	        reporting_infinite_indVariable = 0;
	cJSON *reporting_interval_ms = NULL;
	reporting_amount = cJSON_GetObjectItemCaseSensitive(
		periodic_event_infoJSON, "reportingAmount");
	if(!reporting_amount) {
		printf(
			"periodic_event_info_parseFromJSON() failed [reporting_amount]");
		goto end;
	}
	if(!cJSON_IsNumber(reporting_amount)) {
		printf(
			"periodic_event_info_parseFromJSON() failed [reporting_amount]");
		goto end;
	}

	reporting_interval = cJSON_GetObjectItemCaseSensitive(
		periodic_event_infoJSON, "reportingInterval");
	if(!reporting_interval) {
		printf(
			"periodic_event_info_parseFromJSON() failed [reporting_interval]");
		goto end;
	}
	if(!cJSON_IsNumber(reporting_interval)) {
		printf(
			"periodic_event_info_parseFromJSON() failed [reporting_interval]");
		goto end;
	}

	reporting_infinite_ind = cJSON_GetObjectItemCaseSensitive(
		periodic_event_infoJSON, "reportingInfiniteInd");
	if(reporting_infinite_ind) {
		if(!cJSON_IsString(reporting_infinite_ind)) {
			printf(
				"periodic_event_info_parseFromJSON() failed [reporting_infinite_ind]");
			goto end;
		}
		reporting_infinite_indVariable =
			reporting_infinite_indperiodic_event_info_FromString(
				reporting_infinite_ind->valuestring);
	}

	reporting_interval_ms = cJSON_GetObjectItemCaseSensitive(
		periodic_event_infoJSON, "reportingIntervalMs");
	if(reporting_interval_ms) {
		if(!cJSON_IsNumber(reporting_interval_ms)) {
			printf(
				"periodic_event_info_parseFromJSON() failed [reporting_interval_ms]");
			goto end;
		}
	}

	periodic_event_info_local_var = periodic_event_info_create(

		reporting_amount->valuedouble,

		reporting_interval->valuedouble,
		reporting_infinite_ind ? reporting_infinite_indVariable : 0,
		reporting_interval_ms ? true : false,
		reporting_interval_ms ? reporting_interval_ms->valuedouble : 0
		);

	return periodic_event_info_local_var;
end:
	return NULL;
}

periodic_event_info_t *periodic_event_info_copy(periodic_event_info_t	*dst,
                                                periodic_event_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = periodic_event_info_convertToJSON(src);
	if(!item) {
		printf("periodic_event_info_convertToJSON() failed");
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

	periodic_event_info_free(dst);
	dst = periodic_event_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
