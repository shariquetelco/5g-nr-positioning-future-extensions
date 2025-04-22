/*
 * loc_measurement_resp.h
 *
 * Location Measurement Response.
 */

#ifndef _loc_measurement_resp_H_
#define _loc_measurement_resp_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographic_area.h"
#include "loc_measurements.h"
#include "local_area.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_measurement_resp_s loc_measurement_resp_t;
typedef struct loc_measurement_resp_s {
	struct loc_measurements_s *loc_measurements;
	struct geographic_area_s *location_estimate;
	bool is_age_of_location_estimate;
	int age_of_location_estimate;
	char *timestamp_of_location_estimate;
	struct velocity_estimate_s *velocity_estimate;
	struct local_area_s *local_location_estimate;
} loc_measurement_resp_t;

loc_measurement_resp_t *loc_measurement_resp_create(
	loc_measurements_t *loc_measurements,
	geographic_area_t *location_estimate, bool is_age_of_location_estimate,
	int age_of_location_estimate, char *timestamp_of_location_estimate,
	velocity_estimate_t *velocity_estimate,
	local_area_t *local_location_estimate);
void loc_measurement_resp_free(loc_measurement_resp_t *loc_measurement_resp);
loc_measurement_resp_t *loc_measurement_resp_parseFromJSON(
	cJSON *loc_measurement_respJSON);
cJSON *loc_measurement_resp_convertToJSON(
	loc_measurement_resp_t *loc_measurement_resp);
loc_measurement_resp_t *loc_measurement_resp_copy(
	loc_measurement_resp_t	*dst,
	loc_measurement_resp_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_measurement_resp_H_ */
