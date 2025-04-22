#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_context_transfer_rsp_data.h"

ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_create(
	ue_context_t *ue_context, n2_info_content_t *ue_radio_capability,
	n2_info_content_t *ue_radio_capability_for_paging,
	n2_info_content_t *ue_nbiot_radio_capability,
	char *supported_features) {
	ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_local_var =
		malloc(sizeof(ue_context_transfer_rsp_data_t));

	ue_context_transfer_rsp_data_local_var->ue_context = ue_context;
	ue_context_transfer_rsp_data_local_var->ue_radio_capability =
		ue_radio_capability;
	ue_context_transfer_rsp_data_local_var->ue_radio_capability_for_paging =
		ue_radio_capability_for_paging;
	ue_context_transfer_rsp_data_local_var->ue_nbiot_radio_capability =
		ue_nbiot_radio_capability;
	ue_context_transfer_rsp_data_local_var->supported_features =
		supported_features;

	return ue_context_transfer_rsp_data_local_var;
}

void ue_context_transfer_rsp_data_free(
	ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data) {
	lnode_t *node = NULL;

	if(NULL == ue_context_transfer_rsp_data) {
		return;
	}
	if(ue_context_transfer_rsp_data->ue_context) {
		ue_context_free(ue_context_transfer_rsp_data->ue_context);
		ue_context_transfer_rsp_data->ue_context = NULL;
	}
	if(ue_context_transfer_rsp_data->ue_radio_capability) {
		n2_info_content_free(
			ue_context_transfer_rsp_data->ue_radio_capability);
		ue_context_transfer_rsp_data->ue_radio_capability = NULL;
	}
	if(ue_context_transfer_rsp_data->ue_radio_capability_for_paging) {
		n2_info_content_free(
			ue_context_transfer_rsp_data->ue_radio_capability_for_paging);
		ue_context_transfer_rsp_data->ue_radio_capability_for_paging =
			NULL;
	}
	if(ue_context_transfer_rsp_data->ue_nbiot_radio_capability) {
		n2_info_content_free(
			ue_context_transfer_rsp_data->ue_nbiot_radio_capability);
		ue_context_transfer_rsp_data->ue_nbiot_radio_capability = NULL;
	}
	if(ue_context_transfer_rsp_data->supported_features) {
		free(ue_context_transfer_rsp_data->supported_features);
		ue_context_transfer_rsp_data->supported_features = NULL;
	}
	free(ue_context_transfer_rsp_data);
}

cJSON *ue_context_transfer_rsp_data_convertToJSON(
	ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_context_transfer_rsp_data == NULL) {
		printf(
			"ue_context_transfer_rsp_data_convertToJSON() failed [UeContextTransferRspData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ue_context_transfer_rsp_data->ue_context) {
		printf(
			"ue_context_transfer_rsp_data_convertToJSON() failed [ue_context]");
		return NULL;
	}
	cJSON *ue_context_local_JSON = ue_context_convertToJSON(
		ue_context_transfer_rsp_data->ue_context);
	if(ue_context_local_JSON == NULL) {
		printf(
			"ue_context_transfer_rsp_data_convertToJSON() failed [ue_context]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ueContext", ue_context_local_JSON);
	if(item->child == NULL) {
		printf(
			"ue_context_transfer_rsp_data_convertToJSON() failed [ue_context]");
		goto end;
	}

	if(ue_context_transfer_rsp_data->ue_radio_capability) {
		cJSON *ue_radio_capability_local_JSON =
			n2_info_content_convertToJSON(
				ue_context_transfer_rsp_data->ue_radio_capability);
		if(ue_radio_capability_local_JSON == NULL) {
			printf(
				"ue_context_transfer_rsp_data_convertToJSON() failed [ue_radio_capability]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueRadioCapability",
		                      ue_radio_capability_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_transfer_rsp_data_convertToJSON() failed [ue_radio_capability]");
			goto end;
		}
	}

	if(ue_context_transfer_rsp_data->ue_radio_capability_for_paging) {
		cJSON *ue_radio_capability_for_paging_local_JSON =
			n2_info_content_convertToJSON(
				ue_context_transfer_rsp_data->ue_radio_capability_for_paging);
		if(ue_radio_capability_for_paging_local_JSON == NULL) {
			printf(
				"ue_context_transfer_rsp_data_convertToJSON() failed [ue_radio_capability_for_paging]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueRadioCapabilityForPaging",
		                      ue_radio_capability_for_paging_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_transfer_rsp_data_convertToJSON() failed [ue_radio_capability_for_paging]");
			goto end;
		}
	}

	if(ue_context_transfer_rsp_data->ue_nbiot_radio_capability) {
		cJSON *ue_nbiot_radio_capability_local_JSON =
			n2_info_content_convertToJSON(
				ue_context_transfer_rsp_data->ue_nbiot_radio_capability);
		if(ue_nbiot_radio_capability_local_JSON == NULL) {
			printf(
				"ue_context_transfer_rsp_data_convertToJSON() failed [ue_nbiot_radio_capability]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueNbiotRadioCapability",
		                      ue_nbiot_radio_capability_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_transfer_rsp_data_convertToJSON() failed [ue_nbiot_radio_capability]");
			goto end;
		}
	}

	if(ue_context_transfer_rsp_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           ue_context_transfer_rsp_data->
		                           supported_features) == NULL)
		{
			printf(
				"ue_context_transfer_rsp_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

end:
	return item;
}

ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_parseFromJSON(
	cJSON *ue_context_transfer_rsp_dataJSON) {
	ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *ue_context = NULL;
	ue_context_t *ue_context_local_nonprim = NULL;
	cJSON *ue_radio_capability = NULL;
	n2_info_content_t *ue_radio_capability_local_nonprim = NULL;
	cJSON *ue_radio_capability_for_paging = NULL;
	n2_info_content_t *ue_radio_capability_for_paging_local_nonprim = NULL;
	cJSON *ue_nbiot_radio_capability = NULL;
	n2_info_content_t *ue_nbiot_radio_capability_local_nonprim = NULL;
	cJSON *supported_features = NULL;
	ue_context = cJSON_GetObjectItemCaseSensitive(
		ue_context_transfer_rsp_dataJSON, "ueContext");
	if(!ue_context) {
		printf(
			"ue_context_transfer_rsp_data_parseFromJSON() failed [ue_context]");
		goto end;
	}
	ue_context_local_nonprim = ue_context_parseFromJSON(ue_context);
	if(!ue_context_local_nonprim) {
		printf("ue_context_parseFromJSON failed [ue_context]");
		goto end;
	}

	ue_radio_capability = cJSON_GetObjectItemCaseSensitive(
		ue_context_transfer_rsp_dataJSON, "ueRadioCapability");
	if(ue_radio_capability) {
		ue_radio_capability_local_nonprim =
			n2_info_content_parseFromJSON(ue_radio_capability);
		if(!ue_radio_capability_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [ue_radio_capability]");
			goto end;
		}
	}

	ue_radio_capability_for_paging = cJSON_GetObjectItemCaseSensitive(
		ue_context_transfer_rsp_dataJSON, "ueRadioCapabilityForPaging");
	if(ue_radio_capability_for_paging) {
		ue_radio_capability_for_paging_local_nonprim =
			n2_info_content_parseFromJSON(
				ue_radio_capability_for_paging);
		if(!ue_radio_capability_for_paging_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [ue_radio_capability_for_paging]");
			goto end;
		}
	}

	ue_nbiot_radio_capability = cJSON_GetObjectItemCaseSensitive(
		ue_context_transfer_rsp_dataJSON, "ueNbiotRadioCapability");
	if(ue_nbiot_radio_capability) {
		ue_nbiot_radio_capability_local_nonprim =
			n2_info_content_parseFromJSON(ue_nbiot_radio_capability);
		if(!ue_nbiot_radio_capability_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [ue_nbiot_radio_capability]");
			goto end;
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		ue_context_transfer_rsp_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"ue_context_transfer_rsp_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	ue_context_transfer_rsp_data_local_var =
		ue_context_transfer_rsp_data_create(
			ue_context_local_nonprim,
			ue_radio_capability ? ue_radio_capability_local_nonprim : NULL,
			ue_radio_capability_for_paging ? ue_radio_capability_for_paging_local_nonprim : NULL,
			ue_nbiot_radio_capability ? ue_nbiot_radio_capability_local_nonprim : NULL,
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL
			);

	return ue_context_transfer_rsp_data_local_var;
end:
	if(ue_context_local_nonprim) {
		ue_context_free(ue_context_local_nonprim);
		ue_context_local_nonprim = NULL;
	}
	if(ue_radio_capability_local_nonprim) {
		n2_info_content_free(ue_radio_capability_local_nonprim);
		ue_radio_capability_local_nonprim = NULL;
	}
	if(ue_radio_capability_for_paging_local_nonprim) {
		n2_info_content_free(
			ue_radio_capability_for_paging_local_nonprim);
		ue_radio_capability_for_paging_local_nonprim = NULL;
	}
	if(ue_nbiot_radio_capability_local_nonprim) {
		n2_info_content_free(ue_nbiot_radio_capability_local_nonprim);
		ue_nbiot_radio_capability_local_nonprim = NULL;
	}
	return NULL;
}

ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_copy(
	ue_context_transfer_rsp_data_t	*dst,
	ue_context_transfer_rsp_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_context_transfer_rsp_data_convertToJSON(src);
	if(!item) {
		printf("ue_context_transfer_rsp_data_convertToJSON() failed");
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

	ue_context_transfer_rsp_data_free(dst);
	dst = ue_context_transfer_rsp_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
