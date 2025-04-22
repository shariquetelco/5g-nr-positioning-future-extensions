#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_cum_evt_rpt_criteria.h"

up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_create(
	bool is_evt_rpt_time_criteria, int evt_rpt_time_criteria,
	bool is_evt_rpt_count_criteria, int evt_rpt_count_criteria) {
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_var = malloc(
		sizeof(up_cum_evt_rpt_criteria_t));

	up_cum_evt_rpt_criteria_local_var->is_evt_rpt_time_criteria =
		is_evt_rpt_time_criteria;
	up_cum_evt_rpt_criteria_local_var->evt_rpt_time_criteria =
		evt_rpt_time_criteria;
	up_cum_evt_rpt_criteria_local_var->is_evt_rpt_count_criteria =
		is_evt_rpt_count_criteria;
	up_cum_evt_rpt_criteria_local_var->evt_rpt_count_criteria =
		evt_rpt_count_criteria;

	return up_cum_evt_rpt_criteria_local_var;
}

void up_cum_evt_rpt_criteria_free(
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria) {
	lnode_t *node = NULL;

	if(NULL == up_cum_evt_rpt_criteria) {
		return;
	}
	free(up_cum_evt_rpt_criteria);
}

cJSON *up_cum_evt_rpt_criteria_convertToJSON(
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(up_cum_evt_rpt_criteria == NULL) {
		printf(
			"up_cum_evt_rpt_criteria_convertToJSON() failed [UpCumEvtRptCriteria]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(up_cum_evt_rpt_criteria->is_evt_rpt_time_criteria) {
		if(cJSON_AddNumberToObject(item, "evtRptTimeCriteria",
		                           up_cum_evt_rpt_criteria->
		                           evt_rpt_time_criteria) == NULL)
		{
			printf(
				"up_cum_evt_rpt_criteria_convertToJSON() failed [evt_rpt_time_criteria]");
			goto end;
		}
	}

	if(up_cum_evt_rpt_criteria->is_evt_rpt_count_criteria) {
		if(cJSON_AddNumberToObject(item, "evtRptCountCriteria",
		                           up_cum_evt_rpt_criteria->
		                           evt_rpt_count_criteria) == NULL)
		{
			printf(
				"up_cum_evt_rpt_criteria_convertToJSON() failed [evt_rpt_count_criteria]");
			goto end;
		}
	}

end:
	return item;
}

up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_parseFromJSON(
	cJSON *up_cum_evt_rpt_criteriaJSON) {
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *evt_rpt_time_criteria = NULL;
	cJSON *evt_rpt_count_criteria = NULL;
	evt_rpt_time_criteria = cJSON_GetObjectItemCaseSensitive(
		up_cum_evt_rpt_criteriaJSON, "evtRptTimeCriteria");
	if(evt_rpt_time_criteria) {
		if(!cJSON_IsNumber(evt_rpt_time_criteria)) {
			printf(
				"up_cum_evt_rpt_criteria_parseFromJSON() failed [evt_rpt_time_criteria]");
			goto end;
		}
	}

	evt_rpt_count_criteria = cJSON_GetObjectItemCaseSensitive(
		up_cum_evt_rpt_criteriaJSON, "evtRptCountCriteria");
	if(evt_rpt_count_criteria) {
		if(!cJSON_IsNumber(evt_rpt_count_criteria)) {
			printf(
				"up_cum_evt_rpt_criteria_parseFromJSON() failed [evt_rpt_count_criteria]");
			goto end;
		}
	}

	up_cum_evt_rpt_criteria_local_var = up_cum_evt_rpt_criteria_create(
		evt_rpt_time_criteria ? true : false,
		evt_rpt_time_criteria ? evt_rpt_time_criteria->valuedouble : 0,
		evt_rpt_count_criteria ? true : false,
		evt_rpt_count_criteria ? evt_rpt_count_criteria->valuedouble : 0
		);

	return up_cum_evt_rpt_criteria_local_var;
end:
	return NULL;
}

up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_copy(
	up_cum_evt_rpt_criteria_t *dst, up_cum_evt_rpt_criteria_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = up_cum_evt_rpt_criteria_convertToJSON(src);
	if(!item) {
		printf("up_cum_evt_rpt_criteria_convertToJSON() failed");
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

	up_cum_evt_rpt_criteria_free(dst);
	dst = up_cum_evt_rpt_criteria_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
