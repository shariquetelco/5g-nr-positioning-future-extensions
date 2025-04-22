#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "assign_ebi_failed.h"

assign_ebi_failed_t *assign_ebi_failed_create(int	pdu_session_id,
                                              list_t	*failed_arp_list) {
	assign_ebi_failed_t *assign_ebi_failed_local_var =
		malloc(sizeof(assign_ebi_failed_t));

	assign_ebi_failed_local_var->pdu_session_id = pdu_session_id;
	assign_ebi_failed_local_var->failed_arp_list = failed_arp_list;

	return assign_ebi_failed_local_var;
}

void assign_ebi_failed_free(assign_ebi_failed_t *assign_ebi_failed) {
	lnode_t *node = NULL;

	if(NULL == assign_ebi_failed) {
		return;
	}
	if(assign_ebi_failed->failed_arp_list) {
		list_for_each(assign_ebi_failed->failed_arp_list, node) {
			arp_free(node->data);
		}
		list_free(assign_ebi_failed->failed_arp_list);
		assign_ebi_failed->failed_arp_list = NULL;
	}
	free(assign_ebi_failed);
}

cJSON *assign_ebi_failed_convertToJSON(assign_ebi_failed_t *assign_ebi_failed) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(assign_ebi_failed == NULL) {
		printf(
			"assign_ebi_failed_convertToJSON() failed [AssignEbiFailed]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "pduSessionId",
	                           assign_ebi_failed->pdu_session_id) == NULL)
	{
		printf(
			"assign_ebi_failed_convertToJSON() failed [pdu_session_id]");
		goto end;
	}

	if(assign_ebi_failed->failed_arp_list) {
		cJSON *failed_arp_listList = cJSON_AddArrayToObject(item,
		                                                    "failedArpList");
		if(failed_arp_listList == NULL) {
			printf(
				"assign_ebi_failed_convertToJSON() failed [failed_arp_list]");
			goto end;
		}
		list_for_each(assign_ebi_failed->failed_arp_list, node) {
			cJSON *itemLocal = arp_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"assign_ebi_failed_convertToJSON() failed [failed_arp_list]");
				goto end;
			}
			cJSON_AddItemToArray(failed_arp_listList, itemLocal);
		}
	}

end:
	return item;
}

assign_ebi_failed_t *assign_ebi_failed_parseFromJSON(
	cJSON *assign_ebi_failedJSON) {
	assign_ebi_failed_t *assign_ebi_failed_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pdu_session_id = NULL;
	cJSON *failed_arp_list = NULL;
	list_t *failed_arp_listList = NULL;
	pdu_session_id = cJSON_GetObjectItemCaseSensitive(assign_ebi_failedJSON,
	                                                  "pduSessionId");
	if(!pdu_session_id) {
		printf(
			"assign_ebi_failed_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}
	if(!cJSON_IsNumber(pdu_session_id)) {
		printf(
			"assign_ebi_failed_parseFromJSON() failed [pdu_session_id]");
		goto end;
	}

	failed_arp_list = cJSON_GetObjectItemCaseSensitive(
		assign_ebi_failedJSON, "failedArpList");
	if(failed_arp_list) {
		cJSON *failed_arp_list_local = NULL;
		if(!cJSON_IsArray(failed_arp_list)) {
			printf(
				"assign_ebi_failed_parseFromJSON() failed [failed_arp_list]");
			goto end;
		}

		failed_arp_listList = list_create();

		cJSON_ArrayForEach(failed_arp_list_local, failed_arp_list) {
			if(!cJSON_IsObject(failed_arp_list_local)) {
				printf(
					"assign_ebi_failed_parseFromJSON() failed [failed_arp_list]");
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

	assign_ebi_failed_local_var = assign_ebi_failed_create(

		pdu_session_id->valuedouble,
		failed_arp_list ? failed_arp_listList : NULL
		);

	return assign_ebi_failed_local_var;
end:
	if(failed_arp_listList) {
		list_for_each(failed_arp_listList, node) {
			arp_free(node->data);
		}
		list_free(failed_arp_listList);
		failed_arp_listList = NULL;
	}
	return NULL;
}

assign_ebi_failed_t *assign_ebi_failed_copy(assign_ebi_failed_t *dst,
                                            assign_ebi_failed_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = assign_ebi_failed_convertToJSON(src);
	if(!item) {
		printf("assign_ebi_failed_convertToJSON() failed");
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

	assign_ebi_failed_free(dst);
	dst = assign_ebi_failed_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
