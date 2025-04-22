/*
 * stationary_indication_any_of.h
 *
 *
 */

#ifndef _stationary_indication_any_of_H_
#define _stationary_indication_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { stationary_indication_any_of_NULL = 0,
	       stationary_indication_any_of_STATIONARY,
	       stationary_indication_any_of_MOBILE }
stationary_indication_any_of_e;

char *stationary_indication_any_of_ToString(
	stationary_indication_any_of_e stationary_indication_any_of);

stationary_indication_any_of_e stationary_indication_any_of_FromString(
	char *stationary_indication_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _stationary_indication_any_of_H_ */
