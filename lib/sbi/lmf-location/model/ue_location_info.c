#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_location_info.h"

ue_location_info_t *ue_location_info_create(
	geographic_area_t *location_estimate, bool is_age_of_location_estimate,
	int age_of_location_estimate, char *timestamp_of_location_estimate,
	velocity_estimate_t *velocity_estimate,
	bool is_age_of_velocity_estimate, int age_of_velocity_estimate,
	char *timestamp_of_velocity_estimate) {
	ue_location_info_t *ue_location_info_local_var =
		malloc(sizeof(ue_location_info_t));

	ue_location_info_local_var->location_estimate = location_estimate;
	ue_location_info_local_var->is_age_of_location_estimate =
		is_age_of_location_estimate;
	ue_location_info_local_var->age_of_location_estimate =
		age_of_location_estimate;
	ue_location_info_local_var->timestamp_of_location_estimate =
		timestamp_of_location_estimate;
	ue_location_info_local_var->velocity_estimate = velocity_estimate;
	ue_location_info_local_var->is_age_of_velocity_estimate =
		is_age_of_velocity_estimate;
	ue_location_info_local_var->age_of_velocity_estimate =
		age_of_velocity_estimate;
	ue_location_info_local_var->timestamp_of_velocity_estimate =
		timestamp_of_velocity_estimate;

	return ue_location_info_local_var;
}

void ue_location_info_free(ue_location_info_t *ue_location_info) {
	lnode_t *node = NULL;

	if(NULL == ue_location_info) {
		return;
	}
	if(ue_location_info->location_estimate) {
		geographic_area_free(ue_location_info->location_estimate);
		ue_location_info->location_estimate = NULL;
	}
	if(ue_location_info->timestamp_of_location_estimate) {
		free(ue_location_info->timestamp_of_location_estimate);
		ue_location_info->timestamp_of_location_estimate = NULL;
	}
	if(ue_location_info->velocity_estimate) {
		velocity_estimate_free(ue_location_info->velocity_estimate);
		ue_location_info->velocity_estimate = NULL;
	}
	if(ue_location_info->timestamp_of_velocity_estimate) {
		free(ue_location_info->timestamp_of_velocity_estimate);
		ue_location_info->timestamp_of_velocity_estimate = NULL;
	}
	free(ue_location_info);
}

cJSON *ue_location_info_convertToJSON(ue_location_info_t *ue_location_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_location_info == NULL) {
		printf(
			"ue_location_info_convertToJSON() failed [UELocationInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_location_info->location_estimate) {
		cJSON *location_estimate_local_JSON =
			geographic_area_convertToJSON(
				ue_location_info->location_estimate);
		if(location_estimate_local_JSON == NULL) {
			printf(
				"ue_location_info_convertToJSON() failed [location_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationEstimate",
		                      location_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_location_info_convertToJSON() failed [location_estimate]");
			goto end;
		}
	}

	if(ue_location_info->is_age_of_location_estimate) {
		if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate",
		                           ue_location_info->
		                           age_of_location_estimate) == NULL)
		{
			printf(
				"ue_location_info_convertToJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	if(ue_location_info->timestamp_of_location_estimate) {
		if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate",
		                           ue_location_info->
		                           timestamp_of_location_estimate) ==
		   NULL)
		{
			printf(
				"ue_location_info_convertToJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	if(ue_location_info->velocity_estimate) {
		cJSON *velocity_estimate_local_JSON =
			velocity_estimate_convertToJSON(
				ue_location_info->velocity_estimate);
		if(velocity_estimate_local_JSON == NULL) {
			printf(
				"ue_location_info_convertToJSON() failed [velocity_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "velocityEstimate",
		                      velocity_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_location_info_convertToJSON() failed [velocity_estimate]");
			goto end;
		}
	}

	if(ue_location_info->is_age_of_velocity_estimate) {
		if(cJSON_AddNumberToObject(item, "ageOfVelocityEstimate",
		                           ue_location_info->
		                           age_of_velocity_estimate) == NULL)
		{
			printf(
				"ue_location_info_convertToJSON() failed [age_of_velocity_estimate]");
			goto end;
		}
	}

	if(ue_location_info->timestamp_of_velocity_estimate) {
		if(cJSON_AddStringToObject(item, "timestampOfVelocityEstimate",
		                           ue_location_info->
		                           timestamp_of_velocity_estimate) ==
		   NULL)
		{
			printf(
				"ue_location_info_convertToJSON() failed [timestamp_of_velocity_estimate]");
			goto end;
		}
	}

end:
	return item;
}

ue_location_info_t *ue_location_info_parseFromJSON(cJSON *ue_location_infoJSON)
{
	ue_location_info_t *ue_location_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *location_estimate = NULL;
	geographic_area_t *location_estimate_local_nonprim = NULL;
	cJSON *age_of_location_estimate = NULL;
	cJSON *timestamp_of_location_estimate = NULL;
	cJSON *velocity_estimate = NULL;
	velocity_estimate_t *velocity_estimate_local_nonprim = NULL;
	cJSON *age_of_velocity_estimate = NULL;
	cJSON *timestamp_of_velocity_estimate = NULL;
	location_estimate = cJSON_GetObjectItemCaseSensitive(
		ue_location_infoJSON, "locationEstimate");
	if(location_estimate) {
		location_estimate_local_nonprim = geographic_area_parseFromJSON(
			location_estimate);
		if(!location_estimate_local_nonprim) {
			printf(
				"geographic_area_parseFromJSON failed [location_estimate]");
			goto end;
		}
	}

	age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		ue_location_infoJSON, "ageOfLocationEstimate");
	if(age_of_location_estimate) {
		if(!cJSON_IsNumber(age_of_location_estimate)) {
			printf(
				"ue_location_info_parseFromJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		ue_location_infoJSON, "timestampOfLocationEstimate");
	if(timestamp_of_location_estimate) {
		if(!cJSON_IsString(timestamp_of_location_estimate) &&
		   !cJSON_IsNull(timestamp_of_location_estimate))
		{
			printf(
				"ue_location_info_parseFromJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	velocity_estimate = cJSON_GetObjectItemCaseSensitive(
		ue_location_infoJSON, "velocityEstimate");
	if(velocity_estimate) {
		velocity_estimate_local_nonprim =
			velocity_estimate_parseFromJSON(velocity_estimate);
		if(!velocity_estimate_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [velocity_estimate]");
			goto end;
		}
	}

	age_of_velocity_estimate = cJSON_GetObjectItemCaseSensitive(
		ue_location_infoJSON, "ageOfVelocityEstimate");
	if(age_of_velocity_estimate) {
		if(!cJSON_IsNumber(age_of_velocity_estimate)) {
			printf(
				"ue_location_info_parseFromJSON() failed [age_of_velocity_estimate]");
			goto end;
		}
	}

	timestamp_of_velocity_estimate = cJSON_GetObjectItemCaseSensitive(
		ue_location_infoJSON, "timestampOfVelocityEstimate");
	if(timestamp_of_velocity_estimate) {
		if(!cJSON_IsString(timestamp_of_velocity_estimate) &&
		   !cJSON_IsNull(timestamp_of_velocity_estimate))
		{
			printf(
				"ue_location_info_parseFromJSON() failed [timestamp_of_velocity_estimate]");
			goto end;
		}
	}

	ue_location_info_local_var = ue_location_info_create(
		location_estimate ? location_estimate_local_nonprim : NULL,
		age_of_location_estimate ? true : false,
		age_of_location_estimate ? age_of_location_estimate->valuedouble : 0,
		timestamp_of_location_estimate &&
		!cJSON_IsNull(timestamp_of_location_estimate) ? strdup(
			timestamp_of_location_estimate->valuestring) : NULL,
		velocity_estimate ? velocity_estimate_local_nonprim : NULL,
		age_of_velocity_estimate ? true : false,
		age_of_velocity_estimate ? age_of_velocity_estimate->valuedouble : 0,
		timestamp_of_velocity_estimate &&
		!cJSON_IsNull(timestamp_of_velocity_estimate) ? strdup(
			timestamp_of_velocity_estimate->valuestring) : NULL
		);

	return ue_location_info_local_var;
end:
	if(location_estimate_local_nonprim) {
		geographic_area_free(location_estimate_local_nonprim);
		location_estimate_local_nonprim = NULL;
	}
	if(velocity_estimate_local_nonprim) {
		velocity_estimate_free(velocity_estimate_local_nonprim);
		velocity_estimate_local_nonprim = NULL;
	}
	return NULL;
}

ue_location_info_t *ue_location_info_copy(ue_location_info_t	*dst,
                                          ue_location_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_location_info_convertToJSON(src);
	if(!item) {
		printf("ue_location_info_convertToJSON() failed");
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

	ue_location_info_free(dst);
	dst = ue_location_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
