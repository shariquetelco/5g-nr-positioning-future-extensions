/*
 * ranging_sl_result.h
 *
 *
 */

#ifndef _ranging_sl_result_H_
#define _ranging_sl_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ranging_sl_result_NULL = 0, ranging_sl_result_ABSOLUTE_LOCATION,
	       ranging_sl_result_RELATIVE_LOCATION,
	       ranging_sl_result_RANGING_DIRECTION, ranging_sl_result_RANGING,
	       ranging_sl_result_DIRECTION, ranging_sl_result_VELOCITY,
	       ranging_sl_result_RELATIVE_VELOCITY } ranging_sl_result_e;

char *ranging_sl_result_ToString(ranging_sl_result_e ranging_sl_result);

ranging_sl_result_e ranging_sl_result_FromString(char *ranging_sl_result);

#ifdef __cplusplus
}
#endif

#endif /* _ranging_sl_result_H_ */
