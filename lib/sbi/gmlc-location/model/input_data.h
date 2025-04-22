/*
 * input_data.h
 *
 * Contains the input parameters in ProvideLocation service operation
 */

#ifndef _input_data_H_
#define _input_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "area_event_info_ext.h"
#include "external_client_type.h"
#include "geographic_area.h"
#include "input_data_reporting_ind.h"
#include "integrity_requirements.h"
#include "lcs_priority.h"
#include "ldr_type.h"
#include "location_qo_s.h"
#include "location_type_requested.h"
#include "lp_hap_type.h"
#include "mapped_location_qo_s_eps.h"
#include "motion_event_info.h"
#include "periodic_event_info.h"
#include "ranging_sl_result.h"
#include "related_ue.h"
#include "supported_gad_shapes.h"
#include "ue_privacy_requirements.h"
#include "up_loc_rep_info_af.h"
#include "velocity_requested.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct input_data_s input_data_t;
typedef struct input_data_s {
	char *gpsi;
	char *supi;
	char *app_layer_id;
	char *ext_group_id;
	char *int_group_id;
	external_client_type_e external_client_type;
	struct location_qo_s_s *location_qo_s;
	list_t *supported_gad_shapes;
	char *service_identity;
	list_t *service_coverage;
	ldr_type_e ldr_type;
	struct periodic_event_info_s *periodic_event_info;
	struct area_event_info_ext_s *area_event_info;
	struct motion_event_info_s *motion_event_info;
	char *ldr_reference;
	char *hgmlc_call_back_uri;
	char *event_notification_uri;
	char *external_client_identification;
	char *af_id;
	struct ue_privacy_requirements_s *ue_privacy_requirements;
	bool is_lcs_service_type;
	int lcs_service_type;
	velocity_requested_e velocity_requested;
	lcs_priority_e priority;
	location_type_requested_e location_type_requested;
	bool is_maximum_age_of_location_estimate;
	int maximum_age_of_location_estimate;
	char *amf_id;
	char *code_word;
	char *scheduled_loc_time;
	bool is_reliable_loc_req;
	int reliable_loc_req;
	char *serving_lmf_id;
	struct lp_hap_type_s *lp_hap_type;
	struct geographic_area_s *evt_rpt_expected_area;
	struct input_data_reporting_ind_s *reporting_ind;
	struct integrity_requirements_s *integrity_requirements;
	struct up_loc_rep_info_af_s *up_loc_rep_info_af;
	list_t *requested_ranging_sl_result;
	list_t *related_ues;
	struct mapped_location_qo_s_eps_s *mapped_qo_s_eps;
	bool is_coordinate_id;
	int coordinate_id;
} input_data_t;

input_data_t *input_data_create(char *gpsi, char *supi, char *app_layer_id,
                                char *ext_group_id, char *int_group_id,
                                external_client_type_e external_client_type,
                                location_qo_s_t *location_qo_s,
                                list_t *supported_gad_shapes,
                                char *service_identity,
                                list_t *service_coverage, ldr_type_e ldr_type,
                                periodic_event_info_t *periodic_event_info,
                                area_event_info_ext_t *area_event_info,
                                motion_event_info_t *motion_event_info,
                                char *ldr_reference, char *hgmlc_call_back_uri,
                                char *event_notification_uri,
                                char *external_client_identification,
                                char *af_id,
                                ue_privacy_requirements_t *ue_privacy_requirements, bool is_lcs_service_type, int lcs_service_type, velocity_requested_e velocity_requested, lcs_priority_e priority, location_type_requested_e location_type_requested, bool is_maximum_age_of_location_estimate, int maximum_age_of_location_estimate, char *amf_id, char *code_word, char *scheduled_loc_time, bool is_reliable_loc_req, int reliable_loc_req, char *serving_lmf_id, lp_hap_type_t *lp_hap_type, geographic_area_t *evt_rpt_expected_area, input_data_reporting_ind_t *reporting_ind, integrity_requirements_t *integrity_requirements, up_loc_rep_info_af_t *up_loc_rep_info_af, list_t *requested_ranging_sl_result, list_t *related_ues, mapped_location_qo_s_eps_t *mapped_qo_s_eps, bool is_coordinate_id, int coordinate_id);
void input_data_free(input_data_t *input_data);
input_data_t *input_data_parseFromJSON(cJSON *input_dataJSON);
cJSON *input_data_convertToJSON(input_data_t *input_data);
input_data_t *input_data_copy(input_data_t *dst, input_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _input_data_H_ */
