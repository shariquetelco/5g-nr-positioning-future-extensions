/*
 * expected_analytics_type.h
 *
 * Represents the expected UE analytics type.   Possible values are: - MOBILITY: Mobility related abnormal behaviour analytics is expected by the consumer. - COMMUN: Communication related abnormal behaviour analytics is expected by the consumer. - MOBILITY_AND_COMMUN: Both mobility and communication related abnormal behaviour analytics   is expected by the consumer.
 */

#ifndef _expected_analytics_type_H_
#define _expected_analytics_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "expected_analytics_type_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct expected_analytics_type_s expected_analytics_type_t;
typedef struct expected_analytics_type_s {} expected_analytics_type_t;

expected_analytics_type_t *expected_analytics_type_create();
void expected_analytics_type_free(
	expected_analytics_type_t *expected_analytics_type);
expected_analytics_type_t *expected_analytics_type_parseFromJSON(
	cJSON *expected_analytics_typeJSON);
cJSON *expected_analytics_type_convertToJSON(
	expected_analytics_type_t *expected_analytics_type);
expected_analytics_type_t *expected_analytics_type_copy(
	expected_analytics_type_t *dst, expected_analytics_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _expected_analytics_type_H_ */
