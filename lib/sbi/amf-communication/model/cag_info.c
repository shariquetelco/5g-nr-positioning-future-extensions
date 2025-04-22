#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cag_info.h"

cag_info_t *cag_info_create(list_t	*allowed_cag_list,
                            bool	is_cag_only_indicator,
                            int		cag_only_indicator) {
	cag_info_t *cag_info_local_var = malloc(sizeof(cag_info_t));

	cag_info_local_var->allowed_cag_list = allowed_cag_list;
	cag_info_local_var->is_cag_only_indicator = is_cag_only_indicator;
	cag_info_local_var->cag_only_indicator = cag_only_indicator;

	return cag_info_local_var;
}

void cag_info_free(cag_info_t *cag_info) {
	lnode_t *node = NULL;

	if(NULL == cag_info) {
		return;
	}
	if(cag_info->allowed_cag_list) {
		list_for_each(cag_info->allowed_cag_list, node) {
			free(node->data);
		}
		list_free(cag_info->allowed_cag_list);
		cag_info->allowed_cag_list = NULL;
	}
	free(cag_info);
}

cJSON *cag_info_convertToJSON(cag_info_t *cag_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cag_info == NULL) {
		printf("cag_info_convertToJSON() failed [CagInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!cag_info->allowed_cag_list) {
		printf("cag_info_convertToJSON() failed [allowed_cag_list]");
		return NULL;
	}
	cJSON *allowed_cag_listList = cJSON_AddArrayToObject(item,
	                                                     "allowedCagList");
	if(allowed_cag_listList == NULL) {
		printf("cag_info_convertToJSON() failed [allowed_cag_list]");
		goto end;
	}
	list_for_each(cag_info->allowed_cag_list, node) {
		if(cJSON_AddStringToObject(allowed_cag_listList, "",
		                           (char *) node->data) == NULL)
		{
			printf(
				"cag_info_convertToJSON() failed [allowed_cag_list]");
			goto end;
		}
	}

	if(cag_info->is_cag_only_indicator) {
		if(cJSON_AddBoolToObject(item, "cagOnlyIndicator",
		                         cag_info->cag_only_indicator) == NULL)
		{
			printf(
				"cag_info_convertToJSON() failed [cag_only_indicator]");
			goto end;
		}
	}

end:
	return item;
}

cag_info_t *cag_info_parseFromJSON(cJSON *cag_infoJSON) {
	cag_info_t *cag_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *allowed_cag_list = NULL;
	list_t *allowed_cag_listList = NULL;
	cJSON *cag_only_indicator = NULL;
	allowed_cag_list = cJSON_GetObjectItemCaseSensitive(cag_infoJSON,
	                                                    "allowedCagList");
	if(!allowed_cag_list) {
		printf("cag_info_parseFromJSON() failed [allowed_cag_list]");
		goto end;
	}
	cJSON *allowed_cag_list_local = NULL;
	if(!cJSON_IsArray(allowed_cag_list)) {
		printf("cag_info_parseFromJSON() failed [allowed_cag_list]");
		goto end;
	}

	allowed_cag_listList = list_create();

	cJSON_ArrayForEach(allowed_cag_list_local, allowed_cag_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsString(allowed_cag_list_local)) {
			printf(
				"cag_info_parseFromJSON() failed [allowed_cag_list]");
			goto end;
		}
		list_add(allowed_cag_listList,
		         strdup(allowed_cag_list_local->valuestring));
	}

	cag_only_indicator = cJSON_GetObjectItemCaseSensitive(cag_infoJSON,
	                                                      "cagOnlyIndicator");
	if(cag_only_indicator) {
		if(!cJSON_IsBool(cag_only_indicator)) {
			printf(
				"cag_info_parseFromJSON() failed [cag_only_indicator]");
			goto end;
		}
	}

	cag_info_local_var = cag_info_create(
		allowed_cag_listList,
		cag_only_indicator ? true : false,
		cag_only_indicator ? cag_only_indicator->valueint : 0
		);

	return cag_info_local_var;
end:
	if(allowed_cag_listList) {
		list_for_each(allowed_cag_listList, node) {
			free(node->data);
		}
		list_free(allowed_cag_listList);
		allowed_cag_listList = NULL;
	}
	return NULL;
}

cag_info_t *cag_info_copy(cag_info_t *dst, cag_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cag_info_convertToJSON(src);
	if(!item) {
		printf("cag_info_convertToJSON() failed");
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

	cag_info_free(dst);
	dst = cag_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
