/*
 * ue_context_transfer_req_data.h
 *
 * Data within a UE Context Transfer Request to start transferring of an individual ueContext resource from old AMF to new AMF
 */

#ifndef _ue_context_transfer_req_data_H_
#define _ue_context_transfer_req_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "n1_message_container.h"
#include "plmn_id_nid.h"
#include "transfer_reason.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_transfer_req_data_s ue_context_transfer_req_data_t;
typedef struct ue_context_transfer_req_data_s {
	transfer_reason_e reason;
	access_type_e access_type;
	struct plmn_id_nid_s *plmn_id;
	struct n1_message_container_s *reg_request;
	char *supported_features;
} ue_context_transfer_req_data_t;

ue_context_transfer_req_data_t *ue_context_transfer_req_data_create(
	transfer_reason_e reason, access_type_e access_type,
	plmn_id_nid_t *plmn_id, n1_message_container_t *reg_request,
	char *supported_features);
void ue_context_transfer_req_data_free(
	ue_context_transfer_req_data_t *ue_context_transfer_req_data);
ue_context_transfer_req_data_t *ue_context_transfer_req_data_parseFromJSON(
	cJSON *ue_context_transfer_req_dataJSON);
cJSON *ue_context_transfer_req_data_convertToJSON(
	ue_context_transfer_req_data_t *ue_context_transfer_req_data);
ue_context_transfer_req_data_t *ue_context_transfer_req_data_copy(
	ue_context_transfer_req_data_t	*dst,
	ue_context_transfer_req_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_transfer_req_data_H_ */
