#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dispersion_type.h"

dispersion_type_t *dispersion_type_create() {
	dispersion_type_t *dispersion_type_local_var =
		malloc(sizeof(dispersion_type_t));


	return dispersion_type_local_var;
}

void dispersion_type_free(dispersion_type_t *dispersion_type) {
	lnode_t *node = NULL;

	if(NULL == dispersion_type) {
		return;
	}
	free(dispersion_type);
}

cJSON *dispersion_type_convertToJSON(dispersion_type_t *dispersion_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dispersion_type == NULL) {
		printf("dispersion_type_convertToJSON() failed [DispersionType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

dispersion_type_t *dispersion_type_parseFromJSON(cJSON *dispersion_typeJSON) {
	dispersion_type_t *dispersion_type_local_var = NULL;
	lnode_t *node = NULL;
	dispersion_type_local_var = dispersion_type_create(
		);

	return dispersion_type_local_var;
end:
	return NULL;
}

dispersion_type_t *dispersion_type_copy(dispersion_type_t	*dst,
                                        dispersion_type_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dispersion_type_convertToJSON(src);
	if(!item) {
		printf("dispersion_type_convertToJSON() failed");
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

	dispersion_type_free(dst);
	dst = dispersion_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
