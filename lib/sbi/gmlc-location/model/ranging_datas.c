#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ranging_datas.h"

ranging_datas_t *ranging_datas_create(list_t *ranging_datas) {
	ranging_datas_t *ranging_datas_local_var = malloc(
		sizeof(ranging_datas_t));

	ranging_datas_local_var->ranging_datas = ranging_datas;

	return ranging_datas_local_var;
}

void ranging_datas_free(ranging_datas_t *ranging_datas) {
	lnode_t *node = NULL;

	if(NULL == ranging_datas) {
		return;
	}
	if(ranging_datas->ranging_datas) {
		list_for_each(ranging_datas->ranging_datas, node) {
			ranging_data_free(node->data);
		}
		list_free(ranging_datas->ranging_datas);
		ranging_datas->ranging_datas = NULL;
	}
	free(ranging_datas);
}

cJSON *ranging_datas_convertToJSON(ranging_datas_t *ranging_datas) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ranging_datas == NULL) {
		printf("ranging_datas_convertToJSON() failed [RangingDatas]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ranging_datas->ranging_datas) {
		printf("ranging_datas_convertToJSON() failed [ranging_datas]");
		return NULL;
	}
	cJSON *ranging_datasList = cJSON_AddArrayToObject(item, "rangingDatas");
	if(ranging_datasList == NULL) {
		printf("ranging_datas_convertToJSON() failed [ranging_datas]");
		goto end;
	}
	list_for_each(ranging_datas->ranging_datas, node) {
		cJSON *itemLocal = ranging_data_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"ranging_datas_convertToJSON() failed [ranging_datas]");
			goto end;
		}
		cJSON_AddItemToArray(ranging_datasList, itemLocal);
	}

end:
	return item;
}

ranging_datas_t *ranging_datas_parseFromJSON(cJSON *ranging_datasJSON) {
	ranging_datas_t *ranging_datas_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ranging_datas = NULL;
	list_t *ranging_datasList = NULL;
	ranging_datas = cJSON_GetObjectItemCaseSensitive(ranging_datasJSON,
	                                                 "rangingDatas");
	if(!ranging_datas) {
		printf("ranging_datas_parseFromJSON() failed [ranging_datas]");
		goto end;
	}
	cJSON *ranging_datas_local = NULL;
	if(!cJSON_IsArray(ranging_datas)) {
		printf("ranging_datas_parseFromJSON() failed [ranging_datas]");
		goto end;
	}

	ranging_datasList = list_create();

	cJSON_ArrayForEach(ranging_datas_local, ranging_datas) {
		if(!cJSON_IsObject(ranging_datas_local)) {
			printf(
				"ranging_datas_parseFromJSON() failed [ranging_datas]");
			goto end;
		}
		ranging_data_t *ranging_datasItem = ranging_data_parseFromJSON(
			ranging_datas_local);
		if(!ranging_datasItem) {
			printf("No ranging_datasItem");
			goto end;
		}
		list_add(ranging_datasList, ranging_datasItem);
	}

	ranging_datas_local_var = ranging_datas_create(
		ranging_datasList
		);

	return ranging_datas_local_var;
end:
	if(ranging_datasList) {
		list_for_each(ranging_datasList, node) {
			ranging_data_free(node->data);
		}
		list_free(ranging_datasList);
		ranging_datasList = NULL;
	}
	return NULL;
}

ranging_datas_t *ranging_datas_copy(ranging_datas_t	*dst,
                                    ranging_datas_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ranging_datas_convertToJSON(src);
	if(!item) {
		printf("ranging_datas_convertToJSON() failed");
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

	ranging_datas_free(dst);
	dst = ranging_datas_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
