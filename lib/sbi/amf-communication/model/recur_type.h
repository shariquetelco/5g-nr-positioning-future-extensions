/*
 * recur_type.h
 *
 * Indicates the recurrence applicable to a time window.
 */

#ifndef _recur_type_H_
#define _recur_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "recur_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct recur_type_s recur_type_t;
typedef struct recur_type_s {} recur_type_t;

recur_type_t *recur_type_create();
void recur_type_free(recur_type_t *recur_type);
recur_type_t *recur_type_parseFromJSON(cJSON *recur_typeJSON);
cJSON *recur_type_convertToJSON(recur_type_t *recur_type);
recur_type_t *recur_type_copy(recur_type_t *dst, recur_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _recur_type_H_ */
