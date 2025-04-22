/*
 * e2e_data_vol_trans_time_info.h
 *
 * Represents the E2E data volume transfer time analytics information when subscribed event is \&quot;E2E_DATA_VOL_TRANS_TIME\&quot;, the \&quot;dataVlTrnsTmInfos\&quot; attribute shall be included.
 */

#ifndef _e2e_data_vol_trans_time_info_H_
#define _e2e_data_vol_trans_time_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "e2e_data_vol_trans_time_per_ts.h"
#include "e2e_data_vol_trans_time_ue_list.h"
#include "geo_distribution_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct e2e_data_vol_trans_time_info_s e2e_data_vol_trans_time_info_t;
typedef struct e2e_data_vol_trans_time_info_s {
	list_t *e2e_data_vol_trans_times;
	list_t *e2e_data_vol_trans_time_ue_lists;
	list_t *geo_distr_infos;
	bool is_confidence;
	int confidence;
} e2e_data_vol_trans_time_info_t;

e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_create(
	list_t *e2e_data_vol_trans_times,
	list_t *e2e_data_vol_trans_time_ue_lists, list_t *geo_distr_infos,
	bool is_confidence, int confidence);
void e2e_data_vol_trans_time_info_free(
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info);
e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_infoJSON);
cJSON *e2e_data_vol_trans_time_info_convertToJSON(
	e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info);
e2e_data_vol_trans_time_info_t *e2e_data_vol_trans_time_info_copy(
	e2e_data_vol_trans_time_info_t	*dst,
	e2e_data_vol_trans_time_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _e2e_data_vol_trans_time_info_H_ */
