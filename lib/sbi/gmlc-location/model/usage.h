/*
 * usage.h
 *
 *
 */

#ifndef _usage_H_
#define _usage_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { usage_NULL = 0, usage_UNSUCCESS, usage_SUCCESS_RESULTS_NOT_USED,
	       usage_SUCCESS_RESULTS_USED_TO_VERIFY_LOCATION,
	       usage_SUCCESS_RESULTS_USED_TO_GENERATE_LOCATION,
	       usage_SUCCESS_METHOD_NOT_DETERMINED } usage_e;

char *usage_ToString(usage_e usage);

usage_e usage_FromString(char *usage);

#ifdef __cplusplus
}
#endif

#endif /* _usage_H_ */
