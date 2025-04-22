/*
 * ue_comm_order_criterion_any_of.h
 *
 *
 */

#ifndef _ue_comm_order_criterion_any_of_H_
#define _ue_comm_order_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { ue_comm_order_criterion_any_of_NULL = 0,
	       ue_comm_order_criterion_any_of_START_TIME,
	       ue_comm_order_criterion_any_of_DURATION }
ue_comm_order_criterion_any_of_e;

char *ue_comm_order_criterion_any_of_ToString(
	ue_comm_order_criterion_any_of_e ue_comm_order_criterion_any_of);

ue_comm_order_criterion_any_of_e ue_comm_order_criterion_any_of_FromString(
	char *ue_comm_order_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _ue_comm_order_criterion_any_of_H_ */
