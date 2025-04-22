/*
 * reported_event_type.h
 *
 *
 */

#ifndef _reported_event_type_H_
#define _reported_event_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { reported_event_type_NULL = 0, reported_event_type_PERIODIC_EVENT,
	       reported_event_type_ENTERING_AREA_EVENT,
	       reported_event_type_LEAVING_AREA_EVENT,
	       reported_event_type_BEING_INSIDE_AREA_EVENT,
	       reported_event_type_MOTION_EVENT,
	       reported_event_type_MAXIMUM_INTERVAL_EXPIRATION_EVENT,
	       reported_event_type_LOCATION_CANCELLATION_EVENT,
	       reported_event_type_INTERMEDIATE_EVENT,
	       reported_event_type_DIRECT_REPORT_EVENT,
	       reported_event_type_CUMULATIVE_EVENT_REPORT }
reported_event_type_e;

char *reported_event_type_ToString(reported_event_type_e reported_event_type);

reported_event_type_e reported_event_type_FromString(char *reported_event_type);

#ifdef __cplusplus
}
#endif

#endif /* _reported_event_type_H_ */
