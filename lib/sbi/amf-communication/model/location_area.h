/*
 * location_area.h
 *
 *
 */

#ifndef _location_area_H_
#define _location_area_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "civic_address.h"
#include "geographic_area.h"
#include "network_area_info_1.h"
#include "umt_time.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct location_area_s location_area_t;
typedef struct location_area_s {
	list_t *geographic_areas;
	list_t *civic_addresses;
	struct network_area_info_1_s *nw_area_info;
	struct umt_time_s *umt_time;
} location_area_t;

location_area_t *location_area_create(
	list_t			*geographic_areas,
	list_t			*civic_addresses,
	network_area_info_1_t	*nw_area_info,
	umt_time_t		*umt_time);
void location_area_free(location_area_t *location_area);
location_area_t *location_area_parseFromJSON(cJSON *location_areaJSON);
cJSON *location_area_convertToJSON(location_area_t *location_area);
location_area_t *location_area_copy(location_area_t *dst, location_area_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _location_area_H_ */
