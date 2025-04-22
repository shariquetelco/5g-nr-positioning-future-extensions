/*
 * create_ue_context_201_response.h
 *
 *
 */

#ifndef _create_ue_context_201_response_H_
#define _create_ue_context_201_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_created_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct create_ue_context_201_response_s create_ue_context_201_response_t;
typedef struct create_ue_context_201_response_s {
	struct ue_context_created_data_s *json_data;
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
} create_ue_context_201_response_t;

create_ue_context_201_response_t *create_ue_context_201_response_create(
	ue_context_created_data_t	*json_data,
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
	binary_t			*binary_data_n2_information_ext15);
void create_ue_context_201_response_free(
	create_ue_context_201_response_t *create_ue_context_201_response);
create_ue_context_201_response_t *create_ue_context_201_response_parseFromJSON(
	cJSON *create_ue_context_201_responseJSON);
cJSON *create_ue_context_201_response_convertToJSON(
	create_ue_context_201_response_t *create_ue_context_201_response);
create_ue_context_201_response_t *create_ue_context_201_response_copy(
	create_ue_context_201_response_t	*dst,
	create_ue_context_201_response_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _create_ue_context_201_response_H_ */
