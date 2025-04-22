/*
 * ue_type.h
 *
 * Describes the type of UEs
 */

#ifndef _ue_type_H_
#define _ue_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_type_s ue_type_t;
typedef struct ue_type_s {} ue_type_t;

ue_type_t *ue_type_create();
void ue_type_free(ue_type_t *ue_type);
ue_type_t *ue_type_parseFromJSON(cJSON *ue_typeJSON);
cJSON *ue_type_convertToJSON(ue_type_t *ue_type);
ue_type_t *ue_type_copy(ue_type_t *dst, ue_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_type_H_ */
