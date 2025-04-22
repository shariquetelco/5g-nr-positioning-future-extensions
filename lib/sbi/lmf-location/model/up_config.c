#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_config.h"

up_config_t *up_config_create(char *up_notify_call_back_uri,
                              char *notif_correlation_id, char *supi,
                              char *gpsi, bool is_amf_reallocation_ind,
                              int amf_reallocation_ind,
                              lcs_up_connection_ind_e lcs_up_connection_ind,
                              char *target_lmfid) {
	up_config_t *up_config_local_var = malloc(sizeof(up_config_t));

	up_config_local_var->up_notify_call_back_uri = up_notify_call_back_uri;
	up_config_local_var->notif_correlation_id = notif_correlation_id;
	up_config_local_var->supi = supi;
	up_config_local_var->gpsi = gpsi;
	up_config_local_var->is_amf_reallocation_ind = is_amf_reallocation_ind;
	up_config_local_var->amf_reallocation_ind = amf_reallocation_ind;
	up_config_local_var->lcs_up_connection_ind = lcs_up_connection_ind;
	up_config_local_var->target_lmfid = target_lmfid;

	return up_config_local_var;
}

void up_config_free(up_config_t *up_config) {
	lnode_t *node = NULL;

	if(NULL == up_config) {
		return;
	}
	if(up_config->up_notify_call_back_uri) {
		free(up_config->up_notify_call_back_uri);
		up_config->up_notify_call_back_uri = NULL;
	}
	if(up_config->notif_correlation_id) {
		free(up_config->notif_correlation_id);
		up_config->notif_correlation_id = NULL;
	}
	if(up_config->supi) {
		free(up_config->supi);
		up_config->supi = NULL;
	}
	if(up_config->gpsi) {
		free(up_config->gpsi);
		up_config->gpsi = NULL;
	}
	if(up_config->target_lmfid) {
		free(up_config->target_lmfid);
		up_config->target_lmfid = NULL;
	}
	free(up_config);
}

cJSON *up_config_convertToJSON(up_config_t *up_config) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(up_config == NULL) {
		printf("up_config_convertToJSON() failed [UpConfig]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!up_config->up_notify_call_back_uri) {
		printf(
			"up_config_convertToJSON() failed [up_notify_call_back_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "upNotifyCallBackUri",
	                           up_config->up_notify_call_back_uri) == NULL)
	{
		printf(
			"up_config_convertToJSON() failed [up_notify_call_back_uri]");
		goto end;
	}

	if(!up_config->notif_correlation_id) {
		printf("up_config_convertToJSON() failed [notif_correlation_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "notifCorrelationId",
	                           up_config->notif_correlation_id) == NULL)
	{
		printf("up_config_convertToJSON() failed [notif_correlation_id]");
		goto end;
	}

	if(up_config->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           up_config->supi) == NULL)
		{
			printf("up_config_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(up_config->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           up_config->gpsi) == NULL)
		{
			printf("up_config_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(up_config->is_amf_reallocation_ind) {
		if(cJSON_AddBoolToObject(item, "amfReallocationInd",
		                         up_config->amf_reallocation_ind) ==
		   NULL)
		{
			printf(
				"up_config_convertToJSON() failed [amf_reallocation_ind]");
			goto end;
		}
	}

	if(up_config->lcs_up_connection_ind != lcs_up_connection_ind_NULL) {
		if(cJSON_AddStringToObject(item, "lcsUpConnectionInd",
		                           lcs_up_connection_ind_ToString(
						   up_config->
						   lcs_up_connection_ind)) ==
		   NULL)
		{
			printf(
				"up_config_convertToJSON() failed [lcs_up_connection_ind]");
			goto end;
		}
	}

	if(up_config->target_lmfid) {
		if(cJSON_AddStringToObject(item, "targetLMFId",
		                           up_config->target_lmfid) == NULL)
		{
			printf("up_config_convertToJSON() failed [target_lmfid]");
			goto end;
		}
	}

end:
	return item;
}

up_config_t *up_config_parseFromJSON(cJSON *up_configJSON) {
	up_config_t *up_config_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *up_notify_call_back_uri = NULL;
	cJSON *notif_correlation_id = NULL;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	cJSON *amf_reallocation_ind = NULL;
	cJSON *lcs_up_connection_ind = NULL;
	lcs_up_connection_ind_e lcs_up_connection_indVariable = 0;
	cJSON *target_lmfid = NULL;
	up_notify_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		up_configJSON, "upNotifyCallBackUri");
	if(!up_notify_call_back_uri) {
		printf(
			"up_config_parseFromJSON() failed [up_notify_call_back_uri]");
		goto end;
	}
	if(!cJSON_IsString(up_notify_call_back_uri)) {
		printf(
			"up_config_parseFromJSON() failed [up_notify_call_back_uri]");
		goto end;
	}

	notif_correlation_id = cJSON_GetObjectItemCaseSensitive(up_configJSON,
	                                                        "notifCorrelationId");
	if(!notif_correlation_id) {
		printf("up_config_parseFromJSON() failed [notif_correlation_id]");
		goto end;
	}
	if(!cJSON_IsString(notif_correlation_id)) {
		printf("up_config_parseFromJSON() failed [notif_correlation_id]");
		goto end;
	}

	supi = cJSON_GetObjectItemCaseSensitive(up_configJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("up_config_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(up_configJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("up_config_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	amf_reallocation_ind = cJSON_GetObjectItemCaseSensitive(up_configJSON,
	                                                        "amfReallocationInd");
	if(amf_reallocation_ind) {
		if(!cJSON_IsBool(amf_reallocation_ind)) {
			printf(
				"up_config_parseFromJSON() failed [amf_reallocation_ind]");
			goto end;
		}
	}

	lcs_up_connection_ind = cJSON_GetObjectItemCaseSensitive(up_configJSON,
	                                                         "lcsUpConnectionInd");
	if(lcs_up_connection_ind) {
		if(!cJSON_IsString(lcs_up_connection_ind)) {
			printf(
				"up_config_parseFromJSON() failed [lcs_up_connection_ind]");
			goto end;
		}
		lcs_up_connection_indVariable =
			lcs_up_connection_ind_FromString(
				lcs_up_connection_ind->valuestring);
	}

	target_lmfid = cJSON_GetObjectItemCaseSensitive(up_configJSON,
	                                                "targetLMFId");
	if(target_lmfid) {
		if(!cJSON_IsString(target_lmfid) &&
		   !cJSON_IsNull(target_lmfid))
		{
			printf("up_config_parseFromJSON() failed [target_lmfid]");
			goto end;
		}
	}

	up_config_local_var = up_config_create(
		strdup(up_notify_call_back_uri->valuestring),
		strdup(notif_correlation_id->valuestring),
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		amf_reallocation_ind ? true : false,
		amf_reallocation_ind ? amf_reallocation_ind->valueint : 0,
		lcs_up_connection_ind ? lcs_up_connection_indVariable : 0,
		target_lmfid &&
		!cJSON_IsNull(target_lmfid) ? strdup(
			target_lmfid->valuestring) : NULL
		);

	return up_config_local_var;
end:
	return NULL;
}

up_config_t *up_config_copy(up_config_t *dst, up_config_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = up_config_convertToJSON(src);
	if(!item) {
		printf("up_config_convertToJSON() failed");
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

	up_config_free(dst);
	dst = up_config_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
