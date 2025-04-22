/*
 * n2_info_notify_request.h
 *
 *
 */

#ifndef _n2_info_notify_request_H_
#define _n2_info_notify_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_information_notification.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_info_notify_request_s n2_info_notify_request_t;
typedef struct n2_info_notify_request_s {
	struct n2_information_notification_s *json_data;
	binary_t *binary_data_n1_message;
	binary_t *binary_data_n2_information;
} n2_info_notify_request_t;

n2_info_notify_request_t *n2_info_notify_request_create(
	n2_information_notification_t *json_data,
	binary_t *binary_data_n1_message, binary_t *binary_data_n2_information);
void n2_info_notify_request_free(
	n2_info_notify_request_t *n2_info_notify_request);
n2_info_notify_request_t *n2_info_notify_request_parseFromJSON(
	cJSON *n2_info_notify_requestJSON);
cJSON *n2_info_notify_request_convertToJSON(
	n2_info_notify_request_t *n2_info_notify_request);
n2_info_notify_request_t *n2_info_notify_request_copy(
	n2_info_notify_request_t *dst, n2_info_notify_request_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_info_notify_request_H_ */
