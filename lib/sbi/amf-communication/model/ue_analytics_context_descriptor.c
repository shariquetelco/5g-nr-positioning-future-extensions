#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_analytics_context_descriptor.h"

ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_create(
	char *supi, list_t *ana_types) {
	ue_analytics_context_descriptor_t *
	        ue_analytics_context_descriptor_local_var =
		malloc(sizeof(ue_analytics_context_descriptor_t));

	ue_analytics_context_descriptor_local_var->supi = supi;
	ue_analytics_context_descriptor_local_var->ana_types = ana_types;

	return ue_analytics_context_descriptor_local_var;
}

void ue_analytics_context_descriptor_free(
	ue_analytics_context_descriptor_t *ue_analytics_context_descriptor) {
	lnode_t *node = NULL;

	if(NULL == ue_analytics_context_descriptor) {
		return;
	}
	if(ue_analytics_context_descriptor->supi) {
		free(ue_analytics_context_descriptor->supi);
		ue_analytics_context_descriptor->supi = NULL;
	}
	if(ue_analytics_context_descriptor->ana_types) {
		list_for_each(ue_analytics_context_descriptor->ana_types,
		              node) {
			nwdaf_event_free(node->data);
		}
		list_free(ue_analytics_context_descriptor->ana_types);
		ue_analytics_context_descriptor->ana_types = NULL;
	}
	free(ue_analytics_context_descriptor);
}

cJSON *ue_analytics_context_descriptor_convertToJSON(
	ue_analytics_context_descriptor_t *ue_analytics_context_descriptor) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_analytics_context_descriptor == NULL) {
		printf(
			"ue_analytics_context_descriptor_convertToJSON() failed [UeAnalyticsContextDescriptor]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ue_analytics_context_descriptor->supi) {
		printf(
			"ue_analytics_context_descriptor_convertToJSON() failed [supi]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "supi",
	                           ue_analytics_context_descriptor->supi) ==
	   NULL)
	{
		printf(
			"ue_analytics_context_descriptor_convertToJSON() failed [supi]");
		goto end;
	}

	if(!ue_analytics_context_descriptor->ana_types) {
		printf(
			"ue_analytics_context_descriptor_convertToJSON() failed [ana_types]");
		return NULL;
	}
	cJSON *ana_typesList = cJSON_AddArrayToObject(item, "anaTypes");
	if(ana_typesList == NULL) {
		printf(
			"ue_analytics_context_descriptor_convertToJSON() failed [ana_types]");
		goto end;
	}
	list_for_each(ue_analytics_context_descriptor->ana_types, node) {
		cJSON *itemLocal = nwdaf_event_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"ue_analytics_context_descriptor_convertToJSON() failed [ana_types]");
			goto end;
		}
		cJSON_AddItemToArray(ana_typesList, itemLocal);
	}

end:
	return item;
}

ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_parseFromJSON(
	cJSON *ue_analytics_context_descriptorJSON) {
	ue_analytics_context_descriptor_t *
	        ue_analytics_context_descriptor_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *supi = NULL;
	cJSON *ana_types = NULL;
	list_t *ana_typesList = NULL;
	supi = cJSON_GetObjectItemCaseSensitive(
		ue_analytics_context_descriptorJSON, "supi");
	if(!supi) {
		printf(
			"ue_analytics_context_descriptor_parseFromJSON() failed [supi]");
		goto end;
	}
	if(!cJSON_IsString(supi)) {
		printf(
			"ue_analytics_context_descriptor_parseFromJSON() failed [supi]");
		goto end;
	}

	ana_types = cJSON_GetObjectItemCaseSensitive(
		ue_analytics_context_descriptorJSON, "anaTypes");
	if(!ana_types) {
		printf(
			"ue_analytics_context_descriptor_parseFromJSON() failed [ana_types]");
		goto end;
	}
	cJSON *ana_types_local = NULL;
	if(!cJSON_IsArray(ana_types)) {
		printf(
			"ue_analytics_context_descriptor_parseFromJSON() failed [ana_types]");
		goto end;
	}

	ana_typesList = list_create();

	cJSON_ArrayForEach(ana_types_local, ana_types) {
		if(!cJSON_IsObject(ana_types_local)) {
			printf(
				"ue_analytics_context_descriptor_parseFromJSON() failed [ana_types]");
			goto end;
		}
		nwdaf_event_t *ana_typesItem = nwdaf_event_parseFromJSON(
			ana_types_local);
		if(!ana_typesItem) {
			printf("No ana_typesItem");
			goto end;
		}
		list_add(ana_typesList, ana_typesItem);
	}

	ue_analytics_context_descriptor_local_var =
		ue_analytics_context_descriptor_create(
			strdup(supi->valuestring),
			ana_typesList
			);

	return ue_analytics_context_descriptor_local_var;
end:
	if(ana_typesList) {
		list_for_each(ana_typesList, node) {
			nwdaf_event_free(node->data);
		}
		list_free(ana_typesList);
		ana_typesList = NULL;
	}
	return NULL;
}

ue_analytics_context_descriptor_t *ue_analytics_context_descriptor_copy(
	ue_analytics_context_descriptor_t	*dst,
	ue_analytics_context_descriptor_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_analytics_context_descriptor_convertToJSON(src);
	if(!item) {
		printf("ue_analytics_context_descriptor_convertToJSON() failed");
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

	ue_analytics_context_descriptor_free(dst);
	dst = ue_analytics_context_descriptor_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
