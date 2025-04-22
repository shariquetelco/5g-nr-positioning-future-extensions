/*
 * ue_communication.h
 *
 * Represents UE communication information.
 */

#ifndef _ue_communication_H_
#define _ue_communication_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "app_list_for_ue_comm.h"
#include "scheduled_communication_time_1.h"
#include "sess_inact_timer_for_ue_comm.h"
#include "traffic_characterization.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_communication_s ue_communication_t;
typedef struct ue_communication_s {
	bool is_comm_dur;
	int comm_dur;
	bool is_comm_dur_variance;
	float comm_dur_variance;
	bool is_perio_time;
	int perio_time;
	bool is_perio_time_variance;
	float perio_time_variance;
	char *ts;
	bool is_ts_variance;
	float ts_variance;
	struct scheduled_communication_time_1_s *recurring_time;
	struct traffic_characterization_s *traf_char;
	bool is_ratio;
	int ratio;
	bool is_perio_comm_ind;
	int perio_comm_ind;
	bool is_confidence;
	int confidence;
	struct app_list_for_ue_comm_s *ana_of_app_list;
	struct sess_inact_timer_for_ue_comm_s *sess_inact_timer;
} ue_communication_t;

ue_communication_t *ue_communication_create(bool is_comm_dur, int comm_dur,
                                            bool is_comm_dur_variance,
                                            float comm_dur_variance,
                                            bool is_perio_time, int perio_time,
                                            bool is_perio_time_variance,
                                            float perio_time_variance, char *ts,
                                            bool is_ts_variance,
                                            float ts_variance,
                                            scheduled_communication_time_1_t *recurring_time, traffic_characterization_t *traf_char, bool is_ratio, int ratio, bool is_perio_comm_ind, int perio_comm_ind, bool is_confidence, int confidence, app_list_for_ue_comm_t *ana_of_app_list, sess_inact_timer_for_ue_comm_t *sess_inact_timer);
void ue_communication_free(ue_communication_t *ue_communication);
ue_communication_t *ue_communication_parseFromJSON(cJSON *ue_communicationJSON);
cJSON *ue_communication_convertToJSON(ue_communication_t *ue_communication);
ue_communication_t *ue_communication_copy(ue_communication_t	*dst,
                                          ue_communication_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_communication_H_ */
