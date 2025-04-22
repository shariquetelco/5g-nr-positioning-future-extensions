/*
 * area_event_info.h
 *
 * Indicates the information of area based event reporting.
 */

#ifndef _area_event_info_H_
#define _area_event_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "occurrence_info.h"
#include "reporting_area.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct area_event_info_s area_event_info_t;
typedef struct area_event_info_s {
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
} area_event_info_t;

area_event_info_t *area_event_info_create(
	list_t			*area_definition,
	occurrence_info_e	occurrence_info,
	bool			is_minimum_interval,
	int			minimum_interval,
	bool			is_maximum_interval,
	int			maximum_interval,
	bool			is_sampling_interval,
	int			sampling_interval,
	bool			is_reporting_duration,
	int			reporting_duration,
	bool			is_reporting_location_req,
	int			reporting_location_req);
void area_event_info_free(area_event_info_t *area_event_info);
area_event_info_t *area_event_info_parseFromJSON(cJSON *area_event_infoJSON);
cJSON *area_event_info_convertToJSON(area_event_info_t *area_event_info);
area_event_info_t *area_event_info_copy(area_event_info_t	*dst,
                                        area_event_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _area_event_info_H_ */
