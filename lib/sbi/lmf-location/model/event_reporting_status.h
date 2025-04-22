/*
 * event_reporting_status.h
 *
 * Indicates the status of event reporting.
 */

#ifndef _event_reporting_status_H_
#define _event_reporting_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct event_reporting_status_s event_reporting_status_t;
typedef struct event_reporting_status_s {
	bool is_event_report_counter;
	int event_report_counter;
	bool is_event_report_duration;
	int event_report_duration;
} event_reporting_status_t;

event_reporting_status_t *event_reporting_status_create(
	bool is_event_report_counter, int event_report_counter,
	bool is_event_report_duration, int event_report_duration);
void event_reporting_status_free(
	event_reporting_status_t *event_reporting_status);
event_reporting_status_t *event_reporting_status_parseFromJSON(
	cJSON *event_reporting_statusJSON);
cJSON *event_reporting_status_convertToJSON(
	event_reporting_status_t *event_reporting_status);
event_reporting_status_t *event_reporting_status_copy(
	event_reporting_status_t *dst, event_reporting_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _event_reporting_status_H_ */
