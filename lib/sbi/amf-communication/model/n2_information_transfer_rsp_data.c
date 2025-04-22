#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_information_transfer_rsp_data.h"

n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data_create(
	n2_information_transfer_result_e result,
	pws_response_data_t *pws_rsp_data, char *supported_features,
	list_t *tss_rsp_per_ngran_list) {
	n2_information_transfer_rsp_data_t *
	        n2_information_transfer_rsp_data_local_var =
		malloc(sizeof(n2_information_transfer_rsp_data_t));

	n2_information_transfer_rsp_data_local_var->result = result;
	n2_information_transfer_rsp_data_local_var->pws_rsp_data = pws_rsp_data;
	n2_information_transfer_rsp_data_local_var->supported_features =
		supported_features;
	n2_information_transfer_rsp_data_local_var->tss_rsp_per_ngran_list =
		tss_rsp_per_ngran_list;

	return n2_information_transfer_rsp_data_local_var;
}

void n2_information_transfer_rsp_data_free(
	n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data) {
	lnode_t *node = NULL;

	if(NULL == n2_information_transfer_rsp_data) {
		return;
	}
	if(n2_information_transfer_rsp_data->pws_rsp_data) {
		pws_response_data_free(
			n2_information_transfer_rsp_data->pws_rsp_data);
		n2_information_transfer_rsp_data->pws_rsp_data = NULL;
	}
	if(n2_information_transfer_rsp_data->supported_features) {
		free(n2_information_transfer_rsp_data->supported_features);
		n2_information_transfer_rsp_data->supported_features = NULL;
	}
	if(n2_information_transfer_rsp_data->tss_rsp_per_ngran_list) {
		list_for_each(
			n2_information_transfer_rsp_data->tss_rsp_per_ngran_list,
			node) {
			tss_rsp_per_ngran_free(node->data);
		}
		list_free(
			n2_information_transfer_rsp_data->tss_rsp_per_ngran_list);
		n2_information_transfer_rsp_data->tss_rsp_per_ngran_list = NULL;
	}
	free(n2_information_transfer_rsp_data);
}

cJSON *n2_information_transfer_rsp_data_convertToJSON(
	n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n2_information_transfer_rsp_data == NULL) {
		printf(
			"n2_information_transfer_rsp_data_convertToJSON() failed [N2InformationTransferRspData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n2_information_transfer_rsp_data->result ==
	   n2_information_transfer_result_NULL)
	{
		printf(
			"n2_information_transfer_rsp_data_convertToJSON() failed [result]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "result",
	                           n2_information_transfer_result_ToString(
					   n2_information_transfer_rsp_data
					   ->
					   result)) == NULL)
	{
		printf(
			"n2_information_transfer_rsp_data_convertToJSON() failed [result]");
		goto end;
	}

	if(n2_information_transfer_rsp_data->pws_rsp_data) {
		cJSON *pws_rsp_data_local_JSON =
			pws_response_data_convertToJSON(
				n2_information_transfer_rsp_data->pws_rsp_data);
		if(pws_rsp_data_local_JSON == NULL) {
			printf(
				"n2_information_transfer_rsp_data_convertToJSON() failed [pws_rsp_data]");
			goto end;
		}
		cJSON_AddItemToObject(item, "pwsRspData",
		                      pws_rsp_data_local_JSON);
		if(item->child == NULL) {
			printf(
				"n2_information_transfer_rsp_data_convertToJSON() failed [pws_rsp_data]");
			goto end;
		}
	}

	if(n2_information_transfer_rsp_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           n2_information_transfer_rsp_data->
		                           supported_features) == NULL)
		{
			printf(
				"n2_information_transfer_rsp_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(n2_information_transfer_rsp_data->tss_rsp_per_ngran_list) {
		cJSON *tss_rsp_per_ngran_listList = cJSON_AddArrayToObject(item,
		                                                           "tssRspPerNgranList");
		if(tss_rsp_per_ngran_listList == NULL) {
			printf(
				"n2_information_transfer_rsp_data_convertToJSON() failed [tss_rsp_per_ngran_list]");
			goto end;
		}
		list_for_each(
			n2_information_transfer_rsp_data->tss_rsp_per_ngran_list,
			node) {
			cJSON *itemLocal = tss_rsp_per_ngran_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"n2_information_transfer_rsp_data_convertToJSON() failed [tss_rsp_per_ngran_list]");
				goto end;
			}
			cJSON_AddItemToArray(tss_rsp_per_ngran_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

n2_information_transfer_rsp_data_t *
n2_information_transfer_rsp_data_parseFromJSON(
	cJSON *n2_information_transfer_rsp_dataJSON) {
	n2_information_transfer_rsp_data_t *
	        n2_information_transfer_rsp_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *result = NULL;
	n2_information_transfer_result_e resultVariable = 0;
	cJSON *pws_rsp_data = NULL;
	pws_response_data_t *pws_rsp_data_local_nonprim = NULL;
	cJSON *supported_features = NULL;
	cJSON *tss_rsp_per_ngran_list = NULL;
	list_t *tss_rsp_per_ngran_listList = NULL;
	result = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_rsp_dataJSON, "result");
	if(!result) {
		printf(
			"n2_information_transfer_rsp_data_parseFromJSON() failed [result]");
		goto end;
	}
	if(!cJSON_IsString(result)) {
		printf(
			"n2_information_transfer_rsp_data_parseFromJSON() failed [result]");
		goto end;
	}
	resultVariable = n2_information_transfer_result_FromString(
		result->valuestring);

	pws_rsp_data = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_rsp_dataJSON, "pwsRspData");
	if(pws_rsp_data) {
		pws_rsp_data_local_nonprim = pws_response_data_parseFromJSON(
			pws_rsp_data);
		if(!pws_rsp_data_local_nonprim) {
			printf(
				"pws_response_data_parseFromJSON failed [pws_rsp_data]");
			goto end;
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_rsp_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"n2_information_transfer_rsp_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	tss_rsp_per_ngran_list = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_rsp_dataJSON, "tssRspPerNgranList");
	if(tss_rsp_per_ngran_list) {
		cJSON *tss_rsp_per_ngran_list_local = NULL;
		if(!cJSON_IsArray(tss_rsp_per_ngran_list)) {
			printf(
				"n2_information_transfer_rsp_data_parseFromJSON() failed [tss_rsp_per_ngran_list]");
			goto end;
		}

		tss_rsp_per_ngran_listList = list_create();

		cJSON_ArrayForEach(tss_rsp_per_ngran_list_local,
		                   tss_rsp_per_ngran_list) {
			if(!cJSON_IsObject(tss_rsp_per_ngran_list_local)) {
				printf(
					"n2_information_transfer_rsp_data_parseFromJSON() failed [tss_rsp_per_ngran_list]");
				goto end;
			}
			tss_rsp_per_ngran_t *tss_rsp_per_ngran_listItem =
				tss_rsp_per_ngran_parseFromJSON(
					tss_rsp_per_ngran_list_local);
			if(!tss_rsp_per_ngran_listItem) {
				printf("No tss_rsp_per_ngran_listItem");
				goto end;
			}
			list_add(tss_rsp_per_ngran_listList,
			         tss_rsp_per_ngran_listItem);
		}
	}

	n2_information_transfer_rsp_data_local_var =
		n2_information_transfer_rsp_data_create(
			resultVariable,
			pws_rsp_data ? pws_rsp_data_local_nonprim : NULL,
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL,
			tss_rsp_per_ngran_list ? tss_rsp_per_ngran_listList : NULL
			);

	return n2_information_transfer_rsp_data_local_var;
end:
	if(pws_rsp_data_local_nonprim) {
		pws_response_data_free(pws_rsp_data_local_nonprim);
		pws_rsp_data_local_nonprim = NULL;
	}
	if(tss_rsp_per_ngran_listList) {
		list_for_each(tss_rsp_per_ngran_listList, node) {
			tss_rsp_per_ngran_free(node->data);
		}
		list_free(tss_rsp_per_ngran_listList);
		tss_rsp_per_ngran_listList = NULL;
	}
	return NULL;
}

n2_information_transfer_rsp_data_t *n2_information_transfer_rsp_data_copy(
	n2_information_transfer_rsp_data_t	*dst,
	n2_information_transfer_rsp_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n2_information_transfer_rsp_data_convertToJSON(src);
	if(!item) {
		printf("n2_information_transfer_rsp_data_convertToJSON() failed");
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

	n2_information_transfer_rsp_data_free(dst);
	dst = n2_information_transfer_rsp_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
