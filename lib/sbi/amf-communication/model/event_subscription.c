#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_subscription.h"

event_subscription_t *event_subscription_create(bool is_any_slice,
                                                int any_slice, list_t *app_ids,
                                                list_t *deviations,
                                                list_t *dnns, list_t *dnais,
                                                nwdaf_event_t *event,
                                                event_reporting_requirement_t *extra_report_req, list_t *ladn_dnns, bool is_load_level_threshold, int load_level_threshold, notification_method_t *notification_method, matching_direction_t *matching_dir, list_t *nf_load_lvl_thds, list_t *nf_instance_ids, list_t *nf_set_ids, list_t *nf_types, network_area_info_t *network_area, geo_location_t *location, bool is_temporal_gran_size, int temporal_gran_size, bool is_spatial_gran_size_ta, int spatial_gran_size_ta, bool is_spatial_gran_size_cell, int spatial_gran_size_cell, list_t *fine_gran_areas, list_t *visited_areas, bool is_max_top_app_ul_nbr, int max_top_app_ul_nbr, bool is_max_top_app_dl_nbr, int max_top_app_dl_nbr, list_t *nsi_id_infos, list_t *nsi_level_thrds, qos_requirement_t *qos_requ, list_t *qos_flow_ret_thds, list_t *ran_ue_throu_thds, bool is_repetition_period, int repetition_period, list_t *snssaia, target_ue_information_t *tgt_ue, roaming_info_t *roaming_info, list_t *cong_thresholds, list_t *nw_perf_requs, list_t *ue_comm_reqs, list_t *ue_mobility_reqs, user_data_con_order_crit_t *user_data_con_order_cri, list_t *bw_requs, list_t *excep_requs, expected_analytics_type_t *expt_ana_type, expected_ue_behaviour_data_t *expt_ue_behav, list_t *rat_freqs, list_t *list_of_ana_subsets, list_t *disper_reqs, list_t *red_trans_reqs, list_t *wlan_reqs, upf_information_t *upf_info, list_t *app_server_addrs, list_t *dn_perf_reqs, list_t *pdu_ses_infos, char *use_case_cxt, list_t *pdu_ses_traf_reqs, list_t *loc_acc_reqs, loc_info_granularity_t *loc_granularity, location_orientation_t *loc_orientation, list_t *data_vl_trns_tm_rqs, accuracy_req_t *accu_req, bool is_pause_flg, int pause_flg, bool is_resume_flg, int resume_flg, list_t *mov_behav_reqs, list_t *rel_prox_reqs,
                                                analytics_feedback_info_t *feedback)
{
	event_subscription_t *event_subscription_local_var =
		malloc(sizeof(event_subscription_t));

	event_subscription_local_var->is_any_slice = is_any_slice;
	event_subscription_local_var->any_slice = any_slice;
	event_subscription_local_var->app_ids = app_ids;
	event_subscription_local_var->deviations = deviations;
	event_subscription_local_var->dnns = dnns;
	event_subscription_local_var->dnais = dnais;
	event_subscription_local_var->event = event;
	event_subscription_local_var->extra_report_req = extra_report_req;
	event_subscription_local_var->ladn_dnns = ladn_dnns;
	event_subscription_local_var->is_load_level_threshold =
		is_load_level_threshold;
	event_subscription_local_var->load_level_threshold =
		load_level_threshold;
	event_subscription_local_var->notification_method = notification_method;
	event_subscription_local_var->matching_dir = matching_dir;
	event_subscription_local_var->nf_load_lvl_thds = nf_load_lvl_thds;
	event_subscription_local_var->nf_instance_ids = nf_instance_ids;
	event_subscription_local_var->nf_set_ids = nf_set_ids;
	event_subscription_local_var->nf_types = nf_types;
	event_subscription_local_var->network_area = network_area;
	event_subscription_local_var->location = location;
	event_subscription_local_var->is_temporal_gran_size =
		is_temporal_gran_size;
	event_subscription_local_var->temporal_gran_size = temporal_gran_size;
	event_subscription_local_var->is_spatial_gran_size_ta =
		is_spatial_gran_size_ta;
	event_subscription_local_var->spatial_gran_size_ta =
		spatial_gran_size_ta;
	event_subscription_local_var->is_spatial_gran_size_cell =
		is_spatial_gran_size_cell;
	event_subscription_local_var->spatial_gran_size_cell =
		spatial_gran_size_cell;
	event_subscription_local_var->fine_gran_areas = fine_gran_areas;
	event_subscription_local_var->visited_areas = visited_areas;
	event_subscription_local_var->is_max_top_app_ul_nbr =
		is_max_top_app_ul_nbr;
	event_subscription_local_var->max_top_app_ul_nbr = max_top_app_ul_nbr;
	event_subscription_local_var->is_max_top_app_dl_nbr =
		is_max_top_app_dl_nbr;
	event_subscription_local_var->max_top_app_dl_nbr = max_top_app_dl_nbr;
	event_subscription_local_var->nsi_id_infos = nsi_id_infos;
	event_subscription_local_var->nsi_level_thrds = nsi_level_thrds;
	event_subscription_local_var->qos_requ = qos_requ;
	event_subscription_local_var->qos_flow_ret_thds = qos_flow_ret_thds;
	event_subscription_local_var->ran_ue_throu_thds = ran_ue_throu_thds;
	event_subscription_local_var->is_repetition_period =
		is_repetition_period;
	event_subscription_local_var->repetition_period = repetition_period;
	event_subscription_local_var->snssaia = snssaia;
	event_subscription_local_var->tgt_ue = tgt_ue;
	event_subscription_local_var->roaming_info = roaming_info;
	event_subscription_local_var->cong_thresholds = cong_thresholds;
	event_subscription_local_var->nw_perf_requs = nw_perf_requs;
	event_subscription_local_var->ue_comm_reqs = ue_comm_reqs;
	event_subscription_local_var->ue_mobility_reqs = ue_mobility_reqs;
	event_subscription_local_var->user_data_con_order_cri =
		user_data_con_order_cri;
	event_subscription_local_var->bw_requs = bw_requs;
	event_subscription_local_var->excep_requs = excep_requs;
	event_subscription_local_var->expt_ana_type = expt_ana_type;
	event_subscription_local_var->expt_ue_behav = expt_ue_behav;
	event_subscription_local_var->rat_freqs = rat_freqs;
	event_subscription_local_var->list_of_ana_subsets = list_of_ana_subsets;
	event_subscription_local_var->disper_reqs = disper_reqs;
	event_subscription_local_var->red_trans_reqs = red_trans_reqs;
	event_subscription_local_var->wlan_reqs = wlan_reqs;
	event_subscription_local_var->upf_info = upf_info;
	event_subscription_local_var->app_server_addrs = app_server_addrs;
	event_subscription_local_var->dn_perf_reqs = dn_perf_reqs;
	event_subscription_local_var->pdu_ses_infos = pdu_ses_infos;
	event_subscription_local_var->use_case_cxt = use_case_cxt;
	event_subscription_local_var->pdu_ses_traf_reqs = pdu_ses_traf_reqs;
	event_subscription_local_var->loc_acc_reqs = loc_acc_reqs;
	event_subscription_local_var->loc_granularity = loc_granularity;
	event_subscription_local_var->loc_orientation = loc_orientation;
	event_subscription_local_var->data_vl_trns_tm_rqs = data_vl_trns_tm_rqs;
	event_subscription_local_var->accu_req = accu_req;
	event_subscription_local_var->is_pause_flg = is_pause_flg;
	event_subscription_local_var->pause_flg = pause_flg;
	event_subscription_local_var->is_resume_flg = is_resume_flg;
	event_subscription_local_var->resume_flg = resume_flg;
	event_subscription_local_var->mov_behav_reqs = mov_behav_reqs;
	event_subscription_local_var->rel_prox_reqs = rel_prox_reqs;
	event_subscription_local_var->feedback = feedback;

	return event_subscription_local_var;
}

void event_subscription_free(event_subscription_t *event_subscription) {
	lnode_t *node = NULL;

	if(NULL == event_subscription) {
		return;
	}
	if(event_subscription->app_ids) {
		list_for_each(event_subscription->app_ids, node) {
			free(node->data);
		}
		list_free(event_subscription->app_ids);
		event_subscription->app_ids = NULL;
	}
	if(event_subscription->deviations) {
		list_for_each(event_subscription->deviations, node) {
			free(node->data);
		}
		list_free(event_subscription->deviations);
		event_subscription->deviations = NULL;
	}
	if(event_subscription->dnns) {
		list_for_each(event_subscription->dnns, node) {
			free(node->data);
		}
		list_free(event_subscription->dnns);
		event_subscription->dnns = NULL;
	}
	if(event_subscription->dnais) {
		list_for_each(event_subscription->dnais, node) {
			free(node->data);
		}
		list_free(event_subscription->dnais);
		event_subscription->dnais = NULL;
	}
	if(event_subscription->event) {
		nwdaf_event_free(event_subscription->event);
		event_subscription->event = NULL;
	}
	if(event_subscription->extra_report_req) {
		event_reporting_requirement_free(
			event_subscription->extra_report_req);
		event_subscription->extra_report_req = NULL;
	}
	if(event_subscription->ladn_dnns) {
		list_for_each(event_subscription->ladn_dnns, node) {
			free(node->data);
		}
		list_free(event_subscription->ladn_dnns);
		event_subscription->ladn_dnns = NULL;
	}
	if(event_subscription->notification_method) {
		notification_method_free(event_subscription->notification_method);
		event_subscription->notification_method = NULL;
	}
	if(event_subscription->matching_dir) {
		matching_direction_free(event_subscription->matching_dir);
		event_subscription->matching_dir = NULL;
	}
	if(event_subscription->nf_load_lvl_thds) {
		list_for_each(event_subscription->nf_load_lvl_thds, node) {
			threshold_level_free(node->data);
		}
		list_free(event_subscription->nf_load_lvl_thds);
		event_subscription->nf_load_lvl_thds = NULL;
	}
	if(event_subscription->nf_instance_ids) {
		list_for_each(event_subscription->nf_instance_ids, node) {
			free(node->data);
		}
		list_free(event_subscription->nf_instance_ids);
		event_subscription->nf_instance_ids = NULL;
	}
	if(event_subscription->nf_set_ids) {
		list_for_each(event_subscription->nf_set_ids, node) {
			free(node->data);
		}
		list_free(event_subscription->nf_set_ids);
		event_subscription->nf_set_ids = NULL;
	}
	if(event_subscription->nf_types) {
		list_for_each(event_subscription->nf_types, node) {
			nf_type_free(node->data);
		}
		list_free(event_subscription->nf_types);
		event_subscription->nf_types = NULL;
	}
	if(event_subscription->network_area) {
		network_area_info_free(event_subscription->network_area);
		event_subscription->network_area = NULL;
	}
	if(event_subscription->location) {
		geo_location_free(event_subscription->location);
		event_subscription->location = NULL;
	}
	if(event_subscription->fine_gran_areas) {
		list_for_each(event_subscription->fine_gran_areas, node) {
			geographical_area_free(node->data);
		}
		list_free(event_subscription->fine_gran_areas);
		event_subscription->fine_gran_areas = NULL;
	}
	if(event_subscription->visited_areas) {
		list_for_each(event_subscription->visited_areas, node) {
			network_area_info_free(node->data);
		}
		list_free(event_subscription->visited_areas);
		event_subscription->visited_areas = NULL;
	}
	if(event_subscription->nsi_id_infos) {
		list_for_each(event_subscription->nsi_id_infos, node) {
			nsi_id_info_free(node->data);
		}
		list_free(event_subscription->nsi_id_infos);
		event_subscription->nsi_id_infos = NULL;
	}
	if(event_subscription->nsi_level_thrds) {
		list_for_each(event_subscription->nsi_level_thrds, node) {
			free(node->data);
		}
		list_free(event_subscription->nsi_level_thrds);
		event_subscription->nsi_level_thrds = NULL;
	}
	if(event_subscription->qos_requ) {
		qos_requirement_free(event_subscription->qos_requ);
		event_subscription->qos_requ = NULL;
	}
	if(event_subscription->qos_flow_ret_thds) {
		list_for_each(event_subscription->qos_flow_ret_thds, node) {
			retainability_threshold_free(node->data);
		}
		list_free(event_subscription->qos_flow_ret_thds);
		event_subscription->qos_flow_ret_thds = NULL;
	}
	if(event_subscription->ran_ue_throu_thds) {
		list_for_each(event_subscription->ran_ue_throu_thds, node) {
			free(node->data);
		}
		list_free(event_subscription->ran_ue_throu_thds);
		event_subscription->ran_ue_throu_thds = NULL;
	}
	if(event_subscription->snssaia) {
		list_for_each(event_subscription->snssaia, node) {
			snssai_free(node->data);
		}
		list_free(event_subscription->snssaia);
		event_subscription->snssaia = NULL;
	}
	if(event_subscription->tgt_ue) {
		target_ue_information_free(event_subscription->tgt_ue);
		event_subscription->tgt_ue = NULL;
	}
	if(event_subscription->roaming_info) {
		roaming_info_free(event_subscription->roaming_info);
		event_subscription->roaming_info = NULL;
	}
	if(event_subscription->cong_thresholds) {
		list_for_each(event_subscription->cong_thresholds, node) {
			threshold_level_free(node->data);
		}
		list_free(event_subscription->cong_thresholds);
		event_subscription->cong_thresholds = NULL;
	}
	if(event_subscription->nw_perf_requs) {
		list_for_each(event_subscription->nw_perf_requs, node) {
			network_perf_requirement_free(node->data);
		}
		list_free(event_subscription->nw_perf_requs);
		event_subscription->nw_perf_requs = NULL;
	}
	if(event_subscription->ue_comm_reqs) {
		list_for_each(event_subscription->ue_comm_reqs, node) {
			ue_comm_req_free(node->data);
		}
		list_free(event_subscription->ue_comm_reqs);
		event_subscription->ue_comm_reqs = NULL;
	}
	if(event_subscription->ue_mobility_reqs) {
		list_for_each(event_subscription->ue_mobility_reqs, node) {
			ue_mobility_req_free(node->data);
		}
		list_free(event_subscription->ue_mobility_reqs);
		event_subscription->ue_mobility_reqs = NULL;
	}
	if(event_subscription->user_data_con_order_cri) {
		user_data_con_order_crit_free(
			event_subscription->user_data_con_order_cri);
		event_subscription->user_data_con_order_cri = NULL;
	}
	if(event_subscription->bw_requs) {
		list_for_each(event_subscription->bw_requs, node) {
			bw_requirement_free(node->data);
		}
		list_free(event_subscription->bw_requs);
		event_subscription->bw_requs = NULL;
	}
	if(event_subscription->excep_requs) {
		list_for_each(event_subscription->excep_requs, node) {
			exception_free(node->data);
		}
		list_free(event_subscription->excep_requs);
		event_subscription->excep_requs = NULL;
	}
	if(event_subscription->expt_ana_type) {
		expected_analytics_type_free(event_subscription->expt_ana_type);
		event_subscription->expt_ana_type = NULL;
	}
	if(event_subscription->expt_ue_behav) {
		expected_ue_behaviour_data_free(
			event_subscription->expt_ue_behav);
		event_subscription->expt_ue_behav = NULL;
	}
	if(event_subscription->rat_freqs) {
		list_for_each(event_subscription->rat_freqs, node) {
			rat_freq_information_free(node->data);
		}
		list_free(event_subscription->rat_freqs);
		event_subscription->rat_freqs = NULL;
	}
	if(event_subscription->list_of_ana_subsets) {
		list_for_each(event_subscription->list_of_ana_subsets, node) {
			analytics_subset_free(node->data);
		}
		list_free(event_subscription->list_of_ana_subsets);
		event_subscription->list_of_ana_subsets = NULL;
	}
	if(event_subscription->disper_reqs) {
		list_for_each(event_subscription->disper_reqs, node) {
			dispersion_requirement_free(node->data);
		}
		list_free(event_subscription->disper_reqs);
		event_subscription->disper_reqs = NULL;
	}
	if(event_subscription->red_trans_reqs) {
		list_for_each(event_subscription->red_trans_reqs, node) {
			redundant_transmission_exp_req_free(node->data);
		}
		list_free(event_subscription->red_trans_reqs);
		event_subscription->red_trans_reqs = NULL;
	}
	if(event_subscription->wlan_reqs) {
		list_for_each(event_subscription->wlan_reqs, node) {
			wlan_performance_req_free(node->data);
		}
		list_free(event_subscription->wlan_reqs);
		event_subscription->wlan_reqs = NULL;
	}
	if(event_subscription->upf_info) {
		upf_information_free(event_subscription->upf_info);
		event_subscription->upf_info = NULL;
	}
	if(event_subscription->app_server_addrs) {
		list_for_each(event_subscription->app_server_addrs, node) {
			addr_fqdn_free(node->data);
		}
		list_free(event_subscription->app_server_addrs);
		event_subscription->app_server_addrs = NULL;
	}
	if(event_subscription->dn_perf_reqs) {
		list_for_each(event_subscription->dn_perf_reqs, node) {
			dn_performance_req_free(node->data);
		}
		list_free(event_subscription->dn_perf_reqs);
		event_subscription->dn_perf_reqs = NULL;
	}
	if(event_subscription->pdu_ses_infos) {
		list_for_each(event_subscription->pdu_ses_infos, node) {
			pdu_session_info_1_free(node->data);
		}
		list_free(event_subscription->pdu_ses_infos);
		event_subscription->pdu_ses_infos = NULL;
	}
	if(event_subscription->use_case_cxt) {
		free(event_subscription->use_case_cxt);
		event_subscription->use_case_cxt = NULL;
	}
	if(event_subscription->pdu_ses_traf_reqs) {
		list_for_each(event_subscription->pdu_ses_traf_reqs, node) {
			pdu_ses_traffic_req_free(node->data);
		}
		list_free(event_subscription->pdu_ses_traf_reqs);
		event_subscription->pdu_ses_traf_reqs = NULL;
	}
	if(event_subscription->loc_acc_reqs) {
		list_for_each(event_subscription->loc_acc_reqs, node) {
			loc_accuracy_req_free(node->data);
		}
		list_free(event_subscription->loc_acc_reqs);
		event_subscription->loc_acc_reqs = NULL;
	}
	if(event_subscription->loc_granularity) {
		loc_info_granularity_free(event_subscription->loc_granularity);
		event_subscription->loc_granularity = NULL;
	}
	if(event_subscription->loc_orientation) {
		location_orientation_free(event_subscription->loc_orientation);
		event_subscription->loc_orientation = NULL;
	}
	if(event_subscription->data_vl_trns_tm_rqs) {
		list_for_each(event_subscription->data_vl_trns_tm_rqs, node) {
			e2e_data_vol_trans_time_req_free(node->data);
		}
		list_free(event_subscription->data_vl_trns_tm_rqs);
		event_subscription->data_vl_trns_tm_rqs = NULL;
	}
	if(event_subscription->accu_req) {
		accuracy_req_free(event_subscription->accu_req);
		event_subscription->accu_req = NULL;
	}
	if(event_subscription->mov_behav_reqs) {
		list_for_each(event_subscription->mov_behav_reqs, node) {
			mov_behav_req_free(node->data);
		}
		list_free(event_subscription->mov_behav_reqs);
		event_subscription->mov_behav_reqs = NULL;
	}
	if(event_subscription->rel_prox_reqs) {
		list_for_each(event_subscription->rel_prox_reqs, node) {
			rel_prox_req_free(node->data);
		}
		list_free(event_subscription->rel_prox_reqs);
		event_subscription->rel_prox_reqs = NULL;
	}
	if(event_subscription->feedback) {
		analytics_feedback_info_free(event_subscription->feedback);
		event_subscription->feedback = NULL;
	}
	free(event_subscription);
}

cJSON *event_subscription_convertToJSON(
	event_subscription_t *event_subscription) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(event_subscription == NULL) {
		printf(
			"event_subscription_convertToJSON() failed [EventSubscription]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(event_subscription->is_any_slice) {
		if(cJSON_AddBoolToObject(item, "anySlice",
		                         event_subscription->any_slice) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [any_slice]");
			goto end;
		}
	}

	if(event_subscription->app_ids) {
		cJSON *app_idsList = cJSON_AddArrayToObject(item, "appIds");
		if(app_idsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [app_ids]");
			goto end;
		}
		list_for_each(event_subscription->app_ids, node) {
			if(cJSON_AddStringToObject(app_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [app_ids]");
				goto end;
			}
		}
	}

	if(event_subscription->deviations) {
		cJSON *deviationsList = cJSON_AddArrayToObject(item,
		                                               "deviations");
		if(deviationsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [deviations]");
			goto end;
		}
		list_for_each(event_subscription->deviations, node) {
			if(node->data == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [deviations]");
				goto end;
			}
			if(cJSON_AddNumberToObject(deviationsList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [deviations]");
				goto end;
			}
		}
	}

	if(event_subscription->dnns) {
		cJSON *dnnsList = cJSON_AddArrayToObject(item, "dnns");
		if(dnnsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [dnns]");
			goto end;
		}
		list_for_each(event_subscription->dnns, node) {
			if(cJSON_AddStringToObject(dnnsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [dnns]");
				goto end;
			}
		}
	}

	if(event_subscription->dnais) {
		cJSON *dnaisList = cJSON_AddArrayToObject(item, "dnais");
		if(dnaisList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [dnais]");
			goto end;
		}
		list_for_each(event_subscription->dnais, node) {
			if(cJSON_AddStringToObject(dnaisList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [dnais]");
				goto end;
			}
		}
	}

	if(!event_subscription->event) {
		printf("event_subscription_convertToJSON() failed [event]");
		return NULL;
	}
	cJSON *event_local_JSON = nwdaf_event_convertToJSON(
		event_subscription->event);
	if(event_local_JSON == NULL) {
		printf("event_subscription_convertToJSON() failed [event]");
		goto end;
	}
	cJSON_AddItemToObject(item, "event", event_local_JSON);
	if(item->child == NULL) {
		printf("event_subscription_convertToJSON() failed [event]");
		goto end;
	}

	if(event_subscription->extra_report_req) {
		cJSON *extra_report_req_local_JSON =
			event_reporting_requirement_convertToJSON(
				event_subscription->extra_report_req);
		if(extra_report_req_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [extra_report_req]");
			goto end;
		}
		cJSON_AddItemToObject(item, "extraReportReq",
		                      extra_report_req_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [extra_report_req]");
			goto end;
		}
	}

	if(event_subscription->ladn_dnns) {
		cJSON *ladn_dnnsList = cJSON_AddArrayToObject(item, "ladnDnns");
		if(ladn_dnnsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [ladn_dnns]");
			goto end;
		}
		list_for_each(event_subscription->ladn_dnns, node) {
			if(cJSON_AddStringToObject(ladn_dnnsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [ladn_dnns]");
				goto end;
			}
		}
	}

	if(event_subscription->is_load_level_threshold) {
		if(cJSON_AddNumberToObject(item, "loadLevelThreshold",
		                           event_subscription->
		                           load_level_threshold) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [load_level_threshold]");
			goto end;
		}
	}

	if(event_subscription->notification_method) {
		cJSON *notification_method_local_JSON =
			notification_method_convertToJSON(
				event_subscription->notification_method);
		if(notification_method_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [notification_method]");
			goto end;
		}
		cJSON_AddItemToObject(item, "notificationMethod",
		                      notification_method_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [notification_method]");
			goto end;
		}
	}

	if(event_subscription->matching_dir) {
		cJSON *matching_dir_local_JSON =
			matching_direction_convertToJSON(
				event_subscription->matching_dir);
		if(matching_dir_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [matching_dir]");
			goto end;
		}
		cJSON_AddItemToObject(item, "matchingDir",
		                      matching_dir_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [matching_dir]");
			goto end;
		}
	}

	if(event_subscription->nf_load_lvl_thds) {
		cJSON *nf_load_lvl_thdsList = cJSON_AddArrayToObject(item,
		                                                     "nfLoadLvlThds");
		if(nf_load_lvl_thdsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [nf_load_lvl_thds]");
			goto end;
		}
		list_for_each(event_subscription->nf_load_lvl_thds, node) {
			cJSON *itemLocal = threshold_level_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [nf_load_lvl_thds]");
				goto end;
			}
			cJSON_AddItemToArray(nf_load_lvl_thdsList, itemLocal);
		}
	}

	if(event_subscription->nf_instance_ids) {
		cJSON *nf_instance_idsList = cJSON_AddArrayToObject(item,
		                                                    "nfInstanceIds");
		if(nf_instance_idsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [nf_instance_ids]");
			goto end;
		}
		list_for_each(event_subscription->nf_instance_ids, node) {
			if(cJSON_AddStringToObject(nf_instance_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [nf_instance_ids]");
				goto end;
			}
		}
	}

	if(event_subscription->nf_set_ids) {
		cJSON *nf_set_idsList =
			cJSON_AddArrayToObject(item, "nfSetIds");
		if(nf_set_idsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [nf_set_ids]");
			goto end;
		}
		list_for_each(event_subscription->nf_set_ids, node) {
			if(cJSON_AddStringToObject(nf_set_idsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [nf_set_ids]");
				goto end;
			}
		}
	}

	if(event_subscription->nf_types) {
		cJSON *nf_typesList = cJSON_AddArrayToObject(item, "nfTypes");
		if(nf_typesList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [nf_types]");
			goto end;
		}
		list_for_each(event_subscription->nf_types, node) {
			cJSON *itemLocal = nf_type_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [nf_types]");
				goto end;
			}
			cJSON_AddItemToArray(nf_typesList, itemLocal);
		}
	}

	if(event_subscription->network_area) {
		cJSON *network_area_local_JSON =
			network_area_info_convertToJSON(
				event_subscription->network_area);
		if(network_area_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [network_area]");
			goto end;
		}
		cJSON_AddItemToObject(item, "networkArea",
		                      network_area_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [network_area]");
			goto end;
		}
	}

	if(event_subscription->location) {
		cJSON *location_local_JSON = geo_location_convertToJSON(
			event_subscription->location);
		if(location_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [location]");
			goto end;
		}
		cJSON_AddItemToObject(item, "location", location_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [location]");
			goto end;
		}
	}

	if(event_subscription->is_temporal_gran_size) {
		if(cJSON_AddNumberToObject(item, "temporalGranSize",
		                           event_subscription->
		                           temporal_gran_size) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [temporal_gran_size]");
			goto end;
		}
	}

	if(event_subscription->is_spatial_gran_size_ta) {
		if(cJSON_AddNumberToObject(item, "spatialGranSizeTa",
		                           event_subscription->
		                           spatial_gran_size_ta) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [spatial_gran_size_ta]");
			goto end;
		}
	}

	if(event_subscription->is_spatial_gran_size_cell) {
		if(cJSON_AddNumberToObject(item, "spatialGranSizeCell",
		                           event_subscription->
		                           spatial_gran_size_cell) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [spatial_gran_size_cell]");
			goto end;
		}
	}

	if(event_subscription->fine_gran_areas) {
		cJSON *fine_gran_areasList = cJSON_AddArrayToObject(item,
		                                                    "fineGranAreas");
		if(fine_gran_areasList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [fine_gran_areas]");
			goto end;
		}
		list_for_each(event_subscription->fine_gran_areas, node) {
			cJSON *itemLocal = geographical_area_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [fine_gran_areas]");
				goto end;
			}
			cJSON_AddItemToArray(fine_gran_areasList, itemLocal);
		}
	}

	if(event_subscription->visited_areas) {
		cJSON *visited_areasList = cJSON_AddArrayToObject(item,
		                                                  "visitedAreas");
		if(visited_areasList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [visited_areas]");
			goto end;
		}
		list_for_each(event_subscription->visited_areas, node) {
			cJSON *itemLocal = network_area_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [visited_areas]");
				goto end;
			}
			cJSON_AddItemToArray(visited_areasList, itemLocal);
		}
	}

	if(event_subscription->is_max_top_app_ul_nbr) {
		if(cJSON_AddNumberToObject(item, "maxTopAppUlNbr",
		                           event_subscription->
		                           max_top_app_ul_nbr) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [max_top_app_ul_nbr]");
			goto end;
		}
	}

	if(event_subscription->is_max_top_app_dl_nbr) {
		if(cJSON_AddNumberToObject(item, "maxTopAppDlNbr",
		                           event_subscription->
		                           max_top_app_dl_nbr) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [max_top_app_dl_nbr]");
			goto end;
		}
	}

	if(event_subscription->nsi_id_infos) {
		cJSON *nsi_id_infosList = cJSON_AddArrayToObject(item,
		                                                 "nsiIdInfos");
		if(nsi_id_infosList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [nsi_id_infos]");
			goto end;
		}
		list_for_each(event_subscription->nsi_id_infos, node) {
			cJSON *itemLocal =
				nsi_id_info_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [nsi_id_infos]");
				goto end;
			}
			cJSON_AddItemToArray(nsi_id_infosList, itemLocal);
		}
	}

	if(event_subscription->nsi_level_thrds) {
		cJSON *nsi_level_thrdsList = cJSON_AddArrayToObject(item,
		                                                    "nsiLevelThrds");
		if(nsi_level_thrdsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [nsi_level_thrds]");
			goto end;
		}
		list_for_each(event_subscription->nsi_level_thrds, node) {
			if(node->data == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [nsi_level_thrds]");
				goto end;
			}
			if(cJSON_AddNumberToObject(nsi_level_thrdsList, "",
			                           *(double *) node->data) ==
			   NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [nsi_level_thrds]");
				goto end;
			}
		}
	}

	if(event_subscription->qos_requ) {
		cJSON *qos_requ_local_JSON = qos_requirement_convertToJSON(
			event_subscription->qos_requ);
		if(qos_requ_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [qos_requ]");
			goto end;
		}
		cJSON_AddItemToObject(item, "qosRequ", qos_requ_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [qos_requ]");
			goto end;
		}
	}

	if(event_subscription->qos_flow_ret_thds) {
		cJSON *qos_flow_ret_thdsList = cJSON_AddArrayToObject(item,
		                                                      "qosFlowRetThds");
		if(qos_flow_ret_thdsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [qos_flow_ret_thds]");
			goto end;
		}
		list_for_each(event_subscription->qos_flow_ret_thds, node) {
			cJSON *itemLocal =
				retainability_threshold_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [qos_flow_ret_thds]");
				goto end;
			}
			cJSON_AddItemToArray(qos_flow_ret_thdsList, itemLocal);
		}
	}

	if(event_subscription->ran_ue_throu_thds) {
		cJSON *ran_ue_throu_thdsList = cJSON_AddArrayToObject(item,
		                                                      "ranUeThrouThds");
		if(ran_ue_throu_thdsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [ran_ue_throu_thds]");
			goto end;
		}
		list_for_each(event_subscription->ran_ue_throu_thds, node) {
			if(cJSON_AddStringToObject(ran_ue_throu_thdsList, "",
			                           (char *) node->data) == NULL)
			{
				printf(
					"event_subscription_convertToJSON() failed [ran_ue_throu_thds]");
				goto end;
			}
		}
	}

	if(event_subscription->is_repetition_period) {
		if(cJSON_AddNumberToObject(item, "repetitionPeriod",
		                           event_subscription->repetition_period)
		   == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [repetition_period]");
			goto end;
		}
	}

	if(event_subscription->snssaia) {
		cJSON *snssaiaList = cJSON_AddArrayToObject(item, "snssaia");
		if(snssaiaList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [snssaia]");
			goto end;
		}
		list_for_each(event_subscription->snssaia, node) {
			cJSON *itemLocal = snssai_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [snssaia]");
				goto end;
			}
			cJSON_AddItemToArray(snssaiaList, itemLocal);
		}
	}

	if(event_subscription->tgt_ue) {
		cJSON *tgt_ue_local_JSON = target_ue_information_convertToJSON(
			event_subscription->tgt_ue);
		if(tgt_ue_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [tgt_ue]");
			goto end;
		}
		cJSON_AddItemToObject(item, "tgtUe", tgt_ue_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [tgt_ue]");
			goto end;
		}
	}

	if(event_subscription->roaming_info) {
		cJSON *roaming_info_local_JSON = roaming_info_convertToJSON(
			event_subscription->roaming_info);
		if(roaming_info_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [roaming_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "roamingInfo",
		                      roaming_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [roaming_info]");
			goto end;
		}
	}

	if(event_subscription->cong_thresholds) {
		cJSON *cong_thresholdsList = cJSON_AddArrayToObject(item,
		                                                    "congThresholds");
		if(cong_thresholdsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [cong_thresholds]");
			goto end;
		}
		list_for_each(event_subscription->cong_thresholds, node) {
			cJSON *itemLocal = threshold_level_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [cong_thresholds]");
				goto end;
			}
			cJSON_AddItemToArray(cong_thresholdsList, itemLocal);
		}
	}

	if(event_subscription->nw_perf_requs) {
		cJSON *nw_perf_requsList = cJSON_AddArrayToObject(item,
		                                                  "nwPerfRequs");
		if(nw_perf_requsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [nw_perf_requs]");
			goto end;
		}
		list_for_each(event_subscription->nw_perf_requs, node) {
			cJSON *itemLocal =
				network_perf_requirement_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [nw_perf_requs]");
				goto end;
			}
			cJSON_AddItemToArray(nw_perf_requsList, itemLocal);
		}
	}

	if(event_subscription->ue_comm_reqs) {
		cJSON *ue_comm_reqsList = cJSON_AddArrayToObject(item,
		                                                 "ueCommReqs");
		if(ue_comm_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [ue_comm_reqs]");
			goto end;
		}
		list_for_each(event_subscription->ue_comm_reqs, node) {
			cJSON *itemLocal =
				ue_comm_req_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [ue_comm_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(ue_comm_reqsList, itemLocal);
		}
	}

	if(event_subscription->ue_mobility_reqs) {
		cJSON *ue_mobility_reqsList = cJSON_AddArrayToObject(item,
		                                                     "ueMobilityReqs");
		if(ue_mobility_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [ue_mobility_reqs]");
			goto end;
		}
		list_for_each(event_subscription->ue_mobility_reqs, node) {
			cJSON *itemLocal = ue_mobility_req_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [ue_mobility_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(ue_mobility_reqsList, itemLocal);
		}
	}

	if(event_subscription->user_data_con_order_cri) {
		cJSON *user_data_con_order_cri_local_JSON =
			user_data_con_order_crit_convertToJSON(
				event_subscription->user_data_con_order_cri);
		if(user_data_con_order_cri_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [user_data_con_order_cri]");
			goto end;
		}
		cJSON_AddItemToObject(item, "userDataConOrderCri",
		                      user_data_con_order_cri_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [user_data_con_order_cri]");
			goto end;
		}
	}

	if(event_subscription->bw_requs) {
		cJSON *bw_requsList = cJSON_AddArrayToObject(item, "bwRequs");
		if(bw_requsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [bw_requs]");
			goto end;
		}
		list_for_each(event_subscription->bw_requs, node) {
			cJSON *itemLocal = bw_requirement_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [bw_requs]");
				goto end;
			}
			cJSON_AddItemToArray(bw_requsList, itemLocal);
		}
	}

	if(event_subscription->excep_requs) {
		cJSON *excep_requsList = cJSON_AddArrayToObject(item,
		                                                "excepRequs");
		if(excep_requsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [excep_requs]");
			goto end;
		}
		list_for_each(event_subscription->excep_requs, node) {
			cJSON *itemLocal = exception_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [excep_requs]");
				goto end;
			}
			cJSON_AddItemToArray(excep_requsList, itemLocal);
		}
	}

	if(event_subscription->expt_ana_type) {
		cJSON *expt_ana_type_local_JSON =
			expected_analytics_type_convertToJSON(
				event_subscription->expt_ana_type);
		if(expt_ana_type_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [expt_ana_type]");
			goto end;
		}
		cJSON_AddItemToObject(item, "exptAnaType",
		                      expt_ana_type_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [expt_ana_type]");
			goto end;
		}
	}

	if(event_subscription->expt_ue_behav) {
		cJSON *expt_ue_behav_local_JSON =
			expected_ue_behaviour_data_convertToJSON(
				event_subscription->expt_ue_behav);
		if(expt_ue_behav_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [expt_ue_behav]");
			goto end;
		}
		cJSON_AddItemToObject(item, "exptUeBehav",
		                      expt_ue_behav_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [expt_ue_behav]");
			goto end;
		}
	}

	if(event_subscription->rat_freqs) {
		cJSON *rat_freqsList = cJSON_AddArrayToObject(item, "ratFreqs");
		if(rat_freqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [rat_freqs]");
			goto end;
		}
		list_for_each(event_subscription->rat_freqs, node) {
			cJSON *itemLocal = rat_freq_information_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [rat_freqs]");
				goto end;
			}
			cJSON_AddItemToArray(rat_freqsList, itemLocal);
		}
	}

	if(event_subscription->list_of_ana_subsets) {
		cJSON *list_of_ana_subsetsList = cJSON_AddArrayToObject(item,
		                                                        "listOfAnaSubsets");
		if(list_of_ana_subsetsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [list_of_ana_subsets]");
			goto end;
		}
		list_for_each(event_subscription->list_of_ana_subsets, node) {
			cJSON *itemLocal = analytics_subset_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [list_of_ana_subsets]");
				goto end;
			}
			cJSON_AddItemToArray(list_of_ana_subsetsList,
			                     itemLocal);
		}
	}

	if(event_subscription->disper_reqs) {
		cJSON *disper_reqsList = cJSON_AddArrayToObject(item,
		                                                "disperReqs");
		if(disper_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [disper_reqs]");
			goto end;
		}
		list_for_each(event_subscription->disper_reqs, node) {
			cJSON *itemLocal = dispersion_requirement_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [disper_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(disper_reqsList, itemLocal);
		}
	}

	if(event_subscription->red_trans_reqs) {
		cJSON *red_trans_reqsList = cJSON_AddArrayToObject(item,
		                                                   "redTransReqs");
		if(red_trans_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [red_trans_reqs]");
			goto end;
		}
		list_for_each(event_subscription->red_trans_reqs, node) {
			cJSON *itemLocal =
				redundant_transmission_exp_req_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [red_trans_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(red_trans_reqsList, itemLocal);
		}
	}

	if(event_subscription->wlan_reqs) {
		cJSON *wlan_reqsList = cJSON_AddArrayToObject(item, "wlanReqs");
		if(wlan_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [wlan_reqs]");
			goto end;
		}
		list_for_each(event_subscription->wlan_reqs, node) {
			cJSON *itemLocal = wlan_performance_req_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [wlan_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(wlan_reqsList, itemLocal);
		}
	}

	if(event_subscription->upf_info) {
		cJSON *upf_info_local_JSON = upf_information_convertToJSON(
			event_subscription->upf_info);
		if(upf_info_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [upf_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "upfInfo", upf_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [upf_info]");
			goto end;
		}
	}

	if(event_subscription->app_server_addrs) {
		cJSON *app_server_addrsList = cJSON_AddArrayToObject(item,
		                                                     "appServerAddrs");
		if(app_server_addrsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [app_server_addrs]");
			goto end;
		}
		list_for_each(event_subscription->app_server_addrs, node) {
			cJSON *itemLocal = addr_fqdn_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [app_server_addrs]");
				goto end;
			}
			cJSON_AddItemToArray(app_server_addrsList, itemLocal);
		}
	}

	if(event_subscription->dn_perf_reqs) {
		cJSON *dn_perf_reqsList = cJSON_AddArrayToObject(item,
		                                                 "dnPerfReqs");
		if(dn_perf_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [dn_perf_reqs]");
			goto end;
		}
		list_for_each(event_subscription->dn_perf_reqs, node) {
			cJSON *itemLocal = dn_performance_req_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [dn_perf_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(dn_perf_reqsList, itemLocal);
		}
	}

	if(event_subscription->pdu_ses_infos) {
		cJSON *pdu_ses_infosList = cJSON_AddArrayToObject(item,
		                                                  "pduSesInfos");
		if(pdu_ses_infosList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [pdu_ses_infos]");
			goto end;
		}
		list_for_each(event_subscription->pdu_ses_infos, node) {
			cJSON *itemLocal = pdu_session_info_1_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [pdu_ses_infos]");
				goto end;
			}
			cJSON_AddItemToArray(pdu_ses_infosList, itemLocal);
		}
	}

	if(event_subscription->use_case_cxt) {
		if(cJSON_AddStringToObject(item, "useCaseCxt",
		                           event_subscription->use_case_cxt) ==
		   NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [use_case_cxt]");
			goto end;
		}
	}

	if(event_subscription->pdu_ses_traf_reqs) {
		cJSON *pdu_ses_traf_reqsList = cJSON_AddArrayToObject(item,
		                                                      "pduSesTrafReqs");
		if(pdu_ses_traf_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [pdu_ses_traf_reqs]");
			goto end;
		}
		list_for_each(event_subscription->pdu_ses_traf_reqs, node) {
			cJSON *itemLocal = pdu_ses_traffic_req_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [pdu_ses_traf_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(pdu_ses_traf_reqsList, itemLocal);
		}
	}

	if(event_subscription->loc_acc_reqs) {
		cJSON *loc_acc_reqsList = cJSON_AddArrayToObject(item,
		                                                 "locAccReqs");
		if(loc_acc_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [loc_acc_reqs]");
			goto end;
		}
		list_for_each(event_subscription->loc_acc_reqs, node) {
			cJSON *itemLocal = loc_accuracy_req_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [loc_acc_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(loc_acc_reqsList, itemLocal);
		}
	}

	if(event_subscription->loc_granularity) {
		cJSON *loc_granularity_local_JSON =
			loc_info_granularity_convertToJSON(
				event_subscription->loc_granularity);
		if(loc_granularity_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [loc_granularity]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locGranularity",
		                      loc_granularity_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [loc_granularity]");
			goto end;
		}
	}

	if(event_subscription->loc_orientation) {
		cJSON *loc_orientation_local_JSON =
			location_orientation_convertToJSON(
				event_subscription->loc_orientation);
		if(loc_orientation_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [loc_orientation]");
			goto end;
		}
		cJSON_AddItemToObject(item, "locOrientation",
		                      loc_orientation_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [loc_orientation]");
			goto end;
		}
	}

	if(event_subscription->data_vl_trns_tm_rqs) {
		cJSON *data_vl_trns_tm_rqsList = cJSON_AddArrayToObject(item,
		                                                        "dataVlTrnsTmRqs");
		if(data_vl_trns_tm_rqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [data_vl_trns_tm_rqs]");
			goto end;
		}
		list_for_each(event_subscription->data_vl_trns_tm_rqs, node) {
			cJSON *itemLocal =
				e2e_data_vol_trans_time_req_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [data_vl_trns_tm_rqs]");
				goto end;
			}
			cJSON_AddItemToArray(data_vl_trns_tm_rqsList,
			                     itemLocal);
		}
	}

	if(event_subscription->accu_req) {
		cJSON *accu_req_local_JSON = accuracy_req_convertToJSON(
			event_subscription->accu_req);
		if(accu_req_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [accu_req]");
			goto end;
		}
		cJSON_AddItemToObject(item, "accuReq", accu_req_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [accu_req]");
			goto end;
		}
	}

	if(event_subscription->is_pause_flg) {
		if(cJSON_AddBoolToObject(item, "pauseFlg",
		                         event_subscription->pause_flg) == NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [pause_flg]");
			goto end;
		}
	}

	if(event_subscription->is_resume_flg) {
		if(cJSON_AddBoolToObject(item, "resumeFlg",
		                         event_subscription->resume_flg) ==
		   NULL)
		{
			printf(
				"event_subscription_convertToJSON() failed [resume_flg]");
			goto end;
		}
	}

	if(event_subscription->mov_behav_reqs) {
		cJSON *mov_behav_reqsList = cJSON_AddArrayToObject(item,
		                                                   "movBehavReqs");
		if(mov_behav_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [mov_behav_reqs]");
			goto end;
		}
		list_for_each(event_subscription->mov_behav_reqs, node) {
			cJSON *itemLocal = mov_behav_req_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [mov_behav_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(mov_behav_reqsList, itemLocal);
		}
	}

	if(event_subscription->rel_prox_reqs) {
		cJSON *rel_prox_reqsList = cJSON_AddArrayToObject(item,
		                                                  "relProxReqs");
		if(rel_prox_reqsList == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [rel_prox_reqs]");
			goto end;
		}
		list_for_each(event_subscription->rel_prox_reqs, node) {
			cJSON *itemLocal =
				rel_prox_req_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_subscription_convertToJSON() failed [rel_prox_reqs]");
				goto end;
			}
			cJSON_AddItemToArray(rel_prox_reqsList, itemLocal);
		}
	}

	if(event_subscription->feedback) {
		cJSON *feedback_local_JSON =
			analytics_feedback_info_convertToJSON(
				event_subscription->feedback);
		if(feedback_local_JSON == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [feedback]");
			goto end;
		}
		cJSON_AddItemToObject(item, "feedback", feedback_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_subscription_convertToJSON() failed [feedback]");
			goto end;
		}
	}

end:
	return item;
}

event_subscription_t *event_subscription_parseFromJSON(
	cJSON *event_subscriptionJSON) {
	event_subscription_t *event_subscription_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *any_slice = NULL;
	cJSON *app_ids = NULL;
	list_t *app_idsList = NULL;
	cJSON *deviations = NULL;
	list_t *deviationsList = NULL;
	cJSON *dnns = NULL;
	list_t *dnnsList = NULL;
	cJSON *dnais = NULL;
	list_t *dnaisList = NULL;
	cJSON *event = NULL;
	nwdaf_event_t *event_local_nonprim = NULL;
	cJSON *extra_report_req = NULL;
	event_reporting_requirement_t *extra_report_req_local_nonprim = NULL;
	cJSON *ladn_dnns = NULL;
	list_t *ladn_dnnsList = NULL;
	cJSON *load_level_threshold = NULL;
	cJSON *notification_method = NULL;
	notification_method_t *notification_method_local_nonprim = NULL;
	cJSON *matching_dir = NULL;
	matching_direction_t *matching_dir_local_nonprim = NULL;
	cJSON *nf_load_lvl_thds = NULL;
	list_t *nf_load_lvl_thdsList = NULL;
	cJSON *nf_instance_ids = NULL;
	list_t *nf_instance_idsList = NULL;
	cJSON *nf_set_ids = NULL;
	list_t *nf_set_idsList = NULL;
	cJSON *nf_types = NULL;
	list_t *nf_typesList = NULL;
	cJSON *network_area = NULL;
	network_area_info_t *network_area_local_nonprim = NULL;
	cJSON *location = NULL;
	geo_location_t *location_local_nonprim = NULL;
	cJSON *temporal_gran_size = NULL;
	cJSON *spatial_gran_size_ta = NULL;
	cJSON *spatial_gran_size_cell = NULL;
	cJSON *fine_gran_areas = NULL;
	list_t *fine_gran_areasList = NULL;
	cJSON *visited_areas = NULL;
	list_t *visited_areasList = NULL;
	cJSON *max_top_app_ul_nbr = NULL;
	cJSON *max_top_app_dl_nbr = NULL;
	cJSON *nsi_id_infos = NULL;
	list_t *nsi_id_infosList = NULL;
	cJSON *nsi_level_thrds = NULL;
	list_t *nsi_level_thrdsList = NULL;
	cJSON *qos_requ = NULL;
	qos_requirement_t *qos_requ_local_nonprim = NULL;
	cJSON *qos_flow_ret_thds = NULL;
	list_t *qos_flow_ret_thdsList = NULL;
	cJSON *ran_ue_throu_thds = NULL;
	list_t *ran_ue_throu_thdsList = NULL;
	cJSON *repetition_period = NULL;
	cJSON *snssaia = NULL;
	list_t *snssaiaList = NULL;
	cJSON *tgt_ue = NULL;
	target_ue_information_t *tgt_ue_local_nonprim = NULL;
	cJSON *roaming_info = NULL;
	roaming_info_t *roaming_info_local_nonprim = NULL;
	cJSON *cong_thresholds = NULL;
	list_t *cong_thresholdsList = NULL;
	cJSON *nw_perf_requs = NULL;
	list_t *nw_perf_requsList = NULL;
	cJSON *ue_comm_reqs = NULL;
	list_t *ue_comm_reqsList = NULL;
	cJSON *ue_mobility_reqs = NULL;
	list_t *ue_mobility_reqsList = NULL;
	cJSON *user_data_con_order_cri = NULL;
	user_data_con_order_crit_t *user_data_con_order_cri_local_nonprim =
		NULL;
	cJSON *bw_requs = NULL;
	list_t *bw_requsList = NULL;
	cJSON *excep_requs = NULL;
	list_t *excep_requsList = NULL;
	cJSON *expt_ana_type = NULL;
	expected_analytics_type_t *expt_ana_type_local_nonprim = NULL;
	cJSON *expt_ue_behav = NULL;
	expected_ue_behaviour_data_t *expt_ue_behav_local_nonprim = NULL;
	cJSON *rat_freqs = NULL;
	list_t *rat_freqsList = NULL;
	cJSON *list_of_ana_subsets = NULL;
	list_t *list_of_ana_subsetsList = NULL;
	cJSON *disper_reqs = NULL;
	list_t *disper_reqsList = NULL;
	cJSON *red_trans_reqs = NULL;
	list_t *red_trans_reqsList = NULL;
	cJSON *wlan_reqs = NULL;
	list_t *wlan_reqsList = NULL;
	cJSON *upf_info = NULL;
	upf_information_t *upf_info_local_nonprim = NULL;
	cJSON *app_server_addrs = NULL;
	list_t *app_server_addrsList = NULL;
	cJSON *dn_perf_reqs = NULL;
	list_t *dn_perf_reqsList = NULL;
	cJSON *pdu_ses_infos = NULL;
	list_t *pdu_ses_infosList = NULL;
	cJSON *use_case_cxt = NULL;
	cJSON *pdu_ses_traf_reqs = NULL;
	list_t *pdu_ses_traf_reqsList = NULL;
	cJSON *loc_acc_reqs = NULL;
	list_t *loc_acc_reqsList = NULL;
	cJSON *loc_granularity = NULL;
	loc_info_granularity_t *loc_granularity_local_nonprim = NULL;
	cJSON *loc_orientation = NULL;
	location_orientation_t *loc_orientation_local_nonprim = NULL;
	cJSON *data_vl_trns_tm_rqs = NULL;
	list_t *data_vl_trns_tm_rqsList = NULL;
	cJSON *accu_req = NULL;
	accuracy_req_t *accu_req_local_nonprim = NULL;
	cJSON *pause_flg = NULL;
	cJSON *resume_flg = NULL;
	cJSON *mov_behav_reqs = NULL;
	list_t *mov_behav_reqsList = NULL;
	cJSON *rel_prox_reqs = NULL;
	list_t *rel_prox_reqsList = NULL;
	cJSON *feedback = NULL;
	analytics_feedback_info_t *feedback_local_nonprim = NULL;
	any_slice = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                             "anySlice");
	if(any_slice) {
		if(!cJSON_IsBool(any_slice)) {
			printf(
				"event_subscription_parseFromJSON() failed [any_slice]");
			goto end;
		}
	}

	app_ids = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                           "appIds");
	if(app_ids) {
		cJSON *app_ids_local = NULL;
		if(!cJSON_IsArray(app_ids)) {
			printf(
				"event_subscription_parseFromJSON() failed [app_ids]");
			goto end;
		}

		app_idsList = list_create();

		cJSON_ArrayForEach(app_ids_local, app_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(app_ids_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [app_ids]");
				goto end;
			}
			list_add(app_idsList,
			         strdup(app_ids_local->valuestring));
		}
	}

	deviations = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                              "deviations");
	if(deviations) {
		cJSON *deviations_local = NULL;
		if(!cJSON_IsArray(deviations)) {
			printf(
				"event_subscription_parseFromJSON() failed [deviations]");
			goto end;
		}

		deviationsList = list_create();

		cJSON_ArrayForEach(deviations_local, deviations) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(deviations_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [deviations]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"event_subscription_parseFromJSON() failed [deviations]");
				goto end;
			}
			*localDouble = deviations_local->valuedouble;
			list_add(deviationsList, localDouble);
		}
	}

	dnns = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON, "dnns");
	if(dnns) {
		cJSON *dnns_local = NULL;
		if(!cJSON_IsArray(dnns)) {
			printf(
				"event_subscription_parseFromJSON() failed [dnns]");
			goto end;
		}

		dnnsList = list_create();

		cJSON_ArrayForEach(dnns_local, dnns) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(dnns_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [dnns]");
				goto end;
			}
			list_add(dnnsList, strdup(dnns_local->valuestring));
		}
	}

	dnais =
		cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
		                                 "dnais");
	if(dnais) {
		cJSON *dnais_local = NULL;
		if(!cJSON_IsArray(dnais)) {
			printf(
				"event_subscription_parseFromJSON() failed [dnais]");
			goto end;
		}

		dnaisList = list_create();

		cJSON_ArrayForEach(dnais_local, dnais) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(dnais_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [dnais]");
				goto end;
			}
			list_add(dnaisList, strdup(dnais_local->valuestring));
		}
	}

	event =
		cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
		                                 "event");
	if(!event) {
		printf("event_subscription_parseFromJSON() failed [event]");
		goto end;
	}
	event_local_nonprim = nwdaf_event_parseFromJSON(event);
	if(!event_local_nonprim) {
		printf("nwdaf_event_parseFromJSON failed [event]");
		goto end;
	}

	extra_report_req = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "extraReportReq");
	if(extra_report_req) {
		extra_report_req_local_nonprim =
			event_reporting_requirement_parseFromJSON(
				extra_report_req);
		if(!extra_report_req_local_nonprim) {
			printf(
				"event_reporting_requirement_parseFromJSON failed [extra_report_req]");
			goto end;
		}
	}

	ladn_dnns = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                             "ladnDnns");
	if(ladn_dnns) {
		cJSON *ladn_dnns_local = NULL;
		if(!cJSON_IsArray(ladn_dnns)) {
			printf(
				"event_subscription_parseFromJSON() failed [ladn_dnns]");
			goto end;
		}

		ladn_dnnsList = list_create();

		cJSON_ArrayForEach(ladn_dnns_local, ladn_dnns) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(ladn_dnns_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [ladn_dnns]");
				goto end;
			}
			list_add(ladn_dnnsList,
			         strdup(ladn_dnns_local->valuestring));
		}
	}

	load_level_threshold = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "loadLevelThreshold");
	if(load_level_threshold) {
		if(!cJSON_IsNumber(load_level_threshold)) {
			printf(
				"event_subscription_parseFromJSON() failed [load_level_threshold]");
			goto end;
		}
	}

	notification_method = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "notificationMethod");
	if(notification_method) {
		notification_method_local_nonprim =
			notification_method_parseFromJSON(notification_method);
		if(!notification_method_local_nonprim) {
			printf(
				"notification_method_parseFromJSON failed [notification_method]");
			goto end;
		}
	}

	matching_dir = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "matchingDir");
	if(matching_dir) {
		matching_dir_local_nonprim = matching_direction_parseFromJSON(
			matching_dir);
		if(!matching_dir_local_nonprim) {
			printf(
				"matching_direction_parseFromJSON failed [matching_dir]");
			goto end;
		}
	}

	nf_load_lvl_thds = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "nfLoadLvlThds");
	if(nf_load_lvl_thds) {
		cJSON *nf_load_lvl_thds_local = NULL;
		if(!cJSON_IsArray(nf_load_lvl_thds)) {
			printf(
				"event_subscription_parseFromJSON() failed [nf_load_lvl_thds]");
			goto end;
		}

		nf_load_lvl_thdsList = list_create();

		cJSON_ArrayForEach(nf_load_lvl_thds_local, nf_load_lvl_thds) {
			if(!cJSON_IsObject(nf_load_lvl_thds_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [nf_load_lvl_thds]");
				goto end;
			}
			threshold_level_t *nf_load_lvl_thdsItem =
				threshold_level_parseFromJSON(
					nf_load_lvl_thds_local);
			if(!nf_load_lvl_thdsItem) {
				printf("No nf_load_lvl_thdsItem");
				goto end;
			}
			list_add(nf_load_lvl_thdsList, nf_load_lvl_thdsItem);
		}
	}

	nf_instance_ids = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "nfInstanceIds");
	if(nf_instance_ids) {
		cJSON *nf_instance_ids_local = NULL;
		if(!cJSON_IsArray(nf_instance_ids)) {
			printf(
				"event_subscription_parseFromJSON() failed [nf_instance_ids]");
			goto end;
		}

		nf_instance_idsList = list_create();

		cJSON_ArrayForEach(nf_instance_ids_local, nf_instance_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(nf_instance_ids_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [nf_instance_ids]");
				goto end;
			}
			list_add(nf_instance_idsList,
			         strdup(nf_instance_ids_local->valuestring));
		}
	}

	nf_set_ids = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                              "nfSetIds");
	if(nf_set_ids) {
		cJSON *nf_set_ids_local = NULL;
		if(!cJSON_IsArray(nf_set_ids)) {
			printf(
				"event_subscription_parseFromJSON() failed [nf_set_ids]");
			goto end;
		}

		nf_set_idsList = list_create();

		cJSON_ArrayForEach(nf_set_ids_local, nf_set_ids) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(nf_set_ids_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [nf_set_ids]");
				goto end;
			}
			list_add(nf_set_idsList,
			         strdup(nf_set_ids_local->valuestring));
		}
	}

	nf_types = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                            "nfTypes");
	if(nf_types) {
		cJSON *nf_types_local = NULL;
		if(!cJSON_IsArray(nf_types)) {
			printf(
				"event_subscription_parseFromJSON() failed [nf_types]");
			goto end;
		}

		nf_typesList = list_create();

		cJSON_ArrayForEach(nf_types_local, nf_types) {
			if(!cJSON_IsObject(nf_types_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [nf_types]");
				goto end;
			}
			nf_type_t *nf_typesItem = nf_type_parseFromJSON(
				nf_types_local);
			if(!nf_typesItem) {
				printf("No nf_typesItem");
				goto end;
			}
			list_add(nf_typesList, nf_typesItem);
		}
	}

	network_area = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "networkArea");
	if(network_area) {
		network_area_local_nonprim = network_area_info_parseFromJSON(
			network_area);
		if(!network_area_local_nonprim) {
			printf(
				"network_area_info_parseFromJSON failed [network_area]");
			goto end;
		}
	}

	location = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                            "location");
	if(location) {
		location_local_nonprim = geo_location_parseFromJSON(location);
		if(!location_local_nonprim) {
			printf("geo_location_parseFromJSON failed [location]");
			goto end;
		}
	}

	temporal_gran_size = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "temporalGranSize");
	if(temporal_gran_size) {
		if(!cJSON_IsNumber(temporal_gran_size)) {
			printf(
				"event_subscription_parseFromJSON() failed [temporal_gran_size]");
			goto end;
		}
	}

	spatial_gran_size_ta = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "spatialGranSizeTa");
	if(spatial_gran_size_ta) {
		if(!cJSON_IsNumber(spatial_gran_size_ta)) {
			printf(
				"event_subscription_parseFromJSON() failed [spatial_gran_size_ta]");
			goto end;
		}
	}

	spatial_gran_size_cell = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "spatialGranSizeCell");
	if(spatial_gran_size_cell) {
		if(!cJSON_IsNumber(spatial_gran_size_cell)) {
			printf(
				"event_subscription_parseFromJSON() failed [spatial_gran_size_cell]");
			goto end;
		}
	}

	fine_gran_areas = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "fineGranAreas");
	if(fine_gran_areas) {
		cJSON *fine_gran_areas_local = NULL;
		if(!cJSON_IsArray(fine_gran_areas)) {
			printf(
				"event_subscription_parseFromJSON() failed [fine_gran_areas]");
			goto end;
		}

		fine_gran_areasList = list_create();

		cJSON_ArrayForEach(fine_gran_areas_local, fine_gran_areas) {
			if(!cJSON_IsObject(fine_gran_areas_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [fine_gran_areas]");
				goto end;
			}
			geographical_area_t *fine_gran_areasItem =
				geographical_area_parseFromJSON(
					fine_gran_areas_local);
			if(!fine_gran_areasItem) {
				printf("No fine_gran_areasItem");
				goto end;
			}
			list_add(fine_gran_areasList, fine_gran_areasItem);
		}
	}

	visited_areas = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                 "visitedAreas");
	if(visited_areas) {
		cJSON *visited_areas_local = NULL;
		if(!cJSON_IsArray(visited_areas)) {
			printf(
				"event_subscription_parseFromJSON() failed [visited_areas]");
			goto end;
		}

		visited_areasList = list_create();

		cJSON_ArrayForEach(visited_areas_local, visited_areas) {
			if(!cJSON_IsObject(visited_areas_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [visited_areas]");
				goto end;
			}
			network_area_info_t *visited_areasItem =
				network_area_info_parseFromJSON(
					visited_areas_local);
			if(!visited_areasItem) {
				printf("No visited_areasItem");
				goto end;
			}
			list_add(visited_areasList, visited_areasItem);
		}
	}

	max_top_app_ul_nbr = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "maxTopAppUlNbr");
	if(max_top_app_ul_nbr) {
		if(!cJSON_IsNumber(max_top_app_ul_nbr)) {
			printf(
				"event_subscription_parseFromJSON() failed [max_top_app_ul_nbr]");
			goto end;
		}
	}

	max_top_app_dl_nbr = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "maxTopAppDlNbr");
	if(max_top_app_dl_nbr) {
		if(!cJSON_IsNumber(max_top_app_dl_nbr)) {
			printf(
				"event_subscription_parseFromJSON() failed [max_top_app_dl_nbr]");
			goto end;
		}
	}

	nsi_id_infos = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "nsiIdInfos");
	if(nsi_id_infos) {
		cJSON *nsi_id_infos_local = NULL;
		if(!cJSON_IsArray(nsi_id_infos)) {
			printf(
				"event_subscription_parseFromJSON() failed [nsi_id_infos]");
			goto end;
		}

		nsi_id_infosList = list_create();

		cJSON_ArrayForEach(nsi_id_infos_local, nsi_id_infos) {
			if(!cJSON_IsObject(nsi_id_infos_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [nsi_id_infos]");
				goto end;
			}
			nsi_id_info_t *nsi_id_infosItem =
				nsi_id_info_parseFromJSON(nsi_id_infos_local);
			if(!nsi_id_infosItem) {
				printf("No nsi_id_infosItem");
				goto end;
			}
			list_add(nsi_id_infosList, nsi_id_infosItem);
		}
	}

	nsi_level_thrds = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "nsiLevelThrds");
	if(nsi_level_thrds) {
		cJSON *nsi_level_thrds_local = NULL;
		if(!cJSON_IsArray(nsi_level_thrds)) {
			printf(
				"event_subscription_parseFromJSON() failed [nsi_level_thrds]");
			goto end;
		}

		nsi_level_thrdsList = list_create();

		cJSON_ArrayForEach(nsi_level_thrds_local, nsi_level_thrds) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsNumber(nsi_level_thrds_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [nsi_level_thrds]");
				goto end;
			}
			localDouble = (double *) calloc(1, sizeof(double));
			if(!localDouble) {
				printf(
					"event_subscription_parseFromJSON() failed [nsi_level_thrds]");
				goto end;
			}
			*localDouble = nsi_level_thrds_local->valuedouble;
			list_add(nsi_level_thrdsList, localDouble);
		}
	}

	qos_requ = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                            "qosRequ");
	if(qos_requ) {
		qos_requ_local_nonprim =
			qos_requirement_parseFromJSON(qos_requ);
		if(!qos_requ_local_nonprim) {
			printf("qos_requirement_parseFromJSON failed [qos_requ]");
			goto end;
		}
	}

	qos_flow_ret_thds = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "qosFlowRetThds");
	if(qos_flow_ret_thds) {
		cJSON *qos_flow_ret_thds_local = NULL;
		if(!cJSON_IsArray(qos_flow_ret_thds)) {
			printf(
				"event_subscription_parseFromJSON() failed [qos_flow_ret_thds]");
			goto end;
		}

		qos_flow_ret_thdsList = list_create();

		cJSON_ArrayForEach(qos_flow_ret_thds_local, qos_flow_ret_thds) {
			if(!cJSON_IsObject(qos_flow_ret_thds_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [qos_flow_ret_thds]");
				goto end;
			}
			retainability_threshold_t *qos_flow_ret_thdsItem =
				retainability_threshold_parseFromJSON(
					qos_flow_ret_thds_local);
			if(!qos_flow_ret_thdsItem) {
				printf("No qos_flow_ret_thdsItem");
				goto end;
			}
			list_add(qos_flow_ret_thdsList, qos_flow_ret_thdsItem);
		}
	}

	ran_ue_throu_thds = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "ranUeThrouThds");
	if(ran_ue_throu_thds) {
		cJSON *ran_ue_throu_thds_local = NULL;
		if(!cJSON_IsArray(ran_ue_throu_thds)) {
			printf(
				"event_subscription_parseFromJSON() failed [ran_ue_throu_thds]");
			goto end;
		}

		ran_ue_throu_thdsList = list_create();

		cJSON_ArrayForEach(ran_ue_throu_thds_local, ran_ue_throu_thds) {
			double *localDouble = NULL;
			int *localInt = NULL;
			if(!cJSON_IsString(ran_ue_throu_thds_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [ran_ue_throu_thds]");
				goto end;
			}
			list_add(ran_ue_throu_thdsList,
			         strdup(ran_ue_throu_thds_local->valuestring));
		}
	}

	repetition_period = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "repetitionPeriod");
	if(repetition_period) {
		if(!cJSON_IsNumber(repetition_period)) {
			printf(
				"event_subscription_parseFromJSON() failed [repetition_period]");
			goto end;
		}
	}

	snssaia = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                           "snssaia");
	if(snssaia) {
		cJSON *snssaia_local = NULL;
		if(!cJSON_IsArray(snssaia)) {
			printf(
				"event_subscription_parseFromJSON() failed [snssaia]");
			goto end;
		}

		snssaiaList = list_create();

		cJSON_ArrayForEach(snssaia_local, snssaia) {
			if(!cJSON_IsObject(snssaia_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [snssaia]");
				goto end;
			}
			snssai_t *snssaiaItem = snssai_parseFromJSON(
				snssaia_local);
			if(!snssaiaItem) {
				printf("No snssaiaItem");
				goto end;
			}
			list_add(snssaiaList, snssaiaItem);
		}
	}

	tgt_ue = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                          "tgtUe");
	if(tgt_ue) {
		tgt_ue_local_nonprim = target_ue_information_parseFromJSON(
			tgt_ue);
		if(!tgt_ue_local_nonprim) {
			printf(
				"target_ue_information_parseFromJSON failed [tgt_ue]");
			goto end;
		}
	}

	roaming_info = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "roamingInfo");
	if(roaming_info) {
		roaming_info_local_nonprim = roaming_info_parseFromJSON(
			roaming_info);
		if(!roaming_info_local_nonprim) {
			printf(
				"roaming_info_parseFromJSON failed [roaming_info]");
			goto end;
		}
	}

	cong_thresholds = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "congThresholds");
	if(cong_thresholds) {
		cJSON *cong_thresholds_local = NULL;
		if(!cJSON_IsArray(cong_thresholds)) {
			printf(
				"event_subscription_parseFromJSON() failed [cong_thresholds]");
			goto end;
		}

		cong_thresholdsList = list_create();

		cJSON_ArrayForEach(cong_thresholds_local, cong_thresholds) {
			if(!cJSON_IsObject(cong_thresholds_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [cong_thresholds]");
				goto end;
			}
			threshold_level_t *cong_thresholdsItem =
				threshold_level_parseFromJSON(
					cong_thresholds_local);
			if(!cong_thresholdsItem) {
				printf("No cong_thresholdsItem");
				goto end;
			}
			list_add(cong_thresholdsList, cong_thresholdsItem);
		}
	}

	nw_perf_requs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                 "nwPerfRequs");
	if(nw_perf_requs) {
		cJSON *nw_perf_requs_local = NULL;
		if(!cJSON_IsArray(nw_perf_requs)) {
			printf(
				"event_subscription_parseFromJSON() failed [nw_perf_requs]");
			goto end;
		}

		nw_perf_requsList = list_create();

		cJSON_ArrayForEach(nw_perf_requs_local, nw_perf_requs) {
			if(!cJSON_IsObject(nw_perf_requs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [nw_perf_requs]");
				goto end;
			}
			network_perf_requirement_t *nw_perf_requsItem =
				network_perf_requirement_parseFromJSON(
					nw_perf_requs_local);
			if(!nw_perf_requsItem) {
				printf("No nw_perf_requsItem");
				goto end;
			}
			list_add(nw_perf_requsList, nw_perf_requsItem);
		}
	}

	ue_comm_reqs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "ueCommReqs");
	if(ue_comm_reqs) {
		cJSON *ue_comm_reqs_local = NULL;
		if(!cJSON_IsArray(ue_comm_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [ue_comm_reqs]");
			goto end;
		}

		ue_comm_reqsList = list_create();

		cJSON_ArrayForEach(ue_comm_reqs_local, ue_comm_reqs) {
			if(!cJSON_IsObject(ue_comm_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [ue_comm_reqs]");
				goto end;
			}
			ue_comm_req_t *ue_comm_reqsItem =
				ue_comm_req_parseFromJSON(ue_comm_reqs_local);
			if(!ue_comm_reqsItem) {
				printf("No ue_comm_reqsItem");
				goto end;
			}
			list_add(ue_comm_reqsList, ue_comm_reqsItem);
		}
	}

	ue_mobility_reqs = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "ueMobilityReqs");
	if(ue_mobility_reqs) {
		cJSON *ue_mobility_reqs_local = NULL;
		if(!cJSON_IsArray(ue_mobility_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [ue_mobility_reqs]");
			goto end;
		}

		ue_mobility_reqsList = list_create();

		cJSON_ArrayForEach(ue_mobility_reqs_local, ue_mobility_reqs) {
			if(!cJSON_IsObject(ue_mobility_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [ue_mobility_reqs]");
				goto end;
			}
			ue_mobility_req_t *ue_mobility_reqsItem =
				ue_mobility_req_parseFromJSON(
					ue_mobility_reqs_local);
			if(!ue_mobility_reqsItem) {
				printf("No ue_mobility_reqsItem");
				goto end;
			}
			list_add(ue_mobility_reqsList, ue_mobility_reqsItem);
		}
	}

	user_data_con_order_cri = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "userDataConOrderCri");
	if(user_data_con_order_cri) {
		user_data_con_order_cri_local_nonprim =
			user_data_con_order_crit_parseFromJSON(
				user_data_con_order_cri);
		if(!user_data_con_order_cri_local_nonprim) {
			printf(
				"user_data_con_order_crit_parseFromJSON failed [user_data_con_order_cri]");
			goto end;
		}
	}

	bw_requs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                            "bwRequs");
	if(bw_requs) {
		cJSON *bw_requs_local = NULL;
		if(!cJSON_IsArray(bw_requs)) {
			printf(
				"event_subscription_parseFromJSON() failed [bw_requs]");
			goto end;
		}

		bw_requsList = list_create();

		cJSON_ArrayForEach(bw_requs_local, bw_requs) {
			if(!cJSON_IsObject(bw_requs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [bw_requs]");
				goto end;
			}
			bw_requirement_t *bw_requsItem =
				bw_requirement_parseFromJSON(bw_requs_local);
			if(!bw_requsItem) {
				printf("No bw_requsItem");
				goto end;
			}
			list_add(bw_requsList, bw_requsItem);
		}
	}

	excep_requs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                               "excepRequs");
	if(excep_requs) {
		cJSON *excep_requs_local = NULL;
		if(!cJSON_IsArray(excep_requs)) {
			printf(
				"event_subscription_parseFromJSON() failed [excep_requs]");
			goto end;
		}

		excep_requsList = list_create();

		cJSON_ArrayForEach(excep_requs_local, excep_requs) {
			if(!cJSON_IsObject(excep_requs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [excep_requs]");
				goto end;
			}
			exception_t *excep_requsItem = exception_parseFromJSON(
				excep_requs_local);
			if(!excep_requsItem) {
				printf("No excep_requsItem");
				goto end;
			}
			list_add(excep_requsList, excep_requsItem);
		}
	}

	expt_ana_type = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                 "exptAnaType");
	if(expt_ana_type) {
		expt_ana_type_local_nonprim =
			expected_analytics_type_parseFromJSON(expt_ana_type);
		if(!expt_ana_type_local_nonprim) {
			printf(
				"expected_analytics_type_parseFromJSON failed [expt_ana_type]");
			goto end;
		}
	}

	expt_ue_behav = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                 "exptUeBehav");
	if(expt_ue_behav) {
		expt_ue_behav_local_nonprim =
			expected_ue_behaviour_data_parseFromJSON(expt_ue_behav);
		if(!expt_ue_behav_local_nonprim) {
			printf(
				"expected_ue_behaviour_data_parseFromJSON failed [expt_ue_behav]");
			goto end;
		}
	}

	rat_freqs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                             "ratFreqs");
	if(rat_freqs) {
		cJSON *rat_freqs_local = NULL;
		if(!cJSON_IsArray(rat_freqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [rat_freqs]");
			goto end;
		}

		rat_freqsList = list_create();

		cJSON_ArrayForEach(rat_freqs_local, rat_freqs) {
			if(!cJSON_IsObject(rat_freqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [rat_freqs]");
				goto end;
			}
			rat_freq_information_t *rat_freqsItem =
				rat_freq_information_parseFromJSON(
					rat_freqs_local);
			if(!rat_freqsItem) {
				printf("No rat_freqsItem");
				goto end;
			}
			list_add(rat_freqsList, rat_freqsItem);
		}
	}

	list_of_ana_subsets = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "listOfAnaSubsets");
	if(list_of_ana_subsets) {
		cJSON *list_of_ana_subsets_local = NULL;
		if(!cJSON_IsArray(list_of_ana_subsets)) {
			printf(
				"event_subscription_parseFromJSON() failed [list_of_ana_subsets]");
			goto end;
		}

		list_of_ana_subsetsList = list_create();

		cJSON_ArrayForEach(list_of_ana_subsets_local,
		                   list_of_ana_subsets) {
			if(!cJSON_IsObject(list_of_ana_subsets_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [list_of_ana_subsets]");
				goto end;
			}
			analytics_subset_t *list_of_ana_subsetsItem =
				analytics_subset_parseFromJSON(
					list_of_ana_subsets_local);
			if(!list_of_ana_subsetsItem) {
				printf("No list_of_ana_subsetsItem");
				goto end;
			}
			list_add(list_of_ana_subsetsList,
			         list_of_ana_subsetsItem);
		}
	}

	disper_reqs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                               "disperReqs");
	if(disper_reqs) {
		cJSON *disper_reqs_local = NULL;
		if(!cJSON_IsArray(disper_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [disper_reqs]");
			goto end;
		}

		disper_reqsList = list_create();

		cJSON_ArrayForEach(disper_reqs_local, disper_reqs) {
			if(!cJSON_IsObject(disper_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [disper_reqs]");
				goto end;
			}
			dispersion_requirement_t *disper_reqsItem =
				dispersion_requirement_parseFromJSON(
					disper_reqs_local);
			if(!disper_reqsItem) {
				printf("No disper_reqsItem");
				goto end;
			}
			list_add(disper_reqsList, disper_reqsItem);
		}
	}

	red_trans_reqs = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "redTransReqs");
	if(red_trans_reqs) {
		cJSON *red_trans_reqs_local = NULL;
		if(!cJSON_IsArray(red_trans_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [red_trans_reqs]");
			goto end;
		}

		red_trans_reqsList = list_create();

		cJSON_ArrayForEach(red_trans_reqs_local, red_trans_reqs) {
			if(!cJSON_IsObject(red_trans_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [red_trans_reqs]");
				goto end;
			}
			redundant_transmission_exp_req_t *red_trans_reqsItem =
				redundant_transmission_exp_req_parseFromJSON(
					red_trans_reqs_local);
			if(!red_trans_reqsItem) {
				printf("No red_trans_reqsItem");
				goto end;
			}
			list_add(red_trans_reqsList, red_trans_reqsItem);
		}
	}

	wlan_reqs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                             "wlanReqs");
	if(wlan_reqs) {
		cJSON *wlan_reqs_local = NULL;
		if(!cJSON_IsArray(wlan_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [wlan_reqs]");
			goto end;
		}

		wlan_reqsList = list_create();

		cJSON_ArrayForEach(wlan_reqs_local, wlan_reqs) {
			if(!cJSON_IsObject(wlan_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [wlan_reqs]");
				goto end;
			}
			wlan_performance_req_t *wlan_reqsItem =
				wlan_performance_req_parseFromJSON(
					wlan_reqs_local);
			if(!wlan_reqsItem) {
				printf("No wlan_reqsItem");
				goto end;
			}
			list_add(wlan_reqsList, wlan_reqsItem);
		}
	}

	upf_info = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                            "upfInfo");
	if(upf_info) {
		upf_info_local_nonprim =
			upf_information_parseFromJSON(upf_info);
		if(!upf_info_local_nonprim) {
			printf("upf_information_parseFromJSON failed [upf_info]");
			goto end;
		}
	}

	app_server_addrs = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "appServerAddrs");
	if(app_server_addrs) {
		cJSON *app_server_addrs_local = NULL;
		if(!cJSON_IsArray(app_server_addrs)) {
			printf(
				"event_subscription_parseFromJSON() failed [app_server_addrs]");
			goto end;
		}

		app_server_addrsList = list_create();

		cJSON_ArrayForEach(app_server_addrs_local, app_server_addrs) {
			if(!cJSON_IsObject(app_server_addrs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [app_server_addrs]");
				goto end;
			}
			addr_fqdn_t *app_server_addrsItem =
				addr_fqdn_parseFromJSON(app_server_addrs_local);
			if(!app_server_addrsItem) {
				printf("No app_server_addrsItem");
				goto end;
			}
			list_add(app_server_addrsList, app_server_addrsItem);
		}
	}

	dn_perf_reqs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "dnPerfReqs");
	if(dn_perf_reqs) {
		cJSON *dn_perf_reqs_local = NULL;
		if(!cJSON_IsArray(dn_perf_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [dn_perf_reqs]");
			goto end;
		}

		dn_perf_reqsList = list_create();

		cJSON_ArrayForEach(dn_perf_reqs_local, dn_perf_reqs) {
			if(!cJSON_IsObject(dn_perf_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [dn_perf_reqs]");
				goto end;
			}
			dn_performance_req_t *dn_perf_reqsItem =
				dn_performance_req_parseFromJSON(
					dn_perf_reqs_local);
			if(!dn_perf_reqsItem) {
				printf("No dn_perf_reqsItem");
				goto end;
			}
			list_add(dn_perf_reqsList, dn_perf_reqsItem);
		}
	}

	pdu_ses_infos = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                 "pduSesInfos");
	if(pdu_ses_infos) {
		cJSON *pdu_ses_infos_local = NULL;
		if(!cJSON_IsArray(pdu_ses_infos)) {
			printf(
				"event_subscription_parseFromJSON() failed [pdu_ses_infos]");
			goto end;
		}

		pdu_ses_infosList = list_create();

		cJSON_ArrayForEach(pdu_ses_infos_local, pdu_ses_infos) {
			if(!cJSON_IsObject(pdu_ses_infos_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [pdu_ses_infos]");
				goto end;
			}
			pdu_session_info_1_t *pdu_ses_infosItem =
				pdu_session_info_1_parseFromJSON(
					pdu_ses_infos_local);
			if(!pdu_ses_infosItem) {
				printf("No pdu_ses_infosItem");
				goto end;
			}
			list_add(pdu_ses_infosList, pdu_ses_infosItem);
		}
	}

	use_case_cxt = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "useCaseCxt");
	if(use_case_cxt) {
		if(!cJSON_IsString(use_case_cxt) &&
		   !cJSON_IsNull(use_case_cxt))
		{
			printf(
				"event_subscription_parseFromJSON() failed [use_case_cxt]");
			goto end;
		}
	}

	pdu_ses_traf_reqs = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "pduSesTrafReqs");
	if(pdu_ses_traf_reqs) {
		cJSON *pdu_ses_traf_reqs_local = NULL;
		if(!cJSON_IsArray(pdu_ses_traf_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [pdu_ses_traf_reqs]");
			goto end;
		}

		pdu_ses_traf_reqsList = list_create();

		cJSON_ArrayForEach(pdu_ses_traf_reqs_local, pdu_ses_traf_reqs) {
			if(!cJSON_IsObject(pdu_ses_traf_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [pdu_ses_traf_reqs]");
				goto end;
			}
			pdu_ses_traffic_req_t *pdu_ses_traf_reqsItem =
				pdu_ses_traffic_req_parseFromJSON(
					pdu_ses_traf_reqs_local);
			if(!pdu_ses_traf_reqsItem) {
				printf("No pdu_ses_traf_reqsItem");
				goto end;
			}
			list_add(pdu_ses_traf_reqsList, pdu_ses_traf_reqsItem);
		}
	}

	loc_acc_reqs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                "locAccReqs");
	if(loc_acc_reqs) {
		cJSON *loc_acc_reqs_local = NULL;
		if(!cJSON_IsArray(loc_acc_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [loc_acc_reqs]");
			goto end;
		}

		loc_acc_reqsList = list_create();

		cJSON_ArrayForEach(loc_acc_reqs_local, loc_acc_reqs) {
			if(!cJSON_IsObject(loc_acc_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [loc_acc_reqs]");
				goto end;
			}
			loc_accuracy_req_t *loc_acc_reqsItem =
				loc_accuracy_req_parseFromJSON(
					loc_acc_reqs_local);
			if(!loc_acc_reqsItem) {
				printf("No loc_acc_reqsItem");
				goto end;
			}
			list_add(loc_acc_reqsList, loc_acc_reqsItem);
		}
	}

	loc_granularity = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "locGranularity");
	if(loc_granularity) {
		loc_granularity_local_nonprim =
			loc_info_granularity_parseFromJSON(loc_granularity);
		if(!loc_granularity_local_nonprim) {
			printf(
				"loc_info_granularity_parseFromJSON failed [loc_granularity]");
			goto end;
		}
	}

	loc_orientation = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "locOrientation");
	if(loc_orientation) {
		loc_orientation_local_nonprim =
			location_orientation_parseFromJSON(loc_orientation);
		if(!loc_orientation_local_nonprim) {
			printf(
				"location_orientation_parseFromJSON failed [loc_orientation]");
			goto end;
		}
	}

	data_vl_trns_tm_rqs = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "dataVlTrnsTmRqs");
	if(data_vl_trns_tm_rqs) {
		cJSON *data_vl_trns_tm_rqs_local = NULL;
		if(!cJSON_IsArray(data_vl_trns_tm_rqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [data_vl_trns_tm_rqs]");
			goto end;
		}

		data_vl_trns_tm_rqsList = list_create();

		cJSON_ArrayForEach(data_vl_trns_tm_rqs_local,
		                   data_vl_trns_tm_rqs) {
			if(!cJSON_IsObject(data_vl_trns_tm_rqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [data_vl_trns_tm_rqs]");
				goto end;
			}
			e2e_data_vol_trans_time_req_t *data_vl_trns_tm_rqsItem =
				e2e_data_vol_trans_time_req_parseFromJSON(
					data_vl_trns_tm_rqs_local);
			if(!data_vl_trns_tm_rqsItem) {
				printf("No data_vl_trns_tm_rqsItem");
				goto end;
			}
			list_add(data_vl_trns_tm_rqsList,
			         data_vl_trns_tm_rqsItem);
		}
	}

	accu_req = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                            "accuReq");
	if(accu_req) {
		accu_req_local_nonprim = accuracy_req_parseFromJSON(accu_req);
		if(!accu_req_local_nonprim) {
			printf("accuracy_req_parseFromJSON failed [accu_req]");
			goto end;
		}
	}

	pause_flg = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                             "pauseFlg");
	if(pause_flg) {
		if(!cJSON_IsBool(pause_flg)) {
			printf(
				"event_subscription_parseFromJSON() failed [pause_flg]");
			goto end;
		}
	}

	resume_flg = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                              "resumeFlg");
	if(resume_flg) {
		if(!cJSON_IsBool(resume_flg)) {
			printf(
				"event_subscription_parseFromJSON() failed [resume_flg]");
			goto end;
		}
	}

	mov_behav_reqs = cJSON_GetObjectItemCaseSensitive(
		event_subscriptionJSON, "movBehavReqs");
	if(mov_behav_reqs) {
		cJSON *mov_behav_reqs_local = NULL;
		if(!cJSON_IsArray(mov_behav_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [mov_behav_reqs]");
			goto end;
		}

		mov_behav_reqsList = list_create();

		cJSON_ArrayForEach(mov_behav_reqs_local, mov_behav_reqs) {
			if(!cJSON_IsObject(mov_behav_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [mov_behav_reqs]");
				goto end;
			}
			mov_behav_req_t *mov_behav_reqsItem =
				mov_behav_req_parseFromJSON(mov_behav_reqs_local);
			if(!mov_behav_reqsItem) {
				printf("No mov_behav_reqsItem");
				goto end;
			}
			list_add(mov_behav_reqsList, mov_behav_reqsItem);
		}
	}

	rel_prox_reqs = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                                 "relProxReqs");
	if(rel_prox_reqs) {
		cJSON *rel_prox_reqs_local = NULL;
		if(!cJSON_IsArray(rel_prox_reqs)) {
			printf(
				"event_subscription_parseFromJSON() failed [rel_prox_reqs]");
			goto end;
		}

		rel_prox_reqsList = list_create();

		cJSON_ArrayForEach(rel_prox_reqs_local, rel_prox_reqs) {
			if(!cJSON_IsObject(rel_prox_reqs_local)) {
				printf(
					"event_subscription_parseFromJSON() failed [rel_prox_reqs]");
				goto end;
			}
			rel_prox_req_t *rel_prox_reqsItem =
				rel_prox_req_parseFromJSON(rel_prox_reqs_local);
			if(!rel_prox_reqsItem) {
				printf("No rel_prox_reqsItem");
				goto end;
			}
			list_add(rel_prox_reqsList, rel_prox_reqsItem);
		}
	}

	feedback = cJSON_GetObjectItemCaseSensitive(event_subscriptionJSON,
	                                            "feedback");
	if(feedback) {
		feedback_local_nonprim = analytics_feedback_info_parseFromJSON(
			feedback);
		if(!feedback_local_nonprim) {
			printf(
				"analytics_feedback_info_parseFromJSON failed [feedback]");
			goto end;
		}
	}

	event_subscription_local_var = event_subscription_create(
		any_slice ? true : false,
		any_slice ? any_slice->valueint : 0,
		app_ids ? app_idsList : NULL,
		deviations ? deviationsList : NULL,
		dnns ? dnnsList : NULL,
		dnais ? dnaisList : NULL,
		event_local_nonprim,
		extra_report_req ? extra_report_req_local_nonprim : NULL,
		ladn_dnns ? ladn_dnnsList : NULL,
		load_level_threshold ? true : false,
		load_level_threshold ? load_level_threshold->valuedouble : 0,
		notification_method ? notification_method_local_nonprim : NULL,
		matching_dir ? matching_dir_local_nonprim : NULL,
		nf_load_lvl_thds ? nf_load_lvl_thdsList : NULL,
		nf_instance_ids ? nf_instance_idsList : NULL,
		nf_set_ids ? nf_set_idsList : NULL,
		nf_types ? nf_typesList : NULL,
		network_area ? network_area_local_nonprim : NULL,
		location ? location_local_nonprim : NULL,
		temporal_gran_size ? true : false,
		temporal_gran_size ? temporal_gran_size->valuedouble : 0,
		spatial_gran_size_ta ? true : false,
		spatial_gran_size_ta ? spatial_gran_size_ta->valuedouble : 0,
		spatial_gran_size_cell ? true : false,
		spatial_gran_size_cell ? spatial_gran_size_cell->valuedouble : 0,
		fine_gran_areas ? fine_gran_areasList : NULL,
		visited_areas ? visited_areasList : NULL,
		max_top_app_ul_nbr ? true : false,
		max_top_app_ul_nbr ? max_top_app_ul_nbr->valuedouble : 0,
		max_top_app_dl_nbr ? true : false,
		max_top_app_dl_nbr ? max_top_app_dl_nbr->valuedouble : 0,
		nsi_id_infos ? nsi_id_infosList : NULL,
		nsi_level_thrds ? nsi_level_thrdsList : NULL,
		qos_requ ? qos_requ_local_nonprim : NULL,
		qos_flow_ret_thds ? qos_flow_ret_thdsList : NULL,
		ran_ue_throu_thds ? ran_ue_throu_thdsList : NULL,
		repetition_period ? true : false,
		repetition_period ? repetition_period->valuedouble : 0,
		snssaia ? snssaiaList : NULL,
		tgt_ue ? tgt_ue_local_nonprim : NULL,
		roaming_info ? roaming_info_local_nonprim : NULL,
		cong_thresholds ? cong_thresholdsList : NULL,
		nw_perf_requs ? nw_perf_requsList : NULL,
		ue_comm_reqs ? ue_comm_reqsList : NULL,
		ue_mobility_reqs ? ue_mobility_reqsList : NULL,
		user_data_con_order_cri ? user_data_con_order_cri_local_nonprim : NULL,
		bw_requs ? bw_requsList : NULL,
		excep_requs ? excep_requsList : NULL,
		expt_ana_type ? expt_ana_type_local_nonprim : NULL,
		expt_ue_behav ? expt_ue_behav_local_nonprim : NULL,
		rat_freqs ? rat_freqsList : NULL,
		list_of_ana_subsets ? list_of_ana_subsetsList : NULL,
		disper_reqs ? disper_reqsList : NULL,
		red_trans_reqs ? red_trans_reqsList : NULL,
		wlan_reqs ? wlan_reqsList : NULL,
		upf_info ? upf_info_local_nonprim : NULL,
		app_server_addrs ? app_server_addrsList : NULL,
		dn_perf_reqs ? dn_perf_reqsList : NULL,
		pdu_ses_infos ? pdu_ses_infosList : NULL,
		use_case_cxt &&
		!cJSON_IsNull(use_case_cxt) ? strdup(
			use_case_cxt->valuestring) : NULL,
		pdu_ses_traf_reqs ? pdu_ses_traf_reqsList : NULL,
		loc_acc_reqs ? loc_acc_reqsList : NULL,
		loc_granularity ? loc_granularity_local_nonprim : NULL,
		loc_orientation ? loc_orientation_local_nonprim : NULL,
		data_vl_trns_tm_rqs ? data_vl_trns_tm_rqsList : NULL,
		accu_req ? accu_req_local_nonprim : NULL,
		pause_flg ? true : false,
		pause_flg ? pause_flg->valueint : 0,
		resume_flg ? true : false,
		resume_flg ? resume_flg->valueint : 0,
		mov_behav_reqs ? mov_behav_reqsList : NULL,
		rel_prox_reqs ? rel_prox_reqsList : NULL,
		feedback ? feedback_local_nonprim : NULL
		);

	return event_subscription_local_var;
end:
	if(app_idsList) {
		list_for_each(app_idsList, node) {
			free(node->data);
		}
		list_free(app_idsList);
		app_idsList = NULL;
	}
	if(deviationsList) {
		list_for_each(deviationsList, node) {
			free(node->data);
		}
		list_free(deviationsList);
		deviationsList = NULL;
	}
	if(dnnsList) {
		list_for_each(dnnsList, node) {
			free(node->data);
		}
		list_free(dnnsList);
		dnnsList = NULL;
	}
	if(dnaisList) {
		list_for_each(dnaisList, node) {
			free(node->data);
		}
		list_free(dnaisList);
		dnaisList = NULL;
	}
	if(event_local_nonprim) {
		nwdaf_event_free(event_local_nonprim);
		event_local_nonprim = NULL;
	}
	if(extra_report_req_local_nonprim) {
		event_reporting_requirement_free(extra_report_req_local_nonprim);
		extra_report_req_local_nonprim = NULL;
	}
	if(ladn_dnnsList) {
		list_for_each(ladn_dnnsList, node) {
			free(node->data);
		}
		list_free(ladn_dnnsList);
		ladn_dnnsList = NULL;
	}
	if(notification_method_local_nonprim) {
		notification_method_free(notification_method_local_nonprim);
		notification_method_local_nonprim = NULL;
	}
	if(matching_dir_local_nonprim) {
		matching_direction_free(matching_dir_local_nonprim);
		matching_dir_local_nonprim = NULL;
	}
	if(nf_load_lvl_thdsList) {
		list_for_each(nf_load_lvl_thdsList, node) {
			threshold_level_free(node->data);
		}
		list_free(nf_load_lvl_thdsList);
		nf_load_lvl_thdsList = NULL;
	}
	if(nf_instance_idsList) {
		list_for_each(nf_instance_idsList, node) {
			free(node->data);
		}
		list_free(nf_instance_idsList);
		nf_instance_idsList = NULL;
	}
	if(nf_set_idsList) {
		list_for_each(nf_set_idsList, node) {
			free(node->data);
		}
		list_free(nf_set_idsList);
		nf_set_idsList = NULL;
	}
	if(nf_typesList) {
		list_for_each(nf_typesList, node) {
			nf_type_free(node->data);
		}
		list_free(nf_typesList);
		nf_typesList = NULL;
	}
	if(network_area_local_nonprim) {
		network_area_info_free(network_area_local_nonprim);
		network_area_local_nonprim = NULL;
	}
	if(location_local_nonprim) {
		geo_location_free(location_local_nonprim);
		location_local_nonprim = NULL;
	}
	if(fine_gran_areasList) {
		list_for_each(fine_gran_areasList, node) {
			geographical_area_free(node->data);
		}
		list_free(fine_gran_areasList);
		fine_gran_areasList = NULL;
	}
	if(visited_areasList) {
		list_for_each(visited_areasList, node) {
			network_area_info_free(node->data);
		}
		list_free(visited_areasList);
		visited_areasList = NULL;
	}
	if(nsi_id_infosList) {
		list_for_each(nsi_id_infosList, node) {
			nsi_id_info_free(node->data);
		}
		list_free(nsi_id_infosList);
		nsi_id_infosList = NULL;
	}
	if(nsi_level_thrdsList) {
		list_for_each(nsi_level_thrdsList, node) {
			free(node->data);
		}
		list_free(nsi_level_thrdsList);
		nsi_level_thrdsList = NULL;
	}
	if(qos_requ_local_nonprim) {
		qos_requirement_free(qos_requ_local_nonprim);
		qos_requ_local_nonprim = NULL;
	}
	if(qos_flow_ret_thdsList) {
		list_for_each(qos_flow_ret_thdsList, node) {
			retainability_threshold_free(node->data);
		}
		list_free(qos_flow_ret_thdsList);
		qos_flow_ret_thdsList = NULL;
	}
	if(ran_ue_throu_thdsList) {
		list_for_each(ran_ue_throu_thdsList, node) {
			free(node->data);
		}
		list_free(ran_ue_throu_thdsList);
		ran_ue_throu_thdsList = NULL;
	}
	if(snssaiaList) {
		list_for_each(snssaiaList, node) {
			snssai_free(node->data);
		}
		list_free(snssaiaList);
		snssaiaList = NULL;
	}
	if(tgt_ue_local_nonprim) {
		target_ue_information_free(tgt_ue_local_nonprim);
		tgt_ue_local_nonprim = NULL;
	}
	if(roaming_info_local_nonprim) {
		roaming_info_free(roaming_info_local_nonprim);
		roaming_info_local_nonprim = NULL;
	}
	if(cong_thresholdsList) {
		list_for_each(cong_thresholdsList, node) {
			threshold_level_free(node->data);
		}
		list_free(cong_thresholdsList);
		cong_thresholdsList = NULL;
	}
	if(nw_perf_requsList) {
		list_for_each(nw_perf_requsList, node) {
			network_perf_requirement_free(node->data);
		}
		list_free(nw_perf_requsList);
		nw_perf_requsList = NULL;
	}
	if(ue_comm_reqsList) {
		list_for_each(ue_comm_reqsList, node) {
			ue_comm_req_free(node->data);
		}
		list_free(ue_comm_reqsList);
		ue_comm_reqsList = NULL;
	}
	if(ue_mobility_reqsList) {
		list_for_each(ue_mobility_reqsList, node) {
			ue_mobility_req_free(node->data);
		}
		list_free(ue_mobility_reqsList);
		ue_mobility_reqsList = NULL;
	}
	if(user_data_con_order_cri_local_nonprim) {
		user_data_con_order_crit_free(
			user_data_con_order_cri_local_nonprim);
		user_data_con_order_cri_local_nonprim = NULL;
	}
	if(bw_requsList) {
		list_for_each(bw_requsList, node) {
			bw_requirement_free(node->data);
		}
		list_free(bw_requsList);
		bw_requsList = NULL;
	}
	if(excep_requsList) {
		list_for_each(excep_requsList, node) {
			exception_free(node->data);
		}
		list_free(excep_requsList);
		excep_requsList = NULL;
	}
	if(expt_ana_type_local_nonprim) {
		expected_analytics_type_free(expt_ana_type_local_nonprim);
		expt_ana_type_local_nonprim = NULL;
	}
	if(expt_ue_behav_local_nonprim) {
		expected_ue_behaviour_data_free(expt_ue_behav_local_nonprim);
		expt_ue_behav_local_nonprim = NULL;
	}
	if(rat_freqsList) {
		list_for_each(rat_freqsList, node) {
			rat_freq_information_free(node->data);
		}
		list_free(rat_freqsList);
		rat_freqsList = NULL;
	}
	if(list_of_ana_subsetsList) {
		list_for_each(list_of_ana_subsetsList, node) {
			analytics_subset_free(node->data);
		}
		list_free(list_of_ana_subsetsList);
		list_of_ana_subsetsList = NULL;
	}
	if(disper_reqsList) {
		list_for_each(disper_reqsList, node) {
			dispersion_requirement_free(node->data);
		}
		list_free(disper_reqsList);
		disper_reqsList = NULL;
	}
	if(red_trans_reqsList) {
		list_for_each(red_trans_reqsList, node) {
			redundant_transmission_exp_req_free(node->data);
		}
		list_free(red_trans_reqsList);
		red_trans_reqsList = NULL;
	}
	if(wlan_reqsList) {
		list_for_each(wlan_reqsList, node) {
			wlan_performance_req_free(node->data);
		}
		list_free(wlan_reqsList);
		wlan_reqsList = NULL;
	}
	if(upf_info_local_nonprim) {
		upf_information_free(upf_info_local_nonprim);
		upf_info_local_nonprim = NULL;
	}
	if(app_server_addrsList) {
		list_for_each(app_server_addrsList, node) {
			addr_fqdn_free(node->data);
		}
		list_free(app_server_addrsList);
		app_server_addrsList = NULL;
	}
	if(dn_perf_reqsList) {
		list_for_each(dn_perf_reqsList, node) {
			dn_performance_req_free(node->data);
		}
		list_free(dn_perf_reqsList);
		dn_perf_reqsList = NULL;
	}
	if(pdu_ses_infosList) {
		list_for_each(pdu_ses_infosList, node) {
			pdu_session_info_1_free(node->data);
		}
		list_free(pdu_ses_infosList);
		pdu_ses_infosList = NULL;
	}
	if(pdu_ses_traf_reqsList) {
		list_for_each(pdu_ses_traf_reqsList, node) {
			pdu_ses_traffic_req_free(node->data);
		}
		list_free(pdu_ses_traf_reqsList);
		pdu_ses_traf_reqsList = NULL;
	}
	if(loc_acc_reqsList) {
		list_for_each(loc_acc_reqsList, node) {
			loc_accuracy_req_free(node->data);
		}
		list_free(loc_acc_reqsList);
		loc_acc_reqsList = NULL;
	}
	if(loc_granularity_local_nonprim) {
		loc_info_granularity_free(loc_granularity_local_nonprim);
		loc_granularity_local_nonprim = NULL;
	}
	if(loc_orientation_local_nonprim) {
		location_orientation_free(loc_orientation_local_nonprim);
		loc_orientation_local_nonprim = NULL;
	}
	if(data_vl_trns_tm_rqsList) {
		list_for_each(data_vl_trns_tm_rqsList, node) {
			e2e_data_vol_trans_time_req_free(node->data);
		}
		list_free(data_vl_trns_tm_rqsList);
		data_vl_trns_tm_rqsList = NULL;
	}
	if(accu_req_local_nonprim) {
		accuracy_req_free(accu_req_local_nonprim);
		accu_req_local_nonprim = NULL;
	}
	if(mov_behav_reqsList) {
		list_for_each(mov_behav_reqsList, node) {
			mov_behav_req_free(node->data);
		}
		list_free(mov_behav_reqsList);
		mov_behav_reqsList = NULL;
	}
	if(rel_prox_reqsList) {
		list_for_each(rel_prox_reqsList, node) {
			rel_prox_req_free(node->data);
		}
		list_free(rel_prox_reqsList);
		rel_prox_reqsList = NULL;
	}
	if(feedback_local_nonprim) {
		analytics_feedback_info_free(feedback_local_nonprim);
		feedback_local_nonprim = NULL;
	}
	return NULL;
}

event_subscription_t *event_subscription_copy(event_subscription_t	*dst,
                                              event_subscription_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = event_subscription_convertToJSON(src);
	if(!item) {
		printf("event_subscription_convertToJSON() failed");
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

	event_subscription_free(dst);
	dst = event_subscription_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
