#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "flow_info.h"

flow_info_t *flow_info_create(int flow_id, list_t *flow_descriptions,
                              char *tos_tc) {
	flow_info_t *flow_info_local_var = malloc(sizeof(flow_info_t));

	flow_info_local_var->flow_id = flow_id;
	flow_info_local_var->flow_descriptions = flow_descriptions;
	flow_info_local_var->tos_tc = tos_tc;

	return flow_info_local_var;
}

void flow_info_free(flow_info_t *flow_info) {
	lnode_t *node = NULL;

	if(NULL == flow_info) {
		return;
	}
	if(flow_info->flow_descriptions) {
		list_for_each(flow_info->flow_descriptions, node) {
			free(node->data);
		}
		list_free(flow_info->flow_descriptions);
		flow_info->flow_descriptions = NULL;
	}
	if(flow_info->tos_tc) {
		free(flow_info->tos_tc);
		flow_info->tos_tc = NULL;
	}
	free(flow_info);
}

cJSON *flow_info_convertToJSON(flow_info_t *flow_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(flow_info == NULL) {
		printf("flow_info_convertToJSON() failed [FlowInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(cJSON_AddNumberToObject(item, "flowId",
	                           flow_info->flow_id) == NULL)
	{
		printf("flow_info_convertToJSON() failed [flow_id]");
		goto end;
	}

	if(flow_info->flow_descriptions) {
		cJSON *flow_descriptionsList = cJSON_AddArrayToObject(item,
		                                                      "flowDescriptions");
		if(flow_descriptionsList == NULL) {
			printf(
				"flow_info_convertToJSON() failed [flow_descriptions]");
			goto end;
		}
		list_for_each(flow_info->flow_descriptions, node) {
			if(cJSON_AddStringToObject(flow_descriptionsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"flow_info_convertToJSON() failed [flow_descriptions]");
				goto end;
			}
		}
	}

	if(flow_info->tos_tc) {
		if(cJSON_AddStringToObject(item, "tosTC",
		                           flow_info->tos_tc) == NULL)
		{
			printf("flow_info_convertToJSON() failed [tos_tc]");
			goto end;
		}
	}

end:
	return item;
}

flow_info_t *flow_info_parseFromJSON(cJSON *flow_infoJSON) {
	flow_info_t *flow_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *flow_id = NULL;
	cJSON *flow_descriptions = NULL;
	list_t *flow_descriptionsList = NULL;
	cJSON *tos_tc = NULL;
	flow_id = cJSON_GetObjectItemCaseSensitive(flow_infoJSON, "flowId");
	if(!flow_id) {
		printf("flow_info_parseFromJSON() failed [flow_id]");
		goto end;
	}
	if(!cJSON_IsNumber(flow_id)) {
		printf("flow_info_parseFromJSON() failed [flow_id]");
		goto end;
	}

	flow_descriptions = cJSON_GetObjectItemCaseSensitive(flow_infoJSON,
	                                                     "flowDescriptions");
	if(flow_descriptions) {
		cJSON *flow_descriptions_local = NULL;
		if(!cJSON_IsArray(flow_descriptions)) {
			printf(
				"flow_info_parseFromJSON() failed [flow_descriptions]");
			goto end;
		}

		flow_descriptionsList = list_create();

		cJSON_ArrayForEach(flow_descriptions_local, flow_descriptions) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(flow_descriptions_local)) {
				printf(
					"flow_info_parseFromJSON() failed [flow_descriptions]");
				goto end;
			}
			list_add(flow_descriptionsList,
			         strdup(flow_descriptions_local->valuestring));
		}
	}

	tos_tc = cJSON_GetObjectItemCaseSensitive(flow_infoJSON, "tosTC");
	if(tos_tc) {
		if(!cJSON_IsString(tos_tc) &&
		   !cJSON_IsNull(tos_tc))
		{
			printf("flow_info_parseFromJSON() failed [tos_tc]");
			goto end;
		}
	}

	flow_info_local_var = flow_info_create(

		flow_id->valuedouble,
		flow_descriptions ? flow_descriptionsList : NULL,
		tos_tc &&
		!cJSON_IsNull(tos_tc) ? strdup(tos_tc->valuestring) : NULL
		);

	return flow_info_local_var;
end:
	if(flow_descriptionsList) {
		list_for_each(flow_descriptionsList, node) {
			free(node->data);
		}
		list_free(flow_descriptionsList);
		flow_descriptionsList = NULL;
	}
	return NULL;
}

flow_info_t *flow_info_copy(flow_info_t *dst, flow_info_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = flow_info_convertToJSON(src);
	if(!item) {
		printf("flow_info_convertToJSON() failed");
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

	flow_info_free(dst);
	dst = flow_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
