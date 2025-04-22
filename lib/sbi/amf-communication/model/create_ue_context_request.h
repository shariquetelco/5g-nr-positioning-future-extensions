/*
 * create_ue_context_request.h
 *
 *
 */

#ifndef _create_ue_context_request_H_
#define _create_ue_context_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_create_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct create_ue_context_request_s create_ue_context_request_t;
typedef struct create_ue_context_request_s {
	struct ue_context_create_data_s *json_data;
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
	binary_t *binary_data_n2_information_ext17;
} create_ue_context_request_t;

create_ue_context_request_t *create_ue_context_request_create(
	ue_context_create_data_t	*json_data,
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
	binary_t			*binary_data_n2_information_ext16,
	binary_t			*binary_data_n2_information_ext17);
void create_ue_context_request_free(
	create_ue_context_request_t *create_ue_context_request);
create_ue_context_request_t *create_ue_context_request_parseFromJSON(
	cJSON *create_ue_context_requestJSON);
cJSON *create_ue_context_request_convertToJSON(
	create_ue_context_request_t *create_ue_context_request);
create_ue_context_request_t *create_ue_context_request_copy(
	create_ue_context_request_t *dst, create_ue_context_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _create_ue_context_request_H_ */
