/*
 * expected_analytics_type_any_of.h
 *
 *
 */

#ifndef _expected_analytics_type_any_of_H_
#define _expected_analytics_type_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { expected_analytics_type_any_of_NULL = 0,
	       expected_analytics_type_any_of_MOBILITY,
	       expected_analytics_type_any_of_COMMUN,
	       expected_analytics_type_any_of_MOBILITY_AND_COMMUN }
expected_analytics_type_any_of_e;

char *expected_analytics_type_any_of_ToString(
	expected_analytics_type_any_of_e expected_analytics_type_any_of);

expected_analytics_type_any_of_e expected_analytics_type_any_of_FromString(
	char *expected_analytics_type_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _expected_analytics_type_any_of_H_ */
