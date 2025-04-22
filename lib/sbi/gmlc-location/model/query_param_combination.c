#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "query_param_combination.h"

query_param_combination_t *query_param_combination_create(list_t *query_params)
{
	query_param_combination_t *query_param_combination_local_var = malloc(
		sizeof(query_param_combination_t));

	query_param_combination_local_var->query_params = query_params;

	return query_param_combination_local_var;
}

void query_param_combination_free(
	query_param_combination_t *query_param_combination) {
	lnode_t *node = NULL;

	if(NULL == query_param_combination) {
		return;
	}
	if(query_param_combination->query_params) {
		list_for_each(query_param_combination->query_params, node) {
			query_parameter_free(node->data);
		}
		list_free(query_param_combination->query_params);
		query_param_combination->query_params = NULL;
	}
	free(query_param_combination);
}

cJSON *query_param_combination_convertToJSON(
	query_param_combination_t *query_param_combination) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(query_param_combination == NULL) {
		printf(
			"query_param_combination_convertToJSON() failed [QueryParamCombination]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!query_param_combination->query_params) {
		printf(
			"query_param_combination_convertToJSON() failed [query_params]");
		return NULL;
	}
	cJSON *query_paramsList = cJSON_AddArrayToObject(item, "queryParams");
	if(query_paramsList == NULL) {
		printf(
			"query_param_combination_convertToJSON() failed [query_params]");
		goto end;
	}
	list_for_each(query_param_combination->query_params, node) {
		cJSON *itemLocal = query_parameter_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"query_param_combination_convertToJSON() failed [query_params]");
			goto end;
		}
		cJSON_AddItemToArray(query_paramsList, itemLocal);
	}

end:
	return item;
}

query_param_combination_t *query_param_combination_parseFromJSON(
	cJSON *query_param_combinationJSON) {
	query_param_combination_t *query_param_combination_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *query_params = NULL;
	list_t *query_paramsList = NULL;
	query_params = cJSON_GetObjectItemCaseSensitive(
		query_param_combinationJSON, "queryParams");
	if(!query_params) {
		printf(
			"query_param_combination_parseFromJSON() failed [query_params]");
		goto end;
	}
	cJSON *query_params_local = NULL;
	if(!cJSON_IsArray(query_params)) {
		printf(
			"query_param_combination_parseFromJSON() failed [query_params]");
		goto end;
	}

	query_paramsList = list_create();

	cJSON_ArrayForEach(query_params_local, query_params) {
		if(!cJSON_IsObject(query_params_local)) {
			printf(
				"query_param_combination_parseFromJSON() failed [query_params]");
			goto end;
		}
		query_parameter_t *query_paramsItem =
			query_parameter_parseFromJSON(query_params_local);
		if(!query_paramsItem) {
			printf("No query_paramsItem");
			goto end;
		}
		list_add(query_paramsList, query_paramsItem);
	}

	query_param_combination_local_var = query_param_combination_create(
		query_paramsList
		);

	return query_param_combination_local_var;
end:
	if(query_paramsList) {
		list_for_each(query_paramsList, node) {
			query_parameter_free(node->data);
		}
		list_free(query_paramsList);
		query_paramsList = NULL;
	}
	return NULL;
}

query_param_combination_t *query_param_combination_copy(
	query_param_combination_t *dst, query_param_combination_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = query_param_combination_convertToJSON(src);
	if(!item) {
		printf("query_param_combination_convertToJSON() failed");
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

	query_param_combination_free(dst);
	dst = query_param_combination_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
