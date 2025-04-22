#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gnss_positioning_method_and_usage.h"

gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_create(
	positioning_mode_e mode, gnss_id_e gnss, usage_e usage) {
	gnss_positioning_method_and_usage_t *
	        gnss_positioning_method_and_usage_local_var =
		malloc(sizeof(gnss_positioning_method_and_usage_t));

	gnss_positioning_method_and_usage_local_var->mode = mode;
	gnss_positioning_method_and_usage_local_var->gnss = gnss;
	gnss_positioning_method_and_usage_local_var->usage = usage;

	return gnss_positioning_method_and_usage_local_var;
}

void gnss_positioning_method_and_usage_free(
	gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage)
{
	lnode_t *node = NULL;

	if(NULL == gnss_positioning_method_and_usage) {
		return;
	}
	free(gnss_positioning_method_and_usage);
}

cJSON *gnss_positioning_method_and_usage_convertToJSON(
	gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(gnss_positioning_method_and_usage == NULL) {
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed [GnssPositioningMethodAndUsage]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(gnss_positioning_method_and_usage->mode == positioning_mode_NULL) {
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed [mode]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "mode",
	                           positioning_mode_ToString(
					   gnss_positioning_method_and_usage->
					   mode)) ==
	   NULL)
	{
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed [mode]");
		goto end;
	}

	if(gnss_positioning_method_and_usage->gnss == gnss_id_NULL) {
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed [gnss]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "gnss",
	                           gnss_id_ToString(
					   gnss_positioning_method_and_usage->
					   gnss)) == NULL)
	{
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed [gnss]");
		goto end;
	}

	if(gnss_positioning_method_and_usage->usage == usage_NULL) {
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed [usage]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "usage",
	                           usage_ToString(
					   gnss_positioning_method_and_usage->
					   usage)) == NULL)
	{
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed [usage]");
		goto end;
	}

end:
	return item;
}

gnss_positioning_method_and_usage_t *
gnss_positioning_method_and_usage_parseFromJSON(
	cJSON *gnss_positioning_method_and_usageJSON) {
	gnss_positioning_method_and_usage_t *
	        gnss_positioning_method_and_usage_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *mode = NULL;
	positioning_mode_e modeVariable = 0;
	cJSON *gnss = NULL;
	gnss_id_e gnssVariable = 0;
	cJSON *usage = NULL;
	usage_e usageVariable = 0;
	mode = cJSON_GetObjectItemCaseSensitive(
		gnss_positioning_method_and_usageJSON, "mode");
	if(!mode) {
		printf(
			"gnss_positioning_method_and_usage_parseFromJSON() failed [mode]");
		goto end;
	}
	if(!cJSON_IsString(mode)) {
		printf(
			"gnss_positioning_method_and_usage_parseFromJSON() failed [mode]");
		goto end;
	}
	modeVariable = positioning_mode_FromString(mode->valuestring);

	gnss = cJSON_GetObjectItemCaseSensitive(
		gnss_positioning_method_and_usageJSON, "gnss");
	if(!gnss) {
		printf(
			"gnss_positioning_method_and_usage_parseFromJSON() failed [gnss]");
		goto end;
	}
	if(!cJSON_IsString(gnss)) {
		printf(
			"gnss_positioning_method_and_usage_parseFromJSON() failed [gnss]");
		goto end;
	}
	gnssVariable = gnss_id_FromString(gnss->valuestring);

	usage = cJSON_GetObjectItemCaseSensitive(
		gnss_positioning_method_and_usageJSON, "usage");
	if(!usage) {
		printf(
			"gnss_positioning_method_and_usage_parseFromJSON() failed [usage]");
		goto end;
	}
	if(!cJSON_IsString(usage)) {
		printf(
			"gnss_positioning_method_and_usage_parseFromJSON() failed [usage]");
		goto end;
	}
	usageVariable = usage_FromString(usage->valuestring);

	gnss_positioning_method_and_usage_local_var =
		gnss_positioning_method_and_usage_create(
			modeVariable,
			gnssVariable,
			usageVariable
			);

	return gnss_positioning_method_and_usage_local_var;
end:
	return NULL;
}

gnss_positioning_method_and_usage_t *gnss_positioning_method_and_usage_copy(
	gnss_positioning_method_and_usage_t	*dst,
	gnss_positioning_method_and_usage_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = gnss_positioning_method_and_usage_convertToJSON(src);
	if(!item) {
		printf(
			"gnss_positioning_method_and_usage_convertToJSON() failed");
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

	gnss_positioning_method_and_usage_free(dst);
	dst = gnss_positioning_method_and_usage_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
