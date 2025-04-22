/*
 * speed_threshold_info.h
 *
 * UEs information whose speed is faster than the speed threshold.
 */

#ifndef _speed_threshold_info_H_
#define _speed_threshold_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct speed_threshold_info_s speed_threshold_info_t;
typedef struct speed_threshold_info_s {
	bool is_num_of_ue;
	int num_of_ue;
	bool is_ratio;
	int ratio;
} speed_threshold_info_t;

speed_threshold_info_t *speed_threshold_info_create(bool is_num_of_ue,
                                                    int num_of_ue,
                                                    bool is_ratio, int ratio);
void speed_threshold_info_free(speed_threshold_info_t *speed_threshold_info);
speed_threshold_info_t *speed_threshold_info_parseFromJSON(
	cJSON *speed_threshold_infoJSON);
cJSON *speed_threshold_info_convertToJSON(
	speed_threshold_info_t *speed_threshold_info);
speed_threshold_info_t *speed_threshold_info_copy(
	speed_threshold_info_t	*dst,
	speed_threshold_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _speed_threshold_info_H_ */
