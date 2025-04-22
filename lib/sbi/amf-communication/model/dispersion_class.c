#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dispersion_class.h"

dispersion_class_t *dispersion_class_create() {
	dispersion_class_t *dispersion_class_local_var =
		malloc(sizeof(dispersion_class_t));


	return dispersion_class_local_var;
}

void dispersion_class_free(dispersion_class_t *dispersion_class) {
	lnode_t *node = NULL;

	if(NULL == dispersion_class) {
		return;
	}
	free(dispersion_class);
}

cJSON *dispersion_class_convertToJSON(dispersion_class_t *dispersion_class) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dispersion_class == NULL) {
		printf(
			"dispersion_class_convertToJSON() failed [DispersionClass]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

dispersion_class_t *dispersion_class_parseFromJSON(cJSON *dispersion_classJSON)
{
	dispersion_class_t *dispersion_class_local_var = NULL;
	lnode_t *node = NULL;
	dispersion_class_local_var = dispersion_class_create(
		);

	return dispersion_class_local_var;
end:
	return NULL;
}

dispersion_class_t *dispersion_class_copy(dispersion_class_t	*dst,
                                          dispersion_class_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dispersion_class_convertToJSON(src);
	if(!item) {
		printf("dispersion_class_convertToJSON() failed");
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

	dispersion_class_free(dst);
	dst = dispersion_class_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
