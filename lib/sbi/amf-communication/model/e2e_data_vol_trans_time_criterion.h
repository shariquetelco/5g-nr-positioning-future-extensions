/*
 * e2e_data_vol_trans_time_criterion.h
 *
 * Represents the ordering criterion for the list of E2E data volume transfer time.   Possible values are:     - TIME_SLOT_START: Indicates the order of time slot start.   - E2E_DATA_VOL_TRANS_TIME: The ordering criterion is the E2E data volume transfer time.
 */

#ifndef _e2e_data_vol_trans_time_criterion_H_
#define _e2e_data_vol_trans_time_criterion_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "e2e_data_vol_trans_time_criterion_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct e2e_data_vol_trans_time_criterion_s
        e2e_data_vol_trans_time_criterion_t;
typedef struct e2e_data_vol_trans_time_criterion_s {}
e2e_data_vol_trans_time_criterion_t;

e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion_create();
void e2e_data_vol_trans_time_criterion_free(
	e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion);
e2e_data_vol_trans_time_criterion_t *
e2e_data_vol_trans_time_criterion_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_criterionJSON);
cJSON *e2e_data_vol_trans_time_criterion_convertToJSON(
	e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion);
e2e_data_vol_trans_time_criterion_t *e2e_data_vol_trans_time_criterion_copy(
	e2e_data_vol_trans_time_criterion_t	*dst,
	e2e_data_vol_trans_time_criterion_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _e2e_data_vol_trans_time_criterion_H_ */
