#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "congestion_type.h"

congestion_type_t *congestion_type_create() {
	congestion_type_t *congestion_type_local_var =
		malloc(sizeof(congestion_type_t));


	return congestion_type_local_var;
}

void congestion_type_free(congestion_type_t *congestion_type) {
	lnode_t *node = NULL;

	if(NULL == congestion_type) {
		return;
	}
	free(congestion_type);
}

cJSON *congestion_type_convertToJSON(congestion_type_t *congestion_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(congestion_type == NULL) {
		printf("congestion_type_convertToJSON() failed [CongestionType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

congestion_type_t *congestion_type_parseFromJSON(cJSON *congestion_typeJSON) {
	congestion_type_t *congestion_type_local_var = NULL;
	lnode_t *node = NULL;
	congestion_type_local_var = congestion_type_create(
		);

	return congestion_type_local_var;
end:
	return NULL;
}

congestion_type_t *congestion_type_copy(congestion_type_t	*dst,
                                        congestion_type_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = congestion_type_convertToJSON(src);
	if(!item) {
		printf("congestion_type_convertToJSON() failed");
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

	congestion_type_free(dst);
	dst = congestion_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
