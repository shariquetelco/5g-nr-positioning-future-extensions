#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "network_area_info_1.h"

network_area_info_1_t *network_area_info_1_create(list_t *ecgis, list_t *ncgis,
                                                  list_t *g_ran_node_ids,
                                                  list_t *tais) {
	network_area_info_1_t *network_area_info_1_local_var =
		malloc(sizeof(network_area_info_1_t));

	network_area_info_1_local_var->ecgis = ecgis;
	network_area_info_1_local_var->ncgis = ncgis;
	network_area_info_1_local_var->g_ran_node_ids = g_ran_node_ids;
	network_area_info_1_local_var->tais = tais;

	return network_area_info_1_local_var;
}

void network_area_info_1_free(network_area_info_1_t *network_area_info_1) {
	lnode_t *node = NULL;

	if(NULL == network_area_info_1) {
		return;
	}
	if(network_area_info_1->ecgis) {
		list_for_each(network_area_info_1->ecgis, node) {
			ecgi_free(node->data);
		}
		list_free(network_area_info_1->ecgis);
		network_area_info_1->ecgis = NULL;
	}
	if(network_area_info_1->ncgis) {
		list_for_each(network_area_info_1->ncgis, node) {
			ncgi_free(node->data);
		}
		list_free(network_area_info_1->ncgis);
		network_area_info_1->ncgis = NULL;
	}
	if(network_area_info_1->g_ran_node_ids) {
		list_for_each(network_area_info_1->g_ran_node_ids, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(network_area_info_1->g_ran_node_ids);
		network_area_info_1->g_ran_node_ids = NULL;
	}
	if(network_area_info_1->tais) {
		list_for_each(network_area_info_1->tais, node) {
			tai_free(node->data);
		}
		list_free(network_area_info_1->tais);
		network_area_info_1->tais = NULL;
	}
	free(network_area_info_1);
}

cJSON *network_area_info_1_convertToJSON(
	network_area_info_1_t *network_area_info_1) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(network_area_info_1 == NULL) {
		printf(
			"network_area_info_1_convertToJSON() failed [NetworkAreaInfo_1]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(network_area_info_1->ecgis) {
		cJSON *ecgisList = cJSON_AddArrayToObject(item, "ecgis");
		if(ecgisList == NULL) {
			printf(
				"network_area_info_1_convertToJSON() failed [ecgis]");
			goto end;
		}
		list_for_each(network_area_info_1->ecgis, node) {
			cJSON *itemLocal = ecgi_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"network_area_info_1_convertToJSON() failed [ecgis]");
				goto end;
			}
			cJSON_AddItemToArray(ecgisList, itemLocal);
		}
	}

	if(network_area_info_1->ncgis) {
		cJSON *ncgisList = cJSON_AddArrayToObject(item, "ncgis");
		if(ncgisList == NULL) {
			printf(
				"network_area_info_1_convertToJSON() failed [ncgis]");
			goto end;
		}
		list_for_each(network_area_info_1->ncgis, node) {
			cJSON *itemLocal = ncgi_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"network_area_info_1_convertToJSON() failed [ncgis]");
				goto end;
			}
			cJSON_AddItemToArray(ncgisList, itemLocal);
		}
	}

	if(network_area_info_1->g_ran_node_ids) {
		cJSON *g_ran_node_idsList = cJSON_AddArrayToObject(item,
		                                                   "gRanNodeIds");
		if(g_ran_node_idsList == NULL) {
			printf(
				"network_area_info_1_convertToJSON() failed [g_ran_node_ids]");
			goto end;
		}
		list_for_each(network_area_info_1->g_ran_node_ids, node) {
			cJSON *itemLocal = global_ran_node_id_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"network_area_info_1_convertToJSON() failed [g_ran_node_ids]");
				goto end;
			}
			cJSON_AddItemToArray(g_ran_node_idsList, itemLocal);
		}
	}

	if(network_area_info_1->tais) {
		cJSON *taisList = cJSON_AddArrayToObject(item, "tais");
		if(taisList == NULL) {
			printf(
				"network_area_info_1_convertToJSON() failed [tais]");
			goto end;
		}
		list_for_each(network_area_info_1->tais, node) {
			cJSON *itemLocal = tai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"network_area_info_1_convertToJSON() failed [tais]");
				goto end;
			}
			cJSON_AddItemToArray(taisList, itemLocal);
		}
	}

end:
	return item;
}

network_area_info_1_t *network_area_info_1_parseFromJSON(
	cJSON *network_area_info_1JSON) {
	network_area_info_1_t *network_area_info_1_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ecgis = NULL;
	list_t *ecgisList = NULL;
	cJSON *ncgis = NULL;
	list_t *ncgisList = NULL;
	cJSON *g_ran_node_ids = NULL;
	list_t *g_ran_node_idsList = NULL;
	cJSON *tais = NULL;
	list_t *taisList = NULL;
	ecgis = cJSON_GetObjectItemCaseSensitive(network_area_info_1JSON,
	                                         "ecgis");
	if(ecgis) {
		cJSON *ecgis_local = NULL;
		if(!cJSON_IsArray(ecgis)) {
			printf(
				"network_area_info_1_parseFromJSON() failed [ecgis]");
			goto end;
		}

		ecgisList = list_create();

		cJSON_ArrayForEach(ecgis_local, ecgis) {
			if(!cJSON_IsObject(ecgis_local)) {
				printf(
					"network_area_info_1_parseFromJSON() failed [ecgis]");
				goto end;
			}
			ecgi_t *ecgisItem = ecgi_parseFromJSON(ecgis_local);
			if(!ecgisItem) {
				printf("No ecgisItem");
				goto end;
			}
			list_add(ecgisList, ecgisItem);
		}
	}

	ncgis = cJSON_GetObjectItemCaseSensitive(network_area_info_1JSON,
	                                         "ncgis");
	if(ncgis) {
		cJSON *ncgis_local = NULL;
		if(!cJSON_IsArray(ncgis)) {
			printf(
				"network_area_info_1_parseFromJSON() failed [ncgis]");
			goto end;
		}

		ncgisList = list_create();

		cJSON_ArrayForEach(ncgis_local, ncgis) {
			if(!cJSON_IsObject(ncgis_local)) {
				printf(
					"network_area_info_1_parseFromJSON() failed [ncgis]");
				goto end;
			}
			ncgi_t *ncgisItem = ncgi_parseFromJSON(ncgis_local);
			if(!ncgisItem) {
				printf("No ncgisItem");
				goto end;
			}
			list_add(ncgisList, ncgisItem);
		}
	}

	g_ran_node_ids = cJSON_GetObjectItemCaseSensitive(
		network_area_info_1JSON, "gRanNodeIds");
	if(g_ran_node_ids) {
		cJSON *g_ran_node_ids_local = NULL;
		if(!cJSON_IsArray(g_ran_node_ids)) {
			printf(
				"network_area_info_1_parseFromJSON() failed [g_ran_node_ids]");
			goto end;
		}

		g_ran_node_idsList = list_create();

		cJSON_ArrayForEach(g_ran_node_ids_local, g_ran_node_ids) {
			if(!cJSON_IsObject(g_ran_node_ids_local)) {
				printf(
					"network_area_info_1_parseFromJSON() failed [g_ran_node_ids]");
				goto end;
			}
			global_ran_node_id_t *g_ran_node_idsItem =
				global_ran_node_id_parseFromJSON(
					g_ran_node_ids_local);
			if(!g_ran_node_idsItem) {
				printf("No g_ran_node_idsItem");
				goto end;
			}
			list_add(g_ran_node_idsList, g_ran_node_idsItem);
		}
	}

	tais =
		cJSON_GetObjectItemCaseSensitive(network_area_info_1JSON,
		                                 "tais");
	if(tais) {
		cJSON *tais_local = NULL;
		if(!cJSON_IsArray(tais)) {
			printf(
				"network_area_info_1_parseFromJSON() failed [tais]");
			goto end;
		}

		taisList = list_create();

		cJSON_ArrayForEach(tais_local, tais) {
			if(!cJSON_IsObject(tais_local)) {
				printf(
					"network_area_info_1_parseFromJSON() failed [tais]");
				goto end;
			}
			tai_t *taisItem = tai_parseFromJSON(tais_local);
			if(!taisItem) {
				printf("No taisItem");
				goto end;
			}
			list_add(taisList, taisItem);
		}
	}

	network_area_info_1_local_var = network_area_info_1_create(
		ecgis ? ecgisList : NULL,
		ncgis ? ncgisList : NULL,
		g_ran_node_ids ? g_ran_node_idsList : NULL,
		tais ? taisList : NULL
		);

	return network_area_info_1_local_var;
end:
	if(ecgisList) {
		list_for_each(ecgisList, node) {
			ecgi_free(node->data);
		}
		list_free(ecgisList);
		ecgisList = NULL;
	}
	if(ncgisList) {
		list_for_each(ncgisList, node) {
			ncgi_free(node->data);
		}
		list_free(ncgisList);
		ncgisList = NULL;
	}
	if(g_ran_node_idsList) {
		list_for_each(g_ran_node_idsList, node) {
			global_ran_node_id_free(node->data);
		}
		list_free(g_ran_node_idsList);
		g_ran_node_idsList = NULL;
	}
	if(taisList) {
		list_for_each(taisList, node) {
			tai_free(node->data);
		}
		list_free(taisList);
		taisList = NULL;
	}
	return NULL;
}

network_area_info_1_t *network_area_info_1_copy(network_area_info_1_t	*dst,
                                                network_area_info_1_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = network_area_info_1_convertToJSON(src);
	if(!item) {
		printf("network_area_info_1_convertToJSON() failed");
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

	network_area_info_1_free(dst);
	dst = network_area_info_1_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
