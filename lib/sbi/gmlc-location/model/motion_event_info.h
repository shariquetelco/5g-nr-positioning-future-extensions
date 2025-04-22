/*
 * motion_event_info.h
 *
 * Indicates the information of motion based event reporting.
 */

#ifndef _motion_event_info_H_
#define _motion_event_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "occurrence_info.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct motion_event_info_s motion_event_info_t;
typedef struct motion_event_info_s {
	int linear_distance;
	occurrence_info_e occurrence_info;
	bool is_minimum_interval;
	int minimum_interval;
	bool is_maximum_interval;
	int maximum_interval;
	bool is_sampling_interval;
	int sampling_interval;
	bool is_reporting_duration;
	int reporting_duration;
	bool is_reporting_location_req;
	int reporting_location_req;
} motion_event_info_t;

motion_event_info_t *motion_event_info_create(int		linear_distance,
                                              occurrence_info_e occurrence_info,
                                              bool		is_minimum_interval,
                                              int		minimum_interval,
                                              bool		is_maximum_interval,
                                              int		maximum_interval,
                                              bool		is_sampling_interval,
                                              int		sampling_interval,
                                              bool		is_reporting_duration,
                                              int		reporting_duration,
                                              bool		is_reporting_location_req,
                                              int		reporting_location_req);
void motion_event_info_free(motion_event_info_t *motion_event_info);
motion_event_info_t *motion_event_info_parseFromJSON(
	cJSON *motion_event_infoJSON);
cJSON *motion_event_info_convertToJSON(motion_event_info_t *motion_event_info);
motion_event_info_t *motion_event_info_copy(motion_event_info_t *dst,
                                            motion_event_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _motion_event_info_H_ */
