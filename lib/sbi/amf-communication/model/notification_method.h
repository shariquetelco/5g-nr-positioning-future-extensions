/*
 * notification_method.h
 *
 * Represents the notification methods for the subscribed events.   Possible values are: - PERIODIC: The notification of the subscribed NWDAF Event is periodical. The period   between the notifications is identified by repetitionPeriod and represents time in   seconds. - THRESHOLD: The subscribe of NWDAF Event is upon threshold exceeded.
 */

#ifndef _notification_method_H_
#define _notification_method_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "notification_method_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct notification_method_s notification_method_t;
typedef struct notification_method_s {} notification_method_t;

notification_method_t *notification_method_create();
void notification_method_free(notification_method_t *notification_method);
notification_method_t *notification_method_parseFromJSON(
	cJSON *notification_methodJSON);
cJSON *notification_method_convertToJSON(
	notification_method_t *notification_method);
notification_method_t *notification_method_copy(notification_method_t	*dst,
                                                notification_method_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _notification_method_H_ */
