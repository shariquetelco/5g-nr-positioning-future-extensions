/*
 * exception_id.h
 *
 * Describes the Exception Id.   Possible values are: - UNEXPECTED_UE_LOCATION: Unexpected UE location. - UNEXPECTED_LONG_LIVE_FLOW: Unexpected long-live rate flows. - UNEXPECTED_LARGE_RATE_FLOW: Unexpected large rate flows. - UNEXPECTED_WAKEUP: Unexpected wakeup. - SUSPICION_OF_DDOS_ATTACK: Suspicion of DDoS attack. - WRONG_DESTINATION_ADDRESS: Wrong destination address. - TOO_FREQUENT_SERVICE_ACCESS: Too frequent Service Access. - UNEXPECTED_RADIO_LINK_FAILURES: Unexpected radio link failures. - PING_PONG_ACROSS_CELLS: Ping-ponging across neighbouring cells.
 */

#ifndef _exception_id_H_
#define _exception_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "exception_id_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct exception_id_s exception_id_t;
typedef struct exception_id_s {} exception_id_t;

exception_id_t *exception_id_create();
void exception_id_free(exception_id_t *exception_id);
exception_id_t *exception_id_parseFromJSON(cJSON *exception_idJSON);
cJSON *exception_id_convertToJSON(exception_id_t *exception_id);
exception_id_t *exception_id_copy(exception_id_t *dst, exception_id_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _exception_id_H_ */
