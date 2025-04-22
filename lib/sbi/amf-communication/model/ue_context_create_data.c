#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_context_create_data.h"

ue_context_create_data_t *ue_context_create_data_create(
	ue_context_t *ue_context, ng_ran_target_id_t *target_id,
	n2_info_content_t *source_to_target_data, list_t *pdu_session_list,
	char *n2_notify_uri, n2_info_content_t *ue_radio_capability,
	n2_info_content_t *ue_radio_capability_for_paging,
	ng_ap_cause_t *ngap_cause, char *supported_features,
	plmn_id_nid_t *serving_network) {
	ue_context_create_data_t *ue_context_create_data_local_var = malloc(
		sizeof(ue_context_create_data_t));

	ue_context_create_data_local_var->ue_context = ue_context;
	ue_context_create_data_local_var->target_id = target_id;
	ue_context_create_data_local_var->source_to_target_data =
		source_to_target_data;
	ue_context_create_data_local_var->pdu_session_list = pdu_session_list;
	ue_context_create_data_local_var->n2_notify_uri = n2_notify_uri;
	ue_context_create_data_local_var->ue_radio_capability =
		ue_radio_capability;
	ue_context_create_data_local_var->ue_radio_capability_for_paging =
		ue_radio_capability_for_paging;
	ue_context_create_data_local_var->ngap_cause = ngap_cause;
	ue_context_create_data_local_var->supported_features =
		supported_features;
	ue_context_create_data_local_var->serving_network = serving_network;

	return ue_context_create_data_local_var;
}

void ue_context_create_data_free(
	ue_context_create_data_t *ue_context_create_data) {
	lnode_t *node = NULL;

	if(NULL == ue_context_create_data) {
		return;
	}
	if(ue_context_create_data->ue_context) {
		ue_context_free(ue_context_create_data->ue_context);
		ue_context_create_data->ue_context = NULL;
	}
	if(ue_context_create_data->target_id) {
		ng_ran_target_id_free(ue_context_create_data->target_id);
		ue_context_create_data->target_id = NULL;
	}
	if(ue_context_create_data->source_to_target_data) {
		n2_info_content_free(
			ue_context_create_data->source_to_target_data);
		ue_context_create_data->source_to_target_data = NULL;
	}
	if(ue_context_create_data->pdu_session_list) {
		list_for_each(ue_context_create_data->pdu_session_list, node) {
			n2_sm_information_free(node->data);
		}
		list_free(ue_context_create_data->pdu_session_list);
		ue_context_create_data->pdu_session_list = NULL;
	}
	if(ue_context_create_data->n2_notify_uri) {
		free(ue_context_create_data->n2_notify_uri);
		ue_context_create_data->n2_notify_uri = NULL;
	}
	if(ue_context_create_data->ue_radio_capability) {
		n2_info_content_free(ue_context_create_data->ue_radio_capability);
		ue_context_create_data->ue_radio_capability = NULL;
	}
	if(ue_context_create_data->ue_radio_capability_for_paging) {
		n2_info_content_free(
			ue_context_create_data->ue_radio_capability_for_paging);
		ue_context_create_data->ue_radio_capability_for_paging = NULL;
	}
	if(ue_context_create_data->ngap_cause) {
		ng_ap_cause_free(ue_context_create_data->ngap_cause);
		ue_context_create_data->ngap_cause = NULL;
	}
	if(ue_context_create_data->supported_features) {
		free(ue_context_create_data->supported_features);
		ue_context_create_data->supported_features = NULL;
	}
	if(ue_context_create_data->serving_network) {
		plmn_id_nid_free(ue_context_create_data->serving_network);
		ue_context_create_data->serving_network = NULL;
	}
	free(ue_context_create_data);
}

cJSON *ue_context_create_data_convertToJSON(
	ue_context_create_data_t *ue_context_create_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(ue_context_create_data == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [UeContextCreateData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!ue_context_create_data->ue_context) {
		printf(
			"ue_context_create_data_convertToJSON() failed [ue_context]");
		return NULL;
	}
	cJSON *ue_context_local_JSON = ue_context_convertToJSON(
		ue_context_create_data->ue_context);
	if(ue_context_local_JSON == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [ue_context]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ueContext", ue_context_local_JSON);
	if(item->child == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [ue_context]");
		goto end;
	}

	if(!ue_context_create_data->target_id) {
		printf(
			"ue_context_create_data_convertToJSON() failed [target_id]");
		return NULL;
	}
	cJSON *target_id_local_JSON = ng_ran_target_id_convertToJSON(
		ue_context_create_data->target_id);
	if(target_id_local_JSON == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [target_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "targetId", target_id_local_JSON);
	if(item->child == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [target_id]");
		goto end;
	}

	if(!ue_context_create_data->source_to_target_data) {
		printf(
			"ue_context_create_data_convertToJSON() failed [source_to_target_data]");
		return NULL;
	}
	cJSON *source_to_target_data_local_JSON = n2_info_content_convertToJSON(
		ue_context_create_data->source_to_target_data);
	if(source_to_target_data_local_JSON == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [source_to_target_data]");
		goto end;
	}
	cJSON_AddItemToObject(item, "sourceToTargetData",
	                      source_to_target_data_local_JSON);
	if(item->child == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [source_to_target_data]");
		goto end;
	}

	if(!ue_context_create_data->pdu_session_list) {
		printf(
			"ue_context_create_data_convertToJSON() failed [pdu_session_list]");
		return NULL;
	}
	cJSON *pdu_session_listList = cJSON_AddArrayToObject(item,
	                                                     "pduSessionList");
	if(pdu_session_listList == NULL) {
		printf(
			"ue_context_create_data_convertToJSON() failed [pdu_session_list]");
		goto end;
	}
	list_for_each(ue_context_create_data->pdu_session_list, node) {
		cJSON *itemLocal = n2_sm_information_convertToJSON(node->data);
		if(itemLocal == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [pdu_session_list]");
			goto end;
		}
		cJSON_AddItemToArray(pdu_session_listList, itemLocal);
	}

	if(ue_context_create_data->n2_notify_uri) {
		if(cJSON_AddStringToObject(item, "n2NotifyUri",
		                           ue_context_create_data->n2_notify_uri)
		   == NULL)
		{
			printf(
				"ue_context_create_data_convertToJSON() failed [n2_notify_uri]");
			goto end;
		}
	}

	if(ue_context_create_data->ue_radio_capability) {
		cJSON *ue_radio_capability_local_JSON =
			n2_info_content_convertToJSON(
				ue_context_create_data->ue_radio_capability);
		if(ue_radio_capability_local_JSON == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [ue_radio_capability]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueRadioCapability",
		                      ue_radio_capability_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [ue_radio_capability]");
			goto end;
		}
	}

	if(ue_context_create_data->ue_radio_capability_for_paging) {
		cJSON *ue_radio_capability_for_paging_local_JSON =
			n2_info_content_convertToJSON(
				ue_context_create_data->ue_radio_capability_for_paging);
		if(ue_radio_capability_for_paging_local_JSON == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [ue_radio_capability_for_paging]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueRadioCapabilityForPaging",
		                      ue_radio_capability_for_paging_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [ue_radio_capability_for_paging]");
			goto end;
		}
	}

	if(ue_context_create_data->ngap_cause) {
		cJSON *ngap_cause_local_JSON = ng_ap_cause_convertToJSON(
			ue_context_create_data->ngap_cause);
		if(ngap_cause_local_JSON == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [ngap_cause]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ngapCause", ngap_cause_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [ngap_cause]");
			goto end;
		}
	}

	if(ue_context_create_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           ue_context_create_data->
		                           supported_features) == NULL)
		{
			printf(
				"ue_context_create_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(ue_context_create_data->serving_network) {
		cJSON *serving_network_local_JSON = plmn_id_nid_convertToJSON(
			ue_context_create_data->serving_network);
		if(serving_network_local_JSON == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [serving_network]");
			goto end;
		}
		cJSON_AddItemToObject(item, "servingNetwork",
		                      serving_network_local_JSON);
		if(item->child == NULL) {
			printf(
				"ue_context_create_data_convertToJSON() failed [serving_network]");
			goto end;
		}
	}

end:
	return item;
}

ue_context_create_data_t *ue_context_create_data_parseFromJSON(
	cJSON *ue_context_create_dataJSON) {
	ue_context_create_data_t *ue_context_create_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ue_context = NULL;
	ue_context_t *ue_context_local_nonprim = NULL;
	cJSON *target_id = NULL;
	ng_ran_target_id_t *target_id_local_nonprim = NULL;
	cJSON *source_to_target_data = NULL;
	n2_info_content_t *source_to_target_data_local_nonprim = NULL;
	cJSON *pdu_session_list = NULL;
	list_t *pdu_session_listList = NULL;
	cJSON *n2_notify_uri = NULL;
	cJSON *ue_radio_capability = NULL;
	n2_info_content_t *ue_radio_capability_local_nonprim = NULL;
	cJSON *ue_radio_capability_for_paging = NULL;
	n2_info_content_t *ue_radio_capability_for_paging_local_nonprim = NULL;
	cJSON *ngap_cause = NULL;
	ng_ap_cause_t *ngap_cause_local_nonprim = NULL;
	cJSON *supported_features = NULL;
	cJSON *serving_network = NULL;
	plmn_id_nid_t *serving_network_local_nonprim = NULL;
	ue_context = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "ueContext");
	if(!ue_context) {
		printf(
			"ue_context_create_data_parseFromJSON() failed [ue_context]");
		goto end;
	}
	ue_context_local_nonprim = ue_context_parseFromJSON(ue_context);
	if(!ue_context_local_nonprim) {
		printf("ue_context_parseFromJSON failed [ue_context]");
		goto end;
	}

	target_id = cJSON_GetObjectItemCaseSensitive(ue_context_create_dataJSON,
	                                             "targetId");
	if(!target_id) {
		printf(
			"ue_context_create_data_parseFromJSON() failed [target_id]");
		goto end;
	}
	target_id_local_nonprim = ng_ran_target_id_parseFromJSON(target_id);
	if(!target_id_local_nonprim) {
		printf("ng_ran_target_id_parseFromJSON failed [target_id]");
		goto end;
	}

	source_to_target_data = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "sourceToTargetData");
	if(!source_to_target_data) {
		printf(
			"ue_context_create_data_parseFromJSON() failed [source_to_target_data]");
		goto end;
	}
	source_to_target_data_local_nonprim = n2_info_content_parseFromJSON(
		source_to_target_data);
	if(!source_to_target_data_local_nonprim) {
		printf(
			"n2_info_content_parseFromJSON failed [source_to_target_data]");
		goto end;
	}

	pdu_session_list = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "pduSessionList");
	if(!pdu_session_list) {
		printf(
			"ue_context_create_data_parseFromJSON() failed [pdu_session_list]");
		goto end;
	}
	cJSON *pdu_session_list_local = NULL;
	if(!cJSON_IsArray(pdu_session_list)) {
		printf(
			"ue_context_create_data_parseFromJSON() failed [pdu_session_list]");
		goto end;
	}

	pdu_session_listList = list_create();

	cJSON_ArrayForEach(pdu_session_list_local, pdu_session_list) {
		if(!cJSON_IsObject(pdu_session_list_local)) {
			printf(
				"ue_context_create_data_parseFromJSON() failed [pdu_session_list]");
			goto end;
		}
		n2_sm_information_t *pdu_session_listItem =
			n2_sm_information_parseFromJSON(pdu_session_list_local);
		if(!pdu_session_listItem) {
			printf("No pdu_session_listItem");
			goto end;
		}
		list_add(pdu_session_listList, pdu_session_listItem);
	}

	n2_notify_uri = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "n2NotifyUri");
	if(n2_notify_uri) {
		if(!cJSON_IsString(n2_notify_uri) &&
		   !cJSON_IsNull(n2_notify_uri))
		{
			printf(
				"ue_context_create_data_parseFromJSON() failed [n2_notify_uri]");
			goto end;
		}
	}

	ue_radio_capability = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "ueRadioCapability");
	if(ue_radio_capability) {
		ue_radio_capability_local_nonprim =
			n2_info_content_parseFromJSON(ue_radio_capability);
		if(!ue_radio_capability_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [ue_radio_capability]");
			goto end;
		}
	}

	ue_radio_capability_for_paging = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "ueRadioCapabilityForPaging");
	if(ue_radio_capability_for_paging) {
		ue_radio_capability_for_paging_local_nonprim =
			n2_info_content_parseFromJSON(
				ue_radio_capability_for_paging);
		if(!ue_radio_capability_for_paging_local_nonprim) {
			printf(
				"n2_info_content_parseFromJSON failed [ue_radio_capability_for_paging]");
			goto end;
		}
	}

	ngap_cause = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "ngapCause");
	if(ngap_cause) {
		ngap_cause_local_nonprim =
			ng_ap_cause_parseFromJSON(ngap_cause);
		if(!ngap_cause_local_nonprim) {
			printf("ng_ap_cause_parseFromJSON failed [ngap_cause]");
			goto end;
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"ue_context_create_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	serving_network = cJSON_GetObjectItemCaseSensitive(
		ue_context_create_dataJSON, "servingNetwork");
	if(serving_network) {
		serving_network_local_nonprim = plmn_id_nid_parseFromJSON(
			serving_network);
		if(!serving_network_local_nonprim) {
			printf(
				"plmn_id_nid_parseFromJSON failed [serving_network]");
			goto end;
		}
	}

	ue_context_create_data_local_var = ue_context_create_data_create(
		ue_context_local_nonprim,
		target_id_local_nonprim,
		source_to_target_data_local_nonprim,
		pdu_session_listList,
		n2_notify_uri &&
		!cJSON_IsNull(n2_notify_uri) ? strdup(
			n2_notify_uri->valuestring) : NULL,
		ue_radio_capability ? ue_radio_capability_local_nonprim : NULL,
		ue_radio_capability_for_paging ? ue_radio_capability_for_paging_local_nonprim : NULL,
		ngap_cause ? ngap_cause_local_nonprim : NULL,
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL,
		serving_network ? serving_network_local_nonprim : NULL
		);

	return ue_context_create_data_local_var;
end:
	if(ue_context_local_nonprim) {
		ue_context_free(ue_context_local_nonprim);
		ue_context_local_nonprim = NULL;
	}
	if(target_id_local_nonprim) {
		ng_ran_target_id_free(target_id_local_nonprim);
		target_id_local_nonprim = NULL;
	}
	if(source_to_target_data_local_nonprim) {
		n2_info_content_free(source_to_target_data_local_nonprim);
		source_to_target_data_local_nonprim = NULL;
	}
	if(pdu_session_listList) {
		list_for_each(pdu_session_listList, node) {
			n2_sm_information_free(node->data);
		}
		list_free(pdu_session_listList);
		pdu_session_listList = NULL;
	}
	if(ue_radio_capability_local_nonprim) {
		n2_info_content_free(ue_radio_capability_local_nonprim);
		ue_radio_capability_local_nonprim = NULL;
	}
	if(ue_radio_capability_for_paging_local_nonprim) {
		n2_info_content_free(
			ue_radio_capability_for_paging_local_nonprim);
		ue_radio_capability_for_paging_local_nonprim = NULL;
	}
	if(ngap_cause_local_nonprim) {
		ng_ap_cause_free(ngap_cause_local_nonprim);
		ngap_cause_local_nonprim = NULL;
	}
	if(serving_network_local_nonprim) {
		plmn_id_nid_free(serving_network_local_nonprim);
		serving_network_local_nonprim = NULL;
	}
	return NULL;
}

ue_context_create_data_t *ue_context_create_data_copy(
	ue_context_create_data_t *dst, ue_context_create_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = ue_context_create_data_convertToJSON(src);
	if(!item) {
		printf("ue_context_create_data_convertToJSON() failed");
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

	ue_context_create_data_free(dst);
	dst = ue_context_create_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
