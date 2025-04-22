/*
 * scheduled_communication_time.h
 *
 * Identifies time and day of the week when the UE is available for communication.
 */

#ifndef _scheduled_communication_time_H_
#define _scheduled_communication_time_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct scheduled_communication_time_s scheduled_communication_time_t;
typedef struct scheduled_communication_time_s {
	list_t *days_of_week;
	char *time_of_day_start;
	char *time_of_day_end;
} scheduled_communication_time_t;

scheduled_communication_time_t *scheduled_communication_time_create(
	list_t *days_of_week, char *time_of_day_start, char *time_of_day_end);
void scheduled_communication_time_free(
	scheduled_communication_time_t *scheduled_communication_time);
scheduled_communication_time_t *scheduled_communication_time_parseFromJSON(
	cJSON *scheduled_communication_timeJSON);
cJSON *scheduled_communication_time_convertToJSON(
	scheduled_communication_time_t *scheduled_communication_time);
scheduled_communication_time_t *scheduled_communication_time_copy(
	scheduled_communication_time_t	*dst,
	scheduled_communication_time_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _scheduled_communication_time_H_ */
