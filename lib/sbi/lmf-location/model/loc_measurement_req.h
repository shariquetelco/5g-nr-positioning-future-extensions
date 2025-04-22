/*
 * loc_measurement_req.h
 *
 * Location Measurement Request.
 */

#ifndef _loc_measurement_req_H_
#define _loc_measurement_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ecgi.h"
#include "geographic_area.h"
#include "ncgi.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct loc_measurement_req_s loc_measurement_req_t;
typedef struct loc_measurement_req_s {
	struct ncgi_s *ncgi;
	struct ecgi_s *ecgi;
	struct geographic_area_s *pre_calcu_loc_estimate;
	char *timestamp_of_pre_calcu_loc_estimate;
	list_t *time_windows;
} loc_measurement_req_t;

loc_measurement_req_t *loc_measurement_req_create(ncgi_t *ncgi, ecgi_t *ecgi,
                                                  geographic_area_t *pre_calcu_loc_estimate, char *timestamp_of_pre_calcu_loc_estimate, list_t *time_windows);
void loc_measurement_req_free(loc_measurement_req_t *loc_measurement_req);
loc_measurement_req_t *loc_measurement_req_parseFromJSON(
	cJSON *loc_measurement_reqJSON);
cJSON *loc_measurement_req_convertToJSON(
	loc_measurement_req_t *loc_measurement_req);
loc_measurement_req_t *loc_measurement_req_copy(loc_measurement_req_t	*dst,
                                                loc_measurement_req_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _loc_measurement_req_H_ */
