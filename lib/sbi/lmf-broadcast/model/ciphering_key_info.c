#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_key_info.h"

ciphering_key_info_t *ciphering_key_info_create(list_t	*ciphering_data,
                                                char	*supported_features) {
	ciphering_key_info_t *ciphering_key_info_local_var =
		malloc(sizeof(ciphering_key_info_t));

	ciphering_key_info_local_var->ciphering_data = ciphering_data;
	ciphering_key_info_local_var->supported_features = supported_features;

	return ciphering_key_info_local_var;
}

void ciphering_key_info_free(ciphering_key_info_t *ciphering_key_info) {
	lnode_t *node = NULL;

	if(NULL == ciphering_key_info) {
		return;
	}
	if(ciphering_key_info->ciphering_data) {
		list_for_each(ciphering_key_info->ciphering_data, node) {
			ciphering_data_set_free(node->data);
		}
		list_free(ciphering_key_info->ciphering_data);
		ciphering_key_info->ciphering_data = NULL;
	}
	if(ciphering_key_info->supported_features) {
		free(ciphering_key_info->supported_features);
		ciphering_key_info->supported_features = NULL;
	}
	free(ciphering_key_info);
}

cJSON *ciphering_key_info_convertToJSON(
	ciphering_key_info_t *ciphering_key_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ciphering_key_info == NULL) {
		printf(
			"ciphering_key_info_convertToJSON() failed [CipheringKeyInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ciphering_key_info->ciphering_data) {
		printf(
			"ciphering_key_info_convertToJSON() failed [ciphering_data]");
		return NULL;
	}
	cJSON *ciphering_dataList =
		cJSON_AddArrayToObject(item, "cipheringData");
	if(ciphering_dataList == NULL) {
		printf(
			"ciphering_key_info_convertToJSON() failed [ciphering_data]");
		goto end;
	}
	list_for_each(ciphering_key_info->ciphering_data, node) {
		cJSON *itemLocal = ciphering_data_set_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"ciphering_key_info_convertToJSON() failed [ciphering_data]");
			goto end;
		}
		cJSON_AddItemToArray(ciphering_dataList, itemLocal);
	}

	if(ciphering_key_info->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           ciphering_key_info->
		                           supported_features) == NULL)
		{
			printf(
				"ciphering_key_info_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

end:
	return item;
}

ciphering_key_info_t *ciphering_key_info_parseFromJSON(
	cJSON *ciphering_key_infoJSON) {
	ciphering_key_info_t *ciphering_key_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ciphering_data = NULL;
	list_t *ciphering_dataList = NULL;
	cJSON *supported_features = NULL;
	ciphering_data = cJSON_GetObjectItemCaseSensitive(
		ciphering_key_infoJSON, "cipheringData");
	if(!ciphering_data) {
		printf(
			"ciphering_key_info_parseFromJSON() failed [ciphering_data]");
		goto end;
	}
	cJSON *ciphering_data_local = NULL;
	if(!cJSON_IsArray(ciphering_data)) {
		printf(
			"ciphering_key_info_parseFromJSON() failed [ciphering_data]");
		goto end;
	}

	ciphering_dataList = list_create();

	cJSON_ArrayForEach(ciphering_data_local, ciphering_data) {
		if(!cJSON_IsObject(ciphering_data_local)) {
			printf(
				"ciphering_key_info_parseFromJSON() failed [ciphering_data]");
			goto end;
		}
		ciphering_data_set_t *ciphering_dataItem =
			ciphering_data_set_parseFromJSON(ciphering_data_local);
		if(!ciphering_dataItem) {
			printf("No ciphering_dataItem");
			goto end;
		}
		list_add(ciphering_dataList, ciphering_dataItem);
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		ciphering_key_infoJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"ciphering_key_info_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	ciphering_key_info_local_var = ciphering_key_info_create(
		ciphering_dataList,
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL
		);

	return ciphering_key_info_local_var;
end:
	if(ciphering_dataList) {
		list_for_each(ciphering_dataList, node) {
			ciphering_data_set_free(node->data);
		}
		list_free(ciphering_dataList);
		ciphering_dataList = NULL;
	}
	return NULL;
}

ciphering_key_info_t *ciphering_key_info_copy(ciphering_key_info_t	*dst,
                                              ciphering_key_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ciphering_key_info_convertToJSON(src);
	if(!item) {
		printf("ciphering_key_info_convertToJSON() failed");
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

	ciphering_key_info_free(dst);
	dst = ciphering_key_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
