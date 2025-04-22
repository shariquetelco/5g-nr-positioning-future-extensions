#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_key_response.h"

ciphering_key_response_t *ciphering_key_response_create(
	list_t *ciphering_data_report) {
	ciphering_key_response_t *ciphering_key_response_local_var = malloc(
		sizeof(ciphering_key_response_t));

	ciphering_key_response_local_var->ciphering_data_report =
		ciphering_data_report;

	return ciphering_key_response_local_var;
}

void ciphering_key_response_free(
	ciphering_key_response_t *ciphering_key_response) {
	lnode_t *node = NULL;

	if(NULL == ciphering_key_response) {
		return;
	}
	if(ciphering_key_response->ciphering_data_report) {
		list_for_each(ciphering_key_response->ciphering_data_report,
		              node) {
			ciphering_set_report_free(node->data);
		}
		list_free(ciphering_key_response->ciphering_data_report);
		ciphering_key_response->ciphering_data_report = NULL;
	}
	free(ciphering_key_response);
}

cJSON *ciphering_key_response_convertToJSON(
	ciphering_key_response_t *ciphering_key_response) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ciphering_key_response == NULL) {
		printf(
			"ciphering_key_response_convertToJSON() failed [CipheringKeyResponse]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ciphering_key_response->ciphering_data_report) {
		cJSON *ciphering_data_reportList = cJSON_AddArrayToObject(item,
		                                                          "cipheringDataReport");
		if(ciphering_data_reportList == NULL) {
			printf(
				"ciphering_key_response_convertToJSON() failed [ciphering_data_report]");
			goto end;
		}
		list_for_each(ciphering_key_response->ciphering_data_report,
		              node) {
			cJSON *itemLocal = ciphering_set_report_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"ciphering_key_response_convertToJSON() failed [ciphering_data_report]");
				goto end;
			}
			cJSON_AddItemToArray(ciphering_data_reportList,
			                     itemLocal);
		}
	}

end:
	return item;
}

ciphering_key_response_t *ciphering_key_response_parseFromJSON(
	cJSON *ciphering_key_responseJSON) {
	ciphering_key_response_t *ciphering_key_response_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ciphering_data_report = NULL;
	list_t *ciphering_data_reportList = NULL;
	ciphering_data_report = cJSON_GetObjectItemCaseSensitive(
		ciphering_key_responseJSON, "cipheringDataReport");
	if(ciphering_data_report) {
		cJSON *ciphering_data_report_local = NULL;
		if(!cJSON_IsArray(ciphering_data_report)) {
			printf(
				"ciphering_key_response_parseFromJSON() failed [ciphering_data_report]");
			goto end;
		}

		ciphering_data_reportList = list_create();

		cJSON_ArrayForEach(ciphering_data_report_local,
		                   ciphering_data_report) {
			if(!cJSON_IsObject(ciphering_data_report_local)) {
				printf(
					"ciphering_key_response_parseFromJSON() failed [ciphering_data_report]");
				goto end;
			}
			ciphering_set_report_t *ciphering_data_reportItem =
				ciphering_set_report_parseFromJSON(
					ciphering_data_report_local);
			if(!ciphering_data_reportItem) {
				printf("No ciphering_data_reportItem");
				goto end;
			}
			list_add(ciphering_data_reportList,
			         ciphering_data_reportItem);
		}
	}

	ciphering_key_response_local_var = ciphering_key_response_create(
		ciphering_data_report ? ciphering_data_reportList : NULL
		);

	return ciphering_key_response_local_var;
end:
	if(ciphering_data_reportList) {
		list_for_each(ciphering_data_reportList, node) {
			ciphering_set_report_free(node->data);
		}
		list_free(ciphering_data_reportList);
		ciphering_data_reportList = NULL;
	}
	return NULL;
}

ciphering_key_response_t *ciphering_key_response_copy(
	ciphering_key_response_t *dst, ciphering_key_response_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ciphering_key_response_convertToJSON(src);
	if(!item) {
		printf("ciphering_key_response_convertToJSON() failed");
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

	ciphering_key_response_free(dst);
	dst = ciphering_key_response_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
