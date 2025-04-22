/*
 * recur_type_any_of.h
 *
 *
 */

#ifndef _recur_type_any_of_H_
#define _recur_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { recur_type_any_of_NULL = 0, recur_type_any_of_DAILY,
	       recur_type_any_of_WEEKLY, recur_type_any_of_MONTHLY_BY_DATE,
	       recur_type_any_of_MONTHLY_BY_DAY, recur_type_any_of_YEARLY,
	       recur_type_any_of_WEEKDAYS_ONLY,
	       recur_type_any_of_WEEKENDS_ONLY } recur_type_any_of_e;

char *recur_type_any_of_ToString(recur_type_any_of_e recur_type_any_of);

recur_type_any_of_e recur_type_any_of_FromString(char *recur_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _recur_type_any_of_H_ */
