#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "clock_quality.h"

clock_quality_t *clock_quality_create(bool	is_traceability_to_gnss,
                                      int	traceability_to_gnss,
                                      bool	is_traceability_to_utc,
                                      int	traceability_to_utc,
                                      bool	is_frequency_stability,
                                      int	frequency_stability,
                                      char	*clock_accuracy_index,
                                      bool	is_clock_accuracy_value,
                                      int	clock_accuracy_value) {
	clock_quality_t *clock_quality_local_var = malloc(
		sizeof(clock_quality_t));

	clock_quality_local_var->is_traceability_to_gnss =
		is_traceability_to_gnss;
	clock_quality_local_var->traceability_to_gnss = traceability_to_gnss;
	clock_quality_local_var->is_traceability_to_utc =
		is_traceability_to_utc;
	clock_quality_local_var->traceability_to_utc = traceability_to_utc;
	clock_quality_local_var->is_frequency_stability =
		is_frequency_stability;
	clock_quality_local_var->frequency_stability = frequency_stability;
	clock_quality_local_var->clock_accuracy_index = clock_accuracy_index;
	clock_quality_local_var->is_clock_accuracy_value =
		is_clock_accuracy_value;
	clock_quality_local_var->clock_accuracy_value = clock_accuracy_value;

	return clock_quality_local_var;
}

void clock_quality_free(clock_quality_t *clock_quality) {
	lnode_t *node = NULL;

	if(NULL == clock_quality) {
		return;
	}
	if(clock_quality->clock_accuracy_index) {
		free(clock_quality->clock_accuracy_index);
		clock_quality->clock_accuracy_index = NULL;
	}
	free(clock_quality);
}

cJSON *clock_quality_convertToJSON(clock_quality_t *clock_quality) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(clock_quality == NULL) {
		printf("clock_quality_convertToJSON() failed [ClockQuality]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(clock_quality->is_traceability_to_gnss) {
		if(cJSON_AddBoolToObject(item, "traceabilityToGnss",
		                         clock_quality->traceability_to_gnss) ==
		   NULL)
		{
			printf(
				"clock_quality_convertToJSON() failed [traceability_to_gnss]");
			goto end;
		}
	}

	if(clock_quality->is_traceability_to_utc) {
		if(cJSON_AddBoolToObject(item, "traceabilityToUtc",
		                         clock_quality->traceability_to_utc) ==
		   NULL)
		{
			printf(
				"clock_quality_convertToJSON() failed [traceability_to_utc]");
			goto end;
		}
	}

	if(clock_quality->is_frequency_stability) {
		if(cJSON_AddNumberToObject(item, "frequencyStability",
		                           clock_quality->frequency_stability)
		   == NULL)
		{
			printf(
				"clock_quality_convertToJSON() failed [frequency_stability]");
			goto end;
		}
	}

	if(clock_quality->clock_accuracy_index) {
		if(cJSON_AddStringToObject(item, "clockAccuracyIndex",
		                           clock_quality->clock_accuracy_index)
		   == NULL)
		{
			printf(
				"clock_quality_convertToJSON() failed [clock_accuracy_index]");
			goto end;
		}
	}

	if(clock_quality->is_clock_accuracy_value) {
		if(cJSON_AddNumberToObject(item, "clockAccuracyValue",
		                           clock_quality->clock_accuracy_value)
		   == NULL)
		{
			printf(
				"clock_quality_convertToJSON() failed [clock_accuracy_value]");
			goto end;
		}
	}

end:
	return item;
}

clock_quality_t *clock_quality_parseFromJSON(cJSON *clock_qualityJSON) {
	clock_quality_t *clock_quality_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *traceability_to_gnss = NULL;
	cJSON *traceability_to_utc = NULL;
	cJSON *frequency_stability = NULL;
	cJSON *clock_accuracy_index = NULL;
	cJSON *clock_accuracy_value = NULL;
	traceability_to_gnss = cJSON_GetObjectItemCaseSensitive(
		clock_qualityJSON, "traceabilityToGnss");
	if(traceability_to_gnss) {
		if(!cJSON_IsBool(traceability_to_gnss)) {
			printf(
				"clock_quality_parseFromJSON() failed [traceability_to_gnss]");
			goto end;
		}
	}

	traceability_to_utc = cJSON_GetObjectItemCaseSensitive(
		clock_qualityJSON, "traceabilityToUtc");
	if(traceability_to_utc) {
		if(!cJSON_IsBool(traceability_to_utc)) {
			printf(
				"clock_quality_parseFromJSON() failed [traceability_to_utc]");
			goto end;
		}
	}

	frequency_stability = cJSON_GetObjectItemCaseSensitive(
		clock_qualityJSON, "frequencyStability");
	if(frequency_stability) {
		if(!cJSON_IsNumber(frequency_stability)) {
			printf(
				"clock_quality_parseFromJSON() failed [frequency_stability]");
			goto end;
		}
	}

	clock_accuracy_index = cJSON_GetObjectItemCaseSensitive(
		clock_qualityJSON, "clockAccuracyIndex");
	if(clock_accuracy_index) {
		if(!cJSON_IsString(clock_accuracy_index) &&
		   !cJSON_IsNull(clock_accuracy_index))
		{
			printf(
				"clock_quality_parseFromJSON() failed [clock_accuracy_index]");
			goto end;
		}
	}

	clock_accuracy_value = cJSON_GetObjectItemCaseSensitive(
		clock_qualityJSON, "clockAccuracyValue");
	if(clock_accuracy_value) {
		if(!cJSON_IsNumber(clock_accuracy_value)) {
			printf(
				"clock_quality_parseFromJSON() failed [clock_accuracy_value]");
			goto end;
		}
	}

	clock_quality_local_var = clock_quality_create(
		traceability_to_gnss ? true : false,
		traceability_to_gnss ? traceability_to_gnss->valueint : 0,
		traceability_to_utc ? true : false,
		traceability_to_utc ? traceability_to_utc->valueint : 0,
		frequency_stability ? true : false,
		frequency_stability ? frequency_stability->valuedouble : 0,
		clock_accuracy_index &&
		!cJSON_IsNull(clock_accuracy_index) ? strdup(
			clock_accuracy_index->valuestring) : NULL,
		clock_accuracy_value ? true : false,
		clock_accuracy_value ? clock_accuracy_value->valuedouble : 0
		);

	return clock_quality_local_var;
end:
	return NULL;
}

clock_quality_t *clock_quality_copy(clock_quality_t	*dst,
                                    clock_quality_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = clock_quality_convertToJSON(src);
	if(!item) {
		printf("clock_quality_convertToJSON() failed");
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

	clock_quality_free(dst);
	dst = clock_quality_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
