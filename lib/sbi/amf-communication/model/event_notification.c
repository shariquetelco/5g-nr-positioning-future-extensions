#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_notification.h"

event_notification_t *event_notification_create(nwdaf_event_t *event,
                                                char *start, char *expiry,
                                                char *time_stamp_gen,
                                                nwdaf_failure_code_t *fail_notify_code, bool is_rv_wait_time, int rv_wait_time, analytics_metadata_info_t *ana_meta_info, list_t *nf_load_level_infos, list_t *nsi_load_level_infos, list_t *pfd_determ_infos, slice_load_level_information_t *slice_load_level_info, list_t *svc_exps, list_t *qos_sustain_infos, list_t *ue_comms, list_t *ue_mobs, list_t *user_data_cong_infos, list_t *abnor_behavrs, list_t *nw_perfs, list_t *dn_perf_infos, list_t *disper_infos, list_t *red_trans_infos, list_t *wlan_infos, list_t *smcc_exps, list_t *pdu_ses_traf_infos, list_t *data_vl_trns_tm_infos, accuracy_info_t *accu_info, bool is_cancel_accu_ind, int cancel_accu_ind, bool is_pause_ind, int pause_ind, bool is_resume_ind, int resume_ind, list_t *mov_behav_infos, list_t *loc_acc_infos,
                                                list_t *rel_prox_infos) {
	event_notification_t *event_notification_local_var =
		malloc(sizeof(event_notification_t));

	event_notification_local_var->event = event;
	event_notification_local_var->start = start;
	event_notification_local_var->expiry = expiry;
	event_notification_local_var->time_stamp_gen = time_stamp_gen;
	event_notification_local_var->fail_notify_code = fail_notify_code;
	event_notification_local_var->is_rv_wait_time = is_rv_wait_time;
	event_notification_local_var->rv_wait_time = rv_wait_time;
	event_notification_local_var->ana_meta_info = ana_meta_info;
	event_notification_local_var->nf_load_level_infos = nf_load_level_infos;
	event_notification_local_var->nsi_load_level_infos =
		nsi_load_level_infos;
	event_notification_local_var->pfd_determ_infos = pfd_determ_infos;
	event_notification_local_var->slice_load_level_info =
		slice_load_level_info;
	event_notification_local_var->svc_exps = svc_exps;
	event_notification_local_var->qos_sustain_infos = qos_sustain_infos;
	event_notification_local_var->ue_comms = ue_comms;
	event_notification_local_var->ue_mobs = ue_mobs;
	event_notification_local_var->user_data_cong_infos =
		user_data_cong_infos;
	event_notification_local_var->abnor_behavrs = abnor_behavrs;
	event_notification_local_var->nw_perfs = nw_perfs;
	event_notification_local_var->dn_perf_infos = dn_perf_infos;
	event_notification_local_var->disper_infos = disper_infos;
	event_notification_local_var->red_trans_infos = red_trans_infos;
	event_notification_local_var->wlan_infos = wlan_infos;
	event_notification_local_var->smcc_exps = smcc_exps;
	event_notification_local_var->pdu_ses_traf_infos = pdu_ses_traf_infos;
	event_notification_local_var->data_vl_trns_tm_infos =
		data_vl_trns_tm_infos;
	event_notification_local_var->accu_info = accu_info;
	event_notification_local_var->is_cancel_accu_ind = is_cancel_accu_ind;
	event_notification_local_var->cancel_accu_ind = cancel_accu_ind;
	event_notification_local_var->is_pause_ind = is_pause_ind;
	event_notification_local_var->pause_ind = pause_ind;
	event_notification_local_var->is_resume_ind = is_resume_ind;
	event_notification_local_var->resume_ind = resume_ind;
	event_notification_local_var->mov_behav_infos = mov_behav_infos;
	event_notification_local_var->loc_acc_infos = loc_acc_infos;
	event_notification_local_var->rel_prox_infos = rel_prox_infos;

	return event_notification_local_var;
}

void event_notification_free(event_notification_t *event_notification) {
	lnode_t *node = NULL;

	if(NULL == event_notification) {
		return;
	}
	if(event_notification->event) {
		nwdaf_event_free(event_notification->event);
		event_notification->event = NULL;
	}
	if(event_notification->start) {
		free(event_notification->start);
		event_notification->start = NULL;
	}
	if(event_notification->expiry) {
		free(event_notification->expiry);
		event_notification->expiry = NULL;
	}
	if(event_notification->time_stamp_gen) {
		free(event_notification->time_stamp_gen);
		event_notification->time_stamp_gen = NULL;
	}
	if(event_notification->fail_notify_code) {
		nwdaf_failure_code_free(event_notification->fail_notify_code);
		event_notification->fail_notify_code = NULL;
	}
	if(event_notification->ana_meta_info) {
		analytics_metadata_info_free(event_notification->ana_meta_info);
		event_notification->ana_meta_info = NULL;
	}
	if(event_notification->nf_load_level_infos) {
		list_for_each(event_notification->nf_load_level_infos, node) {
			nf_load_level_information_free(node->data);
		}
		list_free(event_notification->nf_load_level_infos);
		event_notification->nf_load_level_infos = NULL;
	}
	if(event_notification->nsi_load_level_infos) {
		list_for_each(event_notification->nsi_load_level_infos, node) {
			nsi_load_level_info_free(node->data);
		}
		list_free(event_notification->nsi_load_level_infos);
		event_notification->nsi_load_level_infos = NULL;
	}
	if(event_notification->pfd_determ_infos) {
		list_for_each(event_notification->pfd_determ_infos, node) {
			pfd_determination_info_free(node->data);
		}
		list_free(event_notification->pfd_determ_infos);
		event_notification->pfd_determ_infos = NULL;
	}
	if(event_notification->slice_load_level_info) {
		slice_load_level_information_free(
			event_notification->slice_load_level_info);
		event_notification->slice_load_level_info = NULL;
	}
	if(event_notification->svc_exps) {
		list_for_each(event_notification->svc_exps, node) {
			service_experience_info_free(node->data);
		}
		list_free(event_notification->svc_exps);
		event_notification->svc_exps = NULL;
	}
	if(event_notification->qos_sustain_infos) {
		list_for_each(event_notification->qos_sustain_infos, node) {
			qos_sustainability_info_free(node->data);
		}
		list_free(event_notification->qos_sustain_infos);
		event_notification->qos_sustain_infos = NULL;
	}
	if(event_notification->ue_comms) {
		list_for_each(event_notification->ue_comms, node) {
			ue_communication_free(node->data);
		}
		list_free(event_notification->ue_comms);
		event_notification->ue_comms = NULL;
	}
	if(event_notification->ue_mobs) {
		list_for_each(event_notification->ue_mobs, node) {
			ue_mobility_free(node->data);
		}
		list_free(event_notification->ue_mobs);
		event_notification->ue_mobs = NULL;
	}
	if(event_notification->user_data_cong_infos) {
		list_for_each(event_notification->user_data_cong_infos, node) {
			user_data_congestion_info_free(node->data);
		}
		list_free(event_notification->user_data_cong_infos);
		event_notification->user_data_cong_infos = NULL;
	}
	if(event_notification->abnor_behavrs) {
		list_for_each(event_notification->abnor_behavrs, node) {
			abnormal_behaviour_free(node->data);
		}
		list_free(event_notification->abnor_behavrs);
		event_notification->abnor_behavrs = NULL;
	}
	if(event_notification->nw_perfs) {
		list_for_each(event_notification->nw_perfs, node) {
			network_perf_info_free(node->data);
		}
		list_free(event_notification->nw_perfs);
		event_notification->nw_perfs = NULL;
	}
	if(event_notification->dn_perf_infos) {
		list_for_each(event_notification->dn_perf_infos, node) {
			dn_perf_info_free(node->data);
		}
		list_free(event_notification->dn_perf_infos);
		event_notification->dn_perf_infos = NULL;
	}
	if(event_notification->disper_infos) {
		list_for_each(event_notification->disper_infos, node) {
			dispersion_info_free(node->data);
		}
		list_free(event_notification->disper_infos);
		event_notification->disper_infos = NULL;
	}
	if(event_notification->red_trans_infos) {
		list_for_each(event_notification->red_trans_infos, node) {
			redundant_transmission_exp_info_free(node->data);
		}
		list_free(event_notification->red_trans_infos);
		event_notification->red_trans_infos = NULL;
	}
	if(event_notification->wlan_infos) {
		list_for_each(event_notification->wlan_infos, node) {
			wlan_performance_info_free(node->data);
		}
		list_free(event_notification->wlan_infos);
		event_notification->wlan_infos = NULL;
	}
	if(event_notification->smcc_exps) {
		list_for_each(event_notification->smcc_exps, node) {
			smcce_info_free(node->data);
		}
		list_free(event_notification->smcc_exps);
		event_notification->smcc_exps = NULL;
	}
	if(event_notification->pdu_ses_traf_infos) {
		list_for_each(event_notification->pdu_ses_traf_infos, node) {
			pdu_ses_traffic_info_free(node->data);
		}
		list_free(event_notification->pdu_ses_traf_infos);
		event_notification->pdu_ses_traf_infos = NULL;
	}
	if(event_notification->data_vl_trns_tm_infos) {
		list_for_each(event_notification->data_vl_trns_tm_infos, node) {
			e2e_data_vol_trans_time_info_free(node->data);
		}
		list_free(event_notification->data_vl_trns_tm_infos);
		event_notification->data_vl_trns_tm_infos = NULL;
	}
	if(event_notification->accu_info) {
		accuracy_info_free(event_notification->accu_info);
		event_notification->accu_info = NULL;
	}
	if(event_notification->mov_behav_infos) {
		list_for_each(event_notification->mov_behav_infos, node) {
			mov_behav_info_free(node->data);
		}
		list_free(event_notification->mov_behav_infos);
		event_notification->mov_behav_infos = NULL;
	}
	if(event_notification->loc_acc_infos) {
		list_for_each(event_notification->loc_acc_infos, node) {
			loc_accuracy_info_free(node->data);
		}
		list_free(event_notification->loc_acc_infos);
		event_notification->loc_acc_infos = NULL;
	}
	if(event_notification->rel_prox_infos) {
		list_for_each(event_notification->rel_prox_infos, node) {
			rel_prox_info_free(node->data);
		}
		list_free(event_notification->rel_prox_infos);
		event_notification->rel_prox_infos = NULL;
	}
	free(event_notification);
}

cJSON *event_notification_convertToJSON(
	event_notification_t *event_notification) {
	cJSON *item = NULL;
	lnode_t *node = NULL;

	if(event_notification == NULL) {
		printf(
			"event_notification_convertToJSON() failed [EventNotification]");
		return NULL;
	}

	item = cJSON_CreateObject();
	if(!event_notification->event) {
		printf("event_notification_convertToJSON() failed [event]");
		return NULL;
	}
	cJSON *event_local_JSON = nwdaf_event_convertToJSON(
		event_notification->event);
	if(event_local_JSON == NULL) {
		printf("event_notification_convertToJSON() failed [event]");
		goto end;
	}
	cJSON_AddItemToObject(item, "event", event_local_JSON);
	if(item->child == NULL) {
		printf("event_notification_convertToJSON() failed [event]");
		goto end;
	}

	if(event_notification->start) {
		if(cJSON_AddStringToObject(item, "start",
		                           event_notification->start) == NULL)
		{
			printf(
				"event_notification_convertToJSON() failed [start]");
			goto end;
		}
	}

	if(event_notification->expiry) {
		if(cJSON_AddStringToObject(item, "expiry",
		                           event_notification->expiry) == NULL)
		{
			printf(
				"event_notification_convertToJSON() failed [expiry]");
			goto end;
		}
	}

	if(event_notification->time_stamp_gen) {
		if(cJSON_AddStringToObject(item, "timeStampGen",
		                           event_notification->time_stamp_gen)
		   == NULL)
		{
			printf(
				"event_notification_convertToJSON() failed [time_stamp_gen]");
			goto end;
		}
	}

	if(event_notification->fail_notify_code) {
		cJSON *fail_notify_code_local_JSON =
			nwdaf_failure_code_convertToJSON(
				event_notification->fail_notify_code);
		if(fail_notify_code_local_JSON == NULL) {
			printf(
				"event_notification_convertToJSON() failed [fail_notify_code]");
			goto end;
		}
		cJSON_AddItemToObject(item, "failNotifyCode",
		                      fail_notify_code_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notification_convertToJSON() failed [fail_notify_code]");
			goto end;
		}
	}

	if(event_notification->is_rv_wait_time) {
		if(cJSON_AddNumberToObject(item, "rvWaitTime",
		                           event_notification->rv_wait_time) ==
		   NULL)
		{
			printf(
				"event_notification_convertToJSON() failed [rv_wait_time]");
			goto end;
		}
	}

	if(event_notification->ana_meta_info) {
		cJSON *ana_meta_info_local_JSON =
			analytics_metadata_info_convertToJSON(
				event_notification->ana_meta_info);
		if(ana_meta_info_local_JSON == NULL) {
			printf(
				"event_notification_convertToJSON() failed [ana_meta_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "anaMetaInfo",
		                      ana_meta_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notification_convertToJSON() failed [ana_meta_info]");
			goto end;
		}
	}

	if(event_notification->nf_load_level_infos) {
		cJSON *nf_load_level_infosList = cJSON_AddArrayToObject(item,
		                                                        "nfLoadLevelInfos");
		if(nf_load_level_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [nf_load_level_infos]");
			goto end;
		}
		list_for_each(event_notification->nf_load_level_infos, node) {
			cJSON *itemLocal =
				nf_load_level_information_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [nf_load_level_infos]");
				goto end;
			}
			cJSON_AddItemToArray(nf_load_level_infosList,
			                     itemLocal);
		}
	}

	if(event_notification->nsi_load_level_infos) {
		cJSON *nsi_load_level_infosList = cJSON_AddArrayToObject(item,
		                                                         "nsiLoadLevelInfos");
		if(nsi_load_level_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [nsi_load_level_infos]");
			goto end;
		}
		list_for_each(event_notification->nsi_load_level_infos, node) {
			cJSON *itemLocal = nsi_load_level_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [nsi_load_level_infos]");
				goto end;
			}
			cJSON_AddItemToArray(nsi_load_level_infosList,
			                     itemLocal);
		}
	}

	if(event_notification->pfd_determ_infos) {
		cJSON *pfd_determ_infosList = cJSON_AddArrayToObject(item,
		                                                     "pfdDetermInfos");
		if(pfd_determ_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [pfd_determ_infos]");
			goto end;
		}
		list_for_each(event_notification->pfd_determ_infos, node) {
			cJSON *itemLocal = pfd_determination_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [pfd_determ_infos]");
				goto end;
			}
			cJSON_AddItemToArray(pfd_determ_infosList, itemLocal);
		}
	}

	if(event_notification->slice_load_level_info) {
		cJSON *slice_load_level_info_local_JSON =
			slice_load_level_information_convertToJSON(
				event_notification->slice_load_level_info);
		if(slice_load_level_info_local_JSON == NULL) {
			printf(
				"event_notification_convertToJSON() failed [slice_load_level_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "sliceLoadLevelInfo",
		                      slice_load_level_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notification_convertToJSON() failed [slice_load_level_info]");
			goto end;
		}
	}

	if(event_notification->svc_exps) {
		cJSON *svc_expsList = cJSON_AddArrayToObject(item, "svcExps");
		if(svc_expsList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [svc_exps]");
			goto end;
		}
		list_for_each(event_notification->svc_exps, node) {
			cJSON *itemLocal =
				service_experience_info_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [svc_exps]");
				goto end;
			}
			cJSON_AddItemToArray(svc_expsList, itemLocal);
		}
	}

	if(event_notification->qos_sustain_infos) {
		cJSON *qos_sustain_infosList = cJSON_AddArrayToObject(item,
		                                                      "qosSustainInfos");
		if(qos_sustain_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [qos_sustain_infos]");
			goto end;
		}
		list_for_each(event_notification->qos_sustain_infos, node) {
			cJSON *itemLocal =
				qos_sustainability_info_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [qos_sustain_infos]");
				goto end;
			}
			cJSON_AddItemToArray(qos_sustain_infosList, itemLocal);
		}
	}

	if(event_notification->ue_comms) {
		cJSON *ue_commsList = cJSON_AddArrayToObject(item, "ueComms");
		if(ue_commsList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [ue_comms]");
			goto end;
		}
		list_for_each(event_notification->ue_comms, node) {
			cJSON *itemLocal = ue_communication_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [ue_comms]");
				goto end;
			}
			cJSON_AddItemToArray(ue_commsList, itemLocal);
		}
	}

	if(event_notification->ue_mobs) {
		cJSON *ue_mobsList = cJSON_AddArrayToObject(item, "ueMobs");
		if(ue_mobsList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [ue_mobs]");
			goto end;
		}
		list_for_each(event_notification->ue_mobs, node) {
			cJSON *itemLocal =
				ue_mobility_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [ue_mobs]");
				goto end;
			}
			cJSON_AddItemToArray(ue_mobsList, itemLocal);
		}
	}

	if(event_notification->user_data_cong_infos) {
		cJSON *user_data_cong_infosList = cJSON_AddArrayToObject(item,
		                                                         "userDataCongInfos");
		if(user_data_cong_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [user_data_cong_infos]");
			goto end;
		}
		list_for_each(event_notification->user_data_cong_infos, node) {
			cJSON *itemLocal =
				user_data_congestion_info_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [user_data_cong_infos]");
				goto end;
			}
			cJSON_AddItemToArray(user_data_cong_infosList,
			                     itemLocal);
		}
	}

	if(event_notification->abnor_behavrs) {
		cJSON *abnor_behavrsList = cJSON_AddArrayToObject(item,
		                                                  "abnorBehavrs");
		if(abnor_behavrsList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [abnor_behavrs]");
			goto end;
		}
		list_for_each(event_notification->abnor_behavrs, node) {
			cJSON *itemLocal = abnormal_behaviour_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [abnor_behavrs]");
				goto end;
			}
			cJSON_AddItemToArray(abnor_behavrsList, itemLocal);
		}
	}

	if(event_notification->nw_perfs) {
		cJSON *nw_perfsList = cJSON_AddArrayToObject(item, "nwPerfs");
		if(nw_perfsList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [nw_perfs]");
			goto end;
		}
		list_for_each(event_notification->nw_perfs, node) {
			cJSON *itemLocal = network_perf_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [nw_perfs]");
				goto end;
			}
			cJSON_AddItemToArray(nw_perfsList, itemLocal);
		}
	}

	if(event_notification->dn_perf_infos) {
		cJSON *dn_perf_infosList = cJSON_AddArrayToObject(item,
		                                                  "dnPerfInfos");
		if(dn_perf_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [dn_perf_infos]");
			goto end;
		}
		list_for_each(event_notification->dn_perf_infos, node) {
			cJSON *itemLocal =
				dn_perf_info_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [dn_perf_infos]");
				goto end;
			}
			cJSON_AddItemToArray(dn_perf_infosList, itemLocal);
		}
	}

	if(event_notification->disper_infos) {
		cJSON *disper_infosList = cJSON_AddArrayToObject(item,
		                                                 "disperInfos");
		if(disper_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [disper_infos]");
			goto end;
		}
		list_for_each(event_notification->disper_infos, node) {
			cJSON *itemLocal = dispersion_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [disper_infos]");
				goto end;
			}
			cJSON_AddItemToArray(disper_infosList, itemLocal);
		}
	}

	if(event_notification->red_trans_infos) {
		cJSON *red_trans_infosList = cJSON_AddArrayToObject(item,
		                                                    "redTransInfos");
		if(red_trans_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [red_trans_infos]");
			goto end;
		}
		list_for_each(event_notification->red_trans_infos, node) {
			cJSON *itemLocal =
				redundant_transmission_exp_info_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [red_trans_infos]");
				goto end;
			}
			cJSON_AddItemToArray(red_trans_infosList, itemLocal);
		}
	}

	if(event_notification->wlan_infos) {
		cJSON *wlan_infosList =
			cJSON_AddArrayToObject(item, "wlanInfos");
		if(wlan_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [wlan_infos]");
			goto end;
		}
		list_for_each(event_notification->wlan_infos, node) {
			cJSON *itemLocal = wlan_performance_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [wlan_infos]");
				goto end;
			}
			cJSON_AddItemToArray(wlan_infosList, itemLocal);
		}
	}

	if(event_notification->smcc_exps) {
		cJSON *smcc_expsList = cJSON_AddArrayToObject(item, "smccExps");
		if(smcc_expsList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [smcc_exps]");
			goto end;
		}
		list_for_each(event_notification->smcc_exps, node) {
			cJSON *itemLocal = smcce_info_convertToJSON(node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [smcc_exps]");
				goto end;
			}
			cJSON_AddItemToArray(smcc_expsList, itemLocal);
		}
	}

	if(event_notification->pdu_ses_traf_infos) {
		cJSON *pdu_ses_traf_infosList = cJSON_AddArrayToObject(item,
		                                                       "pduSesTrafInfos");
		if(pdu_ses_traf_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [pdu_ses_traf_infos]");
			goto end;
		}
		list_for_each(event_notification->pdu_ses_traf_infos, node) {
			cJSON *itemLocal = pdu_ses_traffic_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [pdu_ses_traf_infos]");
				goto end;
			}
			cJSON_AddItemToArray(pdu_ses_traf_infosList, itemLocal);
		}
	}

	if(event_notification->data_vl_trns_tm_infos) {
		cJSON *data_vl_trns_tm_infosList = cJSON_AddArrayToObject(item,
		                                                          "dataVlTrnsTmInfos");
		if(data_vl_trns_tm_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [data_vl_trns_tm_infos]");
			goto end;
		}
		list_for_each(event_notification->data_vl_trns_tm_infos, node) {
			cJSON *itemLocal =
				e2e_data_vol_trans_time_info_convertToJSON(
					node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [data_vl_trns_tm_infos]");
				goto end;
			}
			cJSON_AddItemToArray(data_vl_trns_tm_infosList,
			                     itemLocal);
		}
	}

	if(event_notification->accu_info) {
		cJSON *accu_info_local_JSON = accuracy_info_convertToJSON(
			event_notification->accu_info);
		if(accu_info_local_JSON == NULL) {
			printf(
				"event_notification_convertToJSON() failed [accu_info]");
			goto end;
		}
		cJSON_AddItemToObject(item, "accuInfo", accu_info_local_JSON);
		if(item->child == NULL) {
			printf(
				"event_notification_convertToJSON() failed [accu_info]");
			goto end;
		}
	}

	if(event_notification->is_cancel_accu_ind) {
		if(cJSON_AddBoolToObject(item, "cancelAccuInd",
		                         event_notification->cancel_accu_ind) ==
		   NULL)
		{
			printf(
				"event_notification_convertToJSON() failed [cancel_accu_ind]");
			goto end;
		}
	}

	if(event_notification->is_pause_ind) {
		if(cJSON_AddBoolToObject(item, "pauseInd",
		                         event_notification->pause_ind) == NULL)
		{
			printf(
				"event_notification_convertToJSON() failed [pause_ind]");
			goto end;
		}
	}

	if(event_notification->is_resume_ind) {
		if(cJSON_AddBoolToObject(item, "resumeInd",
		                         event_notification->resume_ind) ==
		   NULL)
		{
			printf(
				"event_notification_convertToJSON() failed [resume_ind]");
			goto end;
		}
	}

	if(event_notification->mov_behav_infos) {
		cJSON *mov_behav_infosList = cJSON_AddArrayToObject(item,
		                                                    "movBehavInfos");
		if(mov_behav_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [mov_behav_infos]");
			goto end;
		}
		list_for_each(event_notification->mov_behav_infos, node) {
			cJSON *itemLocal = mov_behav_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [mov_behav_infos]");
				goto end;
			}
			cJSON_AddItemToArray(mov_behav_infosList, itemLocal);
		}
	}

	if(event_notification->loc_acc_infos) {
		cJSON *loc_acc_infosList = cJSON_AddArrayToObject(item,
		                                                  "locAccInfos");
		if(loc_acc_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [loc_acc_infos]");
			goto end;
		}
		list_for_each(event_notification->loc_acc_infos, node) {
			cJSON *itemLocal = loc_accuracy_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [loc_acc_infos]");
				goto end;
			}
			cJSON_AddItemToArray(loc_acc_infosList, itemLocal);
		}
	}

	if(event_notification->rel_prox_infos) {
		cJSON *rel_prox_infosList = cJSON_AddArrayToObject(item,
		                                                   "relProxInfos");
		if(rel_prox_infosList == NULL) {
			printf(
				"event_notification_convertToJSON() failed [rel_prox_infos]");
			goto end;
		}
		list_for_each(event_notification->rel_prox_infos, node) {
			cJSON *itemLocal = rel_prox_info_convertToJSON(
				node->data);
			if(itemLocal == NULL) {
				printf(
					"event_notification_convertToJSON() failed [rel_prox_infos]");
				goto end;
			}
			cJSON_AddItemToArray(rel_prox_infosList, itemLocal);
		}
	}

end:
	return item;
}

event_notification_t *event_notification_parseFromJSON(
	cJSON *event_notificationJSON) {
	event_notification_t *event_notification_local_var = NULL;
	lnode_t *node = NULL;
	cJSON *event = NULL;
	nwdaf_event_t *event_local_nonprim = NULL;
	cJSON *start = NULL;
	cJSON *expiry = NULL;
	cJSON *time_stamp_gen = NULL;
	cJSON *fail_notify_code = NULL;
	nwdaf_failure_code_t *fail_notify_code_local_nonprim = NULL;
	cJSON *rv_wait_time = NULL;
	cJSON *ana_meta_info = NULL;
	analytics_metadata_info_t *ana_meta_info_local_nonprim = NULL;
	cJSON *nf_load_level_infos = NULL;
	list_t *nf_load_level_infosList = NULL;
	cJSON *nsi_load_level_infos = NULL;
	list_t *nsi_load_level_infosList = NULL;
	cJSON *pfd_determ_infos = NULL;
	list_t *pfd_determ_infosList = NULL;
	cJSON *slice_load_level_info = NULL;
	slice_load_level_information_t *slice_load_level_info_local_nonprim =
		NULL;
	cJSON *svc_exps = NULL;
	list_t *svc_expsList = NULL;
	cJSON *qos_sustain_infos = NULL;
	list_t *qos_sustain_infosList = NULL;
	cJSON *ue_comms = NULL;
	list_t *ue_commsList = NULL;
	cJSON *ue_mobs = NULL;
	list_t *ue_mobsList = NULL;
	cJSON *user_data_cong_infos = NULL;
	list_t *user_data_cong_infosList = NULL;
	cJSON *abnor_behavrs = NULL;
	list_t *abnor_behavrsList = NULL;
	cJSON *nw_perfs = NULL;
	list_t *nw_perfsList = NULL;
	cJSON *dn_perf_infos = NULL;
	list_t *dn_perf_infosList = NULL;
	cJSON *disper_infos = NULL;
	list_t *disper_infosList = NULL;
	cJSON *red_trans_infos = NULL;
	list_t *red_trans_infosList = NULL;
	cJSON *wlan_infos = NULL;
	list_t *wlan_infosList = NULL;
	cJSON *smcc_exps = NULL;
	list_t *smcc_expsList = NULL;
	cJSON *pdu_ses_traf_infos = NULL;
	list_t *pdu_ses_traf_infosList = NULL;
	cJSON *data_vl_trns_tm_infos = NULL;
	list_t *data_vl_trns_tm_infosList = NULL;
	cJSON *accu_info = NULL;
	accuracy_info_t *accu_info_local_nonprim = NULL;
	cJSON *cancel_accu_ind = NULL;
	cJSON *pause_ind = NULL;
	cJSON *resume_ind = NULL;
	cJSON *mov_behav_infos = NULL;
	list_t *mov_behav_infosList = NULL;
	cJSON *loc_acc_infos = NULL;
	list_t *loc_acc_infosList = NULL;
	cJSON *rel_prox_infos = NULL;
	list_t *rel_prox_infosList = NULL;
	event =
		cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
		                                 "event");
	if(!event) {
		printf("event_notification_parseFromJSON() failed [event]");
		goto end;
	}
	event_local_nonprim = nwdaf_event_parseFromJSON(event);
	if(!event_local_nonprim) {
		printf("nwdaf_event_parseFromJSON failed [event]");
		goto end;
	}

	start =
		cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
		                                 "start");
	if(start) {
		if(!cJSON_IsString(start) &&
		   !cJSON_IsNull(start))
		{
			printf(
				"event_notification_parseFromJSON() failed [start]");
			goto end;
		}
	}

	expiry = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                          "expiry");
	if(expiry) {
		if(!cJSON_IsString(expiry) &&
		   !cJSON_IsNull(expiry))
		{
			printf(
				"event_notification_parseFromJSON() failed [expiry]");
			goto end;
		}
	}

	time_stamp_gen = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "timeStampGen");
	if(time_stamp_gen) {
		if(!cJSON_IsString(time_stamp_gen) &&
		   !cJSON_IsNull(time_stamp_gen))
		{
			printf(
				"event_notification_parseFromJSON() failed [time_stamp_gen]");
			goto end;
		}
	}

	fail_notify_code = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "failNotifyCode");
	if(fail_notify_code) {
		fail_notify_code_local_nonprim =
			nwdaf_failure_code_parseFromJSON(fail_notify_code);
		if(!fail_notify_code_local_nonprim) {
			printf(
				"nwdaf_failure_code_parseFromJSON failed [fail_notify_code]");
			goto end;
		}
	}

	rv_wait_time = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                                "rvWaitTime");
	if(rv_wait_time) {
		if(!cJSON_IsNumber(rv_wait_time)) {
			printf(
				"event_notification_parseFromJSON() failed [rv_wait_time]");
			goto end;
		}
	}

	ana_meta_info = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                                 "anaMetaInfo");
	if(ana_meta_info) {
		ana_meta_info_local_nonprim =
			analytics_metadata_info_parseFromJSON(ana_meta_info);
		if(!ana_meta_info_local_nonprim) {
			printf(
				"analytics_metadata_info_parseFromJSON failed [ana_meta_info]");
			goto end;
		}
	}

	nf_load_level_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "nfLoadLevelInfos");
	if(nf_load_level_infos) {
		cJSON *nf_load_level_infos_local = NULL;
		if(!cJSON_IsArray(nf_load_level_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [nf_load_level_infos]");
			goto end;
		}

		nf_load_level_infosList = list_create();

		cJSON_ArrayForEach(nf_load_level_infos_local,
		                   nf_load_level_infos) {
			if(!cJSON_IsObject(nf_load_level_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [nf_load_level_infos]");
				goto end;
			}
			nf_load_level_information_t *nf_load_level_infosItem =
				nf_load_level_information_parseFromJSON(
					nf_load_level_infos_local);
			if(!nf_load_level_infosItem) {
				printf("No nf_load_level_infosItem");
				goto end;
			}
			list_add(nf_load_level_infosList,
			         nf_load_level_infosItem);
		}
	}

	nsi_load_level_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "nsiLoadLevelInfos");
	if(nsi_load_level_infos) {
		cJSON *nsi_load_level_infos_local = NULL;
		if(!cJSON_IsArray(nsi_load_level_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [nsi_load_level_infos]");
			goto end;
		}

		nsi_load_level_infosList = list_create();

		cJSON_ArrayForEach(nsi_load_level_infos_local,
		                   nsi_load_level_infos) {
			if(!cJSON_IsObject(nsi_load_level_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [nsi_load_level_infos]");
				goto end;
			}
			nsi_load_level_info_t *nsi_load_level_infosItem =
				nsi_load_level_info_parseFromJSON(
					nsi_load_level_infos_local);
			if(!nsi_load_level_infosItem) {
				printf("No nsi_load_level_infosItem");
				goto end;
			}
			list_add(nsi_load_level_infosList,
			         nsi_load_level_infosItem);
		}
	}

	pfd_determ_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "pfdDetermInfos");
	if(pfd_determ_infos) {
		cJSON *pfd_determ_infos_local = NULL;
		if(!cJSON_IsArray(pfd_determ_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [pfd_determ_infos]");
			goto end;
		}

		pfd_determ_infosList = list_create();

		cJSON_ArrayForEach(pfd_determ_infos_local, pfd_determ_infos) {
			if(!cJSON_IsObject(pfd_determ_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [pfd_determ_infos]");
				goto end;
			}
			pfd_determination_info_t *pfd_determ_infosItem =
				pfd_determination_info_parseFromJSON(
					pfd_determ_infos_local);
			if(!pfd_determ_infosItem) {
				printf("No pfd_determ_infosItem");
				goto end;
			}
			list_add(pfd_determ_infosList, pfd_determ_infosItem);
		}
	}

	slice_load_level_info = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "sliceLoadLevelInfo");
	if(slice_load_level_info) {
		slice_load_level_info_local_nonprim =
			slice_load_level_information_parseFromJSON(
				slice_load_level_info);
		if(!slice_load_level_info_local_nonprim) {
			printf(
				"slice_load_level_information_parseFromJSON failed [slice_load_level_info]");
			goto end;
		}
	}

	svc_exps = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                            "svcExps");
	if(svc_exps) {
		cJSON *svc_exps_local = NULL;
		if(!cJSON_IsArray(svc_exps)) {
			printf(
				"event_notification_parseFromJSON() failed [svc_exps]");
			goto end;
		}

		svc_expsList = list_create();

		cJSON_ArrayForEach(svc_exps_local, svc_exps) {
			if(!cJSON_IsObject(svc_exps_local)) {
				printf(
					"event_notification_parseFromJSON() failed [svc_exps]");
				goto end;
			}
			service_experience_info_t *svc_expsItem =
				service_experience_info_parseFromJSON(
					svc_exps_local);
			if(!svc_expsItem) {
				printf("No svc_expsItem");
				goto end;
			}
			list_add(svc_expsList, svc_expsItem);
		}
	}

	qos_sustain_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "qosSustainInfos");
	if(qos_sustain_infos) {
		cJSON *qos_sustain_infos_local = NULL;
		if(!cJSON_IsArray(qos_sustain_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [qos_sustain_infos]");
			goto end;
		}

		qos_sustain_infosList = list_create();

		cJSON_ArrayForEach(qos_sustain_infos_local, qos_sustain_infos) {
			if(!cJSON_IsObject(qos_sustain_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [qos_sustain_infos]");
				goto end;
			}
			qos_sustainability_info_t *qos_sustain_infosItem =
				qos_sustainability_info_parseFromJSON(
					qos_sustain_infos_local);
			if(!qos_sustain_infosItem) {
				printf("No qos_sustain_infosItem");
				goto end;
			}
			list_add(qos_sustain_infosList, qos_sustain_infosItem);
		}
	}

	ue_comms = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                            "ueComms");
	if(ue_comms) {
		cJSON *ue_comms_local = NULL;
		if(!cJSON_IsArray(ue_comms)) {
			printf(
				"event_notification_parseFromJSON() failed [ue_comms]");
			goto end;
		}

		ue_commsList = list_create();

		cJSON_ArrayForEach(ue_comms_local, ue_comms) {
			if(!cJSON_IsObject(ue_comms_local)) {
				printf(
					"event_notification_parseFromJSON() failed [ue_comms]");
				goto end;
			}
			ue_communication_t *ue_commsItem =
				ue_communication_parseFromJSON(ue_comms_local);
			if(!ue_commsItem) {
				printf("No ue_commsItem");
				goto end;
			}
			list_add(ue_commsList, ue_commsItem);
		}
	}

	ue_mobs = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                           "ueMobs");
	if(ue_mobs) {
		cJSON *ue_mobs_local = NULL;
		if(!cJSON_IsArray(ue_mobs)) {
			printf(
				"event_notification_parseFromJSON() failed [ue_mobs]");
			goto end;
		}

		ue_mobsList = list_create();

		cJSON_ArrayForEach(ue_mobs_local, ue_mobs) {
			if(!cJSON_IsObject(ue_mobs_local)) {
				printf(
					"event_notification_parseFromJSON() failed [ue_mobs]");
				goto end;
			}
			ue_mobility_t *ue_mobsItem = ue_mobility_parseFromJSON(
				ue_mobs_local);
			if(!ue_mobsItem) {
				printf("No ue_mobsItem");
				goto end;
			}
			list_add(ue_mobsList, ue_mobsItem);
		}
	}

	user_data_cong_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "userDataCongInfos");
	if(user_data_cong_infos) {
		cJSON *user_data_cong_infos_local = NULL;
		if(!cJSON_IsArray(user_data_cong_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [user_data_cong_infos]");
			goto end;
		}

		user_data_cong_infosList = list_create();

		cJSON_ArrayForEach(user_data_cong_infos_local,
		                   user_data_cong_infos) {
			if(!cJSON_IsObject(user_data_cong_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [user_data_cong_infos]");
				goto end;
			}
			user_data_congestion_info_t *user_data_cong_infosItem =
				user_data_congestion_info_parseFromJSON(
					user_data_cong_infos_local);
			if(!user_data_cong_infosItem) {
				printf("No user_data_cong_infosItem");
				goto end;
			}
			list_add(user_data_cong_infosList,
			         user_data_cong_infosItem);
		}
	}

	abnor_behavrs = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                                 "abnorBehavrs");
	if(abnor_behavrs) {
		cJSON *abnor_behavrs_local = NULL;
		if(!cJSON_IsArray(abnor_behavrs)) {
			printf(
				"event_notification_parseFromJSON() failed [abnor_behavrs]");
			goto end;
		}

		abnor_behavrsList = list_create();

		cJSON_ArrayForEach(abnor_behavrs_local, abnor_behavrs) {
			if(!cJSON_IsObject(abnor_behavrs_local)) {
				printf(
					"event_notification_parseFromJSON() failed [abnor_behavrs]");
				goto end;
			}
			abnormal_behaviour_t *abnor_behavrsItem =
				abnormal_behaviour_parseFromJSON(
					abnor_behavrs_local);
			if(!abnor_behavrsItem) {
				printf("No abnor_behavrsItem");
				goto end;
			}
			list_add(abnor_behavrsList, abnor_behavrsItem);
		}
	}

	nw_perfs = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                            "nwPerfs");
	if(nw_perfs) {
		cJSON *nw_perfs_local = NULL;
		if(!cJSON_IsArray(nw_perfs)) {
			printf(
				"event_notification_parseFromJSON() failed [nw_perfs]");
			goto end;
		}

		nw_perfsList = list_create();

		cJSON_ArrayForEach(nw_perfs_local, nw_perfs) {
			if(!cJSON_IsObject(nw_perfs_local)) {
				printf(
					"event_notification_parseFromJSON() failed [nw_perfs]");
				goto end;
			}
			network_perf_info_t *nw_perfsItem =
				network_perf_info_parseFromJSON(nw_perfs_local);
			if(!nw_perfsItem) {
				printf("No nw_perfsItem");
				goto end;
			}
			list_add(nw_perfsList, nw_perfsItem);
		}
	}

	dn_perf_infos = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                                 "dnPerfInfos");
	if(dn_perf_infos) {
		cJSON *dn_perf_infos_local = NULL;
		if(!cJSON_IsArray(dn_perf_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [dn_perf_infos]");
			goto end;
		}

		dn_perf_infosList = list_create();

		cJSON_ArrayForEach(dn_perf_infos_local, dn_perf_infos) {
			if(!cJSON_IsObject(dn_perf_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [dn_perf_infos]");
				goto end;
			}
			dn_perf_info_t *dn_perf_infosItem =
				dn_perf_info_parseFromJSON(dn_perf_infos_local);
			if(!dn_perf_infosItem) {
				printf("No dn_perf_infosItem");
				goto end;
			}
			list_add(dn_perf_infosList, dn_perf_infosItem);
		}
	}

	disper_infos = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                                "disperInfos");
	if(disper_infos) {
		cJSON *disper_infos_local = NULL;
		if(!cJSON_IsArray(disper_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [disper_infos]");
			goto end;
		}

		disper_infosList = list_create();

		cJSON_ArrayForEach(disper_infos_local, disper_infos) {
			if(!cJSON_IsObject(disper_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [disper_infos]");
				goto end;
			}
			dispersion_info_t *disper_infosItem =
				dispersion_info_parseFromJSON(disper_infos_local);
			if(!disper_infosItem) {
				printf("No disper_infosItem");
				goto end;
			}
			list_add(disper_infosList, disper_infosItem);
		}
	}

	red_trans_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "redTransInfos");
	if(red_trans_infos) {
		cJSON *red_trans_infos_local = NULL;
		if(!cJSON_IsArray(red_trans_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [red_trans_infos]");
			goto end;
		}

		red_trans_infosList = list_create();

		cJSON_ArrayForEach(red_trans_infos_local, red_trans_infos) {
			if(!cJSON_IsObject(red_trans_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [red_trans_infos]");
				goto end;
			}
			redundant_transmission_exp_info_t *red_trans_infosItem =
				redundant_transmission_exp_info_parseFromJSON(
					red_trans_infos_local);
			if(!red_trans_infosItem) {
				printf("No red_trans_infosItem");
				goto end;
			}
			list_add(red_trans_infosList, red_trans_infosItem);
		}
	}

	wlan_infos = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                              "wlanInfos");
	if(wlan_infos) {
		cJSON *wlan_infos_local = NULL;
		if(!cJSON_IsArray(wlan_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [wlan_infos]");
			goto end;
		}

		wlan_infosList = list_create();

		cJSON_ArrayForEach(wlan_infos_local, wlan_infos) {
			if(!cJSON_IsObject(wlan_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [wlan_infos]");
				goto end;
			}
			wlan_performance_info_t *wlan_infosItem =
				wlan_performance_info_parseFromJSON(
					wlan_infos_local);
			if(!wlan_infosItem) {
				printf("No wlan_infosItem");
				goto end;
			}
			list_add(wlan_infosList, wlan_infosItem);
		}
	}

	smcc_exps = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                             "smccExps");
	if(smcc_exps) {
		cJSON *smcc_exps_local = NULL;
		if(!cJSON_IsArray(smcc_exps)) {
			printf(
				"event_notification_parseFromJSON() failed [smcc_exps]");
			goto end;
		}

		smcc_expsList = list_create();

		cJSON_ArrayForEach(smcc_exps_local, smcc_exps) {
			if(!cJSON_IsObject(smcc_exps_local)) {
				printf(
					"event_notification_parseFromJSON() failed [smcc_exps]");
				goto end;
			}
			smcce_info_t *smcc_expsItem = smcce_info_parseFromJSON(
				smcc_exps_local);
			if(!smcc_expsItem) {
				printf("No smcc_expsItem");
				goto end;
			}
			list_add(smcc_expsList, smcc_expsItem);
		}
	}

	pdu_ses_traf_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "pduSesTrafInfos");
	if(pdu_ses_traf_infos) {
		cJSON *pdu_ses_traf_infos_local = NULL;
		if(!cJSON_IsArray(pdu_ses_traf_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [pdu_ses_traf_infos]");
			goto end;
		}

		pdu_ses_traf_infosList = list_create();

		cJSON_ArrayForEach(pdu_ses_traf_infos_local,
		                   pdu_ses_traf_infos) {
			if(!cJSON_IsObject(pdu_ses_traf_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [pdu_ses_traf_infos]");
				goto end;
			}
			pdu_ses_traffic_info_t *pdu_ses_traf_infosItem =
				pdu_ses_traffic_info_parseFromJSON(
					pdu_ses_traf_infos_local);
			if(!pdu_ses_traf_infosItem) {
				printf("No pdu_ses_traf_infosItem");
				goto end;
			}
			list_add(pdu_ses_traf_infosList,
			         pdu_ses_traf_infosItem);
		}
	}

	data_vl_trns_tm_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "dataVlTrnsTmInfos");
	if(data_vl_trns_tm_infos) {
		cJSON *data_vl_trns_tm_infos_local = NULL;
		if(!cJSON_IsArray(data_vl_trns_tm_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [data_vl_trns_tm_infos]");
			goto end;
		}

		data_vl_trns_tm_infosList = list_create();

		cJSON_ArrayForEach(data_vl_trns_tm_infos_local,
		                   data_vl_trns_tm_infos) {
			if(!cJSON_IsObject(data_vl_trns_tm_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [data_vl_trns_tm_infos]");
				goto end;
			}
			e2e_data_vol_trans_time_info_t *
			        data_vl_trns_tm_infosItem =
				e2e_data_vol_trans_time_info_parseFromJSON(
					data_vl_trns_tm_infos_local);
			if(!data_vl_trns_tm_infosItem) {
				printf("No data_vl_trns_tm_infosItem");
				goto end;
			}
			list_add(data_vl_trns_tm_infosList,
			         data_vl_trns_tm_infosItem);
		}
	}

	accu_info = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                             "accuInfo");
	if(accu_info) {
		accu_info_local_nonprim =
			accuracy_info_parseFromJSON(accu_info);
		if(!accu_info_local_nonprim) {
			printf("accuracy_info_parseFromJSON failed [accu_info]");
			goto end;
		}
	}

	cancel_accu_ind = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "cancelAccuInd");
	if(cancel_accu_ind) {
		if(!cJSON_IsBool(cancel_accu_ind)) {
			printf(
				"event_notification_parseFromJSON() failed [cancel_accu_ind]");
			goto end;
		}
	}

	pause_ind = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                             "pauseInd");
	if(pause_ind) {
		if(!cJSON_IsBool(pause_ind)) {
			printf(
				"event_notification_parseFromJSON() failed [pause_ind]");
			goto end;
		}
	}

	resume_ind = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                              "resumeInd");
	if(resume_ind) {
		if(!cJSON_IsBool(resume_ind)) {
			printf(
				"event_notification_parseFromJSON() failed [resume_ind]");
			goto end;
		}
	}

	mov_behav_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "movBehavInfos");
	if(mov_behav_infos) {
		cJSON *mov_behav_infos_local = NULL;
		if(!cJSON_IsArray(mov_behav_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [mov_behav_infos]");
			goto end;
		}

		mov_behav_infosList = list_create();

		cJSON_ArrayForEach(mov_behav_infos_local, mov_behav_infos) {
			if(!cJSON_IsObject(mov_behav_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [mov_behav_infos]");
				goto end;
			}
			mov_behav_info_t *mov_behav_infosItem =
				mov_behav_info_parseFromJSON(
					mov_behav_infos_local);
			if(!mov_behav_infosItem) {
				printf("No mov_behav_infosItem");
				goto end;
			}
			list_add(mov_behav_infosList, mov_behav_infosItem);
		}
	}

	loc_acc_infos = cJSON_GetObjectItemCaseSensitive(event_notificationJSON,
	                                                 "locAccInfos");
	if(loc_acc_infos) {
		cJSON *loc_acc_infos_local = NULL;
		if(!cJSON_IsArray(loc_acc_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [loc_acc_infos]");
			goto end;
		}

		loc_acc_infosList = list_create();

		cJSON_ArrayForEach(loc_acc_infos_local, loc_acc_infos) {
			if(!cJSON_IsObject(loc_acc_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [loc_acc_infos]");
				goto end;
			}
			loc_accuracy_info_t *loc_acc_infosItem =
				loc_accuracy_info_parseFromJSON(
					loc_acc_infos_local);
			if(!loc_acc_infosItem) {
				printf("No loc_acc_infosItem");
				goto end;
			}
			list_add(loc_acc_infosList, loc_acc_infosItem);
		}
	}

	rel_prox_infos = cJSON_GetObjectItemCaseSensitive(
		event_notificationJSON, "relProxInfos");
	if(rel_prox_infos) {
		cJSON *rel_prox_infos_local = NULL;
		if(!cJSON_IsArray(rel_prox_infos)) {
			printf(
				"event_notification_parseFromJSON() failed [rel_prox_infos]");
			goto end;
		}

		rel_prox_infosList = list_create();

		cJSON_ArrayForEach(rel_prox_infos_local, rel_prox_infos) {
			if(!cJSON_IsObject(rel_prox_infos_local)) {
				printf(
					"event_notification_parseFromJSON() failed [rel_prox_infos]");
				goto end;
			}
			rel_prox_info_t *rel_prox_infosItem =
				rel_prox_info_parseFromJSON(rel_prox_infos_local);
			if(!rel_prox_infosItem) {
				printf("No rel_prox_infosItem");
				goto end;
			}
			list_add(rel_prox_infosList, rel_prox_infosItem);
		}
	}

	event_notification_local_var = event_notification_create(
		event_local_nonprim,
		start &&
		!cJSON_IsNull(start) ? strdup(start->valuestring) : NULL,
		expiry &&
		!cJSON_IsNull(expiry) ? strdup(expiry->valuestring) : NULL,
		time_stamp_gen &&
		!cJSON_IsNull(time_stamp_gen) ? strdup(time_stamp_gen->
		                                       valuestring) : NULL,
		fail_notify_code ? fail_notify_code_local_nonprim : NULL,
		rv_wait_time ? true : false,
		rv_wait_time ? rv_wait_time->valuedouble : 0,
		ana_meta_info ? ana_meta_info_local_nonprim : NULL,
		nf_load_level_infos ? nf_load_level_infosList : NULL,
		nsi_load_level_infos ? nsi_load_level_infosList : NULL,
		pfd_determ_infos ? pfd_determ_infosList : NULL,
		slice_load_level_info ? slice_load_level_info_local_nonprim : NULL,
		svc_exps ? svc_expsList : NULL,
		qos_sustain_infos ? qos_sustain_infosList : NULL,
		ue_comms ? ue_commsList : NULL,
		ue_mobs ? ue_mobsList : NULL,
		user_data_cong_infos ? user_data_cong_infosList : NULL,
		abnor_behavrs ? abnor_behavrsList : NULL,
		nw_perfs ? nw_perfsList : NULL,
		dn_perf_infos ? dn_perf_infosList : NULL,
		disper_infos ? disper_infosList : NULL,
		red_trans_infos ? red_trans_infosList : NULL,
		wlan_infos ? wlan_infosList : NULL,
		smcc_exps ? smcc_expsList : NULL,
		pdu_ses_traf_infos ? pdu_ses_traf_infosList : NULL,
		data_vl_trns_tm_infos ? data_vl_trns_tm_infosList : NULL,
		accu_info ? accu_info_local_nonprim : NULL,
		cancel_accu_ind ? true : false,
		cancel_accu_ind ? cancel_accu_ind->valueint : 0,
		pause_ind ? true : false,
		pause_ind ? pause_ind->valueint : 0,
		resume_ind ? true : false,
		resume_ind ? resume_ind->valueint : 0,
		mov_behav_infos ? mov_behav_infosList : NULL,
		loc_acc_infos ? loc_acc_infosList : NULL,
		rel_prox_infos ? rel_prox_infosList : NULL
		);

	return event_notification_local_var;
end:
	if(event_local_nonprim) {
		nwdaf_event_free(event_local_nonprim);
		event_local_nonprim = NULL;
	}
	if(fail_notify_code_local_nonprim) {
		nwdaf_failure_code_free(fail_notify_code_local_nonprim);
		fail_notify_code_local_nonprim = NULL;
	}
	if(ana_meta_info_local_nonprim) {
		analytics_metadata_info_free(ana_meta_info_local_nonprim);
		ana_meta_info_local_nonprim = NULL;
	}
	if(nf_load_level_infosList) {
		list_for_each(nf_load_level_infosList, node) {
			nf_load_level_information_free(node->data);
		}
		list_free(nf_load_level_infosList);
		nf_load_level_infosList = NULL;
	}
	if(nsi_load_level_infosList) {
		list_for_each(nsi_load_level_infosList, node) {
			nsi_load_level_info_free(node->data);
		}
		list_free(nsi_load_level_infosList);
		nsi_load_level_infosList = NULL;
	}
	if(pfd_determ_infosList) {
		list_for_each(pfd_determ_infosList, node) {
			pfd_determination_info_free(node->data);
		}
		list_free(pfd_determ_infosList);
		pfd_determ_infosList = NULL;
	}
	if(slice_load_level_info_local_nonprim) {
		slice_load_level_information_free(
			slice_load_level_info_local_nonprim);
		slice_load_level_info_local_nonprim = NULL;
	}
	if(svc_expsList) {
		list_for_each(svc_expsList, node) {
			service_experience_info_free(node->data);
		}
		list_free(svc_expsList);
		svc_expsList = NULL;
	}
	if(qos_sustain_infosList) {
		list_for_each(qos_sustain_infosList, node) {
			qos_sustainability_info_free(node->data);
		}
		list_free(qos_sustain_infosList);
		qos_sustain_infosList = NULL;
	}
	if(ue_commsList) {
		list_for_each(ue_commsList, node) {
			ue_communication_free(node->data);
		}
		list_free(ue_commsList);
		ue_commsList = NULL;
	}
	if(ue_mobsList) {
		list_for_each(ue_mobsList, node) {
			ue_mobility_free(node->data);
		}
		list_free(ue_mobsList);
		ue_mobsList = NULL;
	}
	if(user_data_cong_infosList) {
		list_for_each(user_data_cong_infosList, node) {
			user_data_congestion_info_free(node->data);
		}
		list_free(user_data_cong_infosList);
		user_data_cong_infosList = NULL;
	}
	if(abnor_behavrsList) {
		list_for_each(abnor_behavrsList, node) {
			abnormal_behaviour_free(node->data);
		}
		list_free(abnor_behavrsList);
		abnor_behavrsList = NULL;
	}
	if(nw_perfsList) {
		list_for_each(nw_perfsList, node) {
			network_perf_info_free(node->data);
		}
		list_free(nw_perfsList);
		nw_perfsList = NULL;
	}
	if(dn_perf_infosList) {
		list_for_each(dn_perf_infosList, node) {
			dn_perf_info_free(node->data);
		}
		list_free(dn_perf_infosList);
		dn_perf_infosList = NULL;
	}
	if(disper_infosList) {
		list_for_each(disper_infosList, node) {
			dispersion_info_free(node->data);
		}
		list_free(disper_infosList);
		disper_infosList = NULL;
	}
	if(red_trans_infosList) {
		list_for_each(red_trans_infosList, node) {
			redundant_transmission_exp_info_free(node->data);
		}
		list_free(red_trans_infosList);
		red_trans_infosList = NULL;
	}
	if(wlan_infosList) {
		list_for_each(wlan_infosList, node) {
			wlan_performance_info_free(node->data);
		}
		list_free(wlan_infosList);
		wlan_infosList = NULL;
	}
	if(smcc_expsList) {
		list_for_each(smcc_expsList, node) {
			smcce_info_free(node->data);
		}
		list_free(smcc_expsList);
		smcc_expsList = NULL;
	}
	if(pdu_ses_traf_infosList) {
		list_for_each(pdu_ses_traf_infosList, node) {
			pdu_ses_traffic_info_free(node->data);
		}
		list_free(pdu_ses_traf_infosList);
		pdu_ses_traf_infosList = NULL;
	}
	if(data_vl_trns_tm_infosList) {
		list_for_each(data_vl_trns_tm_infosList, node) {
			e2e_data_vol_trans_time_info_free(node->data);
		}
		list_free(data_vl_trns_tm_infosList);
		data_vl_trns_tm_infosList = NULL;
	}
	if(accu_info_local_nonprim) {
		accuracy_info_free(accu_info_local_nonprim);
		accu_info_local_nonprim = NULL;
	}
	if(mov_behav_infosList) {
		list_for_each(mov_behav_infosList, node) {
			mov_behav_info_free(node->data);
		}
		list_free(mov_behav_infosList);
		mov_behav_infosList = NULL;
	}
	if(loc_acc_infosList) {
		list_for_each(loc_acc_infosList, node) {
			loc_accuracy_info_free(node->data);
		}
		list_free(loc_acc_infosList);
		loc_acc_infosList = NULL;
	}
	if(rel_prox_infosList) {
		list_for_each(rel_prox_infosList, node) {
			rel_prox_info_free(node->data);
		}
		list_free(rel_prox_infosList);
		rel_prox_infosList = NULL;
	}
	return NULL;
}

event_notification_t *event_notification_copy(event_notification_t	*dst,
                                              event_notification_t	*src) {
	cJSON *item = NULL;
	char *content = NULL;

	item = event_notification_convertToJSON(src);
	if(!item) {
		printf("event_notification_convertToJSON() failed");
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

	event_notification_free(dst);
	dst = event_notification_parseFromJSON(item);
	cJSON_Delete(item);

	return dst;
}
