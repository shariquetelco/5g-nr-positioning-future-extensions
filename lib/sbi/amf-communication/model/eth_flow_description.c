#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "eth_flow_description.h"

eth_flow_description_t *eth_flow_description_create(
	char			*dest_mac_addr,
	char			*eth_type,
	char			*f_desc,
	flow_direction_t	*f_dir,
	char			*source_mac_addr,
	list_t			*vlan_tags,
	char			*src_mac_addr_end,
	char			*dest_mac_addr_end)
{
	eth_flow_description_t *eth_flow_description_local_var =
		malloc(sizeof(eth_flow_description_t));

	eth_flow_description_local_var->dest_mac_addr = dest_mac_addr;
	eth_flow_description_local_var->eth_type = eth_type;
	eth_flow_description_local_var->f_desc = f_desc;
	eth_flow_description_local_var->f_dir = f_dir;
	eth_flow_description_local_var->source_mac_addr = source_mac_addr;
	eth_flow_description_local_var->vlan_tags = vlan_tags;
	eth_flow_description_local_var->src_mac_addr_end = src_mac_addr_end;
	eth_flow_description_local_var->dest_mac_addr_end = dest_mac_addr_end;

	return eth_flow_description_local_var;
}

void eth_flow_description_free(eth_flow_description_t *eth_flow_description) {
	lnode_t *node = NULL;

	if(NULL == eth_flow_description) {
		return;
	}
	if(eth_flow_description->dest_mac_addr) {
		free(eth_flow_description->dest_mac_addr);
		eth_flow_description->dest_mac_addr = NULL;
	}
	if(eth_flow_description->eth_type) {
		free(eth_flow_description->eth_type);
		eth_flow_description->eth_type = NULL;
	}
	if(eth_flow_description->f_desc) {
		free(eth_flow_description->f_desc);
		eth_flow_description->f_desc = NULL;
	}
	if(eth_flow_description->f_dir) {
		flow_direction_free(eth_flow_description->f_dir);
		eth_flow_description->f_dir = NULL;
	}
	if(eth_flow_description->source_mac_addr) {
		free(eth_flow_description->source_mac_addr);
		eth_flow_description->source_mac_addr = NULL;
	}
	if(eth_flow_description->vlan_tags) {
		list_for_each(eth_flow_description->vlan_tags, node) {
			free(node->data);
		}
		list_free(eth_flow_description->vlan_tags);
		eth_flow_description->vlan_tags = NULL;
	}
	if(eth_flow_description->src_mac_addr_end) {
		free(eth_flow_description->src_mac_addr_end);
		eth_flow_description->src_mac_addr_end = NULL;
	}
	if(eth_flow_description->dest_mac_addr_end) {
		free(eth_flow_description->dest_mac_addr_end);
		eth_flow_description->dest_mac_addr_end = NULL;
	}
	free(eth_flow_description);
}

cJSON *eth_flow_description_convertToJSON(
	eth_flow_description_t *eth_flow_description) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(eth_flow_description == NULL) {
		printf(
			"eth_flow_description_convertToJSON() failed [EthFlowDescription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(eth_flow_description->dest_mac_addr) {
		if(cJSON_AddStringToObject(item, "destMacAddr",
		                           eth_flow_description->dest_mac_addr)
		   == NULL)
		{
			printf(
				"eth_flow_description_convertToJSON() failed [dest_mac_addr]");
			goto end;
		}
	}

	if(!eth_flow_description->eth_type) {
		printf("eth_flow_description_convertToJSON() failed [eth_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ethType",
	                           eth_flow_description->eth_type) == NULL)
	{
		printf("eth_flow_description_convertToJSON() failed [eth_type]");
		goto end;
	}

	if(eth_flow_description->f_desc) {
		if(cJSON_AddStringToObject(item, "fDesc",
		                           eth_flow_description->f_desc) ==
		   NULL)
		{
			printf(
				"eth_flow_description_convertToJSON() failed [f_desc]");
			goto end;
		}
	}

	if(eth_flow_description->f_dir) {
		cJSON *f_dir_local_JSON = flow_direction_convertToJSON(
			eth_flow_description->f_dir);
		if(f_dir_local_JSON == NULL) {
			printf(
				"eth_flow_description_convertToJSON() failed [f_dir]");
			goto end;
		}
		cJSON_AddItemToObject(item, "fDir", f_dir_local_JSON);
		if(item->child == NULL) {
			printf(
				"eth_flow_description_convertToJSON() failed [f_dir]");
			goto end;
		}
	}

	if(eth_flow_description->source_mac_addr) {
		if(cJSON_AddStringToObject(item, "sourceMacAddr",
		                           eth_flow_description->source_mac_addr)
		   == NULL)
		{
			printf(
				"eth_flow_description_convertToJSON() failed [source_mac_addr]");
			goto end;
		}
	}

	if(eth_flow_description->vlan_tags) {
		cJSON *vlan_tagsList = cJSON_AddArrayToObject(item, "vlanTags");
		if(vlan_tagsList == NULL) {
			printf(
				"eth_flow_description_convertToJSON() failed [vlan_tags]");
			goto end;
		}
		list_for_each(eth_flow_description->vlan_tags, node) {
			if(cJSON_AddStringToObject(vlan_tagsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"eth_flow_description_convertToJSON() failed [vlan_tags]");
				goto end;
			}
		}
	}

	if(eth_flow_description->src_mac_addr_end) {
		if(cJSON_AddStringToObject(item, "srcMacAddrEnd",
		                           eth_flow_description->
		                           src_mac_addr_end) == NULL)
		{
			printf(
				"eth_flow_description_convertToJSON() failed [src_mac_addr_end]");
			goto end;
		}
	}

	if(eth_flow_description->dest_mac_addr_end) {
		if(cJSON_AddStringToObject(item, "destMacAddrEnd",
		                           eth_flow_description->
		                           dest_mac_addr_end) == NULL)
		{
			printf(
				"eth_flow_description_convertToJSON() failed [dest_mac_addr_end]");
			goto end;
		}
	}

end:
	return item;
}

eth_flow_description_t *eth_flow_description_parseFromJSON(
	cJSON *eth_flow_descriptionJSON) {
	eth_flow_description_t *eth_flow_description_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *dest_mac_addr = NULL;
	cJSON *eth_type = NULL;
	cJSON *f_desc = NULL;
	cJSON *f_dir = NULL;
	flow_direction_t *f_dir_local_nonprim = NULL;
	cJSON *source_mac_addr = NULL;
	cJSON *vlan_tags = NULL;
	list_t *vlan_tagsList = NULL;
	cJSON *src_mac_addr_end = NULL;
	cJSON *dest_mac_addr_end = NULL;
	dest_mac_addr = cJSON_GetObjectItemCaseSensitive(
		eth_flow_descriptionJSON, "destMacAddr");
	if(dest_mac_addr) {
		if(!cJSON_IsString(dest_mac_addr) &&
		   !cJSON_IsNull(dest_mac_addr))
		{
			printf(
				"eth_flow_description_parseFromJSON() failed [dest_mac_addr]");
			goto end;
		}
	}

	eth_type = cJSON_GetObjectItemCaseSensitive(eth_flow_descriptionJSON,
	                                            "ethType");
	if(!eth_type) {
		printf("eth_flow_description_parseFromJSON() failed [eth_type]");
		goto end;
	}
	if(!cJSON_IsString(eth_type)) {
		printf("eth_flow_description_parseFromJSON() failed [eth_type]");
		goto end;
	}

	f_desc = cJSON_GetObjectItemCaseSensitive(eth_flow_descriptionJSON,
	                                          "fDesc");
	if(f_desc) {
		if(!cJSON_IsString(f_desc) &&
		   !cJSON_IsNull(f_desc))
		{
			printf(
				"eth_flow_description_parseFromJSON() failed [f_desc]");
			goto end;
		}
	}

	f_dir = cJSON_GetObjectItemCaseSensitive(eth_flow_descriptionJSON,
	                                         "fDir");
	if(f_dir) {
		f_dir_local_nonprim = flow_direction_parseFromJSON(f_dir);
		if(!f_dir_local_nonprim) {
			printf("flow_direction_parseFromJSON failed [f_dir]");
			goto end;
		}
	}

	source_mac_addr = cJSON_GetObjectItemCaseSensitive(
		eth_flow_descriptionJSON, "sourceMacAddr");
	if(source_mac_addr) {
		if(!cJSON_IsString(source_mac_addr) &&
		   !cJSON_IsNull(source_mac_addr))
		{
			printf(
				"eth_flow_description_parseFromJSON() failed [source_mac_addr]");
			goto end;
		}
	}

	vlan_tags = cJSON_GetObjectItemCaseSensitive(eth_flow_descriptionJSON,
	                                             "vlanTags");
	if(vlan_tags) {
		cJSON *vlan_tags_local = NULL;
		if(!cJSON_IsArray(vlan_tags)) {
			printf(
				"eth_flow_description_parseFromJSON() failed [vlan_tags]");
			goto end;
		}

		vlan_tagsList = list_create();

		cJSON_ArrayForEach(vlan_tags_local, vlan_tags) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(vlan_tags_local)) {
				printf(
					"eth_flow_description_parseFromJSON() failed [vlan_tags]");
				goto end;
			}
			list_add(vlan_tagsList,
			         strdup(vlan_tags_local->valuestring));
		}
	}

	src_mac_addr_end = cJSON_GetObjectItemCaseSensitive(
		eth_flow_descriptionJSON, "srcMacAddrEnd");
	if(src_mac_addr_end) {
		if(!cJSON_IsString(src_mac_addr_end) &&
		   !cJSON_IsNull(src_mac_addr_end))
		{
			printf(
				"eth_flow_description_parseFromJSON() failed [src_mac_addr_end]");
			goto end;
		}
	}

	dest_mac_addr_end = cJSON_GetObjectItemCaseSensitive(
		eth_flow_descriptionJSON, "destMacAddrEnd");
	if(dest_mac_addr_end) {
		if(!cJSON_IsString(dest_mac_addr_end) &&
		   !cJSON_IsNull(dest_mac_addr_end))
		{
			printf(
				"eth_flow_description_parseFromJSON() failed [dest_mac_addr_end]");
			goto end;
		}
	}

	eth_flow_description_local_var = eth_flow_description_create(
		dest_mac_addr &&
		!cJSON_IsNull(dest_mac_addr) ? strdup(
			dest_mac_addr->valuestring) : NULL,
		strdup(eth_type->valuestring),
		f_desc &&
		!cJSON_IsNull(f_desc) ? strdup(f_desc->valuestring) : NULL,
		f_dir ? f_dir_local_nonprim : NULL,
		source_mac_addr &&
		!cJSON_IsNull(source_mac_addr) ? strdup(source_mac_addr->
		                                        valuestring) : NULL,
		vlan_tags ? vlan_tagsList : NULL,
		src_mac_addr_end &&
		!cJSON_IsNull(src_mac_addr_end) ? strdup(src_mac_addr_end->
		                                         valuestring) : NULL,
		dest_mac_addr_end &&
		!cJSON_IsNull(dest_mac_addr_end) ? strdup(dest_mac_addr_end->
		                                          valuestring) : NULL
		);

	return eth_flow_description_local_var;
end:
	if(f_dir_local_nonprim) {
		flow_direction_free(f_dir_local_nonprim);
		f_dir_local_nonprim = NULL;
	}
	if(vlan_tagsList) {
		list_for_each(vlan_tagsList, node) {
			free(node->data);
		}
		list_free(vlan_tagsList);
		vlan_tagsList = NULL;
	}
	return NULL;
}

eth_flow_description_t *eth_flow_description_copy(
	eth_flow_description_t	*dst,
	eth_flow_description_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = eth_flow_description_convertToJSON(src);
	if(!item) {
		printf("eth_flow_description_convertToJSON() failed");
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

	eth_flow_description_free(dst);
	dst = eth_flow_description_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
