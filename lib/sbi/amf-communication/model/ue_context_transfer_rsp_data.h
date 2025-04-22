/*
 * ue_context_transfer_rsp_data.h
 *
 * Data within a successful response to the UE Context Transfer request
 */

#ifndef _ue_context_transfer_rsp_data_H_
#define _ue_context_transfer_rsp_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"
#include "ue_context.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_transfer_rsp_data_s ue_context_transfer_rsp_data_t;
typedef struct ue_context_transfer_rsp_data_s {
	struct ue_context_s *ue_context;
	struct n2_info_content_s *ue_radio_capability;
	struct n2_info_content_s *ue_radio_capability_for_paging;
	struct n2_info_content_s *ue_nbiot_radio_capability;
	char *supported_features;
} ue_context_transfer_rsp_data_t;

ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_create(
	ue_context_t *ue_context, n2_info_content_t *ue_radio_capability,
	n2_info_content_t *ue_radio_capability_for_paging,
	n2_info_content_t *ue_nbiot_radio_capability, char *supported_features);
void ue_context_transfer_rsp_data_free(
	ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data);
ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_parseFromJSON(
	cJSON *ue_context_transfer_rsp_dataJSON);
cJSON *ue_context_transfer_rsp_data_convertToJSON(
	ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data);
ue_context_transfer_rsp_data_t *ue_context_transfer_rsp_data_copy(
	ue_context_transfer_rsp_data_t	*dst,
	ue_context_transfer_rsp_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_transfer_rsp_data_H_ */
