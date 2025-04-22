#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "polygon.h"

polygon_t *polygon_create(supported_gad_shapes_t *shape, list_t *point_list) {
	polygon_t *polygon_local_var = malloc(sizeof(polygon_t));

	polygon_local_var->shape = shape;
	polygon_local_var->point_list = point_list;

	return polygon_local_var;
}

void polygon_free(polygon_t *polygon) {
	lnode_t *node = NULL;

	if(NULL == polygon) {
		return;
	}
	if(polygon->shape) {
		supported_gad_shapes_free(polygon->shape);
		polygon->shape = NULL;
	}
	if(polygon->point_list) {
		list_for_each(polygon->point_list, node) {
			geographical_coordinates_free(node->data);
		}
		list_free(polygon->point_list);
		polygon->point_list = NULL;
	}
	free(polygon);
}

cJSON *polygon_convertToJSON(polygon_t *polygon) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(polygon == NULL) {
		printf("polygon_convertToJSON() failed [Polygon]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!polygon->shape) {
		printf("polygon_convertToJSON() failed [shape]");
		return NULL;
	}
	cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(
		polygon->shape);
	if(shape_local_JSON == NULL) {
		printf("polygon_convertToJSON() failed [shape]");
		goto end;
	}
	cJSON_AddItemToObject(item, "shape", shape_local_JSON);
	if(item->child == NULL) {
		printf("polygon_convertToJSON() failed [shape]");
		goto end;
	}

	if(!polygon->point_list) {
		printf("polygon_convertToJSON() failed [point_list]");
		return NULL;
	}
	cJSON *point_listList = cJSON_AddArrayToObject(item, "pointList");
	if(point_listList == NULL) {
		printf("polygon_convertToJSON() failed [point_list]");
		goto end;
	}
	list_for_each(polygon->point_list, node) {
		cJSON *itemLocal = geographical_coordinates_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf("polygon_convertToJSON() failed [point_list]");
			goto end;
		}
		cJSON_AddItemToArray(point_listList, itemLocal);
	}

end:
	return item;
}

polygon_t *polygon_parseFromJSON(cJSON *polygonJSON) {
	polygon_t *polygon_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *shape = NULL;
	supported_gad_shapes_t *shape_local_nonprim = NULL;
	cJSON *point_list = NULL;
	list_t *point_listList = NULL;
	shape = cJSON_GetObjectItemCaseSensitive(polygonJSON, "shape");
	if(!shape) {
		printf("polygon_parseFromJSON() failed [shape]");
		goto end;
	}
	shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape);
	if(!shape_local_nonprim) {
		printf("supported_gad_shapes_parseFromJSON failed [shape]");
		goto end;
	}

	point_list = cJSON_GetObjectItemCaseSensitive(polygonJSON, "pointList");
	if(!point_list) {
		printf("polygon_parseFromJSON() failed [point_list]");
		goto end;
	}
	cJSON *point_list_local = NULL;
	if(!cJSON_IsArray(point_list)) {
		printf("polygon_parseFromJSON() failed [point_list]");
		goto end;
	}

	point_listList = list_create();

	cJSON_ArrayForEach(point_list_local, point_list) {
		if(!cJSON_IsObject(point_list_local)) {
			printf("polygon_parseFromJSON() failed [point_list]");
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

	polygon_local_var = polygon_create(
		shape_local_nonprim,
		point_listList
		);

	return polygon_local_var;
end:
	if(shape_local_nonprim) {
		supported_gad_shapes_free(shape_local_nonprim);
		shape_local_nonprim = NULL;
	}
	if(point_listList) {
		list_for_each(point_listList, node) {
			geographical_coordinates_free(node->data);
		}
		list_free(point_listList);
		point_listList = NULL;
	}
	return NULL;
}

polygon_t *polygon_copy(polygon_t *dst, polygon_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = polygon_convertToJSON(src);
	if(!item) {
		printf("polygon_convertToJSON() failed");
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

	polygon_free(dst);
	dst = polygon_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
