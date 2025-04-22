#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "related_ue.h"

related_ue_t *related_ue_create(char			*applicationlayer_id,
                                related_ue_type_e	related_ue_type) {
	related_ue_t *related_ue_local_var = malloc(sizeof(related_ue_t));

	related_ue_local_var->applicationlayer_id = applicationlayer_id;
	related_ue_local_var->related_ue_type = related_ue_type;

	return related_ue_local_var;
}

void related_ue_free(related_ue_t *related_ue) {
	lnode_t *node = NULL;

	if(NULL == related_ue) {
		return;
	}
	if(related_ue->applicationlayer_id) {
		free(related_ue->applicationlayer_id);
		related_ue->applicationlayer_id = NULL;
	}
	free(related_ue);
}

cJSON *related_ue_convertToJSON(related_ue_t *related_ue) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(related_ue == NULL) {
		printf("related_ue_convertToJSON() failed [RelatedUE]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!related_ue->applicationlayer_id) {
		printf("related_ue_convertToJSON() failed [applicationlayer_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "applicationlayerId",
	                           related_ue->applicationlayer_id) == NULL)
	{
		printf("related_ue_convertToJSON() failed [applicationlayer_id]");
		goto end;
	}

	if(related_ue->related_ue_type == related_ue_type_NULL) {
		printf("related_ue_convertToJSON() failed [related_ue_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "relatedUEType",
	                           related_ue_type_ToString(related_ue->
	                                                    related_ue_type)) ==
	   NULL)
	{
		printf("related_ue_convertToJSON() failed [related_ue_type]");
		goto end;
	}

end:
	return item;
}

related_ue_t *related_ue_parseFromJSON(cJSON *related_ueJSON) {
	related_ue_t *related_ue_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *applicationlayer_id = NULL;
	cJSON *related_ue_type = NULL;
	related_ue_type_e related_ue_typeVariable = 0;
	applicationlayer_id = cJSON_GetObjectItemCaseSensitive(related_ueJSON,
	                                                       "applicationlayerId");
	if(!applicationlayer_id) {
		printf("related_ue_parseFromJSON() failed [applicationlayer_id]");
		goto end;
	}
	if(!cJSON_IsString(applicationlayer_id)) {
		printf("related_ue_parseFromJSON() failed [applicationlayer_id]");
		goto end;
	}

	related_ue_type = cJSON_GetObjectItemCaseSensitive(related_ueJSON,
	                                                   "relatedUEType");
	if(!related_ue_type) {
		printf("related_ue_parseFromJSON() failed [related_ue_type]");
		goto end;
	}
	if(!cJSON_IsString(related_ue_type)) {
		printf("related_ue_parseFromJSON() failed [related_ue_type]");
		goto end;
	}
	related_ue_typeVariable = related_ue_type_FromString(
		related_ue_type->valuestring);

	related_ue_local_var = related_ue_create(
		strdup(applicationlayer_id->valuestring),
		related_ue_typeVariable
		);

	return related_ue_local_var;
end:
	return NULL;
}

related_ue_t *related_ue_copy(related_ue_t *dst, related_ue_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = related_ue_convertToJSON(src);
	if(!item) {
		printf("related_ue_convertToJSON() failed");
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

	related_ue_free(dst);
	dst = related_ue_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
