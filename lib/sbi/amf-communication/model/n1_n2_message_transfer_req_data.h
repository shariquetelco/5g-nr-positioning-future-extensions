/*
 * n1_n2_message_transfer_req_data.h
 *
 * Data within a N1/N2 message transfer request
 */

#ifndef _n1_n2_message_transfer_req_data_H_
#define _n1_n2_message_transfer_req_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "area_of_validity.h"
#include "arp.h"
#include "guami.h"
#include "n1_message_container.h"
#include "n2_info_container.h"
#include "ref_to_binary_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n1_n2_message_transfer_req_data_s
        n1_n2_message_transfer_req_data_t;
typedef enum { n1_n2_message_transfer_req_data_PRUIND_NULL = 0,
	       n1_n2_message_transfer_req_data_PRUIND__true }
n1_n2_message_transfer_req_data_pru_ind_e;

char *n1_n2_message_transfer_req_data_pru_ind_ToString(
	n1_n2_message_transfer_req_data_pru_ind_e pru_ind);

n1_n2_message_transfer_req_data_pru_ind_e
n1_n2_message_transfer_req_data_pru_ind_FromString(char *pru_ind);
typedef struct n1_n2_message_transfer_req_data_s {
	struct n1_message_container_s *n1_message_container;
	struct n2_info_container_s *n2_info_container;
	struct ref_to_binary_data_s *mt_data;
	bool is_skip_ind;
	int skip_ind;
	bool is_last_msg_indication;
	int last_msg_indication;
	bool is_pdu_session_id;
	int pdu_session_id;
	char *lcs_correlation_id;
	bool is_ppi;
	int ppi;
	struct arp_s *arp;
	bool is__5qi;
	int _5qi;
	char *n1n2_failure_txf_notif_uri;
	bool is_smf_reallocation_ind;
	int smf_reallocation_ind;
	struct area_of_validity_s *area_of_validity;
	char *supported_features;
	struct guami_s *old_guami;
	bool is_ma_accepted_ind;
	int ma_accepted_ind;
	bool is_ext_buf_support;
	int ext_buf_support;
	access_type_e target_access;
	char *nf_id;
	n1_n2_message_transfer_req_data_pru_ind_e pru_ind;
} n1_n2_message_transfer_req_data_t;

n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data_create(
	n1_message_container_t *n1_message_container,
	n2_info_container_t *n2_info_container, ref_to_binary_data_t *mt_data,
	bool is_skip_ind, int skip_ind, bool is_last_msg_indication,
	int last_msg_indication, bool is_pdu_session_id, int pdu_session_id,
	char *lcs_correlation_id, bool is_ppi, int ppi, arp_t *arp,
	bool is__5qi, int _5qi, char *n1n2_failure_txf_notif_uri,
	bool is_smf_reallocation_ind, int smf_reallocation_ind,
	area_of_validity_t *area_of_validity, char *supported_features,
	guami_t *old_guami, bool is_ma_accepted_ind, int ma_accepted_ind,
	bool is_ext_buf_support, int ext_buf_support,
	access_type_e target_access, char *nf_id,
	n1_n2_message_transfer_req_data_pru_ind_e pru_ind);
void n1_n2_message_transfer_req_data_free(
	n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data);
n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data_parseFromJSON(
	cJSON *n1_n2_message_transfer_req_dataJSON);
cJSON *n1_n2_message_transfer_req_data_convertToJSON(
	n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data);
n1_n2_message_transfer_req_data_t *n1_n2_message_transfer_req_data_copy(
	n1_n2_message_transfer_req_data_t	*dst,
	n1_n2_message_transfer_req_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n1_n2_message_transfer_req_data_H_ */
