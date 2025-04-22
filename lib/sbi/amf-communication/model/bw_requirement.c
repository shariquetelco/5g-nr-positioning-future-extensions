#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bw_requirement.h"

bw_requirement_t *bw_requirement_create(char *app_id, char *mar_bw_dl,
                                        char *mar_bw_ul, char *mir_bw_dl,
                                        char *mir_bw_ul) {
	bw_requirement_t *bw_requirement_local_var =
		malloc(sizeof(bw_requirement_t));

	bw_requirement_local_var->app_id = app_id;
	bw_requirement_local_var->mar_bw_dl = mar_bw_dl;
	bw_requirement_local_var->mar_bw_ul = mar_bw_ul;
	bw_requirement_local_var->mir_bw_dl = mir_bw_dl;
	bw_requirement_local_var->mir_bw_ul = mir_bw_ul;

	return bw_requirement_local_var;
}

void bw_requirement_free(bw_requirement_t *bw_requirement) {
	lnode_t *node = NULL;

	if(NULL == bw_requirement) {
		return;
	}
	if(bw_requirement->app_id) {
		free(bw_requirement->app_id);
		bw_requirement->app_id = NULL;
	}
	if(bw_requirement->mar_bw_dl) {
		free(bw_requirement->mar_bw_dl);
		bw_requirement->mar_bw_dl = NULL;
	}
	if(bw_requirement->mar_bw_ul) {
		free(bw_requirement->mar_bw_ul);
		bw_requirement->mar_bw_ul = NULL;
	}
	if(bw_requirement->mir_bw_dl) {
		free(bw_requirement->mir_bw_dl);
		bw_requirement->mir_bw_dl = NULL;
	}
	if(bw_requirement->mir_bw_ul) {
		free(bw_requirement->mir_bw_ul);
		bw_requirement->mir_bw_ul = NULL;
	}
	free(bw_requirement);
}

cJSON *bw_requirement_convertToJSON(bw_requirement_t *bw_requirement) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(bw_requirement == NULL) {
		printf("bw_requirement_convertToJSON() failed [BwRequirement]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!bw_requirement->app_id) {
		printf("bw_requirement_convertToJSON() failed [app_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "appId",
	                           bw_requirement->app_id) == NULL)
	{
		printf("bw_requirement_convertToJSON() failed [app_id]");
		goto end;
	}

	if(bw_requirement->mar_bw_dl) {
		if(cJSON_AddStringToObject(item, "marBwDl",
		                           bw_requirement->mar_bw_dl) == NULL)
		{
			printf(
				"bw_requirement_convertToJSON() failed [mar_bw_dl]");
			goto end;
		}
	}

	if(bw_requirement->mar_bw_ul) {
		if(cJSON_AddStringToObject(item, "marBwUl",
		                           bw_requirement->mar_bw_ul) == NULL)
		{
			printf(
				"bw_requirement_convertToJSON() failed [mar_bw_ul]");
			goto end;
		}
	}

	if(bw_requirement->mir_bw_dl) {
		if(cJSON_AddStringToObject(item, "mirBwDl",
		                           bw_requirement->mir_bw_dl) == NULL)
		{
			printf(
				"bw_requirement_convertToJSON() failed [mir_bw_dl]");
			goto end;
		}
	}

	if(bw_requirement->mir_bw_ul) {
		if(cJSON_AddStringToObject(item, "mirBwUl",
		                           bw_requirement->mir_bw_ul) == NULL)
		{
			printf(
				"bw_requirement_convertToJSON() failed [mir_bw_ul]");
			goto end;
		}
	}

end:
	return item;
}

bw_requirement_t *bw_requirement_parseFromJSON(cJSON *bw_requirementJSON) {
	bw_requirement_t *bw_requirement_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_id = NULL;
	cJSON *mar_bw_dl = NULL;
	cJSON *mar_bw_ul = NULL;
	cJSON *mir_bw_dl = NULL;
	cJSON *mir_bw_ul = NULL;
	app_id = cJSON_GetObjectItemCaseSensitive(bw_requirementJSON, "appId");
	if(!app_id) {
		printf("bw_requirement_parseFromJSON() failed [app_id]");
		goto end;
	}
	if(!cJSON_IsString(app_id)) {
		printf("bw_requirement_parseFromJSON() failed [app_id]");
		goto end;
	}

	mar_bw_dl = cJSON_GetObjectItemCaseSensitive(bw_requirementJSON,
	                                             "marBwDl");
	if(mar_bw_dl) {
		if(!cJSON_IsString(mar_bw_dl) &&
		   !cJSON_IsNull(mar_bw_dl))
		{
			printf(
				"bw_requirement_parseFromJSON() failed [mar_bw_dl]");
			goto end;
		}
	}

	mar_bw_ul = cJSON_GetObjectItemCaseSensitive(bw_requirementJSON,
	                                             "marBwUl");
	if(mar_bw_ul) {
		if(!cJSON_IsString(mar_bw_ul) &&
		   !cJSON_IsNull(mar_bw_ul))
		{
			printf(
				"bw_requirement_parseFromJSON() failed [mar_bw_ul]");
			goto end;
		}
	}

	mir_bw_dl = cJSON_GetObjectItemCaseSensitive(bw_requirementJSON,
	                                             "mirBwDl");
	if(mir_bw_dl) {
		if(!cJSON_IsString(mir_bw_dl) &&
		   !cJSON_IsNull(mir_bw_dl))
		{
			printf(
				"bw_requirement_parseFromJSON() failed [mir_bw_dl]");
			goto end;
		}
	}

	mir_bw_ul = cJSON_GetObjectItemCaseSensitive(bw_requirementJSON,
	                                             "mirBwUl");
	if(mir_bw_ul) {
		if(!cJSON_IsString(mir_bw_ul) &&
		   !cJSON_IsNull(mir_bw_ul))
		{
			printf(
				"bw_requirement_parseFromJSON() failed [mir_bw_ul]");
			goto end;
		}
	}

	bw_requirement_local_var = bw_requirement_create(
		strdup(app_id->valuestring),
		mar_bw_dl &&
		!cJSON_IsNull(mar_bw_dl) ? strdup(
			mar_bw_dl->valuestring) : NULL,
		mar_bw_ul &&
		!cJSON_IsNull(mar_bw_ul) ? strdup(
			mar_bw_ul->valuestring) : NULL,
		mir_bw_dl &&
		!cJSON_IsNull(mir_bw_dl) ? strdup(
			mir_bw_dl->valuestring) : NULL,
		mir_bw_ul &&
		!cJSON_IsNull(mir_bw_ul) ? strdup(mir_bw_ul->valuestring) : NULL
		);

	return bw_requirement_local_var;
end:
	return NULL;
}

bw_requirement_t *bw_requirement_copy(bw_requirement_t	*dst,
                                      bw_requirement_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = bw_requirement_convertToJSON(src);
	if(!item) {
		printf("bw_requirement_convertToJSON() failed");
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

	bw_requirement_free(dst);
	dst = bw_requirement_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
