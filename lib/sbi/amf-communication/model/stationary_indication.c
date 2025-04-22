#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "stationary_indication.h"

stationary_indication_t *stationary_indication_create() {
	stationary_indication_t *stationary_indication_local_var = malloc(
		sizeof(stationary_indication_t));


	return stationary_indication_local_var;
}

void stationary_indication_free(stationary_indication_t *stationary_indication)
{
	lnode_t *node = NULL;

	if(NULL == stationary_indication) {
		return;
	}
	free(stationary_indication);
}

cJSON *stationary_indication_convertToJSON(
	stationary_indication_t *stationary_indication) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(stationary_indication == NULL) {
		printf(
			"stationary_indication_convertToJSON() failed [StationaryIndication]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

stationary_indication_t *stationary_indication_parseFromJSON(
	cJSON *stationary_indicationJSON) {
	stationary_indication_t *stationary_indication_local_var = NULL;
	lnode_t *node = NULL;
	stationary_indication_local_var = stationary_indication_create(
		);

	return stationary_indication_local_var;
end:
	return NULL;
}

stationary_indication_t *stationary_indication_copy(
	stationary_indication_t *dst, stationary_indication_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = stationary_indication_convertToJSON(src);
	if(!item) {
		printf("stationary_indication_convertToJSON() failed");
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

	stationary_indication_free(dst);
	dst = stationary_indication_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
