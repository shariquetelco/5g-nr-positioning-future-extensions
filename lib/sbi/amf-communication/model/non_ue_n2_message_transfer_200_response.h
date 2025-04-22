/*
 * non_ue_n2_message_transfer_200_response.h
 *
 *
 */

#ifndef _non_ue_n2_message_transfer_200_response_H_
#define _non_ue_n2_message_transfer_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_information_transfer_rsp_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct non_ue_n2_message_transfer_200_response_s
        non_ue_n2_message_transfer_200_response_t;
typedef struct non_ue_n2_message_transfer_200_response_s {
	struct n2_information_transfer_rsp_data_s *json_data;
	binary_t *binary_data_n2_information1;
	binary_t *binary_data_n2_information2;
	binary_t *binary_data_n2_information3;
	binary_t *binary_data_n2_information4;
	binary_t *binary_data_n2_information5;
	binary_t *binary_data_n2_information6;
	binary_t *binary_data_n2_information7;
	binary_t *binary_data_n2_information8;
	binary_t *binary_data_n2_information9;
	binary_t *binary_data_n2_information10;
} non_ue_n2_message_transfer_200_response_t;

non_ue_n2_message_transfer_200_response_t *
non_ue_n2_message_transfer_200_response_create(
	n2_information_transfer_rsp_data_t	*json_data,
	binary_t				*binary_data_n2_information1,
	binary_t				*binary_data_n2_information2,
	binary_t				*binary_data_n2_information3,
	binary_t				*binary_data_n2_information4,
	binary_t				*binary_data_n2_information5,
	binary_t				*binary_data_n2_information6,
	binary_t				*binary_data_n2_information7,
	binary_t				*binary_data_n2_information8,
	binary_t				*binary_data_n2_information9,
	binary_t				*binary_data_n2_information10);
void non_ue_n2_message_transfer_200_response_free(
	non_ue_n2_message_transfer_200_response_t *non_ue_n2_message_transfer_200_response);
non_ue_n2_message_transfer_200_response_t *
non_ue_n2_message_transfer_200_response_parseFromJSON(
	cJSON *non_ue_n2_message_transfer_200_responseJSON);
cJSON *non_ue_n2_message_transfer_200_response_convertToJSON(
	non_ue_n2_message_transfer_200_response_t *non_ue_n2_message_transfer_200_response);
non_ue_n2_message_transfer_200_response_t *
non_ue_n2_message_transfer_200_response_copy(
	non_ue_n2_message_transfer_200_response_t	*dst,
	non_ue_n2_message_transfer_200_response_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _non_ue_n2_message_transfer_200_response_H_ */
