/*
 * subscription_data.h
 *
 * Data within an AMF Status Change Subscription request and response
 */

#ifndef _subscription_data_H_
#define _subscription_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "guami.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct subscription_data_s subscription_data_t;
typedef struct subscription_data_s {
	char *amf_status_uri;
	list_t *guami_list;
} subscription_data_t;

subscription_data_t *subscription_data_create(char	*amf_status_uri,
                                              list_t	*guami_list);
void subscription_data_free(subscription_data_t *subscription_data);
subscription_data_t *subscription_data_parseFromJSON(
	cJSON *subscription_dataJSON);
cJSON *subscription_data_convertToJSON(subscription_data_t *subscription_data);
subscription_data_t *subscription_data_copy(subscription_data_t *dst,
                                            subscription_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _subscription_data_H_ */
