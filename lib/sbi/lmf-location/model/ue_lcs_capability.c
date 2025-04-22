#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_lcs_capability.h"

ue_lcs_capability_t *ue_lcs_capability_create(bool	is_lpp_support,
                                              int	lpp_support,
                                              bool	is_ciot_optimisation,
                                              int	ciot_optimisation) {
	ue_lcs_capability_t *ue_lcs_capability_local_var =
		malloc(sizeof(ue_lcs_capability_t));

	ue_lcs_capability_local_var->is_lpp_support = is_lpp_support;
	ue_lcs_capability_local_var->lpp_support = lpp_support;
	ue_lcs_capability_local_var->is_ciot_optimisation =
		is_ciot_optimisation;
	ue_lcs_capability_local_var->ciot_optimisation = ciot_optimisation;

	return ue_lcs_capability_local_var;
}

void ue_lcs_capability_free(ue_lcs_capability_t *ue_lcs_capability) {
	lnode_t *node = NULL;

	if(NULL == ue_lcs_capability) {
		return;
	}
	free(ue_lcs_capability);
}

cJSON *ue_lcs_capability_convertToJSON(ue_lcs_capability_t *ue_lcs_capability) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_lcs_capability == NULL) {
		printf(
			"ue_lcs_capability_convertToJSON() failed [UeLcsCapability]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_lcs_capability->is_lpp_support) {
		if(cJSON_AddBoolToObject(item, "lppSupport",
		                         ue_lcs_capability->lpp_support) ==
		   NULL)
		{
			printf(
				"ue_lcs_capability_convertToJSON() failed [lpp_support]");
			goto end;
		}
	}

	if(ue_lcs_capability->is_ciot_optimisation) {
		if(cJSON_AddBoolToObject(item, "ciotOptimisation",
		                         ue_lcs_capability->ciot_optimisation)
		   == NULL)
		{
			printf(
				"ue_lcs_capability_convertToJSON() failed [ciot_optimisation]");
			goto end;
		}
	}

end:
	return item;
}

ue_lcs_capability_t *ue_lcs_capability_parseFromJSON(
	cJSON *ue_lcs_capabilityJSON) {
	ue_lcs_capability_t *ue_lcs_capability_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *lpp_support = NULL;
	cJSON *ciot_optimisation = NULL;
	lpp_support = cJSON_GetObjectItemCaseSensitive(ue_lcs_capabilityJSON,
	                                               "lppSupport");
	if(lpp_support) {
		if(!cJSON_IsBool(lpp_support)) {
			printf(
				"ue_lcs_capability_parseFromJSON() failed [lpp_support]");
			goto end;
		}
	}

	ciot_optimisation = cJSON_GetObjectItemCaseSensitive(
		ue_lcs_capabilityJSON, "ciotOptimisation");
	if(ciot_optimisation) {
		if(!cJSON_IsBool(ciot_optimisation)) {
			printf(
				"ue_lcs_capability_parseFromJSON() failed [ciot_optimisation]");
			goto end;
		}
	}

	ue_lcs_capability_local_var = ue_lcs_capability_create(
		lpp_support ? true : false,
		lpp_support ? lpp_support->valueint : 0,
		ciot_optimisation ? true : false,
		ciot_optimisation ? ciot_optimisation->valueint : 0
		);

	return ue_lcs_capability_local_var;
end:
	return NULL;
}

ue_lcs_capability_t *ue_lcs_capability_copy(ue_lcs_capability_t *dst,
                                            ue_lcs_capability_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_lcs_capability_convertToJSON(src);
	if(!item) {
		printf("ue_lcs_capability_convertToJSON() failed");
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

	ue_lcs_capability_free(dst);
	dst = ue_lcs_capability_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
