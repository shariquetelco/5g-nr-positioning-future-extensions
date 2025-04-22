/*
 * notification_flag_any_of.h
 *
 *
 */

#ifndef _notification_flag_any_of_H_
#define _notification_flag_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { notification_flag_any_of_NULL = 0,
	       notification_flag_any_of_ACTIVATE,
	       notification_flag_any_of_DEACTIVATE,
	       notification_flag_any_of_RETRIEVAL } notification_flag_any_of_e;

char *notification_flag_any_of_ToString(
	notification_flag_any_of_e notification_flag_any_of);

notification_flag_any_of_e notification_flag_any_of_FromString(
	char *notification_flag_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _notification_flag_any_of_H_ */
