/*
 * notification_method_any_of.h
 *
 *
 */

#ifndef _notification_method_any_of_H_
#define _notification_method_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { notification_method_any_of_NULL = 0,
	       notification_method_any_of_PERIODIC,
	       notification_method_any_of_THRESHOLD }
notification_method_any_of_e;

char *notification_method_any_of_ToString(
	notification_method_any_of_e notification_method_any_of);

notification_method_any_of_e notification_method_any_of_FromString(
	char *notification_method_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _notification_method_any_of_H_ */
