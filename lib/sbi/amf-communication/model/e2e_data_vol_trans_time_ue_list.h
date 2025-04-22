/*
 * e2e_data_vol_trans_time_ue_list.h
 *
 * Contains the list of UEs classified based on experience level of E2E Data Volume Transfer  Time
 */

#ifndef _e2e_data_vol_trans_time_ue_list_H_
#define _e2e_data_vol_trans_time_ue_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "network_area_info.h"
#include "time_window.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct e2e_data_vol_trans_time_ue_list_s
        e2e_data_vol_trans_time_ue_list_t;
typedef struct e2e_data_vol_trans_time_ue_list_s {
	list_t *high_level;
	list_t *medium_level;
	list_t *low_level;
	bool is_low_ratio;
	int low_ratio;
	bool is_medium_ratio;
	int medium_ratio;
	bool is_high_ratio;
	int high_ratio;
	struct network_area_info_s *spatial_validity;
	struct time_window_s *validity_period;
} e2e_data_vol_trans_time_ue_list_t;

e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list_create(
	list_t *high_level, list_t *medium_level, list_t *low_level,
	bool is_low_ratio, int low_ratio, bool is_medium_ratio,
	int medium_ratio, bool is_high_ratio, int high_ratio,
	network_area_info_t *spatial_validity, time_window_t *validity_period);
void e2e_data_vol_trans_time_ue_list_free(
	e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list);
e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_ue_listJSON);
cJSON *e2e_data_vol_trans_time_ue_list_convertToJSON(
	e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list);
e2e_data_vol_trans_time_ue_list_t *e2e_data_vol_trans_time_ue_list_copy(
	e2e_data_vol_trans_time_ue_list_t	*dst,
	e2e_data_vol_trans_time_ue_list_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _e2e_data_vol_trans_time_ue_list_H_ */
