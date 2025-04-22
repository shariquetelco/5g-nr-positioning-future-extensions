#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_context_cancel_relocate_data.h"

ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_create(
	char *supi, ref_to_binary_data_t *relocation_cancel_request) {
	ue_context_cancel_relocate_data_t *
	        ue_context_cancel_relocate_data_local_var =
		malloc(sizeof(ue_context_cancel_relocate_data_t));

	ue_context_cancel_relocate_data_local_var->supi = supi;
	ue_context_cancel_relocate_data_local_var->relocation_cancel_request =
		relocation_cancel_request;

	return ue_context_cancel_relocate_data_local_var;
}

void ue_context_cancel_relocate_data_free(
	ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data) {
	lnode_t *node = NULL;

	if(NULL == ue_context_cancel_relocate_data) {
		return;
	}
	if(ue_context_cancel_relocate_data->supi) {
		free(ue_context_cancel_relocate_data->supi);
		ue_context_cancel_relocate_data->supi = NULL;
	}
	if(ue_context_cancel_relocate_data->relocation_cancel_request) {
		ref_to_binary_data_free(
			ue_context_cancel_relocate_data->relocation_cancel_request);
		ue_context_cancel_relocate_data->relocation_cancel_request =
			NULL;
	}
	free(ue_context_cancel_relocate_data);
}

cJSON *ue_context_cancel_relocate_data_convertToJSON(
	ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_context_cancel_relocate_data == NULL) {
		printf(
			"ue_context_cancel_relocate_data_convertToJSON() failed [UeContextCancelRelocateData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_context_cancel_relocate_data->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           ue_context_cancel_relocate_data->supi)
		   == NULL)
		{
			printf(
				"ue_context_cancel_relocate_data_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(!ue_context_cancel_relocate_data->relocation_cancel_request) {
		printf(
			"ue_context_cancel_relocate_data_convertToJSON() failed [relocation_cancel_request]");
		return NULL;
	}
	cJSON *relocation_cancel_request_local_JSON =
		ref_to_binary_data_convertToJSON(
			ue_context_cancel_relocate_data->relocation_cancel_request);
	if(relocation_cancel_request_local_JSON == NULL) {
		printf(
			"ue_context_cancel_relocate_data_convertToJSON() failed [relocation_cancel_request]");
		goto end;
	}
	cJSON_AddItemToObject(item, "relocationCancelRequest",
	                      relocation_cancel_request_local_JSON);
	if(item->child == NULL) {
		printf(
			"ue_context_cancel_relocate_data_convertToJSON() failed [relocation_cancel_request]");
		goto end;
	}

end:
	return item;
}

ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_parseFromJSON(
	cJSON *ue_context_cancel_relocate_dataJSON) {
	ue_context_cancel_relocate_data_t *
	        ue_context_cancel_relocate_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supi = NULL;
	cJSON *relocation_cancel_request = NULL;
	ref_to_binary_data_t *relocation_cancel_request_local_nonprim = NULL;
	supi = cJSON_GetObjectItemCaseSensitive(
		ue_context_cancel_relocate_dataJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf(
				"ue_context_cancel_relocate_data_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	relocation_cancel_request = cJSON_GetObjectItemCaseSensitive(
		ue_context_cancel_relocate_dataJSON, "relocationCancelRequest");
	if(!relocation_cancel_request) {
		printf(
			"ue_context_cancel_relocate_data_parseFromJSON() failed [relocation_cancel_request]");
		goto end;
	}
	relocation_cancel_request_local_nonprim =
		ref_to_binary_data_parseFromJSON(relocation_cancel_request);
	if(!relocation_cancel_request_local_nonprim) {
		printf(
			"ref_to_binary_data_parseFromJSON failed [relocation_cancel_request]");
		goto end;
	}

	ue_context_cancel_relocate_data_local_var =
		ue_context_cancel_relocate_data_create(
			supi &&
			!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
			relocation_cancel_request_local_nonprim
			);

	return ue_context_cancel_relocate_data_local_var;
end:
	if(relocation_cancel_request_local_nonprim) {
		ref_to_binary_data_free(relocation_cancel_request_local_nonprim);
		relocation_cancel_request_local_nonprim = NULL;
	}
	return NULL;
}

ue_context_cancel_relocate_data_t *ue_context_cancel_relocate_data_copy(
	ue_context_cancel_relocate_data_t	*dst,
	ue_context_cancel_relocate_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_context_cancel_relocate_data_convertToJSON(src);
	if(!item) {
		printf("ue_context_cancel_relocate_data_convertToJSON() failed");
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

	ue_context_cancel_relocate_data_free(dst);
	dst = ue_context_cancel_relocate_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
