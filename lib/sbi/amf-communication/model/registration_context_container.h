/*
 * registration_context_container.h
 *
 * Registration Context Container used to send the UE context information, N1 message from UE, AN address etc during Registration with AMF re-allocation procedure
 */

#ifndef _registration_context_container_H_
#define _registration_context_container_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "allowed_nssai.h"
#include "ce_mode_b_ind.h"
#include "configured_snssai.h"
#include "global_ran_node_id.h"
#include "ipv6_addr.h"
#include "lte_m_ind.h"
#include "npn_access_info.h"
#include "plmn_id.h"
#include "snssai.h"
#include "ue_context.h"
#include "user_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct registration_context_container_s registration_context_container_t;
typedef struct registration_context_container_s {
	struct ue_context_s *ue_context;
	char *local_time_zone;
	access_type_e an_type;
	int an_n2_ap_id;
	struct global_ran_node_id_s *ran_node_id;
	char *initial_amf_name;
	struct user_location_s *user_location;
	char *rrc_est_cause;
	bool is_ue_context_request;
	int ue_context_request;
	bool is_initial_amf_n2_ap_id;
	int initial_amf_n2_ap_id;
	char *an_n2_ipv4_addr;
	struct ipv6_addr_s *an_n2_ipv6_addr;
	struct allowed_nssai_s *allowed_nssai;
	list_t *configured_nssai;
	list_t *rejected_nssai_in_plmn;
	list_t *rejected_nssai_in_ta;
	struct plmn_id_s *selected_plmn_id;
	bool is_iab_node_ind;
	int iab_node_ind;
	bool is_mbsr_node_ind;
	int mbsr_node_ind;
	struct ce_mode_b_ind_s *ce_mode_b_ind;
	struct lte_m_ind_s *lte_m_ind;
	bool is_authenticated_ind;
	int authenticated_ind;
	struct npn_access_info_s *npn_access_info;
} registration_context_container_t;

registration_context_container_t *registration_context_container_create(
	ue_context_t *ue_context, char *local_time_zone, access_type_e an_type,
	int an_n2_ap_id, global_ran_node_id_t *ran_node_id,
	char *initial_amf_name, user_location_t *user_location,
	char *rrc_est_cause, bool is_ue_context_request, int ue_context_request,
	bool is_initial_amf_n2_ap_id, int initial_amf_n2_ap_id,
	char *an_n2_ipv4_addr, ipv6_addr_t *an_n2_ipv6_addr,
	allowed_nssai_t *allowed_nssai, list_t *configured_nssai,
	list_t *rejected_nssai_in_plmn, list_t *rejected_nssai_in_ta,
	plmn_id_t *selected_plmn_id, bool is_iab_node_ind, int iab_node_ind,
	bool is_mbsr_node_ind, int mbsr_node_ind,
	ce_mode_b_ind_t *ce_mode_b_ind, lte_m_ind_t *lte_m_ind,
	bool is_authenticated_ind, int authenticated_ind,
	npn_access_info_t *npn_access_info);
void registration_context_container_free(
	registration_context_container_t *registration_context_container);
registration_context_container_t *registration_context_container_parseFromJSON(
	cJSON *registration_context_containerJSON);
cJSON *registration_context_container_convertToJSON(
	registration_context_container_t *registration_context_container);
registration_context_container_t *registration_context_container_copy(
	registration_context_container_t	*dst,
	registration_context_container_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _registration_context_container_H_ */
