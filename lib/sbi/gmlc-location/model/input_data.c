#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "input_data.h"

input_data_t *input_data_create(char *gpsi, char *supi, char *app_layer_id,
                                char *ext_group_id, char *int_group_id,
                                external_client_type_e external_client_type,
                                location_qo_s_t *location_qo_s,
                                list_t *supported_gad_shapes,
                                char *service_identity,
                                list_t *service_coverage, ldr_type_e ldr_type,
                                periodic_event_info_t *periodic_event_info,
                                area_event_info_ext_t *area_event_info,
                                motion_event_info_t *motion_event_info,
                                char *ldr_reference, char *hgmlc_call_back_uri,
                                char *event_notification_uri,
                                char *external_client_identification,
                                char *af_id,
                                ue_privacy_requirements_t *ue_privacy_requirements, bool is_lcs_service_type, int lcs_service_type, velocity_requested_e velocity_requested, lcs_priority_e priority, location_type_requested_e location_type_requested, bool is_maximum_age_of_location_estimate, int maximum_age_of_location_estimate, char *amf_id, char *code_word, char *scheduled_loc_time, bool is_reliable_loc_req, int reliable_loc_req, char *serving_lmf_id, lp_hap_type_t *lp_hap_type, geographic_area_t *evt_rpt_expected_area, input_data_reporting_ind_t *reporting_ind, integrity_requirements_t *integrity_requirements, up_loc_rep_info_af_t *up_loc_rep_info_af, list_t *requested_ranging_sl_result, list_t *related_ues, mapped_location_qo_s_eps_t *mapped_qo_s_eps, bool is_coordinate_id,
                                int coordinate_id) {
	input_data_t *input_data_local_var = malloc(sizeof(input_data_t));

	input_data_local_var->gpsi = gpsi;
	input_data_local_var->supi = supi;
	input_data_local_var->app_layer_id = app_layer_id;
	input_data_local_var->ext_group_id = ext_group_id;
	input_data_local_var->int_group_id = int_group_id;
	input_data_local_var->external_client_type = external_client_type;
	input_data_local_var->location_qo_s = location_qo_s;
	input_data_local_var->supported_gad_shapes = supported_gad_shapes;
	input_data_local_var->service_identity = service_identity;
	input_data_local_var->service_coverage = service_coverage;
	input_data_local_var->ldr_type = ldr_type;
	input_data_local_var->periodic_event_info = periodic_event_info;
	input_data_local_var->area_event_info = area_event_info;
	input_data_local_var->motion_event_info = motion_event_info;
	input_data_local_var->ldr_reference = ldr_reference;
	input_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
	input_data_local_var->event_notification_uri = event_notification_uri;
	input_data_local_var->external_client_identification =
		external_client_identification;
	input_data_local_var->af_id = af_id;
	input_data_local_var->ue_privacy_requirements = ue_privacy_requirements;
	input_data_local_var->is_lcs_service_type = is_lcs_service_type;
	input_data_local_var->lcs_service_type = lcs_service_type;
	input_data_local_var->velocity_requested = velocity_requested;
	input_data_local_var->priority = priority;
	input_data_local_var->location_type_requested = location_type_requested;
	input_data_local_var->is_maximum_age_of_location_estimate =
		is_maximum_age_of_location_estimate;
	input_data_local_var->maximum_age_of_location_estimate =
		maximum_age_of_location_estimate;
	input_data_local_var->amf_id = amf_id;
	input_data_local_var->code_word = code_word;
	input_data_local_var->scheduled_loc_time = scheduled_loc_time;
	input_data_local_var->is_reliable_loc_req = is_reliable_loc_req;
	input_data_local_var->reliable_loc_req = reliable_loc_req;
	input_data_local_var->serving_lmf_id = serving_lmf_id;
	input_data_local_var->lp_hap_type = lp_hap_type;
	input_data_local_var->evt_rpt_expected_area = evt_rpt_expected_area;
	input_data_local_var->reporting_ind = reporting_ind;
	input_data_local_var->integrity_requirements = integrity_requirements;
	input_data_local_var->up_loc_rep_info_af = up_loc_rep_info_af;
	input_data_local_var->requested_ranging_sl_result =
		requested_ranging_sl_result;
	input_data_local_var->related_ues = related_ues;
	input_data_local_var->mapped_qo_s_eps = mapped_qo_s_eps;
	input_data_local_var->is_coordinate_id = is_coordinate_id;
	input_data_local_var->coordinate_id = coordinate_id;

	return input_data_local_var;
}

void input_data_free(input_data_t *input_data) {
	lnode_t *node = NULL;

	if(NULL == input_data) {
		return;
	}
	if(input_data->gpsi) {
		free(input_data->gpsi);
		input_data->gpsi = NULL;
	}
	if(input_data->supi) {
		free(input_data->supi);
		input_data->supi = NULL;
	}
	if(input_data->app_layer_id) {
		free(input_data->app_layer_id);
		input_data->app_layer_id = NULL;
	}
	if(input_data->ext_group_id) {
		free(input_data->ext_group_id);
		input_data->ext_group_id = NULL;
	}
	if(input_data->int_group_id) {
		free(input_data->int_group_id);
		input_data->int_group_id = NULL;
	}
	if(input_data->location_qo_s) {
		location_qo_s_free(input_data->location_qo_s);
		input_data->location_qo_s = NULL;
	}
	if(input_data->supported_gad_shapes) {
		list_free(input_data->supported_gad_shapes);
		input_data->supported_gad_shapes = NULL;
	}
	if(input_data->service_identity) {
		free(input_data->service_identity);
		input_data->service_identity = NULL;
	}
	if(input_data->service_coverage) {
		list_for_each(input_data->service_coverage, node) {
			free(node->data);
		}
		list_free(input_data->service_coverage);
		input_data->service_coverage = NULL;
	}
	if(input_data->periodic_event_info) {
		periodic_event_info_free(input_data->periodic_event_info);
		input_data->periodic_event_info = NULL;
	}
	if(input_data->area_event_info) {
		area_event_info_ext_free(input_data->area_event_info);
		input_data->area_event_info = NULL;
	}
	if(input_data->motion_event_info) {
		motion_event_info_free(input_data->motion_event_info);
		input_data->motion_event_info = NULL;
	}
	if(input_data->ldr_reference) {
		free(input_data->ldr_reference);
		input_data->ldr_reference = NULL;
	}
	if(input_data->hgmlc_call_back_uri) {
		free(input_data->hgmlc_call_back_uri);
		input_data->hgmlc_call_back_uri = NULL;
	}
	if(input_data->event_notification_uri) {
		free(input_data->event_notification_uri);
		input_data->event_notification_uri = NULL;
	}
	if(input_data->external_client_identification) {
		free(input_data->external_client_identification);
		input_data->external_client_identification = NULL;
	}
	if(input_data->af_id) {
		free(input_data->af_id);
		input_data->af_id = NULL;
	}
	if(input_data->ue_privacy_requirements) {
		ue_privacy_requirements_free(input_data->ue_privacy_requirements);
		input_data->ue_privacy_requirements = NULL;
	}
	if(input_data->amf_id) {
		free(input_data->amf_id);
		input_data->amf_id = NULL;
	}
	if(input_data->code_word) {
		free(input_data->code_word);
		input_data->code_word = NULL;
	}
	if(input_data->scheduled_loc_time) {
		free(input_data->scheduled_loc_time);
		input_data->scheduled_loc_time = NULL;
	}
	if(input_data->serving_lmf_id) {
		free(input_data->serving_lmf_id);
		input_data->serving_lmf_id = NULL;
	}
	if(input_data->lp_hap_type) {
		lp_hap_type_free(input_data->lp_hap_type);
		input_data->lp_hap_type = NULL;
	}
	if(input_data->evt_rpt_expected_area) {
		geographic_area_free(input_data->evt_rpt_expected_area);
		input_data->evt_rpt_expected_area = NULL;
	}
	if(input_data->reporting_ind) {
		input_data_reporting_ind_free(input_data->reporting_ind);
		input_data->reporting_ind = NULL;
	}
	if(input_data->integrity_requirements) {
		integrity_requirements_free(input_data->integrity_requirements);
		input_data->integrity_requirements = NULL;
	}
	if(input_data->up_loc_rep_info_af) {
		up_loc_rep_info_af_free(input_data->up_loc_rep_info_af);
		input_data->up_loc_rep_info_af = NULL;
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
	if(input_data->mapped_qo_s_eps) {
		mapped_location_qo_s_eps_free(input_data->mapped_qo_s_eps);
		input_data->mapped_qo_s_eps = NULL;
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
	if(input_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           input_data->gpsi) == NULL)
		{
			printf("input_data_convertToJSON() failed [gpsi]");
			goto end;
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

	if(input_data->app_layer_id) {
		if(cJSON_AddStringToObject(item, "appLayerId",
		                           input_data->app_layer_id) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [app_layer_id]");
			goto end;
		}
	}

	if(input_data->ext_group_id) {
		if(cJSON_AddStringToObject(item, "extGroupId",
		                           input_data->ext_group_id) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ext_group_id]");
			goto end;
		}
	}

	if(input_data->int_group_id) {
		if(cJSON_AddStringToObject(item, "intGroupId",
		                           input_data->int_group_id) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [int_group_id]");
			goto end;
		}
	}

	if(input_data->external_client_type == external_client_type_NULL) {
		printf(
			"input_data_convertToJSON() failed [external_client_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "externalClientType",
	                           external_client_type_ToString(input_data->
	                                                         external_client_type))
	   ==
	   NULL)
	{
		printf(
			"input_data_convertToJSON() failed [external_client_type]");
		goto end;
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

	if(input_data->service_identity) {
		if(cJSON_AddStringToObject(item, "serviceIdentity",
		                           input_data->service_identity) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [service_identity]");
			goto end;
		}
	}

	if(input_data->service_coverage) {
		cJSON *service_coverageList = cJSON_AddArrayToObject(item,
		                                                     "serviceCoverage");
		if(service_coverageList == NULL) {
			printf(
				"input_data_convertToJSON() failed [service_coverage]");
			goto end;
		}
		list_for_each(input_data->service_coverage, node) {
			if(cJSON_AddStringToObject(service_coverageList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"input_data_convertToJSON() failed [service_coverage]");
				goto end;
			}
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
			area_event_info_ext_convertToJSON(
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

	if(input_data->ldr_reference) {
		if(cJSON_AddStringToObject(item, "ldrReference",
		                           input_data->ldr_reference) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [ldr_reference]");
			goto end;
		}
	}

	if(input_data->hgmlc_call_back_uri) {
		if(cJSON_AddStringToObject(item, "hgmlcCallBackUri",
		                           input_data->hgmlc_call_back_uri) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [hgmlc_call_back_uri]");
			goto end;
		}
	}

	if(input_data->event_notification_uri) {
		if(cJSON_AddStringToObject(item, "eventNotificationUri",
		                           input_data->event_notification_uri)
		   == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [event_notification_uri]");
			goto end;
		}
	}

	if(input_data->external_client_identification) {
		if(cJSON_AddStringToObject(item, "externalClientIdentification",
		                           input_data->
		                           external_client_identification) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [external_client_identification]");
			goto end;
		}
	}

	if(input_data->af_id) {
		if(cJSON_AddStringToObject(item, "afId",
		                           input_data->af_id) == NULL)
		{
			printf("input_data_convertToJSON() failed [af_id]");
			goto end;
		}
	}

	if(input_data->ue_privacy_requirements) {
		cJSON *ue_privacy_requirements_local_JSON =
			ue_privacy_requirements_convertToJSON(
				input_data->ue_privacy_requirements);
		if(ue_privacy_requirements_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [ue_privacy_requirements]");
			goto end;
		}
		cJSON_AddItemToObject(item, "uePrivacyRequirements",
		                      ue_privacy_requirements_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [ue_privacy_requirements]");
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

	if(input_data->location_type_requested !=
	   location_type_requested_NULL)
	{
		if(cJSON_AddStringToObject(item, "locationTypeRequested",
		                           location_type_requested_ToString(
						   input_data->
						   location_type_requested))
		   == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [location_type_requested]");
			goto end;
		}
	}

	if(input_data->is_maximum_age_of_location_estimate) {
		if(cJSON_AddNumberToObject(item, "maximumAgeOfLocationEstimate",
		                           input_data->
		                           maximum_age_of_location_estimate) ==
		   NULL)
		{
			printf(
				"input_data_convertToJSON() failed [maximum_age_of_location_estimate]");
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

	if(input_data->code_word) {
		if(cJSON_AddStringToObject(item, "codeWord",
		                           input_data->code_word) == NULL)
		{
			printf("input_data_convertToJSON() failed [code_word]");
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

	if(input_data->serving_lmf_id) {
		if(cJSON_AddStringToObject(item, "servingLmfId",
		                           input_data->serving_lmf_id) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [serving_lmf_id]");
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

	if(input_data->evt_rpt_expected_area) {
		cJSON *evt_rpt_expected_area_local_JSON =
			geographic_area_convertToJSON(
				input_data->evt_rpt_expected_area);
		if(evt_rpt_expected_area_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [evt_rpt_expected_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "evtRptExpectedArea",
		                      evt_rpt_expected_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [evt_rpt_expected_area]");
			goto end;
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

	if(input_data->up_loc_rep_info_af) {
		cJSON *up_loc_rep_info_af_local_JSON =
			up_loc_rep_info_af_convertToJSON(
				input_data->up_loc_rep_info_af);
		if(up_loc_rep_info_af_local_JSON == NULL) {
			printf(
				"input_data_convertToJSON() failed [up_loc_rep_info_af]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upLocRepInfoAf",
		                      up_loc_rep_info_af_local_JSON);
		if(item->child == NULL) {
			printf(
				"input_data_convertToJSON() failed [up_loc_rep_info_af]");
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

	if(input_data->is_coordinate_id) {
		if(cJSON_AddNumberToObject(item, "coordinateID",
		                           input_data->coordinate_id) == NULL)
		{
			printf(
				"input_data_convertToJSON() failed [coordinate_id]");
			goto end;
		}
	}

end:
	return item;
}

input_data_t *input_data_parseFromJSON(cJSON *input_dataJSON) {
	input_data_t *input_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	cJSON *app_layer_id = NULL;
	cJSON *ext_group_id = NULL;
	cJSON *int_group_id = NULL;
	cJSON *external_client_type = NULL;
	external_client_type_e external_client_typeVariable = 0;
	cJSON *location_qo_s = NULL;
	location_qo_s_t *location_qo_s_local_nonprim = NULL;
	cJSON *supported_gad_shapes = NULL;
	list_t *supported_gad_shapesList = NULL;
	cJSON *service_identity = NULL;
	cJSON *service_coverage = NULL;
	list_t *service_coverageList = NULL;
	cJSON *ldr_type = NULL;
	ldr_type_e ldr_typeVariable = 0;
	cJSON *periodic_event_info = NULL;
	periodic_event_info_t *periodic_event_info_local_nonprim = NULL;
	cJSON *area_event_info = NULL;
	area_event_info_ext_t *area_event_info_local_nonprim = NULL;
	cJSON *motion_event_info = NULL;
	motion_event_info_t *motion_event_info_local_nonprim = NULL;
	cJSON *ldr_reference = NULL;
	cJSON *hgmlc_call_back_uri = NULL;
	cJSON *event_notification_uri = NULL;
	cJSON *external_client_identification = NULL;
	cJSON *af_id = NULL;
	cJSON *ue_privacy_requirements = NULL;
	ue_privacy_requirements_t *ue_privacy_requirements_local_nonprim = NULL;
	cJSON *lcs_service_type = NULL;
	cJSON *velocity_requested = NULL;
	velocity_requested_e velocity_requestedVariable = 0;
	cJSON *priority = NULL;
	lcs_priority_e priorityVariable = 0;
	cJSON *location_type_requested = NULL;
	location_type_requested_e location_type_requestedVariable = 0;
	cJSON *maximum_age_of_location_estimate = NULL;
	cJSON *amf_id = NULL;
	cJSON *code_word = NULL;
	cJSON *scheduled_loc_time = NULL;
	cJSON *reliable_loc_req = NULL;
	cJSON *serving_lmf_id = NULL;
	cJSON *lp_hap_type = NULL;
	lp_hap_type_t *lp_hap_type_local_nonprim = NULL;
	cJSON *evt_rpt_expected_area = NULL;
	geographic_area_t *evt_rpt_expected_area_local_nonprim = NULL;
	cJSON *reporting_ind = NULL;
	input_data_reporting_ind_t *reporting_ind_local_nonprim = NULL;
	cJSON *integrity_requirements = NULL;
	integrity_requirements_t *integrity_requirements_local_nonprim = NULL;
	cJSON *up_loc_rep_info_af = NULL;
	up_loc_rep_info_af_t *up_loc_rep_info_af_local_nonprim = NULL;
	cJSON *requested_ranging_sl_result = NULL;
	list_t *requested_ranging_sl_resultList = NULL;
	cJSON *related_ues = NULL;
	list_t *related_uesList = NULL;
	cJSON *mapped_qo_s_eps = NULL;
	mapped_location_qo_s_eps_t *mapped_qo_s_eps_local_nonprim = NULL;
	cJSON *coordinate_id = NULL;
	gpsi = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("input_data_parseFromJSON() failed [gpsi]");
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

	app_layer_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                "appLayerId");
	if(app_layer_id) {
		if(!cJSON_IsString(app_layer_id) &&
		   !cJSON_IsNull(app_layer_id))
		{
			printf(
				"input_data_parseFromJSON() failed [app_layer_id]");
			goto end;
		}
	}

	ext_group_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                "extGroupId");
	if(ext_group_id) {
		if(!cJSON_IsString(ext_group_id) &&
		   !cJSON_IsNull(ext_group_id))
		{
			printf(
				"input_data_parseFromJSON() failed [ext_group_id]");
			goto end;
		}
	}

	int_group_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                "intGroupId");
	if(int_group_id) {
		if(!cJSON_IsString(int_group_id) &&
		   !cJSON_IsNull(int_group_id))
		{
			printf(
				"input_data_parseFromJSON() failed [int_group_id]");
			goto end;
		}
	}

	external_client_type = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                        "externalClientType");
	if(!external_client_type) {
		printf(
			"input_data_parseFromJSON() failed [external_client_type]");
		goto end;
	}
	if(!cJSON_IsString(external_client_type)) {
		printf(
			"input_data_parseFromJSON() failed [external_client_type]");
		goto end;
	}
	external_client_typeVariable = external_client_type_FromString(
		external_client_type->valuestring);

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

	service_identity = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                    "serviceIdentity");
	if(service_identity) {
		if(!cJSON_IsString(service_identity) &&
		   !cJSON_IsNull(service_identity))
		{
			printf(
				"input_data_parseFromJSON() failed [service_identity]");
			goto end;
		}
	}

	service_coverage = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                    "serviceCoverage");
	if(service_coverage) {
		cJSON *service_coverage_local = NULL;
		if(!cJSON_IsArray(service_coverage)) {
			printf(
				"input_data_parseFromJSON() failed [service_coverage]");
			goto end;
		}

		service_coverageList = list_create();

		cJSON_ArrayForEach(service_coverage_local, service_coverage) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(service_coverage_local)) {
				printf(
					"input_data_parseFromJSON() failed [service_coverage]");
				goto end;
			}
			list_add(service_coverageList,
			         strdup(service_coverage_local->valuestring));
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
		area_event_info_local_nonprim =
			area_event_info_ext_parseFromJSON(area_event_info);
		if(!area_event_info_local_nonprim) {
			printf(
				"area_event_info_ext_parseFromJSON failed [area_event_info]");
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

	hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                       "hgmlcCallBackUri");
	if(hgmlc_call_back_uri) {
		if(!cJSON_IsString(hgmlc_call_back_uri) &&
		   !cJSON_IsNull(hgmlc_call_back_uri))
		{
			printf(
				"input_data_parseFromJSON() failed [hgmlc_call_back_uri]");
			goto end;
		}
	}

	event_notification_uri = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "eventNotificationUri");
	if(event_notification_uri) {
		if(!cJSON_IsString(event_notification_uri) &&
		   !cJSON_IsNull(event_notification_uri))
		{
			printf(
				"input_data_parseFromJSON() failed [event_notification_uri]");
			goto end;
		}
	}

	external_client_identification = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "externalClientIdentification");
	if(external_client_identification) {
		if(!cJSON_IsString(external_client_identification) &&
		   !cJSON_IsNull(external_client_identification))
		{
			printf(
				"input_data_parseFromJSON() failed [external_client_identification]");
			goto end;
		}
	}

	af_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "afId");
	if(af_id) {
		if(!cJSON_IsString(af_id) &&
		   !cJSON_IsNull(af_id))
		{
			printf("input_data_parseFromJSON() failed [af_id]");
			goto end;
		}
	}

	ue_privacy_requirements = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "uePrivacyRequirements");
	if(ue_privacy_requirements) {
		ue_privacy_requirements_local_nonprim =
			ue_privacy_requirements_parseFromJSON(
				ue_privacy_requirements);
		if(!ue_privacy_requirements_local_nonprim) {
			printf(
				"ue_privacy_requirements_parseFromJSON failed [ue_privacy_requirements]");
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

	priority = cJSON_GetObjectItemCaseSensitive(input_dataJSON, "priority");
	if(priority) {
		if(!cJSON_IsString(priority)) {
			printf("input_data_parseFromJSON() failed [priority]");
			goto end;
		}
		priorityVariable =
			lcs_priority_FromString(priority->valuestring);
	}

	location_type_requested = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "locationTypeRequested");
	if(location_type_requested) {
		if(!cJSON_IsString(location_type_requested)) {
			printf(
				"input_data_parseFromJSON() failed [location_type_requested]");
			goto end;
		}
		location_type_requestedVariable =
			location_type_requested_FromString(
				location_type_requested->valuestring);
	}

	maximum_age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		input_dataJSON, "maximumAgeOfLocationEstimate");
	if(maximum_age_of_location_estimate) {
		if(!cJSON_IsNumber(maximum_age_of_location_estimate)) {
			printf(
				"input_data_parseFromJSON() failed [maximum_age_of_location_estimate]");
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

	code_word =
		cJSON_GetObjectItemCaseSensitive(input_dataJSON, "codeWord");
	if(code_word) {
		if(!cJSON_IsString(code_word) &&
		   !cJSON_IsNull(code_word))
		{
			printf("input_data_parseFromJSON() failed [code_word]");
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

	serving_lmf_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                  "servingLmfId");
	if(serving_lmf_id) {
		if(!cJSON_IsString(serving_lmf_id) &&
		   !cJSON_IsNull(serving_lmf_id))
		{
			printf(
				"input_data_parseFromJSON() failed [serving_lmf_id]");
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

	evt_rpt_expected_area = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                         "evtRptExpectedArea");
	if(evt_rpt_expected_area) {
		evt_rpt_expected_area_local_nonprim =
			geographic_area_parseFromJSON(evt_rpt_expected_area);
		if(!evt_rpt_expected_area_local_nonprim) {
			printf(
				"geographic_area_parseFromJSON failed [evt_rpt_expected_area]");
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

	up_loc_rep_info_af = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                      "upLocRepInfoAf");
	if(up_loc_rep_info_af) {
		up_loc_rep_info_af_local_nonprim =
			up_loc_rep_info_af_parseFromJSON(up_loc_rep_info_af);
		if(!up_loc_rep_info_af_local_nonprim) {
			printf(
				"up_loc_rep_info_af_parseFromJSON failed [up_loc_rep_info_af]");
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

	coordinate_id = cJSON_GetObjectItemCaseSensitive(input_dataJSON,
	                                                 "coordinateID");
	if(coordinate_id) {
		if(!cJSON_IsNumber(coordinate_id)) {
			printf(
				"input_data_parseFromJSON() failed [coordinate_id]");
			goto end;
		}
	}

	input_data_local_var = input_data_create(
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		app_layer_id &&
		!cJSON_IsNull(app_layer_id) ? strdup(
			app_layer_id->valuestring) : NULL,
		ext_group_id &&
		!cJSON_IsNull(ext_group_id) ? strdup(
			ext_group_id->valuestring) : NULL,
		int_group_id &&
		!cJSON_IsNull(int_group_id) ? strdup(
			int_group_id->valuestring) : NULL,
		external_client_typeVariable,
		location_qo_s ? location_qo_s_local_nonprim : NULL,
		supported_gad_shapes ? supported_gad_shapesList : NULL,
		service_identity &&
		!cJSON_IsNull(service_identity) ? strdup(service_identity->
		                                         valuestring) : NULL,
		service_coverage ? service_coverageList : NULL,
		ldr_type ? ldr_typeVariable : 0,
		periodic_event_info ? periodic_event_info_local_nonprim : NULL,
		area_event_info ? area_event_info_local_nonprim : NULL,
		motion_event_info ? motion_event_info_local_nonprim : NULL,
		ldr_reference &&
		!cJSON_IsNull(ldr_reference) ? strdup(
			ldr_reference->valuestring) : NULL,
		hgmlc_call_back_uri &&
		!cJSON_IsNull(hgmlc_call_back_uri) ? strdup(hgmlc_call_back_uri
		                                            ->valuestring) : NULL,
		event_notification_uri &&
		!cJSON_IsNull(event_notification_uri) ? strdup(
			event_notification_uri->valuestring) : NULL,
		external_client_identification &&
		!cJSON_IsNull(external_client_identification) ? strdup(
			external_client_identification->valuestring) : NULL,
		af_id &&
		!cJSON_IsNull(af_id) ? strdup(
			af_id->valuestring) : NULL,
		ue_privacy_requirements ? ue_privacy_requirements_local_nonprim : NULL,
		lcs_service_type ? true : false,
		lcs_service_type ? lcs_service_type->valuedouble : 0,
		velocity_requested ? velocity_requestedVariable : 0,
		priority ? priorityVariable : 0,
		location_type_requested ? location_type_requestedVariable : 0,
		maximum_age_of_location_estimate ? true : false,
		maximum_age_of_location_estimate ? maximum_age_of_location_estimate->valuedouble : 0,
		amf_id &&
		!cJSON_IsNull(amf_id) ? strdup(amf_id->valuestring) : NULL,
		code_word &&
		!cJSON_IsNull(code_word) ? strdup(
			code_word->valuestring) : NULL,
		scheduled_loc_time &&
		!cJSON_IsNull(scheduled_loc_time) ? strdup(scheduled_loc_time->
		                                           valuestring) : NULL,
		reliable_loc_req ? true : false,
		reliable_loc_req ? reliable_loc_req->valueint : 0,
		serving_lmf_id &&
		!cJSON_IsNull(serving_lmf_id) ? strdup(serving_lmf_id->
		                                       valuestring) : NULL,
		lp_hap_type ? lp_hap_type_local_nonprim : NULL,
		evt_rpt_expected_area ? evt_rpt_expected_area_local_nonprim : NULL,
		reporting_ind ? reporting_ind_local_nonprim : NULL,
		integrity_requirements ? integrity_requirements_local_nonprim : NULL,
		up_loc_rep_info_af ? up_loc_rep_info_af_local_nonprim : NULL,
		requested_ranging_sl_result ? requested_ranging_sl_resultList : NULL,
		related_ues ? related_uesList : NULL,
		mapped_qo_s_eps ? mapped_qo_s_eps_local_nonprim : NULL,
		coordinate_id ? true : false,
		coordinate_id ? coordinate_id->valuedouble : 0
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
	if(service_coverageList) {
		list_for_each(service_coverageList, node) {
			free(node->data);
		}
		list_free(service_coverageList);
		service_coverageList = NULL;
	}
	if(periodic_event_info_local_nonprim) {
		periodic_event_info_free(periodic_event_info_local_nonprim);
		periodic_event_info_local_nonprim = NULL;
	}
	if(area_event_info_local_nonprim) {
		area_event_info_ext_free(area_event_info_local_nonprim);
		area_event_info_local_nonprim = NULL;
	}
	if(motion_event_info_local_nonprim) {
		motion_event_info_free(motion_event_info_local_nonprim);
		motion_event_info_local_nonprim = NULL;
	}
	if(ue_privacy_requirements_local_nonprim) {
		ue_privacy_requirements_free(
			ue_privacy_requirements_local_nonprim);
		ue_privacy_requirements_local_nonprim = NULL;
	}
	if(lp_hap_type_local_nonprim) {
		lp_hap_type_free(lp_hap_type_local_nonprim);
		lp_hap_type_local_nonprim = NULL;
	}
	if(evt_rpt_expected_area_local_nonprim) {
		geographic_area_free(evt_rpt_expected_area_local_nonprim);
		evt_rpt_expected_area_local_nonprim = NULL;
	}
	if(reporting_ind_local_nonprim) {
		input_data_reporting_ind_free(reporting_ind_local_nonprim);
		reporting_ind_local_nonprim = NULL;
	}
	if(integrity_requirements_local_nonprim) {
		integrity_requirements_free(integrity_requirements_local_nonprim);
		integrity_requirements_local_nonprim = NULL;
	}
	if(up_loc_rep_info_af_local_nonprim) {
		up_loc_rep_info_af_free(up_loc_rep_info_af_local_nonprim);
		up_loc_rep_info_af_local_nonprim = NULL;
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
	if(mapped_qo_s_eps_local_nonprim) {
		mapped_location_qo_s_eps_free(mapped_qo_s_eps_local_nonprim);
		mapped_qo_s_eps_local_nonprim = NULL;
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
