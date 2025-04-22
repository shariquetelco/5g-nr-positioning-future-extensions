#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "line_type.h"

line_type_t *line_type_create() {
	line_type_t *line_type_local_var = malloc(sizeof(line_type_t));


	return line_type_local_var;
}

void line_type_free(line_type_t *line_type) {
	lnode_t *node = NULL;

	if(NULL == line_type) {
		return;
	}
	free(line_type);
}

cJSON *line_type_convertToJSON(line_type_t *line_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(line_type == NULL) {
		printf("line_type_convertToJSON() failed [LineType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

line_type_t *line_type_parseFromJSON(cJSON *line_typeJSON) {
	line_type_t *line_type_local_var = NULL;
	lnode_t *node = NULL;
	line_type_local_var = line_type_create(
		);

	return line_type_local_var;
end:
	return NULL;
}

line_type_t *line_type_copy(line_type_t *dst, line_type_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = line_type_convertToJSON(src);
	if(!item) {
		printf("line_type_convertToJSON() failed");
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

	line_type_free(dst);
	dst = line_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
