#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cag_info_1.h"

cag_info_1_t *cag_info_1_create(list_t *cag_list) {
	cag_info_1_t *cag_info_1_local_var = malloc(sizeof(cag_info_1_t));

	cag_info_1_local_var->cag_list = cag_list;

	return cag_info_1_local_var;
}

void cag_info_1_free(cag_info_1_t *cag_info_1) {
	lnode_t *node = NULL;

	if(NULL == cag_info_1) {
		return;
	}
	if(cag_info_1->cag_list) {
		list_for_each(cag_info_1->cag_list, node) {
			free(node->data);
		}
		list_free(cag_info_1->cag_list);
		cag_info_1->cag_list = NULL;
	}
	free(cag_info_1);
}

cJSON *cag_info_1_convertToJSON(cag_info_1_t *cag_info_1) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cag_info_1 == NULL) {
		printf("cag_info_1_convertToJSON() failed [CagInfo_1]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!cag_info_1->cag_list) {
		printf("cag_info_1_convertToJSON() failed [cag_list]");
		return NULL;
	}
	cJSON *cag_listList = cJSON_AddArrayToObject(item, "cagList");
	if(cag_listList == NULL) {
		printf("cag_info_1_convertToJSON() failed [cag_list]");
		goto end;
	}
	list_for_each(cag_info_1->cag_list, node) {
		if(cJSON_AddStringToObject(cag_listList, "",
		                           (char *) node->data) == NULL)
		{
			printf("cag_info_1_convertToJSON() failed [cag_list]");
			goto end;
		}
	}

end:
	return item;
}

cag_info_1_t *cag_info_1_parseFromJSON(cJSON *cag_info_1JSON) {
	cag_info_1_t *cag_info_1_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cag_list = NULL;
	list_t *cag_listList = NULL;
	cag_list = cJSON_GetObjectItemCaseSensitive(cag_info_1JSON, "cagList");
	if(!cag_list) {
		printf("cag_info_1_parseFromJSON() failed [cag_list]");
		goto end;
	}
	cJSON *cag_list_local = NULL;
	if(!cJSON_IsArray(cag_list)) {
		printf("cag_info_1_parseFromJSON() failed [cag_list]");
		goto end;
	}

	cag_listList = list_create();

	cJSON_ArrayForEach(cag_list_local, cag_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsString(cag_list_local)) {
			printf("cag_info_1_parseFromJSON() failed [cag_list]");
			goto end;
		}
		list_add(cag_listList, strdup(cag_list_local->valuestring));
	}

	cag_info_1_local_var = cag_info_1_create(
		cag_listList
		);

	return cag_info_1_local_var;
end:
	if(cag_listList) {
		list_for_each(cag_listList, node) {
			free(node->data);
		}
		list_free(cag_listList);
		cag_listList = NULL;
	}
	return NULL;
}

cag_info_1_t *cag_info_1_copy(cag_info_1_t *dst, cag_info_1_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cag_info_1_convertToJSON(src);
	if(!item) {
		printf("cag_info_1_convertToJSON() failed");
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

	cag_info_1_free(dst);
	dst = cag_info_1_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
