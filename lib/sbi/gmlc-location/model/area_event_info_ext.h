/*
 * area_event_info_ext.h
 *
 * Extended Area Event Information
 */

#ifndef _area_event_info_ext_H_
#define _area_event_info_ext_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographic_area.h"
#include "occurrence_info.h"
#include "reporting_area.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct area_event_info_ext_s area_event_info_ext_t;
typedef struct area_event_info_ext_s {
	list_t *area_definition;
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
	list_t *geo_area_list;
	bool is_ignore_area_def_ind;
	int ignore_area_def_ind;
	bool is_additional_check_ind;
	int additional_check_ind;
} area_event_info_ext_t;

area_event_info_ext_t *area_event_info_ext_create(list_t *area_definition,
                                                  occurrence_info_e occurrence_info, bool is_minimum_interval, int minimum_interval, bool is_maximum_interval, int maximum_interval, bool is_sampling_interval, int sampling_interval, bool is_reporting_duration, int reporting_duration, bool is_reporting_location_req, int reporting_location_req, list_t *geo_area_list, bool is_ignore_area_def_ind, int ignore_area_def_ind, bool is_additional_check_ind, int additional_check_ind);
void area_event_info_ext_free(area_event_info_ext_t *area_event_info_ext);
area_event_info_ext_t *area_event_info_ext_parseFromJSON(
	cJSON *area_event_info_extJSON);
cJSON *area_event_info_ext_convertToJSON(
	area_event_info_ext_t *area_event_info_ext);
area_event_info_ext_t *area_event_info_ext_copy(area_event_info_ext_t	*dst,
                                                area_event_info_ext_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _area_event_info_ext_H_ */
