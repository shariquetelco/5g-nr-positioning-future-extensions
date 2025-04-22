#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_reg_status_update_rsp_data.h"

ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_create(
	int reg_status_transfer_complete) {
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_local_var
	        = malloc(sizeof(ue_reg_status_update_rsp_data_t));

	ue_reg_status_update_rsp_data_local_var->reg_status_transfer_complete =
		reg_status_transfer_complete;

	return ue_reg_status_update_rsp_data_local_var;
}

void ue_reg_status_update_rsp_data_free(
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data) {
	lnode_t *node = NULL;

	if(NULL == ue_reg_status_update_rsp_data) {
		return;
	}
	free(ue_reg_status_update_rsp_data);
}

cJSON *ue_reg_status_update_rsp_data_convertToJSON(
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_reg_status_update_rsp_data == NULL) {
		printf(
			"ue_reg_status_update_rsp_data_convertToJSON() failed [UeRegStatusUpdateRspData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddBoolToObject(item, "regStatusTransferComplete",
	                         ue_reg_status_update_rsp_data->
	                         reg_status_transfer_complete) == NULL)
	{
		printf(
			"ue_reg_status_update_rsp_data_convertToJSON() failed [reg_status_transfer_complete]");
		goto end;
	}

end:
	return item;
}

ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_parseFromJSON(
	cJSON *ue_reg_status_update_rsp_dataJSON) {
	ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_local_var
	        = NULL;
	lnode_t *node = NULL;
	cJSON *reg_status_transfer_complete = NULL;
	reg_status_transfer_complete = cJSON_GetObjectItemCaseSensitive(
		ue_reg_status_update_rsp_dataJSON, "regStatusTransferComplete");
	if(!reg_status_transfer_complete) {
		printf(
			"ue_reg_status_update_rsp_data_parseFromJSON() failed [reg_status_transfer_complete]");
		goto end;
	}
	if(!cJSON_IsBool(reg_status_transfer_complete)) {
		printf(
			"ue_reg_status_update_rsp_data_parseFromJSON() failed [reg_status_transfer_complete]");
		goto end;
	}

	ue_reg_status_update_rsp_data_local_var =
		ue_reg_status_update_rsp_data_create(

			reg_status_transfer_complete->valueint
			);

	return ue_reg_status_update_rsp_data_local_var;
end:
	return NULL;
}

ue_reg_status_update_rsp_data_t *ue_reg_status_update_rsp_data_copy(
	ue_reg_status_update_rsp_data_t *dst,
	ue_reg_status_update_rsp_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_reg_status_update_rsp_data_convertToJSON(src);
	if(!item) {
		printf("ue_reg_status_update_rsp_data_convertToJSON() failed");
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

	ue_reg_status_update_rsp_data_free(dst);
	dst = ue_reg_status_update_rsp_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
