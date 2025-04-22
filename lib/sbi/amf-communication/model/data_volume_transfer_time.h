/*
 * data_volume_transfer_time.h
 *
 * Indicates the E2E data volume transfer time and the data volume used to derive the transfer time.
 */

#ifndef _data_volume_transfer_time_H_
#define _data_volume_transfer_time_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct data_volume_transfer_time_s data_volume_transfer_time_t;
typedef struct data_volume_transfer_time_s {
	bool is_uplink_volume;
	long uplink_volume;
	bool is_avg_trans_time_ul;
	int avg_trans_time_ul;
	bool is_var_trans_time_ul;
	float var_trans_time_ul;
	bool is_downlink_volume;
	long downlink_volume;
	bool is_avg_trans_time_dl;
	int avg_trans_time_dl;
	bool is_var_trans_time_dl;
	float var_trans_time_dl;
} data_volume_transfer_time_t;

data_volume_transfer_time_t *data_volume_transfer_time_create(
	bool is_uplink_volume, long uplink_volume, bool is_avg_trans_time_ul,
	int avg_trans_time_ul, bool is_var_trans_time_ul,
	float var_trans_time_ul, bool is_downlink_volume, long downlink_volume,
	bool is_avg_trans_time_dl, int avg_trans_time_dl,
	bool is_var_trans_time_dl, float var_trans_time_dl);
void data_volume_transfer_time_free(
	data_volume_transfer_time_t *data_volume_transfer_time);
data_volume_transfer_time_t *data_volume_transfer_time_parseFromJSON(
	cJSON *data_volume_transfer_timeJSON);
cJSON *data_volume_transfer_time_convertToJSON(
	data_volume_transfer_time_t *data_volume_transfer_time);
data_volume_transfer_time_t *data_volume_transfer_time_copy(
	data_volume_transfer_time_t *dst, data_volume_transfer_time_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _data_volume_transfer_time_H_ */
