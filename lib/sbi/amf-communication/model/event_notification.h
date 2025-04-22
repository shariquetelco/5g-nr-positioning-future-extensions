/*
 * event_notification.h
 *
 * Represents a notification on events that occurred.
 */

#ifndef _event_notification_H_
#define _event_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "abnormal_behaviour.h"
#include "accuracy_info.h"
#include "analytics_metadata_info.h"
#include "dispersion_info.h"
#include "dn_perf_info.h"
#include "e2e_data_vol_trans_time_info.h"
#include "loc_accuracy_info.h"
#include "mov_behav_info.h"
#include "network_perf_info.h"
#include "nf_load_level_information.h"
#include "nsi_load_level_info.h"
#include "nwdaf_event.h"
#include "nwdaf_failure_code.h"
#include "pdu_ses_traffic_info.h"
#include "pfd_determination_info.h"
#include "qos_sustainability_info.h"
#include "redundant_transmission_exp_info.h"
#include "rel_prox_info.h"
#include "service_experience_info.h"
#include "slice_load_level_information.h"
#include "smcce_info.h"
#include "ue_communication.h"
#include "ue_mobility.h"
#include "user_data_congestion_info.h"
#include "wlan_performance_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct event_notification_s event_notification_t;
typedef struct event_notification_s {
	struct nwdaf_event_s *event;
	char *start;
	char *expiry;
	char *time_stamp_gen;
	struct nwdaf_failure_code_s *fail_notify_code;
	bool is_rv_wait_time;
	int rv_wait_time;
	struct analytics_metadata_info_s *ana_meta_info;
	list_t *nf_load_level_infos;
	list_t *nsi_load_level_infos;
	list_t *pfd_determ_infos;
	struct slice_load_level_information_s *slice_load_level_info;
	list_t *svc_exps;
	list_t *qos_sustain_infos;
	list_t *ue_comms;
	list_t *ue_mobs;
	list_t *user_data_cong_infos;
	list_t *abnor_behavrs;
	list_t *nw_perfs;
	list_t *dn_perf_infos;
	list_t *disper_infos;
	list_t *red_trans_infos;
	list_t *wlan_infos;
	list_t *smcc_exps;
	list_t *pdu_ses_traf_infos;
	list_t *data_vl_trns_tm_infos;
	struct accuracy_info_s *accu_info;
	bool is_cancel_accu_ind;
	int cancel_accu_ind;
	bool is_pause_ind;
	int pause_ind;
	bool is_resume_ind;
	int resume_ind;
	list_t *mov_behav_infos;
	list_t *loc_acc_infos;
	list_t *rel_prox_infos;
} event_notification_t;

event_notification_t *event_notification_create(nwdaf_event_t *event,
                                                char *start, char *expiry,
                                                char *time_stamp_gen,
                                                nwdaf_failure_code_t *fail_notify_code, bool is_rv_wait_time, int rv_wait_time, analytics_metadata_info_t *ana_meta_info, list_t *nf_load_level_infos, list_t *nsi_load_level_infos, list_t *pfd_determ_infos, slice_load_level_information_t *slice_load_level_info, list_t *svc_exps, list_t *qos_sustain_infos, list_t *ue_comms, list_t *ue_mobs, list_t *user_data_cong_infos, list_t *abnor_behavrs, list_t *nw_perfs, list_t *dn_perf_infos, list_t *disper_infos, list_t *red_trans_infos, list_t *wlan_infos, list_t *smcc_exps, list_t *pdu_ses_traf_infos, list_t *data_vl_trns_tm_infos, accuracy_info_t *accu_info, bool is_cancel_accu_ind, int cancel_accu_ind, bool is_pause_ind, int pause_ind, bool is_resume_ind, int resume_ind, list_t *mov_behav_infos, list_t *loc_acc_infos, list_t *rel_prox_infos);
void event_notification_free(event_notification_t *event_notification);
event_notification_t *event_notification_parseFromJSON(
	cJSON *event_notificationJSON);
cJSON *event_notification_convertToJSON(
	event_notification_t *event_notification);
event_notification_t *event_notification_copy(event_notification_t	*dst,
                                              event_notification_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _event_notification_H_ */
