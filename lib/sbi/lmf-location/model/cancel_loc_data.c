#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cancel_loc_data.h"

cancel_loc_data_t *cancel_loc_data_create(char	*hgmlc_call_back_uri,
                                          char	*ldr_reference,
                                          char	*supported_features) {
	cancel_loc_data_t *cancel_loc_data_local_var =
		malloc(sizeof(cancel_loc_data_t));

	cancel_loc_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
	cancel_loc_data_local_var->ldr_reference = ldr_reference;
	cancel_loc_data_local_var->supported_features = supported_features;

	return cancel_loc_data_local_var;
}

void cancel_loc_data_free(cancel_loc_data_t *cancel_loc_data) {
	lnode_t *node = NULL;

	if(NULL == cancel_loc_data) {
		return;
	}
	if(cancel_loc_data->hgmlc_call_back_uri) {
		free(cancel_loc_data->hgmlc_call_back_uri);
		cancel_loc_data->hgmlc_call_back_uri = NULL;
	}
	if(cancel_loc_data->ldr_reference) {
		free(cancel_loc_data->ldr_reference);
		cancel_loc_data->ldr_reference = NULL;
	}
	if(cancel_loc_data->supported_features) {
		free(cancel_loc_data->supported_features);
		cancel_loc_data->supported_features = NULL;
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
	if(!cancel_loc_data->hgmlc_call_back_uri) {
		printf(
			"cancel_loc_data_convertToJSON() failed [hgmlc_call_back_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "hgmlcCallBackURI",
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

	if(cancel_loc_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           cancel_loc_data->supported_features)
		   == NULL)
		{
			printf(
				"cancel_loc_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

end:
	return item;
}

cancel_loc_data_t *cancel_loc_data_parseFromJSON(cJSON *cancel_loc_dataJSON) {
	cancel_loc_data_t *cancel_loc_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *hgmlc_call_back_uri = NULL;
	cJSON *ldr_reference = NULL;
	cJSON *supported_features = NULL;
	hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		cancel_loc_dataJSON, "hgmlcCallBackURI");
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

	supported_features = cJSON_GetObjectItemCaseSensitive(
		cancel_loc_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"cancel_loc_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	cancel_loc_data_local_var = cancel_loc_data_create(
		strdup(hgmlc_call_back_uri->valuestring),
		strdup(ldr_reference->valuestring),
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL
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
