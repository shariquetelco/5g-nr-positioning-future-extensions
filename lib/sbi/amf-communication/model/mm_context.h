/*
 * mm_context.h
 *
 * Represents a Mobility Management Context in UE Context
 */

#ifndef _mm_context_H_
#define _mm_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "dereg_inact_timer_info.h"
#include "eps_nas_security_mode.h"
#include "expected_ue_behavior.h"
#include "global_ran_node_id.h"
#include "nas_security_mode.h"
#include "nssaa_status.h"
#include "nssai_mapping.h"
#include "partially_allowed_snssai.h"
#include "slice_replacement_mapping.h"
#include "snssai.h"
#include "ue_differentiation_info.h"
#include "uuaa_mm_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mm_context_s mm_context_t;
typedef struct mm_context_s {
	access_type_e access_type;
	struct nas_security_mode_s *nas_security_mode;
	struct eps_nas_security_mode_s *eps_nas_security_mode;
	bool is_nas_downlink_count;
	int nas_downlink_count;
	bool is_nas_uplink_count;
	int nas_uplink_count;
	char *ue_security_capability;
	char *s1_ue_network_capability;
	list_t *allowed_nssai;
	list_t *nssai_mapping_list;
	list_t *allowed_home_nssai;
	list_t *partially_allowed_nssai;
	list_t *replaced_snssai_mapping_list;
	list_t *ns_instance_list;
	struct expected_ue_behavior_s *expected_u_ebehavior;
	struct ue_differentiation_info_s *ue_differentiation_info;
	char *plmn_assi_ue_radio_cap_id;
	char *man_assi_ue_radio_cap_id;
	char *ucmf_dic_entry_id;
	struct global_ran_node_id_s *n3_iwf_id;
	struct global_ran_node_id_s *wagf_id;
	struct global_ran_node_id_s *tngf_id;
	bool is_an_n2_ap_id;
	int an_n2_ap_id;
	list_t *nssaa_status_list;
	list_t *pending_nssai_mapping_list;
	uuaa_mm_status_e uuaa_mm_status;
	list_t *dereg_inact_timer_list;
	bool is_vo_support_match_ind;
	int vo_support_match_ind;
} mm_context_t;

mm_context_t *mm_context_create(access_type_e access_type,
                                nas_security_mode_t *nas_security_mode,
                                eps_nas_security_mode_t *eps_nas_security_mode,
                                bool is_nas_downlink_count,
                                int nas_downlink_count,
                                bool is_nas_uplink_count, int nas_uplink_count,
                                char *ue_security_capability,
                                char *s1_ue_network_capability,
                                list_t *allowed_nssai,
                                list_t *nssai_mapping_list,
                                list_t *allowed_home_nssai,
                                list_t *partially_allowed_nssai,
                                list_t *replaced_snssai_mapping_list,
                                list_t *ns_instance_list,
                                expected_ue_behavior_t *expected_u_ebehavior,
                                ue_differentiation_info_t *ue_differentiation_info, char *plmn_assi_ue_radio_cap_id, char *man_assi_ue_radio_cap_id, char *ucmf_dic_entry_id, global_ran_node_id_t *n3_iwf_id, global_ran_node_id_t *wagf_id, global_ran_node_id_t *tngf_id, bool is_an_n2_ap_id, int an_n2_ap_id, list_t *nssaa_status_list, list_t *pending_nssai_mapping_list, uuaa_mm_status_e uuaa_mm_status, list_t *dereg_inact_timer_list, bool is_vo_support_match_ind, int vo_support_match_ind);
void mm_context_free(mm_context_t *mm_context);
mm_context_t *mm_context_parseFromJSON(cJSON *mm_contextJSON);
cJSON *mm_context_convertToJSON(mm_context_t *mm_context);
mm_context_t *mm_context_copy(mm_context_t *dst, mm_context_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _mm_context_H_ */
