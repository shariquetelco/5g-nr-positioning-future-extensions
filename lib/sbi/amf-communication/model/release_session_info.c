#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "release_session_info.h"

release_session_info_t *release_session_info_create(
	list_t *release_session_list, release_cause_e release_cause) {
	release_session_info_t *release_session_info_local_var =
		malloc(sizeof(release_session_info_t));

	release_session_info_local_var->release_session_list =
		release_session_list;
	release_session_info_local_var->release_cause = release_cause;

	return release_session_info_local_var;
}

void release_session_info_free(release_session_info_t *release_session_info) {
	lnode_t *node = NULL;

	if(NULL == release_session_info) {
		return;
	}
	if(release_session_info->release_session_list) {
		list_for_each(release_session_info->release_session_list,
		              node) {
			free(node->data);
		}
		list_free(release_session_info->release_session_list);
		release_session_info->release_session_list = NULL;
	}
	free(release_session_info);
}

cJSON *release_session_info_convertToJSON(
	release_session_info_t *release_session_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(release_session_info == NULL) {
		printf(
			"release_session_info_convertToJSON() failed [ReleaseSessionInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!release_session_info->release_session_list) {
		printf(
			"release_session_info_convertToJSON() failed [release_session_list]");
		return NULL;
	}
	cJSON *release_session_listList = cJSON_AddArrayToObject(item,
	                                                         "releaseSessionList");
	if(release_session_listList == NULL) {
		printf(
			"release_session_info_convertToJSON() failed [release_session_list]");
		goto end;
	}
	list_for_each(release_session_info->release_session_list, node) {
		if(node->data == NULL) {
			printf(
				"release_session_info_convertToJSON() failed [release_session_list]");
			goto end;
		}
		if(cJSON_AddNumberToObject(release_session_listList, "",
		                           *(double *) node->data) == NULL)
		{
			printf(
				"release_session_info_convertToJSON() failed [release_session_list]");
			goto end;
		}
	}

	if(release_session_info->release_cause == release_cause_NULL) {
		printf(
			"release_session_info_convertToJSON() failed [release_cause]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "releaseCause",
	                           release_cause_ToString(release_session_info->
	                                                  release_cause)) ==
	   NULL)
	{
		printf(
			"release_session_info_convertToJSON() failed [release_cause]");
		goto end;
	}

end:
	return item;
}

release_session_info_t *release_session_info_parseFromJSON(
	cJSON *release_session_infoJSON) {
	release_session_info_t *release_session_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *release_session_list = NULL;
	list_t *release_session_listList = NULL;
	cJSON *release_cause = NULL;
	release_cause_e release_causeVariable = 0;
	release_session_list = cJSON_GetObjectItemCaseSensitive(
		release_session_infoJSON, "releaseSessionList");
	if(!release_session_list) {
		printf(
			"release_session_info_parseFromJSON() failed [release_session_list]");
		goto end;
	}
	cJSON *release_session_list_local = NULL;
	if(!cJSON_IsArray(release_session_list)) {
		printf(
			"release_session_info_parseFromJSON() failed [release_session_list]");
		goto end;
	}

	release_session_listList = list_create();

	cJSON_ArrayForEach(release_session_list_local, release_session_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsNumber(release_session_list_local)) {
			printf(
				"release_session_info_parseFromJSON() failed [release_session_list]");
			goto end;
		}
		localDouble = (double *) calloc(1, sizeof(double));
		if(!localDouble) {
			printf(
				"release_session_info_parseFromJSON() failed [release_session_list]");
			goto end;
		}
		*localDouble = release_session_list_local->valuedouble;
		list_add(release_session_listList, localDouble);
	}

	release_cause = cJSON_GetObjectItemCaseSensitive(
		release_session_infoJSON, "releaseCause");
	if(!release_cause) {
		printf(
			"release_session_info_parseFromJSON() failed [release_cause]");
		goto end;
	}
	if(!cJSON_IsString(release_cause)) {
		printf(
			"release_session_info_parseFromJSON() failed [release_cause]");
		goto end;
	}
	release_causeVariable = release_cause_FromString(
		release_cause->valuestring);

	release_session_info_local_var = release_session_info_create(
		release_session_listList,
		release_causeVariable
		);

	return release_session_info_local_var;
end:
	if(release_session_listList) {
		list_for_each(release_session_listList, node) {
			free(node->data);
		}
		list_free(release_session_listList);
		release_session_listList = NULL;
	}
	return NULL;
}

release_session_info_t *release_session_info_copy(
	release_session_info_t	*dst,
	release_session_info_t	*src)
{
	cJSON *item = NULL;
	char *content = NULL;

	item = release_session_info_convertToJSON(src);
	if(!item) {
		printf("release_session_info_convertToJSON() failed");
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

	release_session_info_free(dst);
	dst = release_session_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
