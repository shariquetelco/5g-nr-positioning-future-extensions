#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ranking_criterion.h"

ranking_criterion_t *ranking_criterion_create(int high_base, int low_base) {
	ranking_criterion_t *ranking_criterion_local_var =
		malloc(sizeof(ranking_criterion_t));

	ranking_criterion_local_var->high_base = high_base;
	ranking_criterion_local_var->low_base = low_base;

	return ranking_criterion_local_var;
}

void ranking_criterion_free(ranking_criterion_t *ranking_criterion) {
	lnode_t *node = NULL;

	if(NULL == ranking_criterion) {
		return;
	}
	free(ranking_criterion);
}

cJSON *ranking_criterion_convertToJSON(ranking_criterion_t *ranking_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ranking_criterion == NULL) {
		printf(
			"ranking_criterion_convertToJSON() failed [RankingCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "highBase",
	                           ranking_criterion->high_base) == NULL)
	{
		printf("ranking_criterion_convertToJSON() failed [high_base]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "lowBase",
	                           ranking_criterion->low_base) == NULL)
	{
		printf("ranking_criterion_convertToJSON() failed [low_base]");
		goto end;
	}

end:
	return item;
}

ranking_criterion_t *ranking_criterion_parseFromJSON(
	cJSON *ranking_criterionJSON) {
	ranking_criterion_t *ranking_criterion_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *high_base = NULL;
	cJSON *low_base = NULL;
	high_base = cJSON_GetObjectItemCaseSensitive(ranking_criterionJSON,
	                                             "highBase");
	if(!high_base) {
		printf("ranking_criterion_parseFromJSON() failed [high_base]");
		goto end;
	}
	if(!cJSON_IsNumber(high_base)) {
		printf("ranking_criterion_parseFromJSON() failed [high_base]");
		goto end;
	}

	low_base = cJSON_GetObjectItemCaseSensitive(ranking_criterionJSON,
	                                            "lowBase");
	if(!low_base) {
		printf("ranking_criterion_parseFromJSON() failed [low_base]");
		goto end;
	}
	if(!cJSON_IsNumber(low_base)) {
		printf("ranking_criterion_parseFromJSON() failed [low_base]");
		goto end;
	}

	ranking_criterion_local_var = ranking_criterion_create(

		high_base->valuedouble,

		low_base->valuedouble
		);

	return ranking_criterion_local_var;
end:
	return NULL;
}

ranking_criterion_t *ranking_criterion_copy(ranking_criterion_t *dst,
                                            ranking_criterion_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ranking_criterion_convertToJSON(src);
	if(!item) {
		printf("ranking_criterion_convertToJSON() failed");
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

	ranking_criterion_free(dst);
	dst = ranking_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
