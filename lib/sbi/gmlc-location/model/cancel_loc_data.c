#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_loc_data.h"

cancel_loc_data_t *cancel_loc_data_create(char *gpsi, char *supi,
                                          char *ext_group_id,
                                          char *int_group_id,
                                          char *hgmlc_call_back_uri,
                                          char *ldr_reference,
                                          char *lmf_identification,
                                          char *amf_id) {
	cancel_loc_data_t *cancel_loc_data_local_var =
		malloc(sizeof(cancel_loc_data_t));

	cancel_loc_data_local_var->gpsi = gpsi;
	cancel_loc_data_local_var->supi = supi;
	cancel_loc_data_local_var->ext_group_id = ext_group_id;
	cancel_loc_data_local_var->int_group_id = int_group_id;
	cancel_loc_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
	cancel_loc_data_local_var->ldr_reference = ldr_reference;
	cancel_loc_data_local_var->lmf_identification = lmf_identification;
	cancel_loc_data_local_var->amf_id = amf_id;

	return cancel_loc_data_local_var;
}

void cancel_loc_data_free(cancel_loc_data_t *cancel_loc_data) {
	lnode_t *node = NULL;

	if(NULL == cancel_loc_data) {
		return;
	}
	if(cancel_loc_data->gpsi) {
		free(cancel_loc_data->gpsi);
		cancel_loc_data->gpsi = NULL;
	}
	if(cancel_loc_data->supi) {
		free(cancel_loc_data->supi);
		cancel_loc_data->supi = NULL;
	}
	if(cancel_loc_data->ext_group_id) {
		free(cancel_loc_data->ext_group_id);
		cancel_loc_data->ext_group_id = NULL;
	}
	if(cancel_loc_data->int_group_id) {
		free(cancel_loc_data->int_group_id);
		cancel_loc_data->int_group_id = NULL;
	}
	if(cancel_loc_data->hgmlc_call_back_uri) {
		free(cancel_loc_data->hgmlc_call_back_uri);
		cancel_loc_data->hgmlc_call_back_uri = NULL;
	}
	if(cancel_loc_data->ldr_reference) {
		free(cancel_loc_data->ldr_reference);
		cancel_loc_data->ldr_reference = NULL;
	}
	if(cancel_loc_data->lmf_identification) {
		free(cancel_loc_data->lmf_identification);
		cancel_loc_data->lmf_identification = NULL;
	}
	if(cancel_loc_data->amf_id) {
		free(cancel_loc_data->amf_id);
		cancel_loc_data->amf_id = NULL;
	}
	free(cancel_loc_data);
}

cJSON *cancel_loc_data_convertToJSON(cancel_loc_data_t *cancel_loc_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cancel_loc_data == NULL) {
		printf("cancel_loc_data_convertToJSON() failed [CancelLocData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cancel_loc_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           cancel_loc_data->gpsi) == NULL)
		{
			printf("cancel_loc_data_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(cancel_loc_data->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           cancel_loc_data->supi) == NULL)
		{
			printf("cancel_loc_data_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(cancel_loc_data->ext_group_id) {
		if(cJSON_AddStringToObject(item, "extGroupId",
		                           cancel_loc_data->ext_group_id) ==
		   NULL)
		{
			printf(
				"cancel_loc_data_convertToJSON() failed [ext_group_id]");
			goto end;
		}
	}

	if(cancel_loc_data->int_group_id) {
		if(cJSON_AddStringToObject(item, "intGroupId",
		                           cancel_loc_data->int_group_id) ==
		   NULL)
		{
			printf(
				"cancel_loc_data_convertToJSON() failed [int_group_id]");
			goto end;
		}
	}

	if(!cancel_loc_data->hgmlc_call_back_uri) {
		printf(
			"cancel_loc_data_convertToJSON() failed [hgmlc_call_back_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "hgmlcCallBackUri",
	                           cancel_loc_data->hgmlc_call_back_uri) ==
	   NULL)
	{
		printf(
			"cancel_loc_data_convertToJSON() failed [hgmlc_call_back_uri]");
		goto end;
	}

	if(!cancel_loc_data->ldr_reference) {
		printf("cancel_loc_data_convertToJSON() failed [ldr_reference]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ldrReference",
	                           cancel_loc_data->ldr_reference) == NULL)
	{
		printf("cancel_loc_data_convertToJSON() failed [ldr_reference]");
		goto end;
	}

	if(cancel_loc_data->lmf_identification) {
		if(cJSON_AddStringToObject(item, "lmfIdentification",
		                           cancel_loc_data->lmf_identification)
		   == NULL)
		{
			printf(
				"cancel_loc_data_convertToJSON() failed [lmf_identification]");
			goto end;
		}
	}

	if(cancel_loc_data->amf_id) {
		if(cJSON_AddStringToObject(item, "amfId",
		                           cancel_loc_data->amf_id) == NULL)
		{
			printf("cancel_loc_data_convertToJSON() failed [amf_id]");
			goto end;
		}
	}

end:
	return item;
}

cancel_loc_data_t *cancel_loc_data_parseFromJSON(cJSON *cancel_loc_dataJSON) {
	cancel_loc_data_t *cancel_loc_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	cJSON *ext_group_id = NULL;
	cJSON *int_group_id = NULL;
	cJSON *hgmlc_call_back_uri = NULL;
	cJSON *ldr_reference = NULL;
	cJSON *lmf_identification = NULL;
	cJSON *amf_id = NULL;
	gpsi = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("cancel_loc_data_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("cancel_loc_data_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	ext_group_id = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON,
	                                                "extGroupId");
	if(ext_group_id) {
		if(!cJSON_IsString(ext_group_id) &&
		   !cJSON_IsNull(ext_group_id))
		{
			printf(
				"cancel_loc_data_parseFromJSON() failed [ext_group_id]");
			goto end;
		}
	}

	int_group_id = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON,
	                                                "intGroupId");
	if(int_group_id) {
		if(!cJSON_IsString(int_group_id) &&
		   !cJSON_IsNull(int_group_id))
		{
			printf(
				"cancel_loc_data_parseFromJSON() failed [int_group_id]");
			goto end;
		}
	}

	hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		cancel_loc_dataJSON, "hgmlcCallBackUri");
	if(!hgmlc_call_back_uri) {
		printf(
			"cancel_loc_data_parseFromJSON() failed [hgmlc_call_back_uri]");
		goto end;
	}
	if(!cJSON_IsString(hgmlc_call_back_uri)) {
		printf(
			"cancel_loc_data_parseFromJSON() failed [hgmlc_call_back_uri]");
		goto end;
	}

	ldr_reference = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON,
	                                                 "ldrReference");
	if(!ldr_reference) {
		printf("cancel_loc_data_parseFromJSON() failed [ldr_reference]");
		goto end;
	}
	if(!cJSON_IsString(ldr_reference)) {
		printf("cancel_loc_data_parseFromJSON() failed [ldr_reference]");
		goto end;
	}

	lmf_identification = cJSON_GetObjectItemCaseSensitive(
		cancel_loc_dataJSON, "lmfIdentification");
	if(lmf_identification) {
		if(!cJSON_IsString(lmf_identification) &&
		   !cJSON_IsNull(lmf_identification))
		{
			printf(
				"cancel_loc_data_parseFromJSON() failed [lmf_identification]");
			goto end;
		}
	}

	amf_id = cJSON_GetObjectItemCaseSensitive(cancel_loc_dataJSON, "amfId");
	if(amf_id) {
		if(!cJSON_IsString(amf_id) &&
		   !cJSON_IsNull(amf_id))
		{
			printf("cancel_loc_data_parseFromJSON() failed [amf_id]");
			goto end;
		}
	}

	cancel_loc_data_local_var = cancel_loc_data_create(
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		ext_group_id &&
		!cJSON_IsNull(ext_group_id) ? strdup(
			ext_group_id->valuestring) : NULL,
		int_group_id &&
		!cJSON_IsNull(int_group_id) ? strdup(
			int_group_id->valuestring) : NULL,
		strdup(hgmlc_call_back_uri->valuestring),
		strdup(ldr_reference->valuestring),
		lmf_identification &&
		!cJSON_IsNull(lmf_identification) ? strdup(lmf_identification->
		                                           valuestring) : NULL,
		amf_id &&
		!cJSON_IsNull(amf_id) ? strdup(amf_id->valuestring) : NULL
		);

	return cancel_loc_data_local_var;
end:
	return NULL;
}

cancel_loc_data_t *cancel_loc_data_copy(cancel_loc_data_t	*dst,
                                        cancel_loc_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cancel_loc_data_convertToJSON(src);
	if(!item) {
		printf("cancel_loc_data_convertToJSON() failed");
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

	cancel_loc_data_free(dst);
	dst = cancel_loc_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
