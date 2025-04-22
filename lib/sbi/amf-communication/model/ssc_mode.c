#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ssc_mode.h"

ssc_mode_t *ssc_mode_create() {
	ssc_mode_t *ssc_mode_local_var = malloc(sizeof(ssc_mode_t));


	return ssc_mode_local_var;
}

void ssc_mode_free(ssc_mode_t *ssc_mode) {
	lnode_t *node = NULL;

	if(NULL == ssc_mode) {
		return;
	}
	free(ssc_mode);
}

cJSON *ssc_mode_convertToJSON(ssc_mode_t *ssc_mode) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ssc_mode == NULL) {
		printf("ssc_mode_convertToJSON() failed [SscMode]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

ssc_mode_t *ssc_mode_parseFromJSON(cJSON *ssc_modeJSON) {
	ssc_mode_t *ssc_mode_local_var = NULL;
	lnode_t *node = NULL;
	ssc_mode_local_var = ssc_mode_create(
		);

	return ssc_mode_local_var;
end:
	return NULL;
}

ssc_mode_t *ssc_mode_copy(ssc_mode_t *dst, ssc_mode_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ssc_mode_convertToJSON(src);
	if(!item) {
		printf("ssc_mode_convertToJSON() failed");
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

	ssc_mode_free(dst);
	dst = ssc_mode_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
