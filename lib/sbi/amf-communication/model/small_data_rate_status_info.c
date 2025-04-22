#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "small_data_rate_status_info.h"

small_data_rate_status_info_t *small_data_rate_status_info_create(
	snssai_t *snssai, char *dnn,
	small_data_rate_status_t *small_data_rate_status) {
	small_data_rate_status_info_t *small_data_rate_status_info_local_var =
		malloc(sizeof(small_data_rate_status_info_t));

	small_data_rate_status_info_local_var->snssai = snssai;
	small_data_rate_status_info_local_var->dnn = dnn;
	small_data_rate_status_info_local_var->small_data_rate_status =
		small_data_rate_status;

	return small_data_rate_status_info_local_var;
}

void small_data_rate_status_info_free(
	small_data_rate_status_info_t *small_data_rate_status_info) {
	lnode_t *node = NULL;

	if(NULL == small_data_rate_status_info) {
		return;
	}
	if(small_data_rate_status_info->snssai) {
		snssai_free(small_data_rate_status_info->snssai);
		small_data_rate_status_info->snssai = NULL;
	}
	if(small_data_rate_status_info->dnn) {
		free(small_data_rate_status_info->dnn);
		small_data_rate_status_info->dnn = NULL;
	}
	if(small_data_rate_status_info->small_data_rate_status) {
		small_data_rate_status_free(
			small_data_rate_status_info->small_data_rate_status);
		small_data_rate_status_info->small_data_rate_status = NULL;
	}
	free(small_data_rate_status_info);
}

cJSON *small_data_rate_status_info_convertToJSON(
	small_data_rate_status_info_t *small_data_rate_status_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(small_data_rate_status_info == NULL) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [SmallDataRateStatusInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!small_data_rate_status_info->snssai) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [snssai]");
		return NULL;
	}
	cJSON *snssai_local_JSON = snssai_convertToJSON(
		small_data_rate_status_info->snssai);
	if(snssai_local_JSON == NULL) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "Snssai", snssai_local_JSON);
	if(item->child == NULL) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [snssai]");
		goto end;
	}

	if(!small_data_rate_status_info->dnn) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [dnn]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "Dnn",
	                           small_data_rate_status_info->dnn) == NULL)
	{
		printf(
			"small_data_rate_status_info_convertToJSON() failed [dnn]");
		goto end;
	}

	if(!small_data_rate_status_info->small_data_rate_status) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [small_data_rate_status]");
		return NULL;
	}
	cJSON *small_data_rate_status_local_JSON =
		small_data_rate_status_convertToJSON(
			small_data_rate_status_info->small_data_rate_status);
	if(small_data_rate_status_local_JSON == NULL) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [small_data_rate_status]");
		goto end;
	}
	cJSON_AddItemToObject(item, "SmallDataRateStatus",
	                      small_data_rate_status_local_JSON);
	if(item->child == NULL) {
		printf(
			"small_data_rate_status_info_convertToJSON() failed [small_data_rate_status]");
		goto end;
	}

end:
	return item;
}

small_data_rate_status_info_t *small_data_rate_status_info_parseFromJSON(
	cJSON *small_data_rate_status_infoJSON) {
	small_data_rate_status_info_t *small_data_rate_status_info_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *dnn = NULL;
	cJSON *small_data_rate_status = NULL;
	small_data_rate_status_t *small_data_rate_status_local_nonprim = NULL;
	snssai = cJSON_GetObjectItemCaseSensitive(
		small_data_rate_status_infoJSON, "Snssai");
	if(!snssai) {
		printf(
			"small_data_rate_status_info_parseFromJSON() failed [snssai]");
		goto end;
	}
	snssai_local_nonprim = snssai_parseFromJSON(snssai);
	if(!snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [snssai]");
		goto end;
	}

	dnn = cJSON_GetObjectItemCaseSensitive(small_data_rate_status_infoJSON,
	                                       "Dnn");
	if(!dnn) {
		printf(
			"small_data_rate_status_info_parseFromJSON() failed [dnn]");
		goto end;
	}
	if(!cJSON_IsString(dnn)) {
		printf(
			"small_data_rate_status_info_parseFromJSON() failed [dnn]");
		goto end;
	}

	small_data_rate_status = cJSON_GetObjectItemCaseSensitive(
		small_data_rate_status_infoJSON, "SmallDataRateStatus");
	if(!small_data_rate_status) {
		printf(
			"small_data_rate_status_info_parseFromJSON() failed [small_data_rate_status]");
		goto end;
	}
	small_data_rate_status_local_nonprim =
		small_data_rate_status_parseFromJSON(small_data_rate_status);
	if(!small_data_rate_status_local_nonprim) {
		printf(
			"small_data_rate_status_parseFromJSON failed [small_data_rate_status]");
		goto end;
	}

	small_data_rate_status_info_local_var =
		small_data_rate_status_info_create(
			snssai_local_nonprim,
			strdup(dnn->valuestring),
			small_data_rate_status_local_nonprim
			);

	return small_data_rate_status_info_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(small_data_rate_status_local_nonprim) {
		small_data_rate_status_free(small_data_rate_status_local_nonprim);
		small_data_rate_status_local_nonprim = NULL;
	}
	return NULL;
}

small_data_rate_status_info_t *small_data_rate_status_info_copy(
	small_data_rate_status_info_t	*dst,
	small_data_rate_status_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = small_data_rate_status_info_convertToJSON(src);
	if(!item) {
		printf("small_data_rate_status_info_convertToJSON() failed");
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

	small_data_rate_status_info_free(dst);
	dst = small_data_rate_status_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
