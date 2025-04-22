/*
 * pdu_session_type.h
 *
 * PduSessionType indicates the type of a PDU session. It shall comply with the provisions defined in table 5.4.3.3-1.
 */

#ifndef _pdu_session_type_H_
#define _pdu_session_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "pdu_session_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pdu_session_type_s pdu_session_type_t;
typedef struct pdu_session_type_s {} pdu_session_type_t;

pdu_session_type_t *pdu_session_type_create();
void pdu_session_type_free(pdu_session_type_t *pdu_session_type);
pdu_session_type_t *pdu_session_type_parseFromJSON(cJSON *pdu_session_typeJSON);
cJSON *pdu_session_type_convertToJSON(pdu_session_type_t *pdu_session_type);
pdu_session_type_t *pdu_session_type_copy(pdu_session_type_t	*dst,
                                          pdu_session_type_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pdu_session_type_H_ */
