/*
 * exception_trend_any_of.h
 *
 *
 */

#ifndef _exception_trend_any_of_H_
#define _exception_trend_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { exception_trend_any_of_NULL = 0, exception_trend_any_of_UP,
	       exception_trend_any_of_DOWN, exception_trend_any_of_UNKNOW,
	       exception_trend_any_of_STABLE } exception_trend_any_of_e;

char *exception_trend_any_of_ToString(
	exception_trend_any_of_e exception_trend_any_of);

exception_trend_any_of_e exception_trend_any_of_FromString(
	char *exception_trend_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _exception_trend_any_of_H_ */
