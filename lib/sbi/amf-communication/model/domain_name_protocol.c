#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "domain_name_protocol.h"

domain_name_protocol_t *domain_name_protocol_create() {
	domain_name_protocol_t *domain_name_protocol_local_var =
		malloc(sizeof(domain_name_protocol_t));


	return domain_name_protocol_local_var;
}

void domain_name_protocol_free(domain_name_protocol_t *domain_name_protocol) {
	lnode_t *node = NULL;

	if(NULL == domain_name_protocol) {
		return;
	}
	free(domain_name_protocol);
}

cJSON *domain_name_protocol_convertToJSON(
	domain_name_protocol_t *domain_name_protocol) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(domain_name_protocol == NULL) {
		printf(
			"domain_name_protocol_convertToJSON() failed [DomainNameProtocol]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

domain_name_protocol_t *domain_name_protocol_parseFromJSON(
	cJSON *domain_name_protocolJSON) {
	domain_name_protocol_t *domain_name_protocol_local_var = NULL;
	lnode_t *node = NULL;
	domain_name_protocol_local_var = domain_name_protocol_create(
		);

	return domain_name_protocol_local_var;
end:
	return NULL;
}

domain_name_protocol_t *domain_name_protocol_copy(
	domain_name_protocol_t	*dst,
	domain_name_protocol_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = domain_name_protocol_convertToJSON(src);
	if(!item) {
		printf("domain_name_protocol_convertToJSON() failed");
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

	domain_name_protocol_free(dst);
	dst = domain_name_protocol_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
