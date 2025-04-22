/*
 * time_source.h
 *
 * Indicates the Time Source.
 */

#ifndef _time_source_H_
#define _time_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "time_source_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct time_source_s time_source_t;
typedef struct time_source_s {} time_source_t;

time_source_t *time_source_create();
void time_source_free(time_source_t *time_source);
time_source_t *time_source_parseFromJSON(cJSON *time_sourceJSON);
cJSON *time_source_convertToJSON(time_source_t *time_source);
time_source_t *time_source_copy(time_source_t *dst, time_source_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _time_source_H_ */
