#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "partially_allowed_snssai.h"

partially_allowed_snssai_t *partially_allowed_snssai_create(snssai_t	*snssai,
                                                            list_t	*allowed_tai_list)
{
	partially_allowed_snssai_t *partially_allowed_snssai_local_var = malloc(
		sizeof(partially_allowed_snssai_t));

	partially_allowed_snssai_local_var->snssai = snssai;
	partially_allowed_snssai_local_var->allowed_tai_list = allowed_tai_list;

	return partially_allowed_snssai_local_var;
}

void partially_allowed_snssai_free(
	partially_allowed_snssai_t *partially_allowed_snssai) {
	lnode_t *node = NULL;

	if(NULL == partially_allowed_snssai) {
		return;
	}
	if(partially_allowed_snssai->snssai) {
		snssai_free(partially_allowed_snssai->snssai);
		partially_allowed_snssai->snssai = NULL;
	}
	if(partially_allowed_snssai->allowed_tai_list) {
		list_for_each(partially_allowed_snssai->allowed_tai_list,
		              node) {
			tai_free(node->data);
		}
		list_free(partially_allowed_snssai->allowed_tai_list);
		partially_allowed_snssai->allowed_tai_list = NULL;
	}
	free(partially_allowed_snssai);
}

cJSON *partially_allowed_snssai_convertToJSON(
	partially_allowed_snssai_t *partially_allowed_snssai) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(partially_allowed_snssai == NULL) {
		printf(
			"partially_allowed_snssai_convertToJSON() failed [PartiallyAllowedSnssai]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!partially_allowed_snssai->snssai) {
		printf(
			"partially_allowed_snssai_convertToJSON() failed [snssai]");
		return NULL;
	}
	cJSON *snssai_local_JSON = snssai_convertToJSON(
		partially_allowed_snssai->snssai);
	if(snssai_local_JSON == NULL) {
		printf(
			"partially_allowed_snssai_convertToJSON() failed [snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
	if(item->child == NULL) {
		printf(
			"partially_allowed_snssai_convertToJSON() failed [snssai]");
		goto end;
	}

	if(!partially_allowed_snssai->allowed_tai_list) {
		printf(
			"partially_allowed_snssai_convertToJSON() failed [allowed_tai_list]");
		return NULL;
	}
	cJSON *allowed_tai_listList = cJSON_AddArrayToObject(item,
	                                                     "allowedTaiList");
	if(allowed_tai_listList == NULL) {
		printf(
			"partially_allowed_snssai_convertToJSON() failed [allowed_tai_list]");
		goto end;
	}
	list_for_each(partially_allowed_snssai->allowed_tai_list, node) {
		cJSON *itemLocal = tai_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"partially_allowed_snssai_convertToJSON() failed [allowed_tai_list]");
			goto end;
		}
		cJSON_AddItemToArray(allowed_tai_listList, itemLocal);
	}

end:
	return item;
}

partially_allowed_snssai_t *partially_allowed_snssai_parseFromJSON(
	cJSON *partially_allowed_snssaiJSON) {
	partially_allowed_snssai_t *partially_allowed_snssai_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *allowed_tai_list = NULL;
	list_t *allowed_tai_listList = NULL;
	snssai = cJSON_GetObjectItemCaseSensitive(partially_allowed_snssaiJSON,
	                                          "snssai");
	if(!snssai) {
		printf(
			"partially_allowed_snssai_parseFromJSON() failed [snssai]");
		goto end;
	}
	snssai_local_nonprim = snssai_parseFromJSON(snssai);
	if(!snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [snssai]");
		goto end;
	}

	allowed_tai_list = cJSON_GetObjectItemCaseSensitive(
		partially_allowed_snssaiJSON, "allowedTaiList");
	if(!allowed_tai_list) {
		printf(
			"partially_allowed_snssai_parseFromJSON() failed [allowed_tai_list]");
		goto end;
	}
	cJSON *allowed_tai_list_local = NULL;
	if(!cJSON_IsArray(allowed_tai_list)) {
		printf(
			"partially_allowed_snssai_parseFromJSON() failed [allowed_tai_list]");
		goto end;
	}

	allowed_tai_listList = list_create();

	cJSON_ArrayForEach(allowed_tai_list_local, allowed_tai_list) {
		if(!cJSON_IsObject(allowed_tai_list_local)) {
			printf(
				"partially_allowed_snssai_parseFromJSON() failed [allowed_tai_list]");
			goto end;
		}
		tai_t *allowed_tai_listItem = tai_parseFromJSON(
			allowed_tai_list_local);
		if(!allowed_tai_listItem) {
			printf("No allowed_tai_listItem");
			goto end;
		}
		list_add(allowed_tai_listList, allowed_tai_listItem);
	}

	partially_allowed_snssai_local_var = partially_allowed_snssai_create(
		snssai_local_nonprim,
		allowed_tai_listList
		);

	return partially_allowed_snssai_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(allowed_tai_listList) {
		list_for_each(allowed_tai_listList, node) {
			tai_free(node->data);
		}
		list_free(allowed_tai_listList);
		allowed_tai_listList = NULL;
	}
	return NULL;
}

partially_allowed_snssai_t *partially_allowed_snssai_copy(
	partially_allowed_snssai_t *dst, partially_allowed_snssai_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = partially_allowed_snssai_convertToJSON(src);
	if(!item) {
		printf("partially_allowed_snssai_convertToJSON() failed");
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

	partially_allowed_snssai_free(dst);
	dst = partially_allowed_snssai_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
