/*
 * cancel_relocate_ue_context_request.h
 *
 *
 */

#ifndef _cancel_relocate_ue_context_request_H_
#define _cancel_relocate_ue_context_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_cancel_relocate_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cancel_relocate_ue_context_request_s
        cancel_relocate_ue_context_request_t;
typedef struct cancel_relocate_ue_context_request_s {
	struct ue_context_cancel_relocate_data_s *json_data;
	binary_t *binary_data_gtpc_message;
} cancel_relocate_ue_context_request_t;

cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request_create(
	ue_context_cancel_relocate_data_t	*json_data,
	binary_t				*binary_data_gtpc_message);
void cancel_relocate_ue_context_request_free(
	cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request);
cancel_relocate_ue_context_request_t *
cancel_relocate_ue_context_request_parseFromJSON(
	cJSON *cancel_relocate_ue_context_requestJSON);
cJSON *cancel_relocate_ue_context_request_convertToJSON(
	cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request);
cancel_relocate_ue_context_request_t *cancel_relocate_ue_context_request_copy(
	cancel_relocate_ue_context_request_t	*dst,
	cancel_relocate_ue_context_request_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _cancel_relocate_ue_context_request_H_ */
