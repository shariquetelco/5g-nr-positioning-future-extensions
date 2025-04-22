/*
 * ue_location_info.h
 *
 * Indicates location information of a UE.
 */

#ifndef _ue_location_info_H_
#define _ue_location_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "geographic_area.h"
#include "velocity_estimate.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_location_info_s ue_location_info_t;
typedef struct ue_location_info_s {
	struct geographic_area_s *location_estimate;
	bool is_age_of_location_estimate;
	int age_of_location_estimate;
	char *timestamp_of_location_estimate;
	struct velocity_estimate_s *velocity_estimate;
	bool is_age_of_velocity_estimate;
	int age_of_velocity_estimate;
	char *timestamp_of_velocity_estimate;
} ue_location_info_t;

ue_location_info_t *ue_location_info_create(
	geographic_area_t *location_estimate, bool is_age_of_location_estimate,
	int age_of_location_estimate, char *timestamp_of_location_estimate,
	velocity_estimate_t *velocity_estimate,
	bool is_age_of_velocity_estimate, int age_of_velocity_estimate,
	char *timestamp_of_velocity_estimate);
void ue_location_info_free(ue_location_info_t *ue_location_info);
ue_location_info_t *ue_location_info_parseFromJSON(cJSON *ue_location_infoJSON);
cJSON *ue_location_info_convertToJSON(ue_location_info_t *ue_location_info);
ue_location_info_t *ue_location_info_copy(ue_location_info_t	*dst,
                                          ue_location_info_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_location_info_H_ */
