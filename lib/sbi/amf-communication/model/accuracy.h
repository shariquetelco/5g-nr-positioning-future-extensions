/*
 * accuracy.h
 *
 * Represents the preferred level of accuracy of the analytics.   Possible values are: - LOW: Low accuracy. - MEDIUM: Medium accuracy. - HIGH: High accuracy. - HIGHEST: Highest accuracy.
 */

#ifndef _accuracy_H_
#define _accuracy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "accuracy_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct accuracy_s accuracy_t;
typedef struct accuracy_s {} accuracy_t;

accuracy_t *accuracy_create();
void accuracy_free(accuracy_t *accuracy);
accuracy_t *accuracy_parseFromJSON(cJSON *accuracyJSON);
cJSON *accuracy_convertToJSON(accuracy_t *accuracy);
accuracy_t *accuracy_copy(accuracy_t *dst, accuracy_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _accuracy_H_ */
