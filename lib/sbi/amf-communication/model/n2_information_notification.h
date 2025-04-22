/*
 * n2_information_notification.h
 *
 * Data within a N2 information notification request
 */

#ifndef _n2_information_notification_H_
#define _n2_information_notification_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "global_ran_node_id.h"
#include "guami.h"
#include "ipv6_addr.h"
#include "n2_info_container.h"
#include "n2_info_notify_reason.h"
#include "smf_change_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct n2_information_notification_s n2_information_notification_t;
typedef struct n2_information_notification_s {
	char *n2_notify_subscription_id;
	struct n2_info_container_s *n2_info_container;
	list_t *to_release_session_list;
	char *lcs_correlation_id;
	n2_info_notify_reason_e notify_reason;
	list_t *smf_change_info_list;
	struct global_ran_node_id_s *ran_node_id;
	char *initial_amf_name;
	char *an_n2_ipv4_addr;
	struct ipv6_addr_s *an_n2_ipv6_addr;
	struct guami_s *guami;
	bool is_notify_source_ng_ran;
	int notify_source_ng_ran;
	char *notif_correlation_id;
} n2_information_notification_t;

n2_information_notification_t *n2_information_notification_create(
	char *n2_notify_subscription_id, n2_info_container_t *n2_info_container,
	list_t *to_release_session_list, char *lcs_correlation_id,
	n2_info_notify_reason_e notify_reason, list_t *smf_change_info_list,
	global_ran_node_id_t *ran_node_id, char *initial_amf_name,
	char *an_n2_ipv4_addr, ipv6_addr_t *an_n2_ipv6_addr, guami_t *guami,
	bool is_notify_source_ng_ran, int notify_source_ng_ran,
	char *notif_correlation_id);
void n2_information_notification_free(
	n2_information_notification_t *n2_information_notification);
n2_information_notification_t *n2_information_notification_parseFromJSON(
	cJSON *n2_information_notificationJSON);
cJSON *n2_information_notification_convertToJSON(
	n2_information_notification_t *n2_information_notification);
n2_information_notification_t *n2_information_notification_copy(
	n2_information_notification_t *dst, n2_information_notification_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _n2_information_notification_H_ */
