#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_notify_data_ext.h"

event_notify_data_ext_t *event_notify_data_ext_create(
	reported_event_type_e reported_event_type, char *supi, char *gpsi,
	char *hgmlc_call_back_uri, char *ldr_reference, char *lir_reference,
	geographic_area_t *location_estimate, bool is_age_of_location_estimate,
	int age_of_location_estimate, char *timestamp_of_location_estimate,
	civic_address_t *civic_address, local_area_t *local_location_estimate,
	list_t *positioning_data_list, list_t *gnss_positioning_data_list,
	char *serving_lm_fidentification, termination_cause_e termination_cause,
	velocity_estimate_t *velocity_estimate, bool is_altitude,
	double altitude, minor_location_qo_s_t *achieved_qos,
	char *supported_features, indoor_outdoor_ind_e indoor_outdoor_ind,
	high_accuracy_gnss_metrics_t *ha_gnss_metrics,
	los_nlos_measure_ind_e los_nlos_measure_ind, bool is_up_loc_rep_stat_af,
	int up_loc_rep_stat_af, char *related_applicationlayer_id,
	range_direction_t *distance_direction,
	model_2_d_relative_location_t *_2d_relative_location,
	model_3_d_relative_location_t *_3d_relative_location,
	velocity_estimate_t *relative_velocity,
	list_t *add_event_notify_datas) {
	event_notify_data_ext_t *event_notify_data_ext_local_var = malloc(
		sizeof(event_notify_data_ext_t));

	event_notify_data_ext_local_var->reported_event_type =
		reported_event_type;
	event_notify_data_ext_local_var->supi = supi;
	event_notify_data_ext_local_var->gpsi = gpsi;
	event_notify_data_ext_local_var->hgmlc_call_back_uri =
		hgmlc_call_back_uri;
	event_notify_data_ext_local_var->ldr_reference = ldr_reference;
	event_notify_data_ext_local_var->lir_reference = lir_reference;
	event_notify_data_ext_local_var->location_estimate = location_estimate;
	event_notify_data_ext_local_var->is_age_of_location_estimate =
		is_age_of_location_estimate;
	event_notify_data_ext_local_var->age_of_location_estimate =
		age_of_location_estimate;
	event_notify_data_ext_local_var->timestamp_of_location_estimate =
		timestamp_of_location_estimate;
	event_notify_data_ext_local_var->civic_address = civic_address;
	event_notify_data_ext_local_var->local_location_estimate =
		local_location_estimate;
	event_notify_data_ext_local_var->positioning_data_list =
		positioning_data_list;
	event_notify_data_ext_local_var->gnss_positioning_data_list =
		gnss_positioning_data_list;
	event_notify_data_ext_local_var->serving_lm_fidentification =
		serving_lm_fidentification;
	event_notify_data_ext_local_var->termination_cause = termination_cause;
	event_notify_data_ext_local_var->velocity_estimate = velocity_estimate;
	event_notify_data_ext_local_var->is_altitude = is_altitude;
	event_notify_data_ext_local_var->altitude = altitude;
	event_notify_data_ext_local_var->achieved_qos = achieved_qos;
	event_notify_data_ext_local_var->supported_features =
		supported_features;
	event_notify_data_ext_local_var->indoor_outdoor_ind =
		indoor_outdoor_ind;
	event_notify_data_ext_local_var->ha_gnss_metrics = ha_gnss_metrics;
	event_notify_data_ext_local_var->los_nlos_measure_ind =
		los_nlos_measure_ind;
	event_notify_data_ext_local_var->is_up_loc_rep_stat_af =
		is_up_loc_rep_stat_af;
	event_notify_data_ext_local_var->up_loc_rep_stat_af =
		up_loc_rep_stat_af;
	event_notify_data_ext_local_var->related_applicationlayer_id =
		related_applicationlayer_id;
	event_notify_data_ext_local_var->distance_direction =
		distance_direction;
	event_notify_data_ext_local_var->_2d_relative_location =
		_2d_relative_location;
	event_notify_data_ext_local_var->_3d_relative_location =
		_3d_relative_location;
	event_notify_data_ext_local_var->relative_velocity = relative_velocity;
	event_notify_data_ext_local_var->add_event_notify_datas =
		add_event_notify_datas;

	return event_notify_data_ext_local_var;
}

void event_notify_data_ext_free(event_notify_data_ext_t *event_notify_data_ext)
{
	lnode_t *node = NULL;

	if(NULL == event_notify_data_ext) {
		return;
	}
	if(event_notify_data_ext->supi) {
		free(event_notify_data_ext->supi);
		event_notify_data_ext->supi = NULL;
	}
	if(event_notify_data_ext->gpsi) {
		free(event_notify_data_ext->gpsi);
		event_notify_data_ext->gpsi = NULL;
	}
	if(event_notify_data_ext->hgmlc_call_back_uri) {
		free(event_notify_data_ext->hgmlc_call_back_uri);
		event_notify_data_ext->hgmlc_call_back_uri = NULL;
	}
	if(event_notify_data_ext->ldr_reference) {
		free(event_notify_data_ext->ldr_reference);
		event_notify_data_ext->ldr_reference = NULL;
	}
	if(event_notify_data_ext->lir_reference) {
		free(event_notify_data_ext->lir_reference);
		event_notify_data_ext->lir_reference = NULL;
	}
	if(event_notify_data_ext->location_estimate) {
		geographic_area_free(event_notify_data_ext->location_estimate);
		event_notify_data_ext->location_estimate = NULL;
	}
	if(event_notify_data_ext->timestamp_of_location_estimate) {
		free(event_notify_data_ext->timestamp_of_location_estimate);
		event_notify_data_ext->timestamp_of_location_estimate = NULL;
	}
	if(event_notify_data_ext->civic_address) {
		civic_address_free(event_notify_data_ext->civic_address);
		event_notify_data_ext->civic_address = NULL;
	}
	if(event_notify_data_ext->local_location_estimate) {
		local_area_free(event_notify_data_ext->local_location_estimate);
		event_notify_data_ext->local_location_estimate = NULL;
	}
	if(event_notify_data_ext->positioning_data_list) {
		list_for_each(event_notify_data_ext->positioning_data_list,
		              node) {
			positioning_method_and_usage_free(node->data);
		}
		list_free(event_notify_data_ext->positioning_data_list);
		event_notify_data_ext->positioning_data_list = NULL;
	}
	if(event_notify_data_ext->gnss_positioning_data_list) {
		list_for_each(event_notify_data_ext->gnss_positioning_data_list,
		              node) {
			gnss_positioning_method_and_usage_free(node->data);
		}
		list_free(event_notify_data_ext->gnss_positioning_data_list);
		event_notify_data_ext->gnss_positioning_data_list = NULL;
	}
	if(event_notify_data_ext->serving_lm_fidentification) {
		free(event_notify_data_ext->serving_lm_fidentification);
		event_notify_data_ext->serving_lm_fidentification = NULL;
	}
	if(event_notify_data_ext->velocity_estimate) {
		velocity_estimate_free(event_notify_data_ext->velocity_estimate);
		event_notify_data_ext->velocity_estimate = NULL;
	}
	if(event_notify_data_ext->achieved_qos) {
		minor_location_qo_s_free(event_notify_data_ext->achieved_qos);
		event_notify_data_ext->achieved_qos = NULL;
	}
	if(event_notify_data_ext->supported_features) {
		free(event_notify_data_ext->supported_features);
		event_notify_data_ext->supported_features = NULL;
	}
	if(event_notify_data_ext->ha_gnss_metrics) {
		high_accuracy_gnss_metrics_free(
			event_notify_data_ext->ha_gnss_metrics);
		event_notify_data_ext->ha_gnss_metrics = NULL;
	}
	if(event_notify_data_ext->related_applicationlayer_id) {
		free(event_notify_data_ext->related_applicationlayer_id);
		event_notify_data_ext->related_applicationlayer_id = NULL;
	}
	if(event_notify_data_ext->distance_direction) {
		range_direction_free(event_notify_data_ext->distance_direction);
		event_notify_data_ext->distance_direction = NULL;
	}
	if(event_notify_data_ext->_2d_relative_location) {
		model_2_d_relative_location_free(
			event_notify_data_ext->_2d_relative_location);
		event_notify_data_ext->_2d_relative_location = NULL;
	}
	if(event_notify_data_ext->_3d_relative_location) {
		model_3_d_relative_location_free(
			event_notify_data_ext->_3d_relative_location);
		event_notify_data_ext->_3d_relative_location = NULL;
	}
	if(event_notify_data_ext->relative_velocity) {
		velocity_estimate_free(event_notify_data_ext->relative_velocity);
		event_notify_data_ext->relative_velocity = NULL;
	}
	if(event_notify_data_ext->add_event_notify_datas) {
		list_for_each(event_notify_data_ext->add_event_notify_datas,
		              node) {
			event_notify_data_free(node->data);
		}
		list_free(event_notify_data_ext->add_event_notify_datas);
		event_notify_data_ext->add_event_notify_datas = NULL;
	}
	free(event_notify_data_ext);
}

cJSON *event_notify_data_ext_convertToJSON(
	event_notify_data_ext_t *event_notify_data_ext) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(event_notify_data_ext == NULL) {
		printf(
			"event_notify_data_ext_convertToJSON() failed [EventNotifyDataExt]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(event_notify_data_ext->reported_event_type ==
	   reported_event_type_NULL)
	{
		printf(
			"event_notify_data_ext_convertToJSON() failed [reported_event_type]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "reportedEventType",
	                           reported_event_type_ToString(
					   event_notify_data_ext->
					   reported_event_type)) == NULL)
	{
		printf(
			"event_notify_data_ext_convertToJSON() failed [reported_event_type]");
		goto end;
	}

	if(event_notify_data_ext->supi) {
		if(cJSON_AddStringToObject(item, "supi",
		                           event_notify_data_ext->supi) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [supi]");
			goto end;
		}
	}

	if(event_notify_data_ext->gpsi) {
		if(cJSON_AddStringToObject(item, "gpsi",
		                           event_notify_data_ext->gpsi) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [gpsi]");
			goto end;
		}
	}

	if(event_notify_data_ext->hgmlc_call_back_uri) {
		if(cJSON_AddStringToObject(item, "hgmlcCallBackURI",
		                           event_notify_data_ext->
		                           hgmlc_call_back_uri) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [hgmlc_call_back_uri]");
			goto end;
		}
	}

	if(!event_notify_data_ext->ldr_reference) {
		printf(
			"event_notify_data_ext_convertToJSON() failed [ldr_reference]");
		return NULL;
	}
	if(cJSON_AddStringToObject(item, "ldrReference",
	                           event_notify_data_ext->ldr_reference) ==
	   NULL)
	{
		printf(
			"event_notify_data_ext_convertToJSON() failed [ldr_reference]");
		goto end;
	}

	if(event_notify_data_ext->lir_reference) {
		if(cJSON_AddStringToObject(item, "lirReference",
		                           event_notify_data_ext->lir_reference)
		   == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [lir_reference]");
			goto end;
		}
	}

	if(event_notify_data_ext->location_estimate) {
		cJSON *location_estimate_local_JSON =
			geographic_area_convertToJSON(
				event_notify_data_ext->location_estimate);
		if(location_estimate_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [location_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locationEstimate",
		                      location_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [location_estimate]");
			goto end;
		}
	}

	if(event_notify_data_ext->is_age_of_location_estimate) {
		if(cJSON_AddNumberToObject(item, "ageOfLocationEstimate",
		                           event_notify_data_ext->
		                           age_of_location_estimate) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	if(event_notify_data_ext->timestamp_of_location_estimate) {
		if(cJSON_AddStringToObject(item, "timestampOfLocationEstimate",
		                           event_notify_data_ext->
		                           timestamp_of_location_estimate) ==
		   NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	if(event_notify_data_ext->civic_address) {
		cJSON *civic_address_local_JSON = civic_address_convertToJSON(
			event_notify_data_ext->civic_address);
		if(civic_address_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [civic_address]");
			goto end;
		}
		cJSON_AddItemToObject(item, "civicAddress",
		                      civic_address_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [civic_address]");
			goto end;
		}
	}

	if(event_notify_data_ext->local_location_estimate) {
		cJSON *local_location_estimate_local_JSON =
			local_area_convertToJSON(
				event_notify_data_ext->local_location_estimate);
		if(local_location_estimate_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [local_location_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "localLocationEstimate",
		                      local_location_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [local_location_estimate]");
			goto end;
		}
	}

	if(event_notify_data_ext->positioning_data_list) {
		cJSON *positioning_data_listList = cJSON_AddArrayToObject(item,
		                                                          "positioningDataList");
		if(positioning_data_listList == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [positioning_data_list]");
			goto end;
		}
		list_for_each(event_notify_data_ext->positioning_data_list,
		              node) {
			cJSON *itemLocal =
				positioning_method_and_usage_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notify_data_ext_convertToJSON() failed [positioning_data_list]");
				goto end;
			}
			cJSON_AddItemToArray(positioning_data_listList,
			                     itemLocal);
		}
	}

	if(event_notify_data_ext->gnss_positioning_data_list) {
		cJSON *gnss_positioning_data_listList = cJSON_AddArrayToObject(
			item, "gnssPositioningDataList");
		if(gnss_positioning_data_listList == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [gnss_positioning_data_list]");
			goto end;
		}
		list_for_each(event_notify_data_ext->gnss_positioning_data_list,
		              node) {
			cJSON *itemLocal =
				gnss_positioning_method_and_usage_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notify_data_ext_convertToJSON() failed [gnss_positioning_data_list]");
				goto end;
			}
			cJSON_AddItemToArray(gnss_positioning_data_listList,
			                     itemLocal);
		}
	}

	if(event_notify_data_ext->serving_lm_fidentification) {
		if(cJSON_AddStringToObject(item, "servingLMFidentification",
		                           event_notify_data_ext->
		                           serving_lm_fidentification) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [serving_lm_fidentification]");
			goto end;
		}
	}

	if(event_notify_data_ext->termination_cause != termination_cause_NULL) {
		if(cJSON_AddStringToObject(item, "terminationCause",
		                           termination_cause_ToString(
						   event_notify_data_ext->
						   termination_cause))
		   == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [termination_cause]");
			goto end;
		}
	}

	if(event_notify_data_ext->velocity_estimate) {
		cJSON *velocity_estimate_local_JSON =
			velocity_estimate_convertToJSON(
				event_notify_data_ext->velocity_estimate);
		if(velocity_estimate_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [velocity_estimate]");
			goto end;
		}
		cJSON_AddItemToObject(item, "velocityEstimate",
		                      velocity_estimate_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [velocity_estimate]");
			goto end;
		}
	}

	if(event_notify_data_ext->is_altitude) {
		if(cJSON_AddNumberToObject(item, "altitude",
		                           event_notify_data_ext->altitude) ==
		   NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [altitude]");
			goto end;
		}
	}

	if(event_notify_data_ext->achieved_qos) {
		cJSON *achieved_qos_local_JSON =
			minor_location_qo_s_convertToJSON(
				event_notify_data_ext->achieved_qos);
		if(achieved_qos_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [achieved_qos]");
			goto end;
		}
		cJSON_AddItemToObject(item, "achievedQos",
		                      achieved_qos_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [achieved_qos]");
			goto end;
		}
	}

	if(event_notify_data_ext->supported_features) {
		if(cJSON_AddStringToObject(item, "supportedFeatures",
		                           event_notify_data_ext->
		                           supported_features) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [supported_features]");
			goto end;
		}
	}

	if(event_notify_data_ext->indoor_outdoor_ind !=
	   indoor_outdoor_ind_NULL)
	{
		if(cJSON_AddStringToObject(item, "indoorOutdoorInd",
		                           indoor_outdoor_ind_ToString(
						   event_notify_data_ext->
						   indoor_outdoor_ind))
		   == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [indoor_outdoor_ind]");
			goto end;
		}
	}

	if(event_notify_data_ext->ha_gnss_metrics) {
		cJSON *ha_gnss_metrics_local_JSON =
			high_accuracy_gnss_metrics_convertToJSON(
				event_notify_data_ext->ha_gnss_metrics);
		if(ha_gnss_metrics_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [ha_gnss_metrics]");
			goto end;
		}
		cJSON_AddItemToObject(item, "haGnssMetrics",
		                      ha_gnss_metrics_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [ha_gnss_metrics]");
			goto end;
		}
	}

	if(event_notify_data_ext->los_nlos_measure_ind !=
	   los_nlos_measure_ind_NULL)
	{
		if(cJSON_AddStringToObject(item, "losNlosMeasureInd",
		                           los_nlos_measure_ind_ToString(
						   event_notify_data_ext->
						   los_nlos_measure_ind))
		   == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [los_nlos_measure_ind]");
			goto end;
		}
	}

	if(event_notify_data_ext->is_up_loc_rep_stat_af) {
		if(cJSON_AddNumberToObject(item, "upLocRepStatAf",
		                           event_notify_data_ext->
		                           up_loc_rep_stat_af) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [up_loc_rep_stat_af]");
			goto end;
		}
	}

	if(event_notify_data_ext->related_applicationlayer_id) {
		if(cJSON_AddStringToObject(item, "relatedApplicationlayerId",
		                           event_notify_data_ext->
		                           related_applicationlayer_id) == NULL)
		{
			printf(
				"event_notify_data_ext_convertToJSON() failed [related_applicationlayer_id]");
			goto end;
		}
	}

	if(event_notify_data_ext->distance_direction) {
		cJSON *distance_direction_local_JSON =
			range_direction_convertToJSON(
				event_notify_data_ext->distance_direction);
		if(distance_direction_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [distance_direction]");
			goto end;
		}
		cJSON_AddItemToObject(item, "distanceDirection",
		                      distance_direction_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [distance_direction]");
			goto end;
		}
	}

	if(event_notify_data_ext->_2d_relative_location) {
		cJSON *_2d_relative_location_local_JSON =
			model_2_d_relative_location_convertToJSON(
				event_notify_data_ext->_2d_relative_location);
		if(_2d_relative_location_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [_2d_relative_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "2dRelativeLocation",
		                      _2d_relative_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [_2d_relative_location]");
			goto end;
		}
	}

	if(event_notify_data_ext->_3d_relative_location) {
		cJSON *_3d_relative_location_local_JSON =
			model_3_d_relative_location_convertToJSON(
				event_notify_data_ext->_3d_relative_location);
		if(_3d_relative_location_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [_3d_relative_location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "3dRelativeLocation",
		                      _3d_relative_location_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [_3d_relative_location]");
			goto end;
		}
	}

	if(event_notify_data_ext->relative_velocity) {
		cJSON *relative_velocity_local_JSON =
			velocity_estimate_convertToJSON(
				event_notify_data_ext->relative_velocity);
		if(relative_velocity_local_JSON == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [relative_velocity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "relativeVelocity",
		                      relative_velocity_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [relative_velocity]");
			goto end;
		}
	}

	if(event_notify_data_ext->add_event_notify_datas) {
		cJSON *add_event_notify_datasList = cJSON_AddArrayToObject(item,
		                                                           "addEventNotifyDatas");
		if(add_event_notify_datasList == NULL) {
			printf(
				"event_notify_data_ext_convertToJSON() failed [add_event_notify_datas]");
			goto end;
		}
		list_for_each(event_notify_data_ext->add_event_notify_datas,
		              node) {
			cJSON *itemLocal = event_notify_data_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notify_data_ext_convertToJSON() failed [add_event_notify_datas]");
				goto end;
			}
			cJSON_AddItemToArray(add_event_notify_datasList,
			                     itemLocal);
		}
	}

end:
	return item;
}

event_notify_data_ext_t *event_notify_data_ext_parseFromJSON(
	cJSON *event_notify_data_extJSON) {
	event_notify_data_ext_t *event_notify_data_ext_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *reported_event_type = NULL;
	reported_event_type_e reported_event_typeVariable = 0;
	cJSON *supi = NULL;
	cJSON *gpsi = NULL;
	cJSON *hgmlc_call_back_uri = NULL;
	cJSON *ldr_reference = NULL;
	cJSON *lir_reference = NULL;
	cJSON *location_estimate = NULL;
	geographic_area_t *location_estimate_local_nonprim = NULL;
	cJSON *age_of_location_estimate = NULL;
	cJSON *timestamp_of_location_estimate = NULL;
	cJSON *civic_address = NULL;
	civic_address_t *civic_address_local_nonprim = NULL;
	cJSON *local_location_estimate = NULL;
	local_area_t *local_location_estimate_local_nonprim = NULL;
	cJSON *positioning_data_list = NULL;
	list_t *positioning_data_listList = NULL;
	cJSON *gnss_positioning_data_list = NULL;
	list_t *gnss_positioning_data_listList = NULL;
	cJSON *serving_lm_fidentification = NULL;
	cJSON *termination_cause = NULL;
	termination_cause_e termination_causeVariable = 0;
	cJSON *velocity_estimate = NULL;
	velocity_estimate_t *velocity_estimate_local_nonprim = NULL;
	cJSON *altitude = NULL;
	cJSON *achieved_qos = NULL;
	minor_location_qo_s_t *achieved_qos_local_nonprim = NULL;
	cJSON *supported_features = NULL;
	cJSON *indoor_outdoor_ind = NULL;
	indoor_outdoor_ind_e indoor_outdoor_indVariable = 0;
	cJSON *ha_gnss_metrics = NULL;
	high_accuracy_gnss_metrics_t *ha_gnss_metrics_local_nonprim = NULL;
	cJSON *los_nlos_measure_ind = NULL;
	los_nlos_measure_ind_e los_nlos_measure_indVariable = 0;
	cJSON *up_loc_rep_stat_af = NULL;
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
	cJSON *add_event_notify_datas = NULL;
	list_t *add_event_notify_datasList = NULL;
	reported_event_type = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "reportedEventType");
	if(!reported_event_type) {
		printf(
			"event_notify_data_ext_parseFromJSON() failed [reported_event_type]");
		goto end;
	}
	if(!cJSON_IsString(reported_event_type)) {
		printf(
			"event_notify_data_ext_parseFromJSON() failed [reported_event_type]");
		goto end;
	}
	reported_event_typeVariable = reported_event_type_FromString(
		reported_event_type->valuestring);

	supi = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON,
	                                        "supi");
	if(supi) {
		if(!cJSON_IsString(supi) &&
		   !cJSON_IsNull(supi))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [supi]");
			goto end;
		}
	}

	gpsi = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON,
	                                        "gpsi");
	if(gpsi) {
		if(!cJSON_IsString(gpsi) &&
		   !cJSON_IsNull(gpsi))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [gpsi]");
			goto end;
		}
	}

	hgmlc_call_back_uri = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "hgmlcCallBackURI");
	if(hgmlc_call_back_uri) {
		if(!cJSON_IsString(hgmlc_call_back_uri) &&
		   !cJSON_IsNull(hgmlc_call_back_uri))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [hgmlc_call_back_uri]");
			goto end;
		}
	}

	ldr_reference = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "ldrReference");
	if(!ldr_reference) {
		printf(
			"event_notify_data_ext_parseFromJSON() failed [ldr_reference]");
		goto end;
	}
	if(!cJSON_IsString(ldr_reference)) {
		printf(
			"event_notify_data_ext_parseFromJSON() failed [ldr_reference]");
		goto end;
	}

	lir_reference = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "lirReference");
	if(lir_reference) {
		if(!cJSON_IsString(lir_reference) &&
		   !cJSON_IsNull(lir_reference))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [lir_reference]");
			goto end;
		}
	}

	location_estimate = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "locationEstimate");
	if(location_estimate) {
		location_estimate_local_nonprim = geographic_area_parseFromJSON(
			location_estimate);
		if(!location_estimate_local_nonprim) {
			printf(
				"geographic_area_parseFromJSON failed [location_estimate]");
			goto end;
		}
	}

	age_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "ageOfLocationEstimate");
	if(age_of_location_estimate) {
		if(!cJSON_IsNumber(age_of_location_estimate)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [age_of_location_estimate]");
			goto end;
		}
	}

	timestamp_of_location_estimate = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "timestampOfLocationEstimate");
	if(timestamp_of_location_estimate) {
		if(!cJSON_IsString(timestamp_of_location_estimate) &&
		   !cJSON_IsNull(timestamp_of_location_estimate))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [timestamp_of_location_estimate]");
			goto end;
		}
	}

	civic_address = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "civicAddress");
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
		event_notify_data_extJSON, "localLocationEstimate");
	if(local_location_estimate) {
		local_location_estimate_local_nonprim =
			local_area_parseFromJSON(local_location_estimate);
		if(!local_location_estimate_local_nonprim) {
			printf(
				"local_area_parseFromJSON failed [local_location_estimate]");
			goto end;
		}
	}

	positioning_data_list = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "positioningDataList");
	if(positioning_data_list) {
		cJSON *positioning_data_list_local = NULL;
		if(!cJSON_IsArray(positioning_data_list)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [positioning_data_list]");
			goto end;
		}

		positioning_data_listList = list_create();

		cJSON_ArrayForEach(positioning_data_list_local,
		                   positioning_data_list) {
			if(!cJSON_IsObject(positioning_data_list_local)) {
				printf(
					"event_notify_data_ext_parseFromJSON() failed [positioning_data_list]");
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
		event_notify_data_extJSON, "gnssPositioningDataList");
	if(gnss_positioning_data_list) {
		cJSON *gnss_positioning_data_list_local = NULL;
		if(!cJSON_IsArray(gnss_positioning_data_list)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [gnss_positioning_data_list]");
			goto end;
		}

		gnss_positioning_data_listList = list_create();

		cJSON_ArrayForEach(gnss_positioning_data_list_local,
		                   gnss_positioning_data_list) {
			if(!cJSON_IsObject(gnss_positioning_data_list_local)) {
				printf(
					"event_notify_data_ext_parseFromJSON() failed [gnss_positioning_data_list]");
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

	serving_lm_fidentification = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "servingLMFidentification");
	if(serving_lm_fidentification) {
		if(!cJSON_IsString(serving_lm_fidentification) &&
		   !cJSON_IsNull(serving_lm_fidentification))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [serving_lm_fidentification]");
			goto end;
		}
	}

	termination_cause = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "terminationCause");
	if(termination_cause) {
		if(!cJSON_IsString(termination_cause)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [termination_cause]");
			goto end;
		}
		termination_causeVariable = termination_cause_FromString(
			termination_cause->valuestring);
	}

	velocity_estimate = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "velocityEstimate");
	if(velocity_estimate) {
		velocity_estimate_local_nonprim =
			velocity_estimate_parseFromJSON(velocity_estimate);
		if(!velocity_estimate_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [velocity_estimate]");
			goto end;
		}
	}

	altitude = cJSON_GetObjectItemCaseSensitive(event_notify_data_extJSON,
	                                            "altitude");
	if(altitude) {
		if(!cJSON_IsNumber(altitude)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [altitude]");
			goto end;
		}
	}

	achieved_qos = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "achievedQos");
	if(achieved_qos) {
		achieved_qos_local_nonprim = minor_location_qo_s_parseFromJSON(
			achieved_qos);
		if(!achieved_qos_local_nonprim) {
			printf(
				"minor_location_qo_s_parseFromJSON failed [achieved_qos]");
			goto end;
		}
	}

	supported_features = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "supportedFeatures");
	if(supported_features) {
		if(!cJSON_IsString(supported_features) &&
		   !cJSON_IsNull(supported_features))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [supported_features]");
			goto end;
		}
	}

	indoor_outdoor_ind = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "indoorOutdoorInd");
	if(indoor_outdoor_ind) {
		if(!cJSON_IsString(indoor_outdoor_ind)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [indoor_outdoor_ind]");
			goto end;
		}
		indoor_outdoor_indVariable = indoor_outdoor_ind_FromString(
			indoor_outdoor_ind->valuestring);
	}

	ha_gnss_metrics = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "haGnssMetrics");
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
		event_notify_data_extJSON, "losNlosMeasureInd");
	if(los_nlos_measure_ind) {
		if(!cJSON_IsString(los_nlos_measure_ind)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [los_nlos_measure_ind]");
			goto end;
		}
		los_nlos_measure_indVariable = los_nlos_measure_ind_FromString(
			los_nlos_measure_ind->valuestring);
	}

	up_loc_rep_stat_af = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "upLocRepStatAf");
	if(up_loc_rep_stat_af) {
		if(!cJSON_IsNumber(up_loc_rep_stat_af)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [up_loc_rep_stat_af]");
			goto end;
		}
	}

	related_applicationlayer_id = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "relatedApplicationlayerId");
	if(related_applicationlayer_id) {
		if(!cJSON_IsString(related_applicationlayer_id) &&
		   !cJSON_IsNull(related_applicationlayer_id))
		{
			printf(
				"event_notify_data_ext_parseFromJSON() failed [related_applicationlayer_id]");
			goto end;
		}
	}

	distance_direction = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "distanceDirection");
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
		event_notify_data_extJSON, "2dRelativeLocation");
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
		event_notify_data_extJSON, "3dRelativeLocation");
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
		event_notify_data_extJSON, "relativeVelocity");
	if(relative_velocity) {
		relative_velocity_local_nonprim =
			velocity_estimate_parseFromJSON(relative_velocity);
		if(!relative_velocity_local_nonprim) {
			printf(
				"velocity_estimate_parseFromJSON failed [relative_velocity]");
			goto end;
		}
	}

	add_event_notify_datas = cJSON_GetObjectItemCaseSensitive(
		event_notify_data_extJSON, "addEventNotifyDatas");
	if(add_event_notify_datas) {
		cJSON *add_event_notify_datas_local = NULL;
		if(!cJSON_IsArray(add_event_notify_datas)) {
			printf(
				"event_notify_data_ext_parseFromJSON() failed [add_event_notify_datas]");
			goto end;
		}

		add_event_notify_datasList = list_create();

		cJSON_ArrayForEach(add_event_notify_datas_local,
		                   add_event_notify_datas) {
			if(!cJSON_IsObject(add_event_notify_datas_local)) {
				printf(
					"event_notify_data_ext_parseFromJSON() failed [add_event_notify_datas]");
				goto end;
			}
			event_notify_data_t *add_event_notify_datasItem =
				event_notify_data_parseFromJSON(
					add_event_notify_datas_local);
			if(!add_event_notify_datasItem) {
				printf("No add_event_notify_datasItem");
				goto end;
			}
			list_add(add_event_notify_datasList,
			         add_event_notify_datasItem);
		}
	}

	event_notify_data_ext_local_var = event_notify_data_ext_create(
		reported_event_typeVariable,
		supi &&
		!cJSON_IsNull(supi) ? strdup(supi->valuestring) : NULL,
		gpsi &&
		!cJSON_IsNull(gpsi) ? strdup(gpsi->valuestring) : NULL,
		hgmlc_call_back_uri &&
		!cJSON_IsNull(hgmlc_call_back_uri) ? strdup(hgmlc_call_back_uri
		                                            ->valuestring) : NULL,
		strdup(ldr_reference->valuestring),
		lir_reference &&
		!cJSON_IsNull(lir_reference) ? strdup(
			lir_reference->valuestring) : NULL,
		location_estimate ? location_estimate_local_nonprim : NULL,
		age_of_location_estimate ? true : false,
		age_of_location_estimate ? age_of_location_estimate->valuedouble : 0,
		timestamp_of_location_estimate &&
		!cJSON_IsNull(timestamp_of_location_estimate) ? strdup(
			timestamp_of_location_estimate->valuestring) : NULL,
		civic_address ? civic_address_local_nonprim : NULL,
		local_location_estimate ? local_location_estimate_local_nonprim : NULL,
		positioning_data_list ? positioning_data_listList : NULL,
		gnss_positioning_data_list ? gnss_positioning_data_listList : NULL,
		serving_lm_fidentification &&
		!cJSON_IsNull(serving_lm_fidentification) ? strdup(
			serving_lm_fidentification->valuestring) : NULL,
		termination_cause ? termination_causeVariable : 0,
		velocity_estimate ? velocity_estimate_local_nonprim : NULL,
		altitude ? true : false,
		altitude ? altitude->valuedouble : 0,
		achieved_qos ? achieved_qos_local_nonprim : NULL,
		supported_features &&
		!cJSON_IsNull(supported_features) ? strdup(supported_features->
		                                           valuestring) : NULL,
		indoor_outdoor_ind ? indoor_outdoor_indVariable : 0,
		ha_gnss_metrics ? ha_gnss_metrics_local_nonprim : NULL,
		los_nlos_measure_ind ? los_nlos_measure_indVariable : 0,
		up_loc_rep_stat_af ? true : false,
		up_loc_rep_stat_af ? up_loc_rep_stat_af->valuedouble : 0,
		related_applicationlayer_id &&
		!cJSON_IsNull(related_applicationlayer_id) ? strdup(
			related_applicationlayer_id->valuestring) : NULL,
		distance_direction ? distance_direction_local_nonprim : NULL,
		_2d_relative_location ? _2d_relative_location_local_nonprim : NULL,
		_3d_relative_location ? _3d_relative_location_local_nonprim : NULL,
		relative_velocity ? relative_velocity_local_nonprim : NULL,
		add_event_notify_datas ? add_event_notify_datasList : NULL
		);

	return event_notify_data_ext_local_var;
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
	if(velocity_estimate_local_nonprim) {
		velocity_estimate_free(velocity_estimate_local_nonprim);
		velocity_estimate_local_nonprim = NULL;
	}
	if(achieved_qos_local_nonprim) {
		minor_location_qo_s_free(achieved_qos_local_nonprim);
		achieved_qos_local_nonprim = NULL;
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
	if(add_event_notify_datasList) {
		list_for_each(add_event_notify_datasList, node) {
			event_notify_data_free(node->data);
		}
		list_free(add_event_notify_datasList);
		add_event_notify_datasList = NULL;
	}
	return NULL;
}

event_notify_data_ext_t *event_notify_data_ext_copy(
	event_notify_data_ext_t *dst, event_notify_data_ext_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = event_notify_data_ext_convertToJSON(src);
	if(!item) {
		printf("event_notify_data_ext_convertToJSON() failed");
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

	event_notify_data_ext_free(dst);
	dst = event_notify_data_ext_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
