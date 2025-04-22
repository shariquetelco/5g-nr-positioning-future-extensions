/*
 * ue_context_transfer_200_response.h
 *
 *
 */

#ifndef _ue_context_transfer_200_response_H_
#define _ue_context_transfer_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_transfer_rsp_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_context_transfer_200_response_s
        ue_context_transfer_200_response_t;
typedef struct ue_context_transfer_200_response_s {
	struct ue_context_transfer_rsp_data_s *json_data;
	binary_t *binary_data_n2_information;
	binary_t *binary_data_n2_information_ext1;
	binary_t *binary_data_n2_information_ext2;
} ue_context_transfer_200_response_t;

ue_context_transfer_200_response_t *ue_context_transfer_200_response_create(
	ue_context_transfer_rsp_data_t	*json_data,
	binary_t			*binary_data_n2_information,
	binary_t			*binary_data_n2_information_ext1,
	binary_t			*binary_data_n2_information_ext2);
void ue_context_transfer_200_response_free(
	ue_context_transfer_200_response_t *ue_context_transfer_200_response);
ue_context_transfer_200_response_t *
ue_context_transfer_200_response_parseFromJSON(
	cJSON *ue_context_transfer_200_responseJSON);
cJSON *ue_context_transfer_200_response_convertToJSON(
	ue_context_transfer_200_response_t *ue_context_transfer_200_response);
ue_context_transfer_200_response_t *ue_context_transfer_200_response_copy(
	ue_context_transfer_200_response_t	*dst,
	ue_context_transfer_200_response_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_context_transfer_200_response_H_ */
