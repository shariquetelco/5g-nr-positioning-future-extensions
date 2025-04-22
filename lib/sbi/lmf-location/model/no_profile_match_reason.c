#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "no_profile_match_reason.h"

no_profile_match_reason_t *no_profile_match_reason_create() {
	no_profile_match_reason_t *no_profile_match_reason_local_var = malloc(
		sizeof(no_profile_match_reason_t));


	return no_profile_match_reason_local_var;
}

void no_profile_match_reason_free(
	no_profile_match_reason_t *no_profile_match_reason) {
	lnode_t *node = NULL;

	if(NULL == no_profile_match_reason) {
		return;
	}
	free(no_profile_match_reason);
}

cJSON *no_profile_match_reason_convertToJSON(
	no_profile_match_reason_t *no_profile_match_reason) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(no_profile_match_reason == NULL) {
		printf(
			"no_profile_match_reason_convertToJSON() failed [NoProfileMatchReason]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

no_profile_match_reason_t *no_profile_match_reason_parseFromJSON(
	cJSON *no_profile_match_reasonJSON) {
	no_profile_match_reason_t *no_profile_match_reason_local_var = NULL;
	lnode_t *node = NULL;
	no_profile_match_reason_local_var = no_profile_match_reason_create(
		);

	return no_profile_match_reason_local_var;
end:
	return NULL;
}

no_profile_match_reason_t *no_profile_match_reason_copy(
	no_profile_match_reason_t *dst, no_profile_match_reason_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = no_profile_match_reason_convertToJSON(src);
	if(!item) {
		printf("no_profile_match_reason_convertToJSON() failed");
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

	no_profile_match_reason_free(dst);
	dst = no_profile_match_reason_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
