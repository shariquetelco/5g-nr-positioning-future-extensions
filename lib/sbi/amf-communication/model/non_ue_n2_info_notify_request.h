/*
 * non_ue_n2_info_notify_request.h
 *
 *
 */

#ifndef _non_ue_n2_info_notify_request_H_
#define _non_ue_n2_info_notify_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_information_notification.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct non_ue_n2_info_notify_request_s non_ue_n2_info_notify_request_t;
typedef struct non_ue_n2_info_notify_request_s {
	struct n2_information_notification_s *json_data;
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
} non_ue_n2_info_notify_request_t;

non_ue_n2_info_notify_request_t *non_ue_n2_info_notify_request_create(
	n2_information_notification_t	*json_data,
	binary_t			*binary_data_n2_information1,
	binary_t			*binary_data_n2_information2,
	binary_t			*binary_data_n2_information3,
	binary_t			*binary_data_n2_information4,
	binary_t			*binary_data_n2_information5,
	binary_t			*binary_data_n2_information6,
	binary_t			*binary_data_n2_information7,
	binary_t			*binary_data_n2_information8,
	binary_t			*binary_data_n2_information9,
	binary_t			*binary_data_n2_information10);
void non_ue_n2_info_notify_request_free(
	non_ue_n2_info_notify_request_t *non_ue_n2_info_notify_request);
non_ue_n2_info_notify_request_t *non_ue_n2_info_notify_request_parseFromJSON(
	cJSON *non_ue_n2_info_notify_requestJSON);
cJSON *non_ue_n2_info_notify_request_convertToJSON(
	non_ue_n2_info_notify_request_t *non_ue_n2_info_notify_request);
non_ue_n2_info_notify_request_t *non_ue_n2_info_notify_request_copy(
	non_ue_n2_info_notify_request_t *dst,
	non_ue_n2_info_notify_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _non_ue_n2_info_notify_request_H_ */
