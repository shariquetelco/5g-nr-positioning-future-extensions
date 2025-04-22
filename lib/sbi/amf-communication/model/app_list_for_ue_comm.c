#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "app_list_for_ue_comm.h"

app_list_for_ue_comm_t *app_list_for_ue_comm_create(char		*app_id,
                                                    char		*start_time,
                                                    bool		is_app_dur,
                                                    int			app_dur,
                                                    bool		is_occur_ratio,
                                                    int			occur_ratio,
                                                    network_area_info_t *spatial_validity)
{
	app_list_for_ue_comm_t *app_list_for_ue_comm_local_var =
		malloc(sizeof(app_list_for_ue_comm_t));

	app_list_for_ue_comm_local_var->app_id = app_id;
	app_list_for_ue_comm_local_var->start_time = start_time;
	app_list_for_ue_comm_local_var->is_app_dur = is_app_dur;
	app_list_for_ue_comm_local_var->app_dur = app_dur;
	app_list_for_ue_comm_local_var->is_occur_ratio = is_occur_ratio;
	app_list_for_ue_comm_local_var->occur_ratio = occur_ratio;
	app_list_for_ue_comm_local_var->spatial_validity = spatial_validity;

	return app_list_for_ue_comm_local_var;
}

void app_list_for_ue_comm_free(app_list_for_ue_comm_t *app_list_for_ue_comm) {
	lnode_t *node = NULL;

	if(NULL == app_list_for_ue_comm) {
		return;
	}
	if(app_list_for_ue_comm->app_id) {
		free(app_list_for_ue_comm->app_id);
		app_list_for_ue_comm->app_id = NULL;
	}
	if(app_list_for_ue_comm->start_time) {
		free(app_list_for_ue_comm->start_time);
		app_list_for_ue_comm->start_time = NULL;
	}
	if(app_list_for_ue_comm->spatial_validity) {
		network_area_info_free(app_list_for_ue_comm->spatial_validity);
		app_list_for_ue_comm->spatial_validity = NULL;
	}
	free(app_list_for_ue_comm);
}

cJSON *app_list_for_ue_comm_convertToJSON(
	app_list_for_ue_comm_t *app_list_for_ue_comm) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(app_list_for_ue_comm == NULL) {
		printf(
			"app_list_for_ue_comm_convertToJSON() failed [AppListForUeComm]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!app_list_for_ue_comm->app_id) {
		printf("app_list_for_ue_comm_convertToJSON() failed [app_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "appId",
	                           app_list_for_ue_comm->app_id) == NULL)
	{
		printf("app_list_for_ue_comm_convertToJSON() failed [app_id]");
		goto end;
	}

	if(app_list_for_ue_comm->start_time) {
		if(cJSON_AddStringToObject(item, "startTime",
		                           app_list_for_ue_comm->start_time) ==
		   NULL)
		{
			printf(
				"app_list_for_ue_comm_convertToJSON() failed [start_time]");
			goto end;
		}
	}

	if(app_list_for_ue_comm->is_app_dur) {
		if(cJSON_AddNumberToObject(item, "appDur",
		                           app_list_for_ue_comm->app_dur) ==
		   NULL)
		{
			printf(
				"app_list_for_ue_comm_convertToJSON() failed [app_dur]");
			goto end;
		}
	}

	if(app_list_for_ue_comm->is_occur_ratio) {
		if(cJSON_AddNumberToObject(item, "occurRatio",
		                           app_list_for_ue_comm->occur_ratio) ==
		   NULL)
		{
			printf(
				"app_list_for_ue_comm_convertToJSON() failed [occur_ratio]");
			goto end;
		}
	}

	if(app_list_for_ue_comm->spatial_validity) {
		cJSON *spatial_validity_local_JSON =
			network_area_info_convertToJSON(
				app_list_for_ue_comm->spatial_validity);
		if(spatial_validity_local_JSON == NULL) {
			printf(
				"app_list_for_ue_comm_convertToJSON() failed [spatial_validity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "spatialValidity",
		                      spatial_validity_local_JSON);
		if(item->child == NULL) {
			printf(
				"app_list_for_ue_comm_convertToJSON() failed [spatial_validity]");
			goto end;
		}
	}

end:
	return item;
}

app_list_for_ue_comm_t *app_list_for_ue_comm_parseFromJSON(
	cJSON *app_list_for_ue_commJSON) {
	app_list_for_ue_comm_t *app_list_for_ue_comm_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *app_id = NULL;
	cJSON *start_time = NULL;
	cJSON *app_dur = NULL;
	cJSON *occur_ratio = NULL;
	cJSON *spatial_validity = NULL;
	network_area_info_t *spatial_validity_local_nonprim = NULL;
	app_id = cJSON_GetObjectItemCaseSensitive(app_list_for_ue_commJSON,
	                                          "appId");
	if(!app_id) {
		printf("app_list_for_ue_comm_parseFromJSON() failed [app_id]");
		goto end;
	}
	if(!cJSON_IsString(app_id)) {
		printf("app_list_for_ue_comm_parseFromJSON() failed [app_id]");
		goto end;
	}

	start_time = cJSON_GetObjectItemCaseSensitive(app_list_for_ue_commJSON,
	                                              "startTime");
	if(start_time) {
		if(!cJSON_IsString(start_time) &&
		   !cJSON_IsNull(start_time))
		{
			printf(
				"app_list_for_ue_comm_parseFromJSON() failed [start_time]");
			goto end;
		}
	}

	app_dur = cJSON_GetObjectItemCaseSensitive(app_list_for_ue_commJSON,
	                                           "appDur");
	if(app_dur) {
		if(!cJSON_IsNumber(app_dur)) {
			printf(
				"app_list_for_ue_comm_parseFromJSON() failed [app_dur]");
			goto end;
		}
	}

	occur_ratio = cJSON_GetObjectItemCaseSensitive(app_list_for_ue_commJSON,
	                                               "occurRatio");
	if(occur_ratio) {
		if(!cJSON_IsNumber(occur_ratio)) {
			printf(
				"app_list_for_ue_comm_parseFromJSON() failed [occur_ratio]");
			goto end;
		}
	}

	spatial_validity = cJSON_GetObjectItemCaseSensitive(
		app_list_for_ue_commJSON, "spatialValidity");
	if(spatial_validity) {
		spatial_validity_local_nonprim =
			network_area_info_parseFromJSON(spatial_validity);
		if(!spatial_validity_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [spatial_validity]");
			goto end;
		}
	}

	app_list_for_ue_comm_local_var = app_list_for_ue_comm_create(
		strdup(app_id->valuestring),
		start_time &&
		!cJSON_IsNull(start_time) ? strdup(
			start_time->valuestring) : NULL,
		app_dur ? true : false,
		app_dur ? app_dur->valuedouble : 0,
		occur_ratio ? true : false,
		occur_ratio ? occur_ratio->valuedouble : 0,
		spatial_validity ? spatial_validity_local_nonprim : NULL
		);

	return app_list_for_ue_comm_local_var;
end:
	if(spatial_validity_local_nonprim) {
		network_area_info_free(spatial_validity_local_nonprim);
		spatial_validity_local_nonprim = NULL;
	}
	return NULL;
}

app_list_for_ue_comm_t *app_list_for_ue_comm_copy(
	app_list_for_ue_comm_t	*dst,
	app_list_for_ue_comm_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = app_list_for_ue_comm_convertToJSON(src);
	if(!item) {
		printf("app_list_for_ue_comm_convertToJSON() failed");
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

	app_list_for_ue_comm_free(dst);
	dst = app_list_for_ue_comm_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
