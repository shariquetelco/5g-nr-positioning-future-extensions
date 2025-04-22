/*
 * release_cause.h
 *
 *
 */

#ifndef _release_cause_H_
#define _release_cause_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { release_cause_NULL = 0, release_cause_SNPN_SNPN_MOBILITY,
	       release_cause_NO_HR_AGREEMENT,
	       release_cause_UNSPECIFIED } release_cause_e;

char *release_cause_ToString(release_cause_e release_cause);

release_cause_e release_cause_FromString(char *release_cause);

#ifdef __cplusplus
}
#endif

#endif /* _release_cause_H_ */
