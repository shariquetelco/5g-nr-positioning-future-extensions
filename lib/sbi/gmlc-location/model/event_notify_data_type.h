/*
 * event_notify_data_type.h
 *
 *
 */

#ifndef _event_notify_data_type_H_
#define _event_notify_data_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { event_notify_data_type_NULL = 0,
	       event_notify_data_type_UE_AVAILABLE,
	       event_notify_data_type_PERIODIC,
	       event_notify_data_type_ENTERING_INTO_AREA,
	       event_notify_data_type_LEAVING_FROM_AREA,
	       event_notify_data_type_BEING_INSIDE_AREA,
	       event_notify_data_type_MOTION,
	       event_notify_data_type_MAXIMUM_INTERVAL_EXPIRATION_EVENT,
	       event_notify_data_type_LOCATION_CANCELLATION_EVENT,
	       event_notify_data_type_ACTIVATION_OF_DEFERRED_LOCATION,
	       event_notify_data_type_UE_MOBILITY_FOR_DEFERRED_LOCATION,
	       event_notify_data_type__5GC_MT_LR,
	       event_notify_data_type_DIRECT_REPORT_EVENT,
	       event_notify_data_type_CUMULATIVE_EVENT_REPORT }
event_notify_data_type_e;

char *event_notify_data_type_ToString(
	event_notify_data_type_e event_notify_data_type);

event_notify_data_type_e event_notify_data_type_FromString(
	char *event_notify_data_type);

#ifdef __cplusplus
}
#endif

#endif /* _event_notify_data_type_H_ */
