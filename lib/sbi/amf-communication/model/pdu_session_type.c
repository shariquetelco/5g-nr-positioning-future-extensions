#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pdu_session_type.h"

pdu_session_type_t *pdu_session_type_create() {
	pdu_session_type_t *pdu_session_type_local_var =
		malloc(sizeof(pdu_session_type_t));


	return pdu_session_type_local_var;
}

void pdu_session_type_free(pdu_session_type_t *pdu_session_type) {
	lnode_t *node = NULL;

	if(NULL == pdu_session_type) {
		return;
	}
	free(pdu_session_type);
}

cJSON *pdu_session_type_convertToJSON(pdu_session_type_t *pdu_session_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pdu_session_type == NULL) {
		printf(
			"pdu_session_type_convertToJSON() failed [PduSessionType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

pdu_session_type_t *pdu_session_type_parseFromJSON(cJSON *pdu_session_typeJSON)
{
	pdu_session_type_t *pdu_session_type_local_var = NULL;
	lnode_t *node = NULL;
	pdu_session_type_local_var = pdu_session_type_create(
		);

	return pdu_session_type_local_var;
end:
	return NULL;
}

pdu_session_type_t *pdu_session_type_copy(pdu_session_type_t	*dst,
                                          pdu_session_type_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pdu_session_type_convertToJSON(src);
	if(!item) {
		printf("pdu_session_type_convertToJSON() failed");
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

	pdu_session_type_free(dst);
	dst = pdu_session_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
