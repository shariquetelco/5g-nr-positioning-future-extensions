/*
 * synchronization_state.h
 *
 * Indicates the Synchronization State.
 */

#ifndef _synchronization_state_H_
#define _synchronization_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "synchronization_state_any_of.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct synchronization_state_s synchronization_state_t;
typedef struct synchronization_state_s {} synchronization_state_t;

synchronization_state_t *synchronization_state_create();
void synchronization_state_free(synchronization_state_t *synchronization_state);
synchronization_state_t *synchronization_state_parseFromJSON(
	cJSON *synchronization_stateJSON);
cJSON *synchronization_state_convertToJSON(
	synchronization_state_t *synchronization_state);
synchronization_state_t *synchronization_state_copy(
	synchronization_state_t *dst, synchronization_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _synchronization_state_H_ */
