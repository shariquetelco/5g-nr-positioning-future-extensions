#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "analytics_accuracy_indication.h"

analytics_accuracy_indication_t *analytics_accuracy_indication_create() {
	analytics_accuracy_indication_t *analytics_accuracy_indication_local_var
	        = malloc(sizeof(analytics_accuracy_indication_t));


	return analytics_accuracy_indication_local_var;
}

void analytics_accuracy_indication_free(
	analytics_accuracy_indication_t *analytics_accuracy_indication) {
	lnode_t *node = NULL;

	if(NULL == analytics_accuracy_indication) {
		return;
	}
	free(analytics_accuracy_indication);
}

cJSON *analytics_accuracy_indication_convertToJSON(
	analytics_accuracy_indication_t *analytics_accuracy_indication) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(analytics_accuracy_indication == NULL) {
		printf(
			"analytics_accuracy_indication_convertToJSON() failed [AnalyticsAccuracyIndication]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

analytics_accuracy_indication_t *analytics_accuracy_indication_parseFromJSON(
	cJSON *analytics_accuracy_indicationJSON) {
	analytics_accuracy_indication_t *analytics_accuracy_indication_local_var
	        = NULL;
	lnode_t *node = NULL;
	analytics_accuracy_indication_local_var =
		analytics_accuracy_indication_create(
			);

	return analytics_accuracy_indication_local_var;
end:
	return NULL;
}

analytics_accuracy_indication_t *analytics_accuracy_indication_copy(
	analytics_accuracy_indication_t *dst,
	analytics_accuracy_indication_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = analytics_accuracy_indication_convertToJSON(src);
	if(!item) {
		printf("analytics_accuracy_indication_convertToJSON() failed");
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

	analytics_accuracy_indication_free(dst);
	dst = analytics_accuracy_indication_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
