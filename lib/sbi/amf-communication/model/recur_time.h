/*
 * recur_time.h
 *
 *
 */

#ifndef _recur_time_H_
#define _recur_time_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "recur_type.h"
#include "valid_time_period.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct recur_time_s recur_time_t;
typedef struct recur_time_s {
	struct valid_time_period_s *recur_time_window;
	struct recur_type_s *recur_type;
	list_t *recur_month;
	list_t *recur_week;
	list_t *recur_day;
	list_t *recur_date;
} recur_time_t;

recur_time_t *recur_time_create(valid_time_period_t *recur_time_window,
                                recur_type_t *recur_type, list_t *recur_month,
                                list_t *recur_week, list_t *recur_day,
                                list_t *recur_date);
void recur_time_free(recur_time_t *recur_time);
recur_time_t *recur_time_parseFromJSON(cJSON *recur_timeJSON);
cJSON *recur_time_convertToJSON(recur_time_t *recur_time);
recur_time_t *recur_time_copy(recur_time_t *dst, recur_time_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _recur_time_H_ */
