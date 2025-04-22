/*
 * e2e_data_vol_trans_time_per_ts.h
 *
 * Represents the E2E data volume transfer time analytics per Time Slot.
 */

#ifndef _e2e_data_vol_trans_time_per_ts_H_
#define _e2e_data_vol_trans_time_per_ts_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "e2e_data_vol_trans_time_per_ue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct e2e_data_vol_trans_time_per_ts_s e2e_data_vol_trans_time_per_ts_t;
typedef struct e2e_data_vol_trans_time_per_ts_s {
	char *ts_start;
	int ts_duration;
	list_t *e2e_data_vol_trans_time_per_ue;
} e2e_data_vol_trans_time_per_ts_t;

e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts_create(
	char *ts_start, int ts_duration,
	list_t *e2e_data_vol_trans_time_per_ue);
void e2e_data_vol_trans_time_per_ts_free(
	e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts);
e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_per_tsJSON);
cJSON *e2e_data_vol_trans_time_per_ts_convertToJSON(
	e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts);
e2e_data_vol_trans_time_per_ts_t *e2e_data_vol_trans_time_per_ts_copy(
	e2e_data_vol_trans_time_per_ts_t	*dst,
	e2e_data_vol_trans_time_per_ts_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _e2e_data_vol_trans_time_per_ts_H_ */
