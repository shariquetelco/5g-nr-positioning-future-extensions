#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "privacy_check_id_mapping_resp_data.h"

privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data_create(
	char *app_layer_id, char *gpsi) {
	privacy_check_id_mapping_resp_data_t *
	        privacy_check_id_mapping_resp_data_local_var =
		malloc(sizeof(privacy_check_id_mapping_resp_data_t));

	privacy_check_id_mapping_resp_data_local_var->app_layer_id =
		app_layer_id;
	privacy_check_id_mapping_resp_data_local_var->gpsi = gpsi;

	return privacy_check_id_mapping_resp_data_local_var;
}

void privacy_check_id_mapping_resp_data_free(
	privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data)
{
	lnode_t *node = NULL;

	if(NULL == privacy_check_id_mapping_resp_data) {
		return;
	}
	if(privacy_check_id_mapping_resp_data->app_layer_id) {
		free(privacy_check_id_mapping_resp_data->app_layer_id);
		privacy_check_id_mapping_resp_data->app_layer_id = NULL;
	}
	if(privacy_check_id_mapping_resp_data->gpsi) {
		free(privacy_check_id_mapping_resp_data->gpsi);
		privacy_check_id_mapping_resp_data->gpsi = NULL;
	}
	free(privacy_check_id_mapping_resp_data);
}

cJSON *privacy_check_id_mapping_resp_data_convertToJSON(
	privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data)
{
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(privacy_check_id_mapping_resp_data == NULL) {
		printf(
			"privacy_check_id_mapping_resp_data_convertToJSON() failed [PrivacyCheckIdMappingRespData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(privacy_check_id_mapping_resp_data->app_layer_id) {
		if(cJSON_AddStringToObject(item, "appLayerId",
		                           privacy_check_id_mapping_resp_data->
		                           app_layer_id) == NULL)
		{
			printf(
				"privacy_check_id_mapping_resp_data_convertToJSON() failed [app_layer_id]");
			goto end;
		}
	}

	if(privacy_check_id_mapping_resp_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           privacy_check_id_mapping_resp_data->
		                           gpsi) == NULL)
		{
			printf(
				"privacy_check_id_mapping_resp_data_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

end:
	return item;
}

privacy_check_id_mapping_resp_data_t *
privacy_check_id_mapping_resp_data_parseFromJSON(
	cJSON *privacy_check_id_mapping_resp_dataJSON) {
	privacy_check_id_mapping_resp_data_t *
	        privacy_check_id_mapping_resp_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_layer_id = NULL;
	cJSON *gpsi = NULL;
	app_layer_id = cJSON_GetObjectItemCaseSensitive(
		privacy_check_id_mapping_resp_dataJSON, "appLayerId");
	if(app_layer_id) {
		if(!cJSON_IsString(app_layer_id) &&
		   !cJSON_IsNull(app_layer_id))
		{
			printf(
				"privacy_check_id_mapping_resp_data_parseFromJSON() failed [app_layer_id]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(
		privacy_check_id_mapping_resp_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf(
				"privacy_check_id_mapping_resp_data_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	privacy_check_id_mapping_resp_data_local_var =
		privacy_check_id_mapping_resp_data_create(
			app_layer_id &&
			!cJSON_IsNull(app_layer_id) ? strdup(
				app_layer_id->valuestring) : NULL,
			gpsi &&
			!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL
			);

	return privacy_check_id_mapping_resp_data_local_var;
end:
	return NULL;
}

privacy_check_id_mapping_resp_data_t *privacy_check_id_mapping_resp_data_copy(
	privacy_check_id_mapping_resp_data_t	*dst,
	privacy_check_id_mapping_resp_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = privacy_check_id_mapping_resp_data_convertToJSON(src);
	if(!item) {
		printf(
			"privacy_check_id_mapping_resp_data_convertToJSON() failed");
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

	privacy_check_id_mapping_resp_data_free(dst);
	dst = privacy_check_id_mapping_resp_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
