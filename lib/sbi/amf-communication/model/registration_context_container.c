#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "registration_context_container.h"

registration_context_container_t *registration_context_container_create(
	ue_context_t *ue_context, char *local_time_zone, access_type_e an_type,
	int an_n2_ap_id, global_ran_node_id_t *ran_node_id,
	char *initial_amf_name, user_location_t *user_location,
	char *rrc_est_cause, bool is_ue_context_request, int ue_context_request,
	bool is_initial_amf_n2_ap_id, int initial_amf_n2_ap_id,
	char *an_n2_ipv4_addr, ipv6_addr_t *an_n2_ipv6_addr,
	allowed_nssai_t *allowed_nssai, list_t *configured_nssai,
	list_t *rejected_nssai_in_plmn, list_t *rejected_nssai_in_ta,
	plmn_id_t *selected_plmn_id, bool is_iab_node_ind, int iab_node_ind,
	bool is_mbsr_node_ind, int mbsr_node_ind,
	ce_mode_b_ind_t *ce_mode_b_ind, lte_m_ind_t *lte_m_ind,
	bool is_authenticated_ind, int authenticated_ind,
	npn_access_info_t *npn_access_info) {
	registration_context_container_t *
	        registration_context_container_local_var =
		malloc(sizeof(registration_context_container_t));

	registration_context_container_local_var->ue_context = ue_context;
	registration_context_container_local_var->local_time_zone =
		local_time_zone;
	registration_context_container_local_var->an_type = an_type;
	registration_context_container_local_var->an_n2_ap_id = an_n2_ap_id;
	registration_context_container_local_var->ran_node_id = ran_node_id;
	registration_context_container_local_var->initial_amf_name =
		initial_amf_name;
	registration_context_container_local_var->user_location = user_location;
	registration_context_container_local_var->rrc_est_cause = rrc_est_cause;
	registration_context_container_local_var->is_ue_context_request =
		is_ue_context_request;
	registration_context_container_local_var->ue_context_request =
		ue_context_request;
	registration_context_container_local_var->is_initial_amf_n2_ap_id =
		is_initial_amf_n2_ap_id;
	registration_context_container_local_var->initial_amf_n2_ap_id =
		initial_amf_n2_ap_id;
	registration_context_container_local_var->an_n2_ipv4_addr =
		an_n2_ipv4_addr;
	registration_context_container_local_var->an_n2_ipv6_addr =
		an_n2_ipv6_addr;
	registration_context_container_local_var->allowed_nssai = allowed_nssai;
	registration_context_container_local_var->configured_nssai =
		configured_nssai;
	registration_context_container_local_var->rejected_nssai_in_plmn =
		rejected_nssai_in_plmn;
	registration_context_container_local_var->rejected_nssai_in_ta =
		rejected_nssai_in_ta;
	registration_context_container_local_var->selected_plmn_id =
		selected_plmn_id;
	registration_context_container_local_var->is_iab_node_ind =
		is_iab_node_ind;
	registration_context_container_local_var->iab_node_ind = iab_node_ind;
	registration_context_container_local_var->is_mbsr_node_ind =
		is_mbsr_node_ind;
	registration_context_container_local_var->mbsr_node_ind = mbsr_node_ind;
	registration_context_container_local_var->ce_mode_b_ind = ce_mode_b_ind;
	registration_context_container_local_var->lte_m_ind = lte_m_ind;
	registration_context_container_local_var->is_authenticated_ind =
		is_authenticated_ind;
	registration_context_container_local_var->authenticated_ind =
		authenticated_ind;
	registration_context_container_local_var->npn_access_info =
		npn_access_info;

	return registration_context_container_local_var;
}

void registration_context_container_free(
	registration_context_container_t *registration_context_container) {
	lnode_t *node = NULL;

	if(NULL == registration_context_container) {
		return;
	}
	if(registration_context_container->ue_context) {
		ue_context_free(registration_context_container->ue_context);
		registration_context_container->ue_context = NULL;
	}
	if(registration_context_container->local_time_zone) {
		free(registration_context_container->local_time_zone);
		registration_context_container->local_time_zone = NULL;
	}
	if(registration_context_container->ran_node_id) {
		global_ran_node_id_free(
			registration_context_container->ran_node_id);
		registration_context_container->ran_node_id = NULL;
	}
	if(registration_context_container->initial_amf_name) {
		free(registration_context_container->initial_amf_name);
		registration_context_container->initial_amf_name = NULL;
	}
	if(registration_context_container->user_location) {
		user_location_free(registration_context_container->user_location);
		registration_context_container->user_location = NULL;
	}
	if(registration_context_container->rrc_est_cause) {
		free(registration_context_container->rrc_est_cause);
		registration_context_container->rrc_est_cause = NULL;
	}
	if(registration_context_container->an_n2_ipv4_addr) {
		free(registration_context_container->an_n2_ipv4_addr);
		registration_context_container->an_n2_ipv4_addr = NULL;
	}
	if(registration_context_container->an_n2_ipv6_addr) {
		ipv6_addr_free(registration_context_container->an_n2_ipv6_addr);
		registration_context_container->an_n2_ipv6_addr = NULL;
	}
	if(registration_context_container->allowed_nssai) {
		allowed_nssai_free(registration_context_container->allowed_nssai);
		registration_context_container->allowed_nssai = NULL;
	}
	if(registration_context_container->configured_nssai) {
		list_for_each(registration_context_container->configured_nssai,
		              node) {
			configured_snssai_free(node->data);
		}
		list_free(registration_context_container->configured_nssai);
		registration_context_container->configured_nssai = NULL;
	}
	if(registration_context_container->rejected_nssai_in_plmn) {
		list_for_each(
			registration_context_container->rejected_nssai_in_plmn,
			node) {
			snssai_free(node->data);
		}
		list_free(registration_context_container->rejected_nssai_in_plmn);
		registration_context_container->rejected_nssai_in_plmn = NULL;
	}
	if(registration_context_container->rejected_nssai_in_ta) {
		list_for_each(
			registration_context_container->rejected_nssai_in_ta,
			node) {
			snssai_free(node->data);
		}
		list_free(registration_context_container->rejected_nssai_in_ta);
		registration_context_container->rejected_nssai_in_ta = NULL;
	}
	if(registration_context_container->selected_plmn_id) {
		plmn_id_free(registration_context_container->selected_plmn_id);
		registration_context_container->selected_plmn_id = NULL;
	}
	if(registration_context_container->ce_mode_b_ind) {
		ce_mode_b_ind_free(registration_context_container->ce_mode_b_ind);
		registration_context_container->ce_mode_b_ind = NULL;
	}
	if(registration_context_container->lte_m_ind) {
		lte_m_ind_free(registration_context_container->lte_m_ind);
		registration_context_container->lte_m_ind = NULL;
	}
	if(registration_context_container->npn_access_info) {
		npn_access_info_free(
			registration_context_container->npn_access_info);
		registration_context_container->npn_access_info = NULL;
	}
	free(registration_context_container);
}

cJSON *registration_context_container_convertToJSON(
	registration_context_container_t *registration_context_container) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(registration_context_container == NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [RegistrationContextContainer]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!registration_context_container->ue_context) {
		printf(
			"registration_context_container_convertToJSON() failed [ue_context]");
		return NULL;
	}
	cJSON *ue_context_local_JSON = ue_context_convertToJSON(
		registration_context_container->ue_context);
	if(ue_context_local_JSON == NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [ue_context]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ueContext", ue_context_local_JSON);
	if(item->child == NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [ue_context]");
		goto end;
	}

	if(registration_context_container->local_time_zone) {
		if(cJSON_AddStringToObject(item, "localTimeZone",
		                           registration_context_container->
		                           local_time_zone) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [local_time_zone]");
			goto end;
		}
	}

	if(registration_context_container->an_type == access_type_NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [an_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "anType",
	                           access_type_ToString(
					   registration_context_container->
					   an_type)) ==
	   NULL)
	{
		printf(
			"registration_context_container_convertToJSON() failed [an_type]");
		goto end;
	}

	if(cJSON_AddNumberToObject(item, "anN2ApId",
	                           registration_context_container->an_n2_ap_id)
	   == NULL)
	{
		printf(
			"registration_context_container_convertToJSON() failed [an_n2_ap_id]");
		goto end;
	}

	if(!registration_context_container->ran_node_id) {
		printf(
			"registration_context_container_convertToJSON() failed [ran_node_id]");
		return NULL;
	}
	cJSON *ran_node_id_local_JSON = global_ran_node_id_convertToJSON(
		registration_context_container->ran_node_id);
	if(ran_node_id_local_JSON == NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [ran_node_id]");
		goto end;
	}
	cJSON_AddItemToObject(item, "ranNodeId", ran_node_id_local_JSON);
	if(item->child == NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [ran_node_id]");
		goto end;
	}

	if(!registration_context_container->initial_amf_name) {
		printf(
			"registration_context_container_convertToJSON() failed [initial_amf_name]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "initialAmfName",
	                           registration_context_container->
	                           initial_amf_name) == NULL)
	{
		printf(
			"registration_context_container_convertToJSON() failed [initial_amf_name]");
		goto end;
	}

	if(!registration_context_container->user_location) {
		printf(
			"registration_context_container_convertToJSON() failed [user_location]");
		return NULL;
	}
	cJSON *user_location_local_JSON = user_location_convertToJSON(
		registration_context_container->user_location);
	if(user_location_local_JSON == NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [user_location]");
		goto end;
	}
	cJSON_AddItemToObject(item, "userLocation", user_location_local_JSON);
	if(item->child == NULL) {
		printf(
			"registration_context_container_convertToJSON() failed [user_location]");
		goto end;
	}

	if(registration_context_container->rrc_est_cause) {
		if(cJSON_AddStringToObject(item, "rrcEstCause",
		                           registration_context_container->
		                           rrc_est_cause) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [rrc_est_cause]");
			goto end;
		}
	}

	if(registration_context_container->is_ue_context_request) {
		if(cJSON_AddBoolToObject(item, "ueContextRequest",
		                         registration_context_container->
		                         ue_context_request) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [ue_context_request]");
			goto end;
		}
	}

	if(registration_context_container->is_initial_amf_n2_ap_id) {
		if(cJSON_AddNumberToObject(item, "initialAmfN2ApId",
		                           registration_context_container->
		                           initial_amf_n2_ap_id) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [initial_amf_n2_ap_id]");
			goto end;
		}
	}

	if(registration_context_container->an_n2_ipv4_addr) {
		if(cJSON_AddStringToObject(item, "anN2IPv4Addr",
		                           registration_context_container->
		                           an_n2_ipv4_addr) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [an_n2_ipv4_addr]");
			goto end;
		}
	}

	if(registration_context_container->an_n2_ipv6_addr) {
		cJSON *an_n2_ipv6_addr_local_JSON = ipv6_addr_convertToJSON(
			registration_context_container->an_n2_ipv6_addr);
		if(an_n2_ipv6_addr_local_JSON == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [an_n2_ipv6_addr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "anN2IPv6Addr",
		                      an_n2_ipv6_addr_local_JSON);
		if(item->child == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [an_n2_ipv6_addr]");
			goto end;
		}
	}

	if(registration_context_container->allowed_nssai) {
		cJSON *allowed_nssai_local_JSON = allowed_nssai_convertToJSON(
			registration_context_container->allowed_nssai);
		if(allowed_nssai_local_JSON == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [allowed_nssai]");
			goto end;
		}
		cJSON_AddItemToObject(item, "allowedNssai",
		                      allowed_nssai_local_JSON);
		if(item->child == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [allowed_nssai]");
			goto end;
		}
	}

	if(registration_context_container->configured_nssai) {
		cJSON *configured_nssaiList = cJSON_AddArrayToObject(item,
		                                                     "configuredNssai");
		if(configured_nssaiList == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [configured_nssai]");
			goto end;
		}
		list_for_each(registration_context_container->configured_nssai,
		              node) {
			cJSON *itemLocal = configured_snssai_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"registration_context_container_convertToJSON() failed [configured_nssai]");
				goto end;
			}
			cJSON_AddItemToArray(configured_nssaiList, itemLocal);
		}
	}

	if(registration_context_container->rejected_nssai_in_plmn) {
		cJSON *rejected_nssai_in_plmnList = cJSON_AddArrayToObject(item,
		                                                           "rejectedNssaiInPlmn");
		if(rejected_nssai_in_plmnList == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [rejected_nssai_in_plmn]");
			goto end;
		}
		list_for_each(
			registration_context_container->rejected_nssai_in_plmn,
			node) {
			cJSON *itemLocal = snssai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"registration_context_container_convertToJSON() failed [rejected_nssai_in_plmn]");
				goto end;
			}
			cJSON_AddItemToArray(rejected_nssai_in_plmnList,
			                     itemLocal);
		}
	}

	if(registration_context_container->rejected_nssai_in_ta) {
		cJSON *rejected_nssai_in_taList = cJSON_AddArrayToObject(item,
		                                                         "rejectedNssaiInTa");
		if(rejected_nssai_in_taList == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [rejected_nssai_in_ta]");
			goto end;
		}
		list_for_each(
			registration_context_container->rejected_nssai_in_ta,
			node) {
			cJSON *itemLocal = snssai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"registration_context_container_convertToJSON() failed [rejected_nssai_in_ta]");
				goto end;
			}
			cJSON_AddItemToArray(rejected_nssai_in_taList,
			                     itemLocal);
		}
	}

	if(registration_context_container->selected_plmn_id) {
		cJSON *selected_plmn_id_local_JSON = plmn_id_convertToJSON(
			registration_context_container->selected_plmn_id);
		if(selected_plmn_id_local_JSON == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [selected_plmn_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "selectedPlmnId",
		                      selected_plmn_id_local_JSON);
		if(item->child == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [selected_plmn_id]");
			goto end;
		}
	}

	if(registration_context_container->is_iab_node_ind) {
		if(cJSON_AddBoolToObject(item, "iabNodeInd",
		                         registration_context_container->
		                         iab_node_ind) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [iab_node_ind]");
			goto end;
		}
	}

	if(registration_context_container->is_mbsr_node_ind) {
		if(cJSON_AddBoolToObject(item, "mbsrNodeInd",
		                         registration_context_container->
		                         mbsr_node_ind) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [mbsr_node_ind]");
			goto end;
		}
	}

	if(registration_context_container->ce_mode_b_ind) {
		cJSON *ce_mode_b_ind_local_JSON = ce_mode_b_ind_convertToJSON(
			registration_context_container->ce_mode_b_ind);
		if(ce_mode_b_ind_local_JSON == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [ce_mode_b_ind]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ceModeBInd",
		                      ce_mode_b_ind_local_JSON);
		if(item->child == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [ce_mode_b_ind]");
			goto end;
		}
	}

	if(registration_context_container->lte_m_ind) {
		cJSON *lte_m_ind_local_JSON = lte_m_ind_convertToJSON(
			registration_context_container->lte_m_ind);
		if(lte_m_ind_local_JSON == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [lte_m_ind]");
			goto end;
		}
		cJSON_AddItemToObject(item, "lteMInd", lte_m_ind_local_JSON);
		if(item->child == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [lte_m_ind]");
			goto end;
		}
	}

	if(registration_context_container->is_authenticated_ind) {
		if(cJSON_AddBoolToObject(item, "authenticatedInd",
		                         registration_context_container->
		                         authenticated_ind) == NULL)
		{
			printf(
				"registration_context_container_convertToJSON() failed [authenticated_ind]");
			goto end;
		}
	}

	if(registration_context_container->npn_access_info) {
		cJSON *npn_access_info_local_JSON =
			npn_access_info_convertToJSON(
				registration_context_container->npn_access_info);
		if(npn_access_info_local_JSON == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [npn_access_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "npnAccessInfo",
		                      npn_access_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"registration_context_container_convertToJSON() failed [npn_access_info]");
			goto end;
		}
	}

end:
	return item;
}

registration_context_container_t *registration_context_container_parseFromJSON(
	cJSON *registration_context_containerJSON) {
	registration_context_container_t *
	        registration_context_container_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *ue_context = NULL;
	ue_context_t *ue_context_local_nonprim = NULL;
	cJSON *local_time_zone = NULL;
	cJSON *an_type = NULL;
	access_type_e an_typeVariable = 0;
	cJSON *an_n2_ap_id = NULL;
	cJSON *ran_node_id = NULL;
	global_ran_node_id_t *ran_node_id_local_nonprim = NULL;
	cJSON *initial_amf_name = NULL;
	cJSON *user_location = NULL;
	user_location_t *user_location_local_nonprim = NULL;
	cJSON *rrc_est_cause = NULL;
	cJSON *ue_context_request = NULL;
	cJSON *initial_amf_n2_ap_id = NULL;
	cJSON *an_n2_ipv4_addr = NULL;
	cJSON *an_n2_ipv6_addr = NULL;
	ipv6_addr_t *an_n2_ipv6_addr_local_nonprim = NULL;
	cJSON *allowed_nssai = NULL;
	allowed_nssai_t *allowed_nssai_local_nonprim = NULL;
	cJSON *configured_nssai = NULL;
	list_t *configured_nssaiList = NULL;
	cJSON *rejected_nssai_in_plmn = NULL;
	list_t *rejected_nssai_in_plmnList = NULL;
	cJSON *rejected_nssai_in_ta = NULL;
	list_t *rejected_nssai_in_taList = NULL;
	cJSON *selected_plmn_id = NULL;
	plmn_id_t *selected_plmn_id_local_nonprim = NULL;
	cJSON *iab_node_ind = NULL;
	cJSON *mbsr_node_ind = NULL;
	cJSON *ce_mode_b_ind = NULL;
	ce_mode_b_ind_t *ce_mode_b_ind_local_nonprim = NULL;
	cJSON *lte_m_ind = NULL;
	lte_m_ind_t *lte_m_ind_local_nonprim = NULL;
	cJSON *authenticated_ind = NULL;
	cJSON *npn_access_info = NULL;
	npn_access_info_t *npn_access_info_local_nonprim = NULL;
	ue_context = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "ueContext");
	if(!ue_context) {
		printf(
			"registration_context_container_parseFromJSON() failed [ue_context]");
		goto end;
	}
	ue_context_local_nonprim = ue_context_parseFromJSON(ue_context);
	if(!ue_context_local_nonprim) {
		printf("ue_context_parseFromJSON failed [ue_context]");
		goto end;
	}

	local_time_zone = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "localTimeZone");
	if(local_time_zone) {
		if(!cJSON_IsString(local_time_zone) &&
		   !cJSON_IsNull(local_time_zone))
		{
			printf(
				"registration_context_container_parseFromJSON() failed [local_time_zone]");
			goto end;
		}
	}

	an_type = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "anType");
	if(!an_type) {
		printf(
			"registration_context_container_parseFromJSON() failed [an_type]");
		goto end;
	}
	if(!cJSON_IsString(an_type)) {
		printf(
			"registration_context_container_parseFromJSON() failed [an_type]");
		goto end;
	}
	an_typeVariable = access_type_FromString(an_type->valuestring);

	an_n2_ap_id = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "anN2ApId");
	if(!an_n2_ap_id) {
		printf(
			"registration_context_container_parseFromJSON() failed [an_n2_ap_id]");
		goto end;
	}
	if(!cJSON_IsNumber(an_n2_ap_id)) {
		printf(
			"registration_context_container_parseFromJSON() failed [an_n2_ap_id]");
		goto end;
	}

	ran_node_id = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "ranNodeId");
	if(!ran_node_id) {
		printf(
			"registration_context_container_parseFromJSON() failed [ran_node_id]");
		goto end;
	}
	ran_node_id_local_nonprim =
		global_ran_node_id_parseFromJSON(ran_node_id);
	if(!ran_node_id_local_nonprim) {
		printf("global_ran_node_id_parseFromJSON failed [ran_node_id]");
		goto end;
	}

	initial_amf_name = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "initialAmfName");
	if(!initial_amf_name) {
		printf(
			"registration_context_container_parseFromJSON() failed [initial_amf_name]");
		goto end;
	}
	if(!cJSON_IsString(initial_amf_name)) {
		printf(
			"registration_context_container_parseFromJSON() failed [initial_amf_name]");
		goto end;
	}

	user_location = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "userLocation");
	if(!user_location) {
		printf(
			"registration_context_container_parseFromJSON() failed [user_location]");
		goto end;
	}
	user_location_local_nonprim =
		user_location_parseFromJSON(user_location);
	if(!user_location_local_nonprim) {
		printf("user_location_parseFromJSON failed [user_location]");
		goto end;
	}

	rrc_est_cause = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "rrcEstCause");
	if(rrc_est_cause) {
		if(!cJSON_IsString(rrc_est_cause) &&
		   !cJSON_IsNull(rrc_est_cause))
		{
			printf(
				"registration_context_container_parseFromJSON() failed [rrc_est_cause]");
			goto end;
		}
	}

	ue_context_request = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "ueContextRequest");
	if(ue_context_request) {
		if(!cJSON_IsBool(ue_context_request)) {
			printf(
				"registration_context_container_parseFromJSON() failed [ue_context_request]");
			goto end;
		}
	}

	initial_amf_n2_ap_id = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "initialAmfN2ApId");
	if(initial_amf_n2_ap_id) {
		if(!cJSON_IsNumber(initial_amf_n2_ap_id)) {
			printf(
				"registration_context_container_parseFromJSON() failed [initial_amf_n2_ap_id]");
			goto end;
		}
	}

	an_n2_ipv4_addr = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "anN2IPv4Addr");
	if(an_n2_ipv4_addr) {
		if(!cJSON_IsString(an_n2_ipv4_addr) &&
		   !cJSON_IsNull(an_n2_ipv4_addr))
		{
			printf(
				"registration_context_container_parseFromJSON() failed [an_n2_ipv4_addr]");
			goto end;
		}
	}

	an_n2_ipv6_addr = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "anN2IPv6Addr");
	if(an_n2_ipv6_addr) {
		an_n2_ipv6_addr_local_nonprim = ipv6_addr_parseFromJSON(
			an_n2_ipv6_addr);
		if(!an_n2_ipv6_addr_local_nonprim) {
			printf(
				"ipv6_addr_parseFromJSON failed [an_n2_ipv6_addr]");
			goto end;
		}
	}

	allowed_nssai = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "allowedNssai");
	if(allowed_nssai) {
		allowed_nssai_local_nonprim = allowed_nssai_parseFromJSON(
			allowed_nssai);
		if(!allowed_nssai_local_nonprim) {
			printf(
				"allowed_nssai_parseFromJSON failed [allowed_nssai]");
			goto end;
		}
	}

	configured_nssai = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "configuredNssai");
	if(configured_nssai) {
		cJSON *configured_nssai_local = NULL;
		if(!cJSON_IsArray(configured_nssai)) {
			printf(
				"registration_context_container_parseFromJSON() failed [configured_nssai]");
			goto end;
		}

		configured_nssaiList = list_create();

		cJSON_ArrayForEach(configured_nssai_local, configured_nssai) {
			if(!cJSON_IsObject(configured_nssai_local)) {
				printf(
					"registration_context_container_parseFromJSON() failed [configured_nssai]");
				goto end;
			}
			configured_snssai_t *configured_nssaiItem =
				configured_snssai_parseFromJSON(
					configured_nssai_local);
			if(!configured_nssaiItem) {
				printf("No configured_nssaiItem");
				goto end;
			}
			list_add(configured_nssaiList, configured_nssaiItem);
		}
	}

	rejected_nssai_in_plmn = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "rejectedNssaiInPlmn");
	if(rejected_nssai_in_plmn) {
		cJSON *rejected_nssai_in_plmn_local = NULL;
		if(!cJSON_IsArray(rejected_nssai_in_plmn)) {
			printf(
				"registration_context_container_parseFromJSON() failed [rejected_nssai_in_plmn]");
			goto end;
		}

		rejected_nssai_in_plmnList = list_create();

		cJSON_ArrayForEach(rejected_nssai_in_plmn_local,
		                   rejected_nssai_in_plmn) {
			if(!cJSON_IsObject(rejected_nssai_in_plmn_local)) {
				printf(
					"registration_context_container_parseFromJSON() failed [rejected_nssai_in_plmn]");
				goto end;
			}
			snssai_t *rejected_nssai_in_plmnItem =
				snssai_parseFromJSON(
					rejected_nssai_in_plmn_local);
			if(!rejected_nssai_in_plmnItem) {
				printf("No rejected_nssai_in_plmnItem");
				goto end;
			}
			list_add(rejected_nssai_in_plmnList,
			         rejected_nssai_in_plmnItem);
		}
	}

	rejected_nssai_in_ta = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "rejectedNssaiInTa");
	if(rejected_nssai_in_ta) {
		cJSON *rejected_nssai_in_ta_local = NULL;
		if(!cJSON_IsArray(rejected_nssai_in_ta)) {
			printf(
				"registration_context_container_parseFromJSON() failed [rejected_nssai_in_ta]");
			goto end;
		}

		rejected_nssai_in_taList = list_create();

		cJSON_ArrayForEach(rejected_nssai_in_ta_local,
		                   rejected_nssai_in_ta) {
			if(!cJSON_IsObject(rejected_nssai_in_ta_local)) {
				printf(
					"registration_context_container_parseFromJSON() failed [rejected_nssai_in_ta]");
				goto end;
			}
			snssai_t *rejected_nssai_in_taItem =
				snssai_parseFromJSON(rejected_nssai_in_ta_local);
			if(!rejected_nssai_in_taItem) {
				printf("No rejected_nssai_in_taItem");
				goto end;
			}
			list_add(rejected_nssai_in_taList,
			         rejected_nssai_in_taItem);
		}
	}

	selected_plmn_id = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "selectedPlmnId");
	if(selected_plmn_id) {
		selected_plmn_id_local_nonprim = plmn_id_parseFromJSON(
			selected_plmn_id);
		if(!selected_plmn_id_local_nonprim) {
			printf("plmn_id_parseFromJSON failed [selected_plmn_id]");
			goto end;
		}
	}

	iab_node_ind = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "iabNodeInd");
	if(iab_node_ind) {
		if(!cJSON_IsBool(iab_node_ind)) {
			printf(
				"registration_context_container_parseFromJSON() failed [iab_node_ind]");
			goto end;
		}
	}

	mbsr_node_ind = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "mbsrNodeInd");
	if(mbsr_node_ind) {
		if(!cJSON_IsBool(mbsr_node_ind)) {
			printf(
				"registration_context_container_parseFromJSON() failed [mbsr_node_ind]");
			goto end;
		}
	}

	ce_mode_b_ind = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "ceModeBInd");
	if(ce_mode_b_ind) {
		ce_mode_b_ind_local_nonprim = ce_mode_b_ind_parseFromJSON(
			ce_mode_b_ind);
		if(!ce_mode_b_ind_local_nonprim) {
			printf(
				"ce_mode_b_ind_parseFromJSON failed [ce_mode_b_ind]");
			goto end;
		}
	}

	lte_m_ind = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "lteMInd");
	if(lte_m_ind) {
		lte_m_ind_local_nonprim = lte_m_ind_parseFromJSON(lte_m_ind);
		if(!lte_m_ind_local_nonprim) {
			printf("lte_m_ind_parseFromJSON failed [lte_m_ind]");
			goto end;
		}
	}

	authenticated_ind = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "authenticatedInd");
	if(authenticated_ind) {
		if(!cJSON_IsBool(authenticated_ind)) {
			printf(
				"registration_context_container_parseFromJSON() failed [authenticated_ind]");
			goto end;
		}
	}

	npn_access_info = cJSON_GetObjectItemCaseSensitive(
		registration_context_containerJSON, "npnAccessInfo");
	if(npn_access_info) {
		npn_access_info_local_nonprim = npn_access_info_parseFromJSON(
			npn_access_info);
		if(!npn_access_info_local_nonprim) {
			printf(
				"npn_access_info_parseFromJSON failed [npn_access_info]");
			goto end;
		}
	}

	registration_context_container_local_var =
		registration_context_container_create(
			ue_context_local_nonprim,
			local_time_zone &&
			!cJSON_IsNull(local_time_zone) ? strdup(local_time_zone
			                                        ->
			                                        valuestring) : NULL,
			an_typeVariable,

			an_n2_ap_id->valuedouble,
			ran_node_id_local_nonprim,
			strdup(initial_amf_name->valuestring),
			user_location_local_nonprim,
			rrc_est_cause &&
			!cJSON_IsNull(rrc_est_cause) ? strdup(
				rrc_est_cause->valuestring) : NULL,
			ue_context_request ? true : false,
			ue_context_request ? ue_context_request->valueint : 0,
			initial_amf_n2_ap_id ? true : false,
			initial_amf_n2_ap_id ? initial_amf_n2_ap_id->valuedouble : 0,
			an_n2_ipv4_addr &&
			!cJSON_IsNull(an_n2_ipv4_addr) ? strdup(an_n2_ipv4_addr
			                                        ->
			                                        valuestring) : NULL,
			an_n2_ipv6_addr ? an_n2_ipv6_addr_local_nonprim : NULL,
			allowed_nssai ? allowed_nssai_local_nonprim : NULL,
			configured_nssai ? configured_nssaiList : NULL,
			rejected_nssai_in_plmn ? rejected_nssai_in_plmnList : NULL,
			rejected_nssai_in_ta ? rejected_nssai_in_taList : NULL,
			selected_plmn_id ? selected_plmn_id_local_nonprim : NULL,
			iab_node_ind ? true : false,
			iab_node_ind ? iab_node_ind->valueint : 0,
			mbsr_node_ind ? true : false,
			mbsr_node_ind ? mbsr_node_ind->valueint : 0,
			ce_mode_b_ind ? ce_mode_b_ind_local_nonprim : NULL,
			lte_m_ind ? lte_m_ind_local_nonprim : NULL,
			authenticated_ind ? true : false,
			authenticated_ind ? authenticated_ind->valueint : 0,
			npn_access_info ? npn_access_info_local_nonprim : NULL
			);

	return registration_context_container_local_var;
end:
	if(ue_context_local_nonprim) {
		ue_context_free(ue_context_local_nonprim);
		ue_context_local_nonprim = NULL;
	}
	if(ran_node_id_local_nonprim) {
		global_ran_node_id_free(ran_node_id_local_nonprim);
		ran_node_id_local_nonprim = NULL;
	}
	if(user_location_local_nonprim) {
		user_location_free(user_location_local_nonprim);
		user_location_local_nonprim = NULL;
	}
	if(an_n2_ipv6_addr_local_nonprim) {
		ipv6_addr_free(an_n2_ipv6_addr_local_nonprim);
		an_n2_ipv6_addr_local_nonprim = NULL;
	}
	if(allowed_nssai_local_nonprim) {
		allowed_nssai_free(allowed_nssai_local_nonprim);
		allowed_nssai_local_nonprim = NULL;
	}
	if(configured_nssaiList) {
		list_for_each(configured_nssaiList, node) {
			configured_snssai_free(node->data);
		}
		list_free(configured_nssaiList);
		configured_nssaiList = NULL;
	}
	if(rejected_nssai_in_plmnList) {
		list_for_each(rejected_nssai_in_plmnList, node) {
			snssai_free(node->data);
		}
		list_free(rejected_nssai_in_plmnList);
		rejected_nssai_in_plmnList = NULL;
	}
	if(rejected_nssai_in_taList) {
		list_for_each(rejected_nssai_in_taList, node) {
			snssai_free(node->data);
		}
		list_free(rejected_nssai_in_taList);
		rejected_nssai_in_taList = NULL;
	}
	if(selected_plmn_id_local_nonprim) {
		plmn_id_free(selected_plmn_id_local_nonprim);
		selected_plmn_id_local_nonprim = NULL;
	}
	if(ce_mode_b_ind_local_nonprim) {
		ce_mode_b_ind_free(ce_mode_b_ind_local_nonprim);
		ce_mode_b_ind_local_nonprim = NULL;
	}
	if(lte_m_ind_local_nonprim) {
		lte_m_ind_free(lte_m_ind_local_nonprim);
		lte_m_ind_local_nonprim = NULL;
	}
	if(npn_access_info_local_nonprim) {
		npn_access_info_free(npn_access_info_local_nonprim);
		npn_access_info_local_nonprim = NULL;
	}
	return NULL;
}

registration_context_container_t *registration_context_container_copy(
	registration_context_container_t	*dst,
	registration_context_container_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = registration_context_container_convertToJSON(src);
	if(!item) {
		printf("registration_context_container_convertToJSON() failed");
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

	registration_context_container_free(dst);
	dst = registration_context_container_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
