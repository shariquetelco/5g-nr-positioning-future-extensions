/*
 * n2_info_notify_reason.h
 *
 *
 */

#ifndef _n2_info_notify_reason_H_
#define _n2_info_notify_reason_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { n2_info_notify_reason_NULL = 0,
	       n2_info_notify_reason_HANDOVER_COMPLETED }
n2_info_notify_reason_e;

char *n2_info_notify_reason_ToString(
	n2_info_notify_reason_e n2_info_notify_reason);

n2_info_notify_reason_e n2_info_notify_reason_FromString(
	char *n2_info_notify_reason);

#ifdef __cplusplus
}
#endif

#endif /* _n2_info_notify_reason_H_ */
