#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "geographical_area.h"

geographical_area_t *geographical_area_create(civic_address_t	*civic_address,
                                              geographic_area_t *shapes) {
	geographical_area_t *geographical_area_local_var =
		malloc(sizeof(geographical_area_t));

	geographical_area_local_var->civic_address = civic_address;
	geographical_area_local_var->shapes = shapes;

	return geographical_area_local_var;
}

void geographical_area_free(geographical_area_t *geographical_area) {
	lnode_t *node = NULL;

	if(NULL == geographical_area) {
		return;
	}
	if(geographical_area->civic_address) {
		civic_address_free(geographical_area->civic_address);
		geographical_area->civic_address = NULL;
	}
	if(geographical_area->shapes) {
		geographic_area_free(geographical_area->shapes);
		geographical_area->shapes = NULL;
	}
	free(geographical_area);
}

cJSON *geographical_area_convertToJSON(geographical_area_t *geographical_area) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(geographical_area == NULL) {
		printf(
			"geographical_area_convertToJSON() failed [GeographicalArea]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(geographical_area->civic_address) {
		cJSON *civic_address_local_JSON = civic_address_convertToJSON(
			geographical_area->civic_address);
		if(civic_address_local_JSON == NULL) {
			printf(
				"geographical_area_convertToJSON() failed [civic_address]");
			goto end;
		}
		cJSON_AddItemToObject(item, "civicAddress",
		                      civic_address_local_JSON);
		if(item->child == NULL) {
			printf(
				"geographical_area_convertToJSON() failed [civic_address]");
			goto end;
		}
	}

	if(geographical_area->shapes) {
		cJSON *shapes_local_JSON = geographic_area_convertToJSON(
			geographical_area->shapes);
		if(shapes_local_JSON == NULL) {
			printf(
				"geographical_area_convertToJSON() failed [shapes]");
			goto end;
		}
		cJSON_AddItemToObject(item, "shapes", shapes_local_JSON);
		if(item->child == NULL) {
			printf(
				"geographical_area_convertToJSON() failed [shapes]");
			goto end;
		}
	}

end:
	return item;
}

geographical_area_t *geographical_area_parseFromJSON(
	cJSON *geographical_areaJSON) {
	geographical_area_t *geographical_area_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *civic_address = NULL;
	civic_address_t *civic_address_local_nonprim = NULL;
	cJSON *shapes = NULL;
	geographic_area_t *shapes_local_nonprim = NULL;
	civic_address = cJSON_GetObjectItemCaseSensitive(geographical_areaJSON,
	                                                 "civicAddress");
	if(civic_address) {
		civic_address_local_nonprim = civic_address_parseFromJSON(
			civic_address);
		if(!civic_address_local_nonprim) {
			printf(
				"civic_address_parseFromJSON failed [civic_address]");
			goto end;
		}
	}

	shapes = cJSON_GetObjectItemCaseSensitive(geographical_areaJSON,
	                                          "shapes");
	if(shapes) {
		shapes_local_nonprim = geographic_area_parseFromJSON(shapes);
		if(!shapes_local_nonprim) {
			printf("geographic_area_parseFromJSON failed [shapes]");
			goto end;
		}
	}

	geographical_area_local_var = geographical_area_create(
		civic_address ? civic_address_local_nonprim : NULL,
		shapes ? shapes_local_nonprim : NULL
		);

	return geographical_area_local_var;
end:
	if(civic_address_local_nonprim) {
		civic_address_free(civic_address_local_nonprim);
		civic_address_local_nonprim = NULL;
	}
	if(shapes_local_nonprim) {
		geographic_area_free(shapes_local_nonprim);
		shapes_local_nonprim = NULL;
	}
	return NULL;
}

geographical_area_t *geographical_area_copy(geographical_area_t *dst,
                                            geographical_area_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = geographical_area_convertToJSON(src);
	if(!item) {
		printf("geographical_area_convertToJSON() failed");
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

	geographical_area_free(dst);
	dst = geographical_area_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
