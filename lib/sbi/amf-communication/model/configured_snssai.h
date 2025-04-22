/*
 * configured_snssai.h
 *
 * Contains the configured S-NSSAI(s) authorized by the NSSF in the serving PLMN and optional mapped home S-NSSAI
 */

#ifndef _configured_snssai_H_
#define _configured_snssai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct configured_snssai_s configured_snssai_t;
typedef struct configured_snssai_s {
	struct snssai_s *configured_snssai;
	struct snssai_s *mapped_home_snssai;
} configured_snssai_t;

configured_snssai_t *configured_snssai_create(snssai_t	*configured_snssai,
                                              snssai_t	*mapped_home_snssai);
void configured_snssai_free(configured_snssai_t *configured_snssai);
configured_snssai_t *configured_snssai_parseFromJSON(
	cJSON *configured_snssaiJSON);
cJSON *configured_snssai_convertToJSON(configured_snssai_t *configured_snssai);
configured_snssai_t *configured_snssai_copy(configured_snssai_t *dst,
                                            configured_snssai_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _configured_snssai_H_ */
