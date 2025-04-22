#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "proximity_criterion.h"

proximity_criterion_t *proximity_criterion_create() {
	proximity_criterion_t *proximity_criterion_local_var =
		malloc(sizeof(proximity_criterion_t));


	return proximity_criterion_local_var;
}

void proximity_criterion_free(proximity_criterion_t *proximity_criterion) {
	lnode_t *node = NULL;

	if(NULL == proximity_criterion) {
		return;
	}
	free(proximity_criterion);
}

cJSON *proximity_criterion_convertToJSON(
	proximity_criterion_t *proximity_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(proximity_criterion == NULL) {
		printf(
			"proximity_criterion_convertToJSON() failed [ProximityCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

proximity_criterion_t *proximity_criterion_parseFromJSON(
	cJSON *proximity_criterionJSON) {
	proximity_criterion_t *proximity_criterion_local_var = NULL;
	lnode_t *node = NULL;
	proximity_criterion_local_var = proximity_criterion_create(
		);

	return proximity_criterion_local_var;
end:
	return NULL;
}

proximity_criterion_t *proximity_criterion_copy(proximity_criterion_t	*dst,
                                                proximity_criterion_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = proximity_criterion_convertToJSON(src);
	if(!item) {
		printf("proximity_criterion_convertToJSON() failed");
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

	proximity_criterion_free(dst);
	dst = proximity_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
