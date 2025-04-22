/*
 * nssai_mapping.h
 *
 * Represents the mapping between a S-NSSAI in serving PLMN to a S-NSSAI in home PLMN
 */

#ifndef _nssai_mapping_H_
#define _nssai_mapping_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct nssai_mapping_s nssai_mapping_t;
typedef struct nssai_mapping_s {
	struct snssai_s *mapped_snssai;
	struct snssai_s *h_snssai;
} nssai_mapping_t;

nssai_mapping_t *nssai_mapping_create(snssai_t	*mapped_snssai,
                                      snssai_t	*h_snssai);
void nssai_mapping_free(nssai_mapping_t *nssai_mapping);
nssai_mapping_t *nssai_mapping_parseFromJSON(cJSON *nssai_mappingJSON);
cJSON *nssai_mapping_convertToJSON(nssai_mapping_t *nssai_mapping);
nssai_mapping_t *nssai_mapping_copy(nssai_mapping_t *dst, nssai_mapping_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _nssai_mapping_H_ */
