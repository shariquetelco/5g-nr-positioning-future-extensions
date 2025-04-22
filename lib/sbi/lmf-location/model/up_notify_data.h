/*
 * up_notify_data.h
 *
 * UP Subscription
 */

#ifndef _up_notify_data_H_
#define _up_notify_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "up_connection_status.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct up_notify_data_s up_notify_data_t;
typedef struct up_notify_data_s {
	char *notif_correlation_id;
	up_connection_status_e up_connection_status;
	char *target_lmfid;
} up_notify_data_t;

up_notify_data_t *up_notify_data_create(char *notif_correlation_id,
                                        up_connection_status_e up_connection_status, char *target_lmfid);
void up_notify_data_free(up_notify_data_t *up_notify_data);
up_notify_data_t *up_notify_data_parseFromJSON(cJSON *up_notify_dataJSON);
cJSON *up_notify_data_convertToJSON(up_notify_data_t *up_notify_data);
up_notify_data_t *up_notify_data_copy(up_notify_data_t	*dst,
                                      up_notify_data_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _up_notify_data_H_ */
