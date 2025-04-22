/*
 * ue_comm_order_criterion.h
 *
 * Represents the ordering criterion for the list of UE communication analytics.   Possible values are:     - START_TIME: The ordering criterion of the analytics is the start time.   - DURATION: The ordering criterion of the analytics is the duration of the communication.
 */

#ifndef _ue_comm_order_criterion_H_
#define _ue_comm_order_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ue_comm_order_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_comm_order_criterion_s ue_comm_order_criterion_t;
typedef struct ue_comm_order_criterion_s {} ue_comm_order_criterion_t;

ue_comm_order_criterion_t *ue_comm_order_criterion_create();
void ue_comm_order_criterion_free(
	ue_comm_order_criterion_t *ue_comm_order_criterion);
ue_comm_order_criterion_t *ue_comm_order_criterion_parseFromJSON(
	cJSON *ue_comm_order_criterionJSON);
cJSON *ue_comm_order_criterion_convertToJSON(
	ue_comm_order_criterion_t *ue_comm_order_criterion);
ue_comm_order_criterion_t *ue_comm_order_criterion_copy(
	ue_comm_order_criterion_t *dst, ue_comm_order_criterion_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_comm_order_criterion_H_ */
