#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "npn_access_info.h"

npn_access_info_t *npn_access_info_create(list_t *cell_cag_info) {
	npn_access_info_t *npn_access_info_local_var =
		malloc(sizeof(npn_access_info_t));

	npn_access_info_local_var->cell_cag_info = cell_cag_info;

	return npn_access_info_local_var;
}

void npn_access_info_free(npn_access_info_t *npn_access_info) {
	lnode_t *node = NULL;

	if(NULL == npn_access_info) {
		return;
	}
	if(npn_access_info->cell_cag_info) {
		list_for_each(npn_access_info->cell_cag_info, node) {
			free(node->data);
		}
		list_free(npn_access_info->cell_cag_info);
		npn_access_info->cell_cag_info = NULL;
	}
	free(npn_access_info);
}

cJSON *npn_access_info_convertToJSON(npn_access_info_t *npn_access_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(npn_access_info == NULL) {
		printf("npn_access_info_convertToJSON() failed [NpnAccessInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(npn_access_info->cell_cag_info) {
		cJSON *cell_cag_infoList = cJSON_AddArrayToObject(item,
		                                                  "cellCagInfo");
		if(cell_cag_infoList == NULL) {
			printf(
				"npn_access_info_convertToJSON() failed [cell_cag_info]");
			goto end;
		}
		list_for_each(npn_access_info->cell_cag_info, node) {
			if(cJSON_AddStringToObject(cell_cag_infoList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"npn_access_info_convertToJSON() failed [cell_cag_info]");
				goto end;
			}
		}
	}

end:
	return item;
}

npn_access_info_t *npn_access_info_parseFromJSON(cJSON *npn_access_infoJSON) {
	npn_access_info_t *npn_access_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *cell_cag_info = NULL;
	list_t *cell_cag_infoList = NULL;
	cell_cag_info = cJSON_GetObjectItemCaseSensitive(npn_access_infoJSON,
	                                                 "cellCagInfo");
	if(cell_cag_info) {
		cJSON *cell_cag_info_local = NULL;
		if(!cJSON_IsArray(cell_cag_info)) {
			printf(
				"npn_access_info_parseFromJSON() failed [cell_cag_info]");
			goto end;
		}

		cell_cag_infoList = list_create();

		cJSON_ArrayForEach(cell_cag_info_local, cell_cag_info) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(cell_cag_info_local)) {
				printf(
					"npn_access_info_parseFromJSON() failed [cell_cag_info]");
				goto end;
			}
			list_add(cell_cag_infoList,
			         strdup(cell_cag_info_local->valuestring));
		}
	}

	npn_access_info_local_var = npn_access_info_create(
		cell_cag_info ? cell_cag_infoList : NULL
		);

	return npn_access_info_local_var;
end:
	if(cell_cag_infoList) {
		list_for_each(cell_cag_infoList, node) {
			free(node->data);
		}
		list_free(cell_cag_infoList);
		cell_cag_infoList = NULL;
	}
	return NULL;
}

npn_access_info_t *npn_access_info_copy(npn_access_info_t	*dst,
                                        npn_access_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = npn_access_info_convertToJSON(src);
	if(!item) {
		printf("npn_access_info_convertToJSON() failed");
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

	npn_access_info_free(dst);
	dst = npn_access_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
