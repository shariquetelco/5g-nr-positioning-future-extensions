#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_data_ext.h"

location_data_ext_t *location_data_ext_create(char *gpsi, char *supi,
                                              geographic_area_t *location_estimate, civic_address_t *civic_address, local_area_t *local_location_estimate, bool is_age_of_location_estimate, int age_of_location_estimate, char *timestamp_of_location_estimate, list_t *positioning_data_list, list_t *gnss_positioning_data_list, accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator, velocity_estimate_t *ue_velocity, char *ldr_reference, bool is_altitude, double altitude, char *serving_lmf_identification, location_privacy_ver_result_t *location_privacy_ver_result, success_type_e success_type, minor_location_qo_s_t *achieved_qos, bool is_direct_report_ind, int direct_report_ind, periodic_event_info_t *accepted_periodic_event_info, high_accuracy_gnss_metrics_t *ha_gnss_metrics, los_nlos_measure_ind_e los_nlos_measure_ind, indoor_outdoor_ind_e indoor_outdoor_ind, char *related_applicationlayer_id, range_direction_t *distance_direction, model_2_d_relative_location_t *_2d_relative_location, model_3_d_relative_location_t *_3d_relative_location,
                                              velocity_estimate_t *relative_velocity)
{
	location_data_ext_t *location_data_ext_local_var =
		malloc(sizeof(location_data_ext_t));

	location_data_ext_local_var->gpsi = gpsi;
	location_data_ext_local_var->supi = supi;
	location_data_ext_local_var->location_estimate = location_estimate;
	location_data_ext_local_var->civic_address = civic_address;
	location_data_ext_local_var->local_location_estimate =
		local_location_estimate;
	location_data_ext_local_var->is_age_of_location_estimate =
		is_age_of_location_estimate;
	location_data_ext_local_var->age_of_location_estimate =
		age_of_location_estimate;
	location_data_ext_local_var->timestamp_of_location_estimate =
		timestamp_of_location_estimate;
	location_data_ext_local_var->positioning_data_list =
		positioning_data_list;
	location_data_ext_local_var->gnss_positioning_data_list =
		gnss_positioning_data_list;
	location_data_ext_local_var->accuracy_fulfilment_indicator =
		accuracy_fulfilment_indicator;
	location_data_ext_local_var->ue_velocity = ue_velocity;
	location_data_ext_local_var->ldr_reference = ldr_reference;
	location_data_ext_local_var->is_altitude = is_altitude;
	location_data_ext_local_var->altitude = altitude;
	location_data_ext_local_var->serving_lmf_identification =
		serving_lmf_identification;
	location_data_ext_local_var->location_privacy_ver_result =
		location_privacy_ver_result;
	location_data_ext_local_var->success_type = success_type;
	location_data_ext_local_var->achieved_qos = achieved_qos;
	location_data_ext_local_var->is_direct_report_ind =
		is_direct_report_ind;
	location_data_ext_local_var->direct_report_ind = direct_report_ind;
	location_data_ext_local_var->accepted_periodic_event_info =
		accepted_periodic_event_info;
	location_data_ext_local_var->ha_gnss_metrics = ha_gnss_metrics;
	location_data_ext_local_var->los_nlos_measure_ind =
		los_nlos_measure_ind;
	location_data_ext_local_var->indoor_outdoor_ind = indoor_outdoor_ind;
	location_data_ext_local_var->related_applicationlayer_id =
		related_applicationlayer_id;
	location_data_ext_local_var->distance_direction = distance_direction;
	location_data_ext_local_var->_2d_relative_location =
		_2d_relative_location;
	location_data_ext_local_var->_3d_relative_location =
		_3d_relative_location;
	location_data_ext_local_var->relative_velocity = relative_velocity;

	return location_data_ext_local_var;
}

void location_data_ext_free(location_data_ext_t *location_data_ext) {
	lnode_t *node = NULL;

	if(NULL == location_data_ext) {
		return;
	}
	if(location_data_ext->gpsi) {
		free(location_data_ext->gpsi);
		location_data_ext->gpsi = NULL;
	}
	if(location_data_ext->supi) {
		free(location_data_ext->supi);
		location_data_ext->supi = NULL;
	}
	if(location_data_ext->location_estimate) {
		geographic_area_free(location_data_ext->location_estimate);
		location_data_ext->location_estimate = NULL;
	}
	if(location_data_ext->civic_address) {
		civic_address_free(location_data_ext->civic_address);
		location_data_ext->civic_address = NULL;
	}
	if(location_data_ext->local_location_estimate) {
		local_area_free(location_data_ext->local_location_estimate);
		location_data_ext->local_location_estimate = NULL;
	}
	if(location_data_ext->timestamp_of_location_estimate) {
		free(location_data_ext->timestamp_of_location_estimate);
		location_data_ext->timestamp_of_location_estimate = NULL;
	}
	if(location_data_ext->positioning_data_list) {
		list_for_each(location_data_ext->positioning_data_list, node) {
			positioning_method_and_usage_free(node->data);
		}
		list_free(location_data_ext->positioning_data_list);
		location_data_ext->positioning_data_list = NULL;
	}
	if(location_data_ext->gnss_positioning_data_list) {
		list_for_each(location_data_ext->gnss_positioning_data_list,
		              node) {
			gnss_positioning_method_and_usage_free(node->data);
		}
		list_free(location_data_ext->gnss_positioning_data_list);
		location_data_ext->gnss_positioning_data_list = NULL;
	}
	if(location_data_ext->ue_velocity) {
		velocity_estimate_free(location_data_ext->ue_velocity);
		location_data_ext->ue_velocity = NULL;
	}
	if(location_data_ext->ldr_reference) {
		free(location_data_ext->ldr_reference);
		location_data_ext->ldr_reference = NULL;
	}
	if(location_data_ext->serving_lmf_identification) {
		free(location_data_ext->serving_lmf_identification);
		location_data_ext->serving_lmf_identification = NULL;
	}
	if(location_data_ext->location_privacy_ver_result) {
		location_privacy_ver_result_free(
			location_data_ext->location_privacy_ver_result);
		location_data_ext->location_privacy_ver_result = NULL;
	}
	if(location_data_ext->achieved_qos) {
		minor_location_qo_s_free(location_data_ext->achieved_qos);
		location_data_ext->achieved_qos = NULL;
	}
	if(location_data_ext->accepted_periodic_event_info) {
		periodic_event_info_free(
			location_data_ext->accepted_periodic_event_info);
		location_data_ext->accepted_periodic_event_info = NULL;
	}
	if(location_data_ext->ha_gnss_metrics) {
		high_accuracy_gnss_metrics_free(
			location_data_ext->ha_gnss_metrics);
		location_data_ext->ha_gnss_metrics = NULL;
	}
	if(location_data_ext->related_applicationlayer_id) {
		free(location_data_ext->related_applicationlayer_id);
		location_data_ext->related_applicationlayer_id = NULL;
	}
	if(location_data_ext->distance_direction) {
		range_direction_free(location_data_ext->distance_direction);
		location_data_ext->distance_direction = NULL;
	}
	if(location_data_ext->_2d_relative_location) {
		model_2_d_relative_location_free(
			location_data_ext->_2d_relative_location);
		location_data_ext->_2d_relative_location = NULL;
	}
	if(location_data_ext->_3d_relative_location) {
		model_3_d_relative_location_free(
			location_data_ext->_3d_relative_location);
		location_data_ext->_3d_relative_location = NULL;
	}
	if(location_data_ext->relative_velocity) {
		velocity_estimate_free(location_data_ext->relative_velocity);
		location_data_ext->relative_velocity = NULL;
	}
	free(location_data_ext);
}

cJSON *location_data_ext_convertToJSON(location_data_ext_t *location_data_ext) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(location_data_ext == NULL) {
		printf(
			"location_data_ext_convertToJSON() failed [LocationDataExt]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(location_data_ext->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           location_data_ext->gpsi) == NULL)
		{
			printf("location_data_ext_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(location_data_ext->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           location_data_ext->supi) == NULL)
		{
			printf("location_data_ext_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(location_data_ext->location_estimate) {
		cJSON *location_estimate_local_JSON =
			geographic_area_convertToJSON(
				location_data_ext->location_estimate);
		if(location_estimate_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [location_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationEstimate",
		                      location_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [location_estimate]");
			goto end;
		}
	}

	if(location_data_ext->civic_address) {
		cJSON *civic_address_local_JSON = civic_address_convertToJSON(
			location_data_ext->civic_address);
		if(civic_address_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [civic_address]");
			goto end;
		}
		cJSON_AddItemToObject(item, "civicAddress",
		                      civic_address_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [civic_address]");
			goto end;
		}
	}

	if(location_data_ext->local_location_estimate) {
		cJSON *local_location_estimate_local_JSON =
			local_area_convertToJSON(
				location_data_ext->local_location_estimate);
		if(local_location_estimate_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [local_location_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "localLocationEstimate",
		                      local_location_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [local_location_estimate]");
			goto end;
		}
	}

	if(location_data_ext->is_age_of_location_estimate) {
		if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate",
		                           location_data_ext->
		                           age_of_location_estimate) == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	if(location_data_ext->timestamp_of_location_estimate) {
		if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate",
		                           location_data_ext->
		                           timestamp_of_location_estimate) ==
		   NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	if(location_data_ext->positioning_data_list) {
		cJSON *positioning_data_listList = cJSON_AddArrayToObject(item,
		                                                          "positioningDataList");
		if(positioning_data_listList == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [positioning_data_list]");
			goto end;
		}
		list_for_each(location_data_ext->positioning_data_list, node) {
			cJSON *itemLocal =
				positioning_method_and_usage_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"location_data_ext_convertToJSON() failed [positioning_data_list]");
				goto end;
			}
			cJSON_AddItemToArray(positioning_data_listList,
			                     itemLocal);
		}
	}

	if(location_data_ext->gnss_positioning_data_list) {
		cJSON *gnss_positioning_data_listList = cJSON_AddArrayToObject(
			item, "gnssPositioningDataList");
		if(gnss_positioning_data_listList == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [gnss_positioning_data_list]");
			goto end;
		}
		list_for_each(location_data_ext->gnss_positioning_data_list,
		              node) {
			cJSON *itemLocal =
				gnss_positioning_method_and_usage_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"location_data_ext_convertToJSON() failed [gnss_positioning_data_list]");
				goto end;
			}
			cJSON_AddItemToArray(gnss_positioning_data_listList,
			                     itemLocal);
		}
	}

	if(location_data_ext->accuracy_fulfilment_indicator !=
	   accuracy_fulfilment_indicator_NULL)
	{
		if(cJSON_AddStringToObject(item, "accuracyFulfilmentIndicator",
		                           accuracy_fulfilment_indicator_ToString(
						   location_data_ext->
						   accuracy_fulfilment_indicator))
		   == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [accuracy_fulfilment_indicator]");
			goto end;
		}
	}

	if(location_data_ext->ue_velocity) {
		cJSON *ue_velocity_local_JSON = velocity_estimate_convertToJSON(
			location_data_ext->ue_velocity);
		if(ue_velocity_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [ue_velocity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueVelocity",
		                      ue_velocity_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [ue_velocity]");
			goto end;
		}
	}

	if(location_data_ext->ldr_reference) {
		if(cJSON_AddStringToObject(item, "ldrReference",
		                           location_data_ext->ldr_reference) ==
		   NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [ldr_reference]");
			goto end;
		}
	}

	if(location_data_ext->is_altitude) {
		if(cJSON_AddNumberToObject(item, "altitude",
		                           location_data_ext->altitude) == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [altitude]");
			goto end;
		}
	}

	if(location_data_ext->serving_lmf_identification) {
		if(cJSON_AddStringToObject(item, "servingLMFIdentification",
		                           location_data_ext->
		                           serving_lmf_identification) == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [serving_lmf_identification]");
			goto end;
		}
	}

	if(location_data_ext->location_privacy_ver_result) {
		cJSON *location_privacy_ver_result_local_JSON =
			location_privacy_ver_result_convertToJSON(
				location_data_ext->location_privacy_ver_result);
		if(location_privacy_ver_result_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [location_privacy_ver_result]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationPrivacyVerResult",
		                      location_privacy_ver_result_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [location_privacy_ver_result]");
			goto end;
		}
	}

	if(location_data_ext->success_type != success_type_NULL) {
		if(cJSON_AddStringToObject(item, "successType",
		                           success_type_ToString(
						   location_data_ext->
						   success_type)) ==
		   NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [success_type]");
			goto end;
		}
	}

	if(location_data_ext->achieved_qos) {
		cJSON *achieved_qos_local_JSON =
			minor_location_qo_s_convertToJSON(
				location_data_ext->achieved_qos);
		if(achieved_qos_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [achieved_qos]");
			goto end;
		}
		cJSON_AddItemToObject(item, "achievedQos",
		                      achieved_qos_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [achieved_qos]");
			goto end;
		}
	}

	if(location_data_ext->is_direct_report_ind) {
		if(cJSON_AddBoolToObject(item, "directReportInd",
		                         location_data_ext->direct_report_ind)
		   == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [direct_report_ind]");
			goto end;
		}
	}

	if(location_data_ext->accepted_periodic_event_info) {
		cJSON *accepted_periodic_event_info_local_JSON =
			periodic_event_info_convertToJSON(
				location_data_ext->accepted_periodic_event_info);
		if(accepted_periodic_event_info_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [accepted_periodic_event_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "acceptedPeriodicEventInfo",
		                      accepted_periodic_event_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [accepted_periodic_event_info]");
			goto end;
		}
	}

	if(location_data_ext->ha_gnss_metrics) {
		cJSON *ha_gnss_metrics_local_JSON =
			high_accuracy_gnss_metrics_convertToJSON(
				location_data_ext->ha_gnss_metrics);
		if(ha_gnss_metrics_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [ha_gnss_metrics]");
			goto end;
		}
		cJSON_AddItemToObject(item, "haGnssMetrics",
		                      ha_gnss_metrics_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [ha_gnss_metrics]");
			goto end;
		}
	}

	if(location_data_ext->los_nlos_measure_ind !=
	   los_nlos_measure_ind_NULL)
	{
		if(cJSON_AddStringToObject(item, "losNlosMeasureInd",
		                           los_nlos_measure_ind_ToString(
						   location_data_ext->
						   los_nlos_measure_ind))
		   == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [los_nlos_measure_ind]");
			goto end;
		}
	}

	if(location_data_ext->indoor_outdoor_ind != indoor_outdoor_ind_NULL) {
		if(cJSON_AddStringToObject(item, "indoorOutdoorInd",
		                           indoor_outdoor_ind_ToString(
						   location_data_ext->
						   indoor_outdoor_ind))
		   == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [indoor_outdoor_ind]");
			goto end;
		}
	}

	if(location_data_ext->related_applicationlayer_id) {
		if(cJSON_AddStringToObject(item, "relatedApplicationlayerId",
		                           location_data_ext->
		                           related_applicationlayer_id) == NULL)
		{
			printf(
				"location_data_ext_convertToJSON() failed [related_applicationlayer_id]");
			goto end;
		}
	}

	if(location_data_ext->distance_direction) {
		cJSON *distance_direction_local_JSON =
			range_direction_convertToJSON(
				location_data_ext->distance_direction);
		if(distance_direction_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [distance_direction]");
			goto end;
		}
		cJSON_AddItemToObject(item, "distanceDirection",
		                      distance_direction_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [distance_direction]");
			goto end;
		}
	}

	if(location_data_ext->_2d_relative_location) {
		cJSON *_2d_relative_location_local_JSON =
			model_2_d_relative_location_convertToJSON(
				location_data_ext->_2d_relative_location);
		if(_2d_relative_location_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [_2d_relative_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "2dRelativeLocation",
		                      _2d_relative_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [_2d_relative_location]");
			goto end;
		}
	}

	if(location_data_ext->_3d_relative_location) {
		cJSON *_3d_relative_location_local_JSON =
			model_3_d_relative_location_convertToJSON(
				location_data_ext->_3d_relative_location);
		if(_3d_relative_location_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [_3d_relative_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "3dRelativeLocation",
		                      _3d_relative_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [_3d_relative_location]");
			goto end;
		}
	}

	if(location_data_ext->relative_velocity) {
		cJSON *relative_velocity_local_JSON =
			velocity_estimate_convertToJSON(
				location_data_ext->relative_velocity);
		if(relative_velocity_local_JSON == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [relative_velocity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "relativeVelocity",
		                      relative_velocity_local_JSON);
		if(item->child == NULL) {
			printf(
				"location_data_ext_convertToJSON() failed [relative_velocity]");
			goto end;
		}
	}

end:
	return item;
}

location_data_ext_t *location_data_ext_parseFromJSON(
	cJSON *location_data_extJSON) {
	location_data_ext_t *location_data_ext_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *gpsi = NULL;
	cJSON *supi = NULL;
	cJSON *location_estimate = NULL;
	geographic_area_t *location_estimate_local_nonprim = NULL;
	cJSON *civic_address = NULL;
	civic_address_t *civic_address_local_nonprim = NULL;
	cJSON *local_location_estimate = NULL;
	local_area_t *local_location_estimate_local_nonprim = NULL;
	cJSON *age_of_location_estimate = NULL;
	cJSON *timestamp_of_location_estimate = NULL;
	cJSON *positioning_data_list = NULL;
	list_t *positioning_data_listList = NULL;
	cJSON *gnss_positioning_data_list = NULL;
	list_t *gnss_positioning_data_listList = NULL;
	cJSON *accuracy_fulfilment_indicator = NULL;
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicatorVariable =
		0;
	cJSON *ue_velocity = NULL;
	velocity_estimate_t *ue_velocity_local_nonprim = NULL;
	cJSON *ldr_reference = NULL;
	cJSON *altitude = NULL;
	cJSON *serving_lmf_identification = NULL;
	cJSON *location_privacy_ver_result = NULL;
	location_privacy_ver_result_t *location_privacy_ver_result_local_nonprim
	        = NULL;
	cJSON *success_type = NULL;
	success_type_e success_typeVariable = 0;
	cJSON *achieved_qos = NULL;
	minor_location_qo_s_t *achieved_qos_local_nonprim = NULL;
	cJSON *direct_report_ind = NULL;
	cJSON *accepted_periodic_event_info = NULL;
	periodic_event_info_t *accepted_periodic_event_info_local_nonprim =
		NULL;
	cJSON *ha_gnss_metrics = NULL;
	high_accuracy_gnss_metrics_t *ha_gnss_metrics_local_nonprim = NULL;
	cJSON *los_nlos_measure_ind = NULL;
	los_nlos_measure_ind_e los_nlos_measure_indVariable = 0;
	cJSON *indoor_outdoor_ind = NULL;
	indoor_outdoor_ind_e indoor_outdoor_indVariable = 0;
	cJSON *related_applicationlayer_id = NULL;
	cJSON *distance_direction = NULL;
	range_direction_t *distance_direction_local_nonprim = NULL;
	cJSON *_2d_relative_location = NULL;
	model_2_d_relative_location_t *_2d_relative_location_local_nonprim =
		NULL;
	cJSON *_3d_relative_location = NULL;
	model_3_d_relative_location_t *_3d_relative_location_local_nonprim =
		NULL;
	cJSON *relative_velocity = NULL;
	velocity_estimate_t *relative_velocity_local_nonprim = NULL;
	gpsi = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf("location_data_ext_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	supi = cJSON_GetObjectItemCaseSensitive(location_data_extJSON, "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf("location_data_ext_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	location_estimate = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "locationEstimate");
	if(location_estimate) {
		location_estimate_local_nonprim = geographic_area_parseFromJSON(
			location_estimate);
		if(!location_estimate_local_nonprim) {
			printf(
				"geographic_area_parseFromJSON failed [location_estimate]");
			goto end;
		}
	}

	civic_address = cJSON_GetObjectItemCaseSensitive(location_data_extJSON,
	                                                 "civicAddress");
	if(civic_address) {
		civic_address_local_nonprim = civic_address_parseFromJSON(
			civic_address);
		if(!civic_address_local_nonprim) {
			printf(
				"civic_address_parseFromJSON failed [civic_address]");
			goto end;
		}
	}

	local_location_estimate = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "localLocationEstimate");
	if(local_location_estimate) {
		local_location_estimate_local_nonprim =
			local_area_parseFromJSON(local_location_estimate);
		if(!local_location_estimate_local_nonprim) {
			printf(
				"local_area_parseFromJSON failed [local_location_estimate]");
			goto end;
		}
	}

	age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "ageOfLocationEstimate");
	if(age_of_location_estimate) {
		if(!cJSON_IsNumber(age_of_location_estimate)) {
			printf(
				"location_data_ext_parseFromJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "timestampOfLocationEstimate");
	if(timestamp_of_location_estimate) {
		if(!cJSON_IsString(timestamp_of_location_estimate) &&
		   !cJSON_IsNull(timestamp_of_location_estimate))
		{
			printf(
				"location_data_ext_parseFromJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	positioning_data_list = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "positioningDataList");
	if(positioning_data_list) {
		cJSON *positioning_data_list_local = NULL;
		if(!cJSON_IsArray(positioning_data_list)) {
			printf(
				"location_data_ext_parseFromJSON() failed [positioning_data_list]");
			goto end;
		}

		positioning_data_listList = list_create();

		cJSON_ArrayForEach(positioning_data_list_local,
		                   positioning_data_list) {
			if(!cJSON_IsObject(positioning_data_list_local)) {
				printf(
					"location_data_ext_parseFromJSON() failed [positioning_data_list]");
				goto end;
			}
			positioning_method_and_usage_t *
			        positioning_data_listItem =
				positioning_method_and_usage_parseFromJSON(
					positioning_data_list_local);
			if(!positioning_data_listItem) {
				printf("No positioning_data_listItem");
				goto end;
			}
			list_add(positioning_data_listList,
			         positioning_data_listItem);
		}
	}

	gnss_positioning_data_list = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "gnssPositioningDataList");
	if(gnss_positioning_data_list) {
		cJSON *gnss_positioning_data_list_local = NULL;
		if(!cJSON_IsArray(gnss_positioning_data_list)) {
			printf(
				"location_data_ext_parseFromJSON() failed [gnss_positioning_data_list]");
			goto end;
		}

		gnss_positioning_data_listList = list_create();

		cJSON_ArrayForEach(gnss_positioning_data_list_local,
		                   gnss_positioning_data_list) {
			if(!cJSON_IsObject(gnss_positioning_data_list_local)) {
				printf(
					"location_data_ext_parseFromJSON() failed [gnss_positioning_data_list]");
				goto end;
			}
			gnss_positioning_method_and_usage_t *
			        gnss_positioning_data_listItem =
				gnss_positioning_method_and_usage_parseFromJSON(
					gnss_positioning_data_list_local);
			if(!gnss_positioning_data_listItem) {
				printf("No gnss_positioning_data_listItem");
				goto end;
			}
			list_add(gnss_positioning_data_listList,
			         gnss_positioning_data_listItem);
		}
	}

	accuracy_fulfilment_indicator = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "accuracyFulfilmentIndicator");
	if(accuracy_fulfilment_indicator) {
		if(!cJSON_IsString(accuracy_fulfilment_indicator)) {
			printf(
				"location_data_ext_parseFromJSON() failed [accuracy_fulfilment_indicator]");
			goto end;
		}
		accuracy_fulfilment_indicatorVariable =
			accuracy_fulfilment_indicator_FromString(
				accuracy_fulfilment_indicator->valuestring);
	}

	ue_velocity = cJSON_GetObjectItemCaseSensitive(location_data_extJSON,
	                                               "ueVelocity");
	if(ue_velocity) {
		ue_velocity_local_nonprim = velocity_estimate_parseFromJSON(
			ue_velocity);
		if(!ue_velocity_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [ue_velocity]");
			goto end;
		}
	}

	ldr_reference = cJSON_GetObjectItemCaseSensitive(location_data_extJSON,
	                                                 "ldrReference");
	if(ldr_reference) {
		if(!cJSON_IsString(ldr_reference) &&
		   !cJSON_IsNull(ldr_reference))
		{
			printf(
				"location_data_ext_parseFromJSON() failed [ldr_reference]");
			goto end;
		}
	}

	altitude = cJSON_GetObjectItemCaseSensitive(location_data_extJSON,
	                                            "altitude");
	if(altitude) {
		if(!cJSON_IsNumber(altitude)) {
			printf(
				"location_data_ext_parseFromJSON() failed [altitude]");
			goto end;
		}
	}

	serving_lmf_identification = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "servingLMFIdentification");
	if(serving_lmf_identification) {
		if(!cJSON_IsString(serving_lmf_identification) &&
		   !cJSON_IsNull(serving_lmf_identification))
		{
			printf(
				"location_data_ext_parseFromJSON() failed [serving_lmf_identification]");
			goto end;
		}
	}

	location_privacy_ver_result = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "locationPrivacyVerResult");
	if(location_privacy_ver_result) {
		location_privacy_ver_result_local_nonprim =
			location_privacy_ver_result_parseFromJSON(
				location_privacy_ver_result);
		if(!location_privacy_ver_result_local_nonprim) {
			printf(
				"location_privacy_ver_result_parseFromJSON failed [location_privacy_ver_result]");
			goto end;
		}
	}

	success_type = cJSON_GetObjectItemCaseSensitive(location_data_extJSON,
	                                                "successType");
	if(success_type) {
		if(!cJSON_IsString(success_type)) {
			printf(
				"location_data_ext_parseFromJSON() failed [success_type]");
			goto end;
		}
		success_typeVariable = success_type_FromString(
			success_type->valuestring);
	}

	achieved_qos = cJSON_GetObjectItemCaseSensitive(location_data_extJSON,
	                                                "achievedQos");
	if(achieved_qos) {
		achieved_qos_local_nonprim = minor_location_qo_s_parseFromJSON(
			achieved_qos);
		if(!achieved_qos_local_nonprim) {
			printf(
				"minor_location_qo_s_parseFromJSON failed [achieved_qos]");
			goto end;
		}
	}

	direct_report_ind = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "directReportInd");
	if(direct_report_ind) {
		if(!cJSON_IsBool(direct_report_ind)) {
			printf(
				"location_data_ext_parseFromJSON() failed [direct_report_ind]");
			goto end;
		}
	}

	accepted_periodic_event_info = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "acceptedPeriodicEventInfo");
	if(accepted_periodic_event_info) {
		accepted_periodic_event_info_local_nonprim =
			periodic_event_info_parseFromJSON(
				accepted_periodic_event_info);
		if(!accepted_periodic_event_info_local_nonprim) {
			printf(
				"periodic_event_info_parseFromJSON failed [accepted_periodic_event_info]");
			goto end;
		}
	}

	ha_gnss_metrics = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "haGnssMetrics");
	if(ha_gnss_metrics) {
		ha_gnss_metrics_local_nonprim =
			high_accuracy_gnss_metrics_parseFromJSON(ha_gnss_metrics);
		if(!ha_gnss_metrics_local_nonprim) {
			printf(
				"high_accuracy_gnss_metrics_parseFromJSON failed [ha_gnss_metrics]");
			goto end;
		}
	}

	los_nlos_measure_ind = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "losNlosMeasureInd");
	if(los_nlos_measure_ind) {
		if(!cJSON_IsString(los_nlos_measure_ind)) {
			printf(
				"location_data_ext_parseFromJSON() failed [los_nlos_measure_ind]");
			goto end;
		}
		los_nlos_measure_indVariable = los_nlos_measure_ind_FromString(
			los_nlos_measure_ind->valuestring);
	}

	indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "indoorOutdoorInd");
	if(indoor_outdoor_ind) {
		if(!cJSON_IsString(indoor_outdoor_ind)) {
			printf(
				"location_data_ext_parseFromJSON() failed [indoor_outdoor_ind]");
			goto end;
		}
		indoor_outdoor_indVariable = indoor_outdoor_ind_FromString(
			indoor_outdoor_ind->valuestring);
	}

	related_applicationlayer_id = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "relatedApplicationlayerId");
	if(related_applicationlayer_id) {
		if(!cJSON_IsString(related_applicationlayer_id) &&
		   !cJSON_IsNull(related_applicationlayer_id))
		{
			printf(
				"location_data_ext_parseFromJSON() failed [related_applicationlayer_id]");
			goto end;
		}
	}

	distance_direction = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "distanceDirection");
	if(distance_direction) {
		distance_direction_local_nonprim =
			range_direction_parseFromJSON(distance_direction);
		if(!distance_direction_local_nonprim) {
			printf(
				"range_direction_parseFromJSON failed [distance_direction]");
			goto end;
		}
	}

	_2d_relative_location = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "2dRelativeLocation");
	if(_2d_relative_location) {
		_2d_relative_location_local_nonprim =
			model_2_d_relative_location_parseFromJSON(
				_2d_relative_location);
		if(!_2d_relative_location_local_nonprim) {
			printf(
				"model_2_d_relative_location_parseFromJSON failed [_2d_relative_location]");
			goto end;
		}
	}

	_3d_relative_location = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "3dRelativeLocation");
	if(_3d_relative_location) {
		_3d_relative_location_local_nonprim =
			model_3_d_relative_location_parseFromJSON(
				_3d_relative_location);
		if(!_3d_relative_location_local_nonprim) {
			printf(
				"model_3_d_relative_location_parseFromJSON failed [_3d_relative_location]");
			goto end;
		}
	}

	relative_velocity = cJSON_GetObjectItemCaseSensitive(
		location_data_extJSON, "relativeVelocity");
	if(relative_velocity) {
		relative_velocity_local_nonprim =
			velocity_estimate_parseFromJSON(relative_velocity);
		if(!relative_velocity_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [relative_velocity]");
			goto end;
		}
	}

	location_data_ext_local_var = location_data_ext_create(
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		supi &&
		!cJSON_IsNull(supi) ? strdup(
			supi->valuestring) : NULL,
		location_estimate ? location_estimate_local_nonprim : NULL,
		civic_address ? civic_address_local_nonprim : NULL,
		local_location_estimate ? local_location_estimate_local_nonprim : NULL,
		age_of_location_estimate ? true : false,
		age_of_location_estimate ? age_of_location_estimate->valuedouble : 0,
		timestamp_of_location_estimate &&
		!cJSON_IsNull(timestamp_of_location_estimate) ? strdup(
			timestamp_of_location_estimate->valuestring) : NULL,
		positioning_data_list ? positioning_data_listList : NULL,
		gnss_positioning_data_list ? gnss_positioning_data_listList : NULL,
		accuracy_fulfilment_indicator ? accuracy_fulfilment_indicatorVariable : 0,
		ue_velocity ? ue_velocity_local_nonprim : NULL,
		ldr_reference &&
		!cJSON_IsNull(ldr_reference) ? strdup(
			ldr_reference->valuestring) : NULL,
		altitude ? true : false,
		altitude ? altitude->valuedouble : 0,
		serving_lmf_identification &&
		!cJSON_IsNull(serving_lmf_identification) ? strdup(
			serving_lmf_identification->valuestring) : NULL,
		location_privacy_ver_result ? location_privacy_ver_result_local_nonprim : NULL,
		success_type ? success_typeVariable : 0,
		achieved_qos ? achieved_qos_local_nonprim : NULL,
		direct_report_ind ? true : false,
		direct_report_ind ? direct_report_ind->valueint : 0,
		accepted_periodic_event_info ? accepted_periodic_event_info_local_nonprim : NULL,
		ha_gnss_metrics ? ha_gnss_metrics_local_nonprim : NULL,
		los_nlos_measure_ind ? los_nlos_measure_indVariable : 0,
		indoor_outdoor_ind ? indoor_outdoor_indVariable : 0,
		related_applicationlayer_id &&
		!cJSON_IsNull(related_applicationlayer_id) ? strdup(
			related_applicationlayer_id->valuestring) : NULL,
		distance_direction ? distance_direction_local_nonprim : NULL,
		_2d_relative_location ? _2d_relative_location_local_nonprim : NULL,
		_3d_relative_location ? _3d_relative_location_local_nonprim : NULL,
		relative_velocity ? relative_velocity_local_nonprim : NULL
		);

	return location_data_ext_local_var;
end:
	if(location_estimate_local_nonprim) {
		geographic_area_free(location_estimate_local_nonprim);
		location_estimate_local_nonprim = NULL;
	}
	if(civic_address_local_nonprim) {
		civic_address_free(civic_address_local_nonprim);
		civic_address_local_nonprim = NULL;
	}
	if(local_location_estimate_local_nonprim) {
		local_area_free(local_location_estimate_local_nonprim);
		local_location_estimate_local_nonprim = NULL;
	}
	if(positioning_data_listList) {
		list_for_each(positioning_data_listList, node) {
			positioning_method_and_usage_free(node->data);
		}
		list_free(positioning_data_listList);
		positioning_data_listList = NULL;
	}
	if(gnss_positioning_data_listList) {
		list_for_each(gnss_positioning_data_listList, node) {
			gnss_positioning_method_and_usage_free(node->data);
		}
		list_free(gnss_positioning_data_listList);
		gnss_positioning_data_listList = NULL;
	}
	if(ue_velocity_local_nonprim) {
		velocity_estimate_free(ue_velocity_local_nonprim);
		ue_velocity_local_nonprim = NULL;
	}
	if(location_privacy_ver_result_local_nonprim) {
		location_privacy_ver_result_free(
			location_privacy_ver_result_local_nonprim);
		location_privacy_ver_result_local_nonprim = NULL;
	}
	if(achieved_qos_local_nonprim) {
		minor_location_qo_s_free(achieved_qos_local_nonprim);
		achieved_qos_local_nonprim = NULL;
	}
	if(accepted_periodic_event_info_local_nonprim) {
		periodic_event_info_free(
			accepted_periodic_event_info_local_nonprim);
		accepted_periodic_event_info_local_nonprim = NULL;
	}
	if(ha_gnss_metrics_local_nonprim) {
		high_accuracy_gnss_metrics_free(ha_gnss_metrics_local_nonprim);
		ha_gnss_metrics_local_nonprim = NULL;
	}
	if(distance_direction_local_nonprim) {
		range_direction_free(distance_direction_local_nonprim);
		distance_direction_local_nonprim = NULL;
	}
	if(_2d_relative_location_local_nonprim) {
		model_2_d_relative_location_free(
			_2d_relative_location_local_nonprim);
		_2d_relative_location_local_nonprim = NULL;
	}
	if(_3d_relative_location_local_nonprim) {
		model_3_d_relative_location_free(
			_3d_relative_location_local_nonprim);
		_3d_relative_location_local_nonprim = NULL;
	}
	if(relative_velocity_local_nonprim) {
		velocity_estimate_free(relative_velocity_local_nonprim);
		relative_velocity_local_nonprim = NULL;
	}
	return NULL;
}

location_data_ext_t *location_data_ext_copy(location_data_ext_t *dst,
                                            location_data_ext_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = location_data_ext_convertToJSON(src);
	if(!item) {
		printf("location_data_ext_convertToJSON() failed");
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

	location_data_ext_free(dst);
	dst = location_data_ext_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
