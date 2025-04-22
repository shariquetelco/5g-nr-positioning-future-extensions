#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plmn_id_nid.h"

plmn_id_nid_t *plmn_id_nid_create(char *mcc, char *mnc, char *nid) {
	plmn_id_nid_t *plmn_id_nid_local_var = malloc(sizeof(plmn_id_nid_t));

	plmn_id_nid_local_var->mcc = mcc;
	plmn_id_nid_local_var->mnc = mnc;
	plmn_id_nid_local_var->nid = nid;

	return plmn_id_nid_local_var;
}

void plmn_id_nid_free(plmn_id_nid_t *plmn_id_nid) {
	lnode_t *node = NULL;

	if(NULL == plmn_id_nid) {
		return;
	}
	if(plmn_id_nid->mcc) {
		free(plmn_id_nid->mcc);
		plmn_id_nid->mcc = NULL;
	}
	if(plmn_id_nid->mnc) {
		free(plmn_id_nid->mnc);
		plmn_id_nid->mnc = NULL;
	}
	if(plmn_id_nid->nid) {
		free(plmn_id_nid->nid);
		plmn_id_nid->nid = NULL;
	}
	free(plmn_id_nid);
}

cJSON *plmn_id_nid_convertToJSON(plmn_id_nid_t *plmn_id_nid) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(plmn_id_nid == NULL) {
		printf("plmn_id_nid_convertToJSON() failed [PlmnIdNid]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!plmn_id_nid->mcc) {
		printf("plmn_id_nid_convertToJSON() failed [mcc]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "mcc", plmn_id_nid->mcc) == NULL) {
		printf("plmn_id_nid_convertToJSON() failed [mcc]");
		goto end;
	}

	if(!plmn_id_nid->mnc) {
		printf("plmn_id_nid_convertToJSON() failed [mnc]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "mnc", plmn_id_nid->mnc) == NULL) {
		printf("plmn_id_nid_convertToJSON() failed [mnc]");
		goto end;
	}

	if(plmn_id_nid->nid) {
		if(cJSON_AddStringToObject(item, "nid",
		                           plmn_id_nid->nid) == NULL)
		{
			printf("plmn_id_nid_convertToJSON() failed [nid]");
			goto end;
		}
	}

end:
	return item;
}

plmn_id_nid_t *plmn_id_nid_parseFromJSON(cJSON *plmn_id_nidJSON) {
	plmn_id_nid_t *plmn_id_nid_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *mcc = NULL;
	cJSON *mnc = NULL;
	cJSON *nid = NULL;
	mcc = cJSON_GetObjectItemCaseSensitive(plmn_id_nidJSON, "mcc");
	if(!mcc) {
		printf("plmn_id_nid_parseFromJSON() failed [mcc]");
		goto end;
	}
	if(!cJSON_IsString(mcc)) {
		printf("plmn_id_nid_parseFromJSON() failed [mcc]");
		goto end;
	}

	mnc = cJSON_GetObjectItemCaseSensitive(plmn_id_nidJSON, "mnc");
	if(!mnc) {
		printf("plmn_id_nid_parseFromJSON() failed [mnc]");
		goto end;
	}
	if(!cJSON_IsString(mnc)) {
		printf("plmn_id_nid_parseFromJSON() failed [mnc]");
		goto end;
	}

	nid = cJSON_GetObjectItemCaseSensitive(plmn_id_nidJSON, "nid");
	if(nid) {
		if(!cJSON_IsString(nid) &&
		   !cJSON_IsNull(nid))
		{
			printf("plmn_id_nid_parseFromJSON() failed [nid]");
			goto end;
		}
	}

	plmn_id_nid_local_var = plmn_id_nid_create(
		strdup(mcc->valuestring),
		strdup(mnc->valuestring),
		nid &&
		!cJSON_IsNull(nid) ? strdup(nid->valuestring) : NULL
		);

	return plmn_id_nid_local_var;
end:
	return NULL;
}

plmn_id_nid_t *plmn_id_nid_copy(plmn_id_nid_t *dst, plmn_id_nid_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = plmn_id_nid_convertToJSON(src);
	if(!item) {
		printf("plmn_id_nid_convertToJSON() failed");
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

	plmn_id_nid_free(dst);
	dst = plmn_id_nid_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
