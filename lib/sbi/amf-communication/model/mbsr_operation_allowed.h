/*
 * mbsr_operation_allowed.h
 *
 *
 */

#ifndef _mbsr_operation_allowed_H_
#define _mbsr_operation_allowed_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "mbsr_location_info.h"
#include "mbsr_time_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct mbsr_operation_allowed_s mbsr_operation_allowed_t;
typedef struct mbsr_operation_allowed_s {
	bool is_mbsr_operation_allowed_ind;
	int mbsr_operation_allowed_ind;
	struct mbsr_location_info_s *mbsr_location_info;
	struct mbsr_time_info_s *mbsr_time_info;
} mbsr_operation_allowed_t;

mbsr_operation_allowed_t *mbsr_operation_allowed_create(
	bool is_mbsr_operation_allowed_ind, int mbsr_operation_allowed_ind,
	mbsr_location_info_t *mbsr_location_info,
	mbsr_time_info_t *mbsr_time_info);
void mbsr_operation_allowed_free(
	mbsr_operation_allowed_t *mbsr_operation_allowed);
mbsr_operation_allowed_t *mbsr_operation_allowed_parseFromJSON(
	cJSON *mbsr_operation_allowedJSON);
cJSON *mbsr_operation_allowed_convertToJSON(
	mbsr_operation_allowed_t *mbsr_operation_allowed);
mbsr_operation_allowed_t *mbsr_operation_allowed_copy(
	mbsr_operation_allowed_t *dst, mbsr_operation_allowed_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _mbsr_operation_allowed_H_ */
