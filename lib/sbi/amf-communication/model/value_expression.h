/*
 * value_expression.h
 *
 * Represents the average or peak value of the resource usage for the network performance type.   Possible values are:     - AVERAGE: Resource usage information in average value.   - PEAK: Resource usage information in peak value.
 */

#ifndef _value_expression_H_
#define _value_expression_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "value_expression_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct value_expression_s value_expression_t;
typedef struct value_expression_s {} value_expression_t;

value_expression_t *value_expression_create();
void value_expression_free(value_expression_t *value_expression);
value_expression_t *value_expression_parseFromJSON(cJSON *value_expressionJSON);
cJSON *value_expression_convertToJSON(value_expression_t *value_expression);
value_expression_t *value_expression_copy(value_expression_t	*dst,
                                          value_expression_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _value_expression_H_ */
