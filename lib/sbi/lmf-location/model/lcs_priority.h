/*
 * lcs_priority.h
 *
 *
 */

#ifndef _lcs_priority_H_
#define _lcs_priority_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { lcs_priority_NULL = 0, lcs_priority_HIGHEST_PRIORITY,
	       lcs_priority_NORMAL_PRIORITY } lcs_priority_e;

char *lcs_priority_ToString(lcs_priority_e lcs_priority);

lcs_priority_e lcs_priority_FromString(char *lcs_priority);

#ifdef __cplusplus
}
#endif

#endif /* _lcs_priority_H_ */
