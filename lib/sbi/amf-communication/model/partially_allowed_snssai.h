/*
 * partially_allowed_snssai.h
 *
 * Indicates a S-NSSAI that is partially allowed in the Registration Area.
 */

#ifndef _partially_allowed_snssai_H_
#define _partially_allowed_snssai_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "snssai.h"
#include "tai.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct partially_allowed_snssai_s partially_allowed_snssai_t;
typedef struct partially_allowed_snssai_s {
	struct snssai_s *snssai;
	list_t *allowed_tai_list;
} partially_allowed_snssai_t;

partially_allowed_snssai_t *partially_allowed_snssai_create(snssai_t	*snssai,
                                                            list_t	*allowed_tai_list);
void partially_allowed_snssai_free(
	partially_allowed_snssai_t *partially_allowed_snssai);
partially_allowed_snssai_t *partially_allowed_snssai_parseFromJSON(
	cJSON *partially_allowed_snssaiJSON);
cJSON *partially_allowed_snssai_convertToJSON(
	partially_allowed_snssai_t *partially_allowed_snssai);
partially_allowed_snssai_t *partially_allowed_snssai_copy(
	partially_allowed_snssai_t *dst, partially_allowed_snssai_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _partially_allowed_snssai_H_ */
