#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_data_reporting_ind.h"

input_data_reporting_ind_t *input_data_reporting_ind_create() {
	input_data_reporting_ind_t *input_data_reporting_ind_local_var = malloc(
		sizeof(input_data_reporting_ind_t));


	return input_data_reporting_ind_local_var;
}

void input_data_reporting_ind_free(
	input_data_reporting_ind_t *input_data_reporting_ind) {
	lnode_t *node = NULL;

	if(NULL == input_data_reporting_ind) {
		return;
	}
	free(input_data_reporting_ind);
}

cJSON *input_data_reporting_ind_convertToJSON(
	input_data_reporting_ind_t *input_data_reporting_ind) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(input_data_reporting_ind == NULL) {
		printf(
			"input_data_reporting_ind_convertToJSON() failed [InputData_reportingInd]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

input_data_reporting_ind_t *input_data_reporting_ind_parseFromJSON(
	cJSON *input_data_reporting_indJSON) {
	input_data_reporting_ind_t *input_data_reporting_ind_local_var = NULL;
	lnode_t *node = NULL;
	input_data_reporting_ind_local_var = input_data_reporting_ind_create(
		);

	return input_data_reporting_ind_local_var;
end:
	return NULL;
}

input_data_reporting_ind_t *input_data_reporting_ind_copy(
	input_data_reporting_ind_t *dst, input_data_reporting_ind_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = input_data_reporting_ind_convertToJSON(src);
	if(!item) {
		printf("input_data_reporting_ind_convertToJSON() failed");
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

	input_data_reporting_ind_free(dst);
	dst = input_data_reporting_ind_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
