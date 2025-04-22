#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "high_accuracy_gnss_metrics.h"

high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_create(
	bool is_nr_of_used_satellites, int nr_of_used_satellites, bool is_hdopi,
	int hdopi, bool is_pdopi, int pdopi, bool is_age, int age,
	fix_type_e fix_type) {
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_local_var =
		malloc(sizeof(high_accuracy_gnss_metrics_t));

	high_accuracy_gnss_metrics_local_var->is_nr_of_used_satellites =
		is_nr_of_used_satellites;
	high_accuracy_gnss_metrics_local_var->nr_of_used_satellites =
		nr_of_used_satellites;
	high_accuracy_gnss_metrics_local_var->is_hdopi = is_hdopi;
	high_accuracy_gnss_metrics_local_var->hdopi = hdopi;
	high_accuracy_gnss_metrics_local_var->is_pdopi = is_pdopi;
	high_accuracy_gnss_metrics_local_var->pdopi = pdopi;
	high_accuracy_gnss_metrics_local_var->is_age = is_age;
	high_accuracy_gnss_metrics_local_var->age = age;
	high_accuracy_gnss_metrics_local_var->fix_type = fix_type;

	return high_accuracy_gnss_metrics_local_var;
}

void high_accuracy_gnss_metrics_free(
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics) {
	lnode_t *node = NULL;

	if(NULL == high_accuracy_gnss_metrics) {
		return;
	}
	free(high_accuracy_gnss_metrics);
}

cJSON *high_accuracy_gnss_metrics_convertToJSON(
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(high_accuracy_gnss_metrics == NULL) {
		printf(
			"high_accuracy_gnss_metrics_convertToJSON() failed [HighAccuracyGnssMetrics]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(high_accuracy_gnss_metrics->is_nr_of_used_satellites) {
		if(cJSON_AddNumberToObject(item, "nrOfUsedSatellites",
		                           high_accuracy_gnss_metrics->
		                           nr_of_used_satellites) == NULL)
		{
			printf(
				"high_accuracy_gnss_metrics_convertToJSON() failed [nr_of_used_satellites]");
			goto end;
		}
	}

	if(high_accuracy_gnss_metrics->is_hdopi) {
		if(cJSON_AddNumberToObject(item, "hdopi",
		                           high_accuracy_gnss_metrics->hdopi) ==
		   NULL)
		{
			printf(
				"high_accuracy_gnss_metrics_convertToJSON() failed [hdopi]");
			goto end;
		}
	}

	if(high_accuracy_gnss_metrics->is_pdopi) {
		if(cJSON_AddNumberToObject(item, "pdopi",
		                           high_accuracy_gnss_metrics->pdopi) ==
		   NULL)
		{
			printf(
				"high_accuracy_gnss_metrics_convertToJSON() failed [pdopi]");
			goto end;
		}
	}

	if(high_accuracy_gnss_metrics->is_age) {
		if(cJSON_AddNumberToObject(item, "age",
		                           high_accuracy_gnss_metrics->age) ==
		   NULL)
		{
			printf(
				"high_accuracy_gnss_metrics_convertToJSON() failed [age]");
			goto end;
		}
	}

	if(high_accuracy_gnss_metrics->fix_type != fix_type_NULL) {
		if(cJSON_AddStringToObject(item, "fixType",
		                           fix_type_ToString(
						   high_accuracy_gnss_metrics->
						   fix_type)) ==
		   NULL)
		{
			printf(
				"high_accuracy_gnss_metrics_convertToJSON() failed [fix_type]");
			goto end;
		}
	}

end:
	return item;
}

high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_parseFromJSON(
	cJSON *high_accuracy_gnss_metricsJSON) {
	high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *nr_of_used_satellites = NULL;
	cJSON *hdopi = NULL;
	cJSON *pdopi = NULL;
	cJSON *age = NULL;
	cJSON *fix_type = NULL;
	fix_type_e fix_typeVariable = 0;
	nr_of_used_satellites = cJSON_GetObjectItemCaseSensitive(
		high_accuracy_gnss_metricsJSON, "nrOfUsedSatellites");
	if(nr_of_used_satellites) {
		if(!cJSON_IsNumber(nr_of_used_satellites)) {
			printf(
				"high_accuracy_gnss_metrics_parseFromJSON() failed [nr_of_used_satellites]");
			goto end;
		}
	}

	hdopi = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON,
	                                         "hdopi");
	if(hdopi) {
		if(!cJSON_IsNumber(hdopi)) {
			printf(
				"high_accuracy_gnss_metrics_parseFromJSON() failed [hdopi]");
			goto end;
		}
	}

	pdopi = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON,
	                                         "pdopi");
	if(pdopi) {
		if(!cJSON_IsNumber(pdopi)) {
			printf(
				"high_accuracy_gnss_metrics_parseFromJSON() failed [pdopi]");
			goto end;
		}
	}

	age = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON,
	                                       "age");
	if(age) {
		if(!cJSON_IsNumber(age)) {
			printf(
				"high_accuracy_gnss_metrics_parseFromJSON() failed [age]");
			goto end;
		}
	}

	fix_type = cJSON_GetObjectItemCaseSensitive(
		high_accuracy_gnss_metricsJSON, "fixType");
	if(fix_type) {
		if(!cJSON_IsString(fix_type)) {
			printf(
				"high_accuracy_gnss_metrics_parseFromJSON() failed [fix_type]");
			goto end;
		}
		fix_typeVariable = fix_type_FromString(fix_type->valuestring);
	}

	high_accuracy_gnss_metrics_local_var =
		high_accuracy_gnss_metrics_create(
			nr_of_used_satellites ? true : false,
			nr_of_used_satellites ? nr_of_used_satellites->valuedouble : 0,
			hdopi ? true : false,
			hdopi ? hdopi->valuedouble : 0,
			pdopi ? true : false,
			pdopi ? pdopi->valuedouble : 0,
			age ? true : false,
			age ? age->valuedouble : 0,
			fix_type ? fix_typeVariable : 0
			);

	return high_accuracy_gnss_metrics_local_var;
end:
	return NULL;
}

high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_copy(
	high_accuracy_gnss_metrics_t *dst, high_accuracy_gnss_metrics_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = high_accuracy_gnss_metrics_convertToJSON(src);
	if(!item) {
		printf("high_accuracy_gnss_metrics_convertToJSON() failed");
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

	high_accuracy_gnss_metrics_free(dst);
	dst = high_accuracy_gnss_metrics_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
