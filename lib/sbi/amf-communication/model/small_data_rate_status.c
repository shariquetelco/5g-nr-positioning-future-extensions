#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "small_data_rate_status.h"

small_data_rate_status_t *small_data_rate_status_create(
	bool is_remain_packets_ul, int remain_packets_ul,
	bool is_remain_packets_dl, int remain_packets_dl, char *validity_time,
	bool is_remain_ex_reports_ul, int remain_ex_reports_ul,
	bool is_remain_ex_reports_dl, int remain_ex_reports_dl) {
	small_data_rate_status_t *small_data_rate_status_local_var = malloc(
		sizeof(small_data_rate_status_t));

	small_data_rate_status_local_var->is_remain_packets_ul =
		is_remain_packets_ul;
	small_data_rate_status_local_var->remain_packets_ul = remain_packets_ul;
	small_data_rate_status_local_var->is_remain_packets_dl =
		is_remain_packets_dl;
	small_data_rate_status_local_var->remain_packets_dl = remain_packets_dl;
	small_data_rate_status_local_var->validity_time = validity_time;
	small_data_rate_status_local_var->is_remain_ex_reports_ul =
		is_remain_ex_reports_ul;
	small_data_rate_status_local_var->remain_ex_reports_ul =
		remain_ex_reports_ul;
	small_data_rate_status_local_var->is_remain_ex_reports_dl =
		is_remain_ex_reports_dl;
	small_data_rate_status_local_var->remain_ex_reports_dl =
		remain_ex_reports_dl;

	return small_data_rate_status_local_var;
}

void small_data_rate_status_free(
	small_data_rate_status_t *small_data_rate_status) {
	lnode_t *node = NULL;

	if(NULL == small_data_rate_status) {
		return;
	}
	if(small_data_rate_status->validity_time) {
		free(small_data_rate_status->validity_time);
		small_data_rate_status->validity_time = NULL;
	}
	free(small_data_rate_status);
}

cJSON *small_data_rate_status_convertToJSON(
	small_data_rate_status_t *small_data_rate_status) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(small_data_rate_status == NULL) {
		printf(
			"small_data_rate_status_convertToJSON() failed [SmallDataRateStatus]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(small_data_rate_status->is_remain_packets_ul) {
		if(cJSON_AddNumberToObject(item, "remainPacketsUl",
		                           small_data_rate_status->
		                           remain_packets_ul) == NULL)
		{
			printf(
				"small_data_rate_status_convertToJSON() failed [remain_packets_ul]");
			goto end;
		}
	}

	if(small_data_rate_status->is_remain_packets_dl) {
		if(cJSON_AddNumberToObject(item, "remainPacketsDl",
		                           small_data_rate_status->
		                           remain_packets_dl) == NULL)
		{
			printf(
				"small_data_rate_status_convertToJSON() failed [remain_packets_dl]");
			goto end;
		}
	}

	if(small_data_rate_status->validity_time) {
		if(cJSON_AddStringToObject(item, "validityTime",
		                           small_data_rate_status->validity_time)
		   == NULL)
		{
			printf(
				"small_data_rate_status_convertToJSON() failed [validity_time]");
			goto end;
		}
	}

	if(small_data_rate_status->is_remain_ex_reports_ul) {
		if(cJSON_AddNumberToObject(item, "remainExReportsUl",
		                           small_data_rate_status->
		                           remain_ex_reports_ul) == NULL)
		{
			printf(
				"small_data_rate_status_convertToJSON() failed [remain_ex_reports_ul]");
			goto end;
		}
	}

	if(small_data_rate_status->is_remain_ex_reports_dl) {
		if(cJSON_AddNumberToObject(item, "remainExReportsDl",
		                           small_data_rate_status->
		                           remain_ex_reports_dl) == NULL)
		{
			printf(
				"small_data_rate_status_convertToJSON() failed [remain_ex_reports_dl]");
			goto end;
		}
	}

end:
	return item;
}

small_data_rate_status_t *small_data_rate_status_parseFromJSON(
	cJSON *small_data_rate_statusJSON) {
	small_data_rate_status_t *small_data_rate_status_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *remain_packets_ul = NULL;
	cJSON *remain_packets_dl = NULL;
	cJSON *validity_time = NULL;
	cJSON *remain_ex_reports_ul = NULL;
	cJSON *remain_ex_reports_dl = NULL;
	remain_packets_ul = cJSON_GetObjectItemCaseSensitive(
		small_data_rate_statusJSON, "remainPacketsUl");
	if(remain_packets_ul) {
		if(!cJSON_IsNumber(remain_packets_ul)) {
			printf(
				"small_data_rate_status_parseFromJSON() failed [remain_packets_ul]");
			goto end;
		}
	}

	remain_packets_dl = cJSON_GetObjectItemCaseSensitive(
		small_data_rate_statusJSON, "remainPacketsDl");
	if(remain_packets_dl) {
		if(!cJSON_IsNumber(remain_packets_dl)) {
			printf(
				"small_data_rate_status_parseFromJSON() failed [remain_packets_dl]");
			goto end;
		}
	}

	validity_time = cJSON_GetObjectItemCaseSensitive(
		small_data_rate_statusJSON, "validityTime");
	if(validity_time) {
		if(!cJSON_IsString(validity_time) &&
		   !cJSON_IsNull(validity_time))
		{
			printf(
				"small_data_rate_status_parseFromJSON() failed [validity_time]");
			goto end;
		}
	}

	remain_ex_reports_ul = cJSON_GetObjectItemCaseSensitive(
		small_data_rate_statusJSON, "remainExReportsUl");
	if(remain_ex_reports_ul) {
		if(!cJSON_IsNumber(remain_ex_reports_ul)) {
			printf(
				"small_data_rate_status_parseFromJSON() failed [remain_ex_reports_ul]");
			goto end;
		}
	}

	remain_ex_reports_dl = cJSON_GetObjectItemCaseSensitive(
		small_data_rate_statusJSON, "remainExReportsDl");
	if(remain_ex_reports_dl) {
		if(!cJSON_IsNumber(remain_ex_reports_dl)) {
			printf(
				"small_data_rate_status_parseFromJSON() failed [remain_ex_reports_dl]");
			goto end;
		}
	}

	small_data_rate_status_local_var = small_data_rate_status_create(
		remain_packets_ul ? true : false,
		remain_packets_ul ? remain_packets_ul->valuedouble : 0,
		remain_packets_dl ? true : false,
		remain_packets_dl ? remain_packets_dl->valuedouble : 0,
		validity_time &&
		!cJSON_IsNull(validity_time) ? strdup(
			validity_time->valuestring) : NULL,
		remain_ex_reports_ul ? true : false,
		remain_ex_reports_ul ? remain_ex_reports_ul->valuedouble : 0,
		remain_ex_reports_dl ? true : false,
		remain_ex_reports_dl ? remain_ex_reports_dl->valuedouble : 0
		);

	return small_data_rate_status_local_var;
end:
	return NULL;
}

small_data_rate_status_t *small_data_rate_status_copy(
	small_data_rate_status_t *dst, small_data_rate_status_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = small_data_rate_status_convertToJSON(src);
	if(!item) {
		printf("small_data_rate_status_convertToJSON() failed");
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

	small_data_rate_status_free(dst);
	dst = small_data_rate_status_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
