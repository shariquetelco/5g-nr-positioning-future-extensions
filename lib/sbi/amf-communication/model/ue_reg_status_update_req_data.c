#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_reg_status_update_req_data.h"

ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_create(
	ue_context_transfer_status_e transfer_status,
	list_t *to_release_session_list, bool is_pcf_reselected_ind,
	int pcf_reselected_ind, list_t *smf_change_info_list,
	list_t *analytics_not_used_list, list_t *to_release_session_info) {
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_local_var
	        = malloc(sizeof(ue_reg_status_update_req_data_t));

	ue_reg_status_update_req_data_local_var->transfer_status =
		transfer_status;
	ue_reg_status_update_req_data_local_var->to_release_session_list =
		to_release_session_list;
	ue_reg_status_update_req_data_local_var->is_pcf_reselected_ind =
		is_pcf_reselected_ind;
	ue_reg_status_update_req_data_local_var->pcf_reselected_ind =
		pcf_reselected_ind;
	ue_reg_status_update_req_data_local_var->smf_change_info_list =
		smf_change_info_list;
	ue_reg_status_update_req_data_local_var->analytics_not_used_list =
		analytics_not_used_list;
	ue_reg_status_update_req_data_local_var->to_release_session_info =
		to_release_session_info;

	return ue_reg_status_update_req_data_local_var;
}

void ue_reg_status_update_req_data_free(
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data) {
	lnode_t *node = NULL;

	if(NULL == ue_reg_status_update_req_data) {
		return;
	}
	if(ue_reg_status_update_req_data->to_release_session_list) {
		list_for_each(
			ue_reg_status_update_req_data->to_release_session_list,
			node) {
			free(node->data);
		}
		list_free(ue_reg_status_update_req_data->to_release_session_list);
		ue_reg_status_update_req_data->to_release_session_list = NULL;
	}
	if(ue_reg_status_update_req_data->smf_change_info_list) {
		list_for_each(
			ue_reg_status_update_req_data->smf_change_info_list,
			node) {
			smf_change_info_free(node->data);
		}
		list_free(ue_reg_status_update_req_data->smf_change_info_list);
		ue_reg_status_update_req_data->smf_change_info_list = NULL;
	}
	if(ue_reg_status_update_req_data->analytics_not_used_list) {
		list_for_each(
			ue_reg_status_update_req_data->analytics_not_used_list,
			node) {
			free(node->data);
		}
		list_free(ue_reg_status_update_req_data->analytics_not_used_list);
		ue_reg_status_update_req_data->analytics_not_used_list = NULL;
	}
	if(ue_reg_status_update_req_data->to_release_session_info) {
		list_for_each(
			ue_reg_status_update_req_data->to_release_session_info,
			node) {
			release_session_info_free(node->data);
		}
		list_free(ue_reg_status_update_req_data->to_release_session_info);
		ue_reg_status_update_req_data->to_release_session_info = NULL;
	}
	free(ue_reg_status_update_req_data);
}

cJSON *ue_reg_status_update_req_data_convertToJSON(
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_reg_status_update_req_data == NULL) {
		printf(
			"ue_reg_status_update_req_data_convertToJSON() failed [UeRegStatusUpdateReqData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(ue_reg_status_update_req_data->transfer_status ==
	   ue_context_transfer_status_NULL)
	{
		printf(
			"ue_reg_status_update_req_data_convertToJSON() failed [transfer_status]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "transferStatus",
	                           ue_context_transfer_status_ToString(
					   ue_reg_status_update_req_data->
					   transfer_status))
	   == NULL)
	{
		printf(
			"ue_reg_status_update_req_data_convertToJSON() failed [transfer_status]");
		goto end;
	}

	if(ue_reg_status_update_req_data->to_release_session_list) {
		cJSON *to_release_session_listList = cJSON_AddArrayToObject(
			item, "toReleaseSessionList");
		if(to_release_session_listList == NULL) {
			printf(
				"ue_reg_status_update_req_data_convertToJSON() failed [to_release_session_list]");
			goto end;
		}
		list_for_each(
			ue_reg_status_update_req_data->to_release_session_list,
			node) {
			if(node->data == NULL) {
				printf(
					"ue_reg_status_update_req_data_convertToJSON() failed [to_release_session_list]");
				goto end;
			}
			if(cJSON_AddNumberToObject(to_release_session_listList,
			                           "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"ue_reg_status_update_req_data_convertToJSON() failed [to_release_session_list]");
				goto end;
			}
		}
	}

	if(ue_reg_status_update_req_data->is_pcf_reselected_ind) {
		if(cJSON_AddBoolToObject(item, "pcfReselectedInd",
		                         ue_reg_status_update_req_data->
		                         pcf_reselected_ind) == NULL)
		{
			printf(
				"ue_reg_status_update_req_data_convertToJSON() failed [pcf_reselected_ind]");
			goto end;
		}
	}

	if(ue_reg_status_update_req_data->smf_change_info_list) {
		cJSON *smf_change_info_listList = cJSON_AddArrayToObject(item,
		                                                         "smfChangeInfoList");
		if(smf_change_info_listList == NULL) {
			printf(
				"ue_reg_status_update_req_data_convertToJSON() failed [smf_change_info_list]");
			goto end;
		}
		list_for_each(
			ue_reg_status_update_req_data->smf_change_info_list,
			node) {
			cJSON *itemLocal = smf_change_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"ue_reg_status_update_req_data_convertToJSON() failed [smf_change_info_list]");
				goto end;
			}
			cJSON_AddItemToArray(smf_change_info_listList,
			                     itemLocal);
		}
	}

	if(ue_reg_status_update_req_data->analytics_not_used_list) {
		cJSON *analytics_not_used_listList = cJSON_AddArrayToObject(
			item, "analyticsNotUsedList");
		if(analytics_not_used_listList == NULL) {
			printf(
				"ue_reg_status_update_req_data_convertToJSON() failed [analytics_not_used_list]");
			goto end;
		}
		list_for_each(
			ue_reg_status_update_req_data->analytics_not_used_list,
			node) {
			if(cJSON_AddStringToObject(analytics_not_used_listList,
			                           "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"ue_reg_status_update_req_data_convertToJSON() failed [analytics_not_used_list]");
				goto end;
			}
		}
	}

	if(ue_reg_status_update_req_data->to_release_session_info) {
		cJSON *to_release_session_infoList = cJSON_AddArrayToObject(
			item, "toReleaseSessionInfo");
		if(to_release_session_infoList == NULL) {
			printf(
				"ue_reg_status_update_req_data_convertToJSON() failed [to_release_session_info]");
			goto end;
		}
		list_for_each(
			ue_reg_status_update_req_data->to_release_session_info,
			node) {
			cJSON *itemLocal = release_session_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"ue_reg_status_update_req_data_convertToJSON() failed [to_release_session_info]");
				goto end;
			}
			cJSON_AddItemToArray(to_release_session_infoList,
			                     itemLocal);
		}
	}

end:
	return item;
}

ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_parseFromJSON(
	cJSON *ue_reg_status_update_req_dataJSON) {
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_local_var
	        = NULL;
	lnode_t *node = NULL;
	cJSON *transfer_status = NULL;
	ue_context_transfer_status_e transfer_statusVariable = 0;
	cJSON *to_release_session_list = NULL;
	list_t *to_release_session_listList = NULL;
	cJSON *pcf_reselected_ind = NULL;
	cJSON *smf_change_info_list = NULL;
	list_t *smf_change_info_listList = NULL;
	cJSON *analytics_not_used_list = NULL;
	list_t *analytics_not_used_listList = NULL;
	cJSON *to_release_session_info = NULL;
	list_t *to_release_session_infoList = NULL;
	transfer_status = cJSON_GetObjectItemCaseSensitive(
		ue_reg_status_update_req_dataJSON, "transferStatus");
	if(!transfer_status) {
		printf(
			"ue_reg_status_update_req_data_parseFromJSON() failed [transfer_status]");
		goto end;
	}
	if(!cJSON_IsString(transfer_status)) {
		printf(
			"ue_reg_status_update_req_data_parseFromJSON() failed [transfer_status]");
		goto end;
	}
	transfer_statusVariable = ue_context_transfer_status_FromString(
		transfer_status->valuestring);

	to_release_session_list = cJSON_GetObjectItemCaseSensitive(
		ue_reg_status_update_req_dataJSON, "toReleaseSessionList");
	if(to_release_session_list) {
		cJSON *to_release_session_list_local = NULL;
		if(!cJSON_IsArray(to_release_session_list)) {
			printf(
				"ue_reg_status_update_req_data_parseFromJSON() failed [to_release_session_list]");
			goto end;
		}

		to_release_session_listList = list_create();

		cJSON_ArrayForEach(to_release_session_list_local,
		                   to_release_session_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(to_release_session_list_local)) {
				printf(
					"ue_reg_status_update_req_data_parseFromJSON() failed [to_release_session_list]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"ue_reg_status_update_req_data_parseFromJSON() failed [to_release_session_list]");
				goto end;
			}
			*localDouble =
				to_release_session_list_local->valuedouble;
			list_add(to_release_session_listList, localDouble);
		}
	}

	pcf_reselected_ind = cJSON_GetObjectItemCaseSensitive(
		ue_reg_status_update_req_dataJSON, "pcfReselectedInd");
	if(pcf_reselected_ind) {
		if(!cJSON_IsBool(pcf_reselected_ind)) {
			printf(
				"ue_reg_status_update_req_data_parseFromJSON() failed [pcf_reselected_ind]");
			goto end;
		}
	}

	smf_change_info_list = cJSON_GetObjectItemCaseSensitive(
		ue_reg_status_update_req_dataJSON, "smfChangeInfoList");
	if(smf_change_info_list) {
		cJSON *smf_change_info_list_local = NULL;
		if(!cJSON_IsArray(smf_change_info_list)) {
			printf(
				"ue_reg_status_update_req_data_parseFromJSON() failed [smf_change_info_list]");
			goto end;
		}

		smf_change_info_listList = list_create();

		cJSON_ArrayForEach(smf_change_info_list_local,
		                   smf_change_info_list) {
			if(!cJSON_IsObject(smf_change_info_list_local)) {
				printf(
					"ue_reg_status_update_req_data_parseFromJSON() failed [smf_change_info_list]");
				goto end;
			}
			smf_change_info_t *smf_change_info_listItem =
				smf_change_info_parseFromJSON(
					smf_change_info_list_local);
			if(!smf_change_info_listItem) {
				printf("No smf_change_info_listItem");
				goto end;
			}
			list_add(smf_change_info_listList,
			         smf_change_info_listItem);
		}
	}

	analytics_not_used_list = cJSON_GetObjectItemCaseSensitive(
		ue_reg_status_update_req_dataJSON, "analyticsNotUsedList");
	if(analytics_not_used_list) {
		cJSON *analytics_not_used_list_local = NULL;
		if(!cJSON_IsArray(analytics_not_used_list)) {
			printf(
				"ue_reg_status_update_req_data_parseFromJSON() failed [analytics_not_used_list]");
			goto end;
		}

		analytics_not_used_listList = list_create();

		cJSON_ArrayForEach(analytics_not_used_list_local,
		                   analytics_not_used_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(analytics_not_used_list_local)) {
				printf(
					"ue_reg_status_update_req_data_parseFromJSON() failed [analytics_not_used_list]");
				goto end;
			}
			list_add(analytics_not_used_listList,
			         strdup(analytics_not_used_list_local->
			                valuestring));
		}
	}

	to_release_session_info = cJSON_GetObjectItemCaseSensitive(
		ue_reg_status_update_req_dataJSON, "toReleaseSessionInfo");
	if(to_release_session_info) {
		cJSON *to_release_session_info_local = NULL;
		if(!cJSON_IsArray(to_release_session_info)) {
			printf(
				"ue_reg_status_update_req_data_parseFromJSON() failed [to_release_session_info]");
			goto end;
		}

		to_release_session_infoList = list_create();

		cJSON_ArrayForEach(to_release_session_info_local,
		                   to_release_session_info) {
			if(!cJSON_IsObject(to_release_session_info_local)) {
				printf(
					"ue_reg_status_update_req_data_parseFromJSON() failed [to_release_session_info]");
				goto end;
			}
			release_session_info_t *to_release_session_infoItem =
				release_session_info_parseFromJSON(
					to_release_session_info_local);
			if(!to_release_session_infoItem) {
				printf("No to_release_session_infoItem");
				goto end;
			}
			list_add(to_release_session_infoList,
			         to_release_session_infoItem);
		}
	}

	ue_reg_status_update_req_data_local_var =
		ue_reg_status_update_req_data_create(
			transfer_statusVariable,
			to_release_session_list ? to_release_session_listList : NULL,
			pcf_reselected_ind ? true : false,
			pcf_reselected_ind ? pcf_reselected_ind->valueint : 0,
			smf_change_info_list ? smf_change_info_listList : NULL,
			analytics_not_used_list ? analytics_not_used_listList : NULL,
			to_release_session_info ? to_release_session_infoList : NULL
			);

	return ue_reg_status_update_req_data_local_var;
end:
	if(to_release_session_listList) {
		list_for_each(to_release_session_listList, node) {
			free(node->data);
		}
		list_free(to_release_session_listList);
		to_release_session_listList = NULL;
	}
	if(smf_change_info_listList) {
		list_for_each(smf_change_info_listList, node) {
			smf_change_info_free(node->data);
		}
		list_free(smf_change_info_listList);
		smf_change_info_listList = NULL;
	}
	if(analytics_not_used_listList) {
		list_for_each(analytics_not_used_listList, node) {
			free(node->data);
		}
		list_free(analytics_not_used_listList);
		analytics_not_used_listList = NULL;
	}
	if(to_release_session_infoList) {
		list_for_each(to_release_session_infoList, node) {
			release_session_info_free(node->data);
		}
		list_free(to_release_session_infoList);
		to_release_session_infoList = NULL;
	}
	return NULL;
}

ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_copy(
	ue_reg_status_update_req_data_t *dst,
	ue_reg_status_update_req_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_reg_status_update_req_data_convertToJSON(src);
	if(!item) {
		printf("ue_reg_status_update_req_data_convertToJSON() failed");
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

	ue_reg_status_update_req_data_free(dst);
	dst = ue_reg_status_update_req_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
