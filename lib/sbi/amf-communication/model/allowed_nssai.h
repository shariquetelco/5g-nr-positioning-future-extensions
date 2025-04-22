/*
 * allowed_nssai.h
 *
 * Contains an array of allowed S-NSSAI that constitute the allowed NSSAI information for the authorized network slice information
 */

#ifndef _allowed_nssai_H_
#define _allowed_nssai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "allowed_snssai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct allowed_nssai_s allowed_nssai_t;
typedef struct allowed_nssai_s {
	list_t *allowed_snssai_list;
	access_type_e access_type;
} allowed_nssai_t;

allowed_nssai_t *allowed_nssai_create(list_t		*allowed_snssai_list,
                                      access_type_e	access_type);
void allowed_nssai_free(allowed_nssai_t *allowed_nssai);
allowed_nssai_t *allowed_nssai_parseFromJSON(cJSON *allowed_nssaiJSON);
cJSON *allowed_nssai_convertToJSON(allowed_nssai_t *allowed_nssai);
allowed_nssai_t *allowed_nssai_copy(allowed_nssai_t *dst, allowed_nssai_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _allowed_nssai_H_ */
