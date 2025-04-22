#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n1_n2_message_transfer_rsp_data.h"

n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_create(
	n1_n2_message_transfer_cause_e cause, char *supported_features) {
	n1_n2_message_transfer_rsp_data_t *
	        n1_n2_message_transfer_rsp_data_local_var =
		malloc(sizeof(n1_n2_message_transfer_rsp_data_t));

	n1_n2_message_transfer_rsp_data_local_var->cause = cause;
	n1_n2_message_transfer_rsp_data_local_var->supported_features =
		supported_features;

	return n1_n2_message_transfer_rsp_data_local_var;
}

void n1_n2_message_transfer_rsp_data_free(
	n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data) {
	lnode_t *node = NULL;

	if(NULL == n1_n2_message_transfer_rsp_data) {
		return;
	}
	if(n1_n2_message_transfer_rsp_data->supported_features) {
		free(n1_n2_message_transfer_rsp_data->supported_features);
		n1_n2_message_transfer_rsp_data->supported_features = NULL;
	}
	free(n1_n2_message_transfer_rsp_data);
}

cJSON *n1_n2_message_transfer_rsp_data_convertToJSON(
	n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n1_n2_message_transfer_rsp_data == NULL) {
		printf(
			"n1_n2_message_transfer_rsp_data_convertToJSON() failed [N1N2MessageTransferRspData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n1_n2_message_transfer_rsp_data->cause ==
	   n1_n2_message_transfer_cause_NULL)
	{
		printf(
			"n1_n2_message_transfer_rsp_data_convertToJSON() failed [cause]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "cause",
	                           n1_n2_message_transfer_cause_ToString(
					   n1_n2_message_transfer_rsp_data->
					   cause))
	   == NULL)
	{
		printf(
			"n1_n2_message_transfer_rsp_data_convertToJSON() failed [cause]");
		goto end;
	}

	if(n1_n2_message_transfer_rsp_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           n1_n2_message_transfer_rsp_data->
		                           supported_features) == NULL)
		{
			printf(
				"n1_n2_message_transfer_rsp_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

end:
	return item;
}

n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_parseFromJSON(
	cJSON *n1_n2_message_transfer_rsp_dataJSON) {
	n1_n2_message_transfer_rsp_data_t *
	        n1_n2_message_transfer_rsp_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cause = NULL;
	n1_n2_message_transfer_cause_e causeVariable = 0;
	cJSON *supported_features = NULL;
	cause = cJSON_GetObjectItemCaseSensitive(
		n1_n2_message_transfer_rsp_dataJSON, "cause");
	if(!cause) {
		printf(
			"n1_n2_message_transfer_rsp_data_parseFromJSON() failed [cause]");
		goto end;
	}
	if(!cJSON_IsString(cause)) {
		printf(
			"n1_n2_message_transfer_rsp_data_parseFromJSON() failed [cause]");
		goto end;
	}
	causeVariable = n1_n2_message_transfer_cause_FromString(
		cause->valuestring);

	supported_features = cJSON_GetObjectItemCaseSensitive(
		n1_n2_message_transfer_rsp_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"n1_n2_message_transfer_rsp_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	n1_n2_message_transfer_rsp_data_local_var =
		n1_n2_message_transfer_rsp_data_create(
			causeVariable,
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL
			);

	return n1_n2_message_transfer_rsp_data_local_var;
end:
	return NULL;
}

n1_n2_message_transfer_rsp_data_t *n1_n2_message_transfer_rsp_data_copy(
	n1_n2_message_transfer_rsp_data_t	*dst,
	n1_n2_message_transfer_rsp_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n1_n2_message_transfer_rsp_data_convertToJSON(src);
	if(!item) {
		printf("n1_n2_message_transfer_rsp_data_convertToJSON() failed");
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

	n1_n2_message_transfer_rsp_data_free(dst);
	dst = n1_n2_message_transfer_rsp_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
