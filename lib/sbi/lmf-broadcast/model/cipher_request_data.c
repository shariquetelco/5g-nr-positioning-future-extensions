#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cipher_request_data.h"

cipher_request_data_t *cipher_request_data_create(char	*amf_call_back_uri,
                                                  char	*supported_features) {
	cipher_request_data_t *cipher_request_data_local_var =
		malloc(sizeof(cipher_request_data_t));

	cipher_request_data_local_var->amf_call_back_uri = amf_call_back_uri;
	cipher_request_data_local_var->supported_features = supported_features;

	return cipher_request_data_local_var;
}

void cipher_request_data_free(cipher_request_data_t *cipher_request_data) {
	lnode_t *node = NULL;

	if(NULL == cipher_request_data) {
		return;
	}
	if(cipher_request_data->amf_call_back_uri) {
		free(cipher_request_data->amf_call_back_uri);
		cipher_request_data->amf_call_back_uri = NULL;
	}
	if(cipher_request_data->supported_features) {
		free(cipher_request_data->supported_features);
		cipher_request_data->supported_features = NULL;
	}
	free(cipher_request_data);
}

cJSON *cipher_request_data_convertToJSON(
	cipher_request_data_t *cipher_request_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cipher_request_data == NULL) {
		printf(
			"cipher_request_data_convertToJSON() failed [CipherRequestData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!cipher_request_data->amf_call_back_uri) {
		printf(
			"cipher_request_data_convertToJSON() failed [amf_call_back_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "amfCallBackURI",
	                           cipher_request_data->amf_call_back_uri) ==
	   NULL)
	{
		printf(
			"cipher_request_data_convertToJSON() failed [amf_call_back_uri]");
		goto end;
	}

	if(cipher_request_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           cipher_request_data->
		                           supported_features) == NULL)
		{
			printf(
				"cipher_request_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

end:
	return item;
}

cipher_request_data_t *cipher_request_data_parseFromJSON(
	cJSON *cipher_request_dataJSON) {
	cipher_request_data_t *cipher_request_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *amf_call_back_uri = NULL;
	cJSON *supported_features = NULL;
	amf_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		cipher_request_dataJSON, "amfCallBackURI");
	if(!amf_call_back_uri) {
		printf(
			"cipher_request_data_parseFromJSON() failed [amf_call_back_uri]");
		goto end;
	}
	if(!cJSON_IsString(amf_call_back_uri)) {
		printf(
			"cipher_request_data_parseFromJSON() failed [amf_call_back_uri]");
		goto end;
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		cipher_request_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"cipher_request_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	cipher_request_data_local_var = cipher_request_data_create(
		strdup(amf_call_back_uri->valuestring),
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL
		);

	return cipher_request_data_local_var;
end:
	return NULL;
}

cipher_request_data_t *cipher_request_data_copy(cipher_request_data_t	*dst,
                                                cipher_request_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cipher_request_data_convertToJSON(src);
	if(!item) {
		printf("cipher_request_data_convertToJSON() failed");
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

	cipher_request_data_free(dst);
	dst = cipher_request_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
