#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ddd_traffic_descriptor.h"

ddd_traffic_descriptor_t *ddd_traffic_descriptor_create(
	char		*ipv4_addr,
	ipv6_addr_t	*ipv6_addr,
	bool		is_port_number,
	int		port_number,
	char		*mac_addr)
{
	ddd_traffic_descriptor_t *ddd_traffic_descriptor_local_var = malloc(
		sizeof(ddd_traffic_descriptor_t));

	ddd_traffic_descriptor_local_var->ipv4_addr = ipv4_addr;
	ddd_traffic_descriptor_local_var->ipv6_addr = ipv6_addr;
	ddd_traffic_descriptor_local_var->is_port_number = is_port_number;
	ddd_traffic_descriptor_local_var->port_number = port_number;
	ddd_traffic_descriptor_local_var->mac_addr = mac_addr;

	return ddd_traffic_descriptor_local_var;
}

void ddd_traffic_descriptor_free(
	ddd_traffic_descriptor_t *ddd_traffic_descriptor) {
	lnode_t *node = NULL;

	if(NULL == ddd_traffic_descriptor) {
		return;
	}
	if(ddd_traffic_descriptor->ipv4_addr) {
		free(ddd_traffic_descriptor->ipv4_addr);
		ddd_traffic_descriptor->ipv4_addr = NULL;
	}
	if(ddd_traffic_descriptor->ipv6_addr) {
		ipv6_addr_free(ddd_traffic_descriptor->ipv6_addr);
		ddd_traffic_descriptor->ipv6_addr = NULL;
	}
	if(ddd_traffic_descriptor->mac_addr) {
		free(ddd_traffic_descriptor->mac_addr);
		ddd_traffic_descriptor->mac_addr = NULL;
	}
	free(ddd_traffic_descriptor);
}

cJSON *ddd_traffic_descriptor_convertToJSON(
	ddd_traffic_descriptor_t *ddd_traffic_descriptor) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ddd_traffic_descriptor == NULL) {
		printf(
			"ddd_traffic_descriptor_convertToJSON() failed [DddTrafficDescriptor]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ddd_traffic_descriptor->ipv4_addr) {
		if(cJSON_AddStringToObject(item, "ipv4Addr",
		                           ddd_traffic_descriptor->ipv4_addr) ==
		   NULL)
		{
			printf(
				"ddd_traffic_descriptor_convertToJSON() failed [ipv4_addr]");
			goto end;
		}
	}

	if(ddd_traffic_descriptor->ipv6_addr) {
		cJSON *ipv6_addr_local_JSON = ipv6_addr_convertToJSON(
			ddd_traffic_descriptor->ipv6_addr);
		if(ipv6_addr_local_JSON == NULL) {
			printf(
				"ddd_traffic_descriptor_convertToJSON() failed [ipv6_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ipv6Addr", ipv6_addr_local_JSON);
		if(item->child == NULL) {
			printf(
				"ddd_traffic_descriptor_convertToJSON() failed [ipv6_addr]");
			goto end;
		}
	}

	if(ddd_traffic_descriptor->is_port_number) {
		if(cJSON_AddNumberToObject(item, "portNumber",
		                           ddd_traffic_descriptor->port_number)
		   == NULL)
		{
			printf(
				"ddd_traffic_descriptor_convertToJSON() failed [port_number]");
			goto end;
		}
	}

	if(ddd_traffic_descriptor->mac_addr) {
		if(cJSON_AddStringToObject(item, "macAddr",
		                           ddd_traffic_descriptor->mac_addr) ==
		   NULL)
		{
			printf(
				"ddd_traffic_descriptor_convertToJSON() failed [mac_addr]");
			goto end;
		}
	}

end:
	return item;
}

ddd_traffic_descriptor_t *ddd_traffic_descriptor_parseFromJSON(
	cJSON *ddd_traffic_descriptorJSON) {
	ddd_traffic_descriptor_t *ddd_traffic_descriptor_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ipv4_addr = NULL;
	cJSON *ipv6_addr = NULL;
	ipv6_addr_t *ipv6_addr_local_nonprim = NULL;
	cJSON *port_number = NULL;
	cJSON *mac_addr = NULL;
	ipv4_addr = cJSON_GetObjectItemCaseSensitive(ddd_traffic_descriptorJSON,
	                                             "ipv4Addr");
	if(ipv4_addr) {
		if(!cJSON_IsString(ipv4_addr) &&
		   !cJSON_IsNull(ipv4_addr))
		{
			printf(
				"ddd_traffic_descriptor_parseFromJSON() failed [ipv4_addr]");
			goto end;
		}
	}

	ipv6_addr = cJSON_GetObjectItemCaseSensitive(ddd_traffic_descriptorJSON,
	                                             "ipv6Addr");
	if(ipv6_addr) {
		ipv6_addr_local_nonprim = ipv6_addr_parseFromJSON(ipv6_addr);
		if(!ipv6_addr_local_nonprim) {
			printf("ipv6_addr_parseFromJSON failed [ipv6_addr]");
			goto end;
		}
	}

	port_number = cJSON_GetObjectItemCaseSensitive(
		ddd_traffic_descriptorJSON, "portNumber");
	if(port_number) {
		if(!cJSON_IsNumber(port_number)) {
			printf(
				"ddd_traffic_descriptor_parseFromJSON() failed [port_number]");
			goto end;
		}
	}

	mac_addr = cJSON_GetObjectItemCaseSensitive(ddd_traffic_descriptorJSON,
	                                            "macAddr");
	if(mac_addr) {
		if(!cJSON_IsString(mac_addr) &&
		   !cJSON_IsNull(mac_addr))
		{
			printf(
				"ddd_traffic_descriptor_parseFromJSON() failed [mac_addr]");
			goto end;
		}
	}

	ddd_traffic_descriptor_local_var = ddd_traffic_descriptor_create(
		ipv4_addr &&
		!cJSON_IsNull(ipv4_addr) ? strdup(
			ipv4_addr->valuestring) : NULL,
		ipv6_addr ? ipv6_addr_local_nonprim : NULL,
		port_number ? true : false,
		port_number ? port_number->valuedouble : 0,
		mac_addr &&
		!cJSON_IsNull(mac_addr) ? strdup(mac_addr->valuestring) : NULL
		);

	return ddd_traffic_descriptor_local_var;
end:
	if(ipv6_addr_local_nonprim) {
		ipv6_addr_free(ipv6_addr_local_nonprim);
		ipv6_addr_local_nonprim = NULL;
	}
	return NULL;
}

ddd_traffic_descriptor_t *ddd_traffic_descriptor_copy(
	ddd_traffic_descriptor_t *dst, ddd_traffic_descriptor_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ddd_traffic_descriptor_convertToJSON(src);
	if(!item) {
		printf("ddd_traffic_descriptor_convertToJSON() failed");
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

	ddd_traffic_descriptor_free(dst);
	dst = ddd_traffic_descriptor_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
