#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nf_status.h"

nf_status_t *nf_status_create(bool is_status_registered, int status_registered,
                              bool is_status_unregistered,
                              int status_unregistered,
                              bool is_status_undiscoverable,
                              int status_undiscoverable) {
	nf_status_t *nf_status_local_var = malloc(sizeof(nf_status_t));

	nf_status_local_var->is_status_registered = is_status_registered;
	nf_status_local_var->status_registered = status_registered;
	nf_status_local_var->is_status_unregistered = is_status_unregistered;
	nf_status_local_var->status_unregistered = status_unregistered;
	nf_status_local_var->is_status_undiscoverable =
		is_status_undiscoverable;
	nf_status_local_var->status_undiscoverable = status_undiscoverable;

	return nf_status_local_var;
}

void nf_status_free(nf_status_t *nf_status) {
	lnode_t *node = NULL;

	if(NULL == nf_status) {
		return;
	}
	free(nf_status);
}

cJSON *nf_status_convertToJSON(nf_status_t *nf_status) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nf_status == NULL) {
		printf("nf_status_convertToJSON() failed [NfStatus]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(nf_status->is_status_registered) {
		if(cJSON_AddNumberToObject(item, "statusRegistered",
		                           nf_status->status_registered) ==
		   NULL)
		{
			printf(
				"nf_status_convertToJSON() failed [status_registered]");
			goto end;
		}
	}

	if(nf_status->is_status_unregistered) {
		if(cJSON_AddNumberToObject(item, "statusUnregistered",
		                           nf_status->status_unregistered) ==
		   NULL)
		{
			printf(
				"nf_status_convertToJSON() failed [status_unregistered]");
			goto end;
		}
	}

	if(nf_status->is_status_undiscoverable) {
		if(cJSON_AddNumberToObject(item, "statusUndiscoverable",
		                           nf_status->status_undiscoverable) ==
		   NULL)
		{
			printf(
				"nf_status_convertToJSON() failed [status_undiscoverable]");
			goto end;
		}
	}

end:
	return item;
}

nf_status_t *nf_status_parseFromJSON(cJSON *nf_statusJSON) {
	nf_status_t *nf_status_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *status_registered = NULL;
	cJSON *status_unregistered = NULL;
	cJSON *status_undiscoverable = NULL;
	status_registered = cJSON_GetObjectItemCaseSensitive(nf_statusJSON,
	                                                     "statusRegistered");
	if(status_registered) {
		if(!cJSON_IsNumber(status_registered)) {
			printf(
				"nf_status_parseFromJSON() failed [status_registered]");
			goto end;
		}
	}

	status_unregistered = cJSON_GetObjectItemCaseSensitive(nf_statusJSON,
	                                                       "statusUnregistered");
	if(status_unregistered) {
		if(!cJSON_IsNumber(status_unregistered)) {
			printf(
				"nf_status_parseFromJSON() failed [status_unregistered]");
			goto end;
		}
	}

	status_undiscoverable = cJSON_GetObjectItemCaseSensitive(nf_statusJSON,
	                                                         "statusUndiscoverable");
	if(status_undiscoverable) {
		if(!cJSON_IsNumber(status_undiscoverable)) {
			printf(
				"nf_status_parseFromJSON() failed [status_undiscoverable]");
			goto end;
		}
	}

	nf_status_local_var = nf_status_create(
		status_registered ? true : false,
		status_registered ? status_registered->valuedouble : 0,
		status_unregistered ? true : false,
		status_unregistered ? status_unregistered->valuedouble : 0,
		status_undiscoverable ? true : false,
		status_undiscoverable ? status_undiscoverable->valuedouble : 0
		);

	return nf_status_local_var;
end:
	return NULL;
}

nf_status_t *nf_status_copy(nf_status_t *dst, nf_status_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nf_status_convertToJSON(src);
	if(!item) {
		printf("nf_status_convertToJSON() failed");
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

	nf_status_free(dst);
	dst = nf_status_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
