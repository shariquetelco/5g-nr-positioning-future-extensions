#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "e2e_data_vol_trans_time_criterion.h"

e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion_create()
{
	e2e_data_vol_trans_time_criterion_t *
	        e2e_data_vol_trans_time_criterion_local_var =
		malloc(sizeof(e2e_data_vol_trans_time_criterion_t));


	return e2e_data_vol_trans_time_criterion_local_var;
}

void e2e_data_vol_trans_time_criterion_free(
	e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion)
{
	lnode_t *node = NULL;

	if(NULL == e2e_data_vol_trans_time_criterion) {
		return;
	}
	free(e2e_data_vol_trans_time_criterion);
}

cJSON *e2e_data_vol_trans_time_criterion_convertToJSON(
	e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(e2e_data_vol_trans_time_criterion == NULL) {
		printf(
			"e2e_data_vol_trans_time_criterion_convertToJSON() failed [E2eDataVolTransTimeCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

e2e_data_vol_trans_time_criterion_t *
e2e_data_vol_trans_time_criterion_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_criterionJSON) {
	e2e_data_vol_trans_time_criterion_t *
	        e2e_data_vol_trans_time_criterion_local_var = NULL;
	lnode_t *node = NULL;
	e2e_data_vol_trans_time_criterion_local_var =
		e2e_data_vol_trans_time_criterion_create(
			);

	return e2e_data_vol_trans_time_criterion_local_var;
end:
	return NULL;
}

e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion_copy(
	e2e_data_vol_trans_time_criterion_t	*dst,
	e2e_data_vol_trans_time_criterion_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = e2e_data_vol_trans_time_criterion_convertToJSON(src);
	if(!item) {
		printf(
			"e2e_data_vol_trans_time_criterion_convertToJSON() failed");
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

	e2e_data_vol_trans_time_criterion_free(dst);
	dst = e2e_data_vol_trans_time_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
