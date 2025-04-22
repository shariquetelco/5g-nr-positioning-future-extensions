#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_method_and_usage.h"

positioning_method_and_usage_t *positioning_method_and_usage_create(
	positioning_method_e method, positioning_mode_e mode, usage_e usage,
	bool is_method_code, int method_code) {
	positioning_method_and_usage_t *positioning_method_and_usage_local_var =
		malloc(sizeof(positioning_method_and_usage_t));

	positioning_method_and_usage_local_var->method = method;
	positioning_method_and_usage_local_var->mode = mode;
	positioning_method_and_usage_local_var->usage = usage;
	positioning_method_and_usage_local_var->is_method_code = is_method_code;
	positioning_method_and_usage_local_var->method_code = method_code;

	return positioning_method_and_usage_local_var;
}

void positioning_method_and_usage_free(
	positioning_method_and_usage_t *positioning_method_and_usage) {
	lnode_t *node = NULL;

	if(NULL == positioning_method_and_usage) {
		return;
	}
	free(positioning_method_and_usage);
}

cJSON *positioning_method_and_usage_convertToJSON(
	positioning_method_and_usage_t *positioning_method_and_usage) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(positioning_method_and_usage == NULL) {
		printf(
			"positioning_method_and_usage_convertToJSON() failed [PositioningMethodAndUsage]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(positioning_method_and_usage->method == positioning_method_NULL) {
		printf(
			"positioning_method_and_usage_convertToJSON() failed [method]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "method",
	                           positioning_method_ToString(
					   positioning_method_and_usage->method))
	   ==
	   NULL)
	{
		printf(
			"positioning_method_and_usage_convertToJSON() failed [method]");
		goto end;
	}

	if(positioning_method_and_usage->mode == positioning_mode_NULL) {
		printf(
			"positioning_method_and_usage_convertToJSON() failed [mode]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "mode",
	                           positioning_mode_ToString(
					   positioning_method_and_usage->mode))
	   ==
	   NULL)
	{
		printf(
			"positioning_method_and_usage_convertToJSON() failed [mode]");
		goto end;
	}

	if(positioning_method_and_usage->usage == usage_NULL) {
		printf(
			"positioning_method_and_usage_convertToJSON() failed [usage]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "usage",
	                           usage_ToString(positioning_method_and_usage->
	                                          usage)) == NULL)
	{
		printf(
			"positioning_method_and_usage_convertToJSON() failed [usage]");
		goto end;
	}

	if(positioning_method_and_usage->is_method_code) {
		if(cJSON_AddNumberToObject(item, "methodCode",
		                           positioning_method_and_usage->
		                           method_code) == NULL)
		{
			printf(
				"positioning_method_and_usage_convertToJSON() failed [method_code]");
			goto end;
		}
	}

end:
	return item;
}

positioning_method_and_usage_t *positioning_method_and_usage_parseFromJSON(
	cJSON *positioning_method_and_usageJSON) {
	positioning_method_and_usage_t *positioning_method_and_usage_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *method = NULL;
	positioning_method_e methodVariable = 0;
	cJSON *mode = NULL;
	positioning_mode_e modeVariable = 0;
	cJSON *usage = NULL;
	usage_e usageVariable = 0;
	cJSON *method_code = NULL;
	method = cJSON_GetObjectItemCaseSensitive(
		positioning_method_and_usageJSON, "method");
	if(!method) {
		printf(
			"positioning_method_and_usage_parseFromJSON() failed [method]");
		goto end;
	}
	if(!cJSON_IsString(method)) {
		printf(
			"positioning_method_and_usage_parseFromJSON() failed [method]");
		goto end;
	}
	methodVariable = positioning_method_FromString(method->valuestring);

	mode = cJSON_GetObjectItemCaseSensitive(
		positioning_method_and_usageJSON, "mode");
	if(!mode) {
		printf(
			"positioning_method_and_usage_parseFromJSON() failed [mode]");
		goto end;
	}
	if(!cJSON_IsString(mode)) {
		printf(
			"positioning_method_and_usage_parseFromJSON() failed [mode]");
		goto end;
	}
	modeVariable = positioning_mode_FromString(mode->valuestring);

	usage = cJSON_GetObjectItemCaseSensitive(
		positioning_method_and_usageJSON, "usage");
	if(!usage) {
		printf(
			"positioning_method_and_usage_parseFromJSON() failed [usage]");
		goto end;
	}
	if(!cJSON_IsString(usage)) {
		printf(
			"positioning_method_and_usage_parseFromJSON() failed [usage]");
		goto end;
	}
	usageVariable = usage_FromString(usage->valuestring);

	method_code = cJSON_GetObjectItemCaseSensitive(
		positioning_method_and_usageJSON, "methodCode");
	if(method_code) {
		if(!cJSON_IsNumber(method_code)) {
			printf(
				"positioning_method_and_usage_parseFromJSON() failed [method_code]");
			goto end;
		}
	}

	positioning_method_and_usage_local_var =
		positioning_method_and_usage_create(
			methodVariable,
			modeVariable,
			usageVariable,
			method_code ? true : false,
			method_code ? method_code->valuedouble : 0
			);

	return positioning_method_and_usage_local_var;
end:
	return NULL;
}

positioning_method_and_usage_t *positioning_method_and_usage_copy(
	positioning_method_and_usage_t	*dst,
	positioning_method_and_usage_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = positioning_method_and_usage_convertToJSON(src);
	if(!item) {
		printf("positioning_method_and_usage_convertToJSON() failed");
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

	positioning_method_and_usage_free(dst);
	dst = positioning_method_and_usage_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
