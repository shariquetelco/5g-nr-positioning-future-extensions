#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ntn_tai_info.h"

ntn_tai_info_t *ntn_tai_info_create(plmn_id_nid_t *plmn_id, list_t *tac_list,
                                    char *derived_tac) {
	ntn_tai_info_t *ntn_tai_info_local_var = malloc(sizeof(ntn_tai_info_t));

	ntn_tai_info_local_var->plmn_id = plmn_id;
	ntn_tai_info_local_var->tac_list = tac_list;
	ntn_tai_info_local_var->derived_tac = derived_tac;

	return ntn_tai_info_local_var;
}

void ntn_tai_info_free(ntn_tai_info_t *ntn_tai_info) {
	lnode_t *node = NULL;

	if(NULL == ntn_tai_info) {
		return;
	}
	if(ntn_tai_info->plmn_id) {
		plmn_id_nid_free(ntn_tai_info->plmn_id);
		ntn_tai_info->plmn_id = NULL;
	}
	if(ntn_tai_info->tac_list) {
		list_for_each(ntn_tai_info->tac_list, node) {
			free(node->data);
		}
		list_free(ntn_tai_info->tac_list);
		ntn_tai_info->tac_list = NULL;
	}
	if(ntn_tai_info->derived_tac) {
		free(ntn_tai_info->derived_tac);
		ntn_tai_info->derived_tac = NULL;
	}
	free(ntn_tai_info);
}

cJSON *ntn_tai_info_convertToJSON(ntn_tai_info_t *ntn_tai_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ntn_tai_info == NULL) {
		printf("ntn_tai_info_convertToJSON() failed [NtnTaiInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ntn_tai_info->plmn_id) {
		printf("ntn_tai_info_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_nid_convertToJSON(
		ntn_tai_info->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("ntn_tai_info_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("ntn_tai_info_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!ntn_tai_info->tac_list) {
		printf("ntn_tai_info_convertToJSON() failed [tac_list]");
		return NULL;
	}
	cJSON *tac_listList = cJSON_AddArrayToObject(item, "tacList");
	if(tac_listList == NULL) {
		printf("ntn_tai_info_convertToJSON() failed [tac_list]");
		goto end;
	}
	list_for_each(ntn_tai_info->tac_list, node) {
		if(cJSON_AddStringToObject(tac_listList, "",
		                           (char *) node->data) == NULL)
		{
			printf("ntn_tai_info_convertToJSON() failed [tac_list]");
			goto end;
		}
	}

	if(ntn_tai_info->derived_tac) {
		if(cJSON_AddStringToObject(item, "derivedTac",
		                           ntn_tai_info->derived_tac) == NULL)
		{
			printf(
				"ntn_tai_info_convertToJSON() failed [derived_tac]");
			goto end;
		}
	}

end:
	return item;
}

ntn_tai_info_t *ntn_tai_info_parseFromJSON(cJSON *ntn_tai_infoJSON) {
	ntn_tai_info_t *ntn_tai_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_nid_t *plmn_id_local_nonprim = NULL;
	cJSON *tac_list = NULL;
	list_t *tac_listList = NULL;
	cJSON *derived_tac = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(ntn_tai_infoJSON, "plmnId");
	if(!plmn_id) {
		printf("ntn_tai_info_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_nid_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_nid_parseFromJSON failed [plmn_id]");
		goto end;
	}

	tac_list =
		cJSON_GetObjectItemCaseSensitive(ntn_tai_infoJSON, "tacList");
	if(!tac_list) {
		printf("ntn_tai_info_parseFromJSON() failed [tac_list]");
		goto end;
	}
	cJSON *tac_list_local = NULL;
	if(!cJSON_IsArray(tac_list)) {
		printf("ntn_tai_info_parseFromJSON() failed [tac_list]");
		goto end;
	}

	tac_listList = list_create();

	cJSON_ArrayForEach(tac_list_local, tac_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsString(tac_list_local)) {
			printf("ntn_tai_info_parseFromJSON() failed [tac_list]");
			goto end;
		}
		list_add(tac_listList, strdup(tac_list_local->valuestring));
	}

	derived_tac = cJSON_GetObjectItemCaseSensitive(ntn_tai_infoJSON,
	                                               "derivedTac");
	if(derived_tac) {
		if(!cJSON_IsString(derived_tac) &&
		   !cJSON_IsNull(derived_tac))
		{
			printf(
				"ntn_tai_info_parseFromJSON() failed [derived_tac]");
			goto end;
		}
	}

	ntn_tai_info_local_var = ntn_tai_info_create(
		plmn_id_local_nonprim,
		tac_listList,
		derived_tac &&
		!cJSON_IsNull(derived_tac) ? strdup(
			derived_tac->valuestring) : NULL
		);

	return ntn_tai_info_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_nid_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	if(tac_listList) {
		list_for_each(tac_listList, node) {
			free(node->data);
		}
		list_free(tac_listList);
		tac_listList = NULL;
	}
	return NULL;
}

ntn_tai_info_t *ntn_tai_info_copy(ntn_tai_info_t *dst, ntn_tai_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ntn_tai_info_convertToJSON(src);
	if(!item) {
		printf("ntn_tai_info_convertToJSON() failed");
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

	ntn_tai_info_free(dst);
	dst = ntn_tai_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
