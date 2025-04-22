#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "horizontal_with_vertical_velocity.h"

horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_create(
	float h_speed, int bearing, float v_speed,
	vertical_direction_e v_direction) {
	horizontal_with_vertical_velocity_t *
	        horizontal_with_vertical_velocity_local_var =
		malloc(sizeof(horizontal_with_vertical_velocity_t));

	horizontal_with_vertical_velocity_local_var->h_speed = h_speed;
	horizontal_with_vertical_velocity_local_var->bearing = bearing;
	horizontal_with_vertical_velocity_local_var->v_speed = v_speed;
	horizontal_with_vertical_velocity_local_var->v_direction = v_direction;

	return horizontal_with_vertical_velocity_local_var;
}

void horizontal_with_vertical_velocity_free(
	horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity)
{
	lnode_t *node = NULL;

	if(NULL == horizontal_with_vertical_velocity) {
		return;
	}
	free(horizontal_with_vertical_velocity);
}

cJSON *horizontal_with_vertical_velocity_convertToJSON(
	horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(horizontal_with_vertical_velocity == NULL) {
		printf(
			"horizontal_with_vertical_velocity_convertToJSON() failed [HorizontalWithVerticalVelocity]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "hSpeed",
	                           horizontal_with_vertical_velocity->h_speed)
	   == NULL)
	{
		printf(
			"horizontal_with_vertical_velocity_convertToJSON() failed [h_speed]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "bearing",
	                           horizontal_with_vertical_velocity->bearing)
	   == NULL)
	{
		printf(
			"horizontal_with_vertical_velocity_convertToJSON() failed [bearing]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "vSpeed",
	                           horizontal_with_vertical_velocity->v_speed)
	   == NULL)
	{
		printf(
			"horizontal_with_vertical_velocity_convertToJSON() failed [v_speed]");
		goto end;
	}

	if(horizontal_with_vertical_velocity->v_direction ==
	   vertical_direction_NULL)
	{
		printf(
			"horizontal_with_vertical_velocity_convertToJSON() failed [v_direction]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "vDirection",
	                           vertical_direction_ToString(
					   horizontal_with_vertical_velocity->
					   v_direction)) ==
	   NULL)
	{
		printf(
			"horizontal_with_vertical_velocity_convertToJSON() failed [v_direction]");
		goto end;
	}

end:
	return item;
}

horizontal_with_vertical_velocity_t *
horizontal_with_vertical_velocity_parseFromJSON(
	cJSON *horizontal_with_vertical_velocityJSON) {
	horizontal_with_vertical_velocity_t *
	        horizontal_with_vertical_velocity_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *h_speed = NULL;
	cJSON *bearing = NULL;
	cJSON *v_speed = NULL;
	cJSON *v_direction = NULL;
	vertical_direction_e v_directionVariable = 0;
	h_speed = cJSON_GetObjectItemCaseSensitive(
		horizontal_with_vertical_velocityJSON, "hSpeed");
	if(!h_speed) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [h_speed]");
		goto end;
	}
	if(!cJSON_IsNumber(h_speed)) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [h_speed]");
		goto end;
	}

	bearing = cJSON_GetObjectItemCaseSensitive(
		horizontal_with_vertical_velocityJSON, "bearing");
	if(!bearing) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [bearing]");
		goto end;
	}
	if(!cJSON_IsNumber(bearing)) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [bearing]");
		goto end;
	}

	v_speed = cJSON_GetObjectItemCaseSensitive(
		horizontal_with_vertical_velocityJSON, "vSpeed");
	if(!v_speed) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [v_speed]");
		goto end;
	}
	if(!cJSON_IsNumber(v_speed)) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [v_speed]");
		goto end;
	}

	v_direction = cJSON_GetObjectItemCaseSensitive(
		horizontal_with_vertical_velocityJSON, "vDirection");
	if(!v_direction) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [v_direction]");
		goto end;
	}
	if(!cJSON_IsString(v_direction)) {
		printf(
			"horizontal_with_vertical_velocity_parseFromJSON() failed [v_direction]");
		goto end;
	}
	v_directionVariable = vertical_direction_FromString(
		v_direction->valuestring);

	horizontal_with_vertical_velocity_local_var =
		horizontal_with_vertical_velocity_create(

			h_speed->valuedouble,

			bearing->valuedouble,

			v_speed->valuedouble,
			v_directionVariable
			);

	return horizontal_with_vertical_velocity_local_var;
end:
	return NULL;
}

horizontal_with_vertical_velocity_t *horizontal_with_vertical_velocity_copy(
	horizontal_with_vertical_velocity_t	*dst,
	horizontal_with_vertical_velocity_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = horizontal_with_vertical_velocity_convertToJSON(src);
	if(!item) {
		printf(
			"horizontal_with_vertical_velocity_convertToJSON() failed");
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

	horizontal_with_vertical_velocity_free(dst);
	dst = horizontal_with_vertical_velocity_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
