#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ip_eth_flow_description.h"

ip_eth_flow_description_t *ip_eth_flow_description_create(
	char *ip_traffic_filter, eth_flow_description_t *eth_traffic_filter) {
	ip_eth_flow_description_t *ip_eth_flow_description_local_var = malloc(
		sizeof(ip_eth_flow_description_t));

	ip_eth_flow_description_local_var->ip_traffic_filter =
		ip_traffic_filter;
	ip_eth_flow_description_local_var->eth_traffic_filter =
		eth_traffic_filter;

	return ip_eth_flow_description_local_var;
}

void ip_eth_flow_description_free(
	ip_eth_flow_description_t *ip_eth_flow_description) {
	lnode_t *node = NULL;

	if(NULL == ip_eth_flow_description) {
		return;
	}
	if(ip_eth_flow_description->ip_traffic_filter) {
		free(ip_eth_flow_description->ip_traffic_filter);
		ip_eth_flow_description->ip_traffic_filter = NULL;
	}
	if(ip_eth_flow_description->eth_traffic_filter) {
		eth_flow_description_free(
			ip_eth_flow_description->eth_traffic_filter);
		ip_eth_flow_description->eth_traffic_filter = NULL;
	}
	free(ip_eth_flow_description);
}

cJSON *ip_eth_flow_description_convertToJSON(
	ip_eth_flow_description_t *ip_eth_flow_description) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ip_eth_flow_description == NULL) {
		printf(
			"ip_eth_flow_description_convertToJSON() failed [IpEthFlowDescription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ip_eth_flow_description->ip_traffic_filter) {
		if(cJSON_AddStringToObject(item, "ipTrafficFilter",
		                           ip_eth_flow_description->
		                           ip_traffic_filter) == NULL)
		{
			printf(
				"ip_eth_flow_description_convertToJSON() failed [ip_traffic_filter]");
			goto end;
		}
	}

	if(ip_eth_flow_description->eth_traffic_filter) {
		cJSON *eth_traffic_filter_local_JSON =
			eth_flow_description_convertToJSON(
				ip_eth_flow_description->eth_traffic_filter);
		if(eth_traffic_filter_local_JSON == NULL) {
			printf(
				"ip_eth_flow_description_convertToJSON() failed [eth_traffic_filter]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ethTrafficFilter",
		                      eth_traffic_filter_local_JSON);
		if(item->child == NULL) {
			printf(
				"ip_eth_flow_description_convertToJSON() failed [eth_traffic_filter]");
			goto end;
		}
	}

end:
	return item;
}

ip_eth_flow_description_t *ip_eth_flow_description_parseFromJSON(
	cJSON *ip_eth_flow_descriptionJSON) {
	ip_eth_flow_description_t *ip_eth_flow_description_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ip_traffic_filter = NULL;
	cJSON *eth_traffic_filter = NULL;
	eth_flow_description_t *eth_traffic_filter_local_nonprim = NULL;
	ip_traffic_filter = cJSON_GetObjectItemCaseSensitive(
		ip_eth_flow_descriptionJSON, "ipTrafficFilter");
	if(ip_traffic_filter) {
		if(!cJSON_IsString(ip_traffic_filter) &&
		   !cJSON_IsNull(ip_traffic_filter))
		{
			printf(
				"ip_eth_flow_description_parseFromJSON() failed [ip_traffic_filter]");
			goto end;
		}
	}

	eth_traffic_filter = cJSON_GetObjectItemCaseSensitive(
		ip_eth_flow_descriptionJSON, "ethTrafficFilter");
	if(eth_traffic_filter) {
		eth_traffic_filter_local_nonprim =
			eth_flow_description_parseFromJSON(eth_traffic_filter);
		if(!eth_traffic_filter_local_nonprim) {
			printf(
				"eth_flow_description_parseFromJSON failed [eth_traffic_filter]");
			goto end;
		}
	}

	ip_eth_flow_description_local_var = ip_eth_flow_description_create(
		ip_traffic_filter &&
		!cJSON_IsNull(ip_traffic_filter) ? strdup(ip_traffic_filter->
		                                          valuestring) : NULL,
		eth_traffic_filter ? eth_traffic_filter_local_nonprim : NULL
		);

	return ip_eth_flow_description_local_var;
end:
	if(eth_traffic_filter_local_nonprim) {
		eth_flow_description_free(eth_traffic_filter_local_nonprim);
		eth_traffic_filter_local_nonprim = NULL;
	}
	return NULL;
}

ip_eth_flow_description_t *ip_eth_flow_description_copy(
	ip_eth_flow_description_t *dst, ip_eth_flow_description_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ip_eth_flow_description_convertToJSON(src);
	if(!item) {
		printf("ip_eth_flow_description_convertToJSON() failed");
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

	ip_eth_flow_description_free(dst);
	dst = ip_eth_flow_description_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
