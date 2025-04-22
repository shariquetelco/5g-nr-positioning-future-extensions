/*
 * output_strategy.h
 *
 * Represents the output strategy used for the analytics reporting.   Possible values are: - BINARY: Indicates that the analytics shall only be reported when the requested level   of accuracy is reached within a cycle of periodic notification. - GRADIENT: Indicates that the analytics shall be reported according with the periodicity   irrespective of whether the requested level of accuracy has been reached or not.
 */

#ifndef _output_strategy_H_
#define _output_strategy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "output_strategy_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct output_strategy_s output_strategy_t;
typedef struct output_strategy_s {} output_strategy_t;

output_strategy_t *output_strategy_create();
void output_strategy_free(output_strategy_t *output_strategy);
output_strategy_t *output_strategy_parseFromJSON(cJSON *output_strategyJSON);
cJSON *output_strategy_convertToJSON(output_strategy_t *output_strategy);
output_strategy_t *output_strategy_copy(output_strategy_t	*dst,
                                        output_strategy_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _output_strategy_H_ */
