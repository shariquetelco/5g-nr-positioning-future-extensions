/*
 * partitioning_criteria.h
 *
 * Possible values are: - \&quot;TAC\&quot;: Type Allocation Code - \&quot;SUBPLMN\&quot;: Subscriber PLMN ID - \&quot;GEOAREA\&quot;: Geographical area, i.e. list(s) of TAI(s) - \&quot;SNSSAI\&quot;: S-NSSAI - \&quot;DNN\&quot;: DNN
 */

#ifndef _partitioning_criteria_H_
#define _partitioning_criteria_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "partitioning_criteria_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct partitioning_criteria_s partitioning_criteria_t;
typedef struct partitioning_criteria_s {} partitioning_criteria_t;

partitioning_criteria_t *partitioning_criteria_create();
void partitioning_criteria_free(partitioning_criteria_t *partitioning_criteria);
partitioning_criteria_t *partitioning_criteria_parseFromJSON(
	cJSON *partitioning_criteriaJSON);
cJSON *partitioning_criteria_convertToJSON(
	partitioning_criteria_t *partitioning_criteria);
partitioning_criteria_t *partitioning_criteria_copy(
	partitioning_criteria_t *dst, partitioning_criteria_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _partitioning_criteria_H_ */
