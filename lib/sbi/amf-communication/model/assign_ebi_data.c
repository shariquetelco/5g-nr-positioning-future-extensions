#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assign_ebi_data.h"

assign_ebi_data_t *assign_ebi_data_create(int pdu_session_id, list_t *arp_list,
                                          list_t *released_ebi_list,
                                          guami_t *old_guami,
                                          list_t *modified_ebi_list) {
	assign_ebi_data_t *assign_ebi_data_local_var =
		malloc(sizeof(assign_ebi_data_t));

	assign_ebi_data_local_var->pdu_session_id = pdu_session_id;
	assign_ebi_data_local_var->arp_list = arp_list;
	assign_ebi_data_local_var->released_ebi_list = released_ebi_list;
	assign_ebi_data_local_var->old_guami = old_guami;
	assign_ebi_data_local_var->modified_ebi_list = modified_ebi_list;

	return assign_ebi_data_local_var;
}

void assign_ebi_data_free(assign_ebi_data_t *assign_ebi_data) {
	lnode_t *node = NULL;

	if(NULL == assign_ebi_data) {
		return;
	}
	if(assign_ebi_data->arp_list) {
		list_for_each(assign_ebi_data->arp_list, node) {
			arp_free(node->data);
		}
		list_free(assign_ebi_data->arp_list);
		assign_ebi_data->arp_list = NULL;
	}
	if(assign_ebi_data->released_ebi_list) {
		list_for_each(assign_ebi_data->released_ebi_list, node) {
			free(node->data);
		}
		list_free(assign_ebi_data->released_ebi_list);
		assign_ebi_data->released_ebi_list = NULL;
	}
	if(assign_ebi_data->old_guami) {
		guami_free(assign_ebi_data->old_guami);
		assign_ebi_data->old_guami = NULL;
	}
	if(assign_ebi_data->modified_ebi_list) {
		list_for_each(assign_ebi_data->modified_ebi_list, node) {
			ebi_arp_mapping_free(node->data);
		}
		list_free(assign_ebi_data->modified_ebi_list);
		assign_ebi_data->modified_ebi_list = NULL;
	}
	free(assign_ebi_data);
}

cJSON *assign_ebi_data_convertToJSON(assign_ebi_data_t *assign_ebi_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(assign_ebi_data == NULL) {
		printf("assign_ebi_data_convertToJSON() failed [AssignEbiData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "pduSessionId",
	                           assign_ebi_data->pdu_session_id) == NULL)
	{
		printf("assign_ebi_data_convertToJSON() failed [pdu_session_id]");
		goto end;
	}

	if(assign_ebi_data->arp_list) {
		cJSON *arp_listList = cJSON_AddArrayToObject(item, "arpList");
		if(arp_listList == NULL) {
			printf(
				"assign_ebi_data_convertToJSON() failed [arp_list]");
			goto end;
		}
		list_for_each(assign_ebi_data->arp_list, node) {
			cJSON *itemLocal = arp_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"assign_ebi_data_convertToJSON() failed [arp_list]");
				goto end;
			}
			cJSON_AddItemToArray(arp_listList, itemLocal);
		}
	}

	if(assign_ebi_data->released_ebi_list) {
		cJSON *released_ebi_listList = cJSON_AddArrayToObject(item,
		                                                      "releasedEbiList");
		if(released_ebi_listList == NULL) {
			printf(
				"assign_ebi_data_convertToJSON() failed [released_ebi_list]");
			goto end;
		}
		list_for_each(assign_ebi_data->released_ebi_list, node) {
			if(node->data == NULL) {
				printf(
					"assign_ebi_data_convertToJSON() failed [released_ebi_list]");
				goto end;
			}
			if(cJSON_AddNumberToObject(released_ebi_listList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"assign_ebi_data_convertToJSON() failed [released_ebi_list]");
				goto end;
			}
		}
	}

	if(assign_ebi_data->old_guami) {
		cJSON *old_guami_local_JSON = guami_convertToJSON(
			assign_ebi_data->old_guami);
		if(old_guami_local_JSON == NULL) {
			printf(
				"assign_ebi_data_convertToJSON() failed [old_guami]");
			goto end;
		}
		cJSON_AddItemToObject(item, "oldGuami", old_guami_local_JSON);
		if(item->child == NULL) {
			printf(
				"assign_ebi_data_convertToJSON() failed [old_guami]");
			goto end;
		}
	}

	if(assign_ebi_data->modified_ebi_list) {
		cJSON *modified_ebi_listList = cJSON_AddArrayToObject(item,
		                                                      "modifiedEbiList");
		if(modified_ebi_listList == NULL) {
			printf(
				"assign_ebi_data_convertToJSON() failed [modified_ebi_list]");
			goto end;
		}
		list_for_each(assign_ebi_data->modified_ebi_list, node) {
			cJSON *itemLocal = ebi_arp_mapping_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"assign_ebi_data_convertToJSON() failed [modified_ebi_list]");
				goto end;
			}
			cJSON_AddItemToArray(modified_ebi_listList, itemLocal);
		}
	}

end:
	return item;
}

assign_ebi_data_t *assign_ebi_data_parseFromJSON(cJSON *assign_ebi_dataJSON) {
	assign_ebi_data_t *assign_ebi_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pdu_session_id = NULL;
	cJSON *arp_list = NULL;
	list_t *arp_listList = NULL;
	cJSON *released_ebi_list = NULL;
	list_t *released_ebi_listList = NULL;
	cJSON *old_guami = NULL;
	guami_t *old_guami_local_nonprim = NULL;
	cJSON *modified_ebi_list = NULL;
	list_t *modified_ebi_listList = NULL;
	pdu_session_id = cJSON_GetObjectItemCaseSensitive(assign_ebi_dataJSON,
	                                                  "pduSessionId");
	if(!pdu_session_id) {
		printf("assign_ebi_data_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}
	if(!cJSON_IsNumber(pdu_session_id)) {
		printf("assign_ebi_data_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}

	arp_list = cJSON_GetObjectItemCaseSensitive(assign_ebi_dataJSON,
	                                            "arpList");
	if(arp_list) {
		cJSON *arp_list_local = NULL;
		if(!cJSON_IsArray(arp_list)) {
			printf(
				"assign_ebi_data_parseFromJSON() failed [arp_list]");
			goto end;
		}

		arp_listList = list_create();

		cJSON_ArrayForEach(arp_list_local, arp_list) {
			if(!cJSON_IsObject(arp_list_local)) {
				printf(
					"assign_ebi_data_parseFromJSON() failed [arp_list]");
				goto end;
			}
			arp_t *arp_listItem = arp_parseFromJSON(arp_list_local);
			if(!arp_listItem) {
				printf("No arp_listItem");
				goto end;
			}
			list_add(arp_listList, arp_listItem);
		}
	}

	released_ebi_list = cJSON_GetObjectItemCaseSensitive(
		assign_ebi_dataJSON, "releasedEbiList");
	if(released_ebi_list) {
		cJSON *released_ebi_list_local = NULL;
		if(!cJSON_IsArray(released_ebi_list)) {
			printf(
				"assign_ebi_data_parseFromJSON() failed [released_ebi_list]");
			goto end;
		}

		released_ebi_listList = list_create();

		cJSON_ArrayForEach(released_ebi_list_local, released_ebi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(released_ebi_list_local)) {
				printf(
					"assign_ebi_data_parseFromJSON() failed [released_ebi_list]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"assign_ebi_data_parseFromJSON() failed [released_ebi_list]");
				goto end;
			}
			*localDouble = released_ebi_list_local->valuedouble;
			list_add(released_ebi_listList, localDouble);
		}
	}

	old_guami = cJSON_GetObjectItemCaseSensitive(assign_ebi_dataJSON,
	                                             "oldGuami");
	if(old_guami) {
		old_guami_local_nonprim = guami_parseFromJSON(old_guami);
		if(!old_guami_local_nonprim) {
			printf("guami_parseFromJSON failed [old_guami]");
			goto end;
		}
	}

	modified_ebi_list = cJSON_GetObjectItemCaseSensitive(
		assign_ebi_dataJSON, "modifiedEbiList");
	if(modified_ebi_list) {
		cJSON *modified_ebi_list_local = NULL;
		if(!cJSON_IsArray(modified_ebi_list)) {
			printf(
				"assign_ebi_data_parseFromJSON() failed [modified_ebi_list]");
			goto end;
		}

		modified_ebi_listList = list_create();

		cJSON_ArrayForEach(modified_ebi_list_local, modified_ebi_list) {
			if(!cJSON_IsObject(modified_ebi_list_local)) {
				printf(
					"assign_ebi_data_parseFromJSON() failed [modified_ebi_list]");
				goto end;
			}
			ebi_arp_mapping_t *modified_ebi_listItem =
				ebi_arp_mapping_parseFromJSON(
					modified_ebi_list_local);
			if(!modified_ebi_listItem) {
				printf("No modified_ebi_listItem");
				goto end;
			}
			list_add(modified_ebi_listList, modified_ebi_listItem);
		}
	}

	assign_ebi_data_local_var = assign_ebi_data_create(

		pdu_session_id->valuedouble,
		arp_list ? arp_listList : NULL,
		released_ebi_list ? released_ebi_listList : NULL,
		old_guami ? old_guami_local_nonprim : NULL,
		modified_ebi_list ? modified_ebi_listList : NULL
		);

	return assign_ebi_data_local_var;
end:
	if(arp_listList) {
		list_for_each(arp_listList, node) {
			arp_free(node->data);
		}
		list_free(arp_listList);
		arp_listList = NULL;
	}
	if(released_ebi_listList) {
		list_for_each(released_ebi_listList, node) {
			free(node->data);
		}
		list_free(released_ebi_listList);
		released_ebi_listList = NULL;
	}
	if(old_guami_local_nonprim) {
		guami_free(old_guami_local_nonprim);
		old_guami_local_nonprim = NULL;
	}
	if(modified_ebi_listList) {
		list_for_each(modified_ebi_listList, node) {
			ebi_arp_mapping_free(node->data);
		}
		list_free(modified_ebi_listList);
		modified_ebi_listList = NULL;
	}
	return NULL;
}

assign_ebi_data_t *assign_ebi_data_copy(assign_ebi_data_t	*dst,
                                        assign_ebi_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = assign_ebi_data_convertToJSON(src);
	if(!item) {
		printf("assign_ebi_data_convertToJSON() failed");
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

	assign_ebi_data_free(dst);
	dst = assign_ebi_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
