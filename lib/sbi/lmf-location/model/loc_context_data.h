/*
 * loc_context_data.h
 *
 * Information within Transfer Location Context Request.
 */

#ifndef _loc_context_data_H_
#define _loc_context_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "area_event_info.h"
#include "ecgi.h"
#include "event_report_message.h"
#include "event_reporting_status.h"
#include "guami.h"
#include "indoor_outdoor_ind.h"
#include "ldr_type.h"
#include "location_qo_s.h"
#include "los_nlos_measure_ind.h"
#include "motion_event_info.h"
#include "ncgi.h"
#include "periodic_event_info.h"
#include "supported_gad_shapes.h"
#include "ue_location_info.h"
#include "up_cum_evt_rpt_criteria.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_context_data_s loc_context_data_t;
typedef struct loc_context_data_s {
	char *amf_id;
	struct location_qo_s_s *location_qo_s;
	list_t *supported_gad_shapes;
	char *supi;
	char *gpsi;
	ldr_type_e ldr_type;
	char *hgmlc_call_back_uri;
	char *ldr_reference;
	struct periodic_event_info_s *periodic_event_info;
	struct area_event_info_s *area_event_info;
	struct motion_event_info_s *motion_event_info;
	struct event_report_message_s *event_report_message;
	struct event_reporting_status_s *event_reporting_status;
	struct ue_location_info_s *ue_location_info;
	bool is_c_io_t5_gs_optimisation;
	int c_io_t5_gs_optimisation;
	struct ecgi_s *ecgi;
	struct ncgi_s *ncgi;
	struct guami_s *guami;
	char *supported_features;
	char *ue_positioning_cap;
	char *scheduled_loc_time;
	indoor_outdoor_ind_e indoor_outdoor_ind;
	los_nlos_measure_ind_e los_nlos_measure_ind;
	struct up_cum_evt_rpt_criteria_s *up_cum_evt_rpt_criteria;
} loc_context_data_t;

loc_context_data_t *loc_context_data_create(char *amf_id,
                                            location_qo_s_t *location_qo_s,
                                            list_t *supported_gad_shapes,
                                            char *supi, char *gpsi,
                                            ldr_type_e ldr_type,
                                            char *hgmlc_call_back_uri,
                                            char *ldr_reference,
                                            periodic_event_info_t *periodic_event_info, area_event_info_t *area_event_info, motion_event_info_t *motion_event_info, event_report_message_t *event_report_message, event_reporting_status_t *event_reporting_status, ue_location_info_t *ue_location_info, bool is_c_io_t5_gs_optimisation, int c_io_t5_gs_optimisation, ecgi_t *ecgi, ncgi_t *ncgi, guami_t *guami, char *supported_features, char *ue_positioning_cap, char *scheduled_loc_time, indoor_outdoor_ind_e indoor_outdoor_ind, los_nlos_measure_ind_e los_nlos_measure_ind, up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria);
void loc_context_data_free(loc_context_data_t *loc_context_data);
loc_context_data_t *loc_context_data_parseFromJSON(cJSON *loc_context_dataJSON);
cJSON *loc_context_data_convertToJSON(loc_context_data_t *loc_context_data);
loc_context_data_t *loc_context_data_copy(loc_context_data_t	*dst,
                                          loc_context_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_context_data_H_ */
