/*
 * n1_n2_msg_txfr_failure_notification.h
 *
 * Data within a N1/N2 Message Transfer Failure Notification request
 */

#ifndef _n1_n2_msg_txfr_failure_notification_H_
#define _n1_n2_msg_txfr_failure_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n1_n2_message_transfer_cause.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n1_n2_msg_txfr_failure_notification_s
        n1_n2_msg_txfr_failure_notification_t;
typedef struct n1_n2_msg_txfr_failure_notification_s {
	n1_n2_message_transfer_cause_e cause;
	char *n1n2_msg_data_uri;
	bool is_retry_after;
	int retry_after;
} n1_n2_msg_txfr_failure_notification_t;

n1_n2_msg_txfr_failure_notification_t *
n1_n2_msg_txfr_failure_notification_create(
	n1_n2_message_transfer_cause_e	cause,
	char				*n1n2_msg_data_uri,
	bool				is_retry_after,
	int				retry_after);
void n1_n2_msg_txfr_failure_notification_free(
	n1_n2_msg_txfr_failure_notification_t *n1_n2_msg_txfr_failure_notification);
n1_n2_msg_txfr_failure_notification_t *
n1_n2_msg_txfr_failure_notification_parseFromJSON(
	cJSON *n1_n2_msg_txfr_failure_notificationJSON);
cJSON *n1_n2_msg_txfr_failure_notification_convertToJSON(
	n1_n2_msg_txfr_failure_notification_t *n1_n2_msg_txfr_failure_notification);
n1_n2_msg_txfr_failure_notification_t *n1_n2_msg_txfr_failure_notification_copy(
	n1_n2_msg_txfr_failure_notification_t	*dst,
	n1_n2_msg_txfr_failure_notification_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _n1_n2_msg_txfr_failure_notification_H_ */
