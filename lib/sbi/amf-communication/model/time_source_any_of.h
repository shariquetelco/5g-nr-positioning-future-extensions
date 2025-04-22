/*
 * time_source_any_of.h
 *
 *
 */

#ifndef _time_source_any_of_H_
#define _time_source_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { time_source_any_of_NULL = 0, time_source_any_of_SYNC_E,
	       time_source_any_of_PTP, time_source_any_of_GNSS,
	       time_source_any_of_ATOMIC_CLOCK,
	       time_source_any_of_TERRESTRIAL_RADIO,
	       time_source_any_of_SERIAL_TIME_CODE, time_source_any_of_NTP,
	       time_source_any_of_HAND_SET,
	       time_source_any_of_OTHER } time_source_any_of_e;

char *time_source_any_of_ToString(time_source_any_of_e time_source_any_of);

time_source_any_of_e time_source_any_of_FromString(char *time_source_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _time_source_any_of_H_ */
