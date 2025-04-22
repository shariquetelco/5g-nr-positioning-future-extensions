/*
 * valid_time_period.h
 *
 *
 */

#ifndef _valid_time_period_H_
#define _valid_time_period_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct valid_time_period_s valid_time_period_t;
typedef struct valid_time_period_s {
	char *start_time;
	char *end_time;
} valid_time_period_t;

valid_time_period_t *valid_time_period_create(char *start_time, char *end_time);
void valid_time_period_free(valid_time_period_t *valid_time_period);
valid_time_period_t *valid_time_period_parseFromJSON(
	cJSON *valid_time_periodJSON);
cJSON *valid_time_period_convertToJSON(valid_time_period_t *valid_time_period);
valid_time_period_t *valid_time_period_copy(valid_time_period_t *dst,
                                            valid_time_period_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _valid_time_period_H_ */
