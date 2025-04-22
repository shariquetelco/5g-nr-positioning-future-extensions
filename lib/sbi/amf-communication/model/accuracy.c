#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "accuracy.h"

accuracy_t *accuracy_create() {
	accuracy_t *accuracy_local_var = malloc(sizeof(accuracy_t));


	return accuracy_local_var;
}

void accuracy_free(accuracy_t *accuracy) {
	lnode_t *node = NULL;

	if(NULL == accuracy) {
		return;
	}
	free(accuracy);
}

cJSON *accuracy_convertToJSON(accuracy_t *accuracy) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(accuracy == NULL) {
		printf("accuracy_convertToJSON() failed [Accuracy]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

accuracy_t *accuracy_parseFromJSON(cJSON *accuracyJSON) {
	accuracy_t *accuracy_local_var = NULL;
	lnode_t *node = NULL;
	accuracy_local_var = accuracy_create(
		);

	return accuracy_local_var;
end:
	return NULL;
}

accuracy_t *accuracy_copy(accuracy_t *dst, accuracy_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = accuracy_convertToJSON(src);
	if(!item) {
		printf("accuracy_convertToJSON() failed");
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

	accuracy_free(dst);
	dst = accuracy_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
