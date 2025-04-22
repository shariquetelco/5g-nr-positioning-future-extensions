/*
 * area_of_interest_event_state.h
 *
 * Event State of AoI event in old AMF
 */

#ifndef _area_of_interest_event_state_H_
#define _area_of_interest_event_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "presence_state.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct area_of_interest_event_state_s area_of_interest_event_state_t;
typedef struct area_of_interest_event_state_s {
	struct presence_state_s *presence;
	list_t *individual_pra_id_list;
} area_of_interest_event_state_t;

area_of_interest_event_state_t *area_of_interest_event_state_create(
	presence_state_t *presence, list_t *individual_pra_id_list);
void area_of_interest_event_state_free(
	area_of_interest_event_state_t *area_of_interest_event_state);
area_of_interest_event_state_t *area_of_interest_event_state_parseFromJSON(
	cJSON *area_of_interest_event_stateJSON);
cJSON *area_of_interest_event_state_convertToJSON(
	area_of_interest_event_state_t *area_of_interest_event_state);
area_of_interest_event_state_t *area_of_interest_event_state_copy(
	area_of_interest_event_state_t	*dst,
	area_of_interest_event_state_t	*src);

#ifdef __cplusplus
}
#endif

#endif /* _area_of_interest_event_state_H_ */
