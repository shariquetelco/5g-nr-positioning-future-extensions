#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assigned_ebi_data.h"

assigned_ebi_data_t *assigned_ebi_data_create(int	pdu_session_id,
                                              list_t	*assigned_ebi_list,
                                              list_t	*failed_arp_list,
                                              list_t	*released_ebi_list,
                                              list_t	*modified_ebi_list) {
	assigned_ebi_data_t *assigned_ebi_data_local_var =
		malloc(sizeof(assigned_ebi_data_t));

	assigned_ebi_data_local_var->pdu_session_id = pdu_session_id;
	assigned_ebi_data_local_var->assigned_ebi_list = assigned_ebi_list;
	assigned_ebi_data_local_var->failed_arp_list = failed_arp_list;
	assigned_ebi_data_local_var->released_ebi_list = released_ebi_list;
	assigned_ebi_data_local_var->modified_ebi_list = modified_ebi_list;

	return assigned_ebi_data_local_var;
}

void assigned_ebi_data_free(assigned_ebi_data_t *assigned_ebi_data) {
	lnode_t *node = NULL;

	if(NULL == assigned_ebi_data) {
		return;
	}
	if(assigned_ebi_data->assigned_ebi_list) {
		list_for_each(assigned_ebi_data->assigned_ebi_list, node) {
			ebi_arp_mapping_free(node->data);
		}
		list_free(assigned_ebi_data->assigned_ebi_list);
		assigned_ebi_data->assigned_ebi_list = NULL;
	}
	if(assigned_ebi_data->failed_arp_list) {
		list_for_each(assigned_ebi_data->failed_arp_list, node) {
			arp_free(node->data);
		}
		list_free(assigned_ebi_data->failed_arp_list);
		assigned_ebi_data->failed_arp_list = NULL;
	}
	if(assigned_ebi_data->released_ebi_list) {
		list_for_each(assigned_ebi_data->released_ebi_list, node) {
			free(node->data);
		}
		list_free(assigned_ebi_data->released_ebi_list);
		assigned_ebi_data->released_ebi_list = NULL;
	}
	if(assigned_ebi_data->modified_ebi_list) {
		list_for_each(assigned_ebi_data->modified_ebi_list, node) {
			free(node->data);
		}
		list_free(assigned_ebi_data->modified_ebi_list);
		assigned_ebi_data->modified_ebi_list = NULL;
	}
	free(assigned_ebi_data);
}

cJSON *assigned_ebi_data_convertToJSON(assigned_ebi_data_t *assigned_ebi_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(assigned_ebi_data == NULL) {
		printf(
			"assigned_ebi_data_convertToJSON() failed [AssignedEbiData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "pduSessionId",
	                           assigned_ebi_data->pdu_session_id) == NULL)
	{
		printf(
			"assigned_ebi_data_convertToJSON() failed [pdu_session_id]");
		goto end;
	}

	if(!assigned_ebi_data->assigned_ebi_list) {
		printf(
			"assigned_ebi_data_convertToJSON() failed [assigned_ebi_list]");
		return NULL;
	}
	cJSON *assigned_ebi_listList = cJSON_AddArrayToObject(item,
	                                                      "assignedEbiList");
	if(assigned_ebi_listList == NULL) {
		printf(
			"assigned_ebi_data_convertToJSON() failed [assigned_ebi_list]");
		goto end;
	}
	list_for_each(assigned_ebi_data->assigned_ebi_list, node) {
		cJSON *itemLocal = ebi_arp_mapping_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"assigned_ebi_data_convertToJSON() failed [assigned_ebi_list]");
			goto end;
		}
		cJSON_AddItemToArray(assigned_ebi_listList, itemLocal);
	}

	if(assigned_ebi_data->failed_arp_list) {
		cJSON *failed_arp_listList = cJSON_AddArrayToObject(item,
		                                                    "failedArpList");
		if(failed_arp_listList == NULL) {
			printf(
				"assigned_ebi_data_convertToJSON() failed [failed_arp_list]");
			goto end;
		}
		list_for_each(assigned_ebi_data->failed_arp_list, node) {
			cJSON *itemLocal = arp_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"assigned_ebi_data_convertToJSON() failed [failed_arp_list]");
				goto end;
			}
			cJSON_AddItemToArray(failed_arp_listList, itemLocal);
		}
	}

	if(assigned_ebi_data->released_ebi_list) {
		cJSON *released_ebi_listList = cJSON_AddArrayToObject(item,
		                                                      "releasedEbiList");
		if(released_ebi_listList == NULL) {
			printf(
				"assigned_ebi_data_convertToJSON() failed [released_ebi_list]");
			goto end;
		}
		list_for_each(assigned_ebi_data->released_ebi_list, node) {
			if(node->data == NULL) {
				printf(
					"assigned_ebi_data_convertToJSON() failed [released_ebi_list]");
				goto end;
			}
			if(cJSON_AddNumberToObject(released_ebi_listList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"assigned_ebi_data_convertToJSON() failed [released_ebi_list]");
				goto end;
			}
		}
	}

	if(assigned_ebi_data->modified_ebi_list) {
		cJSON *modified_ebi_listList = cJSON_AddArrayToObject(item,
		                                                      "modifiedEbiList");
		if(modified_ebi_listList == NULL) {
			printf(
				"assigned_ebi_data_convertToJSON() failed [modified_ebi_list]");
			goto end;
		}
		list_for_each(assigned_ebi_data->modified_ebi_list, node) {
			if(node->data == NULL) {
				printf(
					"assigned_ebi_data_convertToJSON() failed [modified_ebi_list]");
				goto end;
			}
			if(cJSON_AddNumberToObject(modified_ebi_listList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"assigned_ebi_data_convertToJSON() failed [modified_ebi_list]");
				goto end;
			}
		}
	}

end:
	return item;
}

assigned_ebi_data_t *assigned_ebi_data_parseFromJSON(
	cJSON *assigned_ebi_dataJSON) {
	assigned_ebi_data_t *assigned_ebi_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pdu_session_id = NULL;
	cJSON *assigned_ebi_list = NULL;
	list_t *assigned_ebi_listList = NULL;
	cJSON *failed_arp_list = NULL;
	list_t *failed_arp_listList = NULL;
	cJSON *released_ebi_list = NULL;
	list_t *released_ebi_listList = NULL;
	cJSON *modified_ebi_list = NULL;
	list_t *modified_ebi_listList = NULL;
	pdu_session_id = cJSON_GetObjectItemCaseSensitive(assigned_ebi_dataJSON,
	                                                  "pduSessionId");
	if(!pdu_session_id) {
		printf(
			"assigned_ebi_data_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}
	if(!cJSON_IsNumber(pdu_session_id)) {
		printf(
			"assigned_ebi_data_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}

	assigned_ebi_list = cJSON_GetObjectItemCaseSensitive(
		assigned_ebi_dataJSON, "assignedEbiList");
	if(!assigned_ebi_list) {
		printf(
			"assigned_ebi_data_parseFromJSON() failed [assigned_ebi_list]");
		goto end;
	}
	cJSON *assigned_ebi_list_local = NULL;
	if(!cJSON_IsArray(assigned_ebi_list)) {
		printf(
			"assigned_ebi_data_parseFromJSON() failed [assigned_ebi_list]");
		goto end;
	}

	assigned_ebi_listList = list_create();

	cJSON_ArrayForEach(assigned_ebi_list_local, assigned_ebi_list) {
		if(!cJSON_IsObject(assigned_ebi_list_local)) {
			printf(
				"assigned_ebi_data_parseFromJSON() failed [assigned_ebi_list]");
			goto end;
		}
		ebi_arp_mapping_t *assigned_ebi_listItem =
			ebi_arp_mapping_parseFromJSON(assigned_ebi_list_local);
		if(!assigned_ebi_listItem) {
			printf("No assigned_ebi_listItem");
			goto end;
		}
		list_add(assigned_ebi_listList, assigned_ebi_listItem);
	}

	failed_arp_list = cJSON_GetObjectItemCaseSensitive(
		assigned_ebi_dataJSON, "failedArpList");
	if(failed_arp_list) {
		cJSON *failed_arp_list_local = NULL;
		if(!cJSON_IsArray(failed_arp_list)) {
			printf(
				"assigned_ebi_data_parseFromJSON() failed [failed_arp_list]");
			goto end;
		}

		failed_arp_listList = list_create();

		cJSON_ArrayForEach(failed_arp_list_local, failed_arp_list) {
			if(!cJSON_IsObject(failed_arp_list_local)) {
				printf(
					"assigned_ebi_data_parseFromJSON() failed [failed_arp_list]");
				goto end;
			}
			arp_t *failed_arp_listItem = arp_parseFromJSON(
				failed_arp_list_local);
			if(!failed_arp_listItem) {
				printf("No failed_arp_listItem");
				goto end;
			}
			list_add(failed_arp_listList, failed_arp_listItem);
		}
	}

	released_ebi_list = cJSON_GetObjectItemCaseSensitive(
		assigned_ebi_dataJSON, "releasedEbiList");
	if(released_ebi_list) {
		cJSON *released_ebi_list_local = NULL;
		if(!cJSON_IsArray(released_ebi_list)) {
			printf(
				"assigned_ebi_data_parseFromJSON() failed [released_ebi_list]");
			goto end;
		}

		released_ebi_listList = list_create();

		cJSON_ArrayForEach(released_ebi_list_local, released_ebi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(released_ebi_list_local)) {
				printf(
					"assigned_ebi_data_parseFromJSON() failed [released_ebi_list]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"assigned_ebi_data_parseFromJSON() failed [released_ebi_list]");
				goto end;
			}
			*localDouble = released_ebi_list_local->valuedouble;
			list_add(released_ebi_listList, localDouble);
		}
	}

	modified_ebi_list = cJSON_GetObjectItemCaseSensitive(
		assigned_ebi_dataJSON, "modifiedEbiList");
	if(modified_ebi_list) {
		cJSON *modified_ebi_list_local = NULL;
		if(!cJSON_IsArray(modified_ebi_list)) {
			printf(
				"assigned_ebi_data_parseFromJSON() failed [modified_ebi_list]");
			goto end;
		}

		modified_ebi_listList = list_create();

		cJSON_ArrayForEach(modified_ebi_list_local, modified_ebi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(modified_ebi_list_local)) {
				printf(
					"assigned_ebi_data_parseFromJSON() failed [modified_ebi_list]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"assigned_ebi_data_parseFromJSON() failed [modified_ebi_list]");
				goto end;
			}
			*localDouble = modified_ebi_list_local->valuedouble;
			list_add(modified_ebi_listList, localDouble);
		}
	}

	assigned_ebi_data_local_var = assigned_ebi_data_create(

		pdu_session_id->valuedouble,
		assigned_ebi_listList,
		failed_arp_list ? failed_arp_listList : NULL,
		released_ebi_list ? released_ebi_listList : NULL,
		modified_ebi_list ? modified_ebi_listList : NULL
		);

	return assigned_ebi_data_local_var;
end:
	if(assigned_ebi_listList) {
		list_for_each(assigned_ebi_listList, node) {
			ebi_arp_mapping_free(node->data);
		}
		list_free(assigned_ebi_listList);
		assigned_ebi_listList = NULL;
	}
	if(failed_arp_listList) {
		list_for_each(failed_arp_listList, node) {
			arp_free(node->data);
		}
		list_free(failed_arp_listList);
		failed_arp_listList = NULL;
	}
	if(released_ebi_listList) {
		list_for_each(released_ebi_listList, node) {
			free(node->data);
		}
		list_free(released_ebi_listList);
		released_ebi_listList = NULL;
	}
	if(modified_ebi_listList) {
		list_for_each(modified_ebi_listList, node) {
			free(node->data);
		}
		list_free(modified_ebi_listList);
		modified_ebi_listList = NULL;
	}
	return NULL;
}

assigned_ebi_data_t *assigned_ebi_data_copy(assigned_ebi_data_t *dst,
                                            assigned_ebi_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = assigned_ebi_data_convertToJSON(src);
	if(!item) {
		printf("assigned_ebi_data_convertToJSON() failed");
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

	assigned_ebi_data_free(dst);
	dst = assigned_ebi_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
