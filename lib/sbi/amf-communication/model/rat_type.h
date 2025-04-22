/*
 * rat_type.h
 *
 * Indicates the radio access used.
 */

#ifndef _rat_type_H_
#define _rat_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "rat_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rat_type_s rat_type_t;
typedef struct rat_type_s {} rat_type_t;

rat_type_t *rat_type_create();
void rat_type_free(rat_type_t *rat_type);
rat_type_t *rat_type_parseFromJSON(cJSON *rat_typeJSON);
cJSON *rat_type_convertToJSON(rat_type_t *rat_type);
rat_type_t *rat_type_copy(rat_type_t *dst, rat_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _rat_type_H_ */
