/*
 * cn_assisted_ran_para.h
 *
 * SMF derived CN assisted RAN parameters tuning
 */

#ifndef _cn_assisted_ran_para_H_
#define _cn_assisted_ran_para_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "battery_indication.h"
#include "scheduled_communication_time.h"
#include "scheduled_communication_type.h"
#include "stationary_indication.h"
#include "traffic_profile.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct cn_assisted_ran_para_s cn_assisted_ran_para_t;
typedef struct cn_assisted_ran_para_s {
	struct stationary_indication_s *stationary_indication;
	bool is_communication_duration_time;
	int communication_duration_time;
	bool is_periodic_time;
	int periodic_time;
	struct scheduled_communication_time_s *scheduled_communication_time;
	struct scheduled_communication_type_s *scheduled_communication_type;
	struct traffic_profile_s *traffic_profile;
	struct battery_indication_s *battery_indication;
} cn_assisted_ran_para_t;

cn_assisted_ran_para_t *cn_assisted_ran_para_create(
	stationary_indication_t *stationary_indication,
	bool is_communication_duration_time, int communication_duration_time,
	bool is_periodic_time, int periodic_time,
	scheduled_communication_time_t *scheduled_communication_time,
	scheduled_communication_type_t *scheduled_communication_type,
	traffic_profile_t *traffic_profile,
	battery_indication_t *battery_indication);
void cn_assisted_ran_para_free(cn_assisted_ran_para_t *cn_assisted_ran_para);
cn_assisted_ran_para_t *cn_assisted_ran_para_parseFromJSON(
	cJSON *cn_assisted_ran_paraJSON);
cJSON *cn_assisted_ran_para_convertToJSON(
	cn_assisted_ran_para_t *cn_assisted_ran_para);
cn_assisted_ran_para_t *cn_assisted_ran_para_copy(
	cn_assisted_ran_para_t	*dst,
	cn_assisted_ran_para_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _cn_assisted_ran_para_H_ */
