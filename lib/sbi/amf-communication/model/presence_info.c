#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "presence_info.h"

presence_info_t *presence_info_create(char *pra_id, char *additional_pra_id,
                                      presence_state_t *presence_state,
                                      list_t *tracking_area_list,
                                      list_t *ecgi_list, list_t *ncgi_list,
                                      list_t *global_ran_node_id_list,
                                      list_t *globale_nb_id_list) {
	presence_info_t *presence_info_local_var = malloc(
		sizeof(presence_info_t));

	presence_info_local_var->pra_id = pra_id;
	presence_info_local_var->additional_pra_id = additional_pra_id;
	presence_info_local_var->presence_state = presence_state;
	presence_info_local_var->tracking_area_list = tracking_area_list;
	presence_info_local_var->ecgi_list = ecgi_list;
	presence_info_local_var->ncgi_list = ncgi_list;
	presence_info_local_var->global_ran_node_id_list =
		global_ran_node_id_list;
	presence_info_local_var->globale_nb_id_list = globale_nb_id_list;

	return presence_info_local_var;
}

void presence_info_free(presence_info_t *presence_info) {
	lnode_t *node = NULL;

	if(NULL == presence_info) {
		return;
	}
	if(presence_info->pra_id) {
		free(presence_info->pra_id);
		presence_info->pra_id = NULL;
	}
	if(presence_info->additional_pra_id) {
		free(presence_info->additional_pra_id);
		presence_info->additional_pra_id = NULL;
	}
	if(presence_info->presence_state) {
		presence_state_free(presence_info->presence_state);
		presence_info->presence_state = NULL;
	}
	if(presence_info->tracking_area_list) {
		list_for_each(presence_info->tracking_area_list, node) {
			tai_free(node->data);
		}
		list_free(presence_info->tracking_area_list);
		presence_info->tracking_area_list = NULL;
	}
	if(presence_info->ecgi_list) {
		list_for_each(presence_info->ecgi_list, node) {
			ecgi_free(node->data);
		}
		list_free(presence_info->ecgi_list);
		presence_info->ecgi_list = NULL;
	}
	if(presence_info->ncgi_list) {
		list_for_each(presence_info->ncgi_list, node) {
			ncgi_free(node->data);
		}
		list_free(presence_info->ncgi_list);
		presence_info->ncgi_list = NULL;
	}
	if(presence_info->global_ran_node_id_list) {
		list_for_each(presence_info->global_ran_node_id_list, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(presence_info->global_ran_node_id_list);
		presence_info->global_ran_node_id_list = NULL;
	}
	if(presence_info->globale_nb_id_list) {
		list_for_each(presence_info->globale_nb_id_list, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(presence_info->globale_nb_id_list);
		presence_info->globale_nb_id_list = NULL;
	}
	free(presence_info);
}

cJSON *presence_info_convertToJSON(presence_info_t *presence_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(presence_info == NULL) {
		printf("presence_info_convertToJSON() failed [PresenceInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(presence_info->pra_id) {
		if(cJSON_AddStringToObject(item, "praId",
		                           presence_info->pra_id) == NULL)
		{
			printf("presence_info_convertToJSON() failed [pra_id]");
			goto end;
		}
	}

	if(presence_info->additional_pra_id) {
		if(cJSON_AddStringToObject(item, "additionalPraId",
		                           presence_info->additional_pra_id) ==
		   NULL)
		{
			printf(
				"presence_info_convertToJSON() failed [additional_pra_id]");
			goto end;
		}
	}

	if(presence_info->presence_state) {
		cJSON *presence_state_local_JSON = presence_state_convertToJSON(
			presence_info->presence_state);
		if(presence_state_local_JSON == NULL) {
			printf(
				"presence_info_convertToJSON() failed [presence_state]");
			goto end;
		}
		cJSON_AddItemToObject(item, "presenceState",
		                      presence_state_local_JSON);
		if(item->child == NULL) {
			printf(
				"presence_info_convertToJSON() failed [presence_state]");
			goto end;
		}
	}

	if(presence_info->tracking_area_list) {
		cJSON *tracking_area_listList = cJSON_AddArrayToObject(item,
		                                                       "trackingAreaList");
		if(tracking_area_listList == NULL) {
			printf(
				"presence_info_convertToJSON() failed [tracking_area_list]");
			goto end;
		}
		list_for_each(presence_info->tracking_area_list, node) {
			cJSON *itemLocal = tai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"presence_info_convertToJSON() failed [tracking_area_list]");
				goto end;
			}
			cJSON_AddItemToArray(tracking_area_listList, itemLocal);
		}
	}

	if(presence_info->ecgi_list) {
		cJSON *ecgi_listList = cJSON_AddArrayToObject(item, "ecgiList");
		if(ecgi_listList == NULL) {
			printf(
				"presence_info_convertToJSON() failed [ecgi_list]");
			goto end;
		}
		list_for_each(presence_info->ecgi_list, node) {
			cJSON *itemLocal = ecgi_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"presence_info_convertToJSON() failed [ecgi_list]");
				goto end;
			}
			cJSON_AddItemToArray(ecgi_listList, itemLocal);
		}
	}

	if(presence_info->ncgi_list) {
		cJSON *ncgi_listList = cJSON_AddArrayToObject(item, "ncgiList");
		if(ncgi_listList == NULL) {
			printf(
				"presence_info_convertToJSON() failed [ncgi_list]");
			goto end;
		}
		list_for_each(presence_info->ncgi_list, node) {
			cJSON *itemLocal = ncgi_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"presence_info_convertToJSON() failed [ncgi_list]");
				goto end;
			}
			cJSON_AddItemToArray(ncgi_listList, itemLocal);
		}
	}

	if(presence_info->global_ran_node_id_list) {
		cJSON *global_ran_node_id_listList = cJSON_AddArrayToObject(
			item, "globalRanNodeIdList");
		if(global_ran_node_id_listList == NULL) {
			printf(
				"presence_info_convertToJSON() failed [global_ran_node_id_list]");
			goto end;
		}
		list_for_each(presence_info->global_ran_node_id_list, node) {
			cJSON *itemLocal = global_ran_node_id_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"presence_info_convertToJSON() failed [global_ran_node_id_list]");
				goto end;
			}
			cJSON_AddItemToArray(global_ran_node_id_listList,
			                     itemLocal);
		}
	}

	if(presence_info->globale_nb_id_list) {
		cJSON *globale_nb_id_listList = cJSON_AddArrayToObject(item,
		                                                       "globaleNbIdList");
		if(globale_nb_id_listList == NULL) {
			printf(
				"presence_info_convertToJSON() failed [globale_nb_id_list]");
			goto end;
		}
		list_for_each(presence_info->globale_nb_id_list, node) {
			cJSON *itemLocal = global_ran_node_id_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"presence_info_convertToJSON() failed [globale_nb_id_list]");
				goto end;
			}
			cJSON_AddItemToArray(globale_nb_id_listList, itemLocal);
		}
	}

end:
	return item;
}

presence_info_t *presence_info_parseFromJSON(cJSON *presence_infoJSON) {
	presence_info_t *presence_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pra_id = NULL;
	cJSON *additional_pra_id = NULL;
	cJSON *presence_state = NULL;
	presence_state_t *presence_state_local_nonprim = NULL;
	cJSON *tracking_area_list = NULL;
	list_t *tracking_area_listList = NULL;
	cJSON *ecgi_list = NULL;
	list_t *ecgi_listList = NULL;
	cJSON *ncgi_list = NULL;
	list_t *ncgi_listList = NULL;
	cJSON *global_ran_node_id_list = NULL;
	list_t *global_ran_node_id_listList = NULL;
	cJSON *globale_nb_id_list = NULL;
	list_t *globale_nb_id_listList = NULL;
	pra_id = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "praId");
	if(pra_id) {
		if(!cJSON_IsString(pra_id) &&
		   !cJSON_IsNull(pra_id))
		{
			printf("presence_info_parseFromJSON() failed [pra_id]");
			goto end;
		}
	}

	additional_pra_id = cJSON_GetObjectItemCaseSensitive(presence_infoJSON,
	                                                     "additionalPraId");
	if(additional_pra_id) {
		if(!cJSON_IsString(additional_pra_id) &&
		   !cJSON_IsNull(additional_pra_id))
		{
			printf(
				"presence_info_parseFromJSON() failed [additional_pra_id]");
			goto end;
		}
	}

	presence_state = cJSON_GetObjectItemCaseSensitive(presence_infoJSON,
	                                                  "presenceState");
	if(presence_state) {
		presence_state_local_nonprim = presence_state_parseFromJSON(
			presence_state);
		if(!presence_state_local_nonprim) {
			printf(
				"presence_state_parseFromJSON failed [presence_state]");
			goto end;
		}
	}

	tracking_area_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON,
	                                                      "trackingAreaList");
	if(tracking_area_list) {
		cJSON *tracking_area_list_local = NULL;
		if(!cJSON_IsArray(tracking_area_list)) {
			printf(
				"presence_info_parseFromJSON() failed [tracking_area_list]");
			goto end;
		}

		tracking_area_listList = list_create();

		cJSON_ArrayForEach(tracking_area_list_local,
		                   tracking_area_list) {
			if(!cJSON_IsObject(tracking_area_list_local)) {
				printf(
					"presence_info_parseFromJSON() failed [tracking_area_list]");
				goto end;
			}
			tai_t *tracking_area_listItem = tai_parseFromJSON(
				tracking_area_list_local);
			if(!tracking_area_listItem) {
				printf("No tracking_area_listItem");
				goto end;
			}
			list_add(tracking_area_listList,
			         tracking_area_listItem);
		}
	}

	ecgi_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON,
	                                             "ecgiList");
	if(ecgi_list) {
		cJSON *ecgi_list_local = NULL;
		if(!cJSON_IsArray(ecgi_list)) {
			printf(
				"presence_info_parseFromJSON() failed [ecgi_list]");
			goto end;
		}

		ecgi_listList = list_create();

		cJSON_ArrayForEach(ecgi_list_local, ecgi_list) {
			if(!cJSON_IsObject(ecgi_list_local)) {
				printf(
					"presence_info_parseFromJSON() failed [ecgi_list]");
				goto end;
			}
			ecgi_t *ecgi_listItem = ecgi_parseFromJSON(
				ecgi_list_local);
			if(!ecgi_listItem) {
				printf("No ecgi_listItem");
				goto end;
			}
			list_add(ecgi_listList, ecgi_listItem);
		}
	}

	ncgi_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON,
	                                             "ncgiList");
	if(ncgi_list) {
		cJSON *ncgi_list_local = NULL;
		if(!cJSON_IsArray(ncgi_list)) {
			printf(
				"presence_info_parseFromJSON() failed [ncgi_list]");
			goto end;
		}

		ncgi_listList = list_create();

		cJSON_ArrayForEach(ncgi_list_local, ncgi_list) {
			if(!cJSON_IsObject(ncgi_list_local)) {
				printf(
					"presence_info_parseFromJSON() failed [ncgi_list]");
				goto end;
			}
			ncgi_t *ncgi_listItem = ncgi_parseFromJSON(
				ncgi_list_local);
			if(!ncgi_listItem) {
				printf("No ncgi_listItem");
				goto end;
			}
			list_add(ncgi_listList, ncgi_listItem);
		}
	}

	global_ran_node_id_list = cJSON_GetObjectItemCaseSensitive(
		presence_infoJSON, "globalRanNodeIdList");
	if(global_ran_node_id_list) {
		cJSON *global_ran_node_id_list_local = NULL;
		if(!cJSON_IsArray(global_ran_node_id_list)) {
			printf(
				"presence_info_parseFromJSON() failed [global_ran_node_id_list]");
			goto end;
		}

		global_ran_node_id_listList = list_create();

		cJSON_ArrayForEach(global_ran_node_id_list_local,
		                   global_ran_node_id_list) {
			if(!cJSON_IsObject(global_ran_node_id_list_local)) {
				printf(
					"presence_info_parseFromJSON() failed [global_ran_node_id_list]");
				goto end;
			}
			global_ran_node_id_t *global_ran_node_id_listItem =
				global_ran_node_id_parseFromJSON(
					global_ran_node_id_list_local);
			if(!global_ran_node_id_listItem) {
				printf("No global_ran_node_id_listItem");
				goto end;
			}
			list_add(global_ran_node_id_listList,
			         global_ran_node_id_listItem);
		}
	}

	globale_nb_id_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON,
	                                                      "globaleNbIdList");
	if(globale_nb_id_list) {
		cJSON *globale_nb_id_list_local = NULL;
		if(!cJSON_IsArray(globale_nb_id_list)) {
			printf(
				"presence_info_parseFromJSON() failed [globale_nb_id_list]");
			goto end;
		}

		globale_nb_id_listList = list_create();

		cJSON_ArrayForEach(globale_nb_id_list_local,
		                   globale_nb_id_list) {
			if(!cJSON_IsObject(globale_nb_id_list_local)) {
				printf(
					"presence_info_parseFromJSON() failed [globale_nb_id_list]");
				goto end;
			}
			global_ran_node_id_t *globale_nb_id_listItem =
				global_ran_node_id_parseFromJSON(
					globale_nb_id_list_local);
			if(!globale_nb_id_listItem) {
				printf("No globale_nb_id_listItem");
				goto end;
			}
			list_add(globale_nb_id_listList,
			         globale_nb_id_listItem);
		}
	}

	presence_info_local_var = presence_info_create(
		pra_id &&
		!cJSON_IsNull(pra_id) ? strdup(pra_id->valuestring) : NULL,
		additional_pra_id &&
		!cJSON_IsNull(additional_pra_id) ? strdup(additional_pra_id->
		                                          valuestring) : NULL,
		presence_state ? presence_state_local_nonprim : NULL,
		tracking_area_list ? tracking_area_listList : NULL,
		ecgi_list ? ecgi_listList : NULL,
		ncgi_list ? ncgi_listList : NULL,
		global_ran_node_id_list ? global_ran_node_id_listList : NULL,
		globale_nb_id_list ? globale_nb_id_listList : NULL
		);

	return presence_info_local_var;
end:
	if(presence_state_local_nonprim) {
		presence_state_free(presence_state_local_nonprim);
		presence_state_local_nonprim = NULL;
	}
	if(tracking_area_listList) {
		list_for_each(tracking_area_listList, node) {
			tai_free(node->data);
		}
		list_free(tracking_area_listList);
		tracking_area_listList = NULL;
	}
	if(ecgi_listList) {
		list_for_each(ecgi_listList, node) {
			ecgi_free(node->data);
		}
		list_free(ecgi_listList);
		ecgi_listList = NULL;
	}
	if(ncgi_listList) {
		list_for_each(ncgi_listList, node) {
			ncgi_free(node->data);
		}
		list_free(ncgi_listList);
		ncgi_listList = NULL;
	}
	if(global_ran_node_id_listList) {
		list_for_each(global_ran_node_id_listList, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(global_ran_node_id_listList);
		global_ran_node_id_listList = NULL;
	}
	if(globale_nb_id_listList) {
		list_for_each(globale_nb_id_listList, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(globale_nb_id_listList);
		globale_nb_id_listList = NULL;
	}
	return NULL;
}

presence_info_t *presence_info_copy(presence_info_t	*dst,
                                    presence_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = presence_info_convertToJSON(src);
	if(!item) {
		printf("presence_info_convertToJSON() failed");
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

	presence_info_free(dst);
	dst = presence_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
