/*
 * user_data_con_order_crit.h
 *
 * Represents the cause for requesting to terminate an analytics subscription.   Possible values are:     - APPLICABLE_TIME_WINDOW: The ordering criterion is the Applicable Time Window.   - NETWORK_STATUS_INDICATION: The ordering criterion is the network status indication.
 */

#ifndef _user_data_con_order_crit_H_
#define _user_data_con_order_crit_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "user_data_con_order_crit_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct user_data_con_order_crit_s user_data_con_order_crit_t;
typedef struct user_data_con_order_crit_s {} user_data_con_order_crit_t;

user_data_con_order_crit_t *user_data_con_order_crit_create();
void user_data_con_order_crit_free(
	user_data_con_order_crit_t *user_data_con_order_crit);
user_data_con_order_crit_t *user_data_con_order_crit_parseFromJSON(
	cJSON *user_data_con_order_critJSON);
cJSON *user_data_con_order_crit_convertToJSON(
	user_data_con_order_crit_t *user_data_con_order_crit);
user_data_con_order_crit_t *user_data_con_order_crit_copy(
	user_data_con_order_crit_t *dst, user_data_con_order_crit_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _user_data_con_order_crit_H_ */
