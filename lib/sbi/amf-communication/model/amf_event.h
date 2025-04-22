/*
 * amf_event.h
 *
 * Describes an event to be subscribed
 */

#ifndef _amf_event_H_
#define _amf_event_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "amf_event_area.h"
#include "amf_event_type.h"
#include "dispersion_area.h"
#include "ext_snssai.h"
#include "location_filter.h"
#include "presence_info.h"
#include "reachability_filter.h"
#include "snssai_dnn_item.h"
#include "target_area.h"
#include "traffic_descriptor.h"
#include "ue_in_area_filter.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct amf_event_s amf_event_t;
typedef struct amf_event_s {
	struct amf_event_type_s *type;
	bool is_immediate_flag;
	int immediate_flag;
	list_t *area_list;
	list_t *location_filter_list;
	bool is_ref_id;
	int ref_id;
	list_t *traffic_descriptor_list;
	bool is_report_ue_reachable;
	int report_ue_reachable;
	struct reachability_filter_s *reachability_filter;
	bool is_udm_detect_ind;
	int udm_detect_ind;
	bool is_max_reports;
	int max_reports;
	list_t *presence_info_list;
	bool is_max_response_time;
	int max_response_time;
	struct target_area_s *target_area;
	list_t *snssai_filter;
	struct ue_in_area_filter_s *ue_in_area_filter;
	bool is_min_interval;
	int min_interval;
	char *next_report;
	bool is_idle_status_ind;
	int idle_status_ind;
	struct dispersion_area_s *dispersion_area;
	char *next_periodic_report_time;
	bool is_adjust_ao_ion_ra;
	int adjust_ao_ion_ra;
	bool is_ran_timing_synchro_status_change;
	int ran_timing_synchro_status_change;
	list_t *notify_for_supi_list;
	list_t *notify_for_group_list;
	list_t *notify_for_snssai_dnn_list;
} amf_event_t;

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
                              list_t *notify_for_snssai_dnn_list);
void amf_event_free(amf_event_t *amf_event);
amf_event_t *amf_event_parseFromJSON(cJSON *amf_eventJSON);
cJSON *amf_event_convertToJSON(amf_event_t *amf_event);
amf_event_t *amf_event_copy(amf_event_t *dst, amf_event_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _amf_event_H_ */
