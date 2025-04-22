/*
 * termination_cause.h
 *
 *
 */

#ifndef _termination_cause_H_
#define _termination_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { termination_cause_NULL = 0, termination_cause_TERMINATION_BY_UE,
	       termination_cause_TERMINATION_BY_NETWORK,
	       termination_cause_NORMAL_TERMINATION } termination_cause_e;

char *termination_cause_ToString(termination_cause_e termination_cause);

termination_cause_e termination_cause_FromString(char *termination_cause);

#ifdef __cplusplus
}
#endif

#endif /* _termination_cause_H_ */
