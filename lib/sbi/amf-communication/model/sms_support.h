/*
 * sms_support.h
 *
 *
 */

#ifndef _sms_support_H_
#define _sms_support_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { sms_support_NULL = 0, sms_support__3GPP, sms_support_NON_3GPP,
	       sms_support_BOTH, sms_support_NONE } sms_support_e;

char *sms_support_ToString(sms_support_e sms_support);

sms_support_e sms_support_FromString(char *sms_support);

#ifdef __cplusplus
}
#endif

#endif /* _sms_support_H_ */
