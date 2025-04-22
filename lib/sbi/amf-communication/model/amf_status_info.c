#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_status_info.h"

amf_status_info_t *amf_status_info_create(list_t		*guami_list,
                                          status_change_e	status_change,
                                          char			*target_amf_removal,
                                          char			*target_amf_failure)
{
	amf_status_info_t *amf_status_info_local_var =
		malloc(sizeof(amf_status_info_t));

	amf_status_info_local_var->guami_list = guami_list;
	amf_status_info_local_var->status_change = status_change;
	amf_status_info_local_var->target_amf_removal = target_amf_removal;
	amf_status_info_local_var->target_amf_failure = target_amf_failure;

	return amf_status_info_local_var;
}

void amf_status_info_free(amf_status_info_t *amf_status_info) {
	lnode_t *node = NULL;

	if(NULL == amf_status_info) {
		return;
	}
	if(amf_status_info->guami_list) {
		list_for_each(amf_status_info->guami_list, node) {
			guami_free(node->data);
		}
		list_free(amf_status_info->guami_list);
		amf_status_info->guami_list = NULL;
	}
	if(amf_status_info->target_amf_removal) {
		free(amf_status_info->target_amf_removal);
		amf_status_info->target_amf_removal = NULL;
	}
	if(amf_status_info->target_amf_failure) {
		free(amf_status_info->target_amf_failure);
		amf_status_info->target_amf_failure = NULL;
	}
	free(amf_status_info);
}

cJSON *amf_status_info_convertToJSON(amf_status_info_t *amf_status_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_status_info == NULL) {
		printf("amf_status_info_convertToJSON() failed [AmfStatusInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!amf_status_info->guami_list) {
		printf("amf_status_info_convertToJSON() failed [guami_list]");
		return NULL;
	}
	cJSON *guami_listList = cJSON_AddArrayToObject(item, "guamiList");
	if(guami_listList == NULL) {
		printf("amf_status_info_convertToJSON() failed [guami_list]");
		goto end;
	}
	list_for_each(amf_status_info->guami_list, node) {
		cJSON *itemLocal = guami_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"amf_status_info_convertToJSON() failed [guami_list]");
			goto end;
		}
		cJSON_AddItemToArray(guami_listList, itemLocal);
	}

	if(amf_status_info->status_change == status_change_NULL) {
		printf("amf_status_info_convertToJSON() failed [status_change]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "statusChange",
	                           status_change_ToString(amf_status_info->
	                                                  status_change)) ==
	   NULL)
	{
		printf("amf_status_info_convertToJSON() failed [status_change]");
		goto end;
	}

	if(amf_status_info->target_amf_removal) {
		if(cJSON_AddStringToObject(item, "targetAmfRemoval",
		                           amf_status_info->target_amf_removal)
		   == NULL)
		{
			printf(
				"amf_status_info_convertToJSON() failed [target_amf_removal]");
			goto end;
		}
	}

	if(amf_status_info->target_amf_failure) {
		if(cJSON_AddStringToObject(item, "targetAmfFailure",
		                           amf_status_info->target_amf_failure)
		   == NULL)
		{
			printf(
				"amf_status_info_convertToJSON() failed [target_amf_failure]");
			goto end;
		}
	}

end:
	return item;
}

amf_status_info_t *amf_status_info_parseFromJSON(cJSON *amf_status_infoJSON) {
	amf_status_info_t *amf_status_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *guami_list = NULL;
	list_t *guami_listList = NULL;
	cJSON *status_change = NULL;
	status_change_e status_changeVariable = 0;
	cJSON *target_amf_removal = NULL;
	cJSON *target_amf_failure = NULL;
	guami_list = cJSON_GetObjectItemCaseSensitive(amf_status_infoJSON,
	                                              "guamiList");
	if(!guami_list) {
		printf("amf_status_info_parseFromJSON() failed [guami_list]");
		goto end;
	}
	cJSON *guami_list_local = NULL;
	if(!cJSON_IsArray(guami_list)) {
		printf("amf_status_info_parseFromJSON() failed [guami_list]");
		goto end;
	}

	guami_listList = list_create();

	cJSON_ArrayForEach(guami_list_local, guami_list) {
		if(!cJSON_IsObject(guami_list_local)) {
			printf(
				"amf_status_info_parseFromJSON() failed [guami_list]");
			goto end;
		}
		guami_t *guami_listItem = guami_parseFromJSON(guami_list_local);
		if(!guami_listItem) {
			printf("No guami_listItem");
			goto end;
		}
		list_add(guami_listList, guami_listItem);
	}

	status_change = cJSON_GetObjectItemCaseSensitive(amf_status_infoJSON,
	                                                 "statusChange");
	if(!status_change) {
		printf("amf_status_info_parseFromJSON() failed [status_change]");
		goto end;
	}
	if(!cJSON_IsString(status_change)) {
		printf("amf_status_info_parseFromJSON() failed [status_change]");
		goto end;
	}
	status_changeVariable = status_change_FromString(
		status_change->valuestring);

	target_amf_removal = cJSON_GetObjectItemCaseSensitive(
		amf_status_infoJSON, "targetAmfRemoval");
	if(target_amf_removal) {
		if(!cJSON_IsString(target_amf_removal) &&
		   !cJSON_IsNull(target_amf_removal))
		{
			printf(
				"amf_status_info_parseFromJSON() failed [target_amf_removal]");
			goto end;
		}
	}

	target_amf_failure = cJSON_GetObjectItemCaseSensitive(
		amf_status_infoJSON, "targetAmfFailure");
	if(target_amf_failure) {
		if(!cJSON_IsString(target_amf_failure) &&
		   !cJSON_IsNull(target_amf_failure))
		{
			printf(
				"amf_status_info_parseFromJSON() failed [target_amf_failure]");
			goto end;
		}
	}

	amf_status_info_local_var = amf_status_info_create(
		guami_listList,
		status_changeVariable,
		target_amf_removal &&
		!cJSON_IsNull(target_amf_removal) ? strdup(target_amf_removal->
		                                           valuestring) : NULL,
		target_amf_failure &&
		!cJSON_IsNull(target_amf_failure) ? strdup(target_amf_failure->
		                                           valuestring) : NULL
		);

	return amf_status_info_local_var;
end:
	if(guami_listList) {
		list_for_each(guami_listList, node) {
			guami_free(node->data);
		}
		list_free(guami_listList);
		guami_listList = NULL;
	}
	return NULL;
}

amf_status_info_t *amf_status_info_copy(amf_status_info_t	*dst,
                                        amf_status_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_status_info_convertToJSON(src);
	if(!item) {
		printf("amf_status_info_convertToJSON() failed");
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

	amf_status_info_free(dst);
	dst = amf_status_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
