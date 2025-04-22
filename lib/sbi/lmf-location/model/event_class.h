/*
 * event_class.h
 *
 *
 */

#ifndef _event_class_H_
#define _event_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { event_class_NULL = 0,
	       event_class_SUPPLEMENTARY_SERVICES } event_class_e;

char *event_class_ToString(event_class_e event_class);

event_class_e event_class_FromString(char *event_class);

#ifdef __cplusplus
}
#endif

#endif /* _event_class_H_ */
