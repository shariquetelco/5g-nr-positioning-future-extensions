#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "n2_information_transfer_req_data.h"

n2_information_transfer_req_data_t *n2_information_transfer_req_data_create(
	list_t *tai_list, rat_selector_e rat_selector,
	list_t *global_ran_node_list, n2_info_container_t *n2_information,
	char *supported_features) {
	n2_information_transfer_req_data_t *
	        n2_information_transfer_req_data_local_var =
		malloc(sizeof(n2_information_transfer_req_data_t));

	n2_information_transfer_req_data_local_var->tai_list = tai_list;
	n2_information_transfer_req_data_local_var->rat_selector = rat_selector;
	n2_information_transfer_req_data_local_var->global_ran_node_list =
		global_ran_node_list;
	n2_information_transfer_req_data_local_var->n2_information =
		n2_information;
	n2_information_transfer_req_data_local_var->supported_features =
		supported_features;

	return n2_information_transfer_req_data_local_var;
}

void n2_information_transfer_req_data_free(
	n2_information_transfer_req_data_t *n2_information_transfer_req_data) {
	lnode_t *node = NULL;

	if(NULL == n2_information_transfer_req_data) {
		return;
	}
	if(n2_information_transfer_req_data->tai_list) {
		list_for_each(n2_information_transfer_req_data->tai_list,
		              node) {
			tai_free(node->data);
		}
		list_free(n2_information_transfer_req_data->tai_list);
		n2_information_transfer_req_data->tai_list = NULL;
	}
	if(n2_information_transfer_req_data->global_ran_node_list) {
		list_for_each(
			n2_information_transfer_req_data->global_ran_node_list,
			node) {
			global_ran_node_id_free(node->data);
		}
		list_free(n2_information_transfer_req_data->global_ran_node_list);
		n2_information_transfer_req_data->global_ran_node_list = NULL;
	}
	if(n2_information_transfer_req_data->n2_information) {
		n2_info_container_free(
			n2_information_transfer_req_data->n2_information);
		n2_information_transfer_req_data->n2_information = NULL;
	}
	if(n2_information_transfer_req_data->supported_features) {
		free(n2_information_transfer_req_data->supported_features);
		n2_information_transfer_req_data->supported_features = NULL;
	}
	free(n2_information_transfer_req_data);
}

cJSON *n2_information_transfer_req_data_convertToJSON(
	n2_information_transfer_req_data_t *n2_information_transfer_req_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(n2_information_transfer_req_data == NULL) {
		printf(
			"n2_information_transfer_req_data_convertToJSON() failed [N2InformationTransferReqData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(n2_information_transfer_req_data->tai_list) {
		cJSON *tai_listList = cJSON_AddArrayToObject(item, "taiList");
		if(tai_listList == NULL) {
			printf(
				"n2_information_transfer_req_data_convertToJSON() failed [tai_list]");
			goto end;
		}
		list_for_each(n2_information_transfer_req_data->tai_list,
		              node) {
			cJSON *itemLocal = tai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"n2_information_transfer_req_data_convertToJSON() failed [tai_list]");
				goto end;
			}
			cJSON_AddItemToArray(tai_listList, itemLocal);
		}
	}

	if(n2_information_transfer_req_data->rat_selector !=
	   rat_selector_NULL)
	{
		if(cJSON_AddStringToObject(item, "ratSelector",
		                           rat_selector_ToString(
						   n2_information_transfer_req_data
						   ->
						   rat_selector))
		   == NULL)
		{
			printf(
				"n2_information_transfer_req_data_convertToJSON() failed [rat_selector]");
			goto end;
		}
	}

	if(n2_information_transfer_req_data->global_ran_node_list) {
		cJSON *global_ran_node_listList = cJSON_AddArrayToObject(item,
		                                                         "globalRanNodeList");
		if(global_ran_node_listList == NULL) {
			printf(
				"n2_information_transfer_req_data_convertToJSON() failed [global_ran_node_list]");
			goto end;
		}
		list_for_each(
			n2_information_transfer_req_data->global_ran_node_list,
			node) {
			cJSON *itemLocal = global_ran_node_id_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"n2_information_transfer_req_data_convertToJSON() failed [global_ran_node_list]");
				goto end;
			}
			cJSON_AddItemToArray(global_ran_node_listList,
			                     itemLocal);
		}
	}

	if(!n2_information_transfer_req_data->n2_information) {
		printf(
			"n2_information_transfer_req_data_convertToJSON() failed [n2_information]");
		return NULL;
	}
	cJSON *n2_information_local_JSON = n2_info_container_convertToJSON(
		n2_information_transfer_req_data->n2_information);
	if(n2_information_local_JSON == NULL) {
		printf(
			"n2_information_transfer_req_data_convertToJSON() failed [n2_information]");
		goto end;
	}
	cJSON_AddItemToObject(item, "n2Information", n2_information_local_JSON);
	if(item->child == NULL) {
		printf(
			"n2_information_transfer_req_data_convertToJSON() failed [n2_information]");
		goto end;
	}

	if(n2_information_transfer_req_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           n2_information_transfer_req_data->
		                           supported_features) == NULL)
		{
			printf(
				"n2_information_transfer_req_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

end:
	return item;
}

n2_information_transfer_req_data_t *
n2_information_transfer_req_data_parseFromJSON(
	cJSON *n2_information_transfer_req_dataJSON) {
	n2_information_transfer_req_data_t *
	        n2_information_transfer_req_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *tai_list = NULL;
	list_t *tai_listList = NULL;
	cJSON *rat_selector = NULL;
	rat_selector_e rat_selectorVariable = 0;
	cJSON *global_ran_node_list = NULL;
	list_t *global_ran_node_listList = NULL;
	cJSON *n2_information = NULL;
	n2_info_container_t *n2_information_local_nonprim = NULL;
	cJSON *supported_features = NULL;
	tai_list = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_req_dataJSON, "taiList");
	if(tai_list) {
		cJSON *tai_list_local = NULL;
		if(!cJSON_IsArray(tai_list)) {
			printf(
				"n2_information_transfer_req_data_parseFromJSON() failed [tai_list]");
			goto end;
		}

		tai_listList = list_create();

		cJSON_ArrayForEach(tai_list_local, tai_list) {
			if(!cJSON_IsObject(tai_list_local)) {
				printf(
					"n2_information_transfer_req_data_parseFromJSON() failed [tai_list]");
				goto end;
			}
			tai_t *tai_listItem = tai_parseFromJSON(tai_list_local);
			if(!tai_listItem) {
				printf("No tai_listItem");
				goto end;
			}
			list_add(tai_listList, tai_listItem);
		}
	}

	rat_selector = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_req_dataJSON, "ratSelector");
	if(rat_selector) {
		if(!cJSON_IsString(rat_selector)) {
			printf(
				"n2_information_transfer_req_data_parseFromJSON() failed [rat_selector]");
			goto end;
		}
		rat_selectorVariable = rat_selector_FromString(
			rat_selector->valuestring);
	}

	global_ran_node_list = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_req_dataJSON, "globalRanNodeList");
	if(global_ran_node_list) {
		cJSON *global_ran_node_list_local = NULL;
		if(!cJSON_IsArray(global_ran_node_list)) {
			printf(
				"n2_information_transfer_req_data_parseFromJSON() failed [global_ran_node_list]");
			goto end;
		}

		global_ran_node_listList = list_create();

		cJSON_ArrayForEach(global_ran_node_list_local,
		                   global_ran_node_list) {
			if(!cJSON_IsObject(global_ran_node_list_local)) {
				printf(
					"n2_information_transfer_req_data_parseFromJSON() failed [global_ran_node_list]");
				goto end;
			}
			global_ran_node_id_t *global_ran_node_listItem =
				global_ran_node_id_parseFromJSON(
					global_ran_node_list_local);
			if(!global_ran_node_listItem) {
				printf("No global_ran_node_listItem");
				goto end;
			}
			list_add(global_ran_node_listList,
			         global_ran_node_listItem);
		}
	}

	n2_information = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_req_dataJSON, "n2Information");
	if(!n2_information) {
		printf(
			"n2_information_transfer_req_data_parseFromJSON() failed [n2_information]");
		goto end;
	}
	n2_information_local_nonprim = n2_info_container_parseFromJSON(
		n2_information);
	if(!n2_information_local_nonprim) {
		printf("n2_info_container_parseFromJSON failed [n2_information]");
		goto end;
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		n2_information_transfer_req_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"n2_information_transfer_req_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	n2_information_transfer_req_data_local_var =
		n2_information_transfer_req_data_create(
			tai_list ? tai_listList : NULL,
			rat_selector ? rat_selectorVariable : 0,
			global_ran_node_list ? global_ran_node_listList : NULL,
			n2_information_local_nonprim,
			supported_features &&
			!cJSON_IsNull(supported_features) ? strdup(
				supported_features->
				valuestring) : NULL
			);

	return n2_information_transfer_req_data_local_var;
end:
	if(tai_listList) {
		list_for_each(tai_listList, node) {
			tai_free(node->data);
		}
		list_free(tai_listList);
		tai_listList = NULL;
	}
	if(global_ran_node_listList) {
		list_for_each(global_ran_node_listList, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(global_ran_node_listList);
		global_ran_node_listList = NULL;
	}
	if(n2_information_local_nonprim) {
		n2_info_container_free(n2_information_local_nonprim);
		n2_information_local_nonprim = NULL;
	}
	return NULL;
}

n2_information_transfer_req_data_t *n2_information_transfer_req_data_copy(
	n2_information_transfer_req_data_t	*dst,
	n2_information_transfer_req_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = n2_information_transfer_req_data_convertToJSON(src);
	if(!item) {
		printf("n2_information_transfer_req_data_convertToJSON() failed");
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

	n2_information_transfer_req_data_free(dst);
	dst = n2_information_transfer_req_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
