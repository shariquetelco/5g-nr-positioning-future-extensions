#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_prefix.h"

ipv6_prefix_t *ipv6_prefix_create() {
	ipv6_prefix_t *ipv6_prefix_local_var = malloc(sizeof(ipv6_prefix_t));


	return ipv6_prefix_local_var;
}

void ipv6_prefix_free(ipv6_prefix_t *ipv6_prefix) {
	lnode_t *node = NULL;

	if(NULL == ipv6_prefix) {
		return;
	}
	free(ipv6_prefix);
}

cJSON *ipv6_prefix_convertToJSON(ipv6_prefix_t *ipv6_prefix) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ipv6_prefix == NULL) {
		printf("ipv6_prefix_convertToJSON() failed [Ipv6Prefix]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

ipv6_prefix_t *ipv6_prefix_parseFromJSON(cJSON *ipv6_prefixJSON) {
	ipv6_prefix_t *ipv6_prefix_local_var = NULL;
	lnode_t *node = NULL;
	ipv6_prefix_local_var = ipv6_prefix_create(
		);

	return ipv6_prefix_local_var;
end:
	return NULL;
}

ipv6_prefix_t *ipv6_prefix_copy(ipv6_prefix_t *dst, ipv6_prefix_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ipv6_prefix_convertToJSON(src);
	if(!item) {
		printf("ipv6_prefix_convertToJSON() failed");
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

	ipv6_prefix_free(dst);
	dst = ipv6_prefix_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
