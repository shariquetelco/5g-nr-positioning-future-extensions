#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "snssai_dnn_item.h"

snssai_dnn_item_t *snssai_dnn_item_create(list_t	*snssai_list,
                                          list_t	*dnn_list) {
	snssai_dnn_item_t *snssai_dnn_item_local_var =
		malloc(sizeof(snssai_dnn_item_t));

	snssai_dnn_item_local_var->snssai_list = snssai_list;
	snssai_dnn_item_local_var->dnn_list = dnn_list;

	return snssai_dnn_item_local_var;
}

void snssai_dnn_item_free(snssai_dnn_item_t *snssai_dnn_item) {
	lnode_t *node = NULL;

	if(NULL == snssai_dnn_item) {
		return;
	}
	if(snssai_dnn_item->snssai_list) {
		list_for_each(snssai_dnn_item->snssai_list, node) {
			ext_snssai_free(node->data);
		}
		list_free(snssai_dnn_item->snssai_list);
		snssai_dnn_item->snssai_list = NULL;
	}
	if(snssai_dnn_item->dnn_list) {
		list_for_each(snssai_dnn_item->dnn_list, node) {
			free(node->data);
		}
		list_free(snssai_dnn_item->dnn_list);
		snssai_dnn_item->dnn_list = NULL;
	}
	free(snssai_dnn_item);
}

cJSON *snssai_dnn_item_convertToJSON(snssai_dnn_item_t *snssai_dnn_item) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(snssai_dnn_item == NULL) {
		printf("snssai_dnn_item_convertToJSON() failed [SnssaiDnnItem]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(snssai_dnn_item->snssai_list) {
		cJSON *snssai_listList = cJSON_AddArrayToObject(item,
		                                                "snssaiList");
		if(snssai_listList == NULL) {
			printf(
				"snssai_dnn_item_convertToJSON() failed [snssai_list]");
			goto end;
		}
		list_for_each(snssai_dnn_item->snssai_list, node) {
			cJSON *itemLocal = ext_snssai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"snssai_dnn_item_convertToJSON() failed [snssai_list]");
				goto end;
			}
			cJSON_AddItemToArray(snssai_listList, itemLocal);
		}
	}

	if(snssai_dnn_item->dnn_list) {
		cJSON *dnn_listList = cJSON_AddArrayToObject(item, "dnnList");
		if(dnn_listList == NULL) {
			printf(
				"snssai_dnn_item_convertToJSON() failed [dnn_list]");
			goto end;
		}
		list_for_each(snssai_dnn_item->dnn_list, node) {
			if(cJSON_AddStringToObject(dnn_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"snssai_dnn_item_convertToJSON() failed [dnn_list]");
				goto end;
			}
		}
	}

end:
	return item;
}

snssai_dnn_item_t *snssai_dnn_item_parseFromJSON(cJSON *snssai_dnn_itemJSON) {
	snssai_dnn_item_t *snssai_dnn_item_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *snssai_list = NULL;
	list_t *snssai_listList = NULL;
	cJSON *dnn_list = NULL;
	list_t *dnn_listList = NULL;
	snssai_list = cJSON_GetObjectItemCaseSensitive(snssai_dnn_itemJSON,
	                                               "snssaiList");
	if(snssai_list) {
		cJSON *snssai_list_local = NULL;
		if(!cJSON_IsArray(snssai_list)) {
			printf(
				"snssai_dnn_item_parseFromJSON() failed [snssai_list]");
			goto end;
		}

		snssai_listList = list_create();

		cJSON_ArrayForEach(snssai_list_local, snssai_list) {
			if(!cJSON_IsObject(snssai_list_local)) {
				printf(
					"snssai_dnn_item_parseFromJSON() failed [snssai_list]");
				goto end;
			}
			ext_snssai_t *snssai_listItem =
				ext_snssai_parseFromJSON(snssai_list_local);
			if(!snssai_listItem) {
				printf("No snssai_listItem");
				goto end;
			}
			list_add(snssai_listList, snssai_listItem);
		}
	}

	dnn_list = cJSON_GetObjectItemCaseSensitive(snssai_dnn_itemJSON,
	                                            "dnnList");
	if(dnn_list) {
		cJSON *dnn_list_local = NULL;
		if(!cJSON_IsArray(dnn_list)) {
			printf(
				"snssai_dnn_item_parseFromJSON() failed [dnn_list]");
			goto end;
		}

		dnn_listList = list_create();

		cJSON_ArrayForEach(dnn_list_local, dnn_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(dnn_list_local)) {
				printf(
					"snssai_dnn_item_parseFromJSON() failed [dnn_list]");
				goto end;
			}
			list_add(dnn_listList,
			         strdup(dnn_list_local->valuestring));
		}
	}

	snssai_dnn_item_local_var = snssai_dnn_item_create(
		snssai_list ? snssai_listList : NULL,
		dnn_list ? dnn_listList : NULL
		);

	return snssai_dnn_item_local_var;
end:
	if(snssai_listList) {
		list_for_each(snssai_listList, node) {
			ext_snssai_free(node->data);
		}
		list_free(snssai_listList);
		snssai_listList = NULL;
	}
	if(dnn_listList) {
		list_for_each(dnn_listList, node) {
			free(node->data);
		}
		list_free(dnn_listList);
		dnn_listList = NULL;
	}
	return NULL;
}

snssai_dnn_item_t *snssai_dnn_item_copy(snssai_dnn_item_t	*dst,
                                        snssai_dnn_item_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = snssai_dnn_item_convertToJSON(src);
	if(!item) {
		printf("snssai_dnn_item_convertToJSON() failed");
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

	snssai_dnn_item_free(dst);
	dst = snssai_dnn_item_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
