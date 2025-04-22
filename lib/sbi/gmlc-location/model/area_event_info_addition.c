#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "area_event_info_addition.h"

area_event_info_addition_t *area_event_info_addition_create(
	list_t *geo_area_list, bool is_ignore_area_def_ind,
	int ignore_area_def_ind, bool is_additional_check_ind,
	int additional_check_ind) {
	area_event_info_addition_t *area_event_info_addition_local_var = malloc(
		sizeof(area_event_info_addition_t));

	area_event_info_addition_local_var->geo_area_list = geo_area_list;
	area_event_info_addition_local_var->is_ignore_area_def_ind =
		is_ignore_area_def_ind;
	area_event_info_addition_local_var->ignore_area_def_ind =
		ignore_area_def_ind;
	area_event_info_addition_local_var->is_additional_check_ind =
		is_additional_check_ind;
	area_event_info_addition_local_var->additional_check_ind =
		additional_check_ind;

	return area_event_info_addition_local_var;
}

void area_event_info_addition_free(
	area_event_info_addition_t *area_event_info_addition) {
	lnode_t *node = NULL;

	if(NULL == area_event_info_addition) {
		return;
	}
	if(area_event_info_addition->geo_area_list) {
		list_for_each(area_event_info_addition->geo_area_list, node) {
			geographic_area_free(node->data);
		}
		list_free(area_event_info_addition->geo_area_list);
		area_event_info_addition->geo_area_list = NULL;
	}
	free(area_event_info_addition);
}

cJSON *area_event_info_addition_convertToJSON(
	area_event_info_addition_t *area_event_info_addition) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(area_event_info_addition == NULL) {
		printf(
			"area_event_info_addition_convertToJSON() failed [AreaEventInfoAddition]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(area_event_info_addition->geo_area_list) {
		cJSON *geo_area_listList = cJSON_AddArrayToObject(item,
		                                                  "geoAreaList");
		if(geo_area_listList == NULL) {
			printf(
				"area_event_info_addition_convertToJSON() failed [geo_area_list]");
			goto end;
		}
		list_for_each(area_event_info_addition->geo_area_list, node) {
			cJSON *itemLocal = geographic_area_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"area_event_info_addition_convertToJSON() failed [geo_area_list]");
				goto end;
			}
			cJSON_AddItemToArray(geo_area_listList, itemLocal);
		}
	}

	if(area_event_info_addition->is_ignore_area_def_ind) {
		if(cJSON_AddBoolToObject(item, "ignoreAreaDefInd",
		                         area_event_info_addition->
		                         ignore_area_def_ind) == NULL)
		{
			printf(
				"area_event_info_addition_convertToJSON() failed [ignore_area_def_ind]");
			goto end;
		}
	}

	if(area_event_info_addition->is_additional_check_ind) {
		if(cJSON_AddBoolToObject(item, "additionalCheckInd",
		                         area_event_info_addition->
		                         additional_check_ind) == NULL)
		{
			printf(
				"area_event_info_addition_convertToJSON() failed [additional_check_ind]");
			goto end;
		}
	}

end:
	return item;
}

area_event_info_addition_t *area_event_info_addition_parseFromJSON(
	cJSON *area_event_info_additionJSON) {
	area_event_info_addition_t *area_event_info_addition_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *geo_area_list = NULL;
	list_t *geo_area_listList = NULL;
	cJSON *ignore_area_def_ind = NULL;
	cJSON *additional_check_ind = NULL;
	geo_area_list = cJSON_GetObjectItemCaseSensitive(
		area_event_info_additionJSON, "geoAreaList");
	if(geo_area_list) {
		cJSON *geo_area_list_local = NULL;
		if(!cJSON_IsArray(geo_area_list)) {
			printf(
				"area_event_info_addition_parseFromJSON() failed [geo_area_list]");
			goto end;
		}

		geo_area_listList = list_create();

		cJSON_ArrayForEach(geo_area_list_local, geo_area_list) {
			if(!cJSON_IsObject(geo_area_list_local)) {
				printf(
					"area_event_info_addition_parseFromJSON() failed [geo_area_list]");
				goto end;
			}
			geographic_area_t *geo_area_listItem =
				geographic_area_parseFromJSON(
					geo_area_list_local);
			if(!geo_area_listItem) {
				printf("No geo_area_listItem");
				goto end;
			}
			list_add(geo_area_listList, geo_area_listItem);
		}
	}

	ignore_area_def_ind = cJSON_GetObjectItemCaseSensitive(
		area_event_info_additionJSON, "ignoreAreaDefInd");
	if(ignore_area_def_ind) {
		if(!cJSON_IsBool(ignore_area_def_ind)) {
			printf(
				"area_event_info_addition_parseFromJSON() failed [ignore_area_def_ind]");
			goto end;
		}
	}

	additional_check_ind = cJSON_GetObjectItemCaseSensitive(
		area_event_info_additionJSON, "additionalCheckInd");
	if(additional_check_ind) {
		if(!cJSON_IsBool(additional_check_ind)) {
			printf(
				"area_event_info_addition_parseFromJSON() failed [additional_check_ind]");
			goto end;
		}
	}

	area_event_info_addition_local_var = area_event_info_addition_create(
		geo_area_list ? geo_area_listList : NULL,
		ignore_area_def_ind ? true : false,
		ignore_area_def_ind ? ignore_area_def_ind->valueint : 0,
		additional_check_ind ? true : false,
		additional_check_ind ? additional_check_ind->valueint : 0
		);

	return area_event_info_addition_local_var;
end:
	if(geo_area_listList) {
		list_for_each(geo_area_listList, node) {
			geographic_area_free(node->data);
		}
		list_free(geo_area_listList);
		geo_area_listList = NULL;
	}
	return NULL;
}

area_event_info_addition_t *area_event_info_addition_copy(
	area_event_info_addition_t *dst, area_event_info_addition_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = area_event_info_addition_convertToJSON(src);
	if(!item) {
		printf("area_event_info_addition_convertToJSON() failed");
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

	area_event_info_addition_free(dst);
	dst = area_event_info_addition_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
