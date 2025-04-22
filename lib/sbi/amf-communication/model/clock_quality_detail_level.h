/*
 * clock_quality_detail_level.h
 *
 * Indicates the Clock Quality Detail Level.
 */

#ifndef _clock_quality_detail_level_H_
#define _clock_quality_detail_level_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "clock_quality_detail_level_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct clock_quality_detail_level_s clock_quality_detail_level_t;
typedef struct clock_quality_detail_level_s {} clock_quality_detail_level_t;

clock_quality_detail_level_t *clock_quality_detail_level_create();
void clock_quality_detail_level_free(
	clock_quality_detail_level_t *clock_quality_detail_level);
clock_quality_detail_level_t *clock_quality_detail_level_parseFromJSON(
	cJSON *clock_quality_detail_levelJSON);
cJSON *clock_quality_detail_level_convertToJSON(
	clock_quality_detail_level_t *clock_quality_detail_level);
clock_quality_detail_level_t *clock_quality_detail_level_copy(
	clock_quality_detail_level_t *dst, clock_quality_detail_level_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _clock_quality_detail_level_H_ */
