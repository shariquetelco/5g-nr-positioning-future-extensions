/*
 * ue_context_created_data.h
 *
 * Data within a successful response for creating an individual ueContext resource
 */

#ifndef _ue_context_created_data_H_
#define _ue_context_created_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"
#include "n2_sm_information.h"
#include "ue_context.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_created_data_s ue_context_created_data_t;
typedef struct ue_context_created_data_s {
	struct ue_context_s *ue_context;
	struct n2_info_content_s *target_to_source_data;
	list_t *pdu_session_list;
	list_t *failed_session_list;
	char *supported_features;
	bool is_pcf_reselected_ind;
	int pcf_reselected_ind;
	list_t *analytics_not_used_list;
} ue_context_created_data_t;

ue_context_created_data_t *ue_context_created_data_create(
	ue_context_t *ue_context, n2_info_content_t *target_to_source_data,
	list_t *pdu_session_list, list_t *failed_session_list,
	char *supported_features, bool is_pcf_reselected_ind,
	int pcf_reselected_ind, list_t *analytics_not_used_list);
void ue_context_created_data_free(
	ue_context_created_data_t *ue_context_created_data);
ue_context_created_data_t *ue_context_created_data_parseFromJSON(
	cJSON *ue_context_created_dataJSON);
cJSON *ue_context_created_data_convertToJSON(
	ue_context_created_data_t *ue_context_created_data);
ue_context_created_data_t *ue_context_created_data_copy(
	ue_context_created_data_t *dst, ue_context_created_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_created_data_H_ */
