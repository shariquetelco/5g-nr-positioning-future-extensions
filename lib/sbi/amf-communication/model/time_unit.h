/*
 * time_unit.h
 *
 * Represents the unit for the session active time.   Possible values are: - MINUTE: Time unit is per minute. - HOUR: Time unit is per hour. - DAY: Time unit is per day.
 */

#ifndef _time_unit_H_
#define _time_unit_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "time_unit_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct time_unit_s time_unit_t;
typedef struct time_unit_s {} time_unit_t;

time_unit_t *time_unit_create();
void time_unit_free(time_unit_t *time_unit);
time_unit_t *time_unit_parseFromJSON(cJSON *time_unitJSON);
cJSON *time_unit_convertToJSON(time_unit_t *time_unit);
time_unit_t *time_unit_copy(time_unit_t *dst, time_unit_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _time_unit_H_ */
