#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "time_window.h"

time_window_t *time_window_create(char *start_time, char *stop_time) {
	time_window_t *time_window_local_var = malloc(sizeof(time_window_t));

	time_window_local_var->start_time = start_time;
	time_window_local_var->stop_time = stop_time;

	return time_window_local_var;
}

void time_window_free(time_window_t *time_window) {
	lnode_t *node = NULL;

	if(NULL == time_window) {
		return;
	}
	if(time_window->start_time) {
		free(time_window->start_time);
		time_window->start_time = NULL;
	}
	if(time_window->stop_time) {
		free(time_window->stop_time);
		time_window->stop_time = NULL;
	}
	free(time_window);
}

cJSON *time_window_convertToJSON(time_window_t *time_window) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(time_window == NULL) {
		printf("time_window_convertToJSON() failed [TimeWindow]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!time_window->start_time) {
		printf("time_window_convertToJSON() failed [start_time]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "startTime",
	                           time_window->start_time) == NULL)
	{
		printf("time_window_convertToJSON() failed [start_time]");
		goto end;
	}

	if(!time_window->stop_time) {
		printf("time_window_convertToJSON() failed [stop_time]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "stopTime",
	                           time_window->stop_time) == NULL)
	{
		printf("time_window_convertToJSON() failed [stop_time]");
		goto end;
	}

end:
	return item;
}

time_window_t *time_window_parseFromJSON(cJSON *time_windowJSON) {
	time_window_t *time_window_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *start_time = NULL;
	cJSON *stop_time = NULL;
	start_time = cJSON_GetObjectItemCaseSensitive(time_windowJSON,
	                                              "startTime");
	if(!start_time) {
		printf("time_window_parseFromJSON() failed [start_time]");
		goto end;
	}
	if(!cJSON_IsString(start_time) &&
	   !cJSON_IsNull(start_time))
	{
		printf("time_window_parseFromJSON() failed [start_time]");
		goto end;
	}

	stop_time =
		cJSON_GetObjectItemCaseSensitive(time_windowJSON, "stopTime");
	if(!stop_time) {
		printf("time_window_parseFromJSON() failed [stop_time]");
		goto end;
	}
	if(!cJSON_IsString(stop_time) &&
	   !cJSON_IsNull(stop_time))
	{
		printf("time_window_parseFromJSON() failed [stop_time]");
		goto end;
	}

	time_window_local_var = time_window_create(
		strdup(start_time->valuestring),
		strdup(stop_time->valuestring)
		);

	return time_window_local_var;
end:
	return NULL;
}

time_window_t *time_window_copy(time_window_t *dst, time_window_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = time_window_convertToJSON(src);
	if(!item) {
		printf("time_window_convertToJSON() failed");
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

	time_window_free(dst);
	dst = time_window_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
