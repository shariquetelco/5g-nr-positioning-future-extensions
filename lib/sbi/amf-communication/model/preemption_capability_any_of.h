/*
 * preemption_capability_any_of.h
 *
 *
 */

#ifndef _preemption_capability_any_of_H_
#define _preemption_capability_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { preemption_capability_any_of_NULL = 0,
	       preemption_capability_any_of_NOT_PREEMPT,
	       preemption_capability_any_of_MAY_PREEMPT }
preemption_capability_any_of_e;

char *preemption_capability_any_of_ToString(
	preemption_capability_any_of_e preemption_capability_any_of);

preemption_capability_any_of_e preemption_capability_any_of_FromString(
	char *preemption_capability_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _preemption_capability_any_of_H_ */
