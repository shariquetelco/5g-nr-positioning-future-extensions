/*
 * ue_reg_status_update_req_data.h
 *
 * Data within a UE registration status update request to indicate a completion of transferring at a target AMF
 */

#ifndef _ue_reg_status_update_req_data_H_
#define _ue_reg_status_update_req_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "release_session_info.h"
#include "smf_change_info.h"
#include "ue_context_transfer_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_reg_status_update_req_data_s ue_reg_status_update_req_data_t;
typedef struct ue_reg_status_update_req_data_s {
	ue_context_transfer_status_e transfer_status;
	list_t *to_release_session_list;
	bool is_pcf_reselected_ind;
	int pcf_reselected_ind;
	list_t *smf_change_info_list;
	list_t *analytics_not_used_list;
	list_t *to_release_session_info;
} ue_reg_status_update_req_data_t;

ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_create(
	ue_context_transfer_status_e transfer_status,
	list_t *to_release_session_list, bool is_pcf_reselected_ind,
	int pcf_reselected_ind, list_t *smf_change_info_list,
	list_t *analytics_not_used_list, list_t *to_release_session_info);
void ue_reg_status_update_req_data_free(
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data);
ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_parseFromJSON(
	cJSON *ue_reg_status_update_req_dataJSON);
cJSON *ue_reg_status_update_req_data_convertToJSON(
	ue_reg_status_update_req_data_t *ue_reg_status_update_req_data);
ue_reg_status_update_req_data_t *ue_reg_status_update_req_data_copy(
	ue_reg_status_update_req_data_t *dst,
	ue_reg_status_update_req_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_reg_status_update_req_data_H_ */
