/*
 * pdu_ses_traffic_info.h
 *
 * Represents the PDU Set traffic analytics information.
 */

#ifndef _pdu_ses_traffic_info_H_
#define _pdu_ses_traffic_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"
#include "td_traffic.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pdu_ses_traffic_info_s pdu_ses_traffic_info_t;
typedef struct pdu_ses_traffic_info_s {
	list_t *supis;
	char *dnn;
	struct snssai_s *snssai;
	list_t *td_match_trafs;
	list_t *td_unmatch_trafs;
} pdu_ses_traffic_info_t;

pdu_ses_traffic_info_t *pdu_ses_traffic_info_create(list_t *supis, char *dnn,
                                                    snssai_t *snssai,
                                                    list_t *td_match_trafs,
                                                    list_t *td_unmatch_trafs);
void pdu_ses_traffic_info_free(pdu_ses_traffic_info_t *pdu_ses_traffic_info);
pdu_ses_traffic_info_t *pdu_ses_traffic_info_parseFromJSON(
	cJSON *pdu_ses_traffic_infoJSON);
cJSON *pdu_ses_traffic_info_convertToJSON(
	pdu_ses_traffic_info_t *pdu_ses_traffic_info);
pdu_ses_traffic_info_t *pdu_ses_traffic_info_copy(
	pdu_ses_traffic_info_t	*dst,
	pdu_ses_traffic_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pdu_ses_traffic_info_H_ */
