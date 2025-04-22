/*
 * ue_differentiation_info.h
 *
 * Represents the UE Differentiation Information and its validity time
 */

#ifndef _ue_differentiation_info_H_
#define _ue_differentiation_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "battery_indication.h"
#include "periodic_communication_indicator.h"
#include "scheduled_communication_time.h"
#include "stationary_indication.h"
#include "traffic_profile.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_differentiation_info_s ue_differentiation_info_t;
typedef struct ue_differentiation_info_s {
	periodic_communication_indicator_e periodic_com_ind;
	bool is_periodic_time;
	int periodic_time;
	struct scheduled_communication_time_s *scheduled_com_time;
	struct stationary_indication_s *stationary_ind;
	struct traffic_profile_s *traffic_profile;
	struct battery_indication_s *battery_ind;
	char *validity_time;
} ue_differentiation_info_t;

ue_differentiation_info_t *ue_differentiation_info_create(
	periodic_communication_indicator_e periodic_com_ind,
	bool is_periodic_time, int periodic_time,
	scheduled_communication_time_t *scheduled_com_time,
	stationary_indication_t *stationary_ind,
	traffic_profile_t *traffic_profile, battery_indication_t *battery_ind,
	char *validity_time);
void ue_differentiation_info_free(
	ue_differentiation_info_t *ue_differentiation_info);
ue_differentiation_info_t *ue_differentiation_info_parseFromJSON(
	cJSON *ue_differentiation_infoJSON);
cJSON *ue_differentiation_info_convertToJSON(
	ue_differentiation_info_t *ue_differentiation_info);
ue_differentiation_info_t *ue_differentiation_info_copy(
	ue_differentiation_info_t *dst, ue_differentiation_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_differentiation_info_H_ */
