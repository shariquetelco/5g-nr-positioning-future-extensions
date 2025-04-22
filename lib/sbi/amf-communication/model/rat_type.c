#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rat_type.h"

rat_type_t *rat_type_create() {
	rat_type_t *rat_type_local_var = malloc(sizeof(rat_type_t));


	return rat_type_local_var;
}

void rat_type_free(rat_type_t *rat_type) {
	lnode_t *node = NULL;

	if(NULL == rat_type) {
		return;
	}
	free(rat_type);
}

cJSON *rat_type_convertToJSON(rat_type_t *rat_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(rat_type == NULL) {
		printf("rat_type_convertToJSON() failed [RatType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

rat_type_t *rat_type_parseFromJSON(cJSON *rat_typeJSON) {
	rat_type_t *rat_type_local_var = NULL;
	lnode_t *node = NULL;
	rat_type_local_var = rat_type_create(
		);

	return rat_type_local_var;
end:
	return NULL;
}

rat_type_t *rat_type_copy(rat_type_t *dst, rat_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = rat_type_convertToJSON(src);
	if(!item) {
		printf("rat_type_convertToJSON() failed");
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

	rat_type_free(dst);
	dst = rat_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
