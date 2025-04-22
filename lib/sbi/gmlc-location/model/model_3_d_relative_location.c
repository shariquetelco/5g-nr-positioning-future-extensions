#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "model_3_d_relative_location.h"

model_3_d_relative_location_t *model_3_d_relative_location_create(
	bool is_semi_minor, float semi_minor, bool is_semi_major,
	float semi_major, bool is_vertical_uncertainty,
	float vertical_uncertainty, bool is_orientation_angle,
	int orientation_angle) {
	model_3_d_relative_location_t *model_3_d_relative_location_local_var =
		malloc(sizeof(model_3_d_relative_location_t));

	model_3_d_relative_location_local_var->is_semi_minor = is_semi_minor;
	model_3_d_relative_location_local_var->semi_minor = semi_minor;
	model_3_d_relative_location_local_var->is_semi_major = is_semi_major;
	model_3_d_relative_location_local_var->semi_major = semi_major;
	model_3_d_relative_location_local_var->is_vertical_uncertainty =
		is_vertical_uncertainty;
	model_3_d_relative_location_local_var->vertical_uncertainty =
		vertical_uncertainty;
	model_3_d_relative_location_local_var->is_orientation_angle =
		is_orientation_angle;
	model_3_d_relative_location_local_var->orientation_angle =
		orientation_angle;

	return model_3_d_relative_location_local_var;
}

void model_3_d_relative_location_free(
	model_3_d_relative_location_t *model_3_d_relative_location) {
	lnode_t *node = NULL;

	if(NULL == model_3_d_relative_location) {
		return;
	}
	free(model_3_d_relative_location);
}

cJSON *model_3_d_relative_location_convertToJSON(
	model_3_d_relative_location_t *model_3_d_relative_location) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(model_3_d_relative_location == NULL) {
		printf(
			"model_3_d_relative_location_convertToJSON() failed [3DRelativeLocation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(model_3_d_relative_location->is_semi_minor) {
		if(cJSON_AddNumberToObject(item, "semiMinor",
		                           model_3_d_relative_location->
		                           semi_minor) == NULL)
		{
			printf(
				"model_3_d_relative_location_convertToJSON() failed [semi_minor]");
			goto end;
		}
	}

	if(model_3_d_relative_location->is_semi_major) {
		if(cJSON_AddNumberToObject(item, "semiMajor",
		                           model_3_d_relative_location->
		                           semi_major) == NULL)
		{
			printf(
				"model_3_d_relative_location_convertToJSON() failed [semi_major]");
			goto end;
		}
	}

	if(model_3_d_relative_location->is_vertical_uncertainty) {
		if(cJSON_AddNumberToObject(item, "verticalUncertainty",
		                           model_3_d_relative_location->
		                           vertical_uncertainty) == NULL)
		{
			printf(
				"model_3_d_relative_location_convertToJSON() failed [vertical_uncertainty]");
			goto end;
		}
	}

	if(model_3_d_relative_location->is_orientation_angle) {
		if(cJSON_AddNumberToObject(item, "orientationAngle",
		                           model_3_d_relative_location->
		                           orientation_angle) == NULL)
		{
			printf(
				"model_3_d_relative_location_convertToJSON() failed [orientation_angle]");
			goto end;
		}
	}

end:
	return item;
}

model_3_d_relative_location_t *model_3_d_relative_location_parseFromJSON(
	cJSON *model_3_d_relative_locationJSON) {
	model_3_d_relative_location_t *model_3_d_relative_location_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *semi_minor = NULL;
	cJSON *semi_major = NULL;
	cJSON *vertical_uncertainty = NULL;
	cJSON *orientation_angle = NULL;
	semi_minor = cJSON_GetObjectItemCaseSensitive(
		model_3_d_relative_locationJSON, "semiMinor");
	if(semi_minor) {
		if(!cJSON_IsNumber(semi_minor)) {
			printf(
				"model_3_d_relative_location_parseFromJSON() failed [semi_minor]");
			goto end;
		}
	}

	semi_major = cJSON_GetObjectItemCaseSensitive(
		model_3_d_relative_locationJSON, "semiMajor");
	if(semi_major) {
		if(!cJSON_IsNumber(semi_major)) {
			printf(
				"model_3_d_relative_location_parseFromJSON() failed [semi_major]");
			goto end;
		}
	}

	vertical_uncertainty = cJSON_GetObjectItemCaseSensitive(
		model_3_d_relative_locationJSON, "verticalUncertainty");
	if(vertical_uncertainty) {
		if(!cJSON_IsNumber(vertical_uncertainty)) {
			printf(
				"model_3_d_relative_location_parseFromJSON() failed [vertical_uncertainty]");
			goto end;
		}
	}

	orientation_angle = cJSON_GetObjectItemCaseSensitive(
		model_3_d_relative_locationJSON, "orientationAngle");
	if(orientation_angle) {
		if(!cJSON_IsNumber(orientation_angle)) {
			printf(
				"model_3_d_relative_location_parseFromJSON() failed [orientation_angle]");
			goto end;
		}
	}

	model_3_d_relative_location_local_var =
		model_3_d_relative_location_create(
			semi_minor ? true : false,
			semi_minor ? semi_minor->valuedouble : 0,
			semi_major ? true : false,
			semi_major ? semi_major->valuedouble : 0,
			vertical_uncertainty ? true : false,
			vertical_uncertainty ? vertical_uncertainty->valuedouble : 0,
			orientation_angle ? true : false,
			orientation_angle ? orientation_angle->valuedouble : 0
			);

	return model_3_d_relative_location_local_var;
end:
	return NULL;
}

model_3_d_relative_location_t *model_3_d_relative_location_copy(
	model_3_d_relative_location_t	*dst,
	model_3_d_relative_location_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = model_3_d_relative_location_convertToJSON(src);
	if(!item) {
		printf("model_3_d_relative_location_convertToJSON() failed");
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

	model_3_d_relative_location_free(dst);
	dst = model_3_d_relative_location_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
