#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dispersion_info.h"

dispersion_info_t *dispersion_info_create(char *ts_start, int ts_duration,
                                          list_t *disper_collects,
                                          dispersion_type_t *disper_type) {
	dispersion_info_t *dispersion_info_local_var =
		malloc(sizeof(dispersion_info_t));

	dispersion_info_local_var->ts_start = ts_start;
	dispersion_info_local_var->ts_duration = ts_duration;
	dispersion_info_local_var->disper_collects = disper_collects;
	dispersion_info_local_var->disper_type = disper_type;

	return dispersion_info_local_var;
}

void dispersion_info_free(dispersion_info_t *dispersion_info) {
	lnode_t *node = NULL;

	if(NULL == dispersion_info) {
		return;
	}
	if(dispersion_info->ts_start) {
		free(dispersion_info->ts_start);
		dispersion_info->ts_start = NULL;
	}
	if(dispersion_info->disper_collects) {
		list_for_each(dispersion_info->disper_collects, node) {
			dispersion_collection_free(node->data);
		}
		list_free(dispersion_info->disper_collects);
		dispersion_info->disper_collects = NULL;
	}
	if(dispersion_info->disper_type) {
		dispersion_type_free(dispersion_info->disper_type);
		dispersion_info->disper_type = NULL;
	}
	free(dispersion_info);
}

cJSON *dispersion_info_convertToJSON(dispersion_info_t *dispersion_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(dispersion_info == NULL) {
		printf("dispersion_info_convertToJSON() failed [DispersionInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!dispersion_info->ts_start) {
		printf("dispersion_info_convertToJSON() failed [ts_start]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "tsStart",
	                           dispersion_info->ts_start) == NULL)
	{
		printf("dispersion_info_convertToJSON() failed [ts_start]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "tsDuration",
	                           dispersion_info->ts_duration) == NULL)
	{
		printf("dispersion_info_convertToJSON() failed [ts_duration]");
		goto end;
	}

	if(!dispersion_info->disper_collects) {
		printf(
			"dispersion_info_convertToJSON() failed [disper_collects]");
		return NULL;
	}
	cJSON *disper_collectsList = cJSON_AddArrayToObject(item,
	                                                    "disperCollects");
	if(disper_collectsList == NULL) {
		printf(
			"dispersion_info_convertToJSON() failed [disper_collects]");
		goto end;
	}
	list_for_each(dispersion_info->disper_collects, node) {
		cJSON *itemLocal = dispersion_collection_convertToJSON(
			node->data);
		if(itemLocal == NULL) {
			printf(
				"dispersion_info_convertToJSON() failed [disper_collects]");
			goto end;
		}
		cJSON_AddItemToArray(disper_collectsList, itemLocal);
	}

	if(!dispersion_info->disper_type) {
		printf("dispersion_info_convertToJSON() failed [disper_type]");
		return NULL;
	}
	cJSON *disper_type_local_JSON = dispersion_type_convertToJSON(
		dispersion_info->disper_type);
	if(disper_type_local_JSON == NULL) {
		printf("dispersion_info_convertToJSON() failed [disper_type]");
		goto end;
	}
	cJSON_AddItemToObject(item, "disperType", disper_type_local_JSON);
	if(item->child == NULL) {
		printf("dispersion_info_convertToJSON() failed [disper_type]");
		goto end;
	}

end:
	return item;
}

dispersion_info_t *dispersion_info_parseFromJSON(cJSON *dispersion_infoJSON) {
	dispersion_info_t *dispersion_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ts_start = NULL;
	cJSON *ts_duration = NULL;
	cJSON *disper_collects = NULL;
	list_t *disper_collectsList = NULL;
	cJSON *disper_type = NULL;
	dispersion_type_t *disper_type_local_nonprim = NULL;
	ts_start = cJSON_GetObjectItemCaseSensitive(dispersion_infoJSON,
	                                            "tsStart");
	if(!ts_start) {
		printf("dispersion_info_parseFromJSON() failed [ts_start]");
		goto end;
	}
	if(!cJSON_IsString(ts_start) &&
	   !cJSON_IsNull(ts_start))
	{
		printf("dispersion_info_parseFromJSON() failed [ts_start]");
		goto end;
	}

	ts_duration = cJSON_GetObjectItemCaseSensitive(dispersion_infoJSON,
	                                               "tsDuration");
	if(!ts_duration) {
		printf("dispersion_info_parseFromJSON() failed [ts_duration]");
		goto end;
	}
	if(!cJSON_IsNumber(ts_duration)) {
		printf("dispersion_info_parseFromJSON() failed [ts_duration]");
		goto end;
	}

	disper_collects = cJSON_GetObjectItemCaseSensitive(dispersion_infoJSON,
	                                                   "disperCollects");
	if(!disper_collects) {
		printf(
			"dispersion_info_parseFromJSON() failed [disper_collects]");
		goto end;
	}
	cJSON *disper_collects_local = NULL;
	if(!cJSON_IsArray(disper_collects)) {
		printf(
			"dispersion_info_parseFromJSON() failed [disper_collects]");
		goto end;
	}

	disper_collectsList = list_create();

	cJSON_ArrayForEach(disper_collects_local, disper_collects) {
		if(!cJSON_IsObject(disper_collects_local)) {
			printf(
				"dispersion_info_parseFromJSON() failed [disper_collects]");
			goto end;
		}
		dispersion_collection_t *disper_collectsItem =
			dispersion_collection_parseFromJSON(
				disper_collects_local);
		if(!disper_collectsItem) {
			printf("No disper_collectsItem");
			goto end;
		}
		list_add(disper_collectsList, disper_collectsItem);
	}

	disper_type = cJSON_GetObjectItemCaseSensitive(dispersion_infoJSON,
	                                               "disperType");
	if(!disper_type) {
		printf("dispersion_info_parseFromJSON() failed [disper_type]");
		goto end;
	}
	disper_type_local_nonprim = dispersion_type_parseFromJSON(disper_type);
	if(!disper_type_local_nonprim) {
		printf("dispersion_type_parseFromJSON failed [disper_type]");
		goto end;
	}

	dispersion_info_local_var = dispersion_info_create(
		strdup(ts_start->valuestring),

		ts_duration->valuedouble,
		disper_collectsList,
		disper_type_local_nonprim
		);

	return dispersion_info_local_var;
end:
	if(disper_collectsList) {
		list_for_each(disper_collectsList, node) {
			dispersion_collection_free(node->data);
		}
		list_free(disper_collectsList);
		disper_collectsList = NULL;
	}
	if(disper_type_local_nonprim) {
		dispersion_type_free(disper_type_local_nonprim);
		disper_type_local_nonprim = NULL;
	}
	return NULL;
}

dispersion_info_t *dispersion_info_copy(dispersion_info_t	*dst,
                                        dispersion_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = dispersion_info_convertToJSON(src);
	if(!item) {
		printf("dispersion_info_convertToJSON() failed");
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

	dispersion_info_free(dst);
	dst = dispersion_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
