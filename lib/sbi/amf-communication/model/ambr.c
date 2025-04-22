#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ambr.h"

ambr_t *ambr_create(char *uplink, char *downlink) {
	ambr_t *ambr_local_var = malloc(sizeof(ambr_t));

	ambr_local_var->uplink = uplink;
	ambr_local_var->downlink = downlink;

	return ambr_local_var;
}

void ambr_free(ambr_t *ambr) {
	lnode_t *node = NULL;

	if(NULL == ambr) {
		return;
	}
	if(ambr->uplink) {
		free(ambr->uplink);
		ambr->uplink = NULL;
	}
	if(ambr->downlink) {
		free(ambr->downlink);
		ambr->downlink = NULL;
	}
	free(ambr);
}

cJSON *ambr_convertToJSON(ambr_t *ambr) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ambr == NULL) {
		printf("ambr_convertToJSON() failed [Ambr]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ambr->uplink) {
		printf("ambr_convertToJSON() failed [uplink]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "uplink", ambr->uplink) == NULL) {
		printf("ambr_convertToJSON() failed [uplink]");
		goto end;
	}

	if(!ambr->downlink) {
		printf("ambr_convertToJSON() failed [downlink]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "downlink", ambr->downlink) == NULL) {
		printf("ambr_convertToJSON() failed [downlink]");
		goto end;
	}

end:
	return item;
}

ambr_t *ambr_parseFromJSON(cJSON *ambrJSON) {
	ambr_t *ambr_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *uplink = NULL;
	cJSON *downlink = NULL;
	uplink = cJSON_GetObjectItemCaseSensitive(ambrJSON, "uplink");
	if(!uplink) {
		printf("ambr_parseFromJSON() failed [uplink]");
		goto end;
	}
	if(!cJSON_IsString(uplink)) {
		printf("ambr_parseFromJSON() failed [uplink]");
		goto end;
	}

	downlink = cJSON_GetObjectItemCaseSensitive(ambrJSON, "downlink");
	if(!downlink) {
		printf("ambr_parseFromJSON() failed [downlink]");
		goto end;
	}
	if(!cJSON_IsString(downlink)) {
		printf("ambr_parseFromJSON() failed [downlink]");
		goto end;
	}

	ambr_local_var = ambr_create(
		strdup(uplink->valuestring),
		strdup(downlink->valuestring)
		);

	return ambr_local_var;
end:
	return NULL;
}

ambr_t *ambr_copy(ambr_t *dst, ambr_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ambr_convertToJSON(src);
	if(!item) {
		printf("ambr_convertToJSON() failed");
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

	ambr_free(dst);
	dst = ambr_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
