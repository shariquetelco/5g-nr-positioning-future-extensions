/*
 * nssaa_status.h
 *
 * contains the Subscribed S-NSSAI subject to NSSAA procedure and the status.
 */

#ifndef _nssaa_status_H_
#define _nssaa_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "auth_status.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nssaa_status_s nssaa_status_t;
typedef struct nssaa_status_s {
	struct snssai_s *snssai;
	struct auth_status_s *status;
} nssaa_status_t;

nssaa_status_t *nssaa_status_create(snssai_t *snssai, auth_status_t *status);
void nssaa_status_free(nssaa_status_t *nssaa_status);
nssaa_status_t *nssaa_status_parseFromJSON(cJSON *nssaa_statusJSON);
cJSON *nssaa_status_convertToJSON(nssaa_status_t *nssaa_status);
nssaa_status_t *nssaa_status_copy(nssaa_status_t *dst, nssaa_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nssaa_status_H_ */
