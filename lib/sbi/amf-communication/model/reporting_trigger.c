#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_trigger.h"

reporting_trigger_t *reporting_trigger_create() {
	reporting_trigger_t *reporting_trigger_local_var =
		malloc(sizeof(reporting_trigger_t));


	return reporting_trigger_local_var;
}

void reporting_trigger_free(reporting_trigger_t *reporting_trigger) {
	lnode_t *node = NULL;

	if(NULL == reporting_trigger) {
		return;
	}
	free(reporting_trigger);
}

cJSON *reporting_trigger_convertToJSON(reporting_trigger_t *reporting_trigger) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(reporting_trigger == NULL) {
		printf(
			"reporting_trigger_convertToJSON() failed [ReportingTrigger]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

reporting_trigger_t *reporting_trigger_parseFromJSON(
	cJSON *reporting_triggerJSON) {
	reporting_trigger_t *reporting_trigger_local_var = NULL;
	lnode_t *node = NULL;
	reporting_trigger_local_var = reporting_trigger_create(
		);

	return reporting_trigger_local_var;
end:
	return NULL;
}

reporting_trigger_t *reporting_trigger_copy(reporting_trigger_t *dst,
                                            reporting_trigger_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = reporting_trigger_convertToJSON(src);
	if(!item) {
		printf("reporting_trigger_convertToJSON() failed");
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

	reporting_trigger_free(dst);
	dst = reporting_trigger_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
