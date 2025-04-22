#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "failure_event_info.h"

failure_event_info_t *failure_event_info_create(nwdaf_event_t		*event,
                                                nwdaf_failure_code_t	*failure_code)
{
	failure_event_info_t *failure_event_info_local_var =
		malloc(sizeof(failure_event_info_t));

	failure_event_info_local_var->event = event;
	failure_event_info_local_var->failure_code = failure_code;

	return failure_event_info_local_var;
}

void failure_event_info_free(failure_event_info_t *failure_event_info) {
	lnode_t *node = NULL;

	if(NULL == failure_event_info) {
		return;
	}
	if(failure_event_info->event) {
		nwdaf_event_free(failure_event_info->event);
		failure_event_info->event = NULL;
	}
	if(failure_event_info->failure_code) {
		nwdaf_failure_code_free(failure_event_info->failure_code);
		failure_event_info->failure_code = NULL;
	}
	free(failure_event_info);
}

cJSON *failure_event_info_convertToJSON(
	failure_event_info_t *failure_event_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(failure_event_info == NULL) {
		printf(
			"failure_event_info_convertToJSON() failed [FailureEventInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!failure_event_info->event) {
		printf("failure_event_info_convertToJSON() failed [event]");
		return NULL;
	}
	cJSON *event_local_JSON = nwdaf_event_convertToJSON(
		failure_event_info->event);
	if(event_local_JSON == NULL) {
		printf("failure_event_info_convertToJSON() failed [event]");
		goto end;
	}
	cJSON_AddItemToObject(item, "event", event_local_JSON);
	if(item->child == NULL) {
		printf("failure_event_info_convertToJSON() failed [event]");
		goto end;
	}

	if(!failure_event_info->failure_code) {
		printf(
			"failure_event_info_convertToJSON() failed [failure_code]");
		return NULL;
	}
	cJSON *failure_code_local_JSON = nwdaf_failure_code_convertToJSON(
		failure_event_info->failure_code);
	if(failure_code_local_JSON == NULL) {
		printf(
			"failure_event_info_convertToJSON() failed [failure_code]");
		goto end;
	}
	cJSON_AddItemToObject(item, "failureCode", failure_code_local_JSON);
	if(item->child == NULL) {
		printf(
			"failure_event_info_convertToJSON() failed [failure_code]");
		goto end;
	}

end:
	return item;
}

failure_event_info_t *failure_event_info_parseFromJSON(
	cJSON *failure_event_infoJSON) {
	failure_event_info_t *failure_event_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *event = NULL;
	nwdaf_event_t *event_local_nonprim = NULL;
	cJSON *failure_code = NULL;
	nwdaf_failure_code_t *failure_code_local_nonprim = NULL;
	event =
		cJSON_GetObjectItemCaseSensitive(failure_event_infoJSON,
		                                 "event");
	if(!event) {
		printf("failure_event_info_parseFromJSON() failed [event]");
		goto end;
	}
	event_local_nonprim = nwdaf_event_parseFromJSON(event);
	if(!event_local_nonprim) {
		printf("nwdaf_event_parseFromJSON failed [event]");
		goto end;
	}

	failure_code = cJSON_GetObjectItemCaseSensitive(failure_event_infoJSON,
	                                                "failureCode");
	if(!failure_code) {
		printf(
			"failure_event_info_parseFromJSON() failed [failure_code]");
		goto end;
	}
	failure_code_local_nonprim = nwdaf_failure_code_parseFromJSON(
		failure_code);
	if(!failure_code_local_nonprim) {
		printf("nwdaf_failure_code_parseFromJSON failed [failure_code]");
		goto end;
	}

	failure_event_info_local_var = failure_event_info_create(
		event_local_nonprim,
		failure_code_local_nonprim
		);

	return failure_event_info_local_var;
end:
	if(event_local_nonprim) {
		nwdaf_event_free(event_local_nonprim);
		event_local_nonprim = NULL;
	}
	if(failure_code_local_nonprim) {
		nwdaf_failure_code_free(failure_code_local_nonprim);
		failure_code_local_nonprim = NULL;
	}
	return NULL;
}

failure_event_info_t *failure_event_info_copy(failure_event_info_t	*dst,
                                              failure_event_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = failure_event_info_convertToJSON(src);
	if(!item) {
		printf("failure_event_info_convertToJSON() failed");
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

	failure_event_info_free(dst);
	dst = failure_event_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
