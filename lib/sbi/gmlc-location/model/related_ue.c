#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "related_ue.h"

related_ue_t *related_ue_create(char *app_layer_id, char *gpsi, char *supi,
                                related_ue_type_e related_ue_type) {
	related_ue_t *related_ue_local_var = malloc(sizeof(related_ue_t));

	related_ue_local_var->app_layer_id = app_layer_id;
	related_ue_local_var->gpsi = gpsi;
	related_ue_local_var->supi = supi;
	related_ue_local_var->related_ue_type = related_ue_type;

	return related_ue_local_var;
}

void related_ue_free(related_ue_t *related_ue) {
	lnode_t *node = NULL;

	if(NULL == related_ue) {
		return;
	}
	if(related_ue->app_layer_id) {
		free(related_ue->app_layer_id);
		related_ue->app_layer_id = NULL;
	}
	if(related_ue->gpsi) {
		free(related_ue->gpsi);
		related_ue->gpsi = NULL;
	}
	if(related_ue->supi) {
		free(related_ue->supi);
		related_ue->supi = NULL;
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
	if(related_ue->app_layer_id) {
		if(cJSON_AddStringToObject(item, "appLayerId",
		                           related_ue->app_layer_id) == NULL)
		{
			printf(
				"related_ue_convertToJSON() failed [app_layer_id]");
			goto end;
		}
	}

	if(related_ue->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           related_ue->gpsi) == NULL)
		{
			printf("related_ue_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(related_ue->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           related_ue->supi) == NULL)
		{
			printf("related_ue_convertToJSON() failed [supi]");
			goto end;
		}
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
	cJSON *app_layer_id = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	cJSON *related_ue_type = NULL;
	related_ue_type_e related_ue_typeVariable = 0;
	app_layer_id = cJSON_GetObjectItemCaseSensitive(related_ueJSON,
	                                                "appLayerId");
	if(app_layer_id) {
		if(!cJSON_IsString(app_layer_id) &&
		   !cJSON_IsNull(app_layer_id))
		{
			printf(
				"related_ue_parseFromJSON() failed [app_layer_id]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(related_ueJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("related_ue_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(related_ueJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("related_ue_parseFromJSON() failed [supi]");
			goto end;
		}
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
		app_layer_id &&
		!cJSON_IsNull(app_layer_id) ? strdup(
			app_layer_id->valuestring) : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
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
