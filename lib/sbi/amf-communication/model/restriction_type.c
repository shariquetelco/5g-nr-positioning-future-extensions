#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "restriction_type.h"

restriction_type_t *restriction_type_create() {
	restriction_type_t *restriction_type_local_var =
		malloc(sizeof(restriction_type_t));


	return restriction_type_local_var;
}

void restriction_type_free(restriction_type_t *restriction_type) {
	lnode_t *node = NULL;

	if(NULL == restriction_type) {
		return;
	}
	free(restriction_type);
}

cJSON *restriction_type_convertToJSON(restriction_type_t *restriction_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(restriction_type == NULL) {
		printf(
			"restriction_type_convertToJSON() failed [RestrictionType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

restriction_type_t *restriction_type_parseFromJSON(cJSON *restriction_typeJSON)
{
	restriction_type_t *restriction_type_local_var = NULL;
	lnode_t *node = NULL;
	restriction_type_local_var = restriction_type_create(
		);

	return restriction_type_local_var;
end:
	return NULL;
}

restriction_type_t *restriction_type_copy(restriction_type_t	*dst,
                                          restriction_type_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = restriction_type_convertToJSON(src);
	if(!item) {
		printf("restriction_type_convertToJSON() failed");
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

	restriction_type_free(dst);
	dst = restriction_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
