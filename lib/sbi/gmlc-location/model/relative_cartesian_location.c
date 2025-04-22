#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "relative_cartesian_location.h"

relative_cartesian_location_t *relative_cartesian_location_create(float x,
                                                                  float y,
                                                                  bool	is_z,
                                                                  float z) {
	relative_cartesian_location_t *relative_cartesian_location_local_var =
		malloc(sizeof(relative_cartesian_location_t));

	relative_cartesian_location_local_var->x = x;
	relative_cartesian_location_local_var->y = y;
	relative_cartesian_location_local_var->is_z = is_z;
	relative_cartesian_location_local_var->z = z;

	return relative_cartesian_location_local_var;
}

void relative_cartesian_location_free(
	relative_cartesian_location_t *relative_cartesian_location) {
	lnode_t *node = NULL;

	if(NULL == relative_cartesian_location) {
		return;
	}
	free(relative_cartesian_location);
}

cJSON *relative_cartesian_location_convertToJSON(
	relative_cartesian_location_t *relative_cartesian_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(relative_cartesian_location == NULL) {
		printf(
			"relative_cartesian_location_convertToJSON() failed [RelativeCartesianLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "x",
	                           relative_cartesian_location->x) == NULL)
	{
		printf("relative_cartesian_location_convertToJSON() failed [x]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "y",
	                           relative_cartesian_location->y) == NULL)
	{
		printf("relative_cartesian_location_convertToJSON() failed [y]");
		goto end;
	}

	if(relative_cartesian_location->is_z) {
		if(cJSON_AddNumberToObject(item, "z",
		                           relative_cartesian_location->z) ==
		   NULL)
		{
			printf(
				"relative_cartesian_location_convertToJSON() failed [z]");
			goto end;
		}
	}

end:
	return item;
}

relative_cartesian_location_t *relative_cartesian_location_parseFromJSON(
	cJSON *relative_cartesian_locationJSON) {
	relative_cartesian_location_t *relative_cartesian_location_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *x = NULL;
	cJSON *y = NULL;
	cJSON *z = NULL;
	x = cJSON_GetObjectItemCaseSensitive(relative_cartesian_locationJSON,
	                                     "x");
	if(!x) {
		printf("relative_cartesian_location_parseFromJSON() failed [x]");
		goto end;
	}
	if(!cJSON_IsNumber(x)) {
		printf("relative_cartesian_location_parseFromJSON() failed [x]");
		goto end;
	}

	y = cJSON_GetObjectItemCaseSensitive(relative_cartesian_locationJSON,
	                                     "y");
	if(!y) {
		printf("relative_cartesian_location_parseFromJSON() failed [y]");
		goto end;
	}
	if(!cJSON_IsNumber(y)) {
		printf("relative_cartesian_location_parseFromJSON() failed [y]");
		goto end;
	}

	z = cJSON_GetObjectItemCaseSensitive(relative_cartesian_locationJSON,
	                                     "z");
	if(z) {
		if(!cJSON_IsNumber(z)) {
			printf(
				"relative_cartesian_location_parseFromJSON() failed [z]");
			goto end;
		}
	}

	relative_cartesian_location_local_var =
		relative_cartesian_location_create(

			x->valuedouble,

			y->valuedouble,
			z ? true : false,
			z ? z->valuedouble : 0
			);

	return relative_cartesian_location_local_var;
end:
	return NULL;
}

relative_cartesian_location_t *relative_cartesian_location_copy(
	relative_cartesian_location_t	*dst,
	relative_cartesian_location_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = relative_cartesian_location_convertToJSON(src);
	if(!item) {
		printf("relative_cartesian_location_convertToJSON() failed");
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

	relative_cartesian_location_free(dst);
	dst = relative_cartesian_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
