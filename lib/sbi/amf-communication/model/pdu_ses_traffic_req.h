/*
 * pdu_ses_traffic_req.h
 *
 * Represents the PDU Session traffic analytics requirements.
 */

#ifndef _pdu_ses_traffic_req_H_
#define _pdu_ses_traffic_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct pdu_ses_traffic_req_s pdu_ses_traffic_req_t;
typedef struct pdu_ses_traffic_req_s {
	list_t *flow_descs;
	char *app_id;
	list_t *domain_descs;
} pdu_ses_traffic_req_t;

pdu_ses_traffic_req_t *pdu_ses_traffic_req_create(list_t	*flow_descs,
                                                  char		*app_id,
                                                  list_t	*domain_descs);
void pdu_ses_traffic_req_free(pdu_ses_traffic_req_t *pdu_ses_traffic_req);
pdu_ses_traffic_req_t *pdu_ses_traffic_req_parseFromJSON(
	cJSON *pdu_ses_traffic_reqJSON);
cJSON *pdu_ses_traffic_req_convertToJSON(
	pdu_ses_traffic_req_t *pdu_ses_traffic_req);
pdu_ses_traffic_req_t *pdu_ses_traffic_req_copy(pdu_ses_traffic_req_t	*dst,
                                                pdu_ses_traffic_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _pdu_ses_traffic_req_H_ */
