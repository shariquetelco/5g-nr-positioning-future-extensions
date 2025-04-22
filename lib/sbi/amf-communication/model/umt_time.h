/*
 * umt_time.h
 *
 *
 */

#ifndef _umt_time_H_
#define _umt_time_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct umt_time_s umt_time_t;
typedef struct umt_time_s {
	char *time_of_day;
	int day_of_week;
} umt_time_t;

umt_time_t *umt_time_create(char *time_of_day, int day_of_week);
void umt_time_free(umt_time_t *umt_time);
umt_time_t *umt_time_parseFromJSON(cJSON *umt_timeJSON);
cJSON *umt_time_convertToJSON(umt_time_t *umt_time);
umt_time_t *umt_time_copy(umt_time_t *dst, umt_time_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _umt_time_H_ */
