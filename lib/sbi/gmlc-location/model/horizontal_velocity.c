#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "horizontal_velocity.h"

horizontal_velocity_t *horizontal_velocity_create(float h_speed, int bearing) {
	horizontal_velocity_t *horizontal_velocity_local_var =
		malloc(sizeof(horizontal_velocity_t));

	horizontal_velocity_local_var->h_speed = h_speed;
	horizontal_velocity_local_var->bearing = bearing;

	return horizontal_velocity_local_var;
}

void horizontal_velocity_free(horizontal_velocity_t *horizontal_velocity) {
	lnode_t *node = NULL;

	if(NULL == horizontal_velocity) {
		return;
	}
	free(horizontal_velocity);
}

cJSON *horizontal_velocity_convertToJSON(
	horizontal_velocity_t *horizontal_velocity) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(horizontal_velocity == NULL) {
		printf(
			"horizontal_velocity_convertToJSON() failed [HorizontalVelocity]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "hSpeed",
	                           horizontal_velocity->h_speed) == NULL)
	{
		printf("horizontal_velocity_convertToJSON() failed [h_speed]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "bearing",
	                           horizontal_velocity->bearing) == NULL)
	{
		printf("horizontal_velocity_convertToJSON() failed [bearing]");
		goto end;
	}

end:
	return item;
}

horizontal_velocity_t *horizontal_velocity_parseFromJSON(
	cJSON *horizontal_velocityJSON) {
	horizontal_velocity_t *horizontal_velocity_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *h_speed = NULL;
	cJSON *bearing = NULL;
	h_speed = cJSON_GetObjectItemCaseSensitive(horizontal_velocityJSON,
	                                           "hSpeed");
	if(!h_speed) {
		printf("horizontal_velocity_parseFromJSON() failed [h_speed]");
		goto end;
	}
	if(!cJSON_IsNumber(h_speed)) {
		printf("horizontal_velocity_parseFromJSON() failed [h_speed]");
		goto end;
	}

	bearing = cJSON_GetObjectItemCaseSensitive(horizontal_velocityJSON,
	                                           "bearing");
	if(!bearing) {
		printf("horizontal_velocity_parseFromJSON() failed [bearing]");
		goto end;
	}
	if(!cJSON_IsNumber(bearing)) {
		printf("horizontal_velocity_parseFromJSON() failed [bearing]");
		goto end;
	}

	horizontal_velocity_local_var = horizontal_velocity_create(

		h_speed->valuedouble,

		bearing->valuedouble
		);

	return horizontal_velocity_local_var;
end:
	return NULL;
}

horizontal_velocity_t *horizontal_velocity_copy(horizontal_velocity_t	*dst,
                                                horizontal_velocity_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = horizontal_velocity_convertToJSON(src);
	if(!item) {
		printf("horizontal_velocity_convertToJSON() failed");
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

	horizontal_velocity_free(dst);
	dst = horizontal_velocity_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
