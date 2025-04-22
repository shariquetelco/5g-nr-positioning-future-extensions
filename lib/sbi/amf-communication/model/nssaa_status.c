#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nssaa_status.h"

nssaa_status_t *nssaa_status_create(snssai_t *snssai, auth_status_t *status) {
	nssaa_status_t *nssaa_status_local_var = malloc(sizeof(nssaa_status_t));

	nssaa_status_local_var->snssai = snssai;
	nssaa_status_local_var->status = status;

	return nssaa_status_local_var;
}

void nssaa_status_free(nssaa_status_t *nssaa_status) {
	lnode_t *node = NULL;

	if(NULL == nssaa_status) {
		return;
	}
	if(nssaa_status->snssai) {
		snssai_free(nssaa_status->snssai);
		nssaa_status->snssai = NULL;
	}
	if(nssaa_status->status) {
		auth_status_free(nssaa_status->status);
		nssaa_status->status = NULL;
	}
	free(nssaa_status);
}

cJSON *nssaa_status_convertToJSON(nssaa_status_t *nssaa_status) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nssaa_status == NULL) {
		printf("nssaa_status_convertToJSON() failed [NssaaStatus]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!nssaa_status->snssai) {
		printf("nssaa_status_convertToJSON() failed [snssai]");
		return NULL;
	}
	cJSON *snssai_local_JSON = snssai_convertToJSON(nssaa_status->snssai);
	if(snssai_local_JSON == NULL) {
		printf("nssaa_status_convertToJSON() failed [snssai]");
		goto end;
	}
	cJSON_AddItemToObject(item, "snssai", snssai_local_JSON);
	if(item->child == NULL) {
		printf("nssaa_status_convertToJSON() failed [snssai]");
		goto end;
	}

	if(!nssaa_status->status) {
		printf("nssaa_status_convertToJSON() failed [status]");
		return NULL;
	}
	cJSON *status_local_JSON = auth_status_convertToJSON(
		nssaa_status->status);
	if(status_local_JSON == NULL) {
		printf("nssaa_status_convertToJSON() failed [status]");
		goto end;
	}
	cJSON_AddItemToObject(item, "status", status_local_JSON);
	if(item->child == NULL) {
		printf("nssaa_status_convertToJSON() failed [status]");
		goto end;
	}

end:
	return item;
}

nssaa_status_t *nssaa_status_parseFromJSON(cJSON *nssaa_statusJSON) {
	nssaa_status_t *nssaa_status_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *snssai = NULL;
	snssai_t *snssai_local_nonprim = NULL;
	cJSON *status = NULL;
	auth_status_t *status_local_nonprim = NULL;
	snssai = cJSON_GetObjectItemCaseSensitive(nssaa_statusJSON, "snssai");
	if(!snssai) {
		printf("nssaa_status_parseFromJSON() failed [snssai]");
		goto end;
	}
	snssai_local_nonprim = snssai_parseFromJSON(snssai);
	if(!snssai_local_nonprim) {
		printf("snssai_parseFromJSON failed [snssai]");
		goto end;
	}

	status = cJSON_GetObjectItemCaseSensitive(nssaa_statusJSON, "status");
	if(!status) {
		printf("nssaa_status_parseFromJSON() failed [status]");
		goto end;
	}
	status_local_nonprim = auth_status_parseFromJSON(status);
	if(!status_local_nonprim) {
		printf("auth_status_parseFromJSON failed [status]");
		goto end;
	}

	nssaa_status_local_var = nssaa_status_create(
		snssai_local_nonprim,
		status_local_nonprim
		);

	return nssaa_status_local_var;
end:
	if(snssai_local_nonprim) {
		snssai_free(snssai_local_nonprim);
		snssai_local_nonprim = NULL;
	}
	if(status_local_nonprim) {
		auth_status_free(status_local_nonprim);
		status_local_nonprim = NULL;
	}
	return NULL;
}

nssaa_status_t *nssaa_status_copy(nssaa_status_t *dst, nssaa_status_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nssaa_status_convertToJSON(src);
	if(!item) {
		printf("nssaa_status_convertToJSON() failed");
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

	nssaa_status_free(dst);
	dst = nssaa_status_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
