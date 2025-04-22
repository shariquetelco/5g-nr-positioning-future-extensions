#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plmn_id.h"

plmn_id_t *plmn_id_create(char *mcc, char *mnc) {
	plmn_id_t *plmn_id_local_var = malloc(sizeof(plmn_id_t));

	plmn_id_local_var->mcc = mcc;
	plmn_id_local_var->mnc = mnc;

	return plmn_id_local_var;
}

void plmn_id_free(plmn_id_t *plmn_id) {
	lnode_t *node = NULL;

	if(NULL == plmn_id) {
		return;
	}
	if(plmn_id->mcc) {
		free(plmn_id->mcc);
		plmn_id->mcc = NULL;
	}
	if(plmn_id->mnc) {
		free(plmn_id->mnc);
		plmn_id->mnc = NULL;
	}
	free(plmn_id);
}

cJSON *plmn_id_convertToJSON(plmn_id_t *plmn_id) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(plmn_id == NULL) {
		printf("plmn_id_convertToJSON() failed [PlmnId]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!plmn_id->mcc) {
		printf("plmn_id_convertToJSON() failed [mcc]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "mcc", plmn_id->mcc) == NULL) {
		printf("plmn_id_convertToJSON() failed [mcc]");
		goto end;
	}

	if(!plmn_id->mnc) {
		printf("plmn_id_convertToJSON() failed [mnc]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "mnc", plmn_id->mnc) == NULL) {
		printf("plmn_id_convertToJSON() failed [mnc]");
		goto end;
	}

end:
	return item;
}

plmn_id_t *plmn_id_parseFromJSON(cJSON *plmn_idJSON) {
	plmn_id_t *plmn_id_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *mcc = NULL;
	cJSON *mnc = NULL;
	mcc = cJSON_GetObjectItemCaseSensitive(plmn_idJSON, "mcc");
	if(!mcc) {
		printf("plmn_id_parseFromJSON() failed [mcc]");
		goto end;
	}
	if(!cJSON_IsString(mcc)) {
		printf("plmn_id_parseFromJSON() failed [mcc]");
		goto end;
	}

	mnc = cJSON_GetObjectItemCaseSensitive(plmn_idJSON, "mnc");
	if(!mnc) {
		printf("plmn_id_parseFromJSON() failed [mnc]");
		goto end;
	}
	if(!cJSON_IsString(mnc)) {
		printf("plmn_id_parseFromJSON() failed [mnc]");
		goto end;
	}

	plmn_id_local_var = plmn_id_create(
		strdup(mcc->valuestring),
		strdup(mnc->valuestring)
		);

	return plmn_id_local_var;
end:
	return NULL;
}

plmn_id_t *plmn_id_copy(plmn_id_t *dst, plmn_id_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = plmn_id_convertToJSON(src);
	if(!item) {
		printf("plmn_id_convertToJSON() failed");
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

	plmn_id_free(dst);
	dst = plmn_id_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
