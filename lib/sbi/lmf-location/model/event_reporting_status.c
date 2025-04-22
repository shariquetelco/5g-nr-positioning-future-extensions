#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_reporting_status.h"

event_reporting_status_t *event_reporting_status_create(
	bool is_event_report_counter, int event_report_counter,
	bool is_event_report_duration, int event_report_duration) {
	event_reporting_status_t *event_reporting_status_local_var = malloc(
		sizeof(event_reporting_status_t));

	event_reporting_status_local_var->is_event_report_counter =
		is_event_report_counter;
	event_reporting_status_local_var->event_report_counter =
		event_report_counter;
	event_reporting_status_local_var->is_event_report_duration =
		is_event_report_duration;
	event_reporting_status_local_var->event_report_duration =
		event_report_duration;

	return event_reporting_status_local_var;
}

void event_reporting_status_free(
	event_reporting_status_t *event_reporting_status) {
	lnode_t *node = NULL;

	if(NULL == event_reporting_status) {
		return;
	}
	free(event_reporting_status);
}

cJSON *event_reporting_status_convertToJSON(
	event_reporting_status_t *event_reporting_status) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(event_reporting_status == NULL) {
		printf(
			"event_reporting_status_convertToJSON() failed [EventReportingStatus]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(event_reporting_status->is_event_report_counter) {
		if(cJSON_AddNumberToObject(item, "eventReportCounter",
		                           event_reporting_status->
		                           event_report_counter) == NULL)
		{
			printf(
				"event_reporting_status_convertToJSON() failed [event_report_counter]");
			goto end;
		}
	}

	if(event_reporting_status->is_event_report_duration) {
		if(cJSON_AddNumberToObject(item, "eventReportDuration",
		                           event_reporting_status->
		                           event_report_duration) == NULL)
		{
			printf(
				"event_reporting_status_convertToJSON() failed [event_report_duration]");
			goto end;
		}
	}

end:
	return item;
}

event_reporting_status_t *event_reporting_status_parseFromJSON(
	cJSON *event_reporting_statusJSON) {
	event_reporting_status_t *event_reporting_status_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *event_report_counter = NULL;
	cJSON *event_report_duration = NULL;
	event_report_counter = cJSON_GetObjectItemCaseSensitive(
		event_reporting_statusJSON, "eventReportCounter");
	if(event_report_counter) {
		if(!cJSON_IsNumber(event_report_counter)) {
			printf(
				"event_reporting_status_parseFromJSON() failed [event_report_counter]");
			goto end;
		}
	}

	event_report_duration = cJSON_GetObjectItemCaseSensitive(
		event_reporting_statusJSON, "eventReportDuration");
	if(event_report_duration) {
		if(!cJSON_IsNumber(event_report_duration)) {
			printf(
				"event_reporting_status_parseFromJSON() failed [event_report_duration]");
			goto end;
		}
	}

	event_reporting_status_local_var = event_reporting_status_create(
		event_report_counter ? true : false,
		event_report_counter ? event_report_counter->valuedouble : 0,
		event_report_duration ? true : false,
		event_report_duration ? event_report_duration->valuedouble : 0
		);

	return event_reporting_status_local_var;
end:
	return NULL;
}

event_reporting_status_t *event_reporting_status_copy(
	event_reporting_status_t *dst, event_reporting_status_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = event_reporting_status_convertToJSON(src);
	if(!item) {
		printf("event_reporting_status_convertToJSON() failed");
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

	event_reporting_status_free(dst);
	dst = event_reporting_status_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
