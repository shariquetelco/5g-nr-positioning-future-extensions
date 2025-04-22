#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "report_interval_mdt.h"

report_interval_mdt_t *report_interval_mdt_create() {
	report_interval_mdt_t *report_interval_mdt_local_var =
		malloc(sizeof(report_interval_mdt_t));


	return report_interval_mdt_local_var;
}

void report_interval_mdt_free(report_interval_mdt_t *report_interval_mdt) {
	lnode_t *node = NULL;

	if(NULL == report_interval_mdt) {
		return;
	}
	free(report_interval_mdt);
}

cJSON *report_interval_mdt_convertToJSON(
	report_interval_mdt_t *report_interval_mdt) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(report_interval_mdt == NULL) {
		printf(
			"report_interval_mdt_convertToJSON() failed [ReportIntervalMdt]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

report_interval_mdt_t *report_interval_mdt_parseFromJSON(
	cJSON *report_interval_mdtJSON) {
	report_interval_mdt_t *report_interval_mdt_local_var = NULL;
	lnode_t *node = NULL;
	report_interval_mdt_local_var = report_interval_mdt_create(
		);

	return report_interval_mdt_local_var;
end:
	return NULL;
}

report_interval_mdt_t *report_interval_mdt_copy(report_interval_mdt_t	*dst,
                                                report_interval_mdt_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = report_interval_mdt_convertToJSON(src);
	if(!item) {
		printf("report_interval_mdt_convertToJSON() failed");
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

	report_interval_mdt_free(dst);
	dst = report_interval_mdt_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
