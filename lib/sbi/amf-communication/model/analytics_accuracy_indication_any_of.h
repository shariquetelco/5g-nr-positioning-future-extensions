/*
 * analytics_accuracy_indication_any_of.h
 *
 *
 */

#ifndef _analytics_accuracy_indication_any_of_H_
#define _analytics_accuracy_indication_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { analytics_accuracy_indication_any_of_NULL = 0,
	       analytics_accuracy_indication_any_of_MEET,
	       analytics_accuracy_indication_any_of_NOT_MEET }
analytics_accuracy_indication_any_of_e;

char *analytics_accuracy_indication_any_of_ToString(
	analytics_accuracy_indication_any_of_e analytics_accuracy_indication_any_of);

analytics_accuracy_indication_any_of_e
analytics_accuracy_indication_any_of_FromString(
	char *analytics_accuracy_indication_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _analytics_accuracy_indication_any_of_H_ */
