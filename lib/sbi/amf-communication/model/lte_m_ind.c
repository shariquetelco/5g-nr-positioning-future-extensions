#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lte_m_ind.h"

lte_m_ind_t *lte_m_ind_create(int lte_cat_m_ind) {
	lte_m_ind_t *lte_m_ind_local_var = malloc(sizeof(lte_m_ind_t));

	lte_m_ind_local_var->lte_cat_m_ind = lte_cat_m_ind;

	return lte_m_ind_local_var;
}

void lte_m_ind_free(lte_m_ind_t *lte_m_ind) {
	lnode_t *node = NULL;

	if(NULL == lte_m_ind) {
		return;
	}
	free(lte_m_ind);
}

cJSON *lte_m_ind_convertToJSON(lte_m_ind_t *lte_m_ind) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(lte_m_ind == NULL) {
		printf("lte_m_ind_convertToJSON() failed [LteMInd]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddBoolToObject(item, "lteCatMInd",
	                         lte_m_ind->lte_cat_m_ind) == NULL)
	{
		printf("lte_m_ind_convertToJSON() failed [lte_cat_m_ind]");
		goto end;
	}

end:
	return item;
}

lte_m_ind_t *lte_m_ind_parseFromJSON(cJSON *lte_m_indJSON) {
	lte_m_ind_t *lte_m_ind_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *lte_cat_m_ind = NULL;
	lte_cat_m_ind = cJSON_GetObjectItemCaseSensitive(lte_m_indJSON,
	                                                 "lteCatMInd");
	if(!lte_cat_m_ind) {
		printf("lte_m_ind_parseFromJSON() failed [lte_cat_m_ind]");
		goto end;
	}
	if(!cJSON_IsBool(lte_cat_m_ind)) {
		printf("lte_m_ind_parseFromJSON() failed [lte_cat_m_ind]");
		goto end;
	}

	lte_m_ind_local_var = lte_m_ind_create(

		lte_cat_m_ind->valueint
		);

	return lte_m_ind_local_var;
end:
	return NULL;
}

lte_m_ind_t *lte_m_ind_copy(lte_m_ind_t *dst, lte_m_ind_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = lte_m_ind_convertToJSON(src);
	if(!item) {
		printf("lte_m_ind_convertToJSON() failed");
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

	lte_m_ind_free(dst);
	dst = lte_m_ind_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
