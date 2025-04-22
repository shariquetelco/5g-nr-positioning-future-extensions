/*
 * red_trans_exp_ordering_criterion.h
 *
 * Represents the order criterion for the list of Redundant Transmission Experience.   Possible values are: - TIME_SLOT_START: Indicates the order of time slot start. - RED_TRANS_EXP: Indicates the order of Redundant Transmission Experience.
 */

#ifndef _red_trans_exp_ordering_criterion_H_
#define _red_trans_exp_ordering_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "red_trans_exp_ordering_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct red_trans_exp_ordering_criterion_s
        red_trans_exp_ordering_criterion_t;
typedef struct red_trans_exp_ordering_criterion_s {}
red_trans_exp_ordering_criterion_t;

red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion_create();
void red_trans_exp_ordering_criterion_free(
	red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion);
red_trans_exp_ordering_criterion_t *
red_trans_exp_ordering_criterion_parseFromJSON(
	cJSON *red_trans_exp_ordering_criterionJSON);
cJSON *red_trans_exp_ordering_criterion_convertToJSON(
	red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion);
red_trans_exp_ordering_criterion_t *red_trans_exp_ordering_criterion_copy(
	red_trans_exp_ordering_criterion_t	*dst,
	red_trans_exp_ordering_criterion_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _red_trans_exp_ordering_criterion_H_ */
