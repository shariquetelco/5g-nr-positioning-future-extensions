/*
 * e2e_data_vol_trans_time_per_ue.h
 *
 * Represents the E2E data volume transfer time per UE.
 */

#ifndef _e2e_data_vol_trans_time_per_ue_H_
#define _e2e_data_vol_trans_time_per_ue_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "data_volume_transfer_time.h"
#include "network_area_info.h"
#include "snssai.h"
#include "time_window.h"
#include "user_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct e2e_data_vol_trans_time_per_ue_s e2e_data_vol_trans_time_per_ue_t;
typedef struct e2e_data_vol_trans_time_per_ue_s {
	char *supi;
	char *gpsi;
	struct snssai_s *snssai;
	char *app_id;
	struct user_location_s *ue_loc;
	char *dnn;
	struct network_area_info_s *spatial_validity;
	struct time_window_s *validity_period;
	struct data_volume_transfer_time_s *data_vol_trans_time;
} e2e_data_vol_trans_time_per_ue_t;

e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_create(
	char *supi, char *gpsi, snssai_t *snssai, char *app_id,
	user_location_t *ue_loc, char *dnn,
	network_area_info_t *spatial_validity, time_window_t *validity_period,
	data_volume_transfer_time_t *data_vol_trans_time);
void e2e_data_vol_trans_time_per_ue_free(
	e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue);
e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_parseFromJSON(
	cJSON *e2e_data_vol_trans_time_per_ueJSON);
cJSON *e2e_data_vol_trans_time_per_ue_convertToJSON(
	e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue);
e2e_data_vol_trans_time_per_ue_t *e2e_data_vol_trans_time_per_ue_copy(
	e2e_data_vol_trans_time_per_ue_t	*dst,
	e2e_data_vol_trans_time_per_ue_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _e2e_data_vol_trans_time_per_ue_H_ */
