#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pcf_ue_callback_info.h"

pcf_ue_callback_info_t *pcf_ue_callback_info_create(char	*callback_uri,
                                                    char	*binding_info) {
	pcf_ue_callback_info_t *pcf_ue_callback_info_local_var =
		malloc(sizeof(pcf_ue_callback_info_t));

	pcf_ue_callback_info_local_var->callback_uri = callback_uri;
	pcf_ue_callback_info_local_var->binding_info = binding_info;

	return pcf_ue_callback_info_local_var;
}

void pcf_ue_callback_info_free(pcf_ue_callback_info_t *pcf_ue_callback_info) {
	lnode_t *node = NULL;

	if(NULL == pcf_ue_callback_info) {
		return;
	}
	if(pcf_ue_callback_info->callback_uri) {
		free(pcf_ue_callback_info->callback_uri);
		pcf_ue_callback_info->callback_uri = NULL;
	}
	if(pcf_ue_callback_info->binding_info) {
		free(pcf_ue_callback_info->binding_info);
		pcf_ue_callback_info->binding_info = NULL;
	}
	free(pcf_ue_callback_info);
}

cJSON *pcf_ue_callback_info_convertToJSON(
	pcf_ue_callback_info_t *pcf_ue_callback_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pcf_ue_callback_info == NULL) {
		printf(
			"pcf_ue_callback_info_convertToJSON() failed [PcfUeCallbackInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!pcf_ue_callback_info->callback_uri) {
		printf(
			"pcf_ue_callback_info_convertToJSON() failed [callback_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "callbackUri",
	                           pcf_ue_callback_info->callback_uri) == NULL)
	{
		printf(
			"pcf_ue_callback_info_convertToJSON() failed [callback_uri]");
		goto end;
	}

	if(pcf_ue_callback_info->binding_info) {
		if(cJSON_AddStringToObject(item, "bindingInfo",
		                           pcf_ue_callback_info->binding_info)
		   == NULL)
		{
			printf(
				"pcf_ue_callback_info_convertToJSON() failed [binding_info]");
			goto end;
		}
	}

end:
	return item;
}

pcf_ue_callback_info_t *pcf_ue_callback_info_parseFromJSON(
	cJSON *pcf_ue_callback_infoJSON) {
	pcf_ue_callback_info_t *pcf_ue_callback_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *callback_uri = NULL;
	cJSON *binding_info = NULL;
	callback_uri = cJSON_GetObjectItemCaseSensitive(
		pcf_ue_callback_infoJSON, "callbackUri");
	if(!callback_uri) {
		printf(
			"pcf_ue_callback_info_parseFromJSON() failed [callback_uri]");
		goto end;
	}
	if(!cJSON_IsString(callback_uri)) {
		printf(
			"pcf_ue_callback_info_parseFromJSON() failed [callback_uri]");
		goto end;
	}

	binding_info = cJSON_GetObjectItemCaseSensitive(
		pcf_ue_callback_infoJSON, "bindingInfo");
	if(binding_info) {
		if(!cJSON_IsString(binding_info) &&
		   !cJSON_IsNull(binding_info))
		{
			printf(
				"pcf_ue_callback_info_parseFromJSON() failed [binding_info]");
			goto end;
		}
	}

	pcf_ue_callback_info_local_var = pcf_ue_callback_info_create(
		strdup(callback_uri->valuestring),
		binding_info &&
		!cJSON_IsNull(binding_info) ? strdup(
			binding_info->valuestring) : NULL
		);

	return pcf_ue_callback_info_local_var;
end:
	return NULL;
}

pcf_ue_callback_info_t *pcf_ue_callback_info_copy(
	pcf_ue_callback_info_t	*dst,
	pcf_ue_callback_info_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = pcf_ue_callback_info_convertToJSON(src);
	if(!item) {
		printf("pcf_ue_callback_info_convertToJSON() failed");
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

	pcf_ue_callback_info_free(dst);
	dst = pcf_ue_callback_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
