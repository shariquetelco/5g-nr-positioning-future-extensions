#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "address_list.h"

address_list_t *address_list_create(list_t *ipv4_addrs, list_t *ipv6_addrs) {
	address_list_t *address_list_local_var = malloc(sizeof(address_list_t));

	address_list_local_var->ipv4_addrs = ipv4_addrs;
	address_list_local_var->ipv6_addrs = ipv6_addrs;

	return address_list_local_var;
}

void address_list_free(address_list_t *address_list) {
	lnode_t *node = NULL;

	if(NULL == address_list) {
		return;
	}
	if(address_list->ipv4_addrs) {
		list_for_each(address_list->ipv4_addrs, node) {
			free(node->data);
		}
		list_free(address_list->ipv4_addrs);
		address_list->ipv4_addrs = NULL;
	}
	if(address_list->ipv6_addrs) {
		list_for_each(address_list->ipv6_addrs, node) {
			ipv6_addr_free(node->data);
		}
		list_free(address_list->ipv6_addrs);
		address_list->ipv6_addrs = NULL;
	}
	free(address_list);
}

cJSON *address_list_convertToJSON(address_list_t *address_list) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(address_list == NULL) {
		printf("address_list_convertToJSON() failed [AddressList]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(address_list->ipv4_addrs) {
		cJSON *ipv4_addrsList =
			cJSON_AddArrayToObject(item, "ipv4Addrs");
		if(ipv4_addrsList == NULL) {
			printf(
				"address_list_convertToJSON() failed [ipv4_addrs]");
			goto end;
		}
		list_for_each(address_list->ipv4_addrs, node) {
			if(cJSON_AddStringToObject(ipv4_addrsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"address_list_convertToJSON() failed [ipv4_addrs]");
				goto end;
			}
		}
	}

	if(address_list->ipv6_addrs) {
		cJSON *ipv6_addrsList =
			cJSON_AddArrayToObject(item, "ipv6Addrs");
		if(ipv6_addrsList == NULL) {
			printf(
				"address_list_convertToJSON() failed [ipv6_addrs]");
			goto end;
		}
		list_for_each(address_list->ipv6_addrs, node) {
			cJSON *itemLocal = ipv6_addr_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"address_list_convertToJSON() failed [ipv6_addrs]");
				goto end;
			}
			cJSON_AddItemToArray(ipv6_addrsList, itemLocal);
		}
	}

end:
	return item;
}

address_list_t *address_list_parseFromJSON(cJSON *address_listJSON) {
	address_list_t *address_list_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ipv4_addrs = NULL;
	list_t *ipv4_addrsList = NULL;
	cJSON *ipv6_addrs = NULL;
	list_t *ipv6_addrsList = NULL;
	ipv4_addrs = cJSON_GetObjectItemCaseSensitive(address_listJSON,
	                                              "ipv4Addrs");
	if(ipv4_addrs) {
		cJSON *ipv4_addrs_local = NULL;
		if(!cJSON_IsArray(ipv4_addrs)) {
			printf(
				"address_list_parseFromJSON() failed [ipv4_addrs]");
			goto end;
		}

		ipv4_addrsList = list_create();

		cJSON_ArrayForEach(ipv4_addrs_local, ipv4_addrs) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(ipv4_addrs_local)) {
				printf(
					"address_list_parseFromJSON() failed [ipv4_addrs]");
				goto end;
			}
			list_add(ipv4_addrsList,
			         strdup(ipv4_addrs_local->valuestring));
		}
	}

	ipv6_addrs = cJSON_GetObjectItemCaseSensitive(address_listJSON,
	                                              "ipv6Addrs");
	if(ipv6_addrs) {
		cJSON *ipv6_addrs_local = NULL;
		if(!cJSON_IsArray(ipv6_addrs)) {
			printf(
				"address_list_parseFromJSON() failed [ipv6_addrs]");
			goto end;
		}

		ipv6_addrsList = list_create();

		cJSON_ArrayForEach(ipv6_addrs_local, ipv6_addrs) {
			if(!cJSON_IsObject(ipv6_addrs_local)) {
				printf(
					"address_list_parseFromJSON() failed [ipv6_addrs]");
				goto end;
			}
			ipv6_addr_t *ipv6_addrsItem = ipv6_addr_parseFromJSON(
				ipv6_addrs_local);
			if(!ipv6_addrsItem) {
				printf("No ipv6_addrsItem");
				goto end;
			}
			list_add(ipv6_addrsList, ipv6_addrsItem);
		}
	}

	address_list_local_var = address_list_create(
		ipv4_addrs ? ipv4_addrsList : NULL,
		ipv6_addrs ? ipv6_addrsList : NULL
		);

	return address_list_local_var;
end:
	if(ipv4_addrsList) {
		list_for_each(ipv4_addrsList, node) {
			free(node->data);
		}
		list_free(ipv4_addrsList);
		ipv4_addrsList = NULL;
	}
	if(ipv6_addrsList) {
		list_for_each(ipv6_addrsList, node) {
			ipv6_addr_free(node->data);
		}
		list_free(ipv6_addrsList);
		ipv6_addrsList = NULL;
	}
	return NULL;
}

address_list_t *address_list_copy(address_list_t *dst, address_list_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = address_list_convertToJSON(src);
	if(!item) {
		printf("address_list_convertToJSON() failed");
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

	address_list_free(dst);
	dst = address_list_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
