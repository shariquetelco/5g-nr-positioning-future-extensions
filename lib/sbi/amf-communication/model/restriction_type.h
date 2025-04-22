/*
 * restriction_type.h
 *
 * It contains the restriction type ALLOWED_AREAS or NOT_ALLOWED_AREAS.
 */

#ifndef _restriction_type_H_
#define _restriction_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "restriction_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct restriction_type_s restriction_type_t;
typedef struct restriction_type_s {} restriction_type_t;

restriction_type_t *restriction_type_create();
void restriction_type_free(restriction_type_t *restriction_type);
restriction_type_t *restriction_type_parseFromJSON(cJSON *restriction_typeJSON);
cJSON *restriction_type_convertToJSON(restriction_type_t *restriction_type);
restriction_type_t *restriction_type_copy(restriction_type_t	*dst,
                                          restriction_type_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _restriction_type_H_ */
