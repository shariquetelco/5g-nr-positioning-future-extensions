#ifndef SBI_OBJECT_H
#define SBI_OBJECT_H

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct object_s {
    void *temporary;
} object_t;

object_t *object_create(void);

void object_free(object_t *object);

object_t *object_parseFromJSON(cJSON *json);

cJSON *object_convertToJSON(object_t *object);

#ifdef __cplusplus
}
#endif

#endif /* SBI_OBJECT_H */
