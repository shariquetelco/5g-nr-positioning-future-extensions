/*
 * sess_inact_timer_for_ue_comm.h
 *
 * Represents the N4 Session inactivity timer.
 */

#ifndef _sess_inact_timer_for_ue_comm_H_
#define _sess_inact_timer_for_ue_comm_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct sess_inact_timer_for_ue_comm_s sess_inact_timer_for_ue_comm_t;
typedef struct sess_inact_timer_for_ue_comm_s {
	int n4_sess_id;
	int sess_inactive_timer;
} sess_inact_timer_for_ue_comm_t;

sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_create(
	int n4_sess_id, int sess_inactive_timer);
void sess_inact_timer_for_ue_comm_free(
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm);
sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_parseFromJSON(
	cJSON *sess_inact_timer_for_ue_commJSON);
cJSON *sess_inact_timer_for_ue_comm_convertToJSON(
	sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm);
sess_inact_timer_for_ue_comm_t *sess_inact_timer_for_ue_comm_copy(
	sess_inact_timer_for_ue_comm_t	*dst,
	sess_inact_timer_for_ue_comm_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _sess_inact_timer_for_ue_comm_H_ */
