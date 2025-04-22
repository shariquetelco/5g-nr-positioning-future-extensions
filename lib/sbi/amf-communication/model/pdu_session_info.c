#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pdu_session_info.h"

pdu_session_info_t *pdu_session_info_create(snssai_t *snssai, char *dnn) {
	pdu_session_info_t *pdu_session_info_local_var =
		malloc(sizeof(pdu_session_info_t));

	pdu_session_info_local_var->snssai = snssai;
	pdu_session_info_local_var->dnn = dnn;

	return pdu_session_info_local_var;
}

void pdu_session_info_free(pdu_session_info_t *pdu_session_info) {
	lnode_t *node = NULL;

	if(NULL == pdu_session_info) {
		return;
	}
	if(pdu_session_info->snssai) {
		snssai_free(pdu_session_info->snssai);
		pdu_session_info->snssai = NULL;
	}
	if(pdu_session_info->dnn) {
		free(pdu_session_info->dnn);
		pdu_session_info->dnn = NULL;
	}
	free(pdu_session_info);
}

cJSON *pdu_session_info_convertToJSON(pdu_session_info_t *pdu_session_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pdu_session_info == NULL) {
		printf(
			"pdu_session_info_convertToJSON() failed [PduSessionInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!pdu_session_info->snssai) {
		printf("pdu_session_info_convertToJSON() failed [snssai]");
		return NULL;
	}
	cJSON *snssai_local_JSON =
		snssai_convertToJSON(pdu_session_info->snssai);
	if(snssai_local_JSON == NULL) {
		printf("pdu_session_info_convertToJSON() failed [snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
	if(item->child == NULL) {
		printf("pdu_session_info_convertToJSON() failed [snssai]");
		goto end;
	}

	if(!pdu_session_info->dnn) {
		printf("pdu_session_info_convertToJSON() failed [dnn]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "dnn",
	                           pdu_session_info->dnn) == NULL)
	{
		printf("pdu_session_info_convertToJSON() failed [dnn]");
		goto end;
	}

end:
	return item;
}

pdu_session_info_t *pdu_session_info_parseFromJSON(cJSON *pdu_session_infoJSON)
{
	pdu_session_info_t *pdu_session_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *dnn = NULL;
	snssai =
		cJSON_GetObjectItemCaseSensitive(pdu_session_infoJSON,
		                                 "snssai");
	if(!snssai) {
		printf("pdu_session_info_parseFromJSON() failed [snssai]");
		goto end;
	}
	snssai_local_nonprim = snssai_parseFromJSON(snssai);
	if(!snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [snssai]");
		goto end;
	}

	dnn = cJSON_GetObjectItemCaseSensitive(pdu_session_infoJSON, "dnn");
	if(!dnn) {
		printf("pdu_session_info_parseFromJSON() failed [dnn]");
		goto end;
	}
	if(!cJSON_IsString(dnn)) {
		printf("pdu_session_info_parseFromJSON() failed [dnn]");
		goto end;
	}

	pdu_session_info_local_var = pdu_session_info_create(
		snssai_local_nonprim,
		strdup(dnn->valuestring)
		);

	return pdu_session_info_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	return NULL;
}

pdu_session_info_t *pdu_session_info_copy(pdu_session_info_t	*dst,
                                          pdu_session_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pdu_session_info_convertToJSON(src);
	if(!item) {
		printf("pdu_session_info_convertToJSON() failed");
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

	pdu_session_info_free(dst);
	dst = pdu_session_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
