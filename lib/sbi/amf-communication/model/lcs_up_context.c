#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_up_context.h"

lcs_up_context_t *lcs_up_context_create(
	up_connection_status_t	*up_connection_status,
	char			*serving_lmf_identification) {
	lcs_up_context_t *lcs_up_context_local_var =
		malloc(sizeof(lcs_up_context_t));

	lcs_up_context_local_var->up_connection_status = up_connection_status;
	lcs_up_context_local_var->serving_lmf_identification =
		serving_lmf_identification;

	return lcs_up_context_local_var;
}

void lcs_up_context_free(lcs_up_context_t *lcs_up_context) {
	lnode_t *node = NULL;

	if(NULL == lcs_up_context) {
		return;
	}
	if(lcs_up_context->up_connection_status) {
		up_connection_status_free(lcs_up_context->up_connection_status);
		lcs_up_context->up_connection_status = NULL;
	}
	if(lcs_up_context->serving_lmf_identification) {
		free(lcs_up_context->serving_lmf_identification);
		lcs_up_context->serving_lmf_identification = NULL;
	}
	free(lcs_up_context);
}

cJSON *lcs_up_context_convertToJSON(lcs_up_context_t *lcs_up_context) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(lcs_up_context == NULL) {
		printf("lcs_up_context_convertToJSON() failed [LcsUpContext]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(lcs_up_context->up_connection_status) {
		cJSON *up_connection_status_local_JSON =
			up_connection_status_convertToJSON(
				lcs_up_context->up_connection_status);
		if(up_connection_status_local_JSON == NULL) {
			printf(
				"lcs_up_context_convertToJSON() failed [up_connection_status]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upConnectionStatus",
		                      up_connection_status_local_JSON);
		if(item->child == NULL) {
			printf(
				"lcs_up_context_convertToJSON() failed [up_connection_status]");
			goto end;
		}
	}

	if(lcs_up_context->serving_lmf_identification) {
		if(cJSON_AddStringToObject(item, "servingLMFIdentification",
		                           lcs_up_context->
		                           serving_lmf_identification) == NULL)
		{
			printf(
				"lcs_up_context_convertToJSON() failed [serving_lmf_identification]");
			goto end;
		}
	}

end:
	return item;
}

lcs_up_context_t *lcs_up_context_parseFromJSON(cJSON *lcs_up_contextJSON) {
	lcs_up_context_t *lcs_up_context_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *up_connection_status = NULL;
	up_connection_status_t *up_connection_status_local_nonprim = NULL;
	cJSON *serving_lmf_identification = NULL;
	up_connection_status = cJSON_GetObjectItemCaseSensitive(
		lcs_up_contextJSON, "upConnectionStatus");
	if(up_connection_status) {
		up_connection_status_local_nonprim =
			up_connection_status_parseFromJSON(up_connection_status);
		if(!up_connection_status_local_nonprim) {
			printf(
				"up_connection_status_parseFromJSON failed [up_connection_status]");
			goto end;
		}
	}

	serving_lmf_identification = cJSON_GetObjectItemCaseSensitive(
		lcs_up_contextJSON, "servingLMFIdentification");
	if(serving_lmf_identification) {
		if(!cJSON_IsString(serving_lmf_identification) &&
		   !cJSON_IsNull(serving_lmf_identification))
		{
			printf(
				"lcs_up_context_parseFromJSON() failed [serving_lmf_identification]");
			goto end;
		}
	}

	lcs_up_context_local_var = lcs_up_context_create(
		up_connection_status ? up_connection_status_local_nonprim : NULL,
		serving_lmf_identification &&
		!cJSON_IsNull(serving_lmf_identification) ? strdup(
			serving_lmf_identification->valuestring) : NULL
		);

	return lcs_up_context_local_var;
end:
	if(up_connection_status_local_nonprim) {
		up_connection_status_free(up_connection_status_local_nonprim);
		up_connection_status_local_nonprim = NULL;
	}
	return NULL;
}

lcs_up_context_t *lcs_up_context_copy(lcs_up_context_t	*dst,
                                      lcs_up_context_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = lcs_up_context_convertToJSON(src);
	if(!item) {
		printf("lcs_up_context_convertToJSON() failed");
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

	lcs_up_context_free(dst);
	dst = lcs_up_context_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
