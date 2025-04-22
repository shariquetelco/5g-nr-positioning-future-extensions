/*
 * target_area.h
 *
 * TA list or TAI range list or any TA
 */

#ifndef _target_area_H_
#define _target_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "tai.h"
#include "tai_range.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct target_area_s target_area_t;
typedef struct target_area_s {
	list_t *ta_list;
	list_t *tai_range_list;
	bool is_any_ta;
	int any_ta;
} target_area_t;

target_area_t *target_area_create(list_t *ta_list, list_t *tai_range_list,
                                  bool is_any_ta, int any_ta);
void target_area_free(target_area_t *target_area);
target_area_t *target_area_parseFromJSON(cJSON *target_areaJSON);
cJSON *target_area_convertToJSON(target_area_t *target_area);
target_area_t *target_area_copy(target_area_t *dst, target_area_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _target_area_H_ */
