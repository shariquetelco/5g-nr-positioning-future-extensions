/*
 * input_data.h
 *
 * Information within Determine Location Request.
 */

#ifndef _input_data_H_
#define _input_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "additional_ue_info.h"
#include "area_event_info.h"
#include "ecgi.h"
#include "external_client_type.h"
#include "input_data_reporting_ind.h"
#include "integrity_requirements.h"
#include "lcs_broadcast_assistance_types_data.h"
#include "lcs_priority.h"
#include "ldr_type.h"
#include "location_qo_s.h"
#include "lp_hap_type.h"
#include "mapped_location_qo_s_eps.h"
#include "mbsr_info.h"
#include "motion_event_info.h"
#include "ncgi.h"
#include "periodic_event_info.h"
#include "ranging_sl_result.h"
#include "ref_to_binary_data.h"
#include "related_ue.h"
#include "reporting_access_type.h"
#include "reporting_area.h"
#include "supported_gad_shapes.h"
#include "tnap_id.h"
#include "twap_id.h"
#include "ue_connectivity_state.h"
#include "ue_lcs_capability.h"
#include "ue_location_service_ind.h"
#include "ue_up_positioning_capabilities.h"
#include "up_cum_evt_rpt_criteria.h"
#include "up_loc_rep_addr_af_rm.h"
#include "velocity_requested.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct input_data_s input_data_t;
typedef enum { input_data_UEUNAWAREIND_NULL = 0,
	       input_data_UEUNAWAREIND__true } input_data_ue_unaware_ind_e;

char *input_data_ue_unaware_ind_ToString(
	input_data_ue_unaware_ind_e ue_unaware_ind);

input_data_ue_unaware_ind_e input_data_ue_unaware_ind_FromString(
	char *ue_unaware_ind);
typedef struct input_data_s {
	external_client_type_e external_client_type;
	char *correlation_id;
	char *amf_id;
	struct location_qo_s_s *location_qo_s;
	list_t *supported_gad_shapes;
	char *supi;
	char *pei;
	char *gpsi;
	list_t *requested_ranging_sl_result;
	list_t *related_ues;
	struct ecgi_s *ecgi;
	struct ecgi_s *ecgi_on_second_node;
	struct ncgi_s *ncgi;
	struct ncgi_s *ncgi_on_second_node;
	lcs_priority_e priority;
	velocity_requested_e velocity_requested;
	struct ue_lcs_capability_s *ue_lcs_cap;
	bool is_lcs_service_type;
	int lcs_service_type;
	ldr_type_e ldr_type;
	char *hgmlc_call_back_uri;
	char *lir_gmlc_call_back_uri;
	char *vgmlc_address;
	char *ldr_reference;
	char *lir_reference;
	struct periodic_event_info_s *periodic_event_info;
	struct area_event_info_s *area_event_info;
	struct motion_event_info_s *motion_event_info;
	list_t *reporting_access_types;
	struct ue_connectivity_state_s *ue_connectivity_states;
	ue_location_service_ind_e ue_location_service_ind;
	struct lcs_broadcast_assistance_types_data_s *mo_assistance_data_types;
	struct ref_to_binary_data_s *lpp_message;
	list_t *lpp_message_ext;
	char *supported_features;
	char *ue_positioning_cap;
	struct tnap_id_s *tnap_id;
	struct twap_id_s *twap_id;
	bool is_ue_country_det_ind;
	int ue_country_det_ind;
	char *scheduled_loc_time;
	bool is_reliable_loc_req;
	int reliable_loc_req;
	list_t *evt_rpt_allowed_areas;
	input_data_ue_unaware_ind_e ue_unaware_ind;
	bool is_intermediate_location_ind;
	int intermediate_location_ind;
	bool is_max_resp_time;
	int max_resp_time;
	struct lp_hap_type_s *lp_hap_type;
	list_t *ue_up_pos_caps;
	struct input_data_reporting_ind_s *reporting_ind;
	struct mbsr_info_s *mbsr_info;
	struct integrity_requirements_s *integrity_requirements;
	bool is_up_loc_rep_addr_af_null;
	struct up_loc_rep_addr_af_rm_s *up_loc_rep_addr_af;
	struct up_cum_evt_rpt_criteria_s *up_cum_evt_rpt_criteria;
	struct mapped_location_qo_s_eps_s *mapped_qo_s_eps;
	struct additional_ue_info_s *additional_ue_info;
	bool is_coordinate_id;
	int coordinate_id;
	char *ranging_sl_capability;
} input_data_t;

input_data_t *input_data_create(external_client_type_e external_client_type,
                                char *correlation_id, char *amf_id,
                                location_qo_s_t *location_qo_s,
                                list_t *supported_gad_shapes, char *supi,
                                char *pei, char *gpsi,
                                list_t *requested_ranging_sl_result,
                                list_t *related_ues, ecgi_t *ecgi,
                                ecgi_t *ecgi_on_second_node, ncgi_t *ncgi,
                                ncgi_t *ncgi_on_second_node,
                                lcs_priority_e priority,
                                velocity_requested_e velocity_requested,
                                ue_lcs_capability_t *ue_lcs_cap,
                                bool is_lcs_service_type, int lcs_service_type,
                                ldr_type_e ldr_type, char *hgmlc_call_back_uri,
                                char *lir_gmlc_call_back_uri,
                                char *vgmlc_address, char *ldr_reference,
                                char *lir_reference,
                                periodic_event_info_t *periodic_event_info,
                                area_event_info_t *area_event_info,
                                motion_event_info_t *motion_event_info,
                                list_t *reporting_access_types,
                                ue_connectivity_state_t *ue_connectivity_states,
                                ue_location_service_ind_e ue_location_service_ind, lcs_broadcast_assistance_types_data_t *mo_assistance_data_types, ref_to_binary_data_t *lpp_message, list_t *lpp_message_ext, char *supported_features, char *ue_positioning_cap, tnap_id_t *tnap_id, twap_id_t *twap_id, bool is_ue_country_det_ind, int ue_country_det_ind, char *scheduled_loc_time, bool is_reliable_loc_req, int reliable_loc_req, list_t *evt_rpt_allowed_areas, input_data_ue_unaware_ind_e ue_unaware_ind, bool is_intermediate_location_ind, int intermediate_location_ind, bool is_max_resp_time, int max_resp_time, lp_hap_type_t *lp_hap_type, list_t *ue_up_pos_caps, input_data_reporting_ind_t *reporting_ind, mbsr_info_t *mbsr_info, integrity_requirements_t *integrity_requirements, bool is_up_loc_rep_addr_af_null, up_loc_rep_addr_af_rm_t *up_loc_rep_addr_af, up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria, mapped_location_qo_s_eps_t *mapped_qo_s_eps, additional_ue_info_t *additional_ue_info, bool is_coordinate_id, int coordinate_id, char *ranging_sl_capability);
void input_data_free(input_data_t *input_data);
input_data_t *input_data_parseFromJSON(cJSON *input_dataJSON);
cJSON *input_data_convertToJSON(input_data_t *input_data);
input_data_t *input_data_copy(input_data_t *dst, input_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _input_data_H_ */
