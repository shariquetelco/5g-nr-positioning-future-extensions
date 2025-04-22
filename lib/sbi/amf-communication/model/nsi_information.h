/*
 * nsi_information.h
 *
 * Contains the API URIs of NRF services to be used to discover NFs/services, subscribe to NF status changes and/or request access tokens within the selected Network Slice instance and optional the Identifier of the selected Network Slice instance
 */

#ifndef _nsi_information_H_
#define _nsi_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nsi_information_s nsi_information_t;
typedef struct nsi_information_s {
	char *nrf_id;
	char *nsi_id;
	char *nrf_nf_mgt_uri;
	char *nrf_access_token_uri;
	list_t *nrf_oauth2_required;
} nsi_information_t;

nsi_information_t *nsi_information_create(char *nrf_id, char *nsi_id,
                                          char *nrf_nf_mgt_uri,
                                          char *nrf_access_token_uri,
                                          list_t *nrf_oauth2_required);
void nsi_information_free(nsi_information_t *nsi_information);
nsi_information_t *nsi_information_parseFromJSON(cJSON *nsi_informationJSON);
cJSON *nsi_information_convertToJSON(nsi_information_t *nsi_information);
nsi_information_t *nsi_information_copy(nsi_information_t	*dst,
                                        nsi_information_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _nsi_information_H_ */
