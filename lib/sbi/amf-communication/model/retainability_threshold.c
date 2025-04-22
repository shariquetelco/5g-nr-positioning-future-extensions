#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "retainability_threshold.h"

retainability_threshold_t *retainability_threshold_create(bool is_rel_flow_num,
                                                          int rel_flow_num,
                                                          time_unit_t *rel_time_unit, bool is_rel_flow_ratio,
                                                          int rel_flow_ratio) {
	retainability_threshold_t *retainability_threshold_local_var = malloc(
		sizeof(retainability_threshold_t));

	retainability_threshold_local_var->is_rel_flow_num = is_rel_flow_num;
	retainability_threshold_local_var->rel_flow_num = rel_flow_num;
	retainability_threshold_local_var->rel_time_unit = rel_time_unit;
	retainability_threshold_local_var->is_rel_flow_ratio =
		is_rel_flow_ratio;
	retainability_threshold_local_var->rel_flow_ratio = rel_flow_ratio;

	return retainability_threshold_local_var;
}

void retainability_threshold_free(
	retainability_threshold_t *retainability_threshold) {
	lnode_t *node = NULL;

	if(NULL == retainability_threshold) {
		return;
	}
	if(retainability_threshold->rel_time_unit) {
		time_unit_free(retainability_threshold->rel_time_unit);
		retainability_threshold->rel_time_unit = NULL;
	}
	free(retainability_threshold);
}

cJSON *retainability_threshold_convertToJSON(
	retainability_threshold_t *retainability_threshold) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(retainability_threshold == NULL) {
		printf(
			"retainability_threshold_convertToJSON() failed [RetainabilityThreshold]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(retainability_threshold->is_rel_flow_num) {
		if(cJSON_AddNumberToObject(item, "relFlowNum",
		                           retainability_threshold->rel_flow_num)
		   == NULL)
		{
			printf(
				"retainability_threshold_convertToJSON() failed [rel_flow_num]");
			goto end;
		}
	}

	if(retainability_threshold->rel_time_unit) {
		cJSON *rel_time_unit_local_JSON = time_unit_convertToJSON(
			retainability_threshold->rel_time_unit);
		if(rel_time_unit_local_JSON == NULL) {
			printf(
				"retainability_threshold_convertToJSON() failed [rel_time_unit]");
			goto end;
		}
		cJSON_AddItemToObject(item, "relTimeUnit",
		                      rel_time_unit_local_JSON);
		if(item->child == NULL) {
			printf(
				"retainability_threshold_convertToJSON() failed [rel_time_unit]");
			goto end;
		}
	}

	if(retainability_threshold->is_rel_flow_ratio) {
		if(cJSON_AddNumberToObject(item, "relFlowRatio",
		                           retainability_threshold->
		                           rel_flow_ratio) == NULL)
		{
			printf(
				"retainability_threshold_convertToJSON() failed [rel_flow_ratio]");
			goto end;
		}
	}

end:
	return item;
}

retainability_threshold_t *retainability_threshold_parseFromJSON(
	cJSON *retainability_thresholdJSON) {
	retainability_threshold_t *retainability_threshold_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *rel_flow_num = NULL;
	cJSON *rel_time_unit = NULL;
	time_unit_t *rel_time_unit_local_nonprim = NULL;
	cJSON *rel_flow_ratio = NULL;
	rel_flow_num = cJSON_GetObjectItemCaseSensitive(
		retainability_thresholdJSON, "relFlowNum");
	if(rel_flow_num) {
		if(!cJSON_IsNumber(rel_flow_num)) {
			printf(
				"retainability_threshold_parseFromJSON() failed [rel_flow_num]");
			goto end;
		}
	}

	rel_time_unit = cJSON_GetObjectItemCaseSensitive(
		retainability_thresholdJSON, "relTimeUnit");
	if(rel_time_unit) {
		rel_time_unit_local_nonprim = time_unit_parseFromJSON(
			rel_time_unit);
		if(!rel_time_unit_local_nonprim) {
			printf("time_unit_parseFromJSON failed [rel_time_unit]");
			goto end;
		}
	}

	rel_flow_ratio = cJSON_GetObjectItemCaseSensitive(
		retainability_thresholdJSON, "relFlowRatio");
	if(rel_flow_ratio) {
		if(!cJSON_IsNumber(rel_flow_ratio)) {
			printf(
				"retainability_threshold_parseFromJSON() failed [rel_flow_ratio]");
			goto end;
		}
	}

	retainability_threshold_local_var = retainability_threshold_create(
		rel_flow_num ? true : false,
		rel_flow_num ? rel_flow_num->valuedouble : 0,
		rel_time_unit ? rel_time_unit_local_nonprim : NULL,
		rel_flow_ratio ? true : false,
		rel_flow_ratio ? rel_flow_ratio->valuedouble : 0
		);

	return retainability_threshold_local_var;
end:
	if(rel_time_unit_local_nonprim) {
		time_unit_free(rel_time_unit_local_nonprim);
		rel_time_unit_local_nonprim = NULL;
	}
	return NULL;
}

retainability_threshold_t *retainability_threshold_copy(
	retainability_threshold_t *dst, retainability_threshold_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = retainability_threshold_convertToJSON(src);
	if(!item) {
		printf("retainability_threshold_convertToJSON() failed");
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

	retainability_threshold_free(dst);
	dst = retainability_threshold_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
