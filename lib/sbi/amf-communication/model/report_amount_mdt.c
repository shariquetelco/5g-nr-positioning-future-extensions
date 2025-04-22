#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "report_amount_mdt.h"

report_amount_mdt_t *report_amount_mdt_create() {
	report_amount_mdt_t *report_amount_mdt_local_var =
		malloc(sizeof(report_amount_mdt_t));


	return report_amount_mdt_local_var;
}

void report_amount_mdt_free(report_amount_mdt_t *report_amount_mdt) {
	lnode_t *node = NULL;

	if(NULL == report_amount_mdt) {
		return;
	}
	free(report_amount_mdt);
}

cJSON *report_amount_mdt_convertToJSON(report_amount_mdt_t *report_amount_mdt) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(report_amount_mdt == NULL) {
		printf(
			"report_amount_mdt_convertToJSON() failed [ReportAmountMdt]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

report_amount_mdt_t *report_amount_mdt_parseFromJSON(
	cJSON *report_amount_mdtJSON) {
	report_amount_mdt_t *report_amount_mdt_local_var = NULL;
	lnode_t *node = NULL;
	report_amount_mdt_local_var = report_amount_mdt_create(
		);

	return report_amount_mdt_local_var;
end:
	return NULL;
}

report_amount_mdt_t *report_amount_mdt_copy(report_amount_mdt_t *dst,
                                            report_amount_mdt_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = report_amount_mdt_convertToJSON(src);
	if(!item) {
		printf("report_amount_mdt_convertToJSON() failed");
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

	report_amount_mdt_free(dst);
	dst = report_amount_mdt_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
