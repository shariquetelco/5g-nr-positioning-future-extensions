/*
 * number_average.h
 *
 * Represents average and variance information.
 */

#ifndef _number_average_H_
#define _number_average_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct number_average_s number_average_t;
typedef struct number_average_s {
	float number;
	float variance;
	bool is_skewness;
	float skewness;
} number_average_t;

number_average_t *number_average_create(float number, float variance,
                                        bool is_skewness, float skewness);
void number_average_free(number_average_t *number_average);
number_average_t *number_average_parseFromJSON(cJSON *number_averageJSON);
cJSON *number_average_convertToJSON(number_average_t *number_average);
number_average_t *number_average_copy(number_average_t	*dst,
                                      number_average_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _number_average_H_ */
