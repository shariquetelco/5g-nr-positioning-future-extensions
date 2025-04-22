#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event_trigger.h"

amf_event_trigger_t *amf_event_trigger_create() {
	amf_event_trigger_t *amf_event_trigger_local_var =
		malloc(sizeof(amf_event_trigger_t));


	return amf_event_trigger_local_var;
}

void amf_event_trigger_free(amf_event_trigger_t *amf_event_trigger) {
	lnode_t *node = NULL;

	if(NULL == amf_event_trigger) {
		return;
	}
	free(amf_event_trigger);
}

cJSON *amf_event_trigger_convertToJSON(amf_event_trigger_t *amf_event_trigger) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event_trigger == NULL) {
		printf(
			"amf_event_trigger_convertToJSON() failed [AmfEventTrigger]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

amf_event_trigger_t *amf_event_trigger_parseFromJSON(
	cJSON *amf_event_triggerJSON) {
	amf_event_trigger_t *amf_event_trigger_local_var = NULL;
	lnode_t *node = NULL;
	amf_event_trigger_local_var = amf_event_trigger_create(
		);

	return amf_event_trigger_local_var;
end:
	return NULL;
}

amf_event_trigger_t *amf_event_trigger_copy(amf_event_trigger_t *dst,
                                            amf_event_trigger_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_trigger_convertToJSON(src);
	if(!item) {
		printf("amf_event_trigger_convertToJSON() failed");
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

	amf_event_trigger_free(dst);
	dst = amf_event_trigger_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
