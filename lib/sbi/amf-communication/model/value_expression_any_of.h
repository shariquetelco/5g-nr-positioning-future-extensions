/*
 * value_expression_any_of.h
 *
 *
 */

#ifndef _value_expression_any_of_H_
#define _value_expression_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { value_expression_any_of_NULL = 0,
	       value_expression_any_of_AVERAGE,
	       value_expression_any_of_PEAK } value_expression_any_of_e;

char *value_expression_any_of_ToString(
	value_expression_any_of_e value_expression_any_of);

value_expression_any_of_e value_expression_any_of_FromString(
	char *value_expression_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _value_expression_any_of_H_ */
