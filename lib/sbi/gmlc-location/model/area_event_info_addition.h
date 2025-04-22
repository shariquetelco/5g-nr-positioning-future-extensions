/*
 * area_event_info_addition.h
 *
 * Additional information for Extended Area event information
 */

#ifndef _area_event_info_addition_H_
#define _area_event_info_addition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographic_area.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct area_event_info_addition_s area_event_info_addition_t;
typedef struct area_event_info_addition_s {
	list_t *geo_area_list;
	bool is_ignore_area_def_ind;
	int ignore_area_def_ind;
	bool is_additional_check_ind;
	int additional_check_ind;
} area_event_info_addition_t;

area_event_info_addition_t *area_event_info_addition_create(
	list_t *geo_area_list, bool is_ignore_area_def_ind,
	int ignore_area_def_ind, bool is_additional_check_ind,
	int additional_check_ind);
void area_event_info_addition_free(
	area_event_info_addition_t *area_event_info_addition);
area_event_info_addition_t *area_event_info_addition_parseFromJSON(
	cJSON *area_event_info_additionJSON);
cJSON *area_event_info_addition_convertToJSON(
	area_event_info_addition_t *area_event_info_addition);
area_event_info_addition_t *area_event_info_addition_copy(
	area_event_info_addition_t *dst, area_event_info_addition_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _area_event_info_addition_H_ */
