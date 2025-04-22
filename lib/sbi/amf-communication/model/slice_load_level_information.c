#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "slice_load_level_information.h"

slice_load_level_information_t *slice_load_level_information_create(
	int load_level_information, list_t *snssais) {
	slice_load_level_information_t *slice_load_level_information_local_var =
		malloc(sizeof(slice_load_level_information_t));

	slice_load_level_information_local_var->load_level_information =
		load_level_information;
	slice_load_level_information_local_var->snssais = snssais;

	return slice_load_level_information_local_var;
}

void slice_load_level_information_free(
	slice_load_level_information_t *slice_load_level_information) {
	lnode_t *node = NULL;

	if(NULL == slice_load_level_information) {
		return;
	}
	if(slice_load_level_information->snssais) {
		list_for_each(slice_load_level_information->snssais, node) {
			snssai_free(node->data);
		}
		list_free(slice_load_level_information->snssais);
		slice_load_level_information->snssais = NULL;
	}
	free(slice_load_level_information);
}

cJSON *slice_load_level_information_convertToJSON(
	slice_load_level_information_t *slice_load_level_information) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(slice_load_level_information == NULL) {
		printf(
			"slice_load_level_information_convertToJSON() failed [SliceLoadLevelInformation]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "loadLevelInformation",
	                           slice_load_level_information->
	                           load_level_information) == NULL)
	{
		printf(
			"slice_load_level_information_convertToJSON() failed [load_level_information]");
		goto end;
	}

	if(!slice_load_level_information->snssais) {
		printf(
			"slice_load_level_information_convertToJSON() failed [snssais]");
		return NULL;
	}
	cJSON *snssaisList = cJSON_AddArrayToObject(item, "snssais");
	if(snssaisList == NULL) {
		printf(
			"slice_load_level_information_convertToJSON() failed [snssais]");
		goto end;
	}
	list_for_each(slice_load_level_information->snssais, node) {
		cJSON *itemLocal = snssai_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"slice_load_level_information_convertToJSON() failed [snssais]");
			goto end;
		}
		cJSON_AddItemToArray(snssaisList, itemLocal);
	}

end:
	return item;
}

slice_load_level_information_t *slice_load_level_information_parseFromJSON(
	cJSON *slice_load_level_informationJSON) {
	slice_load_level_information_t *slice_load_level_information_local_var =
		NULL;
	lnode_t *node = NULL;
	cJSON *load_level_information = NULL;
	cJSON *snssais = NULL;
	list_t *snssaisList = NULL;
	load_level_information = cJSON_GetObjectItemCaseSensitive(
		slice_load_level_informationJSON, "loadLevelInformation");
	if(!load_level_information) {
		printf(
			"slice_load_level_information_parseFromJSON() failed [load_level_information]");
		goto end;
	}
	if(!cJSON_IsNumber(load_level_information)) {
		printf(
			"slice_load_level_information_parseFromJSON() failed [load_level_information]");
		goto end;
	}

	snssais = cJSON_GetObjectItemCaseSensitive(
		slice_load_level_informationJSON, "snssais");
	if(!snssais) {
		printf(
			"slice_load_level_information_parseFromJSON() failed [snssais]");
		goto end;
	}
	cJSON *snssais_local = NULL;
	if(!cJSON_IsArray(snssais)) {
		printf(
			"slice_load_level_information_parseFromJSON() failed [snssais]");
		goto end;
	}

	snssaisList = list_create();

	cJSON_ArrayForEach(snssais_local, snssais) {
		if(!cJSON_IsObject(snssais_local)) {
			printf(
				"slice_load_level_information_parseFromJSON() failed [snssais]");
			goto end;
		}
		snssai_t *snssaisItem = snssai_parseFromJSON(snssais_local);
		if(!snssaisItem) {
			printf("No snssaisItem");
			goto end;
		}
		list_add(snssaisList, snssaisItem);
	}

	slice_load_level_information_local_var =
		slice_load_level_information_create(

			load_level_information->valuedouble,
			snssaisList
			);

	return slice_load_level_information_local_var;
end:
	if(snssaisList) {
		list_for_each(snssaisList, node) {
			snssai_free(node->data);
		}
		list_free(snssaisList);
		snssaisList = NULL;
	}
	return NULL;
}

slice_load_level_information_t *slice_load_level_information_copy(
	slice_load_level_information_t	*dst,
	slice_load_level_information_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = slice_load_level_information_convertToJSON(src);
	if(!item) {
		printf("slice_load_level_information_convertToJSON() failed");
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

	slice_load_level_information_free(dst);
	dst = slice_load_level_information_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
