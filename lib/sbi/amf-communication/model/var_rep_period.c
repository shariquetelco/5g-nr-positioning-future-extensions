#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "var_rep_period.h"

var_rep_period_t *var_rep_period_create(int rep_period, uint8_t perc_value_nf_load) {
	var_rep_period_t *var_rep_period_local_var =
		malloc(sizeof(var_rep_period_t));

	var_rep_period_local_var->rep_period = rep_period;
	var_rep_period_local_var->perc_value_nf_load = perc_value_nf_load;

	return var_rep_period_local_var;
}

void var_rep_period_free(var_rep_period_t *var_rep_period) {
	lnode_t *node = NULL;

	if(NULL == var_rep_period) {
		return;
	}
	free(var_rep_period);
}

cJSON *var_rep_period_convertToJSON(var_rep_period_t *var_rep_period) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(var_rep_period == NULL) {
		printf("var_rep_period_convertToJSON() failed [VarRepPeriod]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "repPeriod",
	                           var_rep_period->rep_period) == NULL)
	{
		printf("var_rep_period_convertToJSON() failed [rep_period]");
		goto end;
	}

	if(!var_rep_period->perc_value_nf_load) {
		printf(
			"var_rep_period_convertToJSON() failed [perc_value_nf_load]");
		return NULL;
	}

end:
	return item;
}

var_rep_period_t *var_rep_period_parseFromJSON(cJSON *var_rep_periodJSON) {
	var_rep_period_t *var_rep_period_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *rep_period = NULL;
	cJSON *perc_value_nf_load = NULL;
	rep_period = cJSON_GetObjectItemCaseSensitive(var_rep_periodJSON,
	                                              "repPeriod");
	if(!rep_period) {
		printf("var_rep_period_parseFromJSON() failed [rep_period]");
		goto end;
	}
	if(!cJSON_IsNumber(rep_period)) {
		printf("var_rep_period_parseFromJSON() failed [rep_period]");
		goto end;
	}

	perc_value_nf_load = cJSON_GetObjectItemCaseSensitive(
		var_rep_periodJSON, "percValueNfLoad");
	if(!perc_value_nf_load) {
		printf(
			"var_rep_period_parseFromJSON() failed [perc_value_nf_load]");
		goto end;
	}

	if(!cJSON_IsNumber(perc_value_nf_load)) {
		printf("var_rep_period_parseFromJSON() failed [perc_value_nf_load]");
		goto end;
	}

	var_rep_period_local_var = var_rep_period_create(

		rep_period->valuedouble, perc_value_nf_load->valuedouble
		);

	return var_rep_period_local_var;
end:
	return NULL;
}

var_rep_period_t *var_rep_period_copy(var_rep_period_t	*dst,
                                      var_rep_period_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = var_rep_period_convertToJSON(src);
	if(!item) {
		printf("var_rep_period_convertToJSON() failed");
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

	var_rep_period_free(dst);
	dst = var_rep_period_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
