#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mbsr_location_info.h"

mbsr_location_info_t *mbsr_location_info_create(list_t	*mbsr_location,
                                                list_t	*mbsr_location_areas) {
	mbsr_location_info_t *mbsr_location_info_local_var =
		malloc(sizeof(mbsr_location_info_t));

	mbsr_location_info_local_var->mbsr_location = mbsr_location;
	mbsr_location_info_local_var->mbsr_location_areas = mbsr_location_areas;

	return mbsr_location_info_local_var;
}

void mbsr_location_info_free(mbsr_location_info_t *mbsr_location_info) {
	lnode_t *node = NULL;

	if(NULL == mbsr_location_info) {
		return;
	}
	if(mbsr_location_info->mbsr_location) {
		list_for_each(mbsr_location_info->mbsr_location, node) {
			tai_free(node->data);
		}
		list_free(mbsr_location_info->mbsr_location);
		mbsr_location_info->mbsr_location = NULL;
	}
	if(mbsr_location_info->mbsr_location_areas) {
		list_for_each(mbsr_location_info->mbsr_location_areas, node) {
			free(node->data);
		}
		list_free(mbsr_location_info->mbsr_location_areas);
		mbsr_location_info->mbsr_location_areas = NULL;
	}
	free(mbsr_location_info);
}

cJSON *mbsr_location_info_convertToJSON(
	mbsr_location_info_t *mbsr_location_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(mbsr_location_info == NULL) {
		printf(
			"mbsr_location_info_convertToJSON() failed [MbsrLocationInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(mbsr_location_info->mbsr_location) {
		cJSON *mbsr_locationList = cJSON_AddArrayToObject(item,
		                                                  "mbsrLocation");
		if(mbsr_locationList == NULL) {
			printf(
				"mbsr_location_info_convertToJSON() failed [mbsr_location]");
			goto end;
		}
		list_for_each(mbsr_location_info->mbsr_location, node) {
			cJSON *itemLocal = tai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"mbsr_location_info_convertToJSON() failed [mbsr_location]");
				goto end;
			}
			cJSON_AddItemToArray(mbsr_locationList, itemLocal);
		}
	}

	if(mbsr_location_info->mbsr_location_areas) {
		cJSON *mbsr_location_areasList = cJSON_AddArrayToObject(item,
		                                                        "mbsrLocationAreas");
		if(mbsr_location_areasList == NULL) {
			printf(
				"mbsr_location_info_convertToJSON() failed [mbsr_location_areas]");
			goto end;
		}
		list_for_each(mbsr_location_info->mbsr_location_areas, node) {
			if(cJSON_AddStringToObject(mbsr_location_areasList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"mbsr_location_info_convertToJSON() failed [mbsr_location_areas]");
				goto end;
			}
		}
	}

end:
	return item;
}

mbsr_location_info_t *mbsr_location_info_parseFromJSON(
	cJSON *mbsr_location_infoJSON) {
	mbsr_location_info_t *mbsr_location_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *mbsr_location = NULL;
	list_t *mbsr_locationList = NULL;
	cJSON *mbsr_location_areas = NULL;
	list_t *mbsr_location_areasList = NULL;
	mbsr_location = cJSON_GetObjectItemCaseSensitive(mbsr_location_infoJSON,
	                                                 "mbsrLocation");
	if(mbsr_location) {
		cJSON *mbsr_location_local = NULL;
		if(!cJSON_IsArray(mbsr_location)) {
			printf(
				"mbsr_location_info_parseFromJSON() failed [mbsr_location]");
			goto end;
		}

		mbsr_locationList = list_create();

		cJSON_ArrayForEach(mbsr_location_local, mbsr_location) {
			if(!cJSON_IsObject(mbsr_location_local)) {
				printf(
					"mbsr_location_info_parseFromJSON() failed [mbsr_location]");
				goto end;
			}
			tai_t *mbsr_locationItem = tai_parseFromJSON(
				mbsr_location_local);
			if(!mbsr_locationItem) {
				printf("No mbsr_locationItem");
				goto end;
			}
			list_add(mbsr_locationList, mbsr_locationItem);
		}
	}

	mbsr_location_areas = cJSON_GetObjectItemCaseSensitive(
		mbsr_location_infoJSON, "mbsrLocationAreas");
	if(mbsr_location_areas) {
		cJSON *mbsr_location_areas_local = NULL;
		if(!cJSON_IsArray(mbsr_location_areas)) {
			printf(
				"mbsr_location_info_parseFromJSON() failed [mbsr_location_areas]");
			goto end;
		}

		mbsr_location_areasList = list_create();

		cJSON_ArrayForEach(mbsr_location_areas_local,
		                   mbsr_location_areas) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(mbsr_location_areas_local)) {
				printf(
					"mbsr_location_info_parseFromJSON() failed [mbsr_location_areas]");
				goto end;
			}
			list_add(mbsr_location_areasList,
			         strdup(mbsr_location_areas_local->valuestring));
		}
	}

	mbsr_location_info_local_var = mbsr_location_info_create(
		mbsr_location ? mbsr_locationList : NULL,
		mbsr_location_areas ? mbsr_location_areasList : NULL
		);

	return mbsr_location_info_local_var;
end:
	if(mbsr_locationList) {
		list_for_each(mbsr_locationList, node) {
			tai_free(node->data);
		}
		list_free(mbsr_locationList);
		mbsr_locationList = NULL;
	}
	if(mbsr_location_areasList) {
		list_for_each(mbsr_location_areasList, node) {
			free(node->data);
		}
		list_free(mbsr_location_areasList);
		mbsr_location_areasList = NULL;
	}
	return NULL;
}

mbsr_location_info_t *mbsr_location_info_copy(mbsr_location_info_t	*dst,
                                              mbsr_location_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = mbsr_location_info_convertToJSON(src);
	if(!item) {
		printf("mbsr_location_info_convertToJSON() failed");
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

	mbsr_location_info_free(dst);
	dst = mbsr_location_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
