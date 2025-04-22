/*
 * transport_protocol.h
 *
 * Possible values are: - UDP: User Datagram Protocol. - TCP: Transmission Control Protocol.
 */

#ifndef _transport_protocol_H_
#define _transport_protocol_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "transport_protocol_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct transport_protocol_s transport_protocol_t;
typedef struct transport_protocol_s {} transport_protocol_t;

transport_protocol_t *transport_protocol_create();
void transport_protocol_free(transport_protocol_t *transport_protocol);
transport_protocol_t *transport_protocol_parseFromJSON(
	cJSON *transport_protocolJSON);
cJSON *transport_protocol_convertToJSON(
	transport_protocol_t *transport_protocol);
transport_protocol_t *transport_protocol_copy(transport_protocol_t	*dst,
                                              transport_protocol_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _transport_protocol_H_ */
