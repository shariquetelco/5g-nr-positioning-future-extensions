/*
 * failure_cause.h
 *
 *
 */

#ifndef _failure_cause_H_
#define _failure_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { failure_cause_NULL = 0, failure_cause_POSITIONING_DENIED,
	       failure_cause_UNSUPPORTED_BY_UE, failure_cause_NOT_REGISTED_UE,
	       failure_cause_UNSPECIFIED } failure_cause_e;

char *failure_cause_ToString(failure_cause_e failure_cause);

failure_cause_e failure_cause_FromString(char *failure_cause);

#ifdef __cplusplus
}
#endif

#endif /* _failure_cause_H_ */
