/*
 * scheduled_communication_time_1.h
 *
 * Represents an offered scheduled communication time.
 */

#ifndef _scheduled_communication_time_1_H_
#define _scheduled_communication_time_1_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct scheduled_communication_time_1_s scheduled_communication_time_1_t;
typedef struct scheduled_communication_time_1_s {
	list_t *days_of_week;
	char *time_of_day_start;
	char *time_of_day_end;
} scheduled_communication_time_1_t;

scheduled_communication_time_1_t *scheduled_communication_time_1_create(
	list_t *days_of_week, char *time_of_day_start, char *time_of_day_end);
void scheduled_communication_time_1_free(
	scheduled_communication_time_1_t *scheduled_communication_time_1);
scheduled_communication_time_1_t *scheduled_communication_time_1_parseFromJSON(
	cJSON *scheduled_communication_time_1JSON);
cJSON *scheduled_communication_time_1_convertToJSON(
	scheduled_communication_time_1_t *scheduled_communication_time_1);
scheduled_communication_time_1_t *scheduled_communication_time_1_copy(
	scheduled_communication_time_1_t	*dst,
	scheduled_communication_time_1_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _scheduled_communication_time_1_H_ */
