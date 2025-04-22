/*
 * n2_info_notification_rsp_data.h
 *
 * Data within a N2 information notification response
 */

#ifndef _n2_info_notification_rsp_data_H_
#define _n2_info_notification_rsp_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_sm_information.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_info_notification_rsp_data_s n2_info_notification_rsp_data_t;
typedef struct n2_info_notification_rsp_data_s {
	list_t *sec_rat_data_usage_list;
} n2_info_notification_rsp_data_t;

n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_create(
	list_t *sec_rat_data_usage_list);
void n2_info_notification_rsp_data_free(
	n2_info_notification_rsp_data_t *n2_info_notification_rsp_data);
n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_parseFromJSON(
	cJSON *n2_info_notification_rsp_dataJSON);
cJSON *n2_info_notification_rsp_data_convertToJSON(
	n2_info_notification_rsp_data_t *n2_info_notification_rsp_data);
n2_info_notification_rsp_data_t *n2_info_notification_rsp_data_copy(
	n2_info_notification_rsp_data_t *dst,
	n2_info_notification_rsp_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_info_notification_rsp_data_H_ */
