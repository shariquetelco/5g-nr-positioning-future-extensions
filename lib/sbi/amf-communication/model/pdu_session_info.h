/*
 * pdu_session_info.h
 *
 * indicates the DNN and S-NSSAI combination of a PDU session.
 */

#ifndef _pdu_session_info_H_
#define _pdu_session_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pdu_session_info_s pdu_session_info_t;
typedef struct pdu_session_info_s {
	struct snssai_s *snssai;
	char *dnn;
} pdu_session_info_t;

pdu_session_info_t *pdu_session_info_create(snssai_t *snssai, char *dnn);
void pdu_session_info_free(pdu_session_info_t *pdu_session_info);
pdu_session_info_t *pdu_session_info_parseFromJSON(cJSON *pdu_session_infoJSON);
cJSON *pdu_session_info_convertToJSON(pdu_session_info_t *pdu_session_info);
pdu_session_info_t *pdu_session_info_copy(pdu_session_info_t	*dst,
                                          pdu_session_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pdu_session_info_H_ */
