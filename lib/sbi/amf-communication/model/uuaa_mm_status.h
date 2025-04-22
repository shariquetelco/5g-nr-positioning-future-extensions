/*
 * uuaa_mm_status.h
 *
 *
 */

#ifndef _uuaa_mm_status_H_
#define _uuaa_mm_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { uuaa_mm_status_NULL = 0, uuaa_mm_status_SUCCESS,
	       uuaa_mm_status_PENDING, uuaa_mm_status_FAILED } uuaa_mm_status_e;

char *uuaa_mm_status_ToString(uuaa_mm_status_e uuaa_mm_status);

uuaa_mm_status_e uuaa_mm_status_FromString(char *uuaa_mm_status);

#ifdef __cplusplus
}
#endif

#endif /* _uuaa_mm_status_H_ */
