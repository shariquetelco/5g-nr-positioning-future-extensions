/*
 * proximity_criterion_any_of.h
 *
 *
 */

#ifndef _proximity_criterion_any_of_H_
#define _proximity_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { proximity_criterion_any_of_NULL = 0,
	       proximity_criterion_any_of_VELOCITY,
	       proximity_criterion_any_of_AVG_SPD,
	       proximity_criterion_any_of_ORIENTATION,
	       proximity_criterion_any_of_TRAJECTORY }
proximity_criterion_any_of_e;

char *proximity_criterion_any_of_ToString(
	proximity_criterion_any_of_e proximity_criterion_any_of);

proximity_criterion_any_of_e proximity_criterion_any_of_FromString(
	char *proximity_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _proximity_criterion_any_of_H_ */
