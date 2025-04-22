#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mov_behav_info.h"

mov_behav_info_t *mov_behav_info_create(geographical_coordinates_t *geo_loc,
                                        list_t *mov_behavs, bool is_confidence,
                                        int confidence) {
	mov_behav_info_t *mov_behav_info_local_var =
		malloc(sizeof(mov_behav_info_t));

	mov_behav_info_local_var->geo_loc = geo_loc;
	mov_behav_info_local_var->mov_behavs = mov_behavs;
	mov_behav_info_local_var->is_confidence = is_confidence;
	mov_behav_info_local_var->confidence = confidence;

	return mov_behav_info_local_var;
}

void mov_behav_info_free(mov_behav_info_t *mov_behav_info) {
	lnode_t *node = NULL;

	if(NULL == mov_behav_info) {
		return;
	}
	if(mov_behav_info->geo_loc) {
		geographical_coordinates_free(mov_behav_info->geo_loc);
		mov_behav_info->geo_loc = NULL;
	}
	if(mov_behav_info->mov_behavs) {
		list_for_each(mov_behav_info->mov_behavs, node) {
			mov_behav_free(node->data);
		}
		list_free(mov_behav_info->mov_behavs);
		mov_behav_info->mov_behavs = NULL;
	}
	free(mov_behav_info);
}

cJSON *mov_behav_info_convertToJSON(mov_behav_info_t *mov_behav_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mov_behav_info == NULL) {
		printf("mov_behav_info_convertToJSON() failed [MovBehavInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(mov_behav_info->geo_loc) {
		cJSON *geo_loc_local_JSON =
			geographical_coordinates_convertToJSON(
				mov_behav_info->geo_loc);
		if(geo_loc_local_JSON == NULL) {
			printf("mov_behav_info_convertToJSON() failed [geo_loc]");
			goto end;
		}
		cJSON_AddItemToObject(item, "geoLoc", geo_loc_local_JSON);
		if(item->child == NULL) {
			printf("mov_behav_info_convertToJSON() failed [geo_loc]");
			goto end;
		}
	}

	if(mov_behav_info->mov_behavs) {
		cJSON *mov_behavsList =
			cJSON_AddArrayToObject(item, "movBehavs");
		if(mov_behavsList == NULL) {
			printf(
				"mov_behav_info_convertToJSON() failed [mov_behavs]");
			goto end;
		}
		list_for_each(mov_behav_info->mov_behavs, node) {
			cJSON *itemLocal = mov_behav_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"mov_behav_info_convertToJSON() failed [mov_behavs]");
				goto end;
			}
			cJSON_AddItemToArray(mov_behavsList, itemLocal);
		}
	}

	if(mov_behav_info->is_confidence) {
		if(cJSON_AddNumberToObject(item, "confidence",
		                           mov_behav_info->confidence) == NULL)
		{
			printf(
				"mov_behav_info_convertToJSON() failed [confidence]");
			goto end;
		}
	}

end:
	return item;
}

mov_behav_info_t *mov_behav_info_parseFromJSON(cJSON *mov_behav_infoJSON) {
	mov_behav_info_t *mov_behav_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *geo_loc = NULL;
	geographical_coordinates_t *geo_loc_local_nonprim = NULL;
	cJSON *mov_behavs = NULL;
	list_t *mov_behavsList = NULL;
	cJSON *confidence = NULL;
	geo_loc =
		cJSON_GetObjectItemCaseSensitive(mov_behav_infoJSON, "geoLoc");
	if(geo_loc) {
		geo_loc_local_nonprim = geographical_coordinates_parseFromJSON(
			geo_loc);
		if(!geo_loc_local_nonprim) {
			printf(
				"geographical_coordinates_parseFromJSON failed [geo_loc]");
			goto end;
		}
	}

	mov_behavs = cJSON_GetObjectItemCaseSensitive(mov_behav_infoJSON,
	                                              "movBehavs");
	if(mov_behavs) {
		cJSON *mov_behavs_local = NULL;
		if(!cJSON_IsArray(mov_behavs)) {
			printf(
				"mov_behav_info_parseFromJSON() failed [mov_behavs]");
			goto end;
		}

		mov_behavsList = list_create();

		cJSON_ArrayForEach(mov_behavs_local, mov_behavs) {
			if(!cJSON_IsObject(mov_behavs_local)) {
				printf(
					"mov_behav_info_parseFromJSON() failed [mov_behavs]");
				goto end;
			}
			mov_behav_t *mov_behavsItem = mov_behav_parseFromJSON(
				mov_behavs_local);
			if(!mov_behavsItem) {
				printf("No mov_behavsItem");
				goto end;
			}
			list_add(mov_behavsList, mov_behavsItem);
		}
	}

	confidence = cJSON_GetObjectItemCaseSensitive(mov_behav_infoJSON,
	                                              "confidence");
	if(confidence) {
		if(!cJSON_IsNumber(confidence)) {
			printf(
				"mov_behav_info_parseFromJSON() failed [confidence]");
			goto end;
		}
	}

	mov_behav_info_local_var = mov_behav_info_create(
		geo_loc ? geo_loc_local_nonprim : NULL,
		mov_behavs ? mov_behavsList : NULL,
		confidence ? true : false,
		confidence ? confidence->valuedouble : 0
		);

	return mov_behav_info_local_var;
end:
	if(geo_loc_local_nonprim) {
		geographical_coordinates_free(geo_loc_local_nonprim);
		geo_loc_local_nonprim = NULL;
	}
	if(mov_behavsList) {
		list_for_each(mov_behavsList, node) {
			mov_behav_free(node->data);
		}
		list_free(mov_behavsList);
		mov_behavsList = NULL;
	}
	return NULL;
}

mov_behav_info_t *mov_behav_info_copy(mov_behav_info_t	*dst,
                                      mov_behav_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mov_behav_info_convertToJSON(src);
	if(!item) {
		printf("mov_behav_info_convertToJSON() failed");
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

	mov_behav_info_free(dst);
	dst = mov_behav_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
