/*
 * notification_method_1.h
 *
 * Represents the notification methods that can be subscribed.   Possible values are: - PERIODIC - ONE_TIME - ON_EVENT_DETECTION
 */

#ifndef _notification_method_1_H_
#define _notification_method_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "notification_method_1_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct notification_method_1_s notification_method_1_t;
typedef struct notification_method_1_s {} notification_method_1_t;

notification_method_1_t *notification_method_1_create();
void notification_method_1_free(notification_method_1_t *notification_method_1);
notification_method_1_t *notification_method_1_parseFromJSON(
	cJSON *notification_method_1JSON);
cJSON *notification_method_1_convertToJSON(
	notification_method_1_t *notification_method_1);
notification_method_1_t *notification_method_1_copy(
	notification_method_1_t *dst, notification_method_1_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _notification_method_1_H_ */
