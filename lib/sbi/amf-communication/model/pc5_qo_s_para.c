#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pc5_qo_s_para.h"

pc5_qo_s_para_t *pc5_qo_s_para_create(list_t	*pc5_qos_flow_list,
                                      char	*pc5_link_ambr) {
	pc5_qo_s_para_t *pc5_qo_s_para_local_var = malloc(
		sizeof(pc5_qo_s_para_t));

	pc5_qo_s_para_local_var->pc5_qos_flow_list = pc5_qos_flow_list;
	pc5_qo_s_para_local_var->pc5_link_ambr = pc5_link_ambr;

	return pc5_qo_s_para_local_var;
}

void pc5_qo_s_para_free(pc5_qo_s_para_t *pc5_qo_s_para) {
	lnode_t *node = NULL;

	if(NULL == pc5_qo_s_para) {
		return;
	}
	if(pc5_qo_s_para->pc5_qos_flow_list) {
		list_for_each(pc5_qo_s_para->pc5_qos_flow_list, node) {
			pc5_qos_flow_item_free(node->data);
		}
		list_free(pc5_qo_s_para->pc5_qos_flow_list);
		pc5_qo_s_para->pc5_qos_flow_list = NULL;
	}
	if(pc5_qo_s_para->pc5_link_ambr) {
		free(pc5_qo_s_para->pc5_link_ambr);
		pc5_qo_s_para->pc5_link_ambr = NULL;
	}
	free(pc5_qo_s_para);
}

cJSON *pc5_qo_s_para_convertToJSON(pc5_qo_s_para_t *pc5_qo_s_para) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pc5_qo_s_para == NULL) {
		printf("pc5_qo_s_para_convertToJSON() failed [Pc5QoSPara]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!pc5_qo_s_para->pc5_qos_flow_list) {
		printf(
			"pc5_qo_s_para_convertToJSON() failed [pc5_qos_flow_list]");
		return NULL;
	}
	cJSON *pc5_qos_flow_listList = cJSON_AddArrayToObject(item,
	                                                      "pc5QosFlowList");
	if(pc5_qos_flow_listList == NULL) {
		printf(
			"pc5_qo_s_para_convertToJSON() failed [pc5_qos_flow_list]");
		goto end;
	}
	list_for_each(pc5_qo_s_para->pc5_qos_flow_list, node) {
		cJSON *itemLocal = pc5_qos_flow_item_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"pc5_qo_s_para_convertToJSON() failed [pc5_qos_flow_list]");
			goto end;
		}
		cJSON_AddItemToArray(pc5_qos_flow_listList, itemLocal);
	}

	if(pc5_qo_s_para->pc5_link_ambr) {
		if(cJSON_AddStringToObject(item, "pc5LinkAmbr",
		                           pc5_qo_s_para->pc5_link_ambr) ==
		   NULL)
		{
			printf(
				"pc5_qo_s_para_convertToJSON() failed [pc5_link_ambr]");
			goto end;
		}
	}

end:
	return item;
}

pc5_qo_s_para_t *pc5_qo_s_para_parseFromJSON(cJSON *pc5_qo_s_paraJSON) {
	pc5_qo_s_para_t *pc5_qo_s_para_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pc5_qos_flow_list = NULL;
	list_t *pc5_qos_flow_listList = NULL;
	cJSON *pc5_link_ambr = NULL;
	pc5_qos_flow_list = cJSON_GetObjectItemCaseSensitive(pc5_qo_s_paraJSON,
	                                                     "pc5QosFlowList");
	if(!pc5_qos_flow_list) {
		printf(
			"pc5_qo_s_para_parseFromJSON() failed [pc5_qos_flow_list]");
		goto end;
	}
	cJSON *pc5_qos_flow_list_local = NULL;
	if(!cJSON_IsArray(pc5_qos_flow_list)) {
		printf(
			"pc5_qo_s_para_parseFromJSON() failed [pc5_qos_flow_list]");
		goto end;
	}

	pc5_qos_flow_listList = list_create();

	cJSON_ArrayForEach(pc5_qos_flow_list_local, pc5_qos_flow_list) {
		if(!cJSON_IsObject(pc5_qos_flow_list_local)) {
			printf(
				"pc5_qo_s_para_parseFromJSON() failed [pc5_qos_flow_list]");
			goto end;
		}
		pc5_qos_flow_item_t *pc5_qos_flow_listItem =
			pc5_qos_flow_item_parseFromJSON(pc5_qos_flow_list_local);
		if(!pc5_qos_flow_listItem) {
			printf("No pc5_qos_flow_listItem");
			goto end;
		}
		list_add(pc5_qos_flow_listList, pc5_qos_flow_listItem);
	}

	pc5_link_ambr = cJSON_GetObjectItemCaseSensitive(pc5_qo_s_paraJSON,
	                                                 "pc5LinkAmbr");
	if(pc5_link_ambr) {
		if(!cJSON_IsString(pc5_link_ambr) &&
		   !cJSON_IsNull(pc5_link_ambr))
		{
			printf(
				"pc5_qo_s_para_parseFromJSON() failed [pc5_link_ambr]");
			goto end;
		}
	}

	pc5_qo_s_para_local_var = pc5_qo_s_para_create(
		pc5_qos_flow_listList,
		pc5_link_ambr &&
		!cJSON_IsNull(pc5_link_ambr) ? strdup(
			pc5_link_ambr->valuestring) : NULL
		);

	return pc5_qo_s_para_local_var;
end:
	if(pc5_qos_flow_listList) {
		list_for_each(pc5_qos_flow_listList, node) {
			pc5_qos_flow_item_free(node->data);
		}
		list_free(pc5_qos_flow_listList);
		pc5_qos_flow_listList = NULL;
	}
	return NULL;
}

pc5_qo_s_para_t *pc5_qo_s_para_copy(pc5_qo_s_para_t	*dst,
                                    pc5_qo_s_para_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pc5_qo_s_para_convertToJSON(src);
	if(!item) {
		printf("pc5_qo_s_para_convertToJSON() failed");
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

	pc5_qo_s_para_free(dst);
	dst = pc5_qo_s_para_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
