/*
 * create_ue_context_403_response.h
 *
 *
 */

#ifndef _create_ue_context_403_response_H_
#define _create_ue_context_403_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_context_create_error.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct create_ue_context_403_response_s create_ue_context_403_response_t;
typedef struct create_ue_context_403_response_s {
	struct ue_context_create_error_s *json_data;
	binary_t *binary_data_n2_information;
} create_ue_context_403_response_t;

create_ue_context_403_response_t *create_ue_context_403_response_create(
	ue_context_create_error_t	*json_data,
	binary_t			*binary_data_n2_information);
void create_ue_context_403_response_free(
	create_ue_context_403_response_t *create_ue_context_403_response);
create_ue_context_403_response_t *create_ue_context_403_response_parseFromJSON(
	cJSON *create_ue_context_403_responseJSON);
cJSON *create_ue_context_403_response_convertToJSON(
	create_ue_context_403_response_t *create_ue_context_403_response);
create_ue_context_403_response_t *create_ue_context_403_response_copy(
	create_ue_context_403_response_t	*dst,
	create_ue_context_403_response_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _create_ue_context_403_response_H_ */
