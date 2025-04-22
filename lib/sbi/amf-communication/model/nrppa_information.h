/*
 * nrppa_information.h
 *
 * Represents a NRPPa related N2 information data part
 */

#ifndef _nrppa_information_H_
#define _nrppa_information_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "n2_info_content.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nrppa_information_s nrppa_information_t;
typedef struct nrppa_information_s {
	char *nf_id;
	struct n2_info_content_s *nrppa_pdu;
	char *service_instance_id;
} nrppa_information_t;

nrppa_information_t *nrppa_information_create(char		*nf_id,
                                              n2_info_content_t *nrppa_pdu,
                                              char		*service_instance_id);
void nrppa_information_free(nrppa_information_t *nrppa_information);
nrppa_information_t *nrppa_information_parseFromJSON(
	cJSON *nrppa_informationJSON);
cJSON *nrppa_information_convertToJSON(nrppa_information_t *nrppa_information);
nrppa_information_t *nrppa_information_copy(nrppa_information_t *dst,
                                            nrppa_information_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nrppa_information_H_ */
