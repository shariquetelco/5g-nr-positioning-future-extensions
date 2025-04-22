#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "transport_protocol.h"

transport_protocol_t *transport_protocol_create() {
	transport_protocol_t *transport_protocol_local_var =
		malloc(sizeof(transport_protocol_t));


	return transport_protocol_local_var;
}

void transport_protocol_free(transport_protocol_t *transport_protocol) {
	lnode_t *node = NULL;

	if(NULL == transport_protocol) {
		return;
	}
	free(transport_protocol);
}

cJSON *transport_protocol_convertToJSON(
	transport_protocol_t *transport_protocol) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(transport_protocol == NULL) {
		printf(
			"transport_protocol_convertToJSON() failed [TransportProtocol]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

transport_protocol_t *transport_protocol_parseFromJSON(
	cJSON *transport_protocolJSON) {
	transport_protocol_t *transport_protocol_local_var = NULL;
	lnode_t *node = NULL;
	transport_protocol_local_var = transport_protocol_create(
		);

	return transport_protocol_local_var;
end:
	return NULL;
}

transport_protocol_t *transport_protocol_copy(transport_protocol_t	*dst,
                                              transport_protocol_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = transport_protocol_convertToJSON(src);
	if(!item) {
		printf("transport_protocol_convertToJSON() failed");
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

	transport_protocol_free(dst);
	dst = transport_protocol_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
