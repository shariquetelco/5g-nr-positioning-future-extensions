#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_data.h"

char *ue_unaware_indinput_data_ToString(
	input_data_ue_unaware_ind_e ue_unaware_ind) {
	const char *ue_unaware_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(ue_unaware_indArray) /
	                     sizeof(ue_unaware_indArray[0]);
	if(ue_unaware_ind < sizeofArray) {
		return (char *) ue_unaware_indArray[ue_unaware_ind];
	} else {
		return (char *) "Unknown";
	}
}

input_data_ue_unaware_ind_e ue_unaware_indinput_data_FromString(
	char *ue_unaware_ind) {
	int stringToReturn = 0;
	const char *ue_unaware_indArray[] = { "NULL", "true" };
	size_t sizeofArray = sizeof(ue_unaware_indArray) /
	                     sizeof(ue_unaware_indArray[0]);
	while(stringToReturn < sizeofArray) {
		if(strcmp(ue_unaware_ind,
		          ue_unaware_indArray[stringToReturn]) == 0)
		{
			return stringToReturn;
		}
		stringToReturn++;
	}
	return 0;
}
input_data_t *input_data_create(external_client_type_e external_client_type,
                                char *correlation_id, char *amf_id,
                                location_qo_s_t *location_qo_s,
                                list_t *supported_gad_shapes, char *supi,
                                char *pei, char *gpsi,
                                list_t *requested_ranging_sl_result,
                                list_t *related_ues, ecgi_t *ecgi,
                                ecgi_t *ecgi_on_second_node, ncgi_t *ncgi,
                                ncgi_t *ncgi_on_second_node,
                                lcs_priority_e priority,
                                velocity_requested_e velocity_requested,
                                ue_lcs_capability_t *ue_lcs_cap,
                                bool is_lcs_service_type, int lcs_service_type,
                                ldr_type_e ldr_type, char *hgmlc_call_back_uri,
                                char *lir_gmlc_call_back_uri,
                                char *vgmlc_address, char *ldr_reference,
                                char *lir_reference,
                                periodic_event_info_t *periodic_event_info,
                                area_event_info_t *area_event_info,
                                motion_event_info_t *motion_event_info,
                                list_t *reporting_access_types,
                                ue_connectivity_state_t *ue_connectivity_states,
                                ue_location_service_ind_e ue_location_service_ind, lcs_broadcast_assistance_types_data_t *mo_assistance_data_types, ref_to_binary_data_t *lpp_message, list_t *lpp_message_ext, char *supported_features, char *ue_positioning_cap, tnap_id_t *tnap_id, twap_id_t *twap_id, bool is_ue_country_det_ind, int ue_country_det_ind, char *scheduled_loc_time, bool is_reliable_loc_req, int reliable_loc_req, list_t *evt_rpt_allowed_areas, input_data_ue_unaware_ind_e ue_unaware_ind, bool is_intermediate_location_ind, int intermediate_location_ind, bool is_max_resp_time, int max_resp_time, lp_hap_type_t *lp_hap_type, list_t *ue_up_pos_caps, input_data_reporting_ind_t *reporting_ind, mbsr_info_t *mbsr_info, integrity_requirements_t *integrity_requirements, bool is_up_loc_rep_addr_af_null, up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af, up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria, mapped_location_qo_s_eps_t *mapped_qo_s_eps, additional_ue_info_t *additional_ue_info, bool is_coordinate_id, int coordinate_id,
                                char *ranging_sl_capability) {
	input_data_t *input_data_local_var = malloc(sizeof(input_data_t));

	input_data_local_var->external_client_type = external_client_type;
	input_data_local_var->correlation_id = correlation_id;
	input_data_local_var->amf_id = amf_id;
	input_data_local_var->location_qo_s = location_qo_s;
	input_data_local_var->supported_gad_shapes = supported_gad_shapes;
	input_data_local_var->supi = supi;
	input_data_local_var->pei = pei;
	input_data_local_var->gpsi = gpsi;
	input_data_local_var->requested_ranging_sl_result =
		requested_ranging_sl_result;
	input_data_local_var->related_ues = related_ues;
	input_data_local_var->ecgi = ecgi;
	input_data_local_var->ecgi_on_second_node = ecgi_on_second_node;
	input_data_local_var->ncgi = ncgi;
	input_data_local_var->ncgi_on_second_node = ncgi_on_second_node;
	input_data_local_var->priority = priority;
	input_data_local_var->velocity_requested = velocity_requested;
	input_data_local_var->ue_lcs_cap = ue_lcs_cap;
	input_data_local_var->is_lcs_service_type = is_lcs_service_type;
	input_data_local_var->lcs_service_type = lcs_service_type;
	input_data_local_var->ldr_type = ldr_type;
	input_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
	input_data_local_var->lir_gmlc_call_back_uri = lir_gmlc_call_back_uri;
	input_data_local_var->vgmlc_address = vgmlc_address;
	input_data_local_var->ldr_reference = ldr_reference;
	input_data_local_var->lir_reference = lir_reference;
	input_data_local_var->periodic_event_info = periodic_event_info;
	input_data_local_var->area_event_info = area_event_info;
	input_data_local_var->motion_event_info = motion_event_info;
	input_data_local_var->reporting_access_types = reporting_access_types;
	input_data_local_var->ue_connectivity_states = ue_connectivity_states;
	input_data_local_var->ue_location_service_ind = ue_location_service_ind;
	input_data_local_var->mo_assistance_data_types =
		mo_assistance_data_types;
	input_data_local_var->lpp_message = lpp_message;
	input_data_local_var->lpp_message_ext = lpp_message_ext;
	input_data_local_var->supported_features = supported_features;
	input_data_local_var->ue_positioning_cap = ue_positioning_cap;
	input_data_local_var->tnap_id = tnap_id;
	input_data_local_var->twap_id = twap_id;
	input_data_local_var->is_ue_country_det_ind = is_ue_country_det_ind;
	input_data_local_var->ue_country_det_ind = ue_country_det_ind;
	input_data_local_var->scheduled_loc_time = scheduled_loc_time;
	input_data_local_var->is_reliable_loc_req = is_reliable_loc_req;
	input_data_local_var->reliable_loc_req = reliable_loc_req;
	input_data_local_var->evt_rpt_allowed_areas = evt_rpt_allowed_areas;
	input_data_local_var->ue_unaware_ind = ue_unaware_ind;
	input_data_local_var->is_intermediate_location_ind =
		is_intermediate_location_ind;
	input_data_local_var->intermediate_location_ind =
		intermediate_location_ind;
	input_data_local_var->is_max_resp_time = is_max_resp_time;
	input_data_local_var->max_resp_time = max_resp_time;
	input_data_local_var->lp_hap_type = lp_hap_type;
	input_data_local_var->ue_up_pos_caps = ue_up_pos_caps;
	input_data_local_var->reporting_ind = reporting_ind;
	input_data_local_var->mbsr_info = mbsr_info;
	input_data_local_var->integrity_requirements = integrity_requirements;
	input_data_local_var->is_up_loc_rep_addr_af_null =
		is_up_loc_rep_addr_af_null;
	input_data_local_var->up_loc_rep_addr_af = up_loc_rep_addr_af;
	input_data_local_var->up_cum_evt_rpt_criteria = up_cum_evt_rpt_criteria;
	input_data_local_var->mapped_qo_s_eps = mapped_qo_s_eps;
	input_data_local_var->additional_ue_info = additional_ue_info;
	input_data_local_var->is_coordinate_id = is_coordinate_id;
	input_data_local_var->coordinate_id = coordinate_id;
	input_data_local_var->ranging_sl_capability = ranging_sl_capability;

	return input_data_local_var;
}

void input_data_free(input_data_t *input_data) {
	lnode_t *node = NULL;

	if(NULL == input_data) {
		return;
	}
	if(input_data->correlation_id) {
		free(input_data->correlation_id);
		input_data->correlation_id = NULL;
	}
	if(input_data->amf_id) {
		free(input_data->amf_id);
		input_data->amf_id = NULL;
	}
	if(input_data->location_qo_s) {
		location_qo_s_free(input_data->location_qo_s);
		input_data->location_qo_s = NULL;
	}
	if(input_data->supported_gad_shapes) {
		list_free(input_data->supported_gad_shapes);
		input_data->supported_gad_shapes = NULL;
	}
	if(input_data->supi) {
		free(input_data->supi);
		input_data->supi = NULL;
	}
	if(input_data->pei) {
		free(input_data->pei);
		input_data->pei = NULL;
	}
	if(input_data->gpsi) {
		free(input_data->gpsi);
		input_data->gpsi = NULL;
	}
	if(input_data->requested_ranging_sl_result) {
		list_free(input_data->requested_ranging_sl_result);
		input_data->requested_ranging_sl_result = NULL;
	}
	if(input_data->related_ues) {
		list_for_each(input_data->related_ues, node) {
			related_ue_free(node->data);
		}
		list_free(input_data->related_ues);
		input_data->related_ues = NULL;
	}
	if(input_data->ecgi) {
		ecgi_free(input_data->ecgi);
		input_data->ecgi = NULL;
	}
	if(input_data->ecgi_on_second_node) {
		ecgi_free(input_data->ecgi_on_second_node);
		input_data->ecgi_on_second_node = NULL;
	}
	if(input_data->ncgi) {
		ncgi_free(input_data->ncgi);
		input_data->ncgi = NULL;
	}
	if(input_data->ncgi_on_second_node) {
		ncgi_free(input_data->ncgi_on_second_node);
		input_data->ncgi_on_second_node = NULL;
	}
	if(input_data->ue_lcs_cap) {
		ue_lcs_capability_free(input_data->ue_lcs_cap);
		input_data->ue_lcs_cap = NULL;
	}
	if(input_data->hgmlc_call_back_uri) {
		free(input_data->hgmlc_call_back_uri);
		input_data->hgmlc_call_back_uri = NULL;
	}
	if(input_data->lir_gmlc_call_back_uri) {
		free(input_data->lir_gmlc_call_back_uri);
		input_data->lir_gmlc_call_back_uri = NULL;
	}
	if(input_data->vgmlc_address) {
		free(input_data->vgmlc_address);
		input_data->vgmlc_address = NULL;
	}
	if(input_data->ldr_reference) {
		free(input_data->ldr_reference);
		input_data->ldr_reference = NULL;
	}
	if(input_data->lir_reference) {
		free(input_data->lir_reference);
		input_data->lir_reference = NULL;
	}
	if(input_data->periodic_event_info) {
		periodic_event_info_free(input_data->periodic_event_info);
		input_data->periodic_event_info = NULL;
	}
	if(input_data->area_event_info) {
		area_event_info_free(input_data->area_event_info);
		input_data->area_event_info = NULL;
	}
	if(input_data->motion_event_info) {
		motion_event_info_free(input_data->motion_event_info);
		input_data->motion_event_info = NULL;
	}
	if(input_data->reporting_access_types) {
		list_free(input_data->reporting_access_types);
		input_data->reporting_access_types = NULL;
	}
	if(input_data->ue_connectivity_states) {
		ue_connectivity_state_free(input_data->ue_connectivity_states);
		input_data->ue_connectivity_states = NULL;
	}
	if(input_data->mo_assistance_data_types) {
		lcs_broadcast_assistance_types_data_free(
			input_data->mo_assistance_data_types);
		input_data->mo_assistance_data_types = NULL;
	}
	if(input_data->lpp_message) {
		ref_to_binary_data_free(input_data->lpp_message);
		input_data->lpp_message = NULL;
	}
	if(input_data->lpp_message_ext) {
		list_for_each(input_data->lpp_message_ext, node) {
			ref_to_binary_data_free(node->data);
		}
		list_free(input_data->lpp_message_ext);
		input_data->lpp_message_ext = NULL;
	}
	if(input_data->supported_features) {
		free(input_data->supported_features);
		input_data->supported_features = NULL;
	}
	if(input_data->ue_positioning_cap) {
		free(input_data->ue_positioning_cap);
		input_data->ue_positioning_cap = NULL;
	}
	if(input_data->tnap_id) {
		tnap_id_free(input_data->tnap_id);
		input_data->tnap_id = NULL;
	}
	if(input_data->twap_id) {
		twap_id_free(input_data->twap_id);
		input_data->twap_id = NULL;
	}
	if(input_data->scheduled_loc_time) {
		free(input_data->scheduled_loc_time);
		input_data->scheduled_loc_time = NULL;
	}
	if(input_data->evt_rpt_allowed_areas) {
		list_for_each(input_data->evt_rpt_allowed_areas, node) {
			reporting_area_free(node->data);
		}
		list_free(input_data->evt_rpt_allowed_areas);
		input_data->evt_rpt_allowed_areas = NULL;
	}
	if(input_data->lp_hap_type) {
		lp_hap_type_free(input_data->lp_hap_type);
		input_data->lp_hap_type = NULL;
	}
	if(input_data->ue_up_pos_caps) {
		list_free(input_data->ue_up_pos_caps);
		input_data->ue_up_pos_caps = NULL;
	}
	if(input_data->reporting_ind) {
		input_data_reporting_ind_free(input_data->reporting_ind);
		input_data->reporting_ind = NULL;
	}
	if(input_data->mbsr_info) {
		mbsr_info_free(input_data->mbsr_info);
		input_data->mbsr_info = NULL;
	}
	if(input_data->integrity_requirements) {
		integrity_requirements_free(input_data->integrity_requirements);
		input_data->integrity_requirements = NULL;
	}
	if(input_data->up_loc_rep_addr_af) {
		up_loc_rep_addr_af_rm_free(input_data->up_loc_rep_addr_af);
		input_data->up_loc_rep_addr_af = NULL;
	}
	if(input_data->up_cum_evt_rpt_criteria) {
		up_cum_evt_rpt_criteria_free(input_data->up_cum_evt_rpt_criteria);
		input_data->up_cum_evt_rpt_criteria = NULL;
	}
	if(input_data->mapped_qo_s_eps) {
		mapped_location_qo_s_eps_free(input_data->mapped_qo_s_eps);
		input_data->mapped_qo_s_eps = NULL;
	}
	if(input_data->additional_ue_info) {
		additional_ue_info_free(input_data->additional_ue_info);
		input_data->additional_ue_info = NULL;
	}
	if(input_data->ranging_sl_capability) {
		free(input_data->ranging_sl_capability);
		input_data->ranging_sl_capability = NULL;
	}
	free(input_data);
}

cJSON *input_data_convertToJSON(input_data_t *input_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(input_data == NULL) {
		printf("input_data_convertToJSON() failed [InputData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(input_data->external_client_type != external_client_type_NULL) {
		if(cJSON_AddStringToObject(item, "externalClientType",
		                           external_client_type_ToString(
						   input_data->
						   external_client_type))
		   == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [external_client_type]");
			goto end;
		}
	}

	if(input_data->correlation_id) {
		if(cJSON_AddStringToObject(item, "correlationID",
		                           input_data->correlation_id) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [correlation_id]");
			goto end;
		}
	}

	if(input_data->amf_id) {
		if(cJSON_AddStringToObject(item, "amfId",
		                           input_data->amf_id) == NULL)
		{
			printf("input_data_convertToJSON() failed [amf_id]");
			goto end;
		}
	}

	if(input_data->location_qo_s) {
		cJSON *location_qo_s_local_JSON = location_qo_s_convertToJSON(
			input_data->location_qo_s);
		if(location_qo_s_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [location_qo_s]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationQoS",
		                      location_qo_s_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [location_qo_s]");
			goto end;
		}
	}

	if(input_data->supported_gad_shapes != supported_gad_shapes_NULL) {
		cJSON *supported_gad_shapesList = cJSON_AddArrayToObject(item,
		                                                         "supportedGADShapes");
		if(supported_gad_shapesList == NULL) {
			printf(
				"input_data_convertToJSON() failed [supported_gad_shapes]");
			goto end;
		}
		list_for_each(input_data->supported_gad_shapes, node) {
			if(cJSON_AddStringToObject(supported_gad_shapesList, "",
			                           supported_gad_shapes_ToString((
											 intptr_t)
			                                                         node
			                                                         ->
			                                                         data))
			   ==
			   NULL)
			{
				printf(
					"input_data_convertToJSON() failed [supported_gad_shapes]");
				goto end;
			}
		}
	}

	if(input_data->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           input_data->supi) == NULL)
		{
			printf("input_data_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(input_data->pei) {
		if(cJSON_AddStringToObject(item, "pei",
		                           input_data->pei) == NULL)
		{
			printf("input_data_convertToJSON() failed [pei]");
			goto end;
		}
	}

	if(input_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           input_data->gpsi) == NULL)
		{
			printf("input_data_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(input_data->requested_ranging_sl_result != ranging_sl_result_NULL) {
		cJSON *requested_ranging_sl_resultList = cJSON_AddArrayToObject(
			item, "requestedRangingSlResult");
		if(requested_ranging_sl_resultList == NULL) {
			printf(
				"input_data_convertToJSON() failed [requested_ranging_sl_result]");
			goto end;
		}
		list_for_each(input_data->requested_ranging_sl_result, node) {
			if(cJSON_AddStringToObject(
				   requested_ranging_sl_resultList, "",
				   ranging_sl_result_ToString((intptr_t) node->
				                              data)) ==
			   NULL)
			{
				printf(
					"input_data_convertToJSON() failed [requested_ranging_sl_result]");
				goto end;
			}
		}
	}

	if(input_data->related_ues) {
		cJSON *related_uesList = cJSON_AddArrayToObject(item,
		                                                "relatedUEs");
		if(related_uesList == NULL) {
			printf("input_data_convertToJSON() failed [related_ues]");
			goto end;
		}
		list_for_each(input_data->related_ues, node) {
			cJSON *itemLocal = related_ue_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"input_data_convertToJSON() failed [related_ues]");
				goto end;
			}
			cJSON_AddItemToArray(related_uesList, itemLocal);
		}
	}

	if(input_data->ecgi) {
		cJSON *ecgi_local_JSON = ecgi_convertToJSON(input_data->ecgi);
		if(ecgi_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [ecgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [ecgi]");
			goto end;
		}
	}

	if(input_data->ecgi_on_second_node) {
		cJSON *ecgi_on_second_node_local_JSON = ecgi_convertToJSON(
			input_data->ecgi_on_second_node);
		if(ecgi_on_second_node_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [ecgi_on_second_node]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgiOnSecondNode",
		                      ecgi_on_second_node_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [ecgi_on_second_node]");
			goto end;
		}
	}

	if(input_data->ncgi) {
		cJSON *ncgi_local_JSON = ncgi_convertToJSON(input_data->ncgi);
		if(ncgi_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [ncgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [ncgi]");
			goto end;
		}
	}

	if(input_data->ncgi_on_second_node) {
		cJSON *ncgi_on_second_node_local_JSON = ncgi_convertToJSON(
			input_data->ncgi_on_second_node);
		if(ncgi_on_second_node_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [ncgi_on_second_node]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgiOnSecondNode",
		                      ncgi_on_second_node_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [ncgi_on_second_node]");
			goto end;
		}
	}

	if(input_data->priority != lcs_priority_NULL) {
		if(cJSON_AddStringToObject(item, "priority",
		                           lcs_priority_ToString(input_data->
		                                                 priority)) ==
		   NULL)
		{
			printf("input_data_convertToJSON() failed [priority]");
			goto end;
		}
	}

	if(input_data->velocity_requested != velocity_requested_NULL) {
		if(cJSON_AddStringToObject(item, "velocityRequested",
		                           velocity_requested_ToString(
						   input_data->
						   velocity_requested)) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [velocity_requested]");
			goto end;
		}
	}

	if(input_data->ue_lcs_cap) {
		cJSON *ue_lcs_cap_local_JSON = ue_lcs_capability_convertToJSON(
			input_data->ue_lcs_cap);
		if(ue_lcs_cap_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [ue_lcs_cap]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueLcsCap", ue_lcs_cap_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [ue_lcs_cap]");
			goto end;
		}
	}

	if(input_data->is_lcs_service_type) {
		if(cJSON_AddNumberToObject(item, "lcsServiceType",
		                           input_data->lcs_service_type) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [lcs_service_type]");
			goto end;
		}
	}

	if(input_data->ldr_type != ldr_type_NULL) {
		if(cJSON_AddStringToObject(item, "ldrType",
		                           ldr_type_ToString(input_data->
		                                             ldr_type)) == NULL)
		{
			printf("input_data_convertToJSON() failed [ldr_type]");
			goto end;
		}
	}

	if(input_data->hgmlc_call_back_uri) {
		if(cJSON_AddStringToObject(item, "hgmlcCallBackURI",
		                           input_data->hgmlc_call_back_uri) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [hgmlc_call_back_uri]");
			goto end;
		}
	}

	if(input_data->lir_gmlc_call_back_uri) {
		if(cJSON_AddStringToObject(item, "lirGmlcCallBackUri",
		                           input_data->lir_gmlc_call_back_uri)
		   == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [lir_gmlc_call_back_uri]");
			goto end;
		}
	}

	if(input_data->vgmlc_address) {
		if(cJSON_AddStringToObject(item, "vgmlcAddress",
		                           input_data->vgmlc_address) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [vgmlc_address]");
			goto end;
		}
	}

	if(input_data->ldr_reference) {
		if(cJSON_AddStringToObject(item, "ldrReference",
		                           input_data->ldr_reference) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ldr_reference]");
			goto end;
		}
	}

	if(input_data->lir_reference) {
		if(cJSON_AddStringToObject(item, "lirReference",
		                           input_data->lir_reference) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [lir_reference]");
			goto end;
		}
	}

	if(input_data->periodic_event_info) {
		cJSON *periodic_event_info_local_JSON =
			periodic_event_info_convertToJSON(
				input_data->periodic_event_info);
		if(periodic_event_info_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [periodic_event_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "periodicEventInfo",
		                      periodic_event_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [periodic_event_info]");
			goto end;
		}
	}

	if(input_data->area_event_info) {
		cJSON *area_event_info_local_JSON =
			area_event_info_convertToJSON(
				input_data->area_event_info);
		if(area_event_info_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [area_event_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "areaEventInfo",
		                      area_event_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [area_event_info]");
			goto end;
		}
	}

	if(input_data->motion_event_info) {
		cJSON *motion_event_info_local_JSON =
			motion_event_info_convertToJSON(
				input_data->motion_event_info);
		if(motion_event_info_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [motion_event_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "motionEventInfo",
		                      motion_event_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [motion_event_info]");
			goto end;
		}
	}

	if(input_data->reporting_access_types != reporting_access_type_NULL) {
		cJSON *reporting_access_typesList = cJSON_AddArrayToObject(item,
		                                                           "reportingAccessTypes");
		if(reporting_access_typesList == NULL) {
			printf(
				"input_data_convertToJSON() failed [reporting_access_types]");
			goto end;
		}
		list_for_each(input_data->reporting_access_types, node) {
			if(cJSON_AddStringToObject(reporting_access_typesList,
			                           "",
			                           reporting_access_type_ToString((
											  intptr_t)
			                                                          node
			                                                          ->
			                                                          data))
			   == NULL)
			{
				printf(
					"input_data_convertToJSON() failed [reporting_access_types]");
				goto end;
			}
		}
	}

	if(input_data->ue_connectivity_states) {
		cJSON *ue_connectivity_states_local_JSON =
			ue_connectivity_state_convertToJSON(
				input_data->ue_connectivity_states);
		if(ue_connectivity_states_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [ue_connectivity_states]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueConnectivityStates",
		                      ue_connectivity_states_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [ue_connectivity_states]");
			goto end;
		}
	}

	if(input_data->ue_location_service_ind !=
	   ue_location_service_ind_NULL)
	{
		if(cJSON_AddStringToObject(item, "ueLocationServiceInd",
		                           ue_location_service_ind_ToString(
						   input_data->
						   ue_location_service_ind))
		   == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ue_location_service_ind]");
			goto end;
		}
	}

	if(input_data->mo_assistance_data_types) {
		cJSON *mo_assistance_data_types_local_JSON =
			lcs_broadcast_assistance_types_data_convertToJSON(
				input_data->mo_assistance_data_types);
		if(mo_assistance_data_types_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [mo_assistance_data_types]");
			goto end;
		}
		cJSON_AddItemToObject(item, "moAssistanceDataTypes",
		                      mo_assistance_data_types_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [mo_assistance_data_types]");
			goto end;
		}
	}

	if(input_data->lpp_message) {
		cJSON *lpp_message_local_JSON =
			ref_to_binary_data_convertToJSON(input_data->lpp_message);
		if(lpp_message_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [lpp_message]");
			goto end;
		}
		cJSON_AddItemToObject(item, "lppMessage",
		                      lpp_message_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [lpp_message]");
			goto end;
		}
	}

	if(input_data->lpp_message_ext) {
		cJSON *lpp_message_extList = cJSON_AddArrayToObject(item,
		                                                    "lppMessageExt");
		if(lpp_message_extList == NULL) {
			printf(
				"input_data_convertToJSON() failed [lpp_message_ext]");
			goto end;
		}
		list_for_each(input_data->lpp_message_ext, node) {
			cJSON *itemLocal = ref_to_binary_data_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"input_data_convertToJSON() failed [lpp_message_ext]");
				goto end;
			}
			cJSON_AddItemToArray(lpp_message_extList, itemLocal);
		}
	}

	if(input_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           input_data->supported_features) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(input_data->ue_positioning_cap) {
		if(cJSON_AddStringToObject(item, "uePositioningCap",
		                           input_data->ue_positioning_cap) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ue_positioning_cap]");
			goto end;
		}
	}

	if(input_data->tnap_id) {
		cJSON *tnap_id_local_JSON = tnap_id_convertToJSON(
			input_data->tnap_id);
		if(tnap_id_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [tnap_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "tnapId", tnap_id_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [tnap_id]");
			goto end;
		}
	}

	if(input_data->twap_id) {
		cJSON *twap_id_local_JSON = twap_id_convertToJSON(
			input_data->twap_id);
		if(twap_id_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [twap_id]");
			goto end;
		}
		cJSON_AddItemToObject(item, "twapId", twap_id_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [twap_id]");
			goto end;
		}
	}

	if(input_data->is_ue_country_det_ind) {
		if(cJSON_AddBoolToObject(item, "ueCountryDetInd",
		                         input_data->ue_country_det_ind) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ue_country_det_ind]");
			goto end;
		}
	}

	if(input_data->scheduled_loc_time) {
		if(cJSON_AddStringToObject(item, "scheduledLocTime",
		                           input_data->scheduled_loc_time) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [scheduled_loc_time]");
			goto end;
		}
	}

	if(input_data->is_reliable_loc_req) {
		if(cJSON_AddBoolToObject(item, "reliableLocReq",
		                         input_data->reliable_loc_req) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [reliable_loc_req]");
			goto end;
		}
	}

	if(input_data->evt_rpt_allowed_areas) {
		cJSON *evt_rpt_allowed_areasList = cJSON_AddArrayToObject(item,
		                                                          "evtRptAllowedAreas");
		if(evt_rpt_allowed_areasList == NULL) {
			printf(
				"input_data_convertToJSON() failed [evt_rpt_allowed_areas]");
			goto end;
		}
		list_for_each(input_data->evt_rpt_allowed_areas, node) {
			cJSON *itemLocal = reporting_area_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"input_data_convertToJSON() failed [evt_rpt_allowed_areas]");
				goto end;
			}
			cJSON_AddItemToArray(evt_rpt_allowed_areasList,
			                     itemLocal);
		}
	}

	if(input_data->ue_unaware_ind != input_data_UEUNAWAREIND_NULL) {
		if(cJSON_AddStringToObject(item, "ueUnawareInd",
		                           ue_unaware_indinput_data_ToString(
						   input_data->ue_unaware_ind))
		   == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ue_unaware_ind]");
			goto end;
		}
	}

	if(input_data->is_intermediate_location_ind) {
		if(cJSON_AddBoolToObject(item, "intermediateLocationInd",
		                         input_data->intermediate_location_ind)
		   == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [intermediate_location_ind]");
			goto end;
		}
	}

	if(input_data->is_max_resp_time) {
		if(cJSON_AddNumberToObject(item, "maxRespTime",
		                           input_data->max_resp_time) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [max_resp_time]");
			goto end;
		}
	}

	if(input_data->lp_hap_type) {
		cJSON *lp_hap_type_local_JSON = lp_hap_type_convertToJSON(
			input_data->lp_hap_type);
		if(lp_hap_type_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [lp_hap_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "lpHapType",
		                      lp_hap_type_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [lp_hap_type]");
			goto end;
		}
	}

	if(input_data->ue_up_pos_caps != ue_up_positioning_capabilities_NULL) {
		cJSON *ue_up_pos_capsList = cJSON_AddArrayToObject(item,
		                                                   "ueUpPosCaps");
		if(ue_up_pos_capsList == NULL) {
			printf(
				"input_data_convertToJSON() failed [ue_up_pos_caps]");
			goto end;
		}
		list_for_each(input_data->ue_up_pos_caps, node) {
			if(cJSON_AddStringToObject(ue_up_pos_capsList, "",
			                           ue_up_positioning_capabilities_ToString((
												   intptr_t)
			                                                                   node
			                                                                   ->
			                                                                   data))
			   == NULL)
			{
				printf(
					"input_data_convertToJSON() failed [ue_up_pos_caps]");
				goto end;
			}
		}
	}

	if(input_data->reporting_ind) {
		cJSON *reporting_ind_local_JSON =
			input_data_reporting_ind_convertToJSON(
				input_data->reporting_ind);
		if(reporting_ind_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [reporting_ind]");
			goto end;
		}
		cJSON_AddItemToObject(item, "reportingInd",
		                      reporting_ind_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [reporting_ind]");
			goto end;
		}
	}

	if(input_data->mbsr_info) {
		cJSON *mbsr_info_local_JSON = mbsr_info_convertToJSON(
			input_data->mbsr_info);
		if(mbsr_info_local_JSON == NULL) {
			printf("input_data_convertToJSON() failed [mbsr_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mbsrInfo", mbsr_info_local_JSON);
		if(item->child == NULL) {
			printf("input_data_convertToJSON() failed [mbsr_info]");
			goto end;
		}
	}

	if(input_data->integrity_requirements) {
		cJSON *integrity_requirements_local_JSON =
			integrity_requirements_convertToJSON(
				input_data->integrity_requirements);
		if(integrity_requirements_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [integrity_requirements]");
			goto end;
		}
		cJSON_AddItemToObject(item, "integrityRequirements",
		                      integrity_requirements_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [integrity_requirements]");
			goto end;
		}
	}

	if(input_data->up_loc_rep_addr_af) {
		cJSON *up_loc_rep_addr_af_local_JSON =
			up_loc_rep_addr_af_rm_convertToJSON(
				input_data->up_loc_rep_addr_af);
		if(up_loc_rep_addr_af_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [up_loc_rep_addr_af]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upLocRepAddrAf",
		                      up_loc_rep_addr_af_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [up_loc_rep_addr_af]");
			goto end;
		}
	} else if(input_data->is_up_loc_rep_addr_af_null) {
		if(cJSON_AddNullToObject(item, "upLocRepAddrAf") == NULL) {
			printf(
				"input_data_convertToJSON() failed [up_loc_rep_addr_af]");
			goto end;
		}
	}

	if(input_data->up_cum_evt_rpt_criteria) {
		cJSON *up_cum_evt_rpt_criteria_local_JSON =
			up_cum_evt_rpt_criteria_convertToJSON(
				input_data->up_cum_evt_rpt_criteria);
		if(up_cum_evt_rpt_criteria_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upCumEvtRptCriteria",
		                      up_cum_evt_rpt_criteria_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
	}

	if(input_data->mapped_qo_s_eps) {
		cJSON *mapped_qo_s_eps_local_JSON =
			mapped_location_qo_s_eps_convertToJSON(
				input_data->mapped_qo_s_eps);
		if(mapped_qo_s_eps_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [mapped_qo_s_eps]");
			goto end;
		}
		cJSON_AddItemToObject(item, "mappedQoSEps",
		                      mapped_qo_s_eps_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [mapped_qo_s_eps]");
			goto end;
		}
	}

	if(input_data->additional_ue_info) {
		cJSON *additional_ue_info_local_JSON =
			additional_ue_info_convertToJSON(
				input_data->additional_ue_info);
		if(additional_ue_info_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [additional_ue_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "additionalUeInfo",
		                      additional_ue_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [additional_ue_info]");
			goto end;
		}
	}

	if(input_data->is_coordinate_id) {
		if(cJSON_AddNumberToObject(item, "coordinateID",
		                           input_data->coordinate_id) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [coordinate_id]");
			goto end;
		}
	}

	if(input_data->ranging_sl_capability) {
		if(cJSON_AddStringToObject(item, "rangingSlCapability",
		                           input_data->ranging_sl_capability) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ranging_sl_capability]");
			goto end;
		}
	}

end:
	return item;
}

input_data_t *input_data_parseFromJSON(cJSON *input_dataJSON) {
	input_data_t *input_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *external_client_type = NULL;
	external_client_type_e external_client_typeVariable = 0;
	cJSON *correlation_id = NULL;
	cJSON *amf_id = NULL;
	cJSON *location_qo_s = NULL;
	location_qo_s_t *location_qo_s_local_nonprim = NULL;
	cJSON *supported_gad_shapes = NULL;
	list_t *supported_gad_shapesList = NULL;
	cJSON *supi = NULL;
	cJSON *pei = NULL;
	cJSON *gpsi = NULL;
	cJSON *requested_ranging_sl_result = NULL;
	list_t *requested_ranging_sl_resultList = NULL;
	cJSON *related_ues = NULL;
	list_t *related_uesList = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	cJSON *ecgi_on_second_node = NULL;
	ecgi_t *ecgi_on_second_node_local_nonprim = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	cJSON *ncgi_on_second_node = NULL;
	ncgi_t *ncgi_on_second_node_local_nonprim = NULL;
	cJSON *priority = NULL;
	lcs_priority_e priorityVariable = 0;
	cJSON *velocity_requested = NULL;
	velocity_requested_e velocity_requestedVariable = 0;
	cJSON *ue_lcs_cap = NULL;
	ue_lcs_capability_t *ue_lcs_cap_local_nonprim = NULL;
	cJSON *lcs_service_type = NULL;
	cJSON *ldr_type = NULL;
	ldr_type_e ldr_typeVariable = 0;
	cJSON *hgmlc_call_back_uri = NULL;
	cJSON *lir_gmlc_call_back_uri = NULL;
	cJSON *vgmlc_address = NULL;
	cJSON *ldr_reference = NULL;
	cJSON *lir_reference = NULL;
	cJSON *periodic_event_info = NULL;
	periodic_event_info_t *periodic_event_info_local_nonprim = NULL;
	cJSON *area_event_info = NULL;
	area_event_info_t *area_event_info_local_nonprim = NULL;
	cJSON *motion_event_info = NULL;
	motion_event_info_t *motion_event_info_local_nonprim = NULL;
	cJSON *reporting_access_types = NULL;
	list_t *reporting_access_typesList = NULL;
	cJSON *ue_connectivity_states = NULL;
	ue_connectivity_state_t *ue_connectivity_states_local_nonprim = NULL;
	cJSON *ue_location_service_ind = NULL;
	ue_location_service_ind_e ue_location_service_indVariable = 0;
	cJSON *mo_assistance_data_types = NULL;
	lcs_broadcast_assistance_types_data_t *
	        mo_assistance_data_types_local_nonprim = NULL;
	cJSON *lpp_message = NULL;
	ref_to_binary_data_t *lpp_message_local_nonprim = NULL;
	cJSON *lpp_message_ext = NULL;
	list_t *lpp_message_extList = NULL;
	cJSON *supported_features = NULL;
	cJSON *ue_positioning_cap = NULL;
	cJSON *tnap_id = NULL;
	tnap_id_t *tnap_id_local_nonprim = NULL;
	cJSON *twap_id = NULL;
	twap_id_t *twap_id_local_nonprim = NULL;
	cJSON *ue_country_det_ind = NULL;
	cJSON *scheduled_loc_time = NULL;
	cJSON *reliable_loc_req = NULL;
	cJSON *evt_rpt_allowed_areas = NULL;
	list_t *evt_rpt_allowed_areasList = NULL;
	cJSON *ue_unaware_ind = NULL;
	input_data_ue_unaware_ind_e ue_unaware_indVariable = 0;
	cJSON *intermediate_location_ind = NULL;
	cJSON *max_resp_time = NULL;
	cJSON *lp_hap_type = NULL;
	lp_hap_type_t *lp_hap_type_local_nonprim = NULL;
	cJSON *ue_up_pos_caps = NULL;
	list_t *ue_up_pos_capsList = NULL;
	cJSON *reporting_ind = NULL;
	input_data_reporting_ind_t *reporting_ind_local_nonprim = NULL;
	cJSON *mbsr_info = NULL;
	mbsr_info_t *mbsr_info_local_nonprim = NULL;
	cJSON *integrity_requirements = NULL;
	integrity_requirements_t *integrity_requirements_local_nonprim = NULL;
	cJSON *up_loc_rep_addr_af = NULL;
	up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af_local_nonprim = NULL;
	cJSON *up_cum_evt_rpt_criteria = NULL;
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;
	cJSON *mapped_qo_s_eps = NULL;
	mapped_location_qo_s_eps_t *mapped_qo_s_eps_local_nonprim = NULL;
	cJSON *additional_ue_info = NULL;
	additional_ue_info_t *additional_ue_info_local_nonprim = NULL;
	cJSON *coordinate_id = NULL;
	cJSON *ranging_sl_capability = NULL;
	external_client_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                        "externalClientType");
	if(external_client_type) {
		if(!cJSON_IsString(external_client_type)) {
			printf(
				"input_data_parseFromJSON() failed [external_client_type]");
			goto end;
		}
		external_client_typeVariable = external_client_type_FromString(
			external_client_type->valuestring);
	}

	correlation_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                  "correlationID");
	if(correlation_id) {
		if(!cJSON_IsString(correlation_id) &&
		   !cJSON_IsNull(correlation_id))
		{
			printf(
				"input_data_parseFromJSON() failed [correlation_id]");
			goto end;
		}
	}

	amf_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "amfId");
	if(amf_id) {
		if(!cJSON_IsString(amf_id) &&
		   !cJSON_IsNull(amf_id))
		{
			printf("input_data_parseFromJSON() failed [amf_id]");
			goto end;
		}
	}

	location_qo_s = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "locationQoS");
	if(location_qo_s) {
		location_qo_s_local_nonprim = location_qo_s_parseFromJSON(
			location_qo_s);
		if(!location_qo_s_local_nonprim) {
			printf(
				"location_qo_s_parseFromJSON failed [location_qo_s]");
			goto end;
		}
	}

	supported_gad_shapes = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                        "supportedGADShapes");
	if(supported_gad_shapes) {
		cJSON *supported_gad_shapes_local = NULL;
		if(!cJSON_IsArray(supported_gad_shapes)) {
			printf(
				"input_data_parseFromJSON() failed [supported_gad_shapes]");
			goto end;
		}

		supported_gad_shapesList = list_create();

		cJSON_ArrayForEach(supported_gad_shapes_local,
		                   supported_gad_shapes) {
			supported_gad_shapes_e localEnum =
				supported_gad_shapes_NULL;
			if(!cJSON_IsString(supported_gad_shapes_local)) {
				printf(
					"input_data_parseFromJSON() failed [supported_gad_shapes]");
				goto end;
			}
			localEnum = supported_gad_shapes_FromString(
				supported_gad_shapes_local->valuestring);
			if(!localEnum) {
				printf(
					"Enum value \"%s\" for field \"supported_gad_shapes\" is not supported. Ignoring it ...",
					supported_gad_shapes_local->valuestring);
			} else {
				list_add(supported_gad_shapesList,
				         (void *) localEnum);
			}
		}
		if(supported_gad_shapesList->count == 0) {
			printf(
				"input_data_parseFromJSON() failed: Expected supported_gad_shapesList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("input_data_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	pei = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "pei");
	if(pei) {
		if(!cJSON_IsString(pei) &&
		   !cJSON_IsNull(pei))
		{
			printf("input_data_parseFromJSON() failed [pei]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("input_data_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	requested_ranging_sl_result = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "requestedRangingSlResult");
	if(requested_ranging_sl_result) {
		cJSON *requested_ranging_sl_result_local = NULL;
		if(!cJSON_IsArray(requested_ranging_sl_result)) {
			printf(
				"input_data_parseFromJSON() failed [requested_ranging_sl_result]");
			goto end;
		}

		requested_ranging_sl_resultList = list_create();

		cJSON_ArrayForEach(requested_ranging_sl_result_local,
		                   requested_ranging_sl_result) {
			ranging_sl_result_e localEnum = ranging_sl_result_NULL;
			if(!cJSON_IsString(requested_ranging_sl_result_local)) {
				printf(
					"input_data_parseFromJSON() failed [requested_ranging_sl_result]");
				goto end;
			}
			localEnum = ranging_sl_result_FromString(
				requested_ranging_sl_result_local->valuestring);
			if(!localEnum) {
				printf(
					"Enum value \"%s\" for field \"requested_ranging_sl_result\" is not supported. Ignoring it ...",
					requested_ranging_sl_result_local->valuestring);
			} else {
				list_add(requested_ranging_sl_resultList,
				         (void *) localEnum);
			}
		}
		if(requested_ranging_sl_resultList->count == 0) {
			printf(
				"input_data_parseFromJSON() failed: Expected requested_ranging_sl_resultList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	related_ues = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                               "relatedUEs");
	if(related_ues) {
		cJSON *related_ues_local = NULL;
		if(!cJSON_IsArray(related_ues)) {
			printf("input_data_parseFromJSON() failed [related_ues]");
			goto end;
		}

		related_uesList = list_create();

		cJSON_ArrayForEach(related_ues_local, related_ues) {
			if(!cJSON_IsObject(related_ues_local)) {
				printf(
					"input_data_parseFromJSON() failed [related_ues]");
				goto end;
			}
			related_ue_t *related_uesItem =
				related_ue_parseFromJSON(related_ues_local);
			if(!related_uesItem) {
				printf("No related_uesItem");
				goto end;
			}
			list_add(related_uesList, related_uesItem);
		}
	}

	ecgi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ecgi");
	if(ecgi) {
		ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
		if(!ecgi_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi]");
			goto end;
		}
	}

	ecgi_on_second_node = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                       "ecgiOnSecondNode");
	if(ecgi_on_second_node) {
		ecgi_on_second_node_local_nonprim = ecgi_parseFromJSON(
			ecgi_on_second_node);
		if(!ecgi_on_second_node_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi_on_second_node]");
			goto end;
		}
	}

	ncgi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ncgi");
	if(ncgi) {
		ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
		if(!ncgi_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi]");
			goto end;
		}
	}

	ncgi_on_second_node = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                       "ncgiOnSecondNode");
	if(ncgi_on_second_node) {
		ncgi_on_second_node_local_nonprim = ncgi_parseFromJSON(
			ncgi_on_second_node);
		if(!ncgi_on_second_node_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi_on_second_node]");
			goto end;
		}
	}

	priority = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "priority");
	if(priority) {
		if(!cJSON_IsString(priority)) {
			printf("input_data_parseFromJSON() failed [priority]");
			goto end;
		}
		priorityVariable =
			lcs_priority_FromString(priority->valuestring);
	}

	velocity_requested = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "velocityRequested");
	if(velocity_requested) {
		if(!cJSON_IsString(velocity_requested)) {
			printf(
				"input_data_parseFromJSON() failed [velocity_requested]");
			goto end;
		}
		velocity_requestedVariable = velocity_requested_FromString(
			velocity_requested->valuestring);
	}

	ue_lcs_cap =
		cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ueLcsCap");
	if(ue_lcs_cap) {
		ue_lcs_cap_local_nonprim = ue_lcs_capability_parseFromJSON(
			ue_lcs_cap);
		if(!ue_lcs_cap_local_nonprim) {
			printf(
				"ue_lcs_capability_parseFromJSON failed [ue_lcs_cap]");
			goto end;
		}
	}

	lcs_service_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                    "lcsServiceType");
	if(lcs_service_type) {
		if(!cJSON_IsNumber(lcs_service_type)) {
			printf(
				"input_data_parseFromJSON() failed [lcs_service_type]");
			goto end;
		}
	}

	ldr_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "ldrType");
	if(ldr_type) {
		if(!cJSON_IsString(ldr_type)) {
			printf("input_data_parseFromJSON() failed [ldr_type]");
			goto end;
		}
		ldr_typeVariable = ldr_type_FromString(ldr_type->valuestring);
	}

	hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                       "hgmlcCallBackURI");
	if(hgmlc_call_back_uri) {
		if(!cJSON_IsString(hgmlc_call_back_uri) &&
		   !cJSON_IsNull(hgmlc_call_back_uri))
		{
			printf(
				"input_data_parseFromJSON() failed [hgmlc_call_back_uri]");
			goto end;
		}
	}

	lir_gmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "lirGmlcCallBackUri");
	if(lir_gmlc_call_back_uri) {
		if(!cJSON_IsString(lir_gmlc_call_back_uri) &&
		   !cJSON_IsNull(lir_gmlc_call_back_uri))
		{
			printf(
				"input_data_parseFromJSON() failed [lir_gmlc_call_back_uri]");
			goto end;
		}
	}

	vgmlc_address = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "vgmlcAddress");
	if(vgmlc_address) {
		if(!cJSON_IsString(vgmlc_address) &&
		   !cJSON_IsNull(vgmlc_address))
		{
			printf(
				"input_data_parseFromJSON() failed [vgmlc_address]");
			goto end;
		}
	}

	ldr_reference = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "ldrReference");
	if(ldr_reference) {
		if(!cJSON_IsString(ldr_reference) &&
		   !cJSON_IsNull(ldr_reference))
		{
			printf(
				"input_data_parseFromJSON() failed [ldr_reference]");
			goto end;
		}
	}

	lir_reference = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "lirReference");
	if(lir_reference) {
		if(!cJSON_IsString(lir_reference) &&
		   !cJSON_IsNull(lir_reference))
		{
			printf(
				"input_data_parseFromJSON() failed [lir_reference]");
			goto end;
		}
	}

	periodic_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                       "periodicEventInfo");
	if(periodic_event_info) {
		periodic_event_info_local_nonprim =
			periodic_event_info_parseFromJSON(periodic_event_info);
		if(!periodic_event_info_local_nonprim) {
			printf(
				"periodic_event_info_parseFromJSON failed [periodic_event_info]");
			goto end;
		}
	}

	area_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                   "areaEventInfo");
	if(area_event_info) {
		area_event_info_local_nonprim = area_event_info_parseFromJSON(
			area_event_info);
		if(!area_event_info_local_nonprim) {
			printf(
				"area_event_info_parseFromJSON failed [area_event_info]");
			goto end;
		}
	}

	motion_event_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                     "motionEventInfo");
	if(motion_event_info) {
		motion_event_info_local_nonprim =
			motion_event_info_parseFromJSON(motion_event_info);
		if(!motion_event_info_local_nonprim) {
			printf(
				"motion_event_info_parseFromJSON failed [motion_event_info]");
			goto end;
		}
	}

	reporting_access_types = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "reportingAccessTypes");
	if(reporting_access_types) {
		cJSON *reporting_access_types_local = NULL;
		if(!cJSON_IsArray(reporting_access_types)) {
			printf(
				"input_data_parseFromJSON() failed [reporting_access_types]");
			goto end;
		}

		reporting_access_typesList = list_create();

		cJSON_ArrayForEach(reporting_access_types_local,
		                   reporting_access_types) {
			reporting_access_type_e localEnum =
				reporting_access_type_NULL;
			if(!cJSON_IsString(reporting_access_types_local)) {
				printf(
					"input_data_parseFromJSON() failed [reporting_access_types]");
				goto end;
			}
			localEnum = reporting_access_type_FromString(
				reporting_access_types_local->valuestring);
			if(!localEnum) {
				printf(
					"Enum value \"%s\" for field \"reporting_access_types\" is not supported. Ignoring it ...",
					reporting_access_types_local->valuestring);
			} else {
				list_add(reporting_access_typesList,
				         (void *) localEnum);
			}
		}
		if(reporting_access_typesList->count == 0) {
			printf(
				"input_data_parseFromJSON() failed: Expected reporting_access_typesList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	ue_connectivity_states = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "ueConnectivityStates");
	if(ue_connectivity_states) {
		ue_connectivity_states_local_nonprim =
			ue_connectivity_state_parseFromJSON(
				ue_connectivity_states);
		if(!ue_connectivity_states_local_nonprim) {
			printf(
				"ue_connectivity_state_parseFromJSON failed [ue_connectivity_states]");
			goto end;
		}
	}

	ue_location_service_ind = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "ueLocationServiceInd");
	if(ue_location_service_ind) {
		if(!cJSON_IsString(ue_location_service_ind)) {
			printf(
				"input_data_parseFromJSON() failed [ue_location_service_ind]");
			goto end;
		}
		ue_location_service_indVariable =
			ue_location_service_ind_FromString(
				ue_location_service_ind->valuestring);
	}

	mo_assistance_data_types = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "moAssistanceDataTypes");
	if(mo_assistance_data_types) {
		mo_assistance_data_types_local_nonprim =
			lcs_broadcast_assistance_types_data_parseFromJSON(
				mo_assistance_data_types);
		if(!mo_assistance_data_types_local_nonprim) {
			printf(
				"lcs_broadcast_assistance_types_data_parseFromJSON failed [mo_assistance_data_types]");
			goto end;
		}
	}

	lpp_message = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                               "lppMessage");
	if(lpp_message) {
		lpp_message_local_nonprim = ref_to_binary_data_parseFromJSON(
			lpp_message);
		if(!lpp_message_local_nonprim) {
			printf(
				"ref_to_binary_data_parseFromJSON failed [lpp_message]");
			goto end;
		}
	}

	lpp_message_ext = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                   "lppMessageExt");
	if(lpp_message_ext) {
		cJSON *lpp_message_ext_local = NULL;
		if(!cJSON_IsArray(lpp_message_ext)) {
			printf(
				"input_data_parseFromJSON() failed [lpp_message_ext]");
			goto end;
		}

		lpp_message_extList = list_create();

		cJSON_ArrayForEach(lpp_message_ext_local, lpp_message_ext) {
			if(!cJSON_IsObject(lpp_message_ext_local)) {
				printf(
					"input_data_parseFromJSON() failed [lpp_message_ext]");
				goto end;
			}
			ref_to_binary_data_t *lpp_message_extItem =
				ref_to_binary_data_parseFromJSON(
					lpp_message_ext_local);
			if(!lpp_message_extItem) {
				printf("No lpp_message_extItem");
				goto end;
			}
			list_add(lpp_message_extList, lpp_message_extItem);
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"input_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "uePositioningCap");
	if(ue_positioning_cap) {
		if(!cJSON_IsString(ue_positioning_cap) &&
		   !cJSON_IsNull(ue_positioning_cap))
		{
			printf(
				"input_data_parseFromJSON() failed [ue_positioning_cap]");
			goto end;
		}
	}

	tnap_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "tnapId");
	if(tnap_id) {
		tnap_id_local_nonprim = tnap_id_parseFromJSON(tnap_id);
		if(!tnap_id_local_nonprim) {
			printf("tnap_id_parseFromJSON failed [tnap_id]");
			goto end;
		}
	}

	twap_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "twapId");
	if(twap_id) {
		twap_id_local_nonprim = twap_id_parseFromJSON(twap_id);
		if(!twap_id_local_nonprim) {
			printf("twap_id_parseFromJSON failed [twap_id]");
			goto end;
		}
	}

	ue_country_det_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "ueCountryDetInd");
	if(ue_country_det_ind) {
		if(!cJSON_IsBool(ue_country_det_ind)) {
			printf(
				"input_data_parseFromJSON() failed [ue_country_det_ind]");
			goto end;
		}
	}

	scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "scheduledLocTime");
	if(scheduled_loc_time) {
		if(!cJSON_IsString(scheduled_loc_time) &&
		   !cJSON_IsNull(scheduled_loc_time))
		{
			printf(
				"input_data_parseFromJSON() failed [scheduled_loc_time]");
			goto end;
		}
	}

	reliable_loc_req = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                    "reliableLocReq");
	if(reliable_loc_req) {
		if(!cJSON_IsBool(reliable_loc_req)) {
			printf(
				"input_data_parseFromJSON() failed [reliable_loc_req]");
			goto end;
		}
	}

	evt_rpt_allowed_areas = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                         "evtRptAllowedAreas");
	if(evt_rpt_allowed_areas) {
		cJSON *evt_rpt_allowed_areas_local = NULL;
		if(!cJSON_IsArray(evt_rpt_allowed_areas)) {
			printf(
				"input_data_parseFromJSON() failed [evt_rpt_allowed_areas]");
			goto end;
		}

		evt_rpt_allowed_areasList = list_create();

		cJSON_ArrayForEach(evt_rpt_allowed_areas_local,
		                   evt_rpt_allowed_areas) {
			if(!cJSON_IsObject(evt_rpt_allowed_areas_local)) {
				printf(
					"input_data_parseFromJSON() failed [evt_rpt_allowed_areas]");
				goto end;
			}
			reporting_area_t *evt_rpt_allowed_areasItem =
				reporting_area_parseFromJSON(
					evt_rpt_allowed_areas_local);
			if(!evt_rpt_allowed_areasItem) {
				printf("No evt_rpt_allowed_areasItem");
				goto end;
			}
			list_add(evt_rpt_allowed_areasList,
			         evt_rpt_allowed_areasItem);
		}
	}

	ue_unaware_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                  "ueUnawareInd");
	if(ue_unaware_ind) {
		if(!cJSON_IsString(ue_unaware_ind)) {
			printf(
				"input_data_parseFromJSON() failed [ue_unaware_ind]");
			goto end;
		}
		ue_unaware_indVariable = ue_unaware_indinput_data_FromString(
			ue_unaware_ind->valuestring);
	}

	intermediate_location_ind = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "intermediateLocationInd");
	if(intermediate_location_ind) {
		if(!cJSON_IsBool(intermediate_location_ind)) {
			printf(
				"input_data_parseFromJSON() failed [intermediate_location_ind]");
			goto end;
		}
	}

	max_resp_time = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "maxRespTime");
	if(max_resp_time) {
		if(!cJSON_IsNumber(max_resp_time)) {
			printf(
				"input_data_parseFromJSON() failed [max_resp_time]");
			goto end;
		}
	}

	lp_hap_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                               "lpHapType");
	if(lp_hap_type) {
		lp_hap_type_local_nonprim = lp_hap_type_parseFromJSON(
			lp_hap_type);
		if(!lp_hap_type_local_nonprim) {
			printf("lp_hap_type_parseFromJSON failed [lp_hap_type]");
			goto end;
		}
	}

	ue_up_pos_caps = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                  "ueUpPosCaps");
	if(ue_up_pos_caps) {
		cJSON *ue_up_pos_caps_local = NULL;
		if(!cJSON_IsArray(ue_up_pos_caps)) {
			printf(
				"input_data_parseFromJSON() failed [ue_up_pos_caps]");
			goto end;
		}

		ue_up_pos_capsList = list_create();

		cJSON_ArrayForEach(ue_up_pos_caps_local, ue_up_pos_caps) {
			ue_up_positioning_capabilities_e localEnum =
				ue_up_positioning_capabilities_NULL;
			if(!cJSON_IsString(ue_up_pos_caps_local)) {
				printf(
					"input_data_parseFromJSON() failed [ue_up_pos_caps]");
				goto end;
			}
			localEnum = ue_up_positioning_capabilities_FromString(
				ue_up_pos_caps_local->valuestring);
			if(!localEnum) {
				printf(
					"Enum value \"%s\" for field \"ue_up_pos_caps\" is not supported. Ignoring it ...",
					ue_up_pos_caps_local->valuestring);
			} else {
				list_add(ue_up_pos_capsList,
				         (void *) localEnum);
			}
		}
		if(ue_up_pos_capsList->count == 0) {
			printf(
				"input_data_parseFromJSON() failed: Expected ue_up_pos_capsList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	reporting_ind = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "reportingInd");
	if(reporting_ind) {
		reporting_ind_local_nonprim =
			input_data_reporting_ind_parseFromJSON(reporting_ind);
		if(!reporting_ind_local_nonprim) {
			printf(
				"input_data_reporting_ind_parseFromJSON failed [reporting_ind]");
			goto end;
		}
	}

	mbsr_info =
		cJSON_GetObjectItemCaseSensitive(input_dataJSON, "mbsrInfo");
	if(mbsr_info) {
		mbsr_info_local_nonprim = mbsr_info_parseFromJSON(mbsr_info);
		if(!mbsr_info_local_nonprim) {
			printf("mbsr_info_parseFromJSON failed [mbsr_info]");
			goto end;
		}
	}

	integrity_requirements = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "integrityRequirements");
	if(integrity_requirements) {
		integrity_requirements_local_nonprim =
			integrity_requirements_parseFromJSON(
				integrity_requirements);
		if(!integrity_requirements_local_nonprim) {
			printf(
				"integrity_requirements_parseFromJSON failed [integrity_requirements]");
			goto end;
		}
	}

	up_loc_rep_addr_af = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "upLocRepAddrAf");
	if(up_loc_rep_addr_af) {
		if(!cJSON_IsNull(up_loc_rep_addr_af)) {
			up_loc_rep_addr_af_local_nonprim =
				up_loc_rep_addr_af_rm_parseFromJSON(
					up_loc_rep_addr_af);
			if(!up_loc_rep_addr_af_local_nonprim) {
				printf(
					"up_loc_rep_addr_af_rm_parseFromJSON failed [up_loc_rep_addr_af]");
				goto end;
			}
		}
	}

	up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "upCumEvtRptCriteria");
	if(up_cum_evt_rpt_criteria) {
		up_cum_evt_rpt_criteria_local_nonprim =
			up_cum_evt_rpt_criteria_parseFromJSON(
				up_cum_evt_rpt_criteria);
		if(!up_cum_evt_rpt_criteria_local_nonprim) {
			printf(
				"up_cum_evt_rpt_criteria_parseFromJSON failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
	}

	mapped_qo_s_eps = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                   "mappedQoSEps");
	if(mapped_qo_s_eps) {
		mapped_qo_s_eps_local_nonprim =
			mapped_location_qo_s_eps_parseFromJSON(mapped_qo_s_eps);
		if(!mapped_qo_s_eps_local_nonprim) {
			printf(
				"mapped_location_qo_s_eps_parseFromJSON failed [mapped_qo_s_eps]");
			goto end;
		}
	}

	additional_ue_info = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "additionalUeInfo");
	if(additional_ue_info) {
		additional_ue_info_local_nonprim =
			additional_ue_info_parseFromJSON(additional_ue_info);
		if(!additional_ue_info_local_nonprim) {
			printf(
				"additional_ue_info_parseFromJSON failed [additional_ue_info]");
			goto end;
		}
	}

	coordinate_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "coordinateID");
	if(coordinate_id) {
		if(!cJSON_IsNumber(coordinate_id)) {
			printf(
				"input_data_parseFromJSON() failed [coordinate_id]");
			goto end;
		}
	}

	ranging_sl_capability = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                         "rangingSlCapability");
	if(ranging_sl_capability) {
		if(!cJSON_IsString(ranging_sl_capability) &&
		   !cJSON_IsNull(ranging_sl_capability))
		{
			printf(
				"input_data_parseFromJSON() failed [ranging_sl_capability]");
			goto end;
		}
	}

	input_data_local_var = input_data_create(
		external_client_type ? external_client_typeVariable : 0,
		correlation_id &&
		!cJSON_IsNull(correlation_id) ? strdup(correlation_id->
		                                       valuestring) : NULL,
		amf_id &&
		!cJSON_IsNull(amf_id) ? strdup(amf_id->valuestring) : NULL,
		location_qo_s ? location_qo_s_local_nonprim : NULL,
		supported_gad_shapes ? supported_gad_shapesList : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		pei &&
		!cJSON_IsNull(pei) ? strdup(pei->valuestring) : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(
			gpsi->valuestring) : NULL,
		requested_ranging_sl_result ? requested_ranging_sl_resultList : NULL,
		related_ues ? related_uesList : NULL,
		ecgi ? ecgi_local_nonprim : NULL,
		ecgi_on_second_node ? ecgi_on_second_node_local_nonprim : NULL,
		ncgi ? ncgi_local_nonprim : NULL,
		ncgi_on_second_node ? ncgi_on_second_node_local_nonprim : NULL,
		priority ? priorityVariable : 0,
		velocity_requested ? velocity_requestedVariable : 0,
		ue_lcs_cap ? ue_lcs_cap_local_nonprim : NULL,
		lcs_service_type ? true : false,
		lcs_service_type ? lcs_service_type->valuedouble : 0,
		ldr_type ? ldr_typeVariable : 0,
		hgmlc_call_back_uri &&
		!cJSON_IsNull(hgmlc_call_back_uri) ? strdup(hgmlc_call_back_uri
		                                            ->valuestring) : NULL,
		lir_gmlc_call_back_uri &&
		!cJSON_IsNull(lir_gmlc_call_back_uri) ? strdup(
			lir_gmlc_call_back_uri->valuestring) : NULL,
		vgmlc_address &&
		!cJSON_IsNull(vgmlc_address) ? strdup(
			vgmlc_address->valuestring) : NULL,
		ldr_reference &&
		!cJSON_IsNull(ldr_reference) ? strdup(
			ldr_reference->valuestring) : NULL,
		lir_reference &&
		!cJSON_IsNull(lir_reference) ? strdup(
			lir_reference->valuestring) : NULL,
		periodic_event_info ? periodic_event_info_local_nonprim : NULL,
		area_event_info ? area_event_info_local_nonprim : NULL,
		motion_event_info ? motion_event_info_local_nonprim : NULL,
		reporting_access_types ? reporting_access_typesList : NULL,
		ue_connectivity_states ? ue_connectivity_states_local_nonprim : NULL,
		ue_location_service_ind ? ue_location_service_indVariable : 0,
		mo_assistance_data_types ? mo_assistance_data_types_local_nonprim : NULL,
		lpp_message ? lpp_message_local_nonprim : NULL,
		lpp_message_ext ? lpp_message_extList : NULL,
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL,
		ue_positioning_cap &&
		!cJSON_IsNull(ue_positioning_cap) ? strdup(ue_positioning_cap->
		                                           valuestring) : NULL,
		tnap_id ? tnap_id_local_nonprim : NULL,
		twap_id ? twap_id_local_nonprim : NULL,
		ue_country_det_ind ? true : false,
		ue_country_det_ind ? ue_country_det_ind->valueint : 0,
		scheduled_loc_time &&
		!cJSON_IsNull(scheduled_loc_time) ? strdup(scheduled_loc_time->
		                                           valuestring) : NULL,
		reliable_loc_req ? true : false,
		reliable_loc_req ? reliable_loc_req->valueint : 0,
		evt_rpt_allowed_areas ? evt_rpt_allowed_areasList : NULL,
		ue_unaware_ind ? ue_unaware_indVariable : 0,
		intermediate_location_ind ? true : false,
		intermediate_location_ind ? intermediate_location_ind->valueint : 0,
		max_resp_time ? true : false,
		max_resp_time ? max_resp_time->valuedouble : 0,
		lp_hap_type ? lp_hap_type_local_nonprim : NULL,
		ue_up_pos_caps ? ue_up_pos_capsList : NULL,
		reporting_ind ? reporting_ind_local_nonprim : NULL,
		mbsr_info ? mbsr_info_local_nonprim : NULL,
		integrity_requirements ? integrity_requirements_local_nonprim : NULL,
		up_loc_rep_addr_af &&
		cJSON_IsNull(
			up_loc_rep_addr_af) ? true : false,
		up_loc_rep_addr_af ? up_loc_rep_addr_af_local_nonprim : NULL,
		up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL,
		mapped_qo_s_eps ? mapped_qo_s_eps_local_nonprim : NULL,
		additional_ue_info ? additional_ue_info_local_nonprim : NULL,
		coordinate_id ? true : false,
		coordinate_id ? coordinate_id->valuedouble : 0,
		ranging_sl_capability &&
		!cJSON_IsNull(ranging_sl_capability) ? strdup(
			ranging_sl_capability->valuestring) : NULL
		);

	return input_data_local_var;
end:
	if(location_qo_s_local_nonprim) {
		location_qo_s_free(location_qo_s_local_nonprim);
		location_qo_s_local_nonprim = NULL;
	}
	if(supported_gad_shapesList) {
		list_free(supported_gad_shapesList);
		supported_gad_shapesList = NULL;
	}
	if(requested_ranging_sl_resultList) {
		list_free(requested_ranging_sl_resultList);
		requested_ranging_sl_resultList = NULL;
	}
	if(related_uesList) {
		list_for_each(related_uesList, node) {
			related_ue_free(node->data);
		}
		list_free(related_uesList);
		related_uesList = NULL;
	}
	if(ecgi_local_nonprim) {
		ecgi_free(ecgi_local_nonprim);
		ecgi_local_nonprim = NULL;
	}
	if(ecgi_on_second_node_local_nonprim) {
		ecgi_free(ecgi_on_second_node_local_nonprim);
		ecgi_on_second_node_local_nonprim = NULL;
	}
	if(ncgi_local_nonprim) {
		ncgi_free(ncgi_local_nonprim);
		ncgi_local_nonprim = NULL;
	}
	if(ncgi_on_second_node_local_nonprim) {
		ncgi_free(ncgi_on_second_node_local_nonprim);
		ncgi_on_second_node_local_nonprim = NULL;
	}
	if(ue_lcs_cap_local_nonprim) {
		ue_lcs_capability_free(ue_lcs_cap_local_nonprim);
		ue_lcs_cap_local_nonprim = NULL;
	}
	if(periodic_event_info_local_nonprim) {
		periodic_event_info_free(periodic_event_info_local_nonprim);
		periodic_event_info_local_nonprim = NULL;
	}
	if(area_event_info_local_nonprim) {
		area_event_info_free(area_event_info_local_nonprim);
		area_event_info_local_nonprim = NULL;
	}
	if(motion_event_info_local_nonprim) {
		motion_event_info_free(motion_event_info_local_nonprim);
		motion_event_info_local_nonprim = NULL;
	}
	if(reporting_access_typesList) {
		list_free(reporting_access_typesList);
		reporting_access_typesList = NULL;
	}
	if(ue_connectivity_states_local_nonprim) {
		ue_connectivity_state_free(ue_connectivity_states_local_nonprim);
		ue_connectivity_states_local_nonprim = NULL;
	}
	if(mo_assistance_data_types_local_nonprim) {
		lcs_broadcast_assistance_types_data_free(
			mo_assistance_data_types_local_nonprim);
		mo_assistance_data_types_local_nonprim = NULL;
	}
	if(lpp_message_local_nonprim) {
		ref_to_binary_data_free(lpp_message_local_nonprim);
		lpp_message_local_nonprim = NULL;
	}
	if(lpp_message_extList) {
		list_for_each(lpp_message_extList, node) {
			ref_to_binary_data_free(node->data);
		}
		list_free(lpp_message_extList);
		lpp_message_extList = NULL;
	}
	if(tnap_id_local_nonprim) {
		tnap_id_free(tnap_id_local_nonprim);
		tnap_id_local_nonprim = NULL;
	}
	if(twap_id_local_nonprim) {
		twap_id_free(twap_id_local_nonprim);
		twap_id_local_nonprim = NULL;
	}
	if(evt_rpt_allowed_areasList) {
		list_for_each(evt_rpt_allowed_areasList, node) {
			reporting_area_free(node->data);
		}
		list_free(evt_rpt_allowed_areasList);
		evt_rpt_allowed_areasList = NULL;
	}
	if(lp_hap_type_local_nonprim) {
		lp_hap_type_free(lp_hap_type_local_nonprim);
		lp_hap_type_local_nonprim = NULL;
	}
	if(ue_up_pos_capsList) {
		list_free(ue_up_pos_capsList);
		ue_up_pos_capsList = NULL;
	}
	if(reporting_ind_local_nonprim) {
		input_data_reporting_ind_free(reporting_ind_local_nonprim);
		reporting_ind_local_nonprim = NULL;
	}
	if(mbsr_info_local_nonprim) {
		mbsr_info_free(mbsr_info_local_nonprim);
		mbsr_info_local_nonprim = NULL;
	}
	if(integrity_requirements_local_nonprim) {
		integrity_requirements_free(integrity_requirements_local_nonprim);
		integrity_requirements_local_nonprim = NULL;
	}
	if(up_loc_rep_addr_af_local_nonprim) {
		up_loc_rep_addr_af_rm_free(up_loc_rep_addr_af_local_nonprim);
		up_loc_rep_addr_af_local_nonprim = NULL;
	}
	if(up_cum_evt_rpt_criteria_local_nonprim) {
		up_cum_evt_rpt_criteria_free(
			up_cum_evt_rpt_criteria_local_nonprim);
		up_cum_evt_rpt_criteria_local_nonprim = NULL;
	}
	if(mapped_qo_s_eps_local_nonprim) {
		mapped_location_qo_s_eps_free(mapped_qo_s_eps_local_nonprim);
		mapped_qo_s_eps_local_nonprim = NULL;
	}
	if(additional_ue_info_local_nonprim) {
		additional_ue_info_free(additional_ue_info_local_nonprim);
		additional_ue_info_local_nonprim = NULL;
	}
	return NULL;
}

input_data_t *input_data_copy(input_data_t *dst, input_data_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = input_data_convertToJSON(src);
	if(!item) {
		printf("input_data_convertToJSON() failed");
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

	input_data_free(dst);
	dst = input_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
