/*
 * e2e_data_vol_trans_time_req.h
 *
 * Represents other E2E data volume transfer time analytics requirements.
 */

#ifndef _e2e_data_vol_trans_time_req_H_
#define _e2e_data_vol_trans_time_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "data_volume.h"
#include "e2e_data_vol_trans_time_criterion.h"
#include "matching_direction.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct e2e_data_vol_trans_time_req_s e2e_data_vol_trans_time_req_t;
typedef struct e2e_data_vol_trans_time_req_s {
	struct e2e_data_vol_trans_time_criterion_s *criterion;
	struct matching_direction_s *order;
	bool is_high_trans_tm_thr;
	int high_trans_tm_thr;
	bool is_low_trans_tm_thr;
	int low_trans_tm_thr;
	bool is_repeat_data_trans;
	int repeat_data_trans;
	char *ts_interval_data_trans;
	struct data_volume_s *data_volume;
	bool is_max_number_ues;
	int max_number_ues;
} e2e_data_vol_trans_time_req_t;

e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_create(
	e2e_data_vol_trans_time_criterion_t *criterion,
	matching_direction_t *order, bool is_high_trans_tm_thr,
	int high_trans_tm_thr, bool is_low_trans_tm_thr, int low_trans_tm_thr,
	bool is_repeat_data_trans, int repeat_data_trans,
	char *ts_interval_data_trans, data_volume_t *data_volume,
	bool is_max_number_ues, int max_number_ues);
void e2e_data_vol_trans_time_req_free(
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req);
e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_reqJSON);
cJSON *e2e_data_vol_trans_time_req_convertToJSON(
	e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req);
e2e_data_vol_trans_time_req_t *e2e_data_vol_trans_time_req_copy(
	e2e_data_vol_trans_time_req_t *dst, e2e_data_vol_trans_time_req_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _e2e_data_vol_trans_time_req_H_ */
