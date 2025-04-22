/*
 * relocate_ue_context_request.h
 *
 *
 */

#ifndef _relocate_ue_context_request_H_
#define _relocate_ue_context_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_relocate_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct relocate_ue_context_request_s relocate_ue_context_request_t;
typedef struct relocate_ue_context_request_s {
	struct ue_context_relocate_data_s *json_data;
	binary_t *binary_data_forward_relocation_request;
	binary_t *binary_data_n2_information;
	binary_t *binary_data_n2_information_ext1;
	binary_t *binary_data_n2_information_ext2;
	binary_t *binary_data_n2_information_ext3;
	binary_t *binary_data_n2_information_ext4;
	binary_t *binary_data_n2_information_ext5;
	binary_t *binary_data_n2_information_ext6;
	binary_t *binary_data_n2_information_ext7;
	binary_t *binary_data_n2_information_ext8;
	binary_t *binary_data_n2_information_ext9;
	binary_t *binary_data_n2_information_ext10;
	binary_t *binary_data_n2_information_ext11;
	binary_t *binary_data_n2_information_ext12;
	binary_t *binary_data_n2_information_ext13;
	binary_t *binary_data_n2_information_ext14;
	binary_t *binary_data_n2_information_ext15;
	binary_t *binary_data_n2_information_ext16;
} relocate_ue_context_request_t;

relocate_ue_context_request_t *relocate_ue_context_request_create(
	ue_context_relocate_data_t	*json_data,
	binary_t			*binary_data_forward_relocation_request,
	binary_t			*binary_data_n2_information,
	binary_t			*binary_data_n2_information_ext1,
	binary_t			*binary_data_n2_information_ext2,
	binary_t			*binary_data_n2_information_ext3,
	binary_t			*binary_data_n2_information_ext4,
	binary_t			*binary_data_n2_information_ext5,
	binary_t			*binary_data_n2_information_ext6,
	binary_t			*binary_data_n2_information_ext7,
	binary_t			*binary_data_n2_information_ext8,
	binary_t			*binary_data_n2_information_ext9,
	binary_t			*binary_data_n2_information_ext10,
	binary_t			*binary_data_n2_information_ext11,
	binary_t			*binary_data_n2_information_ext12,
	binary_t			*binary_data_n2_information_ext13,
	binary_t			*binary_data_n2_information_ext14,
	binary_t			*binary_data_n2_information_ext15,
	binary_t			*binary_data_n2_information_ext16);
void relocate_ue_context_request_free(
	relocate_ue_context_request_t *relocate_ue_context_request);
relocate_ue_context_request_t *relocate_ue_context_request_parseFromJSON(
	cJSON *relocate_ue_context_requestJSON);
cJSON *relocate_ue_context_request_convertToJSON(
	relocate_ue_context_request_t *relocate_ue_context_request);
relocate_ue_context_request_t *relocate_ue_context_request_copy(
	relocate_ue_context_request_t *dst, relocate_ue_context_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _relocate_ue_context_request_H_ */
