#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "red_trans_exp_ordering_criterion.h"

red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion_create() {
	red_trans_exp_ordering_criterion_t *
	        red_trans_exp_ordering_criterion_local_var =
		malloc(sizeof(red_trans_exp_ordering_criterion_t));


	return red_trans_exp_ordering_criterion_local_var;
}

void red_trans_exp_ordering_criterion_free(
	red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion) {
	lnode_t *node = NULL;

	if(NULL == red_trans_exp_ordering_criterion) {
		return;
	}
	free(red_trans_exp_ordering_criterion);
}

cJSON *red_trans_exp_ordering_criterion_convertToJSON(
	red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(red_trans_exp_ordering_criterion == NULL) {
		printf(
			"red_trans_exp_ordering_criterion_convertToJSON() failed [RedTransExpOrderingCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

red_trans_exp_ordering_criterion_t *
red_trans_exp_ordering_criterion_parseFromJSON(
	cJSON *red_trans_exp_ordering_criterionJSON) {
	red_trans_exp_ordering_criterion_t *
	        red_trans_exp_ordering_criterion_local_var = NULL;
	lnode_t *node = NULL;
	red_trans_exp_ordering_criterion_local_var =
		red_trans_exp_ordering_criterion_create(
			);

	return red_trans_exp_ordering_criterion_local_var;
end:
	return NULL;
}

red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion_copy(
	red_trans_exp_ordering_criterion_t	*dst,
	red_trans_exp_ordering_criterion_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = red_trans_exp_ordering_criterion_convertToJSON(src);
	if(!item) {
		printf("red_trans_exp_ordering_criterion_convertToJSON() failed");
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

	red_trans_exp_ordering_criterion_free(dst);
	dst = red_trans_exp_ordering_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
