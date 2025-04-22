#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "hfc_node_id.h"

hfc_node_id_t *hfc_node_id_create(char *hfc_nid) {
	hfc_node_id_t *hfc_node_id_local_var = malloc(sizeof(hfc_node_id_t));

	hfc_node_id_local_var->hfc_nid = hfc_nid;

	return hfc_node_id_local_var;
}

void hfc_node_id_free(hfc_node_id_t *hfc_node_id) {
	lnode_t *node = NULL;

	if(NULL == hfc_node_id) {
		return;
	}
	if(hfc_node_id->hfc_nid) {
		free(hfc_node_id->hfc_nid);
		hfc_node_id->hfc_nid = NULL;
	}
	free(hfc_node_id);
}

cJSON *hfc_node_id_convertToJSON(hfc_node_id_t *hfc_node_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(hfc_node_id == NULL) {
		printf("hfc_node_id_convertToJSON() failed [HfcNodeId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!hfc_node_id->hfc_nid) {
		printf("hfc_node_id_convertToJSON() failed [hfc_nid]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "hfcNId",
	                           hfc_node_id->hfc_nid) == NULL)
	{
		printf("hfc_node_id_convertToJSON() failed [hfc_nid]");
		goto end;
	}

end:
	return item;
}

hfc_node_id_t *hfc_node_id_parseFromJSON(cJSON *hfc_node_idJSON) {
	hfc_node_id_t *hfc_node_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *hfc_nid = NULL;
	hfc_nid = cJSON_GetObjectItemCaseSensitive(hfc_node_idJSON, "hfcNId");
	if(!hfc_nid) {
		printf("hfc_node_id_parseFromJSON() failed [hfc_nid]");
		goto end;
	}
	if(!cJSON_IsString(hfc_nid)) {
		printf("hfc_node_id_parseFromJSON() failed [hfc_nid]");
		goto end;
	}

	hfc_node_id_local_var = hfc_node_id_create(
		strdup(hfc_nid->valuestring)
		);

	return hfc_node_id_local_var;
end:
	return NULL;
}

hfc_node_id_t *hfc_node_id_copy(hfc_node_id_t *dst, hfc_node_id_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = hfc_node_id_convertToJSON(src);
	if(!item) {
		printf("hfc_node_id_convertToJSON() failed");
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

	hfc_node_id_free(dst);
	dst = hfc_node_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
