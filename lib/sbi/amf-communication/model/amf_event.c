#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "amf_event.h"

amf_event_t *amf_event_create(amf_event_type_t *type, bool is_immediate_flag,
                              int immediate_flag, list_t *area_list,
                              list_t *location_filter_list, bool is_ref_id,
                              int ref_id, list_t *traffic_descriptor_list,
                              bool is_report_ue_reachable,
                              int report_ue_reachable,
                              reachability_filter_t *reachability_filter,
                              bool is_udm_detect_ind, int udm_detect_ind,
                              bool is_max_reports, int max_reports,
                              list_t *presence_info_list,
                              bool is_max_response_time, int max_response_time,
                              target_area_t *target_area, list_t *snssai_filter,
                              ue_in_area_filter_t *ue_in_area_filter,
                              bool is_min_interval, int min_interval,
                              char *next_report, bool is_idle_status_ind,
                              int idle_status_ind,
                              dispersion_area_t *dispersion_area,
                              char *next_periodic_report_time,
                              bool is_adjust_ao_ion_ra, int adjust_ao_ion_ra,
                              bool is_ran_timing_synchro_status_change,
                              int ran_timing_synchro_status_change,
                              list_t *notify_for_supi_list,
                              list_t *notify_for_group_list,
                              list_t *notify_for_snssai_dnn_list) {
	amf_event_t *amf_event_local_var = malloc(sizeof(amf_event_t));

	amf_event_local_var->type = type;
	amf_event_local_var->is_immediate_flag = is_immediate_flag;
	amf_event_local_var->immediate_flag = immediate_flag;
	amf_event_local_var->area_list = area_list;
	amf_event_local_var->location_filter_list = location_filter_list;
	amf_event_local_var->is_ref_id = is_ref_id;
	amf_event_local_var->ref_id = ref_id;
	amf_event_local_var->traffic_descriptor_list = traffic_descriptor_list;
	amf_event_local_var->is_report_ue_reachable = is_report_ue_reachable;
	amf_event_local_var->report_ue_reachable = report_ue_reachable;
	amf_event_local_var->reachability_filter = reachability_filter;
	amf_event_local_var->is_udm_detect_ind = is_udm_detect_ind;
	amf_event_local_var->udm_detect_ind = udm_detect_ind;
	amf_event_local_var->is_max_reports = is_max_reports;
	amf_event_local_var->max_reports = max_reports;
	amf_event_local_var->presence_info_list = presence_info_list;
	amf_event_local_var->is_max_response_time = is_max_response_time;
	amf_event_local_var->max_response_time = max_response_time;
	amf_event_local_var->target_area = target_area;
	amf_event_local_var->snssai_filter = snssai_filter;
	amf_event_local_var->ue_in_area_filter = ue_in_area_filter;
	amf_event_local_var->is_min_interval = is_min_interval;
	amf_event_local_var->min_interval = min_interval;
	amf_event_local_var->next_report = next_report;
	amf_event_local_var->is_idle_status_ind = is_idle_status_ind;
	amf_event_local_var->idle_status_ind = idle_status_ind;
	amf_event_local_var->dispersion_area = dispersion_area;
	amf_event_local_var->next_periodic_report_time =
		next_periodic_report_time;
	amf_event_local_var->is_adjust_ao_ion_ra = is_adjust_ao_ion_ra;
	amf_event_local_var->adjust_ao_ion_ra = adjust_ao_ion_ra;
	amf_event_local_var->is_ran_timing_synchro_status_change =
		is_ran_timing_synchro_status_change;
	amf_event_local_var->ran_timing_synchro_status_change =
		ran_timing_synchro_status_change;
	amf_event_local_var->notify_for_supi_list = notify_for_supi_list;
	amf_event_local_var->notify_for_group_list = notify_for_group_list;
	amf_event_local_var->notify_for_snssai_dnn_list =
		notify_for_snssai_dnn_list;

	return amf_event_local_var;
}

void amf_event_free(amf_event_t *amf_event) {
	lnode_t *node = NULL;

	if(NULL == amf_event) {
		return;
	}
	if(amf_event->type) {
		amf_event_type_free(amf_event->type);
		amf_event->type = NULL;
	}
	if(amf_event->area_list) {
		list_for_each(amf_event->area_list, node) {
			amf_event_area_free(node->data);
		}
		list_free(amf_event->area_list);
		amf_event->area_list = NULL;
	}
	if(amf_event->location_filter_list) {
		list_for_each(amf_event->location_filter_list, node) {
			location_filter_free(node->data);
		}
		list_free(amf_event->location_filter_list);
		amf_event->location_filter_list = NULL;
	}
	if(amf_event->traffic_descriptor_list) {
		list_for_each(amf_event->traffic_descriptor_list, node) {
			traffic_descriptor_free(node->data);
		}
		list_free(amf_event->traffic_descriptor_list);
		amf_event->traffic_descriptor_list = NULL;
	}
	if(amf_event->reachability_filter) {
		reachability_filter_free(amf_event->reachability_filter);
		amf_event->reachability_filter = NULL;
	}
	if(amf_event->presence_info_list) {
		list_for_each(amf_event->presence_info_list, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			presence_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(amf_event->presence_info_list);
		amf_event->presence_info_list = NULL;
	}
	if(amf_event->target_area) {
		target_area_free(amf_event->target_area);
		amf_event->target_area = NULL;
	}
	if(amf_event->snssai_filter) {
		list_for_each(amf_event->snssai_filter, node) {
			ext_snssai_free(node->data);
		}
		list_free(amf_event->snssai_filter);
		amf_event->snssai_filter = NULL;
	}
	if(amf_event->ue_in_area_filter) {
		ue_in_area_filter_free(amf_event->ue_in_area_filter);
		amf_event->ue_in_area_filter = NULL;
	}
	if(amf_event->next_report) {
		free(amf_event->next_report);
		amf_event->next_report = NULL;
	}
	if(amf_event->dispersion_area) {
		dispersion_area_free(amf_event->dispersion_area);
		amf_event->dispersion_area = NULL;
	}
	if(amf_event->next_periodic_report_time) {
		free(amf_event->next_periodic_report_time);
		amf_event->next_periodic_report_time = NULL;
	}
	if(amf_event->notify_for_supi_list) {
		list_for_each(amf_event->notify_for_supi_list, node) {
			free(node->data);
		}
		list_free(amf_event->notify_for_supi_list);
		amf_event->notify_for_supi_list = NULL;
	}
	if(amf_event->notify_for_group_list) {
		list_for_each(amf_event->notify_for_group_list, node) {
			free(node->data);
		}
		list_free(amf_event->notify_for_group_list);
		amf_event->notify_for_group_list = NULL;
	}
	if(amf_event->notify_for_snssai_dnn_list) {
		list_for_each(amf_event->notify_for_snssai_dnn_list, node) {
			snssai_dnn_item_free(node->data);
		}
		list_free(amf_event->notify_for_snssai_dnn_list);
		amf_event->notify_for_snssai_dnn_list = NULL;
	}
	free(amf_event);
}

cJSON *amf_event_convertToJSON(amf_event_t *amf_event) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(amf_event == NULL) {
		printf("amf_event_convertToJSON() failed [AmfEvent]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!amf_event->type) {
		printf("amf_event_convertToJSON() failed [type]");
		return NULL;
	}
	cJSON *type_local_JSON = amf_event_type_convertToJSON(amf_event->type);
	if(type_local_JSON == NULL) {
		printf("amf_event_convertToJSON() failed [type]");
		goto end;
	}
	cJSON_AddItemToObject(item, "type", type_local_JSON);
	if(item->child == NULL) {
		printf("amf_event_convertToJSON() failed [type]");
		goto end;
	}

	if(amf_event->is_immediate_flag) {
		if(cJSON_AddBoolToObject(item, "immediateFlag",
		                         amf_event->immediate_flag) == NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [immediate_flag]");
			goto end;
		}
	}

	if(amf_event->area_list) {
		cJSON *area_listList = cJSON_AddArrayToObject(item, "areaList");
		if(area_listList == NULL) {
			printf("amf_event_convertToJSON() failed [area_list]");
			goto end;
		}
		list_for_each(amf_event->area_list, node) {
			cJSON *itemLocal = amf_event_area_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"amf_event_convertToJSON() failed [area_list]");
				goto end;
			}
			cJSON_AddItemToArray(area_listList, itemLocal);
		}
	}

	if(amf_event->location_filter_list) {
		cJSON *location_filter_listList = cJSON_AddArrayToObject(item,
		                                                         "locationFilterList");
		if(location_filter_listList == NULL) {
			printf(
				"amf_event_convertToJSON() failed [location_filter_list]");
			goto end;
		}
		list_for_each(amf_event->location_filter_list, node) {
			cJSON *itemLocal = location_filter_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"amf_event_convertToJSON() failed [location_filter_list]");
				goto end;
			}
			cJSON_AddItemToArray(location_filter_listList,
			                     itemLocal);
		}
	}

	if(amf_event->is_ref_id) {
		if(cJSON_AddNumberToObject(item, "refId",
		                           amf_event->ref_id) == NULL)
		{
			printf("amf_event_convertToJSON() failed [ref_id]");
			goto end;
		}
	}

	if(amf_event->traffic_descriptor_list) {
		cJSON *traffic_descriptor_listList = cJSON_AddArrayToObject(
			item, "trafficDescriptorList");
		if(traffic_descriptor_listList == NULL) {
			printf(
				"amf_event_convertToJSON() failed [traffic_descriptor_list]");
			goto end;
		}
		list_for_each(amf_event->traffic_descriptor_list, node) {
			cJSON *itemLocal = traffic_descriptor_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"amf_event_convertToJSON() failed [traffic_descriptor_list]");
				goto end;
			}
			cJSON_AddItemToArray(traffic_descriptor_listList,
			                     itemLocal);
		}
	}

	if(amf_event->is_report_ue_reachable) {
		if(cJSON_AddBoolToObject(item, "reportUeReachable",
		                         amf_event->report_ue_reachable) ==
		   NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [report_ue_reachable]");
			goto end;
		}
	}

	if(amf_event->reachability_filter) {
		cJSON *reachability_filter_local_JSON =
			reachability_filter_convertToJSON(
				amf_event->reachability_filter);
		if(reachability_filter_local_JSON == NULL) {
			printf(
				"amf_event_convertToJSON() failed [reachability_filter]");
			goto end;
		}
		cJSON_AddItemToObject(item, "reachabilityFilter",
		                      reachability_filter_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_convertToJSON() failed [reachability_filter]");
			goto end;
		}
	}

	if(amf_event->is_udm_detect_ind) {
		if(cJSON_AddBoolToObject(item, "udmDetectInd",
		                         amf_event->udm_detect_ind) == NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [udm_detect_ind]");
			goto end;
		}
	}

	if(amf_event->is_max_reports) {
		if(cJSON_AddNumberToObject(item, "maxReports",
		                           amf_event->max_reports) == NULL)
		{
			printf("amf_event_convertToJSON() failed [max_reports]");
			goto end;
		}
	}

	if(amf_event->presence_info_list) {
		cJSON *presence_info_list = cJSON_AddObjectToObject(item,
		                                                    "presenceInfoList");
		if(presence_info_list == NULL) {
			printf(
				"amf_event_convertToJSON() failed [presence_info_list]");
			goto end;
		}
		cJSON *localMapObject = presence_info_list;
		if(amf_event->presence_info_list) {
			list_for_each(amf_event->presence_info_list, node) {
				map_t *localKeyValue = (map_t *) node->data;
				if(localKeyValue == NULL) {
					printf(
						"amf_event_convertToJSON() failed [presence_info_list]");
					goto end;
				}
				if(localKeyValue->key == NULL) {
					printf(
						"amf_event_convertToJSON() failed [presence_info_list]");
					goto end;
				}
				cJSON *itemLocal = localKeyValue->value ?
				                   presence_info_convertToJSON(
					localKeyValue->value) :
				                   cJSON_CreateNull();
				if(itemLocal == NULL) {
					printf(
						"amf_event_convertToJSON() failed [inner]");
					goto end;
				}
				cJSON_AddItemToObject(localMapObject,
				                      localKeyValue->key,
				                      itemLocal);
			}
		}
	}

	if(amf_event->is_max_response_time) {
		if(cJSON_AddNumberToObject(item, "maxResponseTime",
		                           amf_event->max_response_time) ==
		   NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [max_response_time]");
			goto end;
		}
	}

	if(amf_event->target_area) {
		cJSON *target_area_local_JSON = target_area_convertToJSON(
			amf_event->target_area);
		if(target_area_local_JSON == NULL) {
			printf("amf_event_convertToJSON() failed [target_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "targetArea",
		                      target_area_local_JSON);
		if(item->child == NULL) {
			printf("amf_event_convertToJSON() failed [target_area]");
			goto end;
		}
	}

	if(amf_event->snssai_filter) {
		cJSON *snssai_filterList = cJSON_AddArrayToObject(item,
		                                                  "snssaiFilter");
		if(snssai_filterList == NULL) {
			printf(
				"amf_event_convertToJSON() failed [snssai_filter]");
			goto end;
		}
		list_for_each(amf_event->snssai_filter, node) {
			cJSON *itemLocal = ext_snssai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"amf_event_convertToJSON() failed [snssai_filter]");
				goto end;
			}
			cJSON_AddItemToArray(snssai_filterList, itemLocal);
		}
	}

	if(amf_event->ue_in_area_filter) {
		cJSON *ue_in_area_filter_local_JSON =
			ue_in_area_filter_convertToJSON(
				amf_event->ue_in_area_filter);
		if(ue_in_area_filter_local_JSON == NULL) {
			printf(
				"amf_event_convertToJSON() failed [ue_in_area_filter]");
			goto end;
		}
		cJSON_AddItemToObject(item, "ueInAreaFilter",
		                      ue_in_area_filter_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_convertToJSON() failed [ue_in_area_filter]");
			goto end;
		}
	}

	if(amf_event->is_min_interval) {
		if(cJSON_AddNumberToObject(item, "minInterval",
		                           amf_event->min_interval) == NULL)
		{
			printf("amf_event_convertToJSON() failed [min_interval]");
			goto end;
		}
	}

	if(amf_event->next_report) {
		if(cJSON_AddStringToObject(item, "nextReport",
		                           amf_event->next_report) == NULL)
		{
			printf("amf_event_convertToJSON() failed [next_report]");
			goto end;
		}
	}

	if(amf_event->is_idle_status_ind) {
		if(cJSON_AddBoolToObject(item, "idleStatusInd",
		                         amf_event->idle_status_ind) == NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [idle_status_ind]");
			goto end;
		}
	}

	if(amf_event->dispersion_area) {
		cJSON *dispersion_area_local_JSON =
			dispersion_area_convertToJSON(amf_event->dispersion_area);
		if(dispersion_area_local_JSON == NULL) {
			printf(
				"amf_event_convertToJSON() failed [dispersion_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "dispersionArea",
		                      dispersion_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"amf_event_convertToJSON() failed [dispersion_area]");
			goto end;
		}
	}

	if(amf_event->next_periodic_report_time) {
		if(cJSON_AddStringToObject(item, "nextPeriodicReportTime",
		                           amf_event->next_periodic_report_time)
		   == NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [next_periodic_report_time]");
			goto end;
		}
	}

	if(amf_event->is_adjust_ao_ion_ra) {
		if(cJSON_AddBoolToObject(item, "adjustAoIOnRa",
		                         amf_event->adjust_ao_ion_ra) == NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [adjust_ao_ion_ra]");
			goto end;
		}
	}

	if(amf_event->is_ran_timing_synchro_status_change) {
		if(cJSON_AddBoolToObject(item, "ranTimingSynchroStatusChange",
		                         amf_event->
		                         ran_timing_synchro_status_change) ==
		   NULL)
		{
			printf(
				"amf_event_convertToJSON() failed [ran_timing_synchro_status_change]");
			goto end;
		}
	}

	if(amf_event->notify_for_supi_list) {
		cJSON *notify_for_supi_listList = cJSON_AddArrayToObject(item,
		                                                         "notifyForSupiList");
		if(notify_for_supi_listList == NULL) {
			printf(
				"amf_event_convertToJSON() failed [notify_for_supi_list]");
			goto end;
		}
		list_for_each(amf_event->notify_for_supi_list, node) {
			if(cJSON_AddStringToObject(notify_for_supi_listList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_convertToJSON() failed [notify_for_supi_list]");
				goto end;
			}
		}
	}

	if(amf_event->notify_for_group_list) {
		cJSON *notify_for_group_listList = cJSON_AddArrayToObject(item,
		                                                          "notifyForGroupList");
		if(notify_for_group_listList == NULL) {
			printf(
				"amf_event_convertToJSON() failed [notify_for_group_list]");
			goto end;
		}
		list_for_each(amf_event->notify_for_group_list, node) {
			if(cJSON_AddStringToObject(notify_for_group_listList,
			                           "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"amf_event_convertToJSON() failed [notify_for_group_list]");
				goto end;
			}
		}
	}

	if(amf_event->notify_for_snssai_dnn_list) {
		cJSON *notify_for_snssai_dnn_listList = cJSON_AddArrayToObject(
			item, "notifyForSnssaiDnnList");
		if(notify_for_snssai_dnn_listList == NULL) {
			printf(
				"amf_event_convertToJSON() failed [notify_for_snssai_dnn_list]");
			goto end;
		}
		list_for_each(amf_event->notify_for_snssai_dnn_list, node) {
			cJSON *itemLocal = snssai_dnn_item_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"amf_event_convertToJSON() failed [notify_for_snssai_dnn_list]");
				goto end;
			}
			cJSON_AddItemToArray(notify_for_snssai_dnn_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

amf_event_t *amf_event_parseFromJSON(cJSON *amf_eventJSON) {
	amf_event_t *amf_event_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *type = NULL;
	amf_event_type_t *type_local_nonprim = NULL;
	cJSON *immediate_flag = NULL;
	cJSON *area_list = NULL;
	list_t *area_listList = NULL;
	cJSON *location_filter_list = NULL;
	list_t *location_filter_listList = NULL;
	cJSON *ref_id = NULL;
	cJSON *traffic_descriptor_list = NULL;
	list_t *traffic_descriptor_listList = NULL;
	cJSON *report_ue_reachable = NULL;
	cJSON *reachability_filter = NULL;
	reachability_filter_t *reachability_filter_local_nonprim = NULL;
	cJSON *udm_detect_ind = NULL;
	cJSON *max_reports = NULL;
	cJSON *presence_info_list = NULL;
	list_t *presence_info_listList = NULL;
	cJSON *max_response_time = NULL;
	cJSON *target_area = NULL;
	target_area_t *target_area_local_nonprim = NULL;
	cJSON *snssai_filter = NULL;
	list_t *snssai_filterList = NULL;
	cJSON *ue_in_area_filter = NULL;
	ue_in_area_filter_t *ue_in_area_filter_local_nonprim = NULL;
	cJSON *min_interval = NULL;
	cJSON *next_report = NULL;
	cJSON *idle_status_ind = NULL;
	cJSON *dispersion_area = NULL;
	dispersion_area_t *dispersion_area_local_nonprim = NULL;
	cJSON *next_periodic_report_time = NULL;
	cJSON *adjust_ao_ion_ra = NULL;
	cJSON *ran_timing_synchro_status_change = NULL;
	cJSON *notify_for_supi_list = NULL;
	list_t *notify_for_supi_listList = NULL;
	cJSON *notify_for_group_list = NULL;
	list_t *notify_for_group_listList = NULL;
	cJSON *notify_for_snssai_dnn_list = NULL;
	list_t *notify_for_snssai_dnn_listList = NULL;
	type = cJSON_GetObjectItemCaseSensitive(amf_eventJSON, "type");
	if(!type) {
		printf("amf_event_parseFromJSON() failed [type]");
		goto end;
	}
	type_local_nonprim = amf_event_type_parseFromJSON(type);
	if(!type_local_nonprim) {
		printf("amf_event_type_parseFromJSON failed [type]");
		goto end;
	}

	immediate_flag = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                  "immediateFlag");
	if(immediate_flag) {
		if(!cJSON_IsBool(immediate_flag)) {
			printf(
				"amf_event_parseFromJSON() failed [immediate_flag]");
			goto end;
		}
	}

	area_list = cJSON_GetObjectItemCaseSensitive(amf_eventJSON, "areaList");
	if(area_list) {
		cJSON *area_list_local = NULL;
		if(!cJSON_IsArray(area_list)) {
			printf("amf_event_parseFromJSON() failed [area_list]");
			goto end;
		}

		area_listList = list_create();

		cJSON_ArrayForEach(area_list_local, area_list) {
			if(!cJSON_IsObject(area_list_local)) {
				printf(
					"amf_event_parseFromJSON() failed [area_list]");
				goto end;
			}
			amf_event_area_t *area_listItem =
				amf_event_area_parseFromJSON(area_list_local);
			if(!area_listItem) {
				printf("No area_listItem");
				goto end;
			}
			list_add(area_listList, area_listItem);
		}
	}

	location_filter_list = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                        "locationFilterList");
	if(location_filter_list) {
		cJSON *location_filter_list_local = NULL;
		if(!cJSON_IsArray(location_filter_list)) {
			printf(
				"amf_event_parseFromJSON() failed [location_filter_list]");
			goto end;
		}

		location_filter_listList = list_create();

		cJSON_ArrayForEach(location_filter_list_local,
		                   location_filter_list) {
			if(!cJSON_IsObject(location_filter_list_local)) {
				printf(
					"amf_event_parseFromJSON() failed [location_filter_list]");
				goto end;
			}
			location_filter_t *location_filter_listItem =
				location_filter_parseFromJSON(
					location_filter_list_local);
			if(!location_filter_listItem) {
				printf("No location_filter_listItem");
				goto end;
			}
			list_add(location_filter_listList,
			         location_filter_listItem);
		}
	}

	ref_id = cJSON_GetObjectItemCaseSensitive(amf_eventJSON, "refId");
	if(ref_id) {
		if(!cJSON_IsNumber(ref_id)) {
			printf("amf_event_parseFromJSON() failed [ref_id]");
			goto end;
		}
	}

	traffic_descriptor_list = cJSON_GetObjectItemCaseSensitive(
		amf_eventJSON, "trafficDescriptorList");
	if(traffic_descriptor_list) {
		cJSON *traffic_descriptor_list_local = NULL;
		if(!cJSON_IsArray(traffic_descriptor_list)) {
			printf(
				"amf_event_parseFromJSON() failed [traffic_descriptor_list]");
			goto end;
		}

		traffic_descriptor_listList = list_create();

		cJSON_ArrayForEach(traffic_descriptor_list_local,
		                   traffic_descriptor_list) {
			if(!cJSON_IsObject(traffic_descriptor_list_local)) {
				printf(
					"amf_event_parseFromJSON() failed [traffic_descriptor_list]");
				goto end;
			}
			traffic_descriptor_t *traffic_descriptor_listItem =
				traffic_descriptor_parseFromJSON(
					traffic_descriptor_list_local);
			if(!traffic_descriptor_listItem) {
				printf("No traffic_descriptor_listItem");
				goto end;
			}
			list_add(traffic_descriptor_listList,
			         traffic_descriptor_listItem);
		}
	}

	report_ue_reachable = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                       "reportUeReachable");
	if(report_ue_reachable) {
		if(!cJSON_IsBool(report_ue_reachable)) {
			printf(
				"amf_event_parseFromJSON() failed [report_ue_reachable]");
			goto end;
		}
	}

	reachability_filter = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                       "reachabilityFilter");
	if(reachability_filter) {
		reachability_filter_local_nonprim =
			reachability_filter_parseFromJSON(reachability_filter);
		if(!reachability_filter_local_nonprim) {
			printf(
				"reachability_filter_parseFromJSON failed [reachability_filter]");
			goto end;
		}
	}

	udm_detect_ind = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                  "udmDetectInd");
	if(udm_detect_ind) {
		if(!cJSON_IsBool(udm_detect_ind)) {
			printf(
				"amf_event_parseFromJSON() failed [udm_detect_ind]");
			goto end;
		}
	}

	max_reports = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                               "maxReports");
	if(max_reports) {
		if(!cJSON_IsNumber(max_reports)) {
			printf("amf_event_parseFromJSON() failed [max_reports]");
			goto end;
		}
	}

	presence_info_list = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                      "presenceInfoList");
	if(presence_info_list) {
		cJSON *presence_info_list_local_map = NULL;
		if(!cJSON_IsObject(presence_info_list) &&
		   !cJSON_IsNull(presence_info_list))
		{
			printf(
				"amf_event_parseFromJSON() failed [presence_info_list]");
			goto end;
		}
		if(cJSON_IsObject(presence_info_list)) {
			presence_info_listList = list_create();
			map_t *localMapKeyPair = NULL;
			cJSON_ArrayForEach(presence_info_list_local_map,
			                   presence_info_list) {
				cJSON *localMapObject =
					presence_info_list_local_map;
				if(cJSON_IsObject(localMapObject)) {
					localMapKeyPair = map_create(
						strdup(
							localMapObject->string), presence_info_parseFromJSON(
							localMapObject));
				} else if(cJSON_IsNull(localMapObject)) {
					localMapKeyPair =
						map_create(strdup(
								   localMapObject
								   ->string),
						           NULL);
				} else {
					printf(
						"amf_event_parseFromJSON() failed [inner]");
					goto end;
				}
				list_add(presence_info_listList,
				         localMapKeyPair);
			}
		}
	}

	max_response_time = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                     "maxResponseTime");
	if(max_response_time) {
		if(!cJSON_IsNumber(max_response_time)) {
			printf(
				"amf_event_parseFromJSON() failed [max_response_time]");
			goto end;
		}
	}

	target_area = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                               "targetArea");
	if(target_area) {
		target_area_local_nonprim = target_area_parseFromJSON(
			target_area);
		if(!target_area_local_nonprim) {
			printf("target_area_parseFromJSON failed [target_area]");
			goto end;
		}
	}

	snssai_filter = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                 "snssaiFilter");
	if(snssai_filter) {
		cJSON *snssai_filter_local = NULL;
		if(!cJSON_IsArray(snssai_filter)) {
			printf(
				"amf_event_parseFromJSON() failed [snssai_filter]");
			goto end;
		}

		snssai_filterList = list_create();

		cJSON_ArrayForEach(snssai_filter_local, snssai_filter) {
			if(!cJSON_IsObject(snssai_filter_local)) {
				printf(
					"amf_event_parseFromJSON() failed [snssai_filter]");
				goto end;
			}
			ext_snssai_t *snssai_filterItem =
				ext_snssai_parseFromJSON(snssai_filter_local);
			if(!snssai_filterItem) {
				printf("No snssai_filterItem");
				goto end;
			}
			list_add(snssai_filterList, snssai_filterItem);
		}
	}

	ue_in_area_filter = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                     "ueInAreaFilter");
	if(ue_in_area_filter) {
		ue_in_area_filter_local_nonprim =
			ue_in_area_filter_parseFromJSON(ue_in_area_filter);
		if(!ue_in_area_filter_local_nonprim) {
			printf(
				"ue_in_area_filter_parseFromJSON failed [ue_in_area_filter]");
			goto end;
		}
	}

	min_interval = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                "minInterval");
	if(min_interval) {
		if(!cJSON_IsNumber(min_interval)) {
			printf("amf_event_parseFromJSON() failed [min_interval]");
			goto end;
		}
	}

	next_report = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                               "nextReport");
	if(next_report) {
		if(!cJSON_IsString(next_report) &&
		   !cJSON_IsNull(next_report))
		{
			printf("amf_event_parseFromJSON() failed [next_report]");
			goto end;
		}
	}

	idle_status_ind = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                   "idleStatusInd");
	if(idle_status_ind) {
		if(!cJSON_IsBool(idle_status_ind)) {
			printf(
				"amf_event_parseFromJSON() failed [idle_status_ind]");
			goto end;
		}
	}

	dispersion_area = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                   "dispersionArea");
	if(dispersion_area) {
		dispersion_area_local_nonprim = dispersion_area_parseFromJSON(
			dispersion_area);
		if(!dispersion_area_local_nonprim) {
			printf(
				"dispersion_area_parseFromJSON failed [dispersion_area]");
			goto end;
		}
	}

	next_periodic_report_time = cJSON_GetObjectItemCaseSensitive(
		amf_eventJSON, "nextPeriodicReportTime");
	if(next_periodic_report_time) {
		if(!cJSON_IsString(next_periodic_report_time) &&
		   !cJSON_IsNull(next_periodic_report_time))
		{
			printf(
				"amf_event_parseFromJSON() failed [next_periodic_report_time]");
			goto end;
		}
	}

	adjust_ao_ion_ra = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                    "adjustAoIOnRa");
	if(adjust_ao_ion_ra) {
		if(!cJSON_IsBool(adjust_ao_ion_ra)) {
			printf(
				"amf_event_parseFromJSON() failed [adjust_ao_ion_ra]");
			goto end;
		}
	}

	ran_timing_synchro_status_change = cJSON_GetObjectItemCaseSensitive(
		amf_eventJSON, "ranTimingSynchroStatusChange");
	if(ran_timing_synchro_status_change) {
		if(!cJSON_IsBool(ran_timing_synchro_status_change)) {
			printf(
				"amf_event_parseFromJSON() failed [ran_timing_synchro_status_change]");
			goto end;
		}
	}

	notify_for_supi_list = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                        "notifyForSupiList");
	if(notify_for_supi_list) {
		cJSON *notify_for_supi_list_local = NULL;
		if(!cJSON_IsArray(notify_for_supi_list)) {
			printf(
				"amf_event_parseFromJSON() failed [notify_for_supi_list]");
			goto end;
		}

		notify_for_supi_listList = list_create();

		cJSON_ArrayForEach(notify_for_supi_list_local,
		                   notify_for_supi_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(notify_for_supi_list_local)) {
				printf(
					"amf_event_parseFromJSON() failed [notify_for_supi_list]");
				goto end;
			}
			list_add(notify_for_supi_listList,
			         strdup(notify_for_supi_list_local->valuestring));
		}
	}

	notify_for_group_list = cJSON_GetObjectItemCaseSensitive(amf_eventJSON,
	                                                         "notifyForGroupList");
	if(notify_for_group_list) {
		cJSON *notify_for_group_list_local = NULL;
		if(!cJSON_IsArray(notify_for_group_list)) {
			printf(
				"amf_event_parseFromJSON() failed [notify_for_group_list]");
			goto end;
		}

		notify_for_group_listList = list_create();

		cJSON_ArrayForEach(notify_for_group_list_local,
		                   notify_for_group_list) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(notify_for_group_list_local)) {
				printf(
					"amf_event_parseFromJSON() failed [notify_for_group_list]");
				goto end;
			}
			list_add(notify_for_group_listList,
			         strdup(
					 notify_for_group_list_local->
					 valuestring));
		}
	}

	notify_for_snssai_dnn_list = cJSON_GetObjectItemCaseSensitive(
		amf_eventJSON, "notifyForSnssaiDnnList");
	if(notify_for_snssai_dnn_list) {
		cJSON *notify_for_snssai_dnn_list_local = NULL;
		if(!cJSON_IsArray(notify_for_snssai_dnn_list)) {
			printf(
				"amf_event_parseFromJSON() failed [notify_for_snssai_dnn_list]");
			goto end;
		}

		notify_for_snssai_dnn_listList = list_create();

		cJSON_ArrayForEach(notify_for_snssai_dnn_list_local,
		                   notify_for_snssai_dnn_list) {
			if(!cJSON_IsObject(notify_for_snssai_dnn_list_local)) {
				printf(
					"amf_event_parseFromJSON() failed [notify_for_snssai_dnn_list]");
				goto end;
			}
			snssai_dnn_item_t *notify_for_snssai_dnn_listItem =
				snssai_dnn_item_parseFromJSON(
					notify_for_snssai_dnn_list_local);
			if(!notify_for_snssai_dnn_listItem) {
				printf("No notify_for_snssai_dnn_listItem");
				goto end;
			}
			list_add(notify_for_snssai_dnn_listList,
			         notify_for_snssai_dnn_listItem);
		}
	}

	amf_event_local_var = amf_event_create(
		type_local_nonprim,
		immediate_flag ? true : false,
		immediate_flag ? immediate_flag->valueint : 0,
		area_list ? area_listList : NULL,
		location_filter_list ? location_filter_listList : NULL,
		ref_id ? true : false,
		ref_id ? ref_id->valuedouble : 0,
		traffic_descriptor_list ? traffic_descriptor_listList : NULL,
		report_ue_reachable ? true : false,
		report_ue_reachable ? report_ue_reachable->valueint : 0,
		reachability_filter ? reachability_filter_local_nonprim : NULL,
		udm_detect_ind ? true : false,
		udm_detect_ind ? udm_detect_ind->valueint : 0,
		max_reports ? true : false,
		max_reports ? max_reports->valuedouble : 0,
		presence_info_list ? presence_info_listList : NULL,
		max_response_time ? true : false,
		max_response_time ? max_response_time->valuedouble : 0,
		target_area ? target_area_local_nonprim : NULL,
		snssai_filter ? snssai_filterList : NULL,
		ue_in_area_filter ? ue_in_area_filter_local_nonprim : NULL,
		min_interval ? true : false,
		min_interval ? min_interval->valuedouble : 0,
		next_report &&
		!cJSON_IsNull(next_report) ? strdup(
			next_report->valuestring) : NULL,
		idle_status_ind ? true : false,
		idle_status_ind ? idle_status_ind->valueint : 0,
		dispersion_area ? dispersion_area_local_nonprim : NULL,
		next_periodic_report_time &&
		!cJSON_IsNull(next_periodic_report_time) ? strdup(
			next_periodic_report_time->valuestring) : NULL,
		adjust_ao_ion_ra ? true : false,
		adjust_ao_ion_ra ? adjust_ao_ion_ra->valueint : 0,
		ran_timing_synchro_status_change ? true : false,
		ran_timing_synchro_status_change ? ran_timing_synchro_status_change->valueint : 0,
		notify_for_supi_list ? notify_for_supi_listList : NULL,
		notify_for_group_list ? notify_for_group_listList : NULL,
		notify_for_snssai_dnn_list ? notify_for_snssai_dnn_listList : NULL
		);

	return amf_event_local_var;
end:
	if(type_local_nonprim) {
		amf_event_type_free(type_local_nonprim);
		type_local_nonprim = NULL;
	}
	if(area_listList) {
		list_for_each(area_listList, node) {
			amf_event_area_free(node->data);
		}
		list_free(area_listList);
		area_listList = NULL;
	}
	if(location_filter_listList) {
		list_for_each(location_filter_listList, node) {
			location_filter_free(node->data);
		}
		list_free(location_filter_listList);
		location_filter_listList = NULL;
	}
	if(traffic_descriptor_listList) {
		list_for_each(traffic_descriptor_listList, node) {
			traffic_descriptor_free(node->data);
		}
		list_free(traffic_descriptor_listList);
		traffic_descriptor_listList = NULL;
	}
	if(reachability_filter_local_nonprim) {
		reachability_filter_free(reachability_filter_local_nonprim);
		reachability_filter_local_nonprim = NULL;
	}
	if(presence_info_listList) {
		list_for_each(presence_info_listList, node) {
			map_t *localKeyValue = (map_t *) node->data;
			free(localKeyValue->key);
			presence_info_free(localKeyValue->value);
			map_free(localKeyValue);
		}
		list_free(presence_info_listList);
		presence_info_listList = NULL;
	}
	if(target_area_local_nonprim) {
		target_area_free(target_area_local_nonprim);
		target_area_local_nonprim = NULL;
	}
	if(snssai_filterList) {
		list_for_each(snssai_filterList, node) {
			ext_snssai_free(node->data);
		}
		list_free(snssai_filterList);
		snssai_filterList = NULL;
	}
	if(ue_in_area_filter_local_nonprim) {
		ue_in_area_filter_free(ue_in_area_filter_local_nonprim);
		ue_in_area_filter_local_nonprim = NULL;
	}
	if(dispersion_area_local_nonprim) {
		dispersion_area_free(dispersion_area_local_nonprim);
		dispersion_area_local_nonprim = NULL;
	}
	if(notify_for_supi_listList) {
		list_for_each(notify_for_supi_listList, node) {
			free(node->data);
		}
		list_free(notify_for_supi_listList);
		notify_for_supi_listList = NULL;
	}
	if(notify_for_group_listList) {
		list_for_each(notify_for_group_listList, node) {
			free(node->data);
		}
		list_free(notify_for_group_listList);
		notify_for_group_listList = NULL;
	}
	if(notify_for_snssai_dnn_listList) {
		list_for_each(notify_for_snssai_dnn_listList, node) {
			snssai_dnn_item_free(node->data);
		}
		list_free(notify_for_snssai_dnn_listList);
		notify_for_snssai_dnn_listList = NULL;
	}
	return NULL;
}

amf_event_t *amf_event_copy(amf_event_t *dst, amf_event_t *src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = amf_event_convertToJSON(src);
	if(!item) {
		printf("amf_event_convertToJSON() failed");
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

	amf_event_free(dst);
	dst = amf_event_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
