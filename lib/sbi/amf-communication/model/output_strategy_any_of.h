/*
 * output_strategy_any_of.h
 *
 *
 */

#ifndef _output_strategy_any_of_H_
#define _output_strategy_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { output_strategy_any_of_NULL = 0, output_strategy_any_of_BINARY,
	       output_strategy_any_of_GRADIENT } output_strategy_any_of_e;

char *output_strategy_any_of_ToString(
	output_strategy_any_of_e output_strategy_any_of);

output_strategy_any_of_e output_strategy_any_of_FromString(
	char *output_strategy_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _output_strategy_any_of_H_ */
