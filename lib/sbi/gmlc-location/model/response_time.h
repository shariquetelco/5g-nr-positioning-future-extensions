/*
 * response_time.h
 *
 *
 */

#ifndef _response_time_H_
#define _response_time_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { response_time_NULL = 0, response_time_LOW_DELAY,
	       response_time_DELAY_TOLERANT,
	       response_time_NO_DELAY } response_time_e;

char *response_time_ToString(response_time_e response_time);

response_time_e response_time_FromString(char *response_time);

#ifdef __cplusplus
}
#endif

#endif /* _response_time_H_ */
