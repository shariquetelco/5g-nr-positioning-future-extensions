#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "application_volume.h"

application_volume_t *application_volume_create(char *app_id, long app_volume) {
	application_volume_t *application_volume_local_var =
		malloc(sizeof(application_volume_t));

	application_volume_local_var->app_id = app_id;
	application_volume_local_var->app_volume = app_volume;

	return application_volume_local_var;
}

void application_volume_free(application_volume_t *application_volume) {
	lnode_t *node = NULL;

	if(NULL == application_volume) {
		return;
	}
	if(application_volume->app_id) {
		free(application_volume->app_id);
		application_volume->app_id = NULL;
	}
	free(application_volume);
}

cJSON *application_volume_convertToJSON(
	application_volume_t *application_volume) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(application_volume == NULL) {
		printf(
			"application_volume_convertToJSON() failed [ApplicationVolume]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!application_volume->app_id) {
		printf("application_volume_convertToJSON() failed [app_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "appId",
	                           application_volume->app_id) == NULL)
	{
		printf("application_volume_convertToJSON() failed [app_id]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "appVolume",
	                           application_volume->app_volume) == NULL)
	{
		printf("application_volume_convertToJSON() failed [app_volume]");
		goto end;
	}

end:
	return item;
}

application_volume_t *application_volume_parseFromJSON(
	cJSON *application_volumeJSON) {
	application_volume_t *application_volume_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_id = NULL;
	cJSON *app_volume = NULL;
	app_id = cJSON_GetObjectItemCaseSensitive(application_volumeJSON,
	                                          "appId");
	if(!app_id) {
		printf("application_volume_parseFromJSON() failed [app_id]");
		goto end;
	}
	if(!cJSON_IsString(app_id)) {
		printf("application_volume_parseFromJSON() failed [app_id]");
		goto end;
	}

	app_volume = cJSON_GetObjectItemCaseSensitive(application_volumeJSON,
	                                              "appVolume");
	if(!app_volume) {
		printf("application_volume_parseFromJSON() failed [app_volume]");
		goto end;
	}
	if(!cJSON_IsNumber(app_volume)) {
		printf("application_volume_parseFromJSON() failed [app_volume]");
		goto end;
	}

	application_volume_local_var = application_volume_create(
		strdup(app_id->valuestring),

		app_volume->valuedouble
		);

	return application_volume_local_var;
end:
	return NULL;
}

application_volume_t *application_volume_copy(application_volume_t	*dst,
                                              application_volume_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = application_volume_convertToJSON(src);
	if(!item) {
		printf("application_volume_convertToJSON() failed");
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

	application_volume_free(dst);
	dst = application_volume_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
