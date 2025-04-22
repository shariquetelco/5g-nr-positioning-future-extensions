/*
 * ue_context_relocate_data.h
 *
 * Data within a Relocate UE Context request
 */

#ifndef _ue_context_relocate_data_H_
#define _ue_context_relocate_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"
#include "n2_sm_information.h"
#include "ng_ap_cause.h"
#include "ng_ran_target_id.h"
#include "ref_to_binary_data.h"
#include "ue_context.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_relocate_data_s ue_context_relocate_data_t;
typedef struct ue_context_relocate_data_s {
	struct ue_context_s *ue_context;
	struct ng_ran_target_id_s *target_id;
	struct n2_info_content_s *source_to_target_data;
	struct ref_to_binary_data_s *forward_relocation_request;
	list_t *pdu_session_list;
	struct n2_info_content_s *ue_radio_capability;
	struct ng_ap_cause_s *ngap_cause;
	char *supported_features;
} ue_context_relocate_data_t;

ue_context_relocate_data_t *ue_context_relocate_data_create(
	ue_context_t *ue_context, ng_ran_target_id_t *target_id,
	n2_info_content_t *source_to_target_data,
	ref_to_binary_data_t *forward_relocation_request,
	list_t *pdu_session_list, n2_info_content_t *ue_radio_capability,
	ng_ap_cause_t *ngap_cause, char *supported_features);
void ue_context_relocate_data_free(
	ue_context_relocate_data_t *ue_context_relocate_data);
ue_context_relocate_data_t *ue_context_relocate_data_parseFromJSON(
	cJSON *ue_context_relocate_dataJSON);
cJSON *ue_context_relocate_data_convertToJSON(
	ue_context_relocate_data_t *ue_context_relocate_data);
ue_context_relocate_data_t *ue_context_relocate_data_copy(
	ue_context_relocate_data_t *dst, ue_context_relocate_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_relocate_data_H_ */
