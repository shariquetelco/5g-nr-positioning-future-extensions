/*
 * expected_ue_behaviour_data.h
 *
 *
 */

#ifndef _expected_ue_behaviour_data_H_
#define _expected_ue_behaviour_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "battery_indication.h"
#include "location_area.h"
#include "scheduled_communication_time.h"
#include "scheduled_communication_type.h"
#include "stationary_indication.h"
#include "traffic_profile.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct expected_ue_behaviour_data_s expected_ue_behaviour_data_t;
typedef struct expected_ue_behaviour_data_s {
	struct stationary_indication_s *stationary_indication;
	bool is_communication_duration_time;
	int communication_duration_time;
	bool is_periodic_time;
	int periodic_time;
	struct scheduled_communication_time_s *scheduled_communication_time;
	struct scheduled_communication_type_s *scheduled_communication_type;
	list_t *expected_umts;
	struct traffic_profile_s *traffic_profile;
	struct battery_indication_s *battery_indication;
	char *validity_time;
	char *confidence_level;
	char *accuracy_level;
} expected_ue_behaviour_data_t;

expected_ue_behaviour_data_t *expected_ue_behaviour_data_create(
	stationary_indication_t *stationary_indication,
	bool is_communication_duration_time, int communication_duration_time,
	bool is_periodic_time, int periodic_time,
	scheduled_communication_time_t *scheduled_communication_time,
	scheduled_communication_type_t *scheduled_communication_type,
	list_t *expected_umts, traffic_profile_t *traffic_profile,
	battery_indication_t *battery_indication, char *validity_time,
	char *confidence_level, char *accuracy_level);
void expected_ue_behaviour_data_free(
	expected_ue_behaviour_data_t *expected_ue_behaviour_data);
expected_ue_behaviour_data_t *expected_ue_behaviour_data_parseFromJSON(
	cJSON *expected_ue_behaviour_dataJSON);
cJSON *expected_ue_behaviour_data_convertToJSON(
	expected_ue_behaviour_data_t *expected_ue_behaviour_data);
expected_ue_behaviour_data_t *expected_ue_behaviour_data_copy(
	expected_ue_behaviour_data_t *dst, expected_ue_behaviour_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _expected_ue_behaviour_data_H_ */
