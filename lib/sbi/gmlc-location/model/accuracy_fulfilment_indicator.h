/*
 * accuracy_fulfilment_indicator.h
 *
 *
 */

#ifndef _accuracy_fulfilment_indicator_H_
#define _accuracy_fulfilment_indicator_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { accuracy_fulfilment_indicator_NULL = 0,
	       accuracy_fulfilment_indicator_REQUESTED_ACCURACY_FULFILLED,
	       accuracy_fulfilment_indicator_REQUESTED_ACCURACY_NOT_FULFILLED }
accuracy_fulfilment_indicator_e;

char *accuracy_fulfilment_indicator_ToString(
	accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator);

accuracy_fulfilment_indicator_e accuracy_fulfilment_indicator_FromString(
	char *accuracy_fulfilment_indicator);

#ifdef __cplusplus
}
#endif

#endif /* _accuracy_fulfilment_indicator_H_ */
