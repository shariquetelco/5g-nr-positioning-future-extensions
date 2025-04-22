/*
 * synchronization_state_any_of.h
 *
 *
 */

#ifndef _synchronization_state_any_of_H_
#define _synchronization_state_any_of_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { synchronization_state_any_of_NULL = 0,
	       synchronization_state_any_of_LOCKED,
	       synchronization_state_any_of_HOLDOVER,
	       synchronization_state_any_of_FREERUN }
synchronization_state_any_of_e;

char *synchronization_state_any_of_ToString(
	synchronization_state_any_of_e synchronization_state_any_of);

synchronization_state_any_of_e synchronization_state_any_of_FromString(
	char *synchronization_state_any_of);

#ifdef __cplusplus
}
#endif

#endif /* _synchronization_state_any_of_H_ */
