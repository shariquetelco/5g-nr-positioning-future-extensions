#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event_type.h"

amf_event_type_t *amf_event_type_create() {
	amf_event_type_t *amf_event_type_local_var =
		malloc(sizeof(amf_event_type_t));


	return amf_event_type_local_var;
}

void amf_event_type_free(amf_event_type_t *amf_event_type) {
	lnode_t *node = NULL;

	if(NULL == amf_event_type) {
		return;
	}
	free(amf_event_type);
}

cJSON *amf_event_type_convertToJSON(amf_event_type_t *amf_event_type) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event_type == NULL) {
		printf("amf_event_type_convertToJSON() failed [AmfEventType]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

amf_event_type_t *amf_event_type_parseFromJSON(cJSON *amf_event_typeJSON) {
	amf_event_type_t *amf_event_type_local_var = NULL;
	lnode_t *node = NULL;
	amf_event_type_local_var = amf_event_type_create(
		);

	return amf_event_type_local_var;
end:
	return NULL;
}

amf_event_type_t *amf_event_type_copy(amf_event_type_t	*dst,
                                      amf_event_type_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_type_convertToJSON(src);
	if(!item) {
		printf("amf_event_type_convertToJSON() failed");
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

	amf_event_type_free(dst);
	dst = amf_event_type_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
