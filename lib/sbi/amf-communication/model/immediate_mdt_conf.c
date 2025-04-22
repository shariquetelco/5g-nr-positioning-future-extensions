#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "immediate_mdt_conf.h"

immediate_mdt_conf_t *immediate_mdt_conf_create(job_type_t *job_type,
                                                list_t *measurement_lte_list,
                                                list_t *measurement_nr_list,
                                                list_t *reporting_trigger_list,
                                                report_interval_mdt_t *report_interval, report_interval_nr_mdt_t *report_interval_nr, report_amount_mdt_t *report_amount, bool is_event_threshold_rsrp, int event_threshold_rsrp, bool is_event_threshold_rsrq, int event_threshold_rsrq, bool is_event_threshold_rsrp_nr, int event_threshold_rsrp_nr, bool is_event_threshold_rsrq_nr, int event_threshold_rsrq_nr, collection_period_rmm_lte_mdt_t *collection_period_rmm_lte, collection_period_rmm_nr_mdt_t *collection_period_rmm_nr, measurement_period_lte_mdt_t *measurement_period_lte, area_scope_t *area_scope, positioning_method_mdt_t *positioning_method, list_t *add_positioning_method_list, list_t *mdt_allowed_plmn_id_list,
                                                list_t *sensor_measurement_list)
{
	immediate_mdt_conf_t *immediate_mdt_conf_local_var =
		malloc(sizeof(immediate_mdt_conf_t));

	immediate_mdt_conf_local_var->job_type = job_type;
	immediate_mdt_conf_local_var->measurement_lte_list =
		measurement_lte_list;
	immediate_mdt_conf_local_var->measurement_nr_list = measurement_nr_list;
	immediate_mdt_conf_local_var->reporting_trigger_list =
		reporting_trigger_list;
	immediate_mdt_conf_local_var->report_interval = report_interval;
	immediate_mdt_conf_local_var->report_interval_nr = report_interval_nr;
	immediate_mdt_conf_local_var->report_amount = report_amount;
	immediate_mdt_conf_local_var->is_event_threshold_rsrp =
		is_event_threshold_rsrp;
	immediate_mdt_conf_local_var->event_threshold_rsrp =
		event_threshold_rsrp;
	immediate_mdt_conf_local_var->is_event_threshold_rsrq =
		is_event_threshold_rsrq;
	immediate_mdt_conf_local_var->event_threshold_rsrq =
		event_threshold_rsrq;
	immediate_mdt_conf_local_var->is_event_threshold_rsrp_nr =
		is_event_threshold_rsrp_nr;
	immediate_mdt_conf_local_var->event_threshold_rsrp_nr =
		event_threshold_rsrp_nr;
	immediate_mdt_conf_local_var->is_event_threshold_rsrq_nr =
		is_event_threshold_rsrq_nr;
	immediate_mdt_conf_local_var->event_threshold_rsrq_nr =
		event_threshold_rsrq_nr;
	immediate_mdt_conf_local_var->collection_period_rmm_lte =
		collection_period_rmm_lte;
	immediate_mdt_conf_local_var->collection_period_rmm_nr =
		collection_period_rmm_nr;
	immediate_mdt_conf_local_var->measurement_period_lte =
		measurement_period_lte;
	immediate_mdt_conf_local_var->area_scope = area_scope;
	immediate_mdt_conf_local_var->positioning_method = positioning_method;
	immediate_mdt_conf_local_var->add_positioning_method_list =
		add_positioning_method_list;
	immediate_mdt_conf_local_var->mdt_allowed_plmn_id_list =
		mdt_allowed_plmn_id_list;
	immediate_mdt_conf_local_var->sensor_measurement_list =
		sensor_measurement_list;

	return immediate_mdt_conf_local_var;
}

void immediate_mdt_conf_free(immediate_mdt_conf_t *immediate_mdt_conf) {
	lnode_t *node = NULL;

	if(NULL == immediate_mdt_conf) {
		return;
	}
	if(immediate_mdt_conf->job_type) {
		job_type_free(immediate_mdt_conf->job_type);
		immediate_mdt_conf->job_type = NULL;
	}
	if(immediate_mdt_conf->measurement_lte_list) {
		list_for_each(immediate_mdt_conf->measurement_lte_list, node) {
			measurement_lte_for_mdt_free(node->data);
		}
		list_free(immediate_mdt_conf->measurement_lte_list);
		immediate_mdt_conf->measurement_lte_list = NULL;
	}
	if(immediate_mdt_conf->measurement_nr_list) {
		list_for_each(immediate_mdt_conf->measurement_nr_list, node) {
			measurement_nr_for_mdt_free(node->data);
		}
		list_free(immediate_mdt_conf->measurement_nr_list);
		immediate_mdt_conf->measurement_nr_list = NULL;
	}
	if(immediate_mdt_conf->reporting_trigger_list) {
		list_for_each(immediate_mdt_conf->reporting_trigger_list,
		              node) {
			reporting_trigger_free(node->data);
		}
		list_free(immediate_mdt_conf->reporting_trigger_list);
		immediate_mdt_conf->reporting_trigger_list = NULL;
	}
	if(immediate_mdt_conf->report_interval) {
		report_interval_mdt_free(immediate_mdt_conf->report_interval);
		immediate_mdt_conf->report_interval = NULL;
	}
	if(immediate_mdt_conf->report_interval_nr) {
		report_interval_nr_mdt_free(
			immediate_mdt_conf->report_interval_nr);
		immediate_mdt_conf->report_interval_nr = NULL;
	}
	if(immediate_mdt_conf->report_amount) {
		report_amount_mdt_free(immediate_mdt_conf->report_amount);
		immediate_mdt_conf->report_amount = NULL;
	}
	if(immediate_mdt_conf->collection_period_rmm_lte) {
		collection_period_rmm_lte_mdt_free(
			immediate_mdt_conf->collection_period_rmm_lte);
		immediate_mdt_conf->collection_period_rmm_lte = NULL;
	}
	if(immediate_mdt_conf->collection_period_rmm_nr) {
		collection_period_rmm_nr_mdt_free(
			immediate_mdt_conf->collection_period_rmm_nr);
		immediate_mdt_conf->collection_period_rmm_nr = NULL;
	}
	if(immediate_mdt_conf->measurement_period_lte) {
		measurement_period_lte_mdt_free(
			immediate_mdt_conf->measurement_period_lte);
		immediate_mdt_conf->measurement_period_lte = NULL;
	}
	if(immediate_mdt_conf->area_scope) {
		area_scope_free(immediate_mdt_conf->area_scope);
		immediate_mdt_conf->area_scope = NULL;
	}
	if(immediate_mdt_conf->positioning_method) {
		positioning_method_mdt_free(
			immediate_mdt_conf->positioning_method);
		immediate_mdt_conf->positioning_method = NULL;
	}
	if(immediate_mdt_conf->add_positioning_method_list) {
		list_for_each(immediate_mdt_conf->add_positioning_method_list,
		              node) {
			positioning_method_mdt_free(node->data);
		}
		list_free(immediate_mdt_conf->add_positioning_method_list);
		immediate_mdt_conf->add_positioning_method_list = NULL;
	}
	if(immediate_mdt_conf->mdt_allowed_plmn_id_list) {
		list_for_each(immediate_mdt_conf->mdt_allowed_plmn_id_list,
		              node) {
			plmn_id_free(node->data);
		}
		list_free(immediate_mdt_conf->mdt_allowed_plmn_id_list);
		immediate_mdt_conf->mdt_allowed_plmn_id_list = NULL;
	}
	if(immediate_mdt_conf->sensor_measurement_list) {
		list_for_each(immediate_mdt_conf->sensor_measurement_list,
		              node) {
			sensor_measurement_free(node->data);
		}
		list_free(immediate_mdt_conf->sensor_measurement_list);
		immediate_mdt_conf->sensor_measurement_list = NULL;
	}
	free(immediate_mdt_conf);
}

cJSON *immediate_mdt_conf_convertToJSON(
	immediate_mdt_conf_t *immediate_mdt_conf) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(immediate_mdt_conf == NULL) {
		printf(
			"immediate_mdt_conf_convertToJSON() failed [ImmediateMdtConf]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!immediate_mdt_conf->job_type) {
		printf("immediate_mdt_conf_convertToJSON() failed [job_type]");
		return NULL;
	}
	cJSON *job_type_local_JSON = job_type_convertToJSON(
		immediate_mdt_conf->job_type);
	if(job_type_local_JSON == NULL) {
		printf("immediate_mdt_conf_convertToJSON() failed [job_type]");
		goto end;
	}
	cJSON_AddItemToObject(item, "jobType", job_type_local_JSON);
	if(item->child == NULL) {
		printf("immediate_mdt_conf_convertToJSON() failed [job_type]");
		goto end;
	}

	if(immediate_mdt_conf->measurement_lte_list) {
		cJSON *measurement_lte_listList = cJSON_AddArrayToObject(item,
		                                                         "measurementLteList");
		if(measurement_lte_listList == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [measurement_lte_list]");
			goto end;
		}
		list_for_each(immediate_mdt_conf->measurement_lte_list, node) {
			cJSON *itemLocal =
				measurement_lte_for_mdt_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"immediate_mdt_conf_convertToJSON() failed [measurement_lte_list]");
				goto end;
			}
			cJSON_AddItemToArray(measurement_lte_listList,
			                     itemLocal);
		}
	}

	if(immediate_mdt_conf->measurement_nr_list) {
		cJSON *measurement_nr_listList = cJSON_AddArrayToObject(item,
		                                                        "measurementNrList");
		if(measurement_nr_listList == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [measurement_nr_list]");
			goto end;
		}
		list_for_each(immediate_mdt_conf->measurement_nr_list, node) {
			cJSON *itemLocal = measurement_nr_for_mdt_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"immediate_mdt_conf_convertToJSON() failed [measurement_nr_list]");
				goto end;
			}
			cJSON_AddItemToArray(measurement_nr_listList,
			                     itemLocal);
		}
	}

	if(immediate_mdt_conf->reporting_trigger_list) {
		cJSON *reporting_trigger_listList = cJSON_AddArrayToObject(item,
		                                                           "reportingTriggerList");
		if(reporting_trigger_listList == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [reporting_trigger_list]");
			goto end;
		}
		list_for_each(immediate_mdt_conf->reporting_trigger_list,
		              node) {
			cJSON *itemLocal = reporting_trigger_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"immediate_mdt_conf_convertToJSON() failed [reporting_trigger_list]");
				goto end;
			}
			cJSON_AddItemToArray(reporting_trigger_listList,
			                     itemLocal);
		}
	}

	if(immediate_mdt_conf->report_interval) {
		cJSON *report_interval_local_JSON =
			report_interval_mdt_convertToJSON(
				immediate_mdt_conf->report_interval);
		if(report_interval_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [report_interval]");
			goto end;
		}
		cJSON_AddItemToObject(item, "reportInterval",
		                      report_interval_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [report_interval]");
			goto end;
		}
	}

	if(immediate_mdt_conf->report_interval_nr) {
		cJSON *report_interval_nr_local_JSON =
			report_interval_nr_mdt_convertToJSON(
				immediate_mdt_conf->report_interval_nr);
		if(report_interval_nr_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [report_interval_nr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "reportIntervalNr",
		                      report_interval_nr_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [report_interval_nr]");
			goto end;
		}
	}

	if(immediate_mdt_conf->report_amount) {
		cJSON *report_amount_local_JSON =
			report_amount_mdt_convertToJSON(
				immediate_mdt_conf->report_amount);
		if(report_amount_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [report_amount]");
			goto end;
		}
		cJSON_AddItemToObject(item, "reportAmount",
		                      report_amount_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [report_amount]");
			goto end;
		}
	}

	if(immediate_mdt_conf->is_event_threshold_rsrp) {
		if(cJSON_AddNumberToObject(item, "eventThresholdRsrp",
		                           immediate_mdt_conf->
		                           event_threshold_rsrp) == NULL)
		{
			printf(
				"immediate_mdt_conf_convertToJSON() failed [event_threshold_rsrp]");
			goto end;
		}
	}

	if(immediate_mdt_conf->is_event_threshold_rsrq) {
		if(cJSON_AddNumberToObject(item, "eventThresholdRsrq",
		                           immediate_mdt_conf->
		                           event_threshold_rsrq) == NULL)
		{
			printf(
				"immediate_mdt_conf_convertToJSON() failed [event_threshold_rsrq]");
			goto end;
		}
	}

	if(immediate_mdt_conf->is_event_threshold_rsrp_nr) {
		if(cJSON_AddNumberToObject(item, "eventThresholdRsrpNr",
		                           immediate_mdt_conf->
		                           event_threshold_rsrp_nr) == NULL)
		{
			printf(
				"immediate_mdt_conf_convertToJSON() failed [event_threshold_rsrp_nr]");
			goto end;
		}
	}

	if(immediate_mdt_conf->is_event_threshold_rsrq_nr) {
		if(cJSON_AddNumberToObject(item, "eventThresholdRsrqNr",
		                           immediate_mdt_conf->
		                           event_threshold_rsrq_nr) == NULL)
		{
			printf(
				"immediate_mdt_conf_convertToJSON() failed [event_threshold_rsrq_nr]");
			goto end;
		}
	}

	if(immediate_mdt_conf->collection_period_rmm_lte) {
		cJSON *collection_period_rmm_lte_local_JSON =
			collection_period_rmm_lte_mdt_convertToJSON(
				immediate_mdt_conf->collection_period_rmm_lte);
		if(collection_period_rmm_lte_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [collection_period_rmm_lte]");
			goto end;
		}
		cJSON_AddItemToObject(item, "collectionPeriodRmmLte",
		                      collection_period_rmm_lte_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [collection_period_rmm_lte]");
			goto end;
		}
	}

	if(immediate_mdt_conf->collection_period_rmm_nr) {
		cJSON *collection_period_rmm_nr_local_JSON =
			collection_period_rmm_nr_mdt_convertToJSON(
				immediate_mdt_conf->collection_period_rmm_nr);
		if(collection_period_rmm_nr_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [collection_period_rmm_nr]");
			goto end;
		}
		cJSON_AddItemToObject(item, "collectionPeriodRmmNr",
		                      collection_period_rmm_nr_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [collection_period_rmm_nr]");
			goto end;
		}
	}

	if(immediate_mdt_conf->measurement_period_lte) {
		cJSON *measurement_period_lte_local_JSON =
			measurement_period_lte_mdt_convertToJSON(
				immediate_mdt_conf->measurement_period_lte);
		if(measurement_period_lte_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [measurement_period_lte]");
			goto end;
		}
		cJSON_AddItemToObject(item, "measurementPeriodLte",
		                      measurement_period_lte_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [measurement_period_lte]");
			goto end;
		}
	}

	if(immediate_mdt_conf->area_scope) {
		cJSON *area_scope_local_JSON = area_scope_convertToJSON(
			immediate_mdt_conf->area_scope);
		if(area_scope_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [area_scope]");
			goto end;
		}
		cJSON_AddItemToObject(item, "areaScope", area_scope_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [area_scope]");
			goto end;
		}
	}

	if(immediate_mdt_conf->positioning_method) {
		cJSON *positioning_method_local_JSON =
			positioning_method_mdt_convertToJSON(
				immediate_mdt_conf->positioning_method);
		if(positioning_method_local_JSON == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [positioning_method]");
			goto end;
		}
		cJSON_AddItemToObject(item, "positioningMethod",
		                      positioning_method_local_JSON);
		if(item->child == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [positioning_method]");
			goto end;
		}
	}

	if(immediate_mdt_conf->add_positioning_method_list) {
		cJSON *add_positioning_method_listList = cJSON_AddArrayToObject(
			item, "addPositioningMethodList");
		if(add_positioning_method_listList == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [add_positioning_method_list]");
			goto end;
		}
		list_for_each(immediate_mdt_conf->add_positioning_method_list,
		              node) {
			cJSON *itemLocal = positioning_method_mdt_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"immediate_mdt_conf_convertToJSON() failed [add_positioning_method_list]");
				goto end;
			}
			cJSON_AddItemToArray(add_positioning_method_listList,
			                     itemLocal);
		}
	}

	if(immediate_mdt_conf->mdt_allowed_plmn_id_list) {
		cJSON *mdt_allowed_plmn_id_listList = cJSON_AddArrayToObject(
			item, "mdtAllowedPlmnIdList");
		if(mdt_allowed_plmn_id_listList == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [mdt_allowed_plmn_id_list]");
			goto end;
		}
		list_for_each(immediate_mdt_conf->mdt_allowed_plmn_id_list,
		              node) {
			cJSON *itemLocal = plmn_id_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"immediate_mdt_conf_convertToJSON() failed [mdt_allowed_plmn_id_list]");
				goto end;
			}
			cJSON_AddItemToArray(mdt_allowed_plmn_id_listList,
			                     itemLocal);
		}
	}

	if(immediate_mdt_conf->sensor_measurement_list) {
		cJSON *sensor_measurement_listList = cJSON_AddArrayToObject(
			item, "sensorMeasurementList");
		if(sensor_measurement_listList == NULL) {
			printf(
				"immediate_mdt_conf_convertToJSON() failed [sensor_measurement_list]");
			goto end;
		}
		list_for_each(immediate_mdt_conf->sensor_measurement_list,
		              node) {
			cJSON *itemLocal = sensor_measurement_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"immediate_mdt_conf_convertToJSON() failed [sensor_measurement_list]");
				goto end;
			}
			cJSON_AddItemToArray(sensor_measurement_listList,
			                     itemLocal);
		}
	}

end:
	return item;
}

immediate_mdt_conf_t *immediate_mdt_conf_parseFromJSON(
	cJSON *immediate_mdt_confJSON) {
	immediate_mdt_conf_t *immediate_mdt_conf_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *job_type = NULL;
	job_type_t *job_type_local_nonprim = NULL;
	cJSON *measurement_lte_list = NULL;
	list_t *measurement_lte_listList = NULL;
	cJSON *measurement_nr_list = NULL;
	list_t *measurement_nr_listList = NULL;
	cJSON *reporting_trigger_list = NULL;
	list_t *reporting_trigger_listList = NULL;
	cJSON *report_interval = NULL;
	report_interval_mdt_t *report_interval_local_nonprim = NULL;
	cJSON *report_interval_nr = NULL;
	report_interval_nr_mdt_t *report_interval_nr_local_nonprim = NULL;
	cJSON *report_amount = NULL;
	report_amount_mdt_t *report_amount_local_nonprim = NULL;
	cJSON *event_threshold_rsrp = NULL;
	cJSON *event_threshold_rsrq = NULL;
	cJSON *event_threshold_rsrp_nr = NULL;
	cJSON *event_threshold_rsrq_nr = NULL;
	cJSON *collection_period_rmm_lte = NULL;
	collection_period_rmm_lte_mdt_t *collection_period_rmm_lte_local_nonprim
	        = NULL;
	cJSON *collection_period_rmm_nr = NULL;
	collection_period_rmm_nr_mdt_t *collection_period_rmm_nr_local_nonprim =
		NULL;
	cJSON *measurement_period_lte = NULL;
	measurement_period_lte_mdt_t *measurement_period_lte_local_nonprim =
		NULL;
	cJSON *area_scope = NULL;
	area_scope_t *area_scope_local_nonprim = NULL;
	cJSON *positioning_method = NULL;
	positioning_method_mdt_t *positioning_method_local_nonprim = NULL;
	cJSON *add_positioning_method_list = NULL;
	list_t *add_positioning_method_listList = NULL;
	cJSON *mdt_allowed_plmn_id_list = NULL;
	list_t *mdt_allowed_plmn_id_listList = NULL;
	cJSON *sensor_measurement_list = NULL;
	list_t *sensor_measurement_listList = NULL;
	job_type = cJSON_GetObjectItemCaseSensitive(immediate_mdt_confJSON,
	                                            "jobType");
	if(!job_type) {
		printf("immediate_mdt_conf_parseFromJSON() failed [job_type]");
		goto end;
	}
	job_type_local_nonprim = job_type_parseFromJSON(job_type);
	if(!job_type_local_nonprim) {
		printf("job_type_parseFromJSON failed [job_type]");
		goto end;
	}

	measurement_lte_list = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "measurementLteList");
	if(measurement_lte_list) {
		cJSON *measurement_lte_list_local = NULL;
		if(!cJSON_IsArray(measurement_lte_list)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [measurement_lte_list]");
			goto end;
		}

		measurement_lte_listList = list_create();

		cJSON_ArrayForEach(measurement_lte_list_local,
		                   measurement_lte_list) {
			if(!cJSON_IsObject(measurement_lte_list_local)) {
				printf(
					"immediate_mdt_conf_parseFromJSON() failed [measurement_lte_list]");
				goto end;
			}
			measurement_lte_for_mdt_t *measurement_lte_listItem =
				measurement_lte_for_mdt_parseFromJSON(
					measurement_lte_list_local);
			if(!measurement_lte_listItem) {
				printf("No measurement_lte_listItem");
				goto end;
			}
			list_add(measurement_lte_listList,
			         measurement_lte_listItem);
		}
	}

	measurement_nr_list = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "measurementNrList");
	if(measurement_nr_list) {
		cJSON *measurement_nr_list_local = NULL;
		if(!cJSON_IsArray(measurement_nr_list)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [measurement_nr_list]");
			goto end;
		}

		measurement_nr_listList = list_create();

		cJSON_ArrayForEach(measurement_nr_list_local,
		                   measurement_nr_list) {
			if(!cJSON_IsObject(measurement_nr_list_local)) {
				printf(
					"immediate_mdt_conf_parseFromJSON() failed [measurement_nr_list]");
				goto end;
			}
			measurement_nr_for_mdt_t *measurement_nr_listItem =
				measurement_nr_for_mdt_parseFromJSON(
					measurement_nr_list_local);
			if(!measurement_nr_listItem) {
				printf("No measurement_nr_listItem");
				goto end;
			}
			list_add(measurement_nr_listList,
			         measurement_nr_listItem);
		}
	}

	reporting_trigger_list = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "reportingTriggerList");
	if(reporting_trigger_list) {
		cJSON *reporting_trigger_list_local = NULL;
		if(!cJSON_IsArray(reporting_trigger_list)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [reporting_trigger_list]");
			goto end;
		}

		reporting_trigger_listList = list_create();

		cJSON_ArrayForEach(reporting_trigger_list_local,
		                   reporting_trigger_list) {
			if(!cJSON_IsObject(reporting_trigger_list_local)) {
				printf(
					"immediate_mdt_conf_parseFromJSON() failed [reporting_trigger_list]");
				goto end;
			}
			reporting_trigger_t *reporting_trigger_listItem =
				reporting_trigger_parseFromJSON(
					reporting_trigger_list_local);
			if(!reporting_trigger_listItem) {
				printf("No reporting_trigger_listItem");
				goto end;
			}
			list_add(reporting_trigger_listList,
			         reporting_trigger_listItem);
		}
	}

	report_interval = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "reportInterval");
	if(report_interval) {
		report_interval_local_nonprim =
			report_interval_mdt_parseFromJSON(report_interval);
		if(!report_interval_local_nonprim) {
			printf(
				"report_interval_mdt_parseFromJSON failed [report_interval]");
			goto end;
		}
	}

	report_interval_nr = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "reportIntervalNr");
	if(report_interval_nr) {
		report_interval_nr_local_nonprim =
			report_interval_nr_mdt_parseFromJSON(report_interval_nr);
		if(!report_interval_nr_local_nonprim) {
			printf(
				"report_interval_nr_mdt_parseFromJSON failed [report_interval_nr]");
			goto end;
		}
	}

	report_amount = cJSON_GetObjectItemCaseSensitive(immediate_mdt_confJSON,
	                                                 "reportAmount");
	if(report_amount) {
		report_amount_local_nonprim = report_amount_mdt_parseFromJSON(
			report_amount);
		if(!report_amount_local_nonprim) {
			printf(
				"report_amount_mdt_parseFromJSON failed [report_amount]");
			goto end;
		}
	}

	event_threshold_rsrp = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "eventThresholdRsrp");
	if(event_threshold_rsrp) {
		if(!cJSON_IsNumber(event_threshold_rsrp)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [event_threshold_rsrp]");
			goto end;
		}
	}

	event_threshold_rsrq = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "eventThresholdRsrq");
	if(event_threshold_rsrq) {
		if(!cJSON_IsNumber(event_threshold_rsrq)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [event_threshold_rsrq]");
			goto end;
		}
	}

	event_threshold_rsrp_nr = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "eventThresholdRsrpNr");
	if(event_threshold_rsrp_nr) {
		if(!cJSON_IsNumber(event_threshold_rsrp_nr)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [event_threshold_rsrp_nr]");
			goto end;
		}
	}

	event_threshold_rsrq_nr = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "eventThresholdRsrqNr");
	if(event_threshold_rsrq_nr) {
		if(!cJSON_IsNumber(event_threshold_rsrq_nr)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [event_threshold_rsrq_nr]");
			goto end;
		}
	}

	collection_period_rmm_lte = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "collectionPeriodRmmLte");
	if(collection_period_rmm_lte) {
		collection_period_rmm_lte_local_nonprim =
			collection_period_rmm_lte_mdt_parseFromJSON(
				collection_period_rmm_lte);
		if(!collection_period_rmm_lte_local_nonprim) {
			printf(
				"collection_period_rmm_lte_mdt_parseFromJSON failed [collection_period_rmm_lte]");
			goto end;
		}
	}

	collection_period_rmm_nr = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "collectionPeriodRmmNr");
	if(collection_period_rmm_nr) {
		collection_period_rmm_nr_local_nonprim =
			collection_period_rmm_nr_mdt_parseFromJSON(
				collection_period_rmm_nr);
		if(!collection_period_rmm_nr_local_nonprim) {
			printf(
				"collection_period_rmm_nr_mdt_parseFromJSON failed [collection_period_rmm_nr]");
			goto end;
		}
	}

	measurement_period_lte = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "measurementPeriodLte");
	if(measurement_period_lte) {
		measurement_period_lte_local_nonprim =
			measurement_period_lte_mdt_parseFromJSON(
				measurement_period_lte);
		if(!measurement_period_lte_local_nonprim) {
			printf(
				"measurement_period_lte_mdt_parseFromJSON failed [measurement_period_lte]");
			goto end;
		}
	}

	area_scope = cJSON_GetObjectItemCaseSensitive(immediate_mdt_confJSON,
	                                              "areaScope");
	if(area_scope) {
		area_scope_local_nonprim = area_scope_parseFromJSON(area_scope);
		if(!area_scope_local_nonprim) {
			printf("area_scope_parseFromJSON failed [area_scope]");
			goto end;
		}
	}

	positioning_method = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "positioningMethod");
	if(positioning_method) {
		positioning_method_local_nonprim =
			positioning_method_mdt_parseFromJSON(positioning_method);
		if(!positioning_method_local_nonprim) {
			printf(
				"positioning_method_mdt_parseFromJSON failed [positioning_method]");
			goto end;
		}
	}

	add_positioning_method_list = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "addPositioningMethodList");
	if(add_positioning_method_list) {
		cJSON *add_positioning_method_list_local = NULL;
		if(!cJSON_IsArray(add_positioning_method_list)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [add_positioning_method_list]");
			goto end;
		}

		add_positioning_method_listList = list_create();

		cJSON_ArrayForEach(add_positioning_method_list_local,
		                   add_positioning_method_list) {
			if(!cJSON_IsObject(add_positioning_method_list_local)) {
				printf(
					"immediate_mdt_conf_parseFromJSON() failed [add_positioning_method_list]");
				goto end;
			}
			positioning_method_mdt_t *
			        add_positioning_method_listItem =
				positioning_method_mdt_parseFromJSON(
					add_positioning_method_list_local);
			if(!add_positioning_method_listItem) {
				printf("No add_positioning_method_listItem");
				goto end;
			}
			list_add(add_positioning_method_listList,
			         add_positioning_method_listItem);
		}
	}

	mdt_allowed_plmn_id_list = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "mdtAllowedPlmnIdList");
	if(mdt_allowed_plmn_id_list) {
		cJSON *mdt_allowed_plmn_id_list_local = NULL;
		if(!cJSON_IsArray(mdt_allowed_plmn_id_list)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [mdt_allowed_plmn_id_list]");
			goto end;
		}

		mdt_allowed_plmn_id_listList = list_create();

		cJSON_ArrayForEach(mdt_allowed_plmn_id_list_local,
		                   mdt_allowed_plmn_id_list) {
			if(!cJSON_IsObject(mdt_allowed_plmn_id_list_local)) {
				printf(
					"immediate_mdt_conf_parseFromJSON() failed [mdt_allowed_plmn_id_list]");
				goto end;
			}
			plmn_id_t *mdt_allowed_plmn_id_listItem =
				plmn_id_parseFromJSON(
					mdt_allowed_plmn_id_list_local);
			if(!mdt_allowed_plmn_id_listItem) {
				printf("No mdt_allowed_plmn_id_listItem");
				goto end;
			}
			list_add(mdt_allowed_plmn_id_listList,
			         mdt_allowed_plmn_id_listItem);
		}
	}

	sensor_measurement_list = cJSON_GetObjectItemCaseSensitive(
		immediate_mdt_confJSON, "sensorMeasurementList");
	if(sensor_measurement_list) {
		cJSON *sensor_measurement_list_local = NULL;
		if(!cJSON_IsArray(sensor_measurement_list)) {
			printf(
				"immediate_mdt_conf_parseFromJSON() failed [sensor_measurement_list]");
			goto end;
		}

		sensor_measurement_listList = list_create();

		cJSON_ArrayForEach(sensor_measurement_list_local,
		                   sensor_measurement_list) {
			if(!cJSON_IsObject(sensor_measurement_list_local)) {
				printf(
					"immediate_mdt_conf_parseFromJSON() failed [sensor_measurement_list]");
				goto end;
			}
			sensor_measurement_t *sensor_measurement_listItem =
				sensor_measurement_parseFromJSON(
					sensor_measurement_list_local);
			if(!sensor_measurement_listItem) {
				printf("No sensor_measurement_listItem");
				goto end;
			}
			list_add(sensor_measurement_listList,
			         sensor_measurement_listItem);
		}
	}

	immediate_mdt_conf_local_var = immediate_mdt_conf_create(
		job_type_local_nonprim,
		measurement_lte_list ? measurement_lte_listList : NULL,
		measurement_nr_list ? measurement_nr_listList : NULL,
		reporting_trigger_list ? reporting_trigger_listList : NULL,
		report_interval ? report_interval_local_nonprim : NULL,
		report_interval_nr ? report_interval_nr_local_nonprim : NULL,
		report_amount ? report_amount_local_nonprim : NULL,
		event_threshold_rsrp ? true : false,
		event_threshold_rsrp ? event_threshold_rsrp->valuedouble : 0,
		event_threshold_rsrq ? true : false,
		event_threshold_rsrq ? event_threshold_rsrq->valuedouble : 0,
		event_threshold_rsrp_nr ? true : false,
		event_threshold_rsrp_nr ? event_threshold_rsrp_nr->valuedouble : 0,
		event_threshold_rsrq_nr ? true : false,
		event_threshold_rsrq_nr ? event_threshold_rsrq_nr->valuedouble : 0,
		collection_period_rmm_lte ? collection_period_rmm_lte_local_nonprim : NULL,
		collection_period_rmm_nr ? collection_period_rmm_nr_local_nonprim : NULL,
		measurement_period_lte ? measurement_period_lte_local_nonprim : NULL,
		area_scope ? area_scope_local_nonprim : NULL,
		positioning_method ? positioning_method_local_nonprim : NULL,
		add_positioning_method_list ? add_positioning_method_listList : NULL,
		mdt_allowed_plmn_id_list ? mdt_allowed_plmn_id_listList : NULL,
		sensor_measurement_list ? sensor_measurement_listList : NULL
		);

	return immediate_mdt_conf_local_var;
end:
	if(job_type_local_nonprim) {
		job_type_free(job_type_local_nonprim);
		job_type_local_nonprim = NULL;
	}
	if(measurement_lte_listList) {
		list_for_each(measurement_lte_listList, node) {
			measurement_lte_for_mdt_free(node->data);
		}
		list_free(measurement_lte_listList);
		measurement_lte_listList = NULL;
	}
	if(measurement_nr_listList) {
		list_for_each(measurement_nr_listList, node) {
			measurement_nr_for_mdt_free(node->data);
		}
		list_free(measurement_nr_listList);
		measurement_nr_listList = NULL;
	}
	if(reporting_trigger_listList) {
		list_for_each(reporting_trigger_listList, node) {
			reporting_trigger_free(node->data);
		}
		list_free(reporting_trigger_listList);
		reporting_trigger_listList = NULL;
	}
	if(report_interval_local_nonprim) {
		report_interval_mdt_free(report_interval_local_nonprim);
		report_interval_local_nonprim = NULL;
	}
	if(report_interval_nr_local_nonprim) {
		report_interval_nr_mdt_free(report_interval_nr_local_nonprim);
		report_interval_nr_local_nonprim = NULL;
	}
	if(report_amount_local_nonprim) {
		report_amount_mdt_free(report_amount_local_nonprim);
		report_amount_local_nonprim = NULL;
	}
	if(collection_period_rmm_lte_local_nonprim) {
		collection_period_rmm_lte_mdt_free(
			collection_period_rmm_lte_local_nonprim);
		collection_period_rmm_lte_local_nonprim = NULL;
	}
	if(collection_period_rmm_nr_local_nonprim) {
		collection_period_rmm_nr_mdt_free(
			collection_period_rmm_nr_local_nonprim);
		collection_period_rmm_nr_local_nonprim = NULL;
	}
	if(measurement_period_lte_local_nonprim) {
		measurement_period_lte_mdt_free(
			measurement_period_lte_local_nonprim);
		measurement_period_lte_local_nonprim = NULL;
	}
	if(area_scope_local_nonprim) {
		area_scope_free(area_scope_local_nonprim);
		area_scope_local_nonprim = NULL;
	}
	if(positioning_method_local_nonprim) {
		positioning_method_mdt_free(positioning_method_local_nonprim);
		positioning_method_local_nonprim = NULL;
	}
	if(add_positioning_method_listList) {
		list_for_each(add_positioning_method_listList, node) {
			positioning_method_mdt_free(node->data);
		}
		list_free(add_positioning_method_listList);
		add_positioning_method_listList = NULL;
	}
	if(mdt_allowed_plmn_id_listList) {
		list_for_each(mdt_allowed_plmn_id_listList, node) {
			plmn_id_free(node->data);
		}
		list_free(mdt_allowed_plmn_id_listList);
		mdt_allowed_plmn_id_listList = NULL;
	}
	if(sensor_measurement_listList) {
		list_for_each(sensor_measurement_listList, node) {
			sensor_measurement_free(node->data);
		}
		list_free(sensor_measurement_listList);
		sensor_measurement_listList = NULL;
	}
	return NULL;
}

immediate_mdt_conf_t *immediate_mdt_conf_copy(immediate_mdt_conf_t	*dst,
                                              immediate_mdt_conf_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = immediate_mdt_conf_convertToJSON(src);
	if(!item) {
		printf("immediate_mdt_conf_convertToJSON() failed");
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

	immediate_mdt_conf_free(dst);
	dst = immediate_mdt_conf_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
