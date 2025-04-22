#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tai_range.h"

tai_range_t *tai_range_create(plmn_id_t *plmn_id, list_t *tac_range_list,
                              char *nid) {
	tai_range_t *tai_range_local_var = malloc(sizeof(tai_range_t));

	tai_range_local_var->plmn_id = plmn_id;
	tai_range_local_var->tac_range_list = tac_range_list;
	tai_range_local_var->nid = nid;

	return tai_range_local_var;
}

void tai_range_free(tai_range_t *tai_range) {
	lnode_t *node = NULL;

	if(NULL == tai_range) {
		return;
	}
	if(tai_range->plmn_id) {
		plmn_id_free(tai_range->plmn_id);
		tai_range->plmn_id = NULL;
	}
	if(tai_range->tac_range_list) {
		list_for_each(tai_range->tac_range_list, node) {
			tac_range_free(node->data);
		}
		list_free(tai_range->tac_range_list);
		tai_range->tac_range_list = NULL;
	}
	if(tai_range->nid) {
		free(tai_range->nid);
		tai_range->nid = NULL;
	}
	free(tai_range);
}

cJSON *tai_range_convertToJSON(tai_range_t *tai_range) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(tai_range == NULL) {
		printf("tai_range_convertToJSON() failed [TaiRange]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!tai_range->plmn_id) {
		printf("tai_range_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(tai_range->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("tai_range_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("tai_range_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!tai_range->tac_range_list) {
		printf("tai_range_convertToJSON() failed [tac_range_list]");
		return NULL;
	}
	cJSON *tac_range_listList =
		cJSON_AddArrayToObject(item, "tacRangeList");
	if(tac_range_listList == NULL) {
		printf("tai_range_convertToJSON() failed [tac_range_list]");
		goto end;
	}
	list_for_each(tai_range->tac_range_list, node) {
		cJSON *itemLocal = tac_range_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"tai_range_convertToJSON() failed [tac_range_list]");
			goto end;
		}
		cJSON_AddItemToArray(tac_range_listList, itemLocal);
	}

	if(tai_range->nid) {
		if(cJSON_AddStringToObject(item, "nid",
		                           tai_range->nid) == NULL)
		{
			printf("tai_range_convertToJSON() failed [nid]");
			goto end;
		}
	}

end:
	return item;
}

tai_range_t *tai_range_parseFromJSON(cJSON *tai_rangeJSON) {
	tai_range_t *tai_range_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *tac_range_list = NULL;
	list_t *tac_range_listList = NULL;
	cJSON *nid = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(tai_rangeJSON, "plmnId");
	if(!plmn_id) {
		printf("tai_range_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	tac_range_list = cJSON_GetObjectItemCaseSensitive(tai_rangeJSON,
	                                                  "tacRangeList");
	if(!tac_range_list) {
		printf("tai_range_parseFromJSON() failed [tac_range_list]");
		goto end;
	}
	cJSON *tac_range_list_local = NULL;
	if(!cJSON_IsArray(tac_range_list)) {
		printf("tai_range_parseFromJSON() failed [tac_range_list]");
		goto end;
	}

	tac_range_listList = list_create();

	cJSON_ArrayForEach(tac_range_list_local, tac_range_list) {
		if(!cJSON_IsObject(tac_range_list_local)) {
			printf(
				"tai_range_parseFromJSON() failed [tac_range_list]");
			goto end;
		}
		tac_range_t *tac_range_listItem = tac_range_parseFromJSON(
			tac_range_list_local);
		if(!tac_range_listItem) {
			printf("No tac_range_listItem");
			goto end;
		}
		list_add(tac_range_listList, tac_range_listItem);
	}

	nid = cJSON_GetObjectItemCaseSensitive(tai_rangeJSON, "nid");
	if(nid) {
		if(!cJSON_IsString(nid) &&
		   !cJSON_IsNull(nid))
		{
			printf("tai_range_parseFromJSON() failed [nid]");
			goto end;
		}
	}

	tai_range_local_var = tai_range_create(
		plmn_id_local_nonprim,
		tac_range_listList,
		nid &&
		!cJSON_IsNull(nid) ? strdup(nid->valuestring) : NULL
		);

	return tai_range_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	if(tac_range_listList) {
		list_for_each(tac_range_listList, node) {
			tac_range_free(node->data);
		}
		list_free(tac_range_listList);
		tac_range_listList = NULL;
	}
	return NULL;
}

tai_range_t *tai_range_copy(tai_range_t *dst, tai_range_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = tai_range_convertToJSON(src);
	if(!item) {
		printf("tai_range_convertToJSON() failed");
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

	tai_range_free(dst);
	dst = tai_range_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
