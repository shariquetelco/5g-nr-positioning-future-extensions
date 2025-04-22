/*
 * threshold_level.h
 *
 * Represents a threshold level.
 */

#ifndef _threshold_level_H_
#define _threshold_level_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct threshold_level_s threshold_level_t;
typedef struct threshold_level_s {
	bool is_cong_level;
	int cong_level;
	bool is_nf_load_level;
	int nf_load_level;
	bool is_nf_cpu_usage;
	int nf_cpu_usage;
	bool is_nf_memory_usage;
	int nf_memory_usage;
	bool is_nf_storage_usage;
	int nf_storage_usage;
	char *avg_traffic_rate;
	char *max_traffic_rate;
	char *min_traffic_rate;
	char *agg_traffic_rate;
	bool is_var_traffic_rate;
	float var_traffic_rate;
	bool is_avg_packet_delay;
	int avg_packet_delay;
	bool is_max_packet_delay;
	int max_packet_delay;
	bool is_var_packet_delay;
	float var_packet_delay;
	bool is_avg_packet_loss_rate;
	int avg_packet_loss_rate;
	bool is_max_packet_loss_rate;
	int max_packet_loss_rate;
	bool is_var_packet_loss_rate;
	float var_packet_loss_rate;
	bool is_svc_exp_level;
	float svc_exp_level;
	bool is_speed;
	float speed;
} threshold_level_t;

threshold_level_t *threshold_level_create(bool is_cong_level, int cong_level,
                                          bool is_nf_load_level,
                                          int nf_load_level,
                                          bool is_nf_cpu_usage,
                                          int nf_cpu_usage,
                                          bool is_nf_memory_usage,
                                          int nf_memory_usage,
                                          bool is_nf_storage_usage,
                                          int nf_storage_usage,
                                          char *avg_traffic_rate,
                                          char *max_traffic_rate,
                                          char *min_traffic_rate,
                                          char *agg_traffic_rate,
                                          bool is_var_traffic_rate,
                                          float var_traffic_rate,
                                          bool is_avg_packet_delay,
                                          int avg_packet_delay,
                                          bool is_max_packet_delay,
                                          int max_packet_delay,
                                          bool is_var_packet_delay,
                                          float var_packet_delay,
                                          bool is_avg_packet_loss_rate,
                                          int avg_packet_loss_rate,
                                          bool is_max_packet_loss_rate,
                                          int max_packet_loss_rate,
                                          bool is_var_packet_loss_rate,
                                          float var_packet_loss_rate,
                                          bool is_svc_exp_level,
                                          float svc_exp_level, bool is_speed,
                                          float speed);
void threshold_level_free(threshold_level_t *threshold_level);
threshold_level_t *threshold_level_parseFromJSON(cJSON *threshold_levelJSON);
cJSON *threshold_level_convertToJSON(threshold_level_t *threshold_level);
threshold_level_t *threshold_level_copy(threshold_level_t	*dst,
                                        threshold_level_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _threshold_level_H_ */
