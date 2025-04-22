/*
 * partitioning_criteria_any_of.h
 *
 *
 */

#ifndef _partitioning_criteria_any_of_H_
#define _partitioning_criteria_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { partitioning_criteria_any_of_NULL = 0,
	       partitioning_criteria_any_of_TAC,
	       partitioning_criteria_any_of_SUBPLMN,
	       partitioning_criteria_any_of_GEOAREA,
	       partitioning_criteria_any_of_SNSSAI,
	       partitioning_criteria_any_of_DNN } partitioning_criteria_any_of_e;

char *partitioning_criteria_any_of_ToString(
	partitioning_criteria_any_of_e partitioning_criteria_any_of);

partitioning_criteria_any_of_e partitioning_criteria_any_of_FromString(
	char *partitioning_criteria_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _partitioning_criteria_any_of_H_ */
