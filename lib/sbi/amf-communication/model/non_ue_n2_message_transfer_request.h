/*
 * non_ue_n2_message_transfer_request.h
 *
 *
 */

#ifndef _non_ue_n2_message_transfer_request_H_
#define _non_ue_n2_message_transfer_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_information_transfer_req_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct non_ue_n2_message_transfer_request_s
        non_ue_n2_message_transfer_request_t;
typedef struct non_ue_n2_message_transfer_request_s {
	struct n2_information_transfer_req_data_s *json_data;
	binary_t *binary_data_n2_information;
} non_ue_n2_message_transfer_request_t;

non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request_create(
	n2_information_transfer_req_data_t	*json_data,
	binary_t				*binary_data_n2_information);
void non_ue_n2_message_transfer_request_free(
	non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request);
non_ue_n2_message_transfer_request_t *
non_ue_n2_message_transfer_request_parseFromJSON(
	cJSON *non_ue_n2_message_transfer_requestJSON);
cJSON *non_ue_n2_message_transfer_request_convertToJSON(
	non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request);
non_ue_n2_message_transfer_request_t *non_ue_n2_message_transfer_request_copy(
	non_ue_n2_message_transfer_request_t	*dst,
	non_ue_n2_message_transfer_request_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _non_ue_n2_message_transfer_request_H_ */
