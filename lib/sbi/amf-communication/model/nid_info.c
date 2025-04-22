#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nid_info.h"

nid_info_t *nid_info_create(list_t *nid_list) {
	nid_info_t *nid_info_local_var = malloc(sizeof(nid_info_t));

	nid_info_local_var->nid_list = nid_list;

	return nid_info_local_var;
}

void nid_info_free(nid_info_t *nid_info) {
	lnode_t *node = NULL;

	if(NULL == nid_info) {
		return;
	}
	if(nid_info->nid_list) {
		list_for_each(nid_info->nid_list, node) {
			free(node->data);
		}
		list_free(nid_info->nid_list);
		nid_info->nid_list = NULL;
	}
	free(nid_info);
}

cJSON *nid_info_convertToJSON(nid_info_t *nid_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nid_info == NULL) {
		printf("nid_info_convertToJSON() failed [NidInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nid_info->nid_list) {
		printf("nid_info_convertToJSON() failed [nid_list]");
		return NULL;
	}
	cJSON *nid_listList = cJSON_AddArrayToObject(item, "nidList");
	if(nid_listList == NULL) {
		printf("nid_info_convertToJSON() failed [nid_list]");
		goto end;
	}
	list_for_each(nid_info->nid_list, node) {
		if(cJSON_AddStringToObject(nid_listList, "",
		                           (char *) node->data) == NULL)
		{
			printf("nid_info_convertToJSON() failed [nid_list]");
			goto end;
		}
	}

end:
	return item;
}

nid_info_t *nid_info_parseFromJSON(cJSON *nid_infoJSON) {
	nid_info_t *nid_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *nid_list = NULL;
	list_t *nid_listList = NULL;
	nid_list = cJSON_GetObjectItemCaseSensitive(nid_infoJSON, "nidList");
	if(!nid_list) {
		printf("nid_info_parseFromJSON() failed [nid_list]");
		goto end;
	}
	cJSON *nid_list_local = NULL;
	if(!cJSON_IsArray(nid_list)) {
		printf("nid_info_parseFromJSON() failed [nid_list]");
		goto end;
	}

	nid_listList = list_create();

	cJSON_ArrayForEach(nid_list_local, nid_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsString(nid_list_local)) {
			printf("nid_info_parseFromJSON() failed [nid_list]");
			goto end;
		}
		list_add(nid_listList, strdup(nid_list_local->valuestring));
	}

	nid_info_local_var = nid_info_create(
		nid_listList
		);

	return nid_info_local_var;
end:
	if(nid_listList) {
		list_for_each(nid_listList, node) {
			free(node->data);
		}
		list_free(nid_listList);
		nid_listList = NULL;
	}
	return NULL;
}

nid_info_t *nid_info_copy(nid_info_t *dst, nid_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nid_info_convertToJSON(src);
	if(!item) {
		printf("nid_info_convertToJSON() failed");
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

	nid_info_free(dst);
	dst = nid_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
