/*
 * service_area_restriction.h
 *
 * Provides information about allowed or not allowed areas.
 */

#ifndef _service_area_restriction_H_
#define _service_area_restriction_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "area.h"
#include "restriction_type.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct service_area_restriction_s service_area_restriction_t;
typedef struct service_area_restriction_s {
	struct restriction_type_s *restriction_type;
	list_t *areas;
	bool is_max_num_of_tas;
	int max_num_of_tas;
	bool is_max_num_of_tas_for_not_allowed_areas;
	int max_num_of_tas_for_not_allowed_areas;
} service_area_restriction_t;

service_area_restriction_t *service_area_restriction_create(
	restriction_type_t *restriction_type, list_t *areas,
	bool is_max_num_of_tas, int max_num_of_tas,
	bool is_max_num_of_tas_for_not_allowed_areas,
	int max_num_of_tas_for_not_allowed_areas);
void service_area_restriction_free(
	service_area_restriction_t *service_area_restriction);
service_area_restriction_t *service_area_restriction_parseFromJSON(
	cJSON *service_area_restrictionJSON);
cJSON *service_area_restriction_convertToJSON(
	service_area_restriction_t *service_area_restriction);
service_area_restriction_t *service_area_restriction_copy(
	service_area_restriction_t *dst, service_area_restriction_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _service_area_restriction_H_ */
