#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "roaming_info.h"

roaming_info_t *roaming_info_create(plmn_id_nid_t *plmn_id, list_t *aois,
                                    list_t *serving_nf_ids,
                                    list_t *serving_nf_set_ids) {
	roaming_info_t *roaming_info_local_var = malloc(sizeof(roaming_info_t));

	roaming_info_local_var->plmn_id = plmn_id;
	roaming_info_local_var->aois = aois;
	roaming_info_local_var->serving_nf_ids = serving_nf_ids;
	roaming_info_local_var->serving_nf_set_ids = serving_nf_set_ids;

	return roaming_info_local_var;
}

void roaming_info_free(roaming_info_t *roaming_info) {
	lnode_t *node = NULL;

	if(NULL == roaming_info) {
		return;
	}
	if(roaming_info->plmn_id) {
		plmn_id_nid_free(roaming_info->plmn_id);
		roaming_info->plmn_id = NULL;
	}
	if(roaming_info->aois) {
		list_for_each(roaming_info->aois, node) {
			geographical_area_free(node->data);
		}
		list_free(roaming_info->aois);
		roaming_info->aois = NULL;
	}
	if(roaming_info->serving_nf_ids) {
		list_for_each(roaming_info->serving_nf_ids, node) {
			free(node->data);
		}
		list_free(roaming_info->serving_nf_ids);
		roaming_info->serving_nf_ids = NULL;
	}
	if(roaming_info->serving_nf_set_ids) {
		list_for_each(roaming_info->serving_nf_set_ids, node) {
			free(node->data);
		}
		list_free(roaming_info->serving_nf_set_ids);
		roaming_info->serving_nf_set_ids = NULL;
	}
	free(roaming_info);
}

cJSON *roaming_info_convertToJSON(roaming_info_t *roaming_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(roaming_info == NULL) {
		printf("roaming_info_convertToJSON() failed [RoamingInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(roaming_info->plmn_id) {
		cJSON *plmn_id_local_JSON = plmn_id_nid_convertToJSON(
			roaming_info->plmn_id);
		if(plmn_id_local_JSON == NULL) {
			printf("roaming_info_convertToJSON() failed [plmn_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
		if(item->child == NULL) {
			printf("roaming_info_convertToJSON() failed [plmn_id]");
			goto end;
		}
	}

	if(roaming_info->aois) {
		cJSON *aoisList = cJSON_AddArrayToObject(item, "aois");
		if(aoisList == NULL) {
			printf("roaming_info_convertToJSON() failed [aois]");
			goto end;
		}
		list_for_each(roaming_info->aois, node) {
			cJSON *itemLocal = geographical_area_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"roaming_info_convertToJSON() failed [aois]");
				goto end;
			}
			cJSON_AddItemToArray(aoisList, itemLocal);
		}
	}

	if(roaming_info->serving_nf_ids) {
		cJSON *serving_nf_idsList = cJSON_AddArrayToObject(item,
		                                                   "servingNfIds");
		if(serving_nf_idsList == NULL) {
			printf(
				"roaming_info_convertToJSON() failed [serving_nf_ids]");
			goto end;
		}
		list_for_each(roaming_info->serving_nf_ids, node) {
			if(cJSON_AddStringToObject(serving_nf_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"roaming_info_convertToJSON() failed [serving_nf_ids]");
				goto end;
			}
		}
	}

	if(roaming_info->serving_nf_set_ids) {
		cJSON *serving_nf_set_idsList = cJSON_AddArrayToObject(item,
		                                                       "servingNfSetIds");
		if(serving_nf_set_idsList == NULL) {
			printf(
				"roaming_info_convertToJSON() failed [serving_nf_set_ids]");
			goto end;
		}
		list_for_each(roaming_info->serving_nf_set_ids, node) {
			if(cJSON_AddStringToObject(serving_nf_set_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"roaming_info_convertToJSON() failed [serving_nf_set_ids]");
				goto end;
			}
		}
	}

end:
	return item;
}

roaming_info_t *roaming_info_parseFromJSON(cJSON *roaming_infoJSON) {
	roaming_info_t *roaming_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_nid_t *plmn_id_local_nonprim = NULL;
	cJSON *aois = NULL;
	list_t *aoisList = NULL;
	cJSON *serving_nf_ids = NULL;
	list_t *serving_nf_idsList = NULL;
	cJSON *serving_nf_set_ids = NULL;
	list_t *serving_nf_set_idsList = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(roaming_infoJSON, "plmnId");
	if(plmn_id) {
		plmn_id_local_nonprim = plmn_id_nid_parseFromJSON(plmn_id);
		if(!plmn_id_local_nonprim) {
			printf("plmn_id_nid_parseFromJSON failed [plmn_id]");
			goto end;
		}
	}

	aois = cJSON_GetObjectItemCaseSensitive(roaming_infoJSON, "aois");
	if(aois) {
		cJSON *aois_local = NULL;
		if(!cJSON_IsArray(aois)) {
			printf("roaming_info_parseFromJSON() failed [aois]");
			goto end;
		}

		aoisList = list_create();

		cJSON_ArrayForEach(aois_local, aois) {
			if(!cJSON_IsObject(aois_local)) {
				printf(
					"roaming_info_parseFromJSON() failed [aois]");
				goto end;
			}
			geographical_area_t *aoisItem =
				geographical_area_parseFromJSON(aois_local);
			if(!aoisItem) {
				printf("No aoisItem");
				goto end;
			}
			list_add(aoisList, aoisItem);
		}
	}

	serving_nf_ids = cJSON_GetObjectItemCaseSensitive(roaming_infoJSON,
	                                                  "servingNfIds");
	if(serving_nf_ids) {
		cJSON *serving_nf_ids_local = NULL;
		if(!cJSON_IsArray(serving_nf_ids)) {
			printf(
				"roaming_info_parseFromJSON() failed [serving_nf_ids]");
			goto end;
		}

		serving_nf_idsList = list_create();

		cJSON_ArrayForEach(serving_nf_ids_local, serving_nf_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(serving_nf_ids_local)) {
				printf(
					"roaming_info_parseFromJSON() failed [serving_nf_ids]");
				goto end;
			}
			list_add(serving_nf_idsList,
			         strdup(serving_nf_ids_local->valuestring));
		}
	}

	serving_nf_set_ids = cJSON_GetObjectItemCaseSensitive(roaming_infoJSON,
	                                                      "servingNfSetIds");
	if(serving_nf_set_ids) {
		cJSON *serving_nf_set_ids_local = NULL;
		if(!cJSON_IsArray(serving_nf_set_ids)) {
			printf(
				"roaming_info_parseFromJSON() failed [serving_nf_set_ids]");
			goto end;
		}

		serving_nf_set_idsList = list_create();

		cJSON_ArrayForEach(serving_nf_set_ids_local,
		                   serving_nf_set_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(serving_nf_set_ids_local)) {
				printf(
					"roaming_info_parseFromJSON() failed [serving_nf_set_ids]");
				goto end;
			}
			list_add(serving_nf_set_idsList,
			         strdup(serving_nf_set_ids_local->valuestring));
		}
	}

	roaming_info_local_var = roaming_info_create(
		plmn_id ? plmn_id_local_nonprim : NULL,
		aois ? aoisList : NULL,
		serving_nf_ids ? serving_nf_idsList : NULL,
		serving_nf_set_ids ? serving_nf_set_idsList : NULL
		);

	return roaming_info_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_nid_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	if(aoisList) {
		list_for_each(aoisList, node) {
			geographical_area_free(node->data);
		}
		list_free(aoisList);
		aoisList = NULL;
	}
	if(serving_nf_idsList) {
		list_for_each(serving_nf_idsList, node) {
			free(node->data);
		}
		list_free(serving_nf_idsList);
		serving_nf_idsList = NULL;
	}
	if(serving_nf_set_idsList) {
		list_for_each(serving_nf_set_idsList, node) {
			free(node->data);
		}
		list_free(serving_nf_set_idsList);
		serving_nf_set_idsList = NULL;
	}
	return NULL;
}

roaming_info_t *roaming_info_copy(roaming_info_t *dst, roaming_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = roaming_info_convertToJSON(src);
	if(!item) {
		printf("roaming_info_convertToJSON() failed");
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

	roaming_info_free(dst);
	dst = roaming_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
