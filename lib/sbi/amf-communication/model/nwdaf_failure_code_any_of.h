/*
 * nwdaf_failure_code_any_of.h
 *
 *
 */

#ifndef _nwdaf_failure_code_any_of_H_
#define _nwdaf_failure_code_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { nwdaf_failure_code_any_of_NULL = 0,
	       nwdaf_failure_code_any_of_UNAVAILABLE_DATA,
	       nwdaf_failure_code_any_of_BOTH_STAT_PRED_NOT_ALLOWED,
	       nwdaf_failure_code_any_of_PREDICTION_NOT_ALLOWED,
	       nwdaf_failure_code_any_of_UNSATISFIED_REQUESTED_ANALYTICS_TIME,
	       nwdaf_failure_code_any_of_NO_ROAMING_SUPPORT,
	       nwdaf_failure_code_any_of_OTHER } nwdaf_failure_code_any_of_e;

char *nwdaf_failure_code_any_of_ToString(
	nwdaf_failure_code_any_of_e nwdaf_failure_code_any_of);

nwdaf_failure_code_any_of_e nwdaf_failure_code_any_of_FromString(
	char *nwdaf_failure_code_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _nwdaf_failure_code_any_of_H_ */
