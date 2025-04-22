#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_comm_order_criterion.h"

ue_comm_order_criterion_t *ue_comm_order_criterion_create() {
	ue_comm_order_criterion_t *ue_comm_order_criterion_local_var = malloc(
		sizeof(ue_comm_order_criterion_t));


	return ue_comm_order_criterion_local_var;
}

void ue_comm_order_criterion_free(
	ue_comm_order_criterion_t *ue_comm_order_criterion) {
	lnode_t *node = NULL;

	if(NULL == ue_comm_order_criterion) {
		return;
	}
	free(ue_comm_order_criterion);
}

cJSON *ue_comm_order_criterion_convertToJSON(
	ue_comm_order_criterion_t *ue_comm_order_criterion) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_comm_order_criterion == NULL) {
		printf(
			"ue_comm_order_criterion_convertToJSON() failed [UeCommOrderCriterion]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

ue_comm_order_criterion_t *ue_comm_order_criterion_parseFromJSON(
	cJSON *ue_comm_order_criterionJSON) {
	ue_comm_order_criterion_t *ue_comm_order_criterion_local_var = NULL;
	lnode_t *node = NULL;
	ue_comm_order_criterion_local_var = ue_comm_order_criterion_create(
		);

	return ue_comm_order_criterion_local_var;
end:
	return NULL;
}

ue_comm_order_criterion_t *ue_comm_order_criterion_copy(
	ue_comm_order_criterion_t *dst, ue_comm_order_criterion_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_comm_order_criterion_convertToJSON(src);
	if(!item) {
		printf("ue_comm_order_criterion_convertToJSON() failed");
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

	ue_comm_order_criterion_free(dst);
	dst = ue_comm_order_criterion_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
