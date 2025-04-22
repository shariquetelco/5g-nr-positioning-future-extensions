/*
 * time_unit_any_of.h
 *
 *
 */

#ifndef _time_unit_any_of_H_
#define _time_unit_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { time_unit_any_of_NULL = 0, time_unit_any_of_MINUTE,
	       time_unit_any_of_HOUR, time_unit_any_of_DAY } time_unit_any_of_e;

char *time_unit_any_of_ToString(time_unit_any_of_e time_unit_any_of);

time_unit_any_of_e time_unit_any_of_FromString(char *time_unit_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _time_unit_any_of_H_ */
