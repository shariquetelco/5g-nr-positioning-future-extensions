/*
 * ue_context_create_error.h
 *
 * Data within a failure response for creating a UE context
 */

#ifndef _ue_context_create_error_H_
#define _ue_context_create_error_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"
#include "ng_ap_cause.h"
#include "problem_details.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_create_error_s ue_context_create_error_t;
typedef struct ue_context_create_error_s {
	struct problem_details_s *error;
	struct ng_ap_cause_s *ngap_cause;
	struct n2_info_content_s *target_to_source_failure_data;
} ue_context_create_error_t;

ue_context_create_error_t *ue_context_create_error_create(
	problem_details_t *error, ng_ap_cause_t *ngap_cause,
	n2_info_content_t *target_to_source_failure_data);
void ue_context_create_error_free(
	ue_context_create_error_t *ue_context_create_error);
ue_context_create_error_t *ue_context_create_error_parseFromJSON(
	cJSON *ue_context_create_errorJSON);
cJSON *ue_context_create_error_convertToJSON(
	ue_context_create_error_t *ue_context_create_error);
ue_context_create_error_t *ue_context_create_error_copy(
	ue_context_create_error_t *dst, ue_context_create_error_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_create_error_H_ */
