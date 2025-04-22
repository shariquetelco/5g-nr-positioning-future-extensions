/*
 * allowed_snssai.h
 *
 * Contains the authorized S-NSSAI and optional mapped home S-NSSAI and network slice instance information
 */

#ifndef _allowed_snssai_H_
#define _allowed_snssai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "nsi_information.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct allowed_snssai_s allowed_snssai_t;
typedef struct allowed_snssai_s {
	struct snssai_s *allowed_snssai;
	list_t *nsi_information_list;
	struct snssai_s *mapped_home_snssai;
} allowed_snssai_t;

allowed_snssai_t *allowed_snssai_create(snssai_t	*allowed_snssai,
                                        list_t		*nsi_information_list,
                                        snssai_t	*mapped_home_snssai);
void allowed_snssai_free(allowed_snssai_t *allowed_snssai);
allowed_snssai_t *allowed_snssai_parseFromJSON(cJSON *allowed_snssaiJSON);
cJSON *allowed_snssai_convertToJSON(allowed_snssai_t *allowed_snssai);
allowed_snssai_t *allowed_snssai_copy(allowed_snssai_t	*dst,
                                      allowed_snssai_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _allowed_snssai_H_ */
