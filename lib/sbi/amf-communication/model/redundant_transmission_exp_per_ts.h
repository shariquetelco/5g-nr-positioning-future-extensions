/*
 * redundant_transmission_exp_per_ts.h
 *
 * The redundant transmission experience per Time Slot.
 */

#ifndef _redundant_transmission_exp_per_ts_H_
#define _redundant_transmission_exp_per_ts_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "observed_redundant_trans_exp.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct redundant_transmission_exp_per_ts_s
        redundant_transmission_exp_per_ts_t;
typedef struct redundant_transmission_exp_per_ts_s {
	char *ts_start;
	int ts_duration;
	struct observed_redundant_trans_exp_s *obsv_red_trans_exp;
	bool is_red_trans_status;
	int red_trans_status;
	bool is_ue_ratio;
	int ue_ratio;
	bool is_confidence;
	int confidence;
} redundant_transmission_exp_per_ts_t;

redundant_transmission_exp_per_ts_t *redundant_transmission_exp_per_ts_create(
	char *ts_start, int ts_duration,
	observed_redundant_trans_exp_t *obsv_red_trans_exp,
	bool is_red_trans_status, int red_trans_status, bool is_ue_ratio,
	int ue_ratio, bool is_confidence, int confidence);
void redundant_transmission_exp_per_ts_free(
	redundant_transmission_exp_per_ts_t *redundant_transmission_exp_per_ts);
redundant_transmission_exp_per_ts_t *
redundant_transmission_exp_per_ts_parseFromJSON(
	cJSON *redundant_transmission_exp_per_tsJSON);
cJSON *redundant_transmission_exp_per_ts_convertToJSON(
	redundant_transmission_exp_per_ts_t *redundant_transmission_exp_per_ts);
redundant_transmission_exp_per_ts_t *redundant_transmission_exp_per_ts_copy(
	redundant_transmission_exp_per_ts_t	*dst,
	redundant_transmission_exp_per_ts_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _redundant_transmission_exp_per_ts_H_ */
