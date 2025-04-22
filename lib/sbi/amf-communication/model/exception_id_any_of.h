/*
 * exception_id_any_of.h
 *
 *
 */

#ifndef _exception_id_any_of_H_
#define _exception_id_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { exception_id_any_of_NULL = 0,
	       exception_id_any_of_UNEXPECTED_UE_LOCATION,
	       exception_id_any_of_UNEXPECTED_LONG_LIVE_FLOW,
	       exception_id_any_of_UNEXPECTED_LARGE_RATE_FLOW,
	       exception_id_any_of_UNEXPECTED_WAKEUP,
	       exception_id_any_of_SUSPICION_OF_DDOS_ATTACK,
	       exception_id_any_of_WRONG_DESTINATION_ADDRESS,
	       exception_id_any_of_TOO_FREQUENT_SERVICE_ACCESS,
	       exception_id_any_of_UNEXPECTED_RADIO_LINK_FAILURES,
	       exception_id_any_of_PING_PONG_ACROSS_CELLS }
exception_id_any_of_e;

char *exception_id_any_of_ToString(exception_id_any_of_e exception_id_any_of);

exception_id_any_of_e exception_id_any_of_FromString(char *exception_id_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _exception_id_any_of_H_ */
