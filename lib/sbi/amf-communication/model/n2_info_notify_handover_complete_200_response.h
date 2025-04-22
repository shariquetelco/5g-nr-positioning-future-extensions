/*
 * n2_info_notify_handover_complete_200_response.h
 *
 *
 */

#ifndef _n2_info_notify_handover_complete_200_response_H_
#define _n2_info_notify_handover_complete_200_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_notification_rsp_data.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_info_notify_handover_complete_200_response_s
        n2_info_notify_handover_complete_200_response_t;
typedef struct n2_info_notify_handover_complete_200_response_s {
	struct n2_info_notification_rsp_data_s *json_data;
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
} n2_info_notify_handover_complete_200_response_t;

n2_info_notify_handover_complete_200_response_t *
n2_info_notify_handover_complete_200_response_create(
	n2_info_notification_rsp_data_t *json_data,
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
void n2_info_notify_handover_complete_200_response_free(
	n2_info_notify_handover_complete_200_response_t *n2_info_notify_handover_complete_200_response);
n2_info_notify_handover_complete_200_response_t *
n2_info_notify_handover_complete_200_response_parseFromJSON(
	cJSON *n2_info_notify_handover_complete_200_responseJSON);
cJSON *n2_info_notify_handover_complete_200_response_convertToJSON(
	n2_info_notify_handover_complete_200_response_t *n2_info_notify_handover_complete_200_response);
n2_info_notify_handover_complete_200_response_t *
n2_info_notify_handover_complete_200_response_copy(
	n2_info_notify_handover_complete_200_response_t *dst,
	n2_info_notify_handover_complete_200_response_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_info_notify_handover_complete_200_response_H_ */
