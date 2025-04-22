/*
 * pdu_session_type_any_of.h
 *
 *
 */

#ifndef _pdu_session_type_any_of_H_
#define _pdu_session_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { pdu_session_type_any_of_NULL = 0, pdu_session_type_any_of_IPV4,
	       pdu_session_type_any_of_IPV6, pdu_session_type_any_of_IPV4V6,
	       pdu_session_type_any_of_UNSTRUCTURED,
	       pdu_session_type_any_of_ETHERNET } pdu_session_type_any_of_e;

char *pdu_session_type_any_of_ToString(
	pdu_session_type_any_of_e pdu_session_type_any_of);

pdu_session_type_any_of_e pdu_session_type_any_of_FromString(
	char *pdu_session_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _pdu_session_type_any_of_H_ */
