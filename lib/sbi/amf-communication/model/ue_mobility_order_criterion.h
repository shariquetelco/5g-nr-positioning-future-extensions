/*
 * ue_mobility_order_criterion.h
 *
 * Represents the ordering criterion for the list of UE mobility analytics.   Possible values are:     - TIME_SLOT: The ordering criterion is the time slot.
 */

#ifndef _ue_mobility_order_criterion_H_
#define _ue_mobility_order_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_mobility_order_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_mobility_order_criterion_s ue_mobility_order_criterion_t;
typedef struct ue_mobility_order_criterion_s {} ue_mobility_order_criterion_t;

ue_mobility_order_criterion_t *ue_mobility_order_criterion_create();
void ue_mobility_order_criterion_free(
	ue_mobility_order_criterion_t *ue_mobility_order_criterion);
ue_mobility_order_criterion_t *ue_mobility_order_criterion_parseFromJSON(
	cJSON *ue_mobility_order_criterionJSON);
cJSON *ue_mobility_order_criterion_convertToJSON(
	ue_mobility_order_criterion_t *ue_mobility_order_criterion);
ue_mobility_order_criterion_t *ue_mobility_order_criterion_copy(
	ue_mobility_order_criterion_t *dst, ue_mobility_order_criterion_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_mobility_order_criterion_H_ */
