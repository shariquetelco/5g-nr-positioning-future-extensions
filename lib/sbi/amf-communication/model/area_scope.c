#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "area_scope.h"

area_scope_t *area_scope_create(list_t *eutra_cell_id_list,
                                list_t *nr_cell_id_list, list_t *tac_list,
                                list_t *tac_info_per_plmn,
                                list_t *cag_info_per_plmn,
                                list_t *nid_info_per_plmn) {
	area_scope_t *area_scope_local_var = malloc(sizeof(area_scope_t));

	area_scope_local_var->eutra_cell_id_list = eutra_cell_id_list;
	area_scope_local_var->nr_cell_id_list = nr_cell_id_list;
	area_scope_local_var->tac_list = tac_list;
	area_scope_local_var->tac_info_per_plmn = tac_info_per_plmn;
	area_scope_local_var->cag_info_per_plmn = cag_info_per_plmn;
	area_scope_local_var->nid_info_per_plmn = nid_info_per_plmn;

	return area_scope_local_var;
}

void area_scope_free(area_scope_t *area_scope) {
	lnode_t *node = NULL;

	if(NULL == area_scope) {
		return;
	}
	if(area_scope->eutra_cell_id_list) {
		list_for_each(area_scope->eutra_cell_id_list, node) {
			free(node->data);
		}
		list_free(area_scope->eutra_cell_id_list);
		area_scope->eutra_cell_id_list = NULL;
	}
	if(area_scope->nr_cell_id_list) {
		list_for_each(area_scope->nr_cell_id_list, node) {
			free(node->data);
		}
		list_free(area_scope->nr_cell_id_list);
		area_scope->nr_cell_id_list = NULL;
	}
	if(area_scope->tac_list) {
		list_for_each(area_scope->tac_list, node) {
			free(node->data);
		}
		list_free(area_scope->tac_list);
		area_scope->tac_list = NULL;
	}
	if(area_scope->tac_info_per_plmn) {
		list_for_each(area_scope->tac_info_per_plmn, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			tac_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(area_scope->tac_info_per_plmn);
		area_scope->tac_info_per_plmn = NULL;
	}
	if(area_scope->cag_info_per_plmn) {
		list_for_each(area_scope->cag_info_per_plmn, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			cag_info_1_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(area_scope->cag_info_per_plmn);
		area_scope->cag_info_per_plmn = NULL;
	}
	if(area_scope->nid_info_per_plmn) {
		list_for_each(area_scope->nid_info_per_plmn, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			nid_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(area_scope->nid_info_per_plmn);
		area_scope->nid_info_per_plmn = NULL;
	}
	free(area_scope);
}

cJSON *area_scope_convertToJSON(area_scope_t *area_scope) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(area_scope == NULL) {
		printf("area_scope_convertToJSON() failed [AreaScope]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(area_scope->eutra_cell_id_list) {
		cJSON *eutra_cell_id_listList = cJSON_AddArrayToObject(item,
		                                                       "eutraCellIdList");
		if(eutra_cell_id_listList == NULL) {
			printf(
				"area_scope_convertToJSON() failed [eutra_cell_id_list]");
			goto end;
		}
		list_for_each(area_scope->eutra_cell_id_list, node) {
			if(cJSON_AddStringToObject(eutra_cell_id_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"area_scope_convertToJSON() failed [eutra_cell_id_list]");
				goto end;
			}
		}
	}

	if(area_scope->nr_cell_id_list) {
		cJSON *nr_cell_id_listList = cJSON_AddArrayToObject(item,
		                                                    "nrCellIdList");
		if(nr_cell_id_listList == NULL) {
			printf(
				"area_scope_convertToJSON() failed [nr_cell_id_list]");
			goto end;
		}
		list_for_each(area_scope->nr_cell_id_list, node) {
			if(cJSON_AddStringToObject(nr_cell_id_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"area_scope_convertToJSON() failed [nr_cell_id_list]");
				goto end;
			}
		}
	}

	if(area_scope->tac_list) {
		cJSON *tac_listList = cJSON_AddArrayToObject(item, "tacList");
		if(tac_listList == NULL) {
			printf("area_scope_convertToJSON() failed [tac_list]");
			goto end;
		}
		list_for_each(area_scope->tac_list, node) {
			if(cJSON_AddStringToObject(tac_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"area_scope_convertToJSON() failed [tac_list]");
				goto end;
			}
		}
	}

	if(area_scope->tac_info_per_plmn) {
		cJSON *tac_info_per_plmn = cJSON_AddObjectToObject(item,
		                                                   "tacInfoPerPlmn");
		if(tac_info_per_plmn == NULL) {
			printf(
				"area_scope_convertToJSON() failed [tac_info_per_plmn]");
			goto end;
		}
		cJSON *localMapObject = tac_info_per_plmn;
		if(area_scope->tac_info_per_plmn) {
			list_for_each(area_scope->tac_info_per_plmn, node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"area_scope_convertToJSON() failed [tac_info_per_plmn]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"area_scope_convertToJSON() failed [tac_info_per_plmn]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   tac_info_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"area_scope_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

	if(area_scope->cag_info_per_plmn) {
		cJSON *cag_info_per_plmn = cJSON_AddObjectToObject(item,
		                                                   "cagInfoPerPlmn");
		if(cag_info_per_plmn == NULL) {
			printf(
				"area_scope_convertToJSON() failed [cag_info_per_plmn]");
			goto end;
		}
		cJSON *localMapObject = cag_info_per_plmn;
		if(area_scope->cag_info_per_plmn) {
			list_for_each(area_scope->cag_info_per_plmn, node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"area_scope_convertToJSON() failed [cag_info_per_plmn]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"area_scope_convertToJSON() failed [cag_info_per_plmn]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   cag_info_1_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"area_scope_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

	if(area_scope->nid_info_per_plmn) {
		cJSON *nid_info_per_plmn = cJSON_AddObjectToObject(item,
		                                                   "nidInfoPerPlmn");
		if(nid_info_per_plmn == NULL) {
			printf(
				"area_scope_convertToJSON() failed [nid_info_per_plmn]");
			goto end;
		}
		cJSON *localMapObject = nid_info_per_plmn;
		if(area_scope->nid_info_per_plmn) {
			list_for_each(area_scope->nid_info_per_plmn, node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"area_scope_convertToJSON() failed [nid_info_per_plmn]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"area_scope_convertToJSON() failed [nid_info_per_plmn]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   nid_info_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"area_scope_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

end:
	return item;
}

area_scope_t *area_scope_parseFromJSON(cJSON *area_scopeJSON) {
	area_scope_t *area_scope_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *eutra_cell_id_list = NULL;
	list_t *eutra_cell_id_listList = NULL;
	cJSON *nr_cell_id_list = NULL;
	list_t *nr_cell_id_listList = NULL;
	cJSON *tac_list = NULL;
	list_t *tac_listList = NULL;
	cJSON *tac_info_per_plmn = NULL;
	list_t *tac_info_per_plmnList = NULL;
	cJSON *cag_info_per_plmn = NULL;
	list_t *cag_info_per_plmnList = NULL;
	cJSON *nid_info_per_plmn = NULL;
	list_t *nid_info_per_plmnList = NULL;
	eutra_cell_id_list = cJSON_GetObjectItemCaseSensitive(area_scopeJSON,
	                                                      "eutraCellIdList");
	if(eutra_cell_id_list) {
		cJSON *eutra_cell_id_list_local = NULL;
		if(!cJSON_IsArray(eutra_cell_id_list)) {
			printf(
				"area_scope_parseFromJSON() failed [eutra_cell_id_list]");
			goto end;
		}

		eutra_cell_id_listList = list_create();

		cJSON_ArrayForEach(eutra_cell_id_list_local,
		                   eutra_cell_id_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(eutra_cell_id_list_local)) {
				printf(
					"area_scope_parseFromJSON() failed [eutra_cell_id_list]");
				goto end;
			}
			list_add(eutra_cell_id_listList,
			         strdup(eutra_cell_id_list_local->valuestring));
		}
	}

	nr_cell_id_list = cJSON_GetObjectItemCaseSensitive(area_scopeJSON,
	                                                   "nrCellIdList");
	if(nr_cell_id_list) {
		cJSON *nr_cell_id_list_local = NULL;
		if(!cJSON_IsArray(nr_cell_id_list)) {
			printf(
				"area_scope_parseFromJSON() failed [nr_cell_id_list]");
			goto end;
		}

		nr_cell_id_listList = list_create();

		cJSON_ArrayForEach(nr_cell_id_list_local, nr_cell_id_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(nr_cell_id_list_local)) {
				printf(
					"area_scope_parseFromJSON() failed [nr_cell_id_list]");
				goto end;
			}
			list_add(nr_cell_id_listList,
			         strdup(nr_cell_id_list_local->valuestring));
		}
	}

	tac_list = cJSON_GetObjectItemCaseSensitive(area_scopeJSON, "tacList");
	if(tac_list) {
		cJSON *tac_list_local = NULL;
		if(!cJSON_IsArray(tac_list)) {
			printf("area_scope_parseFromJSON() failed [tac_list]");
			goto end;
		}

		tac_listList = list_create();

		cJSON_ArrayForEach(tac_list_local, tac_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(tac_list_local)) {
				printf(
					"area_scope_parseFromJSON() failed [tac_list]");
				goto end;
			}
			list_add(tac_listList,
			         strdup(tac_list_local->valuestring));
		}
	}

	tac_info_per_plmn = cJSON_GetObjectItemCaseSensitive(area_scopeJSON,
	                                                     "tacInfoPerPlmn");
	if(tac_info_per_plmn) {
		cJSON *tac_info_per_plmn_local_map = NULL;
		if(!cJSON_IsObject(tac_info_per_plmn) &&
		   !cJSON_IsNull(tac_info_per_plmn))
		{
			printf(
				"area_scope_parseFromJSON() failed [tac_info_per_plmn]");
			goto end;
		}
		if(cJSON_IsObject(tac_info_per_plmn)) {
			tac_info_per_plmnList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(tac_info_per_plmn_local_map,
			                   tac_info_per_plmn) {
				cJSON *localMapObject =
					tac_info_per_plmn_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), tac_info_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"area_scope_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(tac_info_per_plmnList,
				         localMapKeyPair);
			}
		}
	}

	cag_info_per_plmn = cJSON_GetObjectItemCaseSensitive(area_scopeJSON,
	                                                     "cagInfoPerPlmn");
	if(cag_info_per_plmn) {
		cJSON *cag_info_per_plmn_local_map = NULL;
		if(!cJSON_IsObject(cag_info_per_plmn) &&
		   !cJSON_IsNull(cag_info_per_plmn))
		{
			printf(
				"area_scope_parseFromJSON() failed [cag_info_per_plmn]");
			goto end;
		}
		if(cJSON_IsObject(cag_info_per_plmn)) {
			cag_info_per_plmnList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(cag_info_per_plmn_local_map,
			                   cag_info_per_plmn) {
				cJSON *localMapObject =
					cag_info_per_plmn_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), cag_info_1_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"area_scope_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(cag_info_per_plmnList,
				         localMapKeyPair);
			}
		}
	}

	nid_info_per_plmn = cJSON_GetObjectItemCaseSensitive(area_scopeJSON,
	                                                     "nidInfoPerPlmn");
	if(nid_info_per_plmn) {
		cJSON *nid_info_per_plmn_local_map = NULL;
		if(!cJSON_IsObject(nid_info_per_plmn) &&
		   !cJSON_IsNull(nid_info_per_plmn))
		{
			printf(
				"area_scope_parseFromJSON() failed [nid_info_per_plmn]");
			goto end;
		}
		if(cJSON_IsObject(nid_info_per_plmn)) {
			nid_info_per_plmnList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(nid_info_per_plmn_local_map,
			                   nid_info_per_plmn) {
				cJSON *localMapObject =
					nid_info_per_plmn_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), nid_info_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"area_scope_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(nid_info_per_plmnList,
				         localMapKeyPair);
			}
		}
	}

	area_scope_local_var = area_scope_create(
		eutra_cell_id_list ? eutra_cell_id_listList : NULL,
		nr_cell_id_list ? nr_cell_id_listList : NULL,
		tac_list ? tac_listList : NULL,
		tac_info_per_plmn ? tac_info_per_plmnList : NULL,
		cag_info_per_plmn ? cag_info_per_plmnList : NULL,
		nid_info_per_plmn ? nid_info_per_plmnList : NULL
		);

	return area_scope_local_var;
end:
	if(eutra_cell_id_listList) {
		list_for_each(eutra_cell_id_listList, node) {
			free(node->data);
		}
		list_free(eutra_cell_id_listList);
		eutra_cell_id_listList = NULL;
	}
	if(nr_cell_id_listList) {
		list_for_each(nr_cell_id_listList, node) {
			free(node->data);
		}
		list_free(nr_cell_id_listList);
		nr_cell_id_listList = NULL;
	}
	if(tac_listList) {
		list_for_each(tac_listList, node) {
			free(node->data);
		}
		list_free(tac_listList);
		tac_listList = NULL;
	}
	if(tac_info_per_plmnList) {
		list_for_each(tac_info_per_plmnList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			tac_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(tac_info_per_plmnList);
		tac_info_per_plmnList = NULL;
	}
	if(cag_info_per_plmnList) {
		list_for_each(cag_info_per_plmnList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			cag_info_1_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(cag_info_per_plmnList);
		cag_info_per_plmnList = NULL;
	}
	if(nid_info_per_plmnList) {
		list_for_each(nid_info_per_plmnList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			nid_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(nid_info_per_plmnList);
		nid_info_per_plmnList = NULL;
	}
	return NULL;
}

area_scope_t *area_scope_copy(area_scope_t *dst, area_scope_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = area_scope_convertToJSON(src);
	if(!item) {
		printf("area_scope_convertToJSON() failed");
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

	area_scope_free(dst);
	dst = area_scope_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
