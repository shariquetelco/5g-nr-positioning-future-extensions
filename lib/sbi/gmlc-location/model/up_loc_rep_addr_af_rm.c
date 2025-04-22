#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_loc_rep_addr_af_rm.h"

up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_create(list_t	*ipv4_addrs,
                                                      list_t	*ipv6_addrs,
                                                      char	*fqdn) {
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_local_var = malloc(
		sizeof(up_loc_rep_addr_af_rm_t));

	up_loc_rep_addr_af_rm_local_var->ipv4_addrs = ipv4_addrs;
	up_loc_rep_addr_af_rm_local_var->ipv6_addrs = ipv6_addrs;
	up_loc_rep_addr_af_rm_local_var->fqdn = fqdn;

	return up_loc_rep_addr_af_rm_local_var;
}

void up_loc_rep_addr_af_rm_free(up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm)
{
	lnode_t *node = NULL;

	if(NULL == up_loc_rep_addr_af_rm) {
		return;
	}
	if(up_loc_rep_addr_af_rm->ipv4_addrs) {
		list_for_each(up_loc_rep_addr_af_rm->ipv4_addrs, node) {
			free(node->data);
		}
		list_free(up_loc_rep_addr_af_rm->ipv4_addrs);
		up_loc_rep_addr_af_rm->ipv4_addrs = NULL;
	}
	if(up_loc_rep_addr_af_rm->ipv6_addrs) {
		list_for_each(up_loc_rep_addr_af_rm->ipv6_addrs, node) {
			ipv6_addr_free(node->data);
		}
		list_free(up_loc_rep_addr_af_rm->ipv6_addrs);
		up_loc_rep_addr_af_rm->ipv6_addrs = NULL;
	}
	if(up_loc_rep_addr_af_rm->fqdn) {
		free(up_loc_rep_addr_af_rm->fqdn);
		up_loc_rep_addr_af_rm->fqdn = NULL;
	}
	free(up_loc_rep_addr_af_rm);
}

cJSON *up_loc_rep_addr_af_rm_convertToJSON(
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(up_loc_rep_addr_af_rm == NULL) {
		printf(
			"up_loc_rep_addr_af_rm_convertToJSON() failed [UpLocRepAddrAfRm]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(up_loc_rep_addr_af_rm->ipv4_addrs) {
		cJSON *ipv4_addrsList =
			cJSON_AddArrayToObject(item, "ipv4Addrs");
		if(ipv4_addrsList == NULL) {
			printf(
				"up_loc_rep_addr_af_rm_convertToJSON() failed [ipv4_addrs]");
			goto end;
		}
		list_for_each(up_loc_rep_addr_af_rm->ipv4_addrs, node) {
			if(cJSON_AddStringToObject(ipv4_addrsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"up_loc_rep_addr_af_rm_convertToJSON() failed [ipv4_addrs]");
				goto end;
			}
		}
	}

	if(up_loc_rep_addr_af_rm->ipv6_addrs) {
		cJSON *ipv6_addrsList =
			cJSON_AddArrayToObject(item, "ipv6Addrs");
		if(ipv6_addrsList == NULL) {
			printf(
				"up_loc_rep_addr_af_rm_convertToJSON() failed [ipv6_addrs]");
			goto end;
		}
		list_for_each(up_loc_rep_addr_af_rm->ipv6_addrs, node) {
			cJSON *itemLocal = ipv6_addr_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"up_loc_rep_addr_af_rm_convertToJSON() failed [ipv6_addrs]");
				goto end;
			}
			cJSON_AddItemToArray(ipv6_addrsList, itemLocal);
		}
	}

	if(up_loc_rep_addr_af_rm->fqdn) {
		if(cJSON_AddStringToObject(item, "fqdn",
		                           up_loc_rep_addr_af_rm->fqdn) == NULL)
		{
			printf(
				"up_loc_rep_addr_af_rm_convertToJSON() failed [fqdn]");
			goto end;
		}
	}

end:
	return item;
}

up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_parseFromJSON(
	cJSON *up_loc_rep_addr_af_rmJSON) {
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ipv4_addrs = NULL;
	list_t *ipv4_addrsList = NULL;
	cJSON *ipv6_addrs = NULL;
	list_t *ipv6_addrsList = NULL;
	cJSON *fqdn = NULL;
	ipv4_addrs = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_af_rmJSON,
	                                              "ipv4Addrs");
	if(ipv4_addrs) {
		cJSON *ipv4_addrs_local = NULL;
		if(!cJSON_IsArray(ipv4_addrs)) {
			printf(
				"up_loc_rep_addr_af_rm_parseFromJSON() failed [ipv4_addrs]");
			goto end;
		}

		ipv4_addrsList = list_create();

		cJSON_ArrayForEach(ipv4_addrs_local, ipv4_addrs) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(ipv4_addrs_local)) {
				printf(
					"up_loc_rep_addr_af_rm_parseFromJSON() failed [ipv4_addrs]");
				goto end;
			}
			list_add(ipv4_addrsList,
			         strdup(ipv4_addrs_local->valuestring));
		}
	}

	ipv6_addrs = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_af_rmJSON,
	                                              "ipv6Addrs");
	if(ipv6_addrs) {
		cJSON *ipv6_addrs_local = NULL;
		if(!cJSON_IsArray(ipv6_addrs)) {
			printf(
				"up_loc_rep_addr_af_rm_parseFromJSON() failed [ipv6_addrs]");
			goto end;
		}

		ipv6_addrsList = list_create();

		cJSON_ArrayForEach(ipv6_addrs_local, ipv6_addrs) {
			if(!cJSON_IsObject(ipv6_addrs_local)) {
				printf(
					"up_loc_rep_addr_af_rm_parseFromJSON() failed [ipv6_addrs]");
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

	fqdn = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_af_rmJSON,
	                                        "fqdn");
	if(fqdn) {
		if(!cJSON_IsString(fqdn) &&
		   !cJSON_IsNull(fqdn))
		{
			printf(
				"up_loc_rep_addr_af_rm_parseFromJSON() failed [fqdn]");
			goto end;
		}
	}

	up_loc_rep_addr_af_rm_local_var = up_loc_rep_addr_af_rm_create(
		ipv4_addrs ? ipv4_addrsList : NULL,
		ipv6_addrs ? ipv6_addrsList : NULL,
		fqdn &&
		!cJSON_IsNull(fqdn) ? strdup(fqdn->valuestring) : NULL
		);

	return up_loc_rep_addr_af_rm_local_var;
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

up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_rm_copy(
	up_loc_rep_addr_af_rm_t *dst, up_loc_rep_addr_af_rm_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = up_loc_rep_addr_af_rm_convertToJSON(src);
	if(!item) {
		printf("up_loc_rep_addr_af_rm_convertToJSON() failed");
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

	up_loc_rep_addr_af_rm_free(dst);
	dst = up_loc_rep_addr_af_rm_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
