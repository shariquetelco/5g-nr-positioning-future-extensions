#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_notify_data.h"

up_notify_data_t *up_notify_data_create(
	char			*notif_correlation_id,
	up_connection_status_e	up_connection_status,
	char			*target_lmfid) {
	up_notify_data_t *up_notify_data_local_var =
		malloc(sizeof(up_notify_data_t));

	up_notify_data_local_var->notif_correlation_id = notif_correlation_id;
	up_notify_data_local_var->up_connection_status = up_connection_status;
	up_notify_data_local_var->target_lmfid = target_lmfid;

	return up_notify_data_local_var;
}

void up_notify_data_free(up_notify_data_t *up_notify_data) {
	lnode_t *node = NULL;

	if(NULL == up_notify_data) {
		return;
	}
	if(up_notify_data->notif_correlation_id) {
		free(up_notify_data->notif_correlation_id);
		up_notify_data->notif_correlation_id = NULL;
	}
	if(up_notify_data->target_lmfid) {
		free(up_notify_data->target_lmfid);
		up_notify_data->target_lmfid = NULL;
	}
	free(up_notify_data);
}

cJSON *up_notify_data_convertToJSON(up_notify_data_t *up_notify_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(up_notify_data == NULL) {
		printf("up_notify_data_convertToJSON() failed [UpNotifyData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!up_notify_data->notif_correlation_id) {
		printf(
			"up_notify_data_convertToJSON() failed [notif_correlation_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "notifCorrelationId",
	                           up_notify_data->notif_correlation_id) ==
	   NULL)
	{
		printf(
			"up_notify_data_convertToJSON() failed [notif_correlation_id]");
		goto end;
	}

	if(up_notify_data->up_connection_status == up_connection_status_NULL) {
		printf(
			"up_notify_data_convertToJSON() failed [up_connection_status]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "upConnectionStatus",
	                           up_connection_status_ToString(up_notify_data
	                                                         ->
	                                                         up_connection_status))
	   ==
	   NULL)
	{
		printf(
			"up_notify_data_convertToJSON() failed [up_connection_status]");
		goto end;
	}

	if(up_notify_data->target_lmfid) {
		if(cJSON_AddStringToObject(item, "targetLMFId",
		                           up_notify_data->target_lmfid) ==
		   NULL)
		{
			printf(
				"up_notify_data_convertToJSON() failed [target_lmfid]");
			goto end;
		}
	}

end:
	return item;
}

up_notify_data_t *up_notify_data_parseFromJSON(cJSON *up_notify_dataJSON) {
	up_notify_data_t *up_notify_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *notif_correlation_id = NULL;
	cJSON *up_connection_status = NULL;
	up_connection_status_e up_connection_statusVariable = 0;
	cJSON *target_lmfid = NULL;
	notif_correlation_id = cJSON_GetObjectItemCaseSensitive(
		up_notify_dataJSON, "notifCorrelationId");
	if(!notif_correlation_id) {
		printf(
			"up_notify_data_parseFromJSON() failed [notif_correlation_id]");
		goto end;
	}
	if(!cJSON_IsString(notif_correlation_id)) {
		printf(
			"up_notify_data_parseFromJSON() failed [notif_correlation_id]");
		goto end;
	}

	up_connection_status = cJSON_GetObjectItemCaseSensitive(
		up_notify_dataJSON, "upConnectionStatus");
	if(!up_connection_status) {
		printf(
			"up_notify_data_parseFromJSON() failed [up_connection_status]");
		goto end;
	}
	if(!cJSON_IsString(up_connection_status)) {
		printf(
			"up_notify_data_parseFromJSON() failed [up_connection_status]");
		goto end;
	}
	up_connection_statusVariable = up_connection_status_FromString(
		up_connection_status->valuestring);

	target_lmfid = cJSON_GetObjectItemCaseSensitive(up_notify_dataJSON,
	                                                "targetLMFId");
	if(target_lmfid) {
		if(!cJSON_IsString(target_lmfid) &&
		   !cJSON_IsNull(target_lmfid))
		{
			printf(
				"up_notify_data_parseFromJSON() failed [target_lmfid]");
			goto end;
		}
	}

	up_notify_data_local_var = up_notify_data_create(
		strdup(notif_correlation_id->valuestring),
		up_connection_statusVariable,
		target_lmfid &&
		!cJSON_IsNull(target_lmfid) ? strdup(
			target_lmfid->valuestring) : NULL
		);

	return up_notify_data_local_var;
end:
	return NULL;
}

up_notify_data_t *up_notify_data_copy(up_notify_data_t	*dst,
                                      up_notify_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = up_notify_data_convertToJSON(src);
	if(!item) {
		printf("up_notify_data_convertToJSON() failed");
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

	up_notify_data_free(dst);
	dst = up_notify_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
