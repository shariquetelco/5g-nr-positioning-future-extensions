/*
 * transport_protocol_any_of.h
 *
 *
 */

#ifndef _transport_protocol_any_of_H_
#define _transport_protocol_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { transport_protocol_any_of_NULL = 0,
	       transport_protocol_any_of_UDP,
	       transport_protocol_any_of_TCP } transport_protocol_any_of_e;

char *transport_protocol_any_of_ToString(
	transport_protocol_any_of_e transport_protocol_any_of);

transport_protocol_any_of_e transport_protocol_any_of_FromString(
	char *transport_protocol_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _transport_protocol_any_of_H_ */
