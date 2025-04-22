#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "traffic_descriptor.h"

traffic_descriptor_t *traffic_descriptor_create(char *dnn, snssai_t *s_nssai,
                                                list_t *ddd_traffic_descriptor_list)
{
	traffic_descriptor_t *traffic_descriptor_local_var =
		malloc(sizeof(traffic_descriptor_t));

	traffic_descriptor_local_var->dnn = dnn;
	traffic_descriptor_local_var->s_nssai = s_nssai;
	traffic_descriptor_local_var->ddd_traffic_descriptor_list =
		ddd_traffic_descriptor_list;

	return traffic_descriptor_local_var;
}

void traffic_descriptor_free(traffic_descriptor_t *traffic_descriptor) {
	lnode_t *node = NULL;

	if(NULL == traffic_descriptor) {
		return;
	}
	if(traffic_descriptor->dnn) {
		free(traffic_descriptor->dnn);
		traffic_descriptor->dnn = NULL;
	}
	if(traffic_descriptor->s_nssai) {
		snssai_free(traffic_descriptor->s_nssai);
		traffic_descriptor->s_nssai = NULL;
	}
	if(traffic_descriptor->ddd_traffic_descriptor_list) {
		list_for_each(traffic_descriptor->ddd_traffic_descriptor_list,
		              node) {
			ddd_traffic_descriptor_free(node->data);
		}
		list_free(traffic_descriptor->ddd_traffic_descriptor_list);
		traffic_descriptor->ddd_traffic_descriptor_list = NULL;
	}
	free(traffic_descriptor);
}

cJSON *traffic_descriptor_convertToJSON(
	traffic_descriptor_t *traffic_descriptor) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(traffic_descriptor == NULL) {
		printf(
			"traffic_descriptor_convertToJSON() failed [TrafficDescriptor]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(traffic_descriptor->dnn) {
		if(cJSON_AddStringToObject(item, "dnn",
		                           traffic_descriptor->dnn) == NULL)
		{
			printf("traffic_descriptor_convertToJSON() failed [dnn]");
			goto end;
		}
	}

	if(traffic_descriptor->s_nssai) {
		cJSON *s_nssai_local_JSON = snssai_convertToJSON(
			traffic_descriptor->s_nssai);
		if(s_nssai_local_JSON == NULL) {
			printf(
				"traffic_descriptor_convertToJSON() failed [s_nssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "sNssai", s_nssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"traffic_descriptor_convertToJSON() failed [s_nssai]");
			goto end;
		}
	}

	if(traffic_descriptor->ddd_traffic_descriptor_list) {
		cJSON *ddd_traffic_descriptor_listList = cJSON_AddArrayToObject(
			item, "dddTrafficDescriptorList");
		if(ddd_traffic_descriptor_listList == NULL) {
			printf(
				"traffic_descriptor_convertToJSON() failed [ddd_traffic_descriptor_list]");
			goto end;
		}
		list_for_each(traffic_descriptor->ddd_traffic_descriptor_list,
		              node) {
			cJSON *itemLocal = ddd_traffic_descriptor_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"traffic_descriptor_convertToJSON() failed [ddd_traffic_descriptor_list]");
				goto end;
			}
			cJSON_AddItemToArray(ddd_traffic_descriptor_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

traffic_descriptor_t *traffic_descriptor_parseFromJSON(
	cJSON *traffic_descriptorJSON) {
	traffic_descriptor_t *traffic_descriptor_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *dnn = NULL;
	cJSON *s_nssai = NULL;
	snssai_t *s_nssai_local_nonprim = NULL;
	cJSON *ddd_traffic_descriptor_list = NULL;
	list_t *ddd_traffic_descriptor_listList = NULL;
	dnn = cJSON_GetObjectItemCaseSensitive(traffic_descriptorJSON, "dnn");
	if(dnn) {
		if(!cJSON_IsString(dnn) &&
		   !cJSON_IsNull(dnn))
		{
			printf("traffic_descriptor_parseFromJSON() failed [dnn]");
			goto end;
		}
	}

	s_nssai = cJSON_GetObjectItemCaseSensitive(traffic_descriptorJSON,
	                                           "sNssai");
	if(s_nssai) {
		s_nssai_local_nonprim = snssai_parseFromJSON(s_nssai);
		if(!s_nssai_local_nonprim) {
			printf("snssai_parseFromJSON failed [s_nssai]");
			goto end;
		}
	}

	ddd_traffic_descriptor_list = cJSON_GetObjectItemCaseSensitive(
		traffic_descriptorJSON, "dddTrafficDescriptorList");
	if(ddd_traffic_descriptor_list) {
		cJSON *ddd_traffic_descriptor_list_local = NULL;
		if(!cJSON_IsArray(ddd_traffic_descriptor_list)) {
			printf(
				"traffic_descriptor_parseFromJSON() failed [ddd_traffic_descriptor_list]");
			goto end;
		}

		ddd_traffic_descriptor_listList = list_create();

		cJSON_ArrayForEach(ddd_traffic_descriptor_list_local,
		                   ddd_traffic_descriptor_list) {
			if(!cJSON_IsObject(ddd_traffic_descriptor_list_local)) {
				printf(
					"traffic_descriptor_parseFromJSON() failed [ddd_traffic_descriptor_list]");
				goto end;
			}
			ddd_traffic_descriptor_t *
			        ddd_traffic_descriptor_listItem =
				ddd_traffic_descriptor_parseFromJSON(
					ddd_traffic_descriptor_list_local);
			if(!ddd_traffic_descriptor_listItem) {
				printf("No ddd_traffic_descriptor_listItem");
				goto end;
			}
			list_add(ddd_traffic_descriptor_listList,
			         ddd_traffic_descriptor_listItem);
		}
	}

	traffic_descriptor_local_var = traffic_descriptor_create(
		dnn &&
		!cJSON_IsNull(dnn) ? strdup(
			dnn->valuestring) : NULL,
		s_nssai ? s_nssai_local_nonprim : NULL,
		ddd_traffic_descriptor_list ? ddd_traffic_descriptor_listList : NULL
		);

	return traffic_descriptor_local_var;
end:
	if(s_nssai_local_nonprim) {
		snssai_free(s_nssai_local_nonprim);
		s_nssai_local_nonprim = NULL;
	}
	if(ddd_traffic_descriptor_listList) {
		list_for_each(ddd_traffic_descriptor_listList, node) {
			ddd_traffic_descriptor_free(node->data);
		}
		list_free(ddd_traffic_descriptor_listList);
		ddd_traffic_descriptor_listList = NULL;
	}
	return NULL;
}

traffic_descriptor_t *traffic_descriptor_copy(traffic_descriptor_t	*dst,
                                              traffic_descriptor_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = traffic_descriptor_convertToJSON(src);
	if(!item) {
		printf("traffic_descriptor_convertToJSON() failed");
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

	traffic_descriptor_free(dst);
	dst = traffic_descriptor_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
