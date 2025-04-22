#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "no_profile_match_info.h"

no_profile_match_info_t *no_profile_match_info_create(
	no_profile_match_reason_t	*reason,
	list_t				*query_param_combination_list) {
	no_profile_match_info_t *no_profile_match_info_local_var = malloc(
		sizeof(no_profile_match_info_t));

	no_profile_match_info_local_var->reason = reason;
	no_profile_match_info_local_var->query_param_combination_list =
		query_param_combination_list;

	return no_profile_match_info_local_var;
}

void no_profile_match_info_free(no_profile_match_info_t *no_profile_match_info)
{
	lnode_t *node = NULL;

	if(NULL == no_profile_match_info) {
		return;
	}
	if(no_profile_match_info->reason) {
		no_profile_match_reason_free(no_profile_match_info->reason);
		no_profile_match_info->reason = NULL;
	}
	if(no_profile_match_info->query_param_combination_list) {
		list_for_each(
			no_profile_match_info->query_param_combination_list,
			node) {
			query_param_combination_free(node->data);
		}
		list_free(no_profile_match_info->query_param_combination_list);
		no_profile_match_info->query_param_combination_list = NULL;
	}
	free(no_profile_match_info);
}

cJSON *no_profile_match_info_convertToJSON(
	no_profile_match_info_t *no_profile_match_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(no_profile_match_info == NULL) {
		printf(
			"no_profile_match_info_convertToJSON() failed [NoProfileMatchInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!no_profile_match_info->reason) {
		printf("no_profile_match_info_convertToJSON() failed [reason]");
		return NULL;
	}
	cJSON *reason_local_JSON = no_profile_match_reason_convertToJSON(
		no_profile_match_info->reason);
	if(reason_local_JSON == NULL) {
		printf("no_profile_match_info_convertToJSON() failed [reason]");
		goto end;
	}
	cJSON_AddItemToObject(item, "reason", reason_local_JSON);
	if(item->child == NULL) {
		printf("no_profile_match_info_convertToJSON() failed [reason]");
		goto end;
	}

	if(no_profile_match_info->query_param_combination_list) {
		cJSON *query_param_combination_listList =
			cJSON_AddArrayToObject(item,
			                       "queryParamCombinationList");
		if(query_param_combination_listList == NULL) {
			printf(
				"no_profile_match_info_convertToJSON() failed [query_param_combination_list]");
			goto end;
		}
		list_for_each(
			no_profile_match_info->query_param_combination_list,
			node) {
			cJSON *itemLocal =
				query_param_combination_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"no_profile_match_info_convertToJSON() failed [query_param_combination_list]");
				goto end;
			}
			cJSON_AddItemToArray(query_param_combination_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

no_profile_match_info_t *no_profile_match_info_parseFromJSON(
	cJSON *no_profile_match_infoJSON) {
	no_profile_match_info_t *no_profile_match_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *reason = NULL;
	no_profile_match_reason_t *reason_local_nonprim = NULL;
	cJSON *query_param_combination_list = NULL;
	list_t *query_param_combination_listList = NULL;
	reason = cJSON_GetObjectItemCaseSensitive(no_profile_match_infoJSON,
	                                          "reason");
	if(!reason) {
		printf("no_profile_match_info_parseFromJSON() failed [reason]");
		goto end;
	}
	reason_local_nonprim = no_profile_match_reason_parseFromJSON(reason);
	if(!reason_local_nonprim) {
		printf("no_profile_match_reason_parseFromJSON failed [reason]");
		goto end;
	}

	query_param_combination_list = cJSON_GetObjectItemCaseSensitive(
		no_profile_match_infoJSON, "queryParamCombinationList");
	if(query_param_combination_list) {
		cJSON *query_param_combination_list_local = NULL;
		if(!cJSON_IsArray(query_param_combination_list)) {
			printf(
				"no_profile_match_info_parseFromJSON() failed [query_param_combination_list]");
			goto end;
		}

		query_param_combination_listList = list_create();

		cJSON_ArrayForEach(query_param_combination_list_local,
		                   query_param_combination_list) {
			if(!cJSON_IsObject(query_param_combination_list_local))
			{
				printf(
					"no_profile_match_info_parseFromJSON() failed [query_param_combination_list]");
				goto end;
			}
			query_param_combination_t *
			        query_param_combination_listItem =
				query_param_combination_parseFromJSON(
					query_param_combination_list_local);
			if(!query_param_combination_listItem) {
				printf("No query_param_combination_listItem");
				goto end;
			}
			list_add(query_param_combination_listList,
			         query_param_combination_listItem);
		}
	}

	no_profile_match_info_local_var = no_profile_match_info_create(
		reason_local_nonprim,
		query_param_combination_list ? query_param_combination_listList : NULL
		);

	return no_profile_match_info_local_var;
end:
	if(reason_local_nonprim) {
		no_profile_match_reason_free(reason_local_nonprim);
		reason_local_nonprim = NULL;
	}
	if(query_param_combination_listList) {
		list_for_each(query_param_combination_listList, node) {
			query_param_combination_free(node->data);
		}
		list_free(query_param_combination_listList);
		query_param_combination_listList = NULL;
	}
	return NULL;
}

no_profile_match_info_t *no_profile_match_info_copy(
	no_profile_match_info_t *dst, no_profile_match_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = no_profile_match_info_convertToJSON(src);
	if(!item) {
		printf("no_profile_match_info_convertToJSON() failed");
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

	no_profile_match_info_free(dst);
	dst = no_profile_match_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
