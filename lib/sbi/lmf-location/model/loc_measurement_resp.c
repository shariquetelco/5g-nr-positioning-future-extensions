#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_measurement_resp.h"

loc_measurement_resp_t *loc_measurement_resp_create(
	loc_measurements_t *loc_measurements,
	geographic_area_t *location_estimate, bool is_age_of_location_estimate,
	int age_of_location_estimate, char *timestamp_of_location_estimate,
	velocity_estimate_t *velocity_estimate,
	local_area_t *local_location_estimate) {
	loc_measurement_resp_t *loc_measurement_resp_local_var =
		malloc(sizeof(loc_measurement_resp_t));

	loc_measurement_resp_local_var->loc_measurements = loc_measurements;
	loc_measurement_resp_local_var->location_estimate = location_estimate;
	loc_measurement_resp_local_var->is_age_of_location_estimate =
		is_age_of_location_estimate;
	loc_measurement_resp_local_var->age_of_location_estimate =
		age_of_location_estimate;
	loc_measurement_resp_local_var->timestamp_of_location_estimate =
		timestamp_of_location_estimate;
	loc_measurement_resp_local_var->velocity_estimate = velocity_estimate;
	loc_measurement_resp_local_var->local_location_estimate =
		local_location_estimate;

	return loc_measurement_resp_local_var;
}

void loc_measurement_resp_free(loc_measurement_resp_t *loc_measurement_resp) {
	lnode_t *node = NULL;

	if(NULL == loc_measurement_resp) {
		return;
	}
	if(loc_measurement_resp->loc_measurements) {
		loc_measurements_free(loc_measurement_resp->loc_measurements);
		loc_measurement_resp->loc_measurements = NULL;
	}
	if(loc_measurement_resp->location_estimate) {
		geographic_area_free(loc_measurement_resp->location_estimate);
		loc_measurement_resp->location_estimate = NULL;
	}
	if(loc_measurement_resp->timestamp_of_location_estimate) {
		free(loc_measurement_resp->timestamp_of_location_estimate);
		loc_measurement_resp->timestamp_of_location_estimate = NULL;
	}
	if(loc_measurement_resp->velocity_estimate) {
		velocity_estimate_free(loc_measurement_resp->velocity_estimate);
		loc_measurement_resp->velocity_estimate = NULL;
	}
	if(loc_measurement_resp->local_location_estimate) {
		local_area_free(loc_measurement_resp->local_location_estimate);
		loc_measurement_resp->local_location_estimate = NULL;
	}
	free(loc_measurement_resp);
}

cJSON *loc_measurement_resp_convertToJSON(
	loc_measurement_resp_t *loc_measurement_resp) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_measurement_resp == NULL) {
		printf(
			"loc_measurement_resp_convertToJSON() failed [LocMeasurementResp]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!loc_measurement_resp->loc_measurements) {
		printf(
			"loc_measurement_resp_convertToJSON() failed [loc_measurements]");
		return NULL;
	}
	cJSON *loc_measurements_local_JSON = loc_measurements_convertToJSON(
		loc_measurement_resp->loc_measurements);
	if(loc_measurements_local_JSON == NULL) {
		printf(
			"loc_measurement_resp_convertToJSON() failed [loc_measurements]");
		goto end;
	}
	cJSON_AddItemToObject(item, "locMeasurements",
	                      loc_measurements_local_JSON);
	if(item->child == NULL) {
		printf(
			"loc_measurement_resp_convertToJSON() failed [loc_measurements]");
		goto end;
	}

	if(!loc_measurement_resp->location_estimate) {
		printf(
			"loc_measurement_resp_convertToJSON() failed [location_estimate]");
		return NULL;
	}
	cJSON *location_estimate_local_JSON = geographic_area_convertToJSON(
		loc_measurement_resp->location_estimate);
	if(location_estimate_local_JSON == NULL) {
		printf(
			"loc_measurement_resp_convertToJSON() failed [location_estimate]");
		goto end;
	}
	cJSON_AddItemToObject(item, "locationEstimate",
	                      location_estimate_local_JSON);
	if(item->child == NULL) {
		printf(
			"loc_measurement_resp_convertToJSON() failed [location_estimate]");
		goto end;
	}

	if(loc_measurement_resp->is_age_of_location_estimate) {
		if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate",
		                           loc_measurement_resp->
		                           age_of_location_estimate) == NULL)
		{
			printf(
				"loc_measurement_resp_convertToJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	if(loc_measurement_resp->timestamp_of_location_estimate) {
		if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate",
		                           loc_measurement_resp->
		                           timestamp_of_location_estimate) ==
		   NULL)
		{
			printf(
				"loc_measurement_resp_convertToJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	if(loc_measurement_resp->velocity_estimate) {
		cJSON *velocity_estimate_local_JSON =
			velocity_estimate_convertToJSON(
				loc_measurement_resp->velocity_estimate);
		if(velocity_estimate_local_JSON == NULL) {
			printf(
				"loc_measurement_resp_convertToJSON() failed [velocity_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "velocityEstimate",
		                      velocity_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_measurement_resp_convertToJSON() failed [velocity_estimate]");
			goto end;
		}
	}

	if(loc_measurement_resp->local_location_estimate) {
		cJSON *local_location_estimate_local_JSON =
			local_area_convertToJSON(
				loc_measurement_resp->local_location_estimate);
		if(local_location_estimate_local_JSON == NULL) {
			printf(
				"loc_measurement_resp_convertToJSON() failed [local_location_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "localLocationEstimate",
		                      local_location_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_measurement_resp_convertToJSON() failed [local_location_estimate]");
			goto end;
		}
	}

end:
	return item;
}

loc_measurement_resp_t *loc_measurement_resp_parseFromJSON(
	cJSON *loc_measurement_respJSON) {
	loc_measurement_resp_t *loc_measurement_resp_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *loc_measurements = NULL;
	loc_measurements_t *loc_measurements_local_nonprim = NULL;
	cJSON *location_estimate = NULL;
	geographic_area_t *location_estimate_local_nonprim = NULL;
	cJSON *age_of_location_estimate = NULL;
	cJSON *timestamp_of_location_estimate = NULL;
	cJSON *velocity_estimate = NULL;
	velocity_estimate_t *velocity_estimate_local_nonprim = NULL;
	cJSON *local_location_estimate = NULL;
	local_area_t *local_location_estimate_local_nonprim = NULL;
	loc_measurements = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_respJSON, "locMeasurements");
	if(!loc_measurements) {
		printf(
			"loc_measurement_resp_parseFromJSON() failed [loc_measurements]");
		goto end;
	}
	loc_measurements_local_nonprim = loc_measurements_parseFromJSON(
		loc_measurements);
	if(!loc_measurements_local_nonprim) {
		printf(
			"loc_measurements_parseFromJSON failed [loc_measurements]");
		goto end;
	}

	location_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_respJSON, "locationEstimate");
	if(!location_estimate) {
		printf(
			"loc_measurement_resp_parseFromJSON() failed [location_estimate]");
		goto end;
	}
	location_estimate_local_nonprim = geographic_area_parseFromJSON(
		location_estimate);
	if(!location_estimate_local_nonprim) {
		printf(
			"geographic_area_parseFromJSON failed [location_estimate]");
		goto end;
	}

	age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_respJSON, "ageOfLocationEstimate");
	if(age_of_location_estimate) {
		if(!cJSON_IsNumber(age_of_location_estimate)) {
			printf(
				"loc_measurement_resp_parseFromJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_respJSON, "timestampOfLocationEstimate");
	if(timestamp_of_location_estimate) {
		if(!cJSON_IsString(timestamp_of_location_estimate) &&
		   !cJSON_IsNull(timestamp_of_location_estimate))
		{
			printf(
				"loc_measurement_resp_parseFromJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	velocity_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_respJSON, "velocityEstimate");
	if(velocity_estimate) {
		velocity_estimate_local_nonprim =
			velocity_estimate_parseFromJSON(velocity_estimate);
		if(!velocity_estimate_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [velocity_estimate]");
			goto end;
		}
	}

	local_location_estimate = cJSON_GetObjectItemCaseSensitive(
		loc_measurement_respJSON, "localLocationEstimate");
	if(local_location_estimate) {
		local_location_estimate_local_nonprim =
			local_area_parseFromJSON(local_location_estimate);
		if(!local_location_estimate_local_nonprim) {
			printf(
				"local_area_parseFromJSON failed [local_location_estimate]");
			goto end;
		}
	}

	loc_measurement_resp_local_var = loc_measurement_resp_create(
		loc_measurements_local_nonprim,
		location_estimate_local_nonprim,
		age_of_location_estimate ? true : false,
		age_of_location_estimate ? age_of_location_estimate->valuedouble : 0,
		timestamp_of_location_estimate &&
		!cJSON_IsNull(timestamp_of_location_estimate) ? strdup(
			timestamp_of_location_estimate->valuestring) : NULL,
		velocity_estimate ? velocity_estimate_local_nonprim : NULL,
		local_location_estimate ? local_location_estimate_local_nonprim : NULL
		);

	return loc_measurement_resp_local_var;
end:
	if(loc_measurements_local_nonprim) {
		loc_measurements_free(loc_measurements_local_nonprim);
		loc_measurements_local_nonprim = NULL;
	}
	if(location_estimate_local_nonprim) {
		geographic_area_free(location_estimate_local_nonprim);
		location_estimate_local_nonprim = NULL;
	}
	if(velocity_estimate_local_nonprim) {
		velocity_estimate_free(velocity_estimate_local_nonprim);
		velocity_estimate_local_nonprim = NULL;
	}
	if(local_location_estimate_local_nonprim) {
		local_area_free(local_location_estimate_local_nonprim);
		local_location_estimate_local_nonprim = NULL;
	}
	return NULL;
}

loc_measurement_resp_t *loc_measurement_resp_copy(
	loc_measurement_resp_t	*dst,
	loc_measurement_resp_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_measurement_resp_convertToJSON(src);
	if(!item) {
		printf("loc_measurement_resp_convertToJSON() failed");
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

	loc_measurement_resp_free(dst);
	dst = loc_measurement_resp_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
