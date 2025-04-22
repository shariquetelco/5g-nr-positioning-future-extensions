#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "service_area_restriction.h"

service_area_restriction_t *service_area_restriction_create(
	restriction_type_t *restriction_type, list_t *areas,
	bool is_max_num_of_tas, int max_num_of_tas,
	bool is_max_num_of_tas_for_not_allowed_areas,
	int max_num_of_tas_for_not_allowed_areas) {
	service_area_restriction_t *service_area_restriction_local_var = malloc(
		sizeof(service_area_restriction_t));

	service_area_restriction_local_var->restriction_type = restriction_type;
	service_area_restriction_local_var->areas = areas;
	service_area_restriction_local_var->is_max_num_of_tas =
		is_max_num_of_tas;
	service_area_restriction_local_var->max_num_of_tas = max_num_of_tas;
	service_area_restriction_local_var->
	is_max_num_of_tas_for_not_allowed_areas =
		is_max_num_of_tas_for_not_allowed_areas;
	service_area_restriction_local_var->max_num_of_tas_for_not_allowed_areas
	        = max_num_of_tas_for_not_allowed_areas;

	return service_area_restriction_local_var;
}

void service_area_restriction_free(
	service_area_restriction_t *service_area_restriction) {
	lnode_t *node = NULL;

	if(NULL == service_area_restriction) {
		return;
	}
	if(service_area_restriction->restriction_type) {
		restriction_type_free(service_area_restriction->restriction_type);
		service_area_restriction->restriction_type = NULL;
	}
	if(service_area_restriction->areas) {
		list_for_each(service_area_restriction->areas, node) {
			area_free(node->data);
		}
		list_free(service_area_restriction->areas);
		service_area_restriction->areas = NULL;
	}
	free(service_area_restriction);
}

cJSON *service_area_restriction_convertToJSON(
	service_area_restriction_t *service_area_restriction) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(service_area_restriction == NULL) {
		printf(
			"service_area_restriction_convertToJSON() failed [ServiceAreaRestriction]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(service_area_restriction->restriction_type) {
		cJSON *restriction_type_local_JSON =
			restriction_type_convertToJSON(
				service_area_restriction->restriction_type);
		if(restriction_type_local_JSON == NULL) {
			printf(
				"service_area_restriction_convertToJSON() failed [restriction_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "restrictionType",
		                      restriction_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"service_area_restriction_convertToJSON() failed [restriction_type]");
			goto end;
		}
	}

	if(service_area_restriction->areas) {
		cJSON *areasList = cJSON_AddArrayToObject(item, "areas");
		if(areasList == NULL) {
			printf(
				"service_area_restriction_convertToJSON() failed [areas]");
			goto end;
		}
		list_for_each(service_area_restriction->areas, node) {
			cJSON *itemLocal = area_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"service_area_restriction_convertToJSON() failed [areas]");
				goto end;
			}
			cJSON_AddItemToArray(areasList, itemLocal);
		}
	}

	if(service_area_restriction->is_max_num_of_tas) {
		if(cJSON_AddNumberToObject(item, "maxNumOfTAs",
		                           service_area_restriction->
		                           max_num_of_tas) == NULL)
		{
			printf(
				"service_area_restriction_convertToJSON() failed [max_num_of_tas]");
			goto end;
		}
	}

	if(service_area_restriction->is_max_num_of_tas_for_not_allowed_areas) {
		if(cJSON_AddNumberToObject(item,
		                           "maxNumOfTAsForNotAllowedAreas",
		                           service_area_restriction->
		                           max_num_of_tas_for_not_allowed_areas)
		   == NULL)
		{
			printf(
				"service_area_restriction_convertToJSON() failed [max_num_of_tas_for_not_allowed_areas]");
			goto end;
		}
	}

end:
	return item;
}

service_area_restriction_t *service_area_restriction_parseFromJSON(
	cJSON *service_area_restrictionJSON) {
	service_area_restriction_t *service_area_restriction_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *restriction_type = NULL;
	restriction_type_t *restriction_type_local_nonprim = NULL;
	cJSON *areas = NULL;
	list_t *areasList = NULL;
	cJSON *max_num_of_tas = NULL;
	cJSON *max_num_of_tas_for_not_allowed_areas = NULL;
	restriction_type = cJSON_GetObjectItemCaseSensitive(
		service_area_restrictionJSON, "restrictionType");
	if(restriction_type) {
		restriction_type_local_nonprim = restriction_type_parseFromJSON(
			restriction_type);
		if(!restriction_type_local_nonprim) {
			printf(
				"restriction_type_parseFromJSON failed [restriction_type]");
			goto end;
		}
	}

	areas = cJSON_GetObjectItemCaseSensitive(service_area_restrictionJSON,
	                                         "areas");
	if(areas) {
		cJSON *areas_local = NULL;
		if(!cJSON_IsArray(areas)) {
			printf(
				"service_area_restriction_parseFromJSON() failed [areas]");
			goto end;
		}

		areasList = list_create();

		cJSON_ArrayForEach(areas_local, areas) {
			if(!cJSON_IsObject(areas_local)) {
				printf(
					"service_area_restriction_parseFromJSON() failed [areas]");
				goto end;
			}
			area_t *areasItem = area_parseFromJSON(areas_local);
			if(!areasItem) {
				printf("No areasItem");
				goto end;
			}
			list_add(areasList, areasItem);
		}
	}

	max_num_of_tas = cJSON_GetObjectItemCaseSensitive(
		service_area_restrictionJSON, "maxNumOfTAs");
	if(max_num_of_tas) {
		if(!cJSON_IsNumber(max_num_of_tas)) {
			printf(
				"service_area_restriction_parseFromJSON() failed [max_num_of_tas]");
			goto end;
		}
	}

	max_num_of_tas_for_not_allowed_areas = cJSON_GetObjectItemCaseSensitive(
		service_area_restrictionJSON, "maxNumOfTAsForNotAllowedAreas");
	if(max_num_of_tas_for_not_allowed_areas) {
		if(!cJSON_IsNumber(max_num_of_tas_for_not_allowed_areas)) {
			printf(
				"service_area_restriction_parseFromJSON() failed [max_num_of_tas_for_not_allowed_areas]");
			goto end;
		}
	}

	service_area_restriction_local_var = service_area_restriction_create(
		restriction_type ? restriction_type_local_nonprim : NULL,
		areas ? areasList : NULL,
		max_num_of_tas ? true : false,
		max_num_of_tas ? max_num_of_tas->valuedouble : 0,
		max_num_of_tas_for_not_allowed_areas ? true : false,
		max_num_of_tas_for_not_allowed_areas ? max_num_of_tas_for_not_allowed_areas->valuedouble : 0
		);

	return service_area_restriction_local_var;
end:
	if(restriction_type_local_nonprim) {
		restriction_type_free(restriction_type_local_nonprim);
		restriction_type_local_nonprim = NULL;
	}
	if(areasList) {
		list_for_each(areasList, node) {
			area_free(node->data);
		}
		list_free(areasList);
		areasList = NULL;
	}
	return NULL;
}

service_area_restriction_t *service_area_restriction_copy(
	service_area_restriction_t *dst, service_area_restriction_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = service_area_restriction_convertToJSON(src);
	if(!item) {
		printf("service_area_restriction_convertToJSON() failed");
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

	service_area_restriction_free(dst);
	dst = service_area_restriction_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
