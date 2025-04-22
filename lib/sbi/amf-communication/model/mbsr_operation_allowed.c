#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mbsr_operation_allowed.h"

mbsr_operation_allowed_t *mbsr_operation_allowed_create(
	bool is_mbsr_operation_allowed_ind, int mbsr_operation_allowed_ind,
	mbsr_location_info_t *mbsr_location_info,
	mbsr_time_info_t *mbsr_time_info) {
	mbsr_operation_allowed_t *mbsr_operation_allowed_local_var = malloc(
		sizeof(mbsr_operation_allowed_t));

	mbsr_operation_allowed_local_var->is_mbsr_operation_allowed_ind =
		is_mbsr_operation_allowed_ind;
	mbsr_operation_allowed_local_var->mbsr_operation_allowed_ind =
		mbsr_operation_allowed_ind;
	mbsr_operation_allowed_local_var->mbsr_location_info =
		mbsr_location_info;
	mbsr_operation_allowed_local_var->mbsr_time_info = mbsr_time_info;

	return mbsr_operation_allowed_local_var;
}

void mbsr_operation_allowed_free(
	mbsr_operation_allowed_t *mbsr_operation_allowed) {
	lnode_t *node = NULL;

	if(NULL == mbsr_operation_allowed) {
		return;
	}
	if(mbsr_operation_allowed->mbsr_location_info) {
		mbsr_location_info_free(
			mbsr_operation_allowed->mbsr_location_info);
		mbsr_operation_allowed->mbsr_location_info = NULL;
	}
	if(mbsr_operation_allowed->mbsr_time_info) {
		mbsr_time_info_free(mbsr_operation_allowed->mbsr_time_info);
		mbsr_operation_allowed->mbsr_time_info = NULL;
	}
	free(mbsr_operation_allowed);
}

cJSON *mbsr_operation_allowed_convertToJSON(
	mbsr_operation_allowed_t *mbsr_operation_allowed) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mbsr_operation_allowed == NULL) {
		printf(
			"mbsr_operation_allowed_convertToJSON() failed [MbsrOperationAllowed]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(mbsr_operation_allowed->is_mbsr_operation_allowed_ind) {
		if(cJSON_AddBoolToObject(item, "mbsrOperationAllowedInd",
		                         mbsr_operation_allowed->
		                         mbsr_operation_allowed_ind) == NULL)
		{
			printf(
				"mbsr_operation_allowed_convertToJSON() failed [mbsr_operation_allowed_ind]");
			goto end;
		}
	}

	if(mbsr_operation_allowed->mbsr_location_info) {
		cJSON *mbsr_location_info_local_JSON =
			mbsr_location_info_convertToJSON(
				mbsr_operation_allowed->mbsr_location_info);
		if(mbsr_location_info_local_JSON == NULL) {
			printf(
				"mbsr_operation_allowed_convertToJSON() failed [mbsr_location_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mbsrLocationInfo",
		                      mbsr_location_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"mbsr_operation_allowed_convertToJSON() failed [mbsr_location_info]");
			goto end;
		}
	}

	if(mbsr_operation_allowed->mbsr_time_info) {
		cJSON *mbsr_time_info_local_JSON = mbsr_time_info_convertToJSON(
			mbsr_operation_allowed->mbsr_time_info);
		if(mbsr_time_info_local_JSON == NULL) {
			printf(
				"mbsr_operation_allowed_convertToJSON() failed [mbsr_time_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mbsrTimeInfo",
		                      mbsr_time_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"mbsr_operation_allowed_convertToJSON() failed [mbsr_time_info]");
			goto end;
		}
	}

end:
	return item;
}

mbsr_operation_allowed_t *mbsr_operation_allowed_parseFromJSON(
	cJSON *mbsr_operation_allowedJSON) {
	mbsr_operation_allowed_t *mbsr_operation_allowed_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *mbsr_operation_allowed_ind = NULL;
	cJSON *mbsr_location_info = NULL;
	mbsr_location_info_t *mbsr_location_info_local_nonprim = NULL;
	cJSON *mbsr_time_info = NULL;
	mbsr_time_info_t *mbsr_time_info_local_nonprim = NULL;
	mbsr_operation_allowed_ind = cJSON_GetObjectItemCaseSensitive(
		mbsr_operation_allowedJSON, "mbsrOperationAllowedInd");
	if(mbsr_operation_allowed_ind) {
		if(!cJSON_IsBool(mbsr_operation_allowed_ind)) {
			printf(
				"mbsr_operation_allowed_parseFromJSON() failed [mbsr_operation_allowed_ind]");
			goto end;
		}
	}

	mbsr_location_info = cJSON_GetObjectItemCaseSensitive(
		mbsr_operation_allowedJSON, "mbsrLocationInfo");
	if(mbsr_location_info) {
		mbsr_location_info_local_nonprim =
			mbsr_location_info_parseFromJSON(mbsr_location_info);
		if(!mbsr_location_info_local_nonprim) {
			printf(
				"mbsr_location_info_parseFromJSON failed [mbsr_location_info]");
			goto end;
		}
	}

	mbsr_time_info = cJSON_GetObjectItemCaseSensitive(
		mbsr_operation_allowedJSON, "mbsrTimeInfo");
	if(mbsr_time_info) {
		mbsr_time_info_local_nonprim = mbsr_time_info_parseFromJSON(
			mbsr_time_info);
		if(!mbsr_time_info_local_nonprim) {
			printf(
				"mbsr_time_info_parseFromJSON failed [mbsr_time_info]");
			goto end;
		}
	}

	mbsr_operation_allowed_local_var = mbsr_operation_allowed_create(
		mbsr_operation_allowed_ind ? true : false,
		mbsr_operation_allowed_ind ? mbsr_operation_allowed_ind->valueint : 0,
		mbsr_location_info ? mbsr_location_info_local_nonprim : NULL,
		mbsr_time_info ? mbsr_time_info_local_nonprim : NULL
		);

	return mbsr_operation_allowed_local_var;
end:
	if(mbsr_location_info_local_nonprim) {
		mbsr_location_info_free(mbsr_location_info_local_nonprim);
		mbsr_location_info_local_nonprim = NULL;
	}
	if(mbsr_time_info_local_nonprim) {
		mbsr_time_info_free(mbsr_time_info_local_nonprim);
		mbsr_time_info_local_nonprim = NULL;
	}
	return NULL;
}

mbsr_operation_allowed_t *mbsr_operation_allowed_copy(
	mbsr_operation_allowed_t *dst, mbsr_operation_allowed_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mbsr_operation_allowed_convertToJSON(src);
	if(!item) {
		printf("mbsr_operation_allowed_convertToJSON() failed");
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

	mbsr_operation_allowed_free(dst);
	dst = mbsr_operation_allowed_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
