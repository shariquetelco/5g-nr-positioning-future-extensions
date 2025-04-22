#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "horizontal_velocity_with_uncertainty.h"

horizontal_velocity_with_uncertainty_t *
horizontal_velocity_with_uncertainty_create(float h_speed, int bearing,
                                            float h_uncertainty) {
	horizontal_velocity_with_uncertainty_t *
	        horizontal_velocity_with_uncertainty_local_var =
		malloc(sizeof(horizontal_velocity_with_uncertainty_t));

	horizontal_velocity_with_uncertainty_local_var->h_speed = h_speed;
	horizontal_velocity_with_uncertainty_local_var->bearing = bearing;
	horizontal_velocity_with_uncertainty_local_var->h_uncertainty =
		h_uncertainty;

	return horizontal_velocity_with_uncertainty_local_var;
}

void horizontal_velocity_with_uncertainty_free(
	horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty)
{
	lnode_t *node = NULL;

	if(NULL == horizontal_velocity_with_uncertainty) {
		return;
	}
	free(horizontal_velocity_with_uncertainty);
}

cJSON *horizontal_velocity_with_uncertainty_convertToJSON(
	horizontal_velocity_with_uncertainty_t *horizontal_velocity_with_uncertainty)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(horizontal_velocity_with_uncertainty == NULL) {
		printf(
			"horizontal_velocity_with_uncertainty_convertToJSON() failed [HorizontalVelocityWithUncertainty]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "hSpeed",
	                           horizontal_velocity_with_uncertainty->h_speed)
	   == NULL)
	{
		printf(
			"horizontal_velocity_with_uncertainty_convertToJSON() failed [h_speed]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "bearing",
	                           horizontal_velocity_with_uncertainty->bearing)
	   == NULL)
	{
		printf(
			"horizontal_velocity_with_uncertainty_convertToJSON() failed [bearing]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "hUncertainty",
	                           horizontal_velocity_with_uncertainty->
	                           h_uncertainty) == NULL)
	{
		printf(
			"horizontal_velocity_with_uncertainty_convertToJSON() failed [h_uncertainty]");
		goto end;
	}

end:
	return item;
}

horizontal_velocity_with_uncertainty_t *
horizontal_velocity_with_uncertainty_parseFromJSON(
	cJSON *horizontal_velocity_with_uncertaintyJSON) {
	horizontal_velocity_with_uncertainty_t *
	        horizontal_velocity_with_uncertainty_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *h_speed = NULL;
	cJSON *bearing = NULL;
	cJSON *h_uncertainty = NULL;
	h_speed = cJSON_GetObjectItemCaseSensitive(
		horizontal_velocity_with_uncertaintyJSON, "hSpeed");
	if(!h_speed) {
		printf(
			"horizontal_velocity_with_uncertainty_parseFromJSON() failed [h_speed]");
		goto end;
	}
	if(!cJSON_IsNumber(h_speed)) {
		printf(
			"horizontal_velocity_with_uncertainty_parseFromJSON() failed [h_speed]");
		goto end;
	}

	bearing = cJSON_GetObjectItemCaseSensitive(
		horizontal_velocity_with_uncertaintyJSON, "bearing");
	if(!bearing) {
		printf(
			"horizontal_velocity_with_uncertainty_parseFromJSON() failed [bearing]");
		goto end;
	}
	if(!cJSON_IsNumber(bearing)) {
		printf(
			"horizontal_velocity_with_uncertainty_parseFromJSON() failed [bearing]");
		goto end;
	}

	h_uncertainty = cJSON_GetObjectItemCaseSensitive(
		horizontal_velocity_with_uncertaintyJSON, "hUncertainty");
	if(!h_uncertainty) {
		printf(
			"horizontal_velocity_with_uncertainty_parseFromJSON() failed [h_uncertainty]");
		goto end;
	}
	if(!cJSON_IsNumber(h_uncertainty)) {
		printf(
			"horizontal_velocity_with_uncertainty_parseFromJSON() failed [h_uncertainty]");
		goto end;
	}

	horizontal_velocity_with_uncertainty_local_var =
		horizontal_velocity_with_uncertainty_create(

			h_speed->valuedouble,

			bearing->valuedouble,

			h_uncertainty->valuedouble
			);

	return horizontal_velocity_with_uncertainty_local_var;
end:
	return NULL;
}

horizontal_velocity_with_uncertainty_t *
horizontal_velocity_with_uncertainty_copy(
	horizontal_velocity_with_uncertainty_t	*dst,
	horizontal_velocity_with_uncertainty_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = horizontal_velocity_with_uncertainty_convertToJSON(src);
	if(!item) {
		printf(
			"horizontal_velocity_with_uncertainty_convertToJSON() failed");
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

	horizontal_velocity_with_uncertainty_free(dst);
	dst = horizontal_velocity_with_uncertainty_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
