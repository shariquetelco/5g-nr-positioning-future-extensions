#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_area_id.h"

location_area_id_t *location_area_id_create(plmn_id_t *plmn_id, char *lac) {
	location_area_id_t *location_area_id_local_var =
		malloc(sizeof(location_area_id_t));

	location_area_id_local_var->plmn_id = plmn_id;
	location_area_id_local_var->lac = lac;

	return location_area_id_local_var;
}

void location_area_id_free(location_area_id_t *location_area_id) {
	lnode_t *node = NULL;

	if(NULL == location_area_id) {
		return;
	}
	if(location_area_id->plmn_id) {
		plmn_id_free(location_area_id->plmn_id);
		location_area_id->plmn_id = NULL;
	}
	if(location_area_id->lac) {
		free(location_area_id->lac);
		location_area_id->lac = NULL;
	}
	free(location_area_id);
}

cJSON *location_area_id_convertToJSON(location_area_id_t *location_area_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(location_area_id == NULL) {
		printf(
			"location_area_id_convertToJSON() failed [LocationAreaId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!location_area_id->plmn_id) {
		printf("location_area_id_convertToJSON() failed [plmn_id]");
		return NULL;
	}
	cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(
		location_area_id->plmn_id);
	if(plmn_id_local_JSON == NULL) {
		printf("location_area_id_convertToJSON() failed [plmn_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
	if(item->child == NULL) {
		printf("location_area_id_convertToJSON() failed [plmn_id]");
		goto end;
	}

	if(!location_area_id->lac) {
		printf("location_area_id_convertToJSON() failed [lac]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "lac",
	                           location_area_id->lac) == NULL)
	{
		printf("location_area_id_convertToJSON() failed [lac]");
		goto end;
	}

end:
	return item;
}

location_area_id_t *location_area_id_parseFromJSON(cJSON *location_area_idJSON)
{
	location_area_id_t *location_area_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *plmn_id = NULL;
	plmn_id_t *plmn_id_local_nonprim = NULL;
	cJSON *lac = NULL;
	plmn_id = cJSON_GetObjectItemCaseSensitive(location_area_idJSON,
	                                           "plmnId");
	if(!plmn_id) {
		printf("location_area_id_parseFromJSON() failed [plmn_id]");
		goto end;
	}
	plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id);
	if(!plmn_id_local_nonprim) {
		printf("plmn_id_parseFromJSON failed [plmn_id]");
		goto end;
	}

	lac = cJSON_GetObjectItemCaseSensitive(location_area_idJSON, "lac");
	if(!lac) {
		printf("location_area_id_parseFromJSON() failed [lac]");
		goto end;
	}
	if(!cJSON_IsString(lac)) {
		printf("location_area_id_parseFromJSON() failed [lac]");
		goto end;
	}

	location_area_id_local_var = location_area_id_create(
		plmn_id_local_nonprim,
		strdup(lac->valuestring)
		);

	return location_area_id_local_var;
end:
	if(plmn_id_local_nonprim) {
		plmn_id_free(plmn_id_local_nonprim);
		plmn_id_local_nonprim = NULL;
	}
	return NULL;
}

location_area_id_t *location_area_id_copy(location_area_id_t	*dst,
                                          location_area_id_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = location_area_id_convertToJSON(src);
	if(!item) {
		printf("location_area_id_convertToJSON() failed");
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

	location_area_id_free(dst);
	dst = location_area_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
