#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ng_ap_cause.h"

ng_ap_cause_t *ng_ap_cause_create(int group, int value) {
	ng_ap_cause_t *ng_ap_cause_local_var = malloc(sizeof(ng_ap_cause_t));

	ng_ap_cause_local_var->group = group;
	ng_ap_cause_local_var->value = value;

	return ng_ap_cause_local_var;
}

void ng_ap_cause_free(ng_ap_cause_t *ng_ap_cause) {
	lnode_t *node = NULL;

	if(NULL == ng_ap_cause) {
		return;
	}
	free(ng_ap_cause);
}

cJSON *ng_ap_cause_convertToJSON(ng_ap_cause_t *ng_ap_cause) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ng_ap_cause == NULL) {
		printf("ng_ap_cause_convertToJSON() failed [NgApCause]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "group", ng_ap_cause->group) == NULL) {
		printf("ng_ap_cause_convertToJSON() failed [group]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "value", ng_ap_cause->value) == NULL) {
		printf("ng_ap_cause_convertToJSON() failed [value]");
		goto end;
	}

end:
	return item;
}

ng_ap_cause_t *ng_ap_cause_parseFromJSON(cJSON *ng_ap_causeJSON) {
	ng_ap_cause_t *ng_ap_cause_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *group = NULL;
	cJSON *value = NULL;
	group = cJSON_GetObjectItemCaseSensitive(ng_ap_causeJSON, "group");
	if(!group) {
		printf("ng_ap_cause_parseFromJSON() failed [group]");
		goto end;
	}
	if(!cJSON_IsNumber(group)) {
		printf("ng_ap_cause_parseFromJSON() failed [group]");
		goto end;
	}

	value = cJSON_GetObjectItemCaseSensitive(ng_ap_causeJSON, "value");
	if(!value) {
		printf("ng_ap_cause_parseFromJSON() failed [value]");
		goto end;
	}
	if(!cJSON_IsNumber(value)) {
		printf("ng_ap_cause_parseFromJSON() failed [value]");
		goto end;
	}

	ng_ap_cause_local_var = ng_ap_cause_create(

		group->valuedouble,

		value->valuedouble
		);

	return ng_ap_cause_local_var;
end:
	return NULL;
}

ng_ap_cause_t *ng_ap_cause_copy(ng_ap_cause_t *dst, ng_ap_cause_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ng_ap_cause_convertToJSON(src);
	if(!item) {
		printf("ng_ap_cause_convertToJSON() failed");
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

	ng_ap_cause_free(dst);
	dst = ng_ap_cause_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
