/*
 * event_subscription.h
 *
 * Represents a subscription to a single event.
 */

#ifndef _event_subscription_H_
#define _event_subscription_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy_req.h"
#include "addr_fqdn.h"
#include "analytics_feedback_info.h"
#include "analytics_subset.h"
#include "bw_requirement.h"
#include "dispersion_requirement.h"
#include "dn_performance_req.h"
#include "e2e_data_vol_trans_time_req.h"
#include "event_reporting_requirement.h"
#include "exception.h"
#include "expected_analytics_type.h"
#include "expected_ue_behaviour_data.h"
#include "geo_location.h"
#include "geographical_area.h"
#include "loc_accuracy_req.h"
#include "loc_info_granularity.h"
#include "location_orientation.h"
#include "matching_direction.h"
#include "mov_behav_req.h"
#include "network_area_info.h"
#include "network_perf_requirement.h"
#include "nf_type.h"
#include "notification_method.h"
#include "nsi_id_info.h"
#include "nwdaf_event.h"
#include "pdu_ses_traffic_req.h"
#include "pdu_session_info_1.h"
#include "qos_requirement.h"
#include "rat_freq_information.h"
#include "redundant_transmission_exp_req.h"
#include "rel_prox_req.h"
#include "retainability_threshold.h"
#include "roaming_info.h"
#include "snssai.h"
#include "target_ue_information.h"
#include "threshold_level.h"
#include "ue_comm_req.h"
#include "ue_mobility_req.h"
#include "upf_information.h"
#include "user_data_con_order_crit.h"
#include "wlan_performance_req.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct event_subscription_s event_subscription_t;
typedef struct event_subscription_s {
	bool is_any_slice;
	int any_slice;
	list_t *app_ids;
	list_t *deviations;
	list_t *dnns;
	list_t *dnais;
	struct nwdaf_event_s *event;
	struct event_reporting_requirement_s *extra_report_req;
	list_t *ladn_dnns;
	bool is_load_level_threshold;
	int load_level_threshold;
	struct notification_method_s *notification_method;
	struct matching_direction_s *matching_dir;
	list_t *nf_load_lvl_thds;
	list_t *nf_instance_ids;
	list_t *nf_set_ids;
	list_t *nf_types;
	struct network_area_info_s *network_area;
	struct geo_location_s *location;
	bool is_temporal_gran_size;
	int temporal_gran_size;
	bool is_spatial_gran_size_ta;
	int spatial_gran_size_ta;
	bool is_spatial_gran_size_cell;
	int spatial_gran_size_cell;
	list_t *fine_gran_areas;
	list_t *visited_areas;
	bool is_max_top_app_ul_nbr;
	int max_top_app_ul_nbr;
	bool is_max_top_app_dl_nbr;
	int max_top_app_dl_nbr;
	list_t *nsi_id_infos;
	list_t *nsi_level_thrds;
	struct qos_requirement_s *qos_requ;
	list_t *qos_flow_ret_thds;
	list_t *ran_ue_throu_thds;
	bool is_repetition_period;
	int repetition_period;
	list_t *snssaia;
	struct target_ue_information_s *tgt_ue;
	struct roaming_info_s *roaming_info;
	list_t *cong_thresholds;
	list_t *nw_perf_requs;
	list_t *ue_comm_reqs;
	list_t *ue_mobility_reqs;
	struct user_data_con_order_crit_s *user_data_con_order_cri;
	list_t *bw_requs;
	list_t *excep_requs;
	struct expected_analytics_type_s *expt_ana_type;
	struct expected_ue_behaviour_data_s *expt_ue_behav;
	list_t *rat_freqs;
	list_t *list_of_ana_subsets;
	list_t *disper_reqs;
	list_t *red_trans_reqs;
	list_t *wlan_reqs;
	struct upf_information_s *upf_info;
	list_t *app_server_addrs;
	list_t *dn_perf_reqs;
	list_t *pdu_ses_infos;
	char *use_case_cxt;
	list_t *pdu_ses_traf_reqs;
	list_t *loc_acc_reqs;
	struct loc_info_granularity_s *loc_granularity;
	struct location_orientation_s *loc_orientation;
	list_t *data_vl_trns_tm_rqs;
	struct accuracy_req_s *accu_req;
	bool is_pause_flg;
	int pause_flg;
	bool is_resume_flg;
	int resume_flg;
	list_t *mov_behav_reqs;
	list_t *rel_prox_reqs;
	struct analytics_feedback_info_s *feedback;
} event_subscription_t;

event_subscription_t *event_subscription_create(bool is_any_slice,
                                                int any_slice, list_t *app_ids,
                                                list_t *deviations,
                                                list_t *dnns, list_t *dnais,
                                                nwdaf_event_t *event,
                                                event_reporting_requirement_t *extra_report_req, list_t *ladn_dnns, bool is_load_level_threshold, int load_level_threshold, notification_method_t *notification_method, matching_direction_t *matching_dir, list_t *nf_load_lvl_thds, list_t *nf_instance_ids, list_t *nf_set_ids, list_t *nf_types, network_area_info_t *network_area, geo_location_t *location, bool is_temporal_gran_size, int temporal_gran_size, bool is_spatial_gran_size_ta, int spatial_gran_size_ta, bool is_spatial_gran_size_cell, int spatial_gran_size_cell, list_t *fine_gran_areas, list_t *visited_areas, bool is_max_top_app_ul_nbr, int max_top_app_ul_nbr, bool is_max_top_app_dl_nbr, int max_top_app_dl_nbr, list_t *nsi_id_infos, list_t *nsi_level_thrds, qos_requirement_t *qos_requ, list_t *qos_flow_ret_thds, list_t *ran_ue_throu_thds, bool is_repetition_period, int repetition_period, list_t *snssaia, target_ue_information_t *tgt_ue, roaming_info_t *roaming_info, list_t *cong_thresholds, list_t *nw_perf_requs, list_t *ue_comm_reqs, list_t *ue_mobility_reqs, user_data_con_order_crit_t *user_data_con_order_cri, list_t *bw_requs, list_t *excep_requs, expected_analytics_type_t *expt_ana_type, expected_ue_behaviour_data_t *expt_ue_behav, list_t *rat_freqs, list_t *list_of_ana_subsets, list_t *disper_reqs, list_t *red_trans_reqs, list_t *wlan_reqs, upf_information_t *upf_info, list_t *app_server_addrs, list_t *dn_perf_reqs, list_t *pdu_ses_infos, char *use_case_cxt, list_t *pdu_ses_traf_reqs, list_t *loc_acc_reqs, loc_info_granularity_t *loc_granularity, location_orientation_t *loc_orientation, list_t *data_vl_trns_tm_rqs, accuracy_req_t *accu_req, bool is_pause_flg, int pause_flg, bool is_resume_flg, int resume_flg, list_t *mov_behav_reqs, list_t *rel_prox_reqs, analytics_feedback_info_t *feedback);
void event_subscription_free(event_subscription_t *event_subscription);
event_subscription_t *event_subscription_parseFromJSON(
	cJSON *event_subscriptionJSON);
cJSON *event_subscription_convertToJSON(
	event_subscription_t *event_subscription);
event_subscription_t *event_subscription_copy(event_subscription_t	*dst,
                                              event_subscription_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _event_subscription_H_ */
