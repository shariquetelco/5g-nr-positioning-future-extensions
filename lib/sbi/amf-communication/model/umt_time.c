#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "umt_time.h"

umt_time_t *umt_time_create(char *time_of_day, int day_of_week) {
	umt_time_t *umt_time_local_var = malloc(sizeof(umt_time_t));

	umt_time_local_var->time_of_day = time_of_day;
	umt_time_local_var->day_of_week = day_of_week;

	return umt_time_local_var;
}

void umt_time_free(umt_time_t *umt_time) {
	lnode_t *node = NULL;

	if(NULL == umt_time) {
		return;
	}
	if(umt_time->time_of_day) {
		free(umt_time->time_of_day);
		umt_time->time_of_day = NULL;
	}
	free(umt_time);
}

cJSON *umt_time_convertToJSON(umt_time_t *umt_time) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(umt_time == NULL) {
		printf("umt_time_convertToJSON() failed [UmtTime]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!umt_time->time_of_day) {
		printf("umt_time_convertToJSON() failed [time_of_day]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "timeOfDay",
	                           umt_time->time_of_day) == NULL)
	{
		printf("umt_time_convertToJSON() failed [time_of_day]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "dayOfWeek",
	                           umt_time->day_of_week) == NULL)
	{
		printf("umt_time_convertToJSON() failed [day_of_week]");
		goto end;
	}

end:
	return item;
}

umt_time_t *umt_time_parseFromJSON(cJSON *umt_timeJSON) {
	umt_time_t *umt_time_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *time_of_day = NULL;
	cJSON *day_of_week = NULL;
	time_of_day =
		cJSON_GetObjectItemCaseSensitive(umt_timeJSON, "timeOfDay");
	if(!time_of_day) {
		printf("umt_time_parseFromJSON() failed [time_of_day]");
		goto end;
	}
	if(!cJSON_IsString(time_of_day)) {
		printf("umt_time_parseFromJSON() failed [time_of_day]");
		goto end;
	}

	day_of_week =
		cJSON_GetObjectItemCaseSensitive(umt_timeJSON, "dayOfWeek");
	if(!day_of_week) {
		printf("umt_time_parseFromJSON() failed [day_of_week]");
		goto end;
	}
	if(!cJSON_IsNumber(day_of_week)) {
		printf("umt_time_parseFromJSON() failed [day_of_week]");
		goto end;
	}

	umt_time_local_var = umt_time_create(
		strdup(time_of_day->valuestring),

		day_of_week->valuedouble
		);

	return umt_time_local_var;
end:
	return NULL;
}

umt_time_t *umt_time_copy(umt_time_t *dst, umt_time_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = umt_time_convertToJSON(src);
	if(!item) {
		printf("umt_time_convertToJSON() failed");
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

	umt_time_free(dst);
	dst = umt_time_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
