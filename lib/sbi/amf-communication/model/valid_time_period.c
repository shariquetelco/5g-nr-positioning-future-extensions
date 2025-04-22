#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "valid_time_period.h"

valid_time_period_t *valid_time_period_create(char	*start_time,
                                              char	*end_time) {
	valid_time_period_t *valid_time_period_local_var =
		malloc(sizeof(valid_time_period_t));

	valid_time_period_local_var->start_time = start_time;
	valid_time_period_local_var->end_time = end_time;

	return valid_time_period_local_var;
}

void valid_time_period_free(valid_time_period_t *valid_time_period) {
	lnode_t *node = NULL;

	if(NULL == valid_time_period) {
		return;
	}
	if(valid_time_period->start_time) {
		free(valid_time_period->start_time);
		valid_time_period->start_time = NULL;
	}
	if(valid_time_period->end_time) {
		free(valid_time_period->end_time);
		valid_time_period->end_time = NULL;
	}
	free(valid_time_period);
}

cJSON *valid_time_period_convertToJSON(valid_time_period_t *valid_time_period) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(valid_time_period == NULL) {
		printf(
			"valid_time_period_convertToJSON() failed [ValidTimePeriod]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(valid_time_period->start_time) {
		if(cJSON_AddStringToObject(item, "startTime",
		                           valid_time_period->start_time) ==
		   NULL)
		{
			printf(
				"valid_time_period_convertToJSON() failed [start_time]");
			goto end;
		}
	}

	if(valid_time_period->end_time) {
		if(cJSON_AddStringToObject(item, "endTime",
		                           valid_time_period->end_time) == NULL)
		{
			printf(
				"valid_time_period_convertToJSON() failed [end_time]");
			goto end;
		}
	}

end:
	return item;
}

valid_time_period_t *valid_time_period_parseFromJSON(
	cJSON *valid_time_periodJSON) {
	valid_time_period_t *valid_time_period_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *start_time = NULL;
	cJSON *end_time = NULL;
	start_time = cJSON_GetObjectItemCaseSensitive(valid_time_periodJSON,
	                                              "startTime");
	if(start_time) {
		if(!cJSON_IsString(start_time) &&
		   !cJSON_IsNull(start_time))
		{
			printf(
				"valid_time_period_parseFromJSON() failed [start_time]");
			goto end;
		}
	}

	end_time = cJSON_GetObjectItemCaseSensitive(valid_time_periodJSON,
	                                            "endTime");
	if(end_time) {
		if(!cJSON_IsString(end_time) &&
		   !cJSON_IsNull(end_time))
		{
			printf(
				"valid_time_period_parseFromJSON() failed [end_time]");
			goto end;
		}
	}

	valid_time_period_local_var = valid_time_period_create(
		start_time &&
		!cJSON_IsNull(start_time) ? strdup(
			start_time->valuestring) : NULL,
		end_time &&
		!cJSON_IsNull(end_time) ? strdup(end_time->valuestring) : NULL
		);

	return valid_time_period_local_var;
end:
	return NULL;
}

valid_time_period_t *valid_time_period_copy(valid_time_period_t *dst,
                                            valid_time_period_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = valid_time_period_convertToJSON(src);
	if(!item) {
		printf("valid_time_period_convertToJSON() failed");
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

	valid_time_period_free(dst);
	dst = valid_time_period_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
