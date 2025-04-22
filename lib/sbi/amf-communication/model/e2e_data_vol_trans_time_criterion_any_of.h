/*
 * e2e_data_vol_trans_time_criterion_any_of.h
 *
 *
 */

#ifndef _e2e_data_vol_trans_time_criterion_any_of_H_
#define _e2e_data_vol_trans_time_criterion_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { e2e_data_vol_trans_time_criterion_any_of_NULL = 0,
	       e2e_data_vol_trans_time_criterion_any_of_TIME_SLOT_START,
	       e2e_data_vol_trans_time_criterion_any_of_E2E_DATA_VOL_TRANS_TIME }
e2e_data_vol_trans_time_criterion_any_of_e;

char *e2e_data_vol_trans_time_criterion_any_of_ToString(
	e2e_data_vol_trans_time_criterion_any_of_e e2e_data_vol_trans_time_criterion_any_of);

e2e_data_vol_trans_time_criterion_any_of_e
e2e_data_vol_trans_time_criterion_any_of_FromString(
	char *e2e_data_vol_trans_time_criterion_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _e2e_data_vol_trans_time_criterion_any_of_H_ */
