/*
 * notification_flag.h
 *
 * Possible values are: - ACTIVATE: The event notification is activated. - DEACTIVATE: The event notification is deactivated and shall be muted. The available    event(s) shall be stored. - RETRIEVAL: The event notification shall be sent to the NF service consumer(s),   after that, is muted again.
 */

#ifndef _notification_flag_H_
#define _notification_flag_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "notification_flag_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct notification_flag_s notification_flag_t;
typedef struct notification_flag_s {} notification_flag_t;

notification_flag_t *notification_flag_create();
void notification_flag_free(notification_flag_t *notification_flag);
notification_flag_t *notification_flag_parseFromJSON(
	cJSON *notification_flagJSON);
cJSON *notification_flag_convertToJSON(notification_flag_t *notification_flag);
notification_flag_t *notification_flag_copy(notification_flag_t *dst,
                                            notification_flag_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _notification_flag_H_ */
