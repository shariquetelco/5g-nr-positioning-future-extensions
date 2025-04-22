/*
 * clock_quality_detail_level_any_of.h
 *
 *
 */

#ifndef _clock_quality_detail_level_any_of_H_
#define _clock_quality_detail_level_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { clock_quality_detail_level_any_of_NULL = 0,
	       clock_quality_detail_level_any_of_CLOCK_QUALITY_METRICS,
	       clock_quality_detail_level_any_of_ACCEPT_INDICATION }
clock_quality_detail_level_any_of_e;

char *clock_quality_detail_level_any_of_ToString(
	clock_quality_detail_level_any_of_e clock_quality_detail_level_any_of);

clock_quality_detail_level_any_of_e clock_quality_detail_level_any_of_FromString(
	char *clock_quality_detail_level_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _clock_quality_detail_level_any_of_H_ */
