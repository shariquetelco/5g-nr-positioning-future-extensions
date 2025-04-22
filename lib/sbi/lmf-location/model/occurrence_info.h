/*
 * occurrence_info.h
 *
 *
 */

#ifndef _occurrence_info_H_
#define _occurrence_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { occurrence_info_NULL = 0, occurrence_info_ONE_TIME_EVENT,
	       occurrence_info_MULTIPLE_TIME_EVENT } occurrence_info_e;

char *occurrence_info_ToString(occurrence_info_e occurrence_info);

occurrence_info_e occurrence_info_FromString(char *occurrence_info);

#ifdef __cplusplus
}
#endif

#endif /* _occurrence_info_H_ */
