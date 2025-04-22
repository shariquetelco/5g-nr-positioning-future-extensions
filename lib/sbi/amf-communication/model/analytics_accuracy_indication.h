/*
 * analytics_accuracy_indication.h
 *
 * Represents the notification methods for the subscribed events.   Possible values are: - MEET: Indicates meet the analytics accuracy requirement. - NOT_MEET: Indicates not meet the analytics accuracy requirement.
 */

#ifndef _analytics_accuracy_indication_H_
#define _analytics_accuracy_indication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "analytics_accuracy_indication_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct analytics_accuracy_indication_s analytics_accuracy_indication_t;
typedef struct analytics_accuracy_indication_s {}
analytics_accuracy_indication_t;

analytics_accuracy_indication_t *analytics_accuracy_indication_create();
void analytics_accuracy_indication_free(
	analytics_accuracy_indication_t *analytics_accuracy_indication);
analytics_accuracy_indication_t *analytics_accuracy_indication_parseFromJSON(
	cJSON *analytics_accuracy_indicationJSON);
cJSON *analytics_accuracy_indication_convertToJSON(
	analytics_accuracy_indication_t *analytics_accuracy_indication);
analytics_accuracy_indication_t *analytics_accuracy_indication_copy(
	analytics_accuracy_indication_t *dst,
	analytics_accuracy_indication_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_accuracy_indication_H_ */
