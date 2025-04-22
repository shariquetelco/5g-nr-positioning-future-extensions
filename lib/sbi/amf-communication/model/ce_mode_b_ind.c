#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ce_mode_b_ind.h"

ce_mode_b_ind_t *ce_mode_b_ind_create(int ce_mode_b_support_ind) {
	ce_mode_b_ind_t *ce_mode_b_ind_local_var = malloc(
		sizeof(ce_mode_b_ind_t));

	ce_mode_b_ind_local_var->ce_mode_b_support_ind = ce_mode_b_support_ind;

	return ce_mode_b_ind_local_var;
}

void ce_mode_b_ind_free(ce_mode_b_ind_t *ce_mode_b_ind) {
	lnode_t *node = NULL;

	if(NULL == ce_mode_b_ind) {
		return;
	}
	free(ce_mode_b_ind);
}

cJSON *ce_mode_b_ind_convertToJSON(ce_mode_b_ind_t *ce_mode_b_ind) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ce_mode_b_ind == NULL) {
		printf("ce_mode_b_ind_convertToJSON() failed [CeModeBInd]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddBoolToObject(item, "ceModeBSupportInd",
	                         ce_mode_b_ind->ce_mode_b_support_ind) == NULL)
	{
		printf(
			"ce_mode_b_ind_convertToJSON() failed [ce_mode_b_support_ind]");
		goto end;
	}

end:
	return item;
}

ce_mode_b_ind_t *ce_mode_b_ind_parseFromJSON(cJSON *ce_mode_b_indJSON) {
	ce_mode_b_ind_t *ce_mode_b_ind_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ce_mode_b_support_ind = NULL;
	ce_mode_b_support_ind = cJSON_GetObjectItemCaseSensitive(
		ce_mode_b_indJSON, "ceModeBSupportInd");
	if(!ce_mode_b_support_ind) {
		printf(
			"ce_mode_b_ind_parseFromJSON() failed [ce_mode_b_support_ind]");
		goto end;
	}
	if(!cJSON_IsBool(ce_mode_b_support_ind)) {
		printf(
			"ce_mode_b_ind_parseFromJSON() failed [ce_mode_b_support_ind]");
		goto end;
	}

	ce_mode_b_ind_local_var = ce_mode_b_ind_create(

		ce_mode_b_support_ind->valueint
		);

	return ce_mode_b_ind_local_var;
end:
	return NULL;
}

ce_mode_b_ind_t *ce_mode_b_ind_copy(ce_mode_b_ind_t	*dst,
                                    ce_mode_b_ind_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ce_mode_b_ind_convertToJSON(src);
	if(!item) {
		printf("ce_mode_b_ind_convertToJSON() failed");
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

	ce_mode_b_ind_free(dst);
	dst = ce_mode_b_ind_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
