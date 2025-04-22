/*
 * ngran_failure_info.h
 *
 *
 */

#ifndef _ngran_failure_info_H_
#define _ngran_failure_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ngran_failure_info_NULL = 0,
	       ngran_failure_info_NG_RAN_NOT_REACHABLE } ngran_failure_info_e;

char *ngran_failure_info_ToString(ngran_failure_info_e ngran_failure_info);

ngran_failure_info_e ngran_failure_info_FromString(char *ngran_failure_info);

#ifdef __cplusplus
}
#endif

#endif /* _ngran_failure_info_H_ */
