#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wireline_area.h"

wireline_area_t *wireline_area_create(list_t *global_line_ids,
                                      list_t *hfc_n_ids, char *area_code_b,
                                      char *area_code_c,
                                      list_t *comb_gci_and_hfc_n_ids) {
	wireline_area_t *wireline_area_local_var = malloc(
		sizeof(wireline_area_t));

	wireline_area_local_var->global_line_ids = global_line_ids;
	wireline_area_local_var->hfc_n_ids = hfc_n_ids;
	wireline_area_local_var->area_code_b = area_code_b;
	wireline_area_local_var->area_code_c = area_code_c;
	wireline_area_local_var->comb_gci_and_hfc_n_ids =
		comb_gci_and_hfc_n_ids;

	return wireline_area_local_var;
}

void wireline_area_free(wireline_area_t *wireline_area) {
	lnode_t *node = NULL;

	if(NULL == wireline_area) {
		return;
	}
	if(wireline_area->global_line_ids) {
		list_for_each(wireline_area->global_line_ids, node) {
			free(node->data);
		}
		list_free(wireline_area->global_line_ids);
		wireline_area->global_line_ids = NULL;
	}
	if(wireline_area->hfc_n_ids) {
		list_for_each(wireline_area->hfc_n_ids, node) {
			free(node->data);
		}
		list_free(wireline_area->hfc_n_ids);
		wireline_area->hfc_n_ids = NULL;
	}
	if(wireline_area->area_code_b) {
		free(wireline_area->area_code_b);
		wireline_area->area_code_b = NULL;
	}
	if(wireline_area->area_code_c) {
		free(wireline_area->area_code_c);
		wireline_area->area_code_c = NULL;
	}
	if(wireline_area->comb_gci_and_hfc_n_ids) {
		list_for_each(wireline_area->comb_gci_and_hfc_n_ids, node) {
			comb_gci_and_hfc_n_ids_free(node->data);
		}
		list_free(wireline_area->comb_gci_and_hfc_n_ids);
		wireline_area->comb_gci_and_hfc_n_ids = NULL;
	}
	free(wireline_area);
}

cJSON *wireline_area_convertToJSON(wireline_area_t *wireline_area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(wireline_area == NULL) {
		printf("wireline_area_convertToJSON() failed [WirelineArea]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(wireline_area->global_line_ids) {
		cJSON *global_line_idsList = cJSON_AddArrayToObject(item,
		                                                    "globalLineIds");
		if(global_line_idsList == NULL) {
			printf(
				"wireline_area_convertToJSON() failed [global_line_ids]");
			goto end;
		}
		list_for_each(wireline_area->global_line_ids, node) {
			if(cJSON_AddStringToObject(global_line_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"wireline_area_convertToJSON() failed [global_line_ids]");
				goto end;
			}
		}
	}

	if(wireline_area->hfc_n_ids) {
		cJSON *hfc_n_idsList = cJSON_AddArrayToObject(item, "hfcNIds");
		if(hfc_n_idsList == NULL) {
			printf(
				"wireline_area_convertToJSON() failed [hfc_n_ids]");
			goto end;
		}
		list_for_each(wireline_area->hfc_n_ids, node) {
			if(cJSON_AddStringToObject(hfc_n_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"wireline_area_convertToJSON() failed [hfc_n_ids]");
				goto end;
			}
		}
	}

	if(wireline_area->area_code_b) {
		if(cJSON_AddStringToObject(item, "areaCodeB",
		                           wireline_area->area_code_b) == NULL)
		{
			printf(
				"wireline_area_convertToJSON() failed [area_code_b]");
			goto end;
		}
	}

	if(wireline_area->area_code_c) {
		if(cJSON_AddStringToObject(item, "areaCodeC",
		                           wireline_area->area_code_c) == NULL)
		{
			printf(
				"wireline_area_convertToJSON() failed [area_code_c]");
			goto end;
		}
	}

	if(wireline_area->comb_gci_and_hfc_n_ids) {
		cJSON *comb_gci_and_hfc_n_idsList = cJSON_AddArrayToObject(item,
		                                                           "combGciAndHfcNIds");
		if(comb_gci_and_hfc_n_idsList == NULL) {
			printf(
				"wireline_area_convertToJSON() failed [comb_gci_and_hfc_n_ids]");
			goto end;
		}
		list_for_each(wireline_area->comb_gci_and_hfc_n_ids, node) {
			cJSON *itemLocal = comb_gci_and_hfc_n_ids_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"wireline_area_convertToJSON() failed [comb_gci_and_hfc_n_ids]");
				goto end;
			}
			cJSON_AddItemToArray(comb_gci_and_hfc_n_idsList,
			                     itemLocal);
		}
	}

end:
	return item;
}

wireline_area_t *wireline_area_parseFromJSON(cJSON *wireline_areaJSON) {
	wireline_area_t *wireline_area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *global_line_ids = NULL;
	list_t *global_line_idsList = NULL;
	cJSON *hfc_n_ids = NULL;
	list_t *hfc_n_idsList = NULL;
	cJSON *area_code_b = NULL;
	cJSON *area_code_c = NULL;
	cJSON *comb_gci_and_hfc_n_ids = NULL;
	list_t *comb_gci_and_hfc_n_idsList = NULL;
	global_line_ids = cJSON_GetObjectItemCaseSensitive(wireline_areaJSON,
	                                                   "globalLineIds");
	if(global_line_ids) {
		cJSON *global_line_ids_local = NULL;
		if(!cJSON_IsArray(global_line_ids)) {
			printf(
				"wireline_area_parseFromJSON() failed [global_line_ids]");
			goto end;
		}

		global_line_idsList = list_create();

		cJSON_ArrayForEach(global_line_ids_local, global_line_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(global_line_ids_local)) {
				printf(
					"wireline_area_parseFromJSON() failed [global_line_ids]");
				goto end;
			}
			list_add(global_line_idsList,
			         strdup(global_line_ids_local->valuestring));
		}
	}

	hfc_n_ids = cJSON_GetObjectItemCaseSensitive(wireline_areaJSON,
	                                             "hfcNIds");
	if(hfc_n_ids) {
		cJSON *hfc_n_ids_local = NULL;
		if(!cJSON_IsArray(hfc_n_ids)) {
			printf(
				"wireline_area_parseFromJSON() failed [hfc_n_ids]");
			goto end;
		}

		hfc_n_idsList = list_create();

		cJSON_ArrayForEach(hfc_n_ids_local, hfc_n_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(hfc_n_ids_local)) {
				printf(
					"wireline_area_parseFromJSON() failed [hfc_n_ids]");
				goto end;
			}
			list_add(hfc_n_idsList,
			         strdup(hfc_n_ids_local->valuestring));
		}
	}

	area_code_b = cJSON_GetObjectItemCaseSensitive(wireline_areaJSON,
	                                               "areaCodeB");
	if(area_code_b) {
		if(!cJSON_IsString(area_code_b) &&
		   !cJSON_IsNull(area_code_b))
		{
			printf(
				"wireline_area_parseFromJSON() failed [area_code_b]");
			goto end;
		}
	}

	area_code_c = cJSON_GetObjectItemCaseSensitive(wireline_areaJSON,
	                                               "areaCodeC");
	if(area_code_c) {
		if(!cJSON_IsString(area_code_c) &&
		   !cJSON_IsNull(area_code_c))
		{
			printf(
				"wireline_area_parseFromJSON() failed [area_code_c]");
			goto end;
		}
	}

	comb_gci_and_hfc_n_ids = cJSON_GetObjectItemCaseSensitive(
		wireline_areaJSON, "combGciAndHfcNIds");
	if(comb_gci_and_hfc_n_ids) {
		cJSON *comb_gci_and_hfc_n_ids_local = NULL;
		if(!cJSON_IsArray(comb_gci_and_hfc_n_ids)) {
			printf(
				"wireline_area_parseFromJSON() failed [comb_gci_and_hfc_n_ids]");
			goto end;
		}

		comb_gci_and_hfc_n_idsList = list_create();

		cJSON_ArrayForEach(comb_gci_and_hfc_n_ids_local,
		                   comb_gci_and_hfc_n_ids) {
			if(!cJSON_IsObject(comb_gci_and_hfc_n_ids_local)) {
				printf(
					"wireline_area_parseFromJSON() failed [comb_gci_and_hfc_n_ids]");
				goto end;
			}
			comb_gci_and_hfc_n_ids_t *comb_gci_and_hfc_n_idsItem =
				comb_gci_and_hfc_n_ids_parseFromJSON(
					comb_gci_and_hfc_n_ids_local);
			if(!comb_gci_and_hfc_n_idsItem) {
				printf("No comb_gci_and_hfc_n_idsItem");
				goto end;
			}
			list_add(comb_gci_and_hfc_n_idsList,
			         comb_gci_and_hfc_n_idsItem);
		}
	}

	wireline_area_local_var = wireline_area_create(
		global_line_ids ? global_line_idsList : NULL,
		hfc_n_ids ? hfc_n_idsList : NULL,
		area_code_b &&
		!cJSON_IsNull(area_code_b) ? strdup(
			area_code_b->valuestring) : NULL,
		area_code_c &&
		!cJSON_IsNull(area_code_c) ? strdup(
			area_code_c->valuestring) : NULL,
		comb_gci_and_hfc_n_ids ? comb_gci_and_hfc_n_idsList : NULL
		);

	return wireline_area_local_var;
end:
	if(global_line_idsList) {
		list_for_each(global_line_idsList, node) {
			free(node->data);
		}
		list_free(global_line_idsList);
		global_line_idsList = NULL;
	}
	if(hfc_n_idsList) {
		list_for_each(hfc_n_idsList, node) {
			free(node->data);
		}
		list_free(hfc_n_idsList);
		hfc_n_idsList = NULL;
	}
	if(comb_gci_and_hfc_n_idsList) {
		list_for_each(comb_gci_and_hfc_n_idsList, node) {
			comb_gci_and_hfc_n_ids_free(node->data);
		}
		list_free(comb_gci_and_hfc_n_idsList);
		comb_gci_and_hfc_n_idsList = NULL;
	}
	return NULL;
}

wireline_area_t *wireline_area_copy(wireline_area_t	*dst,
                                    wireline_area_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = wireline_area_convertToJSON(src);
	if(!item) {
		printf("wireline_area_convertToJSON() failed");
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

	wireline_area_free(dst);
	dst = wireline_area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
