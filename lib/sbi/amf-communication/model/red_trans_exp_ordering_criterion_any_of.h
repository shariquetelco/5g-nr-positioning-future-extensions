/*
 * red_trans_exp_ordering_criterion_any_of.h
 *
 *
 */

#ifndef _red_trans_exp_ordering_criterion_any_of_H_
#define _red_trans_exp_ordering_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { red_trans_exp_ordering_criterion_any_of_NULL = 0,
	       red_trans_exp_ordering_criterion_any_of_TIME_SLOT_START,
	       red_trans_exp_ordering_criterion_any_of_RED_TRANS_EXP }
red_trans_exp_ordering_criterion_any_of_e;

char *red_trans_exp_ordering_criterion_any_of_ToString(
	red_trans_exp_ordering_criterion_any_of_e red_trans_exp_ordering_criterion_any_of);

red_trans_exp_ordering_criterion_any_of_e
red_trans_exp_ordering_criterion_any_of_FromString(
	char *red_trans_exp_ordering_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _red_trans_exp_ordering_criterion_any_of_H_ */
