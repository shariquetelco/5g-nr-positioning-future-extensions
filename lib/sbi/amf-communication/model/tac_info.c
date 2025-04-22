#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tac_info.h"

tac_info_t *tac_info_create(list_t *tac_list) {
	tac_info_t *tac_info_local_var = malloc(sizeof(tac_info_t));

	tac_info_local_var->tac_list = tac_list;

	return tac_info_local_var;
}

void tac_info_free(tac_info_t *tac_info) {
	lnode_t *node = NULL;

	if(NULL == tac_info) {
		return;
	}
	if(tac_info->tac_list) {
		list_for_each(tac_info->tac_list, node) {
			free(node->data);
		}
		list_free(tac_info->tac_list);
		tac_info->tac_list = NULL;
	}
	free(tac_info);
}

cJSON *tac_info_convertToJSON(tac_info_t *tac_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(tac_info == NULL) {
		printf("tac_info_convertToJSON() failed [TacInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!tac_info->tac_list) {
		printf("tac_info_convertToJSON() failed [tac_list]");
		return NULL;
	}
	cJSON *tac_listList = cJSON_AddArrayToObject(item, "tacList");
	if(tac_listList == NULL) {
		printf("tac_info_convertToJSON() failed [tac_list]");
		goto end;
	}
	list_for_each(tac_info->tac_list, node) {
		if(cJSON_AddStringToObject(tac_listList, "",
		                           (char *) node->data) == NULL)
		{
			printf("tac_info_convertToJSON() failed [tac_list]");
			goto end;
		}
	}

end:
	return item;
}

tac_info_t *tac_info_parseFromJSON(cJSON *tac_infoJSON) {
	tac_info_t *tac_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *tac_list = NULL;
	list_t *tac_listList = NULL;
	tac_list = cJSON_GetObjectItemCaseSensitive(tac_infoJSON, "tacList");
	if(!tac_list) {
		printf("tac_info_parseFromJSON() failed [tac_list]");
		goto end;
	}
	cJSON *tac_list_local = NULL;
	if(!cJSON_IsArray(tac_list)) {
		printf("tac_info_parseFromJSON() failed [tac_list]");
		goto end;
	}

	tac_listList = list_create();

	cJSON_ArrayForEach(tac_list_local, tac_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsString(tac_list_local)) {
			printf("tac_info_parseFromJSON() failed [tac_list]");
			goto end;
		}
		list_add(tac_listList, strdup(tac_list_local->valuestring));
	}

	tac_info_local_var = tac_info_create(
		tac_listList
		);

	return tac_info_local_var;
end:
	if(tac_listList) {
		list_for_each(tac_listList, node) {
			free(node->data);
		}
		list_free(tac_listList);
		tac_listList = NULL;
	}
	return NULL;
}

tac_info_t *tac_info_copy(tac_info_t *dst, tac_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = tac_info_convertToJSON(src);
	if(!item) {
		printf("tac_info_convertToJSON() failed");
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

	tac_info_free(dst);
	dst = tac_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
