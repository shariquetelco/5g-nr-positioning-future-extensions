#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_report_message.h"

event_report_message_t *event_report_message_create(
	event_class_e		event_class,
	ref_to_binary_data_t	*event_content)
{
	event_report_message_t *event_report_message_local_var =
		malloc(sizeof(event_report_message_t));

	event_report_message_local_var->event_class = event_class;
	event_report_message_local_var->event_content = event_content;

	return event_report_message_local_var;
}

void event_report_message_free(event_report_message_t *event_report_message) {
	lnode_t *node = NULL;

	if(NULL == event_report_message) {
		return;
	}
	if(event_report_message->event_content) {
		ref_to_binary_data_free(event_report_message->event_content);
		event_report_message->event_content = NULL;
	}
	free(event_report_message);
}

cJSON *event_report_message_convertToJSON(
	event_report_message_t *event_report_message) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(event_report_message == NULL) {
		printf(
			"event_report_message_convertToJSON() failed [EventReportMessage]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(event_report_message->event_class == event_class_NULL) {
		printf(
			"event_report_message_convertToJSON() failed [event_class]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "eventClass",
	                           event_class_ToString(event_report_message->
	                                                event_class)) == NULL)
	{
		printf(
			"event_report_message_convertToJSON() failed [event_class]");
		goto end;
	}

	if(!event_report_message->event_content) {
		printf(
			"event_report_message_convertToJSON() failed [event_content]");
		return NULL;
	}
	cJSON *event_content_local_JSON = ref_to_binary_data_convertToJSON(
		event_report_message->event_content);
	if(event_content_local_JSON == NULL) {
		printf(
			"event_report_message_convertToJSON() failed [event_content]");
		goto end;
	}
	cJSON_AddItemToObject(item, "eventContent", event_content_local_JSON);
	if(item->child == NULL) {
		printf(
			"event_report_message_convertToJSON() failed [event_content]");
		goto end;
	}

end:
	return item;
}

event_report_message_t *event_report_message_parseFromJSON(
	cJSON *event_report_messageJSON) {
	event_report_message_t *event_report_message_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *event_class = NULL;
	event_class_e event_classVariable = 0;
	cJSON *event_content = NULL;
	ref_to_binary_data_t *event_content_local_nonprim = NULL;
	event_class = cJSON_GetObjectItemCaseSensitive(event_report_messageJSON,
	                                               "eventClass");
	if(!event_class) {
		printf(
			"event_report_message_parseFromJSON() failed [event_class]");
		goto end;
	}
	if(!cJSON_IsString(event_class)) {
		printf(
			"event_report_message_parseFromJSON() failed [event_class]");
		goto end;
	}
	event_classVariable = event_class_FromString(event_class->valuestring);

	event_content = cJSON_GetObjectItemCaseSensitive(
		event_report_messageJSON, "eventContent");
	if(!event_content) {
		printf(
			"event_report_message_parseFromJSON() failed [event_content]");
		goto end;
	}
	event_content_local_nonprim = ref_to_binary_data_parseFromJSON(
		event_content);
	if(!event_content_local_nonprim) {
		printf("ref_to_binary_data_parseFromJSON failed [event_content]");
		goto end;
	}

	event_report_message_local_var = event_report_message_create(
		event_classVariable,
		event_content_local_nonprim
		);

	return event_report_message_local_var;
end:
	if(event_content_local_nonprim) {
		ref_to_binary_data_free(event_content_local_nonprim);
		event_content_local_nonprim = NULL;
	}
	return NULL;
}

event_report_message_t *event_report_message_copy(
	event_report_message_t	*dst,
	event_report_message_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = event_report_message_convertToJSON(src);
	if(!item) {
		printf("event_report_message_convertToJSON() failed");
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

	event_report_message_free(dst);
	dst = event_report_message_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
