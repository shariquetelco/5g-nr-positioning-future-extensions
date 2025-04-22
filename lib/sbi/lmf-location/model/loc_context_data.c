#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_context_data.h"

loc_context_data_t *loc_context_data_create(char *amf_id,
                                            location_qo_s_t *location_qo_s,
                                            list_t *supported_gad_shapes,
                                            char *supi, char *gpsi,
                                            ldr_type_e ldr_type,
                                            char *hgmlc_call_back_uri,
                                            char *ldr_reference,
                                            periodic_event_info_t *periodic_event_info, area_event_info_t *area_event_info, motion_event_info_t *motion_event_info, event_report_message_t *event_report_message, event_reporting_status_t *event_reporting_status, ue_location_info_t *ue_location_info, bool is_c_io_t5_gs_optimisation, int c_io_t5_gs_optimisation, ecgi_t *ecgi, ncgi_t *ncgi, guami_t *guami, char *supported_features, char *ue_positioning_cap, char *scheduled_loc_time, indoor_outdoor_ind_e indoor_outdoor_ind, los_nlos_measure_ind_e los_nlos_measure_ind,
                                            up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria)
{
	loc_context_data_t *loc_context_data_local_var =
		malloc(sizeof(loc_context_data_t));

	loc_context_data_local_var->amf_id = amf_id;
	loc_context_data_local_var->location_qo_s = location_qo_s;
	loc_context_data_local_var->supported_gad_shapes = supported_gad_shapes;
	loc_context_data_local_var->supi = supi;
	loc_context_data_local_var->gpsi = gpsi;
	loc_context_data_local_var->ldr_type = ldr_type;
	loc_context_data_local_var->hgmlc_call_back_uri = hgmlc_call_back_uri;
	loc_context_data_local_var->ldr_reference = ldr_reference;
	loc_context_data_local_var->periodic_event_info = periodic_event_info;
	loc_context_data_local_var->area_event_info = area_event_info;
	loc_context_data_local_var->motion_event_info = motion_event_info;
	loc_context_data_local_var->event_report_message = event_report_message;
	loc_context_data_local_var->event_reporting_status =
		event_reporting_status;
	loc_context_data_local_var->ue_location_info = ue_location_info;
	loc_context_data_local_var->is_c_io_t5_gs_optimisation =
		is_c_io_t5_gs_optimisation;
	loc_context_data_local_var->c_io_t5_gs_optimisation =
		c_io_t5_gs_optimisation;
	loc_context_data_local_var->ecgi = ecgi;
	loc_context_data_local_var->ncgi = ncgi;
	loc_context_data_local_var->guami = guami;
	loc_context_data_local_var->supported_features = supported_features;
	loc_context_data_local_var->ue_positioning_cap = ue_positioning_cap;
	loc_context_data_local_var->scheduled_loc_time = scheduled_loc_time;
	loc_context_data_local_var->indoor_outdoor_ind = indoor_outdoor_ind;
	loc_context_data_local_var->los_nlos_measure_ind = los_nlos_measure_ind;
	loc_context_data_local_var->up_cum_evt_rpt_criteria =
		up_cum_evt_rpt_criteria;

	return loc_context_data_local_var;
}

void loc_context_data_free(loc_context_data_t *loc_context_data) {
	lnode_t *node = NULL;

	if(NULL == loc_context_data) {
		return;
	}
	if(loc_context_data->amf_id) {
		free(loc_context_data->amf_id);
		loc_context_data->amf_id = NULL;
	}
	if(loc_context_data->location_qo_s) {
		location_qo_s_free(loc_context_data->location_qo_s);
		loc_context_data->location_qo_s = NULL;
	}
	if(loc_context_data->supported_gad_shapes) {
		list_free(loc_context_data->supported_gad_shapes);
		loc_context_data->supported_gad_shapes = NULL;
	}
	if(loc_context_data->supi) {
		free(loc_context_data->supi);
		loc_context_data->supi = NULL;
	}
	if(loc_context_data->gpsi) {
		free(loc_context_data->gpsi);
		loc_context_data->gpsi = NULL;
	}
	if(loc_context_data->hgmlc_call_back_uri) {
		free(loc_context_data->hgmlc_call_back_uri);
		loc_context_data->hgmlc_call_back_uri = NULL;
	}
	if(loc_context_data->ldr_reference) {
		free(loc_context_data->ldr_reference);
		loc_context_data->ldr_reference = NULL;
	}
	if(loc_context_data->periodic_event_info) {
		periodic_event_info_free(loc_context_data->periodic_event_info);
		loc_context_data->periodic_event_info = NULL;
	}
	if(loc_context_data->area_event_info) {
		area_event_info_free(loc_context_data->area_event_info);
		loc_context_data->area_event_info = NULL;
	}
	if(loc_context_data->motion_event_info) {
		motion_event_info_free(loc_context_data->motion_event_info);
		loc_context_data->motion_event_info = NULL;
	}
	if(loc_context_data->event_report_message) {
		event_report_message_free(loc_context_data->event_report_message);
		loc_context_data->event_report_message = NULL;
	}
	if(loc_context_data->event_reporting_status) {
		event_reporting_status_free(
			loc_context_data->event_reporting_status);
		loc_context_data->event_reporting_status = NULL;
	}
	if(loc_context_data->ue_location_info) {
		ue_location_info_free(loc_context_data->ue_location_info);
		loc_context_data->ue_location_info = NULL;
	}
	if(loc_context_data->ecgi) {
		ecgi_free(loc_context_data->ecgi);
		loc_context_data->ecgi = NULL;
	}
	if(loc_context_data->ncgi) {
		ncgi_free(loc_context_data->ncgi);
		loc_context_data->ncgi = NULL;
	}
	if(loc_context_data->guami) {
		guami_free(loc_context_data->guami);
		loc_context_data->guami = NULL;
	}
	if(loc_context_data->supported_features) {
		free(loc_context_data->supported_features);
		loc_context_data->supported_features = NULL;
	}
	if(loc_context_data->ue_positioning_cap) {
		free(loc_context_data->ue_positioning_cap);
		loc_context_data->ue_positioning_cap = NULL;
	}
	if(loc_context_data->scheduled_loc_time) {
		free(loc_context_data->scheduled_loc_time);
		loc_context_data->scheduled_loc_time = NULL;
	}
	if(loc_context_data->up_cum_evt_rpt_criteria) {
		up_cum_evt_rpt_criteria_free(
			loc_context_data->up_cum_evt_rpt_criteria);
		loc_context_data->up_cum_evt_rpt_criteria = NULL;
	}
	free(loc_context_data);
}

cJSON *loc_context_data_convertToJSON(loc_context_data_t *loc_context_data) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(loc_context_data == NULL) {
		printf(
			"loc_context_data_convertToJSON() failed [LocContextData]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!loc_context_data->amf_id) {
		printf("loc_context_data_convertToJSON() failed [amf_id]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "amfId",
	                           loc_context_data->amf_id) == NULL)
	{
		printf("loc_context_data_convertToJSON() failed [amf_id]");
		goto end;
	}

	if(loc_context_data->location_qo_s) {
		cJSON *location_qo_s_local_JSON = location_qo_s_convertToJSON(
			loc_context_data->location_qo_s);
		if(location_qo_s_local_JSON == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [location_qo_s]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationQoS",
		                      location_qo_s_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [location_qo_s]");
			goto end;
		}
	}

	if(loc_context_data->supported_gad_shapes !=
	   supported_gad_shapes_NULL)
	{
		cJSON *supported_gad_shapesList = cJSON_AddArrayToObject(item,
		                                                         "supportedGADShapes");
		if(supported_gad_shapesList == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [supported_gad_shapes]");
			goto end;
		}
		list_for_each(loc_context_data->supported_gad_shapes, node) {
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
					"loc_context_data_convertToJSON() failed [supported_gad_shapes]");
				goto end;
			}
		}
	}

	if(loc_context_data->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           loc_context_data->supi) == NULL)
		{
			printf("loc_context_data_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(loc_context_data->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           loc_context_data->gpsi) == NULL)
		{
			printf("loc_context_data_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(loc_context_data->ldr_type == ldr_type_NULL) {
		printf("loc_context_data_convertToJSON() failed [ldr_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ldrType",
	                           ldr_type_ToString(
					   loc_context_data->ldr_type)) == NULL)
	{
		printf("loc_context_data_convertToJSON() failed [ldr_type]");
		goto end;
	}

	if(!loc_context_data->hgmlc_call_back_uri) {
		printf(
			"loc_context_data_convertToJSON() failed [hgmlc_call_back_uri]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "hgmlcCallBackURI",
	                           loc_context_data->hgmlc_call_back_uri) ==
	   NULL)
	{
		printf(
			"loc_context_data_convertToJSON() failed [hgmlc_call_back_uri]");
		goto end;
	}

	if(!loc_context_data->ldr_reference) {
		printf("loc_context_data_convertToJSON() failed [ldr_reference]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ldrReference",
	                           loc_context_data->ldr_reference) == NULL)
	{
		printf("loc_context_data_convertToJSON() failed [ldr_reference]");
		goto end;
	}

	if(loc_context_data->periodic_event_info) {
		cJSON *periodic_event_info_local_JSON =
			periodic_event_info_convertToJSON(
				loc_context_data->periodic_event_info);
		if(periodic_event_info_local_JSON == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [periodic_event_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "periodicEventInfo",
		                      periodic_event_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [periodic_event_info]");
			goto end;
		}
	}

	if(loc_context_data->area_event_info) {
		cJSON *area_event_info_local_JSON =
			area_event_info_convertToJSON(
				loc_context_data->area_event_info);
		if(area_event_info_local_JSON == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [area_event_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "areaEventInfo",
		                      area_event_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [area_event_info]");
			goto end;
		}
	}

	if(loc_context_data->motion_event_info) {
		cJSON *motion_event_info_local_JSON =
			motion_event_info_convertToJSON(
				loc_context_data->motion_event_info);
		if(motion_event_info_local_JSON == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [motion_event_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "motionEventInfo",
		                      motion_event_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [motion_event_info]");
			goto end;
		}
	}

	if(!loc_context_data->event_report_message) {
		printf(
			"loc_context_data_convertToJSON() failed [event_report_message]");
		return NULL;
	}
	cJSON *event_report_message_local_JSON =
		event_report_message_convertToJSON(
			loc_context_data->event_report_message);
	if(event_report_message_local_JSON == NULL) {
		printf(
			"loc_context_data_convertToJSON() failed [event_report_message]");
		goto end;
	}
	cJSON_AddItemToObject(item, "eventReportMessage",
	                      event_report_message_local_JSON);
	if(item->child == NULL) {
		printf(
			"loc_context_data_convertToJSON() failed [event_report_message]");
		goto end;
	}

	if(loc_context_data->event_reporting_status) {
		cJSON *event_reporting_status_local_JSON =
			event_reporting_status_convertToJSON(
				loc_context_data->event_reporting_status);
		if(event_reporting_status_local_JSON == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [event_reporting_status]");
			goto end;
		}
		cJSON_AddItemToObject(item, "eventReportingStatus",
		                      event_reporting_status_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [event_reporting_status]");
			goto end;
		}
	}

	if(loc_context_data->ue_location_info) {
		cJSON *ue_location_info_local_JSON =
			ue_location_info_convertToJSON(
				loc_context_data->ue_location_info);
		if(ue_location_info_local_JSON == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [ue_location_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueLocationInfo",
		                      ue_location_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [ue_location_info]");
			goto end;
		}
	}

	if(loc_context_data->is_c_io_t5_gs_optimisation) {
		if(cJSON_AddBoolToObject(item, "cIoT5GSOptimisation",
		                         loc_context_data->
		                         c_io_t5_gs_optimisation) == NULL)
		{
			printf(
				"loc_context_data_convertToJSON() failed [c_io_t5_gs_optimisation]");
			goto end;
		}
	}

	if(loc_context_data->ecgi) {
		cJSON *ecgi_local_JSON = ecgi_convertToJSON(
			loc_context_data->ecgi);
		if(ecgi_local_JSON == NULL) {
			printf("loc_context_data_convertToJSON() failed [ecgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
		if(item->child == NULL) {
			printf("loc_context_data_convertToJSON() failed [ecgi]");
			goto end;
		}
	}

	if(loc_context_data->ncgi) {
		cJSON *ncgi_local_JSON = ncgi_convertToJSON(
			loc_context_data->ncgi);
		if(ncgi_local_JSON == NULL) {
			printf("loc_context_data_convertToJSON() failed [ncgi]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
		if(item->child == NULL) {
			printf("loc_context_data_convertToJSON() failed [ncgi]");
			goto end;
		}
	}

	if(loc_context_data->guami) {
		cJSON *guami_local_JSON = guami_convertToJSON(
			loc_context_data->guami);
		if(guami_local_JSON == NULL) {
			printf("loc_context_data_convertToJSON() failed [guami]");
			goto end;
		}
		cJSON_AddItemToObject(item, "guami", guami_local_JSON);
		if(item->child == NULL) {
			printf("loc_context_data_convertToJSON() failed [guami]");
			goto end;
		}
	}

	if(loc_context_data->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           loc_context_data->supported_features)
		   == NULL)
		{
			printf(
				"loc_context_data_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(loc_context_data->ue_positioning_cap) {
		if(cJSON_AddStringToObject(item, "uePositioningCap",
		                           loc_context_data->ue_positioning_cap)
		   == NULL)
		{
			printf(
				"loc_context_data_convertToJSON() failed [ue_positioning_cap]");
			goto end;
		}
	}

	if(loc_context_data->scheduled_loc_time) {
		if(cJSON_AddStringToObject(item, "scheduledLocTime",
		                           loc_context_data->scheduled_loc_time)
		   == NULL)
		{
			printf(
				"loc_context_data_convertToJSON() failed [scheduled_loc_time]");
			goto end;
		}
	}

	if(loc_context_data->indoor_outdoor_ind != indoor_outdoor_ind_NULL) {
		if(cJSON_AddStringToObject(item, "indoorOutdoorInd",
		                           indoor_outdoor_ind_ToString(
						   loc_context_data->
						   indoor_outdoor_ind)) == NULL)
		{
			printf(
				"loc_context_data_convertToJSON() failed [indoor_outdoor_ind]");
			goto end;
		}
	}

	if(loc_context_data->los_nlos_measure_ind !=
	   los_nlos_measure_ind_NULL)
	{
		if(cJSON_AddStringToObject(item, "losNlosMeasureInd",
		                           los_nlos_measure_ind_ToString(
						   loc_context_data->
						   los_nlos_measure_ind))
		   == NULL)
		{
			printf(
				"loc_context_data_convertToJSON() failed [los_nlos_measure_ind]");
			goto end;
		}
	}

	if(loc_context_data->up_cum_evt_rpt_criteria) {
		cJSON *up_cum_evt_rpt_criteria_local_JSON =
			up_cum_evt_rpt_criteria_convertToJSON(
				loc_context_data->up_cum_evt_rpt_criteria);
		if(up_cum_evt_rpt_criteria_local_JSON == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upCumEvtRptCriteria",
		                      up_cum_evt_rpt_criteria_local_JSON);
		if(item->child == NULL) {
			printf(
				"loc_context_data_convertToJSON() failed [up_cum_evt_rpt_criteria]");
			goto end;
		}
	}

end:
	return item;
}

loc_context_data_t *loc_context_data_parseFromJSON(cJSON *loc_context_dataJSON)
{
	loc_context_data_t *loc_context_data_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *amf_id = NULL;
	cJSON *location_qo_s = NULL;
	location_qo_s_t *location_qo_s_local_nonprim = NULL;
	cJSON *supported_gad_shapes = NULL;
	list_t *supported_gad_shapesList = NULL;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	cJSON *ldr_type = NULL;
	ldr_type_e ldr_typeVariable = 0;
	cJSON *hgmlc_call_back_uri = NULL;
	cJSON *ldr_reference = NULL;
	cJSON *periodic_event_info = NULL;
	periodic_event_info_t *periodic_event_info_local_nonprim = NULL;
	cJSON *area_event_info = NULL;
	area_event_info_t *area_event_info_local_nonprim = NULL;
	cJSON *motion_event_info = NULL;
	motion_event_info_t *motion_event_info_local_nonprim = NULL;
	cJSON *event_report_message = NULL;
	event_report_message_t *event_report_message_local_nonprim = NULL;
	cJSON *event_reporting_status = NULL;
	event_reporting_status_t *event_reporting_status_local_nonprim = NULL;
	cJSON *ue_location_info = NULL;
	ue_location_info_t *ue_location_info_local_nonprim = NULL;
	cJSON *c_io_t5_gs_optimisation = NULL;
	cJSON *ecgi = NULL;
	ecgi_t *ecgi_local_nonprim = NULL;
	cJSON *ncgi = NULL;
	ncgi_t *ncgi_local_nonprim = NULL;
	cJSON *guami = NULL;
	guami_t *guami_local_nonprim = NULL;
	cJSON *supported_features = NULL;
	cJSON *ue_positioning_cap = NULL;
	cJSON *scheduled_loc_time = NULL;
	cJSON *indoor_outdoor_ind = NULL;
	indoor_outdoor_ind_e indoor_outdoor_indVariable = 0;
	cJSON *los_nlos_measure_ind = NULL;
	los_nlos_measure_ind_e los_nlos_measure_indVariable = 0;
	cJSON *up_cum_evt_rpt_criteria = NULL;
	up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_nonprim = NULL;
	amf_id =
		cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "amfId");
	if(!amf_id) {
		printf("loc_context_data_parseFromJSON() failed [amf_id]");
		goto end;
	}
	if(!cJSON_IsString(amf_id)) {
		printf("loc_context_data_parseFromJSON() failed [amf_id]");
		goto end;
	}

	location_qo_s = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON,
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

	supported_gad_shapes = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "supportedGADShapes");
	if(supported_gad_shapes) {
		cJSON *supported_gad_shapes_local = NULL;
		if(!cJSON_IsArray(supported_gad_shapes)) {
			printf(
				"loc_context_data_parseFromJSON() failed [supported_gad_shapes]");
			goto end;
		}

		supported_gad_shapesList = list_create();

		cJSON_ArrayForEach(supported_gad_shapes_local,
		                   supported_gad_shapes) {
			supported_gad_shapes_e localEnum =
				supported_gad_shapes_NULL;
			if(!cJSON_IsString(supported_gad_shapes_local)) {
				printf(
					"loc_context_data_parseFromJSON() failed [supported_gad_shapes]");
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
				"loc_context_data_parseFromJSON() failed: Expected supported_gad_shapesList to not be empty (after ignoring unsupported enum values).");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("loc_context_data_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("loc_context_data_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	ldr_type = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON,
	                                            "ldrType");
	if(!ldr_type) {
		printf("loc_context_data_parseFromJSON() failed [ldr_type]");
		goto end;
	}
	if(!cJSON_IsString(ldr_type)) {
		printf("loc_context_data_parseFromJSON() failed [ldr_type]");
		goto end;
	}
	ldr_typeVariable = ldr_type_FromString(ldr_type->valuestring);

	hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "hgmlcCallBackURI");
	if(!hgmlc_call_back_uri) {
		printf(
			"loc_context_data_parseFromJSON() failed [hgmlc_call_back_uri]");
		goto end;
	}
	if(!cJSON_IsString(hgmlc_call_back_uri)) {
		printf(
			"loc_context_data_parseFromJSON() failed [hgmlc_call_back_uri]");
		goto end;
	}

	ldr_reference = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON,
	                                                 "ldrReference");
	if(!ldr_reference) {
		printf("loc_context_data_parseFromJSON() failed [ldr_reference]");
		goto end;
	}
	if(!cJSON_IsString(ldr_reference)) {
		printf("loc_context_data_parseFromJSON() failed [ldr_reference]");
		goto end;
	}

	periodic_event_info = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "periodicEventInfo");
	if(periodic_event_info) {
		periodic_event_info_local_nonprim =
			periodic_event_info_parseFromJSON(periodic_event_info);
		if(!periodic_event_info_local_nonprim) {
			printf(
				"periodic_event_info_parseFromJSON failed [periodic_event_info]");
			goto end;
		}
	}

	area_event_info = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON,
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

	motion_event_info = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "motionEventInfo");
	if(motion_event_info) {
		motion_event_info_local_nonprim =
			motion_event_info_parseFromJSON(motion_event_info);
		if(!motion_event_info_local_nonprim) {
			printf(
				"motion_event_info_parseFromJSON failed [motion_event_info]");
			goto end;
		}
	}

	event_report_message = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "eventReportMessage");
	if(!event_report_message) {
		printf(
			"loc_context_data_parseFromJSON() failed [event_report_message]");
		goto end;
	}
	event_report_message_local_nonprim = event_report_message_parseFromJSON(
		event_report_message);
	if(!event_report_message_local_nonprim) {
		printf(
			"event_report_message_parseFromJSON failed [event_report_message]");
		goto end;
	}

	event_reporting_status = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "eventReportingStatus");
	if(event_reporting_status) {
		event_reporting_status_local_nonprim =
			event_reporting_status_parseFromJSON(
				event_reporting_status);
		if(!event_reporting_status_local_nonprim) {
			printf(
				"event_reporting_status_parseFromJSON failed [event_reporting_status]");
			goto end;
		}
	}

	ue_location_info = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "ueLocationInfo");
	if(ue_location_info) {
		ue_location_info_local_nonprim = ue_location_info_parseFromJSON(
			ue_location_info);
		if(!ue_location_info_local_nonprim) {
			printf(
				"ue_location_info_parseFromJSON failed [ue_location_info]");
			goto end;
		}
	}

	c_io_t5_gs_optimisation = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "cIoT5GSOptimisation");
	if(c_io_t5_gs_optimisation) {
		if(!cJSON_IsBool(c_io_t5_gs_optimisation)) {
			printf(
				"loc_context_data_parseFromJSON() failed [c_io_t5_gs_optimisation]");
			goto end;
		}
	}

	ecgi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ecgi");
	if(ecgi) {
		ecgi_local_nonprim = ecgi_parseFromJSON(ecgi);
		if(!ecgi_local_nonprim) {
			printf("ecgi_parseFromJSON failed [ecgi]");
			goto end;
		}
	}

	ncgi = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "ncgi");
	if(ncgi) {
		ncgi_local_nonprim = ncgi_parseFromJSON(ncgi);
		if(!ncgi_local_nonprim) {
			printf("ncgi_parseFromJSON failed [ncgi]");
			goto end;
		}
	}

	guami = cJSON_GetObjectItemCaseSensitive(loc_context_dataJSON, "guami");
	if(guami) {
		guami_local_nonprim = guami_parseFromJSON(guami);
		if(!guami_local_nonprim) {
			printf("guami_parseFromJSON failed [guami]");
			goto end;
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"loc_context_data_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	ue_positioning_cap = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "uePositioningCap");
	if(ue_positioning_cap) {
		if(!cJSON_IsString(ue_positioning_cap) &&
		   !cJSON_IsNull(ue_positioning_cap))
		{
			printf(
				"loc_context_data_parseFromJSON() failed [ue_positioning_cap]");
			goto end;
		}
	}

	scheduled_loc_time = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "scheduledLocTime");
	if(scheduled_loc_time) {
		if(!cJSON_IsString(scheduled_loc_time) &&
		   !cJSON_IsNull(scheduled_loc_time))
		{
			printf(
				"loc_context_data_parseFromJSON() failed [scheduled_loc_time]");
			goto end;
		}
	}

	indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "indoorOutdoorInd");
	if(indoor_outdoor_ind) {
		if(!cJSON_IsString(indoor_outdoor_ind)) {
			printf(
				"loc_context_data_parseFromJSON() failed [indoor_outdoor_ind]");
			goto end;
		}
		indoor_outdoor_indVariable = indoor_outdoor_ind_FromString(
			indoor_outdoor_ind->valuestring);
	}

	los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "losNlosMeasureInd");
	if(los_nlos_measure_ind) {
		if(!cJSON_IsString(los_nlos_measure_ind)) {
			printf(
				"loc_context_data_parseFromJSON() failed [los_nlos_measure_ind]");
			goto end;
		}
		los_nlos_measure_indVariable = los_nlos_measure_ind_FromString(
			los_nlos_measure_ind->valuestring);
	}

	up_cum_evt_rpt_criteria = cJSON_GetObjectItemCaseSensitive(
		loc_context_dataJSON, "upCumEvtRptCriteria");
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

	loc_context_data_local_var = loc_context_data_create(
		strdup(amf_id->valuestring),
		location_qo_s ? location_qo_s_local_nonprim : NULL,
		supported_gad_shapes ? supported_gad_shapesList : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		ldr_typeVariable,
		strdup(hgmlc_call_back_uri->valuestring),
		strdup(
			ldr_reference->valuestring),
		periodic_event_info ? periodic_event_info_local_nonprim : NULL,
		area_event_info ? area_event_info_local_nonprim : NULL,
		motion_event_info ? motion_event_info_local_nonprim : NULL,
		event_report_message_local_nonprim,
		event_reporting_status ? event_reporting_status_local_nonprim : NULL,
		ue_location_info ? ue_location_info_local_nonprim : NULL,
		c_io_t5_gs_optimisation ? true : false,
		c_io_t5_gs_optimisation ? c_io_t5_gs_optimisation->valueint : 0,
		ecgi ? ecgi_local_nonprim : NULL,
		ncgi ? ncgi_local_nonprim : NULL,
		guami ? guami_local_nonprim : NULL,
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL,
		ue_positioning_cap &&
		!cJSON_IsNull(ue_positioning_cap) ? strdup(ue_positioning_cap->
		                                           valuestring) : NULL,
		scheduled_loc_time &&
		!cJSON_IsNull(scheduled_loc_time) ? strdup(scheduled_loc_time->
		                                           valuestring) : NULL,
		indoor_outdoor_ind ? indoor_outdoor_indVariable : 0,
		los_nlos_measure_ind ? los_nlos_measure_indVariable : 0,
		up_cum_evt_rpt_criteria ? up_cum_evt_rpt_criteria_local_nonprim : NULL
		);

	return loc_context_data_local_var;
end:
	if(location_qo_s_local_nonprim) {
		location_qo_s_free(location_qo_s_local_nonprim);
		location_qo_s_local_nonprim = NULL;
	}
	if(supported_gad_shapesList) {
		list_free(supported_gad_shapesList);
		supported_gad_shapesList = NULL;
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
	if(event_report_message_local_nonprim) {
		event_report_message_free(event_report_message_local_nonprim);
		event_report_message_local_nonprim = NULL;
	}
	if(event_reporting_status_local_nonprim) {
		event_reporting_status_free(event_reporting_status_local_nonprim);
		event_reporting_status_local_nonprim = NULL;
	}
	if(ue_location_info_local_nonprim) {
		ue_location_info_free(ue_location_info_local_nonprim);
		ue_location_info_local_nonprim = NULL;
	}
	if(ecgi_local_nonprim) {
		ecgi_free(ecgi_local_nonprim);
		ecgi_local_nonprim = NULL;
	}
	if(ncgi_local_nonprim) {
		ncgi_free(ncgi_local_nonprim);
		ncgi_local_nonprim = NULL;
	}
	if(guami_local_nonprim) {
		guami_free(guami_local_nonprim);
		guami_local_nonprim = NULL;
	}
	if(up_cum_evt_rpt_criteria_local_nonprim) {
		up_cum_evt_rpt_criteria_free(
			up_cum_evt_rpt_criteria_local_nonprim);
		up_cum_evt_rpt_criteria_local_nonprim = NULL;
	}
	return NULL;
}

loc_context_data_t *loc_context_data_copy(loc_context_data_t	*dst,
                                          loc_context_data_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = loc_context_data_convertToJSON(src);
	if(!item) {
		printf("loc_context_data_convertToJSON() failed");
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

	loc_context_data_free(dst);
	dst = loc_context_data_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
