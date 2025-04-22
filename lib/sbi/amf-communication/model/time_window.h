/*
 * time_window.h
 *
 * Represents a time window identified by a start time and a stop time.
 */

#ifndef _time_window_H_
#define _time_window_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct time_window_s time_window_t;
typedef struct time_window_s {
	char *start_time;
	char *stop_time;
} time_window_t;

time_window_t *time_window_create(char *start_time, char *stop_time);
void time_window_free(time_window_t *time_window);
time_window_t *time_window_parseFromJSON(cJSON *time_windowJSON);
cJSON *time_window_convertToJSON(time_window_t *time_window);
time_window_t *time_window_copy(time_window_t *dst, time_window_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _time_window_H_ */
