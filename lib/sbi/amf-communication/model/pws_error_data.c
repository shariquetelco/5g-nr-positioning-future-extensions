#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "pws_error_data.h"

pws_error_data_t *pws_error_data_create(int namf_cause) {
	pws_error_data_t *pws_error_data_local_var =
		malloc(sizeof(pws_error_data_t));

	pws_error_data_local_var->namf_cause = namf_cause;

	return pws_error_data_local_var;
}

void pws_error_data_free(pws_error_data_t *pws_error_data) {
	lnode_t *node = NULL;

	if(NULL == pws_error_data) {
		return;
	}
	free(pws_error_data);
}

cJSON *pws_error_data_convertToJSON(pws_error_data_t *pws_error_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(pws_error_data == NULL) {
		printf("pws_error_data_convertToJSON() failed [PWSErrorData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "namfCause",
	                           pws_error_data->namf_cause) == NULL)
	{
		printf("pws_error_data_convertToJSON() failed [namf_cause]");
		goto end;
	}

end:
	return item;
}

pws_error_data_t *pws_error_data_parseFromJSON(cJSON *pws_error_dataJSON) {
	pws_error_data_t *pws_error_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *namf_cause = NULL;
	namf_cause = cJSON_GetObjectItemCaseSensitive(pws_error_dataJSON,
	                                              "namfCause");
	if(!namf_cause) {
		printf("pws_error_data_parseFromJSON() failed [namf_cause]");
		goto end;
	}
	if(!cJSON_IsNumber(namf_cause)) {
		printf("pws_error_data_parseFromJSON() failed [namf_cause]");
		goto end;
	}

	pws_error_data_local_var = pws_error_data_create(

		namf_cause->valuedouble
		);

	return pws_error_data_local_var;
end:
	return NULL;
}

pws_error_data_t *pws_error_data_copy(pws_error_data_t	*dst,
                                      pws_error_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = pws_error_data_convertToJSON(src);
	if(!item) {
		printf("pws_error_data_convertToJSON() failed");
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

	pws_error_data_free(dst);
	dst = pws_error_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
