/*
 * ue_context_transfer_request.h
 *
 *
 */

#ifndef _ue_context_transfer_request_H_
#define _ue_context_transfer_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_transfer_req_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_transfer_request_s ue_context_transfer_request_t;
typedef struct ue_context_transfer_request_s {
	struct ue_context_transfer_req_data_s *json_data;
	binary_t *binary_data_n1_message;
} ue_context_transfer_request_t;

ue_context_transfer_request_t *ue_context_transfer_request_create(
	ue_context_transfer_req_data_t	*json_data,
	binary_t			*binary_data_n1_message);
void ue_context_transfer_request_free(
	ue_context_transfer_request_t *ue_context_transfer_request);
ue_context_transfer_request_t *ue_context_transfer_request_parseFromJSON(
	cJSON *ue_context_transfer_requestJSON);
cJSON *ue_context_transfer_request_convertToJSON(
	ue_context_transfer_request_t *ue_context_transfer_request);
ue_context_transfer_request_t *ue_context_transfer_request_copy(
	ue_context_transfer_request_t *dst, ue_context_transfer_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_transfer_request_H_ */
