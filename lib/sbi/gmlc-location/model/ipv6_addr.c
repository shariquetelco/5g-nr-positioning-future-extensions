#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_addr.h"

ipv6_addr_t *ipv6_addr_create() {
	ipv6_addr_t *ipv6_addr_local_var = malloc(sizeof(ipv6_addr_t));


	return ipv6_addr_local_var;
}

void ipv6_addr_free(ipv6_addr_t *ipv6_addr) {
	lnode_t *node = NULL;

	if(NULL == ipv6_addr) {
		return;
	}
	free(ipv6_addr);
}

cJSON *ipv6_addr_convertToJSON(ipv6_addr_t *ipv6_addr) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ipv6_addr == NULL) {
		printf("ipv6_addr_convertToJSON() failed [Ipv6Addr]");
		return NULL;
	}

	item = cJSON_CreateObject();
end:
	return item;
}

ipv6_addr_t *ipv6_addr_parseFromJSON(cJSON *ipv6_addrJSON) {
	ipv6_addr_t *ipv6_addr_local_var = NULL;
	lnode_t *node = NULL;
	ipv6_addr_local_var = ipv6_addr_create(
		);

	return ipv6_addr_local_var;
end:
	return NULL;
}

ipv6_addr_t *ipv6_addr_copy(ipv6_addr_t *dst, ipv6_addr_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ipv6_addr_convertToJSON(src);
	if(!item) {
		printf("ipv6_addr_convertToJSON() failed");
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

	ipv6_addr_free(dst);
	dst = ipv6_addr_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
