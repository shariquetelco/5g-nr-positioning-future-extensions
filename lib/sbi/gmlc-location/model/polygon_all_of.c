#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "polygon_all_of.h"

polygon_all_of_t *polygon_all_of_create(list_t *point_list) {
	polygon_all_of_t *polygon_all_of_local_var =
		malloc(sizeof(polygon_all_of_t));

	polygon_all_of_local_var->point_list = point_list;

	return polygon_all_of_local_var;
}

void polygon_all_of_free(polygon_all_of_t *polygon_all_of) {
	lnode_t *node = NULL;

	if(NULL == polygon_all_of) {
		return;
	}
	if(polygon_all_of->point_list) {
		list_for_each(polygon_all_of->point_list, node) {
			geographical_coordinates_free(node->data);
		}
		list_free(polygon_all_of->point_list);
		polygon_all_of->point_list = NULL;
	}
	free(polygon_all_of);
}

cJSON *polygon_all_of_convertToJSON(polygon_all_of_t *polygon_all_of) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(polygon_all_of == NULL) {
		printf("polygon_all_of_convertToJSON() failed [Polygon_allOf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!polygon_all_of->point_list) {
		printf("polygon_all_of_convertToJSON() failed [point_list]");
		return NULL;
	}
	cJSON *point_listList = cJSON_AddArrayToObject(item, "pointList");
	if(point_listList == NULL) {
		printf("polygon_all_of_convertToJSON() failed [point_list]");
		goto end;
	}
	list_for_each(polygon_all_of->point_list, node) {
		cJSON *itemLocal = geographical_coordinates_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf(
				"polygon_all_of_convertToJSON() failed [point_list]");
			goto end;
		}
		cJSON_AddItemToArray(point_listList, itemLocal);
	}

end:
	return item;
}

polygon_all_of_t *polygon_all_of_parseFromJSON(cJSON *polygon_all_ofJSON) {
	polygon_all_of_t *polygon_all_of_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *point_list = NULL;
	list_t *point_listList = NULL;
	point_list = cJSON_GetObjectItemCaseSensitive(polygon_all_ofJSON,
	                                              "pointList");
	if(!point_list) {
		printf("polygon_all_of_parseFromJSON() failed [point_list]");
		goto end;
	}
	cJSON *point_list_local = NULL;
	if(!cJSON_IsArray(point_list)) {
		printf("polygon_all_of_parseFromJSON() failed [point_list]");
		goto end;
	}

	point_listList = list_create();

	cJSON_ArrayForEach(point_list_local, point_list) {
		if(!cJSON_IsObject(point_list_local)) {
			printf(
				"polygon_all_of_parseFromJSON() failed [point_list]");
			goto end;
		}
		geographical_coordinates_t *point_listItem =
			geographical_coordinates_parseFromJSON(point_list_local);
		if(!point_listItem) {
			printf("No point_listItem");
			goto end;
		}
		list_add(point_listList, point_listItem);
	}

	polygon_all_of_local_var = polygon_all_of_create(
		point_listList
		);

	return polygon_all_of_local_var;
end:
	if(point_listList) {
		list_for_each(point_listList, node) {
			geographical_coordinates_free(node->data);
		}
		list_free(point_listList);
		point_listList = NULL;
	}
	return NULL;
}

polygon_all_of_t *polygon_all_of_copy(polygon_all_of_t	*dst,
                                      polygon_all_of_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = polygon_all_of_convertToJSON(src);
	if(!item) {
		printf("polygon_all_of_convertToJSON() failed");
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

	polygon_all_of_free(dst);
	dst = polygon_all_of_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
