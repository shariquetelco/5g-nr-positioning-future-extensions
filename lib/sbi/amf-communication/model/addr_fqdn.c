#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "addr_fqdn.h"

addr_fqdn_t *addr_fqdn_create(ip_addr_t *ip_addr, char *fqdn) {
	addr_fqdn_t *addr_fqdn_local_var = malloc(sizeof(addr_fqdn_t));

	addr_fqdn_local_var->ip_addr = ip_addr;
	addr_fqdn_local_var->fqdn = fqdn;

	return addr_fqdn_local_var;
}

void addr_fqdn_free(addr_fqdn_t *addr_fqdn) {
	lnode_t *node = NULL;

	if(NULL == addr_fqdn) {
		return;
	}
	if(addr_fqdn->ip_addr) {
		ip_addr_free(addr_fqdn->ip_addr);
		addr_fqdn->ip_addr = NULL;
	}
	if(addr_fqdn->fqdn) {
		free(addr_fqdn->fqdn);
		addr_fqdn->fqdn = NULL;
	}
	free(addr_fqdn);
}

cJSON *addr_fqdn_convertToJSON(addr_fqdn_t *addr_fqdn) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(addr_fqdn == NULL) {
		printf("addr_fqdn_convertToJSON() failed [AddrFqdn]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(addr_fqdn->ip_addr) {
		cJSON *ip_addr_local_JSON = ip_addr_convertToJSON(
			addr_fqdn->ip_addr);
		if(ip_addr_local_JSON == NULL) {
			printf("addr_fqdn_convertToJSON() failed [ip_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ipAddr", ip_addr_local_JSON);
		if(item->child == NULL) {
			printf("addr_fqdn_convertToJSON() failed [ip_addr]");
			goto end;
		}
	}

	if(addr_fqdn->fqdn) {
		if(cJSON_AddStringToObject(item, "fqdn",
		                           addr_fqdn->fqdn) == NULL)
		{
			printf("addr_fqdn_convertToJSON() failed [fqdn]");
			goto end;
		}
	}

end:
	return item;
}

addr_fqdn_t *addr_fqdn_parseFromJSON(cJSON *addr_fqdnJSON) {
	addr_fqdn_t *addr_fqdn_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ip_addr = NULL;
	ip_addr_t *ip_addr_local_nonprim = NULL;
	cJSON *fqdn = NULL;
	ip_addr = cJSON_GetObjectItemCaseSensitive(addr_fqdnJSON, "ipAddr");
	if(ip_addr) {
		ip_addr_local_nonprim = ip_addr_parseFromJSON(ip_addr);
		if(!ip_addr_local_nonprim) {
			printf("ip_addr_parseFromJSON failed [ip_addr]");
			goto end;
		}
	}

	fqdn = cJSON_GetObjectItemCaseSensitive(addr_fqdnJSON, "fqdn");
	if(fqdn) {
		if(!cJSON_IsString(fqdn) &&
		   !cJSON_IsNull(fqdn))
		{
			printf("addr_fqdn_parseFromJSON() failed [fqdn]");
			goto end;
		}
	}

	addr_fqdn_local_var = addr_fqdn_create(
		ip_addr ? ip_addr_local_nonprim : NULL,
		fqdn &&
		!cJSON_IsNull(fqdn) ? strdup(fqdn->valuestring) : NULL
		);

	return addr_fqdn_local_var;
end:
	if(ip_addr_local_nonprim) {
		ip_addr_free(ip_addr_local_nonprim);
		ip_addr_local_nonprim = NULL;
	}
	return NULL;
}

addr_fqdn_t *addr_fqdn_copy(addr_fqdn_t *dst, addr_fqdn_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = addr_fqdn_convertToJSON(src);
	if(!item) {
		printf("addr_fqdn_convertToJSON() failed");
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

	addr_fqdn_free(dst);
	dst = addr_fqdn_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
