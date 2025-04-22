#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cell_global_id.h"

cell_global_id_t *cell_global_id_create(plmn_id_t *plmn_id, char *lac,
                                        char *cell_id) {
	cell_global_id_t *cell_global_id_local_var =
		malloc(sizeof(cell_global_id_t));

	cell_global_id_local_var->plmn_id = plmn_id;
	cell_global_id_local_var->lac = lac;
	cell_global_id_local_var->cell_id = cell_id;

	return cell_global_id_local_var;
}

void cell_global_id_free(cell_global_id_t *cell_global_id) {
	lnode_t *node = NULL;

	if(NULL == cell_global_id) {
		return;
	}
	if(cell_global_id->plmn_id) {
		plmn_id_free(cell_global_id->plmn_id);
		cell_global_id->plmn_id = NULL;
	}
	if(cell_global_id->lac) {
		free(cell_global_id->lac);
		cell_global_id->lac = NULL;
	}
	if(cell_global_id->cell_id) {
		free(cell_global_id->cell_id);
		cell_global_id->cell_id = NULL;
	}
	free(cell_global_id);
}

cJSON *cell_global_id_convertToJSON(cell_global_id_t *cell_global_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(cell_global_id == NULL) {
		printf("cell_global_id_convertToJSON() failed [CellGlobalId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!cell_global_id->plmn_id) {
		printf("cell_global_id_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(
		cell_global_id->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("cell_global_id_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("cell_global_id_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!cell_global_id->lac) {
		printf("cell_global_id_convertToJSON() failed [lac]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "lac", cell_global_id->lac) == NULL) {
		printf("cell_global_id_convertToJSON() failed [lac]");
		goto end;
	}

	if(!cell_global_id->cell_id) {
		printf("cell_global_id_convertToJSON() failed [cell_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "cellId",
	                           cell_global_id->cell_id) == NULL)
	{
		printf("cell_global_id_convertToJSON() failed [cell_id]");
		goto end;
	}

end:
	return item;
}

cell_global_id_t *cell_global_id_parseFromJSON(cJSON *cell_global_idJSON) {
	cell_global_id_t *cell_global_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *lac = NULL;
	cJSON *cell_id = NULL;
	plmn_id =
		cJSON_GetObjectItemCaseSensitive(cell_global_idJSON, "plmnId");
	if(!plmn_id) {
		printf("cell_global_id_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	lac = cJSON_GetObjectItemCaseSensitive(cell_global_idJSON, "lac");
	if(!lac) {
		printf("cell_global_id_parseFromJSON() failed [lac]");
		goto end;
	}
	if(!cJSON_IsString(lac)) {
		printf("cell_global_id_parseFromJSON() failed [lac]");
		goto end;
	}

	cell_id =
		cJSON_GetObjectItemCaseSensitive(cell_global_idJSON, "cellId");
	if(!cell_id) {
		printf("cell_global_id_parseFromJSON() failed [cell_id]");
		goto end;
	}
	if(!cJSON_IsString(cell_id)) {
		printf("cell_global_id_parseFromJSON() failed [cell_id]");
		goto end;
	}

	cell_global_id_local_var = cell_global_id_create(
		plmn_id_local_nonprim,
		strdup(lac->valuestring),
		strdup(cell_id->valuestring)
		);

	return cell_global_id_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

cell_global_id_t *cell_global_id_copy(cell_global_id_t	*dst,
                                      cell_global_id_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = cell_global_id_convertToJSON(src);
	if(!item) {
		printf("cell_global_id_convertToJSON() failed");
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

	cell_global_id_free(dst);
	dst = cell_global_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
