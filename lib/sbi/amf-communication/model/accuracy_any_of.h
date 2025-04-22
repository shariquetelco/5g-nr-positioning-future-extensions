/*
 * accuracy_any_of.h
 *
 *
 */

#ifndef _accuracy_any_of_H_
#define _accuracy_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { accuracy_any_of_NULL = 0, accuracy_any_of_LOW,
	       accuracy_any_of_MEDIUM, accuracy_any_of_HIGH,
	       accuracy_any_of_HIGHEST } accuracy_any_of_e;

char *accuracy_any_of_ToString(accuracy_any_of_e accuracy_any_of);

accuracy_any_of_e accuracy_any_of_FromString(char *accuracy_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _accuracy_any_of_H_ */
