#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "wireline_service_area_restriction.h"

wireline_service_area_restriction_t *wireline_service_area_restriction_create(
	restriction_type_t *restriction_type, list_t *areas) {
	wireline_service_area_restriction_t *
	        wireline_service_area_restriction_local_var =
		malloc(sizeof(wireline_service_area_restriction_t));

	wireline_service_area_restriction_local_var->restriction_type =
		restriction_type;
	wireline_service_area_restriction_local_var->areas = areas;

	return wireline_service_area_restriction_local_var;
}

void wireline_service_area_restriction_free(
	wireline_service_area_restriction_t *wireline_service_area_restriction)
{
	lnode_t *node = NULL;

	if(NULL == wireline_service_area_restriction) {
		return;
	}
	if(wireline_service_area_restriction->restriction_type) {
		restriction_type_free(
			wireline_service_area_restriction->restriction_type);
		wireline_service_area_restriction->restriction_type = NULL;
	}
	if(wireline_service_area_restriction->areas) {
		list_for_each(wireline_service_area_restriction->areas, node) {
			wireline_area_free(node->data);
		}
		list_free(wireline_service_area_restriction->areas);
		wireline_service_area_restriction->areas = NULL;
	}
	free(wireline_service_area_restriction);
}

cJSON *wireline_service_area_restriction_convertToJSON(
	wireline_service_area_restriction_t *wireline_service_area_restriction)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(wireline_service_area_restriction == NULL) {
		printf(
			"wireline_service_area_restriction_convertToJSON() failed [WirelineServiceAreaRestriction]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(wireline_service_area_restriction->restriction_type) {
		cJSON *restriction_type_local_JSON =
			restriction_type_convertToJSON(
				wireline_service_area_restriction->restriction_type);
		if(restriction_type_local_JSON == NULL) {
			printf(
				"wireline_service_area_restriction_convertToJSON() failed [restriction_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "restrictionType",
		                      restriction_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"wireline_service_area_restriction_convertToJSON() failed [restriction_type]");
			goto end;
		}
	}

	if(wireline_service_area_restriction->areas) {
		cJSON *areasList = cJSON_AddArrayToObject(item, "areas");
		if(areasList == NULL) {
			printf(
				"wireline_service_area_restriction_convertToJSON() failed [areas]");
			goto end;
		}
		list_for_each(wireline_service_area_restriction->areas, node) {
			cJSON *itemLocal = wireline_area_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"wireline_service_area_restriction_convertToJSON() failed [areas]");
				goto end;
			}
			cJSON_AddItemToArray(areasList, itemLocal);
		}
	}

end:
	return item;
}

wireline_service_area_restriction_t *
wireline_service_area_restriction_parseFromJSON(
	cJSON *wireline_service_area_restrictionJSON) {
	wireline_service_area_restriction_t *
	        wireline_service_area_restriction_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *restriction_type = NULL;
	restriction_type_t *restriction_type_local_nonprim = NULL;
	cJSON *areas = NULL;
	list_t *areasList = NULL;
	restriction_type = cJSON_GetObjectItemCaseSensitive(
		wireline_service_area_restrictionJSON, "restrictionType");
	if(restriction_type) {
		restriction_type_local_nonprim = restriction_type_parseFromJSON(
			restriction_type);
		if(!restriction_type_local_nonprim) {
			printf(
				"restriction_type_parseFromJSON failed [restriction_type]");
			goto end;
		}
	}

	areas = cJSON_GetObjectItemCaseSensitive(
		wireline_service_area_restrictionJSON, "areas");
	if(areas) {
		cJSON *areas_local = NULL;
		if(!cJSON_IsArray(areas)) {
			printf(
				"wireline_service_area_restriction_parseFromJSON() failed [areas]");
			goto end;
		}

		areasList = list_create();

		cJSON_ArrayForEach(areas_local, areas) {
			if(!cJSON_IsObject(areas_local)) {
				printf(
					"wireline_service_area_restriction_parseFromJSON() failed [areas]");
				goto end;
			}
			wireline_area_t *areasItem =
				wireline_area_parseFromJSON(areas_local);
			if(!areasItem) {
				printf("No areasItem");
				goto end;
			}
			list_add(areasList, areasItem);
		}
	}

	wireline_service_area_restriction_local_var =
		wireline_service_area_restriction_create(
			restriction_type ? restriction_type_local_nonprim : NULL,
			areas ? areasList : NULL
			);

	return wireline_service_area_restriction_local_var;
end:
	if(restriction_type_local_nonprim) {
		restriction_type_free(restriction_type_local_nonprim);
		restriction_type_local_nonprim = NULL;
	}
	if(areasList) {
		list_for_each(areasList, node) {
			wireline_area_free(node->data);
		}
		list_free(areasList);
		areasList = NULL;
	}
	return NULL;
}

wireline_service_area_restriction_t *wireline_service_area_restriction_copy(
	wireline_service_area_restriction_t	*dst,
	wireline_service_area_restriction_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = wireline_service_area_restriction_convertToJSON(src);
	if(!item) {
		printf(
			"wireline_service_area_restriction_convertToJSON() failed");
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

	wireline_service_area_restriction_free(dst);
	dst = wireline_service_area_restriction_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
