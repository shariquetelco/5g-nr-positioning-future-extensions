#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_context_relocated_data.h"

ue_context_relocated_data_t *ue_context_relocated_data_create(
	ue_context_t *ue_context) {
	ue_context_relocated_data_t *ue_context_relocated_data_local_var =
		malloc(sizeof(ue_context_relocated_data_t));

	ue_context_relocated_data_local_var->ue_context = ue_context;

	return ue_context_relocated_data_local_var;
}

void ue_context_relocated_data_free(
	ue_context_relocated_data_t *ue_context_relocated_data) {
	lnode_t *node = NULL;

	if(NULL == ue_context_relocated_data) {
		return;
	}
	if(ue_context_relocated_data->ue_context) {
		ue_context_free(ue_context_relocated_data->ue_context);
		ue_context_relocated_data->ue_context = NULL;
	}
	free(ue_context_relocated_data);
}

cJSON *ue_context_relocated_data_convertToJSON(
	ue_context_relocated_data_t *ue_context_relocated_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_context_relocated_data == NULL) {
		printf(
			"ue_context_relocated_data_convertToJSON() failed [UeContextRelocatedData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ue_context_relocated_data->ue_context) {
		printf(
			"ue_context_relocated_data_convertToJSON() failed [ue_context]");
		return NULL;
	}
	cJSON *ue_context_local_JSON = ue_context_convertToJSON(
		ue_context_relocated_data->ue_context);
	if(ue_context_local_JSON == NULL) {
		printf(
			"ue_context_relocated_data_convertToJSON() failed [ue_context]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ueContext", ue_context_local_JSON);
	if(item->child == NULL) {
		printf(
			"ue_context_relocated_data_convertToJSON() failed [ue_context]");
		goto end;
	}

end:
	return item;
}

ue_context_relocated_data_t *ue_context_relocated_data_parseFromJSON(
	cJSON *ue_context_relocated_dataJSON) {
	ue_context_relocated_data_t *ue_context_relocated_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ue_context = NULL;
	ue_context_t *ue_context_local_nonprim = NULL;
	ue_context = cJSON_GetObjectItemCaseSensitive(
		ue_context_relocated_dataJSON, "ueContext");
	if(!ue_context) {
		printf(
			"ue_context_relocated_data_parseFromJSON() failed [ue_context]");
		goto end;
	}
	ue_context_local_nonprim = ue_context_parseFromJSON(ue_context);
	if(!ue_context_local_nonprim) {
		printf("ue_context_parseFromJSON failed [ue_context]");
		goto end;
	}

	ue_context_relocated_data_local_var = ue_context_relocated_data_create(
		ue_context_local_nonprim
		);

	return ue_context_relocated_data_local_var;
end:
	if(ue_context_local_nonprim) {
		ue_context_free(ue_context_local_nonprim);
		ue_context_local_nonprim = NULL;
	}
	return NULL;
}

ue_context_relocated_data_t *ue_context_relocated_data_copy(
	ue_context_relocated_data_t *dst, ue_context_relocated_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_context_relocated_data_convertToJSON(src);
	if(!item) {
		printf("ue_context_relocated_data_convertToJSON() failed");
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

	ue_context_relocated_data_free(dst);
	dst = ue_context_relocated_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
