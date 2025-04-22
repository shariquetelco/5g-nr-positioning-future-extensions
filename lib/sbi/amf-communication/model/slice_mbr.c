#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "slice_mbr.h"

slice_mbr_t *slice_mbr_create(char *uplink, char *downlink) {
	slice_mbr_t *slice_mbr_local_var = malloc(sizeof(slice_mbr_t));

	slice_mbr_local_var->uplink = uplink;
	slice_mbr_local_var->downlink = downlink;

	return slice_mbr_local_var;
}

void slice_mbr_free(slice_mbr_t *slice_mbr) {
	lnode_t *node = NULL;

	if(NULL == slice_mbr) {
		return;
	}
	if(slice_mbr->uplink) {
		free(slice_mbr->uplink);
		slice_mbr->uplink = NULL;
	}
	if(slice_mbr->downlink) {
		free(slice_mbr->downlink);
		slice_mbr->downlink = NULL;
	}
	free(slice_mbr);
}

cJSON *slice_mbr_convertToJSON(slice_mbr_t *slice_mbr) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(slice_mbr == NULL) {
		printf("slice_mbr_convertToJSON() failed [SliceMbr]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!slice_mbr->uplink) {
		printf("slice_mbr_convertToJSON() failed [uplink]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "uplink", slice_mbr->uplink) == NULL) {
		printf("slice_mbr_convertToJSON() failed [uplink]");
		goto end;
	}

	if(!slice_mbr->downlink) {
		printf("slice_mbr_convertToJSON() failed [downlink]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "downlink",
	                           slice_mbr->downlink) == NULL)
	{
		printf("slice_mbr_convertToJSON() failed [downlink]");
		goto end;
	}

end:
	return item;
}

slice_mbr_t *slice_mbr_parseFromJSON(cJSON *slice_mbrJSON) {
	slice_mbr_t *slice_mbr_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *uplink = NULL;
	cJSON *downlink = NULL;
	uplink = cJSON_GetObjectItemCaseSensitive(slice_mbrJSON, "uplink");
	if(!uplink) {
		printf("slice_mbr_parseFromJSON() failed [uplink]");
		goto end;
	}
	if(!cJSON_IsString(uplink)) {
		printf("slice_mbr_parseFromJSON() failed [uplink]");
		goto end;
	}

	downlink = cJSON_GetObjectItemCaseSensitive(slice_mbrJSON, "downlink");
	if(!downlink) {
		printf("slice_mbr_parseFromJSON() failed [downlink]");
		goto end;
	}
	if(!cJSON_IsString(downlink)) {
		printf("slice_mbr_parseFromJSON() failed [downlink]");
		goto end;
	}

	slice_mbr_local_var = slice_mbr_create(
		strdup(uplink->valuestring),
		strdup(downlink->valuestring)
		);

	return slice_mbr_local_var;
end:
	return NULL;
}

slice_mbr_t *slice_mbr_copy(slice_mbr_t *dst, slice_mbr_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = slice_mbr_convertToJSON(src);
	if(!item) {
		printf("slice_mbr_convertToJSON() failed");
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

	slice_mbr_free(dst);
	dst = slice_mbr_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
