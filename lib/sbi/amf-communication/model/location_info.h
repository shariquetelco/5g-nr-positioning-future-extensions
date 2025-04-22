/*
 * location_info.h
 *
 * Represents UE location information.
 */

#ifndef _location_info_H_
#define _location_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geo_distribution_info.h"
#include "geographical_area.h"
#include "user_location.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_info_s location_info_t;
typedef struct location_info_s {
	struct user_location_s *loc;
	struct geographical_area_s *geo_loc;
	bool is_ratio;
	int ratio;
	bool is_confidence;
	int confidence;
	list_t *geo_distr_infos;
	bool is_dist_threshold;
	int dist_threshold;
} location_info_t;

location_info_t *location_info_create(user_location_t *loc,
                                      geographical_area_t *geo_loc,
                                      bool is_ratio, int ratio,
                                      bool is_confidence, int confidence,
                                      list_t *geo_distr_infos,
                                      bool is_dist_threshold,
                                      int dist_threshold);
void location_info_free(location_info_t *location_info);
location_info_t *location_info_parseFromJSON(cJSON *location_infoJSON);
cJSON *location_info_convertToJSON(location_info_t *location_info);
location_info_t *location_info_copy(location_info_t *dst, location_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _location_info_H_ */
