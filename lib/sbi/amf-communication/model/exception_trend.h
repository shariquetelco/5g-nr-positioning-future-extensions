/*
 * exception_trend.h
 *
 * Represents the Exception Trend.   Possible values are: - UP: Up trend of the exception level. - DOWN: Down trend of the exception level. - UNKNOW: Unknown trend of the exception level. - STABLE: Stable trend of the exception level.
 */

#ifndef _exception_trend_H_
#define _exception_trend_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "exception_trend_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct exception_trend_s exception_trend_t;
typedef struct exception_trend_s {} exception_trend_t;

exception_trend_t *exception_trend_create();
void exception_trend_free(exception_trend_t *exception_trend);
exception_trend_t *exception_trend_parseFromJSON(cJSON *exception_trendJSON);
cJSON *exception_trend_convertToJSON(exception_trend_t *exception_trend);
exception_trend_t *exception_trend_copy(exception_trend_t	*dst,
                                        exception_trend_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _exception_trend_H_ */
