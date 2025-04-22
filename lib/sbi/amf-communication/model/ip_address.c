#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ip_address.h"

ip_address_t *ip_address_create(char *ipv4_addr, ipv6_addr_t *ipv6_addr,
                                ipv6_prefix_t *ipv6_prefix) {
	ip_address_t *ip_address_local_var = malloc(sizeof(ip_address_t));

	ip_address_local_var->ipv4_addr = ipv4_addr;
	ip_address_local_var->ipv6_addr = ipv6_addr;
	ip_address_local_var->ipv6_prefix = ipv6_prefix;

	return ip_address_local_var;
}

void ip_address_free(ip_address_t *ip_address) {
	lnode_t *node = NULL;

	if(NULL == ip_address) {
		return;
	}
	if(ip_address->ipv4_addr) {
		free(ip_address->ipv4_addr);
		ip_address->ipv4_addr = NULL;
	}
	if(ip_address->ipv6_addr) {
		ipv6_addr_free(ip_address->ipv6_addr);
		ip_address->ipv6_addr = NULL;
	}
	if(ip_address->ipv6_prefix) {
		ipv6_prefix_free(ip_address->ipv6_prefix);
		ip_address->ipv6_prefix = NULL;
	}
	free(ip_address);
}

cJSON *ip_address_convertToJSON(ip_address_t *ip_address) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ip_address == NULL) {
		printf("ip_address_convertToJSON() failed [IpAddress]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ip_address->ipv4_addr) {
		if(cJSON_AddStringToObject(item, "ipv4Addr",
		                           ip_address->ipv4_addr) == NULL)
		{
			printf("ip_address_convertToJSON() failed [ipv4_addr]");
			goto end;
		}
	}

	if(ip_address->ipv6_addr) {
		cJSON *ipv6_addr_local_JSON = ipv6_addr_convertToJSON(
			ip_address->ipv6_addr);
		if(ipv6_addr_local_JSON == NULL) {
			printf("ip_address_convertToJSON() failed [ipv6_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ipv6Addr", ipv6_addr_local_JSON);
		if(item->child == NULL) {
			printf("ip_address_convertToJSON() failed [ipv6_addr]");
			goto end;
		}
	}

	if(ip_address->ipv6_prefix) {
		cJSON *ipv6_prefix_local_JSON = ipv6_prefix_convertToJSON(
			ip_address->ipv6_prefix);
		if(ipv6_prefix_local_JSON == NULL) {
			printf("ip_address_convertToJSON() failed [ipv6_prefix]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ipv6Prefix",
		                      ipv6_prefix_local_JSON);
		if(item->child == NULL) {
			printf("ip_address_convertToJSON() failed [ipv6_prefix]");
			goto end;
		}
	}

end:
	return item;
}

ip_address_t *ip_address_parseFromJSON(cJSON *ip_addressJSON) {
	ip_address_t *ip_address_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ipv4_addr = NULL;
	cJSON *ipv6_addr = NULL;
	ipv6_addr_t *ipv6_addr_local_nonprim = NULL;
	cJSON *ipv6_prefix = NULL;
	ipv6_prefix_t *ipv6_prefix_local_nonprim = NULL;
	ipv4_addr =
		cJSON_GetObjectItemCaseSensitive(ip_addressJSON, "ipv4Addr");
	if(ipv4_addr) {
		if(!cJSON_IsString(ipv4_addr) &&
		   !cJSON_IsNull(ipv4_addr))
		{
			printf("ip_address_parseFromJSON() failed [ipv4_addr]");
			goto end;
		}
	}

	ipv6_addr =
		cJSON_GetObjectItemCaseSensitive(ip_addressJSON, "ipv6Addr");
	if(ipv6_addr) {
		ipv6_addr_local_nonprim = ipv6_addr_parseFromJSON(ipv6_addr);
		if(!ipv6_addr_local_nonprim) {
			printf("ipv6_addr_parseFromJSON failed [ipv6_addr]");
			goto end;
		}
	}

	ipv6_prefix = cJSON_GetObjectItemCaseSensitive(ip_addressJSON,
	                                               "ipv6Prefix");
	if(ipv6_prefix) {
		ipv6_prefix_local_nonprim = ipv6_prefix_parseFromJSON(
			ipv6_prefix);
		if(!ipv6_prefix_local_nonprim) {
			printf("ipv6_prefix_parseFromJSON failed [ipv6_prefix]");
			goto end;
		}
	}

	ip_address_local_var = ip_address_create(
		ipv4_addr &&
		!cJSON_IsNull(ipv4_addr) ? strdup(
			ipv4_addr->valuestring) : NULL,
		ipv6_addr ? ipv6_addr_local_nonprim : NULL,
		ipv6_prefix ? ipv6_prefix_local_nonprim : NULL
		);

	return ip_address_local_var;
end:
	if(ipv6_addr_local_nonprim) {
		ipv6_addr_free(ipv6_addr_local_nonprim);
		ipv6_addr_local_nonprim = NULL;
	}
	if(ipv6_prefix_local_nonprim) {
		ipv6_prefix_free(ipv6_prefix_local_nonprim);
		ipv6_prefix_local_nonprim = NULL;
	}
	return NULL;
}

ip_address_t *ip_address_copy(ip_address_t *dst, ip_address_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ip_address_convertToJSON(src);
	if(!item) {
		printf("ip_address_convertToJSON() failed");
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

	ip_address_free(dst);
	dst = ip_address_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
