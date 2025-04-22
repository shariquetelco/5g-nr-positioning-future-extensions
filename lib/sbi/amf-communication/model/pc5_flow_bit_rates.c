#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pc5_flow_bit_rates.h"

pc5_flow_bit_rates_t *pc5_flow_bit_rates_create(char *gua_fbr, char *max_fbr) {
	pc5_flow_bit_rates_t *pc5_flow_bit_rates_local_var =
		malloc(sizeof(pc5_flow_bit_rates_t));

	pc5_flow_bit_rates_local_var->gua_fbr = gua_fbr;
	pc5_flow_bit_rates_local_var->max_fbr = max_fbr;

	return pc5_flow_bit_rates_local_var;
}

void pc5_flow_bit_rates_free(pc5_flow_bit_rates_t *pc5_flow_bit_rates) {
	lnode_t *node = NULL;

	if(NULL == pc5_flow_bit_rates) {
		return;
	}
	if(pc5_flow_bit_rates->gua_fbr) {
		free(pc5_flow_bit_rates->gua_fbr);
		pc5_flow_bit_rates->gua_fbr = NULL;
	}
	if(pc5_flow_bit_rates->max_fbr) {
		free(pc5_flow_bit_rates->max_fbr);
		pc5_flow_bit_rates->max_fbr = NULL;
	}
	free(pc5_flow_bit_rates);
}

cJSON *pc5_flow_bit_rates_convertToJSON(
	pc5_flow_bit_rates_t *pc5_flow_bit_rates) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pc5_flow_bit_rates == NULL) {
		printf(
			"pc5_flow_bit_rates_convertToJSON() failed [Pc5FlowBitRates]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(pc5_flow_bit_rates->gua_fbr) {
		if(cJSON_AddStringToObject(item, "guaFbr",
		                           pc5_flow_bit_rates->gua_fbr) == NULL)
		{
			printf(
				"pc5_flow_bit_rates_convertToJSON() failed [gua_fbr]");
			goto end;
		}
	}

	if(pc5_flow_bit_rates->max_fbr) {
		if(cJSON_AddStringToObject(item, "maxFbr",
		                           pc5_flow_bit_rates->max_fbr) == NULL)
		{
			printf(
				"pc5_flow_bit_rates_convertToJSON() failed [max_fbr]");
			goto end;
		}
	}

end:
	return item;
}

pc5_flow_bit_rates_t *pc5_flow_bit_rates_parseFromJSON(
	cJSON *pc5_flow_bit_ratesJSON) {
	pc5_flow_bit_rates_t *pc5_flow_bit_rates_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *gua_fbr = NULL;
	cJSON *max_fbr = NULL;
	gua_fbr = cJSON_GetObjectItemCaseSensitive(pc5_flow_bit_ratesJSON,
	                                           "guaFbr");
	if(gua_fbr) {
		if(!cJSON_IsString(gua_fbr) &&
		   !cJSON_IsNull(gua_fbr))
		{
			printf(
				"pc5_flow_bit_rates_parseFromJSON() failed [gua_fbr]");
			goto end;
		}
	}

	max_fbr = cJSON_GetObjectItemCaseSensitive(pc5_flow_bit_ratesJSON,
	                                           "maxFbr");
	if(max_fbr) {
		if(!cJSON_IsString(max_fbr) &&
		   !cJSON_IsNull(max_fbr))
		{
			printf(
				"pc5_flow_bit_rates_parseFromJSON() failed [max_fbr]");
			goto end;
		}
	}

	pc5_flow_bit_rates_local_var = pc5_flow_bit_rates_create(
		gua_fbr &&
		!cJSON_IsNull(gua_fbr) ? strdup(gua_fbr->valuestring) : NULL,
		max_fbr &&
		!cJSON_IsNull(max_fbr) ? strdup(max_fbr->valuestring) : NULL
		);

	return pc5_flow_bit_rates_local_var;
end:
	return NULL;
}

pc5_flow_bit_rates_t *pc5_flow_bit_rates_copy(pc5_flow_bit_rates_t	*dst,
                                              pc5_flow_bit_rates_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pc5_flow_bit_rates_convertToJSON(src);
	if(!item) {
		printf("pc5_flow_bit_rates_convertToJSON() failed");
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

	pc5_flow_bit_rates_free(dst);
	dst = pc5_flow_bit_rates_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
