/*
 * pdu_session_info_1.h
 *
 * Represents combination of PDU Session parameter(s) information.
 */

#ifndef _pdu_session_info_1_H_
#define _pdu_session_info_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "pdu_session_type.h"
#include "ssc_mode.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pdu_session_info_1_s pdu_session_info_1_t;
typedef struct pdu_session_info_1_s {
	struct pdu_session_type_s *pdu_sess_type;
	struct ssc_mode_s *ssc_mode;
	list_t *access_types;
} pdu_session_info_1_t;

pdu_session_info_1_t *pdu_session_info_1_create(
	pdu_session_type_t *pdu_sess_type, ssc_mode_t *ssc_mode,
	list_t *access_types);
void pdu_session_info_1_free(pdu_session_info_1_t *pdu_session_info_1);
pdu_session_info_1_t *pdu_session_info_1_parseFromJSON(
	cJSON *pdu_session_info_1JSON);
cJSON *pdu_session_info_1_convertToJSON(
	pdu_session_info_1_t *pdu_session_info_1);
pdu_session_info_1_t *pdu_session_info_1_copy(pdu_session_info_1_t	*dst,
                                              pdu_session_info_1_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pdu_session_info_1_H_ */
