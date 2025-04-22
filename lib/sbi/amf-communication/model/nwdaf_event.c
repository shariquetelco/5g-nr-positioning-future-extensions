#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_event.h"

nwdaf_event_t *nwdaf_event_create() {
	nwdaf_event_t *nwdaf_event_local_var = malloc(sizeof(nwdaf_event_t));


	return nwdaf_event_local_var;
}

void nwdaf_event_free(nwdaf_event_t *nwdaf_event) {
	lnode_t *node = NULL;

	if(NULL == nwdaf_event) {
		return;
	}
	free(nwdaf_event);
}

cJSON *nwdaf_event_convertToJSON(nwdaf_event_t *nwdaf_event) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(nwdaf_event == NULL) {
		printf("nwdaf_event_convertToJSON() failed [NwdafEvent]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

nwdaf_event_t *nwdaf_event_parseFromJSON(cJSON *nwdaf_eventJSON) {
	nwdaf_event_t *nwdaf_event_local_var = NULL;
	lnode_t *node = NULL;
	nwdaf_event_local_var = nwdaf_event_create(
		);

	return nwdaf_event_local_var;
end:
	return NULL;
}

nwdaf_event_t *nwdaf_event_copy(nwdaf_event_t *dst, nwdaf_event_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = nwdaf_event_convertToJSON(src);
	if(!item) {
		printf("nwdaf_event_convertToJSON() failed");
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

	nwdaf_event_free(dst);
	dst = nwdaf_event_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
