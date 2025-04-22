/*
 * pdu_session_context.h
 *
 * Represents a PDU Session Context in UE Context
 */

#ifndef _pdu_session_context_H_
#define _pdu_session_context_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "cn_assisted_ran_para.h"
#include "ebi_arp_mapping.h"
#include "ip_address.h"
#include "plmn_id.h"
#include "sbi_binding_level.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pdu_session_context_s pdu_session_context_t;
typedef struct pdu_session_context_s {
	int pdu_session_id;
	char *sm_context_ref;
	struct snssai_s *s_nssai;
	struct snssai_s *alt_snssai;
	char *dnn;
	char *selected_dnn;
	access_type_e access_type;
	access_type_e additional_access_type;
	list_t *allocated_ebi_list;
	char *hsmf_id;
	char *hsmf_set_id;
	char *hsmf_service_set_id;
	sbi_binding_level_e smf_binding;
	char *vsmf_id;
	char *vsmf_set_id;
	char *vsmf_service_set_id;
	sbi_binding_level_e vsmf_binding;
	char *ismf_id;
	char *ismf_set_id;
	char *ismf_service_set_id;
	sbi_binding_level_e ismf_binding;
	char *ns_instance;
	char *smf_service_instance_id;
	bool is_ma_pdu_session;
	int ma_pdu_session;
	struct cn_assisted_ran_para_s *cn_assisted_ran_para;
	char *nrf_management_uri;
	char *nrf_discovery_uri;
	char *nrf_access_token_uri;
	char *smf_binding_info;
	char *vsmf_binding_info;
	char *ismf_binding_info;
	struct snssai_s *additional_snssai;
	struct snssai_s *alt_additional_snssai;
	char *inter_plmn_api_root;
	char *pgw_fqdn;
	struct ip_address_s *pgw_ip_addr;
	struct plmn_id_s *plmn_id;
	char *anchor_smf_supported_features;
	bool is_anchor_smf_oauth2_required;
	int anchor_smf_oauth2_required;
	bool is_hrsbo_allowed_ind;
	int hrsbo_allowed_ind;
} pdu_session_context_t;

pdu_session_context_t *pdu_session_context_create(int pdu_session_id,
                                                  char *sm_context_ref,
                                                  snssai_t *s_nssai,
                                                  snssai_t *alt_snssai,
                                                  char *dnn, char *selected_dnn,
                                                  access_type_e access_type,
                                                  access_type_e additional_access_type, list_t *allocated_ebi_list, char *hsmf_id, char *hsmf_set_id, char *hsmf_service_set_id, sbi_binding_level_e smf_binding, char *vsmf_id, char *vsmf_set_id, char *vsmf_service_set_id, sbi_binding_level_e vsmf_binding, char *ismf_id, char *ismf_set_id, char *ismf_service_set_id, sbi_binding_level_e ismf_binding, char *ns_instance, char *smf_service_instance_id, bool is_ma_pdu_session, int ma_pdu_session, cn_assisted_ran_para_t *cn_assisted_ran_para, char *nrf_management_uri, char *nrf_discovery_uri, char *nrf_access_token_uri, char *smf_binding_info, char *vsmf_binding_info, char *ismf_binding_info, snssai_t *additional_snssai, snssai_t *alt_additional_snssai, char *inter_plmn_api_root, char *pgw_fqdn, ip_address_t *pgw_ip_addr, plmn_id_t *plmn_id, char *anchor_smf_supported_features, bool is_anchor_smf_oauth2_required, int anchor_smf_oauth2_required, bool is_hrsbo_allowed_ind, int hrsbo_allowed_ind);
void pdu_session_context_free(pdu_session_context_t *pdu_session_context);
pdu_session_context_t *pdu_session_context_parseFromJSON(
	cJSON *pdu_session_contextJSON);
cJSON *pdu_session_context_convertToJSON(
	pdu_session_context_t *pdu_session_context);
pdu_session_context_t *pdu_session_context_copy(pdu_session_context_t	*dst,
                                                pdu_session_context_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pdu_session_context_H_ */
