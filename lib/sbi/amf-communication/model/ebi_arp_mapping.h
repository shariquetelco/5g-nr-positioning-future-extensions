/*
 * ebi_arp_mapping.h
 *
 * EBI to ARP mapping
 */

#ifndef _ebi_arp_mapping_H_
#define _ebi_arp_mapping_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "arp.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ebi_arp_mapping_s ebi_arp_mapping_t;
typedef struct ebi_arp_mapping_s {
	int eps_bearer_id;
	struct arp_s *arp;
} ebi_arp_mapping_t;

ebi_arp_mapping_t *ebi_arp_mapping_create(int eps_bearer_id, arp_t *arp);
void ebi_arp_mapping_free(ebi_arp_mapping_t *ebi_arp_mapping);
ebi_arp_mapping_t *ebi_arp_mapping_parseFromJSON(cJSON *ebi_arp_mappingJSON);
cJSON *ebi_arp_mapping_convertToJSON(ebi_arp_mapping_t *ebi_arp_mapping);
ebi_arp_mapping_t *ebi_arp_mapping_copy(ebi_arp_mapping_t	*dst,
                                        ebi_arp_mapping_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ebi_arp_mapping_H_ */
