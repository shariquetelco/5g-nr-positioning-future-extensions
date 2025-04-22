#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "smf_change_info.h"

smf_change_info_t *smf_change_info_create(
	list_t			*pdu_session_id_list,
	smf_change_indication_e smf_change_ind)
{
	smf_change_info_t *smf_change_info_local_var =
		malloc(sizeof(smf_change_info_t));

	smf_change_info_local_var->pdu_session_id_list = pdu_session_id_list;
	smf_change_info_local_var->smf_change_ind = smf_change_ind;

	return smf_change_info_local_var;
}

void smf_change_info_free(smf_change_info_t *smf_change_info) {
	lnode_t *node = NULL;

	if(NULL == smf_change_info) {
		return;
	}
	if(smf_change_info->pdu_session_id_list) {
		list_for_each(smf_change_info->pdu_session_id_list, node) {
			free(node->data);
		}
		list_free(smf_change_info->pdu_session_id_list);
		smf_change_info->pdu_session_id_list = NULL;
	}
	free(smf_change_info);
}

cJSON *smf_change_info_convertToJSON(smf_change_info_t *smf_change_info) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(smf_change_info == NULL) {
		printf("smf_change_info_convertToJSON() failed [SmfChangeInfo]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!smf_change_info->pdu_session_id_list) {
		printf(
			"smf_change_info_convertToJSON() failed [pdu_session_id_list]");
		return NULL;
	}
	cJSON *pdu_session_id_listList = cJSON_AddArrayToObject(item,
	                                                        "pduSessionIdList");
	if(pdu_session_id_listList == NULL) {
		printf(
			"smf_change_info_convertToJSON() failed [pdu_session_id_list]");
		goto end;
	}
	list_for_each(smf_change_info->pdu_session_id_list, node) {
		if(node->data == NULL) {
			printf(
				"smf_change_info_convertToJSON() failed [pdu_session_id_list]");
			goto end;
		}
		if(cJSON_AddNumberToObject(pdu_session_id_listList, "",
		                           *(double *) node->data) == NULL)
		{
			printf(
				"smf_change_info_convertToJSON() failed [pdu_session_id_list]");
			goto end;
		}
	}

	if(smf_change_info->smf_change_ind == smf_change_indication_NULL) {
		printf("smf_change_info_convertToJSON() failed [smf_change_ind]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "smfChangeInd",
	                           smf_change_indication_ToString(
					   smf_change_info->smf_change_ind)) ==
	   NULL)
	{
		printf("smf_change_info_convertToJSON() failed [smf_change_ind]");
		goto end;
	}

end:
	return item;
}

smf_change_info_t *smf_change_info_parseFromJSON(cJSON *smf_change_infoJSON) {
	smf_change_info_t *smf_change_info_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *pdu_session_id_list = NULL;
	list_t *pdu_session_id_listList = NULL;
	cJSON *smf_change_ind = NULL;
	smf_change_indication_e smf_change_indVariable = 0;
	pdu_session_id_list = cJSON_GetObjectItemCaseSensitive(
		smf_change_infoJSON, "pduSessionIdList");
	if(!pdu_session_id_list) {
		printf(
			"smf_change_info_parseFromJSON() failed [pdu_session_id_list]");
		goto end;
	}
	cJSON *pdu_session_id_list_local = NULL;
	if(!cJSON_IsArray(pdu_session_id_list)) {
		printf(
			"smf_change_info_parseFromJSON() failed [pdu_session_id_list]");
		goto end;
	}

	pdu_session_id_listList = list_create();

	cJSON_ArrayForEach(pdu_session_id_list_local, pdu_session_id_list) {
		double *localDouble = NULL;
		int *localInt = NULL;
		if(!cJSON_IsNumber(pdu_session_id_list_local)) {
			printf(
				"smf_change_info_parseFromJSON() failed [pdu_session_id_list]");
			goto end;
		}
		localDouble = (double *) calloc(1, sizeof(double));
		if(!localDouble) {
			printf(
				"smf_change_info_parseFromJSON() failed [pdu_session_id_list]");
			goto end;
		}
		*localDouble = pdu_session_id_list_local->valuedouble;
		list_add(pdu_session_id_listList, localDouble);
	}

	smf_change_ind = cJSON_GetObjectItemCaseSensitive(smf_change_infoJSON,
	                                                  "smfChangeInd");
	if(!smf_change_ind) {
		printf("smf_change_info_parseFromJSON() failed [smf_change_ind]");
		goto end;
	}
	if(!cJSON_IsString(smf_change_ind)) {
		printf("smf_change_info_parseFromJSON() failed [smf_change_ind]");
		goto end;
	}
	smf_change_indVariable = smf_change_indication_FromString(
		smf_change_ind->valuestring);

	smf_change_info_local_var = smf_change_info_create(
		pdu_session_id_listList,
		smf_change_indVariable
		);

	return smf_change_info_local_var;
end:
	if(pdu_session_id_listList) {
		list_for_each(pdu_session_id_listList, node) {
			free(node->data);
		}
		list_free(pdu_session_id_listList);
		pdu_session_id_listList = NULL;
	}
	return NULL;
}

smf_change_info_t *smf_change_info_copy(smf_change_info_t	*dst,
                                        smf_change_info_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = smf_change_info_convertToJSON(src);
	if(!item) {
		printf("smf_change_info_convertToJSON() failed");
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

	smf_change_info_free(dst);
	dst = smf_change_info_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
