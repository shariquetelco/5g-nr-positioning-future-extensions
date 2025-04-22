/*
 * ue_connectivity_state.h
 *
 * Indicates the connectivity state of a UE.
 */

#ifndef _ue_connectivity_state_H_
#define _ue_connectivity_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "access_type.h"
#include "cm_state.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ue_connectivity_state_s ue_connectivity_state_t;
typedef struct ue_connectivity_state_s {
	access_type_e access_type;
	struct cm_state_s *connectivitystate;
} ue_connectivity_state_t;

ue_connectivity_state_t *ue_connectivity_state_create(
	access_type_e	access_type,
	cm_state_t	*connectivitystate);
void ue_connectivity_state_free(ue_connectivity_state_t *ue_connectivity_state);
ue_connectivity_state_t *ue_connectivity_state_parseFromJSON(
	cJSON *ue_connectivity_stateJSON);
cJSON *ue_connectivity_state_convertToJSON(
	ue_connectivity_state_t *ue_connectivity_state);
ue_connectivity_state_t *ue_connectivity_state_copy(
	ue_connectivity_state_t *dst, ue_connectivity_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _ue_connectivity_state_H_ */
