/*
 * user_data_con_order_crit_any_of.h
 *
 *
 */

#ifndef _user_data_con_order_crit_any_of_H_
#define _user_data_con_order_crit_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { user_data_con_order_crit_any_of_NULL = 0,
	       user_data_con_order_crit_any_of_APPLICABLE_TIME_WINDOW,
	       user_data_con_order_crit_any_of_NETWORK_STATUS_INDICATION }
user_data_con_order_crit_any_of_e;

char *user_data_con_order_crit_any_of_ToString(
	user_data_con_order_crit_any_of_e user_data_con_order_crit_any_of);

user_data_con_order_crit_any_of_e user_data_con_order_crit_any_of_FromString(
	char *user_data_con_order_crit_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _user_data_con_order_crit_any_of_H_ */
